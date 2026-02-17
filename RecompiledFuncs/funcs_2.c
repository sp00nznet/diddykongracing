#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sndp_stop_all_retrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049C0: jal         0x800048D8
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800049C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049D0: jr          $ra
    // 0x800049D4: nop

    return;
    // 0x800049D4: nop

;}
RECOMP_FUNC void sndp_stop_all_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049E0: jal         0x800048D8
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x800049E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049F0: jr          $ra
    // 0x800049F4: nop

    return;
    // 0x800049F4: nop

;}
RECOMP_FUNC void sndp_set_param(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800049FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004A00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80004A04: sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // 0x80004A08: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80004A0C: beq         $a0, $zero, L_80004A2C
    if (ctx->r4 == 0) {
        // 0x80004A10: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80004A2C;
    }
    // 0x80004A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004A18: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x80004A1C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80004A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004A24: jal         0x800C970C
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_80004A2C:
    // 0x80004A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004A34: jr          $ra
    // 0x80004A38: nop

    return;
    // 0x80004A38: nop

;}
RECOMP_FUNC void sndp_get_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80004A40: lw          $t7, -0x5E58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E58);
    // 0x80004A44: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80004A48: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80004A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80004A50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80004A54: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x80004A58: jr          $ra
    // 0x80004A5C: nop

    return;
    // 0x80004A5C: nop

;}
RECOMP_FUNC void sndp_set_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004A64: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80004A68: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x80004A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004A70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004A74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80004A78: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x80004A7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80004A80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80004A84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80004A88: jal         0x800C9F90
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004A90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80004A94: lw          $t6, -0x5E58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E58);
    // 0x80004A98: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004A9C: lw          $s0, -0x33E0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33E0);
    // 0x80004AA0: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x80004AA4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004AA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80004AAC: beq         $s0, $zero, L_80004B0C
    if (ctx->r16 == 0) {
        // 0x80004AB0: sh          $s1, 0x0($t8)
        MEM_H(0X0, ctx->r24) = ctx->r17;
            goto L_80004B0C;
    }
    // 0x80004AB0: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80004AB4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004AB8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80004ABC: addiu       $s2, $s2, -0x33D4
    ctx->r18 = ADD32(ctx->r18, -0X33D4);
    // 0x80004AC0: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
L_80004AC4:
    // 0x80004AC4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80004AC8: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80004ACC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80004AD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80004AD4: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80004AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004ADC: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x80004AE0: bne         $s1, $t2, L_80004AFC
    if (ctx->r17 != ctx->r10) {
        // 0x80004AE4: nop
    
            goto L_80004AFC;
    }
    // 0x80004AE4: nop

    // 0x80004AE8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80004AEC: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80004AF0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80004AF4: jal         0x800C970C
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_80004AFC:
    // 0x80004AFC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004B00: nop

    // 0x80004B04: bne         $s0, $zero, L_80004AC4
    if (ctx->r16 != 0) {
        // 0x80004B08: nop
    
            goto L_80004AC4;
    }
    // 0x80004B08: nop

L_80004B0C:
    // 0x80004B0C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004B10: jal         0x800C9F90
    // 0x80004B14: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004B14: nop

    after_2:
    // 0x80004B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004B1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004B20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004B24: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80004B28: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80004B2C: jr          $ra
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80004B34: nop

    // 0x80004B38: nop

    // 0x80004B3C: nop

;}
RECOMP_FUNC void racer_sound_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B40: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004B44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004B4C: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x80004B50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004B54: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004B58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004B5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004B60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004B64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004B68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004B6C: bne         $at, $zero, L_80004B78
    if (ctx->r1 != 0) {
        // 0x80004B70: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80004B78;
    }
    // 0x80004B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004B74: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
L_80004B78:
    // 0x80004B78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004B7C: lw          $t6, -0x33B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X33B8);
    // 0x80004B80: nop

    // 0x80004B84: beq         $t6, $zero, L_80004BAC
    if (ctx->r14 == 0) {
        // 0x80004B88: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80004BAC;
    }
    // 0x80004B88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80004B8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80004B90: addiu       $v1, $v1, -0x5E48
    ctx->r3 = ADD32(ctx->r3, -0X5E48);
    // 0x80004B94: addiu       $v0, $v0, -0x5E50
    ctx->r2 = ADD32(ctx->r2, -0X5E50);
L_80004B98:
    // 0x80004B98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004B9C: bne         $v0, $v1, L_80004B98
    if (ctx->r2 != ctx->r3) {
        // 0x80004BA0: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80004B98;
    }
    // 0x80004BA0: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80004BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004BA8: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80004BAC:
    // 0x80004BAC: jal         0x80076EE4
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_0:
    // 0x80004BB4: sll         $s6, $s3, 2
    ctx->r22 = S32(ctx->r19 << 2);
    // 0x80004BB8: addu        $s6, $s6, $s3
    ctx->r22 = ADD32(ctx->r22, ctx->r19);
    // 0x80004BBC: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
    // 0x80004BC0: addu        $t8, $s6, $s0
    ctx->r24 = ADD32(ctx->r22, ctx->r16);
    // 0x80004BC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80004BC8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004BCC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80004BD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BD4: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80004BD8: lui         $s2, 0xFF
    ctx->r18 = S32(0XFF << 16);
    // 0x80004BDC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80004BE0: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x80004BE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80004BEC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80004BF0: jal         0x80070EDC
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80004BF8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80004BFC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80004C00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80004C04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80004C08: jal         0x80077190
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    after_2:
    // 0x80004C10: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x80004C14: jal         0x80070EDC
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80004C1C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80004C28: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
L_80004C2C:
    // 0x80004C2C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80004C30: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80004C34: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80004C38: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80004C3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004C40: bne         $a3, $a0, L_80004C2C
    if (ctx->r7 != ctx->r4) {
        // 0x80004C44: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80004C2C;
    }
    // 0x80004C44: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80004C48: lbu         $t6, 0x36($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X36);
    // 0x80004C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004C50: lwc1        $f2, 0x5180($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5180);
    // 0x80004C54: sb          $t6, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r14;
    // 0x80004C58: lbu         $t8, 0x37($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X37);
    // 0x80004C5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80004C60: sb          $t8, 0x37($v0)
    MEM_B(0X37, ctx->r2) = ctx->r24;
    // 0x80004C64: lbu         $t7, 0x38($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X38);
    // 0x80004C68: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80004C6C: sb          $t7, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r15;
    // 0x80004C70: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
    // 0x80004C74: or          $t3, $s5, $zero
    ctx->r11 = ctx->r21 | 0;
    // 0x80004C78: sb          $t9, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r25;
    // 0x80004C7C: lbu         $t6, 0x3A($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X3A);
    // 0x80004C80: or          $t4, $s5, $zero
    ctx->r12 = ctx->r21 | 0;
    // 0x80004C84: sb          $t6, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r14;
    // 0x80004C88: lh          $t8, 0x46($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X46);
    // 0x80004C8C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80004C90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004C94: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x80004C98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004C9C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80004CA0: or          $t2, $s5, $zero
    ctx->r10 = ctx->r21 | 0;
    // 0x80004CA4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CA8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80004CAC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80004CB0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80004CB4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80004CB8: swc1        $f8, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f8.u32l;
    // 0x80004CBC: lh          $t7, 0x3E($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3E);
    // 0x80004CC0: nop

    // 0x80004CC4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004CC8: nop

    // 0x80004CCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004CD0: nop

    // 0x80004CD4: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004CD8: swc1        $f18, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f18.u32l;
    // 0x80004CDC: lh          $t9, 0x40($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X40);
    // 0x80004CE0: nop

    // 0x80004CE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80004CE8: nop

    // 0x80004CEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004CF0: nop

    // 0x80004CF4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CF8: swc1        $f8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f8.u32l;
    // 0x80004CFC: lh          $t6, 0x42($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X42);
    // 0x80004D00: nop

    // 0x80004D04: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80004D08: nop

    // 0x80004D0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D10: nop

    // 0x80004D14: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D18: swc1        $f18, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f18.u32l;
    // 0x80004D1C: lh          $t8, 0x44($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X44);
    // 0x80004D20: nop

    // 0x80004D24: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004D28: nop

    // 0x80004D2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D30: nop

    // 0x80004D34: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D38: swc1        $f8, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f8.u32l;
    // 0x80004D3C: lh          $t7, 0x3C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3C);
    // 0x80004D40: nop

    // 0x80004D44: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004D48: nop

    // 0x80004D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004D54: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D58: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
    // 0x80004D5C: lbu         $t9, 0x3B($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X3B);
    // 0x80004D60: nop

    // 0x80004D64: sb          $t9, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r25;
    // 0x80004D68: lh          $t6, 0x48($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X48);
    // 0x80004D6C: sb          $zero, 0xD8($v0)
    MEM_B(0XD8, ctx->r2) = 0;
    // 0x80004D70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80004D74: nop

    // 0x80004D78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D7C: nop

    // 0x80004D80: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D84: swc1        $f8, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f8.u32l;
L_80004D88:
    // 0x80004D88: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80004D8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004D90: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
    // 0x80004D94: lbu         $t7, 0x4($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X4);
    // 0x80004D98: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
    // 0x80004D9C: sb          $t7, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r15;
    // 0x80004DA0: lhu         $t9, 0x18($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X18);
    // 0x80004DA4: addiu       $a1, $t4, 0x2
    ctx->r5 = ADD32(ctx->r12, 0X2);
    // 0x80004DA8: sh          $t9, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r25;
    // 0x80004DAC: lbu         $t6, 0xE($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0XE);
    // 0x80004DB0: addiu       $a0, $t5, 0x1
    ctx->r4 = ADD32(ctx->r13, 0X1);
    // 0x80004DB4: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x80004DB8: lbu         $t8, 0x2C($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2C);
    // 0x80004DBC: addiu       $a2, $ra, 0x2
    ctx->r6 = ADD32(ctx->r31, 0X2);
    // 0x80004DC0: sb          $t8, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = ctx->r24;
L_80004DC4:
    // 0x80004DC4: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80004DC8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80004DCC: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80004DD0: lhu         $t9, 0x18($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X18);
    // 0x80004DD4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80004DD8: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x80004DDC: lbu         $t6, 0xC($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XC);
    // 0x80004DE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004DE4: sb          $t6, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r14;
    // 0x80004DE8: lbu         $t8, 0x2A($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2A);
    // 0x80004DEC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80004DF0: sb          $t8, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r24;
    // 0x80004DF4: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80004DF8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80004DFC: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    // 0x80004E00: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x80004E04: nop

    // 0x80004E08: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x80004E0C: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x80004E10: nop

    // 0x80004E14: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x80004E18: lbu         $t8, 0x2B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2B);
    // 0x80004E1C: bne         $a3, $t0, L_80004DC4
    if (ctx->r7 != ctx->r8) {
        // 0x80004E20: sb          $t8, 0x2B($a0)
        MEM_B(0X2B, ctx->r4) = ctx->r24;
            goto L_80004DC4;
    }
    // 0x80004E20: sb          $t8, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r24;
    // 0x80004E24: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80004E28: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80004E2C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80004E30: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80004E34: addiu       $t4, $t4, 0xA
    ctx->r12 = ADD32(ctx->r12, 0XA);
    // 0x80004E38: addiu       $t5, $t5, 0x5
    ctx->r13 = ADD32(ctx->r13, 0X5);
    // 0x80004E3C: addiu       $ra, $ra, 0xA
    ctx->r31 = ADD32(ctx->r31, 0XA);
    // 0x80004E40: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x80004E44: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80004E48: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x80004E4C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x80004E50: bne         $at, $zero, L_80004D88
    if (ctx->r1 != 0) {
        // 0x80004E54: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_80004D88;
    }
    // 0x80004E54: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80004E58: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    // 0x80004E5C: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x80004E60: lbu         $t7, 0x4A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X4A);
    // 0x80004E64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004E68: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80004E6C: bgez        $t7, L_80004E80
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004E70: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80004E80;
    }
    // 0x80004E70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004E74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004E78: nop

    // 0x80004E7C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80004E80:
    // 0x80004E80: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80004E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80004E88: nop

    // 0x80004E8C: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80004E90: bne         $s6, $zero, L_80004F40
    if (ctx->r22 != 0) {
        // 0x80004E94: swc1        $f8, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
            goto L_80004F40;
    }
    // 0x80004E94: swc1        $f8, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
    // 0x80004E98: lbu         $t9, 0x2C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2C);
    // 0x80004E9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EA0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80004EA4: bgez        $t9, L_80004EB8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80004EA8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80004EB8;
    }
    // 0x80004EA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004EB0: nop

    // 0x80004EB4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80004EB8:
    // 0x80004EB8: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x80004EBC: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
    // 0x80004EC0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80004EC4: bgez        $t6, L_80004EDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80004EC8: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80004EDC;
    }
    // 0x80004EC8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80004ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004ED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004ED4: nop

    // 0x80004ED8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80004EDC:
    // 0x80004EDC: nop

    // 0x80004EE0: div.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004EE4: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x80004EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EEC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004EF0: nop

    // 0x80004EF4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004EF8: bgez        $t8, L_80004F0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80004EFC: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_80004F0C;
    }
    // 0x80004EFC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80004F00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004F04: nop

    // 0x80004F08: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80004F0C:
    // 0x80004F0C: lhu         $t7, 0x22($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X22);
    // 0x80004F10: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80004F14: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004F18: bgez        $t7, L_80004F30
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004F1C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80004F30;
    }
    // 0x80004F1C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004F20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004F24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004F28: nop

    // 0x80004F2C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80004F30:
    // 0x80004F30: nop

    // 0x80004F34: div.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004F38: b           L_80005090
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
        goto L_80005090;
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
L_80004F40:
    // 0x80004F40: lwc1        $f0, 0xD4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x80004F44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F48: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80004F4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004F50: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80004F54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80004F58: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F5C: nop

    // 0x80004F60: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80004F64: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F68: nop

    // 0x80004F6C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004F70: beq         $v1, $zero, L_80004FBC
    if (ctx->r3 == 0) {
        // 0x80004F74: nop
    
            goto L_80004FBC;
    }
    // 0x80004F74: nop

    // 0x80004F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80004F7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F80: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80004F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004F88: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F8C: nop

    // 0x80004F90: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80004F94: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F98: nop

    // 0x80004F9C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004FA0: bne         $v1, $zero, L_80004FB4
    if (ctx->r3 != 0) {
        // 0x80004FA4: nop
    
            goto L_80004FB4;
    }
    // 0x80004FA4: nop

    // 0x80004FA8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FAC: b           L_80004FCC
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80004FCC;
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80004FB4:
    // 0x80004FB4: b           L_80004FCC
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80004FCC;
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80004FBC:
    // 0x80004FBC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FC0: nop

    // 0x80004FC4: bltz        $v1, L_80004FB4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80004FC8: nop
    
            goto L_80004FB4;
    }
    // 0x80004FC8: nop

L_80004FCC:
    // 0x80004FCC: lhu         $t8, 0x18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X18);
    // 0x80004FD0: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x80004FD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80004FD8: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80004FDC: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80004FE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005010;
    }
    // 0x80004FE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80004FE4:
    // 0x80004FE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004FE8: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x80004FEC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80004FF0: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80004FF4: lhu         $t8, 0x18($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X18);
    // 0x80004FF8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80004FFC: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80005000: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80005004: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80005010;
    }
    // 0x80005004: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80005008: bne         $at, $zero, L_80004FE4
    if (ctx->r1 != 0) {
        // 0x8000500C: nop
    
            goto L_80004FE4;
    }
    // 0x8000500C: nop

L_80005010:
    // 0x80005010: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80005014: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80005018: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8000501C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80005020: lhu         $a2, 0x18($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X18);
    // 0x80005024: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80005028: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8000502C: lhu         $t6, 0x1A($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X1A);
    // 0x80005030: subu        $t8, $a1, $a2
    ctx->r24 = SUB32(ctx->r5, ctx->r6);
    // 0x80005034: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80005038: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x8000503C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80005040: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005044: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x80005048: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000504C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005050: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80005054: lbu         $t6, 0x2D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2D);
    // 0x80005058: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000505C: subu        $t8, $t6, $a3
    ctx->r24 = SUB32(ctx->r14, ctx->r7);
    // 0x80005060: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80005064: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80005068: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000506C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005070: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80005074: bgez        $a3, L_80005088
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80005078: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005088;
    }
    // 0x80005078: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000507C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005080: nop

    // 0x80005084: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80005088:
    // 0x80005088: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000508C: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_80005090:
    // 0x80005090: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80005094: jal         0x80071380
    // 0x80005098: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80005098: nop

    after_4:
    // 0x8000509C: jal         0x80071380
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x800050A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800050A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800050AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800050B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800050B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800050B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800050BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800050C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800050C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800050C8: jr          $ra
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void racer_sound_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800050D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800050D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800050D8: lbu         $t6, -0x33C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33C0);
    // 0x800050DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800050E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800050E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800050E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800050EC: beq         $t6, $zero, L_80005244
    if (ctx->r14 == 0) {
        // 0x800050F0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80005244;
    }
    // 0x800050F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800050F4: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x800050F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800050FC: addiu       $v0, $v0, -0x5E44
    ctx->r2 = ADD32(ctx->r2, -0X5E44);
    // 0x80005100: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005104: lw          $t9, 0x118($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X118);
    // 0x80005108: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000510C: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005110: beq         $t9, $zero, L_80005244
    if (ctx->r25 == 0) {
        // 0x80005114: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_80005244;
    }
    // 0x80005114: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80005118: jal         0x8001139C
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80005120: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005124: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005128: beq         $v0, $zero, L_8000517C
    if (ctx->r2 == 0) {
        // 0x8000512C: addiu       $a1, $a1, -0x5E48
        ctx->r5 = ADD32(ctx->r5, -0X5E48);
            goto L_8000517C;
    }
    // 0x8000512C: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005130: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005134: lw          $t1, -0x5E44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E44);
    // 0x80005138: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000513C: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80005140: nop

    // 0x80005144: beq         $a0, $at, L_8000517C
    if (ctx->r4 == ctx->r1) {
        // 0x80005148: nop
    
            goto L_8000517C;
    }
    // 0x80005148: nop

    // 0x8000514C: jal         0x8006A768
    // 0x80005150: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x80005150: nop

    after_1:
    // 0x80005154: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80005158: lw          $t2, -0x5E44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E44);
    // 0x8000515C: nop

    // 0x80005160: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x80005164: jal         0x8006A794
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000516C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005170: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005174: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005178: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8000517C:
    // 0x8000517C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80005180: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x80005184: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x80005188: nop

    // 0x8000518C: bne         $t3, $zero, L_800051B8
    if (ctx->r11 != 0) {
        // 0x80005190: nop
    
            goto L_800051B8;
    }
    // 0x80005190: nop

    // 0x80005194: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80005198: nop

    // 0x8000519C: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x800051A0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800051A4: nop

    // 0x800051A8: swc1        $f0, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f0.u32l;
    // 0x800051AC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800051B0: b           L_80005244
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
        goto L_80005244;
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
L_800051B8:
    // 0x800051B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800051BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800051C0: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x800051C4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800051C8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800051CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800051D0: swc1        $f6, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f6.u32l;
    // 0x800051D4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800051D8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800051DC: nop

    // 0x800051E0: swc1        $f8, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f8.u32l;
    // 0x800051E4: lw          $t8, -0x5E44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E44);
    // 0x800051E8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800051EC: lb          $v1, 0x1D7($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X1D7);
    // 0x800051F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800051F4: beq         $v1, $at, L_8000520C
    if (ctx->r3 == ctx->r1) {
        // 0x800051F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000520C;
    }
    // 0x800051F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800051FC: beq         $v1, $at, L_80005220
    if (ctx->r3 == ctx->r1) {
        // 0x80005200: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80005220;
    }
    // 0x80005200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80005204: b           L_80005238
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
        goto L_80005238;
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8000520C:
    // 0x8000520C: jal         0x80005D08
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_hovercraft(rdram, ctx);
        goto after_3;
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80005214: b           L_80005248
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000521C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005220:
    // 0x80005220: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80005224: jal         0x800063EC
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_plane(rdram, ctx);
        goto after_4;
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8000522C: b           L_80005248
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005238:
    // 0x80005238: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8000523C: jal         0x80005254
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_car(rdram, ctx);
        goto after_5;
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80005244:
    // 0x80005244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005248:
    // 0x80005248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000524C: jr          $ra
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void racer_sound_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005254: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80005258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000525C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005260: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80005264: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80005268: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000526C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80005270: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80005274: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80005278: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000527C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80005280: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80005284: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80005288: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8000528C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80005290: lb          $t6, 0x1FB($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X1FB);
    // 0x80005294: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80005298: beq         $t6, $zero, L_800052B0
    if (ctx->r14 == 0) {
        // 0x8000529C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800052B0;
    }
    // 0x8000529C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800052A0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800052A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800052A8: b           L_800052BC
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
        goto L_800052BC;
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052B0:
    // 0x800052B0: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800052B4: nop

    // 0x800052B8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052BC:
    // 0x800052BC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800052C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800052C4: bc1f        L_800052D0
    if (!c1cs) {
        // 0x800052C8: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800052D0;
    }
    // 0x800052C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800052CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800052D0:
    // 0x800052D0: nop

    // 0x800052D4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800052D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800052DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800052E0: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x800052E4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800052E8: andi        $t8, $s2, 0x8000
    ctx->r24 = ctx->r18 & 0X8000;
    // 0x800052EC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800052F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800052F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800052F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800052FC: nop

    // 0x80005300: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80005304: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80005308: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000530C: nop

    // 0x80005310: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80005314: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80005318: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000531C: addiu       $s0, $v0, 0x5
    ctx->r16 = ADD32(ctx->r2, 0X5);
    // 0x80005320: slti        $at, $s0, 0x65
    ctx->r1 = SIGNED(ctx->r16) < 0X65 ? 1 : 0;
    // 0x80005324: bne         $at, $zero, L_80005330
    if (ctx->r1 != 0) {
        // 0x80005328: nop
    
            goto L_80005330;
    }
    // 0x80005328: nop

    // 0x8000532C: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_80005330:
    // 0x80005330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005334: lwc1        $f21, 0x5188($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X5188);
    // 0x80005338: lwc1        $f20, 0x518C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X518C);
    // 0x8000533C: lw          $a3, -0x5E48($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5E48);
    // 0x80005340: addiu       $s1, $s1, -0x5E48
    ctx->r17 = ADD32(ctx->r17, -0X5E48);
L_80005344:
    // 0x80005344: addu        $t9, $a3, $t4
    ctx->r25 = ADD32(ctx->r7, ctx->r12);
    // 0x80005348: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x8000534C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80005350: beq         $t5, $zero, L_80005A0C
    if (ctx->r13 == 0) {
        // 0x80005354: addu        $t6, $t6, $t1
        ctx->r14 = ADD32(ctx->r14, ctx->r9);
            goto L_80005A0C;
    }
    // 0x80005354: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80005358: addu        $t0, $a3, $t6
    ctx->r8 = ADD32(ctx->r7, ctx->r14);
    // 0x8000535C: lbu         $t7, 0xE($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XE);
    // 0x80005360: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005364: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80005368: bne         $at, $zero, L_8000538C
    if (ctx->r1 != 0) {
        // 0x8000536C: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8000538C;
    }
    // 0x8000536C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80005370: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80005374: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80005378: addu        $a2, $a3, $t8
    ctx->r6 = ADD32(ctx->r7, ctx->r24);
    // 0x8000537C: lbu         $t9, 0xF($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XF);
    // 0x80005380: nop

    // 0x80005384: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005388: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x8000538C: sll         $t5, $t1, 2
        ctx->r13 = S32(ctx->r9 << 2);
            goto L_800053CC;
    }
L_8000538C:
    // 0x8000538C: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80005390: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80005394: addu        $a2, $a3, $t5
    ctx->r6 = ADD32(ctx->r7, ctx->r13);
    // 0x80005398: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_8000539C:
    // 0x8000539C: lbu         $t6, 0xF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF);
    // 0x800053A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800053A4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800053A8: bne         $at, $zero, L_800053C0
    if (ctx->r1 != 0) {
        // 0x800053AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800053C0;
    }
    // 0x800053AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800053B0: lbu         $t7, 0xF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF);
    // 0x800053B4: nop

    // 0x800053B8: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800053BC: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x800053C0: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800053CC;
    }
L_800053C0:
    // 0x800053C0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800053C4: bne         $at, $zero, L_8000539C
    if (ctx->r1 != 0) {
        // 0x800053C8: nop
    
            goto L_8000539C;
    }
    // 0x800053C8: nop

L_800053CC:
    // 0x800053CC: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x800053D0: lbu         $a0, 0xE($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XE);
    // 0x800053D4: lbu         $t9, 0xF($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF);
    // 0x800053D8: subu        $t8, $s0, $a0
    ctx->r24 = SUB32(ctx->r16, ctx->r4);
    // 0x800053DC: subu        $t5, $t9, $a0
    ctx->r13 = SUB32(ctx->r25, ctx->r4);
    // 0x800053E0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800053E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800053E8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800053EC: lbu         $a1, 0x2C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2C);
    // 0x800053F0: lbu         $t6, 0x2D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2D);
    // 0x800053F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800053F8: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x800053FC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80005400: div.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005404: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005408: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000540C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005410: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005414: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000541C: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80005420: bgez        $a1, L_80005434
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80005424: nop
    
            goto L_80005434;
    }
    // 0x80005424: nop

    // 0x80005428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000542C: nop

    // 0x80005430: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80005434:
    // 0x80005434: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80005438: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000543C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005440: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005444: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005448: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000544C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005450: nop

    // 0x80005454: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005458: beq         $t3, $zero, L_800054A4
    if (ctx->r11 == 0) {
        // 0x8000545C: nop
    
            goto L_800054A4;
    }
    // 0x8000545C: nop

    // 0x80005460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005464: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005468: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000546C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005470: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005474: nop

    // 0x80005478: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000547C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005480: nop

    // 0x80005484: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005488: bne         $t3, $zero, L_8000549C
    if (ctx->r11 != 0) {
        // 0x8000548C: nop
    
            goto L_8000549C;
    }
    // 0x8000548C: nop

    // 0x80005490: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80005494: b           L_800054B4
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800054B4;
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8000549C:
    // 0x8000549C: b           L_800054B4
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800054B4;
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800054A4:
    // 0x800054A4: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800054A8: nop

    // 0x800054AC: bltz        $t3, L_8000549C
    if (SIGNED(ctx->r11) < 0) {
        // 0x800054B0: nop
    
            goto L_8000549C;
    }
    // 0x800054B0: nop

L_800054B4:
    // 0x800054B4: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x800054B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800054BC: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800054C0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800054C4: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x800054C8: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800054E0;
    }
    // 0x800054C8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800054CC: lbu         $t6, 0x5($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X5);
    // 0x800054D0: nop

    // 0x800054D4: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800054D8: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x800054DC: nop
    
            goto L_80005510;
    }
    // 0x800054DC: nop

L_800054E0:
    // 0x800054E0: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x800054E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800054E8: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800054EC: bne         $at, $zero, L_80005504
    if (ctx->r1 != 0) {
        // 0x800054F0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80005504;
    }
    // 0x800054F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800054F4: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800054F8: nop

    // 0x800054FC: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005500: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x80005504: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80005510;
    }
L_80005504:
    // 0x80005504: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80005508: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x8000550C: nop
    
            goto L_800054E0;
    }
    // 0x8000550C: nop

L_80005510:
    // 0x80005510: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005514: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80005518: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8000551C: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x80005520: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80005524: subu        $t9, $s0, $a0
    ctx->r25 = SUB32(ctx->r16, ctx->r4);
    // 0x80005528: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8000552C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80005530: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80005534: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80005538: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
    // 0x8000553C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80005540: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80005544: lhu         $t5, 0x18($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X18);
    // 0x80005548: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000554C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80005550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005554: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80005558: lwc1        $f0, 0x5190($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5190);
    // 0x8000555C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005560: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80005564: bgez        $t5, L_80005578
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80005568: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80005578;
    }
    // 0x80005568: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000556C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005570: nop

    // 0x80005574: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80005578:
    // 0x80005578: lhu         $t6, 0x1A($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1A);
    // 0x8000557C: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005580: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80005584: bgez        $t6, L_8000559C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80005588: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000559C;
    }
    // 0x80005588: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000558C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005594: nop

    // 0x80005598: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8000559C:
    // 0x8000559C: slti        $at, $s0, 0x33
    ctx->r1 = SIGNED(ctx->r16) < 0X33 ? 1 : 0;
    // 0x800055A0: bne         $at, $zero, L_8000567C
    if (ctx->r1 != 0) {
        // 0x800055A4: div.s       $f18, $f8, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
            goto L_8000567C;
    }
    // 0x800055A4: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800055A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800055AC: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x800055B0: nop

    // 0x800055B4: lb          $v0, 0x185($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X185);
    // 0x800055B8: nop

    // 0x800055BC: beq         $v0, $zero, L_8000567C
    if (ctx->r2 == 0) {
        // 0x800055C0: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_8000567C;
    }
    // 0x800055C0: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800055C4: beq         $at, $zero, L_800055D4
    if (ctx->r1 == 0) {
        // 0x800055C8: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800055D4;
    }
    // 0x800055C8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800055CC: b           L_800055D4
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800055D4;
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800055D4:
    // 0x800055D4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800055D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800055DC: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x800055E0: lwc1        $f5, 0x5198($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5198);
    // 0x800055E4: lwc1        $f4, 0x519C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X519C);
    // 0x800055E8: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800055EC: mul.d       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800055F0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800055F4: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800055F8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800055FC: nop

    // 0x80005600: bc1f        L_8000563C
    if (!c1cs) {
        // 0x80005604: nop
    
            goto L_8000563C;
    }
    // 0x80005604: nop

    // 0x80005608: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000560C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005610: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80005614: nop

    // 0x80005618: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x8000561C: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x80005620: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005624: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x80005628: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000562C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005630: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005634: b           L_8000566C
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
        goto L_8000566C;
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000563C:
    // 0x8000563C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80005640: nop

    // 0x80005644: bc1f        L_80005668
    if (!c1cs) {
        // 0x80005648: nop
    
            goto L_80005668;
    }
    // 0x80005648: nop

    // 0x8000564C: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    // 0x80005650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005654: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x80005658: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000565C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005660: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005664: nop

