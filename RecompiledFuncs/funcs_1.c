#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void music_jingle_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001B5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001B60: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001B64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001B68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001B6C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80001B70: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x80001B74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001B78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001B7C: addiu       $s2, $s2, -0x345C
    ctx->r18 = ADD32(ctx->r18, -0X345C);
    // 0x80001B80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001B84: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_80001B88:
    // 0x80001B88: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80001B8C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80001B90: jal         0x800C7E40
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x80001B98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001B9C: bne         $s0, $s3, L_80001B88
    if (ctx->r16 != ctx->r19) {
        // 0x80001BA0: nop
    
            goto L_80001B88;
    }
    // 0x80001BA0: nop

    // 0x80001BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001BA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80001BAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80001BB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80001BB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80001BB8: jr          $ra
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void music_jingle_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001BC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001BC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001BCC: addiu       $v0, $v0, 0x6285
    ctx->r2 = ADD32(ctx->r2, 0X6285);
    // 0x80001BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001BD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001BD8: sb          $t6, -0x344C($at)
    MEM_B(-0X344C, ctx->r1) = ctx->r14;
    // 0x80001BDC: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80001BE0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001BEC: lw          $a1, -0x345C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X345C);
    // 0x80001BF0: jal         0x800022BC
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x80001BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001C00: jr          $ra
    // 0x80001C04: nop

    return;
    // 0x80001C04: nop

;}
RECOMP_FUNC void music_jingle_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C08: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001C0C: lbu         $v1, 0x6285($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6285);
    // 0x80001C10: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001C14: beq         $v1, $zero, L_80001C4C
    if (ctx->r3 == 0) {
        // 0x80001C18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80001C4C;
    }
    // 0x80001C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001C1C: lbu         $t6, -0x344C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X344C);
    // 0x80001C20: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001C24: beq         $t6, $zero, L_80001C4C
    if (ctx->r14 == 0) {
        // 0x80001C28: nop
    
            goto L_80001C4C;
    }
    // 0x80001C28: nop

    // 0x80001C2C: lw          $t7, -0x345C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X345C);
    // 0x80001C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001C34: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80001C38: nop

    // 0x80001C3C: bne         $t8, $at, L_80001C4C
    if (ctx->r24 != ctx->r1) {
        // 0x80001C40: nop
    
            goto L_80001C4C;
    }
    // 0x80001C40: nop

    // 0x80001C44: jr          $ra
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001C4C:
    // 0x80001C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001C50: sb          $zero, -0x344C($at)
    MEM_B(-0X344C, ctx->r1) = 0;
    // 0x80001C54: jr          $ra
    // 0x80001C58: nop

    return;
    // 0x80001C58: nop

;}
RECOMP_FUNC void sound_channel_volume_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001C60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001C64: sll         $s1, $a0, 8
    ctx->r17 = S32(ctx->r4 << 8);
    // 0x80001C68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001C6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001C70: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80001C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001C78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001C7C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80001C80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001C84: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    // 0x80001C88: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80001C8C:
    // 0x80001C8C: jal         0x80004A60
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x80001C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001C98: bne         $s0, $s2, L_80001C8C
    if (ctx->r16 != ctx->r18) {
        // 0x80001C9C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80001C8C;
    }
    // 0x80001C9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80001CA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001CAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001CB0: jr          $ra
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001CB8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001CBC: lw          $t7, 0x62A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A0);
    // 0x80001CC0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001CC8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001CCC: beq         $at, $zero, L_80001CDC
    if (ctx->r1 == 0) {
        // 0x80001CD0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80001CDC;
    }
    // 0x80001CD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001CD4: jr          $ra
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001CDC:
    // 0x80001CDC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001CE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80001CE4: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001CE8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80001CEC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001CF0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001CF4: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
    // 0x80001CF8: nop

    // 0x80001CFC: jr          $ra
    // 0x80001D00: nop

    return;
    // 0x80001D00: nop

;}
RECOMP_FUNC void sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001D04: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001D08: lw          $t7, 0x62A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A0);
    // 0x80001D0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001D10: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001D14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001D18: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001D1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001D24: beq         $at, $zero, L_80001D3C
    if (ctx->r1 == 0) {
        // 0x80001D28: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80001D3C;
    }
    // 0x80001D28: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80001D2C: beq         $a1, $zero, L_80001E9C
    if (ctx->r5 == 0) {
        // 0x80001D30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D34: b           L_80001E98
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80001E98;
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80001D3C:
    // 0x80001D3C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80001D40: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001D44: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001D48: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80001D4C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80001D50: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80001D54: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80001D58: nop

    // 0x80001D5C: bne         $v1, $zero, L_80001D74
    if (ctx->r3 != 0) {
        // 0x80001D60: nop
    
            goto L_80001D74;
    }
    // 0x80001D60: nop

    // 0x80001D64: beq         $a3, $zero, L_80001E9C
    if (ctx->r7 == 0) {
        // 0x80001D68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D6C: b           L_80001E98
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80001E98;
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80001D74:
    // 0x80001D74: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80001D78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001D7C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80001D80: bgez        $t9, L_80001D94
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80001D84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001D94;
    }
    // 0x80001D84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001D8C: nop

    // 0x80001D90: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001D94:
    // 0x80001D94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80001D98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001D9C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DA0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001DA4: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DA8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001DAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80001DB0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80001DB4: beq         $a3, $zero, L_80001E34
    if (ctx->r7 == 0) {
        // 0x80001DB8: swc1        $f16, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
            goto L_80001E34;
    }
    // 0x80001DB8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80001DBC: lw          $t1, 0x6294($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6294);
    // 0x80001DC0: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DC4: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001DC8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80001DCC: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DD0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80001DD4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001DD8: jal         0x80004668
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80001DE0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001DE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001DE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001DEC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80001DF0: beq         $a0, $zero, L_80001E9C
    if (ctx->r4 == 0) {
        // 0x80001DF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001DF8: lw          $t3, 0x6298($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6298);
    // 0x80001DFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E00: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80001E04: lbu         $a2, 0x2($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X2);
    // 0x80001E08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80001E0C: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80001E10: jal         0x800049F8
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_1;
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_1:
    // 0x80001E18: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001E1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E20: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001E24: jal         0x800049F8
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_2;
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80001E2C: b           L_80001E9C
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001E9C;
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E34:
    // 0x80001E34: lw          $t6, 0x6294($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6294);
    // 0x80001E38: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001E3C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80001E40: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x80001E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001E48: jal         0x80004668
    // 0x80001E4C: addiu       $a3, $a3, 0x6500
    ctx->r7 = ADD32(ctx->r7, 0X6500);
    sndp_play_with_priority(rdram, ctx);
        goto after_3;
    // 0x80001E4C: addiu       $a3, $a3, 0x6500
    ctx->r7 = ADD32(ctx->r7, 0X6500);
    after_3:
    // 0x80001E50: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001E54: lw          $t8, 0x6500($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6500);
    // 0x80001E58: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001E5C: beq         $t8, $zero, L_80001E98
    if (ctx->r24 == 0) {
        // 0x80001E60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001E98;
    }
    // 0x80001E60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001E64: lw          $t9, 0x6298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6298);
    // 0x80001E68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80001E6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80001E70: lbu         $a2, 0x2($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X2);
    // 0x80001E74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E78: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x80001E7C: jal         0x800049F8
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_4:
    // 0x80001E84: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001E88: lw          $a0, 0x6500($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6500);
    // 0x80001E8C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E90: jal         0x800049F8
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
L_80001E98:
    // 0x80001E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E9C:
    // 0x80001E9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001EA0: jr          $ra
    // 0x80001EA4: nop

    return;
    // 0x80001EA4: nop

;}
RECOMP_FUNC void sound_play_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001EB0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001EB8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001EBC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001EC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001EC8: bne         $a1, $zero, L_80001ED8
    if (ctx->r5 != 0) {
        // 0x80001ECC: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80001ED8;
    }
    // 0x80001ECC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001ED0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001ED4: addiu       $a1, $a1, 0x6504
    ctx->r5 = ADD32(ctx->r5, 0X6504);
L_80001ED8:
    // 0x80001ED8: jal         0x80001D04
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001EE0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80001EE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80001EEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80001EF0: beq         $a0, $zero, L_80001F08
    if (ctx->r4 == 0) {
        // 0x80001EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001F08;
    }
    // 0x80001EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001EF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80001EFC: jal         0x80009B7C
    // 0x80001F00: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_1;
    // 0x80001F00: nop

    after_1:
    // 0x80001F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F08:
    // 0x80001F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001F0C: jr          $ra
    // 0x80001F10: nop

    return;
    // 0x80001F10: nop

;}
RECOMP_FUNC void sound_play_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F18: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001F20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80001F24: blez        $t6, L_80001F4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001F28: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80001F4C;
    }
    // 0x80001F28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80001F2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80001F30: jal         0x800020E8
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    sound_count(rdram, ctx);
        goto after_0;
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001F38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80001F3C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001F40: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80001F44: beq         $at, $zero, L_80001F5C
    if (ctx->r1 == 0) {
        // 0x80001F48: nop
    
            goto L_80001F5C;
    }
    // 0x80001F48: nop

L_80001F4C:
    // 0x80001F4C: beq         $a2, $zero, L_80001FAC
    if (ctx->r6 == 0) {
        // 0x80001F50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001FAC;
    }
    // 0x80001F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001F54: b           L_80001FA8
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80001FA8;
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80001F5C:
    // 0x80001F5C: beq         $a2, $zero, L_80001F88
    if (ctx->r6 == 0) {
        // 0x80001F60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001F88;
    }
    // 0x80001F60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001F64: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001F68: lw          $t7, 0x6294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6294);
    // 0x80001F6C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F70: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F74: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80001F78: jal         0x80004638
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    sndp_play(rdram, ctx);
        goto after_1;
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x80001F80: b           L_80001FAC
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001FAC;
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F88:
    // 0x80001F88: lw          $t9, 0x6294($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6294);
    // 0x80001F8C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F90: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F94: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80001F98: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80001F9C: addiu       $a2, $a2, 0x6508
    ctx->r6 = ADD32(ctx->r6, 0X6508);
    // 0x80001FA0: jal         0x80004638
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    sndp_play(rdram, ctx);
        goto after_2;
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_2:
L_80001FA8:
    // 0x80001FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001FAC:
    // 0x80001FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001FB0: jr          $ra
    // 0x80001FB4: nop

    return;
    // 0x80001FB4: nop

;}
RECOMP_FUNC void sound_volume_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001FBC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001FC0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80001FC4: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001FC8: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001FCC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80001FD0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001FDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001FE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001FE4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001FE8: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80001FEC: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80001FF0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80001FF4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80001FF8: bgez        $t1, L_80002010
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80001FFC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80002010;
    }
    // 0x80001FFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80002000: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002004: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80002008: nop

    // 0x8000200C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80002010:
    // 0x80002010: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80002014: bgez        $a2, L_8000202C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80002018: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000202C;
    }
    // 0x80002018: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000201C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002020: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80002024: nop

    // 0x80002028: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8000202C:
    // 0x8000202C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80002030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002034: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80002038: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000203C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80002040: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80002044: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80002048: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000204C: nop

    // 0x80002050: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80002054: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80002058: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000205C: nop

    // 0x80002060: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80002064: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80002068: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000206C: beq         $t4, $zero, L_8000207C
    if (ctx->r12 == 0) {
        // 0x80002070: sll         $t3, $a3, 8
        ctx->r11 = S32(ctx->r7 << 8);
            goto L_8000207C;
    }
    // 0x80002070: sll         $t3, $a3, 8
    ctx->r11 = S32(ctx->r7 << 8);
    // 0x80002074: jal         0x800049F8
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_0:
L_8000207C:
    // 0x8000207C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002084: jr          $ra
    // 0x80002088: nop

    return;
    // 0x80002088: nop

;}
RECOMP_FUNC void sound_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000208C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80002098: beq         $a0, $zero, L_800020AC
    if (ctx->r4 == 0) {
        // 0x8000209C: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_800020AC;
    }
    // 0x8000209C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x800020A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800020A4: jal         0x800049F8
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    after_0:
L_800020AC:
    // 0x800020AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020B4: jr          $ra
    // 0x800020B8: nop

    return;
    // 0x800020B8: nop

;}
RECOMP_FUNC void sound_pitch_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800020C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020C4: beq         $a0, $zero, L_800020D8
    if (ctx->r4 == 0) {
        // 0x800020C8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800020D8;
    }
    // 0x800020C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800020CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800020D0: jal         0x800049F8
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
L_800020D8:
    // 0x800020D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020E0: jr          $ra
    // 0x800020E4: nop

    return;
    // 0x800020E4: nop

;}
RECOMP_FUNC void sound_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020E8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800020EC: lw          $t6, 0x6294($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6294);
    // 0x800020F0: nop

    // 0x800020F4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800020F8: nop

    // 0x800020FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80002100: nop

    // 0x80002104: lhu         $v0, 0xE($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XE);
    // 0x80002108: jr          $ra
    // 0x8000210C: nop

    return;
    // 0x8000210C: nop

;}
RECOMP_FUNC void music_sequence_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002110: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002114: lw          $t6, 0x6278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6278);
    // 0x80002118: nop

    // 0x8000211C: lbu         $v0, 0x3($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3);
    // 0x80002120: jr          $ra
    // 0x80002124: nop

    return;
    // 0x80002124: nop

;}
RECOMP_FUNC void sound_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002128: beq         $a0, $zero, L_8000213C
    if (ctx->r4 == 0) {
        // 0x8000212C: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_8000213C;
    }
    // 0x8000212C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002130: lw          $t6, 0x6298($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6298);
    // 0x80002134: nop

    // 0x80002138: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8000213C:
    // 0x8000213C: beq         $a1, $zero, L_80002150
    if (ctx->r5 == 0) {
        // 0x80002140: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002150;
    }
    // 0x80002140: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002144: lw          $t7, 0x62A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A8);
    // 0x80002148: nop

    // 0x8000214C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002150:
    // 0x80002150: beq         $a2, $zero, L_80002164
    if (ctx->r6 == 0) {
        // 0x80002154: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_80002164;
    }
    // 0x80002154: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80002158: lw          $t8, 0x62A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62A0);
    // 0x8000215C: nop

    // 0x80002160: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80002164:
    // 0x80002164: jr          $ra
    // 0x80002168: nop

    return;
    // 0x80002168: nop

;}
RECOMP_FUNC void music_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000216C: beq         $a0, $zero, L_80002180
    if (ctx->r4 == 0) {
        // 0x80002170: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_80002180;
    }
    // 0x80002170: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002174: lw          $t6, 0x629C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X629C);
    // 0x80002178: nop

    // 0x8000217C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80002180:
    // 0x80002180: beq         $a1, $zero, L_80002194
    if (ctx->r5 == 0) {
        // 0x80002184: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002194;
    }
    // 0x80002184: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002188: lw          $t7, 0x62AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62AC);
    // 0x8000218C: nop

    // 0x80002190: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002194:
    // 0x80002194: beq         $a2, $zero, L_800021A8
    if (ctx->r6 == 0) {
        // 0x80002198: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_800021A8;
    }
    // 0x80002198: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8000219C: lw          $t8, 0x62A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62A4);
    // 0x800021A0: nop

    // 0x800021A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800021A8:
    // 0x800021A8: jr          $ra
    // 0x800021AC: nop

    return;
    // 0x800021AC: nop

