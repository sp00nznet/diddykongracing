#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void asset_rom_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077244: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80077248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007724C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80077250: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077254: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077258: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007725C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077260: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80077264: jal         0x800C9110
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007726C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80077270: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80077274: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077278: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007727C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80077280: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80077284: beq         $at, $zero, L_80077294
    if (ctx->r1 == 0) {
        // 0x80077288: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80077294;
    }
    // 0x80077288: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007728C: b           L_800772CC
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800772CC;
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077294:
    // 0x80077294: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077298: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8007729C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800772A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800772A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800772A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800772AC: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800772B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800772B4: jal         0x800C9390
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800772BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800772C0: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800772C4: addiu       $t2, $t2, -0x2E50
    ctx->r10 = ADD32(ctx->r10, -0X2E50);
    // 0x800772C8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_800772CC:
    // 0x800772CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800772D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800772D4: jr          $ra
    // 0x800772D8: nop

    return;
    // 0x800772D8: nop

;}
RECOMP_FUNC void asset_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800772DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800772E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800772E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800772E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800772EC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800772F0: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800772F4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800772F8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800772FC: jal         0x800C9110
    // 0x80077300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80077308: lw          $v0, 0x4830($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4830);
    // 0x8007730C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077310: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80077314: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077318: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x8007731C: beq         $at, $zero, L_8007732C
    if (ctx->r1 == 0) {
        // 0x80077320: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8007732C;
    }
    // 0x80077320: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077324: b           L_80077360
    // 0x80077328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077360;
    // 0x80077328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007732C:
    // 0x8007732C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077330: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80077334: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80077338: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007733C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077340: jal         0x800C9390
    // 0x80077344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80077348: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007734C: nop

    // 0x80077350: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80077354: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80077358: nop

    // 0x8007735C: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
L_80077360:
    // 0x80077360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077368: jr          $ra
    // 0x8007736C: nop

    return;
    // 0x8007736C: nop

;}
RECOMP_FUNC void dmacopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077370: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077374: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80077378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007737C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80077380: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077388: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007738C: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80077390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80077394: jal         0x800C9110
    // 0x80077398: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077398: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8007739C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800773A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800773A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800773A8: jal         0x800773D4
    // 0x800773AC: nop

    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x800773AC: nop

    after_1:
    // 0x800773B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800773B4: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800773B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800773BC: jal         0x800C9390
    // 0x800773C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800773C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800773C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800773C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800773CC: jr          $ra
    // 0x800773D0: nop

    return;
    // 0x800773D0: nop

;}
RECOMP_FUNC void dmacopy_v1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800773D8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800773DC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800773E0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800773E4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800773E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800773EC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800773F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800773F4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800773F8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800773FC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80077400: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80077404: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80077408: jal         0x800D1D50
    // 0x8007740C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8007740C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80077410: blez        $s1, L_80077478
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80077414: addiu       $s0, $zero, 0x5000
        ctx->r16 = ADD32(0, 0X5000);
            goto L_80077478;
    }
    // 0x80077414: addiu       $s0, $zero, 0x5000
    ctx->r16 = ADD32(0, 0X5000);
    // 0x80077418: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8007741C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80077420: addiu       $s4, $s4, 0x47A0
    ctx->r20 = ADD32(ctx->r20, 0X47A0);
    // 0x80077424: addiu       $s5, $s5, 0x4780
    ctx->r21 = ADD32(ctx->r21, 0X4780);
    // 0x80077428: addiu       $s6, $sp, 0x4C
    ctx->r22 = ADD32(ctx->r29, 0X4C);
L_8007742C:
    // 0x8007742C: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80077430: beq         $at, $zero, L_8007743C
    if (ctx->r1 == 0) {
        // 0x80077434: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8007743C;
    }
    // 0x80077434: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80077438: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8007743C:
    // 0x8007743C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80077440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077444: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80077448: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007744C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80077450: jal         0x800C94E0
    // 0x80077454: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80077454: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_1:
    // 0x80077458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007745C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80077460: jal         0x800C9110
    // 0x80077464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80077468: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007746C: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80077470: bgtz        $s1, L_8007742C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80077474: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_8007742C;
    }
    // 0x80077474: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_80077478:
    // 0x80077478: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007747C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80077480: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80077484: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80077488: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007748C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80077490: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80077494: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80077498: jr          $ra
    // 0x8007749C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007749C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void divider_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800774A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800774A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800774AC: jal         0x8007A970
    // 0x800774B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800774B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800774B4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x800774B8: srl         $t6, $a1, 8
    ctx->r14 = S32(U32(ctx->r5) >> 8);
    // 0x800774BC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800774C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800774C4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800774C8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800774CC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800774D0: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800774D4: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x800774D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800774DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800774E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800774E4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x800774E8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800774EC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800774F0: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x800774F4: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800774F8: srl         $a0, $v0, 16
    ctx->r4 = S32(U32(ctx->r2) >> 16);
    // 0x800774FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80077500: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80077504: srl         $t2, $a0, 7
    ctx->r10 = S32(U32(ctx->r4) >> 7);
    // 0x80077508: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007750C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80077510: jal         0x80066450
    // 0x80077514: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80077514: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077518: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007751C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80077520: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80077524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077528: beq         $v0, $at, L_8007754C
    if (ctx->r2 == ctx->r1) {
        // 0x8007752C: srl         $t7, $t0, 1
        ctx->r15 = S32(U32(ctx->r8) >> 1);
            goto L_8007754C;
    }
    // 0x8007752C: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x80077530: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077534: beq         $v0, $at, L_80077590
    if (ctx->r2 == ctx->r1) {
        // 0x80077538: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80077590;
    }
    // 0x80077538: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007753C: beq         $v0, $at, L_80077620
    if (ctx->r2 == ctx->r1) {
        // 0x80077540: nop
    
            goto L_80077620;
    }
    // 0x80077540: nop

    // 0x80077544: b           L_800776AC
    // 0x80077548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800776AC;
    // 0x80077548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007754C:
    // 0x8007754C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077550: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x80077554: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80077558: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8007755C: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x80077560: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077564: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077568: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007756C: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80077570: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80077574: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80077578: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x8007757C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80077580: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80077584: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077588: b           L_800776A8
    // 0x8007758C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_800776A8;
    // 0x8007758C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80077590:
    // 0x80077590: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80077594: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80077598: jal         0x8006BFF0
    // 0x8007759C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    level_header(rdram, ctx);
        goto after_2;
    // 0x8007759C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_2:
    // 0x800775A0: jal         0x800A89B4
    // 0x800775A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    hud_setting(rdram, ctx);
        goto after_3;
    // 0x800775A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x800775A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800775AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800775B0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800775B4: bne         $v0, $zero, L_800775D8
    if (ctx->r2 != 0) {
        // 0x800775B8: andi        $t7, $t1, 0x3FF
        ctx->r15 = ctx->r9 & 0X3FF;
            goto L_800775D8;
    }
    // 0x800775B8: andi        $t7, $t1, 0x3FF
    ctx->r15 = ctx->r9 & 0X3FF;
    // 0x800775BC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800775C0: nop

    // 0x800775C4: lb          $t5, 0x4C($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X4C);
    // 0x800775C8: nop

    // 0x800775CC: andi        $t3, $t5, 0x40
    ctx->r11 = ctx->r13 & 0X40;
    // 0x800775D0: beq         $t3, $zero, L_80077620
    if (ctx->r11 == 0) {
        // 0x800775D4: nop
    
            goto L_80077620;
    }
    // 0x800775D4: nop

L_800775D8:
    // 0x800775D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800775DC: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800775E0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800775E4: andi        $t4, $t0, 0x3FF
    ctx->r12 = ctx->r8 & 0X3FF;
    // 0x800775E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800775EC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800775F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800775F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800775F8: or          $t3, $t9, $t5
    ctx->r11 = ctx->r25 | ctx->r13;
    // 0x800775FC: srl         $t6, $t1, 1
    ctx->r14 = S32(U32(ctx->r9) >> 1);
    // 0x80077600: srl         $t4, $t0, 1
    ctx->r12 = S32(U32(ctx->r8) >> 1);
    // 0x80077604: andi        $t9, $t4, 0x3FF
    ctx->r25 = ctx->r12 & 0X3FF;
    // 0x80077608: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8007760C: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077610: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80077614: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80077618: or          $t3, $t8, $t5
    ctx->r11 = ctx->r24 | ctx->r13;
    // 0x8007761C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80077620:
    // 0x80077620: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077624: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x80077628: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x8007762C: andi        $t4, $t1, 0x3FF
    ctx->r12 = ctx->r9 & 0X3FF;
    // 0x80077630: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077634: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x80077638: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8007763C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077640: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077644: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077648: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007764C: andi        $t3, $t5, 0x3FF
    ctx->r11 = ctx->r13 & 0X3FF;
    // 0x80077650: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80077654: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x80077658: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8007765C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80077660: srl         $t3, $t1, 1
    ctx->r11 = S32(U32(ctx->r9) >> 1);
    // 0x80077664: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077668: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007766C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077670: subu        $a1, $t3, $a3
    ctx->r5 = SUB32(ctx->r11, ctx->r7);
    // 0x80077674: addu        $t8, $a1, $a3
    ctx->r24 = ADD32(ctx->r5, ctx->r7);
    // 0x80077678: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8007767C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80077680: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80077684: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80077688: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x8007768C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80077690: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x80077694: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80077698: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x8007769C: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x800776A0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800776A4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800776A8:
    // 0x800776A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800776AC:
    // 0x800776AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800776B0: jr          $ra
    // 0x800776B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800776B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void divider_clear_coverage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800776BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800776C0: jal         0x8007A970
    // 0x800776C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800776C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800776C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800776CC: srl         $a1, $v0, 16
    ctx->r5 = S32(U32(ctx->r2) >> 16);
    // 0x800776D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800776D4: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x800776D8: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800776DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800776E0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800776E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800776E8: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800776EC: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x800776F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800776F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800776F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800776FC: srl         $t8, $a2, 8
    ctx->r24 = S32(U32(ctx->r6) >> 8);
    // 0x80077700: sll         $ra, $t8, 2
    ctx->r31 = S32(ctx->r24 << 2);
    // 0x80077704: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077708: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8007770C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80077710: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077714: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80077718: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8007771C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077720: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077724: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077728: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8007772C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80077730: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80077734: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80077738: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8007773C: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x80077740: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077744: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077748: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007774C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80077750: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077754: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077758: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007775C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077764: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007776C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80077770: jal         0x80066450
    // 0x80077774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80077774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077778: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007777C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80077780: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80077784: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80077788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007778C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077790: beq         $v0, $at, L_800777B8
    if (ctx->r2 == ctx->r1) {
        // 0x80077794: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_800777B8;
    }
    // 0x80077794: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x80077798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007779C: beq         $v0, $at, L_80077800
    if (ctx->r2 == ctx->r1) {
        // 0x800777A0: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_80077800;
    }
    // 0x800777A0: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x800777A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800777A8: beq         $v0, $at, L_80077800
    if (ctx->r2 == ctx->r1) {
        // 0x800777AC: nop
    
            goto L_80077800;
    }
    // 0x800777AC: nop

    // 0x800777B0: b           L_8007788C
    // 0x800777B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007788C;
    // 0x800777B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800777B8:
    // 0x800777B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800777BC: srl         $t9, $t4, 1
    ctx->r25 = S32(U32(ctx->r12) >> 1);
    // 0x800777C0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800777C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800777C8: srl         $t6, $t2, 1
    ctx->r14 = S32(U32(ctx->r10) >> 1);
    // 0x800777CC: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x800777D0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800777D4: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x800777D8: addu        $t6, $v0, $t2
    ctx->r14 = ADD32(ctx->r2, ctx->r10);
    // 0x800777DC: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800777E0: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x800777E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800777E8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800777EC: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x800777F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800777F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800777F8: b           L_80077888
    // 0x800777FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80077888;
    // 0x800777FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80077800:
    // 0x80077800: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077804: srl         $t6, $t4, 1
    ctx->r14 = S32(U32(ctx->r12) >> 1);
    // 0x80077808: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007780C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077810: srl         $t7, $t2, 1
    ctx->r15 = S32(U32(ctx->r10) >> 1);
    // 0x80077814: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x80077818: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8007781C: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80077820: addu        $t7, $v0, $t2
    ctx->r15 = ADD32(ctx->r2, ctx->r10);
    // 0x80077824: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80077828: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x8007782C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80077830: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80077834: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80077838: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007783C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077840: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077844: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077848: srl         $t7, $t5, 1
    ctx->r15 = S32(U32(ctx->r13) >> 1);
    // 0x8007784C: srl         $t9, $ra, 1
    ctx->r25 = S32(U32(ctx->r31) >> 1);
    // 0x80077850: subu        $a2, $t7, $t9
    ctx->r6 = SUB32(ctx->r15, ctx->r25);
    // 0x80077854: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077858: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007785C: addu        $t6, $a2, $ra
    ctx->r14 = ADD32(ctx->r6, ctx->r31);
    // 0x80077860: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80077864: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80077868: andi        $t6, $t4, 0x3FF
    ctx->r14 = ctx->r12 & 0X3FF;
    // 0x8007786C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80077870: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x80077874: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80077878: andi        $t6, $a2, 0x3FF
    ctx->r14 = ctx->r6 & 0X3FF;
    // 0x8007787C: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x80077880: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077884: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80077888:
    // 0x80077888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007788C:
    // 0x8007788C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80077890: jr          $ra
    // 0x80077894: nop

    return;
    // 0x80077894: nop

    // 0x80077898: nop

    // 0x8007789C: nop

;}
RECOMP_FUNC void gfxtask_run_xbus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800778A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800778A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800778AC: addiu       $v1, $v1, -0x15AC
    ctx->r3 = ADD32(ctx->r3, -0X15AC);
    // 0x800778B0: sw          $t6, -0x15A4($at)
    MEM_W(-0X15A4, ctx->r1) = ctx->r14;
    // 0x800778B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800778B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800778BC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800778C0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800778C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800778C8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800778CC: addiu       $t8, $t8, 0x64E0
    ctx->r24 = ADD32(ctx->r24, 0X64E0);
    // 0x800778D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800778D4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800778D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800778DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800778E0: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800778E4: bne         $t9, $at, L_800778F0
    if (ctx->r25 != ctx->r1) {
        // 0x800778E8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800778F0;
    }
    // 0x800778E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800778EC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800778F0:
    // 0x800778F0: subu        $t3, $a1, $a0
    ctx->r11 = SUB32(ctx->r5, ctx->r4);
    // 0x800778F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800778F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800778FC: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80077900: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80077904: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077908: addiu       $v1, $v1, -0x75E0
    ctx->r3 = ADD32(ctx->r3, -0X75E0);
    // 0x8007790C: addiu       $t2, $t2, 0x6478
    ctx->r10 = ADD32(ctx->r10, 0X6478);
    // 0x80077910: sw          $t4, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r12;
    // 0x80077914: sw          $t5, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r13;
    // 0x80077918: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007791C: addiu       $t7, $t7, -0x7510
    ctx->r15 = ADD32(ctx->r15, -0X7510);
    // 0x80077920: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077924: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80077928: sw          $t2, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r10;
    // 0x8007792C: sw          $t6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r14;
    // 0x80077930: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80077934: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077938: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007793C: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077940: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80077944: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80077948: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8007794C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077950: addiu       $t4, $t4, 0x4C40
    ctx->r12 = ADD32(ctx->r12, 0X4C40);
    // 0x80077954: addiu       $t5, $t5, 0x6440
    ctx->r13 = ADD32(ctx->r13, 0X6440);
    // 0x80077958: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007795C: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x80077960: addiu       $t9, $t9, -0x5120
    ctx->r25 = ADD32(ctx->r25, -0X5120);
    // 0x80077964: addiu       $t0, $t0, -0x4EE0
    ctx->r8 = ADD32(ctx->r8, -0X4EE0);
    // 0x80077968: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8007796C: addiu       $t2, $t2, 0x4840
    ctx->r10 = ADD32(ctx->r10, 0X4840);
    // 0x80077970: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80077974: sw          $t4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r12;
    // 0x80077978: sw          $t5, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r13;
    // 0x8007797C: addiu       $t6, $t6, 0x7770
    ctx->r14 = ADD32(ctx->r14, 0X7770);
    // 0x80077980: addiu       $t7, $zero, 0xA00
    ctx->r15 = ADD32(0, 0XA00);
    // 0x80077984: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077988: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x8007798C: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077990: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
    // 0x80077994: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x80077998: sw          $t0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r8;
    // 0x8007799C: sw          $t1, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r9;
    // 0x800779A0: sw          $t2, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r10;
    // 0x800779A4: sw          $t3, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r11;
    // 0x800779A8: sw          $t6, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r14;
    // 0x800779AC: sw          $t7, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r15;
    // 0x800779B0: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800779B4: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800779B8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800779BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800779C0: lw          $t8, 0x6874($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6874);
    // 0x800779C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800779C8: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x800779CC: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x800779D0: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
    // 0x800779D4: jal         0x800D1E00
    // 0x800779D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800779D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800779DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800779E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800779E4: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x800779E8: jal         0x800C9390
    // 0x800779EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800779EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800779F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800779F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800779F8: jr          $ra
    // 0x800779FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800779FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void gfxtask_run_xbus_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A00: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077A04: addiu       $v1, $v1, -0x15A8
    ctx->r3 = ADD32(ctx->r3, -0X15A8);
    // 0x80077A08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077A0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077A10: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077A14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077A18: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077A1C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077A20: addiu       $t7, $t7, 0x65C0
    ctx->r15 = ADD32(ctx->r15, 0X65C0);
    // 0x80077A24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077A28: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077A30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077A34: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077A38: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077A3C: bne         $t8, $at, L_80077A48
    if (ctx->r24 != ctx->r1) {
        // 0x80077A40: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077A48;
    }
    // 0x80077A40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077A44: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077A48:
    // 0x80077A48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077A4C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077A50: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077A54: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077A58: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077A5C: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077A60: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077A64: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077A68: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077A6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077A70: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077A74: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077A78: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077A7C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077A80: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077A84: addiu       $t7, $t7, -0x5120
    ctx->r15 = ADD32(ctx->r15, -0X5120);
    // 0x80077A88: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077A8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077A90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077A94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80077A98: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077A9C: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077AA0: addiu       $t8, $t8, -0x4EE0
    ctx->r24 = ADD32(ctx->r24, -0X4EE0);
    // 0x80077AA4: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077AA8: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077AAC: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077AB0: addiu       $t2, $t2, 0x7770
    ctx->r10 = ADD32(ctx->r10, 0X7770);
    // 0x80077AB4: addiu       $t3, $zero, 0xA00
    ctx->r11 = ADD32(0, 0XA00);
    // 0x80077AB8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80077ABC: addiu       $t5, $t5, 0x6478
    ctx->r13 = ADD32(ctx->r13, 0X6478);
    // 0x80077AC0: addiu       $t6, $t6, -0x15F0
    ctx->r14 = ADD32(ctx->r14, -0X15F0);
    // 0x80077AC4: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077AC8: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077ACC: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077AD0: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077AD4: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077AD8: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077ADC: sw          $t2, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r10;
    // 0x80077AE0: sw          $t3, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r11;
    // 0x80077AE4: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80077AE8: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80077AEC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077AF0: sw          $t4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r12;
    // 0x80077AF4: sw          $t5, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r13;
    // 0x80077AF8: sw          $t6, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r14;
    // 0x80077AFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077B00: lw          $t7, 0x6874($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6874);
    // 0x80077B04: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077B08: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077B0C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80077B10: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077B14: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077B18: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x80077B1C: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x80077B20: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077B24: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x80077B28: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80077B2C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077B30: beq         $t8, $zero, L_80077B3C
    if (ctx->r24 == 0) {
        // 0x80077B34: addiu       $t9, $t9, 0x6440
        ctx->r25 = ADD32(ctx->r25, 0X6440);
            goto L_80077B3C;
    }
    // 0x80077B34: addiu       $t9, $t9, 0x6440
    ctx->r25 = ADD32(ctx->r25, 0X6440);
    // 0x80077B38: sw          $t9, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r25;
