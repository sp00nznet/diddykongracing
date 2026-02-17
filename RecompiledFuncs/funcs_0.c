#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80000404: lui         $t1, 0x4
    ctx->r9 = S32(0X4 << 16);
    // 0x80000408: addiu       $t0, $t0, -0x3B20
    ctx->r8 = ADD32(ctx->r8, -0X3B20);
    // 0x8000040C: ori         $t1, $t1, 0x14D0
    ctx->r9 = ctx->r9 | 0X14D0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80000428: lui         $sp, 0x8012
    ctx->r29 = S32(0X8012 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x5F80
    ctx->r10 = ADD32(ctx->r10, 0X5F80);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, 0x1040
    ctx->r29 = ADD32(ctx->r29, 0X1040);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, 0x1040
    ctx->r29 = ADD32(ctx->r29, 0X1040);
    // 0x80000438: nop

    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

;}
RECOMP_FUNC void audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80000454: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80000458: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000045C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80000460: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80000464: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80000468: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x8000046C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80000470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000474: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000478: ori         $a2, $a2, 0x9D88
    ctx->r6 = ctx->r6 | 0X9D88;
    // 0x8000047C: addiu       $a1, $a1, -0x3B20
    ctx->r5 = ADD32(ctx->r5, -0X3B20);
    // 0x80000480: jal         0x800C7AC0
    // 0x80000484: addiu       $a0, $a0, 0x6268
    ctx->r4 = ADD32(ctx->r4, 0X6268);
    alHeapInit(rdram, ctx);
        goto after_0;
    // 0x80000484: addiu       $a0, $a0, 0x6268
    ctx->r4 = ADD32(ctx->r4, 0X6268);
    after_0:
    // 0x80000488: jal         0x80076EE4
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80000490: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80000494: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80000498: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8000049C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800004A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800004A4: jal         0x80070EDC
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    after_2:
    // 0x800004AC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004B0: addiu       $s0, $s0, 0x6294
    ctx->r16 = ADD32(ctx->r16, 0X6294);
    // 0x800004B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800004B8: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800004BC: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800004C0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800004C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800004C8: jal         0x80077190
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    after_3:
    // 0x800004D0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800004D4: jal         0x80077240
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_4;
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800004DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800004E0: jal         0x800C7C04
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_5;
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800004E8: lw          $t9, 0x1C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1C);
    // 0x800004EC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x800004F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004F4: addiu       $s0, $s0, 0x62A8
    ctx->r16 = ADD32(ctx->r16, 0X62A8);
    // 0x800004F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800004FC: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    // 0x80000500: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80000504: jal         0x80070EDC
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_6:
    // 0x8000050C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000510: addiu       $v1, $v1, 0x6298
    ctx->r3 = ADD32(ctx->r3, 0X6298);
    // 0x80000514: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000518: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8000051C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000520: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000524: jal         0x80077190
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8000052C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80000530: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80000534: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80000538: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000053C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000540: addiu       $v1, $v1, 0x62AC
    ctx->r3 = ADD32(ctx->r3, 0X62AC);
    // 0x80000544: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000548: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000054C: mflo        $t4
    ctx->r12 = lo;
    // 0x80000550: sw          $t4, 0x62A0($at)
    MEM_W(0X62A0, ctx->r1) = ctx->r12;
    // 0x80000554: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x80000558: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8000055C: nop

    // 0x80000560: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80000564: jal         0x80070EDC
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_8:
    // 0x8000056C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000570: addiu       $v1, $v1, 0x629C
    ctx->r3 = ADD32(ctx->r3, 0X629C);
    // 0x80000574: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80000578: addiu       $s0, $s0, 0x62AC
    ctx->r16 = ADD32(ctx->r16, 0X62AC);
    // 0x8000057C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000580: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x80000584: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000588: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000058C: jal         0x80077190
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_9;
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80000594: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80000598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000059C: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800005A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800005A4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800005A8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800005AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800005B0: sw          $t9, 0x62A4($at)
    MEM_W(0X62A4, ctx->r1) = ctx->r25;
    // 0x800005B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800005B8: jal         0x80070EDC
    // 0x800005BC: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x800005BC: nop

    after_10:
    // 0x800005C0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800005C4: addiu       $s0, $s0, 0x6290
    ctx->r16 = ADD32(ctx->r16, 0X6290);
    // 0x800005C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800005CC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800005D0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800005D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800005D8: jal         0x80077190
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_11;
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800005E0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800005E4: jal         0x80077240
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_12;
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_12:
    // 0x800005EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800005F0: jal         0x800C7C04
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_13;
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x800005F8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800005FC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80000600: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80000604: addiu       $a2, $a2, 0x6268
    ctx->r6 = ADD32(ctx->r6, 0X6268);
    // 0x80000608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000060C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000610: jal         0x800C7D50
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_14;
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80000618: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000061C: addiu       $s0, $s0, 0x6278
    ctx->r16 = ADD32(ctx->r16, 0X6278);
    // 0x80000620: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80000624: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000628: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000062C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80000630: jal         0x80077190
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    asset_load(rdram, ctx);
        goto after_15;
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_15:
    // 0x80000638: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000063C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000640: lh          $a3, 0x2($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X2);
    // 0x80000644: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000648: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8000064C: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    // 0x80000650: jal         0x80070EDC
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_16:
    // 0x80000658: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000065C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80000660: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000664: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000668: jal         0x80077190
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_17;
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80000670: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x80000674: jal         0x80077240
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_18;
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_18:
    // 0x8000067C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000680: jal         0x800C7D08
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alSeqFileNew(rdram, ctx);
        goto after_19;
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x80000688: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000068C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000690: lh          $a0, 0x2($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2);
    // 0x80000694: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000698: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8000069C: jal         0x80070EDC
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_20;
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_20:
    // 0x800006A4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800006A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800006AC: addiu       $t0, $t0, 0x628C
    ctx->r8 = ADD32(ctx->r8, 0X628C);
    // 0x800006B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800006B4: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800006B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800006BC: blez        $t6, L_80000744
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800006C0: addiu       $t5, $zero, 0x28
        ctx->r13 = ADD32(0, 0X28);
            goto L_80000744;
    }
    // 0x800006C0: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x800006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800006C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800006CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800006D0:
    // 0x800006D0: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x800006D4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800006D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800006DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800006E0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800006E4: nop

    // 0x800006E8: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800006EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800006F0: nop

    // 0x800006F4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800006F8: beq         $t1, $zero, L_80000718
    if (ctx->r9 == 0) {
        // 0x800006FC: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80000718;
    }
    // 0x800006FC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80000700: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80000704: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80000708: nop

    // 0x8000070C: addu        $v1, $t3, $a1
    ctx->r3 = ADD32(ctx->r11, ctx->r5);
    // 0x80000710: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80000714: nop

