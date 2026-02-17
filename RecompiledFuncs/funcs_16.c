#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void cam_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800660E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800660E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800660EC: addiu       $t7, $t7, 0x12F0
    ctx->r15 = ADD32(ctx->r15, 0X12F0);
    // 0x800660F0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800660F4: addiu       $a0, $a0, 0x1320
    ctx->r4 = ADD32(ctx->r4, 0X1320);
    // 0x800660F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800660FC: sll         $t9, $v1, 6
    ctx->r25 = S32(ctx->r3 << 6);
    // 0x80066100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066104: sw          $a0, 0x12F0($at)
    MEM_W(0X12F0, ctx->r1) = ctx->r4;
    // 0x80066108: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8006610C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066110: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80066114: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80066118: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8006611C: addiu       $t0, $v1, 0x3
    ctx->r8 = ADD32(ctx->r3, 0X3);
    // 0x80066120: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x80066124: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80066128: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8006612C: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80066130: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80066134: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80066138: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8006613C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80066140: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80066144: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80066148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006614C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80066150: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80066154: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80066158: addiu       $s1, $s1, 0x1264
    ctx->r17 = ADD32(ctx->r17, 0X1264);
    // 0x8006615C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80066160: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80066164: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80066168:
    // 0x80066168: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8006616C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80066170: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80066174: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80066178: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8006617C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066180: jal         0x8006661C
    // 0x80066184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    camera_reset(rdram, ctx);
        goto after_0;
    // 0x80066184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80066188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006618C: bne         $s0, $s2, L_80066168
    if (ctx->r16 != ctx->r18) {
        // 0x80066190: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80066168;
    }
    // 0x80066190: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80066194: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066198: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
    // 0x8006619C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800661A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661A4: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x800661A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661AC: sw          $zero, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = 0;
    // 0x800661B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661B4: sw          $zero, 0x1260($at)
    MEM_W(0X1260, ctx->r1) = 0;
    // 0x800661B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661BC: sw          $zero, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = 0;
    // 0x800661C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661C4: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
    // 0x800661C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800661CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661D0: addiu       $a0, $a0, -0x2A30
    ctx->r4 = ADD32(ctx->r4, -0X2A30);
    // 0x800661D4: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x800661D8: sb          $zero, 0x1295($at)
    MEM_B(0X1295, ctx->r1) = 0;
    // 0x800661DC: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x800661E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800661E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800661E8: lui         $t6, 0xB000
    ctx->r14 = S32(0XB000 << 16);
    // 0x800661EC: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x800661F0: beq         $t4, $zero, L_8006620C
    if (ctx->r12 == 0) {
        // 0x800661F4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8006620C;
    }
    // 0x800661F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_800661F8:
    // 0x800661F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800661FC: nop

    // 0x80066200: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x80066204: bne         $t5, $zero, L_800661F8
    if (ctx->r13 != 0) {
        // 0x80066208: nop
    
            goto L_800661F8;
    }
    // 0x80066208: nop

L_8006620C:
    // 0x8006620C: lw          $t7, 0x578($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X578);
    // 0x80066210: ori         $at, $zero, 0x8965
    ctx->r1 = 0 | 0X8965;
    // 0x80066214: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80066218: beq         $t8, $at, L_80066228
    if (ctx->r24 == ctx->r1) {
        // 0x8006621C: addiu       $s0, $s0, 0x1460
        ctx->r16 = ADD32(ctx->r16, 0X1460);
            goto L_80066228;
    }
    // 0x8006621C: addiu       $s0, $s0, 0x1460
    ctx->r16 = ADD32(ctx->r16, 0X1460);
    // 0x80066220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80066224: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_80066228:
    // 0x80066228: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006622C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066230: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066234: lwc1        $f6, 0x762C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X762C);
    // 0x80066238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006623C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066240: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066244: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066248: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006624C: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x80066250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066254: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80066258: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006625C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80066260: jal         0x800CCE80
    // 0x80066264: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_1;
    // 0x80066264: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80066268: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006626C: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x80066270: jal         0x8006FAB0
    // 0x80066274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x80066274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066278: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8006627C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066280: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066288: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006628C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80066290: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80066294: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80066298: jr          $ra
    // 0x8006629C: swc1        $f10, 0x1290($at)
    MEM_W(0X1290, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8006629C: swc1        $f10, 0x1290($at)
    MEM_W(0X1290, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void cam_set_zoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662A0: bltz        $a0, L_800662D0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800662A4: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_800662D0;
    }
    // 0x800662A4: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800662A8: beq         $at, $zero, L_800662D0
    if (ctx->r1 == 0) {
        // 0x800662AC: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_800662D0;
    }
    // 0x800662AC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800662B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800662B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800662B8: sb          $a1, -0x2798($at)
    MEM_B(-0X2798, ctx->r1) = ctx->r5;
    // 0x800662BC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800662C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800662C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800662C8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800662CC: sb          $a1, 0x107B($at)
    MEM_B(0X107B, ctx->r1) = ctx->r5;
L_800662D0:
    // 0x800662D0: jr          $ra
    // 0x800662D4: nop

    return;
    // 0x800662D4: nop

;}
RECOMP_FUNC void enable_pal_viewport_height_adjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662D8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800662DC: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800662E0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800662E4: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800662E8: bne         $t8, $zero, L_800662F8
    if (ctx->r24 != 0) {
        // 0x800662EC: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800662F8;
    }
    // 0x800662EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800662F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800662F4: sb          $t7, 0x1295($at)
    MEM_B(0X1295, ctx->r1) = ctx->r15;
L_800662F8:
    // 0x800662F8: jr          $ra
    // 0x800662FC: nop

    return;
    // 0x800662FC: nop

;}
RECOMP_FUNC void cam_shake_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80066304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066308: jr          $ra
    // 0x8006630C: sw          $t6, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = ctx->r14;
    return;
    // 0x8006630C: sw          $t6, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void cam_shake_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066314: jr          $ra
    // 0x80066318: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
    return;
    // 0x80066318: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
;}
RECOMP_FUNC void cam_get_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006631C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066320: lwc1        $f0, 0x1290($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1290);
    // 0x80066324: jr          $ra
    // 0x80066328: nop

    return;
    // 0x80066328: nop

;}
RECOMP_FUNC void cam_set_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006632C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80066330: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066334: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80066338: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006633C: bc1f        L_800663C4
    if (!c1cs) {
        // 0x80066340: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_800663C4;
    }
    // 0x80066340: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80066344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066348: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006634C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80066350: addiu       $v0, $v0, 0x1290
    ctx->r2 = ADD32(ctx->r2, 0X1290);
    // 0x80066354: bc1f        L_800663C8
    if (!c1cs) {
        // 0x80066358: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800663C8;
    }
    // 0x80066358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006635C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066360: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066364: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x80066368: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    // 0x8006636C: bc1t        L_800663C4
    if (c1cs) {
        // 0x80066370: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800663C4;
    }
    // 0x80066370: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066374: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80066378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006637C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80066380: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066384: lwc1        $f16, 0x7630($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7630);
    // 0x80066388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006638C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80066390: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80066394: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066398: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006639C: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x800663A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800663A4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800663A8: jal         0x800CCE80
    // 0x800663AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800663AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800663B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800663B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800663B8: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x800663BC: jal         0x8006FAB0
    // 0x800663C0: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x800663C0: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    after_1:
L_800663C4:
    // 0x800663C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800663C8:
    // 0x800663C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800663CC: jr          $ra
    // 0x800663D0: nop

    return;
    // 0x800663D0: nop

;}
RECOMP_FUNC void cam_reset_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800663D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800663DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800663E0: lwc1        $f6, 0x7634($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7634);
    // 0x800663E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800663E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800663EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800663F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800663F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800663F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800663FC: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066400: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80066404: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x80066408: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    // 0x8006640C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80066410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80066414: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80066418: jal         0x800CCE80
    // 0x8006641C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x8006641C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80066420: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066424: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066428: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x8006642C: jal         0x8006FAB0
    // 0x80066430: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x80066430: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    after_1:
    // 0x80066434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80066438: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006643C: jr          $ra
    // 0x80066440: nop

    return;
    // 0x80066440: nop

;}
RECOMP_FUNC void mtx_get_modelmtx_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066444: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066448: jr          $ra
    // 0x8006644C: addiu       $v0, $v0, 0x1620
    ctx->r2 = ADD32(ctx->r2, 0X1620);
    return;
    // 0x8006644C: addiu       $v0, $v0, 0x1620
    ctx->r2 = ADD32(ctx->r2, 0X1620);
;}
RECOMP_FUNC void cam_get_viewport_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066450: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066454: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1260);
    // 0x80066458: jr          $ra
    // 0x8006645C: nop

    return;
    // 0x8006645C: nop

;}
RECOMP_FUNC void get_current_viewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066460: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066464: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80066468: jr          $ra
    // 0x8006646C: nop

    return;
    // 0x8006646C: nop

;}
RECOMP_FUNC void camera_init_tracks_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066478: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006647C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80066480: jal         0x8006676C
    // 0x80066484: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80066484: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80066488: jal         0x80066828
    // 0x8006648C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8006648C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80066490: jal         0x80069F60
    // 0x80066494: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x80066494: nop

    after_2:
    // 0x80066498: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006649C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800664A0: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x800664A4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800664A8: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x800664AC: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x800664B0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800664B4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x800664B8: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x800664BC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800664C0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800664C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800664C8: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800664CC: nop

    // 0x800664D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800664D4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800664D8: nop

    // 0x800664DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800664E0: lh          $t9, 0x38($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X38);
    // 0x800664E4: nop

    // 0x800664E8: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x800664EC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800664F0: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800664F4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800664F8: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x800664FC: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x80066500: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x80066504: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x80066508: jal         0x8001D614
    // 0x8006650C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x8006650C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80066510: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80066514: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80066518: jal         0x80066F1C
    // 0x8006651C: nop

    viewport_main(rdram, ctx);
        goto after_4;
    // 0x8006651C: nop

    after_4:
    // 0x80066520: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80066524: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80066528: nop

    // 0x8006652C: sh          $t1, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r9;
    // 0x80066530: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80066534: nop

    // 0x80066538: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8006653C: lh          $t3, 0x28($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X28);
    // 0x80066540: nop

    // 0x80066544: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80066548: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8006654C: nop

    // 0x80066550: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80066554: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80066558: nop

    // 0x8006655C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80066560: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80066564: nop

    // 0x80066568: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8006656C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80066570: nop

    // 0x80066574: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x80066578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006657C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80066580: jr          $ra
    // 0x80066584: nop

    return;
    // 0x80066584: nop

;}
RECOMP_FUNC void get_distance_to_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006658C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066590: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80066594: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066598: lw          $v1, 0x1264($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1264);
    // 0x8006659C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665A0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800665A4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800665A8: beq         $t6, $zero, L_800665B4
    if (ctx->r14 == 0) {
        // 0x800665AC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800665B4;
    }
    // 0x800665AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800665B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800665B4:
    // 0x800665B4: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x800665B8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800665BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800665C0: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x800665C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800665C8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800665CC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800665D0: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800665D4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800665D8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800665DC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800665E0: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800665E4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800665E8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800665EC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800665F0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800665F4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800665F8: nop

    // 0x800665FC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80066600: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80066604: jal         0x800CA030
    // 0x80066608: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80066608: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8006660C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066614: jr          $ra
    // 0x80066618: nop

    return;
    // 0x80066618: nop

;}
RECOMP_FUNC void camera_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006661C: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x80066620: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066624: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80066628: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006662C: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80066630: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80066634: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80066638: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006663C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80066640: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066644: addiu       $t7, $t7, 0x1040
    ctx->r15 = ADD32(ctx->r15, 0X1040);
    // 0x80066648: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8006664C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80066650: mflo        $t8
    ctx->r24 = lo;
    // 0x80066654: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066658: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8006665C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066660: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80066664: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066668: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8006666C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066670: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80066674: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80066678: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8006667C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066680: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x80066684: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x80066688: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8006668C: mflo        $t1
    ctx->r9 = lo;
    // 0x80066690: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80066694: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x80066698: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006669C: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x800666A0: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800666A4: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x800666A8: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x800666AC: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x800666B0: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x800666B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800666B8: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800666BC: lbu         $t4, -0x2798($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2798);
    // 0x800666C0: jr          $ra
    // 0x800666C4: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
    return;
    // 0x800666C4: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void write_to_object_render_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800666CC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800666D0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800666D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800666D8: addiu       $t7, $t7, 0x1040
    ctx->r15 = ADD32(ctx->r15, 0X1040);
    // 0x800666DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800666E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800666E4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800666E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800666EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800666F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800666F4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800666F8: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x800666FC: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80066700: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x80066704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066708: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x8006670C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80066710: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80066714: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x80066718: swc1        $f14, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f14.u32l;
    // 0x8006671C: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80066720: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80066724: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80066728: jal         0x80029F58
    // 0x8006672C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x8006672C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    after_0:
    // 0x80066730: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80066734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006673C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066740: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80066744: sb          $t1, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = ctx->r9;
    // 0x80066748: jr          $ra
    // 0x8006674C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006674C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void check_if_showing_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066750: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066754: lb          $v0, 0x1294($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1294);
    // 0x80066758: jr          $ra
    // 0x8006675C: nop

    return;
    // 0x8006675C: nop

;}
RECOMP_FUNC void disable_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066764: jr          $ra
    // 0x80066768: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
    return;
    // 0x80066768: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
;}
RECOMP_FUNC void cam_set_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006676C: bltz        $a0, L_80066788
    if (SIGNED(ctx->r4) < 0) {
        // 0x80066770: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066788;
    }
    // 0x80066770: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066774: beq         $at, $zero, L_80066788
    if (ctx->r1 == 0) {
        // 0x80066778: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80066788;
    }
    // 0x80066778: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006677C: addiu       $v1, $v1, 0x1260
    ctx->r3 = ADD32(ctx->r3, 0X1260);
    // 0x80066780: b           L_80066794
    // 0x80066784: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80066794;
    // 0x80066784: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80066788:
    // 0x80066788: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006678C: addiu       $v1, $v1, 0x1260
    ctx->r3 = ADD32(ctx->r3, 0X1260);
    // 0x80066790: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80066794:
    // 0x80066794: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066798: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006679C: beq         $v0, $zero, L_800667D0
    if (ctx->r2 == 0) {
        // 0x800667A0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800667D0;
    }
    // 0x800667A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800667A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800667A8: beq         $v0, $at, L_800667DC
    if (ctx->r2 == ctx->r1) {
        // 0x800667AC: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800667DC;
    }
    // 0x800667AC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800667B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800667B4: beq         $v0, $at, L_800667E8
    if (ctx->r2 == ctx->r1) {
        // 0x800667B8: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800667E8;
    }
    // 0x800667B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800667BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800667C0: beq         $v0, $at, L_800667F4
    if (ctx->r2 == ctx->r1) {
        // 0x800667C4: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_800667F4;
    }
    // 0x800667C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800667C8: b           L_800667FC
    // 0x800667CC: nop

        goto L_800667FC;
    // 0x800667CC: nop

