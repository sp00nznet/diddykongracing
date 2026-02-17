#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_init_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80036C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80036C78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80036C7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80036C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036C84: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80036C88: lbu         $t6, 0xE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XE);
    // 0x80036C8C: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x80036C90: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80036C94: sh          $t7, 0x100($s0)
    MEM_H(0X100, ctx->r16) = ctx->r15;
    // 0x80036C98: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x80036C9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80036CA0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80036CA4: sh          $t9, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r25;
    // 0x80036CA8: lhu         $t0, 0x8($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X8);
    // 0x80036CAC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80036CB0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80036CB4: bgez        $t0, L_80036CCC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80036CB8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80036CCC;
    }
    // 0x80036CB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80036CBC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036CC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036CC4: nop

    // 0x80036CC8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80036CCC:
    // 0x80036CCC: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x80036CD0: lbu         $t1, 0xA($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XA);
    // 0x80036CD4: nop

    // 0x80036CD8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80036CDC: bgez        $t1, L_80036CF4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80036CE0: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80036CF4;
    }
    // 0x80036CE0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036CE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036CEC: nop

    // 0x80036CF0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80036CF4:
    // 0x80036CF4: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
    // 0x80036CF8: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x80036CFC: nop

    // 0x80036D00: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80036D04: nop

    // 0x80036D08: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80036D0C: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x80036D10: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x80036D14: nop

    // 0x80036D18: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80036D1C: nop

    // 0x80036D20: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036D24: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x80036D28: lh          $t4, 0x6($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X6);
    // 0x80036D2C: nop

    // 0x80036D30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80036D34: nop

    // 0x80036D38: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80036D3C: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x80036D40: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80036D44: nop

    // 0x80036D48: bne         $t5, $zero, L_80036D84
    if (ctx->r13 != 0) {
        // 0x80036D4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80036D84;
    }
    // 0x80036D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D50: jal         0x8006FB8C
    // 0x80036D54: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80036D54: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x80036D58: sh          $v0, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r2;
    // 0x80036D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D60: jal         0x8006FB8C
    // 0x80036D64: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80036D64: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x80036D68: sh          $v0, 0x102($s0)
    MEM_H(0X102, ctx->r16) = ctx->r2;
    // 0x80036D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D70: jal         0x8006FB8C
    // 0x80036D74: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80036D74: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_2:
    // 0x80036D78: sh          $v0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r2;
    // 0x80036D7C: b           L_80036D94
    // 0x80036D80: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
        goto L_80036D94;
    // 0x80036D80: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
L_80036D84:
    // 0x80036D84: lh          $t7, 0x104($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X104);
    // 0x80036D88: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80036D8C: sh          $t6, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r14;
    // 0x80036D90: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_80036D94:
    // 0x80036D94: lh          $t8, 0xFE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XFE);
    // 0x80036D98: nop

    // 0x80036D9C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80036DA0: jal         0x80070A04
    // 0x80036DA4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80036DA4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_3:
    // 0x80036DA8: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036DAC: nop

    // 0x80036DB0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80036DB4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80036DB8: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x80036DBC: jal         0x80070A38
    // 0x80036DC0: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80036DC0: nop

    after_4:
    // 0x80036DC4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036DC8: nop

    // 0x80036DCC: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80036DD0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80036DD4: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036DD8: jal         0x80070A04
    // 0x80036DDC: nop

    sins_f(rdram, ctx);
        goto after_5;
    // 0x80036DDC: nop

    after_5:
    // 0x80036DE0: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036DE4: jal         0x80070A38
    // 0x80036DE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80036DE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80036DEC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036DF0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80036DF4: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80036DF8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80036DFC: lwc1        $f18, 0x108($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80036E00: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80036E04: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x80036E08: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80036E0C: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036E10: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80036E14: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80036E18: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036E1C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x80036E20: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80036E24: jal         0x80011560
    // 0x80036E28: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_7;
    // 0x80036E28: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80036E2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80036E30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80036E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036E38: jal         0x80011570
    // 0x80036E3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    move_object(rdram, ctx);
        goto after_8;
    // 0x80036E3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80036E40: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80036E44: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036E48: bne         $t1, $zero, L_80036F10
    if (ctx->r9 != 0) {
        // 0x80036E4C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80036F10;
    }
    // 0x80036E4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036E50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80036E54: addiu       $a0, $a0, -0x3040
    ctx->r4 = ADD32(ctx->r4, -0X3040);
    // 0x80036E58: addiu       $v0, $v0, -0x30C0
    ctx->r2 = ADD32(ctx->r2, -0X30C0);
L_80036E5C:
    // 0x80036E5C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80036E60: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80036E64: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80036E68: lbu         $t3, -0xF($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0XF);
    // 0x80036E6C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80036E70: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x80036E74: lbu         $t4, -0xE($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0XE);
    // 0x80036E78: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80036E7C: sb          $t4, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r12;
    // 0x80036E80: lbu         $t5, -0xD($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0XD);
    // 0x80036E84: bne         $at, $zero, L_80036E5C
    if (ctx->r1 != 0) {
        // 0x80036E88: sb          $t5, -0xD($v1)
        MEM_B(-0XD, ctx->r3) = ctx->r13;
            goto L_80036E5C;
    }
    // 0x80036E88: sb          $t5, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r13;
    // 0x80036E8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036E90: addiu       $v1, $v1, -0x30E8
    ctx->r3 = ADD32(ctx->r3, -0X30E8);
    // 0x80036E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036E98: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80036E9C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036EA0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80036EA4:
    // 0x80036EA4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80036EA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80036EAC: sh          $t6, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r14;
    // 0x80036EB0: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80036EB4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80036EB8: sh          $t7, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r15;
    // 0x80036EBC: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80036EC0: sb          $a0, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r4;
    // 0x80036EC4: sb          $a0, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r4;
    // 0x80036EC8: sb          $a0, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r4;
    // 0x80036ECC: sb          $a0, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = ctx->r4;
    // 0x80036ED0: sh          $t8, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r24;
    // 0x80036ED4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80036ED8: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80036EDC: sh          $t9, 0xB2($v0)
    MEM_H(0XB2, ctx->r2) = ctx->r25;
    // 0x80036EE0: lh          $t0, -0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, -0X4);
    // 0x80036EE4: nop

    // 0x80036EE8: sh          $t0, 0xB4($v0)
    MEM_H(0XB4, ctx->r2) = ctx->r8;
    // 0x80036EEC: lh          $t1, -0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X2);
    // 0x80036EF0: sb          $a0, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r4;
    // 0x80036EF4: sb          $a0, 0xB9($v0)
    MEM_B(0XB9, ctx->r2) = ctx->r4;
    // 0x80036EF8: sb          $a0, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = ctx->r4;
    // 0x80036EFC: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x80036F00: bne         $a2, $a1, L_80036EA4
    if (ctx->r6 != ctx->r5) {
        // 0x80036F04: sh          $t1, 0xB6($v0)
        MEM_H(0XB6, ctx->r2) = ctx->r9;
            goto L_80036EA4;
    }
    // 0x80036F04: sh          $t1, 0xB6($v0)
    MEM_H(0XB6, ctx->r2) = ctx->r9;
    // 0x80036F08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80036F0C: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
L_80036F10:
    // 0x80036F10: lbu         $t3, 0xC($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XC);
    // 0x80036F14: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036F18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80036F1C: bgez        $t3, L_80036F34
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80036F20: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80036F34;
    }
    // 0x80036F20: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036F24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036F2C: nop

    // 0x80036F30: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80036F34:
    // 0x80036F34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036F38: lwc1        $f18, 0x65D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X65D8);
    // 0x80036F3C: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x80036F40: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80036F44: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036F50: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80036F54: lbu         $v0, 0xB($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XB);
    // 0x80036F58: lb          $t5, 0x55($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X55);
    // 0x80036F5C: addiu       $a2, $a2, -0x3040
    ctx->r6 = ADD32(ctx->r6, -0X3040);
    // 0x80036F60: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80036F64: beq         $at, $zero, L_80036F84
    if (ctx->r1 == 0) {
        // 0x80036F68: nop
    
            goto L_80036F84;
    }
    // 0x80036F68: nop

    // 0x80036F6C: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80036F70: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80036F74: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80036F78: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80036F7C: b           L_80036F98
    // 0x80036F80: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
        goto L_80036F98;
    // 0x80036F80: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
L_80036F84:
    // 0x80036F84: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80036F88: nop

    // 0x80036F8C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80036F90: nop

    // 0x80036F94: sw          $t1, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r9;
L_80036F98:
    // 0x80036F98: lw          $v0, 0xF8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF8);
    // 0x80036F9C: nop

    // 0x80036FA0: beq         $v0, $zero, L_80036FCC
    if (ctx->r2 == 0) {
        // 0x80036FA4: nop
    
            goto L_80036FCC;
    }
    // 0x80036FA4: nop

    // 0x80036FA8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80036FAC: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80036FB0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80036FB4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80036FB8: sll         $t2, $a0, 5
    ctx->r10 = S32(ctx->r4 << 5);
    // 0x80036FBC: sll         $t3, $a1, 5
    ctx->r11 = S32(ctx->r5 << 5);
    // 0x80036FC0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80036FC4: b           L_80036FCC
    // 0x80036FC8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80036FCC;
    // 0x80036FC8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80036FCC:
    // 0x80036FCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036FD0: addiu       $v0, $v0, -0x30C0
    ctx->r2 = ADD32(ctx->r2, -0X30C0);
L_80036FD4:
    // 0x80036FD4: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x80036FD8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80036FDC: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FE0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80036FE4: mflo        $t5
    ctx->r13 = lo;
    // 0x80036FE8: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x80036FEC: sh          $t6, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r14;
    // 0x80036FF0: lh          $t7, -0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X1A);
    // 0x80036FF4: nop

    // 0x80036FF8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FFC: mflo        $t8
    ctx->r24 = lo;
    // 0x80037000: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80037004: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x80037008: lh          $t0, -0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X18);
    // 0x8003700C: nop

    // 0x80037010: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037014: mflo        $t1
    ctx->r9 = lo;
    // 0x80037018: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8003701C: sh          $t2, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r10;
    // 0x80037020: lh          $t3, -0x16($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X16);
    // 0x80037024: nop

    // 0x80037028: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003702C: mflo        $t4
    ctx->r12 = lo;
    // 0x80037030: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80037034: sh          $t5, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r13;
    // 0x80037038: lh          $t6, -0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X14);
    // 0x8003703C: nop

    // 0x80037040: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037044: mflo        $t7
    ctx->r15 = lo;
    // 0x80037048: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8003704C: sh          $t8, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r24;
    // 0x80037050: lh          $t9, -0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X12);
    // 0x80037054: nop

    // 0x80037058: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003705C: mflo        $t0
    ctx->r8 = lo;
    // 0x80037060: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x80037064: sh          $t1, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r9;
    // 0x80037068: lh          $t2, -0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, -0XC);
    // 0x8003706C: nop

    // 0x80037070: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037074: mflo        $t3
    ctx->r11 = lo;
    // 0x80037078: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8003707C: sh          $t4, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r12;
    // 0x80037080: lh          $t5, -0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XA);
    // 0x80037084: nop

    // 0x80037088: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003708C: mflo        $t6
    ctx->r14 = lo;
    // 0x80037090: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80037094: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x80037098: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8003709C: nop

    // 0x800370A0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800370A8: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x800370AC: sh          $t0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r8;
    // 0x800370B0: lh          $t1, -0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X6);
    // 0x800370B4: nop

    // 0x800370B8: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370BC: mflo        $t2
    ctx->r10 = lo;
    // 0x800370C0: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x800370C4: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800370C8: lh          $t4, -0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X4);
    // 0x800370CC: nop

    // 0x800370D0: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800370D8: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800370DC: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x800370E0: lh          $t7, -0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X2);
    // 0x800370E4: nop

    // 0x800370E8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800370F0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800370F4: bne         $v0, $a2, L_80036FD4
    if (ctx->r2 != ctx->r6) {
        // 0x800370F8: sh          $t9, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r25;
            goto L_80036FD4;
    }
    // 0x800370F8: sh          $t9, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r25;
    // 0x800370FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80037100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037104: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80037108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003710C: jr          $ra
    // 0x80037110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80037110: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_loop_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037114: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80037118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003711C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80037120: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80037124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80037128: jal         0x80066450
    // 0x8003712C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8003712C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_0:
    // 0x80037130: blez        $v0, L_80037148
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037134: nop
    
            goto L_80037148;
    }
    // 0x80037134: nop

    // 0x80037138: jal         0x8000FFB8
    // 0x8003713C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003713C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80037140: b           L_800375A8
    // 0x80037144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800375A8;
    // 0x80037144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037148:
    // 0x80037148: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003714C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80037150: lbu         $v1, 0xFD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037154: nop

    // 0x80037158: beq         $v1, $zero, L_800371C8
    if (ctx->r3 == 0) {
        // 0x8003715C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800371C8;
    }
    // 0x8003715C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80037160: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80037164: nop

    // 0x80037168: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003716C: bne         $at, $zero, L_80037194
    if (ctx->r1 != 0) {
        // 0x80037170: nop
    
            goto L_80037194;
    }
    // 0x80037170: nop

    // 0x80037174: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80037178: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003717C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037180: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x80037184: sb          $t6, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r14;
    // 0x80037188: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003718C: b           L_800371C0
    // 0x80037190: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
        goto L_800371C0;
    // 0x80037190: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80037194:
    // 0x80037194: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80037198: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003719C: bgez        $v1, L_800371B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800371A0: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800371B4;
    }
    // 0x800371A0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800371A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800371A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800371AC: nop

    // 0x800371B0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800371B4:
    // 0x800371B4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800371B8: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
    // 0x800371BC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800371C0:
    // 0x800371C0: b           L_800372B8
    // 0x800371C4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
        goto L_800372B8;
    // 0x800371C4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_800371C8:
    // 0x800371C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800371CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800371D0: jal         0x8006FB8C
    // 0x800371D4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800371D4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800371D8: bne         $v0, $zero, L_800372B8
    if (ctx->r2 != 0) {
        // 0x800371DC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800372B8;
    }
    // 0x800371DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800371E0: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x800371E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800371E8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800371EC: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x800371F0: nop

    // 0x800371F4: bc1f        L_800372BC
    if (!c1cs) {
        // 0x800371F8: lw          $a1, 0x74($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X74);
            goto L_800372BC;
    }
    // 0x800371F8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800371FC: jal         0x8006FB8C
    // 0x80037200: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x80037200: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80037204: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80037208: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8003720C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80037210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037218: sb          $v0, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r2;
    // 0x8003721C: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037224: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80037228: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003722C: jal         0x8006FB8C
    // 0x80037230: nop

    rand_range(rdram, ctx);
        goto after_4;
    // 0x80037230: nop

    after_4:
    // 0x80037234: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80037238: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8003723C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80037240: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80037244: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80037248: lwc1        $f8, 0x10C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8003724C: nop

    // 0x80037250: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80037254: nop

    // 0x80037258: bc1f        L_80037278
    if (!c1cs) {
        // 0x8003725C: nop
    
            goto L_80037278;
    }
    // 0x8003725C: nop

    // 0x80037260: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80037264: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037268: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003726C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037270: b           L_8003728C
    // 0x80037274: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
        goto L_8003728C;
    // 0x80037274: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_80037278:
    // 0x80037278: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003727C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037280: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037284: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80037288: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_8003728C:
    // 0x8003728C: lbu         $t8, 0xFD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037290: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037294: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80037298: bgez        $t8, L_800372AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003729C: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800372AC;
    }
    // 0x8003729C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800372A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800372A4: nop

    // 0x800372A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800372AC:
    // 0x800372AC: nop

    // 0x800372B0: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800372B4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_800372B8:
    // 0x800372B8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
L_800372BC:
    // 0x800372BC: lh          $t0, 0x100($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X100);
    // 0x800372C0: lh          $t9, 0xFE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XFE);
    // 0x800372C4: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800372C8: mflo        $t1
    ctx->r9 = lo;
    // 0x800372CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800372D0: sh          $t2, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r10;
    // 0x800372D4: lh          $t3, 0xFE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XFE);
    // 0x800372D8: nop

    // 0x800372DC: sll         $t4, $t3, 17
    ctx->r12 = S32(ctx->r11 << 17);
    // 0x800372E0: jal         0x80070A04
    // 0x800372E4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800372E4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_5:
    // 0x800372E8: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800372EC: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x800372F0: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800372F4: jal         0x80070A38
    // 0x800372F8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800372F8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x800372FC: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80037300: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80037304: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80037308: jal         0x80070A04
    // 0x8003730C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x8003730C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x80037310: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80037314: jal         0x80070A38
    // 0x80037318: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x80037318: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8003731C: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80037320: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80037324: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80037328: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003732C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037330: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80037334: nop

    // 0x80037338: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003733C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80037340: lwc1        $f6, 0x108($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80037344: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80037348: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8003734C: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80037350: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80037354: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037358: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8003735C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80037360: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80037364: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80037368: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003736C: nop

    // 0x80037370: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80037374: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80037378: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003737C: nop

    // 0x80037380: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80037384: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80037388: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x8003738C: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80037390: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x80037394: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80037398: jal         0x80011560
    // 0x8003739C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_9;
    // 0x8003739C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x800373A0: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800373A4: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800373A8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800373AC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800373B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800373B4: jal         0x80011570
    // 0x800373B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_10;
    // 0x800373B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800373BC: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800373C0: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800373C4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800373C8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800373CC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800373D0: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800373D4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800373D8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x800373DC: jal         0x800CA030
    // 0x800373E0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800373E0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    after_11:
    // 0x800373E4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800373E8: jal         0x800CA030
    // 0x800373EC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800373EC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800373F0: lui         $at, 0x44C0
    ctx->r1 = S32(0X44C0 << 16);
    // 0x800373F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800373F8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800373FC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80037400: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80037404: lh          $t8, 0x106($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X106);
    // 0x80037408: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003740C: nop

    // 0x80037410: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80037414: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037418: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003741C: nop

    // 0x80037420: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037424: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80037428: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003742C: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x80037430: sh          $t0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r8;
    // 0x80037434: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80037438: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003743C: jal         0x80070990
    // 0x80037440: nop

    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x80037440: nop

    after_13:
    // 0x80037444: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80037448: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003744C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80037450: jal         0x80070990
    // 0x80037454: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x80037454: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_14:
    // 0x80037458: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8003745C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80037460: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x80037464: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80037468: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8003746C: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x80037470: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80037474: beq         $at, $zero, L_8003749C
    if (ctx->r1 == 0) {
        // 0x80037478: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8003749C;
    }
    // 0x80037478: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8003747C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80037480: nop

    // 0x80037484: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037488: mflo        $t3
    ctx->r11 = lo;
    // 0x8003748C: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80037490: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80037494: b           L_800374B0
    // 0x80037498: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
        goto L_800374B0;
    // 0x80037498: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
L_8003749C:
    // 0x8003749C: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800374A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800374A4: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800374A8: subu        $t0, $v1, $t7
    ctx->r8 = SUB32(ctx->r3, ctx->r15);
    // 0x800374AC: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