L_80077B3C:
    // 0x80077B3C: jal         0x800D1E00
    // 0x80077B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077B40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077B44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077B48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077B4C: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077B50: jal         0x800C9390
    // 0x80077B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077B58: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077B5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077B60: beq         $t0, $zero, L_80077B74
    if (ctx->r8 == 0) {
        // 0x80077B64: addiu       $a0, $a0, 0x6440
        ctx->r4 = ADD32(ctx->r4, 0X6440);
            goto L_80077B74;
    }
    // 0x80077B64: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80077B68: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077B6C: jal         0x800C9110
    // 0x80077B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077B74:
    // 0x80077B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077B7C: jr          $ra
    // 0x80077B80: nop

    return;
    // 0x80077B80: nop

;}
RECOMP_FUNC void gfxtask_run_fifo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077B88: addiu       $v1, $v1, -0x15A8
    ctx->r3 = ADD32(ctx->r3, -0X15A8);
    // 0x80077B8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077B94: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077B98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077B9C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077BA0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077BA4: addiu       $t7, $t7, 0x65C0
    ctx->r15 = ADD32(ctx->r15, 0X65C0);
    // 0x80077BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077BAC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077BB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077BB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077BBC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077BC0: bne         $t8, $at, L_80077BCC
    if (ctx->r24 != ctx->r1) {
        // 0x80077BC4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077BCC;
    }
    // 0x80077BC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077BC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077BCC:
    // 0x80077BCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077BD0: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077BD4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077BD8: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077BDC: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077BE0: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077BE4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077BE8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077BEC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077BF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077BF4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077BF8: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077BFC: addiu       $t7, $t7, -0x6310
    ctx->r15 = ADD32(ctx->r15, -0X6310);
    // 0x80077C00: addiu       $t8, $t8, -0x56E0
    ctx->r24 = ADD32(ctx->r24, -0X56E0);
    // 0x80077C04: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077C08: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077C0C: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077C10: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077C14: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077C18: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077C1C: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077C20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077C24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077C28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80077C2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077C30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077C34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077C38: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077C3C: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077C40: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077C44: addiu       $t2, $t2, 0x4C40
    ctx->r10 = ADD32(ctx->r10, 0X4C40);
    // 0x80077C48: addiu       $t3, $t3, 0x6440
    ctx->r11 = ADD32(ctx->r11, 0X6440);
    // 0x80077C4C: addiu       $t4, $t4, 0x7770
    ctx->r12 = ADD32(ctx->r12, 0X7770);
    // 0x80077C50: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80077C54: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80077C58: addiu       $t7, $t7, 0x6478
    ctx->r15 = ADD32(ctx->r15, 0X6478);
    // 0x80077C5C: addiu       $t8, $t8, -0x15F0
    ctx->r24 = ADD32(ctx->r24, -0X15F0);
    // 0x80077C60: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077C64: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077C68: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077C6C: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077C70: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x80077C74: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x80077C78: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x80077C7C: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x80077C80: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077C84: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x80077C88: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x80077C8C: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x80077C90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077C94: lw          $t9, 0x6874($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6874);
    // 0x80077C98: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077C9C: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077CA0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80077CA4: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077CA8: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077CAC: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x80077CB0: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x80077CB4: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077CB8: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80077CBC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077CC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80077CC4: beq         $t0, $zero, L_80077CD0
    if (ctx->r8 == 0) {
        // 0x80077CC8: addiu       $t1, $t1, 0x6440
        ctx->r9 = ADD32(ctx->r9, 0X6440);
            goto L_80077CD0;
    }
    // 0x80077CC8: addiu       $t1, $t1, 0x6440
    ctx->r9 = ADD32(ctx->r9, 0X6440);
    // 0x80077CCC: sw          $t1, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r9;
L_80077CD0:
    // 0x80077CD0: jal         0x800D1E00
    // 0x80077CD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077CD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077CD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077CDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077CE0: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077CE4: jal         0x800C9390
    // 0x80077CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077CEC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80077CF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077CF4: beq         $t2, $zero, L_80077D08
    if (ctx->r10 == 0) {
        // 0x80077CF8: addiu       $a0, $a0, 0x6440
        ctx->r4 = ADD32(ctx->r4, 0X6440);
            goto L_80077D08;
    }
    // 0x80077CF8: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80077CFC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077D00: jal         0x800C9110
    // 0x80077D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077D08:
    // 0x80077D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077D0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077D10: jr          $ra
    // 0x80077D14: nop

    return;
    // 0x80077D14: nop

;}
RECOMP_FUNC void gfxtask_run_fifo_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D18: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077D1C: addiu       $v1, $v1, -0x15AC
    ctx->r3 = ADD32(ctx->r3, -0X15AC);
    // 0x80077D20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077D24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077D28: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077D2C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077D30: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077D34: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077D38: addiu       $t7, $t7, 0x64E0
    ctx->r15 = ADD32(ctx->r15, 0X64E0);
    // 0x80077D3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80077D40: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077D48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077D4C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077D50: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077D54: bne         $t8, $at, L_80077D60
    if (ctx->r24 != ctx->r1) {
        // 0x80077D58: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077D60;
    }
    // 0x80077D58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077D5C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077D60:
    // 0x80077D60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077D64: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077D68: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077D6C: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077D70: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077D74: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077D78: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077D7C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077D80: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077D84: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077D88: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077D8C: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077D90: addiu       $t7, $t7, -0x6310
    ctx->r15 = ADD32(ctx->r15, -0X6310);
    // 0x80077D94: addiu       $t8, $t8, -0x56E0
    ctx->r24 = ADD32(ctx->r24, -0X56E0);
    // 0x80077D98: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077D9C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077DA0: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077DA4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077DA8: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077DAC: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077DB0: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077DB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077DB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077DBC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80077DC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077DC4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077DC8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077DCC: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077DD0: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077DD4: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077DD8: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077DDC: addiu       $t2, $t2, 0x4C40
    ctx->r10 = ADD32(ctx->r10, 0X4C40);
    // 0x80077DE0: addiu       $t3, $t3, 0x6440
    ctx->r11 = ADD32(ctx->r11, 0X6440);
    // 0x80077DE4: addiu       $t4, $t4, 0x7770
    ctx->r12 = ADD32(ctx->r12, 0X7770);
    // 0x80077DE8: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80077DEC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80077DF0: addiu       $t7, $t7, 0x6478
    ctx->r15 = ADD32(ctx->r15, 0X6478);
    // 0x80077DF4: addiu       $t8, $t8, -0x15F0
    ctx->r24 = ADD32(ctx->r24, -0X15F0);
    // 0x80077DF8: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077DFC: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077E00: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077E04: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x80077E08: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x80077E0C: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x80077E10: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x80077E14: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077E18: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x80077E1C: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x80077E20: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x80077E24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077E28: lw          $t9, 0x6874($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6874);
    // 0x80077E2C: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077E30: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077E34: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077E38: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077E3C: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80077E40: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077E44: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80077E48: beq         $t0, $zero, L_80077E58
    if (ctx->r8 == 0) {
        // 0x80077E4C: nop
    
            goto L_80077E58;
    }
    // 0x80077E4C: nop

    // 0x80077E50: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x80077E54: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
L_80077E58:
    // 0x80077E58: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077E5C: jal         0x800D1E00
    // 0x80077E60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077E60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077E64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077E68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077E6C: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077E70: jal         0x800C9390
    // 0x80077E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077E78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80077E7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077E80: beq         $t1, $zero, L_80077E94
    if (ctx->r9 == 0) {
        // 0x80077E84: addiu       $a0, $a0, 0x6478
        ctx->r4 = ADD32(ctx->r4, 0X6478);
            goto L_80077E94;
    }
    // 0x80077E84: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x80077E88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077E8C: jal         0x800C9110
    // 0x80077E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077E94:
    // 0x80077E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077E9C: jr          $ra
    // 0x80077EA0: nop

    return;
    // 0x80077EA0: nop

;}
RECOMP_FUNC void gfxtask_wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EA4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077EA8: lw          $t6, -0x15A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15A4);
    // 0x80077EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077EB4: bne         $t6, $zero, L_80077EC4
    if (ctx->r14 != 0) {
        // 0x80077EB8: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80077EC4;
    }
    // 0x80077EB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077EBC: b           L_80077EEC
    // 0x80077EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077EEC;
    // 0x80077EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077EC4:
    // 0x80077EC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077EC8: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x80077ECC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077ED0: jal         0x800C9110
    // 0x80077ED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077ED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077ED8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80077EDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077EE0: sw          $zero, -0x15A4($at)
    MEM_W(-0X15A4, ctx->r1) = 0;
    // 0x80077EE4: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80077EE8: nop

L_80077EEC:
    // 0x80077EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80077EF4: jr          $ra
    // 0x80077EF8: nop

    return;
    // 0x80077EF8: nop

;}
RECOMP_FUNC void gfxtask_run_rdp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077F08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80077F0C: jal         0x800D1E00
    // 0x80077F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077F14: jal         0x800D1E30
    // 0x80077F18: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x80077F18: nop

    after_1:
    // 0x80077F1C: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80077F20: beq         $t6, $zero, L_80077F40
    if (ctx->r14 == 0) {
        // 0x80077F24: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80077F40;
    }
    // 0x80077F24: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077F28:
    // 0x80077F28: jal         0x800D1E30
    // 0x80077F2C: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x80077F2C: nop

    after_2:
    // 0x80077F30: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80077F34: bne         $t7, $zero, L_80077F28
    if (ctx->r15 != 0) {
        // 0x80077F38: nop
    
            goto L_80077F28;
    }
    // 0x80077F38: nop

    // 0x80077F3C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077F40:
    // 0x80077F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80077F44: jal         0x800D1E40
    // 0x80077F48: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80077F48: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_3:
    // 0x80077F4C: jal         0x800D1E30
    // 0x80077F50: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x80077F50: nop

    after_4:
    // 0x80077F54: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80077F58: beq         $t9, $zero, L_80077F78
    if (ctx->r25 == 0) {
        // 0x80077F5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80077F78;
    }
    // 0x80077F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077F60:
    // 0x80077F60: jal         0x800D1E30
    // 0x80077F64: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_5;
    // 0x80077F64: nop

    after_5:
    // 0x80077F68: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80077F6C: bne         $t0, $zero, L_80077F60
    if (ctx->r8 != 0) {
        // 0x80077F70: nop
    
            goto L_80077F60;
    }
    // 0x80077F70: nop

    // 0x80077F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077F78:
    // 0x80077F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077F7C: jr          $ra
    // 0x80077F80: nop

    return;
    // 0x80077F80: nop

;}
RECOMP_FUNC void bgdraw_primcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F88: sb          $a0, -0x15D0($at)
    MEM_B(-0X15D0, ctx->r1) = ctx->r4;
    // 0x80077F8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F90: sb          $a1, -0x15CC($at)
    MEM_B(-0X15CC, ctx->r1) = ctx->r5;
    // 0x80077F94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80077F9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80077FA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80077FA4: jr          $ra
    // 0x80077FA8: sb          $a2, -0x15C8($at)
    MEM_B(-0X15C8, ctx->r1) = ctx->r6;
    return;
    // 0x80077FA8: sb          $a2, -0x15C8($at)
    MEM_B(-0X15C8, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void bgdraw_fillcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FAC: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80077FB0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80077FB4: andi        $t9, $t8, 0x7C0
    ctx->r25 = ctx->r24 & 0X7C0;
    // 0x80077FB8: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x80077FBC: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80077FC0: andi        $t2, $t1, 0x3E
    ctx->r10 = ctx->r9 & 0X3E;
    // 0x80077FC4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80077FC8: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80077FCC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80077FD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077FD4: addiu       $v1, $v1, -0x15C4
    ctx->r3 = ADD32(ctx->r3, -0X15C4);
    // 0x80077FD8: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80077FDC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80077FE0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80077FE4: jr          $ra
    // 0x80077FE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x80077FE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void bgdraw_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FEC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80077FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80077FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80077FFC: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80078000: jal         0x8007A970
    // 0x80078004: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078004: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80078008: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8007800C: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x80078010: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80078014: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078018: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007801C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80078020: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078024: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80078028: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8007802C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078030: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078034: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80078038: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x8007803C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078048: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007804C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80078050: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80078054: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80078058: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007805C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078060: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078064: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078068: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007806C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078070: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078074: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80078078: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007807C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078080: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80078084: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078088: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x8007808C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80078090: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80078094: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078098: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007809C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800780A0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800780A4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800780A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800780AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780B0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800780B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800780B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800780BC: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800780C0: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800780C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800780C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800780CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780D0: lui         $ra, 0xFF10
    ctx->r31 = S32(0XFF10 << 16);
    // 0x800780D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800780D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800780DC: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x800780E0: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x800780E4: lui         $t8, 0x200
    ctx->r24 = S32(0X200 << 16);
    // 0x800780E8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800780EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800780F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800780F4: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x800780F8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800780FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078100: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x80078104: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x80078108: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007810C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80078110: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078114: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80078118: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007811C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078120: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078124: andi        $t9, $t2, 0x3FF
    ctx->r25 = ctx->r10 & 0X3FF;
    // 0x80078128: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8007812C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078130: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80078134: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80078138: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007813C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078140: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078144: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80078148: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007814C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078150: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078154: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078158: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007815C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80078160: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078164: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078168: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x8007816C: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x80078170: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078174: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078178: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x8007817C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078180: beq         $t8, $zero, L_80078474
    if (ctx->r24 == 0) {
        // 0x80078184: nop
    
            goto L_80078474;
    }
    // 0x80078184: nop

    // 0x80078188: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x8007818C: jal         0x80066B50
    // 0x80078190: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    check_viewport_background_flag(rdram, ctx);
        goto after_1;
    // 0x80078190: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    after_1:
    // 0x80078194: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x80078198: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007819C: beq         $v0, $zero, L_80078384
    if (ctx->r2 == 0) {
        // 0x800781A0: lui         $a3, 0xF700
        ctx->r7 = S32(0XF700 << 16);
            goto L_80078384;
    }
    // 0x800781A0: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x800781A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800781A8: lw          $t6, -0x15B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15B4);
    // 0x800781AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800781B0: beq         $t6, $zero, L_800781C8
    if (ctx->r14 == 0) {
        // 0x800781B4: nop
    
            goto L_800781C8;
    }
    // 0x800781B4: nop

    // 0x800781B8: jal         0x80078C4C
    // 0x800781BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_2;
    // 0x800781BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800781C0: b           L_8007825C
    // 0x800781C4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x800781C4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_800781C8:
    // 0x800781C8: lw          $t9, -0x15BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X15BC);
    // 0x800781CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800781D0: beq         $t9, $zero, L_800781E8
    if (ctx->r25 == 0) {
        // 0x800781D4: nop
    
            goto L_800781E8;
    }
    // 0x800781D4: nop

    // 0x800781D8: jal         0x800785E0
    // 0x800781DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_3;
    // 0x800781DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800781E0: b           L_8007825C
    // 0x800781E4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x800781E4: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_800781E8:
    // 0x800781E8: lw          $v0, -0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X15B0);
    // 0x800781EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800781F0: beq         $v0, $zero, L_8007820C
    if (ctx->r2 == 0) {
        // 0x800781F4: addiu       $t9, $t4, -0x1
        ctx->r25 = ADD32(ctx->r12, -0X1);
            goto L_8007820C;
    }
    // 0x800781F4: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x800781F8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800781FC: jalr        $v0
    // 0x80078200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80078200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80078204: b           L_8007825C
    // 0x80078208: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_8007825C;
    // 0x80078208: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_8007820C:
    // 0x8007820C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078210: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80078214: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078218: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007821C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80078220: lw          $t8, -0x15C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15C4);
    // 0x80078224: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078228: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007822C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078230: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80078234: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078238: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007823C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x80078240: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078244: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80078248: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007824C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80078250: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078254: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078258: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_8007825C:
    // 0x8007825C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80078260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80078264: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80078268: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8007826C: jal         0x80066DE8
    // 0x80078270: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    copy_viewport_background_size_to_coords(rdram, ctx);
        goto after_5;
    // 0x80078270: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x80078274: beq         $v0, $zero, L_80078474
    if (ctx->r2 == 0) {
        // 0x80078278: lui         $t8, 0xBA00
        ctx->r24 = S32(0XBA00 << 16);
            goto L_80078474;
    }
    // 0x80078278: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8007827C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078280: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80078284: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078288: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007828C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078290: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078294: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078298: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007829C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800782A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800782A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800782A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800782AC: lbu         $t8, -0x15D0($t6)
    ctx->r24 = MEM_BU(ctx->r14, -0X15D0);
    // 0x800782B0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800782B4: lbu         $t6, -0x15CC($t7)
    ctx->r14 = MEM_BU(ctx->r15, -0X15CC);
    // 0x800782B8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800782BC: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800782C0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800782C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800782C8: lbu         $t9, -0x15C8($t6)
    ctx->r25 = MEM_BU(ctx->r14, -0X15C8);
    // 0x800782CC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800782D0: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800782D4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800782D8: ori         $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 | 0XFF;
    // 0x800782DC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800782E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800782E4: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800782E8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800782EC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800782F0: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800782F4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800782F8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800782FC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078300: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078304: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078308: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x8007830C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078310: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078314: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80078318: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8007831C: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x80078320: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80078324: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078328: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007832C: nop

    // 0x80078330: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078334: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078338: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8007833C: nop

    // 0x80078340: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078344: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80078348: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8007834C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80078350: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078354: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078358: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007835C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078360: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80078364: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80078368: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8007836C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80078370: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80078374: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078378: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007837C: b           L_80078474
    // 0x80078380: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80078474;
    // 0x80078380: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80078384:
    // 0x80078384: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80078388: lw          $t7, -0x15B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X15B4);
    // 0x8007838C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078390: beq         $t7, $zero, L_800783A8
    if (ctx->r15 == 0) {
        // 0x80078394: nop
    
            goto L_800783A8;
    }
    // 0x80078394: nop

    // 0x80078398: jal         0x80078C4C
    // 0x8007839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_6;
    // 0x8007839C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800783A0: b           L_80078478
    // 0x800783A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783A8:
    // 0x800783A8: lw          $t8, -0x15BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15BC);
    // 0x800783AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800783B0: beq         $t8, $zero, L_800783C8
    if (ctx->r24 == 0) {
        // 0x800783B4: nop
    
            goto L_800783C8;
    }
    // 0x800783B4: nop

    // 0x800783B8: jal         0x800785E0
    // 0x800783BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_7;
    // 0x800783BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800783C0: b           L_80078478
    // 0x800783C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783C8:
    // 0x800783C8: lw          $v0, -0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X15B0);
    // 0x800783CC: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800783D0: beq         $v0, $zero, L_800783E8
    if (ctx->r2 == 0) {
        // 0x800783D4: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800783E8;
    }
    // 0x800783D4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800783D8: jalr        $v0
    // 0x800783DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x800783DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800783E0: b           L_80078478
    // 0x800783E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078478;
    // 0x800783E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800783E8:
    // 0x800783E8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800783EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800783F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800783F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800783F8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800783FC: lbu         $t9, -0x15D0($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15D0);
    // 0x80078400: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078404: lbu         $t6, -0x15CC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X15CC);
    // 0x80078408: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8007840C: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x80078410: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x80078414: andi        $t7, $t9, 0x7C0
    ctx->r15 = ctx->r25 & 0X7C0;
    // 0x80078418: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007841C: lbu         $t9, -0x15C8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15C8);
    // 0x80078420: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80078424: sra         $t8, $t9, 2
    ctx->r24 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80078428: andi        $t7, $t8, 0x3E
    ctx->r15 = ctx->r24 & 0X3E;
    // 0x8007842C: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x80078430: ori         $t9, $a0, 0x1
    ctx->r25 = ctx->r4 | 0X1;
    // 0x80078434: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80078438: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8007843C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078440: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078444: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80078448: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8007844C: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078450: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078454: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078458: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007845C: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078460: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078464: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80078468: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007846C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078470: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80078474:
    // 0x80078474: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80078478:
    // 0x80078478: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007847C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078480: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078488: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007848C: jal         0x80067C7C
    // 0x80078490: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    viewport_scissor(rdram, ctx);
        goto after_9;
    // 0x80078490: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_9:
    // 0x80078494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078498: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007849C: jr          $ra
    // 0x800784A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800784A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void rdp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800784A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800784AC: jal         0x8007A970
    // 0x800784B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800784B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800784B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800784B8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800784BC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800784C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800784C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800784C8: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800784CC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800784D0: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800784D4: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x800784D8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800784DC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800784E0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800784E4: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x800784E8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800784EC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800784F0: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x800784F4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800784F8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800784FC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078500: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80078504: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80078508: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007850C: addiu       $t7, $t7, -0x1560
    ctx->r15 = ADD32(ctx->r15, -0X1560);
    // 0x80078510: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80078514: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078518: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007851C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078524: jr          $ra
    // 0x80078528: nop

    return;
    // 0x80078528: nop

;}
RECOMP_FUNC void rsp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007852C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078530: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078534: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078538: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007853C: addiu       $t8, $t8, -0x15A0
    ctx->r24 = ADD32(ctx->r24, -0X15A0);
    // 0x80078540: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80078544: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078548: jr          $ra
    // 0x8007854C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x8007854C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void gfxtask_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078558: jal         0x800799CC
    // 0x8007855C: nop

    osScGetInterruptQ(rdram, ctx);
        goto after_0;
    // 0x8007855C: nop

    after_0:
    // 0x80078560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078564: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078568: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007856C: sw          $v0, 0x66A0($at)
    MEM_W(0X66A0, ctx->r1) = ctx->r2;
    // 0x80078570: addiu       $a1, $a1, 0x6458
    ctx->r5 = ADD32(ctx->r5, 0X6458);
    // 0x80078574: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80078578: jal         0x800C8D80
    // 0x8007857C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8007857C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80078580: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078584: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80078588: addiu       $a1, $a1, 0x6490
    ctx->r5 = ADD32(ctx->r5, 0X6490);
    // 0x8007858C: addiu       $a0, $a0, 0x6460
    ctx->r4 = ADD32(ctx->r4, 0X6460);
    // 0x80078590: jal         0x800C8D80
    // 0x80078594: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80078594: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80078598: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007859C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800785A0: addiu       $a1, $a1, 0x64B0
    ctx->r5 = ADD32(ctx->r5, 0X64B0);
    // 0x800785A4: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x800785A8: jal         0x800C8D80
    // 0x800785AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800785AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800785B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800785B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800785B8: jr          $ra
    // 0x800785BC: nop

    return;
    // 0x800785BC: nop