L_80000718:
    // 0x80000718: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8000071C: beq         $at, $zero, L_80000728
    if (ctx->r1 == 0) {
        // 0x80000720: nop
    
            goto L_80000728;
    }
    // 0x80000720: nop

    // 0x80000724: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80000728:
    // 0x80000728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000072C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000730: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80000734: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000738: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000073C: bne         $at, $zero, L_800006D0
    if (ctx->r1 != 0) {
        // 0x80000740: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800006D0;
    }
    // 0x80000740: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80000744:
    // 0x80000744: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80000748: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8000074C: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x80000750: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80000754: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80000758: addiu       $t1, $t1, 0x6268
    ctx->r9 = ADD32(ctx->r9, 0X6268);
    // 0x8000075C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80000760: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80000764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80000768: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8000076C: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80000770: sb          $t8, 0x8C($sp)
    MEM_B(0X8C, ctx->r29) = ctx->r24;
    // 0x80000774: sb          $t9, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = ctx->r25;
    // 0x80000778: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8000077C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x80000780: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80000784: jal         0x80002660
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    amCreateAudioMgr(rdram, ctx);
        goto after_21;
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_21:
    // 0x8000078C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80000790: jal         0x80002224
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    sound_seqplayer_init(rdram, ctx);
        goto after_22;
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_22:
    // 0x80000798: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000079C: addiu       $v1, $v1, -0x3460
    ctx->r3 = ADD32(ctx->r3, -0X3460);
    // 0x800007A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800007A8: jal         0x8000B010
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    set_voice_limit(rdram, ctx);
        goto after_23;
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_23:
    // 0x800007B0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800007B4: jal         0x80002224
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    sound_seqplayer_init(rdram, ctx);
        goto after_24;
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_24:
    // 0x800007BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800007C0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007C4: sw          $v0, -0x345C($at)
    MEM_W(-0X345C, ctx->r1) = ctx->r2;
    // 0x800007C8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007CC: jal         0x80070EDC
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_25;
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800007D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007D8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007DC: sw          $v0, 0x627C($at)
    MEM_W(0X627C, ctx->r1) = ctx->r2;
    // 0x800007E0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007E4: jal         0x80070EDC
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_26;
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800007EC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800007F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007F4: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x800007F8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800007FC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80000800: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80000804: addiu       $t6, $t6, 0x6268
    ctx->r14 = ADD32(ctx->r14, 0X6268);
    // 0x80000808: sw          $v0, 0x6280($at)
    MEM_W(0X6280, ctx->r1) = ctx->r2;
    // 0x8000080C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80000810: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80000814: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80000818: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x8000081C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x80000820: jal         0x800031C0
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sndp_init_player(rdram, ctx);
        goto after_27;
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_27:
    // 0x80000828: jal         0x80002A50
    // 0x8000082C: nop

    audioStartThread(rdram, ctx);
        goto after_28;
    // 0x8000082C: nop

    after_28:
    // 0x80000830: jal         0x80000968
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_29;
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x80000838: jal         0x80071380
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_30;
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x80000840: jal         0x8000318C
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_31;
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_31:
    // 0x80000848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000084C: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
    // 0x80000850: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000854: sb          $zero, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = 0;
    // 0x80000858: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000085C: sb          $zero, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = 0;
    // 0x80000860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000864: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
    // 0x80000868: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000086C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000870: sb          $zero, 0x64F8($at)
    MEM_B(0X64F8, ctx->r1) = 0;
    // 0x80000874: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000878: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000087C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80000880: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80000884: sb          $zero, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = 0;
    // 0x80000888: jr          $ra
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void sound_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000890: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80000894: lbu         $t7, 0x64F9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X64F9);
    // 0x80000898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000089C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800008A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800008A4: bne         $t7, $zero, L_80000958
    if (ctx->r15 != 0) {
        // 0x800008A8: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000958;
    }
    // 0x800008A8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800008AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800008B0: addiu       $v0, $v0, 0x64F8
    ctx->r2 = ADD32(ctx->r2, 0X64F8);
    // 0x800008B4: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800008B8: bne         $t8, $zero, L_80000958
    if (ctx->r24 != 0) {
        // 0x800008BC: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_80000958;
    }
    // 0x800008BC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800008C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800008C4: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800008C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800008CC: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x800008D0: jal         0x80001990
    // 0x800008D4: sw          $t9, -0x3424($at)
    MEM_W(-0X3424, ctx->r1) = ctx->r25;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x800008D4: sw          $t9, -0x3424($at)
    MEM_W(-0X3424, ctx->r1) = ctx->r25;
    after_0:
    // 0x800008D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008DC: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x800008E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800008E4: sll         $t0, $a1, 7
    ctx->r8 = S32(ctx->r5 << 7);
    // 0x800008E8: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800008EC: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x800008F0: jal         0x80004A60
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_1:
    // 0x800008F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008FC: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000904: sll         $t2, $a1, 7
    ctx->r10 = S32(ctx->r5 << 7);
    // 0x80000908: addiu       $a1, $t2, -0x1
    ctx->r5 = ADD32(ctx->r10, -0X1);
    // 0x8000090C: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x80000910: jal         0x80004A60
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x80000918: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000091C: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000920: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000924: sll         $t4, $a1, 7
    ctx->r12 = S32(ctx->r5 << 7);
    // 0x80000928: addiu       $a1, $t4, -0x1
    ctx->r5 = ADD32(ctx->r12, -0X1);
    // 0x8000092C: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x80000930: jal         0x80004A60
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_3:
    // 0x80000938: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000093C: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000940: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000944: sll         $t6, $a1, 7
    ctx->r14 = S32(ctx->r5 << 7);
    // 0x80000948: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8000094C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80000950: jal         0x80004A60
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_4;
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_4:
L_80000958:
    // 0x80000958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000960: jr          $ra
    // 0x80000964: nop

    return;
    // 0x80000964: nop