L_800374B0:
    // 0x800374B0: lbu         $t9, 0xFC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XFC);
    // 0x800374B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800374B8: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x800374BC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800374C0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800374C4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800374C8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800374CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800374D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800374D4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800374D8: addu        $v1, $s0, $t5
    ctx->r3 = ADD32(ctx->r16, ctx->r13);
    // 0x800374DC: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
    // 0x800374E0: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800374E4: lh          $a0, 0x106($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X106);
    // 0x800374E8: jal         0x80070A70
    // 0x800374EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    sins_s16(rdram, ctx);
        goto after_15;
    // 0x800374EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_15:
    // 0x800374F0: sra         $s1, $v0, 3
    ctx->r17 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800374F4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800374F8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800374FC: jal         0x80070A38
    // 0x80037500: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    coss_f(rdram, ctx);
        goto after_16;
    // 0x80037500: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_16:
    // 0x80037504: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80037508: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003750C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80037510: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80037514: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80037518: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8003751C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80037520: nop

    // 0x80037524: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80037528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003752C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037530: nop

    // 0x80037534: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80037538: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x8003753C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80037540: jal         0x80070A04
    // 0x80037544: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x80037544: nop

    after_17:
    // 0x80037548: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8003754C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037550: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80037554: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80037558: lh          $t1, 0x14($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X14);
    // 0x8003755C: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
    // 0x80037560: lh          $t4, 0x1E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1E);
    // 0x80037564: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037568: lh          $t6, 0x22($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X22);
    // 0x8003756C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80037570: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037574: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037578: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003757C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037580: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80037584: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80037588: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003758C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80037590: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80037594: sh          $t9, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r25;
    // 0x80037598: sh          $t3, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r11;
    // 0x8003759C: sh          $t5, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r13;
    // 0x800375A0: sh          $t8, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r24;
    // 0x800375A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800375A8:
    // 0x800375A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800375AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800375B0: jr          $ra
    // 0x800375B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800375B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_init_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800375B8: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x800375BC: nop

    // 0x800375C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800375C4: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
    // 0x800375C8: lbu         $t8, 0x8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X8);
    // 0x800375CC: jr          $ra
    // 0x800375D0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    return;
    // 0x800375D0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void obj_loop_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800375D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800375D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800375DC: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800375E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800375E4: blez        $v0, L_80037604
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800375E8: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_80037604;
    }
    // 0x800375E8: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800375EC: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800375F0: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x800375F4: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x800375F8: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x800375FC: b           L_80037654
    // 0x80037600: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80037654;
    // 0x80037600: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80037604:
    // 0x80037604: lh          $t1, 0x18($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X18);
    // 0x80037608: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x8003760C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80037610: sh          $t3, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r11;
    // 0x80037614: lh          $t4, 0x18($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X18);
    // 0x80037618: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x8003761C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x80037620: bne         $at, $zero, L_80037654
    if (ctx->r1 != 0) {
        // 0x80037624: sh          $t0, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r8;
            goto L_80037654;
    }
    // 0x80037624: sh          $t0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r8;
    // 0x80037628: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x8003762C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80037630: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037634: jal         0x8006FB8C
    // 0x80037638: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80037638: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x8003763C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80037640: nop

    // 0x80037644: lw          $t5, 0x7C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X7C);
    // 0x80037648: nop

    // 0x8003764C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80037650: sw          $t6, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r14;
L_80037654:
    // 0x80037654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003765C: jr          $ra
    // 0x80037660: nop

    return;
    // 0x80037660: nop

;}
RECOMP_FUNC void obj_init_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037664: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80037668: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8003766C: nop

    // 0x80037670: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037674: jr          $ra
    // 0x80037678: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    return;
    // 0x80037678: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void obj_loop_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003767C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80037680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037684: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80037688: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003768C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80037690: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80037694: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037698: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8003769C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800376A0: jal         0x8001BAE0
    // 0x800376A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    get_racer_objects_by_position(rdram, ctx);
        goto after_0;
    // 0x800376A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800376A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800376AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800376B0: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x800376B4: nop

    // 0x800376B8: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800376BC: beq         $at, $zero, L_80037710
    if (ctx->r1 == 0) {
        // 0x800376C0: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80037710;
    }
    // 0x800376C0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800376C4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800376C8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800376CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800376D0: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x800376D4: nop

    // 0x800376D8: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x800376DC: nop

    // 0x800376E0: bne         $t1, $at, L_80037708
    if (ctx->r9 != ctx->r1) {
        // 0x800376E4: sll         $t4, $v1, 7
        ctx->r12 = S32(ctx->r3 << 7);
            goto L_80037708;
    }
    // 0x800376E4: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
    // 0x800376E8: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x800376EC: nop

    // 0x800376F0: andi        $t3, $t2, 0xBFFF
    ctx->r11 = ctx->r10 & 0XBFFF;
    // 0x800376F4: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    // 0x800376F8: sw          $a1, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r5;
    // 0x800376FC: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x80037700: nop

    // 0x80037704: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
L_80037708:
    // 0x80037708: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8003770C: sh          $t4, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r12;
L_80037710:
    // 0x80037710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037714: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80037718: jr          $ra
    // 0x8003771C: nop

    return;
    // 0x8003771C: nop

;}
RECOMP_FUNC void obj_init_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037728: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003772C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80037730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80037734: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80037738: jal         0x8002C804
    // 0x8003773C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x8003773C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80037740: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037744: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80037748: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003774C: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x80037750: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80037754: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80037758: lb          $t7, 0x9($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X9);
    // 0x8003775C: nop

    // 0x80037760: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80037764: lb          $t8, 0xA($a1)
    ctx->r24 = MEM_B(ctx->r5, 0XA);
    // 0x80037768: nop

    // 0x8003776C: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x80037770: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x80037774: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80037778: lwc1        $f12, 0xC($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003777C: jal         0x80029F58
    // 0x80037780: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_1;
    // 0x80037780: nop

    after_1:
    // 0x80037784: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80037788: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8003778C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80037790: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80037794: nop

    // 0x80037798: bne         $t9, $zero, L_800377A8
    if (ctx->r25 != 0) {
        // 0x8003779C: nop
    
            goto L_800377A8;
    }
    // 0x8003779C: nop

    // 0x800377A0: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800377A4: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_800377A8:
    // 0x800377A8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800377AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800377B0: beq         $v0, $at, L_8003780C
    if (ctx->r2 == ctx->r1) {
        // 0x800377B4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003780C;
    }
    // 0x800377B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800377B8: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800377BC: nop

    // 0x800377C0: bgez        $a0, L_800377DC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800377C4: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_800377DC;
    }
    // 0x800377C4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800377C8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800377CC: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800377D0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800377D4: nop

    // 0x800377D8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_800377DC:
    // 0x800377DC: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800377E0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800377E4: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800377E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800377EC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800377F0: lh          $a1, 0x20($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X20);
    // 0x800377F4: nop

    // 0x800377F8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800377FC: bne         $at, $zero, L_80037808
    if (ctx->r1 != 0) {
        // 0x80037800: addiu       $t4, $a1, -0x1
        ctx->r12 = ADD32(ctx->r5, -0X1);
            goto L_80037808;
    }
    // 0x80037800: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x80037804: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_80037808:
    // 0x80037808: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003780C:
    // 0x8003780C: jal         0x80037824
    // 0x80037810: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    obj_loop_animator(rdram, ctx);
        goto after_2;
    // 0x80037810: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_2:
    // 0x80037814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003781C: jr          $ra
    // 0x80037820: nop

    return;
    // 0x80037820: nop

;}
RECOMP_FUNC void obj_loop_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037824: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80037828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003782C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80037830: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037834: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80037838: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x8003783C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037840: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80037844: mflo        $t0
    ctx->r8 = lo;
    // 0x80037848: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8003784C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80037850: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037854: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x80037858: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8003785C: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x80037860: nop

    // 0x80037864: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80037868: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8003786C: sra         $t0, $v0, 4
    ctx->r8 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80037870: mflo        $t1
    ctx->r9 = lo;
    // 0x80037874: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x80037878: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8003787C: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x80037880: lh          $a2, 0xA($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XA);
    // 0x80037884: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80037888: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8003788C: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80037890: beq         $t6, $at, L_80037A48
    if (ctx->r14 == ctx->r1) {
        // 0x80037894: sra         $t1, $a2, 4
        ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
            goto L_80037A48;
    }
    // 0x80037894: sra         $t1, $a2, 4
    ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
    // 0x80037898: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8003789C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800378A0: jal         0x8002C804
    // 0x800378A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800378A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800378A8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800378AC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800378B0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800378B4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800378B8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800378BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800378C0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800378C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800378C8: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x800378CC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800378D0: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800378D4: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800378D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800378DC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800378E0: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800378E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800378E8: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x800378EC: lh          $t3, 0x10($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X10);
    // 0x800378F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800378F4: beq         $t5, $at, L_80037A4C
    if (ctx->r13 == ctx->r1) {
        // 0x800378F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037A4C;
    }
    // 0x800378F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800378FC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80037900: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x80037904: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80037908: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x8003790C: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80037910: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80037914: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80037918: sll         $a1, $v1, 7
    ctx->r5 = S32(ctx->r3 << 7);
    // 0x8003791C: beq         $at, $zero, L_80037A48
    if (ctx->r1 == 0) {
        // 0x80037920: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80037A48;
    }
    // 0x80037920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80037924:
    // 0x80037924: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80037928: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x8003792C: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x80037930: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80037934: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80037938: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8003793C: bne         $t7, $zero, L_80037A40
    if (ctx->r15 != 0) {
        // 0x80037940: nop
    
            goto L_80037A40;
    }
    // 0x80037940: nop

    // 0x80037944: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037948: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8003794C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80037950: beq         $at, $zero, L_8003797C
    if (ctx->r1 == 0) {
        // 0x80037954: sll         $a3, $a0, 1
        ctx->r7 = S32(ctx->r4 << 1);
            goto L_8003797C;
    }
    // 0x80037954: sll         $a3, $a0, 1
    ctx->r7 = S32(ctx->r4 << 1);
    // 0x80037958: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x8003795C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80037960: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80037964: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80037968: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8003796C: subu        $t8, $t9, $a1
    ctx->r24 = SUB32(ctx->r25, ctx->r5);
    // 0x80037970: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037974: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x80037978: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_8003797C:
    // 0x8003797C: bgez        $v1, L_800379A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037980: addu        $t6, $v1, $a1
        ctx->r14 = ADD32(ctx->r3, ctx->r5);
            goto L_800379A0;
    }
    // 0x80037980: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x80037984: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80037988: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8003798C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80037990: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x80037994: addu        $t6, $t8, $a1
    ctx->r14 = ADD32(ctx->r24, ctx->r5);
    // 0x80037998: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x8003799C: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
L_800379A0:
    // 0x800379A0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379A4: nop

    // 0x800379A8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800379AC: beq         $at, $zero, L_800379D4
    if (ctx->r1 == 0) {
        // 0x800379B0: subu        $t7, $v1, $a0
        ctx->r15 = SUB32(ctx->r3, ctx->r4);
            goto L_800379D4;
    }
    // 0x800379B0: subu        $t7, $v1, $a0
    ctx->r15 = SUB32(ctx->r3, ctx->r4);
    // 0x800379B4: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800379B8: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x800379BC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800379C0: subu        $t8, $t9, $a0
    ctx->r24 = SUB32(ctx->r25, ctx->r4);
    // 0x800379C4: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x800379C8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379CC: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x800379D0: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_800379D4:
    // 0x800379D4: bgez        $v1, L_800379FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800379D8: addu        $t9, $v1, $a0
        ctx->r25 = ADD32(ctx->r3, ctx->r4);
            goto L_800379FC;
    }
    // 0x800379D8: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x800379DC: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800379E0: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800379E4: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800379E8: addu        $t6, $t8, $a0
    ctx->r14 = ADD32(ctx->r24, ctx->r4);
    // 0x800379EC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800379F0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379F4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x800379F8: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
L_800379FC:
    // 0x800379FC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x80037A00: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80037A04: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80037A08: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80037A0C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80037A10: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80037A14: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80037A18: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80037A1C: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x80037A20: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80037A24: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80037A28: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x80037A2C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x80037A30: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x80037A34: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80037A38: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x80037A3C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_80037A40:
    // 0x80037A40: bne         $a2, $t3, L_80037924
    if (ctx->r6 != ctx->r11) {
        // 0x80037A44: nop
    
            goto L_80037924;
    }
    // 0x80037A44: nop

L_80037A48:
    // 0x80037A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037A4C:
    // 0x80037A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80037A50: jr          $ra
    // 0x80037A54: nop

    return;
    // 0x80037A54: nop

;}
RECOMP_FUNC void obj_init_animation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037A58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037A60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037A64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80037A68: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x80037A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037A70: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80037A74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80037A78: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037A7C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80037A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037A84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80037A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037A8C: bc1f        L_80037A98
    if (!c1cs) {
        // 0x80037A90: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80037A98;
    }
    // 0x80037A90: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80037A94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80037A98:
    // 0x80037A98: nop

    // 0x80037A9C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80037AA0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x80037AA4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037AA8: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80037AAC: nop

    // 0x80037AB0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80037AB4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80037AB8: lbu         $t9, 0xA($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XA);
    // 0x80037ABC: nop

    // 0x80037AC0: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80037AC4: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80037AC8: lbu         $t1, 0x9($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X9);
    // 0x80037ACC: nop

    // 0x80037AD0: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80037AD4: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80037AD8: lbu         $t3, 0x8($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X8);
    // 0x80037ADC: nop

    // 0x80037AE0: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80037AE4: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80037AE8: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037AEC: nop

    // 0x80037AF0: bne         $a0, $at, L_80037B0C
    if (ctx->r4 != ctx->r1) {
        // 0x80037AF4: nop
    
            goto L_80037B0C;
    }
    // 0x80037AF4: nop

    // 0x80037AF8: jal         0x8001F3EC
    // 0x80037AFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3B8(rdram, ctx);
        goto after_0;
    // 0x80037AFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80037B00: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B04: b           L_80037B38
    // 0x80037B08: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
        goto L_80037B38;
    // 0x80037B08: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_80037B0C:
    // 0x80037B0C: bgez        $a0, L_80037B28
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80037B10: slti        $at, $a0, -0x2
        ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
            goto L_80037B28;
    }
    // 0x80037B10: slti        $at, $a0, -0x2
    ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
    // 0x80037B14: bne         $at, $zero, L_80037B28
    if (ctx->r1 != 0) {
        // 0x80037B18: nop
    
            goto L_80037B28;
    }
    // 0x80037B18: nop

    // 0x80037B1C: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
    // 0x80037B20: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037B24: nop

L_80037B28:
    // 0x80037B28: jal         0x8001F3FC
    // 0x80037B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3C8(rdram, ctx);
        goto after_1;
    // 0x80037B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80037B30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B34: nop

L_80037B38:
    // 0x80037B38: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037B3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037B40: bne         $v1, $at, L_80037B68
    if (ctx->r3 != ctx->r1) {
        // 0x80037B44: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80037B68;
    }
    // 0x80037B44: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037B48: jal         0x8001E474
    // 0x80037B4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_2;
    // 0x80037B4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80037B50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B54: nop

    // 0x80037B58: sb          $v0, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r2;
    // 0x80037B5C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037B60: nop

    // 0x80037B64: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_80037B68:
    // 0x80037B68: bne         $v1, $at, L_80037B80
    if (ctx->r3 != ctx->r1) {
        // 0x80037B6C: nop
    
            goto L_80037B80;
    }
    // 0x80037B6C: nop

    // 0x80037B70: lb          $t5, 0x10($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X10);
    // 0x80037B74: nop

    // 0x80037B78: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80037B7C: sb          $t6, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r14;
L_80037B80:
    // 0x80037B80: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037B84: jal         0x8001F420
    // 0x80037B88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3EC(rdram, ctx);
        goto after_3;
    // 0x80037B88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80037B8C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B90: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037B94: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037B98: nop

    // 0x80037B9C: bne         $v1, $at, L_80037BC0
    if (ctx->r3 != ctx->r1) {
        // 0x80037BA0: nop
    
            goto L_80037BC0;
    }
    // 0x80037BA0: nop

    // 0x80037BA4: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037BA8: lb          $t7, 0x11($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X11);
    // 0x80037BAC: nop

    // 0x80037BB0: bgez        $t7, L_80037BE8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80037BB4: nop
    
            goto L_80037BE8;
    }
    // 0x80037BB4: nop

    // 0x80037BB8: b           L_80037BE8
    // 0x80037BBC: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
        goto L_80037BE8;
    // 0x80037BBC: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037BC0:
    // 0x80037BC0: bltz        $v0, L_80037BDC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80037BC4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80037BDC;
    }
    // 0x80037BC4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80037BC8: bne         $at, $zero, L_80037BDC
    if (ctx->r1 != 0) {
        // 0x80037BCC: nop
    
            goto L_80037BDC;
    }
    // 0x80037BCC: nop

    // 0x80037BD0: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037BD4: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037BD8: nop

L_80037BDC:
    // 0x80037BDC: bgez        $v1, L_80037BE8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037BE0: nop
    
            goto L_80037BE8;
    }
    // 0x80037BE0: nop

    // 0x80037BE4: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037BE8:
    // 0x80037BE8: jal         0x80011390
    // 0x80037BEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    path_enable(rdram, ctx);
        goto after_4;
    // 0x80037BEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80037BF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037BF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037BF8: lb          $t8, 0x10($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X10);
    // 0x80037BFC: nop

    // 0x80037C00: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80037C04: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80037C08: nop

    // 0x80037C0C: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80037C10: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80037C14: nop

    // 0x80037C18: beq         $t0, $zero, L_80037C3C
    if (ctx->r8 == 0) {
        // 0x80037C1C: nop
    
            goto L_80037C3C;
    }
    // 0x80037C1C: nop

    // 0x80037C20: jal         0x8006A794
    // 0x80037C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_5;
    // 0x80037C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_5:
    // 0x80037C28: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C2C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80037C30: beq         $t1, $zero, L_80037C3C
    if (ctx->r9 == 0) {
        // 0x80037C34: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80037C3C;
    }
    // 0x80037C34: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80037C38: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
L_80037C3C:
    // 0x80037C3C: jal         0x8001E474
    // 0x80037C40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x80037C40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80037C44: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C48: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037C4C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037C50: nop

    // 0x80037C54: beq         $v0, $v1, L_80037C64
    if (ctx->r2 == ctx->r3) {
        // 0x80037C58: nop
    
            goto L_80037C64;
    }
    // 0x80037C58: nop

    // 0x80037C5C: bne         $v1, $at, L_80037CA8
    if (ctx->r3 != ctx->r1) {
        // 0x80037C60: nop
    
            goto L_80037CA8;
    }
    // 0x80037C60: nop

L_80037C64:
    // 0x80037C64: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80037C68: nop

    // 0x80037C6C: bne         $t3, $zero, L_80037CA8
    if (ctx->r11 != 0) {
        // 0x80037C70: nop
    
            goto L_80037CA8;
    }
    // 0x80037C70: nop

    // 0x80037C74: lb          $t4, 0x11($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X11);
    // 0x80037C78: nop

    // 0x80037C7C: bne         $t4, $zero, L_80037CA8
    if (ctx->r12 != 0) {
        // 0x80037C80: nop
    
            goto L_80037CA8;
    }
    // 0x80037C80: nop

    // 0x80037C84: lh          $t5, 0xC($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XC);
    // 0x80037C88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037C8C: beq         $t5, $at, L_80037CA8
    if (ctx->r13 == ctx->r1) {
        // 0x80037C90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037CA8;
    }
    // 0x80037C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037C94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80037C98: jal         0x8001F270
    // 0x80037C9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F23C(rdram, ctx);
        goto after_7;
    // 0x80037C9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_7:
    // 0x80037CA0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037CA4: nop

L_80037CA8:
    // 0x80037CA8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80037CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037CB0: beq         $v0, $zero, L_80037CFC
    if (ctx->r2 == 0) {
        // 0x80037CB4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80037CFC;
    }
    // 0x80037CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037CB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80037CBC: jal         0x8001EFD8
    // 0x80037CC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    obj_init_animobject(rdram, ctx);
        goto after_8;
    // 0x80037CC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x80037CC4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037CC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037CCC: lb          $t6, 0x11($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X11);
    // 0x80037CD0: nop

    // 0x80037CD4: bne         $t6, $zero, L_80037CF0
    if (ctx->r14 != 0) {
        // 0x80037CD8: nop
    
            goto L_80037CF0;
    }
    // 0x80037CD8: nop

    // 0x80037CDC: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x80037CE0: lh          $t8, 0x4A($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4A);
    // 0x80037CE4: nop

    // 0x80037CE8: beq         $t7, $t8, L_80037CFC
    if (ctx->r15 == ctx->r24) {
        // 0x80037CEC: nop
    
            goto L_80037CFC;
    }
    // 0x80037CEC: nop