L_80005668:
    // 0x80005668: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000566C:
    // 0x8000566C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80005670: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80005674: b           L_800056C0
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
        goto L_800056C0;
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
L_8000567C:
    // 0x8000567C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005680: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005684: lwc1        $f7, 0x51A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X51A0);
    // 0x80005688: lwc1        $f6, 0x51A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51A4);
    // 0x8000568C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80005690: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80005694: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80005698: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000569C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800056A0: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800056A4: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x800056A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800056AC: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x800056B0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800056B4: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800056B8: nop

    // 0x800056BC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_800056C0:
    // 0x800056C0: lb          $t8, 0x1E6($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1E6);
    // 0x800056C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800056C8: beq         $t8, $zero, L_8000570C
    if (ctx->r24 == 0) {
        // 0x800056CC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8000570C;
    }
    // 0x800056CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800056D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800056D4: lwc1        $f7, 0x51A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X51A8);
    // 0x800056D8: lwc1        $f6, 0x51AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51AC);
    // 0x800056DC: lwc1        $f4, 0x40($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800056E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800056E4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800056E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800056EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800056F0: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x800056F4: nop

    // 0x800056F8: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800056FC: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x80005700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005704: b           L_80005720
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
        goto L_80005720;
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
L_8000570C:
    // 0x8000570C: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80005710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005714: nop

    // 0x80005718: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000571C: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
L_80005720:
    // 0x80005720: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005724: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005728: lwc1        $f8, 0x40($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8000572C: lb          $t9, 0x1E2($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1E2);
    // 0x80005730: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005734: bne         $t9, $zero, L_80005760
    if (ctx->r25 != 0) {
        // 0x80005738: add.s       $f2, $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
            goto L_80005760;
    }
    // 0x80005738: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000573C: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x80005740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80005744: beq         $t5, $at, L_80005760
    if (ctx->r13 == ctx->r1) {
        // 0x80005748: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005760;
    }
    // 0x80005748: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000574C: lwc1        $f5, 0x51B0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51B0);
    // 0x80005750: lwc1        $f4, 0x51B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51B4);
    // 0x80005754: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80005758: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8000575C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_80005760:
    // 0x80005760: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80005764: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000576C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80005770: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80005774: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005778: div.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000577C: bgez        $t3, L_80005790
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80005780: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005790;
    }
    // 0x80005780: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005788: nop

    // 0x8000578C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80005790:
    // 0x80005790: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005798: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8000579C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800057A0: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800057A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800057A8: beq         $t6, $at, L_800058B4
    if (ctx->r14 == ctx->r1) {
        // 0x800057AC: div.s       $f14, $f6, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
            goto L_800058B4;
    }
    // 0x800057AC: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800057B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057B8: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057BC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057C0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800057C4: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800057C8: jal         0x8006FB8C
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800057D0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800057D4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800057D8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800057DC: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800057E0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800057E4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800057E8: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x800057EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005868;
    }
    // 0x800057EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057F4: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057F8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057FC: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x80005800: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x80005804: jal         0x8006FB8C
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8000580C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005810: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80005814: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005818: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000581C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80005820: addiu       $t9, $t8, -0x5
    ctx->r25 = ADD32(ctx->r24, -0X5);
    // 0x80005824: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80005828: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000582C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80005830: sb          $t9, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r25;
    // 0x80005834: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005838: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000583C: lb          $v1, 0x90($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X90);
    // 0x80005840: nop

    // 0x80005844: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80005848: bne         $at, $zero, L_8000585C
    if (ctx->r1 != 0) {
        // 0x8000584C: slti        $at, $v1, -0x5
        ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
            goto L_8000585C;
    }
    // 0x8000584C: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x80005850: b           L_80005868
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
        goto L_80005868;
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
    // 0x80005858: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
L_8000585C:
    // 0x8000585C: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x80005860: addiu       $t6, $zero, -0x5
        ctx->r14 = ADD32(0, -0X5);
            goto L_80005868;
    }
    // 0x80005860: addiu       $t6, $zero, -0x5
    ctx->r14 = ADD32(0, -0X5);
    // 0x80005864: sb          $t6, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r14;
L_80005868:
    // 0x80005868: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000586C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005870: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005878: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000587C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005880: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005884: lwc1        $f11, 0x51B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51B8);
    // 0x80005888: lwc1        $f10, 0x51BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51BC);
    // 0x8000588C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005890: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005894: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80005898: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8000589C: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800058A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800058A4: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800058A8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800058AC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800058B0: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_800058B4:
    // 0x800058B4: beq         $s2, $zero, L_8000593C
    if (ctx->r18 == 0) {
        // 0x800058B8: nop
    
            goto L_8000593C;
    }
    // 0x800058B8: nop

    // 0x800058BC: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x800058C0: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800058C4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800058C8: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    // 0x800058CC: nop

    // 0x800058D0: bc1f        L_8000593C
    if (!c1cs) {
        // 0x800058D4: nop
    
            goto L_8000593C;
    }
    // 0x800058D4: nop

    // 0x800058D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800058DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800058E4: lwc1        $f5, 0x51C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51C0);
    // 0x800058E8: lwc1        $f4, 0x51C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51C4);
    // 0x800058EC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800058F0: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800058F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058F8: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x800058FC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80005900: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
    // 0x80005904: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005908: nop

    // 0x8000590C: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005910: nop

    // 0x80005914: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005918: c.lt.d      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.d < ctx->f10.d;
    // 0x8000591C: nop

    // 0x80005920: bc1f        L_8000593C
    if (!c1cs) {
        // 0x80005924: nop
    
            goto L_8000593C;
    }
    // 0x80005924: nop

    // 0x80005928: lwc1        $f8, 0x51C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51C8);
    // 0x8000592C: nop

    // 0x80005930: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005934: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005938: nop

L_8000593C:
    // 0x8000593C: bne         $s2, $zero, L_800059B8
    if (ctx->r18 != 0) {
        // 0x80005940: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005940: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005944: lwc1        $f0, 0x94($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005948: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8000594C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80005950: nop

    // 0x80005954: bc1f        L_800059B8
    if (!c1cs) {
        // 0x80005958: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005958: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8000595C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80005960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005964: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005968: lwc1        $f9, 0x51D0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X51D0);
    // 0x8000596C: lwc1        $f8, 0x51D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51D4);
    // 0x80005970: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005974: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80005978: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8000597C: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x80005980: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80005984: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005988: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000598C: nop

    // 0x80005990: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005994: nop

    // 0x80005998: c.lt.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl < ctx->f22.fl;
    // 0x8000599C: nop

    // 0x800059A0: bc1f        L_800059B8
    if (!c1cs) {
        // 0x800059A4: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x800059A4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x800059A8: swc1        $f22, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f22.u32l;
    // 0x800059AC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059B0: nop

    // 0x800059B4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
L_800059B8:
    // 0x800059B8: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x800059BC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800059C0: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800059C4: beq         $s2, $zero, L_800059F4
    if (ctx->r18 == 0) {
        // 0x800059C8: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_800059F4;
    }
    // 0x800059C8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x800059CC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800059D0: nop

    // 0x800059D4: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800059D8: lwc1        $f8, 0x54($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800059DC: nop

    // 0x800059E0: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800059E4: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x800059E8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059EC: b           L_80005A10
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80005A10;
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800059F4:
    // 0x800059F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800059F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800059FC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80005A00: swc1        $f6, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f6.u32l;
    // 0x80005A04: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005A08: nop

L_80005A0C:
    // 0x80005A0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80005A10:
    // 0x80005A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005A14: bne         $t1, $at, L_80005344
    if (ctx->r9 != ctx->r1) {
        // 0x80005A18: addiu       $t4, $t4, 0x2
        ctx->r12 = ADD32(ctx->r12, 0X2);
            goto L_80005344;
    }
    // 0x80005A18: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x80005A1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005A20: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005A24: nop

    // 0x80005A28: lw          $t8, 0x10($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X10);
    // 0x80005A2C: nop

    // 0x80005A30: bne         $t8, $zero, L_80005A80
    if (ctx->r24 != 0) {
        // 0x80005A34: nop
    
            goto L_80005A80;
    }
    // 0x80005A34: nop

    // 0x80005A38: lw          $t9, 0x14($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X14);
    // 0x80005A3C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80005A40: bne         $t9, $zero, L_80005A80
    if (ctx->r25 != 0) {
        // 0x80005A44: andi        $t6, $t5, 0x4000
        ctx->r14 = ctx->r13 & 0X4000;
            goto L_80005A80;
    }
    // 0x80005A44: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80005A48: beq         $t6, $zero, L_80005A80
    if (ctx->r14 == 0) {
        // 0x80005A4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005A80;
    }
    // 0x80005A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005A50: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005A54: lwc1        $f11, 0x51D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51D8);
    // 0x80005A58: lwc1        $f10, 0x51DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51DC);
    // 0x80005A5C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80005A60: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80005A64: nop

    // 0x80005A68: bc1t        L_80005A80
    if (c1cs) {
        // 0x80005A6C: nop
    
            goto L_80005A80;
    }
    // 0x80005A6C: nop

    // 0x80005A70: lb          $t7, 0x1D6($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D6);
    // 0x80005A74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80005A78: bne         $t7, $at, L_80005ABC
    if (ctx->r15 != ctx->r1) {
        // 0x80005A7C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A7C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005A80:
    // 0x80005A80: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005A84: nop

    // 0x80005A88: beq         $a0, $zero, L_80005ABC
    if (ctx->r4 == 0) {
        // 0x80005A8C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A8C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80005A90: jal         0x8000488C
    // 0x80005A94: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80005A94: nop

    after_2:
    // 0x80005A98: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005A9C: nop

    // 0x80005AA0: sw          $zero, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = 0;
    // 0x80005AA4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005AA8: nop

    // 0x80005AAC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AB0: b           L_80005BA0
    // 0x80005AB4: nop

        goto L_80005BA0;
    // 0x80005AB4: nop

    // 0x80005AB8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005ABC:
    // 0x80005ABC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AC0: andi        $t5, $t9, 0x4000
    ctx->r13 = ctx->r25 & 0X4000;
    // 0x80005AC4: beq         $t5, $zero, L_80005BA0
    if (ctx->r13 == 0) {
        // 0x80005AC8: nop
    
            goto L_80005BA0;
    }
    // 0x80005AC8: nop

    // 0x80005ACC: bne         $a0, $zero, L_80005BA0
    if (ctx->r4 != 0) {
        // 0x80005AD0: nop
    
            goto L_80005BA0;
    }
    // 0x80005AD0: nop

    // 0x80005AD4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x80005AD8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005ADC: bltz        $t6, L_80005BA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80005AE0: addiu       $a1, $a3, 0xA8
        ctx->r5 = ADD32(ctx->r7, 0XA8);
            goto L_80005BA0;
    }
    // 0x80005AE0: addiu       $a1, $a3, 0xA8
    ctx->r5 = ADD32(ctx->r7, 0XA8);
    // 0x80005AE4: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005AE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005AEC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005AF0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005AF4: bc1f        L_80005B04
    if (!c1cs) {
        // 0x80005AF8: nop
    
            goto L_80005B04;
    }
    // 0x80005AF8: nop

    // 0x80005AFC: b           L_80005B08
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
        goto L_80005B08;
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_80005B04:
    // 0x80005B04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80005B08:
    // 0x80005B08: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x80005B0C: nop

    // 0x80005B10: bc1f        L_80005B20
    if (!c1cs) {
        // 0x80005B14: nop
    
            goto L_80005B20;
    }
    // 0x80005B14: nop

    // 0x80005B18: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80005B1C: nop

L_80005B20:
    // 0x80005B20: jal         0x80001F14
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    sound_play_direct(rdram, ctx);
        goto after_3;
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x80005B28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80005B2C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80005B30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80005B34: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80005B38: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80005B3C: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x80005B40: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80005B44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005B48: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B4C: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x80005B50: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80005B54: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80005B58: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80005B5C: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B60: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80005B64: beq         $a0, $zero, L_80005B80
    if (ctx->r4 == 0) {
        // 0x80005B68: addiu       $t7, $zero, 0x6E
        ctx->r15 = ADD32(0, 0X6E);
            goto L_80005B80;
    }
    // 0x80005B68: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
    // 0x80005B6C: jal         0x800049F8
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x80005B74: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B78: nop

    // 0x80005B7C: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
L_80005B80:
    // 0x80005B80: sh          $t7, 0xAC($a3)
    MEM_H(0XAC, ctx->r7) = ctx->r15;
    // 0x80005B84: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005B88: nop

    // 0x80005B8C: sb          $zero, 0xD0($t8)
    MEM_B(0XD0, ctx->r24) = 0;
    // 0x80005B90: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B94: nop

    // 0x80005B98: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B9C: nop

L_80005BA0:
    // 0x80005BA0: beq         $a0, $zero, L_80005C48
    if (ctx->r4 == 0) {
        // 0x80005BA4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80005C48;
    }
    // 0x80005BA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80005BA8: lw          $t9, -0x5E44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E44);
    // 0x80005BAC: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80005BB0: lb          $t5, 0x1E2($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X1E2);
    // 0x80005BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005BB8: bne         $t5, $zero, L_80005BD4
    if (ctx->r13 != 0) {
        // 0x80005BBC: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80005BD4;
    }
    // 0x80005BBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80005BC0: lbu         $t6, 0xD0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BC4: nop

    // 0x80005BC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80005BCC: b           L_80005BD8
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
        goto L_80005BD8;
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
L_80005BD4:
    // 0x80005BD4: sb          $zero, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = 0;
L_80005BD8:
    // 0x80005BD8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005BDC: nop

    // 0x80005BE0: lbu         $t9, 0xD0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BE4: nop

    // 0x80005BE8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80005BEC: bne         $at, $zero, L_80005C0C
    if (ctx->r1 != 0) {
        // 0x80005BF0: nop
    
            goto L_80005C0C;
    }
    // 0x80005BF0: nop

    // 0x80005BF4: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005BF8: jal         0x800049F8
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80005C00: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C04: b           L_80005C48
    // 0x80005C08: nop

        goto L_80005C48;
    // 0x80005C08: nop

L_80005C0C:
    // 0x80005C0C: lhu         $a2, 0xAC($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XAC);
    // 0x80005C10: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005C14: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80005C18: jal         0x800049F8
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_6:
    // 0x80005C20: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80005C24: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80005C28: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x80005C2C: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80005C30: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80005C34: lw          $a0, 0xA8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XA8);
    // 0x80005C38: jal         0x80009B7C
    // 0x80005C3C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_7;
    // 0x80005C3C: nop

    after_7:
    // 0x80005C40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C44: nop

L_80005C48:
    // 0x80005C48: beq         $s2, $zero, L_80005CE0
    if (ctx->r18 == 0) {
        // 0x80005C4C: sb          $s0, 0xA0($a3)
        MEM_B(0XA0, ctx->r7) = ctx->r16;
            goto L_80005CE0;
    }
    // 0x80005C4C: sb          $s0, 0xA0($a3)
    MEM_B(0XA0, ctx->r7) = ctx->r16;
    // 0x80005C50: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C54: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005C58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C60: lwc1        $f4, 0x54($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80005C64: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005C68: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80005C6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005C70: nop

    // 0x80005C74: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005C78: beq         $t9, $zero, L_80005CC4
    if (ctx->r25 == 0) {
        // 0x80005C7C: nop
    
            goto L_80005CC4;
    }
    // 0x80005C7C: nop

    // 0x80005C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005C84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C88: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005C8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005C90: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C94: nop

    // 0x80005C98: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80005C9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005CA0: nop

    // 0x80005CA4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005CA8: bne         $t9, $zero, L_80005CBC
    if (ctx->r25 != 0) {
        // 0x80005CAC: nop
    
            goto L_80005CBC;
    }
    // 0x80005CAC: nop

    // 0x80005CB0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CB4: b           L_80005CD4
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80005CD4;
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80005CBC:
    // 0x80005CBC: b           L_80005CD4
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80005CD4;
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80005CC4:
    // 0x80005CC4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CC8: nop

    // 0x80005CCC: bltz        $t9, L_80005CBC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80005CD0: nop
    
            goto L_80005CBC;
    }
    // 0x80005CD0: nop

L_80005CD4:
    // 0x80005CD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80005CD8: sb          $t9, 0x98($a3)
    MEM_B(0X98, ctx->r7) = ctx->r25;
    // 0x80005CDC: nop

L_80005CE0:
    // 0x80005CE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80005CE4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80005CE8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005CEC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80005CF0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005CF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80005CF8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80005CFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80005D00: jr          $ra
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void racer_sound_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80005D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005D10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80005D14: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80005D18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80005D1C: jal         0x8001139C
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005D24: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80005D28: bne         $v0, $zero, L_80005D54
    if (ctx->r2 != 0) {
        // 0x80005D2C: nop
    
            goto L_80005D54;
    }
    // 0x80005D2C: nop

    // 0x80005D30: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80005D34: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80005D38: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80005D3C: nop

    // 0x80005D40: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005D44: jal         0x800CA030
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80005D4C: b           L_80005D5C
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80005D5C;
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80005D54:
    // 0x80005D54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005D58: nop

L_80005D5C:
    // 0x80005D5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005D60: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005D64: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005D68: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80005D6C: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80005D70: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80005D74: beq         $t7, $zero, L_80005DDC
    if (ctx->r15 == 0) {
        // 0x80005D78: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005DDC;
    }
    // 0x80005D78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005D7C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80005D80: lwc1        $f8, 0xB0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x80005D84: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80005D88: nop

    // 0x80005D8C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005D90: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005D94: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005D98: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005D9C: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80005DA0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DA4: nop

    // 0x80005DA8: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80005DAC: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DB0: nop

    // 0x80005DB4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80005DB8: nop

    // 0x80005DBC: bc1f        L_80005E10
    if (!c1cs) {
        // 0x80005DC0: nop
    
            goto L_80005E10;
    }
    // 0x80005DC0: nop

    // 0x80005DC4: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80005DC8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DCC: nop

    // 0x80005DD0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DD4: b           L_80005E14
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_80005E14;
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005DDC:
    // 0x80005DDC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80005DE0: lwc1        $f4, 0xB4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x80005DE4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80005DE8: nop

    // 0x80005DEC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005DF0: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005DF8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80005DFC: swc1        $f4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f4.u32l;
    // 0x80005E00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005E04: nop

    // 0x80005E08: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005E0C: nop

L_80005E10:
    // 0x80005E10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005E14:
    // 0x80005E14: nop

    // 0x80005E18: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80005E1C: nop

    // 0x80005E20: bc1f        L_80005E2C
    if (!c1cs) {
        // 0x80005E24: nop
    
            goto L_80005E2C;
    }
    // 0x80005E24: nop

    // 0x80005E28: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_80005E2C:
    // 0x80005E2C: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x80005E30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80005E34: lh          $t2, 0x196($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X196);
    // 0x80005E38: lh          $t4, 0x1A0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X1A0);
    // 0x80005E3C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80005E40: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80005E44: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x80005E48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x80005E4C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80005E50: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80005E54: bne         $at, $zero, L_80005E64
    if (ctx->r1 != 0) {
        // 0x80005E58: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80005E64;
    }
    // 0x80005E58: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80005E5C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80005E60: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E64:
    // 0x80005E64: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80005E68: beq         $at, $zero, L_80005E74
    if (ctx->r1 == 0) {
        // 0x80005E6C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80005E74;
    }
    // 0x80005E6C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80005E70: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E74:
    // 0x80005E74: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80005E78: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80005E7C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80005E80: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005E84: jal         0x80070A04
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80005E8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80005E90: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005E94: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80005E98: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005E9C: bc1f        L_80005EA8
    if (!c1cs) {
        // 0x80005EA0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80005EA8;
    }
    // 0x80005EA0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80005EA4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80005EA8:
    // 0x80005EA8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005EAC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005EB0: jal         0x80066750
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_3;
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80005EB8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EBC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EC0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EC4: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EC8: nop
    
            goto L_80005F24;
    }
    // 0x80005EC8: nop

    // 0x80005ECC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005ED0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005ED4: jal         0x8001139C
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    get_race_countdown(rdram, ctx);
        goto after_4;
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80005EDC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005EE0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EE4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EE8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EEC: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EF0: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_80005F24;
    }
    // 0x80005EF0: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005EF4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80005EF8: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80005EFC: lwc1        $f10, 0xBC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XBC);
    // 0x80005F00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80005F04: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80005F08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F0C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80005F10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80005F14: nop

    // 0x80005F18: div.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80005F1C: b           L_80005F2C
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80005F2C;
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80005F24:
    // 0x80005F24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80005F28: nop

L_80005F2C:
    // 0x80005F2C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005F30: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80005F34: jal         0x800A06D0
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_5;
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80005F3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005F40: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005F44: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005F48: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80005F4C: bne         $v0, $zero, L_80005F64
    if (ctx->r2 != 0) {
        // 0x80005F50: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_80005F64;
    }
    // 0x80005F50: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005F54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005F58: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80005F5C: nop

    // 0x80005F60: swc1        $f4, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->f4.u32l;
L_80005F64:
    // 0x80005F64: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80005F68: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80005F6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005F70: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80005F74: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80005F78: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80005F7C: bc1f        L_80005F90
    if (!c1cs) {
        // 0x80005F80: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005F90;
    }
    // 0x80005F80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005F84: sub.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d - ctx->f2.d;
    // 0x80005F88: b           L_80005F98
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
        goto L_80005F98;
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
L_80005F90:
    // 0x80005F90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005F94: nop

L_80005F98:
    // 0x80005F98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F9C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80005FA0: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x80005FA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FA8: bc1t        L_8000607C
    if (c1cs) {
        // 0x80005FAC: nop
    
            goto L_8000607C;
    }
    // 0x80005FAC: nop

    // 0x80005FB0: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x80005FB4: nop

    // 0x80005FB8: lb          $v0, 0x185($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X185);
    // 0x80005FBC: nop

    // 0x80005FC0: beq         $v0, $zero, L_8000607C
    if (ctx->r2 == 0) {
        // 0x80005FC4: nop
    
            goto L_8000607C;
    }
    // 0x80005FC4: nop

    // 0x80005FC8: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80005FCC: beq         $at, $zero, L_80005FDC
    if (ctx->r1 == 0) {
        // 0x80005FD0: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80005FDC;
    }
    // 0x80005FD0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80005FD4: b           L_80005FDC
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80005FDC;
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80005FDC:
    // 0x80005FDC: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80005FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FE4: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80005FE8: lwc1        $f5, 0x51E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51E0);
    // 0x80005FEC: lwc1        $f4, 0x51E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51E4);
    // 0x80005FF0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005FF4: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80005FF8: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80005FFC: sll         $t9, $a1, 6
    ctx->r25 = S32(ctx->r5 << 6);
    // 0x80006000: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006004: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006008: nop

    // 0x8000600C: bc1f        L_80006048
    if (!c1cs) {
        // 0x80006010: nop
    
            goto L_80006048;
    }
    // 0x80006010: nop

    // 0x80006014: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80006018: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000601C: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006020: nop

    // 0x80006024: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006028: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x8000602C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006030: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80006034: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006038: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x8000603C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006040: b           L_800060B4
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006048:
    // 0x80006048: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8000604C: nop

    // 0x80006050: bc1f        L_80006074
    if (!c1cs) {
        // 0x80006054: nop
    
            goto L_80006074;
    }
    // 0x80006054: nop

    // 0x80006058: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x8000605C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006060: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006064: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006068: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x8000606C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006070: nop

L_80006074:
    // 0x80006074: b           L_800060B4
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_8000607C:
    // 0x8000607C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006080: lwc1        $f9, 0x51E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X51E8);
    // 0x80006084: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006088: lwc1        $f8, 0x51EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51EC);
    // 0x8000608C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006090: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006094: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006098: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8000609C: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x800060A0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800060A4: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x800060A8: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800060AC: nop

    // 0x800060B0: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800060B4:
    // 0x800060B4: lwc1        $f8, 0xCC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x800060B8: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800060BC: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800060C0: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x800060C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800060C8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800060CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800060D0: beq         $t2, $at, L_8000612C
    if (ctx->r10 == ctx->r1) {
        // 0x800060D4: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_8000612C;
    }
    // 0x800060D4: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800060D8: lb          $t4, 0x1E2($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X1E2);
    // 0x800060DC: nop

    // 0x800060E0: bne         $t4, $zero, L_8000612C
    if (ctx->r12 != 0) {
        // 0x800060E4: nop
    
            goto L_8000612C;
    }
    // 0x800060E4: nop

    // 0x800060E8: lb          $t3, 0x1E5($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1E5);
    // 0x800060EC: nop

    // 0x800060F0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800060F4: beq         $at, $zero, L_8000612C
    if (ctx->r1 == 0) {
        // 0x800060F8: nop
    
            goto L_8000612C;
    }
    // 0x800060F8: nop

    // 0x800060FC: jal         0x8001139C
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80006104: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80006108: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000610C: bne         $v0, $zero, L_8000612C
    if (ctx->r2 != 0) {
        // 0x80006110: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_8000612C;
    }
    // 0x80006110: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006118: lwc1        $f5, 0x51F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51F0);
    // 0x8000611C: lwc1        $f4, 0x51F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51F4);
    // 0x80006120: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80006124: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80006128: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_8000612C:
    // 0x8000612C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006130: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80006134: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80006138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000613C: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80006140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006144: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80006148: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000614C: swc1        $f4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f4.u32l;
    // 0x80006150: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006154: lwc1        $f10, 0x51FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51FC);
    // 0x80006158: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000615C: lwc1        $f11, 0x51F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51F8);
    // 0x80006160: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80006164: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80006168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000616C: bc1f        L_80006190
    if (!c1cs) {
        // 0x80006170: nop
    
            goto L_80006190;
    }
    // 0x80006170: nop

    // 0x80006174: lwc1        $f6, 0x5200($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5200);
    // 0x80006178: nop

    // 0x8000617C: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80006180: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006184: nop

    // 0x80006188: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000618C: nop

L_80006190:
    // 0x80006190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006194: lwc1        $f4, 0x5204($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5204);
    // 0x80006198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000619C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800061A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800061A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800061A8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061AC: nop

    // 0x800061B0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800061B4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061B8: nop

    // 0x800061BC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061C0: beq         $a1, $zero, L_8000620C
    if (ctx->r5 == 0) {
        // 0x800061C4: nop
    
            goto L_8000620C;
    }
    // 0x800061C4: nop

    // 0x800061C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800061CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800061D0: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800061D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800061D8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061DC: nop

    // 0x800061E0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800061E4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061E8: nop

    // 0x800061EC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061F0: bne         $a1, $zero, L_80006204
    if (ctx->r5 != 0) {
        // 0x800061F4: nop
    
            goto L_80006204;
    }
    // 0x800061F4: nop

    // 0x800061F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800061FC: b           L_8000621C
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8000621C;
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80006204:
    // 0x80006204: b           L_8000621C
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8000621C;
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8000620C:
    // 0x8000620C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006210: nop

    // 0x80006214: bltz        $a1, L_80006204
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006218: nop
    
            goto L_80006204;
    }
    // 0x80006218: nop

L_8000621C:
    // 0x8000621C: lhu         $t7, 0x18($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X18);
    // 0x80006220: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x80006224: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80006228: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000622C: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006230: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006260;
    }
    // 0x80006230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006234:
    // 0x80006234: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006238: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8000623C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80006240: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80006244: lhu         $t4, 0x18($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X18);
    // 0x80006248: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000624C: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80006250: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006254: slti        $at, $t8, 0x4
        ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
            goto L_80006260;
    }
    // 0x80006254: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80006258: bne         $at, $zero, L_80006234
    if (ctx->r1 != 0) {
        // 0x8000625C: nop
    
            goto L_80006234;
    }
    // 0x8000625C: nop

L_80006260:
    // 0x80006260: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006264: bne         $v0, $at, L_8000627C
    if (ctx->r2 != ctx->r1) {
        // 0x80006268: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000627C;
    }
    // 0x80006268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000626C: addu        $t3, $v1, $v0
    ctx->r11 = ADD32(ctx->r3, ctx->r2);
    // 0x80006270: lbu         $t0, 0x2C($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X2C);
    // 0x80006274: b           L_8000638C
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_8000638C;
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000627C:
    // 0x8000627C: beq         $a1, $zero, L_80006290
    if (ctx->r5 == 0) {
        // 0x80006280: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_80006290;
    }
    // 0x80006280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006284: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80006288: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8000628C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80006290:
    // 0x80006290: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006294: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006298: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8000629C: lhu         $a2, 0x18($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X18);
    // 0x800062A0: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x800062A4: lhu         $t4, 0x1A($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1A);
    // 0x800062A8: subu        $t8, $a0, $a2
    ctx->r24 = SUB32(ctx->r4, ctx->r6);
    // 0x800062AC: subu        $t3, $t4, $a2
    ctx->r11 = SUB32(ctx->r12, ctx->r6);
    // 0x800062B0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800062B4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062B8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800062BC: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x800062C0: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x800062C4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062C8: lbu         $a3, 0x2C($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X2C);
    // 0x800062CC: lbu         $t7, 0x2D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2D);
    // 0x800062D0: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800062D4: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x800062D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062DC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800062E0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062E4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800062E8: bgez        $a3, L_800062FC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800062EC: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800062FC;
    }
    // 0x800062EC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800062F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800062F4: nop

    // 0x800062F8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800062FC:
    // 0x800062FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006304: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80006308: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000630C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006310: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80006314: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006318: nop

    // 0x8000631C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006320: beq         $t0, $zero, L_8000636C
    if (ctx->r8 == 0) {
        // 0x80006324: nop
    
            goto L_8000636C;
    }
    // 0x80006324: nop

    // 0x80006328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000632C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006330: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006338: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000633C: nop

    // 0x80006340: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006344: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006348: nop

    // 0x8000634C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006350: bne         $t0, $zero, L_80006364
    if (ctx->r8 != 0) {
        // 0x80006354: nop
    
            goto L_80006364;
    }
    // 0x80006354: nop

    // 0x80006358: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000635C: b           L_8000637C
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8000637C;
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80006364:
    // 0x80006364: b           L_8000637C
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8000637C;
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8000636C:
    // 0x8000636C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006370: nop

    // 0x80006374: bltz        $t0, L_80006364
    if (SIGNED(ctx->r8) < 0) {
        // 0x80006378: nop
    
            goto L_80006364;
    }
    // 0x80006378: nop