;}
RECOMP_FUNC void sound_volume_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000096C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000974: beq         $a0, $at, L_8000099C
    if (ctx->r4 == ctx->r1) {
        // 0x80000978: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000099C;
    }
    // 0x80000978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000980: beq         $a0, $at, L_80000A14
    if (ctx->r4 == ctx->r1) {
        // 0x80000984: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A14;
    }
    // 0x80000984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000098C: beq         $a0, $at, L_80000A48
    if (ctx->r4 == ctx->r1) {
        // 0x80000990: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A48;
    }
    // 0x80000990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000994: b           L_80000A7C
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80000A7C;
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000099C:
    // 0x8000099C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800009A0: jal         0x80004A60
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800009A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800009AC: jal         0x80004A60
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x800009B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800009B8: jal         0x80004A60
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800009C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800009C4: jal         0x80004A60
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800009CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800009D0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800009D4: lw          $t8, -0x343C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X343C);
    // 0x800009D8: lbu         $t7, -0x3458($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3458);
    // 0x800009DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800009E0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800009E4: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800009E8: mflo        $a1
    ctx->r5 = lo;
    // 0x800009EC: sra         $t9, $a1, 2
    ctx->r25 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800009F0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800009F4: jal         0x800C7DB0
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_4;
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x800009FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000A00: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000A04: jal         0x800C7DB0
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alCSPSetVol(rdram, ctx);
        goto after_5;
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80000A0C: b           L_80000B04
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A14:
    // 0x80000A14: jal         0x80004A60
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_6;
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80000A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A20: jal         0x80004A60
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_7;
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_7:
    // 0x80000A28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A2C: jal         0x80004A60
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_8;
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_8:
    // 0x80000A34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A38: jal         0x80004A60
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_9;
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_9:
    // 0x80000A40: b           L_80000B04
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A48:
    // 0x80000A48: jal         0x80004A60
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_10;
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80000A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A54: jal         0x80004A60
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_11;
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_11:
    // 0x80000A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A60: jal         0x80004A60
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_12;
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80000A68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A6C: jal         0x80004A60
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_13;
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80000A74: b           L_80000B04
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A7C:
    // 0x80000A7C: jal         0x80004A60
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x80000A84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A88: jal         0x80004A60
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x80000A90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A94: jal         0x80004A60
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_16;
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_16:
    // 0x80000A9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000AA0: jal         0x80004A60
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_17;
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_17:
    // 0x80000AA8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80000AAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80000AB0: lw          $t3, -0x343C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X343C);
    // 0x80000AB4: lbu         $t2, -0x3458($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3458);
    // 0x80000AB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000ABC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AC0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000AC4: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AC8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80000ACC: jal         0x800C7DB0
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_18;
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_18:
    // 0x80000AD4: jal         0x8000317C
    // 0x80000AD8: nop

    sndp_get_global_volume(rdram, ctx);
        goto after_19;
    // 0x80000AD8: nop

    after_19:
    // 0x80000ADC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000AE0: lbu         $t6, -0x3454($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3454);
    // 0x80000AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000AE8: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AEC: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000AF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AF4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80000AF8: jal         0x800C7DB0
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_20;
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_20:
    // 0x80000B00: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000B04:
    // 0x80000B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000B08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000B10: jr          $ra
    // 0x80000B14: sb          $t9, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = ctx->r25;
    return;
    // 0x80000B14: sb          $t9, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void music_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B20: jr          $ra
    // 0x80000B24: sw          $t6, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r14;
    return;
    // 0x80000B24: sw          $t6, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void music_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B2C: jr          $ra
    // 0x80000B30: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
    return;
    // 0x80000B30: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
;}
RECOMP_FUNC void music_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80000B38: lw          $t7, -0x3448($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3448);
    // 0x80000B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000B48: bne         $t7, $zero, L_80000BD0
    if (ctx->r15 != 0) {
        // 0x80000B4C: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000BD0;
    }
    // 0x80000B4C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80000B50: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80000B54: lw          $t8, -0x343C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X343C);
    // 0x80000B58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000B5C: beq         $t8, $zero, L_80000BD0
    if (ctx->r24 == 0) {
        // 0x80000B60: addiu       $v0, $v0, 0x6284
        ctx->r2 = ADD32(ctx->r2, 0X6284);
            goto L_80000BD0;
    }
    // 0x80000B60: addiu       $v0, $v0, 0x6284
    ctx->r2 = ADD32(ctx->r2, 0X6284);
    // 0x80000B64: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80000B68: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80000B6C: lbu         $t0, -0x3450($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X3450);
    // 0x80000B70: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x80000B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B78: beq         $t0, $zero, L_80000B94
    if (ctx->r8 == 0) {
        // 0x80000B7C: sb          $t9, -0x3458($at)
        MEM_B(-0X3458, ctx->r1) = ctx->r25;
            goto L_80000B94;
    }
    // 0x80000B7C: sb          $t9, -0x3458($at)
    MEM_B(-0X3458, ctx->r1) = ctx->r25;
    // 0x80000B80: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80000B84: lw          $a1, -0x3460($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3460);
    // 0x80000B88: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80000B8C: jal         0x800022BC
    // 0x80000B90: nop

    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80000B90: nop

    after_0:
L_80000B94:
    // 0x80000B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000B98: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000B9C: jal         0x800C7DF0
    // 0x80000BA0: nop

    alCSPGetTempo(rdram, ctx);
        goto after_1;
    // 0x80000BA0: nop

    after_1:
    // 0x80000BA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BA8: jal         0x800C7E30
    // 0x80000BAC: sw          $v0, 0x6288($at)
    MEM_W(0X6288, ctx->r1) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x80000BAC: sw          $v0, 0x6288($at)
    MEM_W(0X6288, ctx->r1) = ctx->r2;
    after_2:
    // 0x80000BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000BB4: sw          $v0, -0x3444($at)
    MEM_W(-0X3444, ctx->r1) = ctx->r2;
    // 0x80000BB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80000BC0: sb          $t1, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = ctx->r9;
    // 0x80000BC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BC8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80000BCC: sw          $t2, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r10;
L_80000BD0:
    // 0x80000BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000BD8: jr          $ra
    // 0x80000BDC: nop

    return;
    // 0x80000BDC: nop

;}
RECOMP_FUNC void music_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BE0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000BE4: lbu         $t6, -0x3420($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3420);
    // 0x80000BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000BF4: bne         $t6, $zero, L_80000C0C
    if (ctx->r14 != 0) {
        // 0x80000BF8: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_80000C0C;
    }
    // 0x80000BF8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C00: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000C04: jal         0x8000B010
    // 0x80000C08: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C08: nop

    after_0:
L_80000C0C:
    // 0x80000C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C14: jr          $ra
    // 0x80000C18: nop

    return;
    // 0x80000C18: nop

;}
RECOMP_FUNC void music_voicelimit_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000C20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C24: jr          $ra
    // 0x80000C28: sb          $t6, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = ctx->r14;
    return;
    // 0x80000C28: sb          $t6, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void music_voicelimit_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C30: jr          $ra
    // 0x80000C34: sb          $zero, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = 0;
    return;
    // 0x80000C34: sb          $zero, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = 0;
;}
RECOMP_FUNC void music_jingle_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C40: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C4C: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000C50: jal         0x8000B010
    // 0x80000C54: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C54: nop

    after_0:
    // 0x80000C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C60: jr          $ra
    // 0x80000C64: nop

    return;
    // 0x80000C64: nop

;}
RECOMP_FUNC void func_80000C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C70: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C7C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000C80: jal         0x80063CD0
    // 0x80000C84: nop

    func_80063A90(rdram, ctx);
        goto after_0;
    // 0x80000C84: nop

    after_0:
    // 0x80000C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C90: jr          $ra
    // 0x80000C94: nop

    return;
    // 0x80000C94: nop