L_80037CF0:
    // 0x80037CF0: jal         0x8000FFB8
    // 0x80037CF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    free_object(rdram, ctx);
        goto after_9;
    // 0x80037CF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x80037CF8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_80037CFC:
    // 0x80037CFC: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x80037D00: jal         0x80021634
    // 0x80037D04: nop

    func_80021600(rdram, ctx);
        goto after_10;
    // 0x80037D04: nop

    after_10:
    // 0x80037D08: beq         $v0, $zero, L_80037D1C
    if (ctx->r2 == 0) {
        // 0x80037D0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80037D1C;
    }
    // 0x80037D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037D10: jal         0x8001EEA8
    // 0x80037D14: nop

    func_8001EE74(rdram, ctx);
        goto after_11;
    // 0x80037D14: nop

    after_11:
    // 0x80037D18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037D1C:
    // 0x80037D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037D20: jr          $ra
    // 0x80037D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80037D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037D30: jal         0x8001F494
    // 0x80037D34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037D34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80037D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037D40: jr          $ra
    // 0x80037D44: nop

    return;
    // 0x80037D44: nop

;}
RECOMP_FUNC void obj_loop_dooropener(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037D50: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80037D54: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80037D58: jal         0x8001F494
    // 0x80037D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037D5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80037D60: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80037D64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037D68: lh          $t9, 0x2A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2A);
    // 0x80037D6C: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    // 0x80037D70: blez        $t9, L_80037D7C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80037D74: nop
    
            goto L_80037D7C;
    }
    // 0x80037D74: nop

    // 0x80037D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80037D7C:
    // 0x80037D7C: jal         0x80023604
    // 0x80037D80: nop

    obj_door_open(rdram, ctx);
        goto after_1;
    // 0x80037D80: nop

    after_1:
    // 0x80037D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037D8C: jr          $ra
    // 0x80037D90: nop

    return;
    // 0x80037D90: nop

;}
RECOMP_FUNC void obj_init_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037D98: jr          $ra
    // 0x80037D9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037D9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037DA4: jr          $ra
    // 0x80037DA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037DA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037DB0: jr          $ra
    // 0x80037DB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037DB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DB8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80037DBC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80037DC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037DC4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80037DC8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80037DCC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80037DD0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80037DD4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80037DD8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80037DDC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80037DE0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80037DE4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80037DE8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80037DEC: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80037DF0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80037DF4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80037DF8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80037DFC: jal         0x8001F494
    // 0x80037E00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037E00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80037E04: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80037E08: nop

    // 0x80037E0C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80037E10: nop

    // 0x80037E14: beq         $v1, $zero, L_800380FC
    if (ctx->r3 == 0) {
        // 0x80037E18: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E18: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E1C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80037E20: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x80037E24: blez        $v0, L_80037E34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037E28: subu        $t7, $v0, $s1
        ctx->r15 = SUB32(ctx->r2, ctx->r17);
            goto L_80037E34;
    }
    // 0x80037E28: subu        $t7, $v0, $s1
    ctx->r15 = SUB32(ctx->r2, ctx->r17);
    // 0x80037E2C: b           L_80037E38
    // 0x80037E30: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
        goto L_80037E38;
    // 0x80037E30: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
L_80037E34:
    // 0x80037E34: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80037E38:
    // 0x80037E38: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x80037E3C: nop

    // 0x80037E40: beq         $t8, $zero, L_800380FC
    if (ctx->r24 == 0) {
        // 0x80037E44: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E44: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E48: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80037E4C: nop

    // 0x80037E50: bne         $t9, $zero, L_800380FC
    if (ctx->r25 != 0) {
        // 0x80037E54: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E54: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E58: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80037E5C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80037E60: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80037E64: beq         $t2, $zero, L_800380F8
    if (ctx->r10 == 0) {
        // 0x80037E68: addiu       $a0, $sp, 0xCC
        ctx->r4 = ADD32(ctx->r29, 0XCC);
            goto L_800380F8;
    }
    // 0x80037E68: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037E6C: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80037E70: jal         0x8006FE70
    // 0x80037E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x80037E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80037E78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80037E7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037E84: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80037E88: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x80037E8C: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x80037E90: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80037E94: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80037E98: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x80037E9C: sh          $t4, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r12;
    // 0x80037EA0: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80037EA4: sh          $zero, 0x70($sp)
    MEM_H(0X70, ctx->r29) = 0;
    // 0x80037EA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80037EAC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80037EB0: jal         0x8006FE70
    // 0x80037EB4: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80037EB4: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    after_2:
    // 0x80037EB8: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80037EBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80037EC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80037EC4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80037EC8: blez        $t6, L_800380F8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80037ECC: addiu       $fp, $sp, 0x84
        ctx->r30 = ADD32(ctx->r29, 0X84);
            goto L_800380F8;
    }
    // 0x80037ECC: addiu       $fp, $sp, 0x84
    ctx->r30 = ADD32(ctx->r29, 0X84);
    // 0x80037ED0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80037ED4: addiu       $s7, $sp, 0x114
    ctx->r23 = ADD32(ctx->r29, 0X114);
    // 0x80037ED8: addiu       $s6, $sp, 0x118
    ctx->r22 = ADD32(ctx->r29, 0X118);
    // 0x80037EDC: addiu       $s5, $sp, 0x11C
    ctx->r21 = ADD32(ctx->r29, 0X11C);
    // 0x80037EE0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80037EE4:
    // 0x80037EE4: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80037EE8: nop

    // 0x80037EEC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80037EF0: lb          $v1, 0x0($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X0);
    // 0x80037EF4: nop

    // 0x80037EF8: bltz        $v1, L_800380DC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80037EFC: nop
    
            goto L_800380DC;
    }
    // 0x80037EFC: nop

    // 0x80037F00: lh          $t9, 0x18($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X18);
    // 0x80037F04: nop

    // 0x80037F08: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80037F0C: beq         $at, $zero, L_800380DC
    if (ctx->r1 == 0) {
        // 0x80037F10: nop
    
            goto L_800380DC;
    }
    // 0x80037F10: nop

    // 0x80037F14: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80037F18: nop

    // 0x80037F1C: beq         $t0, $zero, L_800380DC
    if (ctx->r8 == 0) {
        // 0x80037F20: nop
    
            goto L_800380DC;
    }
    // 0x80037F20: nop

    // 0x80037F24: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x80037F28: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80037F2C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80037F30: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80037F34: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037F38: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F3C: mflo        $t4
    ctx->r12 = lo;
    // 0x80037F40: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80037F44: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80037F48: nop

    // 0x80037F4C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80037F50: nop

    // 0x80037F54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037F58: swc1        $f8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f8.u32l;
    // 0x80037F5C: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80037F60: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80037F64: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80037F68: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80037F6C: lw          $a1, 0x11C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X11C);
    // 0x80037F70: multu       $t1, $s2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F74: mflo        $t2
    ctx->r10 = lo;
    // 0x80037F78: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80037F7C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80037F80: nop

    // 0x80037F84: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80037F88: nop

    // 0x80037F8C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80037F90: swc1        $f16, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f16.u32l;
    // 0x80037F94: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x80037F98: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80037F9C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80037FA0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80037FA4: lw          $a2, 0x118($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X118);
    // 0x80037FA8: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037FAC: mflo        $t1
    ctx->r9 = lo;
    // 0x80037FB0: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x80037FB4: lh          $t2, 0x4($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X4);
    // 0x80037FB8: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80037FBC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80037FC0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80037FC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80037FC8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80037FCC: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
    // 0x80037FD0: lw          $a3, 0x114($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X114);
    // 0x80037FD4: jal         0x8006F88C
    // 0x80037FD8: nop

    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80037FD8: nop

    after_3:
    // 0x80037FDC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80037FE0: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80037FE4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80037FE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037FEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037FF0: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80037FF4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037FF8: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80037FFC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80038000: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80038004: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80038008: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003800C: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x80038010: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80038014: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038018: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003801C: sb          $t1, 0x85($sp)
    MEM_B(0X85, ctx->r29) = ctx->r9;
    // 0x80038020: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80038024: sb          $t7, 0x84($sp)
    MEM_B(0X84, ctx->r29) = ctx->r15;
    // 0x80038028: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003802C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80038030: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80038034: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80038038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003803C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80038040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80038048: sh          $t4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r12;
    // 0x8003804C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80038050: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
    // 0x80038054: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80038058: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003805C: jal         0x8000EA54
    // 0x80038060: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x80038060: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    after_4:
    // 0x80038064: beq         $v0, $zero, L_800380DC
    if (ctx->r2 == 0) {
        // 0x80038068: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_800380DC;
    }
    // 0x80038068: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003806C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80038070: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80038074: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80038078: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8003807C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80038080: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80038084: sw          $t8, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r24;
    // 0x80038088: negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // 0x8003808C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80038090: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80038094: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80038098: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003809C: addiu       $t9, $v0, 0x1C
    ctx->r25 = ADD32(ctx->r2, 0X1C);
    // 0x800380A0: addiu       $t5, $v0, 0x20
    ctx->r13 = ADD32(ctx->r2, 0X20);
    // 0x800380A4: addiu       $t1, $v0, 0x24
    ctx->r9 = ADD32(ctx->r2, 0X24);
    // 0x800380A8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800380AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800380B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800380B4: jal         0x8006F88C
    // 0x800380B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtxf_transform_point(rdram, ctx);
        goto after_5;
    // 0x800380B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x800380BC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800380C0: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800380C4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800380C8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800380CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800380D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800380D4: jal         0x80009558
    // 0x800380D8: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_6;
    // 0x800380D8: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    after_6:
L_800380DC:
    // 0x800380DC: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800380E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800380E4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800380E8: nop

    // 0x800380EC: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800380F0: bne         $at, $zero, L_80037EE4
    if (ctx->r1 != 0) {
        // 0x800380F4: nop
    
            goto L_80037EE4;
    }
    // 0x800380F4: nop

L_800380F8:
    // 0x800380F8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800380FC:
    // 0x800380FC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80038100: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80038104: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80038108: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003810C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80038110: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80038114: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80038118: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8003811C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80038120: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80038124: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80038128: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8003812C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80038130: jr          $ra
    // 0x80038134: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80038134: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void obj_loop_vehicleanim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003813C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038144: jal         0x8001F494
    // 0x80038148: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038148: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x8003814C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038150: nop

    // 0x80038154: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80038158: nop

    // 0x8003815C: beq         $v1, $zero, L_800381C0
    if (ctx->r3 == 0) {
        // 0x80038160: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800381C0;
    }
    // 0x80038160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038164: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80038168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003816C: blez        $v0, L_800381BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038170: addiu       $t6, $zero, 0x4000
        ctx->r14 = ADD32(0, 0X4000);
            goto L_800381BC;
    }
    // 0x80038170: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80038174: bne         $v0, $at, L_80038188
    if (ctx->r2 != ctx->r1) {
        // 0x80038178: nop
    
            goto L_80038188;
    }
    // 0x80038178: nop

    // 0x8003817C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80038180: b           L_80038194
    // 0x80038184: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
        goto L_80038194;
    // 0x80038184: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038188:
    // 0x80038188: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8003818C: nop

    // 0x80038190: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038194:
    // 0x80038194: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x80038198: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003819C: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    // 0x800381A0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x800381A4: lb          $t1, 0x3A($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X3A);
    // 0x800381A8: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x800381AC: nop

    // 0x800381B0: bne         $t0, $t1, L_800381C0
    if (ctx->r8 != ctx->r9) {
        // 0x800381B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800381C0;
    }
    // 0x800381B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800381B8: sb          $zero, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = 0;
L_800381BC:
    // 0x800381BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800381C0:
    // 0x800381C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800381C4: jr          $ra
    // 0x800381C8: nop

    return;
    // 0x800381C8: nop

;}
RECOMP_FUNC void obj_init_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800381CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800381D0: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800381D4: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x800381D8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800381DC: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800381E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800381E4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800381E8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800381EC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800381F0: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800381F4: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800381F8: jr          $ra
    // 0x800381FC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800381FC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void obj_loop_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038208: jal         0x8001F494
    // 0x8003820C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x8003820C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80038210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038218: jr          $ra
    // 0x8003821C: nop

    return;
    // 0x8003821C: nop

;}
RECOMP_FUNC void obj_init_dynamic_lighting_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038220: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038224: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038228: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003822C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038230: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80038234: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80038238: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8003823C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038240: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038244: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80038248: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003824C: jr          $ra
    // 0x80038250: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038250: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void obj_init_unknown96(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038254: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038258: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003825C: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x80038260: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038264: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80038268: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003826C: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80038270: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038274: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038278: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003827C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80038280: jr          $ra
    // 0x80038284: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038284: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void obj_init_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038288: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003828C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038290: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038294: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038298: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003829C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800382A0: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800382A4: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800382A8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800382AC: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800382B0: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800382B4: jr          $ra
    // 0x800382B8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800382B8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void obj_loop_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800382BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800382C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800382C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800382C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800382CC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800382D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800382D4: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x800382D8: nop

    // 0x800382DC: bne         $v1, $zero, L_80038300
    if (ctx->r3 != 0) {
        // 0x800382E0: nop
    
            goto L_80038300;
    }
    // 0x800382E0: nop

    // 0x800382E4: lb          $a0, 0x38($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X38);
    // 0x800382E8: nop

    // 0x800382EC: beq         $a0, $zero, L_80038300
    if (ctx->r4 == 0) {
        // 0x800382F0: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80038300;
    }
    // 0x800382F0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800382F4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x800382F8: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x800382FC: nop

L_80038300:
    // 0x80038300: beq         $v1, $zero, L_80038354
    if (ctx->r3 == 0) {
        // 0x80038304: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80038354;
    }
    // 0x80038304: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80038308: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8003830C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80038310: bne         $t0, $zero, L_8003833C
    if (ctx->r8 != 0) {
        // 0x80038314: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003833C;
    }
    // 0x80038314: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80038318: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003831C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038320: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038324: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x80038328: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003832C: jal         0x80009558
    // 0x80038330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x80038330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80038334: b           L_80038354
    // 0x80038338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
        goto L_80038354;
    // 0x80038338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8003833C:
    // 0x8003833C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80038340: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038344: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038348: jal         0x800096D8
    // 0x8003834C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    audspat_point_set_position(rdram, ctx);
        goto after_1;
    // 0x8003834C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80038350: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_80038354:
    // 0x80038354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038358: jal         0x8001F494
    // 0x8003835C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_2;
    // 0x8003835C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80038360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038364: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80038368: jr          $ra
    // 0x8003836C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003836C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038370: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038374: jr          $ra
    // 0x80038378: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038378: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003837C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80038380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038384: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80038388: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003838C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80038390: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80038394: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80038398: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003839C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800383A0: jal         0x8001F494
    // 0x800383A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x800383A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800383A8: lw          $v1, 0x64($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X64);
    // 0x800383AC: sw          $zero, 0x74($s2)
    MEM_W(0X74, ctx->r18) = 0;
    // 0x800383B0: beq         $v1, $zero, L_80038738
    if (ctx->r3 == 0) {
        // 0x800383B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x800383B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800383B8: lb          $t7, 0x3A($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X3A);
    // 0x800383BC: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x800383C0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800383C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800383C8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800383CC: nop

    // 0x800383D0: beq         $v0, $zero, L_80038738
    if (ctx->r2 == 0) {
        // 0x800383D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x800383D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800383D8: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800383DC: jal         0x8009F214
    // 0x800383E0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x800383E0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x800383E4: beq         $v0, $zero, L_80038418
    if (ctx->r2 == 0) {
        // 0x800383E8: nop
    
            goto L_80038418;
    }
    // 0x800383E8: nop

    // 0x800383EC: jal         0x8009F1FC
    // 0x800383F0: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x800383F0: nop

    after_2:
    // 0x800383F4: beq         $v0, $zero, L_8003840C
    if (ctx->r2 == 0) {
        // 0x800383F8: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_8003840C;
    }
    // 0x800383F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383FC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80038400: addiu       $a2, $a2, -0x3020
    ctx->r6 = ADD32(ctx->r6, -0X3020);
    // 0x80038404: b           L_80038440
    // 0x80038408: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_80038440;
    // 0x80038408: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8003840C:
    // 0x8003840C: addiu       $a2, $a2, -0x3038
    ctx->r6 = ADD32(ctx->r6, -0X3038);
    // 0x80038410: b           L_80038440
    // 0x80038414: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038440;
    // 0x80038414: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_80038418:
    // 0x80038418: jal         0x8009F1FC
    // 0x8003841C: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x8003841C: nop

    after_3:
    // 0x80038420: beq         $v0, $zero, L_80038438
    if (ctx->r2 == 0) {
        // 0x80038424: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80038438;
    }
    // 0x80038424: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80038428: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8003842C: addiu       $a2, $a2, -0x302C
    ctx->r6 = ADD32(ctx->r6, -0X302C);
    // 0x80038430: b           L_80038440
    // 0x80038434: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038440;
    // 0x80038434: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_80038438:
    // 0x80038438: addiu       $a2, $a2, -0x3040
    ctx->r6 = ADD32(ctx->r6, -0X3040);
    // 0x8003843C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80038440:
    // 0x80038440: blez        $a0, L_8003847C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80038444: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003847C;
    }
    // 0x80038444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038448: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8003844C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80038450: lh          $v1, 0x28($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X28);
    // 0x80038454: nop

L_80038458:
    // 0x80038458: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8003845C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80038460: bne         $v1, $t2, L_8003846C
    if (ctx->r3 != ctx->r10) {
        // 0x80038464: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003846C;
    }
    // 0x80038464: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80038468: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003846C:
    // 0x8003846C: beq         $at, $zero, L_8003847C
    if (ctx->r1 == 0) {
        // 0x80038470: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8003847C;
    }
    // 0x80038470: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038474: beq         $s0, $zero, L_80038458
    if (ctx->r16 == 0) {
        // 0x80038478: nop
    
            goto L_80038458;
    }
    // 0x80038478: nop

L_8003847C:
    // 0x8003847C: beq         $s0, $zero, L_80038638
    if (ctx->r16 == 0) {
        // 0x80038480: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80038638;
    }
    // 0x80038480: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038484: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80038488: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x8003848C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038490: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038494: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80038498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003849C:
    // 0x8003849C: sb          $v1, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r3;
    // 0x800384A0: jal         0x8009C7C4
    // 0x800384A4: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    get_player_character(rdram, ctx);
        goto after_4;
    // 0x800384A4: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    after_4:
    // 0x800384A8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800384AC: lbu         $v1, 0x4F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4F);
    // 0x800384B0: bne         $v0, $a1, L_800384CC
    if (ctx->r2 != ctx->r5) {
        // 0x800384B4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800384CC;
    }
    // 0x800384B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800384B8: addu        $t4, $s1, $v1
    ctx->r12 = ADD32(ctx->r17, ctx->r3);
    // 0x800384BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800384C0: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x800384C4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800384C8: sb          $s0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r16;
L_800384CC:
    // 0x800384CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800384D0: bne         $s0, $at, L_8003849C
    if (ctx->r16 != ctx->r1) {
        // 0x800384D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003849C;
    }
    // 0x800384D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800384D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800384DC: addiu       $t7, $t7, -0x3014
    ctx->r15 = ADD32(ctx->r15, -0X3014);
    // 0x800384E0: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x800384E4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800384E8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800384EC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800384F0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800384F4: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
    // 0x800384F8: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800384FC: bne         $at, $zero, L_80038524
    if (ctx->r1 != 0) {
        // 0x80038500: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_80038524;
    }
    // 0x80038500: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80038504: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80038508: addiu       $t2, $t2, -0x3008
    ctx->r10 = ADD32(ctx->r10, -0X3008);
    // 0x8003850C: addu        $t0, $a1, $t2
    ctx->r8 = ADD32(ctx->r5, ctx->r10);
    // 0x80038510: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x80038514: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x80038518: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8003851C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80038520: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
L_80038524:
    // 0x80038524: addiu       $t5, $t5, -0x3008
    ctx->r13 = ADD32(ctx->r13, -0X3008);
    // 0x80038528: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x8003852C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80038530: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80038534: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80038538: bne         $at, $zero, L_80038544
    if (ctx->r1 != 0) {
        // 0x8003853C: nop
    
            goto L_80038544;
    }
    // 0x8003853C: nop

    // 0x80038540: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80038544:
    // 0x80038544: blez        $a3, L_80038638
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038548: nop
    
            goto L_80038638;
    }
    // 0x80038548: nop

    // 0x8003854C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80038550: jal         0x8009C7B8
    // 0x80038554: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    charselect_status(rdram, ctx);
        goto after_5;
    // 0x80038554: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_5:
    // 0x80038558: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8003855C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80038560: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80038564: blez        $a3, L_800385D4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038568: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800385D4;
    }
    // 0x80038568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003856C: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80038570: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80038574:
    // 0x80038574: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80038578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003857C: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x80038580: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80038584: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038588: bne         $t9, $at, L_800385C4
    if (ctx->r25 != ctx->r1) {
        // 0x8003858C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800385C4;
    }
    // 0x8003858C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80038590: sw          $s0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r16;
    // 0x80038594: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80038598: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8003859C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800385A0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x800385A4: jal         0x800B019C
    // 0x800385A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    obj_spawn_particle(rdram, ctx);
        goto after_6;
    // 0x800385A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_6:
    // 0x800385AC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800385B0: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800385B4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800385B8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800385BC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800385C0: nop