L_8000637C:
    // 0x8000637C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80006380: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80006384: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80006388: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000638C:
    // 0x8000638C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006390: bgez        $t0, L_800063A8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80006394: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800063A8;
    }
    // 0x80006394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006398: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000639C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800063A0: nop

    // 0x800063A4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800063A8:
    // 0x800063A8: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800063AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800063B0: div.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800063B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800063B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800063BC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800063C0: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
    // 0x800063C4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800063C8: nop

    // 0x800063CC: swc1        $f6, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f6.u32l;
    // 0x800063D0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800063D4: nop

    // 0x800063D8: swc1        $f10, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f10.u32l;
    // 0x800063DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800063E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800063E4: jr          $ra
    // 0x800063E8: nop

    return;
    // 0x800063E8: nop

;}
RECOMP_FUNC void racer_sound_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800063F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800063F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800063F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800063FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80006400: jal         0x8001139C
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80006408: bne         $v0, $zero, L_80006448
    if (ctx->r2 != 0) {
        // 0x8000640C: nop
    
            goto L_80006448;
    }
    // 0x8000640C: nop

    // 0x80006410: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80006414: nop

    // 0x80006418: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000641C: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80006420: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006424: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80006428: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000642C: nop

    // 0x80006430: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006434: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006438: jal         0x800CA030
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006440: b           L_80006450
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_80006450;
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_80006448:
    // 0x80006448: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000644C: nop

L_80006450:
    // 0x80006450: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006458: nop

    // 0x8000645C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80006460: nop

    // 0x80006464: bc1f        L_800064B8
    if (!c1cs) {
        // 0x80006468: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800064B8;
    }
    // 0x80006468: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000646C: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006470: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006474: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006478: lbu         $t6, 0x37($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X37);
    // 0x8000647C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006480: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80006484: bgez        $t6, L_80006498
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80006488: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80006498;
    }
    // 0x80006488: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000648C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006490: nop

    // 0x80006494: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80006498:
    // 0x80006498: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8000649C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800064A0: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800064A4: nop

    // 0x800064A8: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064AC: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800064B0: b           L_800066FC
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
        goto L_800066FC;
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
L_800064B8:
    // 0x800064B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800064BC: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x800064C0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800064C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800064C8: lwc1        $f6, 0x5208($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5208);
    // 0x800064CC: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800064D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800064D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800064DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800064E0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800064E4: nop

    // 0x800064E8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800064EC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800064F0: nop

    // 0x800064F4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800064F8: beq         $a1, $zero, L_80006544
    if (ctx->r5 == 0) {
        // 0x800064FC: nop
    
            goto L_80006544;
    }
    // 0x800064FC: nop

    // 0x80006500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006508: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000650C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006510: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80006514: nop

    // 0x80006518: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000651C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80006520: nop

    // 0x80006524: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80006528: bne         $a1, $zero, L_8000653C
    if (ctx->r5 != 0) {
        // 0x8000652C: nop
    
            goto L_8000653C;
    }
    // 0x8000652C: nop

    // 0x80006530: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006534: b           L_80006554
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80006554;
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_8000653C:
    // 0x8000653C: b           L_80006554
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80006554;
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80006544:
    // 0x80006544: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006548: nop

    // 0x8000654C: bltz        $a1, L_8000653C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006550: nop
    
            goto L_8000653C;
    }
    // 0x80006550: nop

L_80006554:
    // 0x80006554: lhu         $t9, 0x18($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X18);
    // 0x80006558: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x8000655C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80006560: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80006564: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x80006568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006598;
    }
    // 0x80006568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000656C:
    // 0x8000656C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006570: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80006574: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80006578: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8000657C: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x80006580: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80006584: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80006588: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x8000658C: slti        $at, $t2, 0x4
        ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
            goto L_80006598;
    }
    // 0x8000658C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80006590: bne         $at, $zero, L_8000656C
    if (ctx->r1 != 0) {
        // 0x80006594: nop
    
            goto L_8000656C;
    }
    // 0x80006594: nop

L_80006598:
    // 0x80006598: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000659C: bne         $v0, $at, L_800065B4
    if (ctx->r2 != ctx->r1) {
        // 0x800065A0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800065B4;
    }
    // 0x800065A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800065A4: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800065A8: lbu         $t0, 0x2C($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2C);
    // 0x800065AC: b           L_800066C4
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
        goto L_800066C4;
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800065B4:
    // 0x800065B4: beq         $a1, $zero, L_800065C8
    if (ctx->r5 == 0) {
        // 0x800065B8: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_800065C8;
    }
    // 0x800065B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800065BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800065C0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x800065C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800065C8:
    // 0x800065C8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800065CC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800065D0: sll         $t3, $a1, 1
    ctx->r11 = S32(ctx->r5 << 1);
    // 0x800065D4: lhu         $a2, 0x18($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X18);
    // 0x800065D8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800065DC: lhu         $t5, 0x1A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1A);
    // 0x800065E0: subu        $t2, $a0, $a2
    ctx->r10 = SUB32(ctx->r4, ctx->r6);
    // 0x800065E4: subu        $t6, $t5, $a2
    ctx->r14 = SUB32(ctx->r13, ctx->r6);
    // 0x800065E8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800065EC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800065F0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800065F4: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x800065F8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800065FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006600: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80006604: lbu         $t9, 0x2D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2D);
    // 0x80006608: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000660C: subu        $t2, $t9, $a3
    ctx->r10 = SUB32(ctx->r25, ctx->r7);
    // 0x80006610: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80006614: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80006618: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000661C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80006620: bgez        $a3, L_80006634
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80006624: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80006634;
    }
    // 0x80006624: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000662C: nop

    // 0x80006630: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80006634:
    // 0x80006634: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000663C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80006640: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006644: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006648: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000664C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006650: nop

    // 0x80006654: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006658: beq         $t0, $zero, L_800066A4
    if (ctx->r8 == 0) {
        // 0x8000665C: nop
    
            goto L_800066A4;
    }
    // 0x8000665C: nop

    // 0x80006660: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006664: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006668: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000666C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006670: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006674: nop

    // 0x80006678: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000667C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006680: nop

    // 0x80006684: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006688: bne         $t0, $zero, L_8000669C
    if (ctx->r8 != 0) {
        // 0x8000668C: nop
    
            goto L_8000669C;
    }
    // 0x8000668C: nop

    // 0x80006690: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006694: b           L_800066B4
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800066B4;
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8000669C:
    // 0x8000669C: b           L_800066B4
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800066B4;
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800066A4:
    // 0x800066A4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800066A8: nop

    // 0x800066AC: bltz        $t0, L_8000669C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800066B0: nop
    
            goto L_8000669C;
    }
    // 0x800066B0: nop

L_800066B4:
    // 0x800066B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800066B8: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x800066BC: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x800066C0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800066C4:
    // 0x800066C4: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800066C8: bgez        $t0, L_800066E0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800066CC: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800066E0;
    }
    // 0x800066CC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800066D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800066D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800066D8: nop

    // 0x800066DC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800066E0:
    // 0x800066E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800066E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800066E8: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800066EC: nop

    // 0x800066F0: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800066F4: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800066F8: swc1        $f4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f4.u32l;
L_800066FC:
    // 0x800066FC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006700: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80006704: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80006708: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000670C: beq         $t6, $zero, L_80006778
    if (ctx->r14 == 0) {
        // 0x80006710: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80006778;
    }
    // 0x80006710: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006714: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80006718: lwc1        $f10, 0xB0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x8000671C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80006720: nop

    // 0x80006724: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006728: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000672C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006730: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006734: swc1        $f10, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f10.u32l;
    // 0x80006738: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000673C: nop

    // 0x80006740: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80006744: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80006748: nop

    // 0x8000674C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006750: nop

    // 0x80006754: bc1f        L_800067A8
    if (!c1cs) {
        // 0x80006758: nop
    
            goto L_800067A8;
    }
    // 0x80006758: nop

    // 0x8000675C: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80006760: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006764: nop

    // 0x80006768: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000676C: b           L_800067AC
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_800067AC;
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80006774: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80006778:
    // 0x80006778: lwc1        $f8, 0xB4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8000677C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80006780: nop

    // 0x80006784: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006788: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000678C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80006790: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80006794: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80006798: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000679C: nop

    // 0x800067A0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800067A4: nop

L_800067A8:
    // 0x800067A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800067AC:
    // 0x800067AC: nop

    // 0x800067B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800067B4: nop

    // 0x800067B8: bc1f        L_800067C4
    if (!c1cs) {
        // 0x800067BC: nop
    
            goto L_800067C4;
    }
    // 0x800067BC: nop

    // 0x800067C0: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_800067C4:
    // 0x800067C4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800067C8: jal         0x800A06D0
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_2;
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800067D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800067D4: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800067D8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800067DC: bne         $v0, $zero, L_800067F4
    if (ctx->r2 != 0) {
        // 0x800067E0: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_800067F4;
    }
    // 0x800067E0: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x800067E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800067E8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800067EC: nop

    // 0x800067F0: swc1        $f4, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f4.u32l;
L_800067F4:
    // 0x800067F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800067F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800067FC: lwc1        $f6, 0xA4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XA4);
    // 0x80006800: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    // 0x80006804: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80006808: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8000680C: jal         0x80070A04
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80006814: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80006818: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8000681C: lh          $a0, 0x4($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X4);
    // 0x80006820: jal         0x80070A04
    // 0x80006824: nop

    sins_f(rdram, ctx);
        goto after_4;
    // 0x80006824: nop

    after_4:
    // 0x80006828: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000682C: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006830: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006834: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80006838: lwc1        $f10, 0xC4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8000683C: lwc1        $f4, 0xC0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x80006840: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006844: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006848: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000684C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80006850: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80006854: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80006858: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000685C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80006860: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80006864: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80006868: bc1f        L_80006874
    if (!c1cs) {
        // 0x8000686C: cvt.d.s     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
            goto L_80006874;
    }
    // 0x8000686C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80006870: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80006874:
    // 0x80006874: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80006878: add.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8000687C: bc1f        L_80006890
    if (!c1cs) {
        // 0x80006880: add.s       $f14, $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
            goto L_80006890;
    }
    // 0x80006880: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80006884: sub.d       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f0.d - ctx->f16.d;
    // 0x80006888: b           L_80006898
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80006898;
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80006890:
    // 0x80006890: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80006894: nop

L_80006898:
    // 0x80006898: lwc1        $f4, 0xCC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x8000689C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800068A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800068A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800068A8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800068AC: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x800068B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068B4: bc1t        L_80006980
    if (c1cs) {
        // 0x800068B8: add.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_80006980;
    }
    // 0x800068B8: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800068BC: lw          $t5, -0x5E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E44);
    // 0x800068C0: nop

    // 0x800068C4: lb          $v0, 0x185($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X185);
    // 0x800068C8: nop

    // 0x800068CC: beq         $v0, $zero, L_80006980
    if (ctx->r2 == 0) {
        // 0x800068D0: nop
    
            goto L_80006980;
    }
    // 0x800068D0: nop

    // 0x800068D4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800068D8: beq         $at, $zero, L_800068E8
    if (ctx->r1 == 0) {
        // 0x800068DC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800068E8;
    }
    // 0x800068DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800068E0: b           L_800068E8
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800068E8;
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800068E8:
    // 0x800068E8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800068EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068F0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800068F4: lwc1        $f5, 0x5210($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5210);
    // 0x800068F8: lwc1        $f4, 0x5214($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5214);
    // 0x800068FC: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006900: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80006904: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006908: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x8000690C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006910: nop

    // 0x80006914: bc1f        L_80006950
    if (!c1cs) {
        // 0x80006918: nop
    
            goto L_80006950;
    }
    // 0x80006918: nop

    // 0x8000691C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80006920: nop

    // 0x80006924: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006928: nop

    // 0x8000692C: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006930: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x80006934: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006938: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8000693C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006940: nop

    // 0x80006944: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006948: b           L_800069B0
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006950:
    // 0x80006950: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80006954: nop

    // 0x80006958: bc1f        L_80006978
    if (!c1cs) {
        // 0x8000695C: nop
    
            goto L_80006978;
    }
    // 0x8000695C: nop

    // 0x80006960: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80006964: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006968: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000696C: nop

    // 0x80006970: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006974: nop

L_80006978:
    // 0x80006978: b           L_800069B0
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006980:
    // 0x80006980: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006984: lwc1        $f9, 0x5218($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5218);
    // 0x80006988: lwc1        $f8, 0x521C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X521C);
    // 0x8000698C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006990: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006994: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80006998: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x8000699C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069A0: nop

    // 0x800069A4: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800069A8: nop

    // 0x800069AC: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800069B0:
    // 0x800069B0: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800069B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800069BC: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800069C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069C4: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800069C8: add.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800069CC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x800069D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069D4: lwc1        $f8, 0x5224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5224);
    // 0x800069D8: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069DC: lwc1        $f9, 0x5220($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5220);
    // 0x800069E0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800069E4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x800069E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069EC: bc1f        L_80006A08
    if (!c1cs) {
        // 0x800069F0: nop
    
            goto L_80006A08;
    }
    // 0x800069F0: nop

    // 0x800069F4: lwc1        $f10, 0x5228($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5228);
    // 0x800069F8: nop

    // 0x800069FC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x80006A00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A04: nop

L_80006A08:
    // 0x80006A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006A0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006A10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80006A14: swc1        $f6, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f6.u32l;
    // 0x80006A18: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80006A1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006A20: swc1        $f8, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f8.u32l;
    // 0x80006A24: lw          $v0, -0x5E44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E44);
    // 0x80006A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80006A2C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80006A30: nop

    // 0x80006A34: beq         $t8, $at, L_80006A7C
    if (ctx->r24 == ctx->r1) {
        // 0x80006A38: nop
    
            goto L_80006A7C;
    }
    // 0x80006A38: nop

    // 0x80006A3C: lb          $t9, 0x1DB($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A40: nop

    // 0x80006A44: beq         $t9, $zero, L_80006A7C
    if (ctx->r25 == 0) {
        // 0x80006A48: nop
    
            goto L_80006A7C;
    }
    // 0x80006A48: nop

    // 0x80006A4C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80006A54: lbu         $t2, 0xD8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XD8);
    // 0x80006A58: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    // 0x80006A5C: bne         $t2, $zero, L_80006A7C
    if (ctx->r10 != 0) {
        // 0x80006A60: nop
    
            goto L_80006A7C;
    }
    // 0x80006A60: nop

    // 0x80006A64: sb          $t3, 0xD8($v1)
    MEM_B(0XD8, ctx->r3) = ctx->r11;
    // 0x80006A68: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80006A6C: jal         0x80001D04
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    after_5:
    // 0x80006A74: b           L_80006ABC
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006ABC;
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A7C:
    // 0x80006A7C: lb          $t4, 0x1DB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A80: nop

    // 0x80006A84: bne         $t4, $zero, L_80006ABC
    if (ctx->r12 != 0) {
        // 0x80006A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006A8C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80006A90: nop

    // 0x80006A94: sb          $zero, 0xD8($t5)
    MEM_B(0XD8, ctx->r13) = 0;
    // 0x80006A98: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80006A9C: nop

    // 0x80006AA0: lw          $a0, 0xDC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XDC);
    // 0x80006AA4: nop

    // 0x80006AA8: beq         $a0, $zero, L_80006ABC
    if (ctx->r4 == 0) {
        // 0x80006AAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006AB0: jal         0x8000488C
    // 0x80006AB4: nop

    sndp_stop(rdram, ctx);
        goto after_6;
    // 0x80006AB4: nop

    after_6:
    // 0x80006AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006ABC:
    // 0x80006ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006AC0: jr          $ra
    // 0x80006AC4: nop

    return;
    // 0x80006AC4: nop

;}
RECOMP_FUNC void racer_sound_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006ACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006ADC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80006AE0: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80006AE4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80006AE8: lw          $a1, 0x118($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X118);
    // 0x80006AEC: addiu       $s2, $s2, -0x5E48
    ctx->r18 = ADD32(ctx->r18, -0X5E48);
    // 0x80006AF0: beq         $a1, $zero, L_80006BE4
    if (ctx->r5 == 0) {
        // 0x80006AF4: sw          $a1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r5;
            goto L_80006BE4;
    }
    // 0x80006AF4: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // 0x80006AF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80006AFC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80006B00: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
L_80006B04:
    // 0x80006B04: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x80006B08: nop

    // 0x80006B0C: beq         $a0, $zero, L_80006B34
    if (ctx->r4 == 0) {
        // 0x80006B10: nop
    
            goto L_80006B34;
    }
    // 0x80006B10: nop

    // 0x80006B14: jal         0x8000488C
    // 0x80006B18: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80006B18: nop

    after_0:
    // 0x80006B1C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80006B20: nop

    // 0x80006B24: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80006B28: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x80006B2C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B30: nop

L_80006B34:
    // 0x80006B34: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80006B38: bne         $s0, $s1, L_80006B04
    if (ctx->r16 != ctx->r17) {
        // 0x80006B3C: addu        $t9, $a1, $s0
        ctx->r25 = ADD32(ctx->r5, ctx->r16);
            goto L_80006B04;
    }
    // 0x80006B3C: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
    // 0x80006B40: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x80006B44: nop

    // 0x80006B48: beq         $a0, $zero, L_80006B6C
    if (ctx->r4 == 0) {
        // 0x80006B4C: nop
    
            goto L_80006B6C;
    }
    // 0x80006B4C: nop

    // 0x80006B50: jal         0x8000488C
    // 0x80006B54: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x80006B54: nop

    after_1:
    // 0x80006B58: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80006B5C: nop

    // 0x80006B60: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x80006B64: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B68: nop

L_80006B6C:
    // 0x80006B6C: lw          $a0, 0xA8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XA8);
    // 0x80006B70: nop

    // 0x80006B74: beq         $a0, $zero, L_80006B98
    if (ctx->r4 == 0) {
        // 0x80006B78: nop
    
            goto L_80006B98;
    }
    // 0x80006B78: nop

    // 0x80006B7C: jal         0x8000488C
    // 0x80006B80: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80006B80: nop

    after_2:
    // 0x80006B84: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80006B88: nop

    // 0x80006B8C: sw          $zero, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = 0;
    // 0x80006B90: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B94: nop

L_80006B98:
    // 0x80006B98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006B9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80006BA0: addiu       $v1, $v1, -0x5E48
    ctx->r3 = ADD32(ctx->r3, -0X5E48);
    // 0x80006BA4: addiu       $v0, $v0, -0x5E50
    ctx->r2 = ADD32(ctx->r2, -0X5E50);
L_80006BA8:
    // 0x80006BA8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80006BAC: nop

    // 0x80006BB0: bne         $a1, $t4, L_80006BBC
    if (ctx->r5 != ctx->r12) {
        // 0x80006BB4: nop
    
            goto L_80006BBC;
    }
    // 0x80006BB4: nop

    // 0x80006BB8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80006BBC:
    // 0x80006BBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80006BC0: bne         $v0, $v1, L_80006BA8
    if (ctx->r2 != ctx->r3) {
        // 0x80006BC4: nop
    
            goto L_80006BA8;
    }
    // 0x80006BC4: nop

    // 0x80006BC8: jal         0x80071380
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80006BD0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80006BD4: nop

    // 0x80006BD8: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x80006BDC: nop

    // 0x80006BE0: sw          $zero, 0x118($t6)
    MEM_W(0X118, ctx->r14) = 0;
L_80006BE4:
    // 0x80006BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006BEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006BF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006BF4: jr          $ra
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void racer_sound_doppler_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006BFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80006C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006C04: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80006C08: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80006C0C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80006C10: lw          $t6, 0x118($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X118);
    // 0x80006C14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006C18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80006C1C: sw          $t6, -0x5E48($at)
    MEM_W(-0X5E48, ctx->r1) = ctx->r14;
    // 0x80006C20: lw          $t7, -0x5E48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E48);
    // 0x80006C24: nop

    // 0x80006C28: beq         $t7, $zero, L_80006FBC
    if (ctx->r15 == 0) {
        // 0x80006C2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006FBC;
    }
    // 0x80006C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006C30: beq         $a1, $zero, L_80006C6C
    if (ctx->r5 == 0) {
        // 0x80006C34: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80006C6C;
    }
    // 0x80006C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006C38: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80006C3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006C40: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80006C44: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80006C48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006C4C: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80006C50: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80006C54: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80006C58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80006C5C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80006C60: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80006C64: b           L_80006D84
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_80006D84;
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_80006C6C:
    // 0x80006C6C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80006C70: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80006C74: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80006C78: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80006C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006C80: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80006C84: lb          $v0, 0x1D6($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1D6);
    // 0x80006C88: nop

    // 0x80006C8C: beq         $v0, $zero, L_80006CA4
    if (ctx->r2 == 0) {
        // 0x80006C90: nop
    
            goto L_80006CA4;
    }
    // 0x80006C90: nop

    // 0x80006C94: beq         $v0, $at, L_80006CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80006C98: nop
    
            goto L_80006CD0;
    }
    // 0x80006C98: nop

    // 0x80006C9C: b           L_80006D0C
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
        goto L_80006D0C;
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006CA4:
    // 0x80006CA4: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80006CA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006CAC: nop

    // 0x80006CB0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80006CB4: nop

    // 0x80006CB8: bc1f        L_80006CC8
    if (!c1cs) {
        // 0x80006CBC: nop
    
            goto L_80006CC8;
    }
    // 0x80006CBC: nop

    // 0x80006CC0: b           L_80006D48
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006CC8:
    // 0x80006CC8: b           L_80006D48
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80006CD0:
    // 0x80006CD0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80006CD4: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006CD8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006CDC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006CE0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006CE4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006CE8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006CEC: jal         0x800CA030
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80006CF4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006CF8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006CFC: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D00: b           L_80006D48
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80006D08: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006D0C:
    // 0x80006D0C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006D10: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006D14: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80006D18: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006D1C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006D20: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006D24: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006D28: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006D2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D30: jal         0x800CA030
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006D38: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006D3C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006D40: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D44: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006D48:
    // 0x80006D48: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006D50: nop

    // 0x80006D54: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006D58: nop

    // 0x80006D5C: bc1f        L_80006D6C
    if (!c1cs) {
        // 0x80006D60: nop
    
            goto L_80006D6C;
    }
    // 0x80006D60: nop

    // 0x80006D64: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80006D68: nop

L_80006D6C:
    // 0x80006D6C: div.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80006D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006D74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006D78: nop

    // 0x80006D7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D80: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_80006D84:
    // 0x80006D84: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80006D88: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80006D8C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80006D90: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80006D94: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80006D98: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D9C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80006DA0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006DA4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006DA8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006DAC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006DB0: nop

    // 0x80006DB4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006DB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006DBC: jal         0x800CA030
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80006DC4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006DC8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80006DCC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80006DD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006DD4: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006DD8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80006DDC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80006DE0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80006DE4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80006DE8: lwc1        $f4, 0x6C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x80006DEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006DF0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006DF8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80006DFC: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80006E00: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80006E04: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006E08: nop

    // 0x80006E0C: bc1f        L_80006E1C
    if (!c1cs) {
        // 0x80006E10: nop
    
            goto L_80006E1C;
    }
    // 0x80006E10: nop

    // 0x80006E14: b           L_80006E38
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_80006E38;
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_80006E1C:
    // 0x80006E1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006E20: nop

    // 0x80006E24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006E28: nop

    // 0x80006E2C: bc1f        L_80006E38
    if (!c1cs) {
        // 0x80006E30: nop
    
            goto L_80006E38;
    }
    // 0x80006E30: nop

    // 0x80006E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006E38:
    // 0x80006E38: lwc1        $f12, 0x5C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006E3C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80006E40: jal         0x80007FA4
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    log_recomp(rdram, ctx);
        goto after_3;
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80006E48: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80006E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80006E50: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80006E54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E58: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80006E5C: lwc1        $f5, 0x5230($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5230);
    // 0x80006E60: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80006E64: nop

    // 0x80006E68: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80006E6C: lwc1        $f4, 0x5234($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5234);
    // 0x80006E70: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80006E74: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80006E78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80006E7C: nop

    // 0x80006E80: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80006E84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006E88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006E8C: nop

    // 0x80006E90: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80006E94: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80006E98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80006E9C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80006EA0: nop

    // 0x80006EA4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006EA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80006EAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80006EB0: nop

    // 0x80006EB4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80006EB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006EBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006EC0: nop

    // 0x80006EC4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006EC8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80006ECC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80006ED0: jal         0x800C9F40
    // 0x80006ED4: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x80006ED4: nop

    after_4:
    // 0x80006ED8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006EDC: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006EE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006EE4: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006EE8: lwc1        $f2, 0x68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006EEC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80006EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006EF4: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80006EF8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006EFC: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F04: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80006F08: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F10: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F14: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80006F18: lwc1        $f10, 0x68($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F1C: nop

    // 0x80006F20: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F24: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    // 0x80006F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F2C: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F30: lwc1        $f10, 0x523C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X523C);
    // 0x80006F34: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F38: lwc1        $f11, 0x5238($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5238);
    // 0x80006F3C: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F40: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80006F44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F48: bc1f        L_80006F70
    if (!c1cs) {
        // 0x80006F4C: nop
    
            goto L_80006F70;
    }
    // 0x80006F4C: nop

    // 0x80006F50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F54: lwc1        $f4, 0x5240($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5240);
    // 0x80006F58: nop

    // 0x80006F5C: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x80006F60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F64: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006F68: b           L_80006FA8
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
        goto L_80006FA8;
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006F70:
    // 0x80006F70: lwc1        $f7, 0x5248($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5248);
    // 0x80006F74: lwc1        $f6, 0x524C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X524C);
    // 0x80006F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F7C: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x80006F80: nop

    // 0x80006F84: bc1f        L_80006FA4
    if (!c1cs) {
        // 0x80006F88: nop
    
            goto L_80006FA4;
    }
    // 0x80006F88: nop

    // 0x80006F8C: lwc1        $f8, 0x5250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5250);
    // 0x80006F90: nop

    // 0x80006F94: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F9C: lw          $v0, -0x5E48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E48);
    // 0x80006FA0: nop

L_80006FA4:
    // 0x80006FA4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006FA8:
    // 0x80006FA8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80006FAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80006FB0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80006FB4: swc1        $f10, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f10.u32l;
    // 0x80006FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006FBC:
    // 0x80006FBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006FC0: jr          $ra
    // 0x80006FC4: nop

    return;
    // 0x80006FC4: nop

;}
RECOMP_FUNC void racer_sound_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FC8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80006FCC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80006FD0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80006FD4: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80006FD8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80006FDC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80006FE0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80006FE4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80006FE8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80006FEC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80006FF0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80006FF4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80006FF8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80006FFC: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80007000: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80007004: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80007008: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8000700C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80007010: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80007014: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80007018: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8000701C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80007020: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80007024: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80007028: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000702C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80007030: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80007034: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x80007038: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x8000703C: blez        $t6, L_80007750
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80007040: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_80007750;
    }
    // 0x80007040: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007048: lwc1        $f30, 0x5254($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5254);
    // 0x8000704C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007050: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80007054: lwc1        $f29, 0x5258($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5258);
    // 0x80007058: lwc1        $f28, 0x525C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X525C);
    // 0x8000705C: mtc1        $zero, $f25
    ctx->f_odd[(25 - 1) * 2] = 0;
    // 0x80007060: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80007064: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007068: addiu       $s4, $s4, -0x5E48
    ctx->r20 = ADD32(ctx->r20, -0X5E48);
    // 0x8000706C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
