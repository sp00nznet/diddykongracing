#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void init_object_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F7EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F7F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F7F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F7F8: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x8000F7FC: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
    // 0x8000F800: lb          $v0, 0x53($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X53);
    // 0x8000F804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F808: bne         $v0, $zero, L_8000F948
    if (ctx->r2 != 0) {
        // 0x8000F80C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F948;
    }
    // 0x8000F80C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F810: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x8000F814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F818: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000F81C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000F820: bne         $t6, $zero, L_8000F83C
    if (ctx->r14 != 0) {
        // 0x8000F824: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8000F83C;
    }
    // 0x8000F824: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F828:
    // 0x8000F828: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000F82C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F830: beq         $t7, $zero, L_8000F828
    if (ctx->r15 == 0) {
        // 0x8000F834: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000F828;
    }
    // 0x8000F834: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000F838: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F83C:
    // 0x8000F83C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8000F840: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F844: nop

    // 0x8000F848: beq         $v0, $zero, L_8000F978
    if (ctx->r2 == 0) {
        // 0x8000F84C: nop
    
            goto L_8000F978;
    }
    // 0x8000F84C: nop

    // 0x8000F850: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000F854: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000F858: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8000F85C: nop

    // 0x8000F860: beq         $t2, $zero, L_8000F978
    if (ctx->r10 == 0) {
        // 0x8000F864: nop
    
            goto L_8000F978;
    }
    // 0x8000F864: nop

    // 0x8000F868: lh          $t3, 0x3E($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X3E);
    // 0x8000F86C: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8000F870: lw          $a1, 0x28($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X28);
    // 0x8000F874: lw          $a2, 0x2C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X2C);
    // 0x8000F878: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000F87C: lh          $t4, 0x40($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X40);
    // 0x8000F880: jal         0x8001D4E8
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x8000F888: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8000F88C: nop

    // 0x8000F890: lbu         $t5, 0x3D($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3D);
    // 0x8000F894: nop

    // 0x8000F898: beq         $t5, $zero, L_8000F940
    if (ctx->r13 == 0) {
        // 0x8000F89C: nop
    
            goto L_8000F940;
    }
    // 0x8000F89C: nop

    // 0x8000F8A0: lbu         $t6, 0x3A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3A);
    // 0x8000F8A4: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8A8: nop

    // 0x8000F8AC: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8000F8B0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8B4: lw          $t1, 0x54($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8B8: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x8000F8BC: nop

    // 0x8000F8C0: sb          $t9, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r25;
    // 0x8000F8C4: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8C8: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8CC: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8000F8D0: nop

    // 0x8000F8D4: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8000F8D8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8DC: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8E0: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8000F8E4: nop

    // 0x8000F8E8: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8000F8EC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8F0: nop

    // 0x8000F8F4: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x8000F8F8: nop

    // 0x8000F8FC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8000F900: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8000F904: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x8000F908: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F90C: nop

    // 0x8000F910: lh          $t2, 0x1E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1E);
    // 0x8000F914: nop

    // 0x8000F918: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8000F91C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8000F920: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x8000F924: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F928: nop

    // 0x8000F92C: lh          $t5, 0x20($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X20);
    // 0x8000F930: nop

    // 0x8000F934: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8000F938: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8000F93C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_8000F940:
    // 0x8000F940: b           L_8000F978
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_8000F978;
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_8000F948:
    // 0x8000F948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F94C: bne         $v0, $at, L_8000F978
    if (ctx->r2 != ctx->r1) {
        // 0x8000F950: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000F978;
    }
    // 0x8000F950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F958: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x8000F95C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000F960: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8000F964: sb          $v0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r2;
    // 0x8000F968: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x8000F96C: sb          $v0, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r2;
    // 0x8000F970: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8000F974: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_8000F978:
    // 0x8000F978: bne         $a2, $zero, L_8000F984
    if (ctx->r6 != 0) {
        // 0x8000F97C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8000F984;
    }
    // 0x8000F97C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000F980: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
L_8000F984:
    // 0x8000F984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F988: and         $v0, $a2, $at
    ctx->r2 = ctx->r6 & ctx->r1;
    // 0x8000F98C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000F990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000F994: jr          $ra
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void obj_init_attachpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F99C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F9A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F9A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F9A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F9AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F9B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F9B8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000F9BC: lw          $s3, 0x60($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X60);
    // 0x8000F9C0: lb          $v0, 0x56($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X56);
    // 0x8000F9C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F9C8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000F9D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000F9D4: blez        $v0, L_8000FA20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F9D8: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_8000FA20;
    }
    // 0x8000F9D8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9DC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000F9E0:
    // 0x8000F9E0: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8000F9E4: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8000F9E8: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8000F9EC: nop

    // 0x8000F9F0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000F9F4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000F9F8: jal         0x8000FD54
    // 0x8000F9FC: nop

    obj_spawn_attachment(rdram, ctx);
        goto after_0;
    // 0x8000F9FC: nop

    after_0:
    // 0x8000FA00: bne         $v0, $zero, L_8000FA0C
    if (ctx->r2 != 0) {
        // 0x8000FA04: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_8000FA0C;
    }
    // 0x8000FA04: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8000FA08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8000FA0C:
    // 0x8000FA0C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA10: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA14: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA18: bne         $at, $zero, L_8000F9E0
    if (ctx->r1 != 0) {
        // 0x8000FA1C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000F9E0;
    }
    // 0x8000FA1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA20:
    // 0x8000FA20: beq         $s4, $zero, L_8000FA90
    if (ctx->r20 == 0) {
        // 0x8000FA24: nop
    
            goto L_8000FA90;
    }
    // 0x8000FA24: nop

    // 0x8000FA28: blez        $v0, L_8000FA88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000FA2C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000FA88;
    }
    // 0x8000FA2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000FA30: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000FA34:
    // 0x8000FA34: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000FA38: nop

    // 0x8000FA3C: beq         $s0, $zero, L_8000FA78
    if (ctx->r16 == 0) {
        // 0x8000FA40: nop
    
            goto L_8000FA78;
    }
    // 0x8000FA40: nop

    // 0x8000FA44: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000FA4C: lb          $a1, 0x55($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X55);
    // 0x8000FA50: lb          $a2, 0x53($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X53);
    // 0x8000FA54: jal         0x8000F648
    // 0x8000FA58: nop

    objFreeAssets(rdram, ctx);
        goto after_1;
    // 0x8000FA58: nop

    after_1:
    // 0x8000FA5C: lh          $a0, 0x2C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2C);
    // 0x8000FA60: jal         0x8000C844
    // 0x8000FA64: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FA64: nop

    after_2:
    // 0x8000FA68: jal         0x80071380
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000FA70: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA74: nop

L_8000FA78:
    // 0x8000FA78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA7C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA80: bne         $at, $zero, L_8000FA34
    if (ctx->r1 != 0) {
        // 0x8000FA84: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000FA34;
    }
    // 0x8000FA84: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA88:
    // 0x8000FA88: b           L_8000FAA4
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000FAA4;
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000FA90:
    // 0x8000FA90: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FA98: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8000FA9C: nop

    // 0x8000FAA0: sw          $t4, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r12;
L_8000FAA4:
    // 0x8000FAA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FAA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FAAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FAB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FAB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FAB8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FABC: jr          $ra
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FAC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000FAC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FACC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000FAD0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000FAD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000FAD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000FADC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FAE0: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
    // 0x8000FAE4: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8000FAE8: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000FAEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000FAF0: blez        $v1, L_8000FB9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000FAF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FB9C;
    }
    // 0x8000FAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000FAF8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000FAFC: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
L_8000FB00:
    // 0x8000FB00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000FB04: sll         $t1, $s0, 5
    ctx->r9 = S32(ctx->r16 << 5);
    // 0x8000FB08: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8000FB0C: bne         $s3, $t6, L_8000FB3C
    if (ctx->r19 != ctx->r14) {
        // 0x8000FB10: sra         $a1, $v0, 24
        ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
            goto L_8000FB3C;
    }
    // 0x8000FB10: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000FB14: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB18: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8000FB1C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x8000FB20: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8000FB24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000FB28: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8000FB2C: jal         0x800AF740
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    emitter_init(rdram, ctx);
        goto after_0;
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8000FB34: b           L_8000FB84
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_8000FB84;
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB3C:
    // 0x8000FB3C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8000FB40: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB44: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000FB48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8000FB4C: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000FB50: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000FB54: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8000FB58: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8000FB5C: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8000FB60: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8000FB64: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000FB68: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8000FB6C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8000FB70: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8000FB74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000FB78: jal         0x800AF7FC
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8000FB80: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB84:
    // 0x8000FB84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000FB88: lb          $v1, 0x57($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X57);
    // 0x8000FB8C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000FB90: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000FB94: bne         $at, $zero, L_8000FB00
    if (ctx->r1 != 0) {
        // 0x8000FB98: nop
    
            goto L_8000FB00;
    }
    // 0x8000FB98: nop

L_8000FB9C:
    // 0x8000FB9C: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8000FBA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FBA4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8000FBA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000FBAC: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8000FBB0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FBB4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000FBB8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000FBBC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000FBC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000FBC4: jr          $ra
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void init_object_shadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FBCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FBD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FBD4: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
    // 0x8000FBD8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FBDC: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x8000FBE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FBE4: lh          $t6, 0x32($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X32);
    // 0x8000FBE8: nop

    // 0x8000FBEC: beq         $t6, $zero, L_8000FC18
    if (ctx->r14 == 0) {
        // 0x8000FBF0: nop
    
            goto L_8000FC18;
    }
    // 0x8000FBF0: nop

    // 0x8000FBF4: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8000FBF8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FBFC: jal         0x8007B2C4
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FC04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FC08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FC0C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8000FC10: lw          $v1, 0x40($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC14: nop

L_8000FC18:
    // 0x8000FC18: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000FC1C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC20: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000FC24: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x8000FC28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FC2C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC30: sw          $t8, -0x4C30($at)
    MEM_W(-0X4C30, ctx->r1) = ctx->r24;
    // 0x8000FC34: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FC3C: lh          $t0, 0x32($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X32);
    // 0x8000FC40: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000FC44: beq         $t0, $zero, L_8000FC64
    if (ctx->r8 == 0) {
        // 0x8000FC48: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC48: nop

    // 0x8000FC4C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC50: nop

    // 0x8000FC54: bne         $t1, $zero, L_8000FC64
    if (ctx->r9 != 0) {
        // 0x8000FC58: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC58: nop

    // 0x8000FC5C: b           L_8000FC64
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FC64;
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FC64:
    // 0x8000FC64: jr          $ra
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void init_object_water_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FC74: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC78: sw          $a1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r5;
    // 0x8000FC7C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8000FC80: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x8000FC84: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC88: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FC90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000FC94: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FC98: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8000FC9C: sh          $t9, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r25;
    // 0x8000FCA0: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FCA4: nop

    // 0x8000FCA8: lh          $t0, 0x36($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X36);
    // 0x8000FCAC: nop

    // 0x8000FCB0: beq         $t0, $zero, L_8000FCD4
    if (ctx->r8 == 0) {
        // 0x8000FCB4: nop
    
            goto L_8000FCD4;
    }
    // 0x8000FCB4: nop

    // 0x8000FCB8: lh          $a0, 0x38($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X38);
    // 0x8000FCBC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FCC0: jal         0x8007B2C4
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FCC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FCCC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FCD0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000FCD4:
    // 0x8000FCD4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8000FCD8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000FCDC: sh          $t1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r9;
    // 0x8000FCE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FCE4: sw          $t2, -0x4C2C($at)
    MEM_W(-0X4C2C, ctx->r1) = ctx->r10;
    // 0x8000FCE8: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
    // 0x8000FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FCF0: lh          $t4, 0x36($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X36);
    // 0x8000FCF4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8000FCF8: beq         $t4, $zero, L_8000FD18
    if (ctx->r12 == 0) {
        // 0x8000FCFC: nop
    
            goto L_8000FD18;
    }
    // 0x8000FCFC: nop

    // 0x8000FD00: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x8000FD04: nop

    // 0x8000FD08: bne         $t5, $zero, L_8000FD18
    if (ctx->r13 != 0) {
        // 0x8000FD0C: nop
    
            goto L_8000FD18;
    }
    // 0x8000FD0C: nop

    // 0x8000FD10: b           L_8000FD18
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FD18;
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD18:
    // 0x8000FD18: jr          $ra
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void init_object_interaction_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD20: sw          $a1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r5;
    // 0x8000FD24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8000FD28: sb          $t6, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r14;
    // 0x8000FD2C: jr          $ra
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void obj_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FD3C: jal         0x80016BF8
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    func_80016BC4(rdram, ctx);
        goto after_0;
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    after_0:
    // 0x8000FD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000FD4C: jr          $ra
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
    return;
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
;}
RECOMP_FUNC void obj_spawn_attachment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000FD58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000FD5C: lw          $t6, -0x4D18($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D18);
    // 0x8000FD60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FD64: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000FD68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000FD6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000FD70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FD74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FD78: bne         $at, $zero, L_8000FD84
    if (ctx->r1 != 0) {
        // 0x8000FD7C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8000FD84;
    }
    // 0x8000FD7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FD80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000FD84:
    // 0x8000FD84: jal         0x8000C718
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    load_object_header(rdram, ctx);
        goto after_0;
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000FD8C: bne         $v0, $zero, L_8000FD9C
    if (ctx->r2 != 0) {
        // 0x8000FD90: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000FD9C;
    }
    // 0x8000FD90: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8000FD94: b           L_8000FF98
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD9C:
    // 0x8000FD9C: lb          $s0, 0x55($s3)
    ctx->r16 = MEM_B(ctx->r19, 0X55);
    // 0x8000FDA0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8000FDA4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000FDA8: addiu       $s0, $t7, 0x80
    ctx->r16 = ADD32(ctx->r15, 0X80);
    // 0x8000FDAC: jal         0x80070F50
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000FDB4: bne         $v0, $zero, L_8000FDD0
    if (ctx->r2 != 0) {
        // 0x8000FDB8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000FDD0;
    }
    // 0x8000FDB8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000FDBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FDC0: jal         0x8000C844
    // 0x8000FDC4: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FDC4: nop

    after_2:
    // 0x8000FDC8: b           L_8000FF98
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FDD0:
    // 0x8000FDD0: blez        $s0, L_8000FE20
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8000FDD4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000FE20;
    }
    // 0x8000FDD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000FDD8: andi        $a1, $s0, 0x3
    ctx->r5 = ctx->r16 & 0X3;
    // 0x8000FDDC: beq         $a1, $zero, L_8000FDFC
    if (ctx->r5 == 0) {
        // 0x8000FDE0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000FDFC;
    }
    // 0x8000FDE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000FDE4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8000FDE8:
    // 0x8000FDE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FDEC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FDF0: bne         $a0, $s1, L_8000FDE8
    if (ctx->r4 != ctx->r17) {
        // 0x8000FDF4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FDE8;
    }
    // 0x8000FDF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FDF8: beq         $s1, $s0, L_8000FE1C
    if (ctx->r17 == ctx->r16) {
        // 0x8000FDFC: addu        $v1, $v0, $s1
        ctx->r3 = ADD32(ctx->r2, ctx->r17);
            goto L_8000FE1C;
    }
L_8000FDFC:
    // 0x8000FDFC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
L_8000FE00:
    // 0x8000FE00: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000FE04: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FE08: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8000FE0C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000FE10: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000FE14: bne         $s1, $s0, L_8000FE00
    if (ctx->r17 != ctx->r16) {
        // 0x8000FE18: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000FE00;
    }
    // 0x8000FE18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000FE1C:
    // 0x8000FE1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FE20:
    // 0x8000FE20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000FE24: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x8000FE28: sw          $s3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r19;
    // 0x8000FE2C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE30: nop

    // 0x8000FE34: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x8000FE38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE3C: nop

    // 0x8000FE40: sh          $t0, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r8;
    // 0x8000FE44: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000FE48: nop

    // 0x8000FE4C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8000FE50: lhu         $t1, 0x30($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X30);
    // 0x8000FE54: nop

    // 0x8000FE58: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000FE5C: beq         $t2, $zero, L_8000FE74
    if (ctx->r10 == 0) {
        // 0x8000FE60: nop
    
            goto L_8000FE74;
    }
    // 0x8000FE60: nop

    // 0x8000FE64: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8000FE68: nop

    // 0x8000FE6C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8000FE70: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
L_8000FE74:
    // 0x8000FE74: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000FE78: addiu       $t6, $v0, 0x80
    ctx->r14 = ADD32(ctx->r2, 0X80);
    // 0x8000FE7C: lb          $t5, 0x53($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X53);
    // 0x8000FE80: lb          $s4, 0x55($v1)
    ctx->r20 = MEM_B(ctx->r3, 0X55);
    // 0x8000FE84: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8000FE88: sw          $t6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r14;
    // 0x8000FE8C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000FE90: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000FE94: bne         $t7, $zero, L_8000FF04
    if (ctx->r15 != 0) {
        // 0x8000FE98: nop
    
            goto L_8000FF04;
    }
    // 0x8000FE98: nop

    // 0x8000FE9C: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FEA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FEA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FEA4:
    // 0x8000FEA4: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000FEA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000FEAC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8000FEB0: nop

    // 0x8000FEB4: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FEB8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8000FEBC: jal         0x8005FB3C
    // 0x8000FEC0: nop

    object_model_init(rdram, ctx);
        goto after_3;
    // 0x8000FEC0: nop

    after_3:
    // 0x8000FEC4: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FEC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FECC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FED0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8000FED4: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000FED8: nop

    // 0x8000FEDC: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000FEE0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000FEE4: nop

    // 0x8000FEE8: bne         $t5, $zero, L_8000FEF4
    if (ctx->r13 != 0) {
        // 0x8000FEEC: nop
    
            goto L_8000FEF4;
    }
    // 0x8000FEEC: nop

    // 0x8000FEF0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FEF4:
    // 0x8000FEF4: bne         $s1, $s4, L_8000FEA4
    if (ctx->r17 != ctx->r20) {
        // 0x8000FEF8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FEA4;
    }
    // 0x8000FEF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000FEFC: b           L_8000FF64
    // 0x8000FF00: nop

        goto L_8000FF64;
    // 0x8000FF00: nop

L_8000FF04:
    // 0x8000FF04: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FF08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FF08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FF0C:
    // 0x8000FF0C: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x8000FF10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000FF14: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8000FF18: nop

    // 0x8000FF1C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000FF20: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8000FF24: jal         0x8007C57C
    // 0x8000FF28: nop

    tex_load_sprite(rdram, ctx);
        goto after_4;
    // 0x8000FF28: nop

    after_4:
    // 0x8000FF2C: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FF34: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FF38: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000FF3C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF40: nop

    // 0x8000FF44: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FF48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000FF4C: nop

    // 0x8000FF50: bne         $t3, $zero, L_8000FF5C
    if (ctx->r11 != 0) {
        // 0x8000FF54: nop
    
            goto L_8000FF5C;
    }
    // 0x8000FF54: nop

    // 0x8000FF58: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FF5C:
    // 0x8000FF5C: bne         $s1, $s4, L_8000FF0C
    if (ctx->r17 != ctx->r20) {
        // 0x8000FF60: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FF0C;
    }
    // 0x8000FF60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000FF64:
    // 0x8000FF64: beq         $s3, $zero, L_8000FF98
    if (ctx->r19 == 0) {
        // 0x8000FF68: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_8000FF98;
    }
    // 0x8000FF68: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000FF6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000FF70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000FF74: jal         0x8000F648
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    objFreeAssets(rdram, ctx);
        goto after_5;
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x8000FF7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FF80: jal         0x8000C844
    // 0x8000FF84: nop

    try_free_object_header(rdram, ctx);
        goto after_6;
    // 0x8000FF84: nop

    after_6:
    // 0x8000FF88: jal         0x80071380
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8000FF90: b           L_8000FF98
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FF98:
    // 0x8000FF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FF9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FFA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FFA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FFAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FFB0: jr          $ra
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void free_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FFBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FFC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000FFC4: lh          $a0, 0x4A($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4A);
    // 0x8000FFC8: nop

    // 0x8000FFCC: ori         $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 | 0X8000;
    // 0x8000FFD0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000FFD4: jal         0x800245E8
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_0:
    // 0x8000FFDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000FFE0: addiu       $v0, $v0, -0x4BB8
    ctx->r2 = ADD32(ctx->r2, -0X4BB8);
    // 0x8000FFE4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000FFE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000FFEC: lw          $t1, -0x4BBC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BBC);
    // 0x8000FFF0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000FFF8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000FFFC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x80010000: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80010004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010008: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001000C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80010010: jr          $ra
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_table_ids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001001C: lw          $v0, -0x4BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BC4);
    // 0x80010020: jr          $ra
    // 0x80010024: nop

    return;
    // 0x80010024: nop

;}
RECOMP_FUNC void obj_id_valid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010028: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001002C: lw          $t6, -0x4BC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BC8);
    // 0x80010030: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80010034: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010038: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001003C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80010040: lw          $t0, -0x4D18($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4D18);
    // 0x80010044: jr          $ra
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    return;
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
;}
RECOMP_FUNC void gParticlePtrList_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001004C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80010050: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80010054: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80010058: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001005C: addiu       $s7, $s7, -0x4BB8
    ctx->r23 = ADD32(ctx->r23, -0X4BB8);
    // 0x80010060: sw          $zero, -0x4BF8($at)
    MEM_W(-0X4BF8, ctx->r1) = 0;
    // 0x80010064: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80010068: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001006C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010070: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80010074: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80010078: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001007C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80010080: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010084: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010088: blez        $t6, L_8001017C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001008C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001017C;
    }
    // 0x8001008C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010090: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010094: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80010098: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001009C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800100A0: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    // 0x800100A4: addiu       $s1, $s1, -0x4C28
    ctx->r17 = ADD32(ctx->r17, -0X4C28);
    // 0x800100A8: addiu       $s4, $s4, -0x4C04
    ctx->r20 = ADD32(ctx->r20, -0X4C04);
    // 0x800100AC: addiu       $s5, $s5, -0x4BBC
    ctx->r21 = ADD32(ctx->r21, -0X4BBC);
    // 0x800100B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800100B4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800100B8:
    // 0x800100B8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800100BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800100C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800100C4: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x800100C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800100CC: blez        $a1, L_80010100
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800100D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80010100;
    }
    // 0x800100D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800100D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800100D8: nop

L_800100DC:
    // 0x800100DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800100E0: nop

    // 0x800100E4: bne         $a2, $t9, L_800100F0
    if (ctx->r6 != ctx->r25) {
        // 0x800100E8: nop
    
            goto L_800100F0;
    }
    // 0x800100E8: nop

    // 0x800100EC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800100F0:
    // 0x800100F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800100F4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800100F8: bne         $at, $zero, L_800100DC
    if (ctx->r1 != 0) {
        // 0x800100FC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800100DC;
    }
    // 0x800100FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010100:
    // 0x80010100: beq         $a0, $s6, L_8001015C
    if (ctx->r4 == ctx->r22) {
        // 0x80010104: addiu       $t1, $a1, -0x1
        ctx->r9 = ADD32(ctx->r5, -0X1);
            goto L_8001015C;
    }
    // 0x80010104: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80010108: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8001010C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80010110: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010114: beq         $at, $zero, L_80010120
    if (ctx->r1 == 0) {
        // 0x80010118: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80010120;
    }
    // 0x80010118: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8001011C: sh          $t0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r8;
L_80010120:
    // 0x80010120: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80010124: beq         $at, $zero, L_8001015C
    if (ctx->r1 == 0) {
        // 0x80010128: sw          $t1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r9;
            goto L_8001015C;
    }
    // 0x80010128: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8001012C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_80010130:
    // 0x80010130: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80010134: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80010138: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8001013C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80010140: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010144: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80010148: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001014C: nop

    // 0x80010150: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80010154: bne         $at, $zero, L_80010130
    if (ctx->r1 != 0) {
        // 0x80010158: nop
    
            goto L_80010130;
    }
    // 0x80010158: nop

L_8001015C:
    // 0x8001015C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80010160: jal         0x800101AC
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    obj_destroy(rdram, ctx);
        goto after_0;
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80010168: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8001016C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010170: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80010174: bne         $at, $zero, L_800100B8
    if (ctx->r1 != 0) {
        // 0x80010178: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800100B8;
    }
    // 0x80010178: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001017C:
    // 0x8001017C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010180: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x80010184: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80010188: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001018C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010190: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80010194: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80010198: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001019C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800101A0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800101A4: jr          $ra
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800101AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800101B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800101B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800101B8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800101BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800101C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800101C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800101C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800101CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800101D0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800101D4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x800101D8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800101DC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800101E0: beq         $t7, $zero, L_8001020C
    if (ctx->r15 == 0) {
        // 0x800101E4: nop
    
            goto L_8001020C;
    }
    // 0x800101E4: nop

    // 0x800101E8: jal         0x800B25A0
    // 0x800101EC: nop

    particle_deallocate(rdram, ctx);
        goto after_0;
    // 0x800101EC: nop

    after_0:
    // 0x800101F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800101F4: addiu       $v0, $v0, -0x4C1C
    ctx->r2 = ADD32(ctx->r2, -0X4C1C);
    // 0x800101F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800101FC: nop

    // 0x80010200: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80010204: b           L_8001096C
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8001096C;
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001020C:
    // 0x8001020C: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x80010210: nop

    // 0x80010214: beq         $v1, $zero, L_800102E4
    if (ctx->r3 == 0) {
        // 0x80010218: nop
    
            goto L_800102E4;
    }
    // 0x80010218: nop

    // 0x8001021C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010220: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010224: blez        $t0, L_800102E4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010228: nop
    
            goto L_800102E4;
    }
    // 0x80010228: nop

    // 0x8001022C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010230: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_80010234:
    // 0x80010234: lw          $s1, 0x4($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X4);
    // 0x80010238: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001023C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80010240: nop

    // 0x80010244: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x80010248: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x8001024C: bne         $a0, $zero, L_80010288
    if (ctx->r4 != 0) {
        // 0x80010250: nop
    
            goto L_80010288;
    }
    // 0x80010250: nop

    // 0x80010254: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80010258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x80010258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001025C:
    // 0x8001025C: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80010260: nop

    // 0x80010264: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80010268: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8001026C: jal         0x80060180
    // 0x80010270: nop

    free_3d_model(rdram, ctx);
        goto after_1;
    // 0x80010270: nop

    after_1:
    // 0x80010274: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010278: bne         $s3, $s2, L_8001025C
    if (ctx->r19 != ctx->r18) {
        // 0x8001027C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001025C;
    }
    // 0x8001027C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010280: b           L_800102B8
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
        goto L_800102B8;
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_80010288:
    // 0x80010288: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001028C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x8001028C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010290:
    // 0x80010290: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80010294: nop

    // 0x80010298: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8001029C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800102A0: jal         0x8007D100
    // 0x800102A4: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800102A4: nop

    after_2:
    // 0x800102A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800102AC: bne         $s3, $s2, L_80010290
    if (ctx->r19 != ctx->r18) {
        // 0x800102B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010290;
    }
    // 0x800102B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800102B4:
    // 0x800102B4: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_800102B8:
    // 0x800102B8: jal         0x8000C844
    // 0x800102BC: nop

    try_free_object_header(rdram, ctx);
        goto after_3;
    // 0x800102BC: nop

    after_3:
    // 0x800102C0: jal         0x80071380
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800102C8: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x800102CC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800102D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800102D4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800102D8: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800102DC: bne         $at, $zero, L_80010234
    if (ctx->r1 != 0) {
        // 0x800102E0: addu        $t1, $v1, $s4
        ctx->r9 = ADD32(ctx->r3, ctx->r20);
            goto L_80010234;
    }
    // 0x800102E0: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_800102E4:
    // 0x800102E4: lw          $t7, 0x70($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X70);
    // 0x800102E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800102EC: beq         $t7, $zero, L_80010344
    if (ctx->r15 == 0) {
        // 0x800102F0: nop
    
            goto L_80010344;
    }
    // 0x800102F0: nop

    // 0x800102F4: lw          $t8, 0x40($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X40);
    // 0x800102F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800102FC: lb          $t9, 0x5A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X5A);
    // 0x80010300: nop

    // 0x80010304: blez        $t9, L_80010344
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80010308: nop
    
            goto L_80010344;
    }
    // 0x80010308: nop

    // 0x8001030C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80010310:
    // 0x80010310: lw          $t0, 0x70($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X70);
    // 0x80010314: nop

    // 0x80010318: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8001031C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010320: jal         0x80032BEC
    // 0x80010324: nop

    light_remove(rdram, ctx);
        goto after_5;
    // 0x80010324: nop

    after_5:
    // 0x80010328: lw          $t2, 0x40($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X40);
    // 0x8001032C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80010330: lb          $t3, 0x5A($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X5A);
    // 0x80010334: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80010338: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001033C: bne         $at, $zero, L_80010310
    if (ctx->r1 != 0) {
        // 0x80010340: nop
    
            goto L_80010310;
    }
    // 0x80010340: nop