;}
RECOMP_FUNC void bgdraw_texture_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800785C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785C4: sw          $a0, -0x15BC($at)
    MEM_W(-0X15BC, ctx->r1) = ctx->r4;
    // 0x800785C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785CC: sw          $a1, -0x15B8($at)
    MEM_W(-0X15B8, ctx->r1) = ctx->r5;
    // 0x800785D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785D4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800785D8: jr          $ra
    // 0x800785DC: sw          $t6, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r14;
    return;
    // 0x800785DC: sw          $t6, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void bgdraw_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800785E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800785E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800785E8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800785EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800785F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800785F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800785F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800785FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80078600: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80078604: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80078608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007860C: jal         0x8007A970
    // 0x80078610: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078610: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80078614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80078618: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007861C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078620: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80078624: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078628: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007862C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80078630: andi        $t6, $t0, 0xFFFF
    ctx->r14 = ctx->r8 & 0XFFFF;
    // 0x80078634: addiu       $t9, $t9, -0x14E8
    ctx->r25 = ADD32(ctx->r25, -0X14E8);
    // 0x80078638: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8007863C: addiu       $t2, $t2, -0x15B8
    ctx->r10 = ADD32(ctx->r10, -0X15B8);
    // 0x80078640: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80078644: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078648: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007864C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80078650: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078654: bne         $t6, $zero, L_80078818
    if (ctx->r14 != 0) {
        // 0x80078658: addiu       $t1, $t1, -0x15BC
        ctx->r9 = ADD32(ctx->r9, -0X15BC);
            goto L_80078818;
    }
    // 0x80078658: addiu       $t1, $t1, -0x15BC
    ctx->r9 = ADD32(ctx->r9, -0X15BC);
    // 0x8007865C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078660: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078664: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078668: addiu       $t1, $t1, -0x15BC
    ctx->r9 = ADD32(ctx->r9, -0X15BC);
    // 0x8007866C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078670: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078674: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80078678: lh          $a3, 0xA($t8)
    ctx->r7 = MEM_H(ctx->r24, 0XA);
    // 0x8007867C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80078680: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x80078684: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078688: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007868C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80078690: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078694: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80078698: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007869C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800786A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800786A4: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x800786A8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800786AC: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x800786B0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800786B4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800786B8: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x800786BC: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x800786C0: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x800786C4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800786C8: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800786CC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800786D0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800786D4: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x800786D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800786DC: blez        $s6, L_80078B80
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800786E0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80078B80;
    }
    // 0x800786E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800786E4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800786E8: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800786EC: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800786F0: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x800786F4: addiu       $s5, $t8, -0x1
    ctx->r21 = ADD32(ctx->r24, -0X1);
    // 0x800786F8: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x800786FC: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x80078700: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_80078704:
    // 0x80078704: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x80078708: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007870C: beq         $at, $zero, L_800787F8
    if (ctx->r1 == 0) {
        // 0x80078710: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_800787F8;
    }
    // 0x80078710: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078714: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80078718: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8007871C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078720:
    // 0x80078720: bgez        $v0, L_8007878C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078724: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_8007878C;
    }
    // 0x80078724: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078728: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007872C: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078730: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078734: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078738: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007873C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80078740: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80078744: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x80078748: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007874C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078750: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078754: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078758: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007875C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078760: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80078764: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80078768: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007876C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078770: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078774: nop

    // 0x80078778: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007877C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078780: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078784: b           L_800787EC
    // 0x80078788: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_800787EC;
    // 0x80078788: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_8007878C:
    // 0x8007878C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078790: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80078794: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80078798: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x8007879C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800787A0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800787A4: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x800787A8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800787AC: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x800787B0: or          $t7, $t8, $t2
    ctx->r15 = ctx->r24 | ctx->r10;
    // 0x800787B4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800787B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800787BC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800787C0: nop

    // 0x800787C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800787C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800787CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800787D0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800787D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800787D8: nop

    // 0x800787DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800787E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800787E4: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800787E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800787EC:
    // 0x800787EC: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800787F0: bne         $at, $zero, L_80078720
    if (ctx->r1 != 0) {
        // 0x800787F4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078720;
    }
    // 0x800787F4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800787F8:
    // 0x800787F8: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800787FC: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80078800: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078804: addu        $t7, $s3, $t8
    ctx->r15 = ADD32(ctx->r19, ctx->r24);
    // 0x80078808: bne         $at, $zero, L_80078704
    if (ctx->r1 != 0) {
        // 0x8007880C: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_80078704;
    }
    // 0x8007880C: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
    // 0x80078810: b           L_80078B84
    // 0x80078814: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
        goto L_80078B84;
    // 0x80078814: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80078818:
    // 0x80078818: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007881C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80078820: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078824: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078828: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8007882C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80078830: lh          $a3, 0xA($t6)
    ctx->r7 = MEM_H(ctx->r14, 0XA);
    // 0x80078834: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x80078838: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8007883C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80078840: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x80078844: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80078848: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007884C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80078850: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078854: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80078858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007885C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80078860: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80078864: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80078868: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007886C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80078870: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80078874: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x80078878: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8007887C: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x80078880: lbu         $t7, 0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1);
    // 0x80078884: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80078888: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007888C: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x80078890: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078894: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80078898: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x8007889C: addu        $fp, $t6, $t9
    ctx->r30 = ADD32(ctx->r14, ctx->r25);
    // 0x800788A0: blez        $s6, L_800789D8
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800788A4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800789D8;
    }
    // 0x800788A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800788A8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800788AC: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800788B0: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800788B4: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x800788B8: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
    // 0x800788BC: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x800788C0: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x800788C4: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_800788C8:
    // 0x800788C8: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x800788CC: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800788D0: beq         $at, $zero, L_800789BC
    if (ctx->r1 == 0) {
        // 0x800788D4: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_800789BC;
    }
    // 0x800788D4: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x800788D8: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800788DC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800788E0: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_800788E4:
    // 0x800788E4: bgez        $v0, L_80078950
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800788E8: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_80078950;
    }
    // 0x800788E8: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800788EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800788F0: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800788F4: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x800788F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800788FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078900: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80078904: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x80078908: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x8007890C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078910: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078914: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078918: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007891C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078920: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078924: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80078928: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8007892C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078930: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078934: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078938: nop

    // 0x8007893C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078940: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078944: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078948: b           L_800789B0
    // 0x8007894C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_800789B0;
    // 0x8007894C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078950:
    // 0x80078950: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078954: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078958: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007895C: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078960: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078964: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078968: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8007896C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80078970: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x80078974: or          $t6, $t7, $t2
    ctx->r14 = ctx->r15 | ctx->r10;
    // 0x80078978: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007897C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078980: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078984: nop

    // 0x80078988: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007898C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078990: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078994: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078998: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007899C: nop

    // 0x800789A0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800789A4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800789A8: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800789AC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800789B0:
    // 0x800789B0: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800789B4: bne         $at, $zero, L_800788E4
    if (ctx->r1 != 0) {
        // 0x800789B8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800788E4;
    }
    // 0x800789B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800789BC:
    // 0x800789BC: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800789C0: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x800789C4: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800789C8: addu        $t6, $s3, $t7
    ctx->r14 = ADD32(ctx->r19, ctx->r15);
    // 0x800789CC: bne         $at, $zero, L_800788C8
    if (ctx->r1 != 0) {
        // 0x800789D0: and         $s3, $t6, $s5
        ctx->r19 = ctx->r14 & ctx->r21;
            goto L_800788C8;
    }
    // 0x800789D0: and         $s3, $t6, $s5
    ctx->r19 = ctx->r14 & ctx->r21;
    // 0x800789D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800789D8:
    // 0x800789D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800789DC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800789E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800789E4: addiu       $a2, $a2, -0x15B8
    ctx->r6 = ADD32(ctx->r6, -0X15B8);
    // 0x800789E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800789EC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800789F0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800789F4: lh          $a1, 0xA($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XA);
    // 0x800789F8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x800789FC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80078A00: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80078A04: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80078A08: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80078A0C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80078A10: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80078A14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078A18: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80078A1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80078A20: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80078A24: sll         $t8, $s6, 2
    ctx->r24 = S32(ctx->r22 << 2);
    // 0x80078A28: addu        $t7, $t9, $at
    ctx->r15 = ADD32(ctx->r25, ctx->r1);
    // 0x80078A2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078A30: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80078A34: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x80078A38: lbu         $s4, 0x1($t9)
    ctx->r20 = MEM_BU(ctx->r25, 0X1);
    // 0x80078A3C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80078A40: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80078A44: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80078A48: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80078A4C: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x80078A50: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x80078A54: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
    // 0x80078A58: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x80078A5C: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x80078A60: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80078A64: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x80078A68: beq         $at, $zero, L_80078B80
    if (ctx->r1 == 0) {
        // 0x80078A6C: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_80078B80;
    }
    // 0x80078A6C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80078A70: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
L_80078A74:
    // 0x80078A74: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x80078A78: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078A7C: beq         $at, $zero, L_80078B68
    if (ctx->r1 == 0) {
        // 0x80078A80: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_80078B68;
    }
    // 0x80078A80: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078A84: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80078A88: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x80078A8C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078A90:
    // 0x80078A90: bgez        $v0, L_80078AFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078A94: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_80078AFC;
    }
    // 0x80078A94: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078A98: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078A9C: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078AA0: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x80078AA4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078AA8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078AAC: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80078AB0: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078AB4: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x80078AB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078ABC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078AC0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078AC4: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078AC8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078ACC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078AD0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80078AD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80078AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80078ADC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078AE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078AE4: nop

    // 0x80078AE8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078AEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078AF0: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078AF4: b           L_80078B5C
    // 0x80078AF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_80078B5C;
    // 0x80078AF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078AFC:
    // 0x80078AFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B00: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078B04: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80078B08: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x80078B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B14: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x80078B18: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80078B1C: or          $t6, $t7, $t1
    ctx->r14 = ctx->r15 | ctx->r9;
    // 0x80078B20: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x80078B24: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078B28: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078B2C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B30: nop

    // 0x80078B34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078B40: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078B44: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B48: nop

    // 0x80078B4C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078B50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078B54: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078B58: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078B5C:
    // 0x80078B5C: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078B60: bne         $at, $zero, L_80078A90
    if (ctx->r1 != 0) {
        // 0x80078B64: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078A90;
    }
    // 0x80078B64: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80078B68:
    // 0x80078B68: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80078B6C: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80078B70: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078B74: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80078B78: bne         $at, $zero, L_80078A74
    if (ctx->r1 != 0) {
        // 0x80078B7C: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_80078A74;
    }
    // 0x80078B7C: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
L_80078B80:
    // 0x80078B80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80078B84:
    // 0x80078B84: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078B88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B8C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078B94: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078B98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80078B9C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80078BA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80078BA4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80078BA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80078BAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80078BB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80078BB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80078BB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80078BBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078BC0: jr          $ra
    // 0x80078BC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80078BC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bgdraw_chequer_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078BC8: sra         $t7, $a0, 24
    ctx->r15 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80078BCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BD0: sb          $t7, 0x64D0($at)
    MEM_B(0X64D0, ctx->r1) = ctx->r15;
    // 0x80078BD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BD8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80078BDC: sb          $t9, 0x64D1($at)
    MEM_B(0X64D1, ctx->r1) = ctx->r25;
    // 0x80078BE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BE4: sra         $t1, $a0, 8
    ctx->r9 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80078BE8: sb          $t1, 0x64D2($at)
    MEM_B(0X64D2, ctx->r1) = ctx->r9;
    // 0x80078BEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BF0: sb          $a0, 0x64D3($at)
    MEM_B(0X64D3, ctx->r1) = ctx->r4;
    // 0x80078BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078BF8: sra         $t4, $a1, 24
    ctx->r12 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80078BFC: sb          $t4, 0x64D4($at)
    MEM_B(0X64D4, ctx->r1) = ctx->r12;
    // 0x80078C00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C04: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80078C08: sb          $t6, 0x64D5($at)
    MEM_B(0X64D5, ctx->r1) = ctx->r14;
    // 0x80078C0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C10: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80078C14: sb          $t8, 0x64D6($at)
    MEM_B(0X64D6, ctx->r1) = ctx->r24;
    // 0x80078C18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C1C: sb          $a1, 0x64D7($at)
    MEM_B(0X64D7, ctx->r1) = ctx->r5;
    // 0x80078C20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C24: sw          $a2, 0x64D8($at)
    MEM_W(0X64D8, ctx->r1) = ctx->r6;
    // 0x80078C28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078C2C: sw          $a3, 0x64DC($at)
    MEM_W(0X64DC, ctx->r1) = ctx->r7;
    // 0x80078C30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078C34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80078C38: jr          $ra
    // 0x80078C3C: sw          $t0, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->r8;
    return;
    // 0x80078C3C: sw          $t0, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void bgdraw_chequer_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078C44: jr          $ra
    // 0x80078C48: sw          $zero, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = 0;
    return;
    // 0x80078C48: sw          $zero, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = 0;
;}
RECOMP_FUNC void bgdraw_chequer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80078C50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80078C54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078C58: jal         0x8007A970
    // 0x80078C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80078C60: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078C64: andi        $ra, $t6, 0xFFFF
    ctx->r31 = ctx->r14 & 0XFFFF;
    // 0x80078C68: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80078C6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078C70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078C74: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078C78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078C7C: addiu       $t6, $t6, -0x14A0
    ctx->r14 = ADD32(ctx->r14, -0X14A0);
    // 0x80078C80: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80078C84: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078C88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078C8C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078C90: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078C94: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078C98: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078C9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078CA0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078CA4: lbu         $t6, 0x64D0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X64D0);
    // 0x80078CA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078CAC: lbu         $t9, 0x64D1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X64D1);
    // 0x80078CB0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078CB4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078CB8: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80078CBC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078CC0: lbu         $t7, 0x64D2($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X64D2);
    // 0x80078CC4: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x80078CC8: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80078CCC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80078CD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078CD4: lbu         $t8, 0x64D3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X64D3);
    // 0x80078CD8: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80078CDC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078CE0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078CE4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80078CE8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80078CEC: blez        $t7, L_80078DB8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80078CF0: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80078DB8;
    }
    // 0x80078CF0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80078CF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80078CF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80078CFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80078D00: lw          $a2, 0x64D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X64D8);
    // 0x80078D04: addiu       $a3, $a3, 0x64D8
    ctx->r7 = ADD32(ctx->r7, 0X64D8);
    // 0x80078D08: addiu       $t1, $t1, 0x64DC
    ctx->r9 = ADD32(ctx->r9, 0X64DC);
    // 0x80078D0C: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
L_80078D10:
    // 0x80078D10: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078D14: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x80078D18: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80078D1C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80078D20: mflo        $v0
    ctx->r2 = lo;
    // 0x80078D24: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80078D28: beq         $at, $zero, L_80078D9C
    if (ctx->r1 == 0) {
        // 0x80078D2C: nop
    
            goto L_80078D9C;
    }
    // 0x80078D2C: nop