;}
RECOMP_FUNC void music_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C98: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80000C9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CA0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80000CA4: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
    // 0x80000CA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000CAC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80000CB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CB4: jr          $ra
    // 0x80000CB8: sw          $t7, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = ctx->r15;
    return;
    // 0x80000CB8: sw          $t7, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void music_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC0: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
    // 0x80000CC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC8: sw          $zero, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = 0;
    // 0x80000CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000CD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000CD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000CE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000CE4: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000CE8: jal         0x80001990
    // 0x80000CEC: swc1        $f4, -0x3440($at)
    MEM_W(-0X3440, ctx->r1) = ctx->f4.u32l;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000CEC: swc1        $f4, -0x3440($at)
    MEM_W(-0X3440, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80000CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000CF8: jr          $ra
    // 0x80000CFC: nop

    return;
    // 0x80000CFC: nop

;}
RECOMP_FUNC void sound_update_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000D04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000D08: addiu       $a1, $a1, 0x62BC
    ctx->r5 = ADD32(ctx->r5, 0X62BC);
    // 0x80000D0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80000D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000D14: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80000D18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000D1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000D20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000D24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000D28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000D2C: blez        $v1, L_80000DBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80000D30: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80000DBC;
    }
    // 0x80000D30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80000D34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000D38: addiu       $v0, $v0, 0x62B8
    ctx->r2 = ADD32(ctx->r2, 0X62B8);
    // 0x80000D3C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000D40: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80000D44: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80000D48: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80000D4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80000D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000D54: addiu       $a0, $a0, -0x3440
    ctx->r4 = ADD32(ctx->r4, -0X3440);
    // 0x80000D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000D5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80000D60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80000D64: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80000D68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000D6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80000D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000D74: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80000D78: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000D7C: nop

    // 0x80000D80: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80000D84: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80000D88: nop

    // 0x80000D8C: bc1f        L_80000DA4
    if (!c1cs) {
        // 0x80000D90: nop
    
            goto L_80000DA4;
    }
    // 0x80000D90: nop

    // 0x80000D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000D98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000D9C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000DA0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000DA4:
    // 0x80000DA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DA8: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000DAC: jal         0x80001990
    // 0x80000DB0: nop

    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000DB0: nop

    after_0:
    // 0x80000DB4: b           L_80000E44
    // 0x80000DB8: nop

        goto L_80000E44;
    // 0x80000DB8: nop

L_80000DBC:
    // 0x80000DBC: bgez        $v1, L_80000E44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80000DC0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80000E44;
    }
    // 0x80000DC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000DC4: addiu       $v0, $v0, 0x62B8
    ctx->r2 = ADD32(ctx->r2, 0X62B8);
    // 0x80000DC8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000DCC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80000DD0: subu        $t1, $t9, $s0
    ctx->r9 = SUB32(ctx->r25, ctx->r16);
    // 0x80000DD4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80000DD8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000DE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000DE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80000DE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DEC: addiu       $a0, $a0, -0x3440
    ctx->r4 = ADD32(ctx->r4, -0X3440);
    // 0x80000DF0: div.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80000DF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000DF8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80000DFC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80000E00: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80000E04: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80000E08: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000E0C: nop

    // 0x80000E10: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80000E14: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80000E18: nop

    // 0x80000E1C: bc1f        L_80000E34
    if (!c1cs) {
        // 0x80000E20: nop
    
            goto L_80000E34;
    }
    // 0x80000E20: nop

    // 0x80000E24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000E28: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000E2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000E30: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000E34:
    // 0x80000E34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000E38: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000E3C: jal         0x80001990
    // 0x80000E40: nop

    music_volume_set(rdram, ctx);
        goto after_1;
    // 0x80000E40: nop

    after_1:
L_80000E44:
    // 0x80000E44: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80000E48: addiu       $s3, $s3, -0x3438
    ctx->r19 = ADD32(ctx->r19, -0X3438);
    // 0x80000E4C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80000E50: nop

    // 0x80000E54: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E58: nop
    
            goto L_80000EFC;
    }
    // 0x80000E58: nop

    // 0x80000E5C: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80000EFC;
    }
    // 0x80000E60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80000E64: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000E68: addiu       $s1, $s1, 0x62C8
    ctx->r17 = ADD32(ctx->r17, 0X62C8);
    // 0x80000E6C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
L_80000E70:
    // 0x80000E70: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x80000E74: nop

    // 0x80000E78: subu        $t3, $t2, $s4
    ctx->r11 = SUB32(ctx->r10, ctx->r20);
    // 0x80000E7C: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
    // 0x80000E80: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x80000E84: nop

    // 0x80000E88: bgtz        $t4, L_80000EE8
    if (SIGNED(ctx->r12) > 0) {
        // 0x80000E8C: nop
    
            goto L_80000EE8;
    }
    // 0x80000E8C: nop

    // 0x80000E90: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80000E94: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80000E98: jal         0x80001D04
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_2:
    // 0x80000EA0: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80000EA4: nop

    // 0x80000EA8: addiu       $v0, $t5, -0x1
    ctx->r2 = ADD32(ctx->r13, -0X1);
    // 0x80000EAC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000EB0: beq         $at, $zero, L_80000EF0
    if (ctx->r1 == 0) {
        // 0x80000EB4: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_80000EF0;
    }
    // 0x80000EB4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80000EB8: lhu         $t7, 0x8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X8);
    // 0x80000EBC: lh          $t8, 0xA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XA);
    // 0x80000EC0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80000EC4: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x80000EC8: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x80000ECC: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80000ED0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80000ED4:
    // 0x80000ED4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000ED8: bne         $at, $zero, L_80000ED4
    if (ctx->r1 != 0) {
        // 0x80000EDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80000ED4;
    }
    // 0x80000EDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80000EE0: b           L_80000EF4
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80000EF4;
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EE8:
    // 0x80000EE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80000EEC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80000EF0:
    // 0x80000EF0: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EF4:
    // 0x80000EF4: bne         $at, $zero, L_80000E70
    if (ctx->r1 != 0) {
        // 0x80000EF8: nop
    
            goto L_80000E70;
    }
    // 0x80000EF8: nop