L_80010344:
    // 0x80010344: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010348: nop

    // 0x8001034C: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x80010350: sltiu       $at, $t4, 0x74
    ctx->r1 = ctx->r12 < 0X74 ? 1 : 0;
    // 0x80010354: beq         $at, $zero, L_800105F8
    if (ctx->r1 == 0) {
        // 0x80010358: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800105F8;
    }
    // 0x80010358: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001035C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80010360: addu        $at, $at, $t4
    gpr jr_addend_8001036C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80010364: lw          $t4, 0x57E0($at)
    ctx->r12 = ADD32(ctx->r1, 0X57E0);
    // 0x80010368: nop

    // 0x8001036C: jr          $t4
    // 0x80010370: nop

    switch (jr_addend_8001036C >> 2) {
        case 0: goto L_80010374; break;
        case 1: goto L_800105F8; break;
        case 2: goto L_800105F8; break;
        case 3: goto L_800105F8; break;
        case 4: goto L_80010400; break;
        case 5: goto L_800105F8; break;
        case 6: goto L_800105F8; break;
        case 7: goto L_800105F8; break;
        case 8: goto L_800105F8; break;
        case 9: goto L_800105F8; break;
        case 10: goto L_800105F8; break;
        case 11: goto L_800105F8; break;
        case 12: goto L_800105F8; break;
        case 13: goto L_800105F8; break;
        case 14: goto L_800105F8; break;
        case 15: goto L_800105F8; break;
        case 16: goto L_800105F8; break;
        case 17: goto L_80010400; break;
        case 18: goto L_800105F8; break;
        case 19: goto L_800105F8; break;
        case 20: goto L_800105F8; break;
        case 21: goto L_800105F8; break;
        case 22: goto L_800105F8; break;
        case 23: goto L_800105F8; break;
        case 24: goto L_800105F8; break;
        case 25: goto L_800105F8; break;
        case 26: goto L_800105F8; break;
        case 27: goto L_800105F8; break;
        case 28: goto L_800105F8; break;
        case 29: goto L_800105F8; break;
        case 30: goto L_800105F8; break;
        case 31: goto L_800105F8; break;
        case 32: goto L_800104C0; break;
        case 33: goto L_800105F8; break;
        case 34: goto L_800105F8; break;
        case 35: goto L_800105A8; break;
        case 36: goto L_800105F8; break;
        case 37: goto L_800105F8; break;
        case 38: goto L_800105F8; break;
        case 39: goto L_800105F8; break;
        case 40: goto L_800105F8; break;
        case 41: goto L_800105F8; break;
        case 42: goto L_800105D0; break;
        case 43: goto L_800105E4; break;
        case 44: goto L_800105F8; break;
        case 45: goto L_800105F8; break;
        case 46: goto L_800105F8; break;
        case 47: goto L_800105F8; break;
        case 48: goto L_800104D8; break;
        case 49: goto L_800105F8; break;
        case 50: goto L_800105F8; break;
        case 51: goto L_800105F8; break;
        case 52: goto L_800105F8; break;
        case 53: goto L_800105F8; break;
        case 54: goto L_800105F8; break;
        case 55: goto L_800105F8; break;
        case 56: goto L_800105F8; break;
        case 57: goto L_800105F8; break;
        case 58: goto L_800104AC; break;
        case 59: goto L_800105F8; break;
        case 60: goto L_800105F8; break;
        case 61: goto L_800105F8; break;
        case 62: goto L_800105F8; break;
        case 63: goto L_800105F8; break;
        case 64: goto L_800105F8; break;
        case 65: goto L_800105F8; break;
        case 66: goto L_800105A8; break;
        case 67: goto L_800105F8; break;
        case 68: goto L_800105F8; break;
        case 69: goto L_800105F8; break;
        case 70: goto L_800105F8; break;
        case 71: goto L_800105F8; break;
        case 72: goto L_800105F8; break;
        case 73: goto L_800105F8; break;
        case 74: goto L_800105F8; break;
        case 75: goto L_800105F8; break;
        case 76: goto L_800105F8; break;
        case 77: goto L_800105F8; break;
        case 78: goto L_800105F8; break;
        case 79: goto L_800105F8; break;
        case 80: goto L_800105F8; break;
        case 81: goto L_800105F8; break;
        case 82: goto L_80010508; break;
        case 83: goto L_800105F8; break;
        case 84: goto L_80010374; break;
        case 85: goto L_800105F8; break;
        case 86: goto L_800105F8; break;
        case 87: goto L_800105F8; break;
        case 88: goto L_800105F8; break;
        case 89: goto L_800105F8; break;
        case 90: goto L_800105F8; break;
        case 91: goto L_800105F8; break;
        case 92: goto L_800105F8; break;
        case 93: goto L_800105F8; break;
        case 94: goto L_800105F8; break;
        case 95: goto L_8001047C; break;
        case 96: goto L_8001047C; break;
        case 97: goto L_800105F8; break;
        case 98: goto L_800105F8; break;
        case 99: goto L_800105F8; break;
        case 100: goto L_8001047C; break;
        case 101: goto L_8001047C; break;
        case 102: goto L_800105F8; break;
        case 103: goto L_800105F8; break;
        case 104: goto L_800105F8; break;
        case 105: goto L_800105F8; break;
        case 106: goto L_800105F8; break;
        case 107: goto L_800105F8; break;
        case 108: goto L_800105F8; break;
        case 109: goto L_800105F8; break;
        case 110: goto L_800105F8; break;
        case 111: goto L_800105F8; break;
        case 112: goto L_800105F8; break;
        case 113: goto L_800105F8; break;
        case 114: goto L_800105F8; break;
        case 115: goto L_8001044C; break;
        default: switch_error(__func__, 0x8001036C, 0x800E57E0);
    }
    // 0x80010370: nop

L_80010374:
    // 0x80010374: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010378: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001037C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010380: blez        $v1, L_800103F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010384: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800103F8;
    }
    // 0x80010384: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001038C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
L_80010390:
    // 0x80010390: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80010394: lw          $t5, -0x4C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C28);
    // 0x80010398: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001039C: addu        $t6, $t5, $s4
    ctx->r14 = ADD32(ctx->r13, ctx->r20);
    // 0x800103A0: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800103A4: nop

    // 0x800103A8: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x800103AC: nop

    // 0x800103B0: bne         $a0, $t7, L_800103E8
    if (ctx->r4 != ctx->r15) {
        // 0x800103B4: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103B4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103B8: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x800103BC: nop

    // 0x800103C0: lw          $t8, 0x100($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X100);
    // 0x800103C4: nop

    // 0x800103C8: bne         $s6, $t8, L_800103E8
    if (ctx->r22 != ctx->r24) {
        // 0x800103CC: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103CC: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103D0: sw          $zero, 0x100($v0)
    MEM_W(0X100, ctx->r2) = 0;
    // 0x800103D4: sb          $a1, 0xFD($v0)
    MEM_B(0XFD, ctx->r2) = ctx->r5;
    // 0x800103D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800103DC: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800103E0: nop

    // 0x800103E4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
L_800103E8:
    // 0x800103E8: bne         $at, $zero, L_80010390
    if (ctx->r1 != 0) {
        // 0x800103EC: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80010390;
    }
    // 0x800103EC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800103F0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800103F4: nop

L_800103F8:
    // 0x800103F8: b           L_800105FC
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010400:
    // 0x80010400: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010404: nop

    // 0x80010408: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8001040C: nop

    // 0x80010410: beq         $a0, $zero, L_80010444
    if (ctx->r4 == 0) {
        // 0x80010414: nop
    
            goto L_80010444;
    }
    // 0x80010414: nop

    // 0x80010418: jal         0x800096F8
    // 0x8001041C: nop

    audspat_point_stop(rdram, ctx);
        goto after_6;
    // 0x8001041C: nop

    after_6:
    // 0x80010420: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80010424: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010428: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x8001042C: bne         $s4, $a1, L_80010444
    if (ctx->r20 != ctx->r5) {
        // 0x80010430: nop
    
            goto L_80010444;
    }
    // 0x80010430: nop

    // 0x80010434: jal         0x8003F11C
    // 0x80010438: nop

    decrease_rocket_sound_timer(rdram, ctx);
        goto after_7;
    // 0x80010438: nop

    after_7:
    // 0x8001043C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010440: nop

L_80010444:
    // 0x80010444: b           L_800105FC
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001044C:
    // 0x8001044C: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010450: nop

    // 0x80010454: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80010458: nop

    // 0x8001045C: beq         $a0, $zero, L_80010474
    if (ctx->r4 == 0) {
        // 0x80010460: nop
    
            goto L_80010474;
    }
    // 0x80010460: nop

    // 0x80010464: jal         0x800096F8
    // 0x80010468: nop

    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x80010468: nop

    after_8:
    // 0x8001046C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010470: nop

L_80010474:
    // 0x80010474: b           L_800105FC
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001047C:
    // 0x8001047C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010480: nop

    // 0x80010484: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x80010488: nop

    // 0x8001048C: beq         $v1, $zero, L_800104A4
    if (ctx->r3 == 0) {
        // 0x80010490: nop
    
            goto L_800104A4;
    }
    // 0x80010490: nop

    // 0x80010494: jal         0x800096F8
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_9;
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_9:
    // 0x8001049C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104A0: nop

L_800104A4:
    // 0x800104A4: b           L_800105FC
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104AC:
    // 0x800104AC: jal         0x800BF904
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    wavegen_destroy(rdram, ctx);
        goto after_10;
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_10:
    // 0x800104B4: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104B8: b           L_800105FC
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104C0:
    // 0x800104C0: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104C4: jal         0x80032BEC
    // 0x800104C8: nop

    light_remove(rdram, ctx);
        goto after_11;
    // 0x800104C8: nop

    after_11:
    // 0x800104CC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104D0: b           L_800105FC
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104D8:
    // 0x800104D8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800104E0: beq         $a0, $zero, L_80010500
    if (ctx->r4 == 0) {
        // 0x800104E4: nop
    
            goto L_80010500;
    }
    // 0x800104E4: nop

    // 0x800104E8: bne         $t9, $zero, L_80010500
    if (ctx->r25 != 0) {
        // 0x800104EC: nop
    
            goto L_80010500;
    }
    // 0x800104EC: nop

    // 0x800104F0: jal         0x8000FFB8
    // 0x800104F4: nop

    free_object(rdram, ctx);
        goto after_12;
    // 0x800104F4: nop

    after_12:
    // 0x800104F8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104FC: nop

L_80010500:
    // 0x80010500: b           L_800105FC
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010508:
    // 0x80010508: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001050C: addiu       $a0, $a0, -0x4C80
    ctx->r4 = ADD32(ctx->r4, -0X4C80);
    // 0x80010510: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010514: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010518: blez        $v1, L_80010554
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001051C: addiu       $s4, $zero, 0x12
        ctx->r20 = ADD32(0, 0X12);
            goto L_80010554;
    }
    // 0x8001051C: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x80010520: lw          $t0, -0x4CA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4CA8);
    // 0x80010524: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010528: beq         $s6, $t0, L_80010554
    if (ctx->r22 == ctx->r8) {
        // 0x8001052C: addiu       $v0, $v0, -0x4CA8
        ctx->r2 = ADD32(ctx->r2, -0X4CA8);
            goto L_80010554;
    }
    // 0x8001052C: addiu       $v0, $v0, -0x4CA8
    ctx->r2 = ADD32(ctx->r2, -0X4CA8);
L_80010530:
    // 0x80010530: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010534: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010538: beq         $at, $zero, L_80010554
    if (ctx->r1 == 0) {
        // 0x8001053C: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_80010554;
    }
    // 0x8001053C: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80010540: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80010544: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80010548: nop

    // 0x8001054C: bne         $s6, $t3, L_80010530
    if (ctx->r22 != ctx->r11) {
        // 0x80010550: nop
    
            goto L_80010530;
    }
    // 0x80010550: nop

L_80010554:
    // 0x80010554: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010558: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x8001055C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8001059C;
    }
    // 0x8001055C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80010560: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80010564: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010568: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8001056C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010570: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x80010574: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001059C;
    }
    // 0x80010574: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80010578: addiu       $t6, $t6, -0x4CA8
    ctx->r14 = ADD32(ctx->r14, -0X4CA8);
    // 0x8001057C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80010580: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    // 0x80010584: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_80010588:
    // 0x80010588: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8001058C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010590: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80010594: bne         $at, $zero, L_80010588
    if (ctx->r1 != 0) {
        // 0x80010598: sw          $t8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r24;
            goto L_80010588;
    }
    // 0x80010598: sw          $t8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r24;
L_8001059C:
    // 0x8001059C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105A0: b           L_800105FC
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800105FC;
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800105A8:
    // 0x800105A8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800105AC: nop

    // 0x800105B0: beq         $a0, $zero, L_800105C8
    if (ctx->r4 == 0) {
        // 0x800105B4: nop
    
            goto L_800105C8;
    }
    // 0x800105B4: nop

    // 0x800105B8: jal         0x80071380
    // 0x800105BC: nop

    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800105BC: nop

    after_13:
    // 0x800105C0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105C4: nop

L_800105C8:
    // 0x800105C8: b           L_800105FC
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105D0:
    // 0x800105D0: jal         0x800ACDE0
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_remove(rdram, ctx);
        goto after_14;
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_14:
    // 0x800105D8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105DC: b           L_800105FC
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105E4:
    // 0x800105E4: jal         0x800AD4F8
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_override_remove(rdram, ctx);
        goto after_15;
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_15:
    // 0x800105EC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105F0: b           L_800105FC
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105F8:
    // 0x800105F8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105FC:
    // 0x800105FC: slti        $at, $a1, 0xD
    ctx->r1 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // 0x80010600: bne         $at, $zero, L_80010630
    if (ctx->r1 != 0) {
        // 0x80010604: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80010630;
    }
    // 0x80010604: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80010608: addiu       $t9, $v0, -0x32
    ctx->r25 = ADD32(ctx->r2, -0X32);
    // 0x8001060C: sltiu       $at, $t9, 0x46
    ctx->r1 = ctx->r25 < 0X46 ? 1 : 0;
    // 0x80010610: beq         $at, $zero, L_80010664
    if (ctx->r1 == 0) {
        // 0x80010614: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80010664;
    }
    // 0x80010614: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80010618: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001061C: addu        $at, $at, $t9
    gpr jr_addend_80010628 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80010620: lw          $t9, 0x59B0($at)
    ctx->r25 = ADD32(ctx->r1, 0X59B0);
    // 0x80010624: nop

    // 0x80010628: jr          $t9
    // 0x8001062C: nop

    switch (jr_addend_80010628 >> 2) {
        case 0: goto L_8001063C; break;
        case 1: goto L_8001063C; break;
        case 2: goto L_80010664; break;
        case 3: goto L_8001063C; break;
        case 4: goto L_8001063C; break;
        case 5: goto L_80010664; break;
        case 6: goto L_8001063C; break;
        case 7: goto L_80010664; break;
        case 8: goto L_80010664; break;
        case 9: goto L_80010664; break;
        case 10: goto L_80010664; break;
        case 11: goto L_80010664; break;
        case 12: goto L_80010664; break;
        case 13: goto L_80010664; break;
        case 14: goto L_80010664; break;
        case 15: goto L_80010664; break;
        case 16: goto L_80010664; break;
        case 17: goto L_80010664; break;
        case 18: goto L_80010664; break;
        case 19: goto L_80010664; break;
        case 20: goto L_8001063C; break;
        case 21: goto L_80010664; break;
        case 22: goto L_8001063C; break;
        case 23: goto L_80010664; break;
        case 24: goto L_80010664; break;
        case 25: goto L_80010664; break;
        case 26: goto L_80010664; break;
        case 27: goto L_80010664; break;
        case 28: goto L_80010664; break;
        case 29: goto L_80010664; break;
        case 30: goto L_8001063C; break;
        case 31: goto L_8001063C; break;
        case 32: goto L_80010664; break;
        case 33: goto L_80010664; break;
        case 34: goto L_8001063C; break;
        case 35: goto L_8001063C; break;
        case 36: goto L_8001063C; break;
        case 37: goto L_80010664; break;
        case 38: goto L_80010664; break;
        case 39: goto L_80010664; break;
        case 40: goto L_80010664; break;
        case 41: goto L_80010664; break;
        case 42: goto L_80010664; break;
        case 43: goto L_80010664; break;
        case 44: goto L_80010664; break;
        case 45: goto L_80010664; break;
        case 46: goto L_8001063C; break;
        case 47: goto L_8001063C; break;
        case 48: goto L_80010664; break;
        case 49: goto L_80010664; break;
        case 50: goto L_80010664; break;
        case 51: goto L_8001063C; break;
        case 52: goto L_8001063C; break;
        case 53: goto L_8001063C; break;
        case 54: goto L_8001063C; break;
        case 55: goto L_80010664; break;
        case 56: goto L_80010664; break;
        case 57: goto L_80010664; break;
        case 58: goto L_80010664; break;
        case 59: goto L_80010664; break;
        case 60: goto L_80010664; break;
        case 61: goto L_80010664; break;
        case 62: goto L_80010664; break;
        case 63: goto L_8001063C; break;
        case 64: goto L_80010664; break;
        case 65: goto L_8001063C; break;
        case 66: goto L_80010664; break;
        case 67: goto L_80010664; break;
        case 68: goto L_80010664; break;
        case 69: goto L_8001063C; break;
        default: switch_error(__func__, 0x80010628, 0x800E59B0);
    }
    // 0x8001062C: nop

L_80010630:
    // 0x80010630: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80010634: bne         $v0, $at, L_80010668
    if (ctx->r2 != ctx->r1) {
        // 0x80010638: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8001063C:
    // 0x8001063C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010640: nop

    // 0x80010644: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80010648: nop

    // 0x8001064C: beq         $a0, $zero, L_80010668
    if (ctx->r4 == 0) {
        // 0x80010650: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010650: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010654: jal         0x8000488C
    // 0x80010658: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x80010658: nop

    after_16:
    // 0x8001065C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010660: nop

L_80010664:
    // 0x80010664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80010668:
    // 0x80010668: bne         $a1, $at, L_800107F0
    if (ctx->r5 != ctx->r1) {
        // 0x8001066C: nop
    
            goto L_800107F0;
    }
    // 0x8001066C: nop

    // 0x80010670: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010674: nop

    // 0x80010678: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8001067C: nop

    // 0x80010680: beq         $v0, $zero, L_80010690
    if (ctx->r2 == 0) {
        // 0x80010684: nop
    
            goto L_80010690;
    }
    // 0x80010684: nop

    // 0x80010688: jal         0x8000488C
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_17;
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
L_80010690:
    // 0x80010690: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80010694: nop

    // 0x80010698: beq         $v0, $zero, L_800106A8
    if (ctx->r2 == 0) {
        // 0x8001069C: nop
    
            goto L_800106A8;
    }
    // 0x8001069C: nop

    // 0x800106A0: jal         0x8000488C
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_18;
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
L_800106A8:
    // 0x800106A8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800106AC: nop

    // 0x800106B0: beq         $v0, $zero, L_800106C0
    if (ctx->r2 == 0) {
        // 0x800106B4: nop
    
            goto L_800106C0;
    }
    // 0x800106B4: nop

    // 0x800106B8: jal         0x8000488C
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_19;
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
L_800106C0:
    // 0x800106C0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800106C4: nop

    // 0x800106C8: beq         $v0, $zero, L_800106D8
    if (ctx->r2 == 0) {
        // 0x800106CC: nop
    
            goto L_800106D8;
    }
    // 0x800106CC: nop

    // 0x800106D0: jal         0x8000488C
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
L_800106D8:
    // 0x800106D8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800106DC: nop

    // 0x800106E0: beq         $v0, $zero, L_800106F0
    if (ctx->r2 == 0) {
        // 0x800106E4: nop
    
            goto L_800106F0;
    }
    // 0x800106E4: nop

    // 0x800106E8: jal         0x8000488C
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
L_800106F0:
    // 0x800106F0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800106F4: nop

    // 0x800106F8: beq         $a0, $zero, L_80010708
    if (ctx->r4 == 0) {
        // 0x800106FC: nop
    
            goto L_80010708;
    }
    // 0x800106FC: nop

    // 0x80010700: jal         0x800096F8
    // 0x80010704: nop

    audspat_point_stop(rdram, ctx);
        goto after_22;
    // 0x80010704: nop

    after_22:
L_80010708:
    // 0x80010708: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8001070C: nop

    // 0x80010710: beq         $a0, $zero, L_80010720
    if (ctx->r4 == 0) {
        // 0x80010714: nop
    
            goto L_80010720;
    }
    // 0x80010714: nop

    // 0x80010718: jal         0x800096F8
    // 0x8001071C: nop

    audspat_point_stop(rdram, ctx);
        goto after_23;
    // 0x8001071C: nop

    after_23:
L_80010720:
    // 0x80010720: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x80010724: nop

    // 0x80010728: beq         $a0, $zero, L_80010738
    if (ctx->r4 == 0) {
        // 0x8001072C: nop
    
            goto L_80010738;
    }
    // 0x8001072C: nop

    // 0x80010730: jal         0x8000488C
    // 0x80010734: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80010734: nop

    after_24:
L_80010738:
    // 0x80010738: jal         0x80006AC8
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    racer_sound_free(rdram, ctx);
        goto after_25;
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_25:
    // 0x80010740: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010744: addiu       $s5, $s5, -0x4C24
    ctx->r21 = ADD32(ctx->r21, -0X4C24);
    // 0x80010748: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8001074C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010750: blez        $t0, L_800107F0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010754: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_800107F0;
    }
    // 0x80010754: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80010758: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_8001075C:
    // 0x8001075C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010760: lw          $t1, -0x4C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C28);
    // 0x80010764: nop

    // 0x80010768: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8001076C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80010770: nop

    // 0x80010774: lh          $t3, 0x6($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X6);
    // 0x80010778: nop

    // 0x8001077C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80010780: beq         $t4, $zero, L_800107B0
    if (ctx->r12 == 0) {
        // 0x80010784: nop
    
            goto L_800107B0;
    }
    // 0x80010784: nop

    // 0x80010788: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8001078C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010790: bne         $s6, $t5, L_800107B0
    if (ctx->r22 != ctx->r13) {
        // 0x80010794: nop
    
            goto L_800107B0;
    }
    // 0x80010794: nop

    // 0x80010798: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8001079C: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x800107A0: nop

    // 0x800107A4: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x800107A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800107AC: nop

L_800107B0:
    // 0x800107B0: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x800107B4: nop

    // 0x800107B8: beq         $s4, $v0, L_800107D0
    if (ctx->r20 == ctx->r2) {
        // 0x800107BC: nop
    
            goto L_800107D0;
    }
    // 0x800107BC: nop

    // 0x800107C0: beq         $s1, $v0, L_800107D0
    if (ctx->r17 == ctx->r2) {
        // 0x800107C4: nop
    
            goto L_800107D0;
    }
    // 0x800107C4: nop

    // 0x800107C8: bne         $s2, $v0, L_800107D8
    if (ctx->r18 != ctx->r2) {
        // 0x800107CC: nop
    
            goto L_800107D8;
    }
    // 0x800107CC: nop

L_800107D0:
    // 0x800107D0: jal         0x8000FFB8
    // 0x800107D4: nop

    free_object(rdram, ctx);
        goto after_26;
    // 0x800107D4: nop

    after_26:
L_800107D8:
    // 0x800107D8: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800107DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800107E0: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800107E4: bne         $at, $zero, L_8001075C
    if (ctx->r1 != 0) {
        // 0x800107E8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001075C;
    }
    // 0x800107E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800107EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800107F0:
    // 0x800107F0: lw          $v0, 0x50($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X50);
    // 0x800107F4: nop

    // 0x800107F8: beq         $v0, $zero, L_80010818
    if (ctx->r2 == 0) {
        // 0x800107FC: nop
    
            goto L_80010818;
    }
    // 0x800107FC: nop

    // 0x80010800: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80010804: nop

    // 0x80010808: beq         $a0, $zero, L_80010818
    if (ctx->r4 == 0) {
        // 0x8001080C: nop
    
            goto L_80010818;
    }
    // 0x8001080C: nop

    // 0x80010810: jal         0x8007B70C
    // 0x80010814: nop

    tex_free(rdram, ctx);
        goto after_27;
    // 0x80010814: nop

    after_27:
L_80010818:
    // 0x80010818: lw          $v0, 0x58($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X58);
    // 0x8001081C: nop

    // 0x80010820: beq         $v0, $zero, L_80010840
    if (ctx->r2 == 0) {
        // 0x80010824: nop
    
            goto L_80010840;
    }
    // 0x80010824: nop

    // 0x80010828: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8001082C: nop

    // 0x80010830: beq         $a0, $zero, L_80010840
    if (ctx->r4 == 0) {
        // 0x80010834: nop
    
            goto L_80010840;
    }
    // 0x80010834: nop

    // 0x80010838: jal         0x8007B70C
    // 0x8001083C: nop

    tex_free(rdram, ctx);
        goto after_28;
    // 0x8001083C: nop

    after_28:
L_80010840:
    // 0x80010840: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010844: nop

    // 0x80010848: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x8001084C: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x80010850: bne         $a0, $zero, L_800108A0
    if (ctx->r4 != 0) {
        // 0x80010854: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800108A0;
    }
    // 0x80010854: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80010858: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001085C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x8001085C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010860:
    // 0x80010860: lw          $t9, 0x68($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X68);
    // 0x80010864: nop

    // 0x80010868: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8001086C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80010870: nop

    // 0x80010874: beq         $v0, $zero, L_80010884
    if (ctx->r2 == 0) {
        // 0x80010878: nop
    
            goto L_80010884;
    }
    // 0x80010878: nop

    // 0x8001087C: jal         0x80060180
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_29;
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
L_80010884:
    // 0x80010884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010888: bne         $s3, $s2, L_80010860
    if (ctx->r19 != ctx->r18) {
        // 0x8001088C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010860;
    }
    // 0x8001088C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010890: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010894: b           L_80010918
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8001089C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800108A0:
    // 0x800108A0: bne         $a0, $at, L_800108E0
    if (ctx->r4 != ctx->r1) {
        // 0x800108A4: nop
    
            goto L_800108E0;
    }
    // 0x800108A4: nop

    // 0x800108A8: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108AC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108B0:
    // 0x800108B0: lw          $t1, 0x68($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X68);
    // 0x800108B4: nop

    // 0x800108B8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800108BC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800108C0: jal         0x8007B70C
    // 0x800108C4: nop

    tex_free(rdram, ctx);
        goto after_30;
    // 0x800108C4: nop

    after_30:
    // 0x800108C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800108CC: bne         $s3, $s2, L_800108B0
    if (ctx->r19 != ctx->r18) {
        // 0x800108D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108B0;
    }
    // 0x800108D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800108D4: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x800108D8: b           L_80010918
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_800108E0:
    // 0x800108E0: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108E4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108E8:
    // 0x800108E8: lw          $t3, 0x68($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X68);
    // 0x800108EC: nop

    // 0x800108F0: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800108F4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800108F8: jal         0x8007D100
    // 0x800108FC: nop

    sprite_free(rdram, ctx);
        goto after_31;
    // 0x800108FC: nop

    after_31:
    // 0x80010900: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010904: bne         $s3, $s2, L_800108E8
    if (ctx->r19 != ctx->r18) {
        // 0x80010908: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108E8;
    }
    // 0x80010908: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001090C: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010910: nop

L_80010914:
    // 0x80010914: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_80010918:
    // 0x80010918: nop

    // 0x8001091C: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010920: nop
    
            goto L_80010958;
    }
    // 0x80010920: nop

    // 0x80010924: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010928: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80010958;
    }
    // 0x80010928: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8001092C:
    // 0x8001092C: lw          $t5, 0x6C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X6C);
    // 0x80010930: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x80010934: jal         0x800B27C0
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    emitter_cleanup(rdram, ctx);
        goto after_32;
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    after_32:
    // 0x8001093C: lw          $t6, 0x40($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X40);
    // 0x80010940: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010944: lb          $t8, 0x57($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X57);
    // 0x80010948: nop

    // 0x8001094C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80010950: bne         $at, $zero, L_8001092C
    if (ctx->r1 != 0) {
        // 0x80010954: nop
    
            goto L_8001092C;
    }
    // 0x80010954: nop

L_80010958:
    // 0x80010958: lh          $a0, 0x2C($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X2C);
    // 0x8001095C: jal         0x8000C844
    // 0x80010960: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x80010960: nop

    after_33:
    // 0x80010964: jal         0x80071380
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_34;
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_34:
L_8001096C:
    // 0x8001096C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010974: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80010978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001097C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80010980: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80010984: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80010988: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001098C: jr          $ra
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010994: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80010998: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001099C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800109A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800109A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800109A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800109AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800109B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800109B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800109B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800109BC: jal         0x800245E8
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x800109C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800109C8: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x800109CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800109D0: blez        $v0, L_80010A08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800109D4: sw          $v0, -0x4CC8($at)
        MEM_W(-0X4CC8, ctx->r1) = ctx->r2;
            goto L_80010A08;
    }
    // 0x800109D4: sw          $v0, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = ctx->r2;
    // 0x800109D8: jal         0x800A06D0
    // 0x800109DC: nop

    race_starting(rdram, ctx);
        goto after_1;
    // 0x800109DC: nop

    after_1:
    // 0x800109E0: beq         $v0, $zero, L_80010A08
    if (ctx->r2 == 0) {
        // 0x800109E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80010A08;
    }
    // 0x800109E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800109E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800109EC: addiu       $a0, $a0, -0x4CD0
    ctx->r4 = ADD32(ctx->r4, -0X4CD0);
    // 0x800109F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800109F4: addiu       $v1, $v1, -0x4CC4
    ctx->r3 = ADD32(ctx->r3, -0X4CC4);
    // 0x800109F8: subu        $v0, $t6, $s4
    ctx->r2 = SUB32(ctx->r14, ctx->r20);
    // 0x800109FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80010A00: b           L_80010A28
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80010A28;
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80010A08:
    // 0x80010A08: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010A0C: addiu       $v1, $v1, -0x4CC4
    ctx->r3 = ADD32(ctx->r3, -0X4CC4);
    // 0x80010A10: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80010A14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A18: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x80010A1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80010A20: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x80010A24: nop

L_80010A28:
    // 0x80010A28: bgtz        $v0, L_80010A38
    if (SIGNED(ctx->r2) > 0) {
        // 0x80010A2C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80010A38;
    }
    // 0x80010A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80010A30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A34: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