L_80007070:
    // 0x80007070: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80007074: nop

    // 0x80007078: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x8000707C: nop

    // 0x80007080: beq         $s1, $zero, L_80007094
    if (ctx->r17 == 0) {
        // 0x80007084: nop
    
            goto L_80007094;
    }
    // 0x80007084: nop

    // 0x80007088: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x8000708C: b           L_80007098
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
        goto L_80007098;
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
L_80007094:
    // 0x80007094: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_80007098:
    // 0x80007098: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000709C: nop

    // 0x800070A0: beq         $s0, $zero, L_8000773C
    if (ctx->r16 == 0) {
        // 0x800070A4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070A4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070A8: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x800070AC: nop

    // 0x800070B0: beq         $t0, $zero, L_8000773C
    if (ctx->r8 == 0) {
        // 0x800070B4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070B4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070B8: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x800070BC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800070C0: bne         $t1, $zero, L_800070DC
    if (ctx->r9 != 0) {
        // 0x800070C4: lw          $t2, 0xAC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XAC);
            goto L_800070DC;
    }
    // 0x800070C4: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800070C8: jal         0x80066750
    // 0x800070CC: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800070CC: nop

    after_0:
    // 0x800070D0: beq         $v0, $zero, L_800071F0
    if (ctx->r2 == 0) {
        // 0x800070D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800071F0;
    }
    // 0x800070D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800070D8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
L_800070DC:
    // 0x800070DC: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x800070E0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800070E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800070E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800070EC: addu        $v1, $s7, $t3
    ctx->r3 = ADD32(ctx->r23, ctx->r11);
    // 0x800070F0: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800070F4: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800070F8: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800070FC: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80007100: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80007104: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80007108: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000710C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80007110: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x80007114: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80007118: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8000711C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80007120: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007124: jal         0x80006BFC
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_1;
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    after_1:
    // 0x8000712C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80007130: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80007134: nop

    // 0x80007138: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000713C: nop

    // 0x80007140: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80007144: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80007148: jal         0x800CA030
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80007150: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007154: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80007158: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x8000715C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007164: lwc1        $f16, 0x5260($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5260);
    // 0x80007168: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8000716C: nop

    // 0x80007170: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80007174: nop

    // 0x80007178: bc1f        L_800071C0
    if (!c1cs) {
        // 0x8000717C: nop
    
            goto L_800071C0;
    }
    // 0x8000717C: nop

    // 0x80007180: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80007184: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80007188: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000718C: sub.s       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f18.fl;
    // 0x80007190: nop

    // 0x80007194: div.s       $f26, $f4, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80007198: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000719C: mul.s       $f26, $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800071A0: jal         0x800090C0
    // 0x800071A4: nop

    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_3;
    // 0x800071A4: nop

    after_3:
    // 0x800071A8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800071AC: nop

    // 0x800071B0: sb          $v0, 0x91($t5)
    MEM_B(0X91, ctx->r13) = ctx->r2;
    // 0x800071B4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800071B8: b           L_800071CC
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
        goto L_800071CC;
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071C0:
    // 0x800071C0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800071C4: nop

    // 0x800071C8: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071CC:
    // 0x800071CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800071D0: bne         $t6, $zero, L_80007214
    if (ctx->r14 != 0) {
        // 0x800071D4: nop
    
            goto L_80007214;
    }
    // 0x800071D4: nop

    // 0x800071D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800071DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800071E0: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x800071E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800071E8: b           L_80007214
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
        goto L_80007214;
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
L_800071F0:
    // 0x800071F0: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800071F4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800071F8: sb          $t7, 0x91($t8)
    MEM_B(0X91, ctx->r24) = ctx->r15;
    // 0x800071FC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007200: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80007204: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80007208: swc1        $f16, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->f16.u32l;
    // 0x8000720C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007210: nop

L_80007214:
    // 0x80007214: lbu         $v0, 0xA0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA0);
    // 0x80007218: nop

    // 0x8000721C: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80007220: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x80007224: nop
    
            goto L_80007498;
    }
    // 0x80007224: nop

    // 0x80007228: lbu         $a0, 0x36($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X36);
    // 0x8000722C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80007230: beq         $a0, $zero, L_80007498
    if (ctx->r4 == 0) {
        // 0x80007234: slti        $at, $t0, 0x3
        ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
            goto L_80007498;
    }
    // 0x80007234: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80007238: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x8000723C: nop
    
            goto L_80007498;
    }
    // 0x8000723C: nop

    // 0x80007240: cvt.d.s     $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f18.d = CVT_D_S(ctx->f26.fl);
    // 0x80007244: c.eq.d      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.d == ctx->f18.d;
    // 0x80007248: nop

    // 0x8000724C: bc1t        L_80007498
    if (c1cs) {
        // 0x80007250: nop
    
            goto L_80007498;
    }
    // 0x80007250: nop

    // 0x80007254: lbu         $t1, 0x44($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X44);
    // 0x80007258: nop

    // 0x8000725C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80007260: bne         $t2, $zero, L_80007498
    if (ctx->r10 != 0) {
        // 0x80007264: nop
    
            goto L_80007498;
    }
    // 0x80007264: nop

    // 0x80007268: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000726C: bgez        $v0, L_80007284
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007270: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80007284;
    }
    // 0x80007270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80007274: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000727C: nop

    // 0x80007280: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80007284:
    // 0x80007284: lbu         $t3, 0x37($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X37);
    // 0x80007288: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8000728C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80007290: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80007294: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80007298: bgez        $t3, L_800072B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000729C: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800072B0;
    }
    // 0x8000729C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800072A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800072A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800072A8: nop

    // 0x800072AC: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_800072B0:
    // 0x800072B0: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800072B4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800072BC: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800072C0: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800072C4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800072C8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072CC: nop

    // 0x800072D0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800072D4: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800072D8: nop

    // 0x800072DC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800072E0: beq         $s2, $zero, L_8000732C
    if (ctx->r18 == 0) {
        // 0x800072E4: nop
    
            goto L_8000732C;
    }
    // 0x800072E4: nop

    // 0x800072E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800072EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072F0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800072F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800072F8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072FC: nop

    // 0x80007300: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80007304: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x80007308: nop

    // 0x8000730C: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007310: bne         $s2, $zero, L_80007324
    if (ctx->r18 != 0) {
        // 0x80007314: nop
    
            goto L_80007324;
    }
    // 0x80007314: nop

    // 0x80007318: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x8000731C: b           L_8000733C
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_8000733C;
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007324:
    // 0x80007324: b           L_8000733C
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_8000733C;
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8000732C:
    // 0x8000732C: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x80007330: nop

    // 0x80007334: bltz        $s2, L_80007324
    if (SIGNED(ctx->r18) < 0) {
        // 0x80007338: nop
    
            goto L_80007324;
    }
    // 0x80007338: nop

L_8000733C:
    // 0x8000733C: andi        $s3, $s2, 0xFF
    ctx->r19 = ctx->r18 & 0XFF;
    // 0x80007340: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80007344: slti        $at, $s3, 0x10
    ctx->r1 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80007348: bne         $at, $zero, L_80007468
    if (ctx->r1 != 0) {
        // 0x8000734C: nop
    
            goto L_80007468;
    }
    // 0x8000734C: nop

    // 0x80007350: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80007354: nop

    // 0x80007358: bne         $t6, $zero, L_80007370
    if (ctx->r14 != 0) {
        // 0x8000735C: nop
    
            goto L_80007370;
    }
    // 0x8000735C: nop

    // 0x80007360: jal         0x80001F14
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    after_4:
    // 0x80007368: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000736C: nop

L_80007370:
    // 0x80007370: lbu         $t7, 0x38($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X38);
    // 0x80007374: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007378: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8000737C: bgez        $t7, L_80007390
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80007380: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80007390;
    }
    // 0x80007380: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80007384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80007388: nop

    // 0x8000738C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80007390:
    // 0x80007390: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x80007394: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80007398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000739C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800073A0: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800073A4: bgez        $t8, L_800073BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800073A8: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800073BC;
    }
    // 0x800073A8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800073AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800073B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800073B4: nop

    // 0x800073B8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800073BC:
    // 0x800073BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800073C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800073C4: nop

    // 0x800073C8: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800073CC: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800073D0: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800073D4: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800073D8: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800073DC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800073E0: nop

    // 0x800073E4: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800073E8: nop
    
            goto L_800074C4;
    }
    // 0x800073E8: nop

    // 0x800073EC: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x800073F0: nop

    // 0x800073F4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800073F8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800073FC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007400: jal         0x80009B7C
    // 0x80007404: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_5;
    // 0x80007404: nop

    after_5:
    // 0x80007408: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000740C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007410: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80007414: jal         0x800049F8
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_6:
    // 0x8000741C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007420: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80007424: lw          $a0, 0x50($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X50);
    // 0x80007428: jal         0x800049F8
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_7;
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x80007430: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007434: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80007438: lw          $a0, 0x50($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X50);
    // 0x8000743C: jal         0x80004604
    // 0x80007440: nop

    sndp_set_priority(rdram, ctx);
        goto after_8;
    // 0x80007440: nop

    after_8:
    // 0x80007444: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000744C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80007450: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x80007454: jal         0x800049F8
    // 0x80007458: nop

    sndp_set_param(rdram, ctx);
        goto after_9;
    // 0x80007458: nop

    after_9:
    // 0x8000745C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007460: b           L_800074C8
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007468:
    // 0x80007468: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000746C: nop

    // 0x80007470: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x80007474: nop
    
            goto L_800074C4;
    }
    // 0x80007474: nop

    // 0x80007478: jal         0x8000488C
    // 0x8000747C: nop

    sndp_stop(rdram, ctx);
        goto after_10;
    // 0x8000747C: nop

    after_10:
    // 0x80007480: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80007484: nop

    // 0x80007488: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x8000748C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007490: b           L_800074C8
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007498:
    // 0x80007498: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000749C: nop

    // 0x800074A0: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800074A4: nop
    
            goto L_800074C4;
    }
    // 0x800074A4: nop

    // 0x800074A8: jal         0x8000488C
    // 0x800074AC: nop

    sndp_stop(rdram, ctx);
        goto after_11;
    // 0x800074AC: nop

    after_11:
    // 0x800074B0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800074B4: nop

    // 0x800074B8: sw          $zero, 0x50($t3)
    MEM_W(0X50, ctx->r11) = 0;
    // 0x800074BC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800074C0: nop

L_800074C4:
    // 0x800074C4: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_800074C8:
    // 0x800074C8: nop

    // 0x800074CC: beq         $t4, $zero, L_8000773C
    if (ctx->r12 == 0) {
        // 0x800074D0: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800074D0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800074D4: cvt.d.s     $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f20.d = CVT_D_S(ctx->f26.fl);
    // 0x800074D8: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x800074DC: sll         $s1, $s5, 2
    ctx->r17 = S32(ctx->r21 << 2);
    // 0x800074E0: bc1t        L_80007738
    if (c1cs) {
        // 0x800074E4: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_80007738;
    }
    // 0x800074E4: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_800074E8:
    // 0x800074E8: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800074EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800074F0: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800074F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800074F8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800074FC: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007500: nop

    // 0x80007504: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80007508: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000750C: nop

    // 0x80007510: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007514: beq         $s2, $zero, L_80007560
    if (ctx->r18 == 0) {
        // 0x80007518: nop
    
            goto L_80007560;
    }
    // 0x80007518: nop

    // 0x8000751C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80007520: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80007524: sub.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80007528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000752C: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007530: nop

    // 0x80007534: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007538: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000753C: nop

    // 0x80007540: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007544: bne         $s2, $zero, L_80007558
    if (ctx->r18 != 0) {
        // 0x80007548: nop
    
            goto L_80007558;
    }
    // 0x80007548: nop

    // 0x8000754C: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007550: b           L_80007570
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_80007570;
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007558:
    // 0x80007558: b           L_80007570
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_80007570;
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80007560:
    // 0x80007560: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007564: nop

    // 0x80007568: bltz        $s2, L_80007558
    if (SIGNED(ctx->r18) < 0) {
        // 0x8000756C: nop
    
            goto L_80007558;
    }
    // 0x8000756C: nop

L_80007570:
    // 0x80007570: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007574: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80007578: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000757C: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80007580: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007584: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007588: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8000758C: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80007590: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80007594: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80007598: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8000759C: c.lt.d      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.d < ctx->f28.d;
    // 0x800075A0: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800075A4: bc1f        L_800075B8
    if (!c1cs) {
        // 0x800075A8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800075B8;
    }
    // 0x800075A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800075AC: lwc1        $f16, 0x5264($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5264);
    // 0x800075B0: nop

    // 0x800075B4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
L_800075B8:
    // 0x800075B8: bne         $s5, $zero, L_800075F8
    if (ctx->r21 != 0) {
        // 0x800075BC: nop
    
            goto L_800075F8;
    }
    // 0x800075BC: nop

    // 0x800075C0: lbu         $t7, 0x44($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X44);
    // 0x800075C4: nop

    // 0x800075C8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800075CC: beq         $t8, $zero, L_800075F8
    if (ctx->r24 == 0) {
        // 0x800075D0: nop
    
            goto L_800075F8;
    }
    // 0x800075D0: nop

    // 0x800075D4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x800075D8: nop

    // 0x800075DC: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x800075E0: nop
    
            goto L_800076FC;
    }
    // 0x800075E0: nop

    // 0x800075E4: jal         0x8000488C
    // 0x800075E8: nop

    sndp_stop(rdram, ctx);
        goto after_12;
    // 0x800075E8: nop

    after_12:
    // 0x800075EC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800075F0: b           L_800076FC
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
        goto L_800076FC;
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
L_800075F8:
    // 0x800075F8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x800075FC: nop

    // 0x80007600: beq         $a0, $zero, L_8000762C
    if (ctx->r4 == 0) {
        // 0x80007604: nop
    
            goto L_8000762C;
    }
    // 0x80007604: nop

    // 0x80007608: bne         $s2, $zero, L_8000762C
    if (ctx->r18 != 0) {
        // 0x8000760C: nop
    
            goto L_8000762C;
    }
    // 0x8000760C: nop

    // 0x80007610: jal         0x8000488C
    // 0x80007614: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x80007614: nop

    after_13:
    // 0x80007618: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8000761C: nop

    // 0x80007620: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80007624: b           L_800076FC
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
        goto L_800076FC;
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
L_8000762C:
    // 0x8000762C: bne         $a0, $zero, L_80007658
    if (ctx->r4 != 0) {
        // 0x80007630: sll         $t2, $s5, 1
        ctx->r10 = S32(ctx->r21 << 1);
            goto L_80007658;
    }
    // 0x80007630: sll         $t2, $s5, 1
    ctx->r10 = S32(ctx->r21 << 1);
    // 0x80007634: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80007638: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x8000763C: jal         0x80001F14
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    sound_play_direct(rdram, ctx);
        goto after_14;
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    after_14:
    // 0x80007644: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007648: nop

    // 0x8000764C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80007650: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x80007654: nop

L_80007658:
    // 0x80007658: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x8000765C: nop
    
            goto L_800076FC;
    }
    // 0x8000765C: nop

    // 0x80007660: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x80007664: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80007668: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8000766C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80007670: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007674: jal         0x80009B7C
    // 0x80007678: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_15;
    // 0x80007678: nop

    after_15:
    // 0x8000767C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80007680: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007684: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80007688: lw          $a0, 0x48($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X48);
    // 0x8000768C: jal         0x800049F8
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_16:
    // 0x80007694: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80007698: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8000769C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800076A0: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x800076A4: jal         0x800049F8
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800076AC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800076B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800076B4: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800076B8: lw          $a0, 0x48($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X48);
    // 0x800076BC: jal         0x80004604
    // 0x800076C0: nop

    sndp_set_priority(rdram, ctx);
        goto after_18;
    // 0x800076C0: nop

    after_18:
    // 0x800076C4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800076C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800076CC: beq         $t2, $at, L_800076E0
    if (ctx->r10 == ctx->r1) {
        // 0x800076D0: nop
    
            goto L_800076E0;
    }
    // 0x800076D0: nop

    // 0x800076D4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800076D8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800076DC: sb          $t3, 0x91($t4)
    MEM_B(0X91, ctx->r12) = ctx->r11;
L_800076E0:
    // 0x800076E0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800076E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800076E8: addu        $t5, $s0, $s1
    ctx->r13 = ADD32(ctx->r16, ctx->r17);
    // 0x800076EC: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x800076F0: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x800076F4: jal         0x800049F8
    // 0x800076F8: nop

    sndp_set_param(rdram, ctx);
        goto after_19;
    // 0x800076F8: nop

    after_19:
L_800076FC:
    // 0x800076FC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007700: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80007704: beq         $at, $zero, L_80007738
    if (ctx->r1 == 0) {
        // 0x80007708: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80007738;
    }
    // 0x80007708: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000770C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007710: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80007714: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80007718: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000771C: nop

    // 0x80007720: beq         $t8, $zero, L_8000773C
    if (ctx->r24 == 0) {
        // 0x80007724: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x80007724: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80007728: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x8000772C: nop

    // 0x80007730: bc1f        L_800074E8
    if (!c1cs) {
        // 0x80007734: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_800074E8;
    }
    // 0x80007734: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_80007738:
    // 0x80007738: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_8000773C:
    // 0x8000773C: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80007740: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80007744: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x80007748: bne         $t0, $t1, L_80007070
    if (ctx->r8 != ctx->r9) {
        // 0x8000774C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80007070;
    }
    // 0x8000774C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007750:
    // 0x80007750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007754: lwc1        $f29, 0x5268($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5268);
    // 0x80007758: lwc1        $f28, 0x526C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X526C);
    // 0x8000775C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80007760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007764: lwc1        $f30, 0x5270($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5270);
    // 0x80007768: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000776C: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007770: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80007774: beq         $at, $zero, L_80007F18
    if (ctx->r1 == 0) {
        // 0x80007778: addiu       $s4, $s4, -0x5E48
        ctx->r20 = ADD32(ctx->r20, -0X5E48);
            goto L_80007F18;
    }
    // 0x80007778: addiu       $s4, $s4, -0x5E48
    ctx->r20 = ADD32(ctx->r20, -0X5E48);
    // 0x8000777C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007780: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x80007784: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80007788: beq         $at, $zero, L_800078C0
    if (ctx->r1 == 0) {
        // 0x8000778C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_800078C0;
    }
    // 0x8000778C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007790: subu        $v1, $t4, $t2
    ctx->r3 = SUB32(ctx->r12, ctx->r10);
    // 0x80007794: andi        $t5, $v1, 0x3
    ctx->r13 = ctx->r3 & 0X3;
    // 0x80007798: beq         $t5, $zero, L_800077F0
    if (ctx->r13 == 0) {
        // 0x8000779C: addu        $v0, $t5, $t2
        ctx->r2 = ADD32(ctx->r13, ctx->r10);
            goto L_800077F0;
    }
    // 0x8000779C: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800077A0: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800077A4: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800077A8: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
L_800077AC:
    // 0x800077AC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800077B0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800077B4: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x800077B8: nop

    // 0x800077BC: beq         $s1, $zero, L_800077D8
    if (ctx->r17 == 0) {
        // 0x800077C0: nop
    
            goto L_800077D8;
    }
    // 0x800077C0: nop

    // 0x800077C4: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x800077C8: nop

    // 0x800077CC: beq         $t9, $zero, L_800077D8
    if (ctx->r25 == 0) {
        // 0x800077D0: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_800077D8;
    }
    // 0x800077D0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800077D4: sb          $zero, 0x88($t9)
    MEM_B(0X88, ctx->r25) = 0;
L_800077D8:
    // 0x800077D8: bne         $v0, $s5, L_800077AC
    if (ctx->r2 != ctx->r21) {
        // 0x800077DC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800077AC;
    }
    // 0x800077DC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800077E0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077E4: nop

    // 0x800077E8: beq         $s5, $v1, L_800078C4
    if (ctx->r21 == ctx->r3) {
        // 0x800077EC: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_800078C4;
    }
    // 0x800077EC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800077F0:
    // 0x800077F0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077F4: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x800077F8: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x800077FC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80007800: addu        $v0, $t2, $t0
    ctx->r2 = ADD32(ctx->r10, ctx->r8);
    // 0x80007804: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
L_80007808:
    // 0x80007808: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000780C: nop

    // 0x80007810: lw          $s1, 0x64($t4)
    ctx->r17 = MEM_W(ctx->r12, 0X64);
    // 0x80007814: nop

    // 0x80007818: beq         $s1, $zero, L_80007834
    if (ctx->r17 == 0) {
        // 0x8000781C: nop
    
            goto L_80007834;
    }
    // 0x8000781C: nop

    // 0x80007820: lw          $t5, 0x118($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X118);
    // 0x80007824: nop

    // 0x80007828: beq         $t5, $zero, L_80007834
    if (ctx->r13 == 0) {
        // 0x8000782C: sw          $t5, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r13;
            goto L_80007834;
    }
    // 0x8000782C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x80007830: sb          $zero, 0x88($t5)
    MEM_B(0X88, ctx->r13) = 0;
L_80007834:
    // 0x80007834: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x80007838: nop

    // 0x8000783C: lw          $s1, 0x64($t3)
    ctx->r17 = MEM_W(ctx->r11, 0X64);
    // 0x80007840: nop

    // 0x80007844: beq         $s1, $zero, L_80007860
    if (ctx->r17 == 0) {
        // 0x80007848: nop
    
            goto L_80007860;
    }
    // 0x80007848: nop

    // 0x8000784C: lw          $t6, 0x118($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X118);
    // 0x80007850: nop

    // 0x80007854: beq         $t6, $zero, L_80007860
    if (ctx->r14 == 0) {
        // 0x80007858: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_80007860;
    }
    // 0x80007858: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8000785C: sb          $zero, 0x88($t6)
    MEM_B(0X88, ctx->r14) = 0;
L_80007860:
    // 0x80007860: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x80007864: nop

    // 0x80007868: lw          $s1, 0x64($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X64);
    // 0x8000786C: nop

    // 0x80007870: beq         $s1, $zero, L_8000788C
    if (ctx->r17 == 0) {
        // 0x80007874: nop
    
            goto L_8000788C;
    }
    // 0x80007874: nop

    // 0x80007878: lw          $t8, 0x118($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X118);
    // 0x8000787C: nop

    // 0x80007880: beq         $t8, $zero, L_8000788C
    if (ctx->r24 == 0) {
        // 0x80007884: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_8000788C;
    }
    // 0x80007884: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80007888: sb          $zero, 0x88($t8)
    MEM_B(0X88, ctx->r24) = 0;
L_8000788C:
    // 0x8000788C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80007890: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80007894: lw          $s1, 0x64($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X64);
    // 0x80007898: nop

    // 0x8000789C: beq         $s1, $zero, L_800078B8
    if (ctx->r17 == 0) {
        // 0x800078A0: nop
    
            goto L_800078B8;
    }
    // 0x800078A0: nop

    // 0x800078A4: lw          $t1, 0x118($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X118);
    // 0x800078A8: nop

    // 0x800078AC: beq         $t1, $zero, L_800078B8
    if (ctx->r9 == 0) {
        // 0x800078B0: sw          $t1, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r9;
            goto L_800078B8;
    }
    // 0x800078B0: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x800078B4: sb          $zero, 0x88($t1)
    MEM_B(0X88, ctx->r9) = 0;
L_800078B8:
    // 0x800078B8: bne         $s2, $v0, L_80007808
    if (ctx->r18 != ctx->r2) {
        // 0x800078BC: nop
    
            goto L_80007808;
    }
    // 0x800078BC: nop

L_800078C0:
    // 0x800078C0: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800078C4:
    // 0x800078C4: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x800078C8: blez        $t2, L_80007C28
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800078CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80007C28;
    }
    // 0x800078CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800078D0: lwc1        $f25, 0x5278($at)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r1, 0X5278);
    // 0x800078D4: lwc1        $f24, 0x527C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X527C);
    // 0x800078D8: nop

L_800078DC:
    // 0x800078DC: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800078E0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800078E4: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800078E8: lw          $s1, 0x64($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X64);
    // 0x800078EC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800078F0: beq         $at, $zero, L_80007C10
    if (ctx->r1 == 0) {
        // 0x800078F4: or          $s5, $t4, $zero
        ctx->r21 = ctx->r12 | 0;
            goto L_80007C10;
    }
    // 0x800078F4: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x800078F8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800078FC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80007900: addu        $s2, $t3, $t6
    ctx->r18 = ADD32(ctx->r11, ctx->r14);
L_80007904:
    // 0x80007904: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80007908: nop

    // 0x8000790C: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x80007910: nop

    // 0x80007914: beq         $v0, $zero, L_80007C04
    if (ctx->r2 == 0) {
        // 0x80007918: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007918: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8000791C: lw          $t8, 0x118($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X118);
    // 0x80007920: nop

    // 0x80007924: beq         $t8, $zero, L_80007C00
    if (ctx->r24 == 0) {
        // 0x80007928: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_80007C00;
    }
    // 0x80007928: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8000792C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007930: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80007934: beq         $t1, $zero, L_80007974
    if (ctx->r9 == 0) {
        // 0x80007938: sll         $t0, $t2, 4
        ctx->r8 = S32(ctx->r10 << 4);
            goto L_80007974;
    }
    // 0x80007938: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x8000793C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80007940: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007944: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80007948: addu        $v1, $s7, $t0
    ctx->r3 = ADD32(ctx->r23, ctx->r8);
    // 0x8000794C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80007950: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80007954: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80007958: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000795C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007960: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007964: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007968: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000796C: b           L_800079A0
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
        goto L_800079A0;
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_80007974:
    // 0x80007974: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007978: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x8000797C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80007980: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007984: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007988: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000798C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80007990: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80007994: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007998: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000799C: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_800079A0:
    // 0x800079A0: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800079A4: nop

    // 0x800079A8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800079AC: nop

    // 0x800079B0: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800079B4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800079B8: jal         0x800CA030
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_20:
    // 0x800079C0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800079C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800079C8: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x800079CC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800079D0: lwc1        $f6, 0x5280($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5280);
    // 0x800079D4: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800079D8: nop

    // 0x800079DC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800079E0: nop

    // 0x800079E4: bc1f        L_80007C04
    if (!c1cs) {
        // 0x800079E8: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x800079E8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800079EC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800079F0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800079F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800079F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800079FC: sub.s       $f10, $f30, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x80007A00: nop

    // 0x80007A04: div.s       $f26, $f10, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80007A08: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80007A0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80007A10: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A14: nop

    // 0x80007A18: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007A1C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A20: nop

    // 0x80007A24: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A28: beq         $v0, $zero, L_80007A74
    if (ctx->r2 == 0) {
        // 0x80007A2C: nop
    
            goto L_80007A74;
    }
    // 0x80007A2C: nop

    // 0x80007A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007A38: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80007A3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007A40: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A44: nop

    // 0x80007A48: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80007A4C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A50: nop

    // 0x80007A54: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A58: bne         $v0, $zero, L_80007A6C
    if (ctx->r2 != 0) {
        // 0x80007A5C: nop
    
            goto L_80007A6C;
    }
    // 0x80007A5C: nop

    // 0x80007A60: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A64: b           L_80007A84
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007A84;
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007A6C:
    // 0x80007A6C: b           L_80007A84
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007A84;
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007A74:
    // 0x80007A74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A78: nop

    // 0x80007A7C: bltz        $v0, L_80007A6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007A80: nop
    
            goto L_80007A6C;
    }
    // 0x80007A80: nop

L_80007A84:
    // 0x80007A84: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80007A88: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007A8C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80007A90: bne         $at, $zero, L_80007A9C
    if (ctx->r1 != 0) {
        // 0x80007A94: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80007A9C;
    }
    // 0x80007A94: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80007A98: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80007A9C:
    // 0x80007A9C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007AA0: bgez        $v0, L_80007ABC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007AA4: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_80007ABC;
    }
    // 0x80007AA4: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x80007AA8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80007AAC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80007AB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007AB4: nop

    // 0x80007AB8: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80007ABC:
    // 0x80007ABC: mul.d       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x80007AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AC4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80007AC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80007ACC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007AD0: nop

    // 0x80007AD4: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x80007AD8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007ADC: nop

    // 0x80007AE0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007AE4: beq         $v0, $zero, L_80007B34
    if (ctx->r2 == 0) {
        // 0x80007AE8: nop
    
            goto L_80007B34;
    }
    // 0x80007AE8: nop

    // 0x80007AEC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80007AF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80007AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AF8: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x80007AFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007B00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007B04: nop

    // 0x80007B08: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80007B0C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007B10: nop

    // 0x80007B14: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007B18: bne         $v0, $zero, L_80007B2C
    if (ctx->r2 != 0) {
        // 0x80007B1C: nop
    
            goto L_80007B2C;
    }
    // 0x80007B1C: nop

    // 0x80007B20: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B24: b           L_80007B44
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007B44;
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007B2C:
    // 0x80007B2C: b           L_80007B44
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007B44;
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007B34:
    // 0x80007B34: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B38: nop

    // 0x80007B3C: bltz        $v0, L_80007B2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007B40: nop
    
            goto L_80007B2C;
    }
    // 0x80007B40: nop