L_800667D0:
    // 0x800667D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667D4: b           L_800667FC
    // 0x800667D8: sw          $t6, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r14;
        goto L_800667FC;
    // 0x800667D8: sw          $t6, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r14;
L_800667DC:
    // 0x800667DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667E0: b           L_800667FC
    // 0x800667E4: sw          $t7, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r15;
        goto L_800667FC;
    // 0x800667E4: sw          $t7, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r15;
L_800667E8:
    // 0x800667E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667EC: b           L_800667FC
    // 0x800667F0: sw          $t8, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r24;
        goto L_800667FC;
    // 0x800667F0: sw          $t8, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r24;
L_800667F4:
    // 0x800667F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800667F8: sw          $t9, 0x1268($at)
    MEM_W(0X1268, ctx->r1) = ctx->r25;
L_800667FC:
    // 0x800667FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066800: addiu       $v0, $v0, 0x1264
    ctx->r2 = ADD32(ctx->r2, 0X1264);
    // 0x80066804: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80066808: lw          $v1, 0x1268($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1268);
    // 0x8006680C: nop

    // 0x80066810: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80066814: bne         $at, $zero, L_80066820
    if (ctx->r1 != 0) {
        // 0x80066818: nop
    
            goto L_80066820;
    }
    // 0x80066818: nop

    // 0x8006681C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80066820:
    // 0x80066820: jr          $ra
    // 0x80066824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80066824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void set_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066828: bltz        $a0, L_80066840
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006682C: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066840;
    }
    // 0x8006682C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066830: beq         $at, $zero, L_80066840
    if (ctx->r1 == 0) {
        // 0x80066834: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80066840;
    }
    // 0x80066834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066838: jr          $ra
    // 0x8006683C: sw          $a0, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r4;
    return;
    // 0x8006683C: sw          $a0, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r4;
L_80066840:
    // 0x80066840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066844: sw          $zero, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = 0;
    // 0x80066848: jr          $ra
    // 0x8006684C: nop

    return;
    // 0x8006684C: nop

;}
RECOMP_FUNC void copy_viewports_to_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066850: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80066854: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80066858: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8006685C: addiu       $s7, $s7, -0x295C
    ctx->r23 = ADD32(ctx->r23, -0X295C);
    // 0x80066860: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80066864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066868: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006686C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80066870: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066874: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80066878: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8006687C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80066880: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066884: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066888: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006688C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066890: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066894: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80066898: addiu       $s0, $s0, -0x2A2C
    ctx->r16 = ADD32(ctx->r16, -0X2A2C);
    // 0x8006689C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800668A0: addiu       $fp, $zero, -0x2
    ctx->r30 = ADD32(0, -0X2);
L_800668A4:
    // 0x800668A4: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x800668A8: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x800668AC: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x800668B0: beq         $t9, $zero, L_800668C8
    if (ctx->r25 == 0) {
        // 0x800668B4: andi        $t1, $v1, 0x2
        ctx->r9 = ctx->r3 & 0X2;
            goto L_800668C8;
    }
    // 0x800668B4: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x800668B8: and         $t0, $v1, $fp
    ctx->r8 = ctx->r3 & ctx->r30;
    // 0x800668BC: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800668C0: b           L_800668D8
    // 0x800668C4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_800668D8;
    // 0x800668C4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800668C8:
    // 0x800668C8: beq         $t1, $zero, L_800668D8
    if (ctx->r9 == 0) {
        // 0x800668CC: ori         $t2, $v1, 0x1
        ctx->r10 = ctx->r3 | 0X1;
            goto L_800668D8;
    }
    // 0x800668CC: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x800668D0: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x800668D4: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800668D8:
    // 0x800668D8: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x800668DC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800668E0: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800668E4: beq         $t4, $zero, L_80066A18
    if (ctx->r12 == 0) {
        // 0x800668E8: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80066A18;
    }
    // 0x800668E8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800668EC: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x800668F0: bne         $t5, $zero, L_80066918
    if (ctx->r13 != 0) {
        // 0x800668F4: andi        $t2, $v1, 0x10
        ctx->r10 = ctx->r3 & 0X10;
            goto L_80066918;
    }
    // 0x800668F4: andi        $t2, $v1, 0x10
    ctx->r10 = ctx->r3 & 0X10;
    // 0x800668F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800668FC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80066900: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80066904: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80066908: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006690C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80066910: b           L_80066928
    // 0x80066914: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
        goto L_80066928;
    // 0x80066914: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
L_80066918:
    // 0x80066918: lw          $s5, 0x10($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X10);
    // 0x8006691C: nop

    // 0x80066920: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x80066924: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
L_80066928:
    // 0x80066928: bne         $t2, $zero, L_80066950
    if (ctx->r10 != 0) {
        // 0x8006692C: andi        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 & 0X20;
            goto L_80066950;
    }
    // 0x8006692C: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80066930: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80066934: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80066938: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8006693C: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80066940: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80066944: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80066948: b           L_80066960
    // 0x8006694C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
        goto L_80066960;
    // 0x8006694C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
L_80066950:
    // 0x80066950: lw          $s4, 0x14($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X14);
    // 0x80066954: nop

    // 0x80066958: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8006695C: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
L_80066960:
    // 0x80066960: bne         $t7, $zero, L_80066988
    if (ctx->r15 != 0) {
        // 0x80066964: andi        $t5, $v1, 0x40
        ctx->r13 = ctx->r3 & 0X40;
            goto L_80066988;
    }
    // 0x80066964: andi        $t5, $v1, 0x40
    ctx->r13 = ctx->r3 & 0X40;
    // 0x80066968: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8006696C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80066970: nop

    // 0x80066974: subu        $s1, $t0, $t1
    ctx->r17 = SUB32(ctx->r8, ctx->r9);
    // 0x80066978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006697C: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x80066980: b           L_80066998
    // 0x80066984: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
        goto L_80066998;
    // 0x80066984: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_80066988:
    // 0x80066988: lw          $s1, 0x18($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X18);
    // 0x8006698C: nop

    // 0x80066990: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80066994: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80066998:
    // 0x80066998: bne         $t5, $zero, L_800669C0
    if (ctx->r13 != 0) {
        // 0x8006699C: nop
    
            goto L_800669C0;
    }
    // 0x8006699C: nop

    // 0x800669A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800669A4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800669A8: nop

    // 0x800669AC: subu        $s2, $t6, $t3
    ctx->r18 = SUB32(ctx->r14, ctx->r11);
    // 0x800669B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800669B4: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x800669B8: b           L_800669D0
    // 0x800669BC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_800669D0;
    // 0x800669BC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_800669C0:
    // 0x800669C0: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x800669C4: nop

    // 0x800669C8: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x800669CC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800669D0:
    // 0x800669D0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800669D4: nop

    // 0x800669D8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800669DC: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800669E0: addu        $s3, $s6, $t0
    ctx->r19 = ADD32(ctx->r22, ctx->r8);
    // 0x800669E4: jal         0x8009C850
    // 0x800669E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800669E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    after_0:
    // 0x800669EC: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800669F0: beq         $t1, $zero, L_800669FC
    if (ctx->r9 == 0) {
        // 0x800669F4: sll         $t2, $s3, 4
        ctx->r10 = S32(ctx->r19 << 4);
            goto L_800669FC;
    }
    // 0x800669F4: sll         $t2, $s3, 4
    ctx->r10 = S32(ctx->r19 << 4);
    // 0x800669F8: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
L_800669FC:
    // 0x800669FC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80066A00: addiu       $t4, $t4, -0x2948
    ctx->r12 = ADD32(ctx->r12, -0X2948);
    // 0x80066A04: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x80066A08: sh          $s5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r21;
    // 0x80066A0C: sh          $s4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r20;
    // 0x80066A10: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x80066A14: sh          $s2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r18;
L_80066A18:
    // 0x80066A18: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80066A1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80066A20: bne         $s6, $at, L_800668A4
    if (ctx->r22 != ctx->r1) {
        // 0x80066A24: addiu       $s0, $s0, 0x34
        ctx->r16 = ADD32(ctx->r16, 0X34);
            goto L_800668A4;
    }
    // 0x80066A24: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x80066A28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80066A2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066A30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80066A38: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80066A3C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066A40: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80066A44: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80066A48: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80066A4C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80066A50: jr          $ra
    // 0x80066A54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80066A54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void camEnableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A58: beq         $a1, $zero, L_80066A94
    if (ctx->r5 == 0) {
        // 0x80066A5C: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80066A94;
    }
    // 0x80066A5C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80066A60: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066A64: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066A68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066A6C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066A70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066A74: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066A78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066A7C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066A80: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066A84: nop

    // 0x80066A88: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80066A8C: b           L_80066AC0
    // 0x80066A90: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066AC0;
    // 0x80066A90: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066A94:
    // 0x80066A94: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80066A98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066A9C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80066AA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066AA4: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066AA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066AAC: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80066AB0: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066AB4: nop

    // 0x80066AB8: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80066ABC: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066AC0:
    // 0x80066AC0: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066AC4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80066AC8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80066ACC: jr          $ra
    // 0x80066AD0: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066AD0: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void camDisableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AD4: beq         $a1, $zero, L_80066B10
    if (ctx->r5 == 0) {
        // 0x80066AD8: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80066B10;
    }
    // 0x80066AD8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80066ADC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066AE0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066AE4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AE8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066AEC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066AF0: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066AF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AF8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066AFC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066B00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80066B04: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80066B08: b           L_80066B3C
    // 0x80066B0C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066B3C;
    // 0x80066B0C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066B10:
    // 0x80066B10: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80066B14: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066B18: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80066B1C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066B20: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066B24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066B28: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80066B2C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066B30: nop

    // 0x80066B34: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80066B38: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066B3C:
    // 0x80066B3C: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066B40: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80066B44: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80066B48: jr          $ra
    // 0x80066B4C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066B4C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void check_viewport_background_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066B54: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066B58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066B5C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066B60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066B64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80066B68: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80066B6C: lw          $v0, -0x29FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29FC);
    // 0x80066B70: nop

    // 0x80066B74: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80066B78: jr          $ra
    // 0x80066B7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066B7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void viewport_menu_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066B8C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066B90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80066B94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80066B98: jal         0x8007A970
    // 0x80066B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80066B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066BA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80066BA4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80066BA8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80066BAC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80066BB0: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80066BB4: beq         $at, $zero, L_80066BC8
    if (ctx->r1 == 0) {
        // 0x80066BB8: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80066BC8;
    }
    // 0x80066BB8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80066BBC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80066BC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80066BC4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80066BC8:
    // 0x80066BC8: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80066BCC: beq         $at, $zero, L_80066BDC
    if (ctx->r1 == 0) {
        // 0x80066BD0: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80066BDC;
    }
    // 0x80066BD0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80066BD4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066BD8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80066BDC:
    // 0x80066BDC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80066BE0: beq         $at, $zero, L_80066C04
    if (ctx->r1 == 0) {
        // 0x80066BE4: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_80066C04;
    }
    // 0x80066BE4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80066BE8: bltz        $a3, L_80066C04
    if (SIGNED(ctx->r7) < 0) {
        // 0x80066BEC: sra         $v1, $v0, 16
        ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80066C04;
    }
    // 0x80066BEC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80066BF0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80066BF4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80066BF8: beq         $at, $zero, L_80066C04
    if (ctx->r1 == 0) {
        // 0x80066BFC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80066C04;
    }
    // 0x80066BFC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80066C00: bgez        $a2, L_80066C34
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80066C04: subu        $t7, $t7, $t0
        ctx->r15 = SUB32(ctx->r15, ctx->r8);
            goto L_80066C34;
    }
L_80066C04:
    // 0x80066C04: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80066C08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066C0C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80066C10: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80066C14: addiu       $t8, $t8, -0x2A2C
    ctx->r24 = ADD32(ctx->r24, -0X2A2C);
    // 0x80066C18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066C1C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80066C20: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80066C24: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80066C28: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80066C2C: b           L_80066CC8
    // 0x80066C30: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
        goto L_80066CC8;
    // 0x80066C30: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
L_80066C34:
    // 0x80066C34: bgez        $a1, L_80066C64
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80066C38: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80066C64;
    }
    // 0x80066C38: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80066C3C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80066C40: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80066C44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066C48: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80066C4C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066C50: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066C54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066C58: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80066C5C: b           L_80066C88
    // 0x80066C60: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
        goto L_80066C88;
    // 0x80066C60: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
L_80066C64:
    // 0x80066C64: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80066C68: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80066C6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066C70: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80066C74: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80066C78: addiu       $t3, $t3, -0x2A2C
    ctx->r11 = ADD32(ctx->r11, -0X2A2C);
    // 0x80066C7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066C80: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80066C84: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
L_80066C88:
    // 0x80066C88: bgez        $s0, L_80066C98
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80066C8C: nop
    
            goto L_80066C98;
    }
    // 0x80066C8C: nop

    // 0x80066C90: b           L_80066C9C
    // 0x80066C94: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
        goto L_80066C9C;
    // 0x80066C94: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_80066C98:
    // 0x80066C98: sw          $s0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r16;
L_80066C9C:
    // 0x80066C9C: bne         $at, $zero, L_80066CAC
    if (ctx->r1 != 0) {
        // 0x80066CA0: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_80066CAC;
    }
    // 0x80066CA0: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x80066CA4: b           L_80066CB0
    // 0x80066CA8: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
        goto L_80066CB0;
    // 0x80066CA8: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
L_80066CAC:
    // 0x80066CAC: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
L_80066CB0:
    // 0x80066CB0: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80066CB4: bne         $at, $zero, L_80066CC4
    if (ctx->r1 != 0) {
        // 0x80066CB8: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80066CC4;
    }
    // 0x80066CB8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80066CBC: b           L_80066CC8
    // 0x80066CC0: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
        goto L_80066CC8;
    // 0x80066CC0: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
L_80066CC4:
    // 0x80066CC4: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
L_80066CC8:
    // 0x80066CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066CCC: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80066CD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066CD4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80066CD8: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x80066CDC: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80066CE0: jr          $ra
    // 0x80066CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80066CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_viewport_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CE8: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x80066CEC: beq         $a1, $t0, L_80066D28
    if (ctx->r5 == ctx->r8) {
        // 0x80066CF0: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_80066D28;
    }
    // 0x80066CF0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80066CF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066CF8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066CFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066D00: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066D04: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066D08: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066D0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066D10: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066D14: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066D18: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x80066D1C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80066D20: b           L_80066D54
    // 0x80066D24: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066D54;
    // 0x80066D24: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066D28:
    // 0x80066D28: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80066D2C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066D30: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x80066D34: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066D38: addiu       $t2, $t2, -0x2A2C
    ctx->r10 = ADD32(ctx->r10, -0X2A2C);
    // 0x80066D3C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066D40: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80066D44: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x80066D48: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80066D4C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80066D50: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