L_80000EFC:
    // 0x80000EFC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80000F00: addiu       $s0, $s0, -0x3460
    ctx->r16 = ADD32(ctx->r16, -0X3460);
    // 0x80000F04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F08: lw          $a1, 0x627C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X627C);
    // 0x80000F0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F10: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F14: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F18: addiu       $a3, $a3, 0x6308
    ctx->r7 = ADD32(ctx->r7, 0X6308);
    // 0x80000F1C: jal         0x8000232C
    // 0x80000F20: addiu       $a2, $a2, -0x3434
    ctx->r6 = ADD32(ctx->r6, -0X3434);
    music_sequence_init(rdram, ctx);
        goto after_3;
    // 0x80000F20: addiu       $a2, $a2, -0x3434
    ctx->r6 = ADD32(ctx->r6, -0X3434);
    after_3:
    // 0x80000F24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000F28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F2C: lw          $a1, 0x6280($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6280);
    // 0x80000F30: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000F34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F38: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F3C: addiu       $a3, $a3, 0x6400
    ctx->r7 = ADD32(ctx->r7, 0X6400);
    // 0x80000F40: jal         0x8000232C
    // 0x80000F44: addiu       $a2, $a2, -0x3430
    ctx->r6 = ADD32(ctx->r6, -0X3430);
    music_sequence_init(rdram, ctx);
        goto after_4;
    // 0x80000F44: addiu       $a2, $a2, -0x3430
    ctx->r6 = ADD32(ctx->r6, -0X3430);
    after_4:
    // 0x80000F48: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000F4C: addiu       $s1, $s1, 0x62B0
    ctx->r17 = ADD32(ctx->r17, 0X62B0);
    // 0x80000F50: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80000F54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F58: bne         $t0, $at, L_80000FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80000F5C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F64: nop

    // 0x80000F68: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x80000F6C: nop

    // 0x80000F70: beq         $t1, $zero, L_80000FC0
    if (ctx->r9 == 0) {
        // 0x80000F74: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F78: jal         0x800C7DF0
    // 0x80000F7C: nop

    alCSPGetTempo(rdram, ctx);
        goto after_5;
    // 0x80000F7C: nop

    after_5:
    // 0x80000F80: lui         $t2, 0x393
    ctx->r10 = S32(0X393 << 16);
    // 0x80000F84: ori         $t2, $t2, 0x8700
    ctx->r10 = ctx->r10 | 0X8700;
    // 0x80000F88: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x80000F8C: bne         $v0, $zero, L_80000F98
    if (ctx->r2 != 0) {
        // 0x80000F90: nop
    
            goto L_80000F98;
    }
    // 0x80000F90: nop

    // 0x80000F94: break       7
    do_break(2147487636);
L_80000F98:
    // 0x80000F98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F9C: bne         $v0, $at, L_80000FB0
    if (ctx->r2 != ctx->r1) {
        // 0x80000FA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80000FB0;
    }
    // 0x80000FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80000FA4: bne         $t2, $at, L_80000FB0
    if (ctx->r10 != ctx->r1) {
        // 0x80000FA8: nop
    
            goto L_80000FB0;
    }
    // 0x80000FA8: nop

    // 0x80000FAC: break       6
    do_break(2147487660);
L_80000FB0:
    // 0x80000FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x80000FB4: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80000FB8: nop

    // 0x80000FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80000FC0:
    // 0x80000FC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000FC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000FC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000FCC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000FD0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000FD4: jr          $ra
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80000FE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000FE4: addiu       $a2, $a2, -0x3438
    ctx->r6 = ADD32(ctx->r6, -0X3438);
    // 0x80000FE8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80000FEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80000FF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80000FF4: beq         $at, $zero, L_80001048
    if (ctx->r1 == 0) {
        // 0x80000FF8: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_80001048;
    }
    // 0x80000FF8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80000FFC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80001000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001004: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001008: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000100C: addiu       $t8, $t8, 0x62C8
    ctx->r24 = ADD32(ctx->r24, 0X62C8);
    // 0x80001010: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80001014: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80001018: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000101C: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80001020: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80001024: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001028: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000102C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80001030: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80001034: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80001038: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8000103C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80001040: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80001044: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
L_80001048:
    // 0x80001048: jr          $ra
    // 0x8000104C: nop

    return;
    // 0x8000104C: nop

;}
RECOMP_FUNC void sound_clear_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001050: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001054: jr          $ra
    // 0x80001058: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
    return;
    // 0x80001058: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
;}
RECOMP_FUNC void music_channel_get_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000105C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001060: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001064: nop

    // 0x80001068: lhu         $v0, 0x30($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X30);
    // 0x8000106C: jr          $ra
    // 0x80001070: nop

    return;
    // 0x80001070: nop

;}
RECOMP_FUNC void music_dynamic_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001078: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000107C: lbu         $t7, -0x3434($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3434);
    // 0x80001080: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001084: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001088: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000108C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001090: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001094: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001098: beq         $t7, $zero, L_800010AC
    if (ctx->r15 == 0) {
        // 0x8000109C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800010AC;
    }
    // 0x8000109C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800010A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800010A4: b           L_800010FC
    // 0x800010A8: sw          $t6, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r14;
        goto L_800010FC;
    // 0x800010A8: sw          $t6, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r14;
L_800010AC:
    // 0x800010AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800010B0: lw          $t8, -0x3460($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3460);
    // 0x800010B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800010B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800010BC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x800010C0: sh          $a0, 0x30($t8)
    MEM_H(0X30, ctx->r24) = ctx->r4;
    // 0x800010C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010C8:
    // 0x800010C8: sllv        $t0, $t9, $s0
    ctx->r8 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x800010CC: and         $t1, $s1, $t0
    ctx->r9 = ctx->r17 & ctx->r8;
    // 0x800010D0: beq         $t1, $zero, L_800010E8
    if (ctx->r9 == 0) {
        // 0x800010D4: nop
    
            goto L_800010E8;
    }
    // 0x800010D4: nop

    // 0x800010D8: jal         0x80001170
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800010E0: b           L_800010F4
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800010F4;
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010E8:
    // 0x800010E8: jal         0x80001114
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x800010F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010F4:
    // 0x800010F4: bne         $s0, $s2, L_800010C8
    if (ctx->r16 != ctx->r18) {
        // 0x800010F8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800010C8;
    }
    // 0x800010F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010FC:
    // 0x800010FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001104: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000110C: jr          $ra
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void music_channel_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001114: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000111C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001124: beq         $at, $zero, L_8000113C
    if (ctx->r1 == 0) {
        // 0x80001128: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000113C;
    }
    // 0x80001128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000112C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001130: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001134: jal         0x80063D30
    // 0x80001138: nop

    alSeqChOff(rdram, ctx);
        goto after_0;
    // 0x80001138: nop

    after_0:
L_8000113C:
    // 0x8000113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001144: jr          $ra
    // 0x80001148: nop

    return;
    // 0x80001148: nop

;}
RECOMP_FUNC void music_channel_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000114C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001150: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80001158: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x8000115C: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80001160: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    // 0x80001164: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001168: jr          $ra
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void music_channel_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001170: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001178: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8000117C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001180: beq         $at, $zero, L_80001198
    if (ctx->r1 == 0) {
        // 0x80001184: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001198;
    }
    // 0x80001184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001188: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000118C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001190: jal         0x80063D84
    // 0x80001194: nop

    alSeqChOn(rdram, ctx);
        goto after_0;
    // 0x80001194: nop

    after_0:
L_80001198:
    // 0x80001198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011A0: jr          $ra
    // 0x800011A4: nop

    return;
    // 0x800011A4: nop

;}
RECOMP_FUNC void music_channel_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011AC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011B0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800011C0: beq         $at, $zero, L_800011D8
    if (ctx->r1 == 0) {
        // 0x800011C4: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_800011D8;
    }
    // 0x800011C4: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x800011C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800011CC: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800011D0: jal         0x800C7E40
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_800011D8:
    // 0x800011D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800011DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011E0: jr          $ra
    // 0x800011E4: nop

    return;
    // 0x800011E4: nop

;}
RECOMP_FUNC void music_channel_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011EC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011F0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001200: beq         $at, $zero, L_80001218
    if (ctx->r1 == 0) {
        // 0x80001204: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001218;
    }
    // 0x80001204: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001208: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000120C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001210: jal         0x800C7EA0
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001218:
    // 0x80001218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000121C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001220: jr          $ra
    // 0x80001224: nop

    return;
    // 0x80001224: nop

