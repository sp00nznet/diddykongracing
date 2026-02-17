#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void cam_get_cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069FC0: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069FC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FC8: beq         $t6, $zero, L_80069FDC
    if (ctx->r14 == 0) {
        // 0x80069FCC: addiu       $v0, $v0, 0x1040
        ctx->r2 = ADD32(ctx->r2, 0X1040);
            goto L_80069FDC;
    }
    // 0x80069FCC: addiu       $v0, $v0, 0x1040
    ctx->r2 = ADD32(ctx->r2, 0X1040);
    // 0x80069FD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FD4: jr          $ra
    // 0x80069FD8: addiu       $v0, $v0, 0x1150
    ctx->r2 = ADD32(ctx->r2, 0X1150);
    return;
    // 0x80069FD8: addiu       $v0, $v0, 0x1150
    ctx->r2 = ADD32(ctx->r2, 0X1150);
L_80069FDC:
    // 0x80069FDC: jr          $ra
    // 0x80069FE0: nop

    return;
    // 0x80069FE0: nop

;}
RECOMP_FUNC void get_projection_matrix_f32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FE8: jr          $ra
    // 0x80069FEC: addiu       $v0, $v0, 0x1520
    ctx->r2 = ADD32(ctx->r2, 0X1520);
    return;
    // 0x80069FEC: addiu       $v0, $v0, 0x1520
    ctx->r2 = ADD32(ctx->r2, 0X1520);
;}
RECOMP_FUNC void get_projection_matrix_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FF4: jr          $ra
    // 0x80069FF8: addiu       $v0, $v0, 0x1560
    ctx->r2 = ADD32(ctx->r2, 0X1560);
    return;
    // 0x80069FF8: addiu       $v0, $v0, 0x1560
    ctx->r2 = ADD32(ctx->r2, 0X1560);
;}
RECOMP_FUNC void get_camera_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A000: jr          $ra
    // 0x8006A004: addiu       $v0, $v0, 0x14E0
    ctx->r2 = ADD32(ctx->r2, 0X14E0);
    return;
    // 0x8006A004: addiu       $v0, $v0, 0x14E0
    ctx->r2 = ADD32(ctx->r2, 0X14E0);
;}
RECOMP_FUNC void get_distance_to_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A008: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A00C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006A010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A014: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8006A018: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006A01C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8006A020: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8006A024: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8006A028: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A02C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006A030: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    // 0x8006A034: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006A038: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006A03C: jal         0x8006F88C
    // 0x8006A040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mtxf_transform_point(rdram, ctx);
        goto after_0;
    // 0x8006A040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8006A044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A048: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A04C: jr          $ra
    // 0x8006A050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_camera_shake_by_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A054: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006A058: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8006A05C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8006A060: addiu       $s2, $s2, 0x1260
    ctx->r18 = ADD32(ctx->r18, 0X1260);
    // 0x8006A064: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8006A068: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8006A06C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8006A070: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8006A074: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x8006A078: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8006A07C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8006A080: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8006A084: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8006A088: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8006A08C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8006A090: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x8006A094: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006A098: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006A09C: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8006A0A0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006A0A4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8006A0A8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8006A0AC: bltz        $t6, L_8006A128
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006A0B0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006A128;
    }
    // 0x8006A0B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A0B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A0B8: lwc1        $f22, 0x60($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006A0BC: addiu       $s0, $s0, 0x1040
    ctx->r16 = ADD32(ctx->r16, 0X1040);
L_8006A0C0:
    // 0x8006A0C0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A0C4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A0C8: sub.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8006A0CC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006A0D0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A0D4: sub.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x8006A0D8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A0DC: sub.s       $f14, $f28, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f8.fl;
    // 0x8006A0E0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006A0E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006A0E8: jal         0x800CA030
    // 0x8006A0EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A0EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8006A0F0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006A0F4: nop

    // 0x8006A0F8: bc1f        L_8006A114
    if (!c1cs) {
        // 0x8006A0FC: nop
    
            goto L_8006A114;
    }
    // 0x8006A0FC: nop

    // 0x8006A100: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8006A104: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006A108: nop

    // 0x8006A10C: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8006A110: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_8006A114:
    // 0x8006A114: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8006A118: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A11C: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8006A120: beq         $at, $zero, L_8006A0C0
    if (ctx->r1 == 0) {
        // 0x8006A124: addiu       $s0, $s0, 0x44
        ctx->r16 = ADD32(ctx->r16, 0X44);
            goto L_8006A0C0;
    }
    // 0x8006A124: addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
L_8006A128:
    // 0x8006A128: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A12C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8006A130: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006A134: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006A138: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006A13C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8006A140: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A144: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8006A148: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006A14C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8006A150: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006A154: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8006A158: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8006A15C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006A160: jr          $ra
    // 0x8006A164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006A164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void set_camera_shake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A168: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A16C: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x8006A170: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A174: bltz        $v1, L_8006A19C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006A178: addiu       $v0, $t6, 0x1040
        ctx->r2 = ADD32(ctx->r14, 0X1040);
            goto L_8006A19C;
    }
    // 0x8006A178: addiu       $v0, $t6, 0x1040
    ctx->r2 = ADD32(ctx->r14, 0X1040);
    // 0x8006A17C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8006A180: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006A184: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006A188: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
L_8006A18C:
    // 0x8006A18C: addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    // 0x8006A190: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8006A194: beq         $at, $zero, L_8006A18C
    if (ctx->r1 == 0) {
        // 0x8006A198: swc1        $f12, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
            goto L_8006A18C;
    }
    // 0x8006A198: swc1        $f12, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
L_8006A19C:
    // 0x8006A19C: jr          $ra
    // 0x8006A1A0: nop

    return;
    // 0x8006A1A0: nop

;}
RECOMP_FUNC void debug_print_fixed_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8006A1A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8006A1AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006A1B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006A1B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8006A1B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006A1BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006A1C0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8006A1C4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8006A1C8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8006A1CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006A1D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A1D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A1D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A1DC: addiu       $fp, $fp, 0x7614
    ctx->r30 = ADD32(ctx->r30, 0X7614);
    // 0x8006A1E0: addiu       $s4, $s4, 0x760C
    ctx->r20 = ADD32(ctx->r20, 0X760C);
    // 0x8006A1E4: addiu       $s3, $s3, 0x7608
    ctx->r19 = ADD32(ctx->r19, 0X7608);
    // 0x8006A1E8: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8006A1EC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8006A1F0: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
L_8006A1F4:
    // 0x8006A1F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A1F8: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_8006A1FC:
    // 0x8006A1FC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8006A200: jal         0x800CA2B4
    // 0x8006A204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8006A208: lh          $a1, 0x20($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X20);
    // 0x8006A20C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006A210: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8006A214: jal         0x800CA2B4
    // 0x8006A218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x8006A21C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006A220: bne         $s1, $s5, L_8006A1FC
    if (ctx->r17 != ctx->r21) {
        // 0x8006A224: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8006A1FC;
    }
    // 0x8006A224: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006A228: jal         0x800CA2B4
    // 0x8006A22C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A22C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x8006A230: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8006A234: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8006A238: bne         $s6, $at, L_8006A1F4
    if (ctx->r22 != ctx->r1) {
        // 0x8006A23C: addiu       $s7, $s7, 0x8
        ctx->r23 = ADD32(ctx->r23, 0X8);
            goto L_8006A1F4;
    }
    // 0x8006A23C: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x8006A240: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A244: jal         0x800CA2B4
    // 0x8006A248: addiu       $a0, $a0, 0x7618
    ctx->r4 = ADD32(ctx->r4, 0X7618);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A248: addiu       $a0, $a0, 0x7618
    ctx->r4 = ADD32(ctx->r4, 0X7618);
    after_3:
    // 0x8006A24C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A254: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A258: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A25C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006A260: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006A264: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A268: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006A26C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006A270: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006A274: jr          $ra
    // 0x8006A278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006A278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void debug_print_float_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A27C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A280: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006A284: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A288: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006A28C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006A290: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006A294: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A298: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8006A29C: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8006A2A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006A2A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A2A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A2AC: addiu       $s6, $s6, 0x7624
    ctx->r22 = ADD32(ctx->r22, 0X7624);
    // 0x8006A2B0: addiu       $s2, $s2, 0x761C
    ctx->r18 = ADD32(ctx->r18, 0X761C);
    // 0x8006A2B4: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8006A2B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8006A2BC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8006A2C0: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_8006A2C4:
    // 0x8006A2C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A2C8: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_8006A2CC:
    // 0x8006A2CC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006A2D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006A2D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8006A2D8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8006A2DC: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8006A2E0: jal         0x800CA2B4
    // 0x8006A2E4: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A2E4: nop

    after_0:
    // 0x8006A2E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006A2EC: bne         $s0, $s3, L_8006A2CC
    if (ctx->r16 != ctx->r19) {
        // 0x8006A2F0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A2CC;
    }
    // 0x8006A2F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A2F4: jal         0x800CA2B4
    // 0x8006A2F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A2F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8006A2FC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8006A300: bne         $s4, $s7, L_8006A2C4
    if (ctx->r20 != ctx->r23) {
        // 0x8006A304: addiu       $s5, $s5, 0x10
        ctx->r21 = ADD32(ctx->r21, 0X10);
            goto L_8006A2C4;
    }
    // 0x8006A304: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8006A308: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A30C: jal         0x800CA2B4
    // 0x8006A310: addiu       $a0, $a0, 0x7628
    ctx->r4 = ADD32(ctx->r4, 0X7628);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A310: addiu       $a0, $a0, 0x7628
    ctx->r4 = ADD32(ctx->r4, 0X7628);
    after_2:
    // 0x8006A314: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006A318: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A31C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A320: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A324: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006A328: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006A32C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006A330: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A334: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006A338: jr          $ra
    // 0x8006A33C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A33C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void si_mesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A340: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A344: jr          $ra
    // 0x8006A348: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
    return;
    // 0x8006A348: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
;}
RECOMP_FUNC void input_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A34C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A354: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A358: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A35C: addiu       $a1, $a1, 0x1678
    ctx->r5 = ADD32(ctx->r5, 0X1678);
    // 0x8006A360: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A364: jal         0x800C8D80
    // 0x8006A368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8006A36C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A370: lw          $a2, 0x167C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X167C);
    // 0x8006A374: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A378: addiu       $a1, $a1, 0x1660
    ctx->r5 = ADD32(ctx->r5, 0X1660);
    // 0x8006A37C: jal         0x800CD110
    // 0x8006A380: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A380: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x8006A384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A388: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A38C: addiu       $a2, $a2, 0x1680
    ctx->r6 = ADD32(ctx->r6, 0X1680);
    // 0x8006A390: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A394: jal         0x800CD180
    // 0x8006A398: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A398: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    after_2:
    // 0x8006A39C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A3A0: jal         0x800CD540
    // 0x8006A3A4: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    osContStartReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A3A4: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    after_3:
    // 0x8006A3A8: jal         0x8006A674
    // 0x8006A3AC: nop

    input_assign_players(rdram, ctx);
        goto after_4;
    // 0x8006A3AC: nop

    after_4:
    // 0x8006A3B0: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8006A3B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006A3B8: addiu       $v1, $v1, -0x2790
    ctx->r3 = ADD32(ctx->r3, -0X2790);
    // 0x8006A3BC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8006A3C0: beq         $t6, $zero, L_8006A3E8
    if (ctx->r14 == 0) {
        // 0x8006A3C4: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8006A3E8;
    }
    // 0x8006A3C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8006A3C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006A3CC: lbu         $t7, 0x1683($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1683);
    // 0x8006A3D0: nop

    // 0x8006A3D4: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8006A3D8: bne         $t8, $zero, L_8006A3EC
    if (ctx->r24 != 0) {
        // 0x8006A3DC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8006A3EC;
    }
    // 0x8006A3DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006A3E0: b           L_8006A3F4
    // 0x8006A3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A3F4;
    // 0x8006A3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A3E8:
    // 0x8006A3E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8006A3EC:
    // 0x8006A3EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A3F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006A3F4:
    // 0x8006A3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A3F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006A3FC: jr          $ra
    // 0x8006A400: nop

    return;
    // 0x8006A400: nop

;}
RECOMP_FUNC void input_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A404: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A408: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A40C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006A410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A414: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8006A418: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A41C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A420: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A424: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A428: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8006A42C: jal         0x800C9110
    // 0x8006A430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006A434: bne         $v0, $zero, L_8006A5AC
    if (ctx->r2 != 0) {
        // 0x8006A438: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006A5AC;
    }
    // 0x8006A438: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A43C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A440: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A444: addiu       $v1, $v1, 0x16A8
    ctx->r3 = ADD32(ctx->r3, 0X16A8);
    // 0x8006A448: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, 0X1690);
    // 0x8006A44C: addiu       $a2, $a2, 0x16A8
    ctx->r6 = ADD32(ctx->r6, 0X16A8);
L_8006A450:
    // 0x8006A450: lwl         $at, 0x0($v0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r2, 0X0);
    // 0x8006A454: lwr         $at, 0x3($v0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r2, 0X3);
    // 0x8006A458: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006A45C: swl         $at, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r1);
    // 0x8006A460: swr         $at, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r1);
    // 0x8006A464: lhu         $at, -0x2($v0)
    ctx->r1 = MEM_HU(ctx->r2, -0X2);
    // 0x8006A468: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8006A46C: sh          $at, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r1;
    // 0x8006A470: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8006A474: bne         $at, $zero, L_8006A450
    if (ctx->r1 != 0) {
        // 0x8006A478: nop
    
            goto L_8006A450;
    }
    // 0x8006A478: nop

    // 0x8006A47C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A480: jal         0x800CD604
    // 0x8006A484: addiu       $a0, $a0, 0x1690
    ctx->r4 = ADD32(ctx->r4, 0X1690);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A484: addiu       $a0, $a0, 0x1690
    ctx->r4 = ADD32(ctx->r4, 0X1690);
    after_1:
    // 0x8006A488: beq         $s2, $zero, L_8006A598
    if (ctx->r18 == 0) {
        // 0x8006A48C: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_8006A598;
    }
    // 0x8006A48C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8006A490: jal         0x8006ECD0
    // 0x8006A494: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8006A494: nop

    after_2:
    // 0x8006A498: andi        $v1, $s2, 0x3
    ctx->r3 = ctx->r18 & 0X3;
    // 0x8006A49C: beq         $v1, $zero, L_8006A4B0
    if (ctx->r3 == 0) {
        // 0x8006A4A0: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_8006A4B0;
    }
    // 0x8006A4A0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006A4A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006A4A8: jal         0x80074828
    // 0x8006A4AC: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    read_eeprom_data(rdram, ctx);
        goto after_3;
    // 0x8006A4AC: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_3:
L_8006A4B0:
    // 0x8006A4B0: andi        $t8, $s2, 0x8
    ctx->r24 = ctx->r18 & 0X8;
    // 0x8006A4B4: beq         $t8, $zero, L_8006A4EC
    if (ctx->r24 == 0) {
        // 0x8006A4B8: andi        $t9, $s2, 0x4
        ctx->r25 = ctx->r18 & 0X4;
            goto L_8006A4EC;
    }
    // 0x8006A4B8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x8006A4BC: jal         0x8009C9D4
    // 0x8006A4C0: nop

    get_all_save_files_ptr(rdram, ctx);
        goto after_4;
    // 0x8006A4C0: nop

    after_4:
    // 0x8006A4C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A4C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8006A4CC:
    // 0x8006A4CC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006A4D0: jal         0x8007445C
    // 0x8006A4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    read_save_file(rdram, ctx);
        goto after_5;
    // 0x8006A4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006A4D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006A4DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A4E0: bne         $s0, $at, L_8006A4CC
    if (ctx->r16 != ctx->r1) {
        // 0x8006A4E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A4CC;
    }
    // 0x8006A4E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A4E8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
L_8006A4EC:
    // 0x8006A4EC: beq         $t9, $zero, L_8006A504
    if (ctx->r25 == 0) {
        // 0x8006A4F0: sra         $a0, $s2, 8
        ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
            goto L_8006A504;
    }
    // 0x8006A4F0: sra         $a0, $s2, 8
    ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
    // 0x8006A4F4: andi        $t4, $a0, 0x3
    ctx->r12 = ctx->r4 & 0X3;
    // 0x8006A4F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A4FC: jal         0x8007445C
    // 0x8006A500: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    read_save_file(rdram, ctx);
        goto after_6;
    // 0x8006A500: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_6:
L_8006A504:
    // 0x8006A504: andi        $v0, $s2, 0x30
    ctx->r2 = ctx->r18 & 0X30;
    // 0x8006A508: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006A50C: beq         $t5, $zero, L_8006A524
    if (ctx->r13 == 0) {
        // 0x8006A510: andi        $t6, $s2, 0x40
        ctx->r14 = ctx->r18 & 0X40;
            goto L_8006A524;
    }
    // 0x8006A510: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
    // 0x8006A514: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A518: jal         0x80074948
    // 0x8006A51C: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    write_eeprom_data(rdram, ctx);
        goto after_7;
    // 0x8006A51C: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_7:
    // 0x8006A520: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
L_8006A524:
    // 0x8006A524: beq         $t6, $zero, L_8006A53C
    if (ctx->r14 == 0) {
        // 0x8006A528: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A53C;
    }
    // 0x8006A528: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A52C: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x8006A530: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A534: jal         0x80074734
    // 0x8006A538: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    write_save_data(rdram, ctx);
        goto after_8;
    // 0x8006A538: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_8:
L_8006A53C:
    // 0x8006A53C: andi        $t8, $s2, 0x80
    ctx->r24 = ctx->r18 & 0X80;
    // 0x8006A540: beq         $t8, $zero, L_8006A558
    if (ctx->r24 == 0) {
        // 0x8006A544: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A558;
    }
    // 0x8006A544: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A548: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x8006A54C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A550: jal         0x80074574
    // 0x8006A554: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    erase_save_file(rdram, ctx);
        goto after_9;
    // 0x8006A554: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
L_8006A558:
    // 0x8006A558: andi        $t4, $s2, 0x100
    ctx->r12 = ctx->r18 & 0X100;
    // 0x8006A55C: beq         $t4, $zero, L_8006A578
    if (ctx->r12 == 0) {
        // 0x8006A560: andi        $t5, $s2, 0x200
        ctx->r13 = ctx->r18 & 0X200;
            goto L_8006A578;
    }
    // 0x8006A560: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
    // 0x8006A564: jal         0x8009EFB0
    // 0x8006A568: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_10;
    // 0x8006A568: nop

    after_10:
    // 0x8006A56C: jal         0x80074ACC
    // 0x8006A570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    read_eeprom_settings(rdram, ctx);
        goto after_11;
    // 0x8006A570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006A574: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
L_8006A578:
    // 0x8006A578: beq         $t5, $zero, L_8006A594
    if (ctx->r13 == 0) {
        // 0x8006A57C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8006A594;
    }
    // 0x8006A57C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006A580: jal         0x8009EFB0
    // 0x8006A584: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_12;
    // 0x8006A584: nop

    after_12:
    // 0x8006A588: jal         0x80074BD4
    // 0x8006A58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    write_eeprom_settings(rdram, ctx);
        goto after_13;
    // 0x8006A58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8006A590: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8006A594:
    // 0x8006A594: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_8006A598:
    // 0x8006A598: jal         0x80072964
    // 0x8006A59C: nop

    rumble_update(rdram, ctx);
        goto after_14;
    // 0x8006A59C: nop

    after_14:
    // 0x8006A5A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A5A4: jal         0x800CD540
    // 0x8006A5A8: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    osContStartReadData_recomp(rdram, ctx);
        goto after_15;
    // 0x8006A5A8: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    after_15:
L_8006A5AC:
    // 0x8006A5AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006A5B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8006A5B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A5B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A5BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A5C0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006A5C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006A5C8: lhu         $t1, -0x278C($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X278C);
    // 0x8006A5CC: lw          $t2, -0x2790($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2790);
    // 0x8006A5D0: addiu       $t3, $t3, 0x16D0
    ctx->r11 = ADD32(ctx->r11, 0X16D0);
    // 0x8006A5D4: addiu       $a3, $a3, 0x16C8
    ctx->r7 = ADD32(ctx->r7, 0X16C8);
    // 0x8006A5D8: addiu       $t0, $t0, 0x16C0
    ctx->r8 = ADD32(ctx->r8, 0X16C0);
    // 0x8006A5DC: addiu       $v0, $v0, 0x1690
    ctx->r2 = ADD32(ctx->r2, 0X1690);
    // 0x8006A5E0: addiu       $a2, $a2, 0x16A8
    ctx->r6 = ADD32(ctx->r6, 0X16A8);
L_8006A5E4:
    // 0x8006A5E4: beq         $t2, $zero, L_8006A5F0
    if (ctx->r10 == 0) {
        // 0x8006A5E8: nop
    
            goto L_8006A5F0;
    }
    // 0x8006A5E8: nop

    // 0x8006A5EC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8006A5F0:
    // 0x8006A5F0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8006A5F4: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8006A5F8: nop

    // 0x8006A5FC: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A600: and         $t6, $v1, $a1
    ctx->r14 = ctx->r3 & ctx->r5;
    // 0x8006A604: and         $t8, $a0, $a1
    ctx->r24 = ctx->r4 & ctx->r5;
    // 0x8006A608: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A60C: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x8006A610: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006A614: beq         $t2, $zero, L_8006A620
    if (ctx->r10 == 0) {
        // 0x8006A618: sh          $t9, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r25;
            goto L_8006A620;
    }
    // 0x8006A618: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8006A61C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_8006A620:
    // 0x8006A620: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8006A624: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x8006A628: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8006A62C: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A630: and         $t4, $v1, $a1
    ctx->r12 = ctx->r3 & ctx->r5;
    // 0x8006A634: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8006A638: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A63C: and         $t5, $t4, $t1
    ctx->r13 = ctx->r12 & ctx->r9;
    // 0x8006A640: sh          $t5, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r13;
    // 0x8006A644: sh          $t7, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r15;
    // 0x8006A648: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8006A64C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8006A650: bne         $a3, $t3, L_8006A5E4
    if (ctx->r7 != ctx->r11) {
        // 0x8006A654: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8006A5E4;
    }
    // 0x8006A654: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8006A658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A65C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8006A660: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A668: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A66C: jr          $ra
    // 0x8006A670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006A670: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void input_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006A678: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A67C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006A680: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006A684: sb          $t8, 0x16D3($at)
    MEM_B(0X16D3, ctx->r1) = ctx->r24;
    // 0x8006A688: sb          $t7, 0x16D2($at)
    MEM_B(0X16D2, ctx->r1) = ctx->r15;
    // 0x8006A68C: sb          $t6, 0x16D1($at)
    MEM_B(0X16D1, ctx->r1) = ctx->r14;
    // 0x8006A690: jr          $ra
    // 0x8006A694: sb          $zero, 0x16D0($at)
    MEM_B(0X16D0, ctx->r1) = 0;
    return;
    // 0x8006A694: sb          $zero, 0x16D0($at)
    MEM_B(0X16D0, ctx->r1) = 0;
;}
RECOMP_FUNC void charselect_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A698: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A69C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006A6A0: addiu       $a2, $a2, 0x16D0
    ctx->r6 = ADD32(ctx->r6, 0X16D0);
    // 0x8006A6A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006A6A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8006A6AC:
    // 0x8006A6AC: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006A6B0: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6B4: beq         $t6, $zero, L_8006A6C4
    if (ctx->r14 == 0) {
        // 0x8006A6B8: nop
    
            goto L_8006A6C4;
    }
    // 0x8006A6B8: nop

    // 0x8006A6BC: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x8006A6C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A6C4:
    // 0x8006A6C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006A6C8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006A6CC: bne         $at, $zero, L_8006A6AC
    if (ctx->r1 != 0) {
        // 0x8006A6D0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006A6AC;
    }
    // 0x8006A6D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006A6D4: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006A6D8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006A6DC: bne         $t8, $zero, L_8006A6EC
    if (ctx->r24 != 0) {
        // 0x8006A6E0: addu        $t9, $a2, $v0
        ctx->r25 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A6EC;
    }
    // 0x8006A6E0: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6E4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8006A6E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A6EC:
    // 0x8006A6EC: lb          $t0, 0x1($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X1);
    // 0x8006A6F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006A6F4: bne         $t0, $zero, L_8006A704
    if (ctx->r8 != 0) {
        // 0x8006A6F8: addu        $t2, $a2, $v0
        ctx->r10 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A704;
    }
    // 0x8006A6F8: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A6FC: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x8006A700: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A704:
    // 0x8006A704: lb          $t3, 0x2($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X2);
    // 0x8006A708: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8006A70C: bne         $t3, $zero, L_8006A71C
    if (ctx->r11 != 0) {
        // 0x8006A710: addu        $t5, $a2, $v0
        ctx->r13 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A71C;
    }
    // 0x8006A710: addu        $t5, $a2, $v0
    ctx->r13 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A714: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x8006A718: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A71C:
    // 0x8006A71C: lb          $t6, 0x3($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X3);
    // 0x8006A720: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006A724: bne         $t6, $zero, L_8006A730
    if (ctx->r14 != 0) {
        // 0x8006A728: addu        $t8, $a2, $v0
        ctx->r24 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A730;
    }
    // 0x8006A728: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A72C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8006A730:
    // 0x8006A730: jr          $ra
    // 0x8006A734: nop

    return;
    // 0x8006A734: nop

;}
RECOMP_FUNC void input_player_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A738: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A73C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006A740: lbu         $v0, 0x16D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X16D0);
    // 0x8006A744: jr          $ra
    // 0x8006A748: nop

    return;
    // 0x8006A748: nop

;}
RECOMP_FUNC void input_swap_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A74C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A750: addiu       $v1, $v1, 0x16D0
    ctx->r3 = ADD32(ctx->r3, 0X16D0);
    // 0x8006A754: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006A758: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8006A75C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8006A760: jr          $ra
    // 0x8006A764: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x8006A764: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void input_held(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A768: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A76C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A770: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A774: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A778: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A77C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A780: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A784: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A788: lhu         $v0, 0x1690($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1690);
    // 0x8006A78C: jr          $ra
    // 0x8006A790: nop

    return;
    // 0x8006A790: nop

;}
RECOMP_FUNC void input_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A794: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A798: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A79C: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A7A4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A7A8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A7AC: lhu         $v0, 0x16C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16C0);
    // 0x8006A7B0: jr          $ra
    // 0x8006A7B4: nop

    return;
    // 0x8006A7B4: nop

;}
RECOMP_FUNC void input_released(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A7BC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A7C0: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A7C8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A7CC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A7D0: lhu         $v0, 0x16C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16C8);
    // 0x8006A7D4: jr          $ra
    // 0x8006A7D8: nop

    return;
    // 0x8006A7D8: nop

;}
RECOMP_FUNC void input_clamp_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A7E0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A7E4: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A7EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A7F0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A7F4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A7FC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A804: lb          $a0, 0x1692($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1692);
    // 0x8006A808: jal         0x8006A864
    // 0x8006A80C: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A80C: nop

    after_0:
    // 0x8006A810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A818: jr          $ra
    // 0x8006A81C: nop

    return;
    // 0x8006A81C: nop

;}
RECOMP_FUNC void input_clamp_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A820: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A824: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A828: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A82C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A830: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A834: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A838: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A840: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A848: lb          $a0, 0x1693($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1693);
    // 0x8006A84C: jal         0x8006A864
    // 0x8006A850: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A850: nop

    after_0:
    // 0x8006A854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A85C: jr          $ra
    // 0x8006A860: nop

    return;
    // 0x8006A860: nop

;}
RECOMP_FUNC void input_clamp_stick_mag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A864: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006A868: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006A86C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A870: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8006A874: beq         $at, $zero, L_8006A890
    if (ctx->r1 == 0) {
        // 0x8006A878: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8006A890;
    }
    // 0x8006A878: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8006A87C: slti        $at, $t7, -0x7
    ctx->r1 = SIGNED(ctx->r15) < -0X7 ? 1 : 0;
    // 0x8006A880: bne         $at, $zero, L_8006A890
    if (ctx->r1 != 0) {
        // 0x8006A884: nop
    
            goto L_8006A890;
    }
    // 0x8006A884: nop

    // 0x8006A888: jr          $ra
    // 0x8006A88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006A88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A890:
    // 0x8006A890: blez        $a0, L_8006A8B8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006A894: nop
    
            goto L_8006A8B8;
    }
    // 0x8006A894: nop

    // 0x8006A898: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8006A89C: sll         $t8, $a0, 24
    ctx->r24 = S32(ctx->r4 << 24);
    // 0x8006A8A0: sra         $a0, $t8, 24
    ctx->r4 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006A8A4: slti        $at, $a0, 0x47
    ctx->r1 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // 0x8006A8A8: bne         $at, $zero, L_8006A8D8
    if (ctx->r1 != 0) {
        // 0x8006A8AC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A8D8;
    }
    // 0x8006A8AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A8B0: b           L_8006A8D4
    // 0x8006A8B4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
        goto L_8006A8D4;
    // 0x8006A8B4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
L_8006A8B8:
    // 0x8006A8B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006A8BC: sll         $t0, $a0, 24
    ctx->r8 = S32(ctx->r4 << 24);
    // 0x8006A8C0: sra         $a0, $t0, 24
    ctx->r4 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8006A8C4: slti        $at, $a0, -0x46
    ctx->r1 = SIGNED(ctx->r4) < -0X46 ? 1 : 0;
    // 0x8006A8C8: beq         $at, $zero, L_8006A8D8
    if (ctx->r1 == 0) {
        // 0x8006A8CC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A8D8;
    }
    // 0x8006A8CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A8D0: addiu       $a0, $zero, -0x46
    ctx->r4 = ADD32(0, -0X46);