L_80066D54:
    // 0x80066D54: beq         $a2, $t0, L_80066D70
    if (ctx->r6 == ctx->r8) {
        // 0x80066D58: nop
    
            goto L_80066D70;
    }
    // 0x80066D58: nop

    // 0x80066D5C: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x80066D60: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x80066D64: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80066D68: b           L_80066D80
    // 0x80066D6C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
        goto L_80066D80;
    // 0x80066D6C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_80066D70:
    // 0x80066D70: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80066D74: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80066D78: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80066D7C: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
L_80066D80:
    // 0x80066D80: beq         $a3, $t0, L_80066D9C
    if (ctx->r7 == ctx->r8) {
        // 0x80066D84: nop
    
            goto L_80066D9C;
    }
    // 0x80066D84: nop

    // 0x80066D88: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80066D8C: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x80066D90: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80066D94: b           L_80066DAC
    // 0x80066D98: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
        goto L_80066DAC;
    // 0x80066D98: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
L_80066D9C:
    // 0x80066D9C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066DA0: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80066DA4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80066DA8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066DAC:
    // 0x80066DAC: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80066DB0: nop

    // 0x80066DB4: beq         $v1, $t0, L_80066DD0
    if (ctx->r3 == ctx->r8) {
        // 0x80066DB8: nop
    
            goto L_80066DD0;
    }
    // 0x80066DB8: nop

    // 0x80066DBC: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066DC0: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80066DC4: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80066DC8: jr          $ra
    // 0x80066DCC: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066DCC: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
L_80066DD0:
    // 0x80066DD0: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80066DD4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80066DD8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80066DDC: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x80066DE0: jr          $ra
    // 0x80066DE4: nop

    return;
    // 0x80066DE4: nop

;}
RECOMP_FUNC void copy_viewport_background_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066DEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066DF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066DF4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066DF8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066DFC: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066E00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E04: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066E08: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80066E0C: nop

    // 0x80066E10: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066E14: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x80066E18: nop

    // 0x80066E1C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80066E20: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x80066E24: nop

    // 0x80066E28: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80066E2C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066E30: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x80066E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066E38: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80066E3C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80066E40: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80066E44: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80066E48: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80066E4C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80066E50: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80066E54: bne         $t8, $zero, L_80066E64
    if (ctx->r24 != 0) {
        // 0x80066E58: nop
    
            goto L_80066E64;
    }
    // 0x80066E58: nop

    // 0x80066E5C: jr          $ra
    // 0x80066E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80066E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066E64:
    // 0x80066E64: jr          $ra
    // 0x80066E68: nop

    return;
    // 0x80066E68: nop

;}
RECOMP_FUNC void copy_viewport_frame_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E6C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066E70: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066E74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E78: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066E7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066E80: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066E84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E88: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066E8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80066E90: nop

    // 0x80066E94: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066E98: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80066E9C: nop

    // 0x80066EA0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80066EA4: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80066EA8: nop

    // 0x80066EAC: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80066EB0: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066EB4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80066EB8: jr          $ra
    // 0x80066EBC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    return;
    // 0x80066EBC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
;}
RECOMP_FUNC void copy_framebuffer_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066EC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80066ED0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80066ED4: jal         0x8007A970
    // 0x80066ED8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80066ED8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066EDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80066EE0: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80066EE4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80066EE8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80066EEC: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066EF0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80066EF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80066EF8: nop

    // 0x80066EFC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80066F00: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80066F04: nop

    // 0x80066F08: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80066F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F14: jr          $ra
    // 0x80066F18: nop

    return;
    // 0x80066F18: nop

;}
RECOMP_FUNC void viewport_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F1C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80066F20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066F24: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F28: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F2C: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x80066F30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066F34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066F38: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80066F3C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80066F40: jal         0x8000E184
    // 0x80066F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_player_two_in_control(rdram, ctx);
        goto after_0;
    // 0x80066F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x80066F48: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066F4C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F50: beq         $v0, $zero, L_80066F74
    if (ctx->r2 == 0) {
        // 0x80066F54: addiu       $ra, $ra, 0x1264
        ctx->r31 = ADD32(ctx->r31, 0X1264);
            goto L_80066F74;
    }
    // 0x80066F54: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066F5C: lw          $t6, 0x1260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1260);
    // 0x80066F60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80066F64: bne         $t6, $zero, L_80066F74
    if (ctx->r14 != 0) {
        // 0x80066F68: nop
    
            goto L_80066F74;
    }
    // 0x80066F68: nop

    // 0x80066F6C: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
    // 0x80066F70: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80066F74:
    // 0x80066F74: jal         0x8007A970
    // 0x80066F78: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    fb_size(rdram, ctx);
        goto after_1;
    // 0x80066F78: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_1:
    // 0x80066F7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066F80: addiu       $t3, $zero, 0x34
    ctx->r11 = ADD32(0, 0X34);
    // 0x80066F84: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066F88: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066F8C: addiu       $t2, $t2, -0x2A2C
    ctx->r10 = ADD32(ctx->r10, -0X2A2C);
    // 0x80066F90: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F94: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066F98: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066FA0: srl         $a3, $t0, 1
    ctx->r7 = S32(U32(ctx->r8) >> 1);
    // 0x80066FA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80066FA8: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80066FAC: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80066FB0: nop

    // 0x80066FB4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80066FB8: beq         $t7, $zero, L_8006714C
    if (ctx->r15 == 0) {
        // 0x80066FBC: nop
    
            goto L_8006714C;
    }
    // 0x80066FBC: nop

    // 0x80066FC0: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80066FC4: sw          $t1, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r9;
    // 0x80066FC8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80066FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80066FD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066FD4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066FD8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80066FDC: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80066FE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066FE4: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066FEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066FF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066FF8: mflo        $t7
    ctx->r15 = lo;
    // 0x80066FFC: addu        $v1, $t2, $t7
    ctx->r3 = ADD32(ctx->r10, ctx->r15);
    // 0x80067000: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80067004: nop

    // 0x80067008: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8006700C: nop

    // 0x80067010: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067014: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067018: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006701C: nop

    // 0x80067020: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067024: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067028: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006702C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067030: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067034: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067038: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x8006703C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067040: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80067044: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067048: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006704C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067050: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067054: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067058: nop

    // 0x8006705C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067060: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067064: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067068: nop

    // 0x8006706C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067070: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80067074: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067078: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8006707C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80067080: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067084: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80067088: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x8006708C: nop

    // 0x80067090: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067094: mflo        $t8
    ctx->r24 = lo;
    // 0x80067098: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x8006709C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x800670A0: nop

    // 0x800670A4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800670A8: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x800670AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800670B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800670B4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800670B8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800670BC: nop

    // 0x800670C0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800670C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800670C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800670CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800670D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800670D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800670D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800670DC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800670E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800670E4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800670E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800670EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800670F0: nop

    // 0x800670F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800670F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800670FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067100: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067104: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067108: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8006710C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80067110: jal         0x80068398
    // 0x80067114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_2;
    // 0x80067114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80067118: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8006711C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80067120: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067124: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80067128: beq         $a1, $zero, L_80067140
    if (ctx->r5 == 0) {
        // 0x8006712C: sw          $t6, 0x0($ra)
        MEM_W(0X0, ctx->r31) = ctx->r14;
            goto L_80067140;
    }
    // 0x8006712C: sw          $t6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r14;
    // 0x80067130: jal         0x80067F7C
    // 0x80067134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_3;
    // 0x80067134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80067138: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8006713C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
L_80067140:
    // 0x80067140: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80067144: b           L_80067C6C
    // 0x80067148: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
        goto L_80067C6C;
    // 0x80067148: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
L_8006714C:
    // 0x8006714C: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x80067150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80067154: bne         $v1, $a0, L_80067160
    if (ctx->r3 != ctx->r4) {
        // 0x80067158: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_80067160;
    }
    // 0x80067158: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8006715C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80067160:
    // 0x80067160: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067164: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067168: srl         $a2, $t1, 1
    ctx->r6 = S32(U32(ctx->r9) >> 1);
    // 0x8006716C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80067170: bne         $t2, $zero, L_80067180
    if (ctx->r10 != 0) {
        // 0x80067174: sw          $a3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r7;
            goto L_80067180;
    }
    // 0x80067174: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80067178: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8006717C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_80067180:
    // 0x80067180: beq         $v1, $zero, L_800671B4
    if (ctx->r3 == 0) {
        // 0x80067184: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800671B4;
    }
    // 0x80067184: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067188: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006718C: beq         $v1, $t3, L_8006728C
    if (ctx->r3 == ctx->r11) {
        // 0x80067190: nop
    
            goto L_8006728C;
    }
    // 0x80067190: nop

    // 0x80067194: beq         $v1, $a0, L_8006748C
    if (ctx->r3 == ctx->r4) {
        // 0x80067198: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8006748C;
    }
    // 0x80067198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8006719C: beq         $v1, $a1, L_80067684
    if (ctx->r3 == ctx->r5) {
        // 0x800671A0: srl         $t7, $a2, 1
        ctx->r15 = S32(U32(ctx->r6) >> 1);
            goto L_80067684;
    }
    // 0x800671A0: srl         $t7, $a2, 1
    ctx->r15 = S32(U32(ctx->r6) >> 1);
    // 0x800671A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800671A8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800671AC: b           L_80067C24
    // 0x800671B0: nop

        goto L_80067C24;
    // 0x800671B0: nop

L_800671B4:
    // 0x800671B4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800671B8: bne         $t2, $zero, L_800671C4
    if (ctx->r10 != 0) {
        // 0x800671BC: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800671C4;
    }
    // 0x800671BC: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800671C0: addiu       $t3, $t9, -0x12
    ctx->r11 = ADD32(ctx->r25, -0X12);
L_800671C4:
    // 0x800671C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800671C8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800671CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800671D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800671D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800671D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800671DC: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x800671E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800671E4: bgez        $t1, L_800671FC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800671E8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800671FC;
    }
    // 0x800671E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800671EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800671F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800671F4: nop

    // 0x800671F8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800671FC:
    // 0x800671FC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067200: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80067204: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067208: nop

    // 0x8006720C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067218: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006721C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067220: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80067224: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067228: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8006722C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80067230: bgez        $t0, L_80067244
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067234: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067244;
    }
    // 0x80067234: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006723C: nop

    // 0x80067240: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067244:
    // 0x80067244: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067248: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006724C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80067250: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067254: nop

    // 0x80067258: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8006725C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067264: nop

    // 0x80067268: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8006726C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80067270: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067274: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067278: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006727C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067280: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067284: b           L_80067C24
    // 0x80067288: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
        goto L_80067C24;
    // 0x80067288: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_8006728C:
    // 0x8006728C: lw          $t3, 0x0($ra)
    ctx->r11 = MEM_W(ctx->r31, 0X0);
    // 0x80067290: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067294: bne         $t3, $zero, L_8006736C
    if (ctx->r11 != 0) {
        // 0x80067298: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8006736C;
    }
    // 0x80067298: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006729C: srl         $v0, $t0, 2
    ctx->r2 = S32(U32(ctx->r8) >> 2);
    // 0x800672A0: bne         $t2, $zero, L_800672AC
    if (ctx->r10 != 0) {
        // 0x800672A4: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_800672AC;
    }
    // 0x800672A4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800672A8: addiu       $t3, $v0, -0xC
    ctx->r11 = ADD32(ctx->r2, -0XC);