L_80007B44:
    // 0x80007B44: lbu         $t8, 0x88($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X88);
    // 0x80007B48: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80007B4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80007B50: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80007B54: beq         $at, $zero, L_80007C04
    if (ctx->r1 == 0) {
        // 0x80007B58: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007B58: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007B5C: sb          $t7, 0x88($s0)
    MEM_B(0X88, ctx->r16) = ctx->r15;
    // 0x80007B60: lh          $a2, 0x0($s7)
    ctx->r6 = MEM_H(ctx->r23, 0X0);
    // 0x80007B64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80007B68: jal         0x800090C0
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_21;
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_21:
    // 0x80007B70: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007B74: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80007B78: sb          $v0, 0x91($t9)
    MEM_B(0X91, ctx->r25) = ctx->r2;
    // 0x80007B7C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007B84: beq         $t1, $zero, L_80007BA4
    if (ctx->r9 == 0) {
        // 0x80007B88: nop
    
            goto L_80007BA4;
    }
    // 0x80007B88: nop

    // 0x80007B8C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007B90: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007B94: jal         0x80006BFC
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_22;
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_22:
    // 0x80007B9C: b           L_80007BB8
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
        goto L_80007BB8;
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BA4:
    // 0x80007BA4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007BA8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007BAC: jal         0x80006BFC
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_23;
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_23:
    // 0x80007BB4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BB8:
    // 0x80007BB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007BBC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80007BC0: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007BC4: nop

    // 0x80007BC8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007BCC: swc1        $f10, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f10.u32l;
    // 0x80007BD0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007BD4: nop

    // 0x80007BD8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80007BDC: nop

    // 0x80007BE0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80007BE4: c.lt.d      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.d < ctx->f28.d;
    // 0x80007BE8: nop

    // 0x80007BEC: bc1f        L_80007C04
    if (!c1cs) {
        // 0x80007BF0: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007BF0: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007BF4: lwc1        $f18, 0x5284($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5284);
    // 0x80007BF8: nop

    // 0x80007BFC: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
L_80007C00:
    // 0x80007C00: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
L_80007C04:
    // 0x80007C04: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007C08: bne         $s5, $t2, L_80007904
    if (ctx->r21 != ctx->r10) {
        // 0x80007C0C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007904;
    }
    // 0x80007C0C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007C10:
    // 0x80007C10: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80007C14: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80007C18: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x80007C1C: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x80007C20: bne         $t4, $t5, L_800078DC
    if (ctx->r12 != ctx->r13) {
        // 0x80007C24: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800078DC;
    }
    // 0x80007C24: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007C28:
    // 0x80007C28: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007C2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007C30: addiu       $s0, $s0, -0x5E48
    ctx->r16 = ADD32(ctx->r16, -0X5E48);
    // 0x80007C34: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
L_80007C38:
    // 0x80007C38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80007C3C: nop

    // 0x80007C40: beq         $v0, $zero, L_80007C90
    if (ctx->r2 == 0) {
        // 0x80007C44: nop
    
            goto L_80007C90;
    }
    // 0x80007C44: nop

    // 0x80007C48: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007C4C: nop

    // 0x80007C50: beq         $a0, $zero, L_80007C90
    if (ctx->r4 == 0) {
        // 0x80007C54: nop
    
            goto L_80007C90;
    }
    // 0x80007C54: nop

    // 0x80007C58: lbu         $t3, 0x88($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X88);
    // 0x80007C5C: nop

    // 0x80007C60: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x80007C64: beq         $at, $zero, L_80007C90
    if (ctx->r1 == 0) {
        // 0x80007C68: nop
    
            goto L_80007C90;
    }
    // 0x80007C68: nop

    // 0x80007C6C: jal         0x8000488C
    // 0x80007C70: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80007C70: nop

    after_24:
    // 0x80007C74: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80007C78: nop

    // 0x80007C7C: sw          $zero, 0x48($t6)
    MEM_W(0X48, ctx->r14) = 0;
    // 0x80007C80: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80007C84: nop

    // 0x80007C88: sb          $zero, 0x74($t7)
    MEM_B(0X74, ctx->r15) = 0;
    // 0x80007C8C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_80007C90:
    // 0x80007C90: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007C94: bne         $s3, $s0, L_80007C38
    if (ctx->r19 != ctx->r16) {
        // 0x80007C98: nop
    
            goto L_80007C38;
    }
    // 0x80007C98: nop

    // 0x80007C9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007CA0: addiu       $a3, $a3, -0x33BC
    ctx->r7 = ADD32(ctx->r7, -0X33BC);
    // 0x80007CA4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80007CA8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80007CAC: slt         $at, $fp, $v0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007CB0: beq         $at, $zero, L_80007CC0
    if (ctx->r1 == 0) {
        // 0x80007CB4: subu        $t8, $v0, $fp
        ctx->r24 = SUB32(ctx->r2, ctx->r30);
            goto L_80007CC0;
    }
    // 0x80007CB4: subu        $t8, $v0, $fp
    ctx->r24 = SUB32(ctx->r2, ctx->r30);
    // 0x80007CB8: b           L_80007CC4
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80007CC4;
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80007CC0:
    // 0x80007CC0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80007CC4:
    // 0x80007CC4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CC8: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x80007CCC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80007CD0: bne         $at, $zero, L_80007E24
    if (ctx->r1 != 0) {
        // 0x80007CD4: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80007E24;
    }
    // 0x80007CD4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80007CD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80007CDC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80007CE0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80007CE4:
    // 0x80007CE4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80007CE8: nop

    // 0x80007CEC: lw          $v0, 0x64($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X64);
    // 0x80007CF0: nop

    // 0x80007CF4: beq         $v0, $zero, L_80007E18
    if (ctx->r2 == 0) {
        // 0x80007CF8: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007CF8: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CFC: lw          $t2, 0x118($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X118);
    // 0x80007D00: nop

    // 0x80007D04: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x80007D08: beq         $t2, $zero, L_80007E14
    if (ctx->r10 == 0) {
        // 0x80007D0C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_80007E14;
    }
    // 0x80007D0C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80007D10: lbu         $t0, 0x74($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X74);
    // 0x80007D14: nop

    // 0x80007D18: bne         $t0, $zero, L_80007E18
    if (ctx->r8 != 0) {
        // 0x80007D1C: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007D1C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007D20: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80007D24: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80007D28: beq         $t4, $zero, L_80007E14
    if (ctx->r12 == 0) {
        // 0x80007D2C: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80007E14;
    }
    // 0x80007D2C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80007D30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007D34: lbu         $a1, 0x88($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X88);
    // 0x80007D38: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
    // 0x80007D3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80007D40:
    // 0x80007D40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007D44: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80007D48: beq         $s1, $zero, L_80007D84
    if (ctx->r17 == 0) {
        // 0x80007D4C: nop
    
            goto L_80007D84;
    }
    // 0x80007D4C: nop

    // 0x80007D50: lbu         $t5, 0x88($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X88);
    // 0x80007D54: nop

    // 0x80007D58: subu        $v0, $a1, $t5
    ctx->r2 = SUB32(ctx->r5, ctx->r13);
    // 0x80007D5C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007D60: beq         $at, $zero, L_80007D90
    if (ctx->r1 == 0) {
        // 0x80007D64: nop
    
            goto L_80007D90;
    }
    // 0x80007D64: nop

    // 0x80007D68: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80007D6C: nop

    // 0x80007D70: bne         $t3, $zero, L_80007D90
    if (ctx->r11 != 0) {
        // 0x80007D74: nop
    
            goto L_80007D90;
    }
    // 0x80007D74: nop

    // 0x80007D78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80007D7C: b           L_80007D90
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80007D90;
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80007D84:
    // 0x80007D84: bne         $at, $zero, L_80007D90
    if (ctx->r1 != 0) {
        // 0x80007D88: nop
    
            goto L_80007D90;
    }
    // 0x80007D88: nop

    // 0x80007D8C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80007D90:
    // 0x80007D90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007D94: bne         $v1, $s6, L_80007D40
    if (ctx->r3 != ctx->r22) {
        // 0x80007D98: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80007D40;
    }
    // 0x80007D98: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007D9C: beq         $a0, $fp, L_80007E14
    if (ctx->r4 == ctx->r30) {
        // 0x80007DA0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80007E14;
    }
    // 0x80007DA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80007DA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80007DA8: addiu       $t7, $t7, -0x5E50
    ctx->r15 = ADD32(ctx->r15, -0X5E50);
    // 0x80007DAC: sb          $s7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r23;
    // 0x80007DB0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80007DB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DB8: nop

    // 0x80007DBC: beq         $v0, $zero, L_80007E08
    if (ctx->r2 == 0) {
        // 0x80007DC0: nop
    
            goto L_80007E08;
    }
    // 0x80007DC0: nop

    // 0x80007DC4: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007DC8: nop

    // 0x80007DCC: beq         $a0, $zero, L_80007E00
    if (ctx->r4 == 0) {
        // 0x80007DD0: addiu       $t2, $zero, 0x3C
        ctx->r10 = ADD32(0, 0X3C);
            goto L_80007E00;
    }
    // 0x80007DD0: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80007DD4: jal         0x8000488C
    // 0x80007DD8: nop

    sndp_stop(rdram, ctx);
        goto after_25;
    // 0x80007DD8: nop

    after_25:
    // 0x80007DDC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80007DE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007DE4: sw          $zero, 0x48($t8)
    MEM_W(0X48, ctx->r24) = 0;
    // 0x80007DE8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007DEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007DF0: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    // 0x80007DF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DF8: addiu       $a3, $a3, -0x33BC
    ctx->r7 = ADD32(ctx->r7, -0X33BC);
    // 0x80007DFC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
L_80007E00:
    // 0x80007E00: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80007E04: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
L_80007E08:
    // 0x80007E08: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007E0C: nop

    // 0x80007E10: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80007E14:
    // 0x80007E14: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
L_80007E18:
    // 0x80007E18: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007E1C: bne         $s5, $t4, L_80007CE4
    if (ctx->r21 != ctx->r12) {
        // 0x80007E20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007CE4;
    }
    // 0x80007E20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007E24:
    // 0x80007E24: jal         0x8001139C
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    get_race_countdown(rdram, ctx);
        goto after_26;
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    after_26:
    // 0x80007E2C: bgtz        $v0, L_80007F18
    if (SIGNED(ctx->r2) > 0) {
        // 0x80007E30: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80007F18;
    }
    // 0x80007E30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007E34: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007E38: addiu       $s0, $s0, -0x5E48
    ctx->r16 = ADD32(ctx->r16, -0X5E48);
    // 0x80007E3C: addiu       $s3, $s3, -0x5E50
    ctx->r19 = ADD32(ctx->r19, -0X5E50);
L_80007E40:
    // 0x80007E40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007E44: nop

    // 0x80007E48: beq         $s1, $zero, L_80007F0C
    if (ctx->r17 == 0) {
        // 0x80007E4C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E4C: nop

    // 0x80007E50: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x80007E54: nop

    // 0x80007E58: beq         $a2, $zero, L_80007F0C
    if (ctx->r6 == 0) {
        // 0x80007E5C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E5C: nop

    // 0x80007E60: lbu         $t5, 0x74($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X74);
    // 0x80007E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007E68: bne         $t5, $at, L_80007E78
    if (ctx->r13 != ctx->r1) {
        // 0x80007E6C: nop
    
            goto L_80007E78;
    }
    // 0x80007E6C: nop

    // 0x80007E70: b           L_80007F0C
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
        goto L_80007F0C;
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
L_80007E78:
    // 0x80007E78: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E7C: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    // 0x80007E80: bne         $a0, $zero, L_80007E98
    if (ctx->r4 != 0) {
        // 0x80007E84: nop
    
            goto L_80007E98;
    }
    // 0x80007E84: nop

    // 0x80007E88: jal         0x80001F14
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    sound_play_direct(rdram, ctx);
        goto after_27;
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_27:
    // 0x80007E90: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E94: nop

L_80007E98:
    // 0x80007E98: beq         $a0, $zero, L_80007F0C
    if (ctx->r4 == 0) {
        // 0x80007E9C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E9C: nop

    // 0x80007EA0: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x80007EA4: lw          $a2, 0x7C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7C);
    // 0x80007EA8: lw          $a3, 0x80($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X80);
    // 0x80007EAC: jal         0x80009B7C
    // 0x80007EB0: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_28;
    // 0x80007EB0: nop

    after_28:
    // 0x80007EB4: lbu         $a2, 0x88($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X88);
    // 0x80007EB8: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EBC: sll         $t3, $a2, 8
    ctx->r11 = S32(ctx->r6 << 8);
    // 0x80007EC0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80007EC4: jal         0x800049F8
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_29:
    // 0x80007ECC: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007ED0: lw          $a2, 0x8C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8C);
    // 0x80007ED4: jal         0x800049F8
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_30;
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_30:
    // 0x80007EDC: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80007EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007EE4: beq         $t6, $at, L_80007EF0
    if (ctx->r14 == ctx->r1) {
        // 0x80007EE8: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_80007EF0;
    }
    // 0x80007EE8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80007EEC: sb          $t7, 0x91($s1)
    MEM_B(0X91, ctx->r17) = ctx->r15;
L_80007EF0:
    // 0x80007EF0: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EF4: lbu         $a2, 0x91($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X91);
    // 0x80007EF8: jal         0x800049F8
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_31;
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80007F00: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007F04: jal         0x80004604
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    sndp_set_priority(rdram, ctx);
        goto after_32;
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_32:
L_80007F0C:
    // 0x80007F0C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007F10: bne         $s3, $s0, L_80007E40
    if (ctx->r19 != ctx->r16) {
        // 0x80007F14: nop
    
            goto L_80007E40;
    }
    // 0x80007F14: nop

L_80007F18:
    // 0x80007F18: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80007F1C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80007F20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80007F24: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80007F28: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80007F2C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80007F30: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80007F34: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80007F38: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80007F3C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80007F40: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80007F44: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80007F48: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80007F4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80007F50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80007F54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80007F58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80007F5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80007F60: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80007F64: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80007F68: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80007F6C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80007F70: jr          $ra
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void racer_sound_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007F7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F80: jr          $ra
    // 0x80007F84: sb          $t6, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = ctx->r14;
    return;
    // 0x80007F84: sb          $t6, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void racer_sound_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F8C: jr          $ra
    // 0x80007F90: sb          $zero, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = 0;
    return;
    // 0x80007F90: sb          $zero, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = 0;
;}
RECOMP_FUNC void racer_sound_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F94: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80007F98: lbu         $v0, -0x33C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33C0);
    // 0x80007F9C: jr          $ra
    // 0x80007FA0: nop

    return;
    // 0x80007FA0: nop

;}
RECOMP_FUNC void log_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007FA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007FA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007FAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007FB0: sub.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80007FB4: lwc1        $f19, 0x5288($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X5288);
    // 0x80007FB8: add.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80007FBC: lwc1        $f18, 0x528C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X528C);
    // 0x80007FC0: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80007FC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80007FC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80007FCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007FD4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80007FD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80007FDC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80007FE0: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80007FE4: nop

    // 0x80007FE8: bc1f        L_8000802C
    if (!c1cs) {
        // 0x80007FEC: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8000802C;
    }
    // 0x80007FEC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80007FF0: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80007FF4: nop

L_80007FF8:
    // 0x80007FF8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007FFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80008000: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008004: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80008008: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8000800C: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80008010: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80008014: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80008018: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000801C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80008020: nop

    // 0x80008024: bc1t        L_80007FF8
    if (c1cs) {
        // 0x80008028: nop
    
            goto L_80007FF8;
    }
    // 0x80008028: nop

L_8000802C:
    // 0x8000802C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008030: nop

    // 0x80008034: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80008038: jr          $ra
    // 0x8000803C: nop

    return;
    // 0x8000803C: nop

;}
RECOMP_FUNC void audspat_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008048: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000804C: addiu       $a0, $a0, -0x5E40
    ctx->r4 = ADD32(ctx->r4, -0X5E40);
    // 0x80008050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008054: jal         0x80002128
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sound_table_properties(rdram, ctx);
        goto after_0;
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000805C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008060: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008064: jal         0x80070EDC
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    after_1:
    // 0x8000806C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008070: addiu       $a2, $a2, -0x5E38
    ctx->r6 = ADD32(ctx->r6, -0X5E38);
    // 0x80008074: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008078: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000807C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008080: jal         0x80070EDC
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_2:
    // 0x80008088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000808C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008090: sw          $v0, -0x5E30($at)
    MEM_W(-0X5E30, ctx->r1) = ctx->r2;
    // 0x80008094: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008098: jal         0x80070EDC
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_3:
    // 0x800080A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800080A4: sw          $v0, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = ctx->r2;
    // 0x800080A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800080AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800080B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800080B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800080B8: addiu       $a2, $a2, -0x5E38
    ctx->r6 = ADD32(ctx->r6, -0X5E38);
    // 0x800080BC: sh          $zero, -0x33B0($at)
    MEM_H(-0X33B0, ctx->r1) = 0;
    // 0x800080C0: addiu       $v1, $v1, -0x5E28
    ctx->r3 = ADD32(ctx->r3, -0X5E28);
    // 0x800080C4: addiu       $v0, $v0, -0x53A8
    ctx->r2 = ADD32(ctx->r2, -0X53A8);
L_800080C8:
    // 0x800080C8: addiu       $v1, $v1, 0x180
    ctx->r3 = ADD32(ctx->r3, 0X180);
    // 0x800080CC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800080D0: bne         $at, $zero, L_800080C8
    if (ctx->r1 != 0) {
        // 0x800080D4: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800080C8;
    }
    // 0x800080D4: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800080D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800080DC: addiu       $v1, $zero, 0x5A0
    ctx->r3 = ADD32(0, 0X5A0);
L_800080E0:
    // 0x800080E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800080E4: nop

    // 0x800080E8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800080EC: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x800080F0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800080F4: nop

    // 0x800080F8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800080FC: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x80008100: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80008104: nop

    // 0x80008108: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000810C: sw          $zero, 0x60($t1)
    MEM_W(0X60, ctx->r9) = 0;
    // 0x80008110: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80008114: nop

    // 0x80008118: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000811C: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, 0X90);
    // 0x80008120: bne         $v0, $v1, L_800080E0
    if (ctx->r2 != ctx->r3) {
        // 0x80008124: sw          $zero, 0x84($t3)
        MEM_W(0X84, ctx->r11) = 0;
            goto L_800080E0;
    }
    // 0x80008124: sw          $zero, 0x84($t3)
    MEM_W(0X84, ctx->r11) = 0;
    // 0x80008128: jal         0x80008174
    // 0x8000812C: nop

    audspat_reset(rdram, ctx);
        goto after_4;
    // 0x8000812C: nop

    after_4:
    // 0x80008130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008138: jr          $ra
    // 0x8000813C: nop

    return;
    // 0x8000813C: nop

;}
RECOMP_FUNC void audspat_jingle_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008148: jal         0x800018E0
    // 0x8000814C: nop

    music_jingle_stop(rdram, ctx);
        goto after_0;
    // 0x8000814C: nop

    after_0:
    // 0x80008150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008154: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000815C: sb          $t6, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = ctx->r14;
    // 0x80008160: jr          $ra
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void audspat_jingle_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008168: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000816C: jr          $ra
    // 0x80008170: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
    return;
    // 0x80008170: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
;}
RECOMP_FUNC void audspat_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008174: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008178: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000817C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008180: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80008184: addiu       $v1, $v1, -0x5E34
    ctx->r3 = ADD32(ctx->r3, -0X5E34);
    // 0x80008188: lw          $a0, -0x5E38($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E38);
    // 0x8000818C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80008190: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80008194: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80008198: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000819C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800081A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800081A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800081A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800081AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800081B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800081B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800081B8: beq         $at, $zero, L_800081F4
    if (ctx->r1 == 0) {
        // 0x800081BC: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800081F4;
    }
    // 0x800081BC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800081C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800081C4: addiu       $a1, $a1, -0x5E30
    ctx->r5 = ADD32(ctx->r5, -0X5E30);
L_800081C8:
    // 0x800081C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800081CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800081D0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800081D4: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800081D8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800081DC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x800081E0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800081E4: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x800081E8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x800081EC: bne         $at, $zero, L_800081C8
    if (ctx->r1 != 0) {
        // 0x800081F0: sb          $t1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r9;
            goto L_800081C8;
    }
    // 0x800081F0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_800081F4:
    // 0x800081F4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800081F8: addiu       $s4, $s4, -0x33B0
    ctx->r20 = ADD32(ctx->r20, -0X33B0);
    // 0x800081FC: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
    // 0x80008200: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80008204: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80008208: blez        $t3, L_8000825C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000820C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000825C;
    }
    // 0x8000820C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80008210: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80008214: addiu       $s2, $s2, -0x5E3C
    ctx->r18 = ADD32(ctx->r18, -0X5E3C);
    // 0x80008218: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000821C:
    // 0x8000821C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80008220: nop

    // 0x80008224: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80008228: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000822C: nop

    // 0x80008230: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80008234: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80008238: beq         $a0, $zero, L_80008248
    if (ctx->r4 == 0) {
        // 0x8000823C: nop
    
            goto L_80008248;
    }
    // 0x8000823C: nop

    // 0x80008240: jal         0x8000488C
    // 0x80008244: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80008244: nop

    after_0:
L_80008248:
    // 0x80008248: lhu         $t6, 0x0($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X0);
    // 0x8000824C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80008250: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80008254: bne         $at, $zero, L_8000821C
    if (ctx->r1 != 0) {
        // 0x80008258: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000821C;
    }
    // 0x80008258: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000825C:
    // 0x8000825C: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80008260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008264: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80008268: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000826C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80008270: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80008274: lwc1        $f20, 0x54A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54A0);
    // 0x80008278: addiu       $s5, $s5, -0x53A0
    ctx->r21 = ADD32(ctx->r21, -0X53A0);
    // 0x8000827C: addiu       $s3, $s3, -0x5E20
    ctx->r19 = ADD32(ctx->r19, -0X5E20);
    // 0x80008280: addiu       $s2, $s2, -0x5E24
    ctx->r18 = ADD32(ctx->r18, -0X5E24);
    // 0x80008284: addiu       $s1, $s1, -0x5E28
    ctx->r17 = ADD32(ctx->r17, -0X5E28);
    // 0x80008288: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000828C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80008290: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_80008294:
    // 0x80008294: lw          $a0, 0x178($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X178);
    // 0x80008298: sw          $zero, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = 0;
    // 0x8000829C: beq         $a0, $zero, L_800082D8
    if (ctx->r4 == 0) {
        // 0x800082A0: nop
    
            goto L_800082D8;
    }
    // 0x800082A0: nop

    // 0x800082A4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800082A8: nop

    // 0x800082AC: bne         $v0, $zero, L_800082C4
    if (ctx->r2 != 0) {
        // 0x800082B0: nop
    
            goto L_800082C4;
    }
    // 0x800082B0: nop

    // 0x800082B4: jal         0x8000488C
    // 0x800082B8: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x800082B8: nop

    after_1:
    // 0x800082BC: b           L_800082D8
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
        goto L_800082D8;
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082C4:
    // 0x800082C4: bne         $s6, $v0, L_800082D4
    if (ctx->r22 != ctx->r2) {
        // 0x800082C8: nop
    
            goto L_800082D4;
    }
    // 0x800082C8: nop

    // 0x800082CC: jal         0x800018E0
    // 0x800082D0: nop

    music_jingle_stop(rdram, ctx);
        goto after_2;
    // 0x800082D0: nop

    after_2:
L_800082D4:
    // 0x800082D4: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082D8:
    // 0x800082D8: sb          $s4, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = ctx->r20;
    // 0x800082DC: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x800082E0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800082E4: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x800082E8: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800082EC: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800082F0: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800082F4: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800082F8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800082FC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80008300:
    // 0x80008300: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008304: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x80008308: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8000830C: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x80008310: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008314: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008318: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8000831C: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x80008320: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x80008324: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008328: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8000832C: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x80008330: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008334: bne         $v1, $s0, L_80008300
    if (ctx->r3 != ctx->r16) {
        // 0x80008338: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_80008300;
    }
    // 0x80008338: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x8000833C: addiu       $s3, $s3, 0x180
    ctx->r19 = ADD32(ctx->r19, 0X180);
    // 0x80008340: sltu        $at, $s3, $s5
    ctx->r1 = ctx->r19 < ctx->r21 ? 1 : 0;
    // 0x80008344: addiu       $s1, $s1, 0x180
    ctx->r17 = ADD32(ctx->r17, 0X180);
    // 0x80008348: bne         $at, $zero, L_80008294
    if (ctx->r1 != 0) {
        // 0x8000834C: addiu       $s2, $s2, 0x180
        ctx->r18 = ADD32(ctx->r18, 0X180);
            goto L_80008294;
    }
    // 0x8000834C: addiu       $s2, $s2, 0x180
    ctx->r18 = ADD32(ctx->r18, 0X180);
    // 0x80008350: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008354: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008358: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8000835C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80008360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80008364: addiu       $t0, $t0, -0x4E60
    ctx->r8 = ADD32(ctx->r8, -0X4E60);
    // 0x80008368: addiu       $a3, $a3, -0x53A0
    ctx->r7 = ADD32(ctx->r7, -0X53A0);
    // 0x8000836C: addiu       $a2, $a2, -0x53A4
    ctx->r6 = ADD32(ctx->r6, -0X53A4);
    // 0x80008370: addiu       $a1, $a1, -0x53A8
    ctx->r5 = ADD32(ctx->r5, -0X53A8);
    // 0x80008374: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80008378:
    // 0x80008378: sb          $s4, 0xB8($a1)
    MEM_B(0XB8, ctx->r5) = ctx->r20;
    // 0x8000837C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80008380: swc1        $f0, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = ctx->f0.u32l;
    // 0x80008384: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x80008388: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000838C: swc1        $f20, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f20.u32l;
    // 0x80008390: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008394: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008398: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x8000839C: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083A0: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083A4: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800083A8: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800083AC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800083B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800083B4:
    // 0x800083B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800083B8: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083BC: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083C0: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x800083C4: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x800083C8: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x800083CC: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x800083D0: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x800083D4: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083D8: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083DC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800083E0: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x800083E4: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083E8: bne         $v1, $a0, L_800083B4
    if (ctx->r3 != ctx->r4) {
        // 0x800083EC: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_800083B4;
    }
    // 0x800083EC: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083F0: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    // 0x800083F4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x800083F8: bne         $a3, $t0, L_80008378
    if (ctx->r7 != ctx->r8) {
        // 0x800083FC: addiu       $a2, $a2, 0xC0
        ctx->r6 = ADD32(ctx->r6, 0XC0);
            goto L_80008378;
    }
    // 0x800083FC: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x80008400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80008404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008408: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000840C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80008410: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008414: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80008418: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000841C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80008420: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80008424: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80008428: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000842C: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
    // 0x80008430: jr          $ra
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void audspat_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008438: addiu       $sp, $sp, -0x268
    ctx->r29 = ADD32(ctx->r29, -0X268);
    // 0x8000843C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80008440: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80008444: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80008448: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8000844C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80008450: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80008454: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80008458: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8000845C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80008460: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80008464: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80008468: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8000846C: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80008470: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80008474: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80008478: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8000847C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80008480: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80008484: sw          $a0, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r4;
    // 0x80008488: sw          $a1, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r5;
    // 0x8000848C: sw          $a2, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r6;
    // 0x80008490: jal         0x80066450
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    after_0:
    // 0x80008498: jal         0x8006676C
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800084A0: jal         0x80069FBC
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    cam_get_cameras(rdram, ctx);
        goto after_2;
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    after_2:
    // 0x800084A8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800084AC: addiu       $s5, $s5, -0x33B0
    ctx->r21 = ADD32(ctx->r21, -0X33B0);
    // 0x800084B0: lhu         $t6, 0x0($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X0);
    // 0x800084B4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800084B8: blez        $t6, L_80008AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800084BC: sw          $zero, 0x260($sp)
        MEM_W(0X260, ctx->r29) = 0;
            goto L_80008AD8;
    }
    // 0x800084BC: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
    // 0x800084C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800084C4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800084C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800084CC: addiu       $s6, $s6, -0x5E3C
    ctx->r22 = ADD32(ctx->r22, -0X5E3C);
    // 0x800084D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800084D4: addiu       $s7, $sp, 0xA8
    ctx->r23 = ADD32(ctx->r29, 0XA8);
    // 0x800084D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800084DC:
    // 0x800084DC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800084E0: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x800084E4: addu        $t8, $t7, $s4
    ctx->r24 = ADD32(ctx->r15, ctx->r20);
    // 0x800084E8: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800084EC: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x800084F0: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x800084F4: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800084F8: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x800084FC: beq         $t0, $zero, L_800086BC
    if (ctx->r8 == 0) {
        // 0x80008500: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800086BC;
    }
    // 0x80008500: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008504: bne         $t1, $at, L_80008ABC
    if (ctx->r9 != ctx->r1) {
        // 0x80008508: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008508: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x8000850C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80008510: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008514: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80008518: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000851C: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008520: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80008524: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008528: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000852C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008530: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80008534: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008538: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000853C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80008544: jal         0x800CA030
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x8000854C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80008550: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008554: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80008558: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000855C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008560: nop

    // 0x80008564: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008568: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8000856C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80008570: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008574: beq         $at, $zero, L_8000869C
    if (ctx->r1 == 0) {
        // 0x80008578: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008578: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000857C: lbu         $t4, 0x12($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X12);
    // 0x80008580: nop

    // 0x80008584: bne         $t4, $zero, L_8000869C
    if (ctx->r12 != 0) {
        // 0x80008588: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008588: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000858C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008590: nop

    // 0x80008594: bne         $a0, $zero, L_800085D4
    if (ctx->r4 != 0) {
        // 0x80008598: nop
    
            goto L_800085D4;
    }
    // 0x80008598: nop

    // 0x8000859C: lbu         $t5, 0x22($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X22);
    // 0x800085A0: nop

    // 0x800085A4: beq         $t5, $zero, L_800085C0
    if (ctx->r13 == 0) {
        // 0x800085A8: nop
    
            goto L_800085C0;
    }
    // 0x800085A8: nop

    // 0x800085AC: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
    // 0x800085B0: nop

    // 0x800085B4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800085B8: bne         $t7, $zero, L_800085D4
    if (ctx->r15 != 0) {
        // 0x800085BC: nop
    
            goto L_800085D4;
    }
    // 0x800085BC: nop

L_800085C0:
    // 0x800085C0: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x800085C4: jal         0x80001F14
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_4:
    // 0x800085CC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800085D0: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_800085D4:
    // 0x800085D4: beq         $a0, $zero, L_80008690
    if (ctx->r4 == 0) {
        // 0x800085D8: nop
    
            goto L_80008690;
    }
    // 0x800085D8: nop

    // 0x800085DC: lbu         $t8, 0xF($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XF);
    // 0x800085E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800085E4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800085E8: bgez        $t8, L_800085FC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800085EC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800085FC;
    }
    // 0x800085EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800085F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800085F4: nop

    // 0x800085F8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800085FC:
    // 0x800085FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008604: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008608: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000860C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x80008610: lbu         $a2, 0xE($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XE);
    // 0x80008614: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008618: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8000861C: jal         0x800049F8
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_5:
    // 0x80008624: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008628: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8000862C: jal         0x800049F8
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x80008634: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80008638: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000863C: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x80008640: jal         0x800090C0
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_7;
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_7:
    // 0x80008648: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8000864C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008650: beq         $t1, $at, L_8000865C
    if (ctx->r9 == ctx->r1) {
        // 0x80008654: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000865C;
    }
    // 0x80008654: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80008658: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_8000865C:
    // 0x8000865C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008660: jal         0x800049F8
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_8;
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80008668: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8000866C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008670: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008674: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008678: jal         0x80009B7C
    // 0x8000867C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_9;
    // 0x8000867C: nop

    after_9:
    // 0x80008680: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008684: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008688: jal         0x80004604
    // 0x8000868C: nop

    sndp_set_priority(rdram, ctx);
        goto after_10;
    // 0x8000868C: nop

    after_10:
L_80008690:
    // 0x80008690: b           L_80008AB8
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
        goto L_80008AB8;
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
    // 0x80008698: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8000869C:
    // 0x8000869C: beq         $at, $zero, L_80008ABC
    if (ctx->r1 == 0) {
        // 0x800086A0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086A0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086A4: lbu         $t2, 0x12($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12);
    // 0x800086A8: nop

    // 0x800086AC: beq         $t2, $zero, L_80008ABC
    if (ctx->r10 == 0) {
        // 0x800086B0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086B0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086B4: b           L_80008AB8
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
        goto L_80008AB8;
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
L_800086BC:
    // 0x800086BC: blez        $t3, L_8000884C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800086C0: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8000884C;
    }
    // 0x800086C0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800086C4: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x800086C8: nop

L_800086CC:
    // 0x800086CC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800086D0: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800086D4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800086D8: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800086DC: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800086E0: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800086E4: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800086E8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800086EC: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800086F0: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800086F4: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800086F8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800086FC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80008700: jal         0x800CA030
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_11:
    // 0x80008708: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000870C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008710: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80008714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000871C: lw          $t1, 0x254($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X254);
    // 0x80008720: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008724: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80008728: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000872C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008730: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008734: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008734: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008738: lbu         $t5, 0x20($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X20);
    // 0x8000873C: subu        $t8, $a0, $v1
    ctx->r24 = SUB32(ctx->r4, ctx->r3);
    // 0x80008740: bne         $t5, $zero, L_800087B0
    if (ctx->r13 != 0) {
        // 0x80008744: nop
    
            goto L_800087B0;
    }
    // 0x80008744: nop

    // 0x80008748: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8000874C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80008750: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008754: lbu         $t6, 0xE($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XE);
    // 0x80008758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000875C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008760: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80008764: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80008768: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000876C: bgez        $t6, L_80008780
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80008770: sub.s       $f8, $f26, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
            goto L_80008780;
    }
    // 0x80008770: sub.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x80008774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80008778: nop

    // 0x8000877C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80008780:
    // 0x80008780: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80008784: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80008788: nop

    // 0x8000878C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80008790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008798: nop

    // 0x8000879C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800087A0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800087A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800087A8: b           L_8000881C
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_8000881C;
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_800087B0:
    // 0x800087B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800087B4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800087B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800087BC: lbu         $t9, 0xE($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XE);
    // 0x800087C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800087C4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800087C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800087CC: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800087D0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800087D4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800087D8: bgez        $t9, L_800087EC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800087DC: nop
    
            goto L_800087EC;
    }
    // 0x800087DC: nop

    // 0x800087E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800087E4: nop

    // 0x800087E8: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_800087EC:
    // 0x800087EC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800087F0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800087F4: nop

    // 0x800087F8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800087FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008800: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008804: nop

    // 0x80008808: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000880C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80008810: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80008814: nop

    // 0x80008818: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_8000881C:
    // 0x8000881C: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008820: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008820: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008824: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008828: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x8000882C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80008830: jal         0x800090C0
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_12;
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_12:
    // 0x80008838: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000883C: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
L_80008840:
    // 0x80008840: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008844: bne         $fp, $t2, L_800086CC
    if (ctx->r30 != ctx->r10) {
        // 0x80008848: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800086CC;
    }
    // 0x80008848: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_8000884C:
    // 0x8000884C: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008850: lw          $t3, 0x254($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X254);
    // 0x80008854: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008858: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000885C: beq         $at, $zero, L_8000892C
    if (ctx->r1 == 0) {
        // 0x80008860: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000892C;
    }
    // 0x80008860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008864: lwc1        $f24, 0x54A4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X54A4);
    // 0x80008868: blez        $t4, L_80008928
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000886C: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008928;
    }
    // 0x8000886C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008870: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80008874: nop