L_80078D30:
    // 0x80078D30: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078D34: nop

    // 0x80078D38: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078D3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078D40: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80078D44: nop

    // 0x80078D48: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80078D4C: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80078D50: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078D54: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x80078D58: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x80078D5C: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x80078D60: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078D64: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80078D68: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80078D6C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80078D70: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078D74: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078D78: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078D7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078D80: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078D84: nop

    // 0x80078D88: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80078D8C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80078D90: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078D94: bne         $at, $zero, L_80078D30
    if (ctx->r1 != 0) {
        // 0x80078D98: nop
    
            goto L_80078D30;
    }
    // 0x80078D98: nop

L_80078D9C:
    // 0x80078D9C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078DA0: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078DA4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80078DA8: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80078DAC: bne         $at, $zero, L_80078D10
    if (ctx->r1 != 0) {
        // 0x80078DB0: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_80078D10;
    }
    // 0x80078DB0: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80078DB4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80078DB8:
    // 0x80078DB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078DBC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80078DC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078DC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078DC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078DCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078DD0: lbu         $t6, 0x64D4($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X64D4);
    // 0x80078DD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078DD8: lbu         $t8, 0x64D5($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X64D5);
    // 0x80078DDC: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078DE0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80078DE4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80078DE8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80078DEC: lbu         $t7, 0x64D6($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X64D6);
    // 0x80078DF0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80078DF4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80078DF8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80078DFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078E00: lbu         $t9, 0x64D7($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X64D7);
    // 0x80078E04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80078E08: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80078E0C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078E10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80078E14: addiu       $t1, $t1, 0x64DC
    ctx->r9 = ADD32(ctx->r9, 0X64DC);
    // 0x80078E18: addiu       $a3, $a3, 0x64D8
    ctx->r7 = ADD32(ctx->r7, 0X64D8);
    // 0x80078E1C: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x80078E20: blez        $t7, L_80078ED4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80078E24: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80078ED4;
    }
    // 0x80078E24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80078E28: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078E2C: nop

L_80078E30:
    // 0x80078E30: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078E34: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x80078E38: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80078E3C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80078E40: mflo        $v0
    ctx->r2 = lo;
    // 0x80078E44: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80078E48: beq         $at, $zero, L_80078EBC
    if (ctx->r1 == 0) {
        // 0x80078E4C: nop
    
            goto L_80078EBC;
    }
    // 0x80078E4C: nop

L_80078E50:
    // 0x80078E50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078E54: nop

    // 0x80078E58: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078E5C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078E60: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80078E64: nop

    // 0x80078E68: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80078E6C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80078E70: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078E74: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80078E78: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80078E7C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80078E80: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80078E84: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078E88: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80078E8C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80078E90: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80078E94: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078E98: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078E9C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078EA0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078EA4: nop

    // 0x80078EA8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80078EAC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80078EB0: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078EB4: bne         $at, $zero, L_80078E50
    if (ctx->r1 != 0) {
        // 0x80078EB8: nop
    
            goto L_80078E50;
    }
    // 0x80078EB8: nop

L_80078EBC:
    // 0x80078EBC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80078EC0: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078EC4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80078EC8: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80078ECC: bne         $at, $zero, L_80078E30
    if (ctx->r1 != 0) {
        // 0x80078ED0: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_80078E30;
    }
    // 0x80078ED0: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
L_80078ED4:
    // 0x80078ED4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078ED8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078EDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078EE0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078EE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078EE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078EF4: jr          $ra
    // 0x80078EF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80078EF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bgdraw_set_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078F00: jr          $ra
    // 0x80078F04: sw          $a0, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r4;
    return;
    // 0x80078F04: sw          $a0, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void texrect_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078F08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80078F0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078F10: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80078F14: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80078F18: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80078F1C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80078F20: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80078F24: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80078F28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80078F2C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80078F30: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80078F34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078F38: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078F3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078F40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078F44: addiu       $t8, $t8, -0x1458
    ctx->r24 = ADD32(ctx->r24, -0X1458);
    // 0x80078F48: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80078F4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078F50: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078F54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078F58: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80078F5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80078F60: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078F64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80078F68: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x80078F6C: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x80078F70: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80078F74: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80078F78: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078F7C: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078F84: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80078F88: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80078F8C: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80078F90: sll         $fp, $a2, 2
    ctx->r30 = S32(ctx->r6 << 2);
    // 0x80078F94: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80078F98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078F9C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80078FA0: sll         $ra, $a3, 2
    ctx->r31 = S32(ctx->r7 << 2);
    // 0x80078FA4: beq         $t0, $zero, L_800790EC
    if (ctx->r8 == 0) {
        // 0x80078FA8: or          $t2, $a1, $zero
        ctx->r10 = ctx->r5 | 0;
            goto L_800790EC;
    }
    // 0x80078FA8: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80078FAC: lui         $s7, 0x400
    ctx->r23 = S32(0X400 << 16);
    // 0x80078FB0: ori         $s7, $s7, 0x400
    ctx->r23 = ctx->r23 | 0X400;
    // 0x80078FB4: lui         $s6, 0xB200
    ctx->r22 = S32(0XB200 << 16);
    // 0x80078FB8: lui         $s5, 0xB300
    ctx->r21 = S32(0XB300 << 16);
    // 0x80078FBC: lui         $s4, 0xE400
    ctx->r20 = S32(0XE400 << 16);
    // 0x80078FC0: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80078FC4: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
L_80078FC8:
    // 0x80078FC8: lh          $t6, 0x4($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X4);
    // 0x80078FCC: lh          $t9, 0x6($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X6);
    // 0x80078FD0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078FD4: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80078FD8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078FDC: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x80078FE0: addu        $a2, $t8, $fp
    ctx->r6 = ADD32(ctx->r24, ctx->r30);
    // 0x80078FE4: addu        $a3, $t7, $ra
    ctx->r7 = ADD32(ctx->r15, ctx->r31);
    // 0x80078FE8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078FEC: addu        $t3, $t8, $a2
    ctx->r11 = ADD32(ctx->r24, ctx->r6);
    // 0x80078FF0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078FF4: blez        $t3, L_800790DC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80078FF8: addu        $t4, $t7, $a3
        ctx->r12 = ADD32(ctx->r15, ctx->r7);
            goto L_800790DC;
    }
    // 0x80078FF8: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x80078FFC: blez        $t4, L_800790DC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80079000: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800790DC;
    }
    // 0x80079000: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80079004: bgez        $a2, L_80079018
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80079008: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80079018;
    }
    // 0x80079008: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007900C: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x80079010: negu        $t5, $t5
    ctx->r13 = SUB32(0, ctx->r13);
    // 0x80079014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80079018:
    // 0x80079018: bgez        $a3, L_8007902C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8007901C: nop
    
            goto L_8007902C;
    }
    // 0x8007901C: nop

    // 0x80079020: sll         $s1, $a3, 3
    ctx->r17 = S32(ctx->r7 << 3);
    // 0x80079024: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x80079028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8007902C:
    // 0x8007902C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079030: nop

    // 0x80079034: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079038: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007903C: lh          $a0, 0xA($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XA);
    // 0x80079040: nop

    // 0x80079044: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80079048: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007904C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80079050: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80079054: or          $t7, $t9, $s2
    ctx->r15 = ctx->r25 | ctx->r18;
    // 0x80079058: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007905C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079060: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80079064: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80079068: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8007906C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80079070: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079074: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80079078: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007907C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079080: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80079084: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x80079088: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007908C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80079090: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80079094: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80079098: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007909C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800790A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800790A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790A8: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800790AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800790B0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800790B4: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x800790B8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800790BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800790C0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800790C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790C8: nop

    // 0x800790CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800790D0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800790D4: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x800790D8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
L_800790DC:
    // 0x800790DC: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x800790E0: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800790E4: bne         $t0, $zero, L_80078FC8
    if (ctx->r8 != 0) {
        // 0x800790E8: nop
    
            goto L_80078FC8;
    }
    // 0x800790E8: nop

L_800790EC:
    // 0x800790EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790F0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800790F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800790F8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800790FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80079100: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079104: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079108: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8007910C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079110: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079114: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80079118: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007911C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80079120: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80079124: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80079128: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007912C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80079130: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80079134: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80079138: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007913C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80079140: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80079144: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80079148: jr          $ra
    // 0x8007914C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007914C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void texrect_draw_scaled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079150: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80079154: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80079158: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007915C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079164: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80079168: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007916C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80079170: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80079174: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80079178: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007917C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80079180: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80079184: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80079188: jal         0x8007A970
    // 0x8007918C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x8007918C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    after_0:
    // 0x80079190: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80079194: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80079198: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x8007919C: bne         $t6, $at, L_800791C4
    if (ctx->r14 != ctx->r1) {
        // 0x800791A0: lw          $t0, 0xCC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XCC);
            goto L_800791C4;
    }
    // 0x800791A0: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800791A4: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800791A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800791AC: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800791B0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800791B4: addiu       $t6, $t6, -0x13D8
    ctx->r14 = ADD32(ctx->r14, -0X13D8);
    // 0x800791B8: b           L_800791D8
    // 0x800791BC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
        goto L_800791D8;
    // 0x800791BC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x800791C0: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
L_800791C4:
    // 0x800791C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800791C8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800791CC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800791D0: addiu       $t6, $t6, -0x1398
    ctx->r14 = ADD32(ctx->r14, -0X1398);
    // 0x800791D4: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
L_800791D8:
    // 0x800791D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800791DC: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800791E0: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x800791E4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800791E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800791EC: addiu       $t9, $t9, -0x1410
    ctx->r25 = ADD32(ctx->r25, -0X1410);
    // 0x800791F0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800791F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800791F8: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800791FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80079200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079204: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80079208: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8007920C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079210: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079214: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x80079218: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007921C: addu        $t8, $a3, $at
    ctx->r24 = ADD32(ctx->r7, ctx->r1);
    // 0x80079220: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80079224: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80079228: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8007922C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80079230: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80079234: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079238: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007923C: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80079240: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80079244: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80079248: lw          $ra, 0x0($s2)
    ctx->r31 = MEM_W(ctx->r18, 0X0);
    // 0x8007924C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80079250: beq         $ra, $zero, L_80079730
    if (ctx->r31 == 0) {
        // 0x80079254: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80079730;
    }
    // 0x80079254: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079258: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8007925C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079260: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80079264: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80079268: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8007926C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80079270: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80079274: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80079278: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8007927C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80079280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079288: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007928C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079290: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079294: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80079298: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8007929C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800792A0: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800792A4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800792A8: andi        $s5, $t0, 0x1000
    ctx->r21 = ctx->r8 & 0X1000;
    // 0x800792AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800792B0: andi        $s6, $t0, 0x2000
    ctx->r22 = ctx->r8 & 0X2000;
    // 0x800792B4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800792B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800792BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800792C0: nop

    // 0x800792C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800792C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800792CC: mfc1        $fp, $f6
    ctx->r30 = (int32_t)ctx->f6.u32l;
    // 0x800792D0: nop

L_800792D4:
    // 0x800792D4: bne         $s5, $zero, L_80079320
    if (ctx->r21 != 0) {
        // 0x800792D8: nop
    
            goto L_80079320;
    }
    // 0x800792D8: nop

    // 0x800792DC: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x800792E0: nop

    // 0x800792E4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800792E8: nop

    // 0x800792EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800792F0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800792F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800792F8: nop

    // 0x800792FC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80079300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079308: nop

    // 0x8007930C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80079310: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80079314: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80079318: b           L_800793A4
    // 0x8007931C: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
        goto L_800793A4;
    // 0x8007931C: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
L_80079320:
    // 0x80079320: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x80079324: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x80079328: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8007932C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80079330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079334: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80079338: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007933C: nop

    // 0x80079340: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80079344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007934C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079350: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079354: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80079358: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007935C: subu        $s2, $s7, $t8
    ctx->r18 = SUB32(ctx->r23, ctx->r24);
    // 0x80079360: bgez        $t9, L_80079374
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80079364: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80079374;
    }
    // 0x80079364: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80079368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007936C: nop

    // 0x80079370: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80079374:
    // 0x80079374: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079378: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007937C: nop

    // 0x80079380: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80079384: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079388: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007938C: nop

    // 0x80079390: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80079394: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80079398: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007939C: subu        $t3, $s2, $t7
    ctx->r11 = SUB32(ctx->r18, ctx->r15);
    // 0x800793A0: nop

L_800793A4:
    // 0x800793A4: bne         $s6, $zero, L_800793F0
    if (ctx->r22 != 0) {
        // 0x800793A8: nop
    
            goto L_800793F0;
    }
    // 0x800793A8: nop

    // 0x800793AC: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x800793B0: nop

    // 0x800793B4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800793B8: nop

    // 0x800793BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800793C0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800793C4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800793C8: nop

    // 0x800793CC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800793D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800793D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800793D8: nop

    // 0x800793DC: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800793E0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800793E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800793E8: b           L_80079474
    // 0x800793EC: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
        goto L_80079474;
    // 0x800793EC: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
L_800793F0:
    // 0x800793F0: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x800793F4: lbu         $t6, 0x1($ra)
    ctx->r14 = MEM_BU(ctx->r31, 0X1);
    // 0x800793F8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800793FC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80079400: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80079404: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80079408: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007940C: nop

    // 0x80079410: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80079414: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079418: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007941C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079420: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80079424: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80079428: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007942C: subu        $s3, $fp, $t9
    ctx->r19 = SUB32(ctx->r30, ctx->r25);
    // 0x80079430: bgez        $t6, L_80079444
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80079434: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80079444;
    }
    // 0x80079434: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007943C: nop

    // 0x80079440: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80079444:
    // 0x80079444: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80079448: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007944C: nop

    // 0x80079450: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80079454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007945C: nop

    // 0x80079460: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079464: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80079468: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007946C: subu        $t2, $s3, $t8
    ctx->r10 = SUB32(ctx->r19, ctx->r24);
    // 0x80079470: nop

L_80079474:
    // 0x80079474: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80079478: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007947C: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80079480: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079484: andi        $t7, $t6, 0xFFFF
        ctx->r15 = ctx->r14 & 0XFFFF;
            goto L_80079718;
    }
    // 0x80079484: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80079488: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007948C: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80079490: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079494: nop
    
            goto L_80079718;
    }
    // 0x80079494: nop

    // 0x80079498: bne         $s5, $zero, L_800794F0
    if (ctx->r21 != 0) {
        // 0x8007949C: nop
    
            goto L_800794F0;
    }
    // 0x8007949C: nop

    // 0x800794A0: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x800794A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800794A8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800794AC: bgez        $t9, L_800794C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800794B0: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800794C0;
    }
    // 0x800794B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800794B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800794B8: nop

    // 0x800794BC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800794C0:
    // 0x800794C0: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800794C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800794C8: nop

    // 0x800794CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800794D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800794D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800794D8: nop

    // 0x800794DC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800794E0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800794E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800794E8: addu        $s2, $t7, $t3
    ctx->r18 = ADD32(ctx->r15, ctx->r11);
    // 0x800794EC: nop

L_800794F0:
    // 0x800794F0: bne         $s6, $zero, L_80079548
    if (ctx->r22 != 0) {
        // 0x800794F4: nop
    
            goto L_80079548;
    }
    // 0x800794F4: nop

    // 0x800794F8: lbu         $t8, 0x1($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X1);
    // 0x800794FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079500: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80079504: bgez        $t8, L_80079518
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80079508: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80079518;
    }
    // 0x80079508: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007950C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079510: nop

    // 0x80079514: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80079518:
    // 0x80079518: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8007951C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80079520: nop

    // 0x80079524: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80079528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007952C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079530: nop

    // 0x80079534: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80079538: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8007953C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80079540: addu        $s3, $t6, $t2
    ctx->r19 = ADD32(ctx->r14, ctx->r10);
    // 0x80079544: nop

L_80079548:
    // 0x80079548: blez        $s2, L_80079718
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007954C: nop
    
            goto L_80079718;
    }
    // 0x8007954C: nop

    // 0x80079550: blez        $s3, L_80079718
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80079554: slt         $at, $t3, $s2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80079718;
    }
    // 0x80079554: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80079558: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x8007955C: slt         $at, $t2, $s3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80079718;
    }
    // 0x8007955C: slt         $at, $t2, $s3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80079560: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079564: nop
    
            goto L_80079718;
    }
    // 0x80079564: nop

    // 0x80079568: lbu         $v1, 0x0($ra)
    ctx->r3 = MEM_BU(ctx->r31, 0X0);
    // 0x8007956C: subu        $t8, $s2, $t3
    ctx->r24 = SUB32(ctx->r18, ctx->r11);
    // 0x80079570: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80079574: sll         $t7, $v1, 12
    ctx->r15 = S32(ctx->r3 << 12);
    // 0x80079578: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007957C: andi        $t9, $s2, 0xFFF
    ctx->r25 = ctx->r18 & 0XFFF;
    // 0x80079580: bne         $t8, $zero, L_8007958C
    if (ctx->r24 != 0) {
        // 0x80079584: nop
    
            goto L_8007958C;
    }
    // 0x80079584: nop

    // 0x80079588: break       7
    do_break(2147980680);
L_8007958C:
    // 0x8007958C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079590: bne         $t8, $at, L_800795A4
    if (ctx->r24 != ctx->r1) {
        // 0x80079594: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800795A4;
    }
    // 0x80079594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079598: bne         $t7, $at, L_800795A4
    if (ctx->r15 != ctx->r1) {
        // 0x8007959C: nop
    
            goto L_800795A4;
    }
    // 0x8007959C: nop

    // 0x800795A0: break       6
    do_break(2147980704);
L_800795A4:
    // 0x800795A4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800795A8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800795AC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800795B0: andi        $t8, $s3, 0xFFF
    ctx->r24 = ctx->r19 & 0XFFF;
    // 0x800795B4: or          $s4, $t7, $t8
    ctx->r20 = ctx->r15 | ctx->r24;
    // 0x800795B8: lbu         $a0, 0x1($ra)
    ctx->r4 = MEM_BU(ctx->r31, 0X1);
    // 0x800795BC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800795C0: subu        $t6, $s3, $t2
    ctx->r14 = SUB32(ctx->r19, ctx->r10);
    // 0x800795C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800795C8: negu        $t7, $t3
    ctx->r15 = SUB32(0, ctx->r11);
    // 0x800795CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800795D0: beq         $s5, $zero, L_800795E4
    if (ctx->r21 == 0) {
        // 0x800795D4: nop
    
            goto L_800795E4;
    }
    // 0x800795D4: nop

    // 0x800795D8: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800795DC: b           L_800795E4
    // 0x800795E0: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
        goto L_800795E4;
    // 0x800795E0: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
L_800795E4:
    // 0x800795E4: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800795E8: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x800795EC: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800795F0: bne         $t6, $zero, L_800795FC
    if (ctx->r14 != 0) {
        // 0x800795F4: nop
    
            goto L_800795FC;
    }
    // 0x800795F4: nop

    // 0x800795F8: break       7
    do_break(2147980792);