L_800385C4:
    // 0x800385C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385C8: bne         $v1, $a3, L_80038574
    if (ctx->r3 != ctx->r7) {
        // 0x800385CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80038574;
    }
    // 0x800385CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800385D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800385D4:
    // 0x800385D4: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x800385D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800385DC: blez        $a2, L_80038634
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800385E0: nop
    
            goto L_80038634;
    }
    // 0x800385E0: nop

L_800385E4:
    // 0x800385E4: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x800385E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385EC: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x800385F0: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800385F4: nop

    // 0x800385F8: bltz        $a1, L_80038628
    if (SIGNED(ctx->r5) < 0) {
        // 0x800385FC: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_80038628;
    }
    // 0x800385FC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80038600: beq         $at, $zero, L_8003862C
    if (ctx->r1 == 0) {
        // 0x80038604: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8003862C;
    }
    // 0x80038604: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80038608: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8003860C: nop

    // 0x80038610: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80038614: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80038618: nop

    // 0x8003861C: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80038620: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x80038624: nop

L_80038628:
    // 0x80038628: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_8003862C:
    // 0x8003862C: bne         $at, $zero, L_800385E4
    if (ctx->r1 != 0) {
        // 0x80038630: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800385E4;
    }
    // 0x80038630: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80038634:
    // 0x80038634: sb          $zero, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = 0;
L_80038638:
    // 0x80038638: lb          $v0, 0x3B($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X3B);
    // 0x8003863C: nop

    // 0x80038640: bltz        $v0, L_80038738
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038644: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x80038644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038648: lh          $t5, 0x48($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X48);
    // 0x8003864C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80038650: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80038654: beq         $at, $zero, L_80038734
    if (ctx->r1 == 0) {
        // 0x80038658: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_80038734;
    }
    // 0x80038658: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8003865C: lw          $t7, 0x44($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X44);
    // 0x80038660: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x80038664: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80038668: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8003866C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038670: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038674: bne         $t2, $at, L_80038734
    if (ctx->r10 != ctx->r1) {
        // 0x80038678: sll         $t9, $a1, 4
        ctx->r25 = S32(ctx->r5 << 4);
            goto L_80038734;
    }
    // 0x80038678: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8003867C: jal         0x800015F8
    // 0x80038680: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    music_animation_fraction(rdram, ctx);
        goto after_7;
    // 0x80038680: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    after_7:
    // 0x80038684: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80038688: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003868C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038690: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80038694: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x80038698: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8003869C: bc1f        L_800386F4
    if (!c1cs) {
        // 0x800386A0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800386F4;
    }
    // 0x800386A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800386A4: sub.d       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f14.d - ctx->f18.d;
    // 0x800386A8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800386AC: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800386B0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800386B4: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x800386B8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800386BC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800386C0: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800386C4: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800386C8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800386CC: nop

    // 0x800386D0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800386D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800386D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800386DC: nop

    // 0x800386E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800386E4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800386E8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800386EC: b           L_80038734
    // 0x800386F0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
        goto L_80038734;
    // 0x800386F0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
L_800386F4:
    // 0x800386F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800386F8: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800386FC: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80038700: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80038704: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80038708: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003870C: nop

    // 0x80038710: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80038714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003871C: nop

    // 0x80038720: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80038724: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80038728: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003872C: sh          $t7, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r15;
    // 0x80038730: nop

L_80038734:
    // 0x80038734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80038738:
    // 0x80038738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003873C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80038740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80038744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80038748: jr          $ra
    // 0x8003874C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003874C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void obj_loop_animcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038750: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80038754: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038758: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003875C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038760: jal         0x8001F494
    // 0x80038764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80038768: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003876C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80038770: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038774: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x80038778: bne         $v0, $zero, L_800387F0
    if (ctx->r2 != 0) {
        // 0x8003877C: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_800387F0;
    }
    // 0x8003877C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80038780: jal         0x80066450
    // 0x80038784: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80038784: nop

    after_1:
    // 0x80038788: bne         $v0, $zero, L_800387AC
    if (ctx->r2 != 0) {
        // 0x8003878C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800387AC;
    }
    // 0x8003878C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80038790: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80038794: nop

    // 0x80038798: lb          $a0, 0x44($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X44);
    // 0x8003879C: jal         0x80021100
    // 0x800387A0: nop

    func_800210CC(rdram, ctx);
        goto after_2;
    // 0x800387A0: nop

    after_2:
    // 0x800387A4: b           L_800387AC
    // 0x800387A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800387AC;
    // 0x800387A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800387AC:
    // 0x800387AC: beq         $v1, $zero, L_800387F0
    if (ctx->r3 == 0) {
        // 0x800387B0: ori         $t2, $zero, 0x8000
        ctx->r10 = 0 | 0X8000;
            goto L_800387F0;
    }
    // 0x800387B0: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800387B4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800387B8: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800387BC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800387C0: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800387C4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800387C8: lb          $a0, 0x30($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X30);
    // 0x800387CC: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800387D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800387D4: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800387D8: nop

    // 0x800387DC: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800387E0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800387E4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800387E8: jal         0x800666C8
    // 0x800387EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    write_to_object_render_stack(rdram, ctx);
        goto after_3;
    // 0x800387EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
L_800387F0:
    // 0x800387F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800387F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800387F8: jr          $ra
    // 0x800387FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800387FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038800: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038804: jr          $ra
    // 0x80038808: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038808: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003880C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038818: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8003881C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80038820: beq         $v0, $zero, L_8003883C
    if (ctx->r2 == 0) {
        // 0x80038824: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8003883C;
    }
    // 0x80038824: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038828: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8003882C: jal         0x8001BAFC
    // 0x80038830: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80038830: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80038834: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80038838: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003883C:
    // 0x8003883C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038840: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80038844: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80038848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003884C: jal         0x8001F494
    // 0x80038850: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8001F460(rdram, ctx);
        goto after_1;
    // 0x80038850: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80038854: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80038858: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003885C: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80038860: sw          $v0, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r2;
    // 0x80038864: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038868: bne         $v0, $zero, L_80038884
    if (ctx->r2 != 0) {
        // 0x8003886C: sh          $t7, 0x6($a3)
        MEM_H(0X6, ctx->r7) = ctx->r15;
            goto L_80038884;
    }
    // 0x8003886C: sh          $t7, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r15;
    // 0x80038870: beq         $v1, $zero, L_80038888
    if (ctx->r3 == 0) {
        // 0x80038874: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038888;
    }
    // 0x80038874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038878: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003887C: nop

    // 0x80038880: sw          $a3, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r7;
L_80038884:
    // 0x80038884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038888:
    // 0x80038888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003888C: jr          $ra
    // 0x80038890: nop

    return;
    // 0x80038890: nop

;}
RECOMP_FUNC void obj_init_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038894: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x80038898: addiu       $t7, $zero, 0x21
    ctx->r15 = ADD32(0, 0X21);
    // 0x8003889C: beq         $t6, $zero, L_800388B0
    if (ctx->r14 == 0) {
        // 0x800388A0: nop
    
            goto L_800388B0;
    }
    // 0x800388A0: nop

    // 0x800388A4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800388A8: b           L_800388BC
    // 0x800388AC: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
        goto L_800388BC;
    // 0x800388AC: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
L_800388B0:
    // 0x800388B0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800388B4: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x800388B8: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
L_800388BC:
    // 0x800388BC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800388C0: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800388C4: sb          $zero, 0x11($t1)
    MEM_B(0X11, ctx->r9) = 0;
    // 0x800388C8: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x800388CC: nop

    // 0x800388D0: sb          $t2, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r10;
    // 0x800388D4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x800388D8: nop

    // 0x800388DC: sb          $zero, 0x12($t4)
    MEM_B(0X12, ctx->r12) = 0;
    // 0x800388E0: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800388E4: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800388E8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800388EC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800388F0: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
    // 0x800388F4: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800388F8: nop

    // 0x800388FC: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x80038900: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x80038904: nop

    // 0x80038908: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8003890C: jr          $ra
    // 0x80038910: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    return;
    // 0x80038910: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void obj_loop_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003891C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038920: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038924: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80038928: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003892C: bne         $t6, $zero, L_80038948
    if (ctx->r14 != 0) {
        // 0x80038930: nop
    
            goto L_80038948;
    }
    // 0x80038930: nop

    // 0x80038934: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80038938: nop

    // 0x8003893C: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80038940: b           L_80038958
    // 0x80038944: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80038958;
    // 0x80038944: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80038948:
    // 0x80038948: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x8003894C: nop

    // 0x80038950: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x80038954: sh          $t0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r8;
L_80038958:
    // 0x80038958: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003895C: lw          $t2, 0x78($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X78);
    // 0x80038960: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x80038964: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80038968: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8003896C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80038970: beq         $at, $zero, L_800389E0
    if (ctx->r1 == 0) {
        // 0x80038974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x80038974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038978: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003897C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038980: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x80038984: nop

    // 0x80038988: lb          $t6, 0x54($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X54);
    // 0x8003898C: nop

    // 0x80038990: bne         $t6, $at, L_800389E0
    if (ctx->r14 != ctx->r1) {
        // 0x80038994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x80038994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038998: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003899C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800389A0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800389A4: nop

    // 0x800389A8: beq         $a0, $at, L_800389E0
    if (ctx->r4 == ctx->r1) {
        // 0x800389AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x800389AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389B0: jal         0x8006A794
    // 0x800389B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x800389B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800389B8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800389BC: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x800389C0: beq         $t7, $zero, L_800389E0
    if (ctx->r15 == 0) {
        // 0x800389C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389E0;
    }
    // 0x800389C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389C8: lw          $a0, 0x78($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X78);
    // 0x800389CC: nop

    // 0x800389D0: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800389D4: jal         0x800C3744
    // 0x800389D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800389D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800389DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800389E0:
    // 0x800389E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800389E4: jr          $ra
    // 0x800389E8: nop

    return;
    // 0x800389E8: nop

;}
RECOMP_FUNC void obj_init_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800389F0: jr          $ra
    // 0x800389F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800389F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389F8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800389FC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80038A00: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038A04: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80038A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038A10: bne         $t6, $zero, L_80038A30
    if (ctx->r14 != 0) {
        // 0x80038A14: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80038A30;
    }
    // 0x80038A14: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038A18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038A1C: lwc1        $f9, 0x65E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65E0);
    // 0x80038A20: lwc1        $f8, 0x65E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65E4);
    // 0x80038A24: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80038A28: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80038A2C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80038A30:
    // 0x80038A30: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80038A34: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80038A38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80038A3C: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80038A40: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038A44: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80038A48: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80038A4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038A50: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80038A54: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80038A58: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80038A5C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038A60: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80038A64: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038A68: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80038A6C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038A70: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80038A74: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038A78: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80038A7C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038A80: bne         $at, $zero, L_80038A9C
    if (ctx->r1 != 0) {
        // 0x80038A84: swc1        $f8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
            goto L_80038A9C;
    }
    // 0x80038A84: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80038A88: jal         0x8000FFB8
    // 0x80038A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038A90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038A94: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038A98: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038A9C:
    // 0x80038A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038AA4: jr          $ra
    // 0x80038AA8: nop

    return;
    // 0x80038AA8: nop

;}
RECOMP_FUNC void obj_init_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038AB0: jr          $ra
    // 0x80038AB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038AB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038AC0: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80038AC4: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80038AC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80038ACC: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x80038AD0: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x80038AD4: nop

    // 0x80038AD8: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80038ADC: bne         $at, $zero, L_80038AFC
    if (ctx->r1 != 0) {
        // 0x80038AE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038AFC;
    }
    // 0x80038AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038AE4: jal         0x8000FFB8
    // 0x80038AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038AF0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80038AF4: sh          $t0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r8;
    // 0x80038AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038AFC:
    // 0x80038AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038B00: jr          $ra
    // 0x80038B04: nop

    return;
    // 0x80038B04: nop

;}
RECOMP_FUNC void obj_init_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038B0C: jr          $ra
    // 0x80038B10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038B10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B14: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80038B18: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80038B1C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038B20: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80038B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038B2C: bne         $t6, $zero, L_80038B4C
    if (ctx->r14 != 0) {
        // 0x80038B30: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80038B4C;
    }
    // 0x80038B30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038B38: lwc1        $f9, 0x65E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65E8);
    // 0x80038B3C: lwc1        $f8, 0x65EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65EC);
    // 0x80038B40: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80038B44: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80038B48: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80038B4C:
    // 0x80038B4C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80038B50: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80038B54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038B58: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80038B5C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80038B60: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038B64: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038B68: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80038B6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038B70: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038B74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80038B78: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x80038B7C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038B80: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80038B84: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038B88: bne         $at, $zero, L_80038BA4
    if (ctx->r1 != 0) {
        // 0x80038B8C: swc1        $f16, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
            goto L_80038BA4;
    }
    // 0x80038B8C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038B90: jal         0x8000FFB8
    // 0x80038B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038B9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038BA0: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038BA4:
    // 0x80038BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038BAC: jr          $ra
    // 0x80038BB0: nop

    return;
    // 0x80038BB0: nop

;}
RECOMP_FUNC void obj_init_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038BB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038BC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038BCC: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80038BD0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80038BD4: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x80038BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038BDC: lb          $a1, 0x55($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X55);
    // 0x80038BE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80038BE4: jal         0x8006FB8C
    // 0x80038BE8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80038BE8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x80038BEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80038BF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038BF4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80038BF8: sb          $v0, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r2;
    // 0x80038BFC: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80038C00: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80038C04: lb          $v1, 0x8($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X8);
    // 0x80038C08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80038C0C: beq         $v1, $zero, L_80038C20
    if (ctx->r3 == 0) {
        // 0x80038C10: sll         $t9, $v1, 8
        ctx->r25 = S32(ctx->r3 << 8);
            goto L_80038C20;
    }
    // 0x80038C10: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x80038C14: andi        $t0, $t9, 0xFF00
    ctx->r8 = ctx->r25 & 0XFF00;
    // 0x80038C18: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80038C1C: sw          $t1, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r9;
L_80038C20:
    // 0x80038C20: sw          $t2, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r10;
    // 0x80038C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038C2C: jr          $ra
    // 0x80038C30: nop

    return;
    // 0x80038C30: nop

;}
RECOMP_FUNC void obj_loop_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038C34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80038C38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038C3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038C40: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038C44: lw          $t0, 0x7C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X7C);
    // 0x80038C48: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80038C4C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80038C50: sra         $v1, $t0, 8
    ctx->r3 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80038C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038C58: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80038C5C: bne         $at, $zero, L_80038CA8
    if (ctx->r1 != 0) {
        // 0x80038C60: andi        $t8, $v1, 0xFF
        ctx->r24 = ctx->r3 & 0XFF;
            goto L_80038CA8;
    }
    // 0x80038C60: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x80038C64: beq         $t8, $zero, L_80038CA8
    if (ctx->r24 == 0) {
        // 0x80038C68: sll         $t9, $t8, 8
        ctx->r25 = S32(ctx->r24 << 8);
            goto L_80038CA8;
    }
    // 0x80038C68: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80038C6C: xor         $t1, $t0, $t9
    ctx->r9 = ctx->r8 ^ ctx->r25;
    // 0x80038C70: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80038C74: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038C78: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x80038C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038C84: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
    // 0x80038C88: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80038C8C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80038C90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80038C94: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80038C98: jal         0x8003FC84
    // 0x80038C9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_0;
    // 0x80038C9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80038CA0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80038CA4: nop

L_80038CA8:
    // 0x80038CA8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80038CAC: beq         $at, $zero, L_80038CFC
    if (ctx->r1 == 0) {
        // 0x80038CB0: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80038CFC;
    }
    // 0x80038CB0: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80038CB4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80038CB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038CBC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80038CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038CC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80038CC8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80038CCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038CD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038CD8: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x80038CDC: nop

    // 0x80038CE0: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x80038CE4: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x80038CE8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038CEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038CF0: b           L_80038D58
    // 0x80038CF4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80038D58;
    // 0x80038CF4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80038CF8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
L_80038CFC:
    // 0x80038CFC: beq         $at, $zero, L_80038D50
    if (ctx->r1 == 0) {
        // 0x80038D00: addiu       $t5, $v0, -0x14
        ctx->r13 = ADD32(ctx->r2, -0X14);
            goto L_80038D50;
    }
    // 0x80038D00: addiu       $t5, $v0, -0x14
    ctx->r13 = ADD32(ctx->r2, -0X14);
    // 0x80038D04: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80038D08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038D0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80038D10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038D14: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038D18: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038D1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038D20: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x80038D24: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80038D28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038D2C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80038D30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80038D34: addiu       $t7, $zero, 0x1EF
    ctx->r15 = ADD32(0, 0X1EF);
    // 0x80038D38: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80038D3C: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80038D40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80038D44: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038D48: b           L_80038D58
    // 0x80038D4C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80038D58;
    // 0x80038D4C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80038D50:
    // 0x80038D50: jal         0x8000FFB8
    // 0x80038D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x80038D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80038D58:
    // 0x80038D58: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80038D5C: nop

    // 0x80038D60: beq         $t9, $zero, L_80038D8C
    if (ctx->r25 == 0) {
        // 0x80038D64: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80038D8C;
    }
    // 0x80038D64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80038D68: jal         0x8009C90C
    // 0x80038D6C: nop

    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x80038D6C: nop

    after_2:
    // 0x80038D70: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80038D74: beq         $at, $zero, L_80038D88
    if (ctx->r1 == 0) {
        // 0x80038D78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80038D88;
    }
    // 0x80038D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038D7C: jal         0x800B019C
    // 0x80038D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80038D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80038D84: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
L_80038D88:
    // 0x80038D88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80038D8C:
    // 0x80038D8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80038D90: jr          $ra
    // 0x80038D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80038D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038DA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038DA4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DA8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80038DAC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038DB0: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DB4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80038DB8: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80038DBC: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DC0: nop

    // 0x80038DC4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80038DC8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DCC: nop

    // 0x80038DD0: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80038DD4: jal         0x8006ECD0
    // 0x80038DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038DDC: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80038DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038DE4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80038DE8: beq         $t3, $zero, L_80038DF4
    if (ctx->r11 == 0) {
        // 0x80038DEC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80038DF4;
    }
    // 0x80038DEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80038DF0: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