L_800672AC:
    // 0x800672AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800672B0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800672B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800672B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800672BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800672C0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800672C4: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x800672C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800672CC: bgez        $t1, L_800672E4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800672D0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800672E4;
    }
    // 0x800672D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800672D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800672D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800672DC: nop

    // 0x800672E0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800672E4:
    // 0x800672E4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800672E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800672EC: nop

    // 0x800672F0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800672F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800672F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800672FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067300: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067304: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80067308: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006730C: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x80067310: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80067314: subu        $t7, $a3, $t6
    ctx->r15 = SUB32(ctx->r7, ctx->r14);
    // 0x80067318: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8006731C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80067320: bgez        $t7, L_80067334
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067324: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067334;
    }
    // 0x80067324: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006732C: nop

    // 0x80067330: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067334:
    // 0x80067334: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067338: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006733C: nop

    // 0x80067340: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006734C: nop

    // 0x80067350: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067354: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80067358: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006735C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067360: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067364: b           L_80067478
    // 0x80067368: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80067478;
    // 0x80067368: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8006736C:
    // 0x8006736C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067370: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067374: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x80067378: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8006737C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067380: srl         $t6, $t0, 2
    ctx->r14 = S32(U32(ctx->r8) >> 2);
    // 0x80067384: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80067388: addu        $t3, $a3, $t6
    ctx->r11 = ADD32(ctx->r7, ctx->r14);
    // 0x8006738C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067390: bgez        $t7, L_800673A8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067394: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800673A8;
    }
    // 0x80067394: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067398: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006739C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673A0: nop

    // 0x800673A4: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800673A8:
    // 0x800673A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800673AC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800673B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800673B4: nop

    // 0x800673B8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800673BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800673C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800673C4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800673C8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800673CC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800673D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800673D4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800673D8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800673DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800673E0: bgez        $t1, L_800673F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800673E4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800673F8;
    }
    // 0x800673E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800673E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800673EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673F0: nop

    // 0x800673F4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800673F8:
    // 0x800673F8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800673FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067400: nop

    // 0x80067404: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067408: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006740C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067410: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067414: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067418: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006741C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80067420: subu        $t9, $t0, $v1
    ctx->r25 = SUB32(ctx->r8, ctx->r3);
    // 0x80067424: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80067428: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8006742C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80067430: bgez        $t9, L_80067444
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067434: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067444;
    }
    // 0x80067434: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006743C: nop

    // 0x80067440: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067444:
    // 0x80067444: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067448: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006744C: nop

    // 0x80067450: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006745C: nop

    // 0x80067460: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067464: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067468: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006746C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067470: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80067474: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80067478:
    // 0x80067478: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006747C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067480: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80067484: b           L_80067C24
    // 0x80067488: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_80067C24;
    // 0x80067488: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8006748C:
    // 0x8006748C: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80067490: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80067494: bne         $t8, $zero, L_80067560
    if (ctx->r24 != 0) {
        // 0x80067498: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_80067560;
    }
    // 0x80067498: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006749C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800674A0: srl         $t6, $t1, 8
    ctx->r14 = S32(U32(ctx->r9) >> 8);
    // 0x800674A4: subu        $t8, $a2, $t6
    ctx->r24 = SUB32(ctx->r6, ctx->r14);
    // 0x800674A8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800674AC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800674B0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800674B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800674B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800674BC: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800674C0: srl         $a1, $t1, 2
    ctx->r5 = S32(U32(ctx->r9) >> 2);
    // 0x800674C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800674C8: bgez        $t8, L_800674E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800674CC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800674E0;
    }
    // 0x800674CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800674D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800674D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800674D8: nop

    // 0x800674DC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800674E0:
    // 0x800674E0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800674E4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800674E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800674EC: nop

    // 0x800674F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800674F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800674F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800674FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067500: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067504: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80067508: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006750C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067510: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80067514: bgez        $t0, L_80067528
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067518: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067528;
    }
    // 0x80067518: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006751C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067520: nop

    // 0x80067524: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067528:
    // 0x80067528: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006752C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067530: nop

    // 0x80067534: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067538: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006753C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067540: nop

    // 0x80067544: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067548: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8006754C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067550: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067554: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067558: b           L_80067674
    // 0x8006755C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_80067674;
    // 0x8006755C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80067560:
    // 0x80067560: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067564: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067568: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x8006756C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067570: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067574: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067578: srl         $t9, $t1, 2
    ctx->r25 = S32(U32(ctx->r9) >> 2);
    // 0x8006757C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067580: addu        $a1, $a2, $t9
    ctx->r5 = ADD32(ctx->r6, ctx->r25);
    // 0x80067584: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067588: bgez        $t6, L_800675A0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006758C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800675A0;
    }
    // 0x8006758C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067590: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067598: nop

    // 0x8006759C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800675A0:
    // 0x800675A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800675A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800675A8: nop

    // 0x800675AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800675B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800675B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800675B8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800675BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800675C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800675C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800675C8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800675CC: subu        $t9, $t1, $a0
    ctx->r25 = SUB32(ctx->r9, ctx->r4);
    // 0x800675D0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800675D4: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800675D8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800675DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800675E0: bgez        $t9, L_800675F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800675E4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800675F8;
    }
    // 0x800675E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800675E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800675EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800675F0: nop

    // 0x800675F4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800675F8:
    // 0x800675F8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800675FC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80067600: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067604: nop

    // 0x80067608: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8006760C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067614: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067618: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006761C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80067620: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067624: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067628: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8006762C: bgez        $t0, L_80067640
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067630: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067640;
    }
    // 0x80067630: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067638: nop

    // 0x8006763C: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067640:
    // 0x80067640: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067644: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067648: nop

    // 0x8006764C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067650: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067654: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067658: nop

    // 0x8006765C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067660: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067664: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067668: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8006766C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80067670: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80067674:
    // 0x80067674: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067678: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006767C: b           L_80067C24
    // 0x80067680: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_80067C24;
    // 0x80067680: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_80067684:
    // 0x80067684: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80067688: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x8006768C: srl         $t9, $t6, 1
    ctx->r25 = S32(U32(ctx->r14) >> 1);
    // 0x80067690: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80067694: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80067698: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8006769C: beq         $v0, $zero, L_800676C4
    if (ctx->r2 == 0) {
        // 0x800676A0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800676C4;
    }
    // 0x800676A0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800676A4: beq         $v0, $t3, L_8006782C
    if (ctx->r2 == ctx->r11) {
        // 0x800676A8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8006782C;
    }
    // 0x800676A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676AC: beq         $v0, $a0, L_80067954
    if (ctx->r2 == ctx->r4) {
        // 0x800676B0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067954;
    }
    // 0x800676B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676B4: beq         $v0, $a1, L_80067A78
    if (ctx->r2 == ctx->r5) {
        // 0x800676B8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067A78;
    }
    // 0x800676B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676BC: b           L_80067BF4
    // 0x800676C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x800676C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_800676C4:
    // 0x800676C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800676C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800676CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800676D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800676D8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800676DC: bgez        $zero, L_800676F4
    if (SIGNED(0) >= 0) {
        // 0x800676E0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800676F4;
    }
    // 0x800676E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800676E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800676E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800676EC: nop

    // 0x800676F0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800676F4:
    // 0x800676F4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800676F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800676FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067700: nop

    // 0x80067704: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006770C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067710: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067714: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067718: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8006771C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067720: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80067724: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80067728: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8006772C: bgez        $zero, L_80067744
    if (SIGNED(0) >= 0) {
        // 0x80067730: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067744;
    }
    // 0x80067730: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067734: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067738: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006773C: nop

    // 0x80067740: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067744:
    // 0x80067744: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067748: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006774C: nop

    // 0x80067750: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006775C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067760: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067764: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80067768: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006776C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067770: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80067774: srl         $t7, $t1, 8
    ctx->r15 = S32(U32(ctx->r9) >> 8);
    // 0x80067778: subu        $t6, $a2, $t7
    ctx->r14 = SUB32(ctx->r6, ctx->r15);
    // 0x8006777C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067780: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067784: bgez        $t6, L_80067798
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067788: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067798;
    }
    // 0x80067788: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006778C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067790: nop

    // 0x80067794: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067798:
    // 0x80067798: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006779C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800677A0: nop

    // 0x800677A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800677A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800677AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800677B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800677B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800677B8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800677BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800677C0: srl         $t8, $t0, 7
    ctx->r24 = S32(U32(ctx->r8) >> 7);
    // 0x800677C4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800677C8: subu        $t9, $a3, $t8
    ctx->r25 = SUB32(ctx->r7, ctx->r24);
    // 0x800677CC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800677D0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800677D4: bgez        $t9, L_800677E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800677D8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800677E8;
    }
    // 0x800677D8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800677DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800677E0: nop

    // 0x800677E4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800677E8:
    // 0x800677E8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800677EC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800677F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800677F4: nop

    // 0x800677F8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800677FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067800: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067804: nop

    // 0x80067808: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006780C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80067810: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067814: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067818: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8006781C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067820: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067824: b           L_80067BF4
    // 0x80067828: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067828: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_8006782C:
    // 0x8006782C: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067830: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067834: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x80067838: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006783C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067840: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067844: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067848: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006784C: bgez        $t6, L_80067864
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067850: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067864;
    }
    // 0x80067850: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067854: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006785C: nop

    // 0x80067860: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067864:
    // 0x80067864: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067868: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006786C: nop

    // 0x80067870: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067874: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067878: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006787C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067880: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067884: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80067888: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006788C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067890: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80067894: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067898: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8006789C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800678A0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800678A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800678A8: bgez        $t8, L_800678C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800678AC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800678C0;
    }
    // 0x800678AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800678B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800678B8: nop

    // 0x800678BC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800678C0:
    // 0x800678C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800678C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800678C8: nop

    // 0x800678CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800678D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800678D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800678D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800678E0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800678E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800678E8: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x800678EC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800678F0: subu        $t9, $a3, $t6
    ctx->r25 = SUB32(ctx->r7, ctx->r14);
    // 0x800678F4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800678F8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800678FC: bgez        $t9, L_80067910
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067900: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067910;
    }
    // 0x80067900: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067908: nop

    // 0x8006790C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067910:
    // 0x80067910: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067914: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067918: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006791C: nop

    // 0x80067920: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067924: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067928: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006792C: nop

    // 0x80067930: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067934: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80067938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006793C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80067940: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80067944: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067948: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x8006794C: b           L_80067BF4
    // 0x80067950: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067950: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067954:
    // 0x80067954: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067958: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006795C: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80067960: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067964: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067968: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8006796C: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067970: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80067974: bgez        $t8, L_8006798C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067978: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006798C;
    }
    // 0x80067978: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006797C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067980: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067984: nop

    // 0x80067988: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8006798C:
    // 0x8006798C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067990: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067994: nop

    // 0x80067998: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8006799C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800679A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800679A4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800679A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800679AC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800679B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800679B4: srl         $t9, $t1, 8
    ctx->r25 = S32(U32(ctx->r9) >> 8);
    // 0x800679B8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800679BC: subu        $t7, $a2, $t9
    ctx->r15 = SUB32(ctx->r6, ctx->r25);
    // 0x800679C0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800679C4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800679C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800679CC: bgez        $t7, L_800679E4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800679D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800679E4;
    }
    // 0x800679D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800679D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800679D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800679DC: nop

    // 0x800679E0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800679E4:
    // 0x800679E4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800679E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800679EC: nop

    // 0x800679F0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800679F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800679F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800679FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067A00: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067A04: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80067A08: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067A0C: addu        $t6, $a3, $a3
    ctx->r14 = ADD32(ctx->r7, ctx->r7);
    // 0x80067A10: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067A14: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x80067A18: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80067A1C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80067A20: bgez        $t8, L_80067A34
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067A24: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067A34;
    }
    // 0x80067A24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067A2C: nop

    // 0x80067A30: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067A34:
    // 0x80067A34: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067A38: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067A3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067A40: nop

    // 0x80067A44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067A48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067A4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067A50: nop

    // 0x80067A54: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067A58: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067A5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067A60: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067A64: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067A68: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80067A6C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067A70: b           L_80067BF4
    // 0x80067A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067A78:
    // 0x80067A78: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80067A80: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    // 0x80067A84: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80067A88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067A8C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80067A90: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067A94: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067A98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80067A9C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067AA0: bgez        $t7, L_80067AB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067AA4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80067AB8;
    }
    // 0x80067AA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067AA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067AAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067AB0: nop

    // 0x80067AB4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80067AB8:
    // 0x80067AB8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067ABC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067AC0: nop

    // 0x80067AC4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067AD0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067AD4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067AD8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80067ADC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067AE0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067AE4: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x80067AE8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80067AEC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067AF0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067AF4: bgez        $t9, L_80067B0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067AF8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067B0C;
    }
    // 0x80067AF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067AFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067B04: nop

    // 0x80067B08: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067B0C:
    // 0x80067B0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067B10: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067B14: nop

    // 0x80067B18: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067B1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067B20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067B24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B28: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067B2C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80067B30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067B34: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80067B38: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80067B3C: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067B40: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x80067B44: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067B48: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80067B4C: bgez        $t8, L_80067B60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067B50: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067B60;
    }
    // 0x80067B50: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067B54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067B58: nop

    // 0x80067B5C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067B60:
    // 0x80067B60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067B64: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067B68: nop

    // 0x80067B6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067B70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067B74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067B78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B7C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067B80: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067B84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067B88: addu        $t9, $a3, $a3
    ctx->r25 = ADD32(ctx->r7, ctx->r7);
    // 0x80067B8C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067B90: subu        $t6, $t9, $v1
    ctx->r14 = SUB32(ctx->r25, ctx->r3);
    // 0x80067B94: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80067B98: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80067B9C: bgez        $t6, L_80067BB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067BA0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80067BB0;
    }
    // 0x80067BA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067BA8: nop

    // 0x80067BAC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80067BB0:
    // 0x80067BB0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067BB4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067BB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067BBC: nop

    // 0x80067BC0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067BC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067BC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067BCC: nop

    // 0x80067BD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067BD4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80067BD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067BDC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067BE0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067BE4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80067BE8: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067BEC: nop

    // 0x80067BF0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067BF4:
    // 0x80067BF4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80067BF8: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x80067BFC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80067C00: bne         $t2, $zero, L_80067C24
    if (ctx->r10 != 0) {
        // 0x80067C04: addu        $a3, $t4, $t8
        ctx->r7 = ADD32(ctx->r12, ctx->r24);
            goto L_80067C24;
    }
    // 0x80067C04: addu        $a3, $t4, $t8
    ctx->r7 = ADD32(ctx->r12, ctx->r24);
    // 0x80067C08: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80067C0C: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x80067C10: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80067C14: beq         $at, $zero, L_80067C24
    if (ctx->r1 == 0) {
        // 0x80067C18: nop
    
            goto L_80067C24;
    }
    // 0x80067C18: nop

    // 0x80067C1C: b           L_80067C24
    // 0x80067C20: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
        goto L_80067C24;
    // 0x80067C20: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
L_80067C24:
    // 0x80067C24: bne         $t2, $zero, L_80067C30
    if (ctx->r10 != 0) {
        // 0x80067C28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80067C30;
    }
    // 0x80067C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067C2C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80067C30:
    // 0x80067C30: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80067C34: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80067C38: jal         0x80068398
    // 0x80067C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_rsp_set(rdram, ctx);
        goto after_4;
    // 0x80067C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80067C40: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80067C44: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067C48: beq         $a1, $zero, L_80067C60
    if (ctx->r5 == 0) {
        // 0x80067C4C: addiu       $ra, $ra, 0x1264
        ctx->r31 = ADD32(ctx->r31, 0X1264);
            goto L_80067C60;
    }
    // 0x80067C4C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80067C50: jal         0x80067F7C
    // 0x80067C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_5;
    // 0x80067C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80067C58: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067C5C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
L_80067C60:
    // 0x80067C60: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80067C64: nop

    // 0x80067C68: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
L_80067C6C:
    // 0x80067C6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067C70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80067C74: jr          $ra
    // 0x80067C78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80067C78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void viewport_scissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C84: jal         0x8007A970
    // 0x80067C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80067C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80067C8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80067C90: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x80067C94: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80067C98: beq         $v1, $zero, L_80067ED8
    if (ctx->r3 == 0) {
        // 0x80067C9C: andi        $t7, $v0, 0xFFFF
        ctx->r15 = ctx->r2 & 0XFFFF;
            goto L_80067ED8;
    }
    // 0x80067C9C: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80067CA0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80067CA4: bne         $v1, $t2, L_80067CB0
    if (ctx->r3 != ctx->r10) {
        // 0x80067CA8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80067CB0;
    }
    // 0x80067CA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80067CAC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80067CB0:
    // 0x80067CB0: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067CB4: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80067CB8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80067CBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80067CC0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80067CC4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80067CC8: beq         $v1, $t3, L_80067CEC
    if (ctx->r3 == ctx->r11) {
        // 0x80067CCC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80067CEC;
    }
    // 0x80067CCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80067CD0: beq         $v1, $t2, L_80067D1C
    if (ctx->r3 == ctx->r10) {
        // 0x80067CD4: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80067D1C;
    }
    // 0x80067CD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067CD8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80067CDC: beq         $v1, $t4, L_80067D48
    if (ctx->r3 == ctx->r12) {
        // 0x80067CE0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80067D48;
    }
    // 0x80067CE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80067CE4: b           L_80067DE4
    // 0x80067CE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067DE4;
    // 0x80067CE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067CEC:
    // 0x80067CEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067CF0: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80067CF4: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067CF8: bne         $t7, $zero, L_80067D10
    if (ctx->r15 != 0) {
        // 0x80067CFC: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067D10;
    }
    // 0x80067CFC: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D00: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D04: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D08: b           L_80067DE0
    // 0x80067D0C: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067D0C: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067D10:
    // 0x80067D10: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067D14: b           L_80067DE0
    // 0x80067D18: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067DE0;
    // 0x80067D18: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067D1C:
    // 0x80067D1C: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80067D20: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D24: bne         $t7, $zero, L_80067D3C
    if (ctx->r15 != 0) {
        // 0x80067D28: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80067D3C;
    }
    // 0x80067D28: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D2C: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D30: sra         $t9, $a1, 8
    ctx->r25 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D34: b           L_80067DE0
    // 0x80067D38: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067D38: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