;}
RECOMP_FUNC void music_channel_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001228: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8000122C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001230: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001238: bne         $at, $zero, L_80001248
    if (ctx->r1 != 0) {
        // 0x8000123C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001248;
    }
    // 0x8000123C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001240: b           L_80001258
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80001258;
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001248:
    // 0x80001248: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000124C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001250: jal         0x800C7F00
    // 0x80001254: nop

    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001254: nop

    after_0:
L_80001258:
    // 0x80001258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001260: jr          $ra
    // 0x80001264: nop

    return;
    // 0x80001264: nop

;}
RECOMP_FUNC void music_channel_fade_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000126C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001270: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x80001274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000127C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001280: beq         $at, $zero, L_80001298
    if (ctx->r1 == 0) {
        // 0x80001284: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001298;
    }
    // 0x80001284: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000128C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001290: jal         0x80063DE0
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetFadeIn(rdram, ctx);
        goto after_0;
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001298:
    // 0x80001298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000129C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012A0: jr          $ra
    // 0x800012A4: nop

    return;
    // 0x800012A4: nop

;}
RECOMP_FUNC void music_channel_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012A8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800012B0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800012B8: bne         $at, $zero, L_800012C8
    if (ctx->r1 != 0) {
        // 0x800012BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800012C8;
    }
    // 0x800012BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800012C0: b           L_800012D8
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800012D8;
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800012C8:
    // 0x800012C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800012CC: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800012D0: jal         0x80063E40
    // 0x800012D4: nop

    alCSPGetFadeIn(rdram, ctx);
        goto after_0;
    // 0x800012D4: nop

    after_0:
L_800012D8:
    // 0x800012D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800012DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012E0: jr          $ra
    // 0x800012E4: nop

    return;
    // 0x800012E4: nop

;}
RECOMP_FUNC void music_channel_reset_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800012EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800012F0: lw          $t6, -0x3448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3448);
    // 0x800012F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800012F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800012FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001300: bne         $t6, $zero, L_80001340
    if (ctx->r14 != 0) {
        // 0x80001304: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80001340;
    }
    // 0x80001304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000130C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80001310: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001314:
    // 0x80001314: jal         0x80001170
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_0:
    // 0x8000131C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80001320: jal         0x80001268
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_1;
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_1:
    // 0x80001328: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8000132C: jal         0x800011E8
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_volume_set(rdram, ctx);
        goto after_2;
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_2:
    // 0x80001334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001338: bne         $s0, $s2, L_80001314
    if (ctx->r16 != ctx->r18) {
        // 0x8000133C: andi        $s1, $s0, 0xFF
        ctx->r17 = ctx->r16 & 0XFF;
            goto L_80001314;
    }
    // 0x8000133C: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001340:
    // 0x80001340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000134C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001350: jr          $ra
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80001358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000135C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001360: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80001364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000136C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80001370: beq         $a3, $at, L_800013C0
    if (ctx->r7 == ctx->r1) {
        // 0x80001374: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_800013C0;
    }
    // 0x80001374: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80001378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000137C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001380: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80001384: jal         0x800C7F00
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000138C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80001390: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    // 0x80001394: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80001398: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8000139C: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800013A0: bne         $at, $zero, L_800013AC
    if (ctx->r1 != 0) {
        // 0x800013A4: andi        $a2, $v1, 0xFF
        ctx->r6 = ctx->r3 & 0XFF;
            goto L_800013AC;
    }
    // 0x800013A4: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x800013A8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_800013AC:
    // 0x800013AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013B0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800013B4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x800013B8: jal         0x800C7EA0
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_1;
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    after_1:
L_800013C0:
    // 0x800013C0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800013C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800013C8: beq         $t8, $at, L_8000141C
    if (ctx->r24 == ctx->r1) {
        // 0x800013CC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000141C;
    }
    // 0x800013CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013D0: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800013D4: jal         0x800C7F00
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    alCSPGetChlVol(rdram, ctx);
        goto after_2;
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x800013DC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800013E0: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x800013E4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800013E8: beq         $at, $zero, L_80001400
    if (ctx->r1 == 0) {
        // 0x800013EC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80001400;
    }
    // 0x800013EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013F0: subu        $a2, $v0, $t9
    ctx->r6 = SUB32(ctx->r2, ctx->r25);
    // 0x800013F4: andi        $t0, $a2, 0xFF
    ctx->r8 = ctx->r6 & 0XFF;
    // 0x800013F8: b           L_80001404
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_80001404;
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80001400:
    // 0x80001400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80001404:
    // 0x80001404: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001408: jal         0x800C7EA0
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_3;
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    after_3:
    // 0x80001410: lbu         $v0, 0x1E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1E);
    // 0x80001414: b           L_80001434
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001434;
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000141C:
    // 0x8000141C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x80001420: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80001424: subu        $v0, $t2, $t1
    ctx->r2 = SUB32(ctx->r10, ctx->r9);
    // 0x80001428: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8000142C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80001430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001434:
    // 0x80001434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001438: jr          $ra
    // 0x8000143C: nop

    return;
    // 0x8000143C: nop

;}
RECOMP_FUNC void music_get_fx_mix_all_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001444: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001448: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000144C: addiu       $s3, $s3, -0x3460
    ctx->r19 = ADD32(ctx->r19, -0X3460);
    // 0x80001450: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001454: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000145C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001464: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x80001468: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000146C: blez        $t6, L_800014A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001470: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800014A0;
    }
    // 0x80001470: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80001474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80001478:
    // 0x80001478: jal         0x800C7F20
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    alSeqpGetChlFXMix(rdram, ctx);
        goto after_0;
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_0:
    // 0x80001480: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x80001484: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000148C: lbu         $t7, 0x34($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X34);
    // 0x80001490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001494: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80001498: bne         $at, $zero, L_80001478
    if (ctx->r1 != 0) {
        // 0x8000149C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80001478;
    }
    // 0x8000149C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800014A0:
    // 0x800014A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800014A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800014A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800014AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800014B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800014B4: jr          $ra
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void music_tempo_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800014BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800014C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800014C4: jal         0x800015B8
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    music_tempo(rdram, ctx);
        goto after_0;
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800014CC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800014D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800014D4: bgez        $t6, L_800014EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800014D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800014EC;
    }
    // 0x800014D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800014DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800014E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800014E4: nop

    // 0x800014E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800014EC:
    // 0x800014EC: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800014F0: nop

    // 0x800014F4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800014F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800014FC: nop

    // 0x80001500: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80001504: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001508: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000150C: nop

    // 0x80001510: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80001514: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80001518: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000151C: jal         0x80001534
    // 0x80001520: nop

    music_tempo_set(rdram, ctx);
        goto after_1;
    // 0x80001520: nop

    after_1:
    // 0x80001524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000152C: jr          $ra
    // 0x80001530: nop

    return;
    // 0x80001530: nop