L_8006A8D4:
    // 0x8006A8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006A8D8:
    // 0x8006A8D8: jr          $ra
    // 0x8006A8DC: nop

    return;
    // 0x8006A8DC: nop

;}
RECOMP_FUNC void drm_disable_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A8E4: jr          $ra
    // 0x8006A8E8: sh          $zero, -0x278C($at)
    MEM_H(-0X278C, ctx->r1) = 0;
    return;
    // 0x8006A8E8: sh          $zero, -0x278C($at)
    MEM_H(-0X278C, ctx->r1) = 0;
    // 0x8006A8EC: nop

;}
RECOMP_FUNC void level_global_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A8F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A8F8: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A8FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A900: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A904: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A908: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A90C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A910: jal         0x80070EDC
    // 0x8006A914: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006A914: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x8006A918: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006A91C: jal         0x80076EE4
    // 0x8006A920: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8006A920: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_1:
    // 0x8006A924: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8006A928: addiu       $s3, $s3, 0x16E0
    ctx->r19 = ADD32(ctx->r19, 0X16E0);
    // 0x8006A92C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006A930: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A934: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A938: addiu       $v1, $v1, 0x1700
    ctx->r3 = ADD32(ctx->r3, 0X1700);
    // 0x8006A93C: addiu       $v0, $v0, 0x1740
    ctx->r2 = ADD32(ctx->r2, 0X1740);
L_8006A940:
    // 0x8006A940: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006A944: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8006A948: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8006A94C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8006A950: bne         $v1, $v0, L_8006A940
    if (ctx->r3 != ctx->r2) {
        // 0x8006A954: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8006A940;
    }
    // 0x8006A954: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8006A958: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8006A95C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A960: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006A964: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8006A968: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8006A96C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006A970: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006A974: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A978: beq         $t3, $t8, L_8006A9A0
    if (ctx->r11 == ctx->r24) {
        // 0x8006A97C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8006A9A0;
    }
    // 0x8006A97C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A980: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A984:
    // 0x8006A984: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006A988: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8006A98C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006A990: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8006A994: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8006A998: bne         $t3, $t6, L_8006A984
    if (ctx->r11 != ctx->r14) {
        // 0x8006A99C: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8006A984;
    }
    // 0x8006A99C: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A9A0:
    // 0x8006A9A0: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8006A9A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006A9A8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006A9AC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A9B0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8006A9B4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A9B8: jal         0x80070EDC
    // 0x8006A9BC: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8006A9BC: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    after_2:
    // 0x8006A9C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A9C4: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006A9C8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006A9CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8006A9D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A9D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A9D8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A9DC: addiu       $s0, $s0, 0x16E8
    ctx->r16 = ADD32(ctx->r16, 0X16E8);
    // 0x8006A9E0: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006A9E4: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006A9E8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A9EC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006A9F0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006A9F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A9F8: blez        $t4, L_8006AB28
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8006A9FC: sw          $t9, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r25;
            goto L_8006AB28;
    }
    // 0x8006A9FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8006AA00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006AA04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006AA08:
    // 0x8006AA08: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006AA0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006AA10: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8006AA14: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006AA18: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006AA1C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006AA20: jal         0x80077190
    // 0x8006AA24: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8006AA24: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_3:
    // 0x8006AA28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006AA2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006AA30: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006AA34: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006AA38: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006AA3C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AA40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AA44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006AA48: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006AA4C: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006AA50: beq         $at, $zero, L_8006AA5C
    if (ctx->r1 == 0) {
        // 0x8006AA54: addiu       $t0, $t0, 0x16FC
        ctx->r8 = ADD32(ctx->r8, 0X16FC);
            goto L_8006AA5C;
    }
    // 0x8006AA54: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006AA58: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
L_8006AA5C:
    // 0x8006AA5C: lb          $a0, 0x4C($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X4C);
    // 0x8006AA60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AA64: bltz        $a0, L_8006AA90
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AA68: slti        $at, $a0, 0x10
        ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
            goto L_8006AA90;
    }
    // 0x8006AA68: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x8006AA6C: beq         $at, $zero, L_8006AA90
    if (ctx->r1 == 0) {
        // 0x8006AA70: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006AA90;
    }
    // 0x8006AA70: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006AA74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006AA78: addiu       $t9, $t9, 0x1700
    ctx->r25 = ADD32(ctx->r25, 0X1700);
    // 0x8006AA7C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8006AA80: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006AA84: nop

    // 0x8006AA88: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006AA8C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8006AA90:
    // 0x8006AA90: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006AA94: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006AA98: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006AA9C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8006AAA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAA4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAA8: lb          $t4, 0x4C($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4C);
    // 0x8006AAAC: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8006AAB0: sb          $t4, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r12;
    // 0x8006AAB4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAB8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006AABC: lb          $t9, 0x4E($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X4E);
    // 0x8006AAC0: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x8006AAC4: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8006AAC8: sb          $t5, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r13;
    // 0x8006AACC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAD0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAD4: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006AAD8: lb          $t4, 0x4D($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4D);
    // 0x8006AADC: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8006AAE0: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8006AAE4: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8006AAE8: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8006AAEC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006AAF4: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8006AAF8: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
    // 0x8006AAFC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006AB00: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006AB04: lh          $t5, 0xB0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XB0);
    // 0x8006AB08: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8006AB0C: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // 0x8006AB10: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8006AB14: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AB18: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AB1C: bne         $at, $zero, L_8006AA08
    if (ctx->r1 != 0) {
        // 0x8006AB20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006AA08;
    }
    // 0x8006AB20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006AB24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006AB28:
    // 0x8006AB28: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB2C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AB30: addiu       $a0, $t4, 0x1
    ctx->r4 = ADD32(ctx->r12, 0X1);
    // 0x8006AB34: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x8006AB38: jal         0x80070EDC
    // 0x8006AB3C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8006AB3C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_4:
    // 0x8006AB40: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006AB44: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006AB48: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006AB50: addiu       $a0, $a0, 0x16F8
    ctx->r4 = ADD32(ctx->r4, 0X16F8);
    // 0x8006AB54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AB58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006AB5C: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006AB60: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006AB64: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006AB68: blez        $t7, L_8006AB98
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006AB6C: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8006AB98;
    }
    // 0x8006AB6C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8006AB70:
    // 0x8006AB70: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8006AB74: nop

    // 0x8006AB78: addu        $t9, $t5, $s1
    ctx->r25 = ADD32(ctx->r13, ctx->r17);
    // 0x8006AB7C: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x8006AB80: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AB88: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AB8C: bne         $at, $zero, L_8006AB70
    if (ctx->r1 != 0) {
        // 0x8006AB90: nop
    
            goto L_8006AB70;
    }
    // 0x8006AB90: nop

    // 0x8006AB94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006AB98:
    // 0x8006AB98: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006AB9C: nop

    // 0x8006ABA0: blez        $a2, L_8006ABF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006ABA4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006ABF8;
    }
    // 0x8006ABA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006ABA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8006ABAC:
    // 0x8006ABAC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006ABB0: nop

    // 0x8006ABB4: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8006ABB8: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006ABBC: nop

    // 0x8006ABC0: bne         $a1, $t8, L_8006ABE4
    if (ctx->r5 != ctx->r24) {
        // 0x8006ABC4: nop
    
            goto L_8006ABE4;
    }
    // 0x8006ABC4: nop

    // 0x8006ABC8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8006ABCC: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006ABD0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006ABD4: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8006ABD8: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
    // 0x8006ABDC: lw          $a2, 0x16F0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X16F0);
    // 0x8006ABE0: nop

L_8006ABE4:
    // 0x8006ABE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006ABE8: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006ABEC: bne         $at, $zero, L_8006ABAC
    if (ctx->r1 != 0) {
        // 0x8006ABF0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006ABAC;
    }
    // 0x8006ABF0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006ABF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006ABF8:
    // 0x8006ABF8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006ABFC: jal         0x80071380
    // 0x8006AC00: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006AC00: nop

    after_5:
    // 0x8006AC04: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006AC08: jal         0x80071380
    // 0x8006AC0C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006AC0C: nop

    after_6:
    // 0x8006AC10: jal         0x80076EE4
    // 0x8006AC14: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    asset_table_load(rdram, ctx);
        goto after_7;
    // 0x8006AC14: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x8006AC18: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006AC1C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8006AC20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006AC24: beq         $t3, $a2, L_8006AC3C
    if (ctx->r11 == ctx->r6) {
        // 0x8006AC28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006AC3C;
    }
    // 0x8006AC28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006AC2C:
    // 0x8006AC2C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006AC30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AC34: bne         $t3, $t6, L_8006AC2C
    if (ctx->r11 != ctx->r14) {
        // 0x8006AC38: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006AC2C;
    }
    // 0x8006AC38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006AC3C:
    // 0x8006AC3C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006AC40: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8006AC44: addu        $t4, $v1, $a0
    ctx->r12 = ADD32(ctx->r3, ctx->r4);
    // 0x8006AC48: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8006AC4C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AC50: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    // 0x8006AC54: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8006AC58: jal         0x80070EDC
    // 0x8006AC5C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8006AC5C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_8:
    // 0x8006AC60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006AC64: addiu       $v1, $v1, 0x16EC
    ctx->r3 = ADD32(ctx->r3, 0X16EC);
    // 0x8006AC68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006AC6C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AC70: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006AC74: jal         0x80070EDC
    // 0x8006AC78: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8006AC78: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_9:
    // 0x8006AC7C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8006AC80: addiu       $s0, $s0, -0x2780
    ctx->r16 = ADD32(ctx->r16, -0X2780);
    // 0x8006AC84: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006AC88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006AC8C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006AC90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006AC94: jal         0x80077190
    // 0x8006AC98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_10;
    // 0x8006AC98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8006AC9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ACA0: addiu       $v1, $v1, 0x16EC
    ctx->r3 = ADD32(ctx->r3, 0X16EC);
    // 0x8006ACA4: blez        $s1, L_8006AD7C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006ACA8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8006AD7C;
    }
    // 0x8006ACA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006ACAC: andi        $a1, $s1, 0x3
    ctx->r5 = ctx->r17 & 0X3;
    // 0x8006ACB0: beq         $a1, $zero, L_8006ACEC
    if (ctx->r5 == 0) {
        // 0x8006ACB4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8006ACEC;
    }
    // 0x8006ACB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006ACB8: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
L_8006ACBC:
    // 0x8006ACBC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8006ACC0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006ACC4: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006ACC8: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8006ACCC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006ACD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006ACD4: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x8006ACD8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006ACDC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8006ACE0: bne         $a0, $a3, L_8006ACBC
    if (ctx->r4 != ctx->r7) {
        // 0x8006ACE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006ACBC;
    }
    // 0x8006ACE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006ACE8: beq         $a3, $s1, L_8006AD7C
    if (ctx->r7 == ctx->r17) {
        // 0x8006ACEC: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_8006AD7C;
    }
L_8006ACEC:
    // 0x8006ACEC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8006ACF0: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
L_8006ACF4:
    // 0x8006ACF4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006ACF8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006ACFC: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AD00: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8006AD04: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD08: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8006AD0C: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006AD10: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006AD14: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD18: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD1C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AD20: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8006AD24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD28: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AD2C: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x8006AD30: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8006AD34: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD38: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD3C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AD40: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8006AD44: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD48: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AD4C: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x8006AD50: sw          $t4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r12;
    // 0x8006AD54: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD5C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006AD60: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8006AD64: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD68: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AD6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006AD70: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x8006AD74: bne         $v0, $a0, L_8006ACF4
    if (ctx->r2 != ctx->r4) {
        // 0x8006AD78: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_8006ACF4;
    }
    // 0x8006AD78: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
L_8006AD7C:
    // 0x8006AD7C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD80: jal         0x80071380
    // 0x8006AD84: nop

    mempool_free(rdram, ctx);
        goto after_11;
    // 0x8006AD84: nop

    after_11:
    // 0x8006AD88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006AD8C: lw          $a0, -0x276C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X276C);
    // 0x8006AD90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006AD94: blez        $a0, L_8006ADBC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006AD98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006ADBC;
    }
    // 0x8006AD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006AD9C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006ADA0: addiu       $a1, $a1, -0x7C68
    ctx->r5 = ADD32(ctx->r5, -0X7C68);
L_8006ADA4:
    // 0x8006ADA4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8006ADA8: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x8006ADAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006ADB0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006ADB4: bne         $at, $zero, L_8006ADA4
    if (ctx->r1 != 0) {
        // 0x8006ADB8: addu        $v1, $v1, $t5
        ctx->r3 = ADD32(ctx->r3, ctx->r13);
            goto L_8006ADA4;
    }
    // 0x8006ADB8: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8006ADBC:
    // 0x8006ADBC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006ADC0: lw          $t9, -0x2770($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2770);
    // 0x8006ADC4: nop

    // 0x8006ADC8: beq         $v1, $t9, L_8006ADDC
    if (ctx->r3 == ctx->r25) {
        // 0x8006ADCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006ADDC;
    }
    // 0x8006ADCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006ADD0: jal         0x8006A8E0
    // 0x8006ADD4: nop

    drm_disable_input(rdram, ctx);
        goto after_12;
    // 0x8006ADD4: nop

    after_12:
    // 0x8006ADD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006ADDC:
    // 0x8006ADDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006ADE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006ADE4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ADE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006ADEC: jr          $ra
    // 0x8006ADF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006ADF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8006ABB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADF4: bgez        $a0, L_8006AE04
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006ADF8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006AE04;
    }
    // 0x8006ADF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006ADFC: jr          $ra
    // 0x8006AE00: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006AE00: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006AE04:
    // 0x8006AE04: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006AE08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006AE0C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AE10: bne         $at, $zero, L_8006AE20
    if (ctx->r1 != 0) {
        // 0x8006AE14: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006AE14: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006AE18: jr          $ra
    // 0x8006AE1C: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006AE1C: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006AE20:
    // 0x8006AE20: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006AE24: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006AE28: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006AE2C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006AE30: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x8006AE34: nop

    // 0x8006AE38: jr          $ra
    // 0x8006AE3C: nop

    return;
    // 0x8006AE3C: nop

;}
RECOMP_FUNC void search_level_properties_forwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006AE44: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006AE48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006AE4C: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006AE50: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006AE54: bgez        $a0, L_8006AE64
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AE58: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006AE64;
    }
    // 0x8006AE58: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006AE5C: b           L_8006AE68
    // 0x8006AE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8006AE68;
    // 0x8006AE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006AE64:
    // 0x8006AE64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8006AE68:
    // 0x8006AE68: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006AE6C: beq         $a1, $at, L_8006AF9C
    if (ctx->r5 == ctx->r1) {
        // 0x8006AE70: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8006AF9C;
    }
    // 0x8006AE70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AE74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AE78: bne         $a2, $v0, L_8006AED8
    if (ctx->r6 != ctx->r2) {
        // 0x8006AE7C: nop
    
            goto L_8006AED8;
    }
    // 0x8006AE7C: nop

    // 0x8006AE80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AE84: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AE88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AE8C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AE90: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AE94: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AE94: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AE98: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006AE9C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AEA0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AEA4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AEA8:
    // 0x8006AEA8: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AEAC: nop

    // 0x8006AEB0: bne         $a1, $t2, L_8006AEC0
    if (ctx->r5 != ctx->r10) {
        // 0x8006AEB4: nop
    
            goto L_8006AEC0;
    }
    // 0x8006AEB4: nop

    // 0x8006AEB8: jr          $ra
    // 0x8006AEBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AEBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AEC0:
    // 0x8006AEC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AEC4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AEC8: bne         $at, $zero, L_8006AEA8
    if (ctx->r1 != 0) {
        // 0x8006AECC: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AEA8;
    }
    // 0x8006AECC: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AED0: b           L_8006B064
    // 0x8006AED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AED8:
    // 0x8006AED8: bne         $a1, $v0, L_8006AF34
    if (ctx->r5 != ctx->r2) {
        // 0x8006AEDC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006AF34;
    }
    // 0x8006AEDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AEE0: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AEE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006AEE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AEEC: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AEF0: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AEF0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006AEF4: lw          $t3, 0x16FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16FC);
    // 0x8006AEF8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006AEFC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006AF00: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