;}
RECOMP_FUNC void sound_is_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800021B0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800021B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800021B8: blez        $t6, L_800021F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800021BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800021F0;
    }
    // 0x800021BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800021C0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800021C4: lw          $t7, 0x6294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6294);
    // 0x800021C8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800021CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800021D0: nop

    // 0x800021D4: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800021D8: nop

    // 0x800021DC: lh          $t9, 0xE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XE);
    // 0x800021E0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800021E4: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800021E8: beq         $at, $zero, L_800021F8
    if (ctx->r1 == 0) {
        // 0x800021EC: nop
    
            goto L_800021F8;
    }
    // 0x800021EC: nop

L_800021F0:
    // 0x800021F0: jr          $ra
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800021F8:
    // 0x800021F8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800021FC: nop

    // 0x80002200: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80002204: nop

    // 0x80002208: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x8000220C: nop

    // 0x80002210: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80002214: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80002218: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x8000221C: jr          $ra
    // 0x80002220: nop

    return;
    // 0x80002220: nop

;}
RECOMP_FUNC void sound_seqplayer_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002224: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002228: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8000222C: addiu       $a2, $a2, 0x6268
    ctx->r6 = ADD32(ctx->r6, 0X6268);
    // 0x80002230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002234: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80002238: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000223C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80002240: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80002244: sb          $a0, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r4;
    // 0x80002248: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000224C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80002250: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
    // 0x80002254: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80002258: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000225C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80002260: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80002264: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80002268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000226C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002270: jal         0x800C7D50
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80002278: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000227C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002280: jal         0x800624D0
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alCSPNew(rdram, ctx);
        goto after_1;
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80002288: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8000228C: lw          $t0, 0x6290($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6290);
    // 0x80002290: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80002294: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80002298: jal         0x800C7FC0
    // 0x8000229C: nop

    alCSPSetBank(rdram, ctx);
        goto after_2;
    // 0x8000229C: nop

    after_2:
    // 0x800022A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800022A4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x800022A8: sb          $t1, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r9;
    // 0x800022AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800022B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800022B4: jr          $ra
    // 0x800022B8: nop

    return;
    // 0x800022B8: nop

;}
RECOMP_FUNC void music_sequence_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800022BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800022C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800022C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800022C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800022CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800022D0: sb          $a2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r6;
    // 0x800022D4: jal         0x80002570
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800022DC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800022E0: lw          $t6, 0x6278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6278);
    // 0x800022E4: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    // 0x800022E8: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800022EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800022F0: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800022F4: beq         $at, $zero, L_8000231C
    if (ctx->r1 == 0) {
        // 0x800022F8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000231C;
    }
    // 0x800022F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800022FC: lw          $t9, -0x3460($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3460);
    // 0x80002300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002304: bne         $t8, $t9, L_80002318
    if (ctx->r24 != ctx->r25) {
        // 0x80002308: nop
    
            goto L_80002318;
    }
    // 0x80002308: nop

    // 0x8000230C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002310: b           L_8000231C
    // 0x80002314: sb          $a2, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = ctx->r6;
        goto L_8000231C;
    // 0x80002314: sb          $a2, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = ctx->r6;
L_80002318:
    // 0x80002318: sb          $a2, -0x3430($at)
    MEM_B(-0X3430, ctx->r1) = ctx->r6;
L_8000231C:
    // 0x8000231C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002324: jr          $ra
    // 0x80002328: nop

    return;
    // 0x80002328: nop

;}
RECOMP_FUNC void music_sequence_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000232C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002334: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80002338: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000233C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002340: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002348: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000234C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80002350: jal         0x800C7FB0
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    after_0:
    // 0x80002358: bne         $v0, $zero, L_80002558
    if (ctx->r2 != 0) {
        // 0x8000235C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000235C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002360: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80002364: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80002368: beq         $t6, $zero, L_80002558
    if (ctx->r14 == 0) {
        // 0x8000236C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000236C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002370: jal         0x80077240
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    asset_rom_offset(rdram, ctx);
        goto after_1;
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80002378: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8000237C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002380: lw          $t7, 0x6278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6278);
    // 0x80002384: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80002388: lw          $t1, 0x628C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X628C);
    // 0x8000238C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80002390: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80002394: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80002398: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000239C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800023A0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x800023A4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800023A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800023AC: jal         0x80077190
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    after_2:
    // 0x800023B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800023B8: jal         0x800C855C
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alCSeqNew(rdram, ctx);
        goto after_3;
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800023C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800023C4: jal         0x800C8AC0
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alCSPSetSeq(rdram, ctx);
        goto after_4;
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800023CC: jal         0x800C8B00
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alCSPPlay(rdram, ctx);
        goto after_5;
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800023D4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800023D8: lw          $t4, -0x3460($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3460);
    // 0x800023DC: nop

    // 0x800023E0: bne         $s0, $t4, L_800024E8
    if (ctx->r16 != ctx->r12) {
        // 0x800023E4: nop
    
            goto L_800024E8;
    }
    // 0x800023E4: nop

    // 0x800023E8: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x800023EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800023F0: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800023F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800023F8: addiu       $s0, $s0, 0x629C
    ctx->r16 = ADD32(ctx->r16, 0X629C);
    // 0x800023FC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80002400: mflo        $t7
    ctx->r15 = lo;
    // 0x80002404: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002408: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000240C: jal         0x80001990
    // 0x80002410: nop

    music_volume_set(rdram, ctx);
        goto after_6;
    // 0x80002410: nop

    after_6:
    // 0x80002414: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80002418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000241C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002420: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80002424: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002428: mflo        $t0
    ctx->r8 = lo;
    // 0x8000242C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80002430: lbu         $a0, 0x1($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X1);
    // 0x80002434: nop

    // 0x80002438: beq         $a0, $zero, L_80002458
    if (ctx->r4 == 0) {
        // 0x8000243C: nop
    
            goto L_80002458;
    }
    // 0x8000243C: nop

    // 0x80002440: jal         0x80001534
    // 0x80002444: nop

    music_tempo_set(rdram, ctx);
        goto after_7;
    // 0x80002444: nop

    after_7:
    // 0x80002448: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000244C: lw          $v0, 0x629C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X629C);
    // 0x80002450: b           L_80002460
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
        goto L_80002460;
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002458:
    // 0x80002458: sh          $t2, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r10;
    // 0x8000245C: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002460:
    // 0x80002460: nop

    // 0x80002464: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002468: mflo        $t4
    ctx->r12 = lo;
    // 0x8000246C: addu        $t6, $v0, $t4
    ctx->r14 = ADD32(ctx->r2, ctx->r12);
    // 0x80002470: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    // 0x80002474: jal         0x80002608
    // 0x80002478: nop

    sound_reverb_set(rdram, ctx);
        goto after_8;
    // 0x80002478: nop

    after_8:
    // 0x8000247C: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x80002480: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002484: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002488: addiu       $s1, $s1, 0x64FC
    ctx->r17 = ADD32(ctx->r17, 0X64FC);
    // 0x8000248C: sb          $t5, 0x6284($at)
    MEM_B(0X6284, ctx->r1) = ctx->r13;
    // 0x80002490: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80002494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002498: beq         $t7, $at, L_80002550
    if (ctx->r15 == ctx->r1) {
        // 0x8000249C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80002550;
    }
    // 0x8000249C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800024A0: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_800024A4:
    // 0x800024A4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800024A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800024AC: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x800024B0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800024B4: beq         $t1, $zero, L_800024CC
    if (ctx->r9 == 0) {
        // 0x800024B8: nop
    
            goto L_800024CC;
    }
    // 0x800024B8: nop

    // 0x800024BC: jal         0x80001170
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_9;
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_9:
    // 0x800024C4: b           L_800024D8
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800024D8;
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024CC:
    // 0x800024CC: jal         0x80001114
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_10:
    // 0x800024D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024D8:
    // 0x800024D8: bne         $s0, $s2, L_800024A4
    if (ctx->r16 != ctx->r18) {
        // 0x800024DC: nop
    
            goto L_800024A4;
    }
    // 0x800024DC: nop

    // 0x800024E0: b           L_80002554
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
        goto L_80002554;
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_800024E8:
    // 0x800024E8: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x800024EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800024F0: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800024F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800024F8: addiu       $s0, $s0, 0x629C
    ctx->r16 = ADD32(ctx->r16, 0X629C);
    // 0x800024FC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80002500: mflo        $t4
    ctx->r12 = lo;
    // 0x80002504: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x80002508: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8000250C: jal         0x80001B0C
    // 0x80002510: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_11;
    // 0x80002510: nop

    after_11:
    // 0x80002514: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002518: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000251C: multu       $v1, $s1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002520: mflo        $t7
    ctx->r15 = lo;
    // 0x80002524: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002528: lbu         $a0, 0x1($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X1);
    // 0x8000252C: nop

    // 0x80002530: beq         $a0, $zero, L_80002548
    if (ctx->r4 == 0) {
        // 0x80002534: nop
    
            goto L_80002548;
    }
    // 0x80002534: nop

    // 0x80002538: jal         0x800017D4
    // 0x8000253C: nop

    sound_jingle_tempo_set(rdram, ctx);
        goto after_12;
    // 0x8000253C: nop

    after_12:
    // 0x80002540: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002544: nop

L_80002548:
    // 0x80002548: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000254C: sb          $v1, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = ctx->r3;
L_80002550:
    // 0x80002550: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_80002554:
    // 0x80002554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80002558:
    // 0x80002558: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000255C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002560: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80002564: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80002568: jr          $ra
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void music_sequence_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002570: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80002574: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80002578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000257C: bne         $a0, $t6, L_800025BC
    if (ctx->r4 != ctx->r14) {
        // 0x80002580: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800025BC;
    }
    // 0x80002580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002584: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002588: lbu         $t7, 0x62C0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X62C0);
    // 0x8000258C: nop

    // 0x80002590: beq         $t7, $zero, L_800025BC
    if (ctx->r15 == 0) {
        // 0x80002594: nop
    
            goto L_800025BC;
    }
    // 0x80002594: nop

    // 0x80002598: jal         0x800C8B30
    // 0x8000259C: nop

    alCSPStop(rdram, ctx);
        goto after_0;
    // 0x8000259C: nop

    after_0:
    // 0x800025A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025A4: sb          $zero, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = 0;
    // 0x800025A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025AC: sb          $zero, 0x6284($at)
    MEM_B(0X6284, ctx->r1) = 0;
    // 0x800025B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025B4: b           L_800025F8
    // 0x800025B8: sb          $zero, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = 0;
        goto L_800025F8;
    // 0x800025B8: sb          $zero, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = 0;
L_800025BC:
    // 0x800025BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800025C0: lw          $t8, -0x345C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X345C);
    // 0x800025C4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800025C8: bne         $a0, $t8, L_800025FC
    if (ctx->r4 != ctx->r24) {
        // 0x800025CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025D0: lbu         $t9, 0x62C1($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X62C1);
    // 0x800025D4: nop

    // 0x800025D8: beq         $t9, $zero, L_800025FC
    if (ctx->r25 == 0) {
        // 0x800025DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025E0: jal         0x800C8B30
    // 0x800025E4: nop

    alCSPStop(rdram, ctx);
        goto after_1;
    // 0x800025E4: nop

    after_1:
    // 0x800025E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025EC: sb          $zero, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = 0;
    // 0x800025F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025F4: sb          $zero, -0x3430($at)
    MEM_B(-0X3430, ctx->r1) = 0;
L_800025F8:
    // 0x800025F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800025FC:
    // 0x800025FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002600: jr          $ra
    // 0x80002604: nop

    return;
    // 0x80002604: nop

;}
RECOMP_FUNC void sound_reverb_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000260C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002614: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80002618: jal         0x80064B6C
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    alFxReverbSet(rdram, ctx);
        goto after_0;
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80002620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002628: jr          $ra
    // 0x8000262C: nop

    return;
    // 0x8000262C: nop

;}
RECOMP_FUNC void sound_reverb_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002630: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002634: lbu         $t7, 0x6284($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6284);
    // 0x80002638: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8000263C: lw          $t6, 0x629C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X629C);
    // 0x80002640: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80002644: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80002648: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000264C: lbu         $v0, 0x2($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X2);
    // 0x80002650: jr          $ra
    // 0x80002654: nop

    return;
    // 0x80002654: nop

    // 0x80002658: nop

    // 0x8000265C: nop

;}
RECOMP_FUNC void amCreateAudioMgr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002660: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002664: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002668: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000266C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80002670: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80002674: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80002678: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000267C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002680: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80002684: sw          $a2, 0x6510($at)
    MEM_W(0X6510, ctx->r1) = ctx->r6;
    // 0x80002688: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8000268C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002690: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80002694: addiu       $t7, $t7, 0x3008
    ctx->r15 = ADD32(ctx->r15, 0X3008);
    // 0x80002698: sw          $t6, 0x6514($at)
    MEM_W(0X6514, ctx->r1) = ctx->r14;
    // 0x8000269C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800026A0: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800026A4: jal         0x800C8B60
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_0:
    // 0x800026AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800026B0: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x800026B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800026B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800026BC: lw          $t8, 0x6710($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6710);
    // 0x800026C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800026C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800026C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800026CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800026D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800026D4: addiu       $a0, $a0, -0x6454
    ctx->r4 = ADD32(ctx->r4, -0X6454);
    // 0x800026D8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800026DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800026E0: addiu       $s4, $s4, -0x6450
    ctx->r20 = ADD32(ctx->r20, -0X6450);
    // 0x800026E4: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800026E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800026EC: nop

    // 0x800026F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800026F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800026F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800026FC: nop

    // 0x80002700: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80002704: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80002708: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000270C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80002710: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80002714: bgez        $v1, L_8000272C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80002718: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000272C;
    }
    // 0x80002718: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000271C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002720: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80002724: nop

    // 0x80002728: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000272C:
    // 0x8000272C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80002730: nop

    // 0x80002734: bc1f        L_80002744
    if (!c1cs) {
        // 0x80002738: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80002744;
    }
    // 0x80002738: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8000273C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80002740: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80002744:
    // 0x80002744: andi        $t3, $v1, 0xF
    ctx->r11 = ctx->r3 & 0XF;
    // 0x80002748: beq         $t3, $zero, L_8000275C
    if (ctx->r11 == 0) {
        // 0x8000274C: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8000275C;
    }
    // 0x8000274C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80002750: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x80002754: addiu       $v1, $t4, 0x10
    ctx->r3 = ADD32(ctx->r12, 0X10);
    // 0x80002758: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_8000275C:
    // 0x8000275C: addiu       $t6, $v1, -0x10
    ctx->r14 = ADD32(ctx->r3, -0X10);
    // 0x80002760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80002764: sw          $t6, -0x6458($at)
    MEM_W(-0X6458, ctx->r1) = ctx->r14;
    // 0x80002768: addiu       $t7, $v1, 0x70
    ctx->r15 = ADD32(ctx->r3, 0X70);
    // 0x8000276C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x80002770: lbu         $t8, 0x1C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1C);
    // 0x80002774: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80002778: bne         $t8, $at, L_800027E8
    if (ctx->r24 != ctx->r1) {
        // 0x8000277C: nop
    
            goto L_800027E8;
    }
    // 0x8000277C: nop

    // 0x80002780: jal         0x80076EE4
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80002788: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8000278C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x80002790: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80002794: subu        $s0, $t9, $t1
    ctx->r16 = SUB32(ctx->r25, ctx->r9);
    // 0x80002798: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000279C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800027A0: jal         0x80070EDC
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_2:
    // 0x800027A8: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x800027AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800027B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800027B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800027B8: jal         0x80077190
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x800027C0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027C4: sw          $s1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r17;
    // 0x800027C8: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    // 0x800027CC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    // 0x800027D0: jal         0x800C8D4C
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_4;
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800027D8: jal         0x80071380
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800027E0: b           L_800027F8
    // 0x800027E4: nop

        goto L_800027F8;
    // 0x800027E4: nop