L_800795FC:
    // 0x800795FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079600: bne         $t6, $at, L_80079614
    if (ctx->r14 != ctx->r1) {
        // 0x80079604: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079614;
    }
    // 0x80079604: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079608: bne         $t9, $at, L_80079614
    if (ctx->r25 != ctx->r1) {
        // 0x8007960C: nop
    
            goto L_80079614;
    }
    // 0x8007960C: nop

    // 0x80079610: break       6
    do_break(2147980816);
L_80079614:
    // 0x80079614: negu        $t6, $t2
    ctx->r14 = SUB32(0, ctx->r10);
    // 0x80079618: mflo        $a3
    ctx->r7 = lo;
    // 0x8007961C: beq         $s6, $zero, L_80079630
    if (ctx->r22 == 0) {
        // 0x80079620: nop
    
            goto L_80079630;
    }
    // 0x80079620: nop

    // 0x80079624: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80079628: b           L_80079630
    // 0x8007962C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
        goto L_80079630;
    // 0x8007962C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_80079630:
    // 0x80079630: bgez        $t3, L_8007964C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80079634: nop
    
            goto L_8007964C;
    }
    // 0x80079634: nop

    // 0x80079638: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007963C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80079640: mflo        $t8
    ctx->r24 = lo;
    // 0x80079644: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80079648: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
L_8007964C:
    // 0x8007964C: bgez        $t2, L_80079668
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80079650: nop
    
            goto L_80079668;
    }
    // 0x80079650: nop

    // 0x80079654: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079658: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007965C: mflo        $t7
    ctx->r15 = lo;
    // 0x80079660: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x80079664: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
L_80079668:
    // 0x80079668: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007966C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80079670: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80079674: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079678: lh          $a1, 0xA($ra)
    ctx->r5 = MEM_H(ctx->r31, 0XA);
    // 0x8007967C: nop

    // 0x80079680: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80079684: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80079688: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8007968C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80079690: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80079694: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80079698: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007969C: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x800796A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800796A4: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x800796A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800796AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800796B0: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x800796B4: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800796B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800796BC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800796C0: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x800796C4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800796C8: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800796CC: sw          $s4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r20;
    // 0x800796D0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800796D4: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x800796D8: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800796DC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800796E0: andi        $t7, $t0, 0xFFFF
    ctx->r15 = ctx->r8 & 0XFFFF;
    // 0x800796E4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800796E8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800796EC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800796F0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800796F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800796F8: lui         $t6, 0xB200
    ctx->r14 = S32(0XB200 << 16);
    // 0x800796FC: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80079700: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079704: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x80079708: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8007970C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80079710: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80079714: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80079718:
    // 0x80079718: lw          $ra, 0x8($s1)
    ctx->r31 = MEM_W(ctx->r17, 0X8);
    // 0x8007971C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80079720: bne         $ra, $zero, L_800792D4
    if (ctx->r31 != 0) {
        // 0x80079724: nop
    
            goto L_800792D4;
    }
    // 0x80079724: nop

    // 0x80079728: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8007972C: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
L_80079730:
    // 0x80079730: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80079734: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80079738: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007973C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079740: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80079744: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80079748: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007974C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80079750: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80079754: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079758: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8007975C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80079760: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80079764: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80079768: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007976C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80079770: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80079774: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80079778: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007977C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80079780: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079784: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80079788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007978C: jr          $ra
    // 0x80079790: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80079790: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80079794: nop

    // 0x80079798: nop

    // 0x8007979C: nop

;}
RECOMP_FUNC void osCreateScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800797A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800797A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800797A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800797AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800797B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800797B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800797B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800797BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800797C0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800797C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800797C8: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x800797CC: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x800797D0: sw          $zero, 0x260($a0)
    MEM_W(0X260, ctx->r4) = 0;
    // 0x800797D4: sw          $zero, 0x264($a0)
    MEM_W(0X264, ctx->r4) = 0;
    // 0x800797D8: sw          $zero, 0x268($a0)
    MEM_W(0X268, ctx->r4) = 0;
    // 0x800797DC: sw          $zero, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = 0;
    // 0x800797E0: sw          $zero, 0x270($a0)
    MEM_W(0X270, ctx->r4) = 0;
    // 0x800797E4: sw          $zero, 0x280($a0)
    MEM_W(0X280, ctx->r4) = 0;
    // 0x800797E8: sw          $zero, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = 0;
    // 0x800797EC: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800797F0: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
    // 0x800797F4: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x800797F8: jal         0x800D1EF0
    // 0x800797FC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800797FC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80079800: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80079804: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80079808: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007980C: addiu       $t9, $t9, 0x3E90
    ctx->r25 = ADD32(ctx->r25, 0X3E90);
    // 0x80079810: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80079814: jal         0x800D2200
    // 0x80079818: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x80079818: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x8007981C: jal         0x800D2270
    // 0x80079820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x80079820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80079824: addiu       $s1, $s0, 0x40
    ctx->r17 = ADD32(ctx->r16, 0X40);
    // 0x80079828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007982C: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x80079830: jal         0x800C8D80
    // 0x80079834: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80079834: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80079838: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8007983C: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x80079840: jal         0x800C8D80
    // 0x80079844: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80079844: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80079848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8007984C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079850: jal         0x800CD110
    // 0x80079854: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80079854: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_5:
    // 0x80079858: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007985C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079860: jal         0x800CD110
    // 0x80079864: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80079864: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_6:
    // 0x80079868: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007986C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079870: jal         0x800CD110
    // 0x80079874: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80079874: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_7:
    // 0x80079878: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007987C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80079880: jal         0x800D22E0
    // 0x80079884: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    osViSetEvent_recomp(rdram, ctx);
        goto after_8;
    // 0x80079884: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    after_8:
    // 0x80079888: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007988C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80079890: addiu       $s1, $s0, 0xB0
    ctx->r17 = ADD32(ctx->r16, 0XB0);
    // 0x80079894: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80079898: addiu       $a2, $a2, -0x6604
    ctx->r6 = ADD32(ctx->r6, -0X6604);
    // 0x8007989C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800798A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800798A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800798A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800798AC: jal         0x800C8DB0
    // 0x800798B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x800798B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_9:
    // 0x800798B4: jal         0x800C8F00
    // 0x800798B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x800798B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800798BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800798C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800798C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800798C8: jr          $ra
    // 0x800798CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800798CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void osScAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800798D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800798D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800798DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800798E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800798E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800798E8: jal         0x800C9F90
    // 0x800798EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800798EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800798F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800798F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800798F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800798FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80079900: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x80079904: lw          $t7, 0x260($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X260);
    // 0x80079908: nop

    // 0x8007990C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80079910: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80079914: nop

    // 0x80079918: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x8007991C: jal         0x800C9F90
    // 0x80079920: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80079920: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    after_1:
    // 0x80079924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007992C: jr          $ra
    // 0x80079930: nop

    return;
    // 0x80079930: nop

;}
RECOMP_FUNC void osScRemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007993C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079940: lw          $v1, 0x260($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X260);
    // 0x80079944: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80079948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007994C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80079950: jal         0x800C9F90
    // 0x80079954: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80079954: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80079958: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007995C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80079960: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80079964: beq         $v1, $zero, L_800799AC
    if (ctx->r3 == 0) {
        // 0x80079968: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800799AC;
    }
    // 0x80079968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007996C:
    // 0x8007996C: bne         $v1, $a1, L_80079998
    if (ctx->r3 != ctx->r5) {
        // 0x80079970: nop
    
            goto L_80079998;
    }
    // 0x80079970: nop

    // 0x80079974: beq         $a2, $zero, L_80079988
    if (ctx->r6 == 0) {
        // 0x80079978: nop
    
            goto L_80079988;
    }
    // 0x80079978: nop

    // 0x8007997C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80079980: b           L_800799AC
    // 0x80079984: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
        goto L_800799AC;
    // 0x80079984: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80079988:
    // 0x80079988: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8007998C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80079990: b           L_800799AC
    // 0x80079994: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
        goto L_800799AC;
    // 0x80079994: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
L_80079998:
    // 0x80079998: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007999C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800799A0: nop

    // 0x800799A4: bne         $v1, $zero, L_8007996C
    if (ctx->r3 != 0) {
        // 0x800799A8: nop
    
            goto L_8007996C;
    }
    // 0x800799A8: nop

L_800799AC:
    // 0x800799AC: jal         0x800C9F90
    // 0x800799B0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800799B0: nop

    after_1:
    // 0x800799B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800799B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800799BC: jr          $ra
    // 0x800799C0: nop

    return;
    // 0x800799C0: nop

;}
RECOMP_FUNC void osScGetCmdQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799C4: jr          $ra
    // 0x800799C8: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    return;
    // 0x800799C8: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
;}
RECOMP_FUNC void osScGetInterruptQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799CC: jr          $ra
    // 0x800799D0: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    return;
    // 0x800799D0: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
;}
RECOMP_FUNC void scGetAudioTaskTimers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799D8: lwc1        $f4, -0x1340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1340);
    // 0x800799DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799E0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800799E4: lwc1        $f6, -0x1338($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1338);
    // 0x800799E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800799EC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800799F0: lwc1        $f8, -0x1334($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1334);
    // 0x800799F4: jr          $ra
    // 0x800799F8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x800799F8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800799FC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80079A00: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80079A04: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80079A08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80079A0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80079A10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80079A14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80079A18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80079A1C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80079A20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80079A24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80079A28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079A2C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80079A30: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80079A34: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80079A38: addiu       $s3, $a0, 0x40
    ctx->r19 = ADD32(ctx->r4, 0X40);
    // 0x80079A3C: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x80079A40: addiu       $s5, $zero, 0x63
    ctx->r21 = ADD32(0, 0X63);
    // 0x80079A44: addiu       $s6, $zero, 0x29A
    ctx->r22 = ADD32(0, 0X29A);
    // 0x80079A48: addiu       $s7, $zero, 0x29B
    ctx->r23 = ADD32(0, 0X29B);
    // 0x80079A4C: addiu       $fp, $zero, 0x29C
    ctx->r30 = ADD32(0, 0X29C);
    // 0x80079A50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079A54:
    // 0x80079A54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80079A58: jal         0x800C9110
    // 0x80079A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80079A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80079A60: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80079A64: nop

    // 0x80079A68: beq         $t6, $s5, L_80079AC8
    if (ctx->r14 == ctx->r21) {
        // 0x80079A6C: nop
    
            goto L_80079AC8;
    }
    // 0x80079A6C: nop

    // 0x80079A70: beq         $t6, $s6, L_80079A98
    if (ctx->r14 == ctx->r22) {
        // 0x80079A74: nop
    
            goto L_80079A98;
    }
    // 0x80079A74: nop

    // 0x80079A78: beq         $t6, $s7, L_80079AA8
    if (ctx->r14 == ctx->r23) {
        // 0x80079A7C: nop
    
            goto L_80079AA8;
    }
    // 0x80079A7C: nop

    // 0x80079A80: beq         $t6, $fp, L_80079AB8
    if (ctx->r14 == ctx->r30) {
        // 0x80079A84: addiu       $at, $zero, 0x29D
        ctx->r1 = ADD32(0, 0X29D);
            goto L_80079AB8;
    }
    // 0x80079A84: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x80079A88: beq         $t6, $at, L_80079AD8
    if (ctx->r14 == ctx->r1) {
        // 0x80079A8C: nop
    
            goto L_80079AD8;
    }
    // 0x80079A8C: nop

    // 0x80079A90: b           L_80079B14
    // 0x80079A94: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
        goto L_80079B14;
    // 0x80079A94: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
L_80079A98:
    // 0x80079A98: jal         0x80079C68
    // 0x80079A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scHandleRetrace(rdram, ctx);
        goto after_1;
    // 0x80079A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80079AA0: b           L_80079A54
    // 0x80079AA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079AA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079AA8:
    // 0x80079AA8: jal         0x80079F94
    // 0x80079AAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scHandleRSP(rdram, ctx);
        goto after_2;
    // 0x80079AAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80079AB0: b           L_80079A54
    // 0x80079AB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079AB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079AB8:
    // 0x80079AB8: jal         0x8007A1AC
    // 0x80079ABC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scHandleRDP(rdram, ctx);
        goto after_3;
    // 0x80079ABC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80079AC0: b           L_80079A54
    // 0x80079AC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079AC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079AC8:
    // 0x80079AC8: jal         0x80079BB0
    // 0x80079ACC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80079760(rdram, ctx);
        goto after_4;
    // 0x80079ACC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80079AD0: b           L_80079A54
    // 0x80079AD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079AD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079AD8:
    // 0x80079AD8: lw          $s0, 0x260($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X260);
    // 0x80079ADC: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // 0x80079AE0: beq         $s0, $zero, L_80079A54
    if (ctx->r16 == 0) {
        // 0x80079AE4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80079A54;
    }
    // 0x80079AE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079AE8:
    // 0x80079AE8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80079AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079AF0: jal         0x800C9390
    // 0x80079AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80079AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80079AF8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80079AFC: nop

    // 0x80079B00: bne         $s0, $zero, L_80079AE8
    if (ctx->r16 != 0) {
        // 0x80079B04: nop
    
            goto L_80079AE8;
    }
    // 0x80079B04: nop

    // 0x80079B08: b           L_80079A54
    // 0x80079B0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079B0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80079B10: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
L_80079B14:
    // 0x80079B14: jal         0x8007A390
    // 0x80079B18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scAppendList(rdram, ctx);
        goto after_6;
    // 0x80079B18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80079B1C: lw          $t7, 0x274($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X274);
    // 0x80079B20: lw          $t0, 0x278($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X278);
    // 0x80079B24: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80079B28: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80079B2C: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80079B30: or          $s0, $t9, $t1
    ctx->r16 = ctx->r25 | ctx->r9;
    // 0x80079B34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80079B38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80079B3C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80079B40: jal         0x8007A524
    // 0x80079B44: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    static_0_8007A524(rdram, ctx);
        goto after_7;
    // 0x80079B44: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x80079B48: beq         $v0, $s0, L_80079A54
    if (ctx->r2 == ctx->r16) {
        // 0x80079B4C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80079A54;
    }
    // 0x80079B4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80079B50: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80079B54: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80079B58: jal         0x8007A3F8
    // 0x80079B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scExec(rdram, ctx);
        goto after_8;
    // 0x80079B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80079B60: b           L_80079A54
    // 0x80079B64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079A54;
    // 0x80079B64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80079B68: nop

    // 0x80079B6C: nop

    // 0x80079B70: nop

    // 0x80079B74: nop

    // 0x80079B78: nop

    // 0x80079B7C: nop

    // 0x80079B80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80079B84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079B88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80079B8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079B90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80079B94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80079B98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80079B9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80079BA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80079BA4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80079BA8: jr          $ra
    // 0x80079BAC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80079BAC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80079760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079BB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079BB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079BBC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079BC0: lw          $t6, 0x264($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X264);
    // 0x80079BC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80079BC8: beq         $t6, $zero, L_80079BD4
    if (ctx->r14 == 0) {
        // 0x80079BCC: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_80079BD4;
    }
    // 0x80079BCC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80079BD0: sw          $t7, 0x284($a0)
    MEM_W(0X284, ctx->r4) = ctx->r15;
L_80079BD4:
    // 0x80079BD4: lw          $t8, 0x284($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X284);
    // 0x80079BD8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80079BDC: beq         $t8, $zero, L_80079C04
    if (ctx->r24 == 0) {
        // 0x80079BE0: nop
    
            goto L_80079C04;
    }
    // 0x80079BE0: nop

    // 0x80079BE4: lw          $t9, 0x274($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X274);
    // 0x80079BE8: nop

    // 0x80079BEC: beq         $t9, $zero, L_80079C04
    if (ctx->r25 == 0) {
        // 0x80079BF0: nop
    
            goto L_80079C04;
    }
    // 0x80079BF0: nop

    // 0x80079BF4: jal         0x8007A4D0
    // 0x80079BF8: nop

    __scYield(rdram, ctx);
        goto after_0;
    // 0x80079BF8: nop

    after_0:
    // 0x80079BFC: b           L_80079C4C
    // 0x80079C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80079C4C;
    // 0x80079C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079C04:
    // 0x80079C04: lw          $t0, 0x274($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X274);
    // 0x80079C08: lw          $t3, 0x278($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X278);
    // 0x80079C0C: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80079C10: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80079C14: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80079C18: or          $a3, $t2, $t4
    ctx->r7 = ctx->r10 | ctx->r12;
    // 0x80079C1C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80079C20: jal         0x8007A524
    // 0x80079C24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    static_0_8007A524(rdram, ctx);
        goto after_1;
    // 0x80079C24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80079C28: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80079C2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079C30: beq         $v0, $a3, L_80079C4C
    if (ctx->r2 == ctx->r7) {
        // 0x80079C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80079C4C;
    }
    // 0x80079C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079C38: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80079C3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80079C40: jal         0x8007A3F8
    // 0x80079C44: nop

    __scExec(rdram, ctx);
        goto after_2;
    // 0x80079C44: nop

    after_2:
    // 0x80079C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079C4C:
    // 0x80079C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079C50: jr          $ra
    // 0x80079C54: nop

    return;
    // 0x80079C54: nop

;}
RECOMP_FUNC void dummy_80079808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C58: jr          $ra
    // 0x80079C5C: nop

    return;
    // 0x80079C5C: nop

;}
RECOMP_FUNC void dummy_80079810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C60: jr          $ra
    // 0x80079C64: nop

    return;
    // 0x80079C64: nop

;}
RECOMP_FUNC void __scHandleRetrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80079C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079C70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80079C74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80079C78: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80079C7C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80079C80: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80079C84: sb          $zero, 0x32($sp)
    MEM_B(0X32, ctx->r29) = 0;
    // 0x80079C88: lw          $t6, 0x274($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X274);
    // 0x80079C8C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80079C90: beq         $t6, $zero, L_80079CB0
    if (ctx->r14 == 0) {
        // 0x80079C94: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80079CB0;
    }
    // 0x80079C94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80079C98: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80079C9C: addiu       $v1, $v1, -0x132C
    ctx->r3 = ADD32(ctx->r3, -0X132C);
    // 0x80079CA0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80079CA4: nop

    // 0x80079CA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80079CAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80079CB0:
    // 0x80079CB0: lw          $t9, 0x278($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X278);
    // 0x80079CB4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80079CB8: beq         $t9, $zero, L_80079CD4
    if (ctx->r25 == 0) {
        // 0x80079CBC: addiu       $v1, $v1, -0x132C
        ctx->r3 = ADD32(ctx->r3, -0X132C);
            goto L_80079CD4;
    }
    // 0x80079CBC: addiu       $v1, $v1, -0x132C
    ctx->r3 = ADD32(ctx->r3, -0X132C);
    // 0x80079CC0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80079CC4: lw          $t0, -0x1328($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1328);
    // 0x80079CC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079CCC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80079CD0: sw          $t1, -0x1328($at)
    MEM_W(-0X1328, ctx->r1) = ctx->r9;