L_8006AF04:
    // 0x8006AF04: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8006AF08: nop

    // 0x8006AF0C: bne         $a2, $t5, L_8006AF1C
    if (ctx->r6 != ctx->r13) {
        // 0x8006AF10: nop
    
            goto L_8006AF1C;
    }
    // 0x8006AF10: nop

    // 0x8006AF14: jr          $ra
    // 0x8006AF18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AF18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AF1C:
    // 0x8006AF1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AF20: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF24: bne         $at, $zero, L_8006AF04
    if (ctx->r1 != 0) {
        // 0x8006AF28: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AF04;
    }
    // 0x8006AF28: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AF2C: b           L_8006B064
    // 0x8006AF30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AF30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF34:
    // 0x8006AF34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AF38: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AF40: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF44: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AF48: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AF48: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006AF4C: lw          $t6, 0x16FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16FC);
    // 0x8006AF50: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006AF54: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006AF58: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_8006AF5C:
    // 0x8006AF5C: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8006AF60: nop

    // 0x8006AF64: bne         $a1, $t8, L_8006AF84
    if (ctx->r5 != ctx->r24) {
        // 0x8006AF68: nop
    
            goto L_8006AF84;
    }
    // 0x8006AF68: nop

    // 0x8006AF6C: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8006AF70: nop

    // 0x8006AF74: bne         $a2, $t9, L_8006AF84
    if (ctx->r6 != ctx->r25) {
        // 0x8006AF78: nop
    
            goto L_8006AF84;
    }
    // 0x8006AF78: nop

    // 0x8006AF7C: jr          $ra
    // 0x8006AF80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AF80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AF84:
    // 0x8006AF84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AF88: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF8C: bne         $at, $zero, L_8006AF5C
    if (ctx->r1 != 0) {
        // 0x8006AF90: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AF5C;
    }
    // 0x8006AF90: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AF94: b           L_8006B064
    // 0x8006AF98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AF98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF9C:
    // 0x8006AF9C: bne         $a2, $v0, L_8006AFFC
    if (ctx->r6 != ctx->r2) {
        // 0x8006AFA0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006AFFC;
    }
    // 0x8006AFA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AFA4: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AFA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AFAC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AFB0: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AFB4: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AFB4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AFB8: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006AFBC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AFC0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AFC4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AFC8:
    // 0x8006AFC8: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AFCC: nop

    // 0x8006AFD0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006AFD4: beq         $t3, $zero, L_8006AFE4
    if (ctx->r11 == 0) {
        // 0x8006AFD8: nop
    
            goto L_8006AFE4;
    }
    // 0x8006AFD8: nop

    // 0x8006AFDC: jr          $ra
    // 0x8006AFE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AFE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AFE4:
    // 0x8006AFE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AFE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AFEC: bne         $at, $zero, L_8006AFC8
    if (ctx->r1 != 0) {
        // 0x8006AFF0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AFC8;
    }
    // 0x8006AFF0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AFF4: b           L_8006B064
    // 0x8006AFF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AFF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AFFC:
    // 0x8006AFFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B000: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006B004: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006B008: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B00C: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006B010: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006B010: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006B014: lw          $t4, 0x16FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X16FC);
    // 0x8006B018: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006B01C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006B020: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
L_8006B024:
    // 0x8006B024: lb          $t6, 0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1);
    // 0x8006B028: nop

    // 0x8006B02C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006B030: beq         $t7, $zero, L_8006B050
    if (ctx->r15 == 0) {
        // 0x8006B034: nop
    
            goto L_8006B050;
    }
    // 0x8006B034: nop

    // 0x8006B038: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8006B03C: nop

    // 0x8006B040: bne         $a2, $t8, L_8006B050
    if (ctx->r6 != ctx->r24) {
        // 0x8006B044: nop
    
            goto L_8006B050;
    }
    // 0x8006B044: nop

    // 0x8006B048: jr          $ra
    // 0x8006B04C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B04C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B050:
    // 0x8006B050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006B054: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B058: bne         $at, $zero, L_8006B024
    if (ctx->r1 != 0) {
        // 0x8006B05C: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006B024;
    }
    // 0x8006B05C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_8006B060:
    // 0x8006B060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B064:
    // 0x8006B064: jr          $ra
    // 0x8006B068: nop

    return;
    // 0x8006B068: nop

;}
RECOMP_FUNC void search_level_properties_backwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B06C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B070: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006B074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006B078: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006B07C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006B080: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006B084: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B088: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006B08C: bne         $at, $zero, L_8006B098
    if (ctx->r1 != 0) {
        // 0x8006B090: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006B098;
    }
    // 0x8006B090: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8006B098:
    // 0x8006B098: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006B09C: beq         $a1, $at, L_8006B1A0
    if (ctx->r5 == ctx->r1) {
        // 0x8006B0A0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8006B1A0;
    }
    // 0x8006B0A0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B0A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B0A8: bne         $a2, $v0, L_8006B0F8
    if (ctx->r6 != ctx->r2) {
        // 0x8006B0AC: nop
    
            goto L_8006B0F8;
    }
    // 0x8006B0AC: nop

    // 0x8006B0B0: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B0B4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B0B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006B0B8: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006B0BC: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006B0C0: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006B0C4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006B0C8: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006B0CC:
    // 0x8006B0CC: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006B0D0: nop

    // 0x8006B0D4: bne         $a1, $t2, L_8006B0E4
    if (ctx->r5 != ctx->r10) {
        // 0x8006B0D8: nop
    
            goto L_8006B0E4;
    }
    // 0x8006B0D8: nop

    // 0x8006B0DC: jr          $ra
    // 0x8006B0E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B0E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B0E4:
    // 0x8006B0E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B0E8: bgez        $a0, L_8006B0CC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B0EC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B0CC;
    }
    // 0x8006B0EC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B0F0: b           L_8006B250
    // 0x8006B0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B0F8:
    // 0x8006B0F8: bne         $a1, $v0, L_8006B148
    if (ctx->r5 != ctx->r2) {
        // 0x8006B0FC: nop
    
            goto L_8006B148;
    }
    // 0x8006B0FC: nop

    // 0x8006B100: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B104: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B104: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006B108: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006B10C: lw          $t3, 0x16FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16FC);
    // 0x8006B110: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006B114: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006B118: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_8006B11C:
    // 0x8006B11C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006B120: nop

    // 0x8006B124: bne         $a2, $t5, L_8006B134
    if (ctx->r6 != ctx->r13) {
        // 0x8006B128: nop
    
            goto L_8006B134;
    }
    // 0x8006B128: nop

    // 0x8006B12C: jr          $ra
    // 0x8006B130: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B130: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B134:
    // 0x8006B134: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B138: bgez        $a0, L_8006B11C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B13C: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B11C;
    }
    // 0x8006B13C: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B140: b           L_8006B250
    // 0x8006B144: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B144: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B148:
    // 0x8006B148: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B14C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B14C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B150: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006B154: lw          $t6, 0x16FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16FC);
    // 0x8006B158: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006B15C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006B160: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8006B164:
    // 0x8006B164: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006B168: nop

    // 0x8006B16C: bne         $a1, $t8, L_8006B18C
    if (ctx->r5 != ctx->r24) {
        // 0x8006B170: nop
    
            goto L_8006B18C;
    }
    // 0x8006B170: nop

    // 0x8006B174: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x8006B178: nop

    // 0x8006B17C: bne         $a2, $t9, L_8006B18C
    if (ctx->r6 != ctx->r25) {
        // 0x8006B180: nop
    
            goto L_8006B18C;
    }
    // 0x8006B180: nop

    // 0x8006B184: jr          $ra
    // 0x8006B188: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B188: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B18C:
    // 0x8006B18C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B190: bgez        $a0, L_8006B164
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B194: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B164;
    }
    // 0x8006B194: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B198: b           L_8006B250
    // 0x8006B19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B19C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B1A0:
    // 0x8006B1A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B1A4: bne         $a2, $v0, L_8006B1F8
    if (ctx->r6 != ctx->r2) {
        // 0x8006B1A8: nop
    
            goto L_8006B1F8;
    }
    // 0x8006B1A8: nop

    // 0x8006B1AC: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B1B0: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B1B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006B1B4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006B1B8: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006B1BC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006B1C0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006B1C4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006B1C8:
    // 0x8006B1C8: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006B1CC: nop

    // 0x8006B1D0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006B1D4: beq         $t3, $zero, L_8006B1E4
    if (ctx->r11 == 0) {
        // 0x8006B1D8: nop
    
            goto L_8006B1E4;
    }
    // 0x8006B1D8: nop

    // 0x8006B1DC: jr          $ra
    // 0x8006B1E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B1E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B1E4:
    // 0x8006B1E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B1E8: bgez        $a0, L_8006B1C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B1EC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B1C8;
    }
    // 0x8006B1EC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006B1F0: b           L_8006B250
    // 0x8006B1F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B250;
    // 0x8006B1F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B1F8:
    // 0x8006B1F8: bltz        $a0, L_8006B24C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B1FC: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8006B24C;
    }
    // 0x8006B1FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006B200: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006B204: lw          $t4, 0x16FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X16FC);
    // 0x8006B208: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006B20C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006B210: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_8006B214:
    // 0x8006B214: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8006B218: nop

    // 0x8006B21C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006B220: beq         $t7, $zero, L_8006B240
    if (ctx->r15 == 0) {
        // 0x8006B224: nop
    
            goto L_8006B240;
    }
    // 0x8006B224: nop

    // 0x8006B228: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8006B22C: nop

    // 0x8006B230: bne         $a2, $t8, L_8006B240
    if (ctx->r6 != ctx->r24) {
        // 0x8006B234: nop
    
            goto L_8006B240;
    }
    // 0x8006B234: nop

    // 0x8006B238: jr          $ra
    // 0x8006B23C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B23C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B240:
    // 0x8006B240: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B244: bgez        $a0, L_8006B214
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B248: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006B214;
    }
    // 0x8006B248: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
L_8006B24C:
    // 0x8006B24C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B250:
    // 0x8006B250: jr          $ra
    // 0x8006B254: nop

    return;
    // 0x8006B254: nop

;}
RECOMP_FUNC void leveltable_non_challenge_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B258: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B25C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B260: bltz        $t7, L_8006B288
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006B264: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006B288;
    }
    // 0x8006B264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B268: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8006B26C: beq         $at, $zero, L_8006B288
    if (ctx->r1 == 0) {
        // 0x8006B270: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_8006B288;
    }
    // 0x8006B270: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006B274: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B278: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006B27C: lw          $v0, 0x1700($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1700);
    // 0x8006B280: jr          $ra
    // 0x8006B284: nop

    return;
    // 0x8006B284: nop

L_8006B288:
    // 0x8006B288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B28C: jr          $ra
    // 0x8006B290: nop

    return;
    // 0x8006B290: nop

;}
RECOMP_FUNC void leveltable_world_level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B294: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B298: lw          $a1, 0x16F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X16F0);
    // 0x8006B29C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B2A0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B2A4: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B2A8: blez        $a1, L_8006B2E4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006B2AC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006B2E4;
    }
    // 0x8006B2AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B2B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006B2B4: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x8006B2B8: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x8006B2BC: lw          $a2, 0x16FC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X16FC);
    // 0x8006B2C0: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8006B2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B2C8:
    // 0x8006B2C8: lb          $t8, 0x0($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X0);
    // 0x8006B2CC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006B2D0: bne         $a0, $t8, L_8006B2DC
    if (ctx->r4 != ctx->r24) {
        // 0x8006B2D4: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8006B2DC;
    }
    // 0x8006B2D4: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8006B2D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006B2DC:
    // 0x8006B2DC: bne         $at, $zero, L_8006B2C8
    if (ctx->r1 != 0) {
        // 0x8006B2E0: addiu       $a2, $a2, 0x6
        ctx->r6 = ADD32(ctx->r6, 0X6);
            goto L_8006B2C8;
    }
    // 0x8006B2E0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
L_8006B2E4:
    // 0x8006B2E4: jr          $ra
    // 0x8006B2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006B2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void leveltable_vehicle_default(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B2EC: blez        $a0, L_8006B32C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B2F0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B32C;
    }
    // 0x8006B2F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B2F4: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B2F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B2FC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B300: beq         $at, $zero, L_8006B32C
    if (ctx->r1 == 0) {
        // 0x8006B304: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B32C;
    }
    // 0x8006B304: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B308: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B30C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B310: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B314: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B318: lb          $v0, 0x2($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X2);
    // 0x8006B31C: nop

    // 0x8006B320: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B324: jr          $ra
    // 0x8006B328: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B328: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B32C:
    // 0x8006B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B330: jr          $ra
    // 0x8006B334: nop

    return;
    // 0x8006B334: nop

;}
RECOMP_FUNC void leveltable_vehicle_usable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B338: blez        $a0, L_8006B380
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B33C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B380;
    }
    // 0x8006B33C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B340: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B344: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B348: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B34C: beq         $at, $zero, L_8006B380
    if (ctx->r1 == 0) {
        // 0x8006B350: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B380;
    }
    // 0x8006B350: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B354: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B358: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B35C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B360: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B364: lb          $v1, 0x2($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X2);
    // 0x8006B368: nop

    // 0x8006B36C: beq         $v1, $zero, L_8006B380
    if (ctx->r3 == 0) {
        // 0x8006B370: sra         $v0, $v1, 4
        ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
            goto L_8006B380;
    }
    // 0x8006B370: sra         $v0, $v1, 4
    ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8006B374: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B378: jr          $ra
    // 0x8006B37C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B37C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B380:
    // 0x8006B380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B384: jr          $ra
    // 0x8006B388: nop

    return;
    // 0x8006B388: nop