L_80010A38:
    // 0x80010A38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A40: addiu       $v0, $v0, -0x4D5F
    ctx->r2 = ADD32(ctx->r2, -0X4D5F);
    // 0x80010A44: sb          $zero, -0x4D43($at)
    MEM_B(-0X4D43, ctx->r1) = 0;
    // 0x80010A48: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x80010A4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80010A50: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80010A54: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80010A58: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x80010A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A60: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80010A64: addiu       $a0, $a0, -0x4B90
    ctx->r4 = ADD32(ctx->r4, -0X4B90);
    // 0x80010A68: sb          $zero, -0x4D5E($at)
    MEM_B(-0X4D5E, ctx->r1) = 0;
    // 0x80010A6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80010A70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010A74: blez        $t4, L_80010AFC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010A78: lui         $s5, 0x8012
        ctx->r21 = S32(0X8012 << 16);
            goto L_80010AFC;
    }
    // 0x80010A78: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010A7C: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    // 0x80010A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80010A84:
    // 0x80010A84: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010A88: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010A8C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80010A90: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80010A94: nop

    // 0x80010A98: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x80010A9C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80010AA0: nop

    // 0x80010AA4: swc1        $f4, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f4.u32l;
    // 0x80010AA8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80010AAC: nop

    // 0x80010AB0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80010AB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80010AB8: nop

    // 0x80010ABC: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80010AC0: nop

    // 0x80010AC4: swc1        $f6, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f6.u32l;
    // 0x80010AC8: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80010ACC: nop

    // 0x80010AD0: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x80010AD4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80010AD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010ADC: lwc1        $f8, 0x14($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80010AE0: nop

    // 0x80010AE4: swc1        $f8, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->f8.u32l;
    // 0x80010AE8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80010AEC: nop

    // 0x80010AF0: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010AF4: bne         $at, $zero, L_80010A84
    if (ctx->r1 != 0) {
        // 0x80010AF8: nop
    
            goto L_80010A84;
    }
    // 0x80010AF8: nop

L_80010AFC:
    // 0x80010AFC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010B00: jal         0x800142B8
    // 0x80010B04: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    obj_tick_anims(rdram, ctx);
        goto after_2;
    // 0x80010B04: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    after_2:
    // 0x80010B08: jal         0x800155B8
    // 0x80010B0C: nop

    process_object_interactions(rdram, ctx);
        goto after_3;
    // 0x80010B0C: nop

    after_3:
    // 0x80010B10: jal         0x8001E8D0
    // 0x80010B14: nop

    func_8001E89C(rdram, ctx);
        goto after_4;
    // 0x80010B14: nop

    after_4:
    // 0x80010B18: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010B1C: addiu       $s3, $s3, -0x4C10
    ctx->r19 = ADD32(ctx->r19, -0X4C10);
    // 0x80010B20: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80010B24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010B28: blez        $t4, L_80010B68
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010B2C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80010B68;
    }
    // 0x80010B2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B30: addiu       $s0, $s0, -0x4C14
    ctx->r16 = ADD32(ctx->r16, -0X4C14);
    // 0x80010B34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B38:
    // 0x80010B38: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010B3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010B40: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010B44: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010B48: jal         0x80023F7C
    // 0x80010B4C: nop

    run_object_loop_func(rdram, ctx);
        goto after_5;
    // 0x80010B4C: nop

    after_5:
    // 0x80010B50: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80010B54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010B58: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010B5C: bne         $at, $zero, L_80010B38
    if (ctx->r1 != 0) {
        // 0x80010B60: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B38;
    }
    // 0x80010B60: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80010B68:
    // 0x80010B68: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B6C: addiu       $s0, $s0, -0x4C14
    ctx->r16 = ADD32(ctx->r16, -0X4C14);
    // 0x80010B70: jal         0x8001E720
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001E6EC(rdram, ctx);
        goto after_6;
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80010B78: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80010B7C: nop

    // 0x80010B80: blez        $t8, L_80010BB4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010B84: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80010BB4;
    }
    // 0x80010B84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B88:
    // 0x80010B88: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010B8C: nop

    // 0x80010B90: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010B94: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010B98: jal         0x800170D0
    // 0x80010B9C: nop

    obj_collision_transform(rdram, ctx);
        goto after_7;
    // 0x80010B9C: nop

    after_7:
    // 0x80010BA0: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80010BA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010BA8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80010BAC: bne         $at, $zero, L_80010B88
    if (ctx->r1 != 0) {
        // 0x80010BB0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B88;
    }
    // 0x80010BB0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010BB4:
    // 0x80010BB4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010BB8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010BBC: lw          $s3, -0x4C24($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4C24);
    // 0x80010BC0: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010BC4: nop

    // 0x80010BC8: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010BCC: beq         $at, $zero, L_80010D00
    if (ctx->r1 == 0) {
        // 0x80010BD0: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010D00;
    }
    // 0x80010BD0: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010BD4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80010BD8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010BDC: addiu       $s6, $s6, -0x4C28
    ctx->r22 = ADD32(ctx->r22, -0X4C28);
    // 0x80010BE0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80010BE4: addiu       $s1, $zero, 0x21
    ctx->r17 = ADD32(0, 0X21);
L_80010BE8:
    // 0x80010BE8: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010BEC: nop

    // 0x80010BF0: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010BF4: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010BF8: nop

    // 0x80010BFC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010C00: nop

    // 0x80010C04: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010C08: bne         $t6, $zero, L_80010CF0
    if (ctx->r14 != 0) {
        // 0x80010C0C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C0C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C10: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80010C14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010C18: beq         $s1, $v0, L_80010CF0
    if (ctx->r17 == ctx->r2) {
        // 0x80010C1C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C1C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C20: beq         $v0, $at, L_80010CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80010C24: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80010CEC;
    }
    // 0x80010C24: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010C28: beq         $v0, $at, L_80010CF0
    if (ctx->r2 == ctx->r1) {
        // 0x80010C2C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C2C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C30: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80010C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C38: beq         $v0, $zero, L_80010C60
    if (ctx->r2 == 0) {
        // 0x80010C3C: nop
    
            goto L_80010C60;
    }
    // 0x80010C3C: nop

    // 0x80010C40: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x80010C44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010C48: beq         $t7, $at, L_80010C68
    if (ctx->r15 == ctx->r1) {
        // 0x80010C4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010C68;
    }
    // 0x80010C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C50: jal         0x80023F7C
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_8;
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x80010C58: b           L_80010C6C
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
        goto L_80010C6C;
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C60:
    // 0x80010C60: jal         0x80023F7C
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_9;
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
L_80010C68:
    // 0x80010C68: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C6C:
    // 0x80010C6C: nop

    // 0x80010C70: lb          $t8, 0x53($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X53);
    // 0x80010C74: nop

    // 0x80010C78: bne         $t8, $zero, L_80010CF0
    if (ctx->r24 != 0) {
        // 0x80010C7C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C80: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010C88: blez        $a0, L_80010CD4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80010C8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80010CD4;
    }
    // 0x80010C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80010C90:
    // 0x80010C90: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80010C94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010C98: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80010C9C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80010CA0: nop

    // 0x80010CA4: beq         $v1, $zero, L_80010CCC
    if (ctx->r3 == 0) {
        // 0x80010CA8: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80010CCC;
    }
    // 0x80010CA8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010CAC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010CB0: nop

    // 0x80010CB4: sh          $s4, 0x52($t0)
    MEM_H(0X52, ctx->r8) = ctx->r20;
    // 0x80010CB8: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80010CBC: nop

    // 0x80010CC0: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010CC4: nop

    // 0x80010CC8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80010CCC:
    // 0x80010CCC: bne         $at, $zero, L_80010C90
    if (ctx->r1 != 0) {
        // 0x80010CD0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80010C90;
    }
    // 0x80010CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010CD4:
    // 0x80010CD4: lbu         $t2, 0x72($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X72);
    // 0x80010CD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80010CDC: beq         $t2, $at, L_80010CEC
    if (ctx->r10 == ctx->r1) {
        // 0x80010CE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010CEC;
    }
    // 0x80010CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010CE4: jal         0x80014090
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80014090(rdram, ctx);
        goto after_10;
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
L_80010CEC:
    // 0x80010CEC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80010CF0:
    // 0x80010CF0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010CF4: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010CF8: bne         $at, $zero, L_80010BE8
    if (ctx->r1 != 0) {
        // 0x80010CFC: nop
    
            goto L_80010BE8;
    }
    // 0x80010CFC: nop

L_80010D00:
    // 0x80010D00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80010D04: lw          $t4, -0x4B90($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B90);
    // 0x80010D08: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010D0C: addiu       $s6, $s6, -0x4C28
    ctx->r22 = ADD32(ctx->r22, -0X4C28);
    // 0x80010D10: blez        $t4, L_80010D4C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010D14: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80010D4C;
    }
    // 0x80010D14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010D1C:
    // 0x80010D1C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010D20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010D24: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010D28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010D2C: jal         0x8004DE78
    // 0x80010D30: nop

    update_player_racer(rdram, ctx);
        goto after_11;
    // 0x80010D30: nop

    after_11:
    // 0x80010D34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010D38: lw          $t7, -0x4B90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B90);
    // 0x80010D3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010D40: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010D44: bne         $at, $zero, L_80010D1C
    if (ctx->r1 != 0) {
        // 0x80010D48: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010D1C;
    }
    // 0x80010D48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010D4C:
    // 0x80010D4C: jal         0x8006BFD8
    // 0x80010D50: nop

    level_type(rdram, ctx);
        goto after_12;
    // 0x80010D50: nop

    after_12:
    // 0x80010D54: bne         $v0, $zero, L_80010DC8
    if (ctx->r2 != 0) {
        // 0x80010D58: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80010DC8;
    }
    // 0x80010D58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010D5C: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010D60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D64: blez        $a3, L_80010DC8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80010D68: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80010DC8;
    }
    // 0x80010D68: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80010D6C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010D70: addiu       $s0, $s0, -0x4B98
    ctx->r16 = ADD32(ctx->r16, -0X4B98);
L_80010D74:
    // 0x80010D74: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80010D78: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80010D7C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80010D80: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010D84: nop

    // 0x80010D88: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80010D8C: nop

    // 0x80010D90: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80010D94: nop

    // 0x80010D98: beq         $s2, $t0, L_80010DBC
    if (ctx->r18 == ctx->r8) {
        // 0x80010D9C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80010DBC;
    }
    // 0x80010D9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010DA0: jal         0x80043F0C
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    increment_ai_behaviour_chances(rdram, ctx);
        goto after_13;
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_13:
    // 0x80010DA8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010DAC: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010DB0: nop

    // 0x80010DB4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80010DB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80010DBC:
    // 0x80010DBC: slt         $at, $s1, $a3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80010DC0: bne         $at, $zero, L_80010D74
    if (ctx->r1 != 0) {
        // 0x80010DC4: nop
    
            goto L_80010D74;
    }
    // 0x80010DC4: nop

L_80010DC8:
    // 0x80010DC8: jal         0x8000BADC
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    racerfx_update(rdram, ctx);
        goto after_14;
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80010DD0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010DD4: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010DD8: nop

    // 0x80010DDC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010DE0: beq         $at, $zero, L_80010E58
    if (ctx->r1 == 0) {
        // 0x80010DE4: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010E58;
    }
    // 0x80010DE4: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010DE8: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80010DEC:
    // 0x80010DEC: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80010DF0: nop

    // 0x80010DF4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80010DF8: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80010DFC: nop

    // 0x80010E00: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80010E04: nop

    // 0x80010E08: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80010E0C: bne         $t5, $zero, L_80010E24
    if (ctx->r13 != 0) {
        // 0x80010E10: nop
    
            goto L_80010E24;
    }
    // 0x80010E10: nop

    // 0x80010E14: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80010E18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010E1C: beq         $t6, $at, L_80010E34
    if (ctx->r14 == ctx->r1) {
        // 0x80010E20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E34;
    }
    // 0x80010E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E24:
    // 0x80010E24: lh          $t7, 0x48($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X48);
    // 0x80010E28: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010E2C: bne         $t7, $at, L_80010E48
    if (ctx->r15 != ctx->r1) {
        // 0x80010E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E48;
    }
    // 0x80010E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E34:
    // 0x80010E34: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E38: jal         0x80023F7C
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    run_object_loop_func(rdram, ctx);
        goto after_15;
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_15:
    // 0x80010E40: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010E44: nop

L_80010E48:
    // 0x80010E48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010E4C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010E50: bne         $at, $zero, L_80010DEC
    if (ctx->r1 != 0) {
        // 0x80010E54: nop
    
            goto L_80010DEC;
    }
    // 0x80010E54: nop

L_80010E58:
    // 0x80010E58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010E5C: lw          $t8, -0x4C1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C1C);
    // 0x80010E60: nop

    // 0x80010E64: blez        $t8, L_80010EC8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010E68: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010EC8;
    }
    // 0x80010E68: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010E6C: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010E70: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80010E74: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010E78: beq         $at, $zero, L_80010EC8
    if (ctx->r1 == 0) {
        // 0x80010E7C: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010EC8;
    }
    // 0x80010E7C: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010E80:
    // 0x80010E80: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80010E84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E88: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010E8C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80010E90: nop

    // 0x80010E94: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80010E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010E9C: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x80010EA0: beq         $t2, $zero, L_80010EB8
    if (ctx->r10 == 0) {
        // 0x80010EA4: nop
    
            goto L_80010EB8;
    }
    // 0x80010EA4: nop

    // 0x80010EA8: jal         0x800B285C
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    particle_update(rdram, ctx);
        goto after_16;
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_16:
    // 0x80010EB0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010EB4: nop

L_80010EB8:
    // 0x80010EB8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010EBC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EC0: bne         $at, $zero, L_80010E80
    if (ctx->r1 != 0) {
        // 0x80010EC4: nop
    
            goto L_80010E80;
    }
    // 0x80010EC4: nop

L_80010EC8:
    // 0x80010EC8: jal         0x800323D8
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    light_update_all(rdram, ctx);
        goto after_17;
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x80010ED0: jal         0x80032CAC
    // 0x80010ED4: nop

    light_count(rdram, ctx);
        goto after_18;
    // 0x80010ED4: nop

    after_18:
    // 0x80010ED8: blez        $v0, L_80010F58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80010EDC: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010F58;
    }
    // 0x80010EDC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010EE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010EE4: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x80010EE8: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010EEC: nop

    // 0x80010EF0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EF4: beq         $at, $zero, L_80010F58
    if (ctx->r1 == 0) {
        // 0x80010EF8: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010F58;
    }
    // 0x80010EF8: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010EFC:
    // 0x80010EFC: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010F00: nop

    // 0x80010F04: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010F08: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010F0C: nop

    // 0x80010F10: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010F14: nop

    // 0x80010F18: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010F1C: bne         $t6, $zero, L_80010F48
    if (ctx->r14 != 0) {
        // 0x80010F20: nop
    
            goto L_80010F48;
    }
    // 0x80010F20: nop

    // 0x80010F24: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80010F28: nop

    // 0x80010F2C: beq         $t7, $zero, L_80010F48
    if (ctx->r15 == 0) {
        // 0x80010F30: nop
    
            goto L_80010F48;
    }
    // 0x80010F30: nop

    // 0x80010F34: jal         0x80032CBC
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    light_update_shading(rdram, ctx);
        goto after_19;
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80010F3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010F40: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x80010F44: nop

L_80010F48:
    // 0x80010F48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010F4C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010F50: bne         $at, $zero, L_80010EFC
    if (ctx->r1 != 0) {
        // 0x80010F54: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010EFC;
    }
    // 0x80010F54: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010F58:
    // 0x80010F58: jal         0x8001E720
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001E6EC(rdram, ctx);
        goto after_20;
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80010F60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010F64: lb          $t8, -0x4B89($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4B89);
    // 0x80010F68: nop

    // 0x80010F6C: beq         $t8, $zero, L_80010F7C
    if (ctx->r24 == 0) {
        // 0x80010F70: nop
    
            goto L_80010F7C;
    }
    // 0x80010F70: nop

    // 0x80010F74: jal         0x8002297C
    // 0x80010F78: nop

    mode_init_taj_race(rdram, ctx);
        goto after_21;
    // 0x80010F78: nop

    after_21:
L_80010F7C:
    // 0x80010F7C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010F80: addiu       $s0, $s0, -0x4CD4
    ctx->r16 = ADD32(ctx->r16, -0X4CD4);
    // 0x80010F84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010F88: nop

    // 0x80010F8C: bne         $t9, $zero, L_80010FB4
    if (ctx->r25 != 0) {
        // 0x80010F90: nop
    
            goto L_80010FB4;
    }
    // 0x80010F90: nop

    // 0x80010F94: jal         0x8001004C
    // 0x80010F98: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_22;
    // 0x80010F98: nop

    after_22:
    // 0x80010F9C: jal         0x80017ECC
    // 0x80010FA0: nop

    checkpoint_update_all(rdram, ctx);
        goto after_23;
    // 0x80010FA0: nop

    after_23:
    // 0x80010FA4: jal         0x8001BC88
    // 0x80010FA8: nop

    spectate_update(rdram, ctx);
        goto after_24;
    // 0x80010FA8: nop

    after_24:
    // 0x80010FAC: jal         0x8001E970
    // 0x80010FB0: nop

    func_8001E93C(rdram, ctx);
        goto after_25;
    // 0x80010FB0: nop

    after_25:
L_80010FB4:
    // 0x80010FB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FB8: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010FBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010FC0: beq         $a3, $zero, L_80011004
    if (ctx->r7 == 0) {
        // 0x80010FC4: nop
    
            goto L_80011004;
    }
    // 0x80010FC4: nop

    // 0x80010FC8: lh          $t1, -0x4D32($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4D32);
    // 0x80010FCC: nop

    // 0x80010FD0: bne         $t1, $zero, L_80010FF0
    if (ctx->r9 != 0) {
        // 0x80010FD4: nop
    
            goto L_80010FF0;
    }
    // 0x80010FD4: nop

    // 0x80010FD8: jal         0x8001983C
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_check_finish(rdram, ctx);
        goto after_26;
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_26:
    // 0x80010FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FE4: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010FE8: b           L_80011004
    // 0x80010FEC: nop

        goto L_80011004;
    // 0x80010FEC: nop

L_80010FF0:
    // 0x80010FF0: jal         0x8001A928
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_transition_adventure(rdram, ctx);
        goto after_27;
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x80010FF8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FFC: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80011000: nop

L_80011004:
    // 0x80011004: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011008: lw          $a0, -0x4B94($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4B94);
    // 0x8001100C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80011010: jal         0x80008438
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    audspat_update_all(rdram, ctx);
        goto after_28;
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_28:
    // 0x80011018: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8001101C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011020: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011024: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80011028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001102C: swc1        $f16, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f16.u32l;
    // 0x80011030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011034: sb          $zero, -0x4D5C($at)
    MEM_B(-0X4D5C, ctx->r1) = 0;
    // 0x80011038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001103C: jal         0x8000E2B4
    // 0x80011040: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    transform_player_vehicle(rdram, ctx);
        goto after_29;
    // 0x80011040: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    after_29:
    // 0x80011044: jal         0x8009D4F4
    // 0x80011048: nop

    dialogue_try_close(rdram, ctx);
        goto after_30;
    // 0x80011048: nop

    after_30:
    // 0x8001104C: jal         0x80017A04
    // 0x80011050: nop

    func_800179D0(rdram, ctx);
        goto after_31;
    // 0x80011050: nop

    after_31:
    // 0x80011054: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80011058: addiu       $v1, $v1, -0x4B80
    ctx->r3 = ADD32(ctx->r3, -0X4B80);
    // 0x8001105C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80011060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011064: bne         $v0, $at, L_80011100
    if (ctx->r2 != ctx->r1) {
        // 0x80011068: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80011100;
    }
    // 0x80011068: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001106C: lw          $t2, -0x4CD0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CD0);
    // 0x80011070: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80011074: bne         $t2, $at, L_8001110C
    if (ctx->r10 != ctx->r1) {
        // 0x80011078: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8001110C;
    }
    // 0x80011078: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001107C: lh          $t3, -0x4C06($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4C06);
    // 0x80011080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011084: bne         $t3, $zero, L_8001110C
    if (ctx->r11 != 0) {
        // 0x80011088: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001110C;
    }
    // 0x80011088: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001108C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011090:
    // 0x80011090: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011094: jal         0x8006A794
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_32;
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_32:
    // 0x8001109C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800110A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800110A4: bne         $s3, $s0, L_80011090
    if (ctx->r19 != ctx->r16) {
        // 0x800110A8: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_80011090;
    }
    // 0x800110A8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800110AC: andi        $t4, $a1, 0x8000
    ctx->r12 = ctx->r5 & 0X8000;
    // 0x800110B0: beq         $t4, $zero, L_800110C8
    if (ctx->r12 == 0) {
        // 0x800110B4: andi        $t5, $a1, 0x4000
        ctx->r13 = ctx->r5 & 0X4000;
            goto L_800110C8;
    }
    // 0x800110B4: andi        $t5, $a1, 0x4000
    ctx->r13 = ctx->r5 & 0X4000;
    // 0x800110B8: jal         0x8001E490
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8001E45C(rdram, ctx);
        goto after_33;
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_33:
    // 0x800110C0: b           L_80011110
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800110C8:
    // 0x800110C8: beq         $t5, $zero, L_80011110
    if (ctx->r13 == 0) {
        // 0x800110CC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110D0: jal         0x80099B68
    // 0x800110D4: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_34;
    // 0x800110D4: nop

    after_34:
    // 0x800110D8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110E0: jal         0x8009C814
    // 0x800110E4: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_35;
    // 0x800110E4: nop

    after_35:
    // 0x800110E8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110F0: jal         0x8006F380
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_36;
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x800110F8: b           L_80011110
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011100:
    // 0x80011100: bne         $v0, $zero, L_8001110C
    if (ctx->r2 != 0) {
        // 0x80011104: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001110C;
    }
    // 0x80011104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011108: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8001110C:
    // 0x8001110C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011110:
    // 0x80011110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011114: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001111C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011120: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011124: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011128: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001112C: jr          $ra
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_tex_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011134: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80011138: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001113C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80011140: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80011144: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80011148: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001114C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80011150: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011154: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011158: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001115C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011160: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80011164: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80011168: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001116C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80011170: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80011174: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80011178: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8001117C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011180: lh          $s5, 0x50($s3)
    ctx->r21 = MEM_H(ctx->r19, 0X50);
    // 0x80011184: lw          $s4, 0x38($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X38);
    // 0x80011188: blez        $s5, L_80011238
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001118C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80011238;
    }
    // 0x8001118C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80011190: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80011194: sll         $s2, $zero, 2
    ctx->r18 = S32(0 << 2);
    // 0x80011198: blez        $t0, L_80011234
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001119C: subu        $s2, $s2, $zero
        ctx->r18 = SUB32(ctx->r18, 0);
            goto L_80011234;
    }
    // 0x8001119C: subu        $s2, $s2, $zero
    ctx->r18 = SUB32(ctx->r18, 0);
    // 0x800111A0: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x800111A4: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x800111A8: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x800111AC: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
L_800111B0:
    // 0x800111B0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800111B4: nop

    // 0x800111B8: and         $t2, $t1, $s7
    ctx->r10 = ctx->r9 & ctx->r23;
    // 0x800111BC: beq         $t2, $zero, L_80011210
    if (ctx->r10 == 0) {
        // 0x800111C0: nop
    
            goto L_80011210;
    }
    // 0x800111C0: nop

    // 0x800111C4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800111C8: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
    // 0x800111CC: beq         $fp, $v0, L_80011210
    if (ctx->r30 == ctx->r2) {
        // 0x800111D0: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80011210;
    }
    // 0x800111D0: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800111D4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800111D8: lbu         $t7, 0x7($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7);
    // 0x800111DC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800111E0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800111E4: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800111E8: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800111EC: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800111F0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800111F4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800111F8: jal         0x8007F3D0
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80011200: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80011204: nop

    // 0x80011208: sra         $t1, $t9, 6
    ctx->r9 = S32(SIGNED(ctx->r25) >> 6);
    // 0x8001120C: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_80011210:
    // 0x80011210: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011214: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80011218: blez        $s5, L_80011234
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001121C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80011234;
    }
    // 0x8001121C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80011220: lh          $t2, 0x28($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X28);
    // 0x80011224: nop

    // 0x80011228: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001122C: bne         $at, $zero, L_800111B0
    if (ctx->r1 != 0) {
        // 0x80011230: nop
    
            goto L_800111B0;
    }
    // 0x80011230: nop

L_80011234:
    // 0x80011234: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80011238:
    // 0x80011238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001123C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011240: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011244: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011248: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001124C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011250: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011254: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80011258: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001125C: jr          $ra
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_door_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011264: lh          $t6, 0x50($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X50);
    // 0x80011268: nop

    // 0x8001126C: blez        $t6, L_8001135C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80011270: nop
    
            goto L_8001135C;
    }
    // 0x80011270: nop

    // 0x80011274: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80011278: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001127C: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x80011280: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x80011284: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x80011288: bne         $t2, $zero, L_80011294
    if (ctx->r10 != 0) {
        // 0x8001128C: nop
    
            goto L_80011294;
    }
    // 0x8001128C: nop

    // 0x80011290: break       7
    do_break(2147553936);
L_80011294:
    // 0x80011294: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011298: bne         $t2, $at, L_800112AC
    if (ctx->r10 != ctx->r1) {
        // 0x8001129C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800112AC;
    }
    // 0x8001129C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800112A0: bne         $v1, $at, L_800112AC
    if (ctx->r3 != ctx->r1) {
        // 0x800112A4: nop
    
            goto L_800112AC;
    }
    // 0x800112A4: nop

    // 0x800112A8: break       6
    do_break(2147553960);
L_800112AC:
    // 0x800112AC: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800112B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800112B4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800112B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800112BC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800112C0: mflo        $a2
    ctx->r6 = lo;
    // 0x800112C4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800112C8: mfhi        $v1
    ctx->r3 = hi;
    // 0x800112CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800112D0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800112D4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800112D8: blez        $t1, L_8001135C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800112DC: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8001135C;
    }
    // 0x800112DC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800112E0:
    // 0x800112E0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800112E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800112E8: and         $t4, $t9, $t2
    ctx->r12 = ctx->r25 & ctx->r10;
    // 0x800112EC: beq         $t4, $zero, L_80011354
    if (ctx->r12 == 0) {
        // 0x800112F0: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x800112F0: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800112F4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800112F8: nop

    // 0x800112FC: beq         $t3, $a1, L_80011354
    if (ctx->r11 == ctx->r5) {
        // 0x80011300: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011300: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011304: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80011308: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8001130C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80011310: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80011314: nop

    // 0x80011318: lhu         $t8, 0x12($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X12);
    // 0x8001131C: nop

    // 0x80011320: slti        $at, $t8, 0x901
    ctx->r1 = SIGNED(ctx->r24) < 0X901 ? 1 : 0;
    // 0x80011324: bne         $at, $zero, L_8001133C
    if (ctx->r1 != 0) {
        // 0x80011328: nop
    
            goto L_8001133C;
    }
    // 0x80011328: nop

    // 0x8001132C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x80011330: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x80011334: b           L_80011354
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
        goto L_80011354;
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_8001133C:
    // 0x8001133C: bltz        $a2, L_80011354
    if (SIGNED(ctx->r6) < 0) {
        // 0x80011340: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011340: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011344: sb          $a2, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r6;
    // 0x80011348: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x8001134C: nop

    // 0x80011350: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_80011354:
    // 0x80011354: bne         $at, $zero, L_800112E0
    if (ctx->r1 != 0) {
        // 0x80011358: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800112E0;
    }
    // 0x80011358: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8001135C:
    // 0x8001135C: jr          $ra
    // 0x80011360: nop

    return;
    // 0x80011360: nop

;}
RECOMP_FUNC void do_nothing_func_80011364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011364: jr          $ra
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void path_update_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001136C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80011370: lw          $t6, -0x4CD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CD4);
    // 0x80011374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011378: beq         $t6, $zero, L_80011388
    if (ctx->r14 == 0) {
        // 0x8001137C: nop
    
            goto L_80011388;
    }
    // 0x8001137C: nop

    // 0x80011380: jr          $ra
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011388:
    // 0x80011388: jr          $ra
    // 0x8001138C: nop

    return;
    // 0x8001138C: nop

;}
RECOMP_FUNC void path_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011390: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011394: jr          $ra
    // 0x80011398: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    return;
    // 0x80011398: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
;}
RECOMP_FUNC void get_race_countdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001139C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113A0: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x800113A4: jr          $ra
    // 0x800113A8: nop

    return;
    // 0x800113A8: nop

;}
RECOMP_FUNC void get_race_start_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113B0: lw          $v0, -0x4CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC8);
    // 0x800113B4: jr          $ra
    // 0x800113B8: nop

    return;
    // 0x800113B8: nop

;}
RECOMP_FUNC void func_800113BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113C0: lw          $v0, -0x4CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC4);
    // 0x800113C4: jr          $ra
    // 0x800113C8: nop

    return;
    // 0x800113C8: nop