L_80038DF4:
    // 0x80038DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038DFC: jr          $ra
    // 0x80038E00: nop

    return;
    // 0x80038E00: nop

;}
RECOMP_FUNC void obj_loop_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038E10: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038E14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038E18: beq         $t6, $zero, L_80038E70
    if (ctx->r14 == 0) {
        // 0x80038E1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E70;
    }
    // 0x80038E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038E20: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038E24: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80038E28: lbu         $t8, 0x13($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X13);
    // 0x80038E2C: nop

    // 0x80038E30: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x80038E34: beq         $at, $zero, L_80038E70
    if (ctx->r1 == 0) {
        // 0x80038E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E70;
    }
    // 0x80038E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038E3C: lb          $a0, 0x8($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X8);
    // 0x80038E40: jal         0x8006F578
    // 0x80038E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    begin_level_teleport(rdram, ctx);
        goto after_0;
    // 0x80038E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80038E48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038E4C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80038E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E54: jal         0x80001D04
    // 0x80038E58: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80038E58: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    after_1:
    // 0x80038E5C: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    // 0x80038E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E64: jal         0x80000FDC
    // 0x80038E68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_2;
    // 0x80038E68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80038E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038E70:
    // 0x80038E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038E74: jr          $ra
    // 0x80038E78: nop

    return;
    // 0x80038E78: nop

;}
RECOMP_FUNC void obj_init_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E84: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x80038E88: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038E8C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80038E90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80038E94: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038E98: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80038E9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038EA0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80038EA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038EA8: bc1f        L_80038EB8
    if (!c1cs) {
        // 0x80038EAC: nop
    
            goto L_80038EB8;
    }
    // 0x80038EAC: nop

    // 0x80038EB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038EB4: nop

L_80038EB8:
    // 0x80038EB8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80038EBC: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80038EC0: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x80038EC4: lbu         $t9, 0x11($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X11);
    // 0x80038EC8: nop

    // 0x80038ECC: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80038ED0: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x80038ED4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038ED8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80038EDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038EE0: jal         0x80070A04
    // 0x80038EE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80038EE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80038EE8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038EEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038EF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038EF4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80038EF8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80038EFC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038F00: jal         0x80070A38
    // 0x80038F04: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80038F04: nop

    after_1:
    // 0x80038F08: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038F0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038F10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038F14: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80038F18: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80038F1C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80038F20: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80038F24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80038F28: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80038F2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80038F30: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038F34: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80038F38: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80038F3C: lbu         $t1, 0x10($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F40: nop

    // 0x80038F44: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x80038F48: lb          $t2, 0x18($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X18);
    // 0x80038F4C: nop

    // 0x80038F50: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x80038F54: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F58: nop

    // 0x80038F5C: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80038F60: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F64: nop

    // 0x80038F68: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80038F6C: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F70: lbu         $t6, 0x10($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F74: nop

    // 0x80038F78: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80038F7C: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F80: nop

    // 0x80038F84: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x80038F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038F90: jr          $ra
    // 0x80038F94: nop

    return;
    // 0x80038F94: nop