L_80079CD4:
    // 0x80079CD4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80079CD8: lw          $v0, 0x274($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X274);
    // 0x80079CDC: slti        $at, $t2, 0xB
    ctx->r1 = SIGNED(ctx->r10) < 0XB ? 1 : 0;
    // 0x80079CE0: bne         $at, $zero, L_80079D08
    if (ctx->r1 != 0) {
        // 0x80079CE4: nop
    
            goto L_80079D08;
    }
    // 0x80079CE4: nop

    // 0x80079CE8: beq         $v0, $zero, L_80079D08
    if (ctx->r2 == 0) {
        // 0x80079CEC: lui         $a0, 0xAA
        ctx->r4 = S32(0XAA << 16);
            goto L_80079D08;
    }
    // 0x80079CEC: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x80079CF0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80079CF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80079CF8: jal         0x800CD7A0
    // 0x80079CFC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_0;
    // 0x80079CFC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_0:
    // 0x80079D00: b           L_80079D18
    // 0x80079D04: nop

        goto L_80079D18;
    // 0x80079D04: nop

L_80079D08:
    // 0x80079D08: beq         $v0, $zero, L_80079D18
    if (ctx->r2 == 0) {
        // 0x80079D0C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80079D18;
    }
    // 0x80079D0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80079D10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079D14: sw          $t3, 0x66B0($at)
    MEM_W(0X66B0, ctx->r1) = ctx->r11;
L_80079D18:
    // 0x80079D18: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80079D1C: lw          $t4, -0x1328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1328);
    // 0x80079D20: lw          $v0, 0x278($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X278);
    // 0x80079D24: slti        $at, $t4, 0xB
    ctx->r1 = SIGNED(ctx->r12) < 0XB ? 1 : 0;
    // 0x80079D28: bne         $at, $zero, L_80079D84
    if (ctx->r1 != 0) {
        // 0x80079D2C: nop
    
            goto L_80079D84;
    }
    // 0x80079D2C: nop

    // 0x80079D30: beq         $v0, $zero, L_80079D84
    if (ctx->r2 == 0) {
        // 0x80079D34: nop
    
            goto L_80079D84;
    }
    // 0x80079D34: nop

    // 0x80079D38: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x80079D3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079D40: bne         $t5, $zero, L_80079D54
    if (ctx->r13 != 0) {
        // 0x80079D44: addiu       $a1, $a1, -0x1348
        ctx->r5 = ADD32(ctx->r5, -0X1348);
            goto L_80079D54;
    }
    // 0x80079D44: addiu       $a1, $a1, -0x1348
    ctx->r5 = ADD32(ctx->r5, -0X1348);
    // 0x80079D48: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80079D4C: jal         0x800C9390
    // 0x80079D50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80079D50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80079D54:
    // 0x80079D54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80079D58: sb          $t6, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r14;
    // 0x80079D5C: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
    // 0x80079D60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079D64: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x80079D68: sw          $zero, -0x1328($at)
    MEM_W(-0X1328, ctx->r1) = 0;
    // 0x80079D6C: jal         0x800CD7A0
    // 0x80079D70: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x80079D70: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_2:
    // 0x80079D74: jal         0x800CD7B0
    // 0x80079D78: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_3;
    // 0x80079D78: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_3:
    // 0x80079D7C: b           L_80079D94
    // 0x80079D80: nop

        goto L_80079D94;
    // 0x80079D80: nop

L_80079D84:
    // 0x80079D84: beq         $v0, $zero, L_80079D94
    if (ctx->r2 == 0) {
        // 0x80079D88: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80079D94;
    }
    // 0x80079D88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80079D8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079D90: sw          $t7, 0x66B4($at)
    MEM_W(0X66B4, ctx->r1) = ctx->r15;
L_80079D94:
    // 0x80079D94: beq         $s0, $zero, L_80079DA0
    if (ctx->r16 == 0) {
        // 0x80079D98: addiu       $a0, $s1, 0x78
        ctx->r4 = ADD32(ctx->r17, 0X78);
            goto L_80079DA0;
    }
    // 0x80079D98: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x80079D9C: sw          $zero, 0x274($s1)
    MEM_W(0X274, ctx->r17) = 0;
L_80079DA0:
    // 0x80079DA0: lbu         $t8, 0x32($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X32);
    // 0x80079DA4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80079DA8: beq         $t8, $zero, L_80079DB4
    if (ctx->r24 == 0) {
        // 0x80079DAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80079DB4;
    }
    // 0x80079DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80079DB0: sw          $zero, 0x278($s1)
    MEM_W(0X278, ctx->r17) = 0;
L_80079DB4:
    // 0x80079DB4: jal         0x800C9110
    // 0x80079DB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80079DB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x80079DBC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80079DC0: beq         $v0, $s0, L_80079DEC
    if (ctx->r2 == ctx->r16) {
        // 0x80079DC4: nop
    
            goto L_80079DEC;
    }
    // 0x80079DC4: nop

    // 0x80079DC8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_80079DCC:
    // 0x80079DCC: jal         0x8007A390
    // 0x80079DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __scAppendList(rdram, ctx);
        goto after_5;
    // 0x80079DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80079DD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079DD8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80079DDC: jal         0x800C9110
    // 0x80079DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80079DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80079DE4: bne         $v0, $s0, L_80079DCC
    if (ctx->r2 != ctx->r16) {
        // 0x80079DE8: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80079DCC;
    }
    // 0x80079DE8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_80079DEC:
    // 0x80079DEC: lw          $t9, 0x274($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X274);
    // 0x80079DF0: lw          $t2, 0x278($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X278);
    // 0x80079DF4: sltiu       $t0, $t9, 0x1
    ctx->r8 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80079DF8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80079DFC: sltiu       $t3, $t2, 0x1
    ctx->r11 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80079E00: or          $s0, $t1, $t3
    ctx->r16 = ctx->r9 | ctx->r11;
    // 0x80079E04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80079E08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80079E0C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80079E10: jal         0x8007A524
    // 0x80079E14: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    static_0_8007A524(rdram, ctx);
        goto after_7;
    // 0x80079E14: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80079E18: beq         $v0, $s0, L_80079E30
    if (ctx->r2 == ctx->r16) {
        // 0x80079E1C: nop
    
            goto L_80079E30;
    }
    // 0x80079E1C: nop

    // 0x80079E20: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80079E24: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80079E28: jal         0x8007A3F8
    // 0x80079E2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __scExec(rdram, ctx);
        goto after_8;
    // 0x80079E2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80079E30:
    // 0x80079E30: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80079E34: lw          $t5, -0x131C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X131C);
    // 0x80079E38: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80079E3C: lw          $t4, -0x1320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1320);
    // 0x80079E40: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80079E44: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80079E48: addu        $t6, $t4, $at
    ctx->r14 = ADD32(ctx->r12, ctx->r1);
    // 0x80079E4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079E50: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80079E54: addiu       $v0, $v0, -0x1330
    ctx->r2 = ADD32(ctx->r2, -0X1330);
    // 0x80079E58: sw          $t6, -0x1320($at)
    MEM_W(-0X1320, ctx->r1) = ctx->r14;
    // 0x80079E5C: sw          $t7, -0x131C($at)
    MEM_W(-0X131C, ctx->r1) = ctx->r15;
    // 0x80079E60: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80079E64: nop

    // 0x80079E68: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80079E6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079E70: lw          $t0, 0x280($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X280);
    // 0x80079E74: lw          $v1, 0x27C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X27C);
    // 0x80079E78: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80079E7C: beq         $v1, $zero, L_80079EE4
    if (ctx->r3 == 0) {
        // 0x80079E80: sw          $t2, 0x280($s1)
        MEM_W(0X280, ctx->r17) = ctx->r10;
            goto L_80079EE4;
    }
    // 0x80079E80: sw          $t2, 0x280($s1)
    MEM_W(0X280, ctx->r17) = ctx->r10;
    // 0x80079E84: sltiu       $at, $t2, 0x2
    ctx->r1 = ctx->r10 < 0X2 ? 1 : 0;
    // 0x80079E88: bne         $at, $zero, L_80079EE4
    if (ctx->r1 != 0) {
        // 0x80079E8C: nop
    
            goto L_80079EE4;
    }
    // 0x80079E8C: nop

    // 0x80079E90: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x80079E94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80079E98: beq         $a0, $zero, L_80079EDC
    if (ctx->r4 == 0) {
        // 0x80079E9C: nop
    
            goto L_80079EDC;
    }
    // 0x80079E9C: nop

    // 0x80079EA0: lw          $t3, 0x68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X68);
    // 0x80079EA4: nop

    // 0x80079EA8: bne         $t3, $zero, L_80079EC0
    if (ctx->r11 != 0) {
        // 0x80079EAC: nop
    
            goto L_80079EC0;
    }
    // 0x80079EAC: nop

    // 0x80079EB0: lw          $t4, 0x54($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X54);
    // 0x80079EB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079EB8: beq         $t4, $zero, L_80079ED4
    if (ctx->r12 == 0) {
        // 0x80079EBC: addiu       $a1, $a1, -0x1350
        ctx->r5 = ADD32(ctx->r5, -0X1350);
            goto L_80079ED4;
    }
    // 0x80079EBC: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
L_80079EC0:
    // 0x80079EC0: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    // 0x80079EC4: jal         0x800C9390
    // 0x80079EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80079EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80079ECC: b           L_80079EE0
    // 0x80079ED0: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
        goto L_80079EE0;
    // 0x80079ED0: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
L_80079ED4:
    // 0x80079ED4: jal         0x800C9390
    // 0x80079ED8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80079ED8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
L_80079EDC:
    // 0x80079EDC: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
L_80079EE0:
    // 0x80079EE0: sw          $zero, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = 0;
L_80079EE4:
    // 0x80079EE4: lw          $s0, 0x260($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X260);
    // 0x80079EE8: nop

    // 0x80079EEC: beq         $s0, $zero, L_80079F84
    if (ctx->r16 == 0) {
        // 0x80079EF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80079F84;
    }
    // 0x80079EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079EF4:
    // 0x80079EF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80079EF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079EFC: bne         $v0, $at, L_80079F58
    if (ctx->r2 != ctx->r1) {
        // 0x80079F00: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80079F58;
    }
    // 0x80079F00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80079F04: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079F08: lw          $a1, -0x131C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X131C);
    // 0x80079F0C: lw          $a0, -0x1320($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1320);
    // 0x80079F10: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80079F14: jal         0x800CEFEC
    // 0x80079F18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ull_rem_recomp(rdram, ctx);
        goto after_11;
    // 0x80079F18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_11:
    // 0x80079F1C: bne         $v0, $zero, L_80079F70
    if (ctx->r2 != 0) {
        // 0x80079F20: nop
    
            goto L_80079F70;
    }
    // 0x80079F20: nop

    // 0x80079F24: bne         $v1, $zero, L_80079F70
    if (ctx->r3 != 0) {
        // 0x80079F28: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80079F70;
    }
    // 0x80079F28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079F2C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80079F30: jal         0x800C9390
    // 0x80079F34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80079F34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80079F38: lw          $t5, 0x264($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X264);
    // 0x80079F3C: nop

    // 0x80079F40: beq         $t5, $zero, L_80079F70
    if (ctx->r13 == 0) {
        // 0x80079F44: nop
    
            goto L_80079F70;
    }
    // 0x80079F44: nop

    // 0x80079F48: jal         0x80079BB0
    // 0x80079F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80079760(rdram, ctx);
        goto after_13;
    // 0x80079F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80079F50: b           L_80079F74
    // 0x80079F54: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
        goto L_80079F74;
    // 0x80079F54: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80079F58:
    // 0x80079F58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079F5C: bne         $v0, $at, L_80079F70
    if (ctx->r2 != ctx->r1) {
        // 0x80079F60: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80079F70;
    }
    // 0x80079F60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079F64: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80079F68: jal         0x800C9390
    // 0x80079F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80079F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_80079F70:
    // 0x80079F70: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80079F74:
    // 0x80079F74: nop

    // 0x80079F78: bne         $s0, $zero, L_80079EF4
    if (ctx->r16 != 0) {
        // 0x80079F7C: nop
    
            goto L_80079EF4;
    }
    // 0x80079F7C: nop

    // 0x80079F80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079F84:
    // 0x80079F84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80079F88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80079F8C: jr          $ra
    // 0x80079F90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80079F90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __scHandleRSP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80079F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079FA0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80079FA4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80079FA8: lw          $a1, 0x274($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X274);
    // 0x80079FAC: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x80079FB0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80079FB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079FB8: bne         $t6, $at, L_8007A0A0
    if (ctx->r14 != ctx->r1) {
        // 0x80079FBC: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8007A0A0;
    }
    // 0x80079FBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079FC0: jal         0x800C7E30
    // 0x80079FC4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80079FC4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80079FC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80079FCC: addiu       $v1, $v1, 0x66C4
    ctx->r3 = ADD32(ctx->r3, 0X66C4);
    // 0x80079FD0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80079FD4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80079FD8: lw          $t8, 0x66C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X66C0);
    // 0x80079FDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80079FE0: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80079FE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80079FE8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80079FEC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80079FF0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80079FF4: addiu       $a3, $a3, -0x1340
    ctx->r7 = ADD32(ctx->r7, -0X1340);
    // 0x80079FF8: addiu       $a2, $a2, -0x133C
    ctx->r6 = ADD32(ctx->r6, -0X133C);
    // 0x80079FFC: addiu       $a0, $a0, -0x1334
    ctx->r4 = ADD32(ctx->r4, -0X1334);
    // 0x8007A000: bgez        $t9, L_8007A018
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007A004: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007A018;
    }
    // 0x8007A004: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007A008: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007A00C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007A010: nop

    // 0x8007A014: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007A018:
    // 0x8007A018: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8007A01C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A020: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A024: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007A028: lwc1        $f18, 0x7EFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EFC);
    // 0x8007A02C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8007A030: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8007A034: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007A038: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007A03C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8007A040: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8007A044: nop

    // 0x8007A048: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8007A04C: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8007A050: bc1f        L_8007A05C
    if (!c1cs) {
        // 0x8007A054: swc1        $f6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
            goto L_8007A05C;
    }
    // 0x8007A054: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8007A058: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8007A05C:
    // 0x8007A05C: lw          $v0, -0x1330($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1330);
    // 0x8007A060: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8007A064: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8007A068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A06C: mfhi        $t0
    ctx->r8 = hi;
    // 0x8007A070: beq         $t0, $at, L_8007A07C
    if (ctx->r8 == ctx->r1) {
        // 0x8007A074: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007A07C;
    }
    // 0x8007A074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A078: bne         $t0, $at, L_8007A0A0
    if (ctx->r8 != ctx->r1) {
        // 0x8007A07C: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_8007A0A0;
    }
L_8007A07C:
    // 0x8007A07C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8007A080: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A084: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8007A088: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A08C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007A090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A094: swc1        $f4, -0x1338($at)
    MEM_W(-0X1338, ctx->r1) = ctx->f4.u32l;
    // 0x8007A098: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8007A09C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8007A0A0:
    // 0x8007A0A0: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8007A0A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8007A0A8: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
    // 0x8007A0AC: beq         $t1, $zero, L_8007A148
    if (ctx->r9 == 0) {
        // 0x8007A0B0: and         $t2, $v0, $at
        ctx->r10 = ctx->r2 & ctx->r1;
            goto L_8007A148;
    }
    // 0x8007A0B0: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x8007A0B4: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    // 0x8007A0B8: jal         0x800D2350
    // 0x8007A0BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A0BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8007A0C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8007A0C4: beq         $v0, $zero, L_8007A11C
    if (ctx->r2 == 0) {
        // 0x8007A0C8: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_8007A11C;
    }
    // 0x8007A0C8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8007A0CC: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8007A0D0: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x8007A0D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A0D8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8007A0DC: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8007A0E0: bne         $t5, $at, L_8007A108
    if (ctx->r13 != ctx->r1) {
        // 0x8007A0E4: sw          $t3, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r11;
            goto L_8007A108;
    }
    // 0x8007A0E4: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x8007A0E8: lw          $t6, 0x268($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X268);
    // 0x8007A0EC: nop

    // 0x8007A0F0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007A0F4: lw          $t7, 0x270($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X270);
    // 0x8007A0F8: sw          $a1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r5;
    // 0x8007A0FC: bne         $t7, $zero, L_8007A108
    if (ctx->r15 != 0) {
        // 0x8007A100: nop
    
            goto L_8007A108;
    }
    // 0x8007A100: nop

    // 0x8007A104: sw          $a1, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->r5;
L_8007A108:
    // 0x8007A108: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8007A10C: nop

    // 0x8007A110: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x8007A114: b           L_8007A134
    // 0x8007A118: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8007A134;
    // 0x8007A118: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8007A11C:
    // 0x8007A11C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8007A120: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8007A124: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8007A128: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x8007A12C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8007A130: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8007A134:
    // 0x8007A134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A138: beq         $v0, $at, L_8007A154
    if (ctx->r2 == ctx->r1) {
        // 0x8007A13C: nop
    
            goto L_8007A154;
    }
    // 0x8007A13C: nop

    // 0x8007A140: b           L_8007A158
    // 0x8007A144: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
        goto L_8007A158;
    // 0x8007A144: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_8007A148:
    // 0x8007A148: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8007A14C: jal         0x8007A290
    // 0x8007A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __scTaskComplete(rdram, ctx);
        goto after_2;
    // 0x8007A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8007A154:
    // 0x8007A154: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_8007A158:
    // 0x8007A158: lw          $t6, 0x278($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X278);
    // 0x8007A15C: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8007A160: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8007A164: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007A168: or          $a3, $t5, $t7
    ctx->r7 = ctx->r13 | ctx->r15;
    // 0x8007A16C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8007A170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A174: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8007A178: jal         0x8007A524
    // 0x8007A17C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    static_0_8007A524(rdram, ctx);
        goto after_3;
    // 0x8007A17C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8007A180: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007A184: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8007A188: beq         $v0, $a3, L_8007A1A0
    if (ctx->r2 == ctx->r7) {
        // 0x8007A18C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A1A0;
    }
    // 0x8007A18C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A190: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A194: jal         0x8007A3F8
    // 0x8007A198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __scExec(rdram, ctx);
        goto after_4;
    // 0x8007A198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007A19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A1A0:
    // 0x8007A1A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007A1A4: jr          $ra
    // 0x8007A1A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007A1A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __scHandleRDP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A1AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A1B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007A1B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007A1BC: lw          $a1, 0x278($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X278);
    // 0x8007A1C0: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x8007A1C4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8007A1C8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A1CC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8007A1D0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007A1D4: jal         0x8007A290
    // 0x8007A1D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __scTaskComplete(rdram, ctx);
        goto after_0;
    // 0x8007A1D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007A1DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007A1E0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8007A1E4: lw          $t8, 0x274($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X274);
    // 0x8007A1E8: lw          $t1, 0x278($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X278);
    // 0x8007A1EC: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007A1F0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8007A1F4: sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8007A1F8: or          $a3, $t0, $t2
    ctx->r7 = ctx->r8 | ctx->r10;
    // 0x8007A1FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8007A200: jal         0x8007A524
    // 0x8007A204: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    static_0_8007A524(rdram, ctx);
        goto after_1;
    // 0x8007A204: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8007A208: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8007A20C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007A210: beq         $v0, $a3, L_8007A22C
    if (ctx->r2 == ctx->r7) {
        // 0x8007A214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007A22C;
    }
    // 0x8007A214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A218: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007A21C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A220: jal         0x8007A3F8
    // 0x8007A224: nop

    __scExec(rdram, ctx);
        goto after_2;
    // 0x8007A224: nop

    after_2:
    // 0x8007A228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A22C:
    // 0x8007A22C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A230: jr          $ra
    // 0x8007A234: nop

    return;
    // 0x8007A234: nop