;}
RECOMP_FUNC void play_footstep_sounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800113D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800113D4: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800113D8: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800113DC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800113E0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800113E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800113E8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800113EC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800113F0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800113F4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800113F8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800113FC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80011400: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80011404: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80011408: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001140C: lbu         $t6, 0x5B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5B);
    // 0x80011410: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80011414: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80011418: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8001141C: beq         $at, $zero, L_80011520
    if (ctx->r1 == 0) {
        // 0x80011420: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80011520;
    }
    // 0x80011420: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80011424: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80011428: lbu         $a0, 0x5C($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5C);
    // 0x8001142C: jal         0x8001E2D0
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    after_0:
    // 0x80011434: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x80011438: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x8001143C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011440: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80011444: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80011448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001144C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80011450: lh          $s4, 0x18($s1)
    ctx->r20 = MEM_H(ctx->r17, 0X18);
    // 0x80011454: lb          $s2, 0x0($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X0);
    // 0x80011458: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8001145C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80011460: sra         $t1, $s3, 4
    ctx->r9 = S32(SIGNED(ctx->r19) >> 4);
    // 0x80011464: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80011468: sra         $t2, $s4, 4
    ctx->r10 = S32(SIGNED(ctx->r20) >> 4);
    // 0x8001146C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80011470: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x80011474: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x80011478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001147C: blez        $s2, L_80011520
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80011480: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80011520;
    }
    // 0x80011480: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011484: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80011488: nop

    // 0x8001148C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011490:
    // 0x80011490: lb          $v0, 0x3($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X3);
    // 0x80011494: nop

    // 0x80011498: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001149C: bne         $at, $zero, L_800114A8
    if (ctx->r1 != 0) {
        // 0x800114A0: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800114A8;
    }
    // 0x800114A0: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800114A4: bne         $at, $zero, L_800114BC
    if (ctx->r1 != 0) {
        // 0x800114A8: slt         $at, $v0, $s4
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800114BC;
    }
L_800114A8:
    // 0x800114A8: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800114AC: bne         $at, $zero, L_80011510
    if (ctx->r1 != 0) {
        // 0x800114B0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80011510;
    }
    // 0x800114B0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800114B4: beq         $at, $zero, L_80011510
    if (ctx->r1 == 0) {
        // 0x800114B8: nop
    
            goto L_80011510;
    }
    // 0x800114B8: nop

L_800114BC:
    // 0x800114BC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800114C0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800114C4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800114C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800114CC: jal         0x8006A054
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    set_camera_shake_by_distance(rdram, ctx);
        goto after_1;
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x800114D4: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x800114D8: beq         $t4, $zero, L_800114E8
    if (ctx->r12 == 0) {
        // 0x800114DC: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_800114E8;
    }
    // 0x800114DC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800114E0: b           L_800114EC
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_800114EC;
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_800114E8:
    // 0x800114E8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800114EC:
    // 0x800114EC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800114F0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800114F4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800114F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800114FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80011500: jal         0x80009558
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80011508: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8001150C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80011510:
    // 0x80011510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80011514: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80011518: bne         $at, $zero, L_80011490
    if (ctx->r1 != 0) {
        // 0x8001151C: addu        $t3, $s0, $s6
        ctx->r11 = ADD32(ctx->r16, ctx->r22);
            goto L_80011490;
    }
    // 0x8001151C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011520:
    // 0x80011520: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80011524: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80011528: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001152C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80011530: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80011534: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80011538: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8001153C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80011540: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80011544: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80011548: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8001154C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80011550: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80011554: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80011558: jr          $ra
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ignore_bounds_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011568: jr          $ra
    // 0x8001156C: sb          $t6, -0x3248($at)
    MEM_B(-0X3248, ctx->r1) = ctx->r14;
    return;
    // 0x8001156C: sb          $t6, -0x3248($at)
    MEM_B(-0X3248, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void move_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80011574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011578: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001157C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80011580: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80011584: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80011588: jal         0x8002C804
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80011590: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011594: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80011598: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001159C: lwc1        $f2, 0xC($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800115A0: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800115A4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800115A8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800115AC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800115B0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800115B4: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800115B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115BC: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800115C0: bne         $v0, $zero, L_800115D8
    if (ctx->r2 != 0) {
        // 0x800115C4: swc1        $f4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
            goto L_800115D8;
    }
    // 0x800115C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800115C8: addiu       $a0, $a0, -0x3248
    ctx->r4 = ADD32(ctx->r4, -0X3248);
    // 0x800115CC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800115D0: b           L_80011950
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800115D8:
    // 0x800115D8: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800115DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800115E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800115E4: lwc1        $f13, 0x5AC8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X5AC8);
    // 0x800115E8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800115EC: lwc1        $f12, 0x5ACC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5ACC);
    // 0x800115F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115F4: add.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d + ctx->f12.d;
    // 0x800115F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800115FC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80011600: addiu       $a0, $a0, -0x3248
    ctx->r4 = ADD32(ctx->r4, -0X3248);
    // 0x80011604: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80011608: nop

    // 0x8001160C: bc1f        L_80011618
    if (!c1cs) {
        // 0x80011610: nop
    
            goto L_80011618;
    }
    // 0x80011610: nop

    // 0x80011614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011618:
    // 0x80011618: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x8001161C: nop

    // 0x80011620: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80011624: nop

    // 0x80011628: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001162C: sub.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d - ctx->f12.d;
    // 0x80011630: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80011634: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80011638: nop

    // 0x8001163C: bc1f        L_80011648
    if (!c1cs) {
        // 0x80011640: nop
    
            goto L_80011648;
    }
    // 0x80011640: nop

    // 0x80011644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011648:
    // 0x80011648: lh          $t8, 0x42($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X42);
    // 0x8001164C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011650: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80011654: lwc1        $f7, 0x5AD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5AD0);
    // 0x80011658: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8001165C: lwc1        $f6, 0x5AD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5AD4);
    // 0x80011660: nop

    // 0x80011664: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80011668: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8001166C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80011670: nop

    // 0x80011674: bc1f        L_80011680
    if (!c1cs) {
        // 0x80011678: nop
    
            goto L_80011680;
    }
    // 0x80011678: nop

    // 0x8001167C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011680:
    // 0x80011680: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x80011684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011688: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8001168C: lwc1        $f7, 0x5AD8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5AD8);
    // 0x80011690: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80011694: lwc1        $f6, 0x5ADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ADC);
    // 0x80011698: nop

    // 0x8001169C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800116A0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800116A4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800116A8: nop

    // 0x800116AC: bc1f        L_800116B8
    if (!c1cs) {
        // 0x800116B0: nop
    
            goto L_800116B8;
    }
    // 0x800116B0: nop

    // 0x800116B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116B8:
    // 0x800116B8: lh          $t1, 0x46($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X46);
    // 0x800116BC: nop

    // 0x800116C0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800116C4: nop

    // 0x800116C8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800116CC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x800116D0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800116D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800116D8: nop

    // 0x800116DC: bc1f        L_800116E8
    if (!c1cs) {
        // 0x800116E0: nop
    
            goto L_800116E8;
    }
    // 0x800116E0: nop

    // 0x800116E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116E8:
    // 0x800116E8: lh          $t2, 0x44($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X44);
    // 0x800116EC: nop

    // 0x800116F0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800116F4: nop

    // 0x800116F8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800116FC: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x80011700: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x80011704: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80011708: nop

    // 0x8001170C: bc1f        L_80011718
    if (!c1cs) {
        // 0x80011710: nop
    
            goto L_80011718;
    }
    // 0x80011710: nop

    // 0x80011714: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011718:
    // 0x80011718: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001171C: nop

    // 0x80011720: beq         $t3, $zero, L_8001172C
    if (ctx->r11 == 0) {
        // 0x80011724: nop
    
            goto L_8001172C;
    }
    // 0x80011724: nop

    // 0x80011728: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001172C:
    // 0x8001172C: beq         $v1, $zero, L_80011744
    if (ctx->r3 == 0) {
        // 0x80011730: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80011744;
    }
    // 0x80011730: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80011734: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011738: sh          $t4, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r12;
    // 0x8001173C: b           L_80011950
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011950;
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011744:
    // 0x80011744: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x80011748: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001174C: lh          $a0, 0x2E($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2E);
    // 0x80011750: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
    // 0x80011754: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011758: nop

    // 0x8001175C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x80011760: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80011764: jal         0x8002A31C
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    block_boundbox(rdram, ctx);
        goto after_1;
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001176C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011770: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80011774: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011778: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001177C: bne         $v0, $zero, L_80011834
    if (ctx->r2 != 0) {
        // 0x80011780: nop
    
            goto L_80011834;
    }
    // 0x80011780: nop

    // 0x80011784: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011788: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8001178C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011798: nop

    // 0x8001179C: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800117A0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800117A4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800117A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800117AC: nop

    // 0x800117B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800117B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800117B8: nop

    // 0x800117BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800117C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117C8: nop

    // 0x800117CC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800117D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800117D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800117D8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800117DC: nop

    // 0x800117E0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800117E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800117E8: nop

    // 0x800117EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800117F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117F8: nop

    // 0x800117FC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80011800: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80011804: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80011808: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8001180C: nop

    // 0x80011810: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011814: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80011818: jal         0x80029F58
    // 0x8001181C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_2;
    // 0x8001181C: nop

    after_2:
    // 0x80011820: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011824: nop

    // 0x80011828: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
    // 0x8001182C: b           L_80011950
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011834:
    // 0x80011834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80011838: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8001183C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80011840: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011844: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001184C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80011850: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80011854: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80011858: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001185C: bne         $at, $zero, L_80011878
    if (ctx->r1 != 0) {
        // 0x80011860: nop
    
            goto L_80011878;
    }
    // 0x80011860: nop

    // 0x80011864: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80011868: nop

    // 0x8001186C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80011870: beq         $at, $zero, L_8001187C
    if (ctx->r1 == 0) {
        // 0x80011874: nop
    
            goto L_8001187C;
    }
    // 0x80011874: nop

L_80011878:
    // 0x80011878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001187C:
    // 0x8001187C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011880: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80011884: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011888: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001188C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011890: nop

    // 0x80011894: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80011898: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8001189C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800118A0: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800118A4: bne         $at, $zero, L_800118C0
    if (ctx->r1 != 0) {
        // 0x800118A8: nop
    
            goto L_800118C0;
    }
    // 0x800118A8: nop

    // 0x800118AC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800118B0: nop

    // 0x800118B4: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800118B8: beq         $at, $zero, L_800118C4
    if (ctx->r1 == 0) {
        // 0x800118BC: nop
    
            goto L_800118C4;
    }
    // 0x800118BC: nop

L_800118C0:
    // 0x800118C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800118C4:
    // 0x800118C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800118C8: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x800118CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800118D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800118D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800118D8: nop

    // 0x800118DC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800118E0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800118E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800118E8: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800118EC: bne         $at, $zero, L_80011908
    if (ctx->r1 != 0) {
        // 0x800118F0: nop
    
            goto L_80011908;
    }
    // 0x800118F0: nop

    // 0x800118F4: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800118F8: nop

    // 0x800118FC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011900: beq         $at, $zero, L_8001190C
    if (ctx->r1 == 0) {
        // 0x80011904: nop
    
            goto L_8001190C;
    }
    // 0x80011904: nop

L_80011908:
    // 0x80011908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001190C:
    // 0x8001190C: beq         $a0, $zero, L_80011950
    if (ctx->r4 == 0) {
        // 0x80011910: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80011950;
    }
    // 0x80011910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011914: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80011918: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001191C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011920: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80011924: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80011928: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8001192C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011930: jal         0x80029F58
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_3;
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x80011938: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001193C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011940: beq         $v0, $at, L_8001194C
    if (ctx->r2 == ctx->r1) {
        // 0x80011944: nop
    
            goto L_8001194C;
    }
    // 0x80011944: nop

    // 0x80011948: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
L_8001194C:
    // 0x8001194C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011950:
    // 0x80011950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80011958: jr          $ra
    // 0x8001195C: nop

    return;
    // 0x8001195C: nop

;}
RECOMP_FUNC void render_misc_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011964: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80011968: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001196C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80011970: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80011974: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80011978: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001197C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011984: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80011988: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001198C: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x80011990: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80011994: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80011998: jal         0x800696C4
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_0;
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800119A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800119A4: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x800119A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800119B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800119B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800119B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800119BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800119C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800119C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119C8: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800119CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800119D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800119D4: addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // 0x800119D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800119DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800119E0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800119E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800119E8: beq         $t4, $zero, L_800119F8
    if (ctx->r12 == 0) {
        // 0x800119EC: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800119F8;
    }
    // 0x800119EC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800119F0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800119F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800119F8:
    // 0x800119F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800119FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80011A00: jal         0x8007B938
    // 0x80011A04: nop

    material_set(rdram, ctx);
        goto after_1;
    // 0x80011A04: nop

    after_1:
    // 0x80011A08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80011A0C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80011A10: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80011A14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011A18: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80011A1C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    // 0x80011A20: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x80011A24: andi        $t2, $a1, 0x6
    ctx->r10 = ctx->r5 & 0X6;
    // 0x80011A28: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80011A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A30: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80011A34: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80011A38: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80011A3C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80011A40: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80011A44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011A48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80011A4C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80011A50: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011A54: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80011A58: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80011A5C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80011A60: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80011A64: or          $t4, $t6, $t3
    ctx->r12 = ctx->r14 | ctx->r11;
    // 0x80011A68: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80011A6C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80011A70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80011A74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A78: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x80011A7C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80011A80: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80011A84: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011A88: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80011A8C: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80011A90: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x80011A94: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80011A98: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x80011A9C: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80011AA0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80011AA4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80011AA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011AAC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80011AB0: nop

    // 0x80011AB4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80011AB8: jal         0x80069C80
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    mtx_pop(rdram, ctx);
        goto after_2;
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_2:
    // 0x80011AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011AC8: jr          $ra
    // 0x80011ACC: nop

    return;
    // 0x80011ACC: nop

;}
RECOMP_FUNC void render_3d_misc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011AD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011AD8: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x80011ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011AE0: beq         $v0, $at, L_80011BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80011AE4: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011BB4;
    }
    // 0x80011AE4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AE8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80011AEC: beq         $v0, $at, L_80011B10
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80011B10;
    }
    // 0x80011AF0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80011AF4: beq         $v0, $at, L_80011B58
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF8: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011B58;
    }
    // 0x80011AF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AFC: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80011B00: beq         $v0, $at, L_80011C38
    if (ctx->r2 == ctx->r1) {
        // 0x80011B04: nop
    
            goto L_80011C38;
    }
    // 0x80011B04: nop

    // 0x80011B08: b           L_80011C88
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B10:
    // 0x80011B10: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80011B14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80011B18: bltz        $t6, L_80011C84
    if (SIGNED(ctx->r14) < 0) {
        // 0x80011B1C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80011C84;
    }
    // 0x80011B1C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80011B20: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B28: lw          $a1, 0x20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X20);
    // 0x80011B2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80011B30: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x80011B34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011B38: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80011B3C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80011B40: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011B44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80011B48: jal         0x80011960
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    render_misc_model(rdram, ctx);
        goto after_0;
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80011B50: b           L_80011C88
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B58:
    // 0x80011B58: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B5C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80011B60: lbu         $t0, 0xFC($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011B64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80011B68: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80011B6C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80011B70: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80011B74: lw          $t4, 0xF8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XF8);
    // 0x80011B78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80011B7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80011B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011B88: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80011B8C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80011B90: addu        $a1, $a3, $t2
    ctx->r5 = ADD32(ctx->r7, ctx->r10);
    // 0x80011B94: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011B98: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80011B9C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011BA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80011BA4: jal         0x80011960
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    render_misc_model(rdram, ctx);
        goto after_1;
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80011BAC: b           L_80011C88
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011BB4:
    // 0x80011BB4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80011BB8: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011BBC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80011BC0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80011BC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80011BC8: bgez        $t7, L_80011BE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80011BCC: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80011BE0;
    }
    // 0x80011BCC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011BD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80011BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80011BD8: nop

    // 0x80011BDC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80011BE0:
    // 0x80011BE0: lbu         $t8, 0xFC($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011BE8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80011BEC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80011BF0: lwc1        $f16, 0x5AE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5AE0);
    // 0x80011BF4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80011BF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80011BFC: lw          $t2, 0xF8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XF8);
    // 0x80011C00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80011C04: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80011C08: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80011C0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80011C10: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    // 0x80011C14: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80011C18: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80011C1C: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011C20: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80011C24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011C28: jal         0x80011960
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    render_misc_model(rdram, ctx);
        goto after_2;
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x80011C30: b           L_80011C88
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C38:
    // 0x80011C38: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x80011C3C: nop

    // 0x80011C40: beq         $t4, $zero, L_80011C88
    if (ctx->r12 == 0) {
        // 0x80011C44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011C48: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80011C4C: nop

    // 0x80011C50: lbu         $t5, 0x70($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X70);
    // 0x80011C54: nop

    // 0x80011C58: bgtz        $t5, L_80011C7C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80011C5C: nop
    
            goto L_80011C7C;
    }
    // 0x80011C5C: nop

    // 0x80011C60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80011C64: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80011C68: nop

    // 0x80011C6C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80011C70: nop

    // 0x80011C74: bc1f        L_80011C88
    if (!c1cs) {
        // 0x80011C78: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C7C:
    // 0x80011C7C: jal         0x800135B8
    // 0x80011C80: nop

    func_800135B8(rdram, ctx);
        goto after_3;
    // 0x80011C80: nop

    after_3:
L_80011C84:
    // 0x80011C84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C88:
    // 0x80011C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011C8C: jr          $ra
    // 0x80011C90: nop

    return;
    // 0x80011C90: nop

;}
RECOMP_FUNC void render_3d_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011C94: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80011C98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011C9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80011CA0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80011CA4: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80011CA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011CAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80011CB0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80011CB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80011CB8: beq         $v1, $zero, L_80011D00
    if (ctx->r3 == 0) {
        // 0x80011CBC: ori         $t2, $t6, 0x108
        ctx->r10 = ctx->r14 | 0X108;
            goto L_80011D00;
    }
    // 0x80011CBC: ori         $t2, $t6, 0x108
    ctx->r10 = ctx->r14 | 0X108;
    // 0x80011CC0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80011CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011CC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011CCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011CD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011CD8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80011CDC: nop

    // 0x80011CE0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80011CE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011CE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011CEC: nop

    // 0x80011CF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80011CF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80011CF8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80011CFC: nop

L_80011D00:
    // 0x80011D00: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D04: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80011D08: bne         $v0, $at, L_80011D50
    if (ctx->r2 != ctx->r1) {
        // 0x80011D0C: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_80011D50;
    }
    // 0x80011D0C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80011D10: lbu         $v1, 0x39($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D14: nop

    // 0x80011D18: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80011D1C: bne         $at, $zero, L_80011D34
    if (ctx->r1 != 0) {
        // 0x80011D20: nop
    
            goto L_80011D34;
    }
    // 0x80011D20: nop

    // 0x80011D24: lw          $t4, 0x7C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D28: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D2C: b           L_80011D50
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
        goto L_80011D50;
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
L_80011D34:
    // 0x80011D34: lw          $t5, 0x7C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D38: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D3C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80011D40: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011D44: mflo        $t7
    ctx->r15 = lo;
    // 0x80011D48: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80011D4C: sb          $t8, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r24;
L_80011D50:
    // 0x80011D50: lbu         $a1, 0x39($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D54: addiu       $v1, $zero, 0x77
    ctx->r3 = ADD32(0, 0X77);
    // 0x80011D58: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80011D5C: bne         $at, $zero, L_80011D68
    if (ctx->r1 != 0) {
        // 0x80011D60: ori         $t4, $t2, 0x4
        ctx->r12 = ctx->r10 | 0X4;
            goto L_80011D68;
    }
    // 0x80011D60: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x80011D64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80011D68:
    // 0x80011D68: bne         $v1, $v0, L_80011D74
    if (ctx->r3 != ctx->r2) {
        // 0x80011D6C: sra         $t9, $a1, 1
        ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80011D74;
    }
    // 0x80011D6C: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80011D70: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80011D74:
    // 0x80011D74: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011D78: beq         $at, $zero, L_80011D88
    if (ctx->r1 == 0) {
        // 0x80011D7C: nop
    
            goto L_80011D88;
    }
    // 0x80011D7C: nop

    // 0x80011D80: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80011D84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011D88:
    // 0x80011D88: bne         $t3, $v0, L_80011DFC
    if (ctx->r11 != ctx->r2) {
        // 0x80011D8C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80011DFC;
    }
    // 0x80011D8C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80011D90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80011D94: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011D98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011D9C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80011DA0: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011DA4: bc1f        L_80011DFC
    if (!c1cs) {
        // 0x80011DA8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80011DFC;
    }
    // 0x80011DA8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80011DAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011DB0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80011DB4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011DB8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80011DBC: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80011DC0: sra         $t9, $t7, 2
    ctx->r25 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80011DC4: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x80011DC8: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x80011DCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011DD0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80011DD4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80011DD8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011DDC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80011DE0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x80011DE4: or          $t4, $t7, $t5
    ctx->r12 = ctx->r15 | ctx->r13;
    // 0x80011DE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80011DEC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x80011DF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011DF4: b           L_80011EAC
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80011EAC;
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80011DFC:
    // 0x80011DFC: bne         $v1, $v0, L_80011E38
    if (ctx->r3 != ctx->r2) {
        // 0x80011E00: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E38;
    }
    // 0x80011E00: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E04: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E0C: lui         $at, 0x96E6
    ctx->r1 = S32(0X96E6 << 16);
    // 0x80011E10: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80011E14: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80011E18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80011E1C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80011E20: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80011E24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80011E28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011E2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80011E30: b           L_80011EAC
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011EAC;
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011E38:
    // 0x80011E38: bne         $t0, $zero, L_80011E48
    if (ctx->r8 != 0) {
        // 0x80011E3C: slti        $at, $a1, 0xFF
        ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
            goto L_80011E48;
    }
    // 0x80011E3C: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011E40: beq         $at, $zero, L_80011E8C
    if (ctx->r1 == 0) {
        // 0x80011E44: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E8C;
    }
    // 0x80011E44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_80011E48:
    // 0x80011E48: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E4C: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E54: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80011E58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011E5C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011E60: sll         $t9, $v1, 24
    ctx->r25 = S32(ctx->r3 << 24);
    // 0x80011E64: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80011E68: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80011E6C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x80011E70: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x80011E74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011E78: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80011E7C: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x80011E80: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80011E84: b           L_80011EAC
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80011EAC;
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80011E8C:
    // 0x80011E8C: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80011E90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E94: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80011E98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011E9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011EA0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011EA4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80011EA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80011EAC:
    // 0x80011EAC: beq         $t1, $zero, L_80011F00
    if (ctx->r9 == 0) {
        // 0x80011EB0: nop
    
            goto L_80011F00;
    }
    // 0x80011EB0: nop

    // 0x80011EB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011EB8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011EBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011EC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011EC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011EC8: lw          $v1, 0x54($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X54);
    // 0x80011ECC: nop

    // 0x80011ED0: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80011ED4: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x80011ED8: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x80011EDC: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x80011EE0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80011EE4: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x80011EE8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80011EEC: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x80011EF0: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x80011EF4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x80011EF8: b           L_80011F50
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011F50;
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011F00:
    // 0x80011F00: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80011F04: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80011F08: bne         $t9, $at, L_80011F38
    if (ctx->r25 != ctx->r1) {
        // 0x80011F0C: lui         $t4, 0xFB00
        ctx->r12 = S32(0XFB00 << 16);
            goto L_80011F38;
    }
    // 0x80011F0C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80011F10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F14: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x80011F18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011F1C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011F20: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x80011F24: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011F28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011F2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011F30: b           L_80011F50
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_80011F50;
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80011F38:
    // 0x80011F38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F3C: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x80011F40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011F44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011F48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80011F4C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80011F50:
    // 0x80011F50: lb          $t8, 0x3A($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X3A);
    // 0x80011F54: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    // 0x80011F58: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80011F5C: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80011F60: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80011F64: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80011F68: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80011F6C: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011F74: bne         $v0, $at, L_80011F90
    if (ctx->r2 != ctx->r1) {
        // 0x80011F78: nop
    
            goto L_80011F90;
    }
    // 0x80011F78: nop

    // 0x80011F7C: lw          $t9, 0x7C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X7C);
    // 0x80011F80: lw          $a0, 0x78($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X78);
    // 0x80011F84: blez        $t9, L_80011F90
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80011F88: nop
    
            goto L_80011F90;
    }
    // 0x80011F88: nop

    // 0x80011F8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80011F90:
    // 0x80011F90: bne         $a0, $zero, L_80011FB8
    if (ctx->r4 != 0) {
        // 0x80011F94: nop
    
            goto L_80011FB8;
    }
    // 0x80011F94: nop

    // 0x80011F98: bne         $t3, $v0, L_8001203C
    if (ctx->r11 != ctx->r2) {
        // 0x80011F9C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001203C;
    }
    // 0x80011F9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80011FA0: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
    // 0x80011FA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80011FA8: lbu         $t6, 0x18($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X18);
    // 0x80011FAC: nop

    // 0x80011FB0: bne         $t6, $at, L_80012040
    if (ctx->r14 != ctx->r1) {
        // 0x80011FB4: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_80012040;
    }
    // 0x80011FB4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80011FB8:
    // 0x80011FB8: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x80011FBC: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80011FC0: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80011FC4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011FC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011FCC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80011FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011FD4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80011FD8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80011FDC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80011FE0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80011FE4: lh          $t5, 0x18($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X18);
    // 0x80011FE8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80011FEC: sh          $t7, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r15;
    // 0x80011FF0: bne         $a0, $zero, L_80012014
    if (ctx->r4 != 0) {
        // 0x80011FF4: sh          $t5, 0x78($sp)
        MEM_H(0X78, ctx->r29) = ctx->r13;
            goto L_80012014;
    }
    // 0x80011FF4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80011FF8: lw          $t4, 0x64($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X64);
    // 0x80011FFC: nop

    // 0x80012000: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80012004: nop

    // 0x80012008: bne         $a0, $zero, L_80012018
    if (ctx->r4 != 0) {
        // 0x8001200C: lw          $a1, 0x58($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X58);
            goto L_80012018;
    }
    // 0x8001200C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80012010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80012014:
    // 0x80012014: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
L_80012018:
    // 0x80012018: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8001201C: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    // 0x80012020: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012024: jal         0x800138A8
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    render_bubble_trap(rdram, ctx);
        goto after_0;
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8001202C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012030: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80012034: b           L_80012070
    // 0x80012038: nop

        goto L_80012070;
    // 0x80012038: nop

L_8001203C:
    // 0x8001203C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80012040:
    // 0x80012040: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012044: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x80012048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001204C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012050: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80012054: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012058: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8001205C: jal         0x80068754
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_sprite_billboard(rdram, ctx);
        goto after_1;
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80012064: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012068: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8001206C: nop

L_80012070:
    // 0x80012070: beq         $t0, $zero, L_80012094
    if (ctx->r8 == 0) {
        // 0x80012074: nop
    
            goto L_80012094;
    }
    // 0x80012074: nop

    // 0x80012078: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001207C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012080: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012084: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80012088: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001208C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80012090: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012094:
    // 0x80012094: beq         $t1, $zero, L_800120BC
    if (ctx->r9 == 0) {
        // 0x80012098: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800120BC;
    }
    // 0x80012098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001209C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800120A0: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800120A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800120A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800120AC: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800120B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800120B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800120B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800120BC:
    // 0x800120BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800120C0: jr          $ra
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void render_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800120C8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800120CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800120D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800120D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800120D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800120DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800120E0: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x800120E4: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x800120E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800120EC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800120F0: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x800120F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800120F8: beq         $s0, $zero, L_80012C14
    if (ctx->r16 == 0) {
        // 0x800120FC: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80012C14;
    }
    // 0x800120FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80012100: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80012104: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80012108: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8001210C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x80012110: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x80012114: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80012118: nop

    // 0x8001211C: beq         $v1, $zero, L_8001217C
    if (ctx->r3 == 0) {
        // 0x80012120: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8001217C;
    }
    // 0x80012120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80012124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012128: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001212C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012130: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80012134: addiu       $s1, $s1, -0x4D50
    ctx->r17 = ADD32(ctx->r17, -0X4D50);
    // 0x80012138: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001213C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012140: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012144: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80012148: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x8001214C: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x80012150: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012154: nop

    // 0x80012158: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001215C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012160: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012164: nop

    // 0x80012168: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001216C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80012170: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012174: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x80012178: nop

L_8001217C:
    // 0x8001217C: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012180: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012188: bne         $t7, $at, L_800121A4
    if (ctx->r15 != ctx->r1) {
        // 0x8001218C: addiu       $s1, $s1, -0x4D50
        ctx->r17 = ADD32(ctx->r17, -0X4D50);
            goto L_800121A4;
    }
    // 0x8001218C: addiu       $s1, $s1, -0x4D50
    ctx->r17 = ADD32(ctx->r17, -0X4D50);
    // 0x80012190: lw          $s3, 0x64($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X64);
    // 0x80012194: jal         0x80012E28
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8001219C: b           L_800121AC
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
        goto L_800121AC;
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121A4:
    // 0x800121A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800121A8: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121AC:
    // 0x800121AC: nop

    // 0x800121B0: bgtz        $t6, L_800122FC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800121B4: nop
    
            goto L_800122FC;
    }
    // 0x800121B4: nop

    // 0x800121B8: lb          $t8, 0x1F($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1F);
    // 0x800121BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800121C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800121C4: addu        $t5, $s0, $t9
    ctx->r13 = ADD32(ctx->r16, ctx->r25);
    // 0x800121C8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800121CC: nop

    // 0x800121D0: sw          $t7, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r15;
    // 0x800121D4: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121D8: nop

    // 0x800121DC: bne         $v1, $at, L_800121F4
    if (ctx->r3 != ctx->r1) {
        // 0x800121E0: nop
    
            goto L_800121F4;
    }
    // 0x800121E0: nop

    // 0x800121E4: jal         0x80061F70
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_animate(rdram, ctx);
        goto after_1;
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800121EC: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121F0: nop