L_800027E8:
    // 0x800027E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027EC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    // 0x800027F0: jal         0x800C8D4C
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_6;
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800027F8:
    // 0x800027F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800027FC: addiu       $v0, $v0, -0x6840
    ctx->r2 = ADD32(ctx->r2, -0X6840);
    // 0x80002800: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80002804: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80002808: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000280C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80002810: addiu       $s0, $s0, -0x682C
    ctx->r16 = ADD32(ctx->r16, -0X682C);
    // 0x80002814: addiu       $s2, $s2, -0x6840
    ctx->r18 = ADD32(ctx->r18, -0X6840);
    // 0x80002818: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000281C:
    // 0x8000281C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002820: jal         0x800C8CF0
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_7;
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80002828: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000282C: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80002830: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000283C: jal         0x800C7D50
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80002844: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002848: slti        $at, $s1, 0x31
    ctx->r1 = SIGNED(ctx->r17) < 0X31 ? 1 : 0;
    // 0x8000284C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80002850: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80002854: bne         $at, $zero, L_8000281C
    if (ctx->r1 != 0) {
        // 0x80002858: sw          $v0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r2;
            goto L_8000281C;
    }
    // 0x80002858: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x8000285C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002860: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80002864: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80002868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000286C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002870: jal         0x800C7D50
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_9;
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80002878: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000287C: addiu       $a0, $a0, -0x6448
    ctx->r4 = ADD32(ctx->r4, -0X6448);
    // 0x80002880: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80002884: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002888: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8000288C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80002890: addiu       $t0, $t0, -0x3404
    ctx->r8 = ADD32(ctx->r8, -0X3404);
    // 0x80002894: lui         $t5, 0x8002
    ctx->r13 = S32(0X8002 << 16);
    // 0x80002898: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x8000289C: addiu       $t5, $t5, -0x67C4
    ctx->r13 = ADD32(ctx->r13, -0X67C4);
    // 0x800028A0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x800028A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800028A8: lw          $a1, -0x33FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33FC);
    // 0x800028AC: subu        $v1, $t5, $a2
    ctx->r3 = SUB32(ctx->r13, ctx->r6);
    // 0x800028B0: addu        $a3, $a2, $v1
    ctx->r7 = ADD32(ctx->r6, ctx->r3);
    // 0x800028B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800028B8: blez        $a1, L_800028E8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800028BC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800028E8;
    }
    // 0x800028BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800028C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800028C4:
    // 0x800028C4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800028C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800028CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800028D0: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800028D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800028D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800028DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800028E0: bne         $at, $zero, L_800028C4
    if (ctx->r1 != 0) {
        // 0x800028E4: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_800028C4;
    }
    // 0x800028E4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800028E8:
    // 0x800028E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800028EC: lw          $t9, -0x3400($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3400);
    // 0x800028F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800028F4: beq         $v1, $t9, L_80002904
    if (ctx->r3 == ctx->r25) {
        // 0x800028F8: addiu       $s0, $s0, 0x6518
        ctx->r16 = ADD32(ctx->r16, 0X6518);
            goto L_80002904;
    }
    // 0x800028F8: addiu       $s0, $s0, 0x6518
    ctx->r16 = ADD32(ctx->r16, 0X6518);
    // 0x800028FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002900: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
L_80002904:
    // 0x80002904: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002908: addiu       $s1, $s1, 0x6520
    ctx->r17 = ADD32(ctx->r17, 0X6520);
L_8000290C:
    // 0x8000290C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002910: ori         $t2, $zero, 0xA000
    ctx->r10 = 0 | 0XA000;
    // 0x80002914: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000291C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002920: jal         0x800C7D50
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80002928: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000292C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80002930: bne         $at, $zero, L_8000290C
    if (ctx->r1 != 0) {
        // 0x80002934: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8000290C;
    }
    // 0x80002934: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80002938: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000293C: lui         $t4, 0x803F
    ctx->r12 = S32(0X803F << 16);
    // 0x80002940: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80002944: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80002948: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x8000294C: ori         $t4, $t4, 0xFE00
    ctx->r12 = ctx->r12 | 0XFE00;
    // 0x80002950: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x80002954: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80002958: subu        $a1, $t4, $a0
    ctx->r5 = SUB32(ctx->r12, ctx->r4);
    // 0x8000295C: jal         0x80071138
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_11;
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    after_11:
    // 0x80002964: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002968: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000296C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80002970: addiu       $s1, $s1, 0x6524
    ctx->r17 = ADD32(ctx->r17, 0X6524);
    // 0x80002974: addiu       $s0, $s0, 0x6518
    ctx->r16 = ADD32(ctx->r16, 0X6518);
L_80002978:
    // 0x80002978: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000297C: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80002980: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80002984: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80002988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000298C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002990: jal         0x800C7D50
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80002998: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8000299C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800029A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800029A4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800029A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800029AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800029B0: bne         $s0, $s1, L_80002978
    if (ctx->r16 != ctx->r17) {
        // 0x800029B4: addu        $v1, $v1, $t7
        ctx->r3 = ADD32(ctx->r3, ctx->r15);
            goto L_80002978;
    }
    // 0x800029B4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800029B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029C0: addiu       $a1, $a1, 0x6730
    ctx->r5 = ADD32(ctx->r5, 0X6730);
    // 0x800029C4: addiu       $a0, $a0, 0x6718
    ctx->r4 = ADD32(ctx->r4, 0X6718);
    // 0x800029C8: jal         0x800C8D80
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_13;
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_13:
    // 0x800029D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029D4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029D8: addiu       $a1, $a1, 0x66F8
    ctx->r5 = ADD32(ctx->r5, 0X66F8);
    // 0x800029DC: addiu       $a0, $a0, 0x66E0
    ctx->r4 = ADD32(ctx->r4, 0X66E0);
    // 0x800029E0: jal         0x800C8D80
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_14;
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x800029E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800029EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800029F0: addiu       $a1, $a1, -0x5F78
    ctx->r5 = ADD32(ctx->r5, -0X5F78);
    // 0x800029F4: addiu       $a0, $a0, -0x5F90
    ctx->r4 = ADD32(ctx->r4, -0X5F90);
    // 0x800029F8: jal         0x800C8D80
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_15;
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_15:
    // 0x80002A00: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80002A08: addiu       $t8, $t8, -0x6850
    ctx->r24 = ADD32(ctx->r24, -0X6850);
    // 0x80002A0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A10: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80002A14: addiu       $a2, $a2, 0x2A98
    ctx->r6 = ADD32(ctx->r6, 0X2A98);
    // 0x80002A18: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x80002A1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80002A20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80002A24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80002A28: jal         0x800C8DB0
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_16;
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_16:
    // 0x80002A30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80002A34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80002A38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80002A3C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80002A40: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80002A48: jr          $ra
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void audioStartThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A5C: jal         0x800C8F00
    // 0x80002A60: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A60: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    after_0:
    // 0x80002A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A6C: jr          $ra
    // 0x80002A70: nop

    return;
    // 0x80002A70: nop

;}
RECOMP_FUNC void audioStopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A80: jal         0x800C9050
    // 0x80002A84: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A84: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    after_0:
    // 0x80002A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A90: jr          $ra
    // 0x80002A94: nop

    return;
    // 0x80002A94: nop

;}
RECOMP_FUNC void __amMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A98: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002A9C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80002AA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002AA4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002AA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002AAC: lw          $a0, 0x6510($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6510);
    // 0x80002AB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002AB4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80002AB8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002ABC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002AC0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002AC4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002AC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002ACC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002AD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002ADC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002AE0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80002AE4: addiu       $a2, $a2, 0x66E0
    ctx->r6 = ADD32(ctx->r6, 0X66E0);
    // 0x80002AE8: addiu       $a1, $a1, 0x67A0
    ctx->r5 = ADD32(ctx->r5, 0X67A0);
    // 0x80002AEC: jal         0x800798D0
    // 0x80002AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    osScAddClient(rdram, ctx);
        goto after_0;
    // 0x80002AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80002AF4: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x80002AF8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80002AFC: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80002B00: addiu       $s5, $s5, 0x6518
    ctx->r21 = ADD32(ctx->r21, 0X6518);
    // 0x80002B04: addiu       $s6, $s6, -0x3410
    ctx->r22 = ADD32(ctx->r22, -0X3410);
    // 0x80002B08: addiu       $fp, $fp, 0x6718
    ctx->r30 = ADD32(ctx->r30, 0X6718);
    // 0x80002B0C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80002B10: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80002B14: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80002B18: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80002B1C: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
L_80002B20:
    // 0x80002B20: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002B24: addiu       $a0, $a0, 0x66E0
    ctx->r4 = ADD32(ctx->r4, 0X66E0);
    // 0x80002B28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002B2C: jal         0x800C9110
    // 0x80002B30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002B30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80002B34: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80002B38: nop

    // 0x80002B3C: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80002B40: nop

    // 0x80002B44: beq         $v0, $s2, L_80002B64
    if (ctx->r2 == ctx->r18) {
        // 0x80002B48: nop
    
            goto L_80002B64;
    }
    // 0x80002B48: nop

    // 0x80002B4C: beq         $v0, $s3, L_80002BBC
    if (ctx->r2 == ctx->r19) {
        // 0x80002B50: nop
    
            goto L_80002BBC;
    }
    // 0x80002B50: nop

    // 0x80002B54: beq         $v0, $s4, L_80002BB8
    if (ctx->r2 == ctx->r20) {
        // 0x80002B58: nop
    
            goto L_80002BB8;
    }
    // 0x80002B58: nop

    // 0x80002B5C: b           L_80002BBC
    // 0x80002B60: nop

        goto L_80002BBC;
    // 0x80002B60: nop

L_80002B64:
    // 0x80002B64: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80002B68: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80002B6C: divu        $zero, $t7, $s7
    lo = S32(U32(ctx->r15) / U32(ctx->r23)); hi = S32(U32(ctx->r15) % U32(ctx->r23));
    // 0x80002B70: bne         $s7, $zero, L_80002B7C
    if (ctx->r23 != 0) {
        // 0x80002B74: nop
    
            goto L_80002B7C;
    }
    // 0x80002B74: nop

    // 0x80002B78: break       7
    do_break(2147494776);
L_80002B7C:
    // 0x80002B7C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80002B80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002B84: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80002B88: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x80002B8C: jal         0x80002C00
    // 0x80002B90: nop

    __amHandleFrameMsg(rdram, ctx);
        goto after_2;
    // 0x80002B90: nop

    after_2:
    // 0x80002B94: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80002B98: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80002B9C: jal         0x800C9110
    // 0x80002BA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80002BA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x80002BA4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80002BA8: jal         0x80002DF8
    // 0x80002BAC: nop

    __amHandleDoneMsg(rdram, ctx);
        goto after_4;
    // 0x80002BAC: nop

    after_4:
    // 0x80002BB0: b           L_80002BBC
    // 0x80002BB4: nop

        goto L_80002BBC;
    // 0x80002BB4: nop