L_80008878:
    // 0x80008878: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000887C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008880: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80008884: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80008888: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000888C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008890: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80008894: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008898: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000889C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800088A0: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800088A4: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800088A8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800088AC: jal         0x800CA030
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_13:
    // 0x800088B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800088B8: nop

    // 0x800088BC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800088C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800088C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800088C8: nop

    // 0x800088CC: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800088D0: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x800088D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800088D8: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800088DC: nop

    // 0x800088E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800088E4: c.lt.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl < ctx->f24.fl;
    // 0x800088E8: nop

    // 0x800088EC: bc1f        L_80008914
    if (!c1cs) {
        // 0x800088F0: lw          $t6, 0xB0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB0);
            goto L_80008914;
    }
    // 0x800088F0: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800088F4: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x800088F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800088FC: jal         0x800090C0
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_14;
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_14:
    // 0x80008904: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80008908: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000890C: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008910: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
L_80008914:
    // 0x80008914: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008918: bne         $fp, $t6, L_80008878
    if (ctx->r30 != ctx->r14) {
        // 0x8000891C: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_80008878;
    }
    // 0x8000891C: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x80008920: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008924: nop

L_80008928:
    // 0x80008928: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
L_8000892C:
    // 0x8000892C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008930: nop

    // 0x80008934: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008938: bne         $at, $zero, L_80008A4C
    if (ctx->r1 != 0) {
        // 0x8000893C: nop
    
            goto L_80008A4C;
    }
    // 0x8000893C: nop

    // 0x80008940: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008944: nop

    // 0x80008948: bne         $a0, $zero, L_80008988
    if (ctx->r4 != 0) {
        // 0x8000894C: nop
    
            goto L_80008988;
    }
    // 0x8000894C: nop

    // 0x80008950: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008954: nop

    // 0x80008958: beq         $t8, $zero, L_80008974
    if (ctx->r24 == 0) {
        // 0x8000895C: nop
    
            goto L_80008974;
    }
    // 0x8000895C: nop

    // 0x80008960: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x80008964: nop

    // 0x80008968: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000896C: bne         $t0, $zero, L_80008988
    if (ctx->r8 != 0) {
        // 0x80008970: nop
    
            goto L_80008988;
    }
    // 0x80008970: nop

L_80008974:
    // 0x80008974: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x80008978: jal         0x80001F14
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_15;
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_15:
    // 0x80008980: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008984: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_80008988:
    // 0x80008988: beq         $a0, $zero, L_80008A38
    if (ctx->r4 == 0) {
        // 0x8000898C: nop
    
            goto L_80008A38;
    }
    // 0x8000898C: nop

    // 0x80008990: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    // 0x80008994: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008998: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000899C: bgez        $t1, L_800089B0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800089A0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800089B0;
    }
    // 0x800089A0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800089A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800089A8: nop

    // 0x800089AC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800089B0:
    // 0x800089B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800089B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800089B8: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x800089BC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800089C0: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x800089C4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800089C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800089CC: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x800089D0: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089D4: jal         0x800049F8
    // 0x800089D8: nop

    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x800089D8: nop

    after_16:
    // 0x800089DC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089E0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800089E4: jal         0x800049F8
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800089EC: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800089F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800089F4: beq         $t3, $at, L_80008A00
    if (ctx->r11 == ctx->r1) {
        // 0x800089F8: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008A00;
    }
    // 0x800089F8: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800089FC: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008A00:
    // 0x80008A00: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A04: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008A08: jal         0x800049F8
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_18;
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80008A10: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A14: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008A18: jal         0x80004604
    // 0x80008A1C: nop

    sndp_set_priority(rdram, ctx);
        goto after_19;
    // 0x80008A1C: nop

    after_19:
    // 0x80008A20: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A24: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008A28: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008A2C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008A30: jal         0x80009B7C
    // 0x80008A34: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_20;
    // 0x80008A34: nop

    after_20:
L_80008A38:
    // 0x80008A38: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A3C: nop

    // 0x80008A40: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80008A44: b           L_80008A88
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80008A88;
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80008A4C:
    // 0x80008A4C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A50: nop

    // 0x80008A54: beq         $a0, $zero, L_80008A78
    if (ctx->r4 == 0) {
        // 0x80008A58: nop
    
            goto L_80008A78;
    }
    // 0x80008A58: nop

    // 0x80008A5C: jal         0x8000488C
    // 0x80008A60: nop

    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x80008A60: nop

    after_21:
    // 0x80008A64: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A68: nop

    // 0x80008A6C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x80008A70: b           L_80008A88
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80008A88;
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80008A78:
    // 0x80008A78: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A7C: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
    // 0x80008A80: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80008A84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80008A88:
    // 0x80008A88: beq         $v0, $zero, L_80008ABC
    if (ctx->r2 == 0) {
        // 0x80008A8C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A8C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008A90: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008A94: nop

    // 0x80008A98: beq         $t8, $zero, L_80008ABC
    if (ctx->r24 == 0) {
        // 0x80008A9C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A9C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA0: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x80008AA4: lw          $a0, 0x260($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA8: bne         $t9, $zero, L_80008ABC
    if (ctx->r25 != 0) {
        // 0x80008AAC: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008AAC: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AB0: jal         0x8000A2E8
    // 0x80008AB4: nop

    audspat_point_stop_by_index(rdram, ctx);
        goto after_22;
    // 0x80008AB4: nop

    after_22:
L_80008AB8:
    // 0x80008AB8: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
L_80008ABC:
    // 0x80008ABC: lhu         $t2, 0x0($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X0);
    // 0x80008AC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80008AC4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008AC8: sw          $t1, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r9;
    // 0x80008ACC: bne         $at, $zero, L_800084DC
    if (ctx->r1 != 0) {
        // 0x80008AD0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800084DC;
    }
    // 0x80008AD0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80008AD4: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
L_80008AD8:
    // 0x80008AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80008ADC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80008AE0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80008AE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80008AE8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80008AEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008AF0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80008AF4: addiu       $v0, $v0, -0x5E28
    ctx->r2 = ADD32(ctx->r2, -0X5E28);
L_80008AF8:
    // 0x80008AF8: lw          $t3, 0x16C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X16C);
    // 0x80008AFC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80008B00: beq         $t3, $zero, L_80008FC4
    if (ctx->r11 == 0) {
        // 0x80008B04: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_80008FC4;
    }
    // 0x80008B04: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80008B08: lbu         $a0, 0x263($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X263);
    // 0x80008B0C: jal         0x800099EC
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    audspat_line_validate(rdram, ctx);
        goto after_23;
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    after_23:
    // 0x80008B14: beq         $v0, $zero, L_80008FC8
    if (ctx->r2 == 0) {
        // 0x80008B18: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008B18: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008B1C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008B20: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x80008B24: blez        $t4, L_80008E44
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80008B28: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008E44;
    }
    // 0x80008B28: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008B2C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008B30: nop

    // 0x80008B34: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x80008B38: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80008B3C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008B40:
    // 0x80008B40: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80008B44: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008B48: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x80008B4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80008B50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008B54: blez        $t6, L_80008C0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80008B58: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80008C0C;
    }
    // 0x80008B58: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80008B5C: sll         $t8, $fp, 4
    ctx->r24 = S32(ctx->r30 << 4);
    // 0x80008B60: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80008B64: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x80008B68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80008B6C: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008B70: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008B74: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
L_80008B78:
    // 0x80008B78: lwc1        $f12, 0xC($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008B7C: lwc1        $f14, 0x10($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80008B80: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008B84: addiu       $t9, $sp, 0x22C
    ctx->r25 = ADD32(ctx->r29, 0X22C);
    // 0x80008B88: addiu       $t0, $sp, 0x228
    ctx->r8 = ADD32(ctx->r29, 0X228);
    // 0x80008B8C: addiu       $t1, $sp, 0x224
    ctx->r9 = ADD32(ctx->r29, 0X224);
    // 0x80008B90: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80008B94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80008B98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80008B9C: jal         0x800092A8
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_24;
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_24:
    // 0x80008BA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80008BA8: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80008BAC: lwc1        $f16, 0x224($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X224);
    // 0x80008BB0: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008BB4: lwc1        $f8, 0x22C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X22C);
    // 0x80008BB8: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x80008BBC: sub.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80008BC0: jal         0x800090C0
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_25;
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    after_25:
    // 0x80008BC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80008BCC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80008BD0: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80008BD4: beq         $at, $zero, L_80008BE0
    if (ctx->r1 == 0) {
        // 0x80008BD8: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80008BE0;
    }
    // 0x80008BD8: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80008BDC: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
L_80008BE0:
    // 0x80008BE0: lb          $t2, 0x17C($s7)
    ctx->r10 = MEM_B(ctx->r23, 0X17C);
    // 0x80008BE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008BE8: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008BEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008BF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008BF4: bne         $at, $zero, L_80008B78
    if (ctx->r1 != 0) {
        // 0x80008BF8: addu        $s5, $s5, $v1
        ctx->r21 = ADD32(ctx->r21, ctx->r3);
            goto L_80008B78;
    }
    // 0x80008BF8: addu        $s5, $s5, $v1
    ctx->r21 = ADD32(ctx->r21, ctx->r3);
    // 0x80008BFC: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008C00: nop

    // 0x80008C04: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008C08: nop

L_80008C0C:
    // 0x80008C0C: mtc1        $v1, $f24
    ctx->f24.u32l = ctx->r3;
    // 0x80008C10: lbu         $t4, 0x174($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X174);
    // 0x80008C14: cvt.s.w     $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C18: mtc1        $t4, $f24
    ctx->f24.u32l = ctx->r12;
    // 0x80008C1C: bgez        $t4, L_80008C34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80008C20: cvt.s.w     $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
            goto L_80008C34;
    }
    // 0x80008C20: cvt.s.w     $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008C28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008C2C: nop

    // 0x80008C30: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80008C34:
    // 0x80008C34: lbu         $t5, 0x17D($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17D);
    // 0x80008C38: lw          $t9, 0x254($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X254);
    // 0x80008C3C: bne         $t5, $zero, L_80008C8C
    if (ctx->r13 != 0) {
        // 0x80008C40: subu        $t7, $v1, $s6
        ctx->r15 = SUB32(ctx->r3, ctx->r22);
            goto L_80008C8C;
    }
    // 0x80008C40: subu        $t7, $v1, $s6
    ctx->r15 = SUB32(ctx->r3, ctx->r22);
    // 0x80008C44: mtc1        $s6, $f6
    ctx->f6.u32l = ctx->r22;
    // 0x80008C48: nop

    // 0x80008C4C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C50: nop

    // 0x80008C54: div.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008C58: sub.s       $f18, $f26, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x80008C5C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80008C60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80008C64: nop

    // 0x80008C68: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80008C6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008C70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008C74: nop

    // 0x80008C78: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008C7C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80008C80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80008C84: b           L_80008CD8
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
        goto L_80008CD8;
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008C8C:
    // 0x80008C8C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008C90: nop

    // 0x80008C94: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C98: nop

    // 0x80008C9C: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008CA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008CA4: nop

    // 0x80008CA8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80008CAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80008CB0: nop

    // 0x80008CB4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80008CB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008CBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008CC0: nop

    // 0x80008CC4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008CC8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80008CCC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80008CD0: nop

    // 0x80008CD4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008CD8:
    // 0x80008CD8: bne         $at, $zero, L_80008E38
    if (ctx->r1 != 0) {
        // 0x80008CDC: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008CDC: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008CE0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008CE4: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008CE8: lb          $v1, 0x17C($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X17C);
    // 0x80008CEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008CF0: bne         $v1, $at, L_80008D04
    if (ctx->r3 != ctx->r1) {
        // 0x80008CF4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80008D04;
    }
    // 0x80008CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008CF8: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x80008CFC: b           L_80008DD8
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
        goto L_80008DD8;
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
L_80008D04:
    // 0x80008D04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008D08: blez        $v1, L_80008D50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D0C: sw          $zero, 0x250($sp)
        MEM_W(0X250, ctx->r29) = 0;
            goto L_80008D50;
    }
    // 0x80008D0C: sw          $zero, 0x250($sp)
    MEM_W(0X250, ctx->r29) = 0;
    // 0x80008D10: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008D14: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
L_80008D18:
    // 0x80008D18: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80008D1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008D20: subu        $v1, $s5, $t2
    ctx->r3 = SUB32(ctx->r21, ctx->r10);
    // 0x80008D24: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80008D28: lb          $t3, 0x17C($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008D30: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80008D34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D38: bne         $at, $zero, L_80008D18
    if (ctx->r1 != 0) {
        // 0x80008D3C: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_80008D18;
    }
    // 0x80008D3C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80008D40: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80008D44: nop

    // 0x80008D48: lb          $v1, 0x17C($t4)
    ctx->r3 = MEM_B(ctx->r12, 0X17C);
    // 0x80008D4C: nop

L_80008D50:
    // 0x80008D50: blez        $v1, L_80008DD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D54: addiu       $s1, $sp, 0x12C
        ctx->r17 = ADD32(ctx->r29, 0X12C);
            goto L_80008DD8;
    }
    // 0x80008D54: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008D58: lb          $a1, 0x17C($s7)
    ctx->r5 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D5C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80008D60: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x80008D64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80008D68: lw          $a0, 0x250($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X250);
    // 0x80008D6C: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80008D70: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
L_80008D74:
    // 0x80008D74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80008D78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80008D7C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008D80: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80008D84: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008D88: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80008D8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D90: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80008D94: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008D98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008D9C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008DA0: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80008DA4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80008DA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80008DAC: nop

    // 0x80008DB0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80008DB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008DB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008DBC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80008DC0: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008DC4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80008DC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80008DCC: bne         $at, $zero, L_80008D74
    if (ctx->r1 != 0) {
        // 0x80008DD0: nop
    
            goto L_80008D74;
    }
    // 0x80008DD0: nop

    // 0x80008DD4: sw          $a0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r4;
L_80008DD8:
    // 0x80008DD8: slti        $at, $s6, 0x190
    ctx->r1 = SIGNED(ctx->r22) < 0X190 ? 1 : 0;
    // 0x80008DDC: beq         $at, $zero, L_80008E38
    if (ctx->r1 == 0) {
        // 0x80008DE0: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008DE0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008DE4: mtc1        $s6, $f16
    ctx->f16.u32l = ctx->r22;
    // 0x80008DE8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008DEC: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008DF0: addiu       $t1, $t0, -0x40
    ctx->r9 = ADD32(ctx->r8, -0X40);
    // 0x80008DF4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80008DF8: div.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80008DFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008E00: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80008E04: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80008E08: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80008E0C: nop

    // 0x80008E10: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80008E14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008E18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008E1C: nop

    // 0x80008E20: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008E24: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80008E28: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80008E2C: sw          $t3, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r11;
    // 0x80008E30: nop

    // 0x80008E34: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
L_80008E38:
    // 0x80008E38: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008E3C: bne         $fp, $t4, L_80008B40
    if (ctx->r30 != ctx->r12) {
        // 0x80008E40: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_80008B40;
    }
    // 0x80008E40: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008E44:
    // 0x80008E44: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008E48: lw          $t5, 0x254($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X254);
    // 0x80008E4C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80008E50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008E54: bne         $v0, $zero, L_80008F88
    if (ctx->r2 != 0) {
        // 0x80008E58: nop
    
            goto L_80008F88;
    }
    // 0x80008E58: nop

    // 0x80008E5C: lbu         $v0, 0x175($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X175);
    // 0x80008E60: nop

    // 0x80008E64: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80008E68: beq         $at, $zero, L_80008E78
    if (ctx->r1 == 0) {
        // 0x80008E6C: lw          $t7, 0x254($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X254);
            goto L_80008E78;
    }
    // 0x80008E6C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008E70: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008E74: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
L_80008E78:
    // 0x80008E78: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80008E7C: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008E80: bne         $at, $zero, L_80008F64
    if (ctx->r1 != 0) {
        // 0x80008E84: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80008F64;
    }
    // 0x80008E84: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80008E88: lbu         $t9, 0x176($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X176);
    // 0x80008E8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008E90: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80008E94: bgez        $t9, L_80008EA8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80008E98: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80008EA8;
    }
    // 0x80008E98: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008E9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80008EA0: nop

    // 0x80008EA4: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_80008EA8:
    // 0x80008EA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008EAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008EB0: nop

    // 0x80008EB4: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80008EB8: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80008EBC: lw          $a0, 0x178($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X178);
    // 0x80008EC0: nop

    // 0x80008EC4: bne         $a0, $zero, L_80008EE8
    if (ctx->r4 != 0) {
        // 0x80008EC8: nop
    
            goto L_80008EE8;
    }
    // 0x80008EC8: nop

    // 0x80008ECC: lhu         $a0, 0x16E($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X16E);
    // 0x80008ED0: jal         0x80001F14
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    sound_play_direct(rdram, ctx);
        goto after_26;
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    after_26:
    // 0x80008ED8: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008EDC: nop

    // 0x80008EE0: lw          $a0, 0x178($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X178);
    // 0x80008EE4: nop

L_80008EE8:
    // 0x80008EE8: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008EEC: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008EEC: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008EF0: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x80008EF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008EF8: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x80008EFC: jal         0x800049F8
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    sndp_set_param(rdram, ctx);
        goto after_27;
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_27:
    // 0x80008F04: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80008F08: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80008F0C: lw          $a0, 0x178($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X178);
    // 0x80008F10: jal         0x800049F8
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_28;
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_28:
    // 0x80008F18: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80008F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008F20: beq         $t3, $at, L_80008F2C
    if (ctx->r11 == ctx->r1) {
        // 0x80008F24: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008F2C;
    }
    // 0x80008F24: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80008F28: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008F2C:
    // 0x80008F2C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008F30: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008F34: lw          $a0, 0x178($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X178);
    // 0x80008F38: jal         0x800049F8
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
    // 0x80008F40: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80008F44: nop

    // 0x80008F48: lw          $a0, 0x178($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X178);
    // 0x80008F4C: lbu         $a1, 0x17E($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X17E);
    // 0x80008F50: jal         0x80004604
    // 0x80008F54: nop

    sndp_set_priority(rdram, ctx);
        goto after_30;
    // 0x80008F54: nop

    after_30:
    // 0x80008F58: b           L_80008FC8
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F60: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80008F64:
    // 0x80008F64: nop

    // 0x80008F68: lw          $a0, 0x178($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X178);
    // 0x80008F6C: nop

    // 0x80008F70: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008F74: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F74: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F78: jal         0x8000488C
    // 0x80008F7C: nop

    sndp_stop(rdram, ctx);
        goto after_31;
    // 0x80008F7C: nop

    after_31:
    // 0x80008F80: b           L_80008FC8
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008F88:
    // 0x80008F88: bne         $v0, $at, L_80008FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80008F8C: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F8C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F90: lw          $t9, 0x24C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24C);
    // 0x80008F94: lw          $t8, 0x254($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X254);
    // 0x80008F98: nop

    // 0x80008F9C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80008FA0: beq         $at, $zero, L_80008FC8
    if (ctx->r1 == 0) {
        // 0x80008FA4: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008FA4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008FA8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008FAC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80008FB0: sw          $t8, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r24;
    // 0x80008FB4: sw          $t0, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r8;
    // 0x80008FB8: lw          $t2, 0x16C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X16C);
    // 0x80008FBC: nop

    // 0x80008FC0: sw          $t2, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r10;
L_80008FC4:
    // 0x80008FC4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008FC8:
    // 0x80008FC8: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008FCC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80008FD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80008FD4: sw          $t4, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r12;
    // 0x80008FD8: bne         $t4, $at, L_80008AF8
    if (ctx->r12 != ctx->r1) {
        // 0x80008FDC: addiu       $v0, $v0, 0x180
        ctx->r2 = ADD32(ctx->r2, 0X180);
            goto L_80008AF8;
    }
    // 0x80008FDC: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, 0X180);
    // 0x80008FE0: lw          $t6, 0x24C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24C);
    // 0x80008FE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80008FE8: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80008FEC: bne         $at, $zero, L_80009044
    if (ctx->r1 != 0) {
        // 0x80008FF0: nop
    
            goto L_80009044;
    }
    // 0x80008FF0: nop

    // 0x80008FF4: lbu         $t5, -0x4E68($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4E68);
    // 0x80008FF8: nop

    // 0x80008FFC: bne         $t5, $zero, L_80009044
    if (ctx->r13 != 0) {
        // 0x80009000: nop
    
            goto L_80009044;
    }
    // 0x80009000: nop

    // 0x80009004: jal         0x80001980
    // 0x80009008: nop

    music_jingle_current(rdram, ctx);
        goto after_32;
    // 0x80009008: nop

    after_32:
    // 0x8000900C: lw          $t7, 0x244($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X244);
    // 0x80009010: lbu         $a0, 0x247($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X247);
    // 0x80009014: beq         $t7, $v0, L_80009024
    if (ctx->r15 == ctx->r2) {
        // 0x80009018: nop
    
            goto L_80009024;
    }
    // 0x80009018: nop

    // 0x8000901C: jal         0x80001784
    // 0x80009020: nop

    music_jingle_play_safe(rdram, ctx);
        goto after_33;
    // 0x80009020: nop

    after_33:
L_80009024:
    // 0x80009024: lbu         $a0, 0x24F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24F);
    // 0x80009028: jal         0x80001B0C
    // 0x8000902C: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_34;
    // 0x8000902C: nop

    after_34:
    // 0x80009030: lbu         $a0, 0x24B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24B);
    // 0x80009034: jal         0x80001B58
    // 0x80009038: nop

    music_jingle_pan_set(rdram, ctx);
        goto after_35;
    // 0x80009038: nop

    after_35:
    // 0x8000903C: b           L_80009050
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
        goto L_80009050;
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009044:
    // 0x80009044: jal         0x800018E0
    // 0x80009048: nop

    music_jingle_stop(rdram, ctx);
        goto after_36;
    // 0x80009048: nop

    after_36:
    // 0x8000904C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009050:
    // 0x80009050: lw          $a0, 0x268($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X268);
    // 0x80009054: beq         $a1, $zero, L_80009074
    if (ctx->r5 == 0) {
        // 0x80009058: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80009074;
    }
    // 0x80009058: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8000905C: lw          $t9, 0x270($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X270);
    // 0x80009060: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x80009064: lbu         $a3, 0xB3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XB3);
    // 0x80009068: jal         0x80006FC8
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    racer_sound_update_all(rdram, ctx);
        goto after_37;
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_37:
    // 0x80009070: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80009074:
    // 0x80009074: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009078: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000907C: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009080: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009084: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009088: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000908C: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80009090: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009094: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80009098: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8000909C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800090A0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800090A4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800090A8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800090AC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800090B0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800090B4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800090B8: jr          $ra
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
    return;
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
;}
RECOMP_FUNC void audspat_calculate_spatial_pan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800090C0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800090C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800090C8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800090CC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800090D4: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800090D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800090DC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800090E0: jal         0x800CA030
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800090E8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800090EC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090F0: jal         0x80070990
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800090F8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800090FC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80009100: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x80009104: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009108: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000910C: beq         $at, $zero, L_800091CC
    if (ctx->r1 == 0) {
        // 0x80009110: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800091CC;
    }
    // 0x80009110: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80009114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000911C: subu        $a0, $a2, $a1
    ctx->r4 = SUB32(ctx->r6, ctx->r5);
    // 0x80009120: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80009124: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80009128: bc1f        L_800091A8
    if (!c1cs) {
        // 0x8000912C: nop
    
            goto L_800091A8;
    }
    // 0x8000912C: nop

    // 0x80009130: subu        $a0, $a2, $v1
    ctx->r4 = SUB32(ctx->r6, ctx->r3);
    // 0x80009134: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80009138: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000913C: jal         0x80070A70
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80009144: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009148: bgez        $v0, L_80009158
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000914C: sra         $t9, $v0, 10
        ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009158;
    }
    // 0x8000914C: sra         $t9, $v0, 10
    ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009150: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009154: sra         $t9, $at, 10
    ctx->r25 = S32(SIGNED(ctx->r1) >> 10);
L_80009158:
    // 0x80009158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000915C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009160: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009164: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80009168: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8000916C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009170: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009174: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80009178: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000917C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80009180: nop

    // 0x80009184: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80009188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000918C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009190: nop

    // 0x80009194: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80009198: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8000919C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800091A0: b           L_8000927C
    // 0x800091A4: nop

        goto L_8000927C;
    // 0x800091A4: nop

L_800091A8:
    // 0x800091A8: jal         0x80070AD0
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    sins_2(rdram, ctx);
        goto after_3;
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_3:
    // 0x800091B0: bgez        $v0, L_800091C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800091B4: sra         $t3, $v0, 10
        ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
            goto L_800091C0;
    }
    // 0x800091B4: sra         $t3, $v0, 10
    ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
    // 0x800091B8: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x800091BC: sra         $t3, $at, 10
    ctx->r11 = S32(SIGNED(ctx->r1) >> 10);
L_800091C0:
    // 0x800091C0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800091C4: b           L_8000927C
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
        goto L_8000927C;
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
L_800091CC:
    // 0x800091CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800091D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800091D4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091D8: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x800091DC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800091E0: bc1f        L_80009260
    if (!c1cs) {
        // 0x800091E4: nop
    
            goto L_80009260;
    }
    // 0x800091E4: nop

    // 0x800091E8: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091EC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800091F0: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800091F4: jal         0x80070A70
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    sins_s16(rdram, ctx);
        goto after_4;
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800091FC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009200: bgez        $v0, L_80009210
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009204: sra         $t7, $v0, 10
        ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009210;
    }
    // 0x80009204: sra         $t7, $v0, 10
    ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009208: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x8000920C: sra         $t7, $at, 10
    ctx->r15 = S32(SIGNED(ctx->r1) >> 10);
L_80009210:
    // 0x80009210: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009218: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000921C: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80009220: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80009224: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009228: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000922C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80009230: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80009234: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80009238: nop

    // 0x8000923C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80009240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009248: nop

    // 0x8000924C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009250: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80009254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80009258: b           L_8000927C
    // 0x8000925C: nop

        goto L_8000927C;
    // 0x8000925C: nop

L_80009260:
    // 0x80009260: jal         0x80070AD0
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_2(rdram, ctx);
        goto after_5;
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_5:
    // 0x80009268: bgez        $v0, L_80009278
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000926C: sra         $v1, $v0, 10
        ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009278;
    }
    // 0x8000926C: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009270: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009274: sra         $v1, $at, 10
    ctx->r3 = S32(SIGNED(ctx->r1) >> 10);