L_800121F4:
    // 0x800121F4: beq         $v1, $zero, L_800122C4
    if (ctx->r3 == 0) {
        // 0x800121F8: nop
    
            goto L_800122C4;
    }
    // 0x800121F8: nop

    // 0x800121FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80012200: nop

    // 0x80012204: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x80012208: nop

    // 0x8001220C: beq         $t8, $zero, L_800122C4
    if (ctx->r24 == 0) {
        // 0x80012210: nop
    
            goto L_800122C4;
    }
    // 0x80012210: nop

    // 0x80012214: beq         $s3, $zero, L_80012244
    if (ctx->r19 == 0) {
        // 0x80012218: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80012244;
    }
    // 0x80012218: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001221C: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012220: nop

    // 0x80012224: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80012228: beq         $at, $zero, L_80012244
    if (ctx->r1 == 0) {
        // 0x8001222C: nop
    
            goto L_80012244;
    }
    // 0x8001222C: nop

    // 0x80012230: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x80012234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012238: bne         $t5, $at, L_80012244
    if (ctx->r13 != ctx->r1) {
        // 0x8001223C: nop
    
            goto L_80012244;
    }
    // 0x8001223C: nop

    // 0x80012240: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80012244:
    // 0x80012244: jal         0x80066450
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    after_2:
    // 0x8001224C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012250: beq         $v0, $zero, L_8001225C
    if (ctx->r2 == 0) {
        // 0x80012254: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8001225C;
    }
    // 0x80012254: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80012258: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001225C:
    // 0x8001225C: lb          $t7, 0x1F($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1F);
    // 0x80012260: lh          $t5, 0x48($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X48);
    // 0x80012264: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80012268: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x8001226C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80012270: bne         $t5, $at, L_80012294
    if (ctx->r13 != ctx->r1) {
        // 0x80012274: sw          $t9, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r25;
            goto L_80012294;
    }
    // 0x80012274: sw          $t9, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r25;
    // 0x80012278: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001227C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80012280: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012284: jal         0x8001D718
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    obj_shade_fancy(rdram, ctx);
        goto after_3;
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8001228C: b           L_800122C4
    // 0x80012290: nop

        goto L_800122C4;
    // 0x80012290: nop

L_80012294:
    // 0x80012294: beq         $t1, $zero, L_800122B4
    if (ctx->r9 == 0) {
        // 0x80012298: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800122B4;
    }
    // 0x80012298: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001229C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122A0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800122A4: jal         0x8001D718
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    obj_shade_fancy(rdram, ctx);
        goto after_4;
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
    // 0x800122AC: b           L_800122C4
    // 0x800122B0: nop

        goto L_800122C4;
    // 0x800122B0: nop

L_800122B4:
    // 0x800122B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122B8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800122BC: jal         0x80024630
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_shade_fast(rdram, ctx);
        goto after_5;
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
L_800122C4:
    // 0x800122C4: beq         $s3, $zero, L_800122F8
    if (ctx->r19 == 0) {
        // 0x800122C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800122F8;
    }
    // 0x800122C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800122CC: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x800122D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800122D4: bne         $t7, $at, L_800122F8
    if (ctx->r15 != ctx->r1) {
        // 0x800122D8: nop
    
            goto L_800122F8;
    }
    // 0x800122D8: nop

    // 0x800122DC: lb          $t6, 0x1D6($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1D6);
    // 0x800122E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800122E4: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800122E8: beq         $at, $zero, L_800122F8
    if (ctx->r1 == 0) {
        // 0x800122EC: nop
    
            goto L_800122F8;
    }
    // 0x800122EC: nop

    // 0x800122F0: b           L_800122FC
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
        goto L_800122FC;
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
L_800122F8:
    // 0x800122F8: sb          $t9, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r25;
L_800122FC:
    // 0x800122FC: lb          $t5, 0x1F($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1F);
    // 0x80012300: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80012304: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012308: addu        $t6, $s0, $t7
    ctx->r14 = ADD32(ctx->r16, ctx->r15);
    // 0x8001230C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80012310: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80012314: bne         $t9, $at, L_80012328
    if (ctx->r25 != ctx->r1) {
        // 0x80012318: sw          $t8, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r24;
            goto L_80012328;
    }
    // 0x80012318: sw          $t8, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r24;
    // 0x8001231C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012320: jal         0x80011264
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_door_number(rdram, ctx);
        goto after_6;
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
L_80012328:
    // 0x80012328: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8001232C: nop

    // 0x80012330: lh          $a1, 0x52($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X52);
    // 0x80012334: nop

    // 0x80012338: beq         $a1, $zero, L_80012364
    if (ctx->r5 == 0) {
        // 0x8001233C: nop
    
            goto L_80012364;
    }
    // 0x8001233C: nop

    // 0x80012340: lh          $t7, 0x50($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X50);
    // 0x80012344: nop

    // 0x80012348: blez        $t7, L_80012364
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001234C: nop
    
            goto L_80012364;
    }
    // 0x8001234C: nop

    // 0x80012350: jal         0x80011134
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_7;
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80012358: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8001235C: nop

    // 0x80012360: sh          $zero, 0x52($t6)
    MEM_H(0X52, ctx->r14) = 0;
L_80012364:
    // 0x80012364: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012368: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001236C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012370: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80012374: lw          $a3, -0x4D58($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4D58);
    // 0x80012378: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001237C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012384: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80012388: jal         0x800696C4
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_8;
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80012390: beq         $s3, $zero, L_800123E4
    if (ctx->r19 == 0) {
        // 0x80012394: sw          $zero, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = 0;
            goto L_800123E4;
    }
    // 0x80012394: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x80012398: jal         0x80012F30
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_9;
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x800123A0: lb          $t8, 0x3B($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X3B);
    // 0x800123A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800123A8: beq         $t8, $zero, L_800123C4
    if (ctx->r24 == 0) {
        // 0x800123AC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800123C4;
    }
    // 0x800123AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800123B0: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x800123B4: nop

    // 0x800123B8: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x800123BC: bne         $at, $zero, L_800123E0
    if (ctx->r1 != 0) {
        // 0x800123C0: nop
    
            goto L_800123E0;
    }
    // 0x800123C0: nop

L_800123C4:
    // 0x800123C4: lh          $a3, 0x16A($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X16A);
    // 0x800123C8: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800123CC: jal         0x800699D0
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtx_head_push(rdram, ctx);
        goto after_10;
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x800123D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800123D8: b           L_800123E4
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
        goto L_800123E4;
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
L_800123E0:
    // 0x800123E0: sh          $zero, 0x16A($s3)
    MEM_H(0X16A, ctx->r19) = 0;
L_800123E4:
    // 0x800123E4: lbu         $t0, 0x39($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X39);
    // 0x800123E8: nop

    // 0x800123EC: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x800123F0: bne         $at, $zero, L_800123FC
    if (ctx->r1 != 0) {
        // 0x800123F4: nop
    
            goto L_800123FC;
    }
    // 0x800123F4: nop

    // 0x800123F8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800123FC:
    // 0x800123FC: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012400: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80012404: bne         $t7, $at, L_80012410
    if (ctx->r15 != ctx->r1) {
        // 0x80012408: sra         $t6, $t0, 1
        ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80012410;
    }
    // 0x80012408: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8001240C: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_80012410:
    // 0x80012410: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x80012414: beq         $at, $zero, L_80012420
    if (ctx->r1 == 0) {
        // 0x80012418: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80012420;
    }
    // 0x80012418: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001241C: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
L_80012420:
    // 0x80012420: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80012424: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80012428: beq         $t9, $zero, L_8001247C
    if (ctx->r25 == 0) {
        // 0x8001242C: nop
    
            goto L_8001247C;
    }
    // 0x8001242C: nop

    // 0x80012430: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012434: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012438: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001243C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012440: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012444: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012448: nop

    // 0x8001244C: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80012450: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80012454: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80012458: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    // 0x8001245C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80012460: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80012464: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80012468: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x8001246C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80012470: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80012474: b           L_80012494
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80012494;
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8001247C:
    // 0x8001247C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012480: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x80012484: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80012488: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8001248C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012490: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80012494:
    // 0x80012494: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80012498: nop

    // 0x8001249C: lbu         $t8, 0x71($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X71);
    // 0x800124A0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x800124A4: beq         $t8, $zero, L_80012504
    if (ctx->r24 == 0) {
        // 0x800124A8: nop
    
            goto L_80012504;
    }
    // 0x800124A8: nop

    // 0x800124AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800124B0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800124B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800124B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800124BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800124C0: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x800124C4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x800124C8: lbu         $t5, 0x19($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X19);
    // 0x800124CC: lbu         $t7, 0x18($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18);
    // 0x800124D0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800124D4: lbu         $t5, 0x1A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1A);
    // 0x800124D8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800124DC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800124E0: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x800124E4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800124E8: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x800124EC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800124F0: jal         0x8007B88C
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    directional_lighting_on(rdram, ctx);
        goto after_11;
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_11:
    // 0x800124F8: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800124FC: b           L_8001256C
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
        goto L_8001256C;
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_80012504:
    // 0x80012504: beq         $t7, $zero, L_80012550
    if (ctx->r15 == 0) {
        // 0x80012508: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012550;
    }
    // 0x80012508: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8001250C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012510: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012514: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012518: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8001251C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012520: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80012524: nop

    // 0x80012528: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001252C: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012530: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x80012534: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012538: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8001253C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80012540: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x80012544: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012548: b           L_80012568
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80012568;
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80012550:
    // 0x80012550: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012554: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012558: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001255C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012560: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80012564: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012568:
    // 0x80012568: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_8001256C:
    // 0x8001256C: beq         $at, $zero, L_8001259C
    if (ctx->r1 == 0) {
        // 0x80012570: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8001259C;
    }
    // 0x80012570: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012574: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012578: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001257C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012584: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012588: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x8001258C: jal         0x800143A8
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_12;
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_12:
    // 0x80012594: b           L_800125BC
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
        goto L_800125BC;
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_8001259C:
    // 0x8001259C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800125A0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800125A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800125A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800125AC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800125B0: jal         0x800143A8
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_mesh(rdram, ctx);
        goto after_13;
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x800125B8: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_800125BC:
    // 0x800125BC: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800125C0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800125C4: lbu         $t6, 0x71($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X71);
    // 0x800125C8: nop

    // 0x800125CC: beq         $t6, $zero, L_80012644
    if (ctx->r14 == 0) {
        // 0x800125D0: nop
    
            goto L_80012644;
    }
    // 0x800125D0: nop

    // 0x800125D4: beq         $t9, $zero, L_80012624
    if (ctx->r25 == 0) {
        // 0x800125D8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012624;
    }
    // 0x800125D8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800125DC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800125E0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800125E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800125E8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800125EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800125F0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800125F4: nop

    // 0x800125F8: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800125FC: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80012600: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80012604: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80012608: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8001260C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80012610: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012614: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80012618: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x8001261C: b           L_8001263C
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8001263C;
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80012624:
    // 0x80012624: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012628: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001262C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80012630: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012634: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80012638: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8001263C:
    // 0x8001263C: jal         0x8007B8A4
    // 0x80012640: nop

    directional_lighting_off(rdram, ctx);
        goto after_14;
    // 0x80012640: nop

    after_14:
L_80012644:
    // 0x80012644: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x80012648: nop

    // 0x8001264C: beq         $v0, $zero, L_800129A0
    if (ctx->r2 == 0) {
        // 0x80012650: lw          $a1, 0x78($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X78);
            goto L_800129A0;
    }
    // 0x80012650: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012654: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80012658: beq         $s3, $zero, L_80012674
    if (ctx->r19 == 0) {
        // 0x8001265C: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80012674;
    }
    // 0x8001265C: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x80012660: lb          $t5, 0x1D6($s3)
    ctx->r13 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012668: bne         $t5, $at, L_80012678
    if (ctx->r13 != ctx->r1) {
        // 0x8001266C: lw          $t7, 0xAC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XAC);
            goto L_80012678;
    }
    // 0x8001266C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80012670: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
L_80012674:
    // 0x80012674: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
L_80012678:
    // 0x80012678: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001267C: blez        $t7, L_8001299C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80012680: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8001299C;
    }
    // 0x80012680: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80012684: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80012688:
    // 0x80012688: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x8001268C: nop

    // 0x80012690: addu        $t6, $v0, $t3
    ctx->r14 = ADD32(ctx->r2, ctx->r11);
    // 0x80012694: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x80012698: nop

    // 0x8001269C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800126A0: nop

    // 0x800126A4: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x800126A8: bne         $t9, $zero, L_80012990
    if (ctx->r25 != 0) {
        // 0x800126AC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126AC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126B0: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x800126B4: nop

    // 0x800126B8: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x800126BC: lb          $v1, 0x0($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X0);
    // 0x800126C0: nop

    // 0x800126C4: bltz        $v1, L_80012990
    if (SIGNED(ctx->r3) < 0) {
        // 0x800126C8: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126C8: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126CC: lh          $t6, 0x18($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X18);
    // 0x800126D0: nop

    // 0x800126D4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800126D8: beq         $at, $zero, L_80012990
    if (ctx->r1 == 0) {
        // 0x800126DC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126DC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126E0: lb          $t9, 0x3A($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3A);
    // 0x800126E4: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x800126E8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800126EC: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x800126F0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800126F4: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800126F8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800126FC: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80012700: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80012704: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012708: lw          $t6, 0x44($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X44);
    // 0x8001270C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80012710: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80012714: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80012718: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001271C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80012720: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80012724: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80012728: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001272C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012730: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80012734: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80012738: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001273C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012740: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80012744: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80012748: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001274C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80012750: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012758: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001275C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012760: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80012764: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80012768: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8001276C: lb          $t7, 0x53($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X53);
    // 0x80012770: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80012774: bne         $t7, $at, L_80012784
    if (ctx->r15 != ctx->r1) {
        // 0x80012778: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_80012784;
    }
    // 0x80012778: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8001277C: b           L_80012788
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
        goto L_80012788;
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
L_80012784:
    // 0x80012784: addiu       $t1, $zero, 0x10B
    ctx->r9 = ADD32(0, 0X10B);
L_80012788:
    // 0x80012788: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8001278C: beq         $at, $zero, L_80012798
    if (ctx->r1 == 0) {
        // 0x80012790: ori         $t8, $t1, 0x4
        ctx->r24 = ctx->r9 | 0X4;
            goto L_80012798;
    }
    // 0x80012790: ori         $t8, $t1, 0x4
    ctx->r24 = ctx->r9 | 0X4;
    // 0x80012794: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
L_80012798:
    // 0x80012798: lw          $t5, 0x310($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X310);
    // 0x8001279C: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x800127A0: beq         $t5, $at, L_800127AC
    if (ctx->r13 == ctx->r1) {
        // 0x800127A4: nop
    
            goto L_800127AC;
    }
    // 0x800127A4: nop

    // 0x800127A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800127AC:
    // 0x800127AC: bne         $a0, $zero, L_80012960
    if (ctx->r4 != 0) {
        // 0x800127B0: nop
    
            goto L_80012960;
    }
    // 0x800127B0: nop

    // 0x800127B4: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800127B8: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800127BC: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800127C0: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x800127C4: beq         $v0, $zero, L_800127DC
    if (ctx->r2 == 0) {
        // 0x800127C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800127DC;
    }
    // 0x800127C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800127CC: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x800127D0: nop

    // 0x800127D4: xori        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 ^ 0X3;
    // 0x800127D8: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_800127DC:
    // 0x800127DC: sll         $t0, $v0, 24
    ctx->r8 = S32(ctx->r2 << 24);
    // 0x800127E0: sra         $t8, $t0, 24
    ctx->r24 = S32(SIGNED(ctx->r8) >> 24);
    // 0x800127E4: beq         $s3, $zero, L_80012804
    if (ctx->r19 == 0) {
        // 0x800127E8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_80012804;
    }
    // 0x800127E8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800127EC: lbu         $t5, 0x1F7($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X1F7);
    // 0x800127F0: nop

    // 0x800127F4: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x800127F8: beq         $at, $zero, L_80012804
    if (ctx->r1 == 0) {
        // 0x800127FC: nop
    
            goto L_80012804;
    }
    // 0x800127FC: nop

    // 0x80012800: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80012804:
    // 0x80012804: beq         $t0, $zero, L_800128B4
    if (ctx->r8 == 0) {
        // 0x80012808: andi        $t6, $v1, 0xFF
        ctx->r14 = ctx->r3 & 0XFF;
            goto L_800128B4;
    }
    // 0x80012808: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001280C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80012810: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80012814: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80012818: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8001281C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80012820: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012824: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80012828: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8001282C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80012830: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80012834: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x80012838: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x8001283C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012840: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80012844: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x80012848: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001284C: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012850: jal         0x80012C98
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    func_80012C98(rdram, ctx);
        goto after_15;
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80012858: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001285C: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x80012860: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012864: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012868: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001286C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012870: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80012874: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012878: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001287C: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012880: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012884: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012888: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8001288C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012890: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012894: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012898: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8001289C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800128A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800128A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800128A8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800128AC: nop

    // 0x800128B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800128B4:
    // 0x800128B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800128B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800128BC: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800128C0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800128C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800128C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800128CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800128D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800128D4: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x800128D8: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x800128DC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800128E0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800128E4: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x800128E8: jal         0x80068754
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    render_sprite_billboard(rdram, ctx);
        goto after_16;
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_16:
    // 0x800128F0: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x800128F4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x800128F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800128FC: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012900: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012904: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012908: beq         $t0, $zero, L_80012960
    if (ctx->r8 == 0) {
        // 0x8001290C: sw          $v0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r2;
            goto L_80012960;
    }
    // 0x8001290C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x80012910: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012914: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x80012918: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001291C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012920: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x80012924: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012928: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001292C: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x80012930: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012934: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80012938: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8001293C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012940: jal         0x80012CE8
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80012CE8(rdram, ctx);
        goto after_17;
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80012948: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001294C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012950: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012954: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012958: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001295C: nop

L_80012960:
    // 0x80012960: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012964: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012968: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001296C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012970: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80012974: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80012978: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8001297C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80012980: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012984: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012988: nop

    // 0x8001298C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80012990:
    // 0x80012990: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012994: bne         $t2, $t9, L_80012688
    if (ctx->r10 != ctx->r25) {
        // 0x80012998: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80012688;
    }
    // 0x80012998: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_8001299C:
    // 0x8001299C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
L_800129A0:
    // 0x800129A0: beq         $s3, $zero, L_80012AF8
    if (ctx->r19 == 0) {
        // 0x800129A4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129A4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129A8: lw          $s0, 0x144($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X144);
    // 0x800129AC: nop

    // 0x800129B0: beq         $s0, $zero, L_80012AF8
    if (ctx->r16 == 0) {
        // 0x800129B4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129B4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129B8: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800129BC: nop

    // 0x800129C0: lb          $v1, 0x58($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X58);
    // 0x800129C4: nop

    // 0x800129C8: bltz        $v1, L_80012AF8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800129CC: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129CC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129D0: lh          $t5, 0x18($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X18);
    // 0x800129D4: nop

    // 0x800129D8: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800129DC: beq         $at, $zero, L_80012AF8
    if (ctx->r1 == 0) {
        // 0x800129E0: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129E0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129E4: lb          $t6, 0x3A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3A);
    // 0x800129E8: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x800129EC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800129F0: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x800129F4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800129F8: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800129FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80012A00: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x80012A04: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80012A08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80012A0C: lw          $t5, 0x44($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X44);
    // 0x80012A10: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80012A14: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80012A18: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x80012A1C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80012A20: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80012A24: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80012A28: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80012A2C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012A30: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012A34: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80012A38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80012A3C: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80012A40: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80012A44: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012A48: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80012A4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80012A50: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012A54: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012A5C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80012A60: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80012A64: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80012A68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012A6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012A70: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x80012A74: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80012A78: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80012A7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80012A80: addiu       $t6, $zero, 0x10A
    ctx->r14 = ADD32(0, 0X10A);
    // 0x80012A84: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80012A88: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012A8C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80012A90: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80012A94: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80012A98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012A9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80012AA0: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80012AA4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012AA8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80012AAC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80012AB0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80012AB4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012AB8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x80012ABC: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80012AC0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80012AC4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80012AC8: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80012ACC: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x80012AD0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80012AD4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012AD8: lb          $t8, 0x53($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X53);
    // 0x80012ADC: nop

    // 0x80012AE0: bne         $t8, $at, L_80012AF8
    if (ctx->r24 != ctx->r1) {
        // 0x80012AE4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x80012AE4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80012AE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80012AEC: jal         0x80068754
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    render_sprite_billboard(rdram, ctx);
        goto after_18;
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x80012AF4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
L_80012AF8:
    // 0x80012AF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012AFC: beq         $t7, $at, L_80012BA8
    if (ctx->r15 == ctx->r1) {
        // 0x80012B00: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B00: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B04: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012B08: nop

    // 0x80012B0C: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012B10: nop

    // 0x80012B14: beq         $t5, $zero, L_80012B6C
    if (ctx->r13 == 0) {
        // 0x80012B18: lw          $t5, 0xB0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB0);
            goto L_80012B6C;
    }
    // 0x80012B18: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012B1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012B20: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012B24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012B28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012B2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012B30: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012B34: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80012B38: lbu         $t6, 0x19($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X19);
    // 0x80012B3C: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x80012B40: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80012B44: lbu         $t6, 0x1A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1A);
    // 0x80012B48: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012B4C: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80012B50: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012B54: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012B58: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80012B5C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80012B60: jal         0x8007B88C
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    directional_lighting_on(rdram, ctx);
        goto after_19;
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_19:
    // 0x80012B68: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
L_80012B6C:
    // 0x80012B6C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012B70: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x80012B74: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012B78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012B7C: jal         0x800143A8
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_20;
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_20:
    // 0x80012B84: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x80012B88: nop

    // 0x80012B8C: lbu         $t7, 0x71($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X71);
    // 0x80012B90: nop

    // 0x80012B94: beq         $t7, $zero, L_80012BA8
    if (ctx->r15 == 0) {
        // 0x80012B98: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B98: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B9C: jal         0x8007B8A4
    // 0x80012BA0: nop

    directional_lighting_off(rdram, ctx);
        goto after_21;
    // 0x80012BA0: nop

    after_21:
    // 0x80012BA4: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_80012BA8:
    // 0x80012BA8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80012BAC: bne         $t6, $zero, L_80012BCC
    if (ctx->r14 != 0) {
        // 0x80012BB0: nop
    
            goto L_80012BCC;
    }
    // 0x80012BB0: nop

    // 0x80012BB4: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012BB8: nop

    // 0x80012BBC: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012BC0: nop

    // 0x80012BC4: beq         $t5, $zero, L_80012BE8
    if (ctx->r13 == 0) {
        // 0x80012BC8: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80012BE8;
    }
    // 0x80012BC8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BCC:
    // 0x80012BCC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BD0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012BD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012BD8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012BDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012BE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012BE4: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BE8:
    // 0x80012BE8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80012BEC: beq         $t9, $zero, L_80012C0C
    if (ctx->r25 == 0) {
        // 0x80012BF0: nop
    
            goto L_80012C0C;
    }
    // 0x80012BF0: nop

    // 0x80012BF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BF8: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x80012BFC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012C00: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012C04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80012C08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80012C0C:
    // 0x80012C0C: jal         0x80069C80
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_22;
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
L_80012C14:
    // 0x80012C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012C18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80012C1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80012C20: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80012C24: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80012C28: jr          $ra
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80012C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012C34: jr          $ra
    // 0x80012C38: sh          $zero, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = 0;
    return;
    // 0x80012C38: sh          $zero, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80012C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012C40: addiu       $a3, $a3, -0x4CDC
    ctx->r7 = ADD32(ctx->r7, -0X4CDC);
    // 0x80012C44: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80012C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012C4C: blez        $t6, L_80012C90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012C50: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80012C90;
    }
    // 0x80012C50: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012C54: addiu       $a2, $a2, -0x4D08
    ctx->r6 = ADD32(ctx->r6, -0X4D08);
    // 0x80012C58: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
L_80012C5C:
    // 0x80012C5C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80012C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80012C64: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80012C68: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012C6C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80012C70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80012C74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80012C78: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80012C7C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80012C80: nop

    // 0x80012C84: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012C88: bne         $at, $zero, L_80012C5C
    if (ctx->r1 != 0) {
        // 0x80012C8C: nop
    
            goto L_80012C5C;
    }
    // 0x80012C8C: nop

L_80012C90:
    // 0x80012C90: jr          $ra
    // 0x80012C94: nop

    return;
    // 0x80012C94: nop

;}
RECOMP_FUNC void func_80012C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012C9C: addiu       $a1, $a1, -0x4CDC
    ctx->r5 = ADD32(ctx->r5, -0X4CDC);
    // 0x80012CA0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80012CA4: nop

    // 0x80012CA8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CAC: beq         $at, $zero, L_80012CE0
    if (ctx->r1 == 0) {
        // 0x80012CB0: nop
    
            goto L_80012CE0;
    }
    // 0x80012CB0: nop

    // 0x80012CB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012CB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012CBC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012CC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012CC4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012CC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80012CCC: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x80012CD0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80012CD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012CD8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80012CDC: sw          $t8, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = ctx->r24;
L_80012CE0:
    // 0x80012CE0: jr          $ra
    // 0x80012CE4: nop

    return;
    // 0x80012CE4: nop

;}
RECOMP_FUNC void func_80012CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012CE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012CEC: addiu       $a2, $a2, -0x4CDC
    ctx->r6 = ADD32(ctx->r6, -0X4CDC);
    // 0x80012CF0: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80012CF4: nop

    // 0x80012CF8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CFC: beq         $at, $zero, L_80012D54
    if (ctx->r1 == 0) {
        // 0x80012D00: nop
    
            goto L_80012D54;
    }
    // 0x80012D00: nop

    // 0x80012D04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012D08: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80012D0C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012D10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012D14: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012D18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012D1C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80012D20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012D24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012D28: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80012D2C: lw          $a1, -0x4D08($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4D08);
    // 0x80012D30: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x80012D34: sw          $t1, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r9;
    // 0x80012D38: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80012D3C: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x80012D40: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80012D44: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
    // 0x80012D48: nop

    // 0x80012D4C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80012D50: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
L_80012D54:
    // 0x80012D54: jr          $ra
    // 0x80012D58: nop

    return;
    // 0x80012D58: nop

;}
RECOMP_FUNC void render_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80012D6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80012D70: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80012D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012D78: andi        $t7, $t6, 0x5000
    ctx->r15 = ctx->r14 & 0X5000;
    // 0x80012D7C: bne         $t7, $zero, L_80012E1C
    if (ctx->r15 != 0) {
        // 0x80012D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012E1C;
    }
    // 0x80012D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012D84: lh          $a1, 0x4A($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X4A);
    // 0x80012D88: jal         0x800B7BD8
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80012D90: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80012D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012D98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80012D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DA0: sw          $t9, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r25;
    // 0x80012DA4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80012DA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DB0: sw          $t1, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r9;
    // 0x80012DB4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80012DB8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DC0: sw          $t3, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r11;
    // 0x80012DC4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80012DC8: jal         0x8001348C
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    render_object_parts(rdram, ctx);
        goto after_1;
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80012DD0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DD4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80012DDC: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x80012DE0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80012DE4: lw          $t4, -0x4BF4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BF4);
    // 0x80012DE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80012DEC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80012DF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012DF4: lw          $t6, -0x4BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF0);
    // 0x80012DF8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80012DFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80012E00: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012E04: lw          $t8, -0x4BEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BEC);
    // 0x80012E08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012E0C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80012E10: jal         0x800B7BD8
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    update_object_stack_trace(rdram, ctx);
        goto after_2;
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_2:
    // 0x80012E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012E1C:
    // 0x80012E1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012E20: jr          $ra
    // 0x80012E24: nop

    return;
    // 0x80012E24: nop

;}
RECOMP_FUNC void object_do_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012E38: bne         $t6, $at, L_80012F20
    if (ctx->r14 != ctx->r1) {
        // 0x80012E3C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80012F20;
    }
    // 0x80012E3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80012E40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012E44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012E48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012E4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012E50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80012E54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012E58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012E5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012E60: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80012E64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012E68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012E6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80012E70: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80012E74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012E78: lb          $t6, 0x1D7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1D7);
    // 0x80012E7C: nop

    // 0x80012E80: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80012E84: beq         $at, $zero, L_80012F0C
    if (ctx->r1 == 0) {
        // 0x80012E88: nop
    
            goto L_80012F0C;
    }
    // 0x80012E88: nop

    // 0x80012E8C: lh          $a0, 0x164($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X164);
    // 0x80012E90: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80012E94: jal         0x80070A38
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80012E9C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012EA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80012EA4: lh          $t8, 0x166($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X166);
    // 0x80012EA8: lh          $t7, 0x162($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X162);
    // 0x80012EAC: nop

    // 0x80012EB0: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80012EB4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80012EB8: jal         0x80070A38
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80012EC0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012EC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80012EC8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80012ECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012ED0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012ED4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80012ED8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80012EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012EE0: bc1f        L_80012EF0
    if (!c1cs) {
        // 0x80012EE4: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_80012EF0;
    }
    // 0x80012EE4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80012EE8: b           L_80012EF8
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80012EF8;
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80012EF0:
    // 0x80012EF0: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80012EF4: nop

L_80012EF8:
    // 0x80012EF8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80012EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012F00: lwc1        $f18, 0xD0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80012F04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012F08: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_80012F0C:
    // 0x80012F0C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80012F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F14: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80012F18: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80012F1C: swc1        $f0, -0x4CB0($at)
    MEM_W(-0X4CB0, ctx->r1) = ctx->f0.u32l;
L_80012F20:
    // 0x80012F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80012F28: jr          $ra
    // 0x80012F2C: nop

    return;
    // 0x80012F2C: nop

;}
RECOMP_FUNC void object_undo_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F38: bne         $t6, $at, L_80012F8C
    if (ctx->r14 != ctx->r1) {
        // 0x80012F3C: nop
    
            goto L_80012F8C;
    }
    // 0x80012F3C: nop

    // 0x80012F40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012F44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012F48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012F4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012F50: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80012F54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012F58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012F5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012F60: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80012F64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012F68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012F6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F70: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80012F74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012F78: lwc1        $f6, -0x4CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CB0);
    // 0x80012F7C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80012F80: nop

    // 0x80012F84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80012F88: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_80012F8C:
    // 0x80012F8C: jr          $ra
    // 0x80012F90: nop

    return;
    // 0x80012F90: nop

;}
RECOMP_FUNC void set_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012FA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012FA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80012FA8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80012FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80012FB0: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80012FB4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80012FB8: bne         $t7, $zero, L_8001346C
    if (ctx->r15 != 0) {
        // 0x80012FBC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8001346C;
    }
    // 0x80012FBC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80012FC0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80012FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012FC8: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80012FCC: nop

    // 0x80012FD0: bne         $t9, $at, L_8001344C
    if (ctx->r25 != ctx->r1) {
        // 0x80012FD4: nop
    
            goto L_8001344C;
    }
    // 0x80012FD4: nop

    // 0x80012FD8: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x80012FDC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80012FE0: lh          $v0, 0x206($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X206);
    // 0x80012FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012FE8: blez        $v0, L_80013024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012FEC: sb          $t3, 0x201($t2)
        MEM_B(0X201, ctx->r10) = ctx->r11;
            goto L_80013024;
    }
    // 0x80012FEC: sb          $t3, 0x201($t2)
    MEM_B(0X201, ctx->r10) = ctx->r11;
    // 0x80012FF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80012FF4: lwc1        $f0, 0x5AE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AE4);
    // 0x80012FF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012FFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013000: lwc1        $f8, 0x5AE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5AE8);
    // 0x80013004: nop

    // 0x80013008: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001300C: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80013010: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80013014: nop

    // 0x80013018: bc1f        L_80013024
    if (!c1cs) {
        // 0x8001301C: nop
    
            goto L_80013024;
    }
    // 0x8001301C: nop

    // 0x80013020: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80013024:
    // 0x80013024: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80013028: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001302C: beq         $t4, $at, L_8001304C
    if (ctx->r12 == ctx->r1) {
        // 0x80013030: nop
    
            goto L_8001304C;
    }
    // 0x80013030: nop

    // 0x80013034: lb          $t5, 0x1D8($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X1D8);
    // 0x80013038: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001303C: beq         $t5, $zero, L_8001304C
    if (ctx->r13 == 0) {
        // 0x80013040: nop
    
            goto L_8001304C;
    }
    // 0x80013040: nop

    // 0x80013044: b           L_80013274
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001304C:
    // 0x8001304C: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80013050: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80013054: bne         $t6, $at, L_80013064
    if (ctx->r14 != ctx->r1) {
        // 0x80013058: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80013064;
    }
    // 0x80013058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001305C: b           L_80013274
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80013064:
    // 0x80013064: lb          $t1, 0x1D6($t2)
    ctx->r9 = MEM_B(ctx->r10, 0X1D6);
    // 0x80013068: nop

    // 0x8001306C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80013070: bne         $at, $zero, L_80013080
    if (ctx->r1 != 0) {
        // 0x80013074: addiu       $a0, $t1, 0x5
        ctx->r4 = ADD32(ctx->r9, 0X5);
            goto L_80013080;
    }
    // 0x80013074: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
    // 0x80013078: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001307C: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