L_80002BB8:
    // 0x80002BB8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80002BBC:
    // 0x80002BBC: beq         $s0, $zero, L_80002B20
    if (ctx->r16 == 0) {
        // 0x80002BC0: nop
    
            goto L_80002B20;
    }
    // 0x80002BC0: nop

    // 0x80002BC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002BC8: jal         0x800C8D14
    // 0x80002BCC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    alClose(rdram, ctx);
        goto after_5;
    // 0x80002BCC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    after_5:
    // 0x80002BD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002BE0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002BE4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002BE8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002BEC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002BF0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002BF4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002BF8: jr          $ra
    // 0x80002BFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002BFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __amHandleFrameMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002C04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002C0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002C10: jal         0x80003040
    // 0x80002C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    __clearAudioDMA(rdram, ctx);
        goto after_0;
    // 0x80002C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80002C18: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80002C1C: jal         0x800C9250
    // 0x80002C20: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C20: nop

    after_1:
    // 0x80002C24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80002C28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80002C2C: beq         $v1, $zero, L_80002C7C
    if (ctx->r3 == 0) {
        // 0x80002C30: nop
    
            goto L_80002C7C;
    }
    // 0x80002C30: nop

    // 0x80002C34: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80002C38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002C3C: sw          $a0, -0x33F8($at)
    MEM_W(-0X33F8, ctx->r1) = ctx->r4;
    // 0x80002C40: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80002C44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002C48: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80002C4C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80002C50: jal         0x800C92D0
    // 0x80002C54: sw          $t6, -0x33F4($at)
    MEM_W(-0X33F4, ctx->r1) = ctx->r14;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80002C54: sw          $t6, -0x33F4($at)
    MEM_W(-0X33F4, ctx->r1) = ctx->r14;
    after_2:
    // 0x80002C58: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002C5C: lb          $t7, -0x3404($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3404);
    // 0x80002C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002C64: beq         $t7, $zero, L_80002C7C
    if (ctx->r15 == 0) {
        // 0x80002C68: nop
    
            goto L_80002C7C;
    }
    // 0x80002C68: nop

    // 0x80002C6C: jal         0x8006FB8C
    // 0x80002C70: addiu       $a1, $zero, 0x2710
    ctx->r5 = ADD32(0, 0X2710);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x80002C70: addiu       $a1, $zero, 0x2710
    ctx->r5 = ADD32(0, 0X2710);
    after_3:
    // 0x80002C74: jal         0x800C8B60
    // 0x80002C78: addiu       $a0, $v0, 0x5622
    ctx->r4 = ADD32(ctx->r2, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_4;
    // 0x80002C78: addiu       $a0, $v0, 0x5622
    ctx->r4 = ADD32(ctx->r2, 0X5622);
    after_4:
L_80002C7C:
    // 0x80002C7C: jal         0x800C9380
    // 0x80002C80: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_5;
    // 0x80002C80: nop

    after_5:
    // 0x80002C84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80002C88: lw          $t8, -0x6454($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6454);
    // 0x80002C8C: srl         $t9, $v0, 2
    ctx->r25 = S32(U32(ctx->r2) >> 2);
    // 0x80002C90: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80002C94: addiu       $t1, $t0, 0x70
    ctx->r9 = ADD32(ctx->r8, 0X70);
    // 0x80002C98: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x80002C9C: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80002CA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80002CA4: lw          $v1, -0x6458($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6458);
    // 0x80002CA8: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80002CAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80002CB0: sltu        $at, $a3, $v1
    ctx->r1 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x80002CB4: beq         $at, $zero, L_80002CC8
    if (ctx->r1 == 0) {
        // 0x80002CB8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80002CC8;
    }
    // 0x80002CB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002CBC: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x80002CC0: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80002CC4: nop

L_80002CC8:
    // 0x80002CC8: lw          $t3, -0x3408($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3408);
    // 0x80002CCC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80002CD0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80002CD4: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80002CD8: lw          $a0, 0x6518($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6518);
    // 0x80002CDC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80002CE0: jal         0x800656D4
    // 0x80002CE4: addiu       $a1, $a1, -0x644C
    ctx->r5 = ADD32(ctx->r5, -0X644C);
    alAudioFrame(rdram, ctx);
        goto after_6;
    // 0x80002CE4: addiu       $a1, $a1, -0x644C
    ctx->r5 = ADD32(ctx->r5, -0X644C);
    after_6:
    // 0x80002CE8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80002CEC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80002CF0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80002CF4: addiu       $t5, $t5, 0x6718
    ctx->r13 = ADD32(ctx->r13, 0X6718);
    // 0x80002CF8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80002CFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80002D00: addiu       $a2, $a2, -0x3408
    ctx->r6 = ADD32(ctx->r6, -0X3408);
    // 0x80002D04: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80002D08: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
    // 0x80002D0C: sw          $s0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r16;
    // 0x80002D10: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80002D14: sw          $t6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r14;
    // 0x80002D18: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    // 0x80002D1C: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80002D20: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80002D24: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80002D28: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80002D2C: addiu       $a3, $a3, 0x6518
    ctx->r7 = ADD32(ctx->r7, 0X6518);
    // 0x80002D30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002D34: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x80002D38: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80002D3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80002D40: sw          $t1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r9;
    // 0x80002D44: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80002D48: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80002D4C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80002D50: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80002D54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80002D58: addiu       $a1, $a1, -0x75E0
    ctx->r5 = ADD32(ctx->r5, -0X75E0);
    // 0x80002D5C: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x80002D60: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80002D64: addiu       $t9, $t9, -0x7510
    ctx->r25 = ADD32(ctx->r25, -0X7510);
    // 0x80002D68: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80002D6C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x80002D70: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80002D74: subu        $t0, $t9, $a1
    ctx->r8 = SUB32(ctx->r25, ctx->r5);
    // 0x80002D78: addiu       $t1, $t1, 0x7B60
    ctx->r9 = ADD32(ctx->r9, 0X7B60);
    // 0x80002D7C: addiu       $t2, $t2, -0x61B0
    ctx->r10 = ADD32(ctx->r10, -0X61B0);
    // 0x80002D80: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80002D84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80002D88: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    // 0x80002D8C: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80002D90: sw          $a1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r5;
    // 0x80002D94: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80002D98: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80002D9C: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x80002DA0: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x80002DA4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x80002DA8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80002DAC: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80002DB0: sw          $t4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r12;
    // 0x80002DB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002DB8: lw          $a0, 0x6510($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6510);
    // 0x80002DBC: jal         0x800799C4
    // 0x80002DC0: nop

    osScGetCmdQ(rdram, ctx);
        goto after_7;
    // 0x80002DC0: nop

    after_7:
    // 0x80002DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002DC8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80002DCC: jal         0x800C9390
    // 0x80002DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80002DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80002DD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80002DD8: addiu       $v1, $v1, -0x3408
    ctx->r3 = ADD32(ctx->r3, -0X3408);
    // 0x80002DDC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80002DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002DE8: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x80002DEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80002DF0: jr          $ra
    // 0x80002DF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80002DF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __amHandleDoneMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002E00: jal         0x800C9380
    // 0x80002E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osAiGetLength_recomp(rdram, ctx);
        goto after_0;
    // 0x80002E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80002E08: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x80002E0C: bne         $t6, $zero, L_80002E28
    if (ctx->r14 != 0) {
        // 0x80002E10: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80002E28;
    }
    // 0x80002E10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002E14: lw          $t7, -0x33F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33F0);
    // 0x80002E18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002E1C: bne         $t7, $zero, L_80002E2C
    if (ctx->r15 != 0) {
        // 0x80002E20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80002E2C;
    }
    // 0x80002E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002E24: sw          $zero, -0x33F0($at)
    MEM_W(-0X33F0, ctx->r1) = 0;
L_80002E28:
    // 0x80002E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002E2C:
    // 0x80002E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002E30: jr          $ra
    // 0x80002E34: nop

    return;
    // 0x80002E34: nop

;}
RECOMP_FUNC void __amDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80002E3C: addiu       $t1, $t1, -0x6850
    ctx->r9 = ADD32(ctx->r9, -0X6850);
    // 0x80002E40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002E44: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80002E48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80002E4C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80002E50: andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // 0x80002E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80002E58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80002E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002E60: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80002E64: beq         $t0, $zero, L_80002EC0
    if (ctx->r8 == 0) {
        // 0x80002E68: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80002EC0;
    }
    // 0x80002E68: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80002E6C:
    // 0x80002E6C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80002E70: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x80002E74: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80002E78: bne         $at, $zero, L_80002EC0
    if (ctx->r1 != 0) {
        // 0x80002E7C: addiu       $v1, $v0, 0x400
        ctx->r3 = ADD32(ctx->r2, 0X400);
            goto L_80002EC0;
    }
    // 0x80002E7C: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x80002E80: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80002E84: bne         $at, $zero, L_80002EB0
    if (ctx->r1 != 0) {
        // 0x80002E88: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80002EB0;
    }
    // 0x80002E88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80002E8C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80002E90: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002E94: lw          $t7, -0x3410($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3410);
    // 0x80002E98: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80002E9C: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80002EA0: jal         0x800C9250
    // 0x80002EA4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80002EA4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x80002EA8: b           L_80002FFC
    // 0x80002EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80002FFC;
    // 0x80002EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80002EB0:
    // 0x80002EB0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80002EB4: nop

    // 0x80002EB8: bne         $s0, $zero, L_80002E6C
    if (ctx->r16 != 0) {
        // 0x80002EBC: nop
    
            goto L_80002E6C;
    }
    // 0x80002EBC: nop

L_80002EC0:
    // 0x80002EC0: lw          $s0, 0x8($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X8);
    // 0x80002EC4: nop

    // 0x80002EC8: bne         $s0, $zero, L_80002EDC
    if (ctx->r16 != 0) {
        // 0x80002ECC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002EDC;
    }
    // 0x80002ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002ED0: bne         $a2, $zero, L_80002EDC
    if (ctx->r6 != 0) {
        // 0x80002ED4: nop
    
            goto L_80002EDC;
    }
    // 0x80002ED4: nop

    // 0x80002ED8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80002EDC:
    // 0x80002EDC: bne         $s0, $zero, L_80002EFC
    if (ctx->r16 != 0) {
        // 0x80002EE0: nop
    
            goto L_80002EFC;
    }
    // 0x80002EE0: nop

    // 0x80002EE4: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80002EE8: jal         0x800C9250
    // 0x80002EEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80002EEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_1:
    // 0x80002EF0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002EF4: b           L_80002FF8
    // 0x80002EF8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
        goto L_80002FF8;
    // 0x80002EF8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80002EFC:
    // 0x80002EFC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80002F00: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80002F04: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80002F08: jal         0x800C8CC0
    // 0x80002F0C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x80002F0C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    after_2:
    // 0x80002F10: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80002F14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80002F18: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80002F1C: beq         $a2, $zero, L_80002F40
    if (ctx->r6 == 0) {
        // 0x80002F20: addiu       $t1, $t1, -0x6850
        ctx->r9 = ADD32(ctx->r9, -0X6850);
            goto L_80002F40;
    }
    // 0x80002F20: addiu       $t1, $t1, -0x6850
    ctx->r9 = ADD32(ctx->r9, -0X6850);
    // 0x80002F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002F28: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80002F2C: jal         0x800C8CF0
    // 0x80002F30: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    alLink(rdram, ctx);
        goto after_3;
    // 0x80002F30: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_3:
    // 0x80002F34: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80002F38: b           L_80002F74
    // 0x80002F3C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
        goto L_80002F74;
    // 0x80002F3C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80002F40:
    // 0x80002F40: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80002F44: nop

    // 0x80002F48: beq         $t0, $zero, L_80002F64
    if (ctx->r8 == 0) {
        // 0x80002F4C: nop
    
            goto L_80002F64;
    }
    // 0x80002F4C: nop

    // 0x80002F50: sw          $s0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r16;
    // 0x80002F54: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80002F58: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80002F5C: b           L_80002F70
    // 0x80002F60: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
        goto L_80002F70;
    // 0x80002F60: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
L_80002F64:
    // 0x80002F64: sw          $s0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r16;
    // 0x80002F68: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80002F6C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80002F70:
    // 0x80002F70: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80002F74:
    // 0x80002F74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80002F78: subu        $a3, $a3, $t4
    ctx->r7 = SUB32(ctx->r7, ctx->r12);
    // 0x80002F7C: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x80002F80: lw          $t5, -0x3410($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3410);
    // 0x80002F84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002F88: addiu       $t0, $t0, -0x340C
    ctx->r8 = ADD32(ctx->r8, -0X340C);
    // 0x80002F8C: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
    // 0x80002F90: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80002F94: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80002F98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80002F9C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80002FA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80002FA4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80002FA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002FAC: addiu       $t9, $t9, -0x5F90
    ctx->r25 = ADD32(ctx->r25, -0X5F90);
    // 0x80002FB0: addiu       $t7, $t7, -0x6440
    ctx->r15 = ADD32(ctx->r15, -0X6440);
    // 0x80002FB4: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80002FB8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80002FBC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80002FC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80002FC4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80002FC8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80002FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80002FD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002FD4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80002FD8: jal         0x800C94E0
    // 0x80002FDC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    osPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x80002FDC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_4:
    // 0x80002FE0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80002FE4: jal         0x800C9250
    // 0x80002FE8: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x80002FE8: nop

    after_5:
    // 0x80002FEC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002FF0: nop

    // 0x80002FF4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
L_80002FF8:
    // 0x80002FF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80002FFC:
    // 0x80002FFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80003000: jr          $ra
    // 0x80003004: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80003004: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __amDmaNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003008: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000300C: addiu       $v1, $v1, -0x6850
    ctx->r3 = ADD32(ctx->r3, -0X6850);
    // 0x80003010: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80003014: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80003018: bne         $t6, $zero, L_80003038
    if (ctx->r14 != 0) {
        // 0x8000301C: addiu       $v0, $v0, 0x2E38
        ctx->r2 = ADD32(ctx->r2, 0X2E38);
            goto L_80003038;
    }
    // 0x8000301C: addiu       $v0, $v0, 0x2E38
    ctx->r2 = ADD32(ctx->r2, 0X2E38);
    // 0x80003020: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80003024: addiu       $t7, $t7, -0x6840
    ctx->r15 = ADD32(ctx->r15, -0X6840);
    // 0x80003028: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000302C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80003030: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80003034: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80003038:
    // 0x80003038: jr          $ra
    // 0x8000303C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x8000303C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void __clearAudioDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003040: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80003044: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80003048: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8000304C: addiu       $s4, $s4, -0x340C
    ctx->r20 = ADD32(ctx->r20, -0X340C);
    // 0x80003050: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80003054: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003058: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000305C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80003060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003068: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8000306C: beq         $t6, $zero, L_800030A4
    if (ctx->r14 == 0) {
        // 0x80003070: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800030A4;
    }
    // 0x80003070: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80003074: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80003078: addiu       $s1, $s1, -0x5F90
    ctx->r17 = ADD32(ctx->r17, -0X5F90);
    // 0x8000307C: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x80003080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80003084:
    // 0x80003084: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80003088: jal         0x800C9110
    // 0x8000308C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000308C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80003090: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80003094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003098: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8000309C: bne         $at, $zero, L_80003084
    if (ctx->r1 != 0) {
        // 0x800030A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80003084;
    }
    // 0x800030A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800030A4:
    // 0x800030A4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800030A8: addiu       $s2, $s2, -0x6850
    ctx->r18 = ADD32(ctx->r18, -0X6850);
    // 0x800030AC: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x800030B0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800030B4: beq         $s0, $zero, L_80003128
    if (ctx->r16 == 0) {
        // 0x800030B8: addiu       $s3, $s3, -0x3410
        ctx->r19 = ADD32(ctx->r19, -0X3410);
            goto L_80003128;
    }
    // 0x800030B8: addiu       $s3, $s3, -0x3410
    ctx->r19 = ADD32(ctx->r19, -0X3410);
L_800030BC:
    // 0x800030BC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800030C0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800030C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800030C8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800030CC: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x800030D0: beq         $at, $zero, L_80003120
    if (ctx->r1 == 0) {
        // 0x800030D4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80003120;
    }
    // 0x800030D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800030D8: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x800030DC: nop

    // 0x800030E0: bne         $s0, $t1, L_800030EC
    if (ctx->r16 != ctx->r9) {
        // 0x800030E4: nop
    
            goto L_800030EC;
    }
    // 0x800030E4: nop

    // 0x800030E8: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_800030EC:
    // 0x800030EC: jal         0x800C8CC0
    // 0x800030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800030F4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800030F8: nop

    // 0x800030FC: beq         $a1, $zero, L_80003114
    if (ctx->r5 == 0) {
        // 0x80003100: nop
    
            goto L_80003114;
    }
    // 0x80003100: nop

    // 0x80003104: jal         0x800C8CF0
    // 0x80003108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80003108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000310C: b           L_80003120
    // 0x80003110: nop

        goto L_80003120;
    // 0x80003110: nop

L_80003114:
    // 0x80003114: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    // 0x80003118: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000311C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80003120:
    // 0x80003120: bne         $s1, $zero, L_800030BC
    if (ctx->r17 != 0) {
        // 0x80003124: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800030BC;
    }
    // 0x80003124: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80003128:
    // 0x80003128: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000312C: addiu       $s3, $s3, -0x3410
    ctx->r19 = ADD32(ctx->r19, -0X3410);
    // 0x80003130: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80003134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003138: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000313C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80003140: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80003144: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003148: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000314C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003150: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003154: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003158: jr          $ra
    // 0x8000315C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000315C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sndp_set_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003160: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80003164: bne         $at, $zero, L_80003170
    if (ctx->r1 != 0) {
        // 0x80003168: nop
    
            goto L_80003170;
    }
    // 0x80003168: nop

    // 0x8000316C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_80003170:
    // 0x80003170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003174: jr          $ra
    // 0x80003178: sw          $a0, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = ctx->r4;
    return;
    // 0x80003178: sw          $a0, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sndp_get_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000317C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003180: lw          $v0, -0x33D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33D0);
    // 0x80003184: jr          $ra
    // 0x80003188: nop

    return;
    // 0x80003188: nop