;}
RECOMP_FUNC void obj_loop_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F98: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80038F9C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80038FA0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80038FA4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80038FA8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80038FAC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80038FB0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80038FB4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80038FB8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80038FBC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80038FC0: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80038FC4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80038FC8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80038FCC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80038FD0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80038FD4: lw          $s5, 0x64($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X64);
    // 0x80038FD8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80038FDC: jal         0x8006ECD0
    // 0x80038FE0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038FE0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_0:
    // 0x80038FE4: lb          $v1, 0x14($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X14);
    // 0x80038FE8: nop

    // 0x80038FEC: bne         $v1, $zero, L_8003901C
    if (ctx->r3 != 0) {
        // 0x80038FF0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003901C;
    }
    // 0x80038FF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038FF4: lbu         $t7, 0x48($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X48);
    // 0x80038FF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80038FFC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80039000: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80039004: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80039008: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003900C: bne         $t0, $at, L_8003901C
    if (ctx->r8 != ctx->r1) {
        // 0x80039010: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003901C;
    }
    // 0x80039010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80039014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80039018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8003901C:
    // 0x8003901C: bne         $v1, $at, L_8003904C
    if (ctx->r3 != ctx->r1) {
        // 0x80039020: nop
    
            goto L_8003904C;
    }
    // 0x80039020: nop

    // 0x80039024: lbu         $t2, 0x48($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X48);
    // 0x80039028: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8003902C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80039030: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80039034: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80039038: nop

    // 0x8003903C: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80039040: beq         $at, $zero, L_8003904C
    if (ctx->r1 == 0) {
        // 0x80039044: nop
    
            goto L_8003904C;
    }
    // 0x80039044: nop

    // 0x80039048: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003904C:
    // 0x8003904C: beq         $s0, $zero, L_80039168
    if (ctx->r16 == 0) {
        // 0x80039050: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039168;
    }
    // 0x80039050: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039054: lw          $t7, 0x4C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4C);
    // 0x80039058: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x8003905C: lbu         $t6, 0x13($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X13);
    // 0x80039060: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80039064: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039068: beq         $at, $zero, L_80039168
    if (ctx->r1 == 0) {
        // 0x8003906C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039168;
    }
    // 0x8003906C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039070: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80039074: jal         0x8001BAA8
    // 0x80039078: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80039078: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8003907C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80039080: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80039084: blez        $t8, L_80039164
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80039088: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80039164;
    }
    // 0x80039088: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003908C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80039090: addiu       $s7, $zero, -0x78
    ctx->r23 = ADD32(0, -0X78);
    // 0x80039094: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80039098:
    // 0x80039098: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003909C: nop

    // 0x800390A0: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800390A4: nop

    // 0x800390A8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800390AC: nop

    // 0x800390B0: beq         $s6, $t9, L_80039154
    if (ctx->r22 == ctx->r25) {
        // 0x800390B4: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x800390B4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800390B8: lw          $t0, 0x108($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X108);
    // 0x800390BC: nop

    // 0x800390C0: bne         $t0, $zero, L_80039154
    if (ctx->r8 != 0) {
        // 0x800390C4: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x800390C4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800390C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800390CC: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800390D0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800390D4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800390D8: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800390DC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800390E0: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800390E4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800390E8: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800390EC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800390F0: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800390F4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800390F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800390FC: jal         0x800CA030
    // 0x80039100: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80039100: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_2:
    // 0x80039104: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80039108: nop

    // 0x8003910C: bc1f        L_80039154
    if (!c1cs) {
        // 0x80039110: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x80039110: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039114: lwc1        $f18, 0x0($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80039118: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003911C: lwc1        $f8, 0x8($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80039120: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80039124: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039128: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8003912C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80039130: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80039134: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80039138: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003913C: nop

    // 0x80039140: bc1f        L_80039154
    if (!c1cs) {
        // 0x80039144: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039154;
    }
    // 0x80039144: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039148: sw          $s4, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->r20;
    // 0x8003914C: sb          $s7, 0x200($s1)
    MEM_B(0X200, ctx->r17) = ctx->r23;
    // 0x80039150: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80039154:
    // 0x80039154: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80039158: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003915C: bne         $at, $zero, L_80039098
    if (ctx->r1 != 0) {
        // 0x80039160: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80039098;
    }
    // 0x80039160: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80039164:
    // 0x80039164: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80039168:
    // 0x80039168: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003916C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80039170: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80039174: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80039178: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003917C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80039180: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80039184: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80039188: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003918C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80039190: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80039194: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80039198: jr          $ra
    // 0x8003919C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003919C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_init_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800391A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800391A8: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x800391AC: jal         0x80011390
    // 0x800391B0: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x800391B0: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    after_0:
    // 0x800391B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800391B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800391BC: jr          $ra
    // 0x800391C0: nop

    return;
    // 0x800391C0: nop

;}
RECOMP_FUNC void obj_loop_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800391C8: jr          $ra
    // 0x800391CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800391CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391D0: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800391D4: nop

    // 0x800391D8: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x800391DC: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800391E0: nop

    // 0x800391E4: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x800391E8: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800391EC: nop

    // 0x800391F0: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800391F4: jr          $ra
    // 0x800391F8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x800391F8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void obj_loop_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039200: jr          $ra
    // 0x80039204: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80039204: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_init_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039208: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003920C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80039210: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039214: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80039218: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003921C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80039220: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80039224: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80039228: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003922C: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80039230: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80039234: jr          $ra
    // 0x80039238: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80039238: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void obj_loop_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003923C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039244: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80039248: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8003924C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80039250: blez        $v0, L_8003926C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039254: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_8003926C;
    }
    // 0x80039254: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80039258: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8003925C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80039260: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80039264: b           L_80039270
    // 0x80039268: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80039270;
    // 0x80039268: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8003926C:
    // 0x8003926C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_80039270:
    // 0x80039270: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80039274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039278: jal         0x8001F494
    // 0x8003927C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x8003927C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80039280: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80039284: addiu       $t9, $zero, 0xAD
    ctx->r25 = ADD32(0, 0XAD);
    // 0x80039288: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003928C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039294: jal         0x800113CC
    // 0x80039298: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_1;
    // 0x80039298: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_1:
    // 0x8003929C: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x800392A0: nop

    // 0x800392A4: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x800392A8: nop

    // 0x800392AC: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x800392B0: beq         $at, $zero, L_800392EC
    if (ctx->r1 == 0) {
        // 0x800392B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800392EC;
    }
    // 0x800392B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800392B8: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x800392BC: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800392C0: bne         $t2, $zero, L_800392E8
    if (ctx->r10 != 0) {
        // 0x800392C4: addiu       $a0, $zero, 0x23B
        ctx->r4 = ADD32(0, 0X23B);
            goto L_800392E8;
    }
    // 0x800392C4: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    // 0x800392C8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800392CC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800392D0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800392D4: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x800392D8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800392DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800392E0: jal         0x80009558
    // 0x800392E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x800392E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
L_800392E8:
    // 0x800392E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800392EC:
    // 0x800392EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800392F0: jr          $ra
    // 0x800392F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800392F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800392F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800392FC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80039300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039304: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80039308: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003930C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80039310: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80039314: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80039318: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003931C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80039320: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80039324: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80039328: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003932C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80039330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039334: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x80039338: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003933C: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x80039340: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80039344: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80039348: sb          $zero, 0x36($v0)
    MEM_B(0X36, ctx->r2) = 0;
    // 0x8003934C: sw          $zero, -0x25AC($at)
    MEM_W(-0X25AC, ctx->r1) = 0;
    // 0x80039350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039354: addiu       $t3, $zero, 0x10F
    ctx->r11 = ADD32(0, 0X10F);
    // 0x80039358: jr          $ra
    // 0x8003935C: sh          $t3, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r11;
    return;
    // 0x8003935C: sh          $t3, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void set_taj_voice_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039364: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039368: jr          $ra
    // 0x8003936C: sh          $a0, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r4;
    return;
    // 0x8003936C: sh          $a0, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_loop_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039370: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80039374: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80039378: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003937C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80039380: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80039384: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80039388: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    // 0x8003938C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80039390: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80039394: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80039398: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003939C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800393A0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800393A4: bne         $t7, $zero, L_800393C4
    if (ctx->r15 != 0) {
        // 0x800393A8: swc1        $f4, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
            goto L_800393C4;
    }
    // 0x800393A8: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x800393AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800393B0: lwc1        $f11, 0x65F0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65F0);
    // 0x800393B4: lwc1        $f10, 0x65F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65F4);
    // 0x800393B8: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800393BC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800393C0: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
L_800393C4:
    // 0x800393C4: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800393C8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800393CC: jal         0x8006BFF0
    // 0x800393D0: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x800393D0: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800393D4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800393D8: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x800393DC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x800393E0: bne         $t8, $zero, L_80039418
    if (ctx->r24 != 0) {
        // 0x800393E4: nop
    
            goto L_80039418;
    }
    // 0x800393E4: nop

    // 0x800393E8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800393EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800393F0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800393F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800393F8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800393FC: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80039400: nop

    // 0x80039404: bc1f        L_80039418
    if (!c1cs) {
        // 0x80039408: nop
    
            goto L_80039418;
    }
    // 0x80039408: nop

    // 0x8003940C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039410: nop

    // 0x80039414: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
L_80039418:
    // 0x80039418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003941C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039420: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80039424: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80039428: jal         0x8001BAFC
    // 0x8003942C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x8003942C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80039430: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80039434: beq         $v0, $zero, L_8003949C
    if (ctx->r2 == 0) {
        // 0x80039438: sw          $v0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r2;
            goto L_8003949C;
    }
    // 0x80039438: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8003943C: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x80039440: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80039444: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80039448: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003944C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80039450: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039454: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80039458: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003945C: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80039460: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80039464: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039468: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8003946C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039470: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80039474: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80039478: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x8003947C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80039480: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80039484: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80039488: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    // 0x8003948C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80039490: jal         0x800CA030
    // 0x80039494: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80039494: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_2:
    // 0x80039498: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
L_8003949C:
    // 0x8003949C: jal         0x8006A794
    // 0x800394A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x800394A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800394A4: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x800394A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800394AC: bne         $t9, $zero, L_800395A0
    if (ctx->r25 != 0) {
        // 0x800394B0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800395A0;
    }
    // 0x800394B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800394B4: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800394B8: lwc1        $f17, 0x65F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X65F8);
    // 0x800394BC: lwc1        $f16, 0x65FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X65FC);
    // 0x800394C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800394C4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800394C8: nop

    // 0x800394CC: bc1f        L_800395A0
    if (!c1cs) {
        // 0x800394D0: nop
    
            goto L_800395A0;
    }
    // 0x800394D0: nop

    // 0x800394D4: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x800394D8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800394DC: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800394E0: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x800394E4: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800394E8: beq         $t1, $zero, L_80039500
    if (ctx->r9 == 0) {
        // 0x800394EC: nop
    
            goto L_80039500;
    }
    // 0x800394EC: nop

    // 0x800394F0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800394F4: nop

    // 0x800394F8: beq         $t2, $t3, L_80039508
    if (ctx->r10 == ctx->r11) {
        // 0x800394FC: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_80039508;
    }
    // 0x800394FC: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_80039500:
    // 0x80039500: beq         $t4, $zero, L_800395A0
    if (ctx->r12 == 0) {
        // 0x80039504: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_800395A0;
    }
    // 0x80039504: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_80039508:
    // 0x80039508: beq         $t5, $zero, L_8003952C
    if (ctx->r13 == 0) {
        // 0x8003950C: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_8003952C;
    }
    // 0x8003950C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80039510: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80039514: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80039518: jal         0x80056970
    // 0x8003951C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    play_char_horn_sound(rdram, ctx);
        goto after_4;
    // 0x8003951C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_4:
    // 0x80039520: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039524: nop

    // 0x80039528: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_8003952C:
    // 0x8003952C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80039530: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039534: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80039538: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8003953C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x80039540: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80039544: jal         0x80070990
    // 0x80039548: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    arctan2_f(rdram, ctx);
        goto after_5;
    // 0x80039548: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    after_5:
    // 0x8003954C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80039550: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039554: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80039558: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8003955C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80039560: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039564: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039568: bne         $at, $zero, L_8003957C
    if (ctx->r1 != 0) {
        // 0x8003956C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8003957C;
    }
    // 0x8003956C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039570: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80039574: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80039578: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8003957C:
    // 0x8003957C: beq         $at, $zero, L_8003958C
    if (ctx->r1 == 0) {
        // 0x80039580: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_8003958C;
    }
    // 0x80039580: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80039584: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80039588: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
L_8003958C:
    // 0x8003958C: bne         $at, $zero, L_800395A0
    if (ctx->r1 != 0) {
        // 0x80039590: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_800395A0;
    }
    // 0x80039590: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80039594: beq         $at, $zero, L_800395A0
    if (ctx->r1 == 0) {
        // 0x80039598: nop
    
            goto L_800395A0;
    }
    // 0x80039598: nop

    // 0x8003959C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800395A0:
    // 0x800395A0: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800395A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800395A8: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x800395AC: jal         0x800521C8
    // 0x800395B0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    should_taj_teleport(rdram, ctx);
        goto after_6;
    // 0x800395B0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_6:
    // 0x800395B4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800395B8: bne         $v0, $zero, L_800395C8
    if (ctx->r2 != 0) {
        // 0x800395BC: nop
    
            goto L_800395C8;
    }
    // 0x800395BC: nop

    // 0x800395C0: beq         $a2, $zero, L_800396E0
    if (ctx->r6 == 0) {
        // 0x800395C4: nop
    
            goto L_800396E0;
    }
    // 0x800395C4: nop

L_800395C8:
    // 0x800395C8: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800395CC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800395D0: beq         $v0, $zero, L_800395E0
    if (ctx->r2 == 0) {
        // 0x800395D4: nop
    
            goto L_800395E0;
    }
    // 0x800395D4: nop

    // 0x800395D8: bne         $v0, $at, L_800396E0
    if (ctx->r2 != ctx->r1) {
        // 0x800395DC: nop
    
            goto L_800396E0;
    }
    // 0x800395DC: nop

L_800395E0:
    // 0x800395E0: jal         0x800012E8
    // 0x800395E4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    music_channel_reset_all(rdram, ctx);
        goto after_7;
    // 0x800395E4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_7:
    // 0x800395E8: jal         0x80000BE0
    // 0x800395EC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_8;
    // 0x800395EC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x800395F0: jal         0x80000B34
    // 0x800395F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800395F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_9:
    // 0x800395F8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800395FC: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039600: beq         $t2, $zero, L_8003961C
    if (ctx->r10 == 0) {
        // 0x80039604: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_8003961C;
    }
    // 0x80039604: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80039608: jal         0x80006AC8
    // 0x8003960C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x8003960C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_10:
    // 0x80039610: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80039614: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039618: sw          $zero, 0x118($t3)
    MEM_W(0X118, ctx->r11) = 0;
L_8003961C:
    // 0x8003961C: jal         0x80008140
    // 0x80039620: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    audspat_jingle_off(rdram, ctx);
        goto after_11;
    // 0x80039620: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_11:
    // 0x80039624: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x80039628: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003962C: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039630: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80039634: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80039638: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8003963C: jal         0x80070990
    // 0x80039640: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x80039640: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_12:
    // 0x80039644: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80039648: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003964C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80039650: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039654: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80039658: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8003965C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039660: bne         $at, $zero, L_80039668
    if (ctx->r1 != 0) {
        // 0x80039664: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80039668;
    }
    // 0x80039664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80039668:
    // 0x80039668: beq         $a2, $zero, L_8003967C
    if (ctx->r6 == 0) {
        // 0x8003966C: addiu       $a1, $s1, 0x20
        ctx->r5 = ADD32(ctx->r17, 0X20);
            goto L_8003967C;
    }
    // 0x8003966C: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x80039670: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039674: b           L_8003968C
    // 0x80039678: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003968C;
    // 0x80039678: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003967C:
    // 0x8003967C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80039680: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039684: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039688: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
L_8003968C:
    // 0x8003968C: addiu       $t0, $s1, 0x12
    ctx->r8 = ADD32(ctx->r17, 0X12);
    // 0x80039690: addiu       $t1, $s1, 0x13
    ctx->r9 = ADD32(ctx->r17, 0X13);
    // 0x80039694: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80039698: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003969C: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x800396A0: jal         0x80030790
    // 0x800396A4: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_13;
    // 0x800396A4: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_13:
    // 0x800396A8: addiu       $t2, $zero, 0x3C0
    ctx->r10 = ADD32(0, 0X3C0);
    // 0x800396AC: addiu       $t3, $zero, 0x44C
    ctx->r11 = ADD32(0, 0X44C);
    // 0x800396B0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x800396B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800396B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800396BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800396C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800396C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800396C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800396CC: jal         0x80030E20
    // 0x800396D0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x800396D0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_14:
    // 0x800396D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800396D8: nop

    // 0x800396DC: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_800396E0:
    // 0x800396E0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800396E4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800396E8: beq         $v0, $zero, L_80039724
    if (ctx->r2 == 0) {
        // 0x800396EC: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80039724;
    }
    // 0x800396EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800396F0: beq         $v0, $at, L_80039720
    if (ctx->r2 == ctx->r1) {
        // 0x800396F4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80039720;
    }
    // 0x800396F4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800396F8: beq         $v0, $at, L_80039720
    if (ctx->r2 == ctx->r1) {
        // 0x800396FC: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80039720;
    }
    // 0x800396FC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80039700: beq         $v0, $at, L_80039724
    if (ctx->r2 == ctx->r1) {
        // 0x80039704: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80039724;
    }
    // 0x80039704: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039708: jal         0x8005A41C
    // 0x8003970C: nop

    disable_racer_input(rdram, ctx);
        goto after_15;
    // 0x8003970C: nop

    after_15:
    // 0x80039710: jal         0x800AB6F0
    // 0x80039714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_16;
    // 0x80039714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80039718: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003971C: nop

L_80039720:
    // 0x80039720: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80039724:
    // 0x80039724: beq         $v0, $a3, L_80039744
    if (ctx->r2 == ctx->r7) {
        // 0x80039728: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039744;
    }
    // 0x80039728: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003972C: beq         $v0, $at, L_80039744
    if (ctx->r2 == ctx->r1) {
        // 0x80039730: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80039744;
    }
    // 0x80039730: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80039734: beq         $v0, $at, L_80039744
    if (ctx->r2 == ctx->r1) {
        // 0x80039738: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80039744;
    }
    // 0x80039738: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003973C: bne         $v0, $at, L_80039758
    if (ctx->r2 != ctx->r1) {
        // 0x80039740: nop
    
            goto L_80039758;
    }
    // 0x80039740: nop

L_80039744:
    // 0x80039744: jal         0x8009D530
    // 0x80039748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    npc_dialogue_loop(rdram, ctx);
        goto after_17;
    // 0x80039748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8003974C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039750: b           L_80039768
    // 0x80039754: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
        goto L_80039768;
    // 0x80039754: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_80039758:
    // 0x80039758: jal         0x8009D4AC
    // 0x8003975C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_18;
    // 0x8003975C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x80039760: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039764: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_80039768:
    // 0x80039768: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003976C: nop

    // 0x80039770: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80039774: sltiu       $at, $t5, 0x15
    ctx->r1 = ctx->r13 < 0X15 ? 1 : 0;
    // 0x80039778: beq         $at, $zero, L_800397A8
    if (ctx->r1 == 0) {
        // 0x8003977C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800397A8;
    }
    // 0x8003977C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80039780: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039784: addu        $at, $at, $t5
    gpr jr_addend_80039790 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80039788: lw          $t5, 0x6600($at)
    ctx->r13 = ADD32(ctx->r1, 0X6600);
    // 0x8003978C: nop

    // 0x80039790: jr          $t5
    // 0x80039794: nop

    switch (jr_addend_80039790 >> 2) {
        case 0: goto L_80039798; break;
        case 1: goto L_80039798; break;
        case 2: goto L_80039798; break;
        case 3: goto L_80039798; break;
        case 4: goto L_800397A8; break;
        case 5: goto L_800397A8; break;
        case 6: goto L_80039798; break;
        case 7: goto L_800397A8; break;
        case 8: goto L_800397A8; break;
        case 9: goto L_80039798; break;
        case 10: goto L_80039798; break;
        case 11: goto L_800397A8; break;
        case 12: goto L_800397A8; break;
        case 13: goto L_800397A8; break;
        case 14: goto L_80039798; break;
        case 15: goto L_800397A8; break;
        case 16: goto L_800397A8; break;
        case 17: goto L_800397A8; break;
        case 18: goto L_800397A8; break;
        case 19: goto L_80039798; break;
        case 20: goto L_80039798; break;
        default: switch_error(__func__, 0x80039790, 0x800E6600);
    }
    // 0x80039794: nop

L_80039798:
    // 0x80039798: jal         0x8006F5C8
    // 0x8003979C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_19;
    // 0x8003979C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800397A0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800397A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800397A8:
    // 0x800397A8: beq         $v0, $zero, L_800397D4
    if (ctx->r2 == 0) {
        // 0x800397AC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397AC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397B0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800397B4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800397B8: beq         $t6, $zero, L_800397D4
    if (ctx->r14 == 0) {
        // 0x800397BC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397BC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397C0: beq         $at, $zero, L_800397D4
    if (ctx->r1 == 0) {
        // 0x800397C4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397C4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397C8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800397CC: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x800397D0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800397D4:
    // 0x800397D4: sltiu       $at, $t7, 0x1E
    ctx->r1 = ctx->r15 < 0X1E ? 1 : 0;
    // 0x800397D8: beq         $at, $zero, L_8003A5EC
    if (ctx->r1 == 0) {
        // 0x800397DC: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_8003A5EC;
    }
    // 0x800397DC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800397E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800397E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800397E8: addu        $at, $at, $t7
    gpr jr_addend_800397F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800397EC: lw          $t7, 0x6654($at)
    ctx->r15 = ADD32(ctx->r1, 0X6654);
    // 0x800397F0: nop

    // 0x800397F4: jr          $t7
    // 0x800397F8: nop

    switch (jr_addend_800397F4 >> 2) {
        case 0: goto L_800397FC; break;
        case 1: goto L_800399B8; break;
        case 2: goto L_80039B20; break;
        case 3: goto L_80039BF8; break;
        case 4: goto L_80039E04; break;
        case 5: goto L_80039F18; break;
        case 6: goto L_8003A01C; break;
        case 7: goto L_8003A01C; break;
        case 8: goto L_8003A5EC; break;
        case 9: goto L_8003A10C; break;
        case 10: goto L_8003A228; break;
        case 11: goto L_8003A5EC; break;
        case 12: goto L_8003A5EC; break;
        case 13: goto L_8003A5EC; break;
        case 14: goto L_8003A2A8; break;
        case 15: goto L_8003A5EC; break;
        case 16: goto L_8003A5EC; break;
        case 17: goto L_8003A5EC; break;
        case 18: goto L_8003A5EC; break;
        case 19: goto L_8003A43C; break;
        case 20: goto L_8003A534; break;
        case 21: goto L_8003A5EC; break;
        case 22: goto L_8003A5EC; break;
        case 23: goto L_8003A5EC; break;
        case 24: goto L_8003A5EC; break;
        case 25: goto L_8003A5EC; break;
        case 26: goto L_8003A5EC; break;
        case 27: goto L_8003A5EC; break;
        case 28: goto L_8003A5EC; break;
        case 29: goto L_8003A5B4; break;
        default: switch_error(__func__, 0x800397F4, 0x800E6654);
    }
    // 0x800397F8: nop

L_800397FC:
    // 0x800397FC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039800: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80039804: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80039808: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003980C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80039810: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80039814: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80039818: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003981C: bc1f        L_80039840
    if (!c1cs) {
        // 0x80039820: sb          $t8, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r24;
            goto L_80039840;
    }
    // 0x80039820: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x80039824: swc1        $f1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x80039828: jal         0x8005A42C
    // 0x8003982C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_20;
    // 0x8003982C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80039830: lwc1        $f1, 0x40($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80039834: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80039838: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003983C: nop

L_80039840:
    // 0x80039840: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80039844: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80039848: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003984C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039850: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80039854: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039858: bc1f        L_80039974
    if (!c1cs) {
        // 0x8003985C: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80039974;
    }
    // 0x8003985C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80039860: nop

    // 0x80039864: div.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80039868: jal         0x80070990
    // 0x8003986C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    arctan2_f(rdram, ctx);
        goto after_21;
    // 0x8003986C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    after_21:
    // 0x80039870: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039874: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039878: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8003987C: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039880: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039884: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039888: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003988C: bne         $at, $zero, L_8003989C
    if (ctx->r1 != 0) {
        // 0x80039890: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003989C;
    }
    // 0x80039890: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039894: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039898: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003989C:
    // 0x8003989C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800398A0: beq         $at, $zero, L_800398AC
    if (ctx->r1 == 0) {
        // 0x800398A4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800398AC;
    }
    // 0x800398A4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800398A8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800398AC:
    // 0x800398AC: blez        $v1, L_800398C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800398B0: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800398C0;
    }
    // 0x800398B0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800398B4: beq         $at, $zero, L_800398C4
    if (ctx->r1 == 0) {
        // 0x800398B8: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_800398C4;
    }
    // 0x800398B8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800398BC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800398C0:
    // 0x800398C0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_800398C4:
    // 0x800398C4: sra         $t0, $v1, 4
    ctx->r8 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800398C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800398CC: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800398D0: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x800398D4: beq         $at, $zero, L_800398E4
    if (ctx->r1 == 0) {
        // 0x800398D8: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_800398E4;
    }
    // 0x800398D8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x800398DC: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x800398E0: beq         $at, $zero, L_800398F0
    if (ctx->r1 == 0) {
        // 0x800398E4: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_800398F0;
    }
L_800398E4:
    // 0x800398E4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x800398E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800398EC: nop

L_800398F0:
    // 0x800398F0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800398F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800398F8: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800398FC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80039900: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039904: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80039908: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8003990C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80039910: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x80039914: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039918: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8003991C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80039920: jal         0x80070A04
    // 0x80039924: nop

    sins_f(rdram, ctx);
        goto after_22;
    // 0x80039924: nop

    after_22:
    // 0x80039928: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003992C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80039930: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80039934: jal         0x80070A38
    // 0x80039938: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    coss_f(rdram, ctx);
        goto after_23;
    // 0x80039938: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    after_23:
    // 0x8003993C: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039940: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039944: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80039948: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003994C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039950: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80039954: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039958: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003995C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80039960: nop

    // 0x80039964: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039968: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003996C: b           L_80039980
    // 0x80039970: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
        goto L_80039980;
    // 0x80039970: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
L_80039974:
    // 0x80039974: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x80039978: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003997C: nop

L_80039980:
    // 0x80039980: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80039984: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80039988: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003998C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80039990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039994: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039998: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003999C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800399A0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800399A4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800399A8: jal         0x80011570
    // 0x800399AC: nop

    move_object(rdram, ctx);
        goto after_24;
    // 0x800399AC: nop

    after_24:
    // 0x800399B0: b           L_8003AB44
    // 0x800399B4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x800399B4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_800399B8:
    // 0x800399B8: jal         0x8005A42C
    // 0x800399BC: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_25;
    // 0x800399BC: nop

    after_25:
    // 0x800399C0: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800399C4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x800399C8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800399CC: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x800399D0: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800399D4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800399D8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800399DC: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x800399E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800399E4: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800399E8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800399EC: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800399F0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800399F4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800399F8: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x800399FC: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x80039A00: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039A04: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039A08: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039A0C: bne         $at, $zero, L_80039A1C
    if (ctx->r1 != 0) {
        // 0x80039A10: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80039A1C;
    }
    // 0x80039A10: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039A14: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039A18: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039A1C:
    // 0x80039A1C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039A20: beq         $at, $zero, L_80039A2C
    if (ctx->r1 == 0) {
        // 0x80039A24: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80039A2C;
    }
    // 0x80039A24: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039A28: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039A2C:
    // 0x80039A2C: blez        $v1, L_80039A40
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039A30: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039A40;
    }
    // 0x80039A30: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039A34: beq         $at, $zero, L_80039A44
    if (ctx->r1 == 0) {
        // 0x80039A38: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80039A44;
    }
    // 0x80039A38: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80039A3C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039A40:
    // 0x80039A40: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
L_80039A44:
    // 0x80039A44: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80039A48: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80039A4C: beq         $at, $zero, L_80039AAC
    if (ctx->r1 == 0) {
        // 0x80039A50: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_80039AAC;
    }
    // 0x80039A50: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80039A54: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80039A58: bne         $at, $zero, L_80039AAC
    if (ctx->r1 != 0) {
        // 0x80039A5C: nop
    
            goto L_80039AAC;
    }
    // 0x80039A5C: nop

    // 0x80039A60: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039A64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80039A68: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039A6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039A70: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039A74: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80039A78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80039A7C: bc1f        L_80039AAC
    if (!c1cs) {
        // 0x80039A80: nop
    
            goto L_80039AAC;
    }
    // 0x80039A80: nop

    // 0x80039A84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039A88: sw          $a3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r7;
    // 0x80039A8C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039A90: lhu         $a0, -0x259E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X259E);
    // 0x80039A94: jal         0x8003AC7C
    // 0x80039A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x80039A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80039A9C: addiu       $t8, $zero, 0x10F
    ctx->r24 = ADD32(0, 0X10F);
    // 0x80039AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039AA4: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039AA8: sh          $t8, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r24;
L_80039AAC:
    // 0x80039AAC: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039AB0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80039AB4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80039AB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039ABC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039AC0: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80039AC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80039AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039ACC: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80039AD0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80039AD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039AD8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80039ADC: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039AE0: nop

    // 0x80039AE4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039AE8: mul.d       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x80039AEC: nop

    // 0x80039AF0: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80039AF4: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80039AF8: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80039AFC: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80039B00: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80039B04: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80039B08: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80039B0C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80039B10: jal         0x80011570
    // 0x80039B14: nop

    move_object(rdram, ctx);
        goto after_27;
    // 0x80039B14: nop

    after_27:
    // 0x80039B18: b           L_8003AB44
    // 0x80039B1C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039B1C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039B20:
    // 0x80039B20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039B24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039B28: sb          $t9, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r25;
    // 0x80039B2C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80039B30: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039B34: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039B38: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039B3C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039B40: add.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d + ctx->f16.d;
    // 0x80039B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039B48: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80039B4C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039B50: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039B54: lwc1        $f18, 0x66D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X66D4);
    // 0x80039B58: lwc1        $f19, 0x66D0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X66D0);
    // 0x80039B5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80039B60: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80039B64: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x80039B68: bc1f        L_80039B8C
    if (!c1cs) {
        // 0x80039B6C: lw          $t0, 0x90($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X90);
            goto L_80039B8C;
    }
    // 0x80039B6C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80039B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039B74: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80039B78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039B7C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039B80: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x80039B84: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x80039B88: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
L_80039B8C:
    // 0x80039B8C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039B90: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80039B94: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x80039B98: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039B9C: subu        $v1, $t1, $t2
    ctx->r3 = SUB32(ctx->r9, ctx->r10);
    // 0x80039BA0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039BA4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039BA8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039BAC: bne         $at, $zero, L_80039BBC
    if (ctx->r1 != 0) {
        // 0x80039BB0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80039BBC;
    }
    // 0x80039BB0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039BB4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039BB8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039BBC:
    // 0x80039BBC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039BC0: beq         $at, $zero, L_80039BCC
    if (ctx->r1 == 0) {
        // 0x80039BC4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80039BCC;
    }
    // 0x80039BC4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039BC8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039BCC:
    // 0x80039BCC: blez        $v1, L_80039BE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039BD0: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039BE0;
    }
    // 0x80039BD0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039BD4: beq         $at, $zero, L_80039BE4
    if (ctx->r1 == 0) {
        // 0x80039BD8: sra         $t3, $v1, 4
        ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
            goto L_80039BE4;
    }
    // 0x80039BD8: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80039BDC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039BE0:
    // 0x80039BE0: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
L_80039BE4:
    // 0x80039BE4: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80039BE8: jal         0x8005A42C
    // 0x80039BEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_28;
    // 0x80039BEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    after_28:
    // 0x80039BF0: b           L_8003AB44
    // 0x80039BF4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039BF4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039BF8:
    // 0x80039BF8: sb          $v1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r3;
    // 0x80039BFC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039C00: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039C04: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80039C08: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039C0C: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x80039C10: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039C14: jal         0x8005A42C
    // 0x80039C18: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_29;
    // 0x80039C18: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    after_29:
    // 0x80039C1C: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039C20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039C24: beq         $a2, $a3, L_80039C30
    if (ctx->r6 == ctx->r7) {
        // 0x80039C28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039C30;
    }
    // 0x80039C28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039C2C: bne         $a2, $at, L_80039CE8
    if (ctx->r6 != ctx->r1) {
        // 0x80039C30: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039CE8;
    }
L_80039C30:
    // 0x80039C30: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039C34: bne         $a2, $at, L_80039C48
    if (ctx->r6 != ctx->r1) {
        // 0x80039C38: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80039C48;
    }
    // 0x80039C38: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80039C3C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80039C40: b           L_80039C50
    // 0x80039C44: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
        goto L_80039C50;
    // 0x80039C44: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_80039C48:
    // 0x80039C48: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80039C4C: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
L_80039C50:
    // 0x80039C50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039C54: lwc1        $f10, 0x66D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66D8);
    // 0x80039C58: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    // 0x80039C5C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039C60: sb          $t7, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r15;
    // 0x80039C64: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x80039C68: jal         0x8003AC7C
    // 0x80039C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x80039C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80039C70: lh          $t8, 0x20($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X20);
    // 0x80039C74: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80039C78: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x80039C7C: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80039C80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80039C84: lh          $t9, 0x22($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X22);
    // 0x80039C88: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x80039C8C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80039C90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039C94: jal         0x80030E20
    // 0x80039C98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    slowly_change_fog(rdram, ctx);
        goto after_31;
    // 0x80039C98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_31:
    // 0x80039C9C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80039CA0: nop

    // 0x80039CA4: lbu         $a0, 0xB3($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XB3);
    // 0x80039CA8: jal         0x80000BE0
    // 0x80039CAC: nop

    music_voicelimit_set(rdram, ctx);
        goto after_32;
    // 0x80039CAC: nop

    after_32:
    // 0x80039CB0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80039CB4: nop

    // 0x80039CB8: lbu         $a0, 0x52($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X52);
    // 0x80039CBC: jal         0x80000B34
    // 0x80039CC0: nop

    music_play(rdram, ctx);
        goto after_33;
    // 0x80039CC0: nop

    after_33:
    // 0x80039CC4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80039CC8: nop

    // 0x80039CCC: lhu         $a0, 0x54($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X54);
    // 0x80039CD0: jal         0x80001074
    // 0x80039CD4: nop

    music_dynamic_set(rdram, ctx);
        goto after_34;
    // 0x80039CD4: nop

    after_34:
    // 0x80039CD8: jal         0x80008168
    // 0x80039CDC: nop

    audspat_jingle_on(rdram, ctx);
        goto after_35;
    // 0x80039CDC: nop

    after_35:
    // 0x80039CE0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039CE4: nop

L_80039CE8:
    // 0x80039CE8: andi        $t4, $a2, 0x80
    ctx->r12 = ctx->r6 & 0X80;
    // 0x80039CEC: beq         $t4, $zero, L_80039D60
    if (ctx->r12 == 0) {
        // 0x80039CF0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039D60;
    }
    // 0x80039CF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039CF4: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039CF8: andi        $t5, $a2, 0x7F
    ctx->r13 = ctx->r6 & 0X7F;
    // 0x80039CFC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80039D00: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80039D04: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x80039D08: lb          $t7, 0x1D6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1D6);
    // 0x80039D0C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80039D10: beq         $t7, $t8, L_80039D50
    if (ctx->r15 == ctx->r24) {
        // 0x80039D14: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_80039D50;
    }
    // 0x80039D14: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039D18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039D1C: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80039D20: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x80039D24: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80039D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039D2C: lb          $a0, 0x1D6($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X1D6);
    // 0x80039D30: nop

    // 0x80039D34: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039D38: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x80039D3C: jal         0x8003AC7C
    // 0x80039D40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_36;
    // 0x80039D40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_36:
    // 0x80039D44: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D48: b           L_80039D60
    // 0x80039D4C: nop

        goto L_80039D60;
    // 0x80039D4C: nop

L_80039D50:
    // 0x80039D50: jal         0x8009D880
    // 0x80039D54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_37;
    // 0x80039D54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80039D58: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D5C: nop

L_80039D60:
    // 0x80039D60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039D64: andi        $t2, $a2, 0x40
    ctx->r10 = ctx->r6 & 0X40;
    // 0x80039D68: beq         $t2, $zero, L_80039DFC
    if (ctx->r10 == 0) {
        // 0x80039D6C: addiu       $v1, $v1, -0x25A0
        ctx->r3 = ADD32(ctx->r3, -0X25A0);
            goto L_80039DFC;
    }
    // 0x80039D6C: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039D70: andi        $t3, $a2, 0xF
    ctx->r11 = ctx->r6 & 0XF;
    // 0x80039D74: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80039D78: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80039D7C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80039D80: lb          $t5, 0x1D6($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D6);
    // 0x80039D84: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80039D88: beq         $t5, $v0, L_80039DD0
    if (ctx->r13 == ctx->r2) {
        // 0x80039D8C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80039DD0;
    }
    // 0x80039D8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039D90: ori         $t6, $v0, 0x80
    ctx->r14 = ctx->r2 | 0X80;
    // 0x80039D94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039D98: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80039D9C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80039DA0: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039DA4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80039DA8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80039DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039DB0: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x80039DB4: nop

    // 0x80039DB8: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039DBC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x80039DC0: jal         0x8003AC7C
    // 0x80039DC4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_38;
    // 0x80039DC4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_38:
    // 0x80039DC8: b           L_8003AB44
    // 0x80039DCC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039DCC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039DD0:
    // 0x80039DD0: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x80039DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80039DD8: sb          $t1, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r9;
    // 0x80039DDC: jal         0x800C06F8
    // 0x80039DE0: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    transition_begin(rdram, ctx);
        goto after_39;
    // 0x80039DE0: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    after_39:
    // 0x80039DE4: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039DE8: jal         0x8003AC7C
    // 0x80039DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_40;
    // 0x80039DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80039DF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039DF4: nop

    // 0x80039DF8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80039DFC:
    // 0x80039DFC: b           L_8003AB44
    // 0x80039E00: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039E00: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039E04:
    // 0x80039E04: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80039E08: jal         0x8005A42C
    // 0x80039E0C: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_41;
    // 0x80039E0C: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    after_41:
    // 0x80039E10: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039E14: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E18: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80039E1C: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x80039E20: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80039E24: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039E28: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039E2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039E30: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039E34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039E38: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039E3C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E40: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80039E44: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x80039E48: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80039E4C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039E50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039E54: bc1f        L_80039E70
    if (!c1cs) {
        // 0x80039E58: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_80039E70;
    }
    // 0x80039E58: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80039E5C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80039E60: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80039E64: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E68: nop

    // 0x80039E6C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
L_80039E70:
    // 0x80039E70: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80039E74: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80039E78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039E7C: bc1f        L_80039E94
    if (!c1cs) {
        // 0x80039E80: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80039E94;
    }
    // 0x80039E80: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80039E84: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x80039E88: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E8C: nop

    // 0x80039E90: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
L_80039E94:
    // 0x80039E94: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80039E98: nop

    // 0x80039E9C: bc1f        L_80039F10
    if (!c1cs) {
        // 0x80039EA0: nop
    
            goto L_80039F10;
    }
    // 0x80039EA0: nop

    // 0x80039EA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039EA8: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80039EAC: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039EB0: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x80039EB4: lbu         $v0, 0x1F7($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1F7);
    // 0x80039EB8: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80039EBC: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039EC0: beq         $at, $zero, L_80039ED4
    if (ctx->r1 == 0) {
        // 0x80039EC4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039ED4;
    }
    // 0x80039EC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039EC8: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80039ECC: b           L_8003AB40
    // 0x80039ED0: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
        goto L_8003AB40;
    // 0x80039ED0: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
L_80039ED4:
    // 0x80039ED4: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039ED8: sb          $zero, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = 0;
    // 0x80039EDC: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80039EE0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80039EE4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x80039EE8: jal         0x8000E1EC
    // 0x80039EEC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    despawn_player_racer(rdram, ctx);
        goto after_42;
    // 0x80039EEC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_42:
    // 0x80039EF0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80039EF4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039EF8: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    // 0x80039EFC: jal         0x80001D04
    // 0x80039F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_43;
    // 0x80039F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80039F04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039F08: jal         0x800C06F8
    // 0x80039F0C: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    transition_begin(rdram, ctx);
        goto after_44;
    // 0x80039F0C: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    after_44:
L_80039F10:
    // 0x80039F10: b           L_8003AB44
    // 0x80039F14: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039F14: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039F18:
    // 0x80039F18: jal         0x8005A42C
    // 0x80039F1C: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_45;
    // 0x80039F1C: nop

    after_45:
    // 0x80039F20: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80039F24: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80039F28: beq         $t8, $zero, L_8003A014
    if (ctx->r24 == 0) {
        // 0x80039F2C: nop
    
            goto L_8003A014;
    }
    // 0x80039F2C: nop

    // 0x80039F30: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039F34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039F38: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80039F3C: c.eq.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl == ctx->f12.fl;
    // 0x80039F40: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80039F44: bc1t        L_80039F68
    if (c1cs) {
        // 0x80039F48: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_80039F68;
    }
    // 0x80039F48: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x80039F4C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039F50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039F54: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80039F58: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039F5C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039F60: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039F64: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_80039F68:
    // 0x80039F68: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80039F6C: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80039F70: bne         $at, $zero, L_80039F7C
    if (ctx->r1 != 0) {
        // 0x80039F74: nop
    
            goto L_80039F7C;
    }
    // 0x80039F74: nop

    // 0x80039F78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80039F7C:
    // 0x80039F7C: lbu         $v0, 0x1F7($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F7);
    // 0x80039F80: sll         $t0, $a2, 5
    ctx->r8 = S32(ctx->r6 << 5);
    // 0x80039F84: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80039F88: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80039F8C: beq         $at, $zero, L_80039F9C
    if (ctx->r1 == 0) {
        // 0x80039F90: addu        $t3, $v0, $t0
        ctx->r11 = ADD32(ctx->r2, ctx->r8);
            goto L_80039F9C;
    }
    // 0x80039F90: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80039F94: b           L_8003AB40
    // 0x80039F98: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
        goto L_8003AB40;
    // 0x80039F98: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
L_80039F9C:
    // 0x80039F9C: sb          $t4, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r12;
    // 0x80039FA0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039FA4: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80039FA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039FAC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80039FB0: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80039FB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039FB8: bc1f        L_8003A014
    if (!c1cs) {
        // 0x80039FBC: addiu       $v1, $v1, -0x25A0
        ctx->r3 = ADD32(ctx->r3, -0X25A0);
            goto L_8003A014;
    }
    // 0x80039FBC: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039FC0: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x80039FC4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80039FC8: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80039FCC: beq         $t6, $zero, L_8003A008
    if (ctx->r14 == 0) {
        // 0x80039FD0: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_8003A008;
    }
    // 0x80039FD0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039FD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039FD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039FDC: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    // 0x80039FE0: jal         0x800C06F8
    // 0x80039FE4: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    transition_begin(rdram, ctx);
        goto after_46;
    // 0x80039FE4: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    after_46:
    // 0x80039FE8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80039FEC: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039FF0: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039FF4: jal         0x80001D04
    // 0x80039FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_47;
    // 0x80039FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80039FFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A000: b           L_8003AB40
    // 0x8003A004: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB40;
    // 0x8003A004: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8003A008:
    // 0x8003A008: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x8003A00C: jal         0x8009D880
    // 0x8003A010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_48;
    // 0x8003A010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
L_8003A014:
    // 0x8003A014: b           L_8003AB44
    // 0x8003A018: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A018: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A01C:
    // 0x8003A01C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A020: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8003A024: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A028: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8003A02C: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x8003A030: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A034: bc1t        L_8003A060
    if (c1cs) {
        // 0x8003A038: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003A060;
    }
    // 0x8003A038: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003A03C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003A040: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A044: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A048: mul.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8003A04C: add.d       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f2.d + ctx->f16.d;
    // 0x8003A050: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A054: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A058: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A05C: nop

L_8003A060:
    // 0x8003A060: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A064: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003A068: c.eq.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl == ctx->f12.fl;
    // 0x8003A06C: nop

    // 0x8003A070: bc1f        L_8003AB40
    if (!c1cs) {
        // 0x8003A074: nop
    
            goto L_8003AB40;
    }
    // 0x8003A074: nop

    // 0x8003A078: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    // 0x8003A07C: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x8003A080: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003A084: bne         $t1, $at, L_8003A0D8
    if (ctx->r9 != ctx->r1) {
        // 0x8003A088: addiu       $t2, $zero, 0x14
        ctx->r10 = ADD32(0, 0X14);
            goto L_8003A0D8;
    }
    // 0x8003A088: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8003A08C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A090: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003A094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A098: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A09C: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A0A0: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8003A0A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A0A8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A0AC: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003A0B0: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8003A0B4: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8003A0B8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A0BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003A0C0: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A0C4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003A0C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003A0CC: jal         0x80022D30
    // 0x8003A0D0: nop

    obj_taj_create_balloon(rdram, ctx);
        goto after_49;
    // 0x8003A0D0: nop

    after_49:
    // 0x8003A0D4: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
L_8003A0D8:
    // 0x8003A0D8: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x8003A0DC: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A0E0: jal         0x80001D04
    // 0x8003A0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_50;
    // 0x8003A0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x8003A0E8: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A0EC: nop

    // 0x8003A0F0: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A0F4: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A0F8: jal         0x80004B40
    // 0x8003A0FC: nop

    racer_sound_init(rdram, ctx);
        goto after_51;
    // 0x8003A0FC: nop

    after_51:
    // 0x8003A100: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8003A104: b           L_8003AB40
    // 0x8003A108: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
        goto L_8003AB40;
    // 0x8003A108: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
L_8003A10C:
    // 0x8003A10C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A110: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A114: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A118: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A11C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x8003A120: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A124: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A128: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A12C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A130: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A134: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003A138: add.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d + ctx->f6.d;
    // 0x8003A13C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A140: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A144: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A148: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A14C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A150: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A154: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A158: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A15C: bc1f        L_8003A170
    if (!c1cs) {
        // 0x8003A160: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003A170;
    }
    // 0x8003A160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003A164: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A168: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A16C: nop

L_8003A170:
    // 0x8003A170: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A174: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A178: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A17C: bc1f        L_8003A188
    if (!c1cs) {
        // 0x8003A180: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A188;
    }
    // 0x8003A180: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A188:
    // 0x8003A188: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A18C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A190: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A194: beq         $at, $zero, L_8003A1A4
    if (ctx->r1 == 0) {
        // 0x8003A198: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A1A4;
    }
    // 0x8003A198: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A19C: b           L_8003AB40
    // 0x8003A1A0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB40;
    // 0x8003A1A0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A1A4:
    // 0x8003A1A4: jal         0x80001D04
    // 0x8003A1A8: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_52;
    // 0x8003A1A8: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    after_52:
    // 0x8003A1AC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A1B0: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x8003A1B4: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8003A1B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8003A1BC: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A1C0: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003A1C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A1C8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A1CC: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003A1D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003A1D4: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A1D8: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003A1DC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A1E0: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A1E4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003A1E8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003A1EC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A1F0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003A1F4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8003A1F8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A1FC: jal         0x80029F58
    // 0x8003A200: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_53;
    // 0x8003A200: nop

    after_53:
    // 0x8003A204: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8003A208: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A20C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A210: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A214: nop

    // 0x8003A218: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A21C: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003A220: b           L_8003AB44
    // 0x8003A224: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A224: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A228:
    // 0x8003A228: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A22C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A230: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A234: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A238: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A23C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A240: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A244: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x8003A248: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A24C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A250: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A254: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A258: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A25C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A260: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003A264: nop

    // 0x8003A268: bc1f        L_8003A278
    if (!c1cs) {
        // 0x8003A26C: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A278;
    }
    // 0x8003A26C: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A270: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A274: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A278:
    // 0x8003A278: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A27C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A280: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A284: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A288: beq         $at, $zero, L_8003A298
    if (ctx->r1 == 0) {
        // 0x8003A28C: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A298;
    }
    // 0x8003A28C: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A290: b           L_8003AB40
    // 0x8003A294: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB40;
    // 0x8003A294: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A298:
    // 0x8003A298: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A29C: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x8003A2A0: b           L_8003AB44
    // 0x8003A2A4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A2A4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A2A8:
    // 0x8003A2A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003A2AC: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A2B0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003A2B4: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x8003A2B8: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x8003A2BC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A2C0: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2C4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A2C8: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A2CC: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A2D0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A2D4: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8003A2D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A2DC: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8003A2E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A2E4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8003A2E8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A2F0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A2F4: nop

    // 0x8003A2F8: bc1f        L_8003A310
    if (!c1cs) {
        // 0x8003A2FC: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A310;
    }
    // 0x8003A2FC: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A300: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A304: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A308: nop

    // 0x8003A30C: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A310:
    // 0x8003A310: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A314: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x8003A318: bc1f        L_8003A324
    if (!c1cs) {
        // 0x8003A31C: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8003A324;
    }
    // 0x8003A31C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8003A320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A324:
    // 0x8003A324: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A328: nop

    // 0x8003A32C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A330: beq         $at, $zero, L_8003A340
    if (ctx->r1 == 0) {
        // 0x8003A334: subu        $t0, $v0, $a2
        ctx->r8 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A340;
    }
    // 0x8003A334: subu        $t0, $v0, $a2
    ctx->r8 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A338: b           L_8003AB40
    // 0x8003A33C: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
        goto L_8003AB40;
    // 0x8003A33C: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
L_8003A340:
    // 0x8003A340: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A344: nop

    // 0x8003A348: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A34C: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A350: jal         0x80004B40
    // 0x8003A354: nop

    racer_sound_init(rdram, ctx);
        goto after_54;
    // 0x8003A354: nop

    after_54:
    // 0x8003A358: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8003A35C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8003A360: sw          $v0, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->r2;
    // 0x8003A364: lh          $t2, 0x20($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X20);
    // 0x8003A368: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x8003A36C: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x8003A370: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x8003A374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003A378: lh          $t3, 0x22($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X22);
    // 0x8003A37C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003A380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003A384: jal         0x80030E20
    // 0x8003A388: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    slowly_change_fog(rdram, ctx);
        goto after_55;
    // 0x8003A388: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_55:
    // 0x8003A38C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8003A390: nop

    // 0x8003A394: lbu         $a0, 0xB3($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0XB3);
    // 0x8003A398: jal         0x80000BE0
    // 0x8003A39C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_56;
    // 0x8003A39C: nop

    after_56:
    // 0x8003A3A0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003A3A4: nop

    // 0x8003A3A8: lbu         $a0, 0x52($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X52);
    // 0x8003A3AC: jal         0x80000B34
    // 0x8003A3B0: nop

    music_play(rdram, ctx);
        goto after_57;
    // 0x8003A3B0: nop

    after_57:
    // 0x8003A3B4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8003A3B8: nop

    // 0x8003A3BC: lhu         $a0, 0x54($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X54);
    // 0x8003A3C0: jal         0x80001074
    // 0x8003A3C4: nop

    music_dynamic_set(rdram, ctx);
        goto after_58;
    // 0x8003A3C4: nop

    after_58:
    // 0x8003A3C8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8003A3CC: nop

    // 0x8003A3D0: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x8003A3D4: jal         0x80022920
    // 0x8003A3D8: nop

    init_racer_for_challenge(rdram, ctx);
        goto after_59;
    // 0x8003A3D8: nop

    after_59:
    // 0x8003A3DC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A3E0: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A3E4: jal         0x80023460
    // 0x8003A3E8: nop

    find_furthest_telepoint(rdram, ctx);
        goto after_60;
    // 0x8003A3E8: nop

    after_60:
    // 0x8003A3EC: beq         $v0, $zero, L_8003A430
    if (ctx->r2 == 0) {
        // 0x8003A3F0: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_8003A430;
    }
    // 0x8003A3F0: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8003A3F4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A3F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A3FC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8003A400: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A404: nop

    // 0x8003A408: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003A40C: lh          $t9, 0x2E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A410: nop

    // 0x8003A414: sh          $t9, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r25;
    // 0x8003A418: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8003A41C: nop

    // 0x8003A420: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8003A424: nop

    // 0x8003A428: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8003A42C: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
L_8003A430:
    // 0x8003A430: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003A434: b           L_8003AB44
    // 0x8003A438: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A438: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A43C:
    // 0x8003A43C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A440: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A444: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A448: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A44C: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x8003A450: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A454: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A458: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A45C: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A460: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A464: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A468: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8003A46C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A470: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A474: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A478: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A47C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A484: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A488: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x8003A48C: bc1f        L_8003A4A4
    if (!c1cs) {
        // 0x8003A490: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A4A4;
    }
    // 0x8003A490: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A494: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A498: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A49C: nop

    // 0x8003A4A0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A4A4:
    // 0x8003A4A4: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8003A4A8: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A4AC: bc1f        L_8003A4B8
    if (!c1cs) {
        // 0x8003A4B0: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A4B8;
    }
    // 0x8003A4B0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A4B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A4B8:
    // 0x8003A4B8: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A4BC: nop

    // 0x8003A4C0: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A4C4: beq         $at, $zero, L_8003A4D4
    if (ctx->r1 == 0) {
        // 0x8003A4C8: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A4D4;
    }
    // 0x8003A4C8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A4CC: b           L_8003AB40
    // 0x8003A4D0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB40;
    // 0x8003A4D0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A4D4:
    // 0x8003A4D4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A4D8: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A4DC: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A4E0: jal         0x80023460
    // 0x8003A4E4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    find_furthest_telepoint(rdram, ctx);
        goto after_61;
    // 0x8003A4E4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    after_61:
    // 0x8003A4E8: beq         $v0, $zero, L_8003A52C
    if (ctx->r2 == 0) {
        // 0x8003A4EC: nop
    
            goto L_8003A52C;
    }
    // 0x8003A4EC: nop

    // 0x8003A4F0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A4F4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A4F8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A4FC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A500: nop

    // 0x8003A504: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8003A508: lh          $t8, 0x2E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A50C: nop

    // 0x8003A510: sh          $t8, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r24;
    // 0x8003A514: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A518: nop

    // 0x8003A51C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A520: nop

    // 0x8003A524: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A528: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8003A52C:
    // 0x8003A52C: b           L_8003AB44
    // 0x8003A530: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A530: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A534:
    // 0x8003A534: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A538: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A53C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A540: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A544: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A548: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A54C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A550: sub.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d - ctx->f6.d;
    // 0x8003A554: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A558: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A55C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A560: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8003A564: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A568: nop

    // 0x8003A56C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8003A570: nop

    // 0x8003A574: bc1f        L_8003A584
    if (!c1cs) {
        // 0x8003A578: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A584;
    }
    // 0x8003A578: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A57C: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A580: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A584:
    // 0x8003A584: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A588: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A58C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A590: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A594: beq         $at, $zero, L_8003A5A4
    if (ctx->r1 == 0) {
        // 0x8003A598: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A5A4;
    }
    // 0x8003A598: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A59C: b           L_8003AB40
    // 0x8003A5A0: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB40;
    // 0x8003A5A0: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A5A4:
    // 0x8003A5A4: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A5A8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003A5AC: b           L_8003AB44
    // 0x8003A5B0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A5B0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A5B4:
    // 0x8003A5B4: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x8003A5B8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8003A5BC: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
    // 0x8003A5C0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003A5C4: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8003A5C8: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8003A5CC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A5D0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A5D4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A5D8: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A5DC: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x8003A5E0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A5E4: b           L_8003AB40
    // 0x8003A5E8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB40;
    // 0x8003A5E8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8003A5EC:
    // 0x8003A5EC: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003A5F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A5F4: lbu         $t0, 0xD($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A5F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A5FC: bne         $t0, $at, L_8003A66C
    if (ctx->r8 != ctx->r1) {
        // 0x8003A600: swc1        $f4, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
            goto L_8003A66C;
    }
    // 0x8003A600: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8003A604: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A608: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A60C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A610: jal         0x8001C558
    // 0x8003A614: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_62;
    // 0x8003A614: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_62:
    // 0x8003A618: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A61C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A620: beq         $a0, $at, L_8003A820
    if (ctx->r4 == ctx->r1) {
        // 0x8003A624: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_8003A820;
    }
    // 0x8003A624: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x8003A628: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003A62C: jal         0x8001CC7C
    // 0x8003A630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_63;
    // 0x8003A630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8003A634: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A638: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x8003A63C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A640: jal         0x8001CC7C
    // 0x8003A644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_64;
    // 0x8003A644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8003A648: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x8003A64C: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x8003A650: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A654: jal         0x8001CC7C
    // 0x8003A658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_65;
    // 0x8003A658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8003A65C: lbu         $t1, 0xD($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A660: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x8003A664: b           L_8003A820
    // 0x8003A668: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
        goto L_8003A820;
    // 0x8003A668: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
L_8003A66C:
    // 0x8003A66C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8003A670: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A674: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A678: nop

    // 0x8003A67C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003A680: nop

    // 0x8003A684: bc1f        L_8003A6C8
    if (!c1cs) {
        // 0x8003A688: nop
    
            goto L_8003A6C8;
    }
    // 0x8003A688: nop

    // 0x8003A68C: lh          $t2, 0x1C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A690: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x8003A694: bne         $t2, $zero, L_8003A6C8
    if (ctx->r10 != 0) {
        // 0x8003A698: nop
    
            goto L_8003A6C8;
    }
    // 0x8003A698: nop

    // 0x8003A69C: beq         $t3, $zero, L_8003A6C8
    if (ctx->r11 == 0) {
        // 0x8003A6A0: addiu       $t4, $zero, 0xF0
        ctx->r12 = ADD32(0, 0XF0);
            goto L_8003A6C8;
    }
    // 0x8003A6A0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x8003A6A4: sh          $t4, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r12;
    // 0x8003A6A8: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A6AC: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8003A6B0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A6B4: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003A6B8: jal         0x80070990
    // 0x8003A6BC: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    arctan2_f(rdram, ctx);
        goto after_66;
    // 0x8003A6BC: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    after_66:
    // 0x8003A6C0: addiu       $t5, $v0, 0x4000
    ctx->r13 = ADD32(ctx->r2, 0X4000);
    // 0x8003A6C4: sh          $t5, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r13;
L_8003A6C8:
    // 0x8003A6C8: lh          $v0, 0x1C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A6CC: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A6D0: blez        $v0, L_8003A6E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003A6D4: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003A6E0;
    }
    // 0x8003A6D4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003A6D8: b           L_8003A6E4
    // 0x8003A6DC: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
        goto L_8003A6E4;
    // 0x8003A6DC: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