L_80067D3C:
    // 0x80067D3C: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
    // 0x80067D40: b           L_80067DE0
    // 0x80067D44: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
        goto L_80067DE0;
    // 0x80067D44: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067D48:
    // 0x80067D48: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80067D4C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D50: beq         $v0, $zero, L_80067D78
    if (ctx->r2 == 0) {
        // 0x80067D54: sra         $t8, $a1, 8
        ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067D78;
    }
    // 0x80067D54: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D58: beq         $v0, $t3, L_80067D8C
    if (ctx->r2 == ctx->r11) {
        // 0x80067D5C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067D8C;
    }
    // 0x80067D5C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D60: beq         $v0, $t2, L_80067DA8
    if (ctx->r2 == ctx->r10) {
        // 0x80067D64: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067DA8;
    }
    // 0x80067D64: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D68: beq         $v0, $t4, L_80067DC4
    if (ctx->r2 == ctx->r12) {
        // 0x80067D6C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067DC4;
    }
    // 0x80067D6C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067D70: b           L_80067DE4
    // 0x80067D74: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067DE4;
    // 0x80067D74: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067D78:
    // 0x80067D78: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D7C: sra         $t6, $a0, 7
    ctx->r14 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D80: subu        $a3, $t9, $t6
    ctx->r7 = SUB32(ctx->r25, ctx->r14);
    // 0x80067D84: b           L_80067DE0
    // 0x80067D88: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
        goto L_80067DE0;
    // 0x80067D88: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
L_80067D8C:
    // 0x80067D8C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067D90: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067D94: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067D98: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x80067D9C: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
    // 0x80067DA0: b           L_80067DE0
    // 0x80067DA4: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067DE0;
    // 0x80067DA4: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067DA8:
    // 0x80067DA8: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067DAC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067DB0: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067DB4: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067DB8: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x80067DBC: b           L_80067DE0
    // 0x80067DC0: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067DE0;
    // 0x80067DC0: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067DC4:
    // 0x80067DC4: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067DC8: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067DCC: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067DD0: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067DD4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80067DD8: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
    // 0x80067DDC: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067DE0:
    // 0x80067DE0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067DE4:
    // 0x80067DE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067DE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067DEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067DF0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80067DF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067DF8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067DFC: nop

    // 0x80067E00: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80067E04: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067E08: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80067E0C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067E10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E18: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067E1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067E20: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80067E24: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067E28: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80067E2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067E30: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067E34: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067E38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067E3C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067E40: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067E44: nop

    // 0x80067E48: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067E4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E54: nop

    // 0x80067E58: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067E5C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80067E60: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067E64: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067E68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067E6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067E70: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067E74: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067E78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067E7C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067E80: nop

    // 0x80067E84: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067E88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067E90: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067E94: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067E98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067E9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067EA0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80067EA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067EA8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067EAC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80067EB0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067EB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067EB8: nop

    // 0x80067EBC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067EC0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80067EC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067EC8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067ECC: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80067ED0: b           L_80067F6C
    // 0x80067ED4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_80067F6C;
    // 0x80067ED4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80067ED8:
    // 0x80067ED8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80067EDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067EE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067EE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067EE8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067EEC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067EF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067EF4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80067EF8: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x80067EFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067F00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067F04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067F08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067F0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067F10: nop

    // 0x80067F14: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067F18: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067F1C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067F20: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067F24: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067F28: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80067F2C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80067F30: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80067F34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067F38: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067F3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067F40: nop

    // 0x80067F44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067F48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067F4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067F50: nop

    // 0x80067F54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067F58: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80067F5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067F60: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067F64: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067F68: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80067F6C:
    // 0x80067F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F74: jr          $ra
    // 0x80067F78: nop

    return;
    // 0x80067F78: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80067F88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80067F8C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80067F90: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80067F94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80067F98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80067F9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80067FA0: lhu         $t8, 0x12EC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X12EC);
    // 0x80067FA4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80067FA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80067FAC: addiu       $a2, $a2, 0x1264
    ctx->r6 = ADD32(ctx->r6, 0X1264);
    // 0x80067FB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80067FB4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80067FB8: lb          $t9, 0x1294($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X1294);
    // 0x80067FBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80067FC0: beq         $t9, $zero, L_80067FD4
    if (ctx->r25 == 0) {
        // 0x80067FC4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80067FD4;
    }
    // 0x80067FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067FC8: addiu       $t0, $a1, 0x4
    ctx->r8 = ADD32(ctx->r5, 0X4);
    // 0x80067FCC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80067FD0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80067FD4:
    // 0x80067FD4: sll         $t1, $a1, 4
    ctx->r9 = S32(ctx->r5 << 4);
    // 0x80067FD8: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80067FDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80067FE0: addiu       $t2, $t2, 0x1040
    ctx->r10 = ADD32(ctx->r10, 0X1040);
    // 0x80067FE4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80067FE8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80067FEC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x80067FF0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80067FF4: lh          $t5, 0x38($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X38);
    // 0x80067FF8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80067FFC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80068000: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80068004: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80068008: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8006800C: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80068010: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80068014: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80068018: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8006801C: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x80068020: sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // 0x80068024: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x80068028: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x8006802C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068030: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // 0x80068034: lw          $t9, 0x1298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1298);
    // 0x80068038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006803C: beq         $t9, $zero, L_80068058
    if (ctx->r25 == 0) {
        // 0x80068040: addiu       $a0, $a0, 0x14E0
        ctx->r4 = ADD32(ctx->r4, 0X14E0);
            goto L_80068058;
    }
    // 0x80068040: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    // 0x80068044: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068048: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8006804C: nop

    // 0x80068050: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80068054: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
L_80068058:
    // 0x80068058: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8006805C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80068060: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80068064: jal         0x800700B4
    // 0x80068068: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80068068: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_0:
    // 0x8006806C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068070: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068074: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068078: addiu       $a2, $a2, 0x14A0
    ctx->r6 = ADD32(ctx->r6, 0X14A0);
    // 0x8006807C: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    // 0x80068080: jal         0x8006F9A8
    // 0x80068084: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x80068084: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    after_1:
    // 0x80068088: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006808C: lw          $t0, 0x1264($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1264);
    // 0x80068090: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80068094: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80068098: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006809C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800680A0: addiu       $t2, $t2, 0x1040
    ctx->r10 = ADD32(ctx->r10, 0X1040);
    // 0x800680A4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800680A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800680AC: addiu       $a3, $a3, 0x1270
    ctx->r7 = ADD32(ctx->r7, 0X1270);
    // 0x800680B0: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x800680B4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800680B8: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800680BC: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x800680C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800680C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800680C8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800680CC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800680D0: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800680D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800680D8: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800680DC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800680E0: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x800680E4: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x800680E8: sh          $t9, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r25;
    // 0x800680EC: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x800680F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800680F4: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x800680F8: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800680FC: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
    // 0x80068100: lw          $t2, 0x1298($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1298);
    // 0x80068104: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068108: beq         $t2, $zero, L_80068124
    if (ctx->r10 == 0) {
        // 0x8006810C: addiu       $a0, $a0, 0x1520
        ctx->r4 = ADD32(ctx->r4, 0X1520);
            goto L_80068124;
    }
    // 0x8006810C: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    // 0x80068110: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068114: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80068118: nop

    // 0x8006811C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80068120: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_80068124:
    // 0x80068124: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80068128: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8006812C: jal         0x8006FE70
    // 0x80068130: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80068130: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    after_2:
    // 0x80068134: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068138: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006813C: addiu       $a1, $a1, 0x15A0
    ctx->r5 = ADD32(ctx->r5, 0X15A0);
    // 0x80068140: jal         0x8006FAB0
    // 0x80068144: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    mtxf_to_mtx(rdram, ctx);
        goto after_3;
    // 0x80068144: addiu       $a0, $a0, 0x1520
    ctx->r4 = ADD32(ctx->r4, 0X1520);
    after_3:
    // 0x80068148: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006814C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068154: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068158: jr          $ra
    // 0x8006815C: sw          $t4, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r12;
    return;
    // 0x8006815C: sw          $t4, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void set_ortho_matrix_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80068164: jr          $ra
    // 0x80068168: swc1        $f12, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80068168: swc1        $f12, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void mtx_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006816C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80068170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068178: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006817C: jal         0x8007A970
    // 0x80068180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80068180: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068184: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x80068188: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8006818C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80068190: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80068194: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80068198: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006819C: jal         0x8006FAB0
    // 0x800681A0: addiu       $a0, $a0, -0x27D8
    ctx->r4 = ADD32(ctx->r4, -0X27D8);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x800681A0: addiu       $a0, $a0, -0x27D8
    ctx->r4 = ADD32(ctx->r4, -0X27D8);
    after_1:
    // 0x800681A4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800681A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800681AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800681B0: addiu       $t4, $t4, 0x1264
    ctx->r12 = ADD32(ctx->r12, 0X1264);
    // 0x800681B4: sw          $t8, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r24;
    // 0x800681B8: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800681BC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800681C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800681C4: addiu       $t3, $t3, -0x2948
    ctx->r11 = ADD32(ctx->r11, -0X2948);
    // 0x800681C8: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x800681CC: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x800681D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800681D4: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800681D8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800681DC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800681E0: sh          $t6, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r14;
    // 0x800681E4: sh          $t6, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r14;
    // 0x800681E8: sh          $t6, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r14;
    // 0x800681EC: sh          $t8, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r24;
    // 0x800681F0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800681F4: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x800681F8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800681FC: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80068200: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80068204: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80068208: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8006820C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068210: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80068214: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80068218: ori         $at, $at, 0x50
    ctx->r1 = ctx->r1 | 0X50;
    // 0x8006821C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80068220: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80068224: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80068228: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8006822C: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80068230: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80068234: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80068238: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006823C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80068240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068244: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80068248: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8006824C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80068250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068254: addiu       $t5, $t9, 0x40
    ctx->r13 = ADD32(ctx->r25, 0X40);
    // 0x80068258: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006825C: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x80068260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068264: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80068268: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006826C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80068270: sw          $zero, 0x1288($at)
    MEM_W(0X1288, ctx->r1) = 0;
    // 0x80068274: addiu       $v0, $v0, -0x27D8
    ctx->r2 = ADD32(ctx->r2, -0X27D8);
    // 0x80068278: addiu       $v1, $v1, 0x14A0
    ctx->r3 = ADD32(ctx->r3, 0X14A0);
    // 0x8006827C: addiu       $a0, $a0, -0x2798
    ctx->r4 = ADD32(ctx->r4, -0X2798);
L_80068280:
    // 0x80068280: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80068284: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80068288: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006828C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80068290: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80068294: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80068298: swc1        $f4, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8006829C: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800682A0: swc1        $f8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800682A4: bne         $v0, $a0, L_80068280
    if (ctx->r2 != ctx->r4) {
        // 0x800682A8: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80068280;
    }
    // 0x800682A8: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800682AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800682B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800682B4: jr          $ra
    // 0x800682B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800682B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mtx_perspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800682BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800682C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800682C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800682C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800682CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800682D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800682D4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800682D8: jal         0x800700B4
    // 0x800682DC: addiu       $a1, $a1, -0x2808
    ctx->r5 = ADD32(ctx->r5, -0X2808);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x800682DC: addiu       $a1, $a1, -0x2808
    ctx->r5 = ADD32(ctx->r5, -0X2808);
    after_0:
    // 0x800682E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800682E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800682E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800682EC: addiu       $a2, $a2, 0x14A0
    ctx->r6 = ADD32(ctx->r6, 0X14A0);
    // 0x800682F0: addiu       $a1, $a1, 0x1460
    ctx->r5 = ADD32(ctx->r5, 0X1460);
    // 0x800682F4: jal         0x8006F9A8
    // 0x800682F8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800682F8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_1:
    // 0x800682FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068300: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068304: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068308: jal         0x800700B4
    // 0x8006830C: addiu       $a1, $a1, -0x27F0
    ctx->r5 = ADD32(ctx->r5, -0X27F0);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x8006830C: addiu       $a1, $a1, -0x27F0
    ctx->r5 = ADD32(ctx->r5, -0X27F0);
    after_2:
    // 0x80068310: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068314: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068318: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006831C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068320: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x80068324: jal         0x8006F9A8
    // 0x80068328: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x80068328: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_3:
    // 0x8006832C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80068330: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068334: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80068338: jal         0x8006FAB0
    // 0x8006833C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_to_mtx(rdram, ctx);
        goto after_4;
    // 0x8006833C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_4:
    // 0x80068340: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80068344: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80068348: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006834C: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80068350: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068354: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80068358: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8006835C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80068360: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80068364: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068368: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8006836C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80068370: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80068374: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068378: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x8006837C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80068380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068384: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x80068388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006838C: sw          $zero, 0x1288($at)
    MEM_W(0X1288, ctx->r1) = 0;
    // 0x80068390: jr          $ra
    // 0x80068394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void viewport_rsp_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006839C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800683A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800683A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800683A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800683AC: jal         0x8009C850
    // 0x800683B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800683B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800683B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800683B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800683BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800683C0: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800683C4: beq         $t6, $zero, L_800683D4
    if (ctx->r14 == 0) {
        // 0x800683C8: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800683D4;
    }
    // 0x800683C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800683CC: b           L_800683D8
    // 0x800683D0: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
        goto L_800683D8;
    // 0x800683D0: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_800683D4:
    // 0x800683D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800683D8:
    // 0x800683D8: lb          $t7, -0x2A30($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2A30);
    // 0x800683DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800683E0: beq         $t7, $zero, L_800683F0
    if (ctx->r15 == 0) {
        // 0x800683E4: addiu       $a3, $a3, 0x1264
        ctx->r7 = ADD32(ctx->r7, 0X1264);
            goto L_800683F0;
    }
    // 0x800683E4: addiu       $a3, $a3, 0x1264
    ctx->r7 = ADD32(ctx->r7, 0X1264);
    // 0x800683E8: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800683EC: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_800683F0:
    // 0x800683F0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800683F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800683F8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800683FC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80068400: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068404: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80068408: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006840C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80068410: lw          $t9, -0x29FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29FC);
    // 0x80068414: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80068418: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x8006841C: bne         $t3, $zero, L_80068488
    if (ctx->r11 != 0) {
        // 0x80068420: addiu       $t2, $t2, -0x2948
        ctx->r10 = ADD32(ctx->r10, -0X2948);
            goto L_80068488;
    }
    // 0x80068420: addiu       $t2, $t2, -0x2948
    ctx->r10 = ADD32(ctx->r10, -0X2948);
    // 0x80068424: sll         $t4, $a1, 4
    ctx->r12 = S32(ctx->r5 << 4);
    // 0x80068428: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8006842C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80068430: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80068434: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80068438: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8006843C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80068440: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068444: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80068448: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8006844C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80068450: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x80068454: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80068458: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x8006845C: addiu       $t4, $a0, 0x8
    ctx->r12 = ADD32(ctx->r4, 0X8);
    // 0x80068460: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80068464: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80068468: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8006846C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80068470: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068474: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80068478: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8006847C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80068480: b           L_800684DC
    // 0x80068484: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_800684DC;
    // 0x80068484: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_80068488:
    // 0x80068488: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006848C: lui         $t4, 0x380
    ctx->r12 = S32(0X380 << 16);
    // 0x80068490: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80068494: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068498: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8006849C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800684A0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800684A4: lw          $t8, -0x295C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X295C);
    // 0x800684A8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800684AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800684B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800684B4: addiu       $t2, $t2, -0x2948
    ctx->r10 = ADD32(ctx->r10, -0X2948);
    // 0x800684B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800684BC: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800684C0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800684C4: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x800684C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800684CC: ori         $at, $at, 0xA0
    ctx->r1 = ctx->r1 | 0XA0;
    // 0x800684D0: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x800684D4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800684D8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_800684DC:
    // 0x800684DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800684E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800684E4: jr          $ra
    // 0x800684E8: nop

    return;
    // 0x800684E8: nop