;}
RECOMP_FUNC void music_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000153C: beq         $a0, $zero, L_800015A8
    if (ctx->r4 == 0) {
        // 0x80001540: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800015A8;
    }
    // 0x80001540: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001544: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80001548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000154C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80001550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001558: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000155C: lwc1        $f16, 0x4F6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4F6C);
    // 0x80001560: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001564: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001568: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000156C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001570: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80001574: nop

    // 0x80001578: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000157C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001580: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001584: nop

    // 0x80001588: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000158C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001590: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80001594: jal         0x800C7F40
    // 0x80001598: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001598: nop

    after_0:
    // 0x8000159C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800015A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800015A4: sh          $a2, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r6;
L_800015A8:
    // 0x800015A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800015B0: jr          $ra
    // 0x800015B4: nop

    return;
    // 0x800015B4: nop

;}
RECOMP_FUNC void music_tempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800015BC: lh          $v0, 0x62B0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X62B0);
    // 0x800015C0: jr          $ra
    // 0x800015C4: nop

    return;
    // 0x800015C4: nop

;}
RECOMP_FUNC void music_is_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800015D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800015D4: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800015D8: jal         0x800C7FB0
    // 0x800015DC: nop

    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x800015DC: nop

    after_0:
    // 0x800015E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015E4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800015E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800015EC: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800015F0: jr          $ra
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_animation_fraction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001600: jal         0x800C7E30
    // 0x80001604: nop

    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80001604: nop

    after_0:
    // 0x80001608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000160C: lw          $a0, -0x3444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3444);
    // 0x80001610: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001614: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80001618: beq         $at, $zero, L_80001668
    if (ctx->r1 == 0) {
        // 0x8000161C: lui         $t1, 0x8011
        ctx->r9 = S32(0X8011 << 16);
            goto L_80001668;
    }
    // 0x8000161C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001620: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x80001624: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80001628: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000162C: addiu       $v1, $v1, 0x62B4
    ctx->r3 = ADD32(ctx->r3, 0X62B4);
    // 0x80001630: bgez        $t6, L_80001648
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80001634: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001648;
    }
    // 0x80001634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000163C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001640: nop

    // 0x80001644: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001648:
    // 0x80001648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000164C: lwc1        $f10, 0x4F70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4F70);
    // 0x80001650: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001654: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001658: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000165C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80001660: b           L_800016B0
    // 0x80001664: swc1        $f4, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f4.u32l;
        goto L_800016B0;
    // 0x80001664: swc1        $f4, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f4.u32l;
L_80001668:
    // 0x80001668: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8000166C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80001670: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80001674: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001678: addiu       $v1, $v1, 0x62B4
    ctx->r3 = ADD32(ctx->r3, 0X62B4);
    // 0x8000167C: bgez        $t8, L_80001694
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80001680: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80001694;
    }
    // 0x80001680: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80001684: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000168C: nop

    // 0x80001690: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80001694:
    // 0x80001694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001698: lwc1        $f18, 0x4F74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4F74);
    // 0x8000169C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016A0: div.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800016A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016A8: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800016AC: swc1        $f8, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f8.u32l;
L_800016B0:
    // 0x800016B0: lbu         $t9, 0x62C0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X62C0);
    // 0x800016B4: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x800016B8: bne         $t9, $zero, L_800016C4
    if (ctx->r25 != 0) {
        // 0x800016BC: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800016C4;
    }
    // 0x800016BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016C0: sh          $t0, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r8;
L_800016C4:
    // 0x800016C4: lh          $t1, 0x62B0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X62B0);
    // 0x800016C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016CC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800016D0: lwc1        $f10, 0x4F78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4F78);
    // 0x800016D4: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800016D8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016E0: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800016E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800016E8: nop

    // 0x800016EC: bc1f        L_80001718
    if (!c1cs) {
        // 0x800016F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001718;
    }
    // 0x800016F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800016F4:
    // 0x800016F4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800016F8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800016FC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001700: nop

    // 0x80001704: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80001708: nop

    // 0x8000170C: bc1t        L_800016F4
    if (c1cs) {
        // 0x80001710: nop
    
            goto L_800016F4;
    }
    // 0x80001710: nop

    // 0x80001714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001718:
    // 0x80001718: sw          $v0, -0x3444($at)
    MEM_W(-0X3444, ctx->r1) = ctx->r2;
    // 0x8000171C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001720: jr          $ra
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    return;
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
;}
RECOMP_FUNC void sound_get_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001728: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000172C: addiu       $v1, $v1, 0x629C
    ctx->r3 = ADD32(ctx->r3, 0X629C);
    // 0x80001730: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80001734: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80001738: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x8000173C: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80001740: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001744: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80001748: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8000174C: nop

    // 0x80001750: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x80001754: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80001758: nop

    // 0x8000175C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80001760: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80001764: nop

    // 0x80001768: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8000176C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80001770: nop

    // 0x80001774: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80001778: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x8000177C: jr          $ra
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
    return;
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
;}
RECOMP_FUNC void music_jingle_play_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000178C: jal         0x80001C08
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001794: bne         $v0, $zero, L_800017C4
    if (ctx->r2 != 0) {
        // 0x80001798: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800017C4;
    }
    // 0x80001798: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000179C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800017A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800017A4: addiu       $v0, $v0, 0x6285
    ctx->r2 = ADD32(ctx->r2, 0X6285);
    // 0x800017A8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800017AC: lw          $a1, -0x345C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X345C);
    // 0x800017B0: jal         0x800022BC
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_1;
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    after_1:
    // 0x800017B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800017BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800017C0: sb          $t7, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = ctx->r15;
L_800017C4:
    // 0x800017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800017C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800017CC: jr          $ra
    // 0x800017D0: nop

    return;
    // 0x800017D0: nop

;}
RECOMP_FUNC void sound_jingle_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800017D8: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800017DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800017E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800017E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800017E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800017EC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800017F0: lwc1        $f16, 0x4F7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4F7C);
    // 0x800017F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800017F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800017FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001800: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001804: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001808: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000180C: nop

    // 0x80001810: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80001814: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001818: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000181C: nop

    // 0x80001820: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001824: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001828: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000182C: jal         0x800C7F40
    // 0x80001830: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001830: nop

    after_0:
    // 0x80001834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000183C: jr          $ra
    // 0x80001840: nop

    return;
    // 0x80001840: nop

;}
RECOMP_FUNC void music_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001844: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001848: lw          $t6, -0x3448($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3448);
    // 0x8000184C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001850: bne         $t6, $zero, L_80001868
    if (ctx->r14 != 0) {
        // 0x80001854: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001868;
    }
    // 0x80001854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001858: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000185C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001860: jal         0x80002570
    // 0x80001864: nop

    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x80001864: nop

    after_0:
L_80001868:
    // 0x80001868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000186C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001870: jr          $ra
    // 0x80001874: nop

    return;
    // 0x80001874: nop