;}
RECOMP_FUNC void sndp_set_active_sound_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000318C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003190: lw          $v0, -0x33D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33D4);
    // 0x80003194: nop

    // 0x80003198: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8000319C: nop

    // 0x800031A0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800031A4: bne         $at, $zero, L_800031B4
    if (ctx->r1 != 0) {
        // 0x800031A8: nop
    
            goto L_800031B4;
    }
    // 0x800031A8: nop

    // 0x800031AC: jr          $ra
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
    return;
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
L_800031B4:
    // 0x800031B4: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x800031B8: jr          $ra
    // 0x800031BC: nop

    return;
    // 0x800031BC: nop

;}
RECOMP_FUNC void sndp_init_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800031C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800031C8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800031CC: addiu       $s2, $s2, -0x33D4
    ctx->r18 = ADD32(ctx->r18, -0X33D4);
    // 0x800031D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800031D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800031D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800031DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800031E0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800031E4: ori         $t1, $zero, 0x80E8
    ctx->r9 = 0 | 0X80E8;
    // 0x800031E8: sw          $t6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r14;
    // 0x800031EC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800031F0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800031F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800031F8: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
    // 0x800031FC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003204: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x80003208: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8000320C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003210: sw          $t1, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r9;
    // 0x80003214: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80003218: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8000321C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80003220: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80003224: jal         0x800C7D50
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8000322C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003234: sw          $v0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r2;
    // 0x80003238: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8000323C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80003240: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80003244: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003248: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000324C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80003250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003254: jal         0x800C7D50
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8000325C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80003260: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80003264: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003268: jal         0x800C98BC
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqNew(rdram, ctx);
        goto after_2;
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x80003270: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80003274: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003278: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8000327C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80003280: sw          $t9, -0x33D8($at)
    MEM_W(-0X33D8, ctx->r1) = ctx->r25;
    // 0x80003284: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003288: nop

    // 0x8000328C: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x80003290: bne         $at, $zero, L_800032C8
    if (ctx->r1 != 0) {
        // 0x80003294: nop
    
            goto L_800032C8;
    }
    // 0x80003294: nop

L_80003298:
    // 0x80003298: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000329C: sll         $t2, $s0, 6
    ctx->r10 = S32(ctx->r16 << 6);
    // 0x800032A0: lw          $v0, 0x40($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X40);
    // 0x800032A4: nop

    // 0x800032A8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    // 0x800032AC: jal         0x800C8CF0
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    after_3:
    // 0x800032B4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800032B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800032BC: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x800032C0: bne         $at, $zero, L_80003298
    if (ctx->r1 != 0) {
        // 0x800032C4: nop
    
            goto L_80003298;
    }
    // 0x800032C4: nop

L_800032C8:
    // 0x800032C8: lhu         $t4, 0x10($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X10);
    // 0x800032CC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800032D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800032D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800032D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800032DC: jal         0x800C7D50
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x800032E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800032E8: addiu       $a0, $a0, -0x5E58
    ctx->r4 = ADD32(ctx->r4, -0X5E58);
    // 0x800032EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800032F0: lhu         $t5, 0x10($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X10);
    // 0x800032F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800032F8: beq         $t5, $zero, L_8000332C
    if (ctx->r13 == 0) {
        // 0x800032FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000332C;
    }
    // 0x800032FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80003300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003304: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
L_80003308:
    // 0x80003308: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000330C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003310: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80003314: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x80003318: lhu         $t8, 0x10($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X10);
    // 0x8000331C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80003320: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80003324: bne         $at, $zero, L_80003308
    if (ctx->r1 != 0) {
        // 0x80003328: nop
    
            goto L_80003308;
    }
    // 0x80003328: nop

L_8000332C:
    // 0x8000332C: lw          $t9, 0x3D10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3D10);
    // 0x80003330: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003334: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80003338: sw          $t9, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r25;
    // 0x8000333C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80003340: addiu       $t2, $t2, 0x33C8
    ctx->r10 = ADD32(ctx->r10, 0X33C8);
    // 0x80003344: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80003348: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000334C: nop

    // 0x80003350: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80003354: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003358: nop

    // 0x8000335C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80003360: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003364: nop

    // 0x80003368: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8000336C: jal         0x800C9930
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80003374: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003378: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8000337C: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x80003380: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003384: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80003388: jal         0x800C970C
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_6:
    // 0x80003390: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003394: nop

    // 0x80003398: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8000339C: jal         0x800C9830
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    alEvtqNextEvent(rdram, ctx);
        goto after_7;
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_7:
    // 0x800033A4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800033A8: nop

    // 0x800033AC: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800033B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800033B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800033B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800033BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800033C0: jr          $ra
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sndp_voice_handler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800033CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800033D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800033D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800033D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800033DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800033E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800033E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800033E8: addiu       $s1, $a0, 0x28
    ctx->r17 = ADD32(ctx->r4, 0X28);
    // 0x800033EC: addiu       $s2, $a0, 0x14
    ctx->r18 = ADD32(ctx->r4, 0X14);
    // 0x800033F0: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x800033F4: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
L_800033F8:
    // 0x800033F8: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    // 0x800033FC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80003400: bne         $s3, $t6, L_80003424
    if (ctx->r19 != ctx->r14) {
        // 0x80003404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80003424;
    }
    // 0x80003404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003408: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8000340C: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003414: jal         0x800C970C
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8000341C: b           L_80003430
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80003430;
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003424:
    // 0x80003424: jal         0x80003470
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    sndp_handle_event(rdram, ctx);
        goto after_1;
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000342C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003430:
    // 0x80003430: jal         0x800C9830
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_2;
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80003438: beq         $v0, $zero, L_800033F8
    if (ctx->r2 == 0) {
        // 0x8000343C: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_800033F8;
    }
    // 0x8000343C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80003440: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80003444: nop

    // 0x80003448: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000344C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x80003450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003454: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003458: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000345C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003460: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003464: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003468: jr          $ra
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sndp_handle_event(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003470: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80003474: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80003478: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000347C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80003480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003488: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000348C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80003490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80003494: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80003498: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000349C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800034A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800034A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800034A8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800034AC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800034B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800034B4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x800034B8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800034BC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
L_800034C0:
    // 0x800034C0: nop

    // 0x800034C4: beq         $t7, $zero, L_800034E8
    if (ctx->r15 == 0) {
        // 0x800034C8: nop
    
            goto L_800034E8;
    }
    // 0x800034C8: nop

    // 0x800034CC: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
    // 0x800034D0: lhu         $t8, 0x0($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X0);
    // 0x800034D4: nop

    // 0x800034D8: sh          $t8, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r24;
    // 0x800034DC: lw          $t9, 0x8($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X8);
    // 0x800034E0: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x800034E4: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
L_800034E8:
    // 0x800034E8: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x800034EC: nop

    // 0x800034F0: lw          $s2, 0x8($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X8);
    // 0x800034F4: nop

    // 0x800034F8: bne         $s2, $zero, L_80003510
    if (ctx->r18 != 0) {
        // 0x800034FC: addiu       $a0, $sp, 0x72
        ctx->r4 = ADD32(ctx->r29, 0X72);
            goto L_80003510;
    }
    // 0x800034FC: addiu       $a0, $sp, 0x72
    ctx->r4 = ADD32(ctx->r29, 0X72);
    // 0x80003500: jal         0x800042CC
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    sndp_get_state_counts(rdram, ctx);
        goto after_0;
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_0:
    // 0x80003508: b           L_800040E0
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80003510:
    // 0x80003510: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003514: lw          $s6, 0x4($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X4);
    // 0x80003518: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8000351C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003520: nop

    // 0x80003524: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // 0x80003528: bne         $at, $zero, L_8000355C
    if (ctx->r1 != 0) {
        // 0x8000352C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000355C;
    }
    // 0x8000352C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003530: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80003534: beq         $v0, $at, L_8000400C
    if (ctx->r2 == ctx->r1) {
        // 0x80003538: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_8000400C;
    }
    // 0x80003538: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8000353C: beq         $v0, $at, L_80003A0C
    if (ctx->r2 == ctx->r1) {
        // 0x80003540: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80003A0C;
    }
    // 0x80003540: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80003544: beq         $v0, $at, L_80003D78
    if (ctx->r2 == ctx->r1) {
        // 0x80003548: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003D78;
    }
    // 0x80003548: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8000354C: beq         $v0, $at, L_80003A10
    if (ctx->r2 == ctx->r1) {
        // 0x80003550: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003A10;
    }
    // 0x80003550: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80003554: b           L_80004094
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_8000355C:
    // 0x8000355C: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80003560: bne         $at, $zero, L_80003580
    if (ctx->r1 != 0) {
        // 0x80003564: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80003580;
    }
    // 0x80003564: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80003568: beq         $v0, $at, L_80003FF0
    if (ctx->r2 == ctx->r1) {
        // 0x8000356C: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_80003FF0;
    }
    // 0x8000356C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80003570: beq         $v0, $at, L_80003C08
    if (ctx->r2 == ctx->r1) {
        // 0x80003574: nop
    
            goto L_80003C08;
    }
    // 0x80003574: nop

    // 0x80003578: b           L_80004094
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003580:
    // 0x80003580: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80003584: bne         $at, $zero, L_800035A0
    if (ctx->r1 != 0) {
        // 0x80003588: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800035A0;
    }
    // 0x80003588: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8000358C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80003590: beq         $v0, $at, L_80003E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80003594: nop
    
            goto L_80003E8C;
    }
    // 0x80003594: nop

    // 0x80003598: b           L_80004094
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_800035A0:
    // 0x800035A0: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x800035A4: beq         $at, $zero, L_80004090
    if (ctx->r1 == 0) {
        // 0x800035A8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80004090;
    }
    // 0x800035A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800035AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800035B0: addu        $at, $at, $t1
    gpr jr_addend_800035BC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800035B4: lw          $t1, 0x5140($at)
    ctx->r9 = ADD32(ctx->r1, 0X5140);
    // 0x800035B8: nop

    // 0x800035BC: jr          $t1
    // 0x800035C0: nop

    switch (jr_addend_800035BC >> 2) {
        case 0: goto L_800035C4; break;
        case 1: goto L_80003A0C; break;
        case 2: goto L_80004090; break;
        case 3: goto L_80003B2C; break;
        case 4: goto L_80004090; break;
        case 5: goto L_80004090; break;
        case 6: goto L_80004090; break;
        case 7: goto L_80003C8C; break;
        case 8: goto L_80004090; break;
        case 9: goto L_80004090; break;
        case 10: goto L_80004090; break;
        case 11: goto L_80004090; break;
        case 12: goto L_80004090; break;
        case 13: goto L_80004090; break;
        case 14: goto L_80004090; break;
        case 15: goto L_80003BA4; break;
        default: switch_error(__func__, 0x800035BC, 0x800E5140);
    }
    // 0x800035C0: nop

L_800035C4:
    // 0x800035C4: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x800035C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800035CC: beq         $v0, $at, L_800035E0
    if (ctx->r2 == ctx->r1) {
        // 0x800035D0: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_800035E0;
    }
    // 0x800035D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800035D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800035D8: bne         $v0, $at, L_800040E0
    if (ctx->r2 != ctx->r1) {
        // 0x800035DC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800035DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800035E0:
    // 0x800035E0: sh          $zero, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = 0;
    // 0x800035E4: lbu         $t2, 0x36($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X36);
    // 0x800035E8: sb          $zero, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = 0;
    // 0x800035EC: sh          $t2, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r10;
    // 0x800035F0: lw          $t4, 0x48($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X48);
    // 0x800035F4: lh          $t3, -0x33CC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X33CC);
    // 0x800035F8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x800035FC: slt         $s0, $t3, $t4
    ctx->r16 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80003600: xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // 0x80003604: beq         $s0, $zero, L_80003620
    if (ctx->r16 == 0) {
        // 0x80003608: nop
    
            goto L_80003620;
    }
    // 0x80003608: nop

    // 0x8000360C: lbu         $t5, 0x3E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003610: nop

    // 0x80003614: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80003618: beq         $t6, $zero, L_80003634
    if (ctx->r14 == 0) {
        // 0x8000361C: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_80003634;
    }
    // 0x8000361C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003620:
    // 0x80003620: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003624: jal         0x800C9A68
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    after_1:
    // 0x8000362C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80003630: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003634:
    // 0x80003634: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80003638: beq         $t7, $zero, L_80003650
    if (ctx->r15 == 0) {
        // 0x8000363C: sra         $t8, $a2, 16
        ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
            goto L_80003650;
    }
    // 0x8000363C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003640: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003644: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80003648: jal         0x80065CC0
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80065A80(rdram, ctx);
        goto after_2;
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_2:
L_80003650:
    // 0x80003650: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80003654: lbu         $v0, 0x3E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003658: bne         $t9, $zero, L_8000377C
    if (ctx->r25 != 0) {
        // 0x8000365C: addiu       $s3, $s1, 0xC
        ctx->r19 = ADD32(ctx->r17, 0XC);
            goto L_8000377C;
    }
    // 0x8000365C: addiu       $s3, $s1, 0xC
    ctx->r19 = ADD32(ctx->r17, 0XC);
    // 0x80003660: andi        $t0, $v0, 0x12
    ctx->r8 = ctx->r2 & 0X12;
    // 0x80003664: bne         $t0, $zero, L_8000367C
    if (ctx->r8 != 0) {
        // 0x80003668: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8000367C;
    }
    // 0x80003668: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8000366C: lw          $t1, 0x38($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X38);
    // 0x80003670: nop

    // 0x80003674: blez        $t1, L_800036A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80003678: nop
    
            goto L_800036A4;
    }
    // 0x80003678: nop

L_8000367C:
    // 0x8000367C: lw          $t3, 0x38($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X38);
    // 0x80003680: sb          $t2, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r10;
    // 0x80003684: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80003688: sw          $t4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r12;
    // 0x8000368C: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003690: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80003694: jal         0x800C970C
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    after_3:
    // 0x8000369C: b           L_800040E0
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800036A4:
    // 0x800036A4: beq         $s0, $zero, L_8000376C
    if (ctx->r16 == 0) {
        // 0x800036A8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8000376C;
    }
    // 0x800036A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800036AC: lw          $v0, -0x33DC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33DC);
    // 0x800036B0: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x800036B4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800036B8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_800036BC:
    // 0x800036BC: lbu         $t5, 0x36($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X36);
    // 0x800036C0: lbu         $t6, 0x36($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X36);
    // 0x800036C4: nop

    // 0x800036C8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800036CC: bne         $at, $zero, L_80003724
    if (ctx->r1 != 0) {
        // 0x800036D0: nop
    
            goto L_80003724;
    }
    // 0x800036D0: nop

    // 0x800036D4: lbu         $t7, 0x3F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3F);
    // 0x800036D8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800036DC: beq         $s2, $t7, L_80003724
    if (ctx->r18 == ctx->r15) {
        // 0x800036E0: addiu       $a0, $s7, 0x14
        ctx->r4 = ADD32(ctx->r23, 0X14);
            goto L_80003724;
    }
    // 0x800036E0: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x800036E4: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x800036E8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800036EC: sb          $s3, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r19;
    // 0x800036F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800036F4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800036F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800036FC: jal         0x800C970C
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_4:
    // 0x80003704: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003708: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000370C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003710: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003714: jal         0x800C9BB0
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    alSynSetVol(rdram, ctx);
        goto after_5;
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_5:
    // 0x8000371C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003720: nop