;}
RECOMP_FUNC void viewport_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800684F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800684F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800684F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800684FC: sw          $t6, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r14;
    // 0x80068500: jal         0x8007A970
    // 0x80068504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80068504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068508: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006850C: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80068510: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80068514: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068518: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006851C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068520: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068524: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068528: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006852C: lw          $t9, -0x29FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29FC);
    // 0x80068530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80068534: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x80068538: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x8006853C: bne         $t2, $zero, L_80068614
    if (ctx->r10 != 0) {
        // 0x80068540: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_80068614;
    }
    // 0x80068540: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80068544: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068548: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x8006854C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80068550: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80068554: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80068558: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006855C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80068560: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x80068564: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80068568: bgez        $t5, L_80068580
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006856C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80068580;
    }
    // 0x8006856C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80068570: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80068574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068578: nop

    // 0x8006857C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80068580:
    // 0x80068580: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80068584: addiu       $t2, $t0, -0x1
    ctx->r10 = ADD32(ctx->r8, -0X1);
    // 0x80068588: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006858C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80068590: nop

    // 0x80068594: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80068598: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006859C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800685A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800685A4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800685A8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800685AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800685B0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800685B4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800685B8: bgez        $t2, L_800685CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800685BC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800685CC;
    }
    // 0x800685BC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800685C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800685C4: nop

    // 0x800685C8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800685CC:
    // 0x800685CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800685D0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800685D4: srl         $a1, $t1, 1
    ctx->r5 = S32(U32(ctx->r9) >> 1);
    // 0x800685D8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800685DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800685E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800685E4: srl         $a2, $t0, 1
    ctx->r6 = S32(U32(ctx->r8) >> 1);
    // 0x800685E8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800685EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800685F0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800685F4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800685F8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800685FC: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80068600: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80068604: jal         0x80068398
    // 0x80068608: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    viewport_rsp_set(rdram, ctx);
        goto after_1;
    // 0x80068608: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    after_1:
    // 0x8006860C: b           L_80068638
    // 0x80068610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80068638;
    // 0x80068610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068614:
    // 0x80068614: jal         0x80067C7C
    // 0x80068618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x80068618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006861C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80068620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006862C: jal         0x80068398
    // 0x80068630: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_3;
    // 0x80068630: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80068634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068638:
    // 0x80068638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006863C: sw          $zero, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = 0;
    // 0x80068640: jr          $ra
    // 0x80068644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mtx_world_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068648: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006864C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068650: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x80068654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006865C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068660: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068664: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068668: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006866C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068670: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068674: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068678: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006867C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068680: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80068684: jal         0x80070838
    // 0x80068688: nop

    mtxf_from_translation(rdram, ctx);
        goto after_0;
    // 0x80068688: nop

    after_0:
    // 0x8006868C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80068690: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x80068694: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068698: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006869C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800686A0: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x800686A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800686A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800686AC: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x800686B0: jal         0x8006F9A8
    // 0x800686B4: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800686B4: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_1:
    // 0x800686B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800686BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800686C0: jal         0x8006FAB0
    // 0x800686C4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x800686C4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_2:
    // 0x800686C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800686CC: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800686D0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800686D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800686D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800686DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800686E0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800686E4: sw          $t0, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r8;
    // 0x800686E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800686EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800686F0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800686F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800686F8: lw          $t4, 0x1288($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1288);
    // 0x800686FC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80068700: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80068704: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80068708: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8006870C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80068710: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80068714: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80068718: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006871C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068720: addu        $t0, $t1, $at
    ctx->r8 = ADD32(ctx->r9, ctx->r1);
    // 0x80068724: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80068728: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006872C: nop

    // 0x80068730: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x80068734: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80068738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006873C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068740: jr          $ra
    // 0x80068744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void cam_set_sprite_anim_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006874C: jr          $ra
    // 0x80068750: sw          $a0, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = ctx->r4;
    return;
    // 0x80068750: sw          $a0, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_sprite_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068754: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80068758: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8006875C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80068760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80068764: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068768: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8006876C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068770: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068774: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068778: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006877C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80068780: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80068784: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80068788: beq         $t8, $zero, L_80068ADC
    if (ctx->r24 == 0) {
        // 0x8006878C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_80068ADC;
    }
    // 0x8006878C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80068790: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80068794: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X12A0);
    // 0x80068798: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006879C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800687A0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687A4: lwc1        $f4, 0x12A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x800687A8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800687AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800687B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800687B4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687B8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800687BC: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800687C0: lwc1        $f10, 0x12C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x800687C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800687C8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800687CC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687D0: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800687D4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800687D8: lwc1        $f6, 0x12D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x800687DC: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800687E0: jal         0x80070A04
    // 0x800687E4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800687E4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    after_0:
    // 0x800687E8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800687EC: jal         0x80070A38
    // 0x800687F0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800687F0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800687F4: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800687F8: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800687FC: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80068800: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068804: mul.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80068808: nop

    // 0x8006880C: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80068810: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80068814: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80068818: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8006881C: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068820: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80068824: nop

    // 0x80068828: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006882C: jal         0x800CA030
    // 0x80068830: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80068830: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_2:
    // 0x80068834: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068838: jal         0x80070990
    // 0x8006883C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8006883C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x80068840: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068844: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80068848: jal         0x80070990
    // 0x8006884C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8006884C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x80068850: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80068854: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80068858: jal         0x80070A70
    // 0x8006885C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    sins_s16(rdram, ctx);
        goto after_5;
    // 0x8006885C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x80068860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80068864: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80068868: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8006886C: sra         $t3, $v1, 8
    ctx->r11 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80068870: bc1f        L_80068890
    if (!c1cs) {
        // 0x80068874: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80068890;
    }
    // 0x80068874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80068878: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8006887C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80068880: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80068884: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80068888: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x8006888C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80068890:
    // 0x80068890: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068894: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80068898: jal         0x80070990
    // 0x8006889C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    arctan2_f(rdram, ctx);
        goto after_6;
    // 0x8006889C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_6:
    // 0x800688A0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800688A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800688A8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800688AC: bne         $at, $zero, L_800688BC
    if (ctx->r1 != 0) {
        // 0x800688B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800688BC;
    }
    // 0x800688B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800688B4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800688B8: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
L_800688BC:
    // 0x800688BC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800688C0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800688C4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800688C8: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800688CC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800688D0: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800688D4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800688D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800688DC: mflo        $v1
    ctx->r3 = lo;
    // 0x800688E0: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800688E4: bne         $at, $zero, L_800688FC
    if (ctx->r1 != 0) {
        // 0x800688E8: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800688FC;
    }
    // 0x800688E8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800688EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800688F0: subu        $s2, $t2, $t9
    ctx->r18 = SUB32(ctx->r10, ctx->r25);
    // 0x800688F4: addu        $v1, $t7, $at
    ctx->r3 = ADD32(ctx->r15, ctx->r1);
    // 0x800688F8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800688FC:
    // 0x800688FC: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X12A0);
    // 0x80068900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068904: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80068908: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006890C: lwc1        $f6, 0x12A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x80068910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068914: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068918: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006891C: lwc1        $f10, 0x12C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x80068920: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80068924: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006892C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80068930: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068934: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80068938: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006893C: lwc1        $f6, 0x12D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x80068940: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80068944: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068948: sll         $t3, $s2, 1
    ctx->r11 = S32(ctx->r18 << 1);
    // 0x8006894C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80068950: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80068954: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80068958: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006895C: jal         0x800CA030
    // 0x80068960: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80068960: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_7:
    // 0x80068964: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80068968: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8006896C: jal         0x80070990
    // 0x80068970: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_8;
    // 0x80068970: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_8:
    // 0x80068974: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068978: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x8006897C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068980: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80068984: jal         0x80070990
    // 0x80068988: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_9;
    // 0x80068988: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    after_9:
    // 0x8006898C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068990: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80068994: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x80068998: negu        $t5, $v0
    ctx->r13 = SUB32(0, ctx->r2);
    // 0x8006899C: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800689A0: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x800689A4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800689A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800689AC: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800689B0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800689B4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800689B8: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x800689BC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800689C0: nop

    // 0x800689C4: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x800689C8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800689CC: jal         0x8006FE70
    // 0x800689D0: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_10;
    // 0x800689D0: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    after_10:
    // 0x800689D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800689D8: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x800689DC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800689E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800689E4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800689E8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800689EC: addiu       $t3, $t3, 0x12F0
    ctx->r11 = ADD32(ctx->r11, 0X12F0);
    // 0x800689F0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800689F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800689F8: addiu       $s0, $s0, 0x15E0
    ctx->r16 = ADD32(ctx->r16, 0X15E0);
    // 0x800689FC: lw          $a1, -0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X4);
    // 0x80068A00: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80068A04: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80068A08: jal         0x8006F9A8
    // 0x80068A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_11;
    // 0x80068A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80068A10: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A14: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068A18: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80068A1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068A20: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80068A24: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80068A28: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068A2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068A30: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    // 0x80068A34: jal         0x8006F9A8
    // 0x80068A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_12;
    // 0x80068A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80068A3C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80068A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068A44: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80068A48: jal         0x8006FAB0
    // 0x80068A4C: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_13;
    // 0x80068A4C: nop

    after_13:
    // 0x80068A50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A54: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068A58: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80068A5C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068A60: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80068A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068A68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80068A6C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068A70: sw          $t7, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r15;
    // 0x80068A74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068A78: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x80068A7C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068A80: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068A84: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80068A88: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80068A8C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068A94: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80068A98: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068A9C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068AA0: lui         $a1, 0xE
    ctx->r5 = S32(0XE << 16);
    // 0x80068AA4: addiu       $t8, $t6, 0x40
    ctx->r24 = ADD32(ctx->r14, 0X40);
    // 0x80068AA8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80068AAC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068AB0: addiu       $t9, $a1, -0x2958
    ctx->r25 = ADD32(ctx->r5, -0X2958);
    // 0x80068AB4: andi        $t2, $t9, 0x6
    ctx->r10 = ctx->r25 & 0X6;
    // 0x80068AB8: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80068ABC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068AC0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80068AC4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068AC8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80068ACC: ori         $t5, $t4, 0x1A
    ctx->r13 = ctx->r12 | 0X1A;
    // 0x80068AD0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068AD4: b           L_80068D00
    // 0x80068AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80068D00;
    // 0x80068AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80068ADC:
    // 0x80068ADC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80068AE0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068AE4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80068AE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068AEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068AF0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068AF4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80068AF8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80068AFC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80068B00: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80068B04: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80068B08: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80068B0C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80068B10: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80068B14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068B18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068B1C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80068B20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068B24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80068B28: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068B2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80068B30: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80068B34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068B38: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80068B3C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80068B40: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068B44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068B48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068B4C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80068B50: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x80068B54: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80068B58: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x80068B5C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068B60: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x80068B64: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x80068B68: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x80068B6C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068B70: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068B74: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068B78: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068B7C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068B80: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068B84: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80068B88: andi        $t7, $t8, 0x6
    ctx->r15 = ctx->r24 & 0X6;
    // 0x80068B8C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80068B90: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80068B94: ori         $t3, $t2, 0x1A
    ctx->r11 = ctx->r10 | 0X1A;
    // 0x80068B98: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80068B9C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068BA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80068BA4: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80068BA8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068BAC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068BB0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068BB4: addiu       $t8, $t6, 0xA
    ctx->r24 = ADD32(ctx->r14, 0XA);
    // 0x80068BB8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80068BBC: lb          $t7, 0x1294($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X1294);
    // 0x80068BC0: nop

    // 0x80068BC4: bne         $t7, $zero, L_80068BFC
    if (ctx->r15 != 0) {
        // 0x80068BC8: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80068BFC;
    }
    // 0x80068BC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068BCC: lw          $t9, 0x1264($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1264);
    // 0x80068BD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80068BD4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x80068BD8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80068BDC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068BE0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80068BE4: lh          $t3, 0x1044($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1044);
    // 0x80068BE8: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x80068BEC: nop

    // 0x80068BF0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80068BF4: b           L_80068C2C
    // 0x80068BF8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_80068C2C;
    // 0x80068BF8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80068BFC:
    // 0x80068BFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068C00: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80068C04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80068C08: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80068C0C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80068C10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068C14: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80068C18: lh          $t7, 0x1154($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1154);
    // 0x80068C1C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80068C20: nop

    // 0x80068C24: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x80068C28: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80068C2C:
    // 0x80068C2C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80068C30: lh          $s2, 0x18($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X18);
    // 0x80068C34: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80068C38: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80068C3C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80068C40: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80068C44: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068C48: lw          $a3, 0x6714($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6714);
    // 0x80068C4C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80068C50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80068C54: jal         0x80070370
    // 0x80068C58: nop

    mtxf_billboard(rdram, ctx);
        goto after_14;
    // 0x80068C58: nop

    after_14:
    // 0x80068C5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068C60: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068C64: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068C68: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80068C6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068C70: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80068C74: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068C78: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068C7C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80068C80: jal         0x8006FAB0
    // 0x80068C84: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_15;
    // 0x80068C84: nop

    after_15:
    // 0x80068C88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068C8C: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068C90: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80068C94: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80068C98: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80068C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068CA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80068CA4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068CA8: sw          $t2, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r10;
    // 0x80068CAC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068CB0: lui         $t6, 0x180
    ctx->r14 = S32(0X180 << 16);
    // 0x80068CB4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80068CB8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80068CBC: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80068CC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80068CC4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80068CC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068CCC: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80068CD0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068CD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80068CD8: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80068CDC: addiu       $t3, $t9, 0x40
    ctx->r11 = ADD32(ctx->r25, 0X40);
    // 0x80068CE0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80068CE4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068CE8: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x80068CEC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068CF0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068CF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80068CF8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068CFC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80068D00:
    // 0x80068D00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068D04: lw          $t6, 0x128C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X128C);
    // 0x80068D08: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80068D0C: bne         $t6, $zero, L_80068D34
    if (ctx->r14 != 0) {
        // 0x80068D10: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80068D34;
    }
    // 0x80068D10: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80068D14: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068D18: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80068D1C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80068D20: nop

    // 0x80068D24: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068D28: mflo        $s2
    ctx->r18 = lo;
    // 0x80068D2C: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x80068D30: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80068D34:
    // 0x80068D34: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80068D38: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068D3C: andi        $t2, $t3, 0x4
    ctx->r10 = ctx->r11 & 0X4;
    // 0x80068D40: beq         $t2, $zero, L_80068D4C
    if (ctx->r10 == 0) {
        // 0x80068D44: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80068D4C;
    }
    // 0x80068D44: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80068D48: ori         $v0, $t3, 0x1
    ctx->r2 = ctx->r11 | 0X1;