;}
RECOMP_FUNC void leveltable_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B38C: bltz        $a0, L_8006B3C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B390: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B3C4;
    }
    // 0x8006B390: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B394: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B398: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B39C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B3A0: beq         $at, $zero, L_8006B3C4
    if (ctx->r1 == 0) {
        // 0x8006B3A4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B3C4;
    }
    // 0x8006B3A4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B3A8: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B3AC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B3B0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B3B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B3B8: lb          $v0, 0x1($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X1);
    // 0x8006B3BC: jr          $ra
    // 0x8006B3C0: nop

    return;
    // 0x8006B3C0: nop

L_8006B3C4:
    // 0x8006B3C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B3C8: jr          $ra
    // 0x8006B3CC: nop

    return;
    // 0x8006B3CC: nop

;}
RECOMP_FUNC void leveltable_world(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3D0: bltz        $a0, L_8006B408
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B3D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B408;
    }
    // 0x8006B3D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B3D8: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B3DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B3E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B3E4: beq         $at, $zero, L_8006B408
    if (ctx->r1 == 0) {
        // 0x8006B3E8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B408;
    }
    // 0x8006B3E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B3EC: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B3F0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B3F4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B3F8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B3FC: lb          $v0, 0x0($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X0);
    // 0x8006B400: jr          $ra
    // 0x8006B404: nop

    return;
    // 0x8006B404: nop

L_8006B408:
    // 0x8006B408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B40C: jr          $ra
    // 0x8006B410: nop

    return;
    // 0x8006B410: nop

;}
RECOMP_FUNC void level_world_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B41C: bltz        $a0, L_8006B43C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B420: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006B43C;
    }
    // 0x8006B420: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006B424: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B428: lw          $t6, 0x16F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F4);
    // 0x8006B42C: nop

    // 0x8006B430: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B434: bne         $at, $zero, L_8006B444
    if (ctx->r1 != 0) {
        // 0x8006B438: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8006B444;
    }
    // 0x8006B438: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B43C:
    // 0x8006B43C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006B440: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B444:
    // 0x8006B444: jal         0x8001E2D0
    // 0x8006B448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8006B448: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006B44C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006B450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B454: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B458: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8006B45C: jr          $ra
    // 0x8006B460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006B460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B464: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B468: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B46C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B470: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006B474: lw          $t7, 0x16F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16F4);
    // 0x8006B478: jr          $ra
    // 0x8006B47C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x8006B47C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void level_is_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B480: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B484: lw          $v0, -0x2774($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2774);
    // 0x8006B488: jr          $ra
    // 0x8006B48C: nop

    return;
    // 0x8006B48C: nop

;}
RECOMP_FUNC void level_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B490: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006B494: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006B498: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8006B49C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8006B4A0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006B4A4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8006B4A8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006B4AC: jal         0x80072954
    // 0x8006B4B0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x8006B4B0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006B4B4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8006B4B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B4BC: bne         $t6, $v0, L_8006B4CC
    if (ctx->r14 != ctx->r2) {
        // 0x8006B4C0: lw          $t7, 0x64($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X64);
            goto L_8006B4CC;
    }
    // 0x8006B4C0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4C4: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B4C8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
L_8006B4CC:
    // 0x8006B4CC: nop

    // 0x8006B4D0: bne         $t7, $v0, L_8006B4E4
    if (ctx->r15 != ctx->r2) {
        // 0x8006B4D4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006B4E4;
    }
    // 0x8006B4D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B4D8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8006B4DC: b           L_8006B4E8
    // 0x8006B4E0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
        goto L_8006B4E8;
    // 0x8006B4E0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
L_8006B4E4:
    // 0x8006B4E4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_8006B4E8:
    // 0x8006B4E8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4EC: nop

    // 0x8006B4F0: bne         $t9, $zero, L_8006B50C
    if (ctx->r25 != 0) {
        // 0x8006B4F4: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B50C;
    }
    // 0x8006B4F4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4F8: jal         0x8000318C
    // 0x8006B4FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_1;
    // 0x8006B4FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8006B500: b           L_8006B530
    // 0x8006B504: nop

        goto L_8006B530;
    // 0x8006B504: nop

    // 0x8006B508: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_8006B50C:
    // 0x8006B50C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B510: bne         $t2, $at, L_8006B528
    if (ctx->r10 != ctx->r1) {
        // 0x8006B514: nop
    
            goto L_8006B528;
    }
    // 0x8006B514: nop

    // 0x8006B518: jal         0x8000318C
    // 0x8006B51C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_2;
    // 0x8006B51C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_2:
    // 0x8006B520: b           L_8006B530
    // 0x8006B524: nop

        goto L_8006B530;
    // 0x8006B524: nop

L_8006B528:
    // 0x8006B528: jal         0x8000318C
    // 0x8006B52C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_3;
    // 0x8006B52C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
L_8006B530:
    // 0x8006B530: jal         0x8006ECD0
    // 0x8006B534: nop

    get_settings(rdram, ctx);
        goto after_4;
    // 0x8006B534: nop

    after_4:
    // 0x8006B538: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8006B53C: jal         0x80076EE4
    // 0x8006B540: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_5;
    // 0x8006B540: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_5:
    // 0x8006B544: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006B548: addiu       $t1, $t1, 0x16E0
    ctx->r9 = ADD32(ctx->r9, 0X16E0);
    // 0x8006B54C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8006B550: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8006B554: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8006B558: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B55C: beq         $t0, $t3, L_8006B574
    if (ctx->r8 == ctx->r11) {
        // 0x8006B560: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006B574;
    }
    // 0x8006B560: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006B564:
    // 0x8006B564: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8006B568: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B56C: bne         $t0, $t4, L_8006B564
    if (ctx->r8 != ctx->r12) {
        // 0x8006B570: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006B564;
    }
    // 0x8006B570: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006B574:
    // 0x8006B574: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8006B578: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006B57C: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006B580: bne         $at, $zero, L_8006B58C
    if (ctx->r1 != 0) {
        // 0x8006B584: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006B58C;
    }
    // 0x8006B584: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B588: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8006B58C:
    // 0x8006B58C: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8006B590: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B594: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8006B598: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006B59C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B5A0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8006B5A4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8006B5A8: subu        $a0, $t7, $s0
    ctx->r4 = SUB32(ctx->r15, ctx->r16);
    // 0x8006B5AC: jal         0x80070EDC
    // 0x8006B5B0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8006B5B0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_6:
    // 0x8006B5B4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006B5B8: addiu       $s1, $s1, 0x16E8
    ctx->r17 = ADD32(ctx->r17, 0X16E8);
    // 0x8006B5BC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B5C0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B5C4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B5C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B5CC: jal         0x80077190
    // 0x8006B5D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8006B5D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8006B5D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B5D8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B5DC: sb          $zero, -0x2760($at)
    MEM_B(-0X2760, ctx->r1) = 0;
    // 0x8006B5E0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B5E4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8006B5E8: lb          $t2, 0x4C($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X4C);
    // 0x8006B5EC: nop

    // 0x8006B5F0: bne         $t2, $zero, L_8006B600
    if (ctx->r10 != 0) {
        // 0x8006B5F4: nop
    
            goto L_8006B600;
    }
    // 0x8006B5F4: nop

    // 0x8006B5F8: jal         0x8006C524
    // 0x8006B5FC: nop

    level_properties_reset(rdram, ctx);
        goto after_8;
    // 0x8006B5FC: nop

    after_8:
L_8006B600:
    // 0x8006B600: jal         0x8006C530
    // 0x8006B604: nop

    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8006B604: nop

    after_9:
    // 0x8006B608: bne         $v0, $zero, L_8006B870
    if (ctx->r2 != 0) {
        // 0x8006B60C: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8006B870;
    }
    // 0x8006B60C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006B610: lh          $t3, -0x2764($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2764);
    // 0x8006B614: nop

    // 0x8006B618: bne         $t3, $zero, L_8006B874
    if (ctx->r11 != 0) {
        // 0x8006B61C: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B61C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B620: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B624: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B628: lb          $t4, 0x4C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B62C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B630: bne         $t4, $at, L_8006B72C
    if (ctx->r12 != ctx->r1) {
        // 0x8006B634: nop
    
            goto L_8006B72C;
    }
    // 0x8006B634: nop

    // 0x8006B638: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8006B63C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006B640: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B644: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006B648: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8006B64C: beq         $a0, $zero, L_8006B660
    if (ctx->r4 == 0) {
        // 0x8006B650: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006B660;
    }
    // 0x8006B650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B654: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B658: bne         $a0, $at, L_8006B668
    if (ctx->r4 != ctx->r1) {
        // 0x8006B65C: andi        $v1, $s0, 0x1
        ctx->r3 = ctx->r16 & 0X1;
            goto L_8006B668;
    }
    // 0x8006B65C: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B660:
    // 0x8006B660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B664: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B668:
    // 0x8006B668: beq         $v1, $zero, L_8006B67C
    if (ctx->r3 == 0) {
        // 0x8006B66C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_8006B67C;
    }
    // 0x8006B66C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B670: beq         $v0, $zero, L_8006B72C
    if (ctx->r2 == 0) {
        // 0x8006B674: nop
    
            goto L_8006B72C;
    }
    // 0x8006B674: nop

    // 0x8006B678: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_8006B67C:
    // 0x8006B67C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B680: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B684: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B688: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006B68C: jal         0x8006C3EC
    // 0x8006B690: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    level_properties_push(rdram, ctx);
        goto after_10;
    // 0x8006B690: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_10:
    // 0x8006B694: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006B698: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006B69C: lbu         $t2, 0x48($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X48);
    // 0x8006B6A0: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x8006B6A4: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8006B6A8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B6AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B6B0: and         $t5, $t9, $t4
    ctx->r13 = ctx->r25 & ctx->r12;
    // 0x8006B6B4: beq         $t5, $zero, L_8006B6C8
    if (ctx->r13 == 0) {
        // 0x8006B6B8: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8006B6C8;
    }
    // 0x8006B6B8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006B6BC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8006B6C0: b           L_8006B6CC
    // 0x8006B6C4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_8006B6CC;
    // 0x8006B6C4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006B6C8:
    // 0x8006B6C8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006B6CC:
    // 0x8006B6CC: beq         $v0, $zero, L_8006B6E8
    if (ctx->r2 == 0) {
        // 0x8006B6D0: nop
    
            goto L_8006B6E8;
    }
    // 0x8006B6D0: nop

    // 0x8006B6D4: beq         $v1, $zero, L_8006B6E8
    if (ctx->r3 == 0) {
        // 0x8006B6D8: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_8006B6E8;
    }
    // 0x8006B6D8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B6DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006B6E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B6E4: sb          $t8, -0x2760($at)
    MEM_B(-0X2760, ctx->r1) = ctx->r24;
L_8006B6E8:
    // 0x8006B6E8: jal         0x8001E2D0
    // 0x8006B6EC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x8006B6EC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_11:
    // 0x8006B6F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8006B6F4: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8006B6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006B6FC: beq         $a1, $t3, L_8006B718
    if (ctx->r5 == ctx->r11) {
        // 0x8006B700: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006B718;
    }
    // 0x8006B700: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006B704: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8006B708:
    // 0x8006B708: lb          $t2, 0x2($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X2);
    // 0x8006B70C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006B710: bne         $a1, $t2, L_8006B708
    if (ctx->r5 != ctx->r10) {
        // 0x8006B714: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8006B708;
    }
    // 0x8006B714: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8006B718:
    // 0x8006B718: addu        $t9, $s0, $v0
    ctx->r25 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B71C: lb          $t4, 0x1($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X1);
    // 0x8006B720: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8006B724: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B728: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
L_8006B72C:
    // 0x8006B72C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B730: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B734: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B738: nop

    // 0x8006B73C: bne         $a1, $at, L_8006B7F0
    if (ctx->r5 != ctx->r1) {
        // 0x8006B740: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B740: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B744: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B748: nop

    // 0x8006B74C: blez        $a0, L_8006B7EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B750: slti        $at, $a0, 0x5
        ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
            goto L_8006B7EC;
    }
    // 0x8006B750: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8006B754: beq         $at, $zero, L_8006B7F0
    if (ctx->r1 == 0) {
        // 0x8006B758: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B758: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B75C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8006B760: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B764: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x8006B768: sllv        $t3, $t8, $a0
    ctx->r11 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x8006B76C: and         $t2, $t7, $t3
    ctx->r10 = ctx->r15 & ctx->r11;
    // 0x8006B770: beq         $t2, $zero, L_8006B7EC
    if (ctx->r10 == 0) {
        // 0x8006B774: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8006B7EC;
    }
    // 0x8006B774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006B778: lw          $t5, 0x10($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X10);
    // 0x8006B77C: addiu       $t9, $a0, 0x1F
    ctx->r25 = ADD32(ctx->r4, 0X1F);
    // 0x8006B780: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x8006B784: sllv        $v0, $t4, $t9
    ctx->r2 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8006B788: and         $t8, $t5, $v0
    ctx->r24 = ctx->r13 & ctx->r2;
    // 0x8006B78C: bne         $t8, $zero, L_8006B7F0
    if (ctx->r24 != 0) {
        // 0x8006B790: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B790: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B794: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B798: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B79C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B7A0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B7A4: jal         0x8006C3EC
    // 0x8006B7A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8006B7A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_12:
    // 0x8006B7AC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006B7B0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006B7B4: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8006B7B8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B7BC: or          $t3, $t7, $v0
    ctx->r11 = ctx->r15 | ctx->r2;
    // 0x8006B7C0: jal         0x8001E2D0
    // 0x8006B7C4: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8006B7C4: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    after_13:
    // 0x8006B7C8: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B7CC: lb          $t4, -0x1($t2)
    ctx->r12 = MEM_B(ctx->r10, -0X1);
    // 0x8006B7D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B7D4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006B7D8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8006B7DC: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8006B7E0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B7E4: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B7E8: nop

L_8006B7EC:
    // 0x8006B7EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8006B7F0:
    // 0x8006B7F0: bne         $a1, $at, L_8006B874
    if (ctx->r5 != ctx->r1) {
        // 0x8006B7F4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B7F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B7F8: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8006B7FC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B800: bne         $t6, $zero, L_8006B874
    if (ctx->r14 != 0) {
        // 0x8006B804: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B804: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B808: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x8006B80C: nop

    // 0x8006B810: andi        $t7, $t8, 0x2000
    ctx->r15 = ctx->r24 & 0X2000;
    // 0x8006B814: bne         $t7, $zero, L_8006B874
    if (ctx->r15 != 0) {
        // 0x8006B818: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B818: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B81C: lbu         $t3, 0x17($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X17);
    // 0x8006B820: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B824: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8006B828: bne         $at, $zero, L_8006B874
    if (ctx->r1 != 0) {
        // 0x8006B82C: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B82C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B830: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B834: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B838: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B83C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B840: jal         0x8006C3EC
    // 0x8006B844: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8006B844: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    after_14:
    // 0x8006B848: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006B84C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B850: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8006B854: nop

    // 0x8006B858: ori         $t4, $t2, 0x2000
    ctx->r12 = ctx->r10 | 0X2000;
    // 0x8006B85C: jal         0x8001E2D0
    // 0x8006B860: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8006B860: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    after_15:
    // 0x8006B864: lb          $t9, 0x4($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4);
    // 0x8006B868: nop

    // 0x8006B86C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8006B870:
    // 0x8006B870: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8006B874:
    // 0x8006B874: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B87C: beq         $t6, $t8, L_8006B8D8
    if (ctx->r14 == ctx->r24) {
        // 0x8006B880: sh          $zero, -0x2764($at)
        MEM_H(-0X2764, ctx->r1) = 0;
            goto L_8006B8D8;
    }
    // 0x8006B880: sh          $zero, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = 0;
    // 0x8006B884: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B888: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006B88C: jal         0x80071380
    // 0x8006B890: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8006B890: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_16:
    // 0x8006B894: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006B898: lw          $t5, 0x16E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X16E0);
    // 0x8006B89C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8006B8A0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B8A4: addu        $v0, $t5, $t3
    ctx->r2 = ADD32(ctx->r13, ctx->r11);
    // 0x8006B8A8: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B8AC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8006B8B0: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B8B4: subu        $a0, $t2, $s0
    ctx->r4 = SUB32(ctx->r10, ctx->r16);
    // 0x8006B8B8: jal         0x80070EDC
    // 0x8006B8BC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8006B8BC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_17:
    // 0x8006B8C0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B8C4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B8C8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B8CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B8D0: jal         0x80077190
    // 0x8006B8D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_18;
    // 0x8006B8D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
L_8006B8D8:
    // 0x8006B8D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006B8DC: lw          $a0, 0x16E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E0);
    // 0x8006B8E0: jal         0x80071380
    // 0x8006B8E4: nop

    mempool_free(rdram, ctx);
        goto after_19;
    // 0x8006B8E4: nop

    after_19:
    // 0x8006B8E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B8EC: jal         0x8006C208
    // 0x8006B8F0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    aitable_init(rdram, ctx);
        goto after_20;
    // 0x8006B8F0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_20:
    // 0x8006B8F4: jal         0x8000CBC0
    // 0x8006B8F8: nop

    func_8000CBC0(rdram, ctx);
        goto after_21;
    // 0x8006B8F8: nop

    after_21:
    // 0x8006B8FC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006B900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B904: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B908: sw          $t4, 0x16E4($at)
    MEM_W(0X16E4, ctx->r1) = ctx->r12;
L_8006B90C:
    // 0x8006B90C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B910: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B914: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006B918: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8006B91C: nop

    // 0x8006B920: beq         $a0, $at, L_8006B964
    if (ctx->r4 == ctx->r1) {
        // 0x8006B924: nop
    
            goto L_8006B964;
    }
    // 0x8006B924: nop

    // 0x8006B928: jal         0x8001E2D0
    // 0x8006B92C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_22;
    // 0x8006B92C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_22:
    // 0x8006B930: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B934: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006B938: nop

    // 0x8006B93C: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B940: sw          $v0, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->r2;
    // 0x8006B944: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006B948: nop

    // 0x8006B94C: addu        $t3, $t5, $v1
    ctx->r11 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B950: lw          $a0, 0x74($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X74);
    // 0x8006B954: jal         0x8007F638
    // 0x8006B958: nop

    func_8007F1E8(rdram, ctx);
        goto after_23;
    // 0x8006B958: nop

    after_23:
    // 0x8006B95C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B960: nop

L_8006B964:
    // 0x8006B964: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006B968: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x8006B96C: bne         $at, $zero, L_8006B90C
    if (ctx->r1 != 0) {
        // 0x8006B970: nop
    
            goto L_8006B90C;
    }
    // 0x8006B970: nop

    // 0x8006B974: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8006B978: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8006B97C: bne         $t2, $at, L_8006B9E4
    if (ctx->r10 != ctx->r1) {
        // 0x8006B980: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B980: nop

    // 0x8006B984: jal         0x80099B68
    // 0x8006B988: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_24;
    // 0x8006B988: nop

    after_24:
    // 0x8006B98C: beq         $v0, $zero, L_8006B9B4
    if (ctx->r2 == 0) {
        // 0x8006B990: nop
    
            goto L_8006B9B4;
    }
    // 0x8006B990: nop

    // 0x8006B994: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006B998: nop

    // 0x8006B99C: lb          $t9, 0x4C($t4)
    ctx->r25 = MEM_B(ctx->r12, 0X4C);
    // 0x8006B9A0: nop

    // 0x8006B9A4: bne         $t9, $zero, L_8006B9E4
    if (ctx->r25 != 0) {
        // 0x8006B9A8: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9A8: nop

    // 0x8006B9AC: b           L_8006B9E4
    // 0x8006B9B0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
        goto L_8006B9E4;
    // 0x8006B9B0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B9B4:
    // 0x8006B9B4: jal         0x8009C814
    // 0x8006B9B8: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8006B9B8: nop

    after_25:
    // 0x8006B9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B9C0: bne         $v0, $at, L_8006B9E4
    if (ctx->r2 != ctx->r1) {
        // 0x8006B9C4: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9C4: nop

    // 0x8006B9C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006B9CC: nop

    // 0x8006B9D0: lb          $t8, 0x4C($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4C);
    // 0x8006B9D4: nop

    // 0x8006B9D8: bne         $t8, $zero, L_8006B9E4
    if (ctx->r24 != 0) {
        // 0x8006B9DC: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9DC: nop

    // 0x8006B9E0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B9E4:
    // 0x8006B9E4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B9E8: nop

    // 0x8006B9EC: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B9F0: nop

    // 0x8006B9F4: beq         $a1, $zero, L_8006BA00
    if (ctx->r5 == 0) {
        // 0x8006B9F8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006BA00;
    }
    // 0x8006B9F8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B9FC: bne         $a1, $at, L_8006BA10
    if (ctx->r5 != ctx->r1) {
        // 0x8006BA00: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006BA10;
    }
L_8006BA00:
    // 0x8006BA00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BA04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA08: b           L_8006BA18
    // 0x8006BA0C: sw          $t7, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = ctx->r15;
        goto L_8006BA18;
    // 0x8006BA0C: sw          $t7, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = ctx->r15;
L_8006BA10:
    // 0x8006BA10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA14: sw          $zero, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = 0;
L_8006BA18:
    // 0x8006BA18: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8006BA1C: nop

    // 0x8006BA20: beq         $t5, $zero, L_8006BA44
    if (ctx->r13 == 0) {
        // 0x8006BA24: nop
    
            goto L_8006BA44;
    }
    // 0x8006BA24: nop

    // 0x8006BA28: lb          $t3, 0x4C($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X4C);
    // 0x8006BA2C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006BA30: beq         $t3, $at, L_8006BA44
    if (ctx->r11 == ctx->r1) {
        // 0x8006BA34: addiu       $t2, $zero, 0x6
        ctx->r10 = ADD32(0, 0X6);
            goto L_8006BA44;
    }
    // 0x8006BA34: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8006BA38: sb          $t2, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r10;
    // 0x8006BA3C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA40: nop

L_8006BA44:
    // 0x8006BA44: lbu         $a0, 0xB3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB3);
    // 0x8006BA48: jal         0x80000BE0
    // 0x8006BA4C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_26;
    // 0x8006BA4C: nop

    after_26:
    // 0x8006BA50: jal         0x80000CBC
    // 0x8006BA54: nop

    music_volume_reset(rdram, ctx);
        goto after_27;
    // 0x8006BA54: nop

    after_27:
    // 0x8006BA58: jal         0x80031BF8
    // 0x8006BA5C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    lights_init(rdram, ctx);
        goto after_28;
    // 0x8006BA5C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_28:
    // 0x8006BA60: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BA64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BA68: bltz        $t4, L_8006BA8C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8006BA6C: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_8006BA8C;
    }
    // 0x8006BA6C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8006BA70: beq         $at, $zero, L_8006BA8C
    if (ctx->r1 == 0) {
        // 0x8006BA74: nop
    
            goto L_8006BA8C;
    }
    // 0x8006BA74: nop

    // 0x8006BA78: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA7C: nop

    // 0x8006BA80: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8006BA84: lb          $s0, 0x4F($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X4F);
    // 0x8006BA88: nop

L_8006BA8C:
    // 0x8006BA8C: jal         0x80017EA8
    // 0x8006BA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_taj_challenge_type(rdram, ctx);
        goto after_29;
    // 0x8006BA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8006BA94: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA98: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006BA9C: lb          $a0, 0x0($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X0);
    // 0x8006BAA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BAA4: lbu         $s0, 0x48($v1)
    ctx->r16 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAA8: beq         $a0, $at, L_8006BAB8
    if (ctx->r4 == ctx->r1) {
        // 0x8006BAAC: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_8006BAB8;
    }
    // 0x8006BAAC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006BAB0: sb          $a0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r4;
    // 0x8006BAB4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_8006BAB8:
    // 0x8006BAB8: bne         $s0, $zero, L_8006BAE4
    if (ctx->r16 != 0) {
        // 0x8006BABC: sb          $t7, 0x49($v1)
        MEM_B(0X49, ctx->r3) = ctx->r15;
            goto L_8006BAE4;
    }
    // 0x8006BABC: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x8006BAC0: lbu         $t5, 0x48($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAC4: nop

    // 0x8006BAC8: blez        $t5, L_8006BAE4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8006BACC: nop
    
            goto L_8006BAE4;
    }
    // 0x8006BACC: nop

    // 0x8006BAD0: jal         0x8006DD6C
    // 0x8006BAD4: nop

    get_level_default_vehicle(rdram, ctx);
        goto after_30;
    // 0x8006BAD4: nop

    after_30:
    // 0x8006BAD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BADC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006BAE0: sb          $v0, -0x277C($at)
    MEM_B(-0X277C, ctx->r1) = ctx->r2;
L_8006BAE4:
    // 0x8006BAE4: lbu         $t3, 0x48($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAE8: nop

    // 0x8006BAEC: bne         $t3, $zero, L_8006BB14
    if (ctx->r11 != 0) {
        // 0x8006BAF0: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006BB14;
    }
    // 0x8006BAF0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BAF4: blez        $s0, L_8006BB10
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006BAF8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8006BB10;
    }
    // 0x8006BAF8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006BAFC: lb          $v0, -0x277C($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X277C);
    // 0x8006BB00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BB04: beq         $v0, $at, L_8006BB14
    if (ctx->r2 == ctx->r1) {
        // 0x8006BB08: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006BB14;
    }
    // 0x8006BB08: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BB0C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
L_8006BB10:
    // 0x8006BB10: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
L_8006BB14:
    // 0x8006BB14: jal         0x8006DD60
    // 0x8006BB18: nop

    set_vehicle_id_for_menu(rdram, ctx);
        goto after_31;
    // 0x8006BB18: nop

    after_31:
    // 0x8006BB1C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006BB20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006BB24: lb          $t9, 0x4C($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4C);
    // 0x8006BB28: nop

    // 0x8006BB2C: bne         $t9, $at, L_8006BC20
    if (ctx->r25 != ctx->r1) {
        // 0x8006BB30: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB30: nop

    // 0x8006BB34: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006BB38: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8006BB3C: lbu         $a0, 0x48($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X48);
    // 0x8006BB40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006BB44: blez        $a0, L_8006BC20
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006BB48: addiu       $t4, $a0, 0x1F
        ctx->r12 = ADD32(ctx->r4, 0X1F);
            goto L_8006BC20;
    }
    // 0x8006BB48: addiu       $t4, $a0, 0x1F
    ctx->r12 = ADD32(ctx->r4, 0X1F);
    // 0x8006BB4C: bne         $a0, $at, L_8006BBA4
    if (ctx->r4 != ctx->r1) {
        // 0x8006BB50: sllv        $s0, $t6, $t4
        ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
            goto L_8006BBA4;
    }
    // 0x8006BB50: sllv        $s0, $t6, $t4
    ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
    // 0x8006BB54: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8006BB58: nop

    // 0x8006BB5C: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x8006BB60: nop

    // 0x8006BB64: slti        $at, $t7, 0x2F
    ctx->r1 = SIGNED(ctx->r15) < 0X2F ? 1 : 0;
    // 0x8006BB68: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BB6C: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB6C: nop

    // 0x8006BB70: lbu         $t5, 0x16($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X16);
    // 0x8006BB74: nop

    // 0x8006BB78: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8006BB7C: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BB80: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB80: nop

    // 0x8006BB84: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BB88: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006BB8C: and         $t3, $v0, $s0
    ctx->r11 = ctx->r2 & ctx->r16;
    // 0x8006BB90: bne         $t3, $zero, L_8006BC20
    if (ctx->r11 != 0) {
        // 0x8006BB94: or          $t2, $v0, $s0
        ctx->r10 = ctx->r2 | ctx->r16;
            goto L_8006BC20;
    }
    // 0x8006BB94: or          $t2, $v0, $s0
    ctx->r10 = ctx->r2 | ctx->r16;
    // 0x8006BB98: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8006BB9C: b           L_8006BC20
    // 0x8006BBA0: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
        goto L_8006BC20;
    // 0x8006BBA0: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006BBA4:
    // 0x8006BBA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8006BBA8: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8006BBAC: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8006BBB0: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
    // 0x8006BBB4: nop

    // 0x8006BBB8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006BBBC: bne         $at, $zero, L_8006BBFC
    if (ctx->r1 != 0) {
        // 0x8006BBC0: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8006BBFC;
    }
    // 0x8006BBC0: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8006BBC4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BBC8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006BBCC: and         $t7, $v0, $s0
    ctx->r15 = ctx->r2 & ctx->r16;
    // 0x8006BBD0: bne         $t7, $zero, L_8006BBF8
    if (ctx->r15 != 0) {
        // 0x8006BBD4: or          $t5, $v0, $s0
        ctx->r13 = ctx->r2 | ctx->r16;
            goto L_8006BBF8;
    }
    // 0x8006BBD4: or          $t5, $v0, $s0
    ctx->r13 = ctx->r2 | ctx->r16;
    // 0x8006BBD8: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006BBDC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8006BBE0: lbu         $t9, 0x48($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X48);
    // 0x8006BBE4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006BBE8: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8006BBEC: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8006BBF0: lh          $v1, 0x0($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X0);
    // 0x8006BBF4: nop

L_8006BBF8:
    // 0x8006BBF8: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_8006BBFC:
    // 0x8006BBFC: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BC00: sll         $t8, $s0, 5
        ctx->r24 = S32(ctx->r16 << 5);
            goto L_8006BC20;
    }
    // 0x8006BC00: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8006BC04: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BC08: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006BC0C: and         $t7, $v0, $t8
    ctx->r15 = ctx->r2 & ctx->r24;
    // 0x8006BC10: bne         $t7, $zero, L_8006BC20
    if (ctx->r15 != 0) {
        // 0x8006BC14: or          $t5, $v0, $t8
        ctx->r13 = ctx->r2 | ctx->r24;
            goto L_8006BC20;
    }
    // 0x8006BC14: or          $t5, $v0, $t8
    ctx->r13 = ctx->r2 | ctx->r24;
    // 0x8006BC18: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006BC1C: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_8006BC20:
    // 0x8006BC20: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC24: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006BC28: lb          $a1, 0x4C($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X4C);
    // 0x8006BC2C: beq         $t2, $zero, L_8006BC40
    if (ctx->r10 == 0) {
        // 0x8006BC30: nop
    
            goto L_8006BC40;
    }
    // 0x8006BC30: nop

    // 0x8006BC34: bne         $a1, $zero, L_8006BC40
    if (ctx->r5 != 0) {
        // 0x8006BC38: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_8006BC40;
    }
    // 0x8006BC38: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8006BC3C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006BC40:
    // 0x8006BC40: beq         $a1, $zero, L_8006BC50
    if (ctx->r5 == 0) {
        // 0x8006BC44: andi        $t4, $a1, 0x40
        ctx->r12 = ctx->r5 & 0X40;
            goto L_8006BC50;
    }
    // 0x8006BC44: andi        $t4, $a1, 0x40
    ctx->r12 = ctx->r5 & 0X40;
    // 0x8006BC48: beq         $t4, $zero, L_8006BC78
    if (ctx->r12 == 0) {
        // 0x8006BC4C: nop
    
            goto L_8006BC78;
    }
    // 0x8006BC4C: nop

L_8006BC50:
    // 0x8006BC50: jal         0x8009F1C4
    // 0x8006BC54: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_32;
    // 0x8006BC54: nop

    after_32:
    // 0x8006BC58: beq         $v0, $zero, L_8006BC78
    if (ctx->r2 == 0) {
        // 0x8006BC5C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006BC78;
    }
    // 0x8006BC5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BC60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BC64: sb          $t8, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = ctx->r24;
    // 0x8006BC68: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC6C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006BC70: b           L_8006BC88
    // 0x8006BC74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_8006BC88;
    // 0x8006BC74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006BC78:
    // 0x8006BC78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BC7C: sb          $zero, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = 0;
    // 0x8006BC80: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC84: nop

L_8006BC88:
    // 0x8006BC88: lb          $t5, 0x4C($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X4C);
    // 0x8006BC8C: nop

    // 0x8006BC90: bne         $t5, $zero, L_8006BCC0
    if (ctx->r13 != 0) {
        // 0x8006BC94: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BCC0;
    }
    // 0x8006BC94: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BC98: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8006BC9C: nop

    // 0x8006BCA0: bne         $t3, $zero, L_8006BCC0
    if (ctx->r11 != 0) {
        // 0x8006BCA4: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BCC0;
    }
    // 0x8006BCA4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BCA8: jal         0x8000E4C8
    // 0x8006BCAC: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_33;
    // 0x8006BCAC: nop

    after_33:
    // 0x8006BCB0: beq         $v0, $zero, L_8006BCBC
    if (ctx->r2 == 0) {
        // 0x8006BCB4: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8006BCBC;
    }
    // 0x8006BCB4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006BCB8: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006BCBC:
    // 0x8006BCBC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_8006BCC0:
    // 0x8006BCC0: jal         0x8001E484
    // 0x8006BCC4: nop

    cutscene_id_set(rdram, ctx);
        goto after_34;
    // 0x8006BCC4: nop

    after_34:
    // 0x8006BCC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCCC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8006BCD0: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8006BCD4: lh          $a1, 0x38($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X38);
    // 0x8006BCD8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BCDC: lh          $t6, 0x36($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X36);
    // 0x8006BCE0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8006BCE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BCE8: lh          $t4, 0xBA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XBA);
    // 0x8006BCEC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BCF0: jal         0x80024A30
    // 0x8006BCF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    init_track(rdram, ctx);
        goto after_35;
    // 0x8006BCF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_35:
    // 0x8006BCF8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCFC: nop

    // 0x8006BD00: lh          $t8, 0x3A($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BD04: nop

    // 0x8006BD08: bne         $t8, $zero, L_8006BD74
    if (ctx->r24 != 0) {
        // 0x8006BD0C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD10: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BD14: nop

    // 0x8006BD18: bne         $t7, $zero, L_8006BD74
    if (ctx->r15 != 0) {
        // 0x8006BD1C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD20: lh          $t5, 0x3E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X3E);
    // 0x8006BD24: nop

    // 0x8006BD28: bne         $t5, $zero, L_8006BD74
    if (ctx->r13 != 0) {
        // 0x8006BD2C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD30: lh          $t3, 0x40($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X40);
    // 0x8006BD34: nop

    // 0x8006BD38: bne         $t3, $zero, L_8006BD74
    if (ctx->r11 != 0) {
        // 0x8006BD3C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD40: lh          $t9, 0x42($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X42);
    // 0x8006BD44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD48: bne         $t9, $zero, L_8006BD70
    if (ctx->r25 != 0) {
        // 0x8006BD4C: nop
    
            goto L_8006BD70;
    }
    // 0x8006BD4C: nop

L_8006BD50:
    // 0x8006BD50: jal         0x800307FC
    // 0x8006BD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    reset_fog(rdram, ctx);
        goto after_36;
    // 0x8006BD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8006BD58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BD5C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BD60: bne         $s0, $at, L_8006BD50
    if (ctx->r16 != ctx->r1) {
        // 0x8006BD64: nop
    
            goto L_8006BD50;
    }
    // 0x8006BD64: nop

    // 0x8006BD68: b           L_8006BDAC
    // 0x8006BD6C: nop

        goto L_8006BDAC;
    // 0x8006BD6C: nop

L_8006BD70:
    // 0x8006BD70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006BD74:
    // 0x8006BD74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006BD7C: lh          $t2, 0x40($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X40);
    // 0x8006BD80: lh          $a1, 0x3A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BD84: lh          $a2, 0x3C($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BD88: lbu         $a3, 0x3F($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X3F);
    // 0x8006BD8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BD90: lh          $t6, 0x42($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X42);
    // 0x8006BD94: jal         0x800306A4
    // 0x8006BD98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    set_fog(rdram, ctx);
        goto after_37;
    // 0x8006BD98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_37:
    // 0x8006BD9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BDA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BDA4: bne         $s0, $at, L_8006BD74
    if (ctx->r16 != ctx->r1) {
        // 0x8006BDA8: nop
    
            goto L_8006BD74;
    }
    // 0x8006BDA8: nop

L_8006BDAC:
    // 0x8006BDAC: jal         0x8006ECD0
    // 0x8006BDB0: nop

    get_settings(rdram, ctx);
        goto after_38;
    // 0x8006BDB0: nop

    after_38:
    // 0x8006BDB4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006BDB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BDBC: lb          $a0, 0x0($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X0);
    // 0x8006BDC0: nop

    // 0x8006BDC4: beq         $a0, $at, L_8006BDD4
    if (ctx->r4 == ctx->r1) {
        // 0x8006BDC8: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8006BDD4;
    }
    // 0x8006BDC8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006BDCC: sb          $a0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r4;
    // 0x8006BDD0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8006BDD4:
    // 0x8006BDD4: nop

    // 0x8006BDD8: sb          $t8, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r24;
    // 0x8006BDDC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BDE0: nop

    // 0x8006BDE4: lh          $a1, 0x90($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X90);
    // 0x8006BDE8: nop

    // 0x8006BDEC: blez        $a1, L_8006BE60
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006BDF0: nop
    
            goto L_8006BE60;
    }
    // 0x8006BDF0: nop

    // 0x8006BDF4: lh          $t3, 0x9A($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X9A);
    // 0x8006BDF8: lh          $a2, 0x96($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X96);
    // 0x8006BDFC: lh          $a3, 0x98($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X98);
    // 0x8006BE00: lh          $a0, 0x92($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X92);
    // 0x8006BE04: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x8006BE08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006BE0C: lbu         $t2, 0x94($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X94);
    // 0x8006BE10: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x8006BE14: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BE18: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8006BE1C: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x8006BE20: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8006BE24: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8006BE28: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BE2C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BE30: lbu         $t4, 0x95($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X95);
    // 0x8006BE34: nop

    // 0x8006BE38: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BE3C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BE40: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006BE44: jal         0x800ABA08
    // 0x8006BE48: nop

    weather_reset(rdram, ctx);
        goto after_39;
    // 0x8006BE48: nop

    after_39:
    // 0x8006BE4C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006BE50: jal         0x800AB868
    // 0x8006BE54: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_40;
    // 0x8006BE54: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_40:
    // 0x8006BE58: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE5C: nop

L_8006BE60:
    // 0x8006BE60: lb          $t7, 0x49($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X49);
    // 0x8006BE64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BE68: bne         $t7, $at, L_8006BEA8
    if (ctx->r15 != ctx->r1) {
        // 0x8006BE6C: nop
    
            goto L_8006BEA8;
    }
    // 0x8006BE6C: nop

    // 0x8006BE70: lw          $a0, 0xA4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA4);
    // 0x8006BE74: jal         0x8007B2C4
    // 0x8006BE78: nop

    load_texture(rdram, ctx);
        goto after_41;
    // 0x8006BE78: nop

    after_41:
    // 0x8006BE7C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE80: nop

    // 0x8006BE84: sw          $v0, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->r2;
    // 0x8006BE88: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE8C: nop

    // 0x8006BE90: sh          $zero, 0xA8($t3)
    MEM_H(0XA8, ctx->r11) = 0;
    // 0x8006BE94: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE98: nop

    // 0x8006BE9C: sh          $zero, 0xAA($t9)
    MEM_H(0XAA, ctx->r25) = 0;
    // 0x8006BEA0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEA4: nop

L_8006BEA8:
    // 0x8006BEA8: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x8006BEAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BEB0: beq         $a0, $at, L_8006BEE8
    if (ctx->r4 == ctx->r1) {
        // 0x8006BEB4: nop
    
            goto L_8006BEE8;
    }
    // 0x8006BEB4: nop

    // 0x8006BEB8: jal         0x8001E2D0
    // 0x8006BEBC: nop

    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8006BEBC: nop

    after_42:
    // 0x8006BEC0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEC4: nop

    // 0x8006BEC8: sw          $v0, 0xAC($t2)
    MEM_W(0XAC, ctx->r10) = ctx->r2;
    // 0x8006BECC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006BED0: nop

    // 0x8006BED4: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8006BED8: jal         0x8007F864
    // 0x8006BEDC: nop

    init_pulsating_light_data(rdram, ctx);
        goto after_43;
    // 0x8006BEDC: nop

    after_43:
    // 0x8006BEE0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEE4: nop

L_8006BEE8:
    // 0x8006BEE8: lb          $t4, 0x9C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X9C);
    // 0x8006BEEC: nop

    // 0x8006BEF0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8006BEF4: jal         0x8006632C
    // 0x8006BEF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    cam_set_fov(rdram, ctx);
        goto after_44;
    // 0x8006BEF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_44:
    // 0x8006BEFC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BF00: nop

    // 0x8006BF04: lbu         $a0, 0x9D($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X9D);
    // 0x8006BF08: lbu         $a1, 0x9E($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X9E);
    // 0x8006BF0C: lbu         $a2, 0x9F($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X9F);
    // 0x8006BF10: jal         0x80077F84
    // 0x8006BF14: nop

    bgdraw_primcolour(rdram, ctx);
        goto after_45;
    // 0x8006BF14: nop

    after_45:
    // 0x8006BF18: jal         0x8007ADC4
    // 0x8006BF1C: nop

    video_delta_reset(rdram, ctx);
        goto after_46;
    // 0x8006BF1C: nop

    after_46:
    // 0x8006BF20: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006BF24: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006BF28: nop

    // 0x8006BF2C: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x8006BF30: lbu         $a0, 0x4($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X4);
    // 0x8006BF34: jal         0x8007AF74
    // 0x8006BF38: nop

    func_8007AB24(rdram, ctx);
        goto after_47;
    // 0x8006BF38: nop

    after_47:
    // 0x8006BF3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BF40: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8006BF44: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8006BF48: jr          $ra
    // 0x8006BF4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006BF4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void level_music_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BF58: lw          $t6, 0x16E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16E8);
    // 0x8006BF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF60: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8006BF64: lbu         $t7, 0x52($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X52);
    // 0x8006BF68: nop

    // 0x8006BF6C: beq         $t7, $zero, L_8006BFBC
    if (ctx->r15 == 0) {
        // 0x8006BF70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006BFBC;
    }
    // 0x8006BF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF74: jal         0x800012E8
    // 0x8006BF78: nop

    music_channel_reset_all(rdram, ctx);
        goto after_0;
    // 0x8006BF78: nop

    after_0:
    // 0x8006BF7C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006BF80: lw          $t8, 0x16E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X16E8);
    // 0x8006BF84: nop

    // 0x8006BF88: lbu         $a0, 0x52($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X52);
    // 0x8006BF8C: jal         0x80000B34
    // 0x8006BF90: nop

    music_play(rdram, ctx);
        goto after_1;
    // 0x8006BF90: nop

    after_1:
    // 0x8006BF94: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006BF98: jal         0x800014BC
    // 0x8006BF9C: nop

    music_tempo_set_relative(rdram, ctx);
        goto after_2;
    // 0x8006BF9C: nop

    after_2:
    // 0x8006BFA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006BFA4: lw          $t9, 0x16E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16E8);
    // 0x8006BFA8: nop

    // 0x8006BFAC: lhu         $a0, 0x54($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X54);
    // 0x8006BFB0: jal         0x80001074
    // 0x8006BFB4: nop

    music_dynamic_set(rdram, ctx);
        goto after_3;
    // 0x8006BFB4: nop

    after_3:
    // 0x8006BFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006BFBC:
    // 0x8006BFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFC0: jr          $ra
    // 0x8006BFC4: nop

    return;
    // 0x8006BFC4: nop

;}
RECOMP_FUNC void level_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BFCC: lw          $v0, 0x16E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E4);
    // 0x8006BFD0: jr          $ra
    // 0x8006BFD4: nop

    return;
    // 0x8006BFD4: nop

;}
RECOMP_FUNC void level_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFD8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BFDC: lw          $t6, 0x16E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16E8);
    // 0x8006BFE0: nop

    // 0x8006BFE4: lbu         $v0, 0x4C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4C);
    // 0x8006BFE8: jr          $ra
    // 0x8006BFEC: nop

    return;
    // 0x8006BFEC: nop

;}
RECOMP_FUNC void level_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BFF4: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006BFF8: jr          $ra
    // 0x8006BFFC: nop

    return;
    // 0x8006BFFC: nop

;}
RECOMP_FUNC void level_header_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C000: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C004: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006C008: nop

    // 0x8006C00C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006C010: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8006C014: jr          $ra
    // 0x8006C018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8006C018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void level_name(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C01C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C024: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006C028: bltz        $a0, L_8006C048
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006C02C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006C048;
    }
    // 0x8006C02C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C030: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006C034: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006C038: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C03C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006C040: bne         $at, $zero, L_8006C050
    if (ctx->r1 != 0) {
        // 0x8006C044: nop
    
            goto L_8006C050;
    }
    // 0x8006C044: nop

L_8006C048:
    // 0x8006C048: b           L_8006C12C
    // 0x8006C04C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006C12C;
    // 0x8006C04C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006C050:
    // 0x8006C050: lw          $t7, 0x16EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16EC);
    // 0x8006C054: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8006C058: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006C05C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8006C060: sb          $v1, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r3;
    // 0x8006C064: jal         0x8009F064
    // 0x8006C068: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_language(rdram, ctx);
        goto after_0;
    // 0x8006C068: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C06C: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
    // 0x8006C070: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C078: beq         $v0, $at, L_8006C098
    if (ctx->r2 == ctx->r1) {
        // 0x8006C07C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006C098;
    }
    // 0x8006C07C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C080: beq         $v0, $at, L_8006C0C8
    if (ctx->r2 == ctx->r1) {
        // 0x8006C084: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006C0C8;
    }
    // 0x8006C084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006C088: beq         $v0, $at, L_8006C0FC
    if (ctx->r2 == ctx->r1) {
        // 0x8006C08C: nop
    
            goto L_8006C0FC;
    }
    // 0x8006C08C: nop

    // 0x8006C090: b           L_8006C12C
    // 0x8006C094: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C094: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C098:
    // 0x8006C098: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C09C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C0A0: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C0A4: beq         $t0, $zero, L_8006C0B8
    if (ctx->r8 == 0) {
        // 0x8006C0A8: nop
    
            goto L_8006C0B8;
    }
    // 0x8006C0A8: nop

    // 0x8006C0AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C0B0: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8006C0B4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8006C0B8:
    // 0x8006C0B8: blez        $v1, L_8006C098
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006C0BC: nop
    
            goto L_8006C098;
    }
    // 0x8006C0BC: nop

    // 0x8006C0C0: b           L_8006C12C
    // 0x8006C0C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C0C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C0C8:
    // 0x8006C0C8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C0CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C0D0: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C0D4: beq         $t2, $zero, L_8006C0EC
    if (ctx->r10 == 0) {
        // 0x8006C0D8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8006C0EC;
    }
    // 0x8006C0D8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006C0DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C0E0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8006C0E4: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8006C0E8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_8006C0EC:
    // 0x8006C0EC: bne         $at, $zero, L_8006C0C8
    if (ctx->r1 != 0) {
        // 0x8006C0F0: nop
    
            goto L_8006C0C8;
    }
    // 0x8006C0F0: nop

    // 0x8006C0F4: b           L_8006C12C
    // 0x8006C0F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C0F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C0FC:
    // 0x8006C0FC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C104: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C108: beq         $t4, $zero, L_8006C120
    if (ctx->r12 == 0) {
        // 0x8006C10C: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8006C120;
    }
    // 0x8006C10C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8006C110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C114: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8006C118: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8006C11C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_8006C120:
    // 0x8006C120: bne         $at, $zero, L_8006C0FC
    if (ctx->r1 != 0) {
        // 0x8006C124: nop
    
            goto L_8006C0FC;
    }
    // 0x8006C124: nop

    // 0x8006C128: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C12C:
    // 0x8006C12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C130: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006C134: jr          $ra
    // 0x8006C138: nop

    return;
    // 0x8006C138: nop

;}
RECOMP_FUNC void level_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C13C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C144: jal         0x8006C3A4
    // 0x8006C148: nop

    aitable_free(rdram, ctx);
        goto after_0;
    // 0x8006C148: nop

    after_0:
    // 0x8006C14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006C150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C154: jal         0x80077F84
    // 0x8006C158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x8006C158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006C15C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C160: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
    // 0x8006C164: jal         0x80071380
    // 0x8006C168: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006C168: nop

    after_2:
    // 0x8006C16C: jal         0x800049D8
    // 0x8006C170: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_3;
    // 0x8006C170: nop

    after_3:
    // 0x8006C174: jal         0x80001844
    // 0x8006C178: nop

    music_stop(rdram, ctx);
        goto after_4;
    // 0x8006C178: nop

    after_4:
    // 0x8006C17C: jal         0x800018E0
    // 0x8006C180: nop

    music_jingle_stop(rdram, ctx);
        goto after_5;
    // 0x8006C180: nop

    after_5:
    // 0x8006C184: jal         0x800012E8
    // 0x8006C188: nop

    music_channel_reset_all(rdram, ctx);
        goto after_6;
    // 0x8006C188: nop

    after_6:
    // 0x8006C18C: jal         0x80031BA0
    // 0x8006C190: nop

    lights_free(rdram, ctx);
        goto after_7;
    // 0x8006C190: nop

    after_7:
    // 0x8006C194: jal         0x8002C814
    // 0x8006C198: nop

    free_track(rdram, ctx);
        goto after_8;
    // 0x8006C198: nop

    after_8:
    // 0x8006C19C: jal         0x80008174
    // 0x8006C1A0: nop

    audspat_reset(rdram, ctx);
        goto after_9;
    // 0x8006C1A0: nop

    after_9:
    // 0x8006C1A4: jal         0x80000968
    // 0x8006C1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_10;
    // 0x8006C1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8006C1AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C1B0: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006C1B4: nop

    // 0x8006C1B8: lh          $t6, 0x90($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X90);
    // 0x8006C1BC: nop

    // 0x8006C1C0: blez        $t6, L_8006C1DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006C1C4: nop
    
            goto L_8006C1DC;
    }
    // 0x8006C1C4: nop

    // 0x8006C1C8: jal         0x800AB8BC
    // 0x8006C1CC: nop

    weather_free(rdram, ctx);
        goto after_11;
    // 0x8006C1CC: nop

    after_11:
    // 0x8006C1D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C1D4: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006C1D8: nop