;}
RECOMP_FUNC void music_enabled_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001878: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000187C: addiu       $v0, $v0, -0x3450
    ctx->r2 = ADD32(ctx->r2, -0X3450);
    // 0x80001880: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80001884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001888: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8000188C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001890: beq         $t7, $t6, L_800018C0
    if (ctx->r15 == ctx->r14) {
        // 0x80001894: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800018C0;
    }
    // 0x80001894: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001898: beq         $t6, $zero, L_800018B8
    if (ctx->r14 == 0) {
        // 0x8000189C: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_800018B8;
    }
    // 0x8000189C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800018A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800018A4: lbu         $a0, 0x6284($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6284);
    // 0x800018A8: jal         0x80000B34
    // 0x800018AC: nop

    music_play(rdram, ctx);
        goto after_0;
    // 0x800018AC: nop

    after_0:
    // 0x800018B0: b           L_800018C4
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800018C4;
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018B8:
    // 0x800018B8: jal         0x80001844
    // 0x800018BC: nop

    music_stop(rdram, ctx);
        goto after_1;
    // 0x800018BC: nop

    after_1:
L_800018C0:
    // 0x800018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018C4:
    // 0x800018C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800018C8: jr          $ra
    // 0x800018CC: nop

    return;
    // 0x800018CC: nop

;}
RECOMP_FUNC void music_can_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800018D4: lbu         $v0, -0x3450($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3450);
    // 0x800018D8: jr          $ra
    // 0x800018DC: nop

    return;
    // 0x800018DC: nop

;}
RECOMP_FUNC void music_jingle_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800018E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800018E8: jal         0x80001C08
    // 0x800018EC: nop

    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x800018EC: nop

    after_0:
    // 0x800018F0: bne         $v0, $zero, L_80001908
    if (ctx->r2 != 0) {
        // 0x800018F4: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_80001908;
    }
    // 0x800018F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800018F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800018FC: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001900: jal         0x80002570
    // 0x80001904: sb          $zero, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = 0;
    music_sequence_stop(rdram, ctx);
        goto after_1;
    // 0x80001904: sb          $zero, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = 0;
    after_1:
L_80001908:
    // 0x80001908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000190C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001910: jr          $ra
    // 0x80001914: nop

    return;
    // 0x80001914: nop

;}
RECOMP_FUNC void music_current_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001918: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000191C: lbu         $v1, 0x6284($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6284);
    // 0x80001920: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001924: beq         $v1, $zero, L_8000194C
    if (ctx->r3 == 0) {
        // 0x80001928: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000194C;
    }
    // 0x80001928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000192C: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001934: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80001938: nop

    // 0x8000193C: bne         $t7, $at, L_8000194C
    if (ctx->r15 != ctx->r1) {
        // 0x80001940: nop
    
            goto L_8000194C;
    }
    // 0x80001940: nop

    // 0x80001944: jr          $ra
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000194C:
    // 0x8000194C: jr          $ra
    // 0x80001950: nop

    return;
    // 0x80001950: nop

;}
RECOMP_FUNC void music_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001954: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80001958: lbu         $v1, -0x3434($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X3434);
    // 0x8000195C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001960: beq         $v1, $zero, L_80001970
    if (ctx->r3 == 0) {
        // 0x80001964: nop
    
            goto L_80001970;
    }
    // 0x80001964: nop

    // 0x80001968: jr          $ra
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001970:
    // 0x80001970: lbu         $v0, 0x6284($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6284);
    // 0x80001974: nop

    // 0x80001978: jr          $ra
    // 0x8000197C: nop

    return;
    // 0x8000197C: nop

;}
RECOMP_FUNC void music_jingle_current(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001980: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001984: lbu         $v0, 0x6285($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6285);
    // 0x80001988: jr          $ra
    // 0x8000198C: nop

    return;
    // 0x8000198C: nop

;}
RECOMP_FUNC void music_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001990: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001994: addiu       $v0, $v0, -0x3458
    ctx->r2 = ADD32(ctx->r2, -0X3458);
    // 0x80001998: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000199C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x800019A0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800019A4: lw          $t7, -0x343C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X343C);
    // 0x800019A8: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800019AC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800019B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800019B4: lw          $t9, -0x3424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3424);
    // 0x800019B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800019BC: lwc1        $f8, -0x3440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x800019C0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800019C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800019C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800019CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800019D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800019D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800019D8: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800019DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800019E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800019E4: nop

    // 0x800019E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800019EC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800019F0: nop

    // 0x800019F4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800019F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800019FC: nop

    // 0x80001A00: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001A04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001A0C: nop

    // 0x80001A10: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001A14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001A18: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001A1C: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001A20: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001A24: jal         0x800C7DB0
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001A34: jr          $ra
    // 0x80001A38: nop

    return;
    // 0x80001A38: nop

;}
RECOMP_FUNC void music_volume_config_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001A40: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80001A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001A48: bne         $at, $zero, L_80001A54
    if (ctx->r1 != 0) {
        // 0x80001A4C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80001A54;
    }
    // 0x80001A4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001A50: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_80001A54:
    // 0x80001A54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001A58: addiu       $v0, $v0, -0x343C
    ctx->r2 = ADD32(ctx->r2, -0X343C);
    // 0x80001A5C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80001A60: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001A64: lbu         $t6, -0x3458($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3458);
    // 0x80001A68: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80001A6C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001A70: lw          $t9, -0x3424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3424);
    // 0x80001A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001A78: lwc1        $f8, -0x3440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x80001A7C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80001A80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001A84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80001A88: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001A8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80001A90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80001A94: nop

    // 0x80001A98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001A9C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80001AA0: nop

    // 0x80001AA4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001AA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80001AAC: nop

    // 0x80001AB0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001AB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001AB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001ABC: nop

    // 0x80001AC0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001AC4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001AC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001ACC: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001AD0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001AD4: jal         0x800C7DB0
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AE4: jr          $ra
    // 0x80001AE8: nop

    return;
    // 0x80001AE8: nop

;}
RECOMP_FUNC void music_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001AF0: lbu         $v0, -0x3458($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3458);
    // 0x80001AF4: jr          $ra
    // 0x80001AF8: nop

    return;
    // 0x80001AF8: nop

;}
RECOMP_FUNC void music_volume_config(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001B00: lw          $v0, -0x343C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X343C);
    // 0x80001B04: jr          $ra
    // 0x80001B08: nop

    return;
    // 0x80001B08: nop

;}
RECOMP_FUNC void music_jingle_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001B1C: jal         0x8000317C
    // 0x80001B20: sb          $a0, -0x3454($at)
    MEM_B(-0X3454, ctx->r1) = ctx->r4;
    sndp_get_global_volume(rdram, ctx);
        goto after_0;
    // 0x80001B20: sb          $a0, -0x3454($at)
    MEM_B(-0X3454, ctx->r1) = ctx->r4;
    after_0:
    // 0x80001B24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001B28: lbu         $t7, -0x3454($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3454);
    // 0x80001B2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001B30: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001B34: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001B38: mflo        $a1
    ctx->r5 = lo;
    // 0x80001B3C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80001B40: jal         0x800C7DB0
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_1;
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80001B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001B50: jr          $ra
    // 0x80001B54: nop

    return;
    // 0x80001B54: nop

;}