L_80003724:
    // 0x80003724: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80003728: beq         $s0, $zero, L_80003738
    if (ctx->r16 == 0) {
        // 0x8000372C: nop
    
            goto L_80003738;
    }
    // 0x8000372C: nop

    // 0x80003730: bne         $v0, $zero, L_800036BC
    if (ctx->r2 != 0) {
        // 0x80003734: nop
    
            goto L_800036BC;
    }
    // 0x80003734: nop

L_80003738:
    // 0x80003738: bne         $s0, $zero, L_8000375C
    if (ctx->r16 != 0) {
        // 0x8000373C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000375C;
    }
    // 0x8000373C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003740: sw          $t9, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r25;
    // 0x80003744: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003748: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000374C: jal         0x800C970C
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    after_6:
    // 0x80003754: b           L_800040E0
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000375C:
    // 0x8000375C: jal         0x8000410C
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_7;
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80003764: b           L_800040E0
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000376C:
    // 0x8000376C: jal         0x8000410C
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_8;
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80003774: b           L_800040E0
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000377C:
    // 0x8000377C: ori         $t0, $v0, 0x4
    ctx->r8 = ctx->r2 | 0X4;
    // 0x80003780: sb          $t0, 0x3E($s1)
    MEM_B(0X3E, ctx->r17) = ctx->r8;
    // 0x80003784: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x80003788: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000378C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80003790: jal         0x800C9C50
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    alSynStartVoice(rdram, ctx);
        goto after_9;
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    after_9:
    // 0x80003798: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000379C: sb          $t1, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r9;
    // 0x800037A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800037A4: lh          $t2, -0x33CC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X33CC);
    // 0x800037A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800037AC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800037B0: sh          $t3, -0x33CC($at)
    MEM_H(-0X33CC, ctx->r1) = ctx->r11;
    // 0x800037B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800037B8: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800037BC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800037C0: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800037C4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800037C8: lh          $t3, 0x34($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X34);
    // 0x800037CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800037D0: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800037D4: lbu         $t7, 0x2($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2);
    // 0x800037D8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800037DC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800037E0: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800037E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800037E8: lw          $t6, -0x5E58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E58);
    // 0x800037EC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800037F0: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x800037F4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800037F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800037FC: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80003800: mflo        $t4
    ctx->r12 = lo;
    // 0x80003804: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80003808: nop

    // 0x8000380C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80003810: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003814: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003818: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8000381C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80003820: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80003824: lbu         $t5, 0xD($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XD);
    // 0x80003828: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8000382C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003830: mflo        $t7
    ctx->r15 = lo;
    // 0x80003834: nop

    // 0x80003838: nop

    // 0x8000383C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80003840: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003844: mflo        $t8
    ctx->r24 = lo;
    // 0x80003848: nop

    // 0x8000384C: nop

    // 0x80003850: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003854: mflo        $a0
    ctx->r4 = lo;
    // 0x80003858: nop

    // 0x8000385C: nop

    // 0x80003860: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003864: mflo        $t6
    ctx->r14 = lo;
    // 0x80003868: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x8000386C: bgez        $a0, L_8000387C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003870: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000387C;
    }
    // 0x80003870: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003874: b           L_8000387C
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000387C;
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000387C:
    // 0x8000387C: lw          $t9, -0x33D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33D0);
    // 0x80003880: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003884: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003888: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000388C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80003894: mflo        $v0
    ctx->r2 = lo;
    // 0x80003898: srl         $t0, $v0, 8
    ctx->r8 = S32(U32(ctx->r2) >> 8);
    // 0x8000389C: jal         0x800C9BB0
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    alSynSetVol(rdram, ctx);
        goto after_10;
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    after_10:
    // 0x800038A4: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x800038A8: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x800038AC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800038B0: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800038B4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800038B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800038BC: jal         0x800C9BB0
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_11;
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_11:
    // 0x800038C4: lbu         $t3, 0x3C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3C);
    // 0x800038C8: lbu         $t4, 0xC($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XC);
    // 0x800038CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038D0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800038D4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800038D8: blez        $v1, L_800038E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038DC: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_800038E8;
    }
    // 0x800038DC: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x800038E0: b           L_800038E8
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800038E8;
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800038E8:
    // 0x800038E8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800038EC: beq         $at, $zero, L_8000390C
    if (ctx->r1 == 0) {
        // 0x800038F0: nop
    
            goto L_8000390C;
    }
    // 0x800038F0: nop

    // 0x800038F4: blez        $v1, L_80003904
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003904;
    }
    // 0x800038F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038FC: b           L_8000390C
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_8000390C;
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003904:
    // 0x80003904: b           L_8000390C
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_8000390C;
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_8000390C:
    // 0x8000390C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003910: jal         0x80065D60
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alSynSetPan(rdram, ctx);
        goto after_12;
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x80003918: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8000391C: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003920: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003924: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003928: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000392C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003930: jal         0x800C9CE0
    // 0x80003934: nop

    alSynSetPitch(rdram, ctx);
        goto after_13;
    // 0x80003934: nop

    after_13:
    // 0x80003938: lbu         $t7, 0x3($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X3);
    // 0x8000393C: lbu         $t5, 0x3D($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3D);
    // 0x80003940: andi        $t1, $t7, 0xF
    ctx->r9 = ctx->r15 & 0XF;
    // 0x80003944: addu        $v1, $t5, $t1
    ctx->r3 = ADD32(ctx->r13, ctx->r9);
    // 0x80003948: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8000394C: bgez        $t8, L_8000395C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80003950: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000395C;
    }
    // 0x80003950: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80003954: b           L_80003960
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003960;
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000395C:
    // 0x8000395C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003960:
    // 0x80003960: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003964: bne         $at, $zero, L_80003974
    if (ctx->r1 != 0) {
        // 0x80003968: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80003974;
    }
    // 0x80003968: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000396C: b           L_80003988
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003988;
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003974:
    // 0x80003974: bgez        $v1, L_80003984
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003978: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003984;
    }
    // 0x80003978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000397C: b           L_80003984
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003984;
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003984:
    // 0x80003984: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003988:
    // 0x80003988: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000398C: jal         0x800C9D70
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_14;
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_14:
    // 0x80003994: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80003998: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x8000399C: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x800039A0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800039A4: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800039A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800039AC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800039B0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800039B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800039B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800039BC: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x800039C0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800039C4: nop

    // 0x800039C8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800039CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800039D0: nop

    // 0x800039D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800039D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800039DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800039E0: nop

    // 0x800039E4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800039E8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800039EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800039F0: jal         0x800C970C
    // 0x800039F4: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_15;
    // 0x800039F4: nop

    after_15:
    // 0x800039F8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x800039FC: nop

    // 0x80003A00: andi        $t3, $v0, 0x2D1
    ctx->r11 = ctx->r2 & 0X2D1;
    // 0x80003A04: b           L_80004094
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80004094;
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80003A0C:
    // 0x80003A0C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
L_80003A10:
    // 0x80003A10: bne         $v1, $at, L_80003A2C
    if (ctx->r3 != ctx->r1) {
        // 0x80003A14: nop
    
            goto L_80003A2C;
    }
    // 0x80003A14: nop

    // 0x80003A18: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003A1C: nop

    // 0x80003A20: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80003A24: beq         $t7, $zero, L_80003B24
    if (ctx->r15 == 0) {
        // 0x80003A28: nop
    
            goto L_80003B24;
    }
    // 0x80003A28: nop

L_80003A2C:
    // 0x80003A2C: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003A30: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003A34: beq         $v0, $fp, L_80003A58
    if (ctx->r2 == ctx->r30) {
        // 0x80003A38: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80003A58;
    }
    // 0x80003A38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003A3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80003A40: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A44: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80003B00;
    }
    // 0x80003A44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80003A48: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A4C: nop
    
            goto L_80003B00;
    }
    // 0x80003A4C: nop

    // 0x80003A50: b           L_80003B14
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003A58:
    // 0x80003A58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80003A5C: jal         0x800041FC
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    sndp_remove_events(rdram, ctx);
        goto after_16;
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_16:
    // 0x80003A64: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003A68: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003A6C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80003A70: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003A74: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80003A78: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003A7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003A80: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003A84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003A88: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003A8C: nop

    // 0x80003A90: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003A94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003A98: nop

    // 0x80003A9C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003AA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003AA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003AA8: nop

    // 0x80003AAC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003AB0: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003AB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003AB8: jal         0x800C9BB0
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x80003AC0: beq         $s0, $zero, L_80003AEC
    if (ctx->r16 == 0) {
        // 0x80003AC4: addiu       $t6, $zero, 0x80
        ctx->r14 = ADD32(0, 0X80);
            goto L_80003AEC;
    }
    // 0x80003AC4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80003AC8: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x80003ACC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003AD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003AD4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003AD8: jal         0x800C970C
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80003AE0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003AE4: b           L_80003AF4
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
        goto L_80003AF4;
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
L_80003AEC:
    // 0x80003AEC: jal         0x8000410C
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_19;
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_80003AF4:
    // 0x80003AF4: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003AF8: b           L_80003B14
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B00:
    // 0x80003B00: jal         0x8000410C
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_20;
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80003B08: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B0C: nop

    // 0x80003B10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B14:
    // 0x80003B14: bne         $v1, $at, L_80003B24
    if (ctx->r3 != ctx->r1) {
        // 0x80003B18: addiu       $t0, $zero, 0x1000
        ctx->r8 = ADD32(0, 0X1000);
            goto L_80003B24;
    }
    // 0x80003B18: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80003B1C: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
    // 0x80003B20: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
L_80003B24:
    // 0x80003B24: b           L_80004094
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003B2C:
    // 0x80003B2C: lw          $t2, 0x8($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X8);
    // 0x80003B30: lbu         $t3, 0x3F($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003B34: sb          $t2, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r10;
    // 0x80003B38: bne         $fp, $t3, L_80003B90
    if (ctx->r30 != ctx->r11) {
        // 0x80003B3C: nop
    
            goto L_80003B90;
    }
    // 0x80003B3C: nop

    // 0x80003B40: lbu         $t7, 0xC($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC);
    // 0x80003B44: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x80003B48: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x80003B4C: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80003B50: blez        $v1, L_80003B60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B60;
    }
    // 0x80003B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B58: b           L_80003B60
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80003B60;
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003B60:
    // 0x80003B60: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80003B64: beq         $at, $zero, L_80003B84
    if (ctx->r1 == 0) {
        // 0x80003B68: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_80003B84;
    }
    // 0x80003B68: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80003B6C: blez        $v1, L_80003B7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B7C;
    }
    // 0x80003B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B74: b           L_80003B84
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_80003B84;
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003B7C:
    // 0x80003B7C: b           L_80003B84
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_80003B84;
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_80003B84:
    // 0x80003B84: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003B88: jal         0x80065D60
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    alSynSetPan(rdram, ctx);
        goto after_21;
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    after_21:
L_80003B90:
    // 0x80003B90: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B94: nop

    // 0x80003B98: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80003B9C: b           L_80004094
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80003BA4:
    // 0x80003BA4: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80003BA8: lbu         $t1, 0x3F($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003BAC: swc1        $f4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f4.u32l;
    // 0x80003BB0: bne         $fp, $t1, L_80003BF4
    if (ctx->r30 != ctx->r9) {
        // 0x80003BB4: nop
    
            goto L_80003BF4;
    }
    // 0x80003BB4: nop

    // 0x80003BB8: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003BBC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003BC0: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003BC4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003BC8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003BCC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003BD0: jal         0x800C9CE0
    // 0x80003BD4: nop

    alSynSetPitch(rdram, ctx);
        goto after_22;
    // 0x80003BD4: nop

    after_22:
    // 0x80003BD8: lbu         $t8, 0x3E($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003BDC: nop

    // 0x80003BE0: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x80003BE4: beq         $t6, $zero, L_80003BF4
    if (ctx->r14 == 0) {
        // 0x80003BE8: nop
    
            goto L_80003BF4;
    }
    // 0x80003BE8: nop

    // 0x80003BEC: jal         0x8000418C
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_23;
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
L_80003BF4:
    // 0x80003BF4: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003BF8: nop

    // 0x80003BFC: andi        $t9, $v0, 0x2D1
    ctx->r25 = ctx->r2 & 0X2D1;
    // 0x80003C00: b           L_80004094
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80004094;
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80003C08:
    // 0x80003C08: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80003C0C: lbu         $t2, 0x3F($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C10: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003C14: bne         $fp, $t2, L_80003C78
    if (ctx->r30 != ctx->r10) {
        // 0x80003C18: sb          $t0, 0x3D($s1)
        MEM_B(0X3D, ctx->r17) = ctx->r8;
            goto L_80003C78;
    }
    // 0x80003C18: sb          $t0, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = ctx->r8;
    // 0x80003C1C: lbu         $t4, 0x3($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X3);
    // 0x80003C20: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80003C24: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x80003C28: addu        $v1, $t3, $t7
    ctx->r3 = ADD32(ctx->r11, ctx->r15);
    // 0x80003C2C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80003C30: bgez        $t5, L_80003C40
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80003C34: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_80003C40;
    }
    // 0x80003C34: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80003C38: b           L_80003C44
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C44;
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C40:
    // 0x80003C40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003C44:
    // 0x80003C44: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003C48: bne         $at, $zero, L_80003C58
    if (ctx->r1 != 0) {
        // 0x80003C4C: nop
    
            goto L_80003C58;
    }
    // 0x80003C4C: nop

    // 0x80003C50: b           L_80003C6C
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003C6C;
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003C58:
    // 0x80003C58: bgez        $v1, L_80003C68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003C5C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003C68;
    }
    // 0x80003C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003C60: b           L_80003C68
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C68;
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C68:
    // 0x80003C68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003C6C:
    // 0x80003C6C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003C70: jal         0x800C9D70
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_24;
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_24:
L_80003C78:
    // 0x80003C78: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003C7C: nop

    // 0x80003C80: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003C84: b           L_80004094
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003C8C:
    // 0x80003C8C: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x80003C90: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C94: sh          $t8, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r24;
    // 0x80003C98: bne         $fp, $t6, L_80003D64
    if (ctx->r30 != ctx->r14) {
        // 0x80003C9C: nop
    
            goto L_80003D64;
    }
    // 0x80003C9C: nop

    // 0x80003CA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003CA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003CA8: lbu         $t1, 0xD($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0XD);
    // 0x80003CAC: lbu         $t0, 0x2($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X2);
    // 0x80003CB0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CB4: andi        $t2, $t0, 0x3F
    ctx->r10 = ctx->r8 & 0X3F;
    // 0x80003CB8: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003CBC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80003CC0: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003CC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80003CC8: lw          $t9, -0x5E58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E58);
    // 0x80003CCC: nop

    // 0x80003CD0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80003CD4: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80003CD8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003CDC: mflo        $t6
    ctx->r14 = lo;
    // 0x80003CE0: nop

    // 0x80003CE4: nop

    // 0x80003CE8: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CEC: mflo        $t2
    ctx->r10 = lo;
    // 0x80003CF0: nop

    // 0x80003CF4: nop

    // 0x80003CF8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80003CFC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003D00: mflo        $t9
    ctx->r25 = lo;
    // 0x80003D04: nop

    // 0x80003D08: nop

    // 0x80003D0C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D10: mflo        $a0
    ctx->r4 = lo;
    // 0x80003D14: nop

    // 0x80003D18: nop

    // 0x80003D1C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003D20: mflo        $t4
    ctx->r12 = lo;
    // 0x80003D24: addiu       $a0, $t4, -0x1
    ctx->r4 = ADD32(ctx->r12, -0X1);
    // 0x80003D28: bgez        $a0, L_80003D38
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003D2C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003D38;
    }
    // 0x80003D2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003D30: b           L_80003D38
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003D38;
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003D38:
    // 0x80003D38: lw          $t3, -0x33D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33D0);
    // 0x80003D3C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003D40: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D44: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003D48: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003D4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80003D50: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003D54: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003D58: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003D5C: jal         0x800C9BB0
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    alSynSetVol(rdram, ctx);
        goto after_25;
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_25:
L_80003D64:
    // 0x80003D64: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003D68: nop

    // 0x80003D6C: andi        $t8, $v0, 0x2D1
    ctx->r24 = ctx->r2 & 0X2D1;
    // 0x80003D70: b           L_80004094
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80004094;
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80003D78:
    // 0x80003D78: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003D7C: nop

    // 0x80003D80: bne         $fp, $t6, L_80003E84
    if (ctx->r30 != ctx->r14) {
        // 0x80003D84: nop
    
            goto L_80003E84;
    }
    // 0x80003D84: nop

    // 0x80003D88: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003D8C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003D90: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80003D94: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003D98: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80003D9C: lh          $t6, 0x34($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X34);
    // 0x80003DA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80003DA4: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x80003DA8: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003DAC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80003DB0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003DB4: andi        $t4, $t9, 0x3F
    ctx->r12 = ctx->r25 & 0X3F;
    // 0x80003DB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80003DBC: lw          $t7, -0x5E58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E58);
    // 0x80003DC0: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80003DC4: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x80003DC8: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80003DCC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003DD0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003DD4: mflo        $t0
    ctx->r8 = lo;
    // 0x80003DD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80003DDC: nop

    // 0x80003DE0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80003DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003DEC: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003DF0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80003DF4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80003DF8: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x80003DFC: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80003E00: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E04: mflo        $t9
    ctx->r25 = lo;
    // 0x80003E08: nop

    // 0x80003E0C: nop

    // 0x80003E10: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003E14: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003E18: mflo        $t4
    ctx->r12 = lo;
    // 0x80003E1C: nop

    // 0x80003E20: nop

    // 0x80003E24: multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E28: mflo        $a0
    ctx->r4 = lo;
    // 0x80003E2C: nop

    // 0x80003E30: nop

    // 0x80003E34: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003E38: mflo        $t7
    ctx->r15 = lo;
    // 0x80003E3C: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    // 0x80003E40: bgez        $a0, L_80003E50
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003E44: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003E50;
    }
    // 0x80003E44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003E48: b           L_80003E50
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003E50;
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003E50:
    // 0x80003E50: lw          $t3, -0x33D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33D0);
    // 0x80003E54: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003E58: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003E60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80003E64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003E68: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003E6C: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003E70: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003E74: jal         0x800C9BB0
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_26:
    // 0x80003E7C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003E80: nop