L_8006C1DC:
    // 0x8006C1DC: lb          $t7, 0x49($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X49);
    // 0x8006C1E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006C1E4: bne         $t7, $at, L_8006C1FC
    if (ctx->r15 != ctx->r1) {
        // 0x8006C1E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006C1FC;
    }
    // 0x8006C1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1EC: lw          $a0, 0xA4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA4);
    // 0x8006C1F0: jal         0x8007B70C
    // 0x8006C1F4: nop

    tex_free(rdram, ctx);
        goto after_12;
    // 0x8006C1F4: nop

    after_12:
    // 0x8006C1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006C1FC:
    // 0x8006C1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C200: jr          $ra
    // 0x8006C204: nop

    return;
    // 0x8006C204: nop

;}
RECOMP_FUNC void aitable_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C214: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006C218: jal         0x8009C814
    // 0x8006C21C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006C21C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8006C220: bne         $v0, $zero, L_8006C268
    if (ctx->r2 != 0) {
        // 0x8006C224: nop
    
            goto L_8006C268;
    }
    // 0x8006C224: nop

    // 0x8006C228: jal         0x8006ECD0
    // 0x8006C22C: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8006C22C: nop

    after_1:
    // 0x8006C230: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8006C234: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006C238: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006C23C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006C240: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8006C244: nop

    // 0x8006C248: andi        $t1, $a3, 0x2
    ctx->r9 = ctx->r7 & 0X2;
    // 0x8006C24C: beq         $t1, $zero, L_8006C258
    if (ctx->r9 == 0) {
        // 0x8006C250: andi        $t2, $a3, 0x4
        ctx->r10 = ctx->r7 & 0X4;
            goto L_8006C258;
    }
    // 0x8006C250: andi        $t2, $a3, 0x4
    ctx->r10 = ctx->r7 & 0X4;
    // 0x8006C254: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8006C258:
    // 0x8006C258: beq         $t2, $zero, L_8006C26C
    if (ctx->r10 == 0) {
        // 0x8006C25C: nop
    
            goto L_8006C26C;
    }
    // 0x8006C25C: nop

    // 0x8006C260: b           L_8006C26C
    // 0x8006C264: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8006C26C;
    // 0x8006C264: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8006C268:
    // 0x8006C268: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8006C26C:
    // 0x8006C26C: jal         0x80099B68
    // 0x8006C270: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_2;
    // 0x8006C270: nop

    after_2:
    // 0x8006C274: beq         $v0, $zero, L_8006C280
    if (ctx->r2 == 0) {
        // 0x8006C278: nop
    
            goto L_8006C280;
    }
    // 0x8006C278: nop

    // 0x8006C27C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8006C280:
    // 0x8006C280: jal         0x8009F1B4
    // 0x8006C284: nop

    is_in_adventure_two(rdram, ctx);
        goto after_3;
    // 0x8006C284: nop

    after_3:
    // 0x8006C288: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006C28C: beq         $v0, $zero, L_8006C2A4
    if (ctx->r2 == 0) {
        // 0x8006C290: addu        $t7, $s0, $t5
        ctx->r15 = ADD32(ctx->r16, ctx->r13);
            goto L_8006C2A4;
    }
    // 0x8006C290: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x8006C294: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x8006C298: sll         $t3, $s0, 24
    ctx->r11 = S32(ctx->r16 << 24);
    // 0x8006C29C: sra         $s0, $t3, 24
    ctx->r16 = S32(SIGNED(ctx->r11) >> 24);
    // 0x8006C2A0: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