L_8003A6E0:
    // 0x8003A6E0: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
L_8003A6E4:
    // 0x8003A6E4: lh          $t8, 0x1C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A6E8: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A6EC: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x8003A6F0: beq         $at, $zero, L_8003A720
    if (ctx->r1 == 0) {
        // 0x8003A6F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003A720;
    }
    // 0x8003A6F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003A6F8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8003A6FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003A700: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A704: jal         0x8001C6F8
    // 0x8003A708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_67;
    // 0x8003A708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_67:
    // 0x8003A70C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A710: nop

    // 0x8003A714: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8003A718: b           L_8003A820
    // 0x8003A71C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
        goto L_8003A820;
    // 0x8003A71C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_8003A720:
    // 0x8003A720: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003A724: lh          $t9, 0x1E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1E);
    // 0x8003A728: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x8003A72C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003A730: subu        $a2, $t9, $t0
    ctx->r6 = SUB32(ctx->r25, ctx->r8);
    // 0x8003A734: slt         $at, $a2, $at
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003A738: bne         $at, $zero, L_8003A748
    if (ctx->r1 != 0) {
        // 0x8003A73C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003A748;
    }
    // 0x8003A73C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003A740: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003A744: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A748:
    // 0x8003A748: slti        $at, $a2, -0x8000
    ctx->r1 = SIGNED(ctx->r6) < -0X8000 ? 1 : 0;
    // 0x8003A74C: beq         $at, $zero, L_8003A758
    if (ctx->r1 == 0) {
        // 0x8003A750: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003A758;
    }
    // 0x8003A750: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003A754: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A758:
    // 0x8003A758: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003A75C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A760: mflo        $t2
    ctx->r10 = lo;
    // 0x8003A764: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8003A768: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8003A76C: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x8003A770: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A774: nop

    // 0x8003A778: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A77C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8003A780: jal         0x80070A04
    // 0x8003A784: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_68;
    // 0x8003A784: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_68:
    // 0x8003A788: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8003A78C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A790: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A794: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A798: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8003A79C: jal         0x80070A38
    // 0x8003A7A0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_69;
    // 0x8003A7A0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_69:
    // 0x8003A7A4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003A7A8: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A7AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A7B0: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003A7B4: lwc1        $f3, 0x66E0($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X66E0);
    // 0x8003A7B8: lwc1        $f2, 0x66E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X66E4);
    // 0x8003A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A7C0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A7C4: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8003A7C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003A7CC: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8003A7D0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A7D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003A7D8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A7DC: mul.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8003A7E0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A7E4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003A7E8: jal         0x80011570
    // 0x8003A7EC: nop

    move_object(rdram, ctx);
        goto after_70;
    // 0x8003A7EC: nop

    after_70:
    // 0x8003A7F0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A7F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A7F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003A7FC: lwc1        $f7, 0x66E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X66E8);
    // 0x8003A800: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x8003A804: lwc1        $f6, 0x66EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X66EC);
    // 0x8003A808: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A80C: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003A810: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A814: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x8003A818: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A81C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_8003A820:
    // 0x8003A820: jal         0x8001BAA8
    // 0x8003A824: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_71;
    // 0x8003A824: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_71:
    // 0x8003A828: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003A82C: nop

    // 0x8003A830: beq         $t0, $zero, L_8003A9AC
    if (ctx->r8 == 0) {
        // 0x8003A834: nop
    
            goto L_8003A9AC;
    }
    // 0x8003A834: nop

    // 0x8003A838: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003A83C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A840: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A844: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A848: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003A84C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003A850: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003A854: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003A858: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A85C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A860: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003A864: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A868: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003A86C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003A870: jal         0x800CA030
    // 0x8003A874: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_72;
    // 0x8003A874: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_72:
    // 0x8003A878: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A87C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A880: nop

    // 0x8003A884: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003A888: nop

    // 0x8003A88C: bc1f        L_8003A994
    if (!c1cs) {
        // 0x8003A890: nop
    
            goto L_8003A994;
    }
    // 0x8003A890: nop

    // 0x8003A894: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8003A898: jal         0x80069FBC
    // 0x8003A89C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    cam_get_cameras(rdram, ctx);
        goto after_73;
    // 0x8003A89C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_73:
    // 0x8003A8A0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A8A4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A8A8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A8AC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A8B0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8003A8B4: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A8B8: jal         0x800090C0
    // 0x8003A8BC: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_74;
    // 0x8003A8BC: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    after_74:
    // 0x8003A8C0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003A8C4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003A8C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003A8CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A8D0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003A8D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A8D8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8003A8DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A8E0: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003A8E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8003A8E8: nop

    // 0x8003A8EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003A8F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003A8F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003A8F8: nop

    // 0x8003A8FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003A900: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8003A904: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003A908: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x8003A90C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003A910: jal         0x80001268
    // 0x8003A914: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    music_channel_fade_set(rdram, ctx);
        goto after_75;
    // 0x8003A914: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_75:
    // 0x8003A918: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A91C: jal         0x80001268
    // 0x8003A920: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_fade_set(rdram, ctx);
        goto after_76;
    // 0x8003A920: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_76:
    // 0x8003A924: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A928: jal         0x80001268
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_fade_set(rdram, ctx);
        goto after_77;
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_77:
    // 0x8003A930: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003A934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A938: jal         0x800011A8
    // 0x8003A93C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    music_channel_pan_set(rdram, ctx);
        goto after_78;
    // 0x8003A93C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_78:
    // 0x8003A940: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A944: jal         0x800011A8
    // 0x8003A948: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_pan_set(rdram, ctx);
        goto after_79;
    // 0x8003A948: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_79:
    // 0x8003A94C: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A950: jal         0x800011A8
    // 0x8003A954: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_pan_set(rdram, ctx);
        goto after_80;
    // 0x8003A954: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_80:
    // 0x8003A958: jal         0x80001170
    // 0x8003A95C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_on(rdram, ctx);
        goto after_81;
    // 0x8003A95C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_81:
    // 0x8003A960: jal         0x80001170
    // 0x8003A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_on(rdram, ctx);
        goto after_82;
    // 0x8003A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_82:
    // 0x8003A968: jal         0x80001170
    // 0x8003A96C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_on(rdram, ctx);
        goto after_83;
    // 0x8003A96C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_83:
    // 0x8003A970: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8003A974: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x8003A978: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A97C: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x8003A980: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8003A984: jal         0x80001268
    // 0x8003A988: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    music_channel_fade_set(rdram, ctx);
        goto after_84;
    // 0x8003A988: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_84:
    // 0x8003A98C: b           L_8003A9B0
    // 0x8003A990: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
        goto L_8003A9B0;
    // 0x8003A990: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A994:
    // 0x8003A994: jal         0x80001114
    // 0x8003A998: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_off(rdram, ctx);
        goto after_85;
    // 0x8003A998: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_85:
    // 0x8003A99C: jal         0x80001114
    // 0x8003A9A0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_off(rdram, ctx);
        goto after_86;
    // 0x8003A9A0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_86:
    // 0x8003A9A4: jal         0x80001114
    // 0x8003A9A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_off(rdram, ctx);
        goto after_87;
    // 0x8003A9A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_87:
L_8003A9AC:
    // 0x8003A9AC: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A9B0:
    // 0x8003A9B0: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A9B4: beq         $v1, $zero, L_8003A9CC
    if (ctx->r3 == 0) {
        // 0x8003A9B8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003A9CC;
    }
    // 0x8003A9B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A9BC: beq         $v1, $at, L_8003AAA4
    if (ctx->r3 == ctx->r1) {
        // 0x8003A9C0: nop
    
            goto L_8003AAA4;
    }
    // 0x8003A9C0: nop

    // 0x8003A9C4: b           L_8003AB30
    // 0x8003A9C8: nop

        goto L_8003AB30;
    // 0x8003A9C8: nop

L_8003A9CC:
    // 0x8003A9CC: lhu         $v1, 0x34($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A9D0: sll         $t5, $v0, 7
    ctx->r13 = S32(ctx->r2 << 7);
    // 0x8003A9D4: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A9D8: beq         $at, $zero, L_8003AA10
    if (ctx->r1 == 0) {
        // 0x8003A9DC: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003AA10;
    }
    // 0x8003A9DC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9E0: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x8003A9E4: sh          $t6, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r14;
    // 0x8003A9E8: jal         0x80001170
    // 0x8003A9EC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_88;
    // 0x8003A9EC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_88:
    // 0x8003A9F0: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A9F4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9F8: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003A9FC: jal         0x80001268
    // 0x8003AA00: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_89;
    // 0x8003AA00: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    after_89:
    // 0x8003AA04: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8003AA08: b           L_8003AA3C
    // 0x8003AA0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8003AA3C;
    // 0x8003AA0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003AA10:
    // 0x8003AA10: jal         0x80001114
    // 0x8003AA14: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    music_channel_off(rdram, ctx);
        goto after_90;
    // 0x8003AA14: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    after_90:
    // 0x8003AA18: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x8003AA1C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003AA20: bne         $v1, $zero, L_8003AA3C
    if (ctx->r3 != 0) {
        // 0x8003AA24: nop
    
            goto L_8003AA3C;
    }
    // 0x8003AA24: nop

    // 0x8003AA28: jal         0x8006FB8C
    // 0x8003AA2C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_91;
    // 0x8003AA2C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_91:
    // 0x8003AA30: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x8003AA34: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AA38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003AA3C:
    // 0x8003AA3C: beq         $v1, $zero, L_8003AA98
    if (ctx->r3 == 0) {
        // 0x8003AA40: nop
    
            goto L_8003AA98;
    }
    // 0x8003AA40: nop

    // 0x8003AA44: jal         0x8000105C
    // 0x8003AA48: nop

    music_channel_get_mask(rdram, ctx);
        goto after_92;
    // 0x8003AA48: nop

    after_92:
    // 0x8003AA4C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AA50: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8003AA54: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AA58: bne         $t9, $at, L_8003AA98
    if (ctx->r25 != ctx->r1) {
        // 0x8003AA5C: nop
    
            goto L_8003AA98;
    }
    // 0x8003AA5C: nop

    // 0x8003AA60: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AA64: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AA68: lw          $t2, 0x30($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X30);
    // 0x8003AA6C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8003AA70: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003AA74: beq         $at, $zero, L_8003AB30
    if (ctx->r1 == 0) {
        // 0x8003AA78: sw          $t3, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r11;
            goto L_8003AB30;
    }
    // 0x8003AA78: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    // 0x8003AA7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003AA80: sb          $t5, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r13;
    // 0x8003AA84: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003AA88: jal         0x8006FB8C
    // 0x8003AA8C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_93;
    // 0x8003AA8C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_93:
    // 0x8003AA90: b           L_8003AB30
    // 0x8003AA94: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
        goto L_8003AB30;
    // 0x8003AA94: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
L_8003AA98:
    // 0x8003AA98: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AA9C: b           L_8003AB30
    // 0x8003AAA0: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
        goto L_8003AB30;
    // 0x8003AAA0: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AAA4:
    // 0x8003AAA4: jal         0x8000105C
    // 0x8003AAA8: nop

    music_channel_get_mask(rdram, ctx);
        goto after_94;
    // 0x8003AAA8: nop

    after_94:
    // 0x8003AAAC: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AAB0: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8003AAB4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AAB8: bne         $t6, $at, L_8003AB24
    if (ctx->r14 != ctx->r1) {
        // 0x8003AABC: nop
    
            goto L_8003AB24;
    }
    // 0x8003AABC: nop

    // 0x8003AAC0: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AAC4: lhu         $t7, 0x34($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AAC8: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x8003AACC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003AAD0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8003AAD4: slti        $at, $t0, 0x7F01
    ctx->r1 = SIGNED(ctx->r8) < 0X7F01 ? 1 : 0;
    // 0x8003AAD8: bne         $at, $zero, L_8003AAE8
    if (ctx->r1 != 0) {
        // 0x8003AADC: sh          $t9, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r25;
            goto L_8003AAE8;
    }
    // 0x8003AADC: sh          $t9, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r25;
    // 0x8003AAE0: addiu       $t1, $zero, 0x7F00
    ctx->r9 = ADD32(0, 0X7F00);
    // 0x8003AAE4: sh          $t1, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r9;
L_8003AAE8:
    // 0x8003AAE8: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AAEC: nop

    // 0x8003AAF0: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8003AAF4: bgez        $t2, L_8003AB00
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003AAF8: sw          $t2, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r10;
            goto L_8003AB00;
    }
    // 0x8003AAF8: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x8003AAFC: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
L_8003AB00:
    // 0x8003AB00: jal         0x80001170
    // 0x8003AB04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_95;
    // 0x8003AB04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_95:
    // 0x8003AB08: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AB0C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003AB10: sra         $t5, $a1, 8
    ctx->r13 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003AB14: jal         0x80001268
    // 0x8003AB18: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_96;
    // 0x8003AB18: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_96:
    // 0x8003AB1C: b           L_8003AB30
    // 0x8003AB20: nop

        goto L_8003AB30;
    // 0x8003AB20: nop

L_8003AB24:
    // 0x8003AB24: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // 0x8003AB28: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AB2C: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AB30:
    // 0x8003AB30: jal         0x8000105C
    // 0x8003AB34: nop

    music_channel_get_mask(rdram, ctx);
        goto after_97;
    // 0x8003AB34: nop

    after_97:
    // 0x8003AB38: andi        $t7, $v0, 0xBFFF
    ctx->r15 = ctx->r2 & 0XBFFF;
    // 0x8003AB3C: sh          $t7, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r15;
L_8003AB40:
    // 0x8003AB40: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003AB44:
    // 0x8003AB44: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003AB48: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003AB4C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AB50: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8003AB54: jal         0x8002B134
    // 0x8003AB58: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    func_8002B0F4(rdram, ctx);
        goto after_98;
    // 0x8003AB58: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_98:
    // 0x8003AB5C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8003AB60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003AB64: beq         $v0, $zero, L_8003ABD8
    if (ctx->r2 == 0) {
        // 0x8003AB68: addiu       $a2, $v0, -0x1
        ctx->r6 = ADD32(ctx->r2, -0X1);
            goto L_8003ABD8;
    }
    // 0x8003AB68: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8003AB6C: bltz        $a2, L_8003ABD8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8003AB70: sll         $a0, $a2, 2
        ctx->r4 = S32(ctx->r6 << 2);
            goto L_8003ABD8;
    }
    // 0x8003AB70: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8003AB74: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8003AB78: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x8003AB7C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003AB80:
    // 0x8003AB80: nop

    // 0x8003AB84: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8003AB88: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003AB8C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8003AB90: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x8003AB94: nop

    // 0x8003AB98: beq         $a2, $v1, L_8003ABD0
    if (ctx->r6 == ctx->r3) {
        // 0x8003AB9C: nop
    
            goto L_8003ABD0;
    }
    // 0x8003AB9C: nop

    // 0x8003ABA0: beq         $a1, $v1, L_8003ABD0
    if (ctx->r5 == ctx->r3) {
        // 0x8003ABA4: nop
    
            goto L_8003ABD0;
    }
    // 0x8003ABA4: nop

    // 0x8003ABA8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003ABAC: nop

    // 0x8003ABB0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8003ABB4: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8003ABB8: nop

    // 0x8003ABBC: bc1f        L_8003ABD0
    if (!c1cs) {
        // 0x8003ABC0: nop
    
            goto L_8003ABD0;
    }
    // 0x8003ABC0: nop

    // 0x8003ABC4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003ABC8: nop

    // 0x8003ABCC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_8003ABD0:
    // 0x8003ABD0: bgez        $a0, L_8003AB80
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003ABD4: lw          $t8, 0x94($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X94);
            goto L_8003AB80;
    }
    // 0x8003ABD4: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003ABD8:
    // 0x8003ABD8: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x8003ABDC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003ABE0: beq         $t0, $zero, L_8003ABF4
    if (ctx->r8 == 0) {
        // 0x8003ABE4: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8003ABF4;
    }
    // 0x8003ABE4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8003ABE8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003ABEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ABF0: swc1        $f4, -0x25B0($at)
    MEM_W(-0X25B0, ctx->r1) = ctx->f4.u32l;
L_8003ABF4:
    // 0x8003ABF4: lb          $t1, 0x6B($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X6B);
    // 0x8003ABF8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8003ABFC: beq         $t1, $zero, L_8003AC24
    if (ctx->r9 == 0) {
        // 0x8003AC00: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003AC24;
    }
    // 0x8003AC00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003AC04: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AC08: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AC0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AC10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AC14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003AC18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003AC1C: jal         0x8003FC84
    // 0x8003AC20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_99;
    // 0x8003AC20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_99:
L_8003AC24:
    // 0x8003AC24: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003AC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AC2C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003AC30: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003AC34: nop

    // 0x8003AC38: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003AC3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003AC40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003AC44: nop

    // 0x8003AC48: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x8003AC4C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8003AC50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003AC54: jal         0x80061E4C
    // 0x8003AC58: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    func_80061C0C(rdram, ctx);
        goto after_100;
    // 0x8003AC58: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    after_100:
    // 0x8003AC5C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AC60: jal         0x800B019C
    // 0x8003AC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_101;
    // 0x8003AC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x8003AC68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AC6C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003AC70: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003AC74: jr          $ra
    // 0x8003AC78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8003AC78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