L_80003E84:
    // 0x80003E84: b           L_80004094
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003E8C:
    // 0x80003E8C: lbu         $t6, 0x3E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003E90: nop

    // 0x80003E94: andi        $t0, $t6, 0x2
    ctx->r8 = ctx->r14 & 0X2;
    // 0x80003E98: bne         $t0, $zero, L_80003FDC
    if (ctx->r8 != 0) {
        // 0x80003E9C: nop
    
            goto L_80003FDC;
    }
    // 0x80003E9C: nop

    // 0x80003EA0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003EA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003EA8: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x80003EAC: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003EB0: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EB4: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003EB8: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003EBC: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x80003EC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80003EC4: lw          $t2, -0x5E58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E58);
    // 0x80003EC8: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80003ECC: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x80003ED0: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x80003ED4: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003ED8: mflo        $t6
    ctx->r14 = lo;
    // 0x80003EDC: nop

    // 0x80003EE0: nop

    // 0x80003EE4: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80003EEC: nop

    // 0x80003EF0: nop

    // 0x80003EF4: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003EF8: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003EFC: mflo        $t1
    ctx->r9 = lo;
    // 0x80003F00: nop

    // 0x80003F04: nop

    // 0x80003F08: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F0C: mflo        $a0
    ctx->r4 = lo;
    // 0x80003F10: nop

    // 0x80003F14: nop

    // 0x80003F18: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003F1C: mflo        $t2
    ctx->r10 = lo;
    // 0x80003F20: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    // 0x80003F24: bgez        $a0, L_80003F34
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003F28: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003F34;
    }
    // 0x80003F28: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003F2C: b           L_80003F34
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003F34;
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003F34:
    // 0x80003F34: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80003F38: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003F3C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80003F40: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003F44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003F48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80003F4C: lw          $t4, -0x33D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33D0);
    // 0x80003F50: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003F54: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F58: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003F5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003F60: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003F64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003F68: srl         $t7, $v0, 8
    ctx->r15 = S32(U32(ctx->r2) >> 8);
    // 0x80003F6C: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x80003F70: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003F74: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003F78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003F7C: nop

    // 0x80003F80: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003F84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003F88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003F8C: nop

    // 0x80003F90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003F94: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003F98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003F9C: jal         0x800C9BB0
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_27;
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_27:
    // 0x80003FA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80003FA8: sh          $t0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r8;
    // 0x80003FAC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003FB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003FB4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003FB8: jal         0x800C970C
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_28;
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_28:
    // 0x80003FC0: lbu         $t9, 0x3E($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003FC4: nop

    // 0x80003FC8: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x80003FCC: beq         $t3, $zero, L_80003FDC
    if (ctx->r11 == 0) {
        // 0x80003FD0: nop
    
            goto L_80003FDC;
    }
    // 0x80003FD0: nop

    // 0x80003FD4: jal         0x8000418C
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_29;
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
L_80003FDC:
    // 0x80003FDC: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FE0: nop

    // 0x80003FE4: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003FE8: b           L_80004094
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003FF0:
    // 0x80003FF0: jal         0x8000410C
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_30;
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x80003FF8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FFC: nop

    // 0x80004000: andi        $t2, $v0, 0x2D1
    ctx->r10 = ctx->r2 & 0X2D1;
    // 0x80004004: b           L_80004094
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80004094;
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8000400C:
    // 0x8000400C: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80004010: nop

    // 0x80004014: andi        $t7, $t4, 0x10
    ctx->r15 = ctx->r12 & 0X10;
    // 0x80004018: beq         $t7, $zero, L_8000407C
    if (ctx->r15 == 0) {
        // 0x8000401C: nop
    
            goto L_8000407C;
    }
    // 0x8000401C: nop

    // 0x80004020: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80004024: lh          $a1, 0xA($s5)
    ctx->r5 = MEM_H(ctx->r21, 0XA);
    // 0x80004028: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x8000402C: jal         0x80004638
    // 0x80004030: nop

    sndp_play(rdram, ctx);
        goto after_31;
    // 0x80004030: nop

    after_31:
    // 0x80004034: beq         $v0, $zero, L_8000407C
    if (ctx->r2 == 0) {
        // 0x80004038: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000407C;
    }
    // 0x80004038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000403C: lh          $a2, 0x34($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X34);
    // 0x80004040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004044: jal         0x800049F8
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_32;
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_32:
    // 0x8000404C: lbu         $a2, 0x3C($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3C);
    // 0x80004050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004054: jal         0x800049F8
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_33;
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_33:
    // 0x8000405C: lbu         $a2, 0x3D($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3D);
    // 0x80004060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004064: jal         0x800049F8
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    sndp_set_param(rdram, ctx);
        goto after_34;
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_34:
    // 0x8000406C: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80004070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004074: jal         0x800049F8
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_35;
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_35:
L_8000407C:
    // 0x8000407C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80004080: nop

    // 0x80004084: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80004088: b           L_80004094
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80004090:
    // 0x80004090: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80004094:
    // 0x80004094: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80004098: nop

    // 0x8000409C: beq         $v1, $zero, L_800040BC
    if (ctx->r3 == 0) {
        // 0x800040A0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800040BC;
    }
    // 0x800040A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800040A4: bne         $v0, $zero, L_800040C0
    if (ctx->r2 != 0) {
        // 0x800040A8: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_800040C0;
    }
    // 0x800040A8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800040AC: lbu         $t8, 0x3E($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3E);
    // 0x800040B0: nop

    // 0x800040B4: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800040B8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
L_800040BC:
    // 0x800040BC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
L_800040C0:
    // 0x800040C0: nop

    // 0x800040C4: bne         $t0, $zero, L_800040E0
    if (ctx->r8 != 0) {
        // 0x800040C8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040CC: beq         $v1, $zero, L_800040E0
    if (ctx->r3 == 0) {
        // 0x800040D0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040D4: beq         $v0, $zero, L_800034C0
    if (ctx->r2 == 0) {
        // 0x800040D8: lw          $t7, 0x74($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X74);
            goto L_800034C0;
    }
    // 0x800040D8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800040DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800040E0:
    // 0x800040E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800040E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800040E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800040EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800040F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800040F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800040F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800040FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004100: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004104: jr          $ra
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void sndp_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000410C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004118: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x8000411C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80004120: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80004124: beq         $t8, $zero, L_80004158
    if (ctx->r24 == 0) {
        // 0x80004128: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80004158;
    }
    // 0x80004128: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000412C: lw          $t9, -0x33D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33D4);
    // 0x80004130: addiu       $a1, $t6, 0xC
    ctx->r5 = ADD32(ctx->r14, 0XC);
    // 0x80004134: lw          $a0, 0x38($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X38);
    // 0x80004138: jal         0x800C9E10
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    alSynStopVoice(rdram, ctx);
        goto after_0;
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80004140: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80004144: lw          $t0, -0x33D4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X33D4);
    // 0x80004148: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000414C: lw          $a0, 0x38($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X38);
    // 0x80004150: jal         0x800C9E90
    // 0x80004154: nop

    alSynFreeVoice(rdram, ctx);
        goto after_1;
    // 0x80004154: nop

    after_1:
L_80004158:
    // 0x80004158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000415C: jal         0x80004520
    // 0x80004160: nop

    sndp_deallocate(rdram, ctx);
        goto after_2;
    // 0x80004160: nop

    after_2:
    // 0x80004164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004168: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x8000416C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80004170: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80004174: jal         0x800041FC
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    sndp_remove_events(rdram, ctx);
        goto after_3;
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x8000417C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004184: jr          $ra
    // 0x80004188: nop

    return;
    // 0x80004188: nop

;}
RECOMP_FUNC void sndp_apply_pitch_slide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000418C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004194: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80004198: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000419C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800041A0: nop

    // 0x800041A4: lb          $a0, 0x5($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X5);
    // 0x800041A8: jal         0x800C9F40
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    alCents2Ratio(rdram, ctx);
        goto after_0;
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800041B0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800041B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800041B8: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800041BC: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x800041C0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800041C4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800041C8: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800041CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800041D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800041D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800041D8: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    // 0x800041DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800041E0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800041E4: jal         0x800C970C
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_1:
    // 0x800041EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800041F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800041F4: jr          $ra
    // 0x800041F8: nop

    return;
    // 0x800041F8: nop

;}
RECOMP_FUNC void sndp_remove_events(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004200: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004204: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80004208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000420C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004214: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004218: andi        $s4, $a2, 0xFFFF
    ctx->r20 = ctx->r6 & 0XFFFF;
    // 0x8000421C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004224: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80004228: jal         0x800C9F90
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004230: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80004234: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80004238: nop

    // 0x8000423C: beq         $s0, $zero, L_800042A4
    if (ctx->r16 == 0) {
        // 0x80004240: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800042A4;
    }
    // 0x80004240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80004244:
    // 0x80004244: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80004248: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000424C: bne         $s3, $t6, L_80004298
    if (ctx->r19 != ctx->r14) {
        // 0x80004250: nop
    
            goto L_80004298;
    }
    // 0x80004250: nop

    // 0x80004254: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x80004258: nop

    // 0x8000425C: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x80004260: beq         $t8, $zero, L_80004298
    if (ctx->r24 == 0) {
        // 0x80004264: nop
    
            goto L_80004298;
    }
    // 0x80004264: nop

    // 0x80004268: beq         $s1, $zero, L_80004284
    if (ctx->r17 == 0) {
        // 0x8000426C: nop
    
            goto L_80004284;
    }
    // 0x8000426C: nop

    // 0x80004270: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80004274: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80004278: nop

    // 0x8000427C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80004280: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_80004284:
    // 0x80004284: jal         0x800C8CC0
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000428C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004290: jal         0x800C8CF0
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_80004298:
    // 0x80004298: bne         $s1, $zero, L_80004244
    if (ctx->r17 != 0) {
        // 0x8000429C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80004244;
    }
    // 0x8000429C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800042A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800042A4:
    // 0x800042A4: jal         0x800C9F90
    // 0x800042A8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800042A8: nop

    after_3:
    // 0x800042AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800042B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800042B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800042B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800042BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800042C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800042C4: jr          $ra
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sndp_get_state_counts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800042D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800042D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800042D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800042DC: jal         0x800C9F90
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800042E4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800042E8: addiu       $a3, $a3, -0x33E0
    ctx->r7 = ADD32(ctx->r7, -0X33E0);
    // 0x800042EC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800042F0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800042F4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x800042F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800042FC: beq         $v1, $zero, L_80004318
    if (ctx->r3 == 0) {
        // 0x80004300: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80004318;
    }
    // 0x80004300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80004304:
    // 0x80004304: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80004308: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000430C: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x80004310: bne         $v1, $zero, L_80004304
    if (ctx->r3 != 0) {
        // 0x80004314: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80004304;
    }
    // 0x80004314: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_80004318:
    // 0x80004318: beq         $a0, $zero, L_80004334
    if (ctx->r4 == 0) {
        // 0x8000431C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004334;
    }
    // 0x8000431C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004320:
    // 0x80004320: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80004324: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004328: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8000432C: bne         $a0, $zero, L_80004320
    if (ctx->r4 != 0) {
        // 0x80004330: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80004320;
    }
    // 0x80004330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80004334:
    // 0x80004334: beq         $a1, $zero, L_80004350
    if (ctx->r5 == 0) {
        // 0x80004338: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80004350;
    }
    // 0x80004338: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000433C:
    // 0x8000433C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x80004340: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004344: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80004348: bne         $a1, $zero, L_8000433C
    if (ctx->r5 != 0) {
        // 0x8000434C: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000433C;
    }
    // 0x8000434C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80004350:
    // 0x80004350: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80004354: nop

    // 0x80004358: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x8000435C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80004360: nop

    // 0x80004364: sh          $a2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r6;
    // 0x80004368: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000436C: jal         0x800C9F90
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    after_1:
    // 0x80004374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004378: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8000437C: jr          $ra
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sndp_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004384: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000438C: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x80004390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004394: lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X8);
    // 0x80004398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000439C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800043A0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800043A4: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x800043A8: beq         $s0, $zero, L_8000450C
    if (ctx->r16 == 0) {
        // 0x800043AC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000450C;
    }
    // 0x800043AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800043B0: jal         0x800C9F90
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800043B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800043BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800043C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043C4: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x800043C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800043CC: jal         0x800C8CC0
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    after_1:
    // 0x800043D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043D8: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x800043DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800043E0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800043E4: beq         $v0, $zero, L_80004408
    if (ctx->r2 == 0) {
        // 0x800043E8: nop
    
            goto L_80004408;
    }
    // 0x800043E8: nop

    // 0x800043EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800043F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800043F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800043F8: nop

    // 0x800043FC: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x80004400: b           L_80004418
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
        goto L_80004418;
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_80004408:
    // 0x80004408: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000440C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80004410: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80004414: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