L_80013080:
    // 0x80013080: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80013084: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80013088: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8001308C: jal         0x8001E2D0
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80013094: jal         0x80066450
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001309C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800130A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130A4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800130A8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800130AC: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800130B0: jal         0x80066460
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x800130B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800130BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130C0: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800130C4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800130C8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800130CC: beq         $v0, $t8, L_800130D8
    if (ctx->r2 == ctx->r24) {
        // 0x800130D0: nop
    
            goto L_800130D8;
    }
    // 0x800130D0: nop

    // 0x800130D4: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
L_800130D8:
    // 0x800130D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800130DC: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800130E0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800130E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800130E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800130EC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800130F0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800130F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800130F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800130FC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80013100: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80013104: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80013108: bc1f        L_80013118
    if (!c1cs) {
        // 0x8001310C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80013118;
    }
    // 0x8001310C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80013110: b           L_80013134
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80013134;
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013118:
    // 0x80013118: lwc1        $f2, 0x5AEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5AEC);
    // 0x8001311C: nop

    // 0x80013120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80013124: nop

    // 0x80013128: bc1f        L_80013134
    if (!c1cs) {
        // 0x8001312C: nop
    
            goto L_80013134;
    }
    // 0x8001312C: nop

    // 0x80013130: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013134:
    // 0x80013134: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013138: lwc1        $f18, 0x5AF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AF0);
    // 0x8001313C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013140: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013148: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001314C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80013150: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80013154: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013158: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8001315C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80013160: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80013164: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80013168: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8001316C: jal         0x8001E2D0
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80013174: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013178: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001317C: lb          $t4, 0x3($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X3);
    // 0x80013180: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80013184: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013188: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001318C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013190: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80013194: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80013198: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001319C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800131A0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800131A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800131A8: nop

    // 0x800131AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800131B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800131B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800131B8: nop

    // 0x800131BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800131C0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800131C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800131C8: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x800131CC: beq         $at, $zero, L_800131DC
    if (ctx->r1 == 0) {
        // 0x800131D0: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800131DC;
    }
    // 0x800131D0: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800131D4: b           L_80013274
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_80013274;
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_800131DC:
    // 0x800131DC: bgez        $t8, L_800131E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800131E0: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800131E8;
    }
    // 0x800131E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800131E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800131E8:
    // 0x800131E8: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800131EC: nop

    // 0x800131F0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800131F4: beq         $at, $zero, L_80013204
    if (ctx->r1 == 0) {
        // 0x800131F8: nop
    
            goto L_80013204;
    }
    // 0x800131F8: nop

    // 0x800131FC: b           L_80013274
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80013274;
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013204:
    // 0x80013204: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x80013208: nop

    // 0x8001320C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80013210: beq         $at, $zero, L_80013220
    if (ctx->r1 == 0) {
        // 0x80013214: nop
    
            goto L_80013220;
    }
    // 0x80013214: nop

    // 0x80013218: b           L_80013274
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80013274;
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013220:
    // 0x80013220: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80013224: nop

    // 0x80013228: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001322C: beq         $at, $zero, L_8001323C
    if (ctx->r1 == 0) {
        // 0x80013230: nop
    
            goto L_8001323C;
    }
    // 0x80013230: nop

    // 0x80013234: b           L_80013274
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80013274;
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8001323C:
    // 0x8001323C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80013240: nop

    // 0x80013244: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80013248: beq         $at, $zero, L_80013258
    if (ctx->r1 == 0) {
        // 0x8001324C: nop
    
            goto L_80013258;
    }
    // 0x8001324C: nop

    // 0x80013250: b           L_80013274
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
        goto L_80013274;
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_80013258:
    // 0x80013258: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8001325C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80013260: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80013264: beq         $at, $zero, L_80013274
    if (ctx->r1 == 0) {
        // 0x80013268: nop
    
            goto L_80013274;
    }
    // 0x80013268: nop

    // 0x8001326C: b           L_80013274
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_80013274;
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80013274:
    // 0x80013274: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80013278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001327C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013280: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80013284: bne         $t7, $zero, L_8001329C
    if (ctx->r15 != 0) {
        // 0x80013288: nop
    
            goto L_8001329C;
    }
    // 0x80013288: nop

L_8001328C:
    // 0x8001328C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80013290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80013294: beq         $t8, $zero, L_8001328C
    if (ctx->r24 == 0) {
        // 0x80013298: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001328C;
    }
    // 0x80013298: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8001329C:
    // 0x8001329C: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800132A0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800132A4: lb          $v1, 0x55($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X55);
    // 0x800132A8: nop

    // 0x800132AC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132B0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800132B4: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x800132B8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800132BC: nop

    // 0x800132C0: bne         $t4, $zero, L_800132D8
    if (ctx->r12 != 0) {
        // 0x800132C4: nop
    
            goto L_800132D8;
    }
    // 0x800132C4: nop

L_800132C8:
    // 0x800132C8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800132CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132D0: beq         $t5, $zero, L_800132C8
    if (ctx->r13 == 0) {
        // 0x800132D4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800132C8;
    }
    // 0x800132D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_800132D8:
    // 0x800132D8: beq         $at, $zero, L_800132E4
    if (ctx->r1 == 0) {
        // 0x800132DC: lui         $a3, 0x81
        ctx->r7 = S32(0X81 << 16);
            goto L_800132E4;
    }
    // 0x800132DC: lui         $a3, 0x81
    ctx->r7 = S32(0X81 << 16);
    // 0x800132E0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_800132E4:
    // 0x800132E4: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800132E8: beq         $at, $zero, L_800132F4
    if (ctx->r1 == 0) {
        // 0x800132EC: lui         $a2, 0x1
        ctx->r6 = S32(0X1 << 16);
            goto L_800132F4;
    }
    // 0x800132EC: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800132F0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800132F4:
    // 0x800132F4: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800132F8: sb          $t0, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r8;
    // 0x800132FC: beq         $v0, $zero, L_80013334
    if (ctx->r2 == 0) {
        // 0x80013300: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80013334;
    }
    // 0x80013300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013304: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013308: lwc1        $f10, 0x5AF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5AF4);
    // 0x8001330C: nop

    // 0x80013310: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80013314: nop

    // 0x80013318: bc1f        L_80013334
    if (!c1cs) {
        // 0x8001331C: nop
    
            goto L_80013334;
    }
    // 0x8001331C: nop

    // 0x80013320: lbu         $t6, 0x20A($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013324: nop

    // 0x80013328: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8001332C: b           L_80013344
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
        goto L_80013344;
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
L_80013334:
    // 0x80013334: lbu         $t8, 0x20A($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013338: nop

    // 0x8001333C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80013340: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013344:
    // 0x80013344: lb          $t4, 0x3A($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3A);
    // 0x80013348: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x8001334C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013350: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80013354: lbu         $v0, 0x20A($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013358: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8001335C: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x80013360: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80013364: beq         $t0, $zero, L_800133BC
    if (ctx->r8 == 0) {
        // 0x80013368: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_800133BC;
    }
    // 0x80013368: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8001336C: beq         $t7, $zero, L_80013388
    if (ctx->r15 == 0) {
        // 0x80013370: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80013388;
    }
    // 0x80013370: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80013374: andi        $t8, $v0, 0xFFEF
    ctx->r24 = ctx->r2 & 0XFFEF;
    // 0x80013378: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001337C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80013380: b           L_800133BC
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
        goto L_800133BC;
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013388:
    // 0x80013388: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x8001338C: beq         $t4, $zero, L_800133A8
    if (ctx->r12 == 0) {
        // 0x80013390: andi        $t6, $v0, 0x20
        ctx->r14 = ctx->r2 & 0X20;
            goto L_800133A8;
    }
    // 0x80013390: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80013394: andi        $t3, $v0, 0xFFDF
    ctx->r11 = ctx->r2 & 0XFFDF;
    // 0x80013398: ori         $t5, $t3, 0x10
    ctx->r13 = ctx->r11 | 0X10;
    // 0x8001339C: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x800133A0: b           L_800133BC
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
        goto L_800133BC;
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
L_800133A8:
    // 0x800133A8: beq         $t6, $zero, L_800133B8
    if (ctx->r14 == 0) {
        // 0x800133AC: nop
    
            goto L_800133B8;
    }
    // 0x800133AC: nop

    // 0x800133B0: b           L_800133BC
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800133BC;
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800133B8:
    // 0x800133B8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
L_800133BC:
    // 0x800133BC: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133C0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800133C4: blez        $a0, L_80013408
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800133C8: or          $t0, $t7, $zero
        ctx->r8 = ctx->r15 | 0;
            goto L_80013408;
    }
    // 0x800133C8: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x800133CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800133D0:
    // 0x800133D0: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x800133D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800133D8: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x800133DC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800133E0: nop

    // 0x800133E4: and         $t4, $t9, $a3
    ctx->r12 = ctx->r25 & ctx->r7;
    // 0x800133E8: bne         $a2, $t4, L_80013400
    if (ctx->r6 != ctx->r12) {
        // 0x800133EC: slt         $at, $t1, $a0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80013400;
    }
    // 0x800133EC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800133F0: sb          $t0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r8;
    // 0x800133F4: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133F8: nop

    // 0x800133FC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
L_80013400:
    // 0x80013400: bne         $at, $zero, L_800133D0
    if (ctx->r1 != 0) {
        // 0x80013404: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800133D0;
    }
    // 0x80013404: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80013408:
    // 0x80013408: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001340C: lwc1        $f18, 0x78($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X78);
    // 0x80013410: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013414: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013418: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001341C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80013420: lwc1        $f8, 0x7C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X7C);
    // 0x80013424: nop

    // 0x80013428: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001342C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80013430: lwc1        $f18, 0x80($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X80);
    // 0x80013434: nop

    // 0x80013438: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001343C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80013440: lwc1        $f0, 0x8C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X8C);
    // 0x80013444: b           L_8001346C
    // 0x80013448: nop

        goto L_8001346C;
    // 0x80013448: nop

L_8001344C:
    // 0x8001344C: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80013450: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x80013454: bne         $t3, $at, L_8001346C
    if (ctx->r11 != ctx->r1) {
        // 0x80013458: nop
    
            goto L_8001346C;
    }
    // 0x80013458: nop

    // 0x8001345C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80013460: nop

    // 0x80013464: lwc1        $f0, 0x30($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80013468: nop

L_8001346C:
    // 0x8001346C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013474: swc1        $f0, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->f0.u32l;
    // 0x80013478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001347C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013480: swc1        $f14, -0x4D50($at)
    MEM_W(-0X4D50, ctx->r1) = ctx->f14.u32l;
    // 0x80013484: jr          $ra
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void render_object_parts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001348C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013490: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013494: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013498: jal         0x80012F94
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    set_temp_model_transforms(rdram, ctx);
        goto after_0;
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800134A0: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800134A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800134A8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800134AC: beq         $t7, $zero, L_800134DC
    if (ctx->r15 == 0) {
        // 0x800134B0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800134DC;
    }
    // 0x800134B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800134B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800134B8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800134BC: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x800134C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800134C4: addiu       $a3, $a3, -0x4BEC
    ctx->r7 = ADD32(ctx->r7, -0X4BEC);
    // 0x800134C8: addiu       $a2, $a2, -0x4BF0
    ctx->r6 = ADD32(ctx->r6, -0X4BF0);
    // 0x800134CC: jal         0x800B3CA0
    // 0x800134D0: addiu       $a1, $a1, -0x4BF4
    ctx->r5 = ADD32(ctx->r5, -0X4BF4);
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800134D0: addiu       $a1, $a1, -0x4BF4
    ctx->r5 = ADD32(ctx->r5, -0X4BF4);
    after_1:
    // 0x800134D4: b           L_80013530
    // 0x800134D8: nop

        goto L_80013530;
    // 0x800134D8: nop

L_800134DC:
    // 0x800134DC: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800134E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800134E4: lb          $v0, 0x53($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X53);
    // 0x800134E8: nop

    // 0x800134EC: bne         $v0, $zero, L_80013504
    if (ctx->r2 != 0) {
        // 0x800134F0: nop
    
            goto L_80013504;
    }
    // 0x800134F0: nop

    // 0x800134F4: jal         0x800120C8
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_model(rdram, ctx);
        goto after_2;
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800134FC: b           L_80013530
    // 0x80013500: nop

        goto L_80013530;
    // 0x80013500: nop

L_80013504:
    // 0x80013504: bne         $v0, $at, L_80013520
    if (ctx->r2 != ctx->r1) {
        // 0x80013508: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80013520;
    }
    // 0x80013508: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001350C: jal         0x80011C94
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_billboard(rdram, ctx);
        goto after_3;
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80013514: b           L_80013530
    // 0x80013518: nop

        goto L_80013530;
    // 0x80013518: nop

    // 0x8001351C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80013520:
    // 0x80013520: bne         $v0, $at, L_80013530
    if (ctx->r2 != ctx->r1) {
        // 0x80013524: nop
    
            goto L_80013530;
    }
    // 0x80013524: nop

    // 0x80013528: jal         0x80011AD0
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_misc(rdram, ctx);
        goto after_4;
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80013530:
    // 0x80013530: jal         0x80013548
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    unset_temp_model_transforms(rdram, ctx);
        goto after_5;
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80013538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001353C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013540: jr          $ra
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unset_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013548: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001354C: nop

    // 0x80013550: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80013554: bne         $t7, $zero, L_800135B0
    if (ctx->r15 != 0) {
        // 0x80013558: nop
    
            goto L_800135B0;
    }
    // 0x80013558: nop

    // 0x8001355C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80013560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013564: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80013568: nop

    // 0x8001356C: bne         $t9, $at, L_800135B0
    if (ctx->r25 != ctx->r1) {
        // 0x80013570: nop
    
            goto L_800135B0;
    }
    // 0x80013570: nop

    // 0x80013574: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80013578: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001357C: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80013580: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80013584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80013588: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001358C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80013590: lwc1        $f16, 0x7C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80013594: nop

    // 0x80013598: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001359C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800135A0: lwc1        $f6, 0x80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X80);
    // 0x800135A4: nop

    // 0x800135A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800135AC: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
L_800135B0:
    // 0x800135B0: jr          $ra
    // 0x800135B4: nop

    return;
    // 0x800135B4: nop

;}
RECOMP_FUNC void func_800135B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800135B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800135BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800135C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800135C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800135C8: lw          $s0, 0x7C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X7C);
    // 0x800135CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800135D0: sra         $t6, $s0, 28
    ctx->r14 = S32(SIGNED(ctx->r16) >> 28);
    // 0x800135D4: andi        $s0, $t6, 0xF
    ctx->r16 = ctx->r14 & 0XF;
    // 0x800135D8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800135DC: lbu         $v0, -0x4A38($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4A38);
    // 0x800135E0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800135E4: beq         $v0, $zero, L_80013600
    if (ctx->r2 == 0) {
        // 0x800135E8: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80013600;
    }
    // 0x800135E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800135EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800135F0: beq         $v0, $at, L_80013608
    if (ctx->r2 == ctx->r1) {
        // 0x800135F4: addiu       $v1, $s1, 0x24
        ctx->r3 = ADD32(ctx->r17, 0X24);
            goto L_80013608;
    }
    // 0x800135F4: addiu       $v1, $s1, 0x24
    ctx->r3 = ADD32(ctx->r17, 0X24);
    // 0x800135F8: b           L_80013608
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
        goto L_80013608;
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
L_80013600:
    // 0x80013600: b           L_80013608
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
        goto L_80013608;
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80013608:
    // 0x80013608: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001360C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80013610: jal         0x8001E2D0
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    after_0:
    // 0x80013618: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001361C: addiu       $t8, $t8, -0x4A28
    ctx->r24 = ADD32(ctx->r24, -0X4A28);
    // 0x80013620: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    // 0x80013624: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80013628: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8001362C: sll         $t4, $t9, 7
    ctx->r12 = S32(ctx->r25 << 7);
    // 0x80013630: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80013634: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80013638: lw          $a0, 0x78($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X78);
    // 0x8001363C: jal         0x80012E28
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    object_do_player_tumble(rdram, ctx);
        goto after_1;
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80013644: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80013648: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001364C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80013650: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80013654: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013658: lw          $a2, 0x78($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X78);
    // 0x8001365C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013664: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80013668: jal         0x800696C4
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80013670: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80013674: nop

    // 0x80013678: lw          $a0, 0x78($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X78);
    // 0x8001367C: jal         0x80012F30
    // 0x80013680: nop

    object_undo_player_tumble(rdram, ctx);
        goto after_3;
    // 0x80013680: nop

    after_3:
    // 0x80013684: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80013688: nop

    // 0x8001368C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013690: nop

    // 0x80013694: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80013698: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001369C: nop

    // 0x800136A0: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800136A4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800136A8: nop

    // 0x800136AC: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x800136B0: lbu         $t9, 0x72($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X72);
    // 0x800136B4: nop

    // 0x800136B8: sll         $t4, $t9, 28
    ctx->r12 = S32(ctx->r25 << 28);
    // 0x800136BC: jal         0x80070A38
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
    // 0x800136C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800136C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800136CC: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800136D0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800136D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800136D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800136DC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800136E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800136E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800136E8: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800136EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800136F0: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x800136F4: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800136F8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800136FC: beq         $at, $zero, L_80013714
    if (ctx->r1 == 0) {
        // 0x80013700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80013714;
    }
    // 0x80013700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013704: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80013708: nop

    // 0x8001370C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80013710: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80013714:
    // 0x80013714: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013718: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001371C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013720: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80013724: beq         $t8, $zero, L_80013740
    if (ctx->r24 == 0) {
        // 0x80013728: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80013740;
    }
    // 0x80013728: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8001372C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013730: lwc1        $f18, 0x5AF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AF8);
    // 0x80013734: nop

    // 0x80013738: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001373C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80013740:
    // 0x80013740: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013744: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x80013748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001374C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80013750: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013754: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x80013758: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8001375C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80013760: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80013764: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013768: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x8001376C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013770: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013774: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80013778: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001377C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80013780: addiu       $t5, $zero, 0x10A
    ctx->r13 = ADD32(0, 0X10A);
    // 0x80013784: lw          $t4, 0x78($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X78);
    // 0x80013788: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001378C: jal         0x80068754
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x80013794: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x80013798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001379C: bne         $t6, $at, L_8001388C
    if (ctx->r14 != ctx->r1) {
        // 0x800137A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001388C;
    }
    // 0x800137A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800137A4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800137A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800137AC: lw          $a1, 0x7C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X7C);
    // 0x800137B0: jal         0x8007B938
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800137B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800137BC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800137C0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x800137C4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800137C8: beq         $t9, $zero, L_800137D8
    if (ctx->r25 == 0) {
        // 0x800137CC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800137D8;
    }
    // 0x800137CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800137D0: b           L_800137DC
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800137DC;
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800137D8:
    // 0x800137D8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800137DC:
    // 0x800137DC: lw          $v1, 0x7C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X7C);
    // 0x800137E0: lw          $a0, -0x4A78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A78);
    // 0x800137E4: sra         $t7, $v1, 14
    ctx->r15 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800137E8: andi        $t8, $t7, 0x3FFF
    ctx->r24 = ctx->r15 & 0X3FFF;
    // 0x800137EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800137F0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800137F4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800137F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800137FC: lw          $t6, -0x3344($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3344);
    // 0x80013800: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80013804: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80013808: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001380C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80013810: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80013814: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013818: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    // 0x8001381C: andi        $t5, $v1, 0x3FFF
    ctx->r13 = ctx->r3 & 0X3FFF;
    // 0x80013820: lw          $t4, -0x333C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X333C);
    // 0x80013824: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013828: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8001382C: andi        $t6, $a2, 0x6
    ctx->r14 = ctx->r6 & 0X6;
    // 0x80013830: ori         $t9, $t6, 0x40
    ctx->r25 = ctx->r14 | 0X40;
    // 0x80013834: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013838: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x8001383C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80013840: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80013844: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013848: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8001384C: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80013850: ori         $t8, $t7, 0xAA
    ctx->r24 = ctx->r15 | 0XAA;
    // 0x80013854: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013858: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8001385C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013860: ori         $t9, $t2, 0x70
    ctx->r25 = ctx->r10 | 0X70;
    // 0x80013864: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013868: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001386C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013870: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013874: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80013878: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8001387C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80013880: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x80013884: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80013888: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8001388C:
    // 0x8001388C: jal         0x80069C80
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_7;
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80013894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001389C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800138A0: jr          $ra
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void render_bubble_trap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800138A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800138AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800138B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800138B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800138B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800138BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800138C0: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800138C4: jal         0x80070560
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800138CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800138D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800138D4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800138D8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800138DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800138E0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800138E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800138E8: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800138EC: nop

    // 0x800138F0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800138F4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800138F8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800138FC: nop

    // 0x80013900: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013904: jal         0x80069F60
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    cam_get_active_camera(rdram, ctx);
        goto after_1;
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8001390C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013910: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80013914: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013918: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8001391C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013920: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80013924: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80013928: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001392C: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80013930: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80013934: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80013938: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8001393C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80013940: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80013944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80013948: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001394C: jal         0x800CA030
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80013954: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80013958: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001395C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013960: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80013964: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80013968: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001396C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80013970: bc1f        L_800139AC
    if (!c1cs) {
        // 0x80013974: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800139AC;
    }
    // 0x80013974: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80013978: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x8001397C: nop

    // 0x80013980: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80013984: nop

    // 0x80013988: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001398C: nop

    // 0x80013990: div.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013994: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80013998: nop

    // 0x8001399C: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800139A0: nop

    // 0x800139A4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800139A8: nop

L_800139AC:
    // 0x800139AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800139B0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800139B4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800139B8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800139BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800139C0: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800139C4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800139C8: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800139CC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800139D0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800139D4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800139D8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800139DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800139E0: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800139E4: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800139E8: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x800139EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800139F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800139F4: jal         0x80068754
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x800139FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013A04: jr          $ra
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void render_racer_shield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A0C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80013A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013A14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013A18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013A1C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80013A20: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80013A24: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80013A28: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80013A2C: lw          $t0, 0x64($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X64);
    // 0x80013A30: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013A34: lh          $t7, 0x18E($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X18E);
    // 0x80013A38: addiu       $s0, $s0, -0x3334
    ctx->r16 = ADD32(ctx->r16, -0X3334);
    // 0x80013A3C: blez        $t7, L_80013DBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013A40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A44: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013A48: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013A4C: beq         $t8, $zero, L_80013DBC
    if (ctx->r24 == 0) {
        // 0x80013A50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A54: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80013A58: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80013A5C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013A60: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80013A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A68: sw          $t3, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r11;
    // 0x80013A6C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80013A70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A74: sw          $t5, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r13;
    // 0x80013A78: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x80013A7C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80013A80: slti        $at, $a2, 0xB
    ctx->r1 = SIGNED(ctx->r6) < 0XB ? 1 : 0;
    // 0x80013A84: bne         $at, $zero, L_80013A90
    if (ctx->r1 != 0) {
        // 0x80013A88: nop
    
            goto L_80013A90;
    }
    // 0x80013A88: nop

    // 0x80013A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80013A90:
    // 0x80013A90: lb          $a1, 0x1D6($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1D6);
    // 0x80013A94: nop

    // 0x80013A98: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80013A9C: bne         $at, $zero, L_80013AA8
    if (ctx->r1 != 0) {
        // 0x80013AA0: nop
    
            goto L_80013AA8;
    }
    // 0x80013AA0: nop

    // 0x80013AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80013AA8:
    // 0x80013AA8: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80013AAC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80013AB0: jal         0x8001E2D0
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_0:
    // 0x80013AB8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80013ABC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80013AC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80013AC4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80013AC8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80013ACC: addu        $a1, $t6, $a2
    ctx->r5 = ADD32(ctx->r14, ctx->r6);
    // 0x80013AD0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80013AD4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80013AD8: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80013ADC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80013AE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013AE4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80013AE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80013AEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013AF0: addiu       $t5, $t5, -0x4A70
    ctx->r13 = ADD32(ctx->r13, -0X4A70);
    // 0x80013AF4: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x80013AF8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x80013AFC: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x80013B00: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80013B04: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80013B08: nop

    // 0x80013B0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013B10: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80013B14: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x80013B18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013B1C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80013B20: nop

    // 0x80013B24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80013B28: swc1        $f18, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f18.u32l;
    // 0x80013B2C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80013B30: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80013B34: sll         $t7, $t6, 25
    ctx->r15 = S32(ctx->r14 << 25);
    // 0x80013B38: jal         0x80070A04
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80013B40: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80013B44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013B48: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80013B4C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013B50: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80013B54: nop

    // 0x80013B58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013B5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013B60: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80013B64: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80013B68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80013B6C: nop

    // 0x80013B70: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80013B74: nop

    // 0x80013B78: sll         $t4, $t3, 26
    ctx->r12 = S32(ctx->r11 << 26);
    // 0x80013B7C: jal         0x80070A38
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x80013B84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B88: lwc1        $f18, 0x5AFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AFC);
    // 0x80013B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B90: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013B94: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80013B98: lwc1        $f8, 0x5B00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5B00);
    // 0x80013B9C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013BA0: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013BA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013BA8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013BAC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013BB0: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80013BB4: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x80013BB8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013BBC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80013BC0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013BC4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013BC8: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80013BCC: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80013BD0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80013BD4: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80013BD8: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80013BDC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013BE0: nop

    // 0x80013BE4: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x80013BE8: lb          $a0, 0x189($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X189);
    // 0x80013BEC: nop

    // 0x80013BF0: beq         $a0, $zero, L_80013C00
    if (ctx->r4 == 0) {
        // 0x80013BF4: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013C00;
    }
    // 0x80013BF4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013BF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80013BFC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80013C00:
    // 0x80013C00: bne         $at, $zero, L_80013C0C
    if (ctx->r1 != 0) {
        // 0x80013C04: nop
    
            goto L_80013C0C;
    }
    // 0x80013C04: nop

    // 0x80013C08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80013C0C:
    // 0x80013C0C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80013C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013C14: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80013C18: lwc1        $f5, 0x5B08($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B08);
    // 0x80013C1C: lwc1        $f4, 0x5B0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B0C);
    // 0x80013C20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80013C24: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80013C28: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80013C2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80013C30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013C34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C38: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80013C3C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013C40: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80013C44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80013C48: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013C4C: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x80013C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013C54: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80013C58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C5C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80013C60: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x80013C64: nop

    // 0x80013C68: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80013C6C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80013C70: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80013C74: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80013C78: nop

    // 0x80013C7C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80013C80: lb          $t9, 0x1F($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1F);
    // 0x80013C84: nop

    // 0x80013C88: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013C8C: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80013C90: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80013C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013C98: sw          $t3, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r11;
    // 0x80013C9C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CA0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013CA4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013CA8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013CAC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80013CB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80013CB4: lh          $t6, 0x18E($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CB8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80013CBC: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80013CC0: beq         $at, $zero, L_80013CF8
    if (ctx->r1 == 0) {
        // 0x80013CC4: nop
    
            goto L_80013CF8;
    }
    // 0x80013CC4: nop

    // 0x80013CC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CCC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80013CD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013CD4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013CD8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013CDC: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CE0: nop

    // 0x80013CE4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013CE8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80013CEC: or          $t3, $t2, $a3
    ctx->r11 = ctx->r10 | ctx->r7;
    // 0x80013CF0: b           L_80013D10
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
        goto L_80013D10;
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80013CF8:
    // 0x80013CF8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013D00: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013D04: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013D08: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80013D0C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80013D10:
    // 0x80013D10: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013D14: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80013D18: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80013D1C: jal         0x800691E8
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_3:
    // 0x80013D24: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80013D28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013D30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013D34: jal         0x800143A8
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80013D3C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D40: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013D44: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013D48: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013D4C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80013D50: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80013D54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013D58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80013D5C: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013D60: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80013D64: slti        $at, $t9, 0x40
    ctx->r1 = SIGNED(ctx->r25) < 0X40 ? 1 : 0;
    // 0x80013D68: beq         $at, $zero, L_80013D88
    if (ctx->r1 == 0) {
        // 0x80013D6C: nop
    
            goto L_80013D88;
    }
    // 0x80013D6C: nop

    // 0x80013D70: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D74: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013D78: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80013D7C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013D80: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80013D84: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80013D88:
    // 0x80013D88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80013D8C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80013D90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80013D94: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80013D98: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80013D9C: lw          $t6, -0x4BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF0);
    // 0x80013DA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80013DA8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80013DAC: lw          $t8, -0x4BEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BEC);
    // 0x80013DB0: nop

    // 0x80013DB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80013DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80013DBC:
    // 0x80013DBC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80013DC0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80013DC4: jr          $ra
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void render_racer_magnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013DCC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80013DD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013DD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013DD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013DDC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80013DE0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80013DE4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80013DE8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80013DEC: lw          $t3, 0x64($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X64);
    // 0x80013DF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DF4: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013DF8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013DFC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80013E00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80013E04: lbu         $t8, -0x4A05($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4A05);
    // 0x80013E08: addiu       $s0, $s0, -0x332C
    ctx->r16 = ADD32(ctx->r16, -0X332C);
    // 0x80013E0C: beq         $t8, $zero, L_80014080
    if (ctx->r24 == 0) {
        // 0x80013E10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80014080;
    }
    // 0x80013E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013E14: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013E18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013E1C: beq         $t9, $zero, L_8001407C
    if (ctx->r25 == 0) {
        // 0x80013E20: addiu       $s1, $s1, -0x4BF4
        ctx->r17 = ADD32(ctx->r17, -0X4BF4);
            goto L_8001407C;
    }
    // 0x80013E20: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80013E24: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80013E28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E2C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80013E30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013E34: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80013E38: sw          $t7, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r15;
    // 0x80013E3C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80013E40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E44: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013E48: jal         0x8001E2D0
    // 0x80013E4C: sw          $t9, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r25;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013E4C: sw          $t9, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r25;
    after_0:
    // 0x80013E50: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013E54: nop

    // 0x80013E58: lb          $a0, 0x1D6($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X1D6);
    // 0x80013E5C: nop

    // 0x80013E60: bltz        $a0, L_80013E70
    if (SIGNED(ctx->r4) < 0) {
        // 0x80013E64: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013E70;
    }
    // 0x80013E64: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013E68: bne         $at, $zero, L_80013E74
    if (ctx->r1 != 0) {
        // 0x80013E6C: nop
    
            goto L_80013E74;
    }
    // 0x80013E6C: nop