;}
RECOMP_FUNC void __scTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A240: beq         $a0, $zero, L_8007A27C
    if (ctx->r4 == 0) {
        // 0x8007A244: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8007A27C;
    }
    // 0x8007A244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007A248: jal         0x800D23D0
    // 0x8007A24C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A24C: nop

    after_0:
    // 0x8007A250: jal         0x800D2410
    // 0x8007A254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007A258: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A25C: nop

    // 0x8007A260: beq         $v0, $t7, L_8007A274
    if (ctx->r2 == ctx->r15) {
        // 0x8007A264: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_8007A274;
    }
    // 0x8007A264: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8007A268: b           L_8007A280
    // 0x8007A26C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A280;
    // 0x8007A26C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A270: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8007A274:
    // 0x8007A274: b           L_8007A284
    // 0x8007A278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007A284;
    // 0x8007A278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A27C:
    // 0x8007A27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A280:
    // 0x8007A280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A284:
    // 0x8007A284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A288: jr          $ra
    // 0x8007A28C: nop

    return;
    // 0x8007A28C: nop

;}
RECOMP_FUNC void __scTaskComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A29C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8007A2A0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007A2A4: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8007A2A8: bne         $t7, $zero, L_8007A380
    if (ctx->r15 != 0) {
        // 0x8007A2AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007A380;
    }
    // 0x8007A2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A2B0: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x8007A2B4: nop

    // 0x8007A2B8: beq         $a0, $zero, L_8007A378
    if (ctx->r4 == 0) {
        // 0x8007A2BC: nop
    
            goto L_8007A378;
    }
    // 0x8007A2BC: nop

    // 0x8007A2C0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8007A2C4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007A2C8: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8007A2CC: beq         $t9, $zero, L_8007A33C
    if (ctx->r25 == 0) {
        // 0x8007A2D0: nop
    
            goto L_8007A33C;
    }
    // 0x8007A2D0: nop

    // 0x8007A2D4: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x8007A2D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007A2DC: sltiu       $at, $t1, 0x2
    ctx->r1 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x8007A2E0: beq         $at, $zero, L_8007A2F0
    if (ctx->r1 == 0) {
        // 0x8007A2E4: nop
    
            goto L_8007A2F0;
    }
    // 0x8007A2E4: nop

    // 0x8007A2E8: b           L_8007A380
    // 0x8007A2EC: sw          $a1, 0x27C($t0)
    MEM_W(0X27C, ctx->r8) = ctx->r5;
        goto L_8007A380;
    // 0x8007A2EC: sw          $a1, 0x27C($t0)
    MEM_W(0X27C, ctx->r8) = ctx->r5;
L_8007A2F0:
    // 0x8007A2F0: lw          $t2, 0x68($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X68);
    // 0x8007A2F4: nop

    // 0x8007A2F8: bne         $t2, $zero, L_8007A310
    if (ctx->r10 != 0) {
        // 0x8007A2FC: nop
    
            goto L_8007A310;
    }
    // 0x8007A2FC: nop

    // 0x8007A300: lw          $t3, 0x54($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X54);
    // 0x8007A304: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007A308: beq         $t3, $zero, L_8007A324
    if (ctx->r11 == 0) {
        // 0x8007A30C: addiu       $a1, $a1, -0x1350
        ctx->r5 = ADD32(ctx->r5, -0X1350);
            goto L_8007A324;
    }
    // 0x8007A30C: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
L_8007A310:
    // 0x8007A310: lw          $a1, 0x54($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X54);
    // 0x8007A314: jal         0x800C9390
    // 0x8007A318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007A31C: b           L_8007A330
    // 0x8007A320: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
        goto L_8007A330;
    // 0x8007A320: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_8007A324:
    // 0x8007A324: jal         0x800C9390
    // 0x8007A328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007A32C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_8007A330:
    // 0x8007A330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007A334: b           L_8007A380
    // 0x8007A338: sw          $zero, 0x280($t4)
    MEM_W(0X280, ctx->r12) = 0;
        goto L_8007A380;
    // 0x8007A338: sw          $zero, 0x280($t4)
    MEM_W(0X280, ctx->r12) = 0;
L_8007A33C:
    // 0x8007A33C: lw          $t5, 0x68($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X68);
    // 0x8007A340: nop

    // 0x8007A344: bne         $t5, $zero, L_8007A35C
    if (ctx->r13 != 0) {
        // 0x8007A348: nop
    
            goto L_8007A35C;
    }
    // 0x8007A348: nop

    // 0x8007A34C: lw          $t6, 0x54($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X54);
    // 0x8007A350: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007A354: beq         $t6, $zero, L_8007A370
    if (ctx->r14 == 0) {
        // 0x8007A358: addiu       $a1, $a1, -0x1350
        ctx->r5 = ADD32(ctx->r5, -0X1350);
            goto L_8007A370;
    }
    // 0x8007A358: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
L_8007A35C:
    // 0x8007A35C: lw          $a1, 0x54($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X54);
    // 0x8007A360: jal         0x800C9390
    // 0x8007A364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007A368: b           L_8007A380
    // 0x8007A36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007A380;
    // 0x8007A36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007A370:
    // 0x8007A370: jal         0x800C9390
    // 0x8007A374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A374: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_8007A378:
    // 0x8007A378: b           L_8007A380
    // 0x8007A37C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007A380;
    // 0x8007A37C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007A380:
    // 0x8007A380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A388: jr          $ra
    // 0x8007A38C: nop

    return;
    // 0x8007A38C: nop

;}
RECOMP_FUNC void __scAppendList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A390: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8007A394: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A398: bne         $v0, $at, L_8007A3C4
    if (ctx->r2 != ctx->r1) {
        // 0x8007A39C: nop
    
            goto L_8007A3C4;
    }
    // 0x8007A39C: nop

    // 0x8007A3A0: lw          $v0, 0x26C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X26C);
    // 0x8007A3A4: nop

    // 0x8007A3A8: beq         $v0, $zero, L_8007A3B8
    if (ctx->r2 == 0) {
        // 0x8007A3AC: nop
    
            goto L_8007A3B8;
    }
    // 0x8007A3AC: nop

    // 0x8007A3B0: b           L_8007A3BC
    // 0x8007A3B4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_8007A3BC;
    // 0x8007A3B4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_8007A3B8:
    // 0x8007A3B8: sw          $a1, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r5;
L_8007A3BC:
    // 0x8007A3BC: b           L_8007A3E4
    // 0x8007A3C0: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
        goto L_8007A3E4;
    // 0x8007A3C0: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
L_8007A3C4:
    // 0x8007A3C4: lw          $v0, 0x270($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X270);
    // 0x8007A3C8: nop

    // 0x8007A3CC: beq         $v0, $zero, L_8007A3DC
    if (ctx->r2 == 0) {
        // 0x8007A3D0: nop
    
            goto L_8007A3DC;
    }
    // 0x8007A3D0: nop

    // 0x8007A3D4: b           L_8007A3E0
    // 0x8007A3D8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_8007A3E0;
    // 0x8007A3D8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_8007A3DC:
    // 0x8007A3DC: sw          $a1, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r5;
L_8007A3E0:
    // 0x8007A3E0: sw          $a1, 0x270($a0)
    MEM_W(0X270, ctx->r4) = ctx->r5;
L_8007A3E4:
    // 0x8007A3E4: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8007A3E8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8007A3EC: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8007A3F0: jr          $ra
    // 0x8007A3F4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    return;
    // 0x8007A3F4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void __scExec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A3F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A3FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A400: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A404: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007A408: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8007A40C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A410: beq         $a1, $zero, L_8007A488
    if (ctx->r5 == 0) {
        // 0x8007A414: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8007A488;
    }
    // 0x8007A414: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007A418: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x8007A41C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A420: bne         $t6, $at, L_8007A440
    if (ctx->r14 != ctx->r1) {
        // 0x8007A424: nop
    
            goto L_8007A440;
    }
    // 0x8007A424: nop

    // 0x8007A428: jal         0x800D1E00
    // 0x8007A42C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A42C: nop

    after_0:
    // 0x8007A430: jal         0x800C7E30
    // 0x8007A434: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A434: nop

    after_1:
    // 0x8007A438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A43C: sw          $v0, 0x66C0($at)
    MEM_W(0X66C0, ctx->r1) = ctx->r2;
L_8007A440:
    // 0x8007A440: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8007A444: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x8007A448: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8007A44C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8007A450: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8007A454: jal         0x800D256C
    // 0x8007A458: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A458: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8007A45C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8007A460: jal         0x800D26CC
    // 0x8007A464: nop

    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A464: nop

    after_3:
    // 0x8007A468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A46C: sw          $zero, -0x132C($at)
    MEM_W(-0X132C, ctx->r1) = 0;
    // 0x8007A470: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007A474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A478: sw          $zero, -0x1328($at)
    MEM_W(-0X1328, ctx->r1) = 0;
    // 0x8007A47C: bne         $s0, $s1, L_8007A488
    if (ctx->r16 != ctx->r17) {
        // 0x8007A480: sw          $s0, 0x274($t9)
        MEM_W(0X274, ctx->r25) = ctx->r16;
            goto L_8007A488;
    }
    // 0x8007A480: sw          $s0, 0x274($t9)
    MEM_W(0X274, ctx->r25) = ctx->r16;
    // 0x8007A484: sw          $s1, 0x278($t9)
    MEM_W(0X278, ctx->r25) = ctx->r17;
L_8007A488:
    // 0x8007A488: beq         $s1, $zero, L_8007A4C0
    if (ctx->r17 == 0) {
        // 0x8007A48C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A4C0;
    }
    // 0x8007A48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A490: beq         $s1, $s0, L_8007A4C0
    if (ctx->r17 == ctx->r16) {
        // 0x8007A494: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A4C0;
    }
    // 0x8007A494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A498: lw          $t0, 0x3C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X3C);
    // 0x8007A49C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007A4A0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8007A4A4: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x8007A4A8: jal         0x800D1E40
    // 0x8007A4AC: nop

    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x8007A4AC: nop

    after_4:
    // 0x8007A4B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A4B4: nop

    // 0x8007A4B8: sw          $s1, 0x278($t1)
    MEM_W(0X278, ctx->r9) = ctx->r17;
    // 0x8007A4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A4C0:
    // 0x8007A4C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A4C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A4C8: jr          $ra
    // 0x8007A4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007A4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __scYield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A4D8: lw          $v0, 0x274($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X274);
    // 0x8007A4DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A4E0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8007A4E4: nop

    // 0x8007A4E8: bne         $t6, $at, L_8007A518
    if (ctx->r14 != ctx->r1) {
        // 0x8007A4EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007A518;
    }
    // 0x8007A4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A4F0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007A4F4: nop

    // 0x8007A4F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8007A4FC: jal         0x800D2710
    // 0x8007A500: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A500: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x8007A504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A508: sw          $v0, 0x66B8($at)
    MEM_W(0X66B8, ctx->r1) = ctx->r2;
    // 0x8007A50C: jal         0x800D27A0
    // 0x8007A510: sw          $v1, 0x66BC($at)
    MEM_W(0X66BC, ctx->r1) = ctx->r3;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A510: sw          $v1, 0x66BC($at)
    MEM_W(0X66BC, ctx->r1) = ctx->r3;
    after_1:
    // 0x8007A514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A518:
    // 0x8007A518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A51C: jr          $ra
    // 0x8007A520: nop

    return;
    // 0x8007A520: nop

    // 0x8007A524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A52C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007A530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A538: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
L_8007A53C:
    // 0x8007A53C: lw          $t6, 0x284($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X284);
    // 0x8007A540: lw          $s0, 0x268($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X268);
    // 0x8007A544: lw          $v0, 0x264($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X264);
    // 0x8007A548: beq         $t6, $zero, L_8007A5A4
    if (ctx->r14 == 0) {
        // 0x8007A54C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007A5A4;
    }
    // 0x8007A54C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007A550: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8007A554: beq         $t7, $zero, L_8007A5A8
    if (ctx->r15 == 0) {
        // 0x8007A558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007A5A8;
    }
    // 0x8007A558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A55C: beq         $s0, $zero, L_8007A580
    if (ctx->r16 == 0) {
        // 0x8007A560: nop
    
            goto L_8007A580;
    }
    // 0x8007A560: nop

    // 0x8007A564: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8007A568: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A56C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8007A570: beq         $t9, $zero, L_8007A580
    if (ctx->r25 == 0) {
        // 0x8007A574: nop
    
            goto L_8007A580;
    }
    // 0x8007A574: nop

    // 0x8007A578: b           L_8007A6F4
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_8007A6F4;
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_8007A580:
    // 0x8007A580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007A584: lw          $t2, 0x264($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X264);
    // 0x8007A588: sw          $zero, 0x284($s1)
    MEM_W(0X284, ctx->r17) = 0;
    // 0x8007A58C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007A590: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A594: bne         $t3, $zero, L_8007A6F4
    if (ctx->r11 != 0) {
        // 0x8007A598: sw          $t3, 0x264($s1)
        MEM_W(0X264, ctx->r17) = ctx->r11;
            goto L_8007A6F4;
    }
    // 0x8007A598: sw          $t3, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r11;
    // 0x8007A59C: b           L_8007A6F4
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
L_8007A5A4:
    // 0x8007A5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007A5A8:
    // 0x8007A5A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007A5AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A5B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A5B4: jal         0x8007A238
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    __scTaskReady(rdram, ctx);
        goto after_2;
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x8007A5BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007A5C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A5C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8007A5C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007A5CC: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
    // 0x8007A5D0: beq         $v0, $zero, L_8007A6F4
    if (ctx->r2 == 0) {
        // 0x8007A5D4: addiu       $t1, $zero, -0x2
        ctx->r9 = ADD32(0, -0X2);
            goto L_8007A6F4;
    }
    // 0x8007A5D4: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8007A5D8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8007A5DC: nop

    // 0x8007A5E0: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8007A5E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007A5E8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8007A5EC: beq         $at, $zero, L_8007A6F4
    if (ctx->r1 == 0) {
        // 0x8007A5F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007A6F4;
    }
    // 0x8007A5F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A5F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A5F8: addu        $at, $at, $t7
    gpr jr_addend_8007A604 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A5FC: lw          $t7, 0x7F00($at)
    ctx->r15 = ADD32(ctx->r1, 0X7F00);
    // 0x8007A600: nop

    // 0x8007A604: jr          $t7
    // 0x8007A608: nop

    switch (jr_addend_8007A604 >> 2) {
        case 0: goto L_8007A6F4; break;
        case 1: goto L_8007A698; break;
        case 2: goto L_8007A60C; break;
        case 3: goto L_8007A6F4; break;
        case 4: goto L_8007A6F4; break;
        case 5: goto L_8007A698; break;
        case 6: goto L_8007A698; break;
        default: switch_error(__func__, 0x8007A604, 0x800E7F00);
    }
    // 0x8007A608: nop