L_80004418:
    // 0x80004418: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000441C: jal         0x800C9F90
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80004424: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004428: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000442C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80004430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80004434: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x80004438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000443C: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80004440: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80004444: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    // 0x80004448: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8000444C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80004450: sb          $a1, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r5;
    // 0x80004454: sb          $t1, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r9;
    // 0x80004458: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8000445C: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    // 0x80004460: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80004464: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x80004468: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8000446C: andi        $t5, $t3, 0xF0
    ctx->r13 = ctx->r11 & 0XF0;
    // 0x80004470: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80004474: beq         $t6, $zero, L_800044AC
    if (ctx->r14 == 0) {
        // 0x80004478: sb          $t5, 0x3E($s0)
        MEM_B(0X3E, ctx->r16) = ctx->r13;
            goto L_800044AC;
    }
    // 0x80004478: sb          $t5, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r13;
    // 0x8000447C: lbu         $a0, 0x4($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X4);
    // 0x80004480: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80004484: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80004488: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8000448C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004490: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80004494: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004498: jal         0x800C9F40
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    after_3:
    // 0x800044A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044A4: b           L_800044E0
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_800044E0;
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044AC:
    // 0x800044AC: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    // 0x800044B0: lb          $t0, 0x5($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X5);
    // 0x800044B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800044B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800044BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800044C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800044C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800044C8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800044CC: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    // 0x800044D0: jal         0x800C9F40
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800044D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044DC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044E0:
    // 0x800044E0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800044E4: beq         $a1, $at, L_800044FC
    if (ctx->r5 == ctx->r1) {
        // 0x800044E8: addiu       $t3, $zero, 0x40
        ctx->r11 = ADD32(0, 0X40);
            goto L_800044FC;
    }
    // 0x800044E8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800044EC: lbu         $t1, 0x3E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X3E);
    // 0x800044F0: nop

    // 0x800044F4: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800044F8: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
L_800044FC:
    // 0x800044FC: addiu       $t4, $zero, 0x7FFF
    ctx->r12 = ADD32(0, 0X7FFF);
    // 0x80004500: sb          $zero, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = 0;
    // 0x80004504: sb          $t3, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r11;
    // 0x80004508: sh          $t4, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r12;
L_8000450C:
    // 0x8000450C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004510: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80004514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004518: jr          $ra
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sndp_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004520: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004524: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x80004528: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000452C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004530: bne         $a0, $t6, L_80004544
    if (ctx->r4 != ctx->r14) {
        // 0x80004534: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80004544;
    }
    // 0x80004534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004538: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000453C: nop

    // 0x80004540: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80004544:
    // 0x80004544: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80004548: nop

    // 0x8000454C: bne         $a0, $t8, L_80004560
    if (ctx->r4 != ctx->r24) {
        // 0x80004550: nop
    
            goto L_80004560;
    }
    // 0x80004550: nop

    // 0x80004554: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80004558: nop

    // 0x8000455C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80004560:
    // 0x80004560: jal         0x800C8CC0
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80004568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000456C: addiu       $v0, $v0, -0x33E0
    ctx->r2 = ADD32(ctx->r2, -0X33E0);
    // 0x80004570: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80004574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80004578: beq         $v1, $zero, L_8000459C
    if (ctx->r3 == 0) {
        // 0x8000457C: nop
    
            goto L_8000459C;
    }
    // 0x8000457C: nop

    // 0x80004580: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80004584: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80004588: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8000458C: nop

    // 0x80004590: sw          $a0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r4;
    // 0x80004594: b           L_800045A8
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
        goto L_800045A8;
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_8000459C:
    // 0x8000459C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800045A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800045A4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_800045A8:
    // 0x800045A8: lbu         $t1, 0x3E($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3E);
    // 0x800045AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800045B0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800045B4: beq         $t2, $zero, L_800045CC
    if (ctx->r10 == 0) {
        // 0x800045B8: addiu       $v0, $v0, -0x33CC
        ctx->r2 = ADD32(ctx->r2, -0X33CC);
            goto L_800045CC;
    }
    // 0x800045B8: addiu       $v0, $v0, -0x33CC
    ctx->r2 = ADD32(ctx->r2, -0X33CC);
    // 0x800045BC: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800045C0: nop

    // 0x800045C4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800045C8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_800045CC:
    // 0x800045CC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800045D0: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
    // 0x800045D4: beq         $v0, $zero, L_800045F8
    if (ctx->r2 == 0) {
        // 0x800045D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800045F8;
    }
    // 0x800045D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800045DC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800045E0: nop

    // 0x800045E4: bne         $a0, $t5, L_800045F0
    if (ctx->r4 != ctx->r13) {
        // 0x800045E8: nop
    
            goto L_800045F0;
    }
    // 0x800045E8: nop

    // 0x800045EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800045F0:
    // 0x800045F0: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800045F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800045F8:
    // 0x800045F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800045FC: jr          $ra
    // 0x80004600: nop

    return;
    // 0x80004600: nop

;}
RECOMP_FUNC void sndp_set_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80004608: beq         $a0, $zero, L_80004614
    if (ctx->r4 == 0) {
        // 0x8000460C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_80004614;
    }
    // 0x8000460C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80004610: sb          $t6, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r14;
L_80004614:
    // 0x80004614: jr          $ra
    // 0x80004618: nop

    return;
    // 0x80004618: nop

;}
RECOMP_FUNC void sndp_get_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000461C: beq         $a0, $zero, L_80004630
    if (ctx->r4 == 0) {
        // 0x80004620: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004630;
    }
    // 0x80004620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004624: lbu         $v0, 0x3F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3F);
    // 0x80004628: jr          $ra
    // 0x8000462C: nop

    return;
    // 0x8000462C: nop

L_80004630:
    // 0x80004630: jr          $ra
    // 0x80004634: nop

    return;
    // 0x80004634: nop

;}
RECOMP_FUNC void sndp_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000463C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004644: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80004648: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000464C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80004650: jal         0x80004668
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80004658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000465C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004660: jr          $ra
    // 0x80004664: nop

    return;
    // 0x80004664: nop

;}
RECOMP_FUNC void sndp_play_with_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004668: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000466C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004670: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80004674: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80004678: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000467C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004680: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004684: andi        $fp, $a2, 0xFF
    ctx->r30 = ctx->r6 & 0XFF;
    // 0x80004688: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8000468C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80004690: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004694: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004698: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000469C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800046A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800046A4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800046A8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800046AC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800046B0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800046B4: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x800046B8: bne         $t6, $zero, L_800046C8
    if (ctx->r14 != 0) {
        // 0x800046BC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800046C8;
    }
    // 0x800046BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800046C0: b           L_8000485C
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000485C;
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046C8:
    // 0x800046C8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800046CC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800046D0: addiu       $s5, $s5, -0x33D4
    ctx->r21 = ADD32(ctx->r21, -0X33D4);
    // 0x800046D4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800046D8: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x800046DC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_800046E0:
    // 0x800046E0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800046E4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800046E8: nop

    // 0x800046EC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800046F0: lw          $s2, 0xC($t9)
    ctx->r18 = MEM_W(ctx->r25, 0XC);
    // 0x800046F4: jal         0x80004384
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    sndp_allocate(rdram, ctx);
        goto after_0;
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800046FC: beq         $v0, $zero, L_800047B0
    if (ctx->r2 == 0) {
        // 0x80004700: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800047B0;
    }
    // 0x80004700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004704: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80004708: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000470C: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // 0x80004710: sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // 0x80004714: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80004718: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8000471C: addiu       $a2, $s4, 0x1
    ctx->r6 = ADD32(ctx->r20, 0X1);
    // 0x80004720: lbu         $s3, 0x1($t2)
    ctx->r19 = MEM_BU(ctx->r10, 0X1);
    // 0x80004724: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004728: sll         $t3, $s3, 6
    ctx->r11 = S32(ctx->r19 << 6);
    // 0x8000472C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004730: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80004734: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004738: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000473C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x80004740: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004744: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004748: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000474C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004750: beq         $fp, $zero, L_8000475C
    if (ctx->r30 == 0) {
        // 0x80004754: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_8000475C;
    }
    // 0x80004754: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80004758: sb          $fp, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r30;
L_8000475C:
    // 0x8000475C: lbu         $t4, 0x3E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3E);
    // 0x80004760: nop

    // 0x80004764: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80004768: beq         $t5, $zero, L_8000479C
    if (ctx->r13 == 0) {
        // 0x8000476C: nop
    
            goto L_8000479C;
    }
    // 0x8000476C: nop

    // 0x80004770: lbu         $t6, 0x3E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004774: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004778: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8000477C: sb          $t7, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r15;
    // 0x80004780: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80004784: jal         0x800C970C
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8000478C: addiu       $t8, $s3, 0x1
    ctx->r24 = ADD32(ctx->r19, 0X1);
    // 0x80004790: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80004794: b           L_800047AC
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
        goto L_800047AC;
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
L_8000479C:
    // 0x8000479C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800047A0: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800047A4: jal         0x800C970C
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_2;
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
L_800047AC:
    // 0x800047AC: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_800047B0:
    // 0x800047B0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800047B4: addu        $s4, $s4, $s3
    ctx->r20 = ADD32(ctx->r20, ctx->r19);
    // 0x800047B8: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x800047BC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800047C0: andi        $t1, $t0, 0xC0
    ctx->r9 = ctx->r8 & 0XC0;
    // 0x800047C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800047C8: addu        $s1, $t9, $t2
    ctx->r17 = ADD32(ctx->r25, ctx->r10);
    // 0x800047CC: sll         $t3, $s1, 16
    ctx->r11 = S32(ctx->r17 << 16);
    // 0x800047D0: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800047D4: beq         $s1, $zero, L_800047E8
    if (ctx->r17 == 0) {
        // 0x800047D8: nop
    
            goto L_800047E8;
    }
    // 0x800047D8: nop

    // 0x800047DC: bne         $s0, $zero, L_800046E0
    if (ctx->r16 != 0) {
        // 0x800047E0: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_800046E0;
    }
    // 0x800047E0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800047E4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
L_800047E8:
    // 0x800047E8: beq         $s7, $zero, L_8000484C
    if (ctx->r23 == 0) {
        // 0x800047EC: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x800047EC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800047F0: lbu         $t5, 0x3E($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X3E);
    // 0x800047F4: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x800047F8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800047FC: sb          $t6, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r14;
    // 0x80004800: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80004804: ori         $t1, $t6, 0x10
    ctx->r9 = ctx->r14 | 0X10;
    // 0x80004808: sw          $t7, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r15;
    // 0x8000480C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80004810: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80004814: beq         $t8, $zero, L_8000484C
    if (ctx->r24 == 0) {
        // 0x80004818: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x80004818: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8000481C: sb          $t1, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r9;
    // 0x80004820: lh          $t2, 0x6E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6E);
    // 0x80004824: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80004828: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8000482C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80004830: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x80004834: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80004838: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8000483C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80004840: jal         0x800C970C
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x80004848: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
L_8000484C:
    // 0x8000484C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80004850: beq         $t4, $zero, L_8000485C
    if (ctx->r12 == 0) {
        // 0x80004854: nop
    
            goto L_8000485C;
    }
    // 0x80004854: nop

    // 0x80004858: sw          $s7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r23;
L_8000485C:
    // 0x8000485C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80004860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004864: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004868: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000486C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004870: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004874: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80004878: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000487C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004880: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004884: jr          $ra
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void sndp_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000488C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004890: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80004894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004898: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8000489C: beq         $a0, $zero, L_800048C8
    if (ctx->r4 == 0) {
        // 0x800048A0: sw          $a0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r4;
            goto L_800048C8;
    }
    // 0x800048A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x800048A4: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x800048A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800048AC: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x800048B0: sb          $t8, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r24;
    // 0x800048B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800048B8: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x800048BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800048C0: jal         0x800C970C
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_800048C8:
    // 0x800048C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800048CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800048D0: jr          $ra
    // 0x800048D4: nop

    return;
    // 0x800048D4: nop

;}
RECOMP_FUNC void sndp_stop_with_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800048DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800048E0: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x800048E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800048E8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800048EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800048F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800048F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800048F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800048FC: jal         0x800C9F90
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004904: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004908: lw          $s0, -0x33E0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33E0);
    // 0x8000490C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80004910: beq         $s0, $zero, L_8000496C
    if (ctx->r16 == 0) {
        // 0x80004914: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8000496C;
    }
    // 0x80004914: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004918: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000491C: addiu       $s3, $s3, -0x33D4
    ctx->r19 = ADD32(ctx->r19, -0X33D4);
    // 0x80004920: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x80004924: addiu       $s2, $zero, -0x11
    ctx->r18 = ADD32(0, -0X11);
    // 0x80004928: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000492C:
    // 0x8000492C: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x80004930: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80004934: lbu         $v0, 0x3E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004938: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000493C: and         $t7, $v0, $s1
    ctx->r15 = ctx->r2 & ctx->r17;
    // 0x80004940: bne         $s1, $t7, L_8000495C
    if (ctx->r17 != ctx->r15) {
        // 0x80004944: and         $t8, $v0, $s2
        ctx->r24 = ctx->r2 & ctx->r18;
            goto L_8000495C;
    }
    // 0x80004944: and         $t8, $v0, $s2
    ctx->r24 = ctx->r2 & ctx->r18;
    // 0x80004948: sb          $t8, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r24;
    // 0x8000494C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80004950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004954: jal         0x800C970C
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_8000495C:
    // 0x8000495C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004960: nop

    // 0x80004964: bne         $s0, $zero, L_8000492C
    if (ctx->r16 != 0) {
        // 0x80004968: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_8000492C;
    }
    // 0x80004968: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000496C:
    // 0x8000496C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80004970: jal         0x800C9F90
    // 0x80004974: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004974: nop

    after_2:
    // 0x80004978: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000497C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000498C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004990: jr          $ra
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sndp_stop_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000499C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049A0: jal         0x800048D8
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800049A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049B0: jr          $ra
    // 0x800049B4: nop

    return;
    // 0x800049B4: nop

;}