L_80013E70:
    // 0x80013E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80013E74:
    // 0x80013E74: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013E78: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80013E7C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013E80: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013E84: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80013E88: bne         $at, $zero, L_80013E94
    if (ctx->r1 != 0) {
        // 0x80013E8C: addu        $v1, $t5, $v0
        ctx->r3 = ADD32(ctx->r13, ctx->r2);
            goto L_80013E94;
    }
    // 0x80013E8C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x80013E90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013E94:
    // 0x80013E94: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013E98: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013E9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80013EA0: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80013EA4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013EA8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013EAC: addiu       $t4, $t4, -0x4A08
    ctx->r12 = ADD32(ctx->r12, -0X4A08);
    // 0x80013EB0: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x80013EB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013EB8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80013EBC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80013EC0: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80013EC4: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x80013EC8: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80013ECC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80013ED0: sll         $t6, $t5, 26
    ctx->r14 = S32(ctx->r13 << 26);
    // 0x80013ED4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80013ED8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80013EDC: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013EE0: jal         0x80070A38
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_1:
    // 0x80013EE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EEC: lwc1        $f10, 0x5B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x80013EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EF4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80013EF8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80013EFC: lwc1        $f18, 0x5B14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5B14);
    // 0x80013F00: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013F04: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013F08: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013F0C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013F10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80013F14: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013F18: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80013F1C: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x80013F20: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013F24: lbu         $t9, 0x2($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X2);
    // 0x80013F28: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80013F2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80013F30: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x80013F34: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80013F38: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80013F3C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80013F40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013F48: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80013F4C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013F50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80013F54: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80013F58: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80013F5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80013F60: lw          $t8, 0x68($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X68);
    // 0x80013F64: nop

    // 0x80013F68: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80013F6C: nop

    // 0x80013F70: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80013F74: nop

    // 0x80013F78: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80013F7C: lb          $t4, 0x1F($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1F);
    // 0x80013F80: nop

    // 0x80013F84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013F88: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013F8C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80013F90: nop

    // 0x80013F94: sw          $t7, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r15;
    // 0x80013F98: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80013F9C: lb          $t4, 0x184($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X184);
    // 0x80013FA0: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x80013FA4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013FA8: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80013FAC: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80013FB0: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x80013FB4: lw          $a3, -0x3244($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3244);
    // 0x80013FB8: jal         0x8007F9E4
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_2;
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    after_2:
    // 0x80013FC0: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013FC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013FC8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013FCC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80013FD0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013FD8: jal         0x800691E8
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80013FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013FE8: sw          $t6, -0x3370($at)
    MEM_W(-0X3370, ctx->r1) = ctx->r14;
    // 0x80013FEC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013FF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80013FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013FF8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013FFC: jal         0x800143A8
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80014004: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014008: sw          $zero, -0x3370($at)
    MEM_W(-0X3370, ctx->r1) = 0;
    // 0x8001400C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80014010: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80014014: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014018: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001401C: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80014020: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80014024: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80014028: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001402C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80014030: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80014034: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80014038: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001403C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80014040: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80014044: jal         0x8007B820
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_5:
    // 0x8001404C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80014050: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80014054: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80014058: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8001405C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80014060: lw          $t8, -0x4BF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BF0);
    // 0x80014064: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80014068: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001406C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80014070: lw          $t4, -0x4BEC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BEC);
    // 0x80014074: nop

    // 0x80014078: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_8001407C:
    // 0x8001407C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80014080:
    // 0x80014080: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80014084: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80014088: jr          $ra
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80014090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014098: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001409C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800140A0: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800140A4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800140A8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800140AC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800140B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800140B4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800140B8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800140BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800140C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800140C4: lb          $t6, 0x74($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X74);
    // 0x800140C8: lb          $t9, 0x75($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X75);
    // 0x800140CC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140D0: lbu         $v1, 0x73($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X73);
    // 0x800140D4: lbu         $s5, 0x72($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X72);
    // 0x800140D8: or          $ra, $a0, $zero
    ctx->r31 = ctx->r4 | 0;
    // 0x800140DC: mflo        $s0
    ctx->r16 = lo;
    // 0x800140E0: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800140E4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800140E8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140EC: mflo        $s1
    ctx->r17 = lo;
    // 0x800140F0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x800140F4: beq         $v1, $a2, L_80014110
    if (ctx->r3 == ctx->r6) {
        // 0x800140F8: sra         $s1, $t6, 16
        ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80014110;
    }
    // 0x800140F8: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800140FC: lb          $t8, 0x55($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X55);
    // 0x80014100: nop

    // 0x80014104: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80014108: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001410C: nop
    
            goto L_80014288;
    }
    // 0x8001410C: nop

L_80014110:
    // 0x80014110: bne         $v1, $a2, L_80014124
    if (ctx->r3 != ctx->r6) {
        // 0x80014114: addiu       $fp, $v1, 0x1
        ctx->r30 = ADD32(ctx->r3, 0X1);
            goto L_80014124;
    }
    // 0x80014114: addiu       $fp, $v1, 0x1
    ctx->r30 = ADD32(ctx->r3, 0X1);
    // 0x80014118: lb          $fp, 0x55($v0)
    ctx->r30 = MEM_B(ctx->r2, 0X55);
    // 0x8001411C: b           L_80014124
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80014124;
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014124:
    // 0x80014124: slt         $at, $v1, $fp
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80014128: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001412C: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_80014288;
    }
    // 0x8001412C: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x80014130: sll         $s6, $v1, 2
    ctx->r22 = S32(ctx->r3 << 2);
L_80014134:
    // 0x80014134: lw          $t9, 0x68($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X68);
    // 0x80014138: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001413C: addu        $t6, $t9, $s6
    ctx->r14 = ADD32(ctx->r25, ctx->r22);
    // 0x80014140: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014144: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x80014148: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001414C: nop

    // 0x80014150: lh          $t7, 0x22($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X22);
    // 0x80014154: nop

    // 0x80014158: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001415C: beq         $at, $zero, L_80014280
    if (ctx->r1 == 0) {
        // 0x80014160: nop
    
            goto L_80014280;
    }
    // 0x80014160: nop

    // 0x80014164: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80014168: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001416C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80014170: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014174: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80014178: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001417C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80014180: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80014184: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80014188: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001418C: blez        $v1, L_80014280
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80014190: sra         $s4, $t7, 16
        ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80014280;
    }
    // 0x80014190: sra         $s4, $t7, 16
    ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80014194: lw          $t1, 0x38($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X38);
    // 0x80014198: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001419C:
    // 0x8001419C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x800141A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800141A4: bne         $s5, $t9, L_80014274
    if (ctx->r21 != ctx->r25) {
        // 0x800141A8: slt         $at, $s2, $v1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014274;
    }
    // 0x800141A8: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800141AC: lh          $a1, 0x4($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X4);
    // 0x800141B0: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x800141B4: addiu       $t2, $s3, -0x1
    ctx->r10 = ADD32(ctx->r19, -0X1);
    // 0x800141B8: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800141BC: beq         $at, $zero, L_80014270
    if (ctx->r1 == 0) {
        // 0x800141C0: sll         $t7, $t2, 16
        ctx->r15 = S32(ctx->r10 << 16);
            goto L_80014270;
    }
    // 0x800141C0: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x800141C4: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x800141C8: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800141CC: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800141D0: sra         $t2, $t7, 16
    ctx->r10 = S32(SIGNED(ctx->r15) >> 16);
L_800141D4:
    // 0x800141D4: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x800141D8: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x800141DC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800141E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800141E4: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x800141E8: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800141EC: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800141F0: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800141F4: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800141F8: subu        $t1, $t9, $v1
    ctx->r9 = SUB32(ctx->r25, ctx->r3);
    // 0x800141FC: subu        $a3, $t7, $v1
    ctx->r7 = SUB32(ctx->r15, ctx->r3);
    // 0x80014200: addu        $t9, $v1, $s0
    ctx->r25 = ADD32(ctx->r3, ctx->r16);
    // 0x80014204: addu        $t7, $a0, $s1
    ctx->r15 = ADD32(ctx->r4, ctx->r17);
    // 0x80014208: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    // 0x8001420C: subu        $t0, $t6, $a0
    ctx->r8 = SUB32(ctx->r14, ctx->r4);
    // 0x80014210: and         $t6, $t9, $t2
    ctx->r14 = ctx->r25 & ctx->r10;
    // 0x80014214: and         $t8, $t7, $t3
    ctx->r24 = ctx->r15 & ctx->r11;
    // 0x80014218: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8001421C: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80014220: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80014224: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x80014228: addu        $t9, $v1, $t1
    ctx->r25 = ADD32(ctx->r3, ctx->r9);
    // 0x8001422C: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80014230: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x80014234: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x80014238: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8001423C: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x80014240: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x80014244: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x80014248: lw          $t9, 0x38($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X38);
    // 0x8001424C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014250: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80014254: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x80014258: nop

    // 0x8001425C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80014260: bne         $at, $zero, L_800141D4
    if (ctx->r1 != 0) {
        // 0x80014264: nop
    
            goto L_800141D4;
    }
    // 0x80014264: nop

    // 0x80014268: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001426C: nop

L_80014270:
    // 0x80014270: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
L_80014274:
    // 0x80014274: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80014278: bne         $at, $zero, L_8001419C
    if (ctx->r1 != 0) {
        // 0x8001427C: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_8001419C;
    }
    // 0x8001427C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_80014280:
    // 0x80014280: bne         $s7, $fp, L_80014134
    if (ctx->r23 != ctx->r30) {
        // 0x80014284: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80014134;
    }
    // 0x80014284: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80014288:
    // 0x80014288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001428C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80014290: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80014294: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80014298: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001429C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800142A0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800142A4: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800142A8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800142AC: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800142B0: jr          $ra
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_tick_anims(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800142B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800142BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800142C0: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x800142C4: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800142C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800142CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800142D0: beq         $at, $zero, L_800143A0
    if (ctx->r1 == 0) {
        // 0x800142D4: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_800143A0;
    }
    // 0x800142D4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800142D8: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
L_800142DC:
    // 0x800142DC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800142E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800142E4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800142E8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800142EC: nop

    // 0x800142F0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800142F4: nop

    // 0x800142F8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800142FC: bne         $t9, $zero, L_80014398
    if (ctx->r25 != 0) {
        // 0x80014300: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014300: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014304: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x80014308: nop

    // 0x8001430C: lb          $t3, 0x53($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X53);
    // 0x80014310: nop

    // 0x80014314: bne         $t3, $zero, L_80014398
    if (ctx->r11 != 0) {
        // 0x80014318: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014318: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001431C: lb          $t0, 0x55($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X55);
    // 0x80014320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014324: blez        $t0, L_80014394
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80014328: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80014394;
    }
    // 0x80014328: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001432C:
    // 0x8001432C: lw          $t4, 0x68($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X68);
    // 0x80014330: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80014334: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80014338: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x8001433C: nop

    // 0x80014340: beq         $v1, $zero, L_80014380
    if (ctx->r3 == 0) {
        // 0x80014344: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80014380;
    }
    // 0x80014344: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80014348: lb          $t1, 0x20($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X20);
    // 0x8001434C: nop

    // 0x80014350: blez        $t1, L_8001437C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014354: andi        $t6, $t1, 0x3
        ctx->r14 = ctx->r9 & 0X3;
            goto L_8001437C;
    }
    // 0x80014354: andi        $t6, $t1, 0x3
    ctx->r14 = ctx->r9 & 0X3;
    // 0x80014358: sb          $t6, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r14;
    // 0x8001435C: lb          $t7, 0x20($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X20);
    // 0x80014360: nop

    // 0x80014364: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80014368: sb          $t8, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r24;
    // 0x8001436C: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x80014370: nop

    // 0x80014374: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x80014378: nop

L_8001437C:
    // 0x8001437C: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
L_80014380:
    // 0x80014380: bne         $at, $zero, L_8001432C
    if (ctx->r1 != 0) {
        // 0x80014384: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001432C;
    }
    // 0x80014384: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80014388: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001438C: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80014390: nop

L_80014394:
    // 0x80014394: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80014398:
    // 0x80014398: bne         $at, $zero, L_800142DC
    if (ctx->r1 != 0) {
        // 0x8001439C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800142DC;
    }
    // 0x8001439C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800143A0:
    // 0x800143A0: jr          $ra
    // 0x800143A4: nop

    return;
    // 0x800143A4: nop

;}
RECOMP_FUNC void render_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800143A8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800143AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800143B0: lw          $t6, -0x4BF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF4);
    // 0x800143B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800143B8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800143BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800143C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800143C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800143C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800143CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800143D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800143D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800143D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800143DC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800143E0: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800143E4: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x800143E8: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800143EC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800143F0: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800143F4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800143F8: beq         $at, $zero, L_800147C4
    if (ctx->r1 == 0) {
        // 0x800143FC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800147C4;
    }
    // 0x800143FC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80014400: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80014404: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80014408: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001440C: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80014410: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80014414: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
L_80014418:
    // 0x80014418: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8001441C: andi        $t9, $t5, 0x4
    ctx->r25 = ctx->r13 & 0X4;
    // 0x80014420: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x80014424: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80014428: nop

    // 0x8001442C: andi        $t8, $t0, 0x4
    ctx->r24 = ctx->r8 & 0X4;
    // 0x80014430: beq         $t8, $zero, L_80014440
    if (ctx->r24 == 0) {
        // 0x80014434: andi        $v1, $t0, 0x100
        ctx->r3 = ctx->r8 & 0X100;
            goto L_80014440;
    }
    // 0x80014434: andi        $v1, $t0, 0x100
    ctx->r3 = ctx->r8 & 0X100;
    // 0x80014438: beq         $t9, $zero, L_800147AC
    if (ctx->r25 == 0) {
        // 0x8001443C: nop
    
            goto L_800147AC;
    }
    // 0x8001443C: nop

L_80014440:
    // 0x80014440: bne         $v1, $zero, L_800147A0
    if (ctx->r3 != 0) {
        // 0x80014444: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800147A0;
    }
    // 0x80014444: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014448: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8001444C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80014450: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80014454: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80014458: andi        $t1, $t5, 0x4
    ctx->r9 = ctx->r13 & 0X4;
    // 0x8001445C: beq         $t7, $zero, L_80014470
    if (ctx->r15 == 0) {
        // 0x80014460: subu        $s1, $t6, $a0
        ctx->r17 = SUB32(ctx->r14, ctx->r4);
            goto L_80014470;
    }
    // 0x80014460: subu        $s1, $t6, $a0
    ctx->r17 = SUB32(ctx->r14, ctx->r4);
    // 0x80014464: lb          $s0, 0x1($v0)
    ctx->r16 = MEM_B(ctx->r2, 0X1);
    // 0x80014468: b           L_80014478
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
        goto L_80014478;
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014470:
    // 0x80014470: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80014474: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014478:
    // 0x80014478: lw          $t9, 0x8($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X8);
    // 0x8001447C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80014480: subu        $s5, $t8, $a1
    ctx->r21 = SUB32(ctx->r24, ctx->r5);
    // 0x80014484: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80014488: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8001448C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80014490: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014494: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80014498: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x8001449C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800144A0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800144A4: bne         $v1, $at, L_800144BC
    if (ctx->r3 != ctx->r1) {
        // 0x800144A8: addu        $s3, $t9, $t6
        ctx->r19 = ADD32(ctx->r25, ctx->r14);
            goto L_800144BC;
    }
    // 0x800144A8: addu        $s3, $t9, $t6
    ctx->r19 = ADD32(ctx->r25, ctx->r14);
    // 0x800144AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800144B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800144B4: b           L_800144DC
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
        goto L_800144DC;
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800144BC:
    // 0x800144BC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800144C0: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x800144C4: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800144C8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800144CC: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x800144D0: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
    // 0x800144D4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800144D8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800144DC:
    // 0x800144DC: beq         $t1, $zero, L_800144FC
    if (ctx->r9 == 0) {
        // 0x800144E0: ori         $a2, $t0, 0x8
        ctx->r6 = ctx->r8 | 0X8;
            goto L_800144FC;
    }
    // 0x800144E0: ori         $a2, $t0, 0x8
    ctx->r6 = ctx->r8 | 0X8;
    // 0x800144E4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800144E8: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800144EC: and         $t8, $t0, $t7
    ctx->r24 = ctx->r8 & ctx->r15;
    // 0x800144F0: bne         $t8, $zero, L_800144FC
    if (ctx->r24 != 0) {
        // 0x800144F4: ori         $t9, $a2, 0x4
        ctx->r25 = ctx->r6 | 0X4;
            goto L_800144FC;
    }
    // 0x800144F4: ori         $t9, $a2, 0x4
    ctx->r25 = ctx->r6 | 0X4;
    // 0x800144F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_800144FC:
    // 0x800144FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80014500: lw          $t6, -0x3370($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3370);
    // 0x80014504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80014508: bne         $t6, $zero, L_80014544
    if (ctx->r14 != 0) {
        // 0x8001450C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80014544;
    }
    // 0x8001450C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80014510: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014514: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80014518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001451C: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x80014520: jal         0x8007B938
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    material_set(rdram, ctx);
        goto after_0;
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_0:
    // 0x80014528: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001452C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014530: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80014534: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014538: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x8001453C: b           L_800145B0
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
        goto L_800145B0;
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
L_80014544:
    // 0x80014544: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014548: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x8001454C: jal         0x8007B8BC
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x80014554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014558: addiu       $a2, $a2, -0x4BF4
    ctx->r6 = ADD32(ctx->r6, -0X4BF4);
    // 0x8001455C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80014560: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80014564: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014568: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8001456C: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x80014570: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80014574: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80014578: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001457C: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80014580: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80014584: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80014588: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8001458C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014590: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x80014594: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80014598: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001459C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800145A0: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800145A4: addu        $t6, $t7, $s4
    ctx->r14 = ADD32(ctx->r15, ctx->r20);
    // 0x800145A8: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
    // 0x800145AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800145B0:
    // 0x800145B0: bne         $s0, $s1, L_80014608
    if (ctx->r16 != ctx->r17) {
        // 0x800145B4: lui         $at, 0x500
        ctx->r1 = S32(0X500 << 16);
            goto L_80014608;
    }
    // 0x800145B4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800145B8: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800145BC: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800145C0: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800145C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800145C8: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x800145CC: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800145D0: andi        $t8, $v0, 0x6
    ctx->r24 = ctx->r2 & 0X6;
    // 0x800145D4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800145D8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800145DC: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800145E0: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x800145E4: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x800145E8: or          $t8, $t6, $fp
    ctx->r24 = ctx->r14 | ctx->r30;
    // 0x800145EC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800145F0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800145F4: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800145F8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800145FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014600: b           L_80014754
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80014754;
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80014608:
    // 0x80014608: blez        $s0, L_800146DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8001460C: addiu       $t8, $zero, 0x80
        ctx->r24 = ADD32(0, 0X80);
            goto L_800146DC;
    }
    // 0x8001460C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80014610: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80014614: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x80014618: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8001461C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80014620: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014624: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80014628: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001462C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80014630: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80014634: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80014638: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8001463C: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x80014640: or          $t9, $t6, $fp
    ctx->r25 = ctx->r14 | ctx->r30;
    // 0x80014644: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80014648: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8001464C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80014650: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80014654: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80014658: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8001465C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80014660: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80014664: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014668: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001466C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80014670: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80014674: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80014678: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8001467C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80014680: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80014684: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80014688: subu        $v1, $s1, $s0
    ctx->r3 = SUB32(ctx->r17, ctx->r16);
    // 0x8001468C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80014690: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014694: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80014698: addu        $a3, $t7, $s4
    ctx->r7 = ADD32(ctx->r15, ctx->r20);
    // 0x8001469C: andi        $t9, $a3, 0x6
    ctx->r25 = ctx->r7 & 0X6;
    // 0x800146A0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800146A4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800146A8: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x800146AC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800146B0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800146B4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800146B8: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800146BC: or          $t7, $t9, $fp
    ctx->r15 = ctx->r25 | ctx->r30;
    // 0x800146C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800146C4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800146C8: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800146CC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800146D0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800146D4: b           L_8001473C
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
        goto L_8001473C;
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
L_800146DC:
    // 0x800146DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800146E0: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800146E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800146E8: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800146EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800146F0: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800146F4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800146F8: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800146FC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80014700: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014704: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80014708: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001470C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80014710: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80014714: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80014718: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x8001471C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80014720: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x80014724: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80014728: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8001472C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80014730: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80014734: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80014738: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8001473C:
    // 0x8001473C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80014740: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80014744: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80014748: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001474C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80014750: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_80014754:
    // 0x80014754: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80014758: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001475C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80014760: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80014764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014768: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x8001476C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80014770: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80014774: sll         $t8, $s5, 4
    ctx->r24 = S32(ctx->r21 << 4);
    // 0x80014778: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8001477C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80014780: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80014784: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80014788: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8001478C: nop

    // 0x80014790: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x80014794: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80014798: lh          $t1, 0x28($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X28);
    // 0x8001479C: nop

L_800147A0:
    // 0x800147A0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800147A4: b           L_800147B0
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
        goto L_800147B0;
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
L_800147AC:
    // 0x800147AC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_800147B0:
    // 0x800147B0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147B4: beq         $at, $zero, L_800147C8
    if (ctx->r1 == 0) {
        // 0x800147B8: slt         $at, $t2, $t1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800147C8;
    }
    // 0x800147B8: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147BC: beq         $ra, $zero, L_80014418
    if (ctx->r31 == 0) {
        // 0x800147C0: nop
    
            goto L_80014418;
    }
    // 0x800147C0: nop

L_800147C4:
    // 0x800147C4: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
L_800147C8:
    // 0x800147C8: bne         $at, $zero, L_800147D8
    if (ctx->r1 != 0) {
        // 0x800147CC: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_800147D8;
    }
    // 0x800147CC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800147D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800147D4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_800147D8:
    // 0x800147D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800147DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800147E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800147E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800147E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800147EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800147F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800147F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800147F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800147FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80014800: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80014804: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80014808: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8001480C: jr          $ra
    // 0x80014810: sw          $t6, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r14;
    return;
    // 0x80014810: sw          $t6, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void get_first_active_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014814: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014818: addiu       $a2, $a2, -0x4C24
    ctx->r6 = ADD32(ctx->r6, -0X4C24);
    // 0x8001481C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80014820: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014824: addiu       $t2, $t2, -0x4C04
    ctx->r10 = ADD32(ctx->r10, -0X4C04);
    // 0x80014828: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001482C: lh          $v1, 0x0($t2)
    ctx->r3 = MEM_H(ctx->r10, 0X0);
    // 0x80014830: nop

    // 0x80014834: beq         $v1, $zero, L_80014844
    if (ctx->r3 == 0) {
        // 0x80014838: nop
    
            goto L_80014844;
    }
    // 0x80014838: nop

    // 0x8001483C: jr          $ra
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80014844:
    // 0x80014844: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014848: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001484C: lw          $v1, -0x4C20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C20);
    // 0x80014850: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014854: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001485C: bne         $at, $zero, L_800149B0
    if (ctx->r1 != 0) {
        // 0x80014860: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800149B0;
    }
    // 0x80014860: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80014864: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80014868: addiu       $t3, $t3, -0x4C28
    ctx->r11 = ADD32(ctx->r11, -0X4C28);
    // 0x8001486C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_80014870:
    // 0x80014870: bne         $at, $zero, L_800148EC
    if (ctx->r1 != 0) {
        // 0x80014874: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800148EC;
    }
    // 0x80014874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014878: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001487C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80014880: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
L_80014884:
    // 0x80014884: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014888: nop

    // 0x8001488C: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x80014890: nop

    // 0x80014894: andi        $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 & 0X8000;
    // 0x80014898: bne         $t4, $zero, L_800148D0
    if (ctx->r12 != 0) {
        // 0x8001489C: nop
    
            goto L_800148D0;
    }
    // 0x8001489C: nop

    // 0x800148A0: lw          $t5, 0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X40);
    // 0x800148A4: nop

    // 0x800148A8: lhu         $t6, 0x30($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X30);
    // 0x800148AC: nop

    // 0x800148B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800148B4: beq         $t7, $zero, L_800148C8
    if (ctx->r15 == 0) {
        // 0x800148B8: nop
    
            goto L_800148C8;
    }
    // 0x800148B8: nop

    // 0x800148BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148C0: b           L_800148D8
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
        goto L_800148D8;
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148C8:
    // 0x800148C8: b           L_800148D8
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800148D8;
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800148D0:
    // 0x800148D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148D4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148D8:
    // 0x800148D8: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800148DC: bne         $at, $zero, L_800148F0
    if (ctx->r1 != 0) {
        // 0x800148E0: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800148F0;
    }
    // 0x800148E0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800148E4: beq         $a2, $zero, L_80014884
    if (ctx->r6 == 0) {
        // 0x800148E8: nop
    
            goto L_80014884;
    }
    // 0x800148E8: nop

L_800148EC:
    // 0x800148EC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_800148F0:
    // 0x800148F0: bne         $at, $zero, L_80014968
    if (ctx->r1 != 0) {
        // 0x800148F4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80014968;
    }
    // 0x800148F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800148F8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800148FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80014900: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
L_80014904:
    // 0x80014904: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014908: nop

    // 0x8001490C: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x80014910: nop

    // 0x80014914: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80014918: beq         $t5, $zero, L_80014928
    if (ctx->r13 == 0) {
        // 0x8001491C: nop
    
            goto L_80014928;
    }
    // 0x8001491C: nop

    // 0x80014920: b           L_80014954
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80014954;
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014928:
    // 0x80014928: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x8001492C: nop

    // 0x80014930: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x80014934: nop

    // 0x80014938: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8001493C: bne         $t8, $zero, L_80014950
    if (ctx->r24 != 0) {
        // 0x80014940: nop
    
            goto L_80014950;
    }
    // 0x80014940: nop

    // 0x80014944: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014948: b           L_80014954
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
        goto L_80014954;
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80014950:
    // 0x80014950: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014954:
    // 0x80014954: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014958: bne         $at, $zero, L_8001496C
    if (ctx->r1 != 0) {
        // 0x8001495C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001496C;
    }
    // 0x8001495C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014960: beq         $a2, $zero, L_80014904
    if (ctx->r6 == 0) {
        // 0x80014964: nop
    
            goto L_80014904;
    }
    // 0x80014964: nop