L_8007A60C:
    // 0x8007A60C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8007A610: andi        $t2, $a3, 0x2
    ctx->r10 = ctx->r7 & 0X2;
    // 0x8007A614: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8007A618: beq         $t9, $zero, L_8007A668
    if (ctx->r25 == 0) {
        // 0x8007A61C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8007A668;
    }
    // 0x8007A61C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A620: beq         $t2, $zero, L_8007A6F4
    if (ctx->r10 == 0) {
        // 0x8007A624: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A624: nop

    // 0x8007A628: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A62C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8007A630: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A634: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8007A638: beq         $t4, $zero, L_8007A648
    if (ctx->r12 == 0) {
        // 0x8007A63C: nop
    
            goto L_8007A648;
    }
    // 0x8007A63C: nop

    // 0x8007A640: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A644: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
L_8007A648:
    // 0x8007A648: lw          $t5, 0x268($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X268);
    // 0x8007A64C: nop

    // 0x8007A650: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007A654: nop

    // 0x8007A658: bne         $t6, $zero, L_8007A6F4
    if (ctx->r14 != 0) {
        // 0x8007A65C: sw          $t6, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r14;
            goto L_8007A6F4;
    }
    // 0x8007A65C: sw          $t6, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r14;
    // 0x8007A660: b           L_8007A6F4
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A668:
    // 0x8007A668: bne         $a3, $at, L_8007A6F4
    if (ctx->r7 != ctx->r1) {
        // 0x8007A66C: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A66C: nop

    // 0x8007A670: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A674: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A678: lw          $t8, 0x268($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X268);
    // 0x8007A67C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007A680: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8007A684: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x8007A688: bne         $t9, $zero, L_8007A6F4
    if (ctx->r25 != 0) {
        // 0x8007A68C: sw          $t9, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r25;
            goto L_8007A6F4;
    }
    // 0x8007A68C: sw          $t9, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r25;
    // 0x8007A690: b           L_8007A6F4
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A698:
    // 0x8007A698: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A69C: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x8007A6A0: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8007A6A4: beq         $t3, $zero, L_8007A6C4
    if (ctx->r11 == 0) {
        // 0x8007A6A8: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6A8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6AC: beq         $t4, $zero, L_8007A6C4
    if (ctx->r12 == 0) {
        // 0x8007A6B0: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6B0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6B4: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A6B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A6BC: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A6C0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
L_8007A6C4:
    // 0x8007A6C4: beq         $t5, $zero, L_8007A6F4
    if (ctx->r13 == 0) {
        // 0x8007A6C8: andi        $t6, $v1, 0x1
        ctx->r14 = ctx->r3 & 0X1;
            goto L_8007A6F4;
    }
    // 0x8007A6C8: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8007A6CC: beq         $t6, $zero, L_8007A6F4
    if (ctx->r14 == 0) {
        // 0x8007A6D0: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A6D0: nop

    // 0x8007A6D4: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A6D8: lw          $t7, 0x268($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X268);
    // 0x8007A6DC: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x8007A6E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007A6E4: nop

    // 0x8007A6E8: bne         $t8, $zero, L_8007A6F4
    if (ctx->r24 != 0) {
        // 0x8007A6EC: sw          $t8, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r24;
            goto L_8007A6F4;
    }
    // 0x8007A6EC: sw          $t8, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r24;
    // 0x8007A6F0: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A6F4:
    // 0x8007A6F4: beq         $v1, $a3, L_8007A708
    if (ctx->r3 == ctx->r7) {
        // 0x8007A6F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A708;
    }
    // 0x8007A6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A6FC: b           L_8007A53C
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8007A53C;
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007A704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A708:
    // 0x8007A708: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A70C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A714: jr          $ra
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007A71C: nop

;}
RECOMP_FUNC void rsp_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A720: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8007A724: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007A728: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8007A72C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8007A730: lui         $at, 0xBC00
    ctx->r1 = S32(0XBC00 << 16);
    // 0x8007A734: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8007A738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A73C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8007A740: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007A744: addu        $t2, $a2, $at
    ctx->r10 = ADD32(ctx->r6, ctx->r1);
    // 0x8007A748: ori         $t1, $t0, 0x6
    ctx->r9 = ctx->r8 | 0X6;
    // 0x8007A74C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007A750: jr          $ra
    // 0x8007A754: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x8007A754: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8007A758: nop

    // 0x8007A75C: nop

;}
RECOMP_FUNC void video_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A760: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A764: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A774: bne         $v0, $zero, L_8007A7AC
    if (ctx->r2 != 0) {
        // 0x8007A778: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8007A7AC;
    }
    // 0x8007A778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007A77C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8007A780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A784: sw          $t6, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r14;
    // 0x8007A788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A78C: lwc1        $f4, -0x7F74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7F74);
    // 0x8007A790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A794: swc1        $f4, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f4.u32l;
    // 0x8007A798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A79C: lwc1        $f6, -0x7F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F70);
    // 0x8007A7A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7A4: b           L_8007A810
    // 0x8007A7A8: swc1        $f6, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f6.u32l;
        goto L_8007A810;
    // 0x8007A7A8: swc1        $f6, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f6.u32l;
L_8007A7AC:
    // 0x8007A7AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A7B0: bne         $v0, $at, L_8007A7E8
    if (ctx->r2 != ctx->r1) {
        // 0x8007A7B4: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_8007A7E8;
    }
    // 0x8007A7B4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8007A7B8: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8007A7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7C0: sw          $t7, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r15;
    // 0x8007A7C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A7C8: lwc1        $f8, -0x7F6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7F6C);
    // 0x8007A7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7D0: swc1        $f8, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f8.u32l;
    // 0x8007A7D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A7D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A7DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7E0: b           L_8007A810
    // 0x8007A7E4: swc1        $f10, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f10.u32l;
        goto L_8007A810;
    // 0x8007A7E4: swc1        $f10, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f10.u32l;
L_8007A7E8:
    // 0x8007A7E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7EC: sw          $t8, 0x6710($at)
    MEM_W(0X6710, ctx->r1) = ctx->r24;
    // 0x8007A7F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A7F4: lwc1        $f16, -0x7F68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7F68);
    // 0x8007A7F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A7FC: swc1        $f16, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = ctx->f16.u32l;
    // 0x8007A800: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A804: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A808: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A80C: swc1        $f18, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->f18.u32l;
L_8007A810:
    // 0x8007A810: bne         $v0, $zero, L_8007A85C
    if (ctx->r2 != 0) {
        // 0x8007A814: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8007A85C;
    }
    // 0x8007A814: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A818: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007A81C: addiu       $v0, $v0, -0x1304
    ctx->r2 = ADD32(ctx->r2, -0X1304);
    // 0x8007A820: addiu       $v1, $v1, -0x12C4
    ctx->r3 = ADD32(ctx->r3, -0X12C4);
L_8007A824:
    // 0x8007A824: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8007A828: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8007A82C: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x8007A830: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007A834: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8007A838: addiu       $t2, $t1, 0x18
    ctx->r10 = ADD32(ctx->r9, 0X18);
    // 0x8007A83C: addiu       $t4, $t3, 0x18
    ctx->r12 = ADD32(ctx->r11, 0X18);
    // 0x8007A840: addiu       $t6, $t5, 0x18
    ctx->r14 = ADD32(ctx->r13, 0X18);
    // 0x8007A844: addiu       $t0, $t9, 0x18
    ctx->r8 = ADD32(ctx->r25, 0X18);
    // 0x8007A848: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8007A84C: sw          $t4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r12;
    // 0x8007A850: sw          $t2, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r10;
    // 0x8007A854: bne         $v0, $v1, L_8007A824
    if (ctx->r2 != ctx->r3) {
        // 0x8007A858: sw          $t0, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->r8;
            goto L_8007A824;
    }
    // 0x8007A858: sw          $t0, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r8;
L_8007A85C:
    // 0x8007A85C: jal         0x8007ADC4
    // 0x8007A860: nop

    video_delta_reset(rdram, ctx);
        goto after_0;
    // 0x8007A860: nop

    after_0:
    // 0x8007A864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007A868: jal         0x8007A910
    // 0x8007A86C: nop

    fb_mode_set(rdram, ctx);
        goto after_1;
    // 0x8007A86C: nop

    after_1:
    // 0x8007A870: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A874: addiu       $v0, $v0, 0x6860
    ctx->r2 = ADD32(ctx->r2, 0X6860);
    // 0x8007A878: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8007A87C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007A880: jal         0x8007AC38
    // 0x8007A884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    fb_alloc(rdram, ctx);
        goto after_2;
    // 0x8007A884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007A888: jal         0x8007AC38
    // 0x8007A88C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    fb_alloc(rdram, ctx);
        goto after_3;
    // 0x8007A88C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8007A890: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A898: jal         0x8007AFEC
    // 0x8007A89C: sw          $t7, 0x6868($at)
    MEM_W(0X6868, ctx->r1) = ctx->r15;
    fb_swap(rdram, ctx);
        goto after_4;
    // 0x8007A89C: sw          $t7, 0x6868($at)
    MEM_W(0X6868, ctx->r1) = ctx->r15;
    after_4:
    // 0x8007A8A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A8A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A8A8: addiu       $a1, $a1, 0x6720
    ctx->r5 = ADD32(ctx->r5, 0X6720);
    // 0x8007A8AC: addiu       $a0, $a0, 0x6740
    ctx->r4 = ADD32(ctx->r4, 0X6740);
    // 0x8007A8B0: jal         0x800C8D80
    // 0x8007A8B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x8007A8B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8007A8B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A8BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A8C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007A8C4: addiu       $a2, $a2, 0x6740
    ctx->r6 = ADD32(ctx->r6, 0X6740);
    // 0x8007A8C8: addiu       $a1, $a1, 0x68B0
    ctx->r5 = ADD32(ctx->r5, 0X68B0);
    // 0x8007A8CC: jal         0x800798D0
    // 0x8007A8D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    osScAddClient(rdram, ctx);
        goto after_6;
    // 0x8007A8D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x8007A8D4: jal         0x8007A9A0
    // 0x8007A8D8: nop

    fb_init_vi(rdram, ctx);
        goto after_7;
    // 0x8007A8D8: nop

    after_7:
    // 0x8007A8DC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8007A8E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A8E4: sw          $t8, 0x6870($at)
    MEM_W(0X6870, ctx->r1) = ctx->r24;
    // 0x8007A8E8: jal         0x800D2270
    // 0x8007A8EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x8007A8EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8007A8F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A8F8: sb          $zero, 0x68A8($at)
    MEM_B(0X68A8, ctx->r1) = 0;
    // 0x8007A8FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A900: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8007A904: sb          $t9, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r25;
    // 0x8007A908: jr          $ra
    // 0x8007A90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fb_mode_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A914: jr          $ra
    // 0x8007A918: sw          $a0, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = ctx->r4;
    return;
    // 0x8007A918: sw          $a0, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void fb_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A91C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A920: lw          $v0, 0x686C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X686C);
    // 0x8007A924: jr          $ra
    // 0x8007A928: nop

    return;
    // 0x8007A928: nop

;}
RECOMP_FUNC void fb_mode_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A92C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A930: lw          $t6, 0x686C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X686C);
    // 0x8007A934: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007A938: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A93C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007A940: addiu       $t9, $t9, -0x1304
    ctx->r25 = ADD32(ctx->r25, -0X1304);
    // 0x8007A944: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8007A948: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8007A94C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8007A950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A954: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A958: sw          $t0, 0x6850($at)
    MEM_W(0X6850, ctx->r1) = ctx->r8;
    // 0x8007A95C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8007A960: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A964: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A968: jr          $ra
    // 0x8007A96C: sw          $t1, 0x6858($at)
    MEM_W(0X6858, ctx->r1) = ctx->r9;
    return;
    // 0x8007A96C: sw          $t1, 0x6858($at)
    MEM_W(0X6858, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void fb_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A970: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007A974: lw          $v1, 0x6868($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6868);
    // 0x8007A978: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007A97C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007A980: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8007A984: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007A988: lw          $t8, 0x6858($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6858);
    // 0x8007A98C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007A990: lw          $t7, 0x6850($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6850);
    // 0x8007A994: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007A998: jr          $ra
    // 0x8007A99C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
    return;
    // 0x8007A99C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
;}
RECOMP_FUNC void fb_init_vi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A9A0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A9A4: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A9B0: bne         $v0, $zero, L_8007A9C4
    if (ctx->r2 != 0) {
        // 0x8007A9B4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007A9C4;
    }
    // 0x8007A9B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007A9B8: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x8007A9BC: b           L_8007A9D4
    // 0x8007A9C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8007A9D4;
    // 0x8007A9C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8007A9C4:
    // 0x8007A9C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007A9C8: bne         $a1, $v0, L_8007A9D4
    if (ctx->r5 != ctx->r2) {
        // 0x8007A9CC: nop
    
            goto L_8007A9D4;
    }
    // 0x8007A9CC: nop

    // 0x8007A9D0: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
L_8007A9D4:
    // 0x8007A9D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A9D8: lw          $t6, 0x686C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X686C);
    // 0x8007A9DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A9E0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A9E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A9E8: addu        $at, $at, $t7
    gpr jr_addend_8007A9F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A9EC: lw          $t7, -0x7F64($at)
    ctx->r15 = ADD32(ctx->r1, -0X7F64);
    // 0x8007A9F0: nop

    // 0x8007A9F4: jr          $t7
    // 0x8007A9F8: nop

    switch (jr_addend_8007A9F4 >> 2) {
        case 0: goto L_8007A9FC; break;
        case 1: goto L_8007AA20; break;
        case 2: goto L_8007AAA8; break;
        case 3: goto L_8007AB10; break;
        case 4: goto L_8007AB78; break;
        case 5: goto L_8007ABA0; break;
        case 6: goto L_8007ABC8; break;
        case 7: goto L_8007ABF0; break;
        default: switch_error(__func__, 0x8007A9F4, 0x800E809C);
    }
    // 0x8007A9F8: nop

L_8007A9FC:
    // 0x8007A9FC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8007AA00: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8007AA04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AA08: addiu       $t9, $t9, 0x3E90
    ctx->r25 = ADD32(ctx->r25, 0X3E90);
    // 0x8007AA0C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007AA10: jal         0x800D2200
    // 0x8007AA14: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AA14: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8007AA18: b           L_8007AC10
    // 0x8007AA1C: nop

        goto L_8007AC10;
    // 0x8007AA1C: nop

L_8007AA20:
    // 0x8007AA20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA24: bne         $v0, $zero, L_8007AA38
    if (ctx->r2 != 0) {
        // 0x8007AA28: addiu       $a0, $a0, 0x4BB0
        ctx->r4 = ADD32(ctx->r4, 0X4BB0);
            goto L_8007AA38;
    }
    // 0x8007AA28: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8007AA2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA30: b           L_8007AA48
    // 0x8007AA34: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
        goto L_8007AA48;
    // 0x8007AA34: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
L_8007AA38:
    // 0x8007AA38: bne         $a1, $v0, L_8007AA48
    if (ctx->r5 != ctx->r2) {
        // 0x8007AA3C: nop
    
            goto L_8007AA48;
    }
    // 0x8007AA3C: nop

    // 0x8007AA40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA44: addiu       $a0, $a0, 0x4C50
    ctx->r4 = ADD32(ctx->r4, 0X4C50);
L_8007AA48:
    // 0x8007AA48: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AA4C: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AA50: jal         0x8007B04C
    // 0x8007AA54: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_1;
    // 0x8007AA54: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x8007AA58: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8007AA5C: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8007AA60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AA64: bne         $t0, $zero, L_8007AA98
    if (ctx->r8 != 0) {
        // 0x8007AA68: addiu       $a1, $a1, 0x6800
        ctx->r5 = ADD32(ctx->r5, 0X6800);
            goto L_8007AA98;
    }
    // 0x8007AA68: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AA6C: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8007AA70: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x8007AA74: lui         $v0, 0x18
    ctx->r2 = S32(0X18 << 16);
    // 0x8007AA78: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x8007AA7C: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8007AA80: sw          $t2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r10;
    // 0x8007AA84: sw          $t4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r12;
    // 0x8007AA88: addiu       $t6, $t2, 0x18
    ctx->r14 = ADD32(ctx->r10, 0X18);
    // 0x8007AA8C: addiu       $t8, $t4, 0x18
    ctx->r24 = ADD32(ctx->r12, 0X18);
    // 0x8007AA90: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x8007AA94: sw          $t8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r24;
L_8007AA98:
    // 0x8007AA98: jal         0x800D2200
    // 0x8007AA9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x8007AA9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8007AAA0: b           L_8007AC10
    // 0x8007AAA4: nop

        goto L_8007AC10;
    // 0x8007AAA4: nop

L_8007AAA8:
    // 0x8007AAA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AAAC: bne         $v0, $zero, L_8007AAC0
    if (ctx->r2 != 0) {
        // 0x8007AAB0: addiu       $a0, $a0, 0x4BB0
        ctx->r4 = ADD32(ctx->r4, 0X4BB0);
            goto L_8007AAC0;
    }
    // 0x8007AAB0: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8007AAB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AAB8: b           L_8007AAD0
    // 0x8007AABC: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
        goto L_8007AAD0;
    // 0x8007AABC: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
L_8007AAC0:
    // 0x8007AAC0: bne         $a1, $v0, L_8007AAD0
    if (ctx->r5 != ctx->r2) {
        // 0x8007AAC4: nop
    
            goto L_8007AAD0;
    }
    // 0x8007AAC4: nop

    // 0x8007AAC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AACC: addiu       $a0, $a0, 0x4C50
    ctx->r4 = ADD32(ctx->r4, 0X4C50);
L_8007AAD0:
    // 0x8007AAD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AAD4: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AAD8: jal         0x8007B04C
    // 0x8007AADC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_3;
    // 0x8007AADC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_3:
    // 0x8007AAE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AAE4: addiu       $a0, $a1, 0x6800
    ctx->r4 = ADD32(ctx->r5, 0X6800);
    // 0x8007AAE8: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007AAEC: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x8007AAF0: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8007AAF4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007AAF8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8007AAFC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007AB00: jal         0x800D2200
    // 0x8007AB04: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AB04: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_4:
    // 0x8007AB08: b           L_8007AC10
    // 0x8007AB0C: nop

        goto L_8007AC10;
    // 0x8007AB0C: nop

L_8007AB10:
    // 0x8007AB10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB14: bne         $v0, $zero, L_8007AB28
    if (ctx->r2 != 0) {
        // 0x8007AB18: addiu       $a0, $a0, 0x4CA0
        ctx->r4 = ADD32(ctx->r4, 0X4CA0);
            goto L_8007AB28;
    }
    // 0x8007AB18: addiu       $a0, $a0, 0x4CA0
    ctx->r4 = ADD32(ctx->r4, 0X4CA0);
    // 0x8007AB1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB20: b           L_8007AB38
    // 0x8007AB24: addiu       $a0, $a0, 0x4CF0
    ctx->r4 = ADD32(ctx->r4, 0X4CF0);
        goto L_8007AB38;
    // 0x8007AB24: addiu       $a0, $a0, 0x4CF0
    ctx->r4 = ADD32(ctx->r4, 0X4CF0);
L_8007AB28:
    // 0x8007AB28: bne         $a1, $v0, L_8007AB38
    if (ctx->r5 != ctx->r2) {
        // 0x8007AB2C: nop
    
            goto L_8007AB38;
    }
    // 0x8007AB2C: nop

    // 0x8007AB30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB34: addiu       $a0, $a0, 0x4D40
    ctx->r4 = ADD32(ctx->r4, 0X4D40);
L_8007AB38:
    // 0x8007AB38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AB3C: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AB40: jal         0x8007B04C
    // 0x8007AB44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_5;
    // 0x8007AB44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x8007AB48: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AB4C: addiu       $a0, $a1, 0x6800
    ctx->r4 = ADD32(ctx->r5, 0X6800);
    // 0x8007AB50: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007AB54: addiu       $t1, $zero, 0x280
    ctx->r9 = ADD32(0, 0X280);
    // 0x8007AB58: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8007AB5C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8007AB60: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8007AB64: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007AB68: jal         0x800D2200
    // 0x8007AB6C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_6;
    // 0x8007AB6C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_6:
    // 0x8007AB70: b           L_8007AC10
    // 0x8007AB74: nop

        goto L_8007AC10;
    // 0x8007AB74: nop

L_8007AB78:
    // 0x8007AB78: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8007AB7C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8007AB80: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8007AB84: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007AB88: addiu       $t5, $t5, 0x3E90
    ctx->r13 = ADD32(ctx->r13, 0X3E90);
    // 0x8007AB8C: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x8007AB90: jal         0x800D2200
    // 0x8007AB94: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x8007AB94: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x8007AB98: b           L_8007AC10
    // 0x8007AB9C: nop

        goto L_8007AC10;
    // 0x8007AB9C: nop

L_8007ABA0:
    // 0x8007ABA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007ABA4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8007ABA8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8007ABAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007ABB0: addiu       $t8, $t8, 0x3E90
    ctx->r24 = ADD32(ctx->r24, 0X3E90);
    // 0x8007ABB4: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8007ABB8: jal         0x800D2200
    // 0x8007ABBC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osViSetMode_recomp(rdram, ctx);
        goto after_8;
    // 0x8007ABBC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x8007ABC0: b           L_8007AC10
    // 0x8007ABC4: nop

        goto L_8007AC10;
    // 0x8007ABC4: nop

L_8007ABC8:
    // 0x8007ABC8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8007ABCC: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8007ABD0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8007ABD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007ABD8: addiu       $t1, $t1, 0x3E90
    ctx->r9 = ADD32(ctx->r9, 0X3E90);
    // 0x8007ABDC: addiu       $t0, $t9, 0x2D0
    ctx->r8 = ADD32(ctx->r25, 0X2D0);
    // 0x8007ABE0: jal         0x800D2200
    // 0x8007ABE4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osViSetMode_recomp(rdram, ctx);
        goto after_9;
    // 0x8007ABE4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_9:
    // 0x8007ABE8: b           L_8007AC10
    // 0x8007ABEC: nop

        goto L_8007AC10;
    // 0x8007ABEC: nop

L_8007ABF0:
    // 0x8007ABF0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8007ABF4: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8007ABF8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8007ABFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007AC00: addiu       $t4, $t4, 0x3E90
    ctx->r12 = ADD32(ctx->r12, 0X3E90);
    // 0x8007AC04: addiu       $t3, $t2, 0x370
    ctx->r11 = ADD32(ctx->r10, 0X370);
    // 0x8007AC08: jal         0x800D2200
    // 0x8007AC0C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    osViSetMode_recomp(rdram, ctx);
        goto after_10;
    // 0x8007AC0C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_10:
L_8007AC10:
    // 0x8007AC10: jal         0x800D27C0
    // 0x8007AC14: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_11;
    // 0x8007AC14: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8007AC18: jal         0x800D27C0
    // 0x8007AC1C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_12;
    // 0x8007AC1C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x8007AC20: jal         0x800D27C0
    // 0x8007AC24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_13;
    // 0x8007AC24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x8007AC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007AC30: jr          $ra
    // 0x8007AC34: nop

    return;
    // 0x8007AC34: nop

;}