L_8006C2A4:
    // 0x8006C2A4: lb          $s0, 0x0($t7)
    ctx->r16 = MEM_B(ctx->r15, 0X0);
    // 0x8006C2A8: jal         0x8009C850
    // 0x8006C2AC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8006C2AC: nop

    after_4:
    // 0x8006C2B0: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x8006C2B4: bgez        $t6, L_8006C2C0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006C2B8: nop
    
            goto L_8006C2C0;
    }
    // 0x8006C2B8: nop

    // 0x8006C2BC: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8006C2C0:
    // 0x8006C2C0: jal         0x8006DC4C
    // 0x8006C2C4: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x8006C2C4: nop

    after_5:
    // 0x8006C2C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C2CC: bne         $v0, $at, L_8006C2D8
    if (ctx->r2 != ctx->r1) {
        // 0x8006C2D0: nop
    
            goto L_8006C2D8;
    }
    // 0x8006C2D0: nop

    // 0x8006C2D4: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_8006C2D8:
    // 0x8006C2D8: jal         0x80076EE4
    // 0x8006C2DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8006C2DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8006C2E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C2E4: addiu       $t0, $t0, 0x16E0
    ctx->r8 = ADD32(ctx->r8, 0X16E0);
    // 0x8006C2E8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006C2EC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006C2F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006C2F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C2F8: beq         $a0, $t8, L_8006C324
    if (ctx->r4 == ctx->r24) {
        // 0x8006C2FC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006C324;
    }
    // 0x8006C2FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006C300:
    // 0x8006C300: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C304: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8006C308: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006C30C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8006C310: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8006C314: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006C318: nop

    // 0x8006C31C: bne         $a0, $t4, L_8006C300
    if (ctx->r4 != ctx->r12) {
        // 0x8006C320: nop
    
            goto L_8006C300;
    }
    // 0x8006C320: nop

L_8006C324:
    // 0x8006C324: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006C328: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x8006C32C: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8006C330: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006C334: bne         $at, $zero, L_8006C340
    if (ctx->r1 != 0) {
        // 0x8006C338: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006C340;
    }
    // 0x8006C338: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006C33C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006C340:
    // 0x8006C340: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8006C344: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006C348: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006C34C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8006C350: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006C354: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x8006C358: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8006C35C: jal         0x80070EDC
    // 0x8006C360: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8006C360: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_7:
    // 0x8006C364: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C368: addiu       $v1, $v1, 0x1740
    ctx->r3 = ADD32(ctx->r3, 0X1740);
    // 0x8006C36C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8006C370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006C374: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006C378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006C37C: jal         0x80077190
    // 0x8006C380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8006C380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8006C384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C388: lw          $a0, 0x16E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E0);
    // 0x8006C38C: jal         0x80071380
    // 0x8006C390: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8006C390: nop

    after_9:
    // 0x8006C394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C39C: jr          $ra
    // 0x8006C3A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C3A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void aitable_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C3AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3B0: lw          $a0, 0x1740($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1740);
    // 0x8006C3B4: jal         0x80071380
    // 0x8006C3B8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8006C3B8: nop

    after_0:
    // 0x8006C3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3C4: jr          $ra
    // 0x8006C3C8: nop

    return;
    // 0x8006C3C8: nop

;}
RECOMP_FUNC void aitable_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C3D0: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1740);
    // 0x8006C3D4: jr          $ra
    // 0x8006C3D8: nop

    return;
    // 0x8006C3D8: nop

;}
RECOMP_FUNC void race_is_adventure_2P(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C3E0: lb          $v0, -0x2778($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2778);
    // 0x8006C3E4: jr          $ra
    // 0x8006C3E8: nop

    return;
    // 0x8006C3E8: nop

;}
RECOMP_FUNC void level_properties_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3EC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C3F0: addiu       $t0, $t0, -0x2768
    ctx->r8 = ADD32(ctx->r8, -0X2768);
    // 0x8006C3F4: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C3F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C3FC: addiu       $v1, $v1, 0x1748
    ctx->r3 = ADD32(ctx->r3, 0X1748);
    // 0x8006C400: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C404: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C408: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x8006C40C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C410: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C414: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C418: nop

    // 0x8006C41C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8006C420: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x8006C424: sh          $a1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r5;
    // 0x8006C428: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8006C42C: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x8006C430: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C434: nop

    // 0x8006C438: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8006C43C: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8006C440: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x8006C444: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8006C448: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C44C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C450: nop

    // 0x8006C454: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C458: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C45C: sh          $a3, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r7;
    // 0x8006C460: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C464: jr          $ra
    // 0x8006C468: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    return;
    // 0x8006C468: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
;}
RECOMP_FUNC void level_properties_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C46C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C470: addiu       $t0, $t0, -0x2768
    ctx->r8 = ADD32(ctx->r8, -0X2768);
    // 0x8006C474: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x8006C478: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C47C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006C480: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006C484: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8006C488: addiu       $t1, $t1, 0x1748
    ctx->r9 = ADD32(ctx->r9, 0X1748);
    // 0x8006C48C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006C490: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8006C494: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8006C498: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006C49C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C4A0: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4A4: nop

    // 0x8006C4A8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8006C4AC: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C4B0: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4B4: nop

    // 0x8006C4B8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C4BC: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8006C4C0: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x8006C4C4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8006C4C8: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C4CC: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4D0: nop

    // 0x8006C4D4: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8006C4D8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006C4DC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8006C4E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C4E4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006C4E8: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4EC: nop

    // 0x8006C4F0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006C4F4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8006C4F8: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4FC: nop

    // 0x8006C500: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006C504: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8006C508: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x8006C50C: beq         $v1, $at, L_8006C518
    if (ctx->r3 == ctx->r1) {
        // 0x8006C510: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_8006C518;
    }
    // 0x8006C510: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8006C514: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006C518:
    // 0x8006C518: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C51C: jr          $ra
    // 0x8006C520: sh          $t3, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = ctx->r11;
    return;
    // 0x8006C520: sh          $t3, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = ctx->r11;
;}