L_80009278:
    // 0x80009278: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8000927C:
    // 0x8000927C: jal         0x8009C850
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_6;
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_6:
    // 0x80009284: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80009288: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8000928C: beq         $t1, $zero, L_80009298
    if (ctx->r9 == 0) {
        // 0x80009290: addiu       $t2, $zero, 0x80
        ctx->r10 = ADD32(0, 0X80);
            goto L_80009298;
    }
    // 0x80009290: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80009294: subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
L_80009298:
    // 0x80009298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000929C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800092A0: jr          $ra
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void audspat_distance_to_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800092A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800092AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800092B0: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800092B4: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800092B8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800092BC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800092C0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800092C4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800092C8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800092CC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800092D0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800092D4: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800092D8: lwc1        $f20, 0x0($a3)
    ctx->f20.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800092DC: lwc1        $f22, 0x4($a3)
    ctx->f22.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800092E0: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800092E4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800092E8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800092EC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800092F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800092F4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800092F8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800092FC: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80009300: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80009304: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009308: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8000930C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80009310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009314: sub.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x80009318: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8000931C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80009320: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009324: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80009328: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
    // 0x8000932C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80009330: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009334: mov.s       $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
            goto L_8000936C;
    }
    // 0x80009334: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
    // 0x80009338: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000933C: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80009340: nop

    // 0x80009344: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009348: nop
    
            goto L_8000936C;
    }
    // 0x80009348: nop

    // 0x8000934C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80009350: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009354: nop

    // 0x80009358: bc1f        L_8000936C
    if (!c1cs) {
        // 0x8000935C: nop
    
            goto L_8000936C;
    }
    // 0x8000935C: nop

    // 0x80009360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009364: b           L_800093BC
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_800093BC;
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8000936C:
    // 0x8000936C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009370: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009374: sub.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80009378: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000937C: sub.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80009380: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80009384: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009388: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000938C: sub.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80009390: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80009394: nop

    // 0x80009398: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000939C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800093A0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800093A4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800093A8: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800093AC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800093B0: nop

    // 0x800093B4: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800093B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800093BC:
    // 0x800093BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800093C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800093C4: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800093C8: bc1f        L_8000941C
    if (!c1cs) {
        // 0x800093CC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000941C;
    }
    // 0x800093CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800093D0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800093D4: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x800093D8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800093DC: nop

    // 0x800093E0: swc1        $f24, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f24.u32l;
    // 0x800093E4: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800093E8: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800093EC: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x800093F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800093F4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800093F8: sub.s       $f2, $f22, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800093FC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009400: sub.s       $f14, $f24, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x80009404: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000940C: jal         0x800CA030
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80009414: b           L_8000951C
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000941C:
    // 0x8000941C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009420: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80009424: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80009428: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000942C: bc1f        L_800094A0
    if (!c1cs) {
        // 0x80009430: nop
    
            goto L_800094A0;
    }
    // 0x80009430: nop

    // 0x80009434: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009438: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8000943C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80009440: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009444: nop

    // 0x80009448: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8000944C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80009450: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009454: nop

    // 0x80009458: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8000945C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009460: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009464: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009468: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000946C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009470: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009474: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80009478: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000947C: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80009480: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009484: nop

    // 0x80009488: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000948C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80009490: jal         0x800CA030
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_1:
    // 0x80009498: b           L_8000951C
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_800094A0:
    // 0x800094A0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800094A4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800094A8: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800094AC: add.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800094B0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800094B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800094B8: nop

    // 0x800094BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800094C0: add.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800094C4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800094C8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800094CC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800094D0: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800094D4: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800094D8: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800094DC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800094E0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800094E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800094E8: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800094EC: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800094F0: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800094F4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800094F8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800094FC: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009500: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009504: nop

    // 0x80009508: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000950C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80009510: jal         0x800CA030
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x80009518: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000951C:
    // 0x8000951C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80009520: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80009524: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009528: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000952C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80009530: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80009534: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80009538: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8000953C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80009540: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009544: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80009548: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000954C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80009550: jr          $ra
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void audspat_play_sound_at_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009558: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000955C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009560: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80009564: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80009568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000956C: lw          $t6, -0x5E40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E40);
    // 0x80009570: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80009574: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80009578: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000957C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009580: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80009584: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80009588: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000958C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80009590: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x80009594: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009598: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000959C: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x800095A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800095A4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800095A8: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x800095AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800095B0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800095B4: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x800095B8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800095BC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800095C0: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800095C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800095C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800095CC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800095D0: jal         0x8000974C
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x800095D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800095DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800095E0: jr          $ra
    // 0x800095E4: nop

    return;
    // 0x800095E4: nop

;}
RECOMP_FUNC void audspat_play_sound_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800095E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800095EC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800095F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800095F4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800095F8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800095FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009600: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80009604: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80009608: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000960C: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80009610: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80009614: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009618: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000961C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80009620: addiu       $t0, $zero, 0x3A98
    ctx->r8 = ADD32(0, 0X3A98);
    // 0x80009624: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80009628: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8000962C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009630: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80009634: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009638: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8000963C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80009640: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80009644: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80009648: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000964C: beq         $t2, $zero, L_8000969C
    if (ctx->r10 == 0) {
        // 0x80009650: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8000969C;
    }
    // 0x80009650: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80009654: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80009658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000965C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80009660: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80009664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009668: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000966C: nop

    // 0x80009670: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009674: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80009678: nop

    // 0x8000967C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009680: bne         $t2, $zero, L_80009694
    if (ctx->r10 != 0) {
        // 0x80009684: nop
    
            goto L_80009694;
    }
    // 0x80009684: nop

    // 0x80009688: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8000968C: b           L_800096AC
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800096AC;
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80009694:
    // 0x80009694: b           L_800096AC
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800096AC;
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8000969C:
    // 0x8000969C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800096A0: nop

    // 0x800096A4: bltz        $t2, L_80009694
    if (SIGNED(ctx->r10) < 0) {
        // 0x800096A8: nop
    
            goto L_80009694;
    }
    // 0x800096A8: nop

L_800096AC:
    // 0x800096AC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800096B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800096B4: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x800096B8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800096BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800096C0: jal         0x8000974C
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x800096C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800096CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800096D0: jr          $ra
    // 0x800096D4: nop

    return;
    // 0x800096D4: nop

;}
RECOMP_FUNC void audspat_point_set_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800096DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800096E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800096E4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800096E8: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x800096EC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800096F0: jr          $ra
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void audspat_point_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800096FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009700: lw          $v0, -0x5E3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E3C);
    // 0x80009704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000970C: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
L_80009710:
    // 0x80009710: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80009714: nop

    // 0x80009718: bne         $a0, $t6, L_80009730
    if (ctx->r4 != ctx->r14) {
        // 0x8000971C: nop
    
            goto L_80009730;
    }
    // 0x8000971C: nop

    // 0x80009720: jal         0x8000A2E8
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    audspat_point_stop_by_index(rdram, ctx);
        goto after_0;
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80009728: b           L_80009740
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009740;
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009730:
    // 0x80009730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80009734: bne         $a1, $v1, L_80009710
    if (ctx->r5 != ctx->r3) {
        // 0x80009738: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80009710;
    }
    // 0x80009738: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009740:
    // 0x80009740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009744: jr          $ra
    // 0x80009748: nop

    return;
    // 0x80009748: nop

;}
RECOMP_FUNC void audspat_point_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000974C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009750: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80009754: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000975C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80009760: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80009764: beq         $a1, $zero, L_8000978C
    if (ctx->r5 == 0) {
        // 0x80009768: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8000978C;
    }
    // 0x80009768: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000976C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009770: nop

    // 0x80009774: ori         $t6, $a0, 0xE000
    ctx->r14 = ctx->r4 | 0XE000;
    // 0x80009778: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000977C: jal         0x800245E8
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80009784: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009788: nop

L_8000978C:
    // 0x8000978C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80009790: addiu       $a0, $a0, -0x33B0
    ctx->r4 = ADD32(ctx->r4, -0X33B0);
    // 0x80009794: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80009798: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8000979C: bne         $t9, $at, L_800097C0
    if (ctx->r25 != ctx->r1) {
        // 0x800097A0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800097C0;
    }
    // 0x800097A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800097A4: beq         $a1, $zero, L_800097B0
    if (ctx->r5 == 0) {
        // 0x800097A8: nop
    
            goto L_800097B0;
    }
    // 0x800097A8: nop

    // 0x800097AC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800097B0:
    // 0x800097B0: jal         0x800245E8
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    after_1:
    // 0x800097B8: b           L_80009898
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009898;
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800097C0:
    // 0x800097C0: addiu       $a2, $a2, -0x5E34
    ctx->r6 = ADD32(ctx->r6, -0X5E34);
    // 0x800097C4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800097C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800097CC: lw          $t0, -0x5E30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E30);
    // 0x800097D0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800097D4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800097D8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800097DC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800097E0: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800097E4: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800097E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800097EC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800097F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800097F4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800097F8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800097FC: nop

    // 0x80009800: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80009804: lhu         $t4, 0x1A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009808: nop

    // 0x8000980C: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x80009810: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80009814: nop

    // 0x80009818: sb          $t5, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r13;
    // 0x8000981C: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80009820: nop

    // 0x80009824: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x80009828: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8000982C: nop

    // 0x80009830: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x80009834: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80009838: nop

    // 0x8000983C: sb          $t8, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r24;
    // 0x80009840: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80009844: nop

    // 0x80009848: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8000984C: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80009850: nop

    // 0x80009854: sb          $t0, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r8;
    // 0x80009858: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x8000985C: sb          $zero, 0x22($v0)
    MEM_B(0X22, ctx->r2) = 0;
    // 0x80009860: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x80009864: sb          $t1, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r9;
    // 0x80009868: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8000986C: lw          $t2, -0x5E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E3C);
    // 0x80009870: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80009874: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80009878: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000987C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80009880: nop

    // 0x80009884: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80009888: beq         $a1, $zero, L_80009894
    if (ctx->r5 == 0) {
        // 0x8000988C: sh          $t7, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r15;
            goto L_80009894;
    }
    // 0x8000988C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80009890: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80009894:
    // 0x80009894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009898:
    // 0x80009898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000989C: jr          $ra
    // 0x800098A0: nop

    return;
    // 0x800098A0: nop

;}
RECOMP_FUNC void audspat_line_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800098A8: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x800098AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800098B0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800098B4: lbu         $a3, 0x3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3);
    // 0x800098B8: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x800098BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800098C0: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098C4: andi        $t6, $a1, 0xFFFF
        ctx->r14 = ctx->r5 & 0XFFFF;
            goto L_80009960;
    }
    // 0x800098C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800098C8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    // 0x800098CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800098D0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800098D4: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098D8: subu        $t7, $t7, $a2
        ctx->r15 = SUB32(ctx->r15, ctx->r6);
            goto L_80009960;
    }
    // 0x800098D8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800098DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800098E0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800098E4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800098E8: addiu       $t8, $t8, -0x5E28
    ctx->r24 = ADD32(ctx->r24, -0X5E28);
    // 0x800098EC: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x800098F0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800098F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800098F8: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800098FC: addu        $a0, $v1, $t0
    ctx->r4 = ADD32(ctx->r3, ctx->r8);
    // 0x80009900: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80009904: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    // 0x80009908: bne         $v0, $zero, L_80009948
    if (ctx->r2 != 0) {
        // 0x8000990C: swc1        $f4, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
            goto L_80009948;
    }
    // 0x8000990C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80009910: sw          $t6, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->r14;
    // 0x80009914: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x80009918: lbu         $t2, 0x2B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2B);
    // 0x8000991C: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x80009920: lbu         $t4, 0x17($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X17);
    // 0x80009924: lbu         $t5, 0x1F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1F);
    // 0x80009928: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8000992C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80009930: sw          $t1, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r9;
    // 0x80009934: sb          $t2, 0x17D($v1)
    MEM_B(0X17D, ctx->r3) = ctx->r10;
    // 0x80009938: sb          $t3, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r11;
    // 0x8000993C: sb          $t4, 0x175($v1)
    MEM_B(0X175, ctx->r3) = ctx->r12;
    // 0x80009940: sb          $t5, 0x176($v1)
    MEM_B(0X176, ctx->r3) = ctx->r13;
    // 0x80009944: sb          $t6, 0x17E($v1)
    MEM_B(0X17E, ctx->r3) = ctx->r14;
L_80009948:
    // 0x80009948: lb          $t7, 0x17C($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X17C);
    // 0x8000994C: nop

    // 0x80009950: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009954: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x80009958: nop
    
            goto L_80009960;
    }
    // 0x80009958: nop

    // 0x8000995C: sb          $v0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r2;
L_80009960:
    // 0x80009960: jr          $ra
    // 0x80009964: nop

    return;
    // 0x80009964: nop

;}
RECOMP_FUNC void audspat_reverb_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009968: lbu         $a0, 0x13($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X13);
    // 0x8000996C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80009970: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80009974: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80009978: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x8000997C: andi        $t6, $a3, 0xFF
        ctx->r14 = ctx->r7 & 0XFF;
            goto L_800099E4;
    }
    // 0x8000997C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80009980: lbu         $v0, 0x17($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X17);
    // 0x80009984: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80009988: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8000998C: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x80009990: subu        $t7, $t7, $a0
        ctx->r15 = SUB32(ctx->r15, ctx->r4);
            goto L_800099E4;
    }
    // 0x80009990: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80009994: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009998: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000999C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800099A0: addiu       $t8, $t8, -0x53A8
    ctx->r24 = ADD32(ctx->r24, -0X53A8);
    // 0x800099A4: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x800099A8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800099AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800099B0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800099B4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x800099B8: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800099BC: swc1        $f14, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f14.u32l;
    // 0x800099C0: bne         $v0, $zero, L_800099CC
    if (ctx->r2 != 0) {
        // 0x800099C4: swc1        $f4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
            goto L_800099CC;
    }
    // 0x800099C4: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x800099C8: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_800099CC:
    // 0x800099CC: lb          $t1, 0xB8($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XB8);
    // 0x800099D0: nop

    // 0x800099D4: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800099D8: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x800099DC: nop
    
            goto L_800099E4;
    }
    // 0x800099DC: nop

    // 0x800099E0: sb          $v0, 0xB8($v1)
    MEM_B(0XB8, ctx->r3) = ctx->r2;
L_800099E4:
    // 0x800099E4: jr          $ra
    // 0x800099E8: nop

    return;
    // 0x800099E8: nop

;}
RECOMP_FUNC void audspat_line_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099EC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800099F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800099F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800099F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800099FC: addiu       $t8, $t8, -0x5E28
    ctx->r24 = ADD32(ctx->r24, -0X5E28);
    // 0x80009A00: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x80009A04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009A08: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009A0C: lb          $a3, 0x17C($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009A14: bgtz        $a3, L_80009A24
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009A18: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009A24;
    }
    // 0x80009A18: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009A1C: jr          $ra
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A24:
    // 0x80009A24: blez        $a3, L_80009AA8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009A28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009AA8;
    }
    // 0x80009A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009A2C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009A30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009A40: lwc1        $f3, 0x54A8($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X54A8);
    // 0x80009A44: lwc1        $f2, 0x54AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X54AC);
    // 0x80009A48: lb          $a1, 0x17C($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A4C: nop

L_80009A50:
    // 0x80009A50: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009A54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009A58: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009A5C: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009A60: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009A64: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A68: nop
    
            goto L_80009A9C;
    }
    // 0x80009A68: nop

    // 0x80009A6C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009A70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009A74: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009A78: nop

    // 0x80009A7C: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A80: nop
    
            goto L_80009A9C;
    }
    // 0x80009A80: nop

    // 0x80009A84: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009A88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009A8C: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009A90: nop

    // 0x80009A94: bc1f        L_80009AA0
    if (!c1cs) {
        // 0x80009A98: nop
    
            goto L_80009AA0;
    }
    // 0x80009A98: nop

L_80009A9C:
    // 0x80009A9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009AA0:
    // 0x80009AA0: bne         $at, $zero, L_80009A50
    if (ctx->r1 != 0) {
        // 0x80009AA4: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009A50;
    }
    // 0x80009AA4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009AA8:
    // 0x80009AA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009AAC: jr          $ra
    // 0x80009AB0: nop

    return;
    // 0x80009AB0: nop

;}
RECOMP_FUNC void audspat_reverb_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009AB4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80009AB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009ABC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009AC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009AC4: addiu       $t8, $t8, -0x53A8
    ctx->r24 = ADD32(ctx->r24, -0X53A8);
    // 0x80009AC8: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x80009ACC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009AD0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009AD4: lb          $a3, 0xB8($v0)
    ctx->r7 = MEM_B(ctx->r2, 0XB8);
    // 0x80009AD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009ADC: bgtz        $a3, L_80009AEC
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009AE0: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009AEC;
    }
    // 0x80009AE0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009AE4: jr          $ra
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009AEC:
    // 0x80009AEC: blez        $a3, L_80009B70
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009AF0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009B70;
    }
    // 0x80009AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009AF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009AF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009B00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009B08: lwc1        $f3, 0x54B0($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X54B0);
    // 0x80009B0C: lwc1        $f2, 0x54B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X54B4);
    // 0x80009B10: lb          $a1, 0xB8($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XB8);
    // 0x80009B14: nop

L_80009B18:
    // 0x80009B18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009B1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009B20: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009B24: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009B28: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009B2C: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B30: nop
    
            goto L_80009B64;
    }
    // 0x80009B30: nop

    // 0x80009B34: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009B38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009B3C: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009B40: nop

    // 0x80009B44: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B48: nop
    
            goto L_80009B64;
    }
    // 0x80009B48: nop

    // 0x80009B4C: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009B50: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009B54: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009B58: nop

    // 0x80009B5C: bc1f        L_80009B68
    if (!c1cs) {
        // 0x80009B60: nop
    
            goto L_80009B68;
    }
    // 0x80009B60: nop

L_80009B64:
    // 0x80009B64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009B68:
    // 0x80009B68: bne         $at, $zero, L_80009B18
    if (ctx->r1 != 0) {
        // 0x80009B6C: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009B18;
    }
    // 0x80009B6C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009B70:
    // 0x80009B70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009B74: jr          $ra
    // 0x80009B78: nop

    return;
    // 0x80009B78: nop

;}
RECOMP_FUNC void audspat_calculate_echo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B7C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80009B80: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80009B84: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80009B88: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80009B8C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80009B90: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80009B94: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80009B98: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80009B9C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009BA0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80009BA4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80009BA8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80009BAC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80009BB0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80009BB4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80009BB8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80009BBC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80009BC0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80009BC4: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009BC8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009BCC: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009BD0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80009BD4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009BD8: jal         0x80029F58
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80009BE0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80009BE4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x80009BE8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80009BEC: addiu       $s6, $zero, 0x190
    ctx->r22 = ADD32(0, 0X190);
    // 0x80009BF0: addiu       $s7, $s7, -0x53A8
    ctx->r23 = ADD32(ctx->r23, -0X53A8);
    // 0x80009BF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009BF8:
    // 0x80009BF8: lbu         $t6, 0x0($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X0);
    // 0x80009BFC: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x80009C00: beq         $t6, $zero, L_80009CF8
    if (ctx->r14 == 0) {
        // 0x80009C04: sw          $v1, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->r3;
            goto L_80009CF8;
    }
    // 0x80009C04: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    // 0x80009C08: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80009C0C: jal         0x80009AB4
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    audspat_reverb_validate(rdram, ctx);
        goto after_1;
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    after_1:
    // 0x80009C14: beq         $v0, $zero, L_80009CFC
    if (ctx->r2 == 0) {
        // 0x80009C18: lw          $v1, 0xD4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XD4);
            goto L_80009CFC;
    }
    // 0x80009C18: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x80009C1C: lb          $t7, 0xB8($s7)
    ctx->r15 = MEM_B(ctx->r23, 0XB8);
    // 0x80009C20: addiu       $fp, $s7, 0x4
    ctx->r30 = ADD32(ctx->r23, 0X4);
    // 0x80009C24: blez        $t7, L_80009CF8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80009C28: sw          $zero, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = 0;
            goto L_80009CF8;
    }
    // 0x80009C28: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_80009C2C:
    // 0x80009C2C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C30: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x80009C34: addiu       $t9, $sp, 0xC0
    ctx->r25 = ADD32(ctx->r29, 0XC0);
    // 0x80009C38: addiu       $t0, $sp, 0xBC
    ctx->r8 = ADD32(ctx->r29, 0XBC);
    // 0x80009C3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80009C40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80009C44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80009C48: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80009C4C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009C50: jal         0x800092A8
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_2;
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x80009C58: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80009C5C: beq         $at, $zero, L_80009CD4
    if (ctx->r1 == 0) {
        // 0x80009C60: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80009CD4;
    }
    // 0x80009C60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80009C64: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80009C68: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80009C6C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C70: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x80009C74: jal         0x8002BAF0
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    collision_get_y(rdram, ctx);
        goto after_3;
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_3:
    // 0x80009C7C: blez        $v0, L_80009CD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80009C80: addiu       $s0, $sp, 0x7C
        ctx->r16 = ADD32(ctx->r29, 0X7C);
            goto L_80009CD4;
    }
    // 0x80009C80: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80009C84: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80009C88: addu        $s4, $t2, $s0
    ctx->r20 = ADD32(ctx->r10, ctx->r16);
L_80009C8C:
    // 0x80009C8C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009C90: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80009C94: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009C98: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80009C9C: bc1f        L_80009CC4
    if (!c1cs) {
        // 0x80009CA0: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80009CC4;
    }
    // 0x80009CA0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80009CA4: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80009CA8: or          $s6, $s3, $zero
    ctx->r22 = ctx->r19 | 0;
    // 0x80009CAC: jal         0x80009D6C
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    audspat_reverb_get_strength_at_point(rdram, ctx);
        goto after_4;
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    after_4:
    // 0x80009CB4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009CB8: beq         $at, $zero, L_80009CC4
    if (ctx->r1 == 0) {
        // 0x80009CBC: nop
    
            goto L_80009CC4;
    }
    // 0x80009CBC: nop

    // 0x80009CC0: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
L_80009CC4:
    // 0x80009CC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80009CC8: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x80009CCC: bne         $at, $zero, L_80009C8C
    if (ctx->r1 != 0) {
        // 0x80009CD0: nop
    
            goto L_80009C8C;
    }
    // 0x80009CD0: nop

L_80009CD4:
    // 0x80009CD4: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x80009CD8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x80009CDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009CE0: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x80009CE4: lb          $t4, 0xB8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0XB8);
    // 0x80009CE8: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
    // 0x80009CEC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80009CF0: bne         $at, $zero, L_80009C2C
    if (ctx->r1 != 0) {
        // 0x80009CF4: nop
    
            goto L_80009C2C;
    }
    // 0x80009CF4: nop

L_80009CF8:
    // 0x80009CF8: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
L_80009CFC:
    // 0x80009CFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80009D00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80009D04: bne         $v1, $at, L_80009BF8
    if (ctx->r3 != ctx->r1) {
        // 0x80009D08: addiu       $s7, $s7, 0xC0
        ctx->r23 = ADD32(ctx->r23, 0XC0);
            goto L_80009BF8;
    }
    // 0x80009D08: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x80009D0C: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80009D10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80009D14: beq         $a0, $zero, L_80009D28
    if (ctx->r4 == 0) {
        // 0x80009D18: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80009D28;
    }
    // 0x80009D18: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80009D1C: jal         0x800049F8
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80009D24: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80009D28:
    // 0x80009D28: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009D2C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80009D30: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009D34: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009D38: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009D3C: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80009D40: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80009D44: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80009D48: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80009D4C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80009D50: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80009D54: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80009D58: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80009D5C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80009D60: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80009D64: jr          $ra
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void audspat_reverb_get_strength_at_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D6C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80009D70: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80009D74: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80009D78: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80009D7C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80009D80: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80009D84: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80009D88: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80009D8C: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80009D90: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80009D94: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80009D98: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009D9C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009DA0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80009DA4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009DA8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80009DAC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80009DB0: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80009DB4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80009DB8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80009DBC: lwc1        $f4, 0xBC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XBC);
    // 0x80009DC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80009DC4: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80009DC8: nop

    // 0x80009DCC: bc1f        L_80009E70
    if (!c1cs) {
        // 0x80009DD0: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80009E70;
    }
    // 0x80009DD0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80009DD4: lb          $t6, 0xB8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XB8);
    // 0x80009DD8: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80009DDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80009DE0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80009DE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80009DE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009DEC: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x80009DF0: nop

    // 0x80009DF4: bc1f        L_80009E6C
    if (!c1cs) {
        // 0x80009DF8: nop
    
            goto L_80009E6C;
    }
    // 0x80009DF8: nop

    // 0x80009DFC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80009E00: nop

L_80009E04:
    // 0x80009E04: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E08: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E0C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E10: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E14: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E18: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E1C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009E20: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E24: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80009E28: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E2C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009E30: nop

    // 0x80009E34: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009E38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009E3C: jal         0x800CA030
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_0:
    // 0x80009E44: lb          $t7, 0xB8($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XB8);
    // 0x80009E48: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80009E4C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80009E50: lwc1        $f6, 0xBC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x80009E54: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009E58: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80009E5C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009E60: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80009E64: bc1t        L_80009E04
    if (c1cs) {
        // 0x80009E68: swc1        $f8, 0xBC($s1)
        MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
            goto L_80009E04;
    }
    // 0x80009E68: swc1        $f8, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
L_80009E6C:
    // 0x80009E6C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80009E70:
    // 0x80009E70: mov.s       $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    ctx->f16.fl = ctx->f24.fl;
    // 0x80009E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009E78:
    // 0x80009E78: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E7C: lwc1        $f20, 0xC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E80: lwc1        $f30, 0x4($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E84: sub.s       $f24, $f20, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80009E88: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E8C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80009E90: sub.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80009E94: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E98: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E9C: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80009EA0: sub.s       $f28, $f2, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80009EA4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80009EA8: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80009EAC: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80009EB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009EB4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80009EB8: jal         0x800CA030
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x80009EC0: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EC4: lbu         $v0, 0x57($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X57);
    // 0x80009EC8: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80009ECC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80009ED0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80009ED4: bc1f        L_80009EEC
    if (!c1cs) {
        // 0x80009ED8: nop
    
            goto L_80009EEC;
    }
    // 0x80009ED8: nop

    // 0x80009EDC: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x80009EE0: nop

    // 0x80009EE4: bc1t        L_80009F14
    if (c1cs) {
        // 0x80009EE8: nop
    
            goto L_80009F14;
    }
    // 0x80009EE8: nop

L_80009EEC:
    // 0x80009EEC: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EF0: nop

    // 0x80009EF4: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x80009EF8: nop

    // 0x80009EFC: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F00: nop
    
            goto L_8000A020;
    }
    // 0x80009F00: nop

    // 0x80009F04: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x80009F08: nop

    // 0x80009F0C: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F10: nop
    
            goto L_8000A020;
    }
    // 0x80009F10: nop

L_80009F14:
    // 0x80009F14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009F18: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009F1C: c.eq.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl == ctx->f10.fl;
    // 0x80009F20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F24: bc1t        L_80009F38
    if (c1cs) {
        // 0x80009F28: nop
    
            goto L_80009F38;
    }
    // 0x80009F28: nop

    // 0x80009F2C: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80009F30: b           L_80009F7C
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
        goto L_80009F7C;
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
L_80009F38:
    // 0x80009F38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80009F3C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F40: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x80009F44: nop

    // 0x80009F48: bc1t        L_80009F5C
    if (c1cs) {
        // 0x80009F4C: nop
    
            goto L_80009F5C;
    }
    // 0x80009F4C: nop

    // 0x80009F50: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x80009F54: b           L_80009F7C
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
        goto L_80009F7C;
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
L_80009F5C:
    // 0x80009F5C: c.eq.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl == ctx->f2.fl;
    // 0x80009F60: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009F64: bc1t        L_80009F78
    if (c1cs) {
        // 0x80009F68: nop
    
            goto L_80009F78;
    }
    // 0x80009F68: nop

    // 0x80009F6C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80009F70: b           L_80009F7C
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
        goto L_80009F7C;
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
L_80009F78:
    // 0x80009F78: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80009F7C:
    // 0x80009F7C: mul.s       $f8, $f26, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f12.fl);
    // 0x80009F80: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009F88: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F8C: add.s       $f2, $f8, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80009F90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F94: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009F98: nop

    // 0x80009F9C: bc1f        L_80009FAC
    if (!c1cs) {
        // 0x80009FA0: nop
    
            goto L_80009FAC;
    }
    // 0x80009FA0: nop

    // 0x80009FA4: b           L_80009FB4
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FB4;
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FAC:
    // 0x80009FAC: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FB0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FB4:
    // 0x80009FB4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FB8: nop

    // 0x80009FBC: bc1f        L_8000A018
    if (!c1cs) {
        // 0x80009FC0: nop
    
            goto L_8000A018;
    }
    // 0x80009FC0: nop

    // 0x80009FC4: mul.s       $f8, $f28, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80009FC8: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009FD0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FD4: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80009FD8: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009FDC: nop

    // 0x80009FE0: bc1f        L_80009FF0
    if (!c1cs) {
        // 0x80009FE4: nop
    
            goto L_80009FF0;
    }
    // 0x80009FE4: nop

    // 0x80009FE8: b           L_80009FF8
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FF8;
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FF0:
    // 0x80009FF0: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FF4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FF8:
    // 0x80009FF8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FFC: nop

    // 0x8000A000: bc1f        L_8000A018
    if (!c1cs) {
        // 0x8000A004: nop
    
            goto L_8000A018;
    }
    // 0x8000A004: nop

    // 0x8000A008: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000A00C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A010: b           L_8000A024
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
        goto L_8000A024;
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8000A018:
    // 0x8000A018: b           L_8000A024
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
        goto L_8000A024;
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A020:
    // 0x8000A020: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A024:
    // 0x8000A024: beq         $v0, $zero, L_80009E78
    if (ctx->r2 == 0) {
        // 0x8000A028: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80009E78;
    }
    // 0x8000A028: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8000A02C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000A030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A034: lwc1        $f0, 0xBC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8000A038: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8000A03C: div.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000A040: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A044: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8000A048: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8000A04C: nop

    // 0x8000A050: bc1f        L_8000A05C
    if (!c1cs) {
        // 0x8000A054: nop
    
            goto L_8000A05C;
    }
    // 0x8000A054: nop

    // 0x8000A058: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