L_80014968:
    // 0x80014968: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001496C:
    // 0x8001496C: beq         $at, $zero, L_800149A4
    if (ctx->r1 == 0) {
        // 0x80014970: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800149A4;
    }
    // 0x80014970: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80014974: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80014978: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8001497C: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x80014980: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80014984: addu        $a3, $a2, $t9
    ctx->r7 = ADD32(ctx->r6, ctx->r25);
    // 0x80014988: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001498C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80014990: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80014994: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80014998: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001499C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800149A0: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_800149A4:
    // 0x800149A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800149A8: beq         $at, $zero, L_80014870
    if (ctx->r1 == 0) {
        // 0x800149AC: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014870;
    }
    // 0x800149AC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800149B0:
    // 0x800149B0: sh          $v1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r3;
    // 0x800149B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800149B8: jr          $ra
    // 0x800149BC: nop

    return;
    // 0x800149BC: nop

;}
RECOMP_FUNC void func_800149C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800149C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800149C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800149C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800149CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800149D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800149D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800149D8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800149DC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800149E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800149E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800149E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800149EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800149F0: lbu         $a3, 0x4($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X4);
    // 0x800149F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800149F8: jal         0x80014B50
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80014B50(rdram, ctx);
        goto after_0;
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80014A00: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80014A04: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80014A08: lbu         $a3, 0x4($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X4);
    // 0x80014A0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014A10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80014A14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80014A18: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80014A1C: jal         0x80014B50
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80014B50(rdram, ctx);
        goto after_1;
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_1:
    // 0x80014A24: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80014A2C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014A30: beq         $at, $zero, L_80014B28
    if (ctx->r1 == 0) {
        // 0x80014A34: subu        $a0, $t3, $v0
        ctx->r4 = SUB32(ctx->r11, ctx->r2);
            goto L_80014B28;
    }
    // 0x80014A34: subu        $a0, $t3, $v0
    ctx->r4 = SUB32(ctx->r11, ctx->r2);
    // 0x80014A38: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x80014A3C: beq         $t9, $zero, L_80014A80
    if (ctx->r25 == 0) {
        // 0x80014A40: addu        $a2, $t9, $v0
        ctx->r6 = ADD32(ctx->r25, ctx->r2);
            goto L_80014A80;
    }
    // 0x80014A40: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80014A44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A48: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A4C: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80014A50: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_80014A54:
    // 0x80014A54: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014A58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014A5C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014A60: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80014A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80014A68: lb          $t7, 0x38($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X38);
    // 0x80014A6C: nop

    // 0x80014A70: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014A74: bne         $a2, $a1, L_80014A54
    if (ctx->r6 != ctx->r5) {
        // 0x80014A78: sb          $t6, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r14;
            goto L_80014A54;
    }
    // 0x80014A78: sb          $t6, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r14;
    // 0x80014A7C: beq         $a1, $t3, L_80014B28
    if (ctx->r5 == ctx->r11) {
        // 0x80014A80: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80014B28;
    }
L_80014A80:
    // 0x80014A80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A84: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A88: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80014A8C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80014A90: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
L_80014A94:
    // 0x80014A94: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014A98: nop

    // 0x80014A9C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014AA0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80014AA4: nop

    // 0x80014AA8: lb          $t4, 0x38($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X38);
    // 0x80014AAC: nop

    // 0x80014AB0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014AB4: sb          $t5, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r13;
    // 0x80014AB8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80014ABC: nop

    // 0x80014AC0: addu        $t6, $t7, $v1
    ctx->r14 = ADD32(ctx->r15, ctx->r3);
    // 0x80014AC4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80014AC8: nop

    // 0x80014ACC: lb          $t8, 0x38($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X38);
    // 0x80014AD0: nop

    // 0x80014AD4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80014AD8: sb          $t9, 0x38($a1)
    MEM_B(0X38, ctx->r5) = ctx->r25;
    // 0x80014ADC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014AE0: nop

    // 0x80014AE4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014AE8: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x80014AEC: nop

    // 0x80014AF0: lb          $t7, 0x38($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X38);
    // 0x80014AF4: nop

    // 0x80014AF8: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014AFC: sb          $t6, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r14;
    // 0x80014B00: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014B04: nop

    // 0x80014B08: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014B0C: lw          $a3, 0xC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XC);
    // 0x80014B10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80014B14: lb          $t4, 0x38($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X38);
    // 0x80014B18: nop

    // 0x80014B1C: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014B20: bne         $v1, $t2, L_80014A94
    if (ctx->r3 != ctx->r10) {
        // 0x80014B24: sb          $t5, 0x38($a3)
        MEM_B(0X38, ctx->r7) = ctx->r13;
            goto L_80014A94;
    }
    // 0x80014B24: sb          $t5, 0x38($a3)
    MEM_B(0X38, ctx->r7) = ctx->r13;
L_80014B28:
    // 0x80014B28: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80014B2C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80014B30: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80014B34: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80014B38: nop

    // 0x80014B3C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80014B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80014B48: jr          $ra
    // 0x80014B4C: nop

    return;
    // 0x80014B4C: nop

;}
RECOMP_FUNC void func_80014B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80014B54: sltiu       $at, $a3, 0xB
    ctx->r1 = ctx->r7 < 0XB ? 1 : 0;
    // 0x80014B58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80014B5C: beq         $at, $zero, L_80015340
    if (ctx->r1 == 0) {
        // 0x80014B60: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80015340;
    }
    // 0x80014B60: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80014B64: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80014B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014B6C: addu        $at, $at, $t6
    gpr jr_addend_80014B78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80014B70: lw          $t6, 0x5B18($at)
    ctx->r14 = ADD32(ctx->r1, 0X5B18);
    // 0x80014B74: nop

    // 0x80014B78: jr          $t6
    // 0x80014B7C: nop

    switch (jr_addend_80014B78 >> 2) {
        case 0: goto L_80014B80; break;
        case 1: goto L_80014CCC; break;
        case 2: goto L_80014E18; break;
        case 3: goto L_80015340; break;
        case 4: goto L_80015340; break;
        case 5: goto L_80015340; break;
        case 6: goto L_80015340; break;
        case 7: goto L_80015340; break;
        case 8: goto L_80014F64; break;
        case 9: goto L_800150B0; break;
        case 10: goto L_800151FC; break;
        default: switch_error(__func__, 0x80014B78, 0x800E5B18);
    }
    // 0x80014B7C: nop

L_80014B80:
    // 0x80014B80: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014B84: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014B88: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014B88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014B8C: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014B90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014B94:
    // 0x80014B94: bne         $at, $zero, L_80014C0C
    if (ctx->r1 != 0) {
        // 0x80014B98: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014B98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014B9C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014BA0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014BA4: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80014BA8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BAC: nop

    // 0x80014BB0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BB4: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BB8: nop

    // 0x80014BBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014BC0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014BC4: nop

    // 0x80014BC8: bc1f        L_80014C0C
    if (!c1cs) {
        // 0x80014BCC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014BCC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014BD0:
    // 0x80014BD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014BD4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014BD8: bne         $at, $zero, L_80014C08
    if (ctx->r1 != 0) {
        // 0x80014BDC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014C08;
    }
    // 0x80014BDC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014BE0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BE4: nop

    // 0x80014BE8: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BEC: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BF0: nop

    // 0x80014BF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014BF8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014BFC: nop

    // 0x80014C00: bc1t        L_80014BD0
    if (c1cs) {
        // 0x80014C04: nop
    
            goto L_80014BD0;
    }
    // 0x80014C04: nop

L_80014C08:
    // 0x80014C08: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014C0C:
    // 0x80014C0C: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C10: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_80014C80;
    }
    // 0x80014C10: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80014C14: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014C18: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80014C1C: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x80014C20: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C24: nop

    // 0x80014C28: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C2C: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C30: nop

    // 0x80014C34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014C38: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014C3C: nop

    // 0x80014C40: bc1f        L_80014C84
    if (!c1cs) {
        // 0x80014C44: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014C84;
    }
    // 0x80014C44: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C48:
    // 0x80014C48: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014C4C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014C50: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C54: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014C80;
    }
    // 0x80014C54: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014C58: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C5C: nop

    // 0x80014C60: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C64: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C68: nop

    // 0x80014C6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014C70: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014C74: nop

    // 0x80014C78: bc1t        L_80014C48
    if (c1cs) {
        // 0x80014C7C: nop
    
            goto L_80014C48;
    }
    // 0x80014C7C: nop

L_80014C80:
    // 0x80014C80: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C84:
    // 0x80014C84: beq         $at, $zero, L_80014CB8
    if (ctx->r1 == 0) {
        // 0x80014C88: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014CB8;
    }
    // 0x80014C88: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014C8C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014C90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014C94: addu        $t5, $a2, $t0
    ctx->r13 = ADD32(ctx->r6, ctx->r8);
    // 0x80014C98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80014C9C: addu        $a3, $a2, $t4
    ctx->r7 = ADD32(ctx->r6, ctx->r12);
    // 0x80014CA0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014CA4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80014CA8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014CAC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014CB0: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80014CB4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80014CB8:
    // 0x80014CB8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CBC: beq         $at, $zero, L_80014B94
    if (ctx->r1 == 0) {
        // 0x80014CC0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014B94;
    }
    // 0x80014CC0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CC4: jr          $ra
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014CCC:
    // 0x80014CCC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CD0: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014CD4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014CD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014CD8: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014CDC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014CE0:
    // 0x80014CE0: bne         $at, $zero, L_80014D58
    if (ctx->r1 != 0) {
        // 0x80014CE4: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014CE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014CE8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014CEC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014CF0: addu        $a3, $t9, $t3
    ctx->r7 = ADD32(ctx->r25, ctx->r11);
    // 0x80014CF4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014CF8: nop

    // 0x80014CFC: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D00: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D04: nop

    // 0x80014D08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D0C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014D10: nop

    // 0x80014D14: bc1f        L_80014D58
    if (!c1cs) {
        // 0x80014D18: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014D18: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D1C:
    // 0x80014D1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014D20: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014D24: bne         $at, $zero, L_80014D54
    if (ctx->r1 != 0) {
        // 0x80014D28: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014D54;
    }
    // 0x80014D28: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014D2C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014D30: nop

    // 0x80014D34: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D38: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D3C: nop

    // 0x80014D40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014D44: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014D48: nop

    // 0x80014D4C: bc1t        L_80014D1C
    if (c1cs) {
        // 0x80014D50: nop
    
            goto L_80014D1C;
    }
    // 0x80014D50: nop

L_80014D54:
    // 0x80014D54: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D58:
    // 0x80014D58: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014D5C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80014DCC;
    }
    // 0x80014D5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014D60: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014D64: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80014D68: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x80014D6C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014D70: nop

    // 0x80014D74: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014D78: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014D7C: nop

    // 0x80014D80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D84: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014D88: nop

    // 0x80014D8C: bc1f        L_80014DD0
    if (!c1cs) {
        // 0x80014D90: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014DD0;
    }
    // 0x80014D90: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D94:
    // 0x80014D94: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014D98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014D9C: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014DA0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014DCC;
    }
    // 0x80014DA0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014DA4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014DA8: nop

    // 0x80014DAC: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014DB0: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014DB4: nop

    // 0x80014DB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014DBC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014DC0: nop

    // 0x80014DC4: bc1t        L_80014D94
    if (c1cs) {
        // 0x80014DC8: nop
    
            goto L_80014D94;
    }
    // 0x80014DC8: nop

L_80014DCC:
    // 0x80014DCC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014DD0:
    // 0x80014DD0: beq         $at, $zero, L_80014E04
    if (ctx->r1 == 0) {
        // 0x80014DD4: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014E04;
    }
    // 0x80014DD4: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014DD8: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014DDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014DE0: addu        $t7, $a2, $t0
    ctx->r15 = ADD32(ctx->r6, ctx->r8);
    // 0x80014DE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014DE8: addu        $a3, $a2, $t6
    ctx->r7 = ADD32(ctx->r6, ctx->r14);
    // 0x80014DEC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014DF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80014DF4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014DF8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014DFC: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80014E00: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
L_80014E04:
    // 0x80014E04: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E08: beq         $at, $zero, L_80014CE0
    if (ctx->r1 == 0) {
        // 0x80014E0C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014CE0;
    }
    // 0x80014E0C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E10: jr          $ra
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014E18:
    // 0x80014E18: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E1C: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014E20: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014E20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014E24: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014E28: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014E2C:
    // 0x80014E2C: bne         $at, $zero, L_80014EA4
    if (ctx->r1 != 0) {
        // 0x80014E30: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E30: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014E34: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014E38: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80014E3C: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x80014E40: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E44: nop

    // 0x80014E48: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E4C: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E50: nop

    // 0x80014E54: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014E58: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014E5C: nop

    // 0x80014E60: bc1f        L_80014EA4
    if (!c1cs) {
        // 0x80014E64: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E64: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014E68:
    // 0x80014E68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014E6C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E70: bne         $at, $zero, L_80014EA0
    if (ctx->r1 != 0) {
        // 0x80014E74: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014EA0;
    }
    // 0x80014E74: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014E78: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E7C: nop

    // 0x80014E80: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E84: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E88: nop

    // 0x80014E8C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014E90: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014E94: nop

    // 0x80014E98: bc1t        L_80014E68
    if (c1cs) {
        // 0x80014E9C: nop
    
            goto L_80014E68;
    }
    // 0x80014E9C: nop

L_80014EA0:
    // 0x80014EA0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014EA4:
    // 0x80014EA4: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EA8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_80014F18;
    }
    // 0x80014EA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014EAC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014EB0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80014EB4: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80014EB8: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EBC: nop

    // 0x80014EC0: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EC4: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014EC8: nop

    // 0x80014ECC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014ED0: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014ED4: nop

    // 0x80014ED8: bc1f        L_80014F1C
    if (!c1cs) {
        // 0x80014EDC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014F1C;
    }
    // 0x80014EDC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014EE0:
    // 0x80014EE0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014EE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014EE8: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EEC: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014F18;
    }
    // 0x80014EEC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014EF0: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EF4: nop

    // 0x80014EF8: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EFC: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014F00: nop

    // 0x80014F04: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014F08: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014F0C: nop

    // 0x80014F10: bc1t        L_80014EE0
    if (c1cs) {
        // 0x80014F14: nop
    
            goto L_80014EE0;
    }
    // 0x80014F14: nop

L_80014F18:
    // 0x80014F18: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014F1C:
    // 0x80014F1C: beq         $at, $zero, L_80014F50
    if (ctx->r1 == 0) {
        // 0x80014F20: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014F50;
    }
    // 0x80014F20: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014F24: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014F28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014F2C: addu        $t9, $a2, $t0
    ctx->r25 = ADD32(ctx->r6, ctx->r8);
    // 0x80014F30: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80014F34: addu        $a3, $a2, $t8
    ctx->r7 = ADD32(ctx->r6, ctx->r24);
    // 0x80014F38: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014F3C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80014F40: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014F44: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014F48: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014F4C: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
L_80014F50:
    // 0x80014F50: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F54: beq         $at, $zero, L_80014E2C
    if (ctx->r1 == 0) {
        // 0x80014F58: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014E2C;
    }
    // 0x80014F58: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F5C: jr          $ra
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014F64:
    // 0x80014F64: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F68: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014F6C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014F6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014F70: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x80014F74: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014F78:
    // 0x80014F78: bne         $at, $zero, L_80014FF0
    if (ctx->r1 != 0) {
        // 0x80014F7C: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014F7C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014F80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014F84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80014F88: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80014F8C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014F90: nop

    // 0x80014F94: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014F98: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014F9C: nop

    // 0x80014FA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80014FA4: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014FA8: nop

    // 0x80014FAC: bc1f        L_80014FF0
    if (!c1cs) {
        // 0x80014FB0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014FB0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FB4:
    // 0x80014FB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014FB8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014FBC: bne         $at, $zero, L_80014FEC
    if (ctx->r1 != 0) {
        // 0x80014FC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014FEC;
    }
    // 0x80014FC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014FC4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014FC8: nop

    // 0x80014FCC: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014FD0: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014FD4: nop

    // 0x80014FD8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80014FDC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014FE0: nop

    // 0x80014FE4: bc1t        L_80014FB4
    if (c1cs) {
        // 0x80014FE8: nop
    
            goto L_80014FB4;
    }
    // 0x80014FE8: nop

L_80014FEC:
    // 0x80014FEC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FF0:
    // 0x80014FF0: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80014FF4: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_80015064;
    }
    // 0x80014FF4: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014FF8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80014FFC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80015000: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80015004: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015008: nop

    // 0x8001500C: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015010: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015014: nop

    // 0x80015018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001501C: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80015020: nop

    // 0x80015024: bc1f        L_80015068
    if (!c1cs) {
        // 0x80015028: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015068;
    }
    // 0x80015028: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8001502C:
    // 0x8001502C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015030: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015034: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80015038: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80015064;
    }
    // 0x80015038: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8001503C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015040: nop

    // 0x80015044: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015048: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001504C: nop

    // 0x80015050: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015054: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80015058: nop

    // 0x8001505C: bc1t        L_8001502C
    if (c1cs) {
        // 0x80015060: nop
    
            goto L_8001502C;
    }
    // 0x80015060: nop

L_80015064:
    // 0x80015064: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015068:
    // 0x80015068: beq         $at, $zero, L_8001509C
    if (ctx->r1 == 0) {
        // 0x8001506C: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_8001509C;
    }
    // 0x8001506C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015070: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80015074: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015078: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x8001507C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80015080: addu        $a3, $a2, $t3
    ctx->r7 = ADD32(ctx->r6, ctx->r11);
    // 0x80015084: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015088: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8001508C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80015090: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015094: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80015098: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_8001509C:
    // 0x8001509C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A0: beq         $at, $zero, L_80014F78
    if (ctx->r1 == 0) {
        // 0x800150A4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014F78;
    }
    // 0x800150A4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A8: jr          $ra
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800150B0:
    // 0x800150B0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150B4: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x800150B8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x800150B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800150BC: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x800150C0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_800150C4:
    // 0x800150C4: bne         $at, $zero, L_8001513C
    if (ctx->r1 != 0) {
        // 0x800150C8: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800150CC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800150D0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800150D4: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800150D8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800150DC: nop

    // 0x800150E0: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800150E4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800150E8: nop

    // 0x800150EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800150F0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800150F4: nop

    // 0x800150F8: bc1f        L_8001513C
    if (!c1cs) {
        // 0x800150FC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150FC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015100:
    // 0x80015100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015104: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015108: bne         $at, $zero, L_80015138
    if (ctx->r1 != 0) {
        // 0x8001510C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015138;
    }
    // 0x8001510C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80015110: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015114: nop

    // 0x80015118: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8001511C: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80015120: nop

    // 0x80015124: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015128: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8001512C: nop

    // 0x80015130: bc1t        L_80015100
    if (c1cs) {
        // 0x80015134: nop
    
            goto L_80015100;
    }
    // 0x80015134: nop

L_80015138:
    // 0x80015138: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001513C:
    // 0x8001513C: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015140: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_800151B0;
    }
    // 0x80015140: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80015144: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015148: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8001514C: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80015150: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015154: nop

    // 0x80015158: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001515C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015160: nop

    // 0x80015164: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015168: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8001516C: nop

    // 0x80015170: bc1f        L_800151B4
    if (!c1cs) {
        // 0x80015174: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800151B4;
    }
    // 0x80015174: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015178:
    // 0x80015178: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001517C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015180: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015184: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800151B0;
    }
    // 0x80015184: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80015188: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8001518C: nop

    // 0x80015190: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015194: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015198: nop

    // 0x8001519C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800151A0: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800151A4: nop

    // 0x800151A8: bc1t        L_80015178
    if (c1cs) {
        // 0x800151AC: nop
    
            goto L_80015178;
    }
    // 0x800151AC: nop

L_800151B0:
    // 0x800151B0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800151B4:
    // 0x800151B4: beq         $at, $zero, L_800151E8
    if (ctx->r1 == 0) {
        // 0x800151B8: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_800151E8;
    }
    // 0x800151B8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800151BC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800151C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800151C4: addu        $t6, $a2, $t0
    ctx->r14 = ADD32(ctx->r6, ctx->r8);
    // 0x800151C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800151CC: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x800151D0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800151D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800151D8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800151DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800151E0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800151E4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
L_800151E8:
    // 0x800151E8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151EC: beq         $at, $zero, L_800150C4
    if (ctx->r1 == 0) {
        // 0x800151F0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800150C4;
    }
    // 0x800151F0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151F4: jr          $ra
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800151FC:
    // 0x800151FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015200: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80015204: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80015204: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80015208: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
    // 0x8001520C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015210:
    // 0x80015210: bne         $at, $zero, L_80015288
    if (ctx->r1 != 0) {
        // 0x80015214: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015214: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015218: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001521C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80015220: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x80015224: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015228: nop

    // 0x8001522C: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015230: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80015234: nop

    // 0x80015238: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001523C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80015240: nop

    // 0x80015244: bc1f        L_80015288
    if (!c1cs) {
        // 0x80015248: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015248: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001524C:
    // 0x8001524C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015250: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015254: bne         $at, $zero, L_80015284
    if (ctx->r1 != 0) {
        // 0x80015258: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015284;
    }
    // 0x80015258: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001525C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015260: nop

    // 0x80015264: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015268: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001526C: nop

    // 0x80015270: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015274: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80015278: nop

    // 0x8001527C: bc1t        L_8001524C
    if (c1cs) {
        // 0x80015280: nop
    
            goto L_8001524C;
    }
    // 0x80015280: nop

L_80015284:
    // 0x80015284: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015288:
    // 0x80015288: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x8001528C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800152FC;
    }
    // 0x8001528C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80015290: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80015294: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80015298: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8001529C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152A0: nop

    // 0x800152A4: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152A8: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152AC: nop

    // 0x800152B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800152B4: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800152B8: nop

    // 0x800152BC: bc1f        L_80015300
    if (!c1cs) {
        // 0x800152C0: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015300;
    }
    // 0x800152C0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800152C4:
    // 0x800152C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800152C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800152CC: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x800152D0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800152FC;
    }
    // 0x800152D0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800152D4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152D8: nop

    // 0x800152DC: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152E0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152E4: nop

    // 0x800152E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800152EC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800152F0: nop

    // 0x800152F4: bc1t        L_800152C4
    if (c1cs) {
        // 0x800152F8: nop
    
            goto L_800152C4;
    }
    // 0x800152F8: nop

L_800152FC:
    // 0x800152FC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015300:
    // 0x80015300: beq         $at, $zero, L_80015334
    if (ctx->r1 == 0) {
        // 0x80015304: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80015334;
    }
    // 0x80015304: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015308: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8001530C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015310: addu        $t8, $a2, $t0
    ctx->r24 = ADD32(ctx->r6, ctx->r8);
    // 0x80015314: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80015318: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8001531C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015320: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80015324: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015328: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001532C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80015330: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
L_80015334:
    // 0x80015334: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015338: beq         $at, $zero, L_80015210
    if (ctx->r1 == 0) {
        // 0x8001533C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80015210;
    }
    // 0x8001533C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015340:
    // 0x80015340: jr          $ra
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void sort_objects_by_dist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015348: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001534C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80015350: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80015354: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015358: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001535C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80015360: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80015364: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80015368: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8001536C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80015370: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80015374: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80015378: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001537C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015380: bne         $at, $zero, L_80015584
    if (ctx->r1 != 0) {
        // 0x80015384: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_80015584;
    }
    // 0x80015384: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80015388: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001538C: bne         $at, $zero, L_80015460
    if (ctx->r1 != 0) {
        // 0x80015390: sll         $s1, $a0, 2
        ctx->r17 = S32(ctx->r4 << 2);
            goto L_80015460;
    }
    // 0x80015390: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x80015394: lui         $at, 0xC67A
    ctx->r1 = S32(0XC67A << 16);
    // 0x80015398: sll         $s5, $a1, 2
    ctx->r21 = S32(ctx->r5 << 2);
    // 0x8001539C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800153A0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800153A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800153A8: addiu       $s2, $s2, -0x4C28
    ctx->r18 = ADD32(ctx->r18, -0X4C28);
    // 0x800153AC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800153B0:
    // 0x800153B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800153B4: nop

    // 0x800153B8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800153BC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800153C0: nop

    // 0x800153C4: beq         $a0, $zero, L_80015450
    if (ctx->r4 == 0) {
        // 0x800153C8: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80015450;
    }
    // 0x800153C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800153CC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800153D0: nop

    // 0x800153D4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800153D8: beq         $t9, $zero, L_80015400
    if (ctx->r25 == 0) {
        // 0x800153DC: nop
    
            goto L_80015400;
    }
    // 0x800153DC: nop

    // 0x800153E0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800153E4: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800153E8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800153EC: jal         0x8006A008
    // 0x800153F0: nop

    get_distance_to_camera(rdram, ctx);
        goto after_0;
    // 0x800153F0: nop

    after_0:
    // 0x800153F4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800153F8: b           L_80015454
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
        goto L_80015454;
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80015400:
    // 0x80015400: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80015404: nop

    // 0x80015408: lhu         $t1, 0x30($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X30);
    // 0x8001540C: nop

    // 0x80015410: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80015414: beq         $t2, $zero, L_80015430
    if (ctx->r10 == 0) {
        // 0x80015418: nop
    
            goto L_80015430;
    }
    // 0x80015418: nop

    // 0x8001541C: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80015420: nop

    // 0x80015424: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80015428: b           L_80015454
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_80015454;
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_80015430:
    // 0x80015430: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015434: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015438: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8001543C: jal         0x8006A008
    // 0x80015440: nop

    get_distance_to_camera(rdram, ctx);
        goto after_1;
    // 0x80015440: nop

    after_1:
    // 0x80015444: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80015448: b           L_80015454
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_80015454;
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80015450:
    // 0x80015450: swc1        $f22, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f22.u32l;
L_80015454:
    // 0x80015454: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80015458: bne         $s5, $s1, L_800153B0
    if (ctx->r21 != ctx->r17) {
        // 0x8001545C: nop
    
            goto L_800153B0;
    }
    // 0x8001545C: nop

L_80015460:
    // 0x80015460: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80015464: addiu       $s2, $s2, -0x4C28
    ctx->r18 = ADD32(ctx->r18, -0X4C28);
    // 0x80015468: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_8001546C:
    // 0x8001546C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80015470: beq         $at, $zero, L_8001557C
    if (ctx->r1 == 0) {
        // 0x80015474: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_8001557C;
    }
    // 0x80015474: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80015478: subu        $v1, $s4, $s3
    ctx->r3 = SUB32(ctx->r20, ctx->r19);
    // 0x8001547C: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x80015480: beq         $t3, $zero, L_800154D8
    if (ctx->r11 == 0) {
        // 0x80015484: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800154D8;
    }
    // 0x80015484: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x80015488: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8001548C: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80015490: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80015494: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80015498: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8001549C: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154A0: lwc1        $f2, 0x30($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800154A4: addiu       $a3, $s3, 0x1
    ctx->r7 = ADD32(ctx->r19, 0X1);
    // 0x800154A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800154AC: nop

    // 0x800154B0: bc1f        L_800154CC
    if (!c1cs) {
        // 0x800154B4: nop
    
            goto L_800154CC;
    }
    // 0x800154B4: nop

    // 0x800154B8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800154BC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800154C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800154C4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800154C8: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
L_800154CC:
    // 0x800154CC: beq         $a3, $s4, L_8001557C
    if (ctx->r7 == ctx->r20) {
        // 0x800154D0: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8001557C;
    }
    // 0x800154D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800154D4: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
L_800154D8:
    // 0x800154D8: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
L_800154DC:
    // 0x800154DC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800154E0: nop

    // 0x800154E4: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x800154E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800154EC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800154F0: lwc1        $f16, 0x30($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154F4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800154F8: nop

    // 0x800154FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80015500: nop

    // 0x80015504: bc1f        L_8001553C
    if (!c1cs) {
        // 0x80015508: nop
    
            goto L_8001553C;
    }
    // 0x80015508: nop

    // 0x8001550C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80015510: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80015514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015518: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8001551C: sw          $a0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r4;
    // 0x80015520: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80015524: nop

    // 0x80015528: addu        $v0, $t0, $s1
    ctx->r2 = ADD32(ctx->r8, ctx->r17);
    // 0x8001552C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80015530: nop

    // 0x80015534: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80015538: nop

L_8001553C:
    // 0x8001553C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80015540: nop

    // 0x80015544: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80015548: nop

    // 0x8001554C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80015550: nop

    // 0x80015554: bc1f        L_80015570
    if (!c1cs) {
        // 0x80015558: nop
    
            goto L_80015570;
    }
    // 0x80015558: nop

    // 0x8001555C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80015560: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80015564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015568: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8001556C: sw          $v1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r3;
L_80015570:
    // 0x80015570: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80015574: bne         $s1, $a2, L_800154DC
    if (ctx->r17 != ctx->r6) {
        // 0x80015578: nop
    
            goto L_800154DC;
    }
    // 0x80015578: nop

L_8001557C:
    // 0x8001557C: beq         $a1, $zero, L_8001546C
    if (ctx->r5 == 0) {
        // 0x80015580: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_8001546C;
    }
    // 0x80015580: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_80015584:
    // 0x80015584: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80015588: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001558C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80015590: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015594: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015598: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8001559C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800155A0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800155A4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800155A8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800155AC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800155B0: jr          $ra
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