L_80068D4C:
    // 0x80068D4C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80068D50: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80068D54: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80068D58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80068D5C: jal         0x8007C384
    // 0x80068D60: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    material_load_simple(rdram, ctx);
        goto after_16;
    // 0x80068D60: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    after_16:
    // 0x80068D64: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80068D68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068D6C: andi        $t7, $t8, 0x100
    ctx->r15 = ctx->r24 & 0X100;
    // 0x80068D70: bne         $t7, $zero, L_80068D94
    if (ctx->r15 != 0) {
        // 0x80068D74: addiu       $t0, $t0, 0x129C
        ctx->r8 = ADD32(ctx->r8, 0X129C);
            goto L_80068D94;
    }
    // 0x80068D74: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068D78: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068D7C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80068D80: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80068D84: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80068D88: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80068D8C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80068D90: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80068D94:
    // 0x80068D94: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068D98: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80068D9C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068DA0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068DA4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80068DA8: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x80068DAC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068DB0: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x80068DB4: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80068DB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068DBC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80068DC0: ori         $t5, $t5, 0xA
    ctx->r13 = ctx->r13 | 0XA;
    // 0x80068DC4: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80068DC8: bne         $t3, $zero, L_80068DD8
    if (ctx->r11 != 0) {
        // 0x80068DCC: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_80068DD8;
    }
    // 0x80068DCC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068DD0: b           L_80068DDC
    // 0x80068DD4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80068DDC;
    // 0x80068DD4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80068DD8:
    // 0x80068DD8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80068DDC:
    // 0x80068DDC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068DE0: sll         $t6, $s2, 6
    ctx->r14 = S32(ctx->r18 << 6);
    // 0x80068DE4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068DE8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068DEC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80068DF0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068DF4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068DF8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80068DFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80068E00: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80068E04: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80068E08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80068E0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80068E10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80068E14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80068E18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80068E1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068E20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80068E24: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80068E28: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80068E2C: jr          $ra
    // 0x80068E30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80068E30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void render_ortho_triangle_image(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E34: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80068E38: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x80068E3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068E40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068E44: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068E48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068E4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068E50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80068E54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80068E58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068E5C: beq         $t6, $zero, L_800691C8
    if (ctx->r14 == 0) {
        // 0x80068E60: sw          $a1, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r5;
            goto L_800691C8;
    }
    // 0x80068E60: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80068E64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80068E68: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80068E6C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80068E70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068E74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068E78: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80068E7C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80068E80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80068E84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80068E88: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80068E8C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80068E90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80068E94: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80068E98: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80068E9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068EA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068EA4: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068EA8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80068EAC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80068EB0: addiu       $s4, $s4, 0x129C
    ctx->r20 = ADD32(ctx->r20, 0X129C);
    // 0x80068EB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80068EB8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80068EBC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80068EC0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80068EC4: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80068EC8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068ECC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068ED0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068ED4: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068ED8: sb          $a1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r5;
    // 0x80068EDC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80068EE0: sb          $a1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r5;
    // 0x80068EE4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068EE8: sb          $a1, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r5;
    // 0x80068EEC: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80068EF0: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80068EF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068EF8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068EFC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80068F00: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068F04: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068F08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068F0C: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80068F10: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80068F14: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80068F18: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80068F1C: ori         $t2, $t1, 0x1A
    ctx->r10 = ctx->r9 | 0X1A;
    // 0x80068F20: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80068F24: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80068F28: addiu       $s2, $s2, 0x1270
    ctx->r18 = ADD32(ctx->r18, 0X1270);
    // 0x80068F2C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80068F30: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80068F34: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068F38: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80068F3C: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x80068F40: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80068F44: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80068F48: lh          $s3, 0x18($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X18);
    // 0x80068F4C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80068F50: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80068F54: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80068F58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068F5C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x80068F60: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x80068F64: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x80068F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068F6C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80068F70: sh          $t3, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r11;
    // 0x80068F74: lw          $t4, 0x1264($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1264);
    // 0x80068F78: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x80068F7C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80068F80: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80068F84: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068F88: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80068F8C: lh          $t6, 0x1044($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1044);
    // 0x80068F90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068F94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80068F98: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x80068F9C: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA0: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA4: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA8: lb          $t9, 0x1295($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X1295);
    // 0x80068FAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068FB0: beq         $t9, $zero, L_80069008
    if (ctx->r25 == 0) {
        // 0x80068FB4: nop
    
            goto L_80069008;
    }
    // 0x80068FB4: nop

    // 0x80068FB8: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80068FBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80068FC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068FC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068FC8: jal         0x80070878
    // 0x80068FCC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_from_scale(rdram, ctx);
        goto after_0;
    // 0x80068FCC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80068FD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068FD4: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80068FD8: lw          $a3, 0x6714($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6714);
    // 0x80068FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068FE4: jal         0x80070370
    // 0x80068FE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_billboard(rdram, ctx);
        goto after_1;
    // 0x80068FE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80068FEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068FF0: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x80068FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068FF8: jal         0x8006F9A8
    // 0x80068FFC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    mtxf_mul(rdram, ctx);
        goto after_2;
    // 0x80068FFC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80069000: b           L_80069028
    // 0x80069004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80069028;
    // 0x80069004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80069008:
    // 0x80069008: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006900C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069010: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069014: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80069018: jal         0x80070878
    // 0x8006901C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_from_scale(rdram, ctx);
        goto after_3;
    // 0x8006901C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80069020: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80069024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80069028:
    // 0x80069028: jal         0x800700B4
    // 0x8006902C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_4;
    // 0x8006902C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80069030: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80069034: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069038: addiu       $s2, $s2, 0x12F0
    ctx->r18 = ADD32(ctx->r18, 0X12F0);
    // 0x8006903C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80069040: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80069044: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80069048: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006904C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069050: jal         0x8006F9A8
    // 0x80069054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_5;
    // 0x80069054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80069058: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8006905C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80069060: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80069064: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80069068: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8006906C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80069070: jal         0x8006FAB0
    // 0x80069074: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_6;
    // 0x80069074: nop

    after_6:
    // 0x80069078: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8006907C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80069080: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80069084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069088: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8006908C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80069090: sw          $t8, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r24;
    // 0x80069094: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80069098: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x8006909C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800690A0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800690A4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800690A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800690AC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800690B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800690B4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800690B8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800690BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800690C0: lui         $s0, 0xBC00
    ctx->r16 = S32(0XBC00 << 16);
    // 0x800690C4: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800690C8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800690CC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800690D0: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    // 0x800690D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800690D8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800690DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800690E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800690E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800690E8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800690EC: lw          $t1, 0x128C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X128C);
    // 0x800690F0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x800690F4: bne         $t1, $zero, L_8006911C
    if (ctx->r9 != 0) {
        // 0x800690F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8006911C;
    }
    // 0x800690F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800690FC: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x80069100: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80069104: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80069108: nop

    // 0x8006910C: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069110: mflo        $s3
    ctx->r19 = lo;
    // 0x80069114: sra         $t5, $s3, 8
    ctx->r13 = S32(SIGNED(ctx->r19) >> 8);
    // 0x80069118: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_8006911C:
    // 0x8006911C: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x80069120: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80069124: jal         0x8007C384
    // 0x80069128: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    material_load_simple(rdram, ctx);
        goto after_7;
    // 0x80069128: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    after_7:
    // 0x8006912C: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x80069130: nop

    // 0x80069134: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x80069138: nop

    // 0x8006913C: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80069140: bne         $at, $zero, L_8006914C
    if (ctx->r1 != 0) {
        // 0x80069144: nop
    
            goto L_8006914C;
    }
    // 0x80069144: nop

    // 0x80069148: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
L_8006914C:
    // 0x8006914C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80069150: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80069154: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80069158: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8006915C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80069160: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x80069164: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x80069168: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006916C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80069170: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x80069174: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80069178: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8006917C: ori         $t3, $t3, 0xA
    ctx->r11 = ctx->r11 | 0XA;
    // 0x80069180: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80069184: bne         $t9, $zero, L_80069194
    if (ctx->r25 != 0) {
        // 0x80069188: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_80069194;
    }
    // 0x80069188: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8006918C: b           L_80069198
    // 0x80069190: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80069198;
    // 0x80069190: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80069194:
    // 0x80069194: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80069198:
    // 0x80069198: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8006919C: sll         $t2, $s3, 6
    ctx->r10 = S32(ctx->r19 << 6);
    // 0x800691A0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800691A4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800691A8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800691AC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800691B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800691B4: nop

    // 0x800691B8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800691BC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800691C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800691C4: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_800691C8:
    // 0x800691C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800691CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800691D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800691D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800691D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800691DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800691E0: jr          $ra
    // 0x800691E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800691E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void mtx_shear_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800691E8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800691EC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800691F0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800691F4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800691F8: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800691FC: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80069200: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80069204: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80069208: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8006920C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80069210: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80069214: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80069218: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006921C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80069220: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80069224: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80069228: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x8006922C: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    // 0x80069230: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80069234: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80069238: jal         0x80070A38
    // 0x8006923C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x8006923C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    after_0:
    // 0x80069240: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80069244: jal         0x80070A04
    // 0x80069248: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069248: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_1:
    // 0x8006924C: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x80069250: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069254: jal         0x80070A38
    // 0x80069258: nop

    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069258: nop

    after_2:
    // 0x8006925C: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069260: jal         0x80070A04
    // 0x80069264: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069264: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069268: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8006926C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80069270: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80069274: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80069278: nop

    // 0x8006927C: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80069280: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80069284: nop

    // 0x80069288: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x8006928C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80069290: jal         0x80070A38
    // 0x80069294: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80069294: nop

    after_4:
    // 0x80069298: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x8006929C: jal         0x80070A04
    // 0x800692A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800692A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800692A4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x800692A8: jal         0x80070A38
    // 0x800692AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800692AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_6:
    // 0x800692B0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x800692B4: jal         0x80070A04
    // 0x800692B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x800692B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_7:
    // 0x800692BC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800692C0: jal         0x80070A38
    // 0x800692C4: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x800692C4: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800692C8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800692CC: jal         0x80070A04
    // 0x800692D0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_9;
    // 0x800692D0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800692D4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800692D8: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800692DC: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x800692E0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800692E4: lwc1        $f14, 0x100($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800692E8: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800692EC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800692F0: lwc1        $f12, 0xFC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800692F4: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x800692F8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800692FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069300: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80069304: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80069308: addiu       $s0, $s0, 0x1620
    ctx->r16 = ADD32(ctx->r16, 0X1620);
    // 0x8006930C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069310: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069314: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    // 0x80069318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8006931C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80069320: mul.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80069324: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80069328: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8006932C: nop

    // 0x80069330: mul.s       $f10, $f26, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80069334: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x80069338: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x8006933C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80069340: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069344: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80069348: mul.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8006934C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80069350: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80069354: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80069358: nop

    // 0x8006935C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80069360: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069364: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80069368: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006936C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80069370: nop

    // 0x80069374: mul.s       $f4, $f26, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80069378: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8006937C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80069380: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80069384: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x80069388: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006938C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069390: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80069394: nop

    // 0x80069398: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006939C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800693A0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800693A4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800693A8: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800693AC: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800693B0: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x800693B4: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800693B8: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800693BC: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800693C0: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800693C4: nop

    // 0x800693C8: mul.s       $f10, $f26, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800693CC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800693D0: mul.s       $f10, $f28, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x800693D4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800693D8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800693DC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800693E0: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800693E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800693E8: nop

    // 0x800693EC: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800693F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800693F4: nop

    // 0x800693F8: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800693FC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80069400: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80069404: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80069408: nop

    // 0x8006940C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80069410: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80069414: neg.s       $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = -ctx->f26.fl;
    // 0x80069418: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x8006941C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069420: nop

    // 0x80069424: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80069428: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006942C: nop

    // 0x80069430: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80069434: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069438: mul.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8006943C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80069440: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069444: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069448: mul.s       $f4, $f22, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8006944C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069450: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069454: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80069458: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006945C: nop

    // 0x80069460: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80069464: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069468: nop

    // 0x8006946C: mul.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80069470: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069474: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80069478: nop

    // 0x8006947C: mul.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80069480: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x80069484: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069488: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8006948C: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069490: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069494: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069498: add.s       $f26, $f10, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006949C: lwc1        $f6, 0x118($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800694A0: mul.s       $f10, $f12, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f30.fl);
    // 0x800694A4: nop

    // 0x800694A8: mul.s       $f6, $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800694AC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800694B0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800694B4: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800694B8: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x800694BC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800694C0: nop

    // 0x800694C4: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800694C8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800694CC: nop

    // 0x800694D0: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800694D4: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800694D8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800694DC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800694E0: mul.s       $f6, $f24, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x800694E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800694E8: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800694EC: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800694F0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800694F4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800694F8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800694FC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80069500: nop

    // 0x80069504: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80069508: nop

    // 0x8006950C: mul.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x80069510: lwc1        $f14, 0x118($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069514: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069518: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8006951C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80069520: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069524: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x80069528: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x8006952C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069530: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069534: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80069538: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006953C: nop

    // 0x80069540: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069544: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069548: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006954C: nop

    // 0x80069550: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80069554: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x80069558: mul.s       $f10, $f30, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x8006955C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069560: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069564: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x80069568: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8006956C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80069570: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069574: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069578: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006957C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80069584: lwc1        $f2, 0xEC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069588: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x8006958C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x80069590: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069594: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069598: nop

    // 0x8006959C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800695A0: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800695A4: nop

    // 0x800695A8: mul.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800695AC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695B0: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800695B4: nop

    // 0x800695B8: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800695BC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695C0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800695C4: nop

    // 0x800695C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800695CC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800695D0: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x800695D4: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800695D8: nop

    // 0x800695DC: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800695E0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695E4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800695E8: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800695EC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800695F0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800695F4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800695F8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800695FC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80069600: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x80069604: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80069608: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8006960C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80069610: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80069614: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80069618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006961C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069620: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
    // 0x80069624: jal         0x8006F9A8
    // 0x80069628: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    mtxf_mul(rdram, ctx);
        goto after_10;
    // 0x80069628: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x8006962C: lw          $t3, 0x12C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X12C);
    // 0x80069630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069634: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80069638: jal         0x8006FAB0
    // 0x8006963C: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_11;
    // 0x8006963C: nop

    after_11:
    // 0x80069640: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80069644: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x80069648: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006964C: lui         $t5, 0x140
    ctx->r13 = S32(0X140 << 16);
    // 0x80069650: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80069654: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80069658: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006965C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80069660: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80069664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069668: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8006966C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80069670: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80069674: nop

    // 0x80069678: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x8006967C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80069680: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80069684: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80069688: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8006968C: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069690: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80069694: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069698: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8006969C: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800696A0: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800696A4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800696A8: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800696AC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800696B0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800696B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800696B8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800696BC: jr          $ra
    // 0x800696C0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800696C0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void mtx_cam_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800696C8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800696CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800696D0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800696D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800696D8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800696DC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800696E0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800696E4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800696E8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800696EC: jal         0x8006FE70
    // 0x800696F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x800696F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800696F4: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800696F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800696FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069700: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80069704: nop

    // 0x80069708: bc1t        L_80069720
    if (c1cs) {
        // 0x8006970C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80069720;
    }
    // 0x8006970C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069710: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069714: jal         0x80070070
    // 0x80069718: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_translate_y(rdram, ctx);
        goto after_1;
    // 0x80069718: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_1:
    // 0x8006971C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80069720:
    // 0x80069720: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80069724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80069728: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006972C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80069730: nop

    // 0x80069734: bc1t        L_80069748
    if (c1cs) {
        // 0x80069738: nop
    
            goto L_80069748;
    }
    // 0x80069738: nop

    // 0x8006973C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069740: jal         0x80070044
    // 0x80069744: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_scale_y(rdram, ctx);
        goto after_2;
    // 0x80069744: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_2:
L_80069748:
    // 0x80069748: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006974C: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x80069750: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069754: addiu       $t8, $t8, 0x12F0
    ctx->r24 = ADD32(ctx->r24, 0X12F0);
    // 0x80069758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006975C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069760: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80069764: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80069768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006976C: jal         0x8006F9A8
    // 0x80069770: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x80069770: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_3:
    // 0x80069774: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069778: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x8006977C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80069780: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069784: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80069788: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8006978C: lw          $a0, 0x12F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F4);
    // 0x80069790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069794: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069798: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, 0X1620);
    // 0x8006979C: jal         0x8006F9A8
    // 0x800697A0: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x800697A0: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_4:
    // 0x800697A4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800697A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800697AC: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800697B0: jal         0x8006FAB0
    // 0x800697B4: addiu       $a0, $a0, 0x1620
    ctx->r4 = ADD32(ctx->r4, 0X1620);
    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x800697B4: addiu       $a0, $a0, 0x1620
    ctx->r4 = ADD32(ctx->r4, 0X1620);
    after_5:
    // 0x800697B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800697BC: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x800697C0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800697C4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800697C8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800697CC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800697D0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800697D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800697D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800697DC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800697E0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800697E4: sw          $t7, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r15;
    // 0x800697E8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800697EC: lui         $t3, 0x140
    ctx->r11 = S32(0X140 << 16);
    // 0x800697F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800697F4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800697F8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800697FC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80069800: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80069804: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069808: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x8006980C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80069810: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80069814: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069818: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x8006981C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80069820: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80069824: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x80069828: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006982C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80069830: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80069834: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x80069838: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x8006983C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80069840: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80069844: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80069848: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006984C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80069850: jal         0x8006F88C
    // 0x80069854: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x80069854: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_6:
    // 0x80069858: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006985C: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069860: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80069864: lw          $v1, 0x1264($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1264);
    // 0x80069868: beq         $t6, $zero, L_80069874
    if (ctx->r14 == 0) {
        // 0x8006986C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80069874;
    }
    // 0x8006986C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069870: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80069874:
    // 0x80069874: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80069878: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006987C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069880: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069884: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069888: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8006988C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069890: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069894: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069898: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006989C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800698A0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800698A4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800698A8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800698AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800698B0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800698B4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800698B8: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800698BC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800698C0: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800698C4: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x800698C8: negu        $t3, $t9
    ctx->r11 = SUB32(0, ctx->r25);
    // 0x800698CC: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x800698D0: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x800698D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800698D8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800698DC: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800698E0: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800698E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800698E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800698EC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800698F0: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x800698F4: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x800698F8: swc1        $f20, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f20.u32l;
    // 0x800698FC: swc1        $f20, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f20.u32l;
    // 0x80069900: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069904: jal         0x800700B4
    // 0x80069908: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_7;
    // 0x80069908: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    after_7:
    // 0x8006990C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069910: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80069914: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80069918: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8006991C: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80069920: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x80069924: addiu       $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x80069928: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8006992C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80069930: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80069934: jal         0x8006F88C
    // 0x80069938: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_transform_point(rdram, ctx);
        goto after_8;
    // 0x80069938: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_8:
    // 0x8006993C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80069940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069944: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80069948: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8006994C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069950: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80069954: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80069958: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006995C: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, 0X12A0);
    // 0x80069960: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80069964: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80069968: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006996C: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x80069970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069974: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80069978: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8006997C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80069980: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069984: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069988: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006998C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069990: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80069994: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069998: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006999C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800699A0: swc1        $f6, 0x12A8($at)
    MEM_W(0X12A8, ctx->r1) = ctx->f6.u32l;
    // 0x800699A4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800699A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800699AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800699B0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800699B4: swc1        $f8, 0x12C0($at)
    MEM_W(0X12C0, ctx->r1) = ctx->f8.u32l;
    // 0x800699B8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800699BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800699C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800699C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800699C8: jr          $ra
    // 0x800699CC: swc1        $f10, 0x12D8($at)
    MEM_W(0X12D8, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x800699CC: swc1        $f10, 0x12D8($at)
    MEM_W(0X12D8, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void mtx_head_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800699D0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800699D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800699D8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800699DC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800699E0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800699E4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800699E8: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800699EC: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800699F0: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800699F4: lh          $t9, 0x16($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X16);
    // 0x800699F8: nop

    // 0x800699FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80069A00: nop

    // 0x80069A04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80069A08: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80069A0C: lh          $t0, 0x18($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X18);
    // 0x80069A10: nop

    // 0x80069A14: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80069A18: nop

    // 0x80069A1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80069A20: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80069A24: lh          $t1, 0x1A($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X1A);
    // 0x80069A28: nop

    // 0x80069A2C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80069A30: nop

    // 0x80069A34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80069A38: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x80069A3C: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069A40: jal         0x80070A38
    // 0x80069A44: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069A44: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069A48: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    // 0x80069A4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80069A50: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069A54: jal         0x80070A04
    // 0x80069A58: nop

    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069A58: nop

    after_1:
    // 0x80069A5C: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x80069A60: jal         0x80070A38
    // 0x80069A64: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069A64: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80069A68: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x80069A6C: jal         0x80070A04
    // 0x80069A70: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069A70: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069A74: mul.s       $f18, $f22, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80069A78: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80069A7C: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069A80: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069A84: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80069A88: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80069A8C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069A90: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x80069A94: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80069A98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80069A9C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x80069AA0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80069AA4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069AA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80069AAC: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x80069AB0: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80069AB4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80069AB8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80069ABC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80069AC0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069AC4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80069AC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80069ACC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069AD0: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80069AD4: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80069AD8: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80069ADC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80069AE0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80069AE4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80069AE8: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80069AEC: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80069AF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80069AF4: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80069AF8: add.s       $f18, $f2, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80069AFC: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B00: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x80069B04: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80069B08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80069B0C: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80069B10: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069B14: mul.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80069B18: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80069B1C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069B24: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80069B28: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069B2C: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x80069B30: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80069B34: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80069B38: lwc1        $f14, 0xF8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80069B3C: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80069B40: mul.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80069B44: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069B48: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80069B50: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80069B54: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80069B58: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069B5C: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80069B60: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80069B64: swc1        $f22, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f22.u32l;
    // 0x80069B68: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069B6C: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80069B70: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x80069B74: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x80069B78: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x80069B7C: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80069B80: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80069B84: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069B88: addiu       $a1, $a1, 0x1620
    ctx->r5 = ADD32(ctx->r5, 0X1620);
    // 0x80069B8C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80069B90: jal         0x8006F9A8
    // 0x80069B94: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x80069B94: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_4:
    // 0x80069B98: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x80069B9C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80069BA0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80069BA4: jal         0x8006FAB0
    // 0x80069BA8: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x80069BA8: nop

    after_5:
    // 0x80069BAC: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x80069BB0: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x80069BB4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80069BB8: lui         $t4, 0x180
    ctx->r12 = S32(0X180 << 16);
    // 0x80069BBC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80069BC0: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x80069BC4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80069BC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80069BCC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80069BD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069BD4: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069BD8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80069BDC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80069BE0: lui         $t0, 0xBC00
    ctx->r8 = S32(0XBC00 << 16);
    // 0x80069BE4: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x80069BE8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80069BEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80069BF0: ori         $t0, $t0, 0xA
    ctx->r8 = ctx->r8 | 0XA;
    // 0x80069BF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80069BF8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80069BFC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80069C00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80069C04: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80069C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069C0C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069C10: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80069C14: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80069C18: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80069C1C: jr          $ra
    // 0x80069C20: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80069C20: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void get_modelmatrix_vector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069C28: addiu       $v0, $v0, 0x12A0
    ctx->r2 = ADD32(ctx->r2, 0X12A0);
    // 0x80069C2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80069C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80069C38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80069C3C: lwc1        $f4, 0x12A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x80069C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C44: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80069C48: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80069C4C: nop

    // 0x80069C50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80069C54: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80069C58: lwc1        $f6, 0x12C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x80069C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069C60: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80069C64: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80069C68: nop

    // 0x80069C6C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80069C70: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80069C74: lwc1        $f8, 0x12D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x80069C78: jr          $ra
    // 0x80069C7C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x80069C7C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void mtx_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069C84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069C88: addiu       $a2, $a2, 0x129C
    ctx->r6 = ADD32(ctx->r6, 0X129C);
    // 0x80069C8C: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    // 0x80069C90: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80069C94: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80069C98: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80069C9C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80069CA0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80069CA4: blez        $t9, L_80069CE8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80069CA8: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80069CE8;
    }
    // 0x80069CA8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80069CAC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069CB0: lui         $t2, 0x140
    ctx->r10 = S32(0X140 << 16);
    // 0x80069CB4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80069CB8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80069CBC: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x80069CC0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80069CC4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80069CC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80069CCC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80069CD0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80069CD4: lw          $t5, 0x1308($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1308);
    // 0x80069CD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069CDC: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069CE0: jr          $ra
    // 0x80069CE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    return;
    // 0x80069CE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80069CE8:
    // 0x80069CE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069CEC: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80069CF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80069CF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80069CF8: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80069CFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80069D00: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80069D04: jr          $ra
    // 0x80069D08: nop

    return;
    // 0x80069D08: nop

;}
RECOMP_FUNC void cam_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069D10: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069D14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069D18: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069D1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069D24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069D28: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069D2C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80069D30: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069D34: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069D38: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80069D3C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80069D40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069D44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80069D48: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069D4C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069D50: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069D54: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80069D58: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80069D5C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069D64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069D68: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80069D6C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80069D70: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80069D74: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069D78: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069D7C: jal         0x80029F58
    // 0x80069D80: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80069D80: nop

    after_0:
    // 0x80069D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80069D88: lw          $t9, 0x1264($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1264);
    // 0x80069D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069D90: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80069D94: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80069D98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80069D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069DA0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80069DA4: sh          $v0, 0x1074($at)
    MEM_H(0X1074, ctx->r1) = ctx->r2;
    // 0x80069DA8: jr          $ra
    // 0x80069DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void cam_move_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069DB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80069DB8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069DBC: addiu       $s2, $s2, 0x1264
    ctx->r18 = ADD32(ctx->r18, 0X1264);
    // 0x80069DC0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80069DC4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80069DC8: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x80069DCC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069DD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069DD4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80069DD8: addiu       $s1, $s1, 0x1040
    ctx->r17 = ADD32(ctx->r17, 0X1040);
    // 0x80069DDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069DE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069DE4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80069DE8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80069DEC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80069DF0: mflo        $t7
    ctx->r15 = lo;
    // 0x80069DF4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80069DF8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x80069DFC: jal         0x80070A38
    // 0x80069E00: nop

    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069E00: nop

    after_0:
    // 0x80069E04: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80069E08: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069E0C: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069E14: mflo        $t0
    ctx->r8 = lo;
    // 0x80069E18: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x80069E1C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069E20: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E24: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80069E28: jal         0x80070A04
    // 0x80069E2C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069E2C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80069E30: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80069E34: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069E38: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E3C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80069E40: mflo        $t2
    ctx->r10 = lo;
    // 0x80069E44: addu        $s0, $s1, $t2
    ctx->r16 = ADD32(ctx->r17, ctx->r10);
    // 0x80069E48: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069E4C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E50: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80069E54: jal         0x80070A04
    // 0x80069E58: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80069E58: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80069E5C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80069E60: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069E64: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E68: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069E6C: mflo        $t4
    ctx->r12 = lo;
    // 0x80069E70: addu        $s0, $s1, $t4
    ctx->r16 = ADD32(ctx->r17, ctx->r12);
    // 0x80069E74: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069E78: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E7C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80069E80: jal         0x80070A38
    // 0x80069E84: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x80069E84: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80069E88: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80069E8C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069E90: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E94: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80069E98: mflo        $t6
    ctx->r14 = lo;
    // 0x80069E9C: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x80069EA0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069EA4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069EA8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069EAC: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80069EB0: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80069EB4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80069EB8: jal         0x80029F58
    // 0x80069EBC: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x80069EBC: nop

    after_4:
    // 0x80069EC0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80069EC4: nop

    // 0x80069EC8: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069ECC: mflo        $t8
    ctx->r24 = lo;
    // 0x80069ED0: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80069ED4: sh          $v0, 0x34($t9)
    MEM_H(0X34, ctx->r25) = ctx->r2;
    // 0x80069ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069EDC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80069EE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80069EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80069EE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069EEC: jr          $ra
    // 0x80069EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void cam_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069EF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069EF8: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069EFC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069F00: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069F04: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069F08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069F0C: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069F10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069F14: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80069F18: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80069F1C: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80069F20: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80069F24: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x80069F28: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80069F2C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80069F30: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80069F34: jr          $ra
    // 0x80069F38: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    return;
    // 0x80069F38: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void cam_get_active_camera_no_cutscenes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069F40: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069F44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069F48: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069F4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069F50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069F54: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069F58: jr          $ra
    // 0x80069F5C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x80069F5C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void cam_get_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069F64: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069F68: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80069F6C: beq         $t6, $zero, L_80069F9C
    if (ctx->r14 == 0) {
        // 0x80069F70: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80069F9C;
    }
    // 0x80069F70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80069F74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80069F78: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80069F7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069F80: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80069F84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80069F88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80069F8C: addiu       $t9, $t8, 0x110
    ctx->r25 = ADD32(ctx->r24, 0X110);
    // 0x80069F90: addiu       $t0, $t0, 0x1040
    ctx->r8 = ADD32(ctx->r8, 0X1040);
    // 0x80069F94: jr          $ra
    // 0x80069F98: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    return;
    // 0x80069F98: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
L_80069F9C:
    // 0x80069F9C: lw          $t1, 0x1264($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1264);
    // 0x80069FA0: addiu       $t3, $t3, 0x1040
    ctx->r11 = ADD32(ctx->r11, 0X1040);
    // 0x80069FA4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80069FA8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80069FAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80069FB0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80069FB4: jr          $ra
    // 0x80069FB8: nop

    return;
    // 0x80069FB8: nop

;}