L_8000A05C:
    // 0x8000A05C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000A060: nop

    // 0x8000A064: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000A068: nop

    // 0x8000A06C: bc1f        L_8000A140
    if (!c1cs) {
        // 0x8000A070: nop
    
            goto L_8000A140;
    }
    // 0x8000A070: nop

    // 0x8000A074: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A078: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A07C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8000A080: bgez        $t8, L_8000A094
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000A084: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000A094;
    }
    // 0x8000A084: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A088: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A08C: nop

    // 0x8000A090: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8000A094:
    // 0x8000A094: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000A098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A09C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000A0A0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000A0A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A0A8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0AC: nop

    // 0x8000A0B0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000A0B4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0B8: nop

    // 0x8000A0BC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0C0: beq         $v0, $zero, L_8000A124
    if (ctx->r2 == 0) {
        // 0x8000A0C4: nop
    
            goto L_8000A124;
    }
    // 0x8000A0C4: nop

    // 0x8000A0C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A0D0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8000A0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000A0D8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0DC: nop

    // 0x8000A0E0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000A0E4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0E8: nop

    // 0x8000A0EC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0F0: bne         $v0, $zero, L_8000A114
    if (ctx->r2 != 0) {
        // 0x8000A0F4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000A114;
    }
    // 0x8000A0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000A0F8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A0FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A100: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8000A104: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A108: b           L_8000A148
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A110:
    // 0x8000A110: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000A114:
    // 0x8000A114: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A118: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A11C: b           L_8000A148
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A124:
    // 0x8000A124: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A128: nop

    // 0x8000A12C: bltz        $v0, L_8000A110
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A130: andi        $t0, $v0, 0xFF
        ctx->r8 = ctx->r2 & 0XFF;
            goto L_8000A110;
    }
    // 0x8000A130: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A134: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A138: b           L_8000A148
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A140:
    // 0x8000A140: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A144: nop

L_8000A148:
    // 0x8000A148: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000A14C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000A150: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000A154: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000A158: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000A15C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000A160: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8000A164: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000A168: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8000A16C: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000A170: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8000A174: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000A178: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8000A17C: jr          $ra
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void audspat_debug_render_lines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A184: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000A188: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000A18C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000A190: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000A194: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000A198: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A19C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A1A0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A1A4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A1A8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A1AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000A1B0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8000A1B4: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8000A1B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000A1BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A1C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A1C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A1C8: addiu       $fp, $fp, -0x53A4
    ctx->r30 = ADD32(ctx->r30, -0X53A4);
    // 0x8000A1CC: addiu       $s7, $s7, -0x5E24
    ctx->r23 = ADD32(ctx->r23, -0X5E24);
    // 0x8000A1D0: addiu       $s6, $s6, -0x5E28
    ctx->r22 = ADD32(ctx->r22, -0X5E28);
L_8000A1D4:
    // 0x8000A1D4: lw          $t6, 0x16C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X16C);
    // 0x8000A1D8: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A1DC: beq         $t6, $zero, L_8000A22C
    if (ctx->r14 == 0) {
        // 0x8000A1E0: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A22C;
    }
    // 0x8000A1E0: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A1E4: lb          $t7, 0x17C($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X17C);
    // 0x8000A1E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A1EC: blez        $t7, L_8000A22C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A1F0: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8000A22C;
    }
L_8000A1F0:
    // 0x8000A1F0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8000A1F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8000A1F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000A1FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A204: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A208: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A20C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A210: jal         0x8000A414
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_0;
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8000A218: lb          $t0, 0x17C($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X17C);
    // 0x8000A21C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A220: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A224: bne         $at, $zero, L_8000A1F0
    if (ctx->r1 != 0) {
        // 0x8000A228: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A1F0;
    }
    // 0x8000A228: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A22C:
    // 0x8000A22C: addiu       $s7, $s7, 0x180
    ctx->r23 = ADD32(ctx->r23, 0X180);
    // 0x8000A230: sltu        $at, $s7, $fp
    ctx->r1 = ctx->r23 < ctx->r30 ? 1 : 0;
    // 0x8000A234: bne         $at, $zero, L_8000A1D4
    if (ctx->r1 != 0) {
        // 0x8000A238: addiu       $s6, $s6, 0x180
        ctx->r22 = ADD32(ctx->r22, 0X180);
            goto L_8000A1D4;
    }
    // 0x8000A238: addiu       $s6, $s6, 0x180
    ctx->r22 = ADD32(ctx->r22, 0X180);
    // 0x8000A23C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A240: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A244: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A248: addiu       $fp, $fp, -0x4E64
    ctx->r30 = ADD32(ctx->r30, -0X4E64);
    // 0x8000A24C: addiu       $s7, $s7, -0x53A4
    ctx->r23 = ADD32(ctx->r23, -0X53A4);
    // 0x8000A250: addiu       $s6, $s6, -0x53A8
    ctx->r22 = ADD32(ctx->r22, -0X53A8);
L_8000A254:
    // 0x8000A254: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8000A258: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A25C: beq         $t1, $zero, L_8000A2AC
    if (ctx->r9 == 0) {
        // 0x8000A260: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A2AC;
    }
    // 0x8000A260: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A264: lb          $t2, 0xB8($s6)
    ctx->r10 = MEM_B(ctx->r22, 0XB8);
    // 0x8000A268: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A26C: blez        $t2, L_8000A2AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000A270: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8000A2AC;
    }
L_8000A270:
    // 0x8000A270: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8000A274: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000A278: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000A27C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000A280: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A284: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A288: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A28C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A290: jal         0x8000A414
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_1;
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8000A298: lb          $t5, 0xB8($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XB8);
    // 0x8000A29C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A2A0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000A2A4: bne         $at, $zero, L_8000A270
    if (ctx->r1 != 0) {
        // 0x8000A2A8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A270;
    }
    // 0x8000A2A8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A2AC:
    // 0x8000A2AC: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x8000A2B0: bne         $s7, $fp, L_8000A254
    if (ctx->r23 != ctx->r30) {
        // 0x8000A2B4: addiu       $s6, $s6, 0xC0
        ctx->r22 = ADD32(ctx->r22, 0XC0);
            goto L_8000A254;
    }
    // 0x8000A2B4: addiu       $s6, $s6, 0xC0
    ctx->r22 = ADD32(ctx->r22, 0XC0);
    // 0x8000A2B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A2BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A2C0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A2C4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A2C8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A2CC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A2D0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A2D4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000A2D8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000A2DC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000A2E0: jr          $ra
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void audspat_point_stop_by_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2E8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A2EC: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
    // 0x8000A2F0: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A2F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A2F8: beq         $t6, $zero, L_8000A404
    if (ctx->r14 == 0) {
        // 0x8000A2FC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000A404;
    }
    // 0x8000A2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A300: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000A304: lw          $t7, -0x5E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E3C);
    // 0x8000A308: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8000A30C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8000A310: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A314: nop

    // 0x8000A318: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8000A31C: nop

    // 0x8000A320: beq         $a0, $zero, L_8000A34C
    if (ctx->r4 == 0) {
        // 0x8000A324: nop
    
            goto L_8000A34C;
    }
    // 0x8000A324: nop

    // 0x8000A328: jal         0x8000488C
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000A330: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000A334: lw          $t8, -0x5E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E3C);
    // 0x8000A338: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A33C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A340: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8000A344: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A348: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
L_8000A34C:
    // 0x8000A34C: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000A350: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A354: beq         $a2, $zero, L_8000A3A4
    if (ctx->r6 == 0) {
        // 0x8000A358: nop
    
            goto L_8000A3A4;
    }
    // 0x8000A358: nop

    // 0x8000A35C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000A360: lw          $t9, -0x5E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E3C);
    // 0x8000A364: nop

    // 0x8000A368: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8000A36C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000A370: nop

    // 0x8000A374: lhu         $a0, 0xC($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XC);
    // 0x8000A378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A37C: ori         $t2, $a0, 0x5000
    ctx->r10 = ctx->r4 | 0X5000;
    // 0x8000A380: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8000A384: jal         0x800245E8
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_1:
    // 0x8000A38C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000A390: lw          $t5, -0x5E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E3C);
    // 0x8000A394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A398: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A39C: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
    // 0x8000A3A0: addu        $v1, $t5, $a1
    ctx->r3 = ADD32(ctx->r13, ctx->r5);
L_8000A3A4:
    // 0x8000A3A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000A3A8: addiu       $a0, $a0, -0x5E34
    ctx->r4 = ADD32(ctx->r4, -0X5E34);
    // 0x8000A3AC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A3B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A3B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000A3B8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8000A3BC: lw          $t9, -0x5E30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E30);
    // 0x8000A3C0: andi        $t0, $t7, 0xFF
    ctx->r8 = ctx->r15 & 0XFF;
    // 0x8000A3C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000A3C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000A3CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000A3D0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8000A3D4: lhu         $t3, 0x0($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A3DC: lw          $v0, -0x5E3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E3C);
    // 0x8000A3E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000A3E4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8000A3E8: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x8000A3EC: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A3F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8000A3F4: lhu         $t0, 0x0($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3F8: nop

    // 0x8000A3FC: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x8000A400: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_8000A404:
    // 0x8000A404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A40C: jr          $ra
    // 0x8000A410: nop

    return;
    // 0x8000A410: nop

;}
RECOMP_FUNC void audspat_debug_render_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A414: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A418: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A420: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A424: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000A428: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000A42C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000A430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A438: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000A43C: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000A440: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A444: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000A448: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A44C: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8000A450: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000A454: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A458: nop

    // 0x8000A45C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A460: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A464: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A468: nop

    // 0x8000A46C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A470: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8000A474: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A478: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8000A47C: nop

    // 0x8000A480: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000A484: nop

    // 0x8000A488: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000A48C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A490: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A494: nop

    // 0x8000A498: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A49C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8000A4A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000A4A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000A4A8: nop

    // 0x8000A4AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000A4B0: nop

    // 0x8000A4B4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000A4B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4C0: nop

    // 0x8000A4C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A4C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000A4CC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8000A4D0: nop

    // 0x8000A4D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A4D8: nop

    // 0x8000A4DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A4E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4E8: nop

    // 0x8000A4EC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A4F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A4F4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8000A4F8: nop

    // 0x8000A4FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A500: nop

    // 0x8000A504: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A508: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A50C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A510: nop

    // 0x8000A514: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A518: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A51C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8000A520: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8000A524: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A528: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000A52C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000A530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A538: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8000A53C: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    // 0x8000A540: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8000A544: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    // 0x8000A548: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x8000A54C: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
    // 0x8000A550: sh          $t5, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r13;
    // 0x8000A554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000A558: jal         0x8007B918
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000A560: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8000A564: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8000A568: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000A56C: addu        $a1, $v0, $a3
    ctx->r5 = ADD32(ctx->r2, ctx->r7);
    // 0x8000A570: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x8000A574: ori         $t7, $t6, 0x18
    ctx->r15 = ctx->r14 | 0X18;
    // 0x8000A578: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8000A57C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A580: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000A584: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000A588: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8000A58C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A590: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8000A594: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8000A598: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8000A59C: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x8000A5A0: lh          $t4, 0x22($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X22);
    // 0x8000A5A4: lh          $t5, 0x20($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X20);
    // 0x8000A5A8: lbu         $ra, 0x4B($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000A5AC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000A5B0: ori         $t7, $t6, 0x50
    ctx->r15 = ctx->r14 | 0X50;
    // 0x8000A5B4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000A5B8: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8000A5BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8000A5C0: lui         $t6, 0x510
    ctx->r14 = S32(0X510 << 16);
    // 0x8000A5C4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8000A5C8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A5CC: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x8000A5D0: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x8000A5D4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8000A5D8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000A5DC: addiu       $t8, $t1, 0x5
    ctx->r24 = ADD32(ctx->r9, 0X5);
    // 0x8000A5E0: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x8000A5E4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8000A5E8: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x8000A5EC: sb          $ra, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r31;
    // 0x8000A5F0: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A5F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000A5F8: sb          $t9, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r25;
    // 0x8000A5FC: lbu         $a1, 0x53($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X53);
    // 0x8000A600: addiu       $t6, $t1, -0x5
    ctx->r14 = ADD32(ctx->r9, -0X5);
    // 0x8000A604: sb          $a0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r4;
    // 0x8000A608: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x8000A60C: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8000A610: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x8000A614: sb          $ra, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r31;
    // 0x8000A618: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8000A61C: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A620: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x8000A624: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8000A628: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x8000A62C: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x8000A630: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x8000A634: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x8000A638: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x8000A63C: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x8000A640: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x8000A644: addiu       $t8, $t4, 0x5
    ctx->r24 = ADD32(ctx->r12, 0X5);
    // 0x8000A648: addiu       $t9, $t4, -0x5
    ctx->r25 = ADD32(ctx->r12, -0X5);
    // 0x8000A64C: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8000A650: sh          $t8, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r24;
    // 0x8000A654: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x8000A658: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8000A65C: sh          $t3, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r11;
    // 0x8000A660: sh          $t5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r13;
    // 0x8000A664: sh          $t5, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r13;
    // 0x8000A668: sb          $t7, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r15;
    // 0x8000A66C: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    // 0x8000A670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000A674: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8000A67C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8000A680: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000A684: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // 0x8000A688: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x8000A68C: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x8000A690: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000A694: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x8000A698: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x8000A69C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x8000A6A0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8000A6A4: sh          $a1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r5;
    // 0x8000A6A8: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8000A6AC: sb          $a2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r6;
    // 0x8000A6B0: sb          $t6, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r14;
    // 0x8000A6B4: sb          $a3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r7;
    // 0x8000A6B8: sb          $t0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r8;
    // 0x8000A6BC: sh          $a1, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r5;
    // 0x8000A6C0: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x8000A6C4: sh          $a0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r4;
    // 0x8000A6C8: sh          $a0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r4;
    // 0x8000A6CC: sh          $a1, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r5;
    // 0x8000A6D0: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8000A6D4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8000A6D8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000A6DC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8000A6E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000A6E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6E8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8000A6EC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000A6F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000A6F4: nop

    // 0x8000A6F8: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8000A6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A700: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000A704: jr          $ra
    // 0x8000A708: nop

    return;
    // 0x8000A708: nop

    // 0x8000A70C: nop

;}
RECOMP_FUNC void dummy_8000A710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A710: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000A714: jr          $ra
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void __mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A71C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000A728: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A72C: lbu         $t9, 0x70($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X70);
    // 0x8000A730: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A734: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A738: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8000A73C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A740: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A744: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8000A748: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A74C: beq         $at, $zero, L_8000A75C
    if (ctx->r1 == 0) {
        // 0x8000A750: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8000A75C;
    }
    // 0x8000A750: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000A754: jr          $ra
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A75C:
    // 0x8000A75C: beq         $v1, $zero, L_8000A7BC
    if (ctx->r3 == 0) {
        // 0x8000A760: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000A7BC;
    }
    // 0x8000A760: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A764: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000A768: nop

    // 0x8000A76C: sw          $t1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r9;
    // 0x8000A770: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A774: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x8000A778: nop

    // 0x8000A77C: bne         $t2, $zero, L_8000A78C
    if (ctx->r10 != 0) {
        // 0x8000A780: nop
    
            goto L_8000A78C;
    }
    // 0x8000A780: nop

    // 0x8000A784: b           L_8000A798
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_8000A798;
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
L_8000A78C:
    // 0x8000A78C: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x8000A790: nop

    // 0x8000A794: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
L_8000A798:
    // 0x8000A798: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x8000A79C: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x8000A7A0: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x8000A7A4: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x8000A7A8: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
    // 0x8000A7AC: lbu         $t4, 0x71($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A7B0: nop

    // 0x8000A7B4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A7B8: sb          $t5, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r13;
L_8000A7BC:
    // 0x8000A7BC: jr          $ra
    // 0x8000A7C0: nop

    return;
    // 0x8000A7C0: nop

;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7C4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A7CC: beq         $v1, $zero, L_8000A844
    if (ctx->r3 == 0) {
        // 0x8000A7D0: addiu       $a2, $a1, -0x4
        ctx->r6 = ADD32(ctx->r5, -0X4);
            goto L_8000A844;
    }
    // 0x8000A7D0: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
L_8000A7D4:
    // 0x8000A7D4: bne         $v1, $a2, L_8000A830
    if (ctx->r3 != ctx->r6) {
        // 0x8000A7D8: nop
    
            goto L_8000A830;
    }
    // 0x8000A7D8: nop

    // 0x8000A7DC: beq         $v0, $zero, L_8000A7F0
    if (ctx->r2 == 0) {
        // 0x8000A7E0: nop
    
            goto L_8000A7F0;
    }
    // 0x8000A7E0: nop

    // 0x8000A7E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7E8: b           L_8000A7FC
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_8000A7FC;
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000A7F0:
    // 0x8000A7F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7F4: nop

    // 0x8000A7F8: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_8000A7FC:
    // 0x8000A7FC: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x8000A800: nop

    // 0x8000A804: bne         $v1, $t8, L_8000A810
    if (ctx->r3 != ctx->r24) {
        // 0x8000A808: nop
    
            goto L_8000A810;
    }
    // 0x8000A808: nop

    // 0x8000A80C: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
L_8000A810:
    // 0x8000A810: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A814: nop

    // 0x8000A818: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A81C: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A820: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x8000A824: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000A828: jr          $ra
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
    return;
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
L_8000A830:
    // 0x8000A830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A834: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A838: nop

    // 0x8000A83C: bne         $v1, $zero, L_8000A7D4
    if (ctx->r3 != 0) {
        // 0x8000A840: nop
    
            goto L_8000A7D4;
    }
    // 0x8000A840: nop

L_8000A844:
    // 0x8000A844: jr          $ra
    // 0x8000A848: nop

    return;
    // 0x8000A848: nop

;}
RECOMP_FUNC void __lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A84C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A850: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A854: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A858: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A85C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A860: beq         $v1, $zero, L_8000A8C4
    if (ctx->r3 == 0) {
        // 0x8000A864: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_8000A8C4;
    }
    // 0x8000A864: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A868: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000A86C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8000A870: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8000A874:
    // 0x8000A874: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    // 0x8000A878: nop

    // 0x8000A87C: bne         $v0, $t8, L_8000A8B4
    if (ctx->r2 != ctx->r24) {
        // 0x8000A880: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A880: nop

    // 0x8000A884: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x8000A888: nop

    // 0x8000A88C: bne         $a2, $t9, L_8000A8B4
    if (ctx->r6 != ctx->r25) {
        // 0x8000A890: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A890: nop

    // 0x8000A894: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x8000A898: nop

    // 0x8000A89C: beq         $a1, $a0, L_8000A8B4
    if (ctx->r5 == ctx->r4) {
        // 0x8000A8A0: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A0: nop

    // 0x8000A8A4: beq         $a3, $a0, L_8000A8B4
    if (ctx->r7 == ctx->r4) {
        // 0x8000A8A8: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A8: nop

    // 0x8000A8AC: jr          $ra
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000A8B4:
    // 0x8000A8B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A8B8: nop

    // 0x8000A8BC: bne         $v1, $zero, L_8000A874
    if (ctx->r3 != 0) {
        // 0x8000A8C0: nop
    
            goto L_8000A874;
    }
    // 0x8000A8C0: nop

L_8000A8C4:
    // 0x8000A8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A8C8: jr          $ra
    // 0x8000A8CC: nop

    return;
    // 0x8000A8CC: nop

;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000A8D4: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x8000A8D8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8000A8DC: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8000A8E0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8000A8E4: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8000A8E8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000A8EC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000A8F0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8000A8F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A8F8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8000A8FC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8000A900: andi        $s0, $a2, 0xFF
    ctx->r16 = ctx->r6 & 0XFF;
    // 0x8000A904: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x8000A908: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A90C: blez        $t0, L_8000A9E8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000A910: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000A9E8;
    }
    // 0x8000A910: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000A914: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8000A918: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A91C:
    // 0x8000A91C: bgez        $a1, L_8000A92C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000A920: sra         $t4, $a1, 1
        ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8000A92C;
    }
    // 0x8000A920: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000A924: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8000A928: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8000A92C:
    // 0x8000A92C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000A930: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000A934: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x8000A938: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000A93C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8000A940: nop

    // 0x8000A944: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8000A948: nop

    // 0x8000A94C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A950: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A954: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A954: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A958: lbu         $t7, 0x3($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A95C: nop

    // 0x8000A960: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A964: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A968: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A968: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A96C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000A974: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000A978: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A97C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A97C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A980: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x8000A984: nop

    // 0x8000A988: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000A98C: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A990: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A990: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A994: b           L_8000A9EC
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8000A9EC;
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000A99C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_8000A9A0:
    // 0x8000A9A0: bne         $at, $zero, L_8000A9D0
    if (ctx->r1 != 0) {
        // 0x8000A9A4: nop
    
            goto L_8000A9D0;
    }
    // 0x8000A9A4: nop

    // 0x8000A9A8: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A9AC: nop

    // 0x8000A9B0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000A9B4: beq         $at, $zero, L_8000A9D8
    if (ctx->r1 == 0) {
        // 0x8000A9B8: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9B8: nop

    // 0x8000A9BC: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A9C0: nop

    // 0x8000A9C4: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A9C8: bne         $at, $zero, L_8000A9D8
    if (ctx->r1 != 0) {
        // 0x8000A9CC: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9CC: nop

L_8000A9D0:
    // 0x8000A9D0: b           L_8000A9DC
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_8000A9DC;
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
L_8000A9D8:
    // 0x8000A9D8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_8000A9DC:
    // 0x8000A9DC: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A9E0: beq         $at, $zero, L_8000A91C
    if (ctx->r1 == 0) {
        // 0x8000A9E4: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8000A91C;
    }
    // 0x8000A9E4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A9E8:
    // 0x8000A9E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A9EC:
    // 0x8000A9EC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8000A9F0: jr          $ra
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A9F8: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x8000A9FC: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8000AA00: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8000AA04: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA08: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AA0C: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x8000AA10: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000AA14: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000AA18: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x8000AA1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000AA20: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000AA24: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x8000AA28: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x8000AA2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA30: nop

    // 0x8000AA34: nop

    // 0x8000AA38: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA3C: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x8000AA40: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA44: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x8000AA48: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000AA4C: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA50: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA54: nop

    // 0x8000AA58: nop

    // 0x8000AA5C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA60: mflo        $a2
    ctx->r6 = lo;
    // 0x8000AA64: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x8000AA68: nop

    // 0x8000AA6C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA70: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA74: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x8000AA78: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8000AA7C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000AA80: jr          $ra
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA88: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8000AA8C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8000AA90: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x8000AA94: bltz        $v1, L_8000AAA4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000AA98: nop
    
            goto L_8000AAA4;
    }
    // 0x8000AA98: nop

    // 0x8000AA9C: jr          $ra
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000AAA4:
    // 0x8000AAA4: jr          $ra
    // 0x8000AAA8: nop

    return;
    // 0x8000AAA8: nop

;}
RECOMP_FUNC void __vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AAAC: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AAB0: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x8000AAB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000AAB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000AABC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x8000AAC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000AAC4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000AAC8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x8000AACC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x8000AAD0: nop

    // 0x8000AAD4: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x8000AAD8: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x8000AADC: bgtz        $v1, L_8000AAEC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000AAE0: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_8000AAEC;
    }
    // 0x8000AAE0: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    // 0x8000AAE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000AAE8: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_8000AAEC:
    // 0x8000AAEC: bne         $at, $zero, L_8000AAF8
    if (ctx->r1 != 0) {
        // 0x8000AAF0: nop
    
            goto L_8000AAF8;
    }
    // 0x8000AAF0: nop

    // 0x8000AAF4: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_8000AAF8:
    // 0x8000AAF8: jr          $ra
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AB00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000AB04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AB08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000AB0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000AB10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000AB14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000AB18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AB1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AB24: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8000AB28: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x8000AB2C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000AB30: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x8000AB34: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000AB38: bne         $t6, $zero, L_8000ABAC
    if (ctx->r14 != 0) {
        // 0x8000AB3C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB3C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8000AB40: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AB44: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8000AB48: beq         $s0, $zero, L_8000ABAC
    if (ctx->r16 == 0) {
        // 0x8000AB4C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB4C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000AB50:
    // 0x8000AB50: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8000AB54: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AB58: bne         $s3, $t7, L_8000ABA0
    if (ctx->r19 != ctx->r15) {
        // 0x8000AB5C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB5C: nop

    // 0x8000AB60: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8000AB64: nop

    // 0x8000AB68: bne         $s5, $t8, L_8000ABA0
    if (ctx->r21 != ctx->r24) {
        // 0x8000AB6C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB6C: nop

    // 0x8000AB70: beq         $s1, $zero, L_8000AB8C
    if (ctx->r17 == 0) {
        // 0x8000AB74: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_8000AB8C;
    }
    // 0x8000AB74: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x8000AB78: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8000AB7C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8000AB80: nop

    // 0x8000AB84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8000AB88: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_8000AB8C:
    // 0x8000AB8C: jal         0x800C8CC0
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000AB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AB98: jal         0x800C8CF0
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_8000ABA0:
    // 0x8000ABA0: bne         $s1, $zero, L_8000AB50
    if (ctx->r17 != 0) {
        // 0x8000ABA4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AB50;
    }
    // 0x8000ABA4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000ABA8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000ABAC:
    // 0x8000ABAC: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x8000ABB0: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x8000ABB4: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x8000ABB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABBC: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x8000ABC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABC4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000ABC8: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x8000ABCC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ABD4: jal         0x800CA040
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x8000ABDC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABE0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABE4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABE8: jal         0x800C9BB0
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8000ABF0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8000ABF4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABF8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000ABFC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8000AC00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AC04: jal         0x800C970C
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8000AC0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000AC10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AC14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AC18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AC1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000AC20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000AC24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AC28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000AC2C: jr          $ra
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000AC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000AC40: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x8000AC44: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000AC48: beq         $a3, $zero, L_8000ACD0
    if (ctx->r7 == 0) {
        // 0x8000AC4C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8000ACD0;
    }
    // 0x8000AC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000AC50: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8000AC54:
    // 0x8000AC54: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8000AC58: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x8000AC5C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000AC60: bne         $a0, $t7, L_8000ACC8
    if (ctx->r4 != ctx->r15) {
        // 0x8000AC64: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_8000ACC8;
    }
    // 0x8000AC64: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8000AC68: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x8000AC6C: nop

    // 0x8000AC70: bne         $a1, $t8, L_8000ACC8
    if (ctx->r5 != ctx->r24) {
        // 0x8000AC74: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8000ACC8;
    }
    // 0x8000AC74: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000AC78: beq         $at, $zero, L_8000ACC0
    if (ctx->r1 == 0) {
        // 0x8000AC7C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000ACC0;
    }
    // 0x8000AC7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000AC80: beq         $v0, $zero, L_8000AC98
    if (ctx->r2 == 0) {
        // 0x8000AC84: nop
    
            goto L_8000AC98;
    }
    // 0x8000AC84: nop

    // 0x8000AC88: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000AC8C: nop

    // 0x8000AC90: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8000AC94: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
L_8000AC98:
    // 0x8000AC98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000AC9C: jal         0x800C8CC0
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    after_0:
    // 0x8000ACA4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8000ACA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000ACAC: jal         0x800C8CF0
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_1:
    // 0x8000ACB4: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x8000ACB8: b           L_8000ACD4
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000ACD4;
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACC0:
    // 0x8000ACC0: b           L_8000ACD0
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8000ACD0;
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8000ACC8:
    // 0x8000ACC8: bne         $v0, $zero, L_8000AC54
    if (ctx->r2 != 0) {
        // 0x8000ACCC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8000AC54;
    }
    // 0x8000ACCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000ACD0:
    // 0x8000ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACD4:
    // 0x8000ACD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000ACD8: jr          $ra
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000ACE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000ACE8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000ACEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000ACF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000ACF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000ACF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000ACFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000AD00:
    // 0x8000AD00: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x8000AD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000AD08: beq         $s1, $zero, L_8000AD00
    if (ctx->r17 == 0) {
        // 0x8000AD0C: nop
    
            goto L_8000AD00;
    }
    // 0x8000AD0C: nop

    // 0x8000AD10: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AD18: blez        $t6, L_8000AD4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AD1C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD4C;
    }
    // 0x8000AD1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD20:
    // 0x8000AD20: jal         0x8000ADF4
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AD28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000AD30: jal         0x8000AD98
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x8000AD38: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AD40: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000AD44: bne         $at, $zero, L_8000AD20
    if (ctx->r1 != 0) {
        // 0x8000AD48: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD20;
    }
    // 0x8000AD48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD4C:
    // 0x8000AD4C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD54: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8000AD58: nop

    // 0x8000AD5C: beq         $t9, $zero, L_8000AD84
    if (ctx->r25 == 0) {
        // 0x8000AD60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000AD84;
    }
    // 0x8000AD60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AD64: jal         0x8000ADF4
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000AD6C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD74: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8000AD78: jal         0x8000AD98
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x8000AD80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000AD84:
    // 0x8000AD84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AD88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AD8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AD90: jr          $ra
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AD98: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8000AD9C: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADA0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000ADA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000ADA8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000ADAC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x8000ADB0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADB4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8000ADB8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADBC: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x8000ADC0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADC4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8000ADC8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000ADCC: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x8000ADD0: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADD4: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x8000ADD8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000ADDC: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x8000ADE0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADE4: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8000ADE8: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADEC: jr          $ra
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
