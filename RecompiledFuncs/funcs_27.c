#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_ghost_data_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099F98: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80099F9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099FA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099FA4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80099FA8: addiu       $t6, $t6, 0x6A98
    ctx->r14 = ADD32(ctx->r14, 0X6A98);
    // 0x80099FAC: lw          $a0, 0x6A70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A70);
    // 0x80099FB0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099FB4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099FB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099FBC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80099FC0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80099FC4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80099FC8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80099FCC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80099FD0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80099FD4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80099FD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80099FDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80099FE0: addiu       $a3, $a3, 0x6A84
    ctx->r7 = ADD32(ctx->r7, 0X6A84);
    // 0x80099FE4: addiu       $a2, $a2, 0x6A8C
    ctx->r6 = ADD32(ctx->r6, 0X6A8C);
    // 0x80099FE8: addiu       $a1, $a1, 0x6A7C
    ctx->r5 = ADD32(ctx->r5, 0X6A7C);
    // 0x80099FEC: jal         0x8007592C
    // 0x80099FF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800756D4(rdram, ctx);
        goto after_0;
    // 0x80099FF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80099FF4: bne         $v0, $zero, L_8009A004
    if (ctx->r2 != 0) {
        // 0x80099FF8: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_8009A004;
    }
    // 0x80099FF8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80099FFC: jal         0x80099B78
    // 0x8009A000: nop

    ghostmenu_generate(rdram, ctx);
        goto after_1;
    // 0x8009A000: nop

    after_1:
L_8009A004:
    // 0x8009A004: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A008: jal         0x8009CBB8
    // 0x8009A00C: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x8009A00C: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    after_2:
    // 0x8009A010: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A014: jal         0x8009CDE8
    // 0x8009A018: addiu       $a0, $a0, 0x1CCC
    ctx->r4 = ADD32(ctx->r4, 0X1CCC);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8009A018: addiu       $a0, $a0, 0x1CCC
    ctx->r4 = ADD32(ctx->r4, 0X1CCC);
    after_3:
    // 0x8009A01C: jal         0x800C46D0
    // 0x8009A020: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x8009A020: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8009A024: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A028: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8009A02C: lw          $s7, 0x38($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X38);
    // 0x8009A030: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A034: sw          $s7, 0x1ABC($at)
    MEM_W(0X1ABC, ctx->r1) = ctx->r23;
    // 0x8009A038: lw          $fp, 0x3C($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X3C);
    // 0x8009A03C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A040: sw          $fp, 0x1AE4($at)
    MEM_W(0X1AE4, ctx->r1) = ctx->r30;
    // 0x8009A044: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8009A048: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A04C: sw          $v1, 0x1B14($at)
    MEM_W(0X1B14, ctx->r1) = ctx->r3;
    // 0x8009A050: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x8009A054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A058: sw          $a0, 0x1B3C($at)
    MEM_W(0X1B3C, ctx->r1) = ctx->r4;
    // 0x8009A05C: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x8009A060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A064: sw          $a1, 0x1B6C($at)
    MEM_W(0X1B6C, ctx->r1) = ctx->r5;
    // 0x8009A068: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    // 0x8009A06C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A070: sw          $a2, 0x1B94($at)
    MEM_W(0X1B94, ctx->r1) = ctx->r6;
    // 0x8009A074: lw          $a3, 0x50($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X50);
    // 0x8009A078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A07C: sw          $a3, 0x1BC4($at)
    MEM_W(0X1BC4, ctx->r1) = ctx->r7;
    // 0x8009A080: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    // 0x8009A084: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A088: sw          $t1, 0x1BEC($at)
    MEM_W(0X1BEC, ctx->r1) = ctx->r9;
    // 0x8009A08C: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x8009A090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A094: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009A098: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8009A09C: sw          $t2, 0x1C1C($at)
    MEM_W(0X1C1C, ctx->r1) = ctx->r10;
    // 0x8009A0A0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8009A0A4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8009A0A8: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8009A0AC: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A0B0: lw          $t3, 0x5C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X5C);
    // 0x8009A0B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A0B8: sw          $t3, 0x1C44($at)
    MEM_W(0X1C44, ctx->r1) = ctx->r11;
    // 0x8009A0BC: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8009A0C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009A0C4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8009A0C8: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8009A0CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A0D0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8009A0D4: addiu       $t7, $t7, 0x1ABC
    ctx->r15 = ADD32(ctx->r15, 0X1ABC);
    // 0x8009A0D8: addiu       $a1, $a1, 0x1B14
    ctx->r5 = ADD32(ctx->r5, 0X1B14);
    // 0x8009A0DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A0E0: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A0E4: xori        $t8, $t2, 0x1
    ctx->r24 = ctx->r10 ^ 0X1;
    // 0x8009A0E8: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A0EC: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x8009A0F0: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x8009A0F4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A0F8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x8009A0FC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8009A100: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8009A104: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8009A108: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009A10C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009A110: addiu       $a3, $a3, 0x1C1C
    ctx->r7 = ADD32(ctx->r7, 0X1C1C);
    // 0x8009A114: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x8009A118: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A11C: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A120: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x8009A124: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A128: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x8009A12C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009A130: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8009A134: addiu       $t9, $t9, 0x1B6C
    ctx->r25 = ADD32(ctx->r25, 0X1B6C);
    // 0x8009A138: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x8009A13C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009A140: addiu       $t8, $t8, 0x1BC4
    ctx->r24 = ADD32(ctx->r24, 0X1BC4);
    // 0x8009A144: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x8009A148: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A14C: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x8009A150: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x8009A154: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009A158: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8009A15C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A160: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8009A164: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x8009A168: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A16C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009A170: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009A174: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8009A178: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009A17C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8009A180: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x8009A184: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x8009A188: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8009A18C: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A190: addu        $ra, $t0, $t8
    ctx->r31 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A194: xori        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 ^ 0X1;
    // 0x8009A198: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A19C: sll         $t9, $ra, 3
    ctx->r25 = S32(ctx->r31 << 3);
    // 0x8009A1A0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009A1A4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A1A8: or          $ra, $t9, $zero
    ctx->r31 = ctx->r25 | 0;
    // 0x8009A1AC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8009A1B0: sw          $fp, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r30;
    // 0x8009A1B4: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x8009A1B8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009A1BC: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x8009A1C0: sw          $s7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r23;
    // 0x8009A1C4: sw          $fp, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r30;
    // 0x8009A1C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A1CC: addu        $s0, $t0, $t9
    ctx->r16 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A1D0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8009A1D4: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A1D8: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8009A1DC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A1E0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009A1E4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009A1E8: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8009A1EC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A1F0: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8009A1F4: addu        $t6, $a3, $ra
    ctx->r14 = ADD32(ctx->r7, ctx->r31);
    // 0x8009A1F8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8009A1FC: andi        $t9, $s1, 0x1
    ctx->r25 = ctx->r17 & 0X1;
    // 0x8009A200: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A204: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8009A208: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009A20C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8009A210: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8009A214: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009A218: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8009A21C: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x8009A220: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8009A224: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8009A228: addiu       $s4, $t0, 0x3
    ctx->r20 = ADD32(ctx->r8, 0X3);
    // 0x8009A22C: sw          $s7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r23;
    // 0x8009A230: mflo        $t6
    ctx->r14 = lo;
    // 0x8009A234: addu        $s2, $t0, $t6
    ctx->r18 = ADD32(ctx->r8, ctx->r14);
    // 0x8009A238: xori        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 ^ 0X1;
    // 0x8009A23C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A240: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x8009A244: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x8009A248: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8009A24C: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x8009A250: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009A254: sw          $fp, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r30;
    // 0x8009A258: mflo        $t7
    ctx->r15 = lo;
    // 0x8009A25C: addu        $s3, $t0, $t7
    ctx->r19 = ADD32(ctx->r8, ctx->r15);
    // 0x8009A260: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x8009A264: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x8009A268: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8009A26C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A270: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8009A274: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8009A278: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x8009A27C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A280: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
    // 0x8009A284: addu        $t8, $a3, $s2
    ctx->r24 = ADD32(ctx->r7, ctx->r18);
    // 0x8009A288: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8009A28C: andi        $t7, $s4, 0x1
    ctx->r15 = ctx->r20 & 0X1;
    // 0x8009A290: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A294: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x8009A298: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8009A29C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8009A2A0: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8009A2A4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8009A2A8: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x8009A2AC: addu        $t6, $a3, $s3
    ctx->r14 = ADD32(ctx->r7, ctx->r19);
    // 0x8009A2B0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8009A2B4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009A2B8: sw          $s7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r23;
    // 0x8009A2BC: sw          $fp, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r30;
    // 0x8009A2C0: mflo        $t8
    ctx->r24 = lo;
    // 0x8009A2C4: addu        $s5, $t0, $t8
    ctx->r21 = ADD32(ctx->r8, ctx->r24);
    // 0x8009A2C8: xori        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 ^ 0X1;
    // 0x8009A2CC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009A2D0: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x8009A2D4: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A2D8: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x8009A2DC: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
    // 0x8009A2E0: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8009A2E4: mflo        $t9
    ctx->r25 = lo;
    // 0x8009A2E8: addu        $s6, $t0, $t9
    ctx->r22 = ADD32(ctx->r8, ctx->r25);
    // 0x8009A2EC: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x8009A2F0: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8009A2F4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x8009A2F8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8009A2FC: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x8009A300: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8009A304: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x8009A308: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A30C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8009A310: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x8009A314: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8009A318: addu        $t6, $a3, $s5
    ctx->r14 = ADD32(ctx->r7, ctx->r21);
    // 0x8009A31C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8009A320: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x8009A324: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8009A328: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
    // 0x8009A32C: addu        $t8, $a3, $s6
    ctx->r24 = ADD32(ctx->r7, ctx->r22);
    // 0x8009A330: jal         0x8008E914
    // 0x8009A334: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    menu_init_vehicle_textures(rdram, ctx);
        goto after_5;
    // 0x8009A334: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    after_5:
    // 0x8009A338: jal         0x80094B08
    // 0x8009A33C: nop

    menu_racer_portraits(rdram, ctx);
        goto after_6;
    // 0x8009A33C: nop

    after_6:
    // 0x8009A340: jal         0x8008E968
    // 0x8009A344: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_7;
    // 0x8009A344: nop

    after_7:
    // 0x8009A348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A34C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8009A350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A354: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009A358: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A35C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A360: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x8009A364: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009A368: addiu       $v0, $v0, -0x604
    ctx->r2 = ADD32(ctx->r2, -0X604);
    // 0x8009A36C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8009A370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009A374: bne         $t9, $zero, L_8009A390
    if (ctx->r25 != 0) {
        // 0x8009A378: sw          $zero, 0x6A38($at)
        MEM_W(0X6A38, ctx->r1) = 0;
            goto L_8009A390;
    }
    // 0x8009A378: sw          $zero, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = 0;
    // 0x8009A37C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A380: jal         0x800C06F8
    // 0x8009A384: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x8009A384: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_8:
    // 0x8009A388: b           L_8009A39C
    // 0x8009A38C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009A39C;
    // 0x8009A38C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009A390:
    // 0x8009A390: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8009A394: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009A398: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009A39C:
    // 0x8009A39C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009A3A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8009A3A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8009A3A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8009A3AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8009A3B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8009A3B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8009A3B8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8009A3BC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8009A3C0: jr          $ra
    // 0x8009A3C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8009A3C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void ghostmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A3C8: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8009A3CC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8009A3D0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009A3D4: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8009A3D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8009A3DC: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x8009A3E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009A3E4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8009A3E8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8009A3EC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8009A3F0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8009A3F4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8009A3F8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8009A3FC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8009A400: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8009A404: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009A408: jal         0x8006816C
    // 0x8009A40C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8009A40C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x8009A410: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8009A414: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8009A418: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A41C: bne         $t6, $zero, L_8009A430
    if (ctx->r14 != 0) {
        // 0x8009A420: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8009A430;
    }
    // 0x8009A420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009A424: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8009A428: b           L_8009A434
    // 0x8009A42C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
        goto L_8009A434;
    // 0x8009A42C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
L_8009A430:
    // 0x8009A430: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_8009A434:
    // 0x8009A434: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x8009A438: jal         0x800C484C
    // 0x8009A43C: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x8009A43C: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    after_1:
    // 0x8009A440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A44C: jal         0x800C492C
    // 0x8009A450: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x8009A450: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8009A454: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8009A458: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A45C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A468: jal         0x800C48E4
    // 0x8009A46C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x8009A46C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8009A470: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009A474: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8009A478: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A47C: lw          $a3, 0x148($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X148);
    // 0x8009A480: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A484: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A488: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8009A48C: jal         0x800C49A0
    // 0x8009A490: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x8009A490: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x8009A494: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009A498: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009A49C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8009A4A0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A4A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A4A8: jal         0x800C48E4
    // 0x8009A4AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x8009A4AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8009A4B0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009A4B4: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009A4B8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8009A4BC: lw          $a3, 0x148($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X148);
    // 0x8009A4C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009A4C4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A4C8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8009A4CC: jal         0x800C49A0
    // 0x8009A4D0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8009A4D0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x8009A4D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009A4D8: lw          $t6, 0x6A74($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A74);
    // 0x8009A4DC: addiu       $s2, $zero, 0x38
    ctx->r18 = ADD32(0, 0X38);
    // 0x8009A4E0: bgtz        $t6, L_8009A534
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009A4E4: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8009A534;
    }
    // 0x8009A4E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009A4E8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A4EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A4F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8009A4F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A4F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A4FC: jal         0x800C48E4
    // 0x8009A500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8009A500: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8009A504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009A508: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009A50C: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A510: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009A514: lw          $a3, 0x14C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14C);
    // 0x8009A518: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A51C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A520: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8009A524: jal         0x800C49A0
    // 0x8009A528: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    draw_text(rdram, ctx);
        goto after_8;
    // 0x8009A528: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    after_8:
    // 0x8009A52C: b           L_8009ACE4
    // 0x8009A530: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8009ACE4;
    // 0x8009A530: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8009A534:
    // 0x8009A534: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A538: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x8009A53C: sw          $t1, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r9;
    // 0x8009A540: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8009A544: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8009A548: bne         $at, $zero, L_8009A558
    if (ctx->r1 != 0) {
        // 0x8009A54C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8009A558;
    }
    // 0x8009A54C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009A550: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8009A554: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
L_8009A558:
    // 0x8009A558: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009A55C: or          $t4, $v0, $at
    ctx->r12 = ctx->r2 | ctx->r1;
    // 0x8009A560: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
    // 0x8009A564: jal         0x800C484C
    // 0x8009A568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_9;
    // 0x8009A568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8009A56C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009A570: lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A574: lw          $t5, 0x6A74($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A74);
    // 0x8009A578: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009A57C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8009A580: beq         $at, $zero, L_8009AA30
    if (ctx->r1 == 0) {
        // 0x8009A584: addiu       $t6, $t6, 0x6AA8
        ctx->r14 = ADD32(ctx->r14, 0X6AA8);
            goto L_8009AA30;
    }
    // 0x8009A584: addiu       $t6, $t6, 0x6AA8
    ctx->r14 = ADD32(ctx->r14, 0X6AA8);
    // 0x8009A588: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8009A58C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8009A590: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009A594: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A598: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009A59C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009A5A0: addiu       $t3, $t3, 0x6AC0
    ctx->r11 = ADD32(ctx->r11, 0X6AC0);
    // 0x8009A5A4: addiu       $t9, $t9, 0x6AB8
    ctx->r25 = ADD32(ctx->r25, 0X6AB8);
    // 0x8009A5A8: addiu       $t7, $t7, 0x6AB0
    ctx->r15 = ADD32(ctx->r15, 0X6AB0);
    // 0x8009A5AC: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8009A5B0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A5B4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009A5B8: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8009A5BC: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8009A5C0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009A5C4: addiu       $s1, $s1, 0x1CD4
    ctx->r17 = ADD32(ctx->r17, 0X1CD4);
    // 0x8009A5C8: addiu       $s5, $s5, 0x23A0
    ctx->r21 = ADD32(ctx->r21, 0X23A0);
    // 0x8009A5CC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8009A5D0: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8009A5D4: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009A5D8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8009A5DC: addu        $fp, $v0, $t6
    ctx->r30 = ADD32(ctx->r2, ctx->r14);
    // 0x8009A5E0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8009A5E4: addiu       $s4, $zero, 0x3F
    ctx->r20 = ADD32(0, 0X3F);
    // 0x8009A5E8: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_8009A5EC:
    // 0x8009A5EC: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A5F0: jal         0x8006B3D0
    // 0x8009A5F4: nop

    leveltable_world(rdram, ctx);
        goto after_10;
    // 0x8009A5F4: nop

    after_10:
    // 0x8009A5F8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8009A5FC: bltz        $v1, L_8009A610
    if (SIGNED(ctx->r3) < 0) {
        // 0x8009A600: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8009A610;
    }
    // 0x8009A600: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8009A604: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8009A608: bne         $at, $zero, L_8009A614
    if (ctx->r1 != 0) {
        // 0x8009A60C: nop
    
            goto L_8009A614;
    }
    // 0x8009A60C: nop

L_8009A610:
    // 0x8009A610: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8009A614:
    // 0x8009A614: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A618: jal         0x8006C01C
    // 0x8009A61C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    level_name(rdram, ctx);
        goto after_11;
    // 0x8009A61C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    after_11:
    // 0x8009A620: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A624: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8009A628: beq         $t6, $zero, L_8009A678
    if (ctx->r14 == 0) {
        // 0x8009A62C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009A678;
    }
    // 0x8009A62C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A630: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A634: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8009A638: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8009A63C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A640:
    // 0x8009A640: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // 0x8009A644: bne         $at, $zero, L_8009A65C
    if (ctx->r1 != 0) {
        // 0x8009A648: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_8009A65C;
    }
    // 0x8009A648: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8009A64C: slti        $at, $v1, 0x7B
    ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
    // 0x8009A650: beq         $at, $zero, L_8009A65C
    if (ctx->r1 == 0) {
        // 0x8009A654: xori        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 ^ 0X20;
            goto L_8009A65C;
    }
    // 0x8009A654: xori        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 ^ 0X20;
    // 0x8009A658: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8009A65C:
    // 0x8009A65C: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    // 0x8009A660: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A664: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009A668: beq         $a1, $zero, L_8009A678
    if (ctx->r5 == 0) {
        // 0x8009A66C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8009A678;
    }
    // 0x8009A66C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8009A670: bne         $s0, $s4, L_8009A640
    if (ctx->r16 != ctx->r20) {
        // 0x8009A674: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_8009A640;
    }
    // 0x8009A674: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A678:
    // 0x8009A678: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8009A67C: addu        $t8, $s3, $s0
    ctx->r24 = ADD32(ctx->r19, ctx->r16);
    // 0x8009A680: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8009A684: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8009A688: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009A68C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009A690: lui         $at, 0x3F50
    ctx->r1 = S32(0X3F50 << 16);
    // 0x8009A694: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8009A698: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A69C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009A6A0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A6A4: lw          $a1, 0x1C74($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1C74);
    // 0x8009A6A8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009A6AC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8009A6B0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8009A6B4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009A6B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A6BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A6C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A6C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8009A6C8: jal         0x80079150
    // 0x8009A6CC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_12;
    // 0x8009A6CC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x8009A6D0: addiu       $t2, $zero, 0x34
    ctx->r10 = ADD32(0, 0X34);
    // 0x8009A6D4: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8009A6D8: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8009A6DC: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x8009A6E0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8009A6E4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8009A6E8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8009A6EC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8009A6F0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009A6F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A6F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A6FC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A700: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A704: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A708: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A70C: jal         0x800812E0
    // 0x8009A710: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    func_80080E90(rdram, ctx);
        goto after_13;
    // 0x8009A710: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_13:
    // 0x8009A714: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A718: lw          $t8, 0x6A38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A38);
    // 0x8009A71C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A720: lw          $v0, 0xD8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A724: bne         $t7, $t8, L_8009A75C
    if (ctx->r15 != ctx->r24) {
        // 0x8009A728: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8009A75C;
    }
    // 0x8009A728: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A72C: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x8009A730: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A734: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A738: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A73C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A740: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A744: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8009A748: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8009A74C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009A750: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009A754: jal         0x800812E0
    // 0x8009A758: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80080E90(rdram, ctx);
        goto after_14;
    // 0x8009A758: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_14:
L_8009A75C:
    // 0x8009A75C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A760: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009A764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A76C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A770: jal         0x800C48E4
    // 0x8009A774: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x8009A774: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_15:
    // 0x8009A778: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
L_8009A77C:
    // 0x8009A77C: addu        $v0, $s5, $t2
    ctx->r2 = ADD32(ctx->r21, ctx->r10);
    // 0x8009A780: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8009A784: lb          $t5, 0x1($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1);
    // 0x8009A788: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009A78C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8009A790: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8009A794: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A798: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8009A79C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A7A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009A7A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A7A8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A7AC: jal         0x800C49A0
    // 0x8009A7B0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8009A7B0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_16:
    // 0x8009A7B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A7B8: bne         $s0, $s6, L_8009A77C
    if (ctx->r16 != ctx->r22) {
        // 0x8009A7BC: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_8009A77C;
    }
    // 0x8009A7BC: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x8009A7C0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A7C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A7C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8009A7CC: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8009A7D0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8009A7D4: jal         0x800C48E4
    // 0x8009A7D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_17;
    // 0x8009A7D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_17:
    // 0x8009A7DC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8009A7E0: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x8009A7E4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A7E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A7EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A7F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A7F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A7F8: jal         0x800C49A0
    // 0x8009A7FC: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    draw_text(rdram, ctx);
        goto after_18;
    // 0x8009A7FC: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    after_18:
    // 0x8009A800: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8009A804: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A808: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8009A80C: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    // 0x8009A810: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8009A814: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8009A818: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x8009A81C: lw          $a1, 0x1070($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1070);
    // 0x8009A820: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A824: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009A828: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A82C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A830: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009A834: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009A838: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009A83C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A840: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A844: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x8009A848: jal         0x80078F08
    // 0x8009A84C: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    texrect_draw(rdram, ctx);
        goto after_19;
    // 0x8009A84C: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    after_19:
    // 0x8009A850: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8009A854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A858: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8009A85C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A860: beq         $v0, $at, L_8009A880
    if (ctx->r2 == ctx->r1) {
        // 0x8009A864: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8009A880;
    }
    // 0x8009A864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009A868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A86C: beq         $v0, $at, L_8009A88C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A870: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8009A88C;
    }
    // 0x8009A870: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A874: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A878: b           L_8009A890
    // 0x8009A87C: addiu       $a1, $a1, 0x9DC
    ctx->r5 = ADD32(ctx->r5, 0X9DC);
        goto L_8009A890;
    // 0x8009A87C: addiu       $a1, $a1, 0x9DC
    ctx->r5 = ADD32(ctx->r5, 0X9DC);
L_8009A880:
    // 0x8009A880: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A884: b           L_8009A890
    // 0x8009A888: addiu       $a1, $a1, 0x9F4
    ctx->r5 = ADD32(ctx->r5, 0X9F4);
        goto L_8009A890;
    // 0x8009A888: addiu       $a1, $a1, 0x9F4
    ctx->r5 = ADD32(ctx->r5, 0X9F4);
L_8009A88C:
    // 0x8009A88C: addiu       $a1, $a1, 0xA0C
    ctx->r5 = ADD32(ctx->r5, 0XA0C);
L_8009A890:
    // 0x8009A890: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x8009A894: lh          $t5, 0xA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XA);
    // 0x8009A898: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x8009A89C: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A8A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009A8A4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8009A8A8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A8AC: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x8009A8B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009A8B4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009A8B8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009A8BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8009A8C0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8009A8C4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A8C8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8009A8CC: jal         0x80079150
    // 0x8009A8D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_20;
    // 0x8009A8D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8009A8D4: jal         0x8007B820
    // 0x8009A8D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_21;
    // 0x8009A8D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_21:
    // 0x8009A8DC: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8009A8E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A8E4: addiu       $t9, $t8, -0x78
    ctx->r25 = ADD32(ctx->r24, -0X78);
    // 0x8009A8E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009A8EC: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x8009A8F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009A8F4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8009A8F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A8FC: swc1        $f8, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f8.u32l;
    // 0x8009A900: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x8009A904: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A908: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8009A90C: subu        $t4, $t3, $s2
    ctx->r12 = SUB32(ctx->r11, ctx->r18);
    // 0x8009A910: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009A914: addiu       $t7, $t6, 0x78
    ctx->r15 = ADD32(ctx->r14, 0X78);
    // 0x8009A918: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8009A91C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8009A920: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009A924: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A928: swc1        $f16, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f16.u32l;
    // 0x8009A92C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8009A930: lwc1        $f18, -0x7500($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7500);
    // 0x8009A934: jal         0x8009CFA4
    // 0x8009A938: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_22;
    // 0x8009A938: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    after_22:
    // 0x8009A93C: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009A940: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A944: sw          $t1, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r9;
    // 0x8009A948: lh          $t3, 0x12($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X12);
    // 0x8009A94C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A950: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A954: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8009A958: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x8009A95C: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A960: subu        $t5, $t4, $s2
    ctx->r13 = SUB32(ctx->r12, ctx->r18);
    // 0x8009A964: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8009A968: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
    // 0x8009A96C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A970: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009A974: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009A978: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009A97C: jal         0x80081C50
    // 0x8009A980: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    menu_timestamp_render(rdram, ctx);
        goto after_23;
    // 0x8009A980: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    after_23:
    // 0x8009A984: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A988: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A98C: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    // 0x8009A990: lh          $t9, 0x12($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X12);
    // 0x8009A994: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A998: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A99C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8009A9A0: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x8009A9A4: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A9A8: subu        $t2, $t1, $s2
    ctx->r10 = SUB32(ctx->r9, ctx->r18);
    // 0x8009A9AC: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009A9B0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009A9B4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A9B8: addiu       $a2, $a2, 0x79
    ctx->r6 = ADD32(ctx->r6, 0X79);
    // 0x8009A9BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009A9C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009A9C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A9C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A9CC: jal         0x80081C50
    // 0x8009A9D0: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    menu_timestamp_render(rdram, ctx);
        goto after_24;
    // 0x8009A9D0: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    after_24:
    // 0x8009A9D4: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8009A9D8: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A9DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009A9E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A9E4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8009A9E8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A9EC: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8009A9F0: lw          $t8, 0x6A74($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A74);
    // 0x8009A9F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009A9F8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8009A9FC: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8009AA00: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8009AA04: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009AA08: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009AA0C: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8009AA10: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8009AA14: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8009AA18: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8009AA1C: sw          $t6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r14;
    // 0x8009AA20: beq         $at, $zero, L_8009AA30
    if (ctx->r1 == 0) {
        // 0x8009AA24: addiu       $s2, $s2, 0x36
        ctx->r18 = ADD32(ctx->r18, 0X36);
            goto L_8009AA30;
    }
    // 0x8009AA24: addiu       $s2, $s2, 0x36
    ctx->r18 = ADD32(ctx->r18, 0X36);
    // 0x8009AA28: bgtz        $t6, L_8009A5EC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009AA2C: nop
    
            goto L_8009A5EC;
    }
    // 0x8009AA2C: nop

L_8009AA30:
    // 0x8009AA30: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AA34: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AA38: addiu       $s0, $s0, 0x6980
    ctx->r16 = ADD32(ctx->r16, 0X6980);
    // 0x8009AA3C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009AA40: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8009AA44: blez        $t2, L_8009ABD4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009AA48: sw          $t1, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r9;
            goto L_8009ABD4;
    }
    // 0x8009AA48: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
    // 0x8009AA4C: jal         0x800C5C30
    // 0x8009AA50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_25;
    // 0x8009AA50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
    // 0x8009AA54: jal         0x800C59F4
    // 0x8009AA58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_26;
    // 0x8009AA58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_26:
    // 0x8009AA5C: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8009AA60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009AA64: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA68: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x8009AA6C: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8009AA70: jal         0x800C543C
    // 0x8009AA74: addiu       $a3, $zero, 0xE4
    ctx->r7 = ADD32(0, 0XE4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_27;
    // 0x8009AA74: addiu       $a3, $zero, 0xE4
    ctx->r7 = ADD32(0, 0XE4);
    after_27:
    // 0x8009AA78: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009AA7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009AA80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AA88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AA8C: jal         0x800C551C
    // 0x8009AA90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_28;
    // 0x8009AA90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8009AA94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AA98: jal         0x800C54DC
    // 0x8009AA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_29;
    // 0x8009AA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009AAA0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AAA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AAAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009AAB0: jal         0x800C55B0
    // 0x8009AAB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_30;
    // 0x8009AAB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_30:
    // 0x8009AAB8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8009AABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009AAC0: bne         $t5, $at, L_8009AAF4
    if (ctx->r13 != ctx->r1) {
        // 0x8009AAC4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009AAF4;
    }
    // 0x8009AAC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAC8: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AACC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009AAD0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009AAD4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AAD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AADC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AAE0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AAE4: jal         0x800C5560
    // 0x8009AAE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    set_current_text_colour(rdram, ctx);
        goto after_31;
    // 0x8009AAE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_31:
    // 0x8009AAEC: b           L_8009AB10
    // 0x8009AAF0: nop

        goto L_8009AB10;
    // 0x8009AAF0: nop

L_8009AAF4:
    // 0x8009AAF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009AAF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009AAFC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB00: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB04: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB08: jal         0x800C5560
    // 0x8009AB0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_32;
    // 0x8009AB0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
L_8009AB10:
    // 0x8009AB10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009AB14: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009AB18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009AB1C: lw          $a3, 0x150($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X150);
    // 0x8009AB20: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009AB24: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009AB28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009AB2C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB30: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009AB34: jal         0x800C56C8
    // 0x8009AB38: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009AB38: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_33:
    // 0x8009AB3C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8009AB40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009AB44: bne         $t3, $at, L_8009AB78
    if (ctx->r11 != ctx->r1) {
        // 0x8009AB48: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009AB78;
    }
    // 0x8009AB48: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB4C: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x8009AB50: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009AB54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009AB58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009AB5C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB60: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB68: jal         0x800C5560
    // 0x8009AB6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_text_colour(rdram, ctx);
        goto after_34;
    // 0x8009AB6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_34:
    // 0x8009AB70: b           L_8009AB94
    // 0x8009AB74: nop

        goto L_8009AB94;
    // 0x8009AB74: nop

L_8009AB78:
    // 0x8009AB78: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009AB7C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009AB80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009AB84: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009AB88: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009AB8C: jal         0x800C5560
    // 0x8009AB90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_35;
    // 0x8009AB90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
L_8009AB94:
    // 0x8009AB94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009AB98: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009AB9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009ABA0: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x8009ABA4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009ABA8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009ABAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009ABB0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009ABB4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009ABB8: jal         0x800C56C8
    // 0x8009ABBC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    render_dialogue_text(rdram, ctx);
        goto after_36;
    // 0x8009ABBC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_36:
    // 0x8009ABC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009ABC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009ABC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009ABCC: jal         0x800C60B8
    // 0x8009ABD0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_37;
    // 0x8009ABD0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_37:
L_8009ABD4:
    // 0x8009ABD4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009ABD8: lw          $t1, 0x695C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X695C);
    // 0x8009ABDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009ABE0: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8009ABE4: beq         $t2, $zero, L_8009ACE0
    if (ctx->r10 == 0) {
        // 0x8009ABE8: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009ACE0;
    }
    // 0x8009ABE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009ABEC: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8009ABF0: lw          $t3, 0x6A74($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A74);
    // 0x8009ABF4: addiu       $t4, $v0, 0x3
    ctx->r12 = ADD32(ctx->r2, 0X3);
    // 0x8009ABF8: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8009ABFC: beq         $at, $zero, L_8009AC70
    if (ctx->r1 == 0) {
        // 0x8009AC00: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009AC70;
    }
    // 0x8009AC00: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009AC04: addiu       $s0, $s0, 0x9BC
    ctx->r16 = ADD32(ctx->r16, 0X9BC);
    // 0x8009AC08: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8009AC0C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009AC10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC14: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC18: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009AC1C: addiu       $a3, $s2, 0x3
    ctx->r7 = ADD32(ctx->r18, 0X3);
    // 0x8009AC20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009AC24: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009AC28: jal         0x80078F08
    // 0x8009AC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_38;
    // 0x8009AC2C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_38:
    // 0x8009AC30: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009AC34: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009AC38: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009AC3C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009AC40: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009AC44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009AC48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009AC4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009AC50: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC58: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009AC5C: jal         0x80078F08
    // 0x8009AC60: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    texrect_draw(rdram, ctx);
        goto after_39;
    // 0x8009AC60: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    after_39:
    // 0x8009AC64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009AC68: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8009AC6C: nop

L_8009AC70:
    // 0x8009AC70: blez        $v0, L_8009ACD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009AC74: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009ACD8;
    }
    // 0x8009AC74: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009AC78: addiu       $s0, $s0, 0x99C
    ctx->r16 = ADD32(ctx->r16, 0X99C);
    // 0x8009AC7C: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009AC80: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009AC84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009AC88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009AC8C: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009AC90: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x8009AC94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009AC98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009AC9C: jal         0x80078F08
    // 0x8009ACA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_40;
    // 0x8009ACA0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_40:
    // 0x8009ACA4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009ACA8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009ACAC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8009ACB0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009ACB4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009ACB8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8009ACBC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009ACC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009ACC4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009ACC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009ACCC: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009ACD0: jal         0x80078F08
    // 0x8009ACD4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_41;
    // 0x8009ACD4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_41:
L_8009ACD8:
    // 0x8009ACD8: jal         0x8007B820
    // 0x8009ACDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_42;
    // 0x8009ACDC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_42:
L_8009ACE0:
    // 0x8009ACE0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8009ACE4:
    // 0x8009ACE4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8009ACE8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8009ACEC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8009ACF0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8009ACF4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8009ACF8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8009ACFC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8009AD00: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8009AD04: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8009AD08: jr          $ra
    // 0x8009AD0C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8009AD0C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void menu_ghost_data_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AD14: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009AD18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AD1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AD20: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x8009AD24: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8009AD28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009AD2C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8009AD30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009AD34: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8009AD38: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8009AD3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009AD40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009AD44: bne         $at, $zero, L_8009AD70
    if (ctx->r1 != 0) {
        // 0x8009AD48: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8009AD70;
    }
    // 0x8009AD48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8009AD4C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8009AD50: beq         $at, $zero, L_8009AD70
    if (ctx->r1 == 0) {
        // 0x8009AD54: nop
    
            goto L_8009AD70;
    }
    // 0x8009AD54: nop

    // 0x8009AD58: jal         0x8009A3C8
    // 0x8009AD5C: nop

    ghostmenu_render(rdram, ctx);
        goto after_0;
    // 0x8009AD5C: nop

    after_0:
    // 0x8009AD60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AD64: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AD68: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AD6C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8009AD70:
    // 0x8009AD70: beq         $v0, $zero, L_8009AD90
    if (ctx->r2 == 0) {
        // 0x8009AD74: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8009AD90;
    }
    // 0x8009AD74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009AD78: bgez        $v0, L_8009AD8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009AD7C: addu        $t2, $v0, $s0
        ctx->r10 = ADD32(ctx->r2, ctx->r16);
            goto L_8009AD8C;
    }
    // 0x8009AD7C: addu        $t2, $v0, $s0
    ctx->r10 = ADD32(ctx->r2, ctx->r16);
    // 0x8009AD80: subu        $t9, $v0, $s0
    ctx->r25 = SUB32(ctx->r2, ctx->r16);
    // 0x8009AD84: b           L_8009AD90
    // 0x8009AD88: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_8009AD90;
    // 0x8009AD88: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8009AD8C:
    // 0x8009AD8C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8009AD90:
    // 0x8009AD90: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009AD94: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x8009AD98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009AD9C: bne         $t3, $zero, L_8009AE20
    if (ctx->r11 != 0) {
        // 0x8009ADA0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8009AE20;
    }
    // 0x8009ADA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8009ADA4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8009ADA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009ADAC: bne         $t4, $zero, L_8009AE20
    if (ctx->r12 != 0) {
        // 0x8009ADB0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009AE20;
    }
    // 0x8009ADB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009ADB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009ADB8: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8009ADBC: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8009ADC0:
    // 0x8009ADC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009ADC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8009ADC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009ADCC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8009ADD0: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8009ADD4: jal         0x8006A794
    // 0x8009ADD8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8009ADD8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8009ADDC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009ADE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009ADE4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009ADE8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8009ADEC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8009ADF0: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8009ADF4: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8009ADF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009ADFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009AE00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009AE04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009AE08: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x8009AE0C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8009AE10: bne         $s0, $at, L_8009ADC0
    if (ctx->r16 != ctx->r1) {
        // 0x8009AE14: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_8009ADC0;
    }
    // 0x8009AE14: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8009AE18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009AE1C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8009AE20:
    // 0x8009AE20: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009AE24: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8009AE28: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009AE2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AE30: beq         $v0, $zero, L_8009AE5C
    if (ctx->r2 == 0) {
        // 0x8009AE34: nop
    
            goto L_8009AE5C;
    }
    // 0x8009AE34: nop

    // 0x8009AE38: beq         $v0, $v1, L_8009AF74
    if (ctx->r2 == ctx->r3) {
        // 0x8009AE3C: andi        $t3, $a3, 0x4000
        ctx->r11 = ctx->r7 & 0X4000;
            goto L_8009AF74;
    }
    // 0x8009AE3C: andi        $t3, $a3, 0x4000
    ctx->r11 = ctx->r7 & 0X4000;
    // 0x8009AE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009AE44: beq         $v0, $at, L_8009B074
    if (ctx->r2 == ctx->r1) {
        // 0x8009AE48: andi        $t8, $a3, 0xD000
        ctx->r24 = ctx->r7 & 0XD000;
            goto L_8009B074;
    }
    // 0x8009AE48: andi        $t8, $a3, 0xD000
    ctx->r24 = ctx->r7 & 0XD000;
    // 0x8009AE4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AE50: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AE54: b           L_8009B0B0
    // 0x8009AE58: nop

        goto L_8009B0B0;
    // 0x8009AE58: nop

L_8009AE5C:
    // 0x8009AE5C: andi        $v0, $a3, 0x9000
    ctx->r2 = ctx->r7 & 0X9000;
    // 0x8009AE60: beq         $v0, $zero, L_8009AE90
    if (ctx->r2 == 0) {
        // 0x8009AE64: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8009AE90;
    }
    // 0x8009AE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AE68: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AE6C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009AE70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009AE74: blez        $t7, L_8009AE90
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009AE78: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009AE90;
    }
    // 0x8009AE78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009AE7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8009AE80: jal         0x80001D04
    // 0x8009AE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8009AE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009AE88: b           L_8009AF64
    // 0x8009AE8C: nop

        goto L_8009AF64;
    // 0x8009AE8C: nop

L_8009AE90:
    // 0x8009AE90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AE94: andi        $t9, $a3, 0x4000
    ctx->r25 = ctx->r7 & 0X4000;
    // 0x8009AE98: bne         $t9, $zero, L_8009AEB4
    if (ctx->r25 != 0) {
        // 0x8009AE9C: addiu       $a1, $a1, 0x6A74
        ctx->r5 = ADD32(ctx->r5, 0X6A74);
            goto L_8009AEB4;
    }
    // 0x8009AE9C: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AEA0: beq         $v0, $zero, L_8009AEDC
    if (ctx->r2 == 0) {
        // 0x8009AEA4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009AEDC;
    }
    // 0x8009AEA4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AEA8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8009AEAC: nop

    // 0x8009AEB0: bne         $t2, $zero, L_8009AEDC
    if (ctx->r10 != 0) {
        // 0x8009AEB4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009AEDC;
    }
L_8009AEB4:
    // 0x8009AEB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AEB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009AEBC: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8009AEC0: jal         0x800C06F8
    // 0x8009AEC4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8009AEC4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x8009AEC8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AECC: jal         0x80001D04
    // 0x8009AED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8009AED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8009AED4: b           L_8009AF64
    // 0x8009AED8: nop

        goto L_8009AF64;
    // 0x8009AED8: nop

L_8009AEDC:
    // 0x8009AEDC: addiu       $s0, $s0, 0x6A38
    ctx->r16 = ADD32(ctx->r16, 0X6A38);
    // 0x8009AEE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AEE4: bgez        $t0, L_8009AF28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009AEE8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8009AF28;
    }
    // 0x8009AEE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009AEEC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8009AEF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AEF4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8009AEF8: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009AEFC: beq         $at, $zero, L_8009AF28
    if (ctx->r1 == 0) {
        // 0x8009AF00: addiu       $v1, $v1, 0x6978
        ctx->r3 = ADD32(ctx->r3, 0X6978);
            goto L_8009AF28;
    }
    // 0x8009AF00: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AF04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AF08: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8009AF0C: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8009AF10: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009AF14: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009AF18: bne         $at, $zero, L_8009AF28
    if (ctx->r1 != 0) {
        // 0x8009AF1C: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8009AF28;
    }
    // 0x8009AF1C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8009AF20: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x8009AF24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009AF28:
    // 0x8009AF28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AF2C: blez        $t0, L_8009AF54
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009AF30: addiu       $v1, $v1, 0x6978
        ctx->r3 = ADD32(ctx->r3, 0X6978);
            goto L_8009AF54;
    }
    // 0x8009AF30: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AF34: blez        $v0, L_8009AF54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009AF38: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8009AF54;
    }
    // 0x8009AF38: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8009AF3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8009AF40: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009AF44: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009AF48: beq         $at, $zero, L_8009AF54
    if (ctx->r1 == 0) {
        // 0x8009AF4C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8009AF54;
    }
    // 0x8009AF4C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009AF50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8009AF54:
    // 0x8009AF54: beq         $a0, $v0, L_8009AF64
    if (ctx->r4 == ctx->r2) {
        // 0x8009AF58: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009AF64;
    }
    // 0x8009AF58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AF5C: jal         0x80001D04
    // 0x8009AF60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8009AF60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_5:
L_8009AF64:
    // 0x8009AF64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AF68: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009AF6C: b           L_8009B0B0
    // 0x8009AF70: nop

        goto L_8009B0B0;
    // 0x8009AF70: nop

L_8009AF74:
    // 0x8009AF74: beq         $t3, $zero, L_8009AF94
    if (ctx->r11 == 0) {
        // 0x8009AF78: andi        $t4, $a3, 0x9000
        ctx->r12 = ctx->r7 & 0X9000;
            goto L_8009AF94;
    }
    // 0x8009AF78: andi        $t4, $a3, 0x9000
    ctx->r12 = ctx->r7 & 0X9000;
    // 0x8009AF7C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009AF80: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AF84: jal         0x80001D04
    // 0x8009AF88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8009AF88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8009AF8C: b           L_8009B064
    // 0x8009AF90: nop

        goto L_8009B064;
    // 0x8009AF90: nop

L_8009AF94:
    // 0x8009AF94: beq         $t4, $zero, L_8009B04C
    if (ctx->r12 == 0) {
        // 0x8009AF98: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009B04C;
    }
    // 0x8009AF98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AF9C: addiu       $s0, $s0, 0x6A38
    ctx->r16 = ADD32(ctx->r16, 0X6A38);
    // 0x8009AFA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009AFA4: jal         0x80099E1C
    // 0x8009AFA8: nop

    ghostmenu_erase(rdram, ctx);
        goto after_7;
    // 0x8009AFA8: nop

    after_7:
    // 0x8009AFAC: bne         $v0, $zero, L_8009B01C
    if (ctx->r2 != 0) {
        // 0x8009AFB0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009B01C;
    }
    // 0x8009AFB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AFB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AFB8: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x8009AFBC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8009AFC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AFC4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009AFC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8009AFCC: bne         $at, $zero, L_8009AFDC
    if (ctx->r1 != 0) {
        // 0x8009AFD0: nop
    
            goto L_8009AFDC;
    }
    // 0x8009AFD0: nop

    // 0x8009AFD4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8009AFD8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8009AFDC:
    // 0x8009AFDC: bgez        $v0, L_8009AFEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009AFE0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009AFEC;
    }
    // 0x8009AFE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AFE4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009AFE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009AFEC:
    // 0x8009AFEC: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009AFF0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AFF4: nop

    // 0x8009AFF8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AFFC: beq         $at, $zero, L_8009B008
    if (ctx->r1 == 0) {
        // 0x8009B000: nop
    
            goto L_8009B008;
    }
    // 0x8009B000: nop

    // 0x8009B004: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8009B008:
    // 0x8009B008: jal         0x80001D04
    // 0x8009B00C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009B00C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009B010: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B014: b           L_8009B044
    // 0x8009B018: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
        goto L_8009B044;
    // 0x8009B018: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
L_8009B01C:
    // 0x8009B01C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B020: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B024: sw          $v1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r3;
    // 0x8009B028: jal         0x800C06F8
    // 0x8009B02C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x8009B02C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_9:
    // 0x8009B030: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009B034: jal         0x80001D04
    // 0x8009B038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8009B038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8009B03C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B040: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
L_8009B044:
    // 0x8009B044: b           L_8009B064
    // 0x8009B048: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8009B064;
    // 0x8009B048: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009B04C:
    // 0x8009B04C: bgez        $t0, L_8009B064
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009B050: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8009B064;
    }
    // 0x8009B050: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009B054: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8009B058: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009B05C: jal         0x80001D04
    // 0x8009B060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8009B060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_8009B064:
    // 0x8009B064: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B068: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009B06C: b           L_8009B0B0
    // 0x8009B070: nop

        goto L_8009B0B0;
    // 0x8009B070: nop

L_8009B074:
    // 0x8009B074: beq         $t8, $zero, L_8009B090
    if (ctx->r24 == 0) {
        // 0x8009B078: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009B090;
    }
    // 0x8009B078: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009B07C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009B080: jal         0x80001D04
    // 0x8009B084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8009B084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8009B088: b           L_8009B0A4
    // 0x8009B08C: nop

        goto L_8009B0A4;
    // 0x8009B08C: nop

L_8009B090:
    // 0x8009B090: blez        $t0, L_8009B0A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009B094: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8009B0A4;
    }
    // 0x8009B094: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009B098: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8009B09C: jal         0x80001D04
    // 0x8009B0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x8009B0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_8009B0A4:
    // 0x8009B0A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B0A8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009B0AC: nop

L_8009B0B0:
    // 0x8009B0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B0B4: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8009B0B8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8009B0BC: bne         $at, $zero, L_8009B0D8
    if (ctx->r1 != 0) {
        // 0x8009B0C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009B0D8;
    }
    // 0x8009B0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B0C4: jal         0x8009B0E8
    // 0x8009B0C8: nop

    ghostmenu_free(rdram, ctx);
        goto after_14;
    // 0x8009B0C8: nop

    after_14:
    // 0x8009B0CC: jal         0x80081820
    // 0x8009B0D0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x8009B0D0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_15:
    // 0x8009B0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B0D8:
    // 0x8009B0D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B0DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8009B0E0: jr          $ra
    // 0x8009B0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009B0E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ghostmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B0F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B0F4: jal         0x8009C9EC
    // 0x8009B0F8: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009B0F8: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    after_0:
    // 0x8009B0FC: jal         0x800C478C
    // 0x8009B100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8009B100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8009B104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B10C: jr          $ra
    // 0x8009B110: nop

    return;
    // 0x8009B110: nop

;}
RECOMP_FUNC void cinematic_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009B118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B11C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009B128: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009B12C: blez        $a1, L_8009B160
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009B130: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009B160;
    }
    // 0x8009B130: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009B134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009B138:
    // 0x8009B138: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8009B13C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009B140: beq         $v0, $t6, L_8009B158
    if (ctx->r2 == ctx->r14) {
        // 0x8009B144: nop
    
            goto L_8009B158;
    }
    // 0x8009B144: nop

L_8009B148:
    // 0x8009B148: lb          $t7, 0x3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X3);
    // 0x8009B14C: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x8009B150: bne         $v0, $t7, L_8009B148
    if (ctx->r2 != ctx->r15) {
        // 0x8009B154: nop
    
            goto L_8009B148;
    }
    // 0x8009B154: nop

L_8009B158:
    // 0x8009B158: bne         $v1, $a1, L_8009B138
    if (ctx->r3 != ctx->r5) {
        // 0x8009B15C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009B138;
    }
    // 0x8009B15C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8009B160:
    // 0x8009B160: bne         $v1, $zero, L_8009B184
    if (ctx->r3 != 0) {
        // 0x8009B164: nop
    
            goto L_8009B184;
    }
    // 0x8009B164: nop

    // 0x8009B168: jal         0x8001E2D0
    // 0x8009B16C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009B16C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x8009B170: bne         $v0, $s0, L_8009B184
    if (ctx->r2 != ctx->r16) {
        // 0x8009B174: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009B184;
    }
    // 0x8009B174: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009B178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B17C: b           L_8009B18C
    // 0x8009B180: sw          $t8, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = ctx->r24;
        goto L_8009B18C;
    // 0x8009B180: sw          $t8, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = ctx->r24;
L_8009B184:
    // 0x8009B184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B188: sw          $zero, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = 0;
L_8009B18C:
    // 0x8009B18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B190: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009B194: sw          $s0, 0x6D8C($at)
    MEM_W(0X6D8C, ctx->r1) = ctx->r16;
    // 0x8009B198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B19C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B1A0: sw          $t9, 0x6DC4($at)
    MEM_W(0X6DC4, ctx->r1) = ctx->r25;
    // 0x8009B1A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8009B1AC: sw          $t0, 0x6DDC($at)
    MEM_W(0X6DDC, ctx->r1) = ctx->r8;
    // 0x8009B1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1B4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8009B1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B1BC: sw          $t1, 0x6DE4($at)
    MEM_W(0X6DE4, ctx->r1) = ctx->r9;
    // 0x8009B1C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B1C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B1C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009B1CC: jr          $ra
    // 0x8009B1D0: sw          $t2, 0x6DA4($at)
    MEM_W(0X6DA4, ctx->r1) = ctx->r10;
    return;
    // 0x8009B1D0: sw          $t2, 0x6DA4($at)
    MEM_W(0X6DA4, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void menu_cinematic_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B1D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B1D8: lw          $t6, 0x6DA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6DA4);
    // 0x8009B1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B1E0: beq         $t6, $zero, L_8009B1FC
    if (ctx->r14 == 0) {
        // 0x8009B1E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009B1FC;
    }
    // 0x8009B1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B1E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B1EC: jal         0x8009CBB8
    // 0x8009B1F0: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x8009B1F0: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    after_0:
    // 0x8009B1F4: jal         0x80094B08
    // 0x8009B1F8: nop

    menu_racer_portraits(rdram, ctx);
        goto after_1;
    // 0x8009B1F8: nop

    after_1:
L_8009B1FC:
    // 0x8009B1FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B200: lw          $v0, 0x6D8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D8C);
    // 0x8009B204: nop

    // 0x8009B208: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009B20C: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x8009B210: lb          $a2, 0x2($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2);
    // 0x8009B214: jal         0x8006E528
    // 0x8009B218: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009B218: nop

    after_2:
    // 0x8009B21C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B224: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009B228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B22C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009B230: jr          $ra
    // 0x8009B234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009B234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_cinematic_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B238: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009B23C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B240: lw          $t6, 0x6964($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6964);
    // 0x8009B244: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8009B248: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8009B24C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8009B250: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8009B254: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8009B258: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8009B25C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8009B260: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009B264: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8009B268: bne         $t6, $zero, L_8009B2A4
    if (ctx->r14 != 0) {
        // 0x8009B26C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8009B2A4;
    }
    // 0x8009B26C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009B270: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009B274: addiu       $s1, $s1, -0x5C4
    ctx->r17 = ADD32(ctx->r17, -0X5C4);
    // 0x8009B278: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009B27C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009B280: blez        $t7, L_8009B2A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009B284: nop
    
            goto L_8009B2A4;
    }
    // 0x8009B284: nop

L_8009B288:
    // 0x8009B288: jal         0x8006A794
    // 0x8009B28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8009B28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009B290: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009B294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009B298: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009B29C: bne         $at, $zero, L_8009B288
    if (ctx->r1 != 0) {
        // 0x8009B2A0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009B288;
    }
    // 0x8009B2A0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_8009B2A4:
    // 0x8009B2A4: jal         0x800214F8
    // 0x8009B2A8: nop

    func_800214C4(rdram, ctx);
        goto after_1;
    // 0x8009B2A8: nop

    after_1:
    // 0x8009B2AC: beq         $v0, $zero, L_8009B320
    if (ctx->r2 == 0) {
        // 0x8009B2B0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009B320;
    }
    // 0x8009B2B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009B2B4: addiu       $v1, $v1, 0x6D8C
    ctx->r3 = ADD32(ctx->r3, 0X6D8C);
    // 0x8009B2B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009B2BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009B2C0: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x8009B2C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8009B2C8: lb          $a0, 0x0($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X0);
    // 0x8009B2CC: nop

    // 0x8009B2D0: bltz        $a0, L_8009B2F0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009B2D4: nop
    
            goto L_8009B2F0;
    }
    // 0x8009B2D4: nop

    // 0x8009B2D8: lb          $a1, 0x1($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1);
    // 0x8009B2DC: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8009B2E0: jal         0x8006E528
    // 0x8009B2E4: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009B2E4: nop

    after_2:
    // 0x8009B2E8: b           L_8009B320
    // 0x8009B2EC: nop

        goto L_8009B320;
    // 0x8009B2EC: nop

L_8009B2F0:
    // 0x8009B2F0: lw          $t1, 0x6DEC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6DEC);
    // 0x8009B2F4: nop

    // 0x8009B2F8: beq         $t1, $zero, L_8009B308
    if (ctx->r9 == 0) {
        // 0x8009B2FC: nop
    
            goto L_8009B308;
    }
    // 0x8009B2FC: nop

    // 0x8009B300: jal         0x80000B18
    // 0x8009B304: nop

    music_change_off(rdram, ctx);
        goto after_3;
    // 0x8009B304: nop

    after_3:
L_8009B308:
    // 0x8009B308: jal         0x8009B454
    // 0x8009B30C: nop

    cinematic_free(rdram, ctx);
        goto after_4;
    // 0x8009B30C: nop

    after_4:
    // 0x8009B310: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B314: lw          $v0, 0x6DC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6DC4);
    // 0x8009B318: b           L_8009B430
    // 0x8009B31C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B31C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B320:
    // 0x8009B320: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009B324: addiu       $s0, $s0, 0x6DDC
    ctx->r16 = ADD32(ctx->r16, 0X6DDC);
    // 0x8009B328: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009B32C: andi        $t3, $s2, 0x9000
    ctx->r11 = ctx->r18 & 0X9000;
    // 0x8009B330: beq         $t2, $zero, L_8009B354
    if (ctx->r10 == 0) {
        // 0x8009B334: nop
    
            goto L_8009B354;
    }
    // 0x8009B334: nop

    // 0x8009B338: beq         $t3, $zero, L_8009B354
    if (ctx->r11 == 0) {
        // 0x8009B33C: nop
    
            goto L_8009B354;
    }
    // 0x8009B33C: nop

    // 0x8009B340: jal         0x8009B454
    // 0x8009B344: nop

    cinematic_free(rdram, ctx);
        goto after_5;
    // 0x8009B344: nop

    after_5:
    // 0x8009B348: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009B34C: b           L_8009B430
    // 0x8009B350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B354:
    // 0x8009B354: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009B358: addiu       $s0, $s0, 0x6DE4
    ctx->r16 = ADD32(ctx->r16, 0X6DE4);
    // 0x8009B35C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8009B360: nop

    // 0x8009B364: beq         $t4, $zero, L_8009B388
    if (ctx->r12 == 0) {
        // 0x8009B368: andi        $t5, $s2, 0x4000
        ctx->r13 = ctx->r18 & 0X4000;
            goto L_8009B388;
    }
    // 0x8009B368: andi        $t5, $s2, 0x4000
    ctx->r13 = ctx->r18 & 0X4000;
    // 0x8009B36C: beq         $t5, $zero, L_8009B388
    if (ctx->r13 == 0) {
        // 0x8009B370: nop
    
            goto L_8009B388;
    }
    // 0x8009B370: nop

    // 0x8009B374: jal         0x8009B454
    // 0x8009B378: nop

    cinematic_free(rdram, ctx);
        goto after_6;
    // 0x8009B378: nop

    after_6:
    // 0x8009B37C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009B380: b           L_8009B430
    // 0x8009B384: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009B430;
    // 0x8009B384: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B388:
    // 0x8009B388: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009B38C: addiu       $s3, $s3, 0x6DA4
    ctx->r19 = ADD32(ctx->r19, 0X6DA4);
    // 0x8009B390: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8009B394: nop

    // 0x8009B398: beq         $v0, $zero, L_8009B420
    if (ctx->r2 == 0) {
        // 0x8009B39C: nop
    
            goto L_8009B420;
    }
    // 0x8009B39C: nop

    // 0x8009B3A0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009B3A4: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8009B3A8: beq         $s4, $t6, L_8009B420
    if (ctx->r20 == ctx->r14) {
        // 0x8009B3AC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009B420;
    }
    // 0x8009B3AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009B3B0: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009B3B4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8009B3B8: lb          $s1, 0x0($v0)
    ctx->r17 = MEM_B(ctx->r2, 0X0);
    // 0x8009B3BC: addiu       $s5, $s5, 0x693C
    ctx->r21 = ADD32(ctx->r21, 0X693C);
    // 0x8009B3C0: addiu       $s6, $s6, 0x1070
    ctx->r22 = ADD32(ctx->r22, 0X1070);
    // 0x8009B3C4: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x8009B3C8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009B3CC:
    // 0x8009B3CC: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8009B3D0: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8009B3D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009B3D8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009B3DC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009B3E0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009B3E4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009B3E8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009B3EC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009B3F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B3F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8009B3F8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8009B3FC: jal         0x80078F08
    // 0x8009B400: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    texrect_draw(rdram, ctx);
        goto after_7;
    // 0x8009B400: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
    // 0x8009B404: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8009B408: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009B40C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8009B410: lb          $s1, 0x0($t4)
    ctx->r17 = MEM_B(ctx->r12, 0X0);
    // 0x8009B414: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8009B418: bne         $s4, $s1, L_8009B3CC
    if (ctx->r20 != ctx->r17) {
        // 0x8009B41C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8009B3CC;
    }
    // 0x8009B41C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009B420:
    // 0x8009B420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B424: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8009B428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009B42C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009B430:
    // 0x8009B430: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009B434: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B438: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8009B43C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009B440: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009B444: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8009B448: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8009B44C: jr          $ra
    // 0x8009B450: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009B450: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void cinematic_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B454: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009B458: lw          $t6, 0x6DA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6DA4);
    // 0x8009B45C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B460: beq         $t6, $zero, L_8009B474
    if (ctx->r14 == 0) {
        // 0x8009B464: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009B474;
    }
    // 0x8009B464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B468: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B46C: jal         0x8009C9EC
    // 0x8009B470: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009B470: addiu       $a0, $a0, 0x1CE8
    ctx->r4 = ADD32(ctx->r4, 0X1CE8);
    after_0:
L_8009B474:
    // 0x8009B474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B47C: jr          $ra
    // 0x8009B480: nop

    return;
    // 0x8009B480: nop

;}
RECOMP_FUNC void menu_credits_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009B488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B48C: jal         0x8006ECD0
    // 0x8009B490: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009B490: nop

    after_0:
    // 0x8009B494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B498: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009B49C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4A0: sw          $zero, 0x7184($at)
    MEM_W(0X7184, ctx->r1) = 0;
    // 0x8009B4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4A8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x8009B4AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4B0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8009B4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4B8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009B4BC: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8009B4C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B4C4: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8009B4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4CC: sw          $zero, 0x7190($at)
    MEM_W(0X7190, ctx->r1) = 0;
    // 0x8009B4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4D4: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
    // 0x8009B4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B4DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009B4E0: sw          $zero, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = 0;
    // 0x8009B4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B4E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B4EC: jal         0x80077FAC
    // 0x8009B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_fillcolour(rdram, ctx);
        goto after_1;
    // 0x8009B4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8009B4F4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009B4F8: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009B4FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B500: bne         $t7, $zero, L_8009B548
    if (ctx->r15 != 0) {
        // 0x8009B504: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009B548;
    }
    // 0x8009B504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B508: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x8009B50C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009B510: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009B518: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8009B51C: jal         0x80066B80
    // 0x8009B520: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_2;
    // 0x8009B520: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x8009B524: addiu       $t9, $zero, 0x11C
    ctx->r25 = ADD32(0, 0X11C);
    // 0x8009B528: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B52C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B530: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009B534: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009B538: jal         0x80066CE8
    // 0x8009B53C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009B53C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x8009B540: b           L_8009B578
    // 0x8009B544: nop

        goto L_8009B578;
    // 0x8009B544: nop

L_8009B548:
    // 0x8009B548: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x8009B54C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009B550: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8009B554: jal         0x80066B80
    // 0x8009B558: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_4;
    // 0x8009B558: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
    // 0x8009B55C: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x8009B560: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009B564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B568: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009B56C: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009B570: jal         0x80066CE8
    // 0x8009B574: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_5;
    // 0x8009B574: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_5:
L_8009B578:
    // 0x8009B578: jal         0x80066850
    // 0x8009B57C: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_6;
    // 0x8009B57C: nop

    after_6:
    // 0x8009B580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B584: jal         0x80066A58
    // 0x8009B588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x8009B588: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8009B58C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B590: jal         0x8009CBB8
    // 0x8009B594: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    menu_assetgroup_load(rdram, ctx);
        goto after_8;
    // 0x8009B594: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    after_8:
    // 0x8009B598: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B59C: jal         0x8009CDE8
    // 0x8009B5A0: addiu       $a0, $a0, 0x1D70
    ctx->r4 = ADD32(ctx->r4, 0X1D70);
    menu_imagegroup_load(rdram, ctx);
        goto after_9;
    // 0x8009B5A0: addiu       $a0, $a0, 0x1D70
    ctx->r4 = ADD32(ctx->r4, 0X1D70);
    after_9:
    // 0x8009B5A4: jal         0x80094B08
    // 0x8009B5A8: nop

    menu_racer_portraits(rdram, ctx);
        goto after_10;
    // 0x8009B5A8: nop

    after_10:
    // 0x8009B5AC: jal         0x800C46D0
    // 0x8009B5B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_11;
    // 0x8009B5B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8009B5B4: jal         0x80000BE0
    // 0x8009B5B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x8009B5B8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x8009B5BC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009B5C0: lw          $t3, 0x20CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20CC);
    // 0x8009B5C4: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8009B5C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B5CC: beq         $t3, $zero, L_8009B610
    if (ctx->r11 == 0) {
        // 0x8009B5D0: sh          $t2, 0x1E78($at)
        MEM_H(0X1E78, ctx->r1) = ctx->r10;
            goto L_8009B610;
    }
    // 0x8009B5D0: sh          $t2, 0x1E78($at)
    MEM_H(0X1E78, ctx->r1) = ctx->r10;
    // 0x8009B5D4: jal         0x80000B34
    // 0x8009B5D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_13;
    // 0x8009B5D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8009B5DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B5E0: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B5E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B5E8: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B5EC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8009B5F0: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8009B5F4: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009B5F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B5FC: sw          $t4, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r12;
    // 0x8009B600: sw          $t5, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r13;
    // 0x8009B604: sw          $t6, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r14;
    // 0x8009B608: b           L_8009B700
    // 0x8009B60C: sw          $zero, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = 0;
        goto L_8009B700;
    // 0x8009B60C: sw          $zero, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = 0;
L_8009B610:
    // 0x8009B610: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009B614: nop

    // 0x8009B618: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x8009B61C: nop

    // 0x8009B620: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8009B624: beq         $t9, $zero, L_8009B668
    if (ctx->r25 == 0) {
        // 0x8009B628: nop
    
            goto L_8009B668;
    }
    // 0x8009B628: nop

    // 0x8009B62C: jal         0x80000B34
    // 0x8009B630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    music_play(rdram, ctx);
        goto after_14;
    // 0x8009B630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_14:
    // 0x8009B634: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B638: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B63C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8009B640: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B644: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B648: addiu       $t1, $zero, 0x61F4
    ctx->r9 = ADD32(0, 0X61F4);
    // 0x8009B64C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B650: sw          $t0, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r8;
    // 0x8009B654: sh          $t1, 0x1E78($at)
    MEM_H(0X1E78, ctx->r1) = ctx->r9;
    // 0x8009B658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B65C: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8009B660: b           L_8009B688
    // 0x8009B664: sw          $t2, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r10;
        goto L_8009B688;
    // 0x8009B664: sw          $t2, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r10;
L_8009B668:
    // 0x8009B668: jal         0x80000B34
    // 0x8009B66C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_15;
    // 0x8009B66C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_15:
    // 0x8009B670: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B674: addiu       $v0, $v0, 0x2064
    ctx->r2 = ADD32(ctx->r2, 0X2064);
    // 0x8009B678: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8009B67C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B680: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B684: sw          $t3, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r11;
L_8009B688:
    // 0x8009B688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B68C: jal         0x8006FB8C
    // 0x8009B690: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x8009B690: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_16:
    // 0x8009B694: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8009B698: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B69C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8009B6A0: lw          $v1, 0x2078($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2078);
    // 0x8009B6A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B6A8: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8009B6AC: beq         $v1, $zero, L_8009B6C4
    if (ctx->r3 == 0) {
        // 0x8009B6B0: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8009B6C4;
    }
    // 0x8009B6B0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8009B6B4:
    // 0x8009B6B4: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8009B6B8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8009B6BC: bne         $t5, $zero, L_8009B6B4
    if (ctx->r13 != 0) {
        // 0x8009B6C0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B6B4;
    }
    // 0x8009B6C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B6C4:
    // 0x8009B6C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B6C8: lw          $v0, 0x71F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71F0);
    // 0x8009B6CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8009B6D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8009B6D4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8009B6D8: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    // 0x8009B6DC: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x8009B6E0: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x8009B6E4: nop

    // 0x8009B6E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009B6EC: sw          $t9, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r25;
    // 0x8009B6F0: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x8009B6F4: nop

    // 0x8009B6F8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8009B6FC: sw          $t1, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r9;
L_8009B700:
    // 0x8009B700: jal         0x80000B18
    // 0x8009B704: nop

    music_change_off(rdram, ctx);
        goto after_17;
    // 0x8009B704: nop

    after_17:
    // 0x8009B708: jal         0x800C0690
    // 0x8009B70C: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_18;
    // 0x8009B70C: nop

    after_18:
    // 0x8009B710: jal         0x8006F7A4
    // 0x8009B714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_19;
    // 0x8009B714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009B718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B71C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009B720: jr          $ra
    // 0x8009B724: nop

    return;
    // 0x8009B724: nop

;}
RECOMP_FUNC void credits_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B72C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009B730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B734: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8009B738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009B73C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009B740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009B744: bne         $at, $zero, L_8009B754
    if (ctx->r1 != 0) {
        // 0x8009B748: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8009B754;
    }
    // 0x8009B748: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009B74C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009B750: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_8009B754:
    // 0x8009B754: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8009B758: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009B75C: bgez        $t2, L_8009B768
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009B760: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_8009B768;
    }
    // 0x8009B760: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009B764: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8009B768:
    // 0x8009B768: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B76C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009B770: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009B774: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009B778: addiu       $t9, $t9, 0x1D00
    ctx->r25 = ADD32(ctx->r25, 0X1D00);
    // 0x8009B77C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8009B780: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009B784: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009B788: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B78C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8009B790: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009B794: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8009B798: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8009B79C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B7A0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009B7A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B7A8: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x8009B7AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B7B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B7B4: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8009B7B8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8009B7BC: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x8009B7C0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009B7C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009B7C8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8009B7CC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8009B7D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B7D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B7D8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8009B7DC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B7E0: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B7E4: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8009B7E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009B7EC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009B7F0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8009B7F4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B7F8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B7FC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009B800: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B804: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x8009B808: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8009B80C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B810: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8009B814: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8009B818: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x8009B81C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8009B820: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8009B824: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8009B828: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B82C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B830: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009B834: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B838: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B83C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009B840: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009B844: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B848: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009B84C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009B850: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009B854: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009B858: jal         0x8007B820
    // 0x8009B85C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x8009B85C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_0:
    // 0x8009B860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B868: jr          $ra
    // 0x8009B86C: nop

    return;
    // 0x8009B86C: nop

;}
RECOMP_FUNC void menu_credits_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B870: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009B874: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8009B878: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8009B87C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8009B880: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8009B884: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8009B888: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8009B88C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8009B890: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8009B894: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8009B898: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8009B89C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8009B8A0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009B8A4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8009B8A8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8009B8AC: jal         0x8001E2D0
    // 0x8009B8B0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009B8B0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x8009B8B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8009B8B8: jal         0x8001E2D0
    // 0x8009B8BC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8009B8BC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_1:
    // 0x8009B8C0: jal         0x800C7950
    // 0x8009B8C4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    bgload_tick(rdram, ctx);
        goto after_2;
    // 0x8009B8C4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_2:
    // 0x8009B8C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009B8CC: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8009B8D0: nop

    // 0x8009B8D4: bne         $t6, $zero, L_8009B8F4
    if (ctx->r14 != 0) {
        // 0x8009B8D8: nop
    
            goto L_8009B8F4;
    }
    // 0x8009B8D8: nop

    // 0x8009B8DC: jal         0x800C06A0
    // 0x8009B8E0: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_3;
    // 0x8009B8E0: nop

    after_3:
    // 0x8009B8E4: jal         0x800C06F8
    // 0x8009B8E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x8009B8E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8009B8EC: jal         0x800C0690
    // 0x8009B8F0: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_5;
    // 0x8009B8F0: nop

    after_5:
L_8009B8F4:
    // 0x8009B8F4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009B8F8: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009B8FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B900: bne         $t7, $zero, L_8009B934
    if (ctx->r15 != 0) {
        // 0x8009B904: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_8009B934;
    }
    // 0x8009B904: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009B908: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009B90C: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x8009B910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B914: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8009B918: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B91C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8009B920: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B924: jal         0x8009B728
    // 0x8009B928: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    credits_fade(rdram, ctx);
        goto after_6;
    // 0x8009B928: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    after_6:
    // 0x8009B92C: b           L_8009B950
    // 0x8009B930: nop

        goto L_8009B950;
    // 0x8009B930: nop

L_8009B934:
    // 0x8009B934: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009B938: lw          $t1, 0x6978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6978);
    // 0x8009B93C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B940: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8009B944: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009B948: jal         0x8009B728
    // 0x8009B94C: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    credits_fade(rdram, ctx);
        goto after_7;
    // 0x8009B94C: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    after_7:
L_8009B950:
    // 0x8009B950: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B954: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
    // 0x8009B958: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009B95C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B960: blez        $v0, L_8009BA68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009B964: addiu       $v1, $v1, -0x620
        ctx->r3 = ADD32(ctx->r3, -0X620);
            goto L_8009BA68;
    }
    // 0x8009B964: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8009B968: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009B96C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8009B970: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8009B974: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x8009B978: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8009B97C: bne         $at, $zero, L_8009B98C
    if (ctx->r1 != 0) {
        // 0x8009B980: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8009B98C;
    }
    // 0x8009B980: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009B984: b           L_8009B994
    // 0x8009B988: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_8009B994;
    // 0x8009B988: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8009B98C:
    // 0x8009B98C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009B990: subu        $s4, $t7, $v0
    ctx->r20 = SUB32(ctx->r15, ctx->r2);
L_8009B994:
    // 0x8009B994: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8009B998: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x8009B99C: lw          $s5, 0x0($v1)
    ctx->r21 = MEM_W(ctx->r3, 0X0);
    // 0x8009B9A0: jal         0x8007A970
    // 0x8009B9A4: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    fb_size(rdram, ctx);
        goto after_8;
    // 0x8009B9A4: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    after_8:
    // 0x8009B9A8: sra         $s2, $v0, 17
    ctx->r18 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8009B9AC: andi        $t9, $s2, 0x7FFF
    ctx->r25 = ctx->r18 & 0X7FFF;
    // 0x8009B9B0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009B9B4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009B9B8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009B9BC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8009B9C0: addiu       $s6, $s6, 0x1098
    ctx->r22 = ADD32(ctx->r22, 0X1098);
    // 0x8009B9C4: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8009B9C8: addiu       $s0, $s0, 0x1070
    ctx->r16 = ADD32(ctx->r16, 0X1070);
L_8009B9CC:
    // 0x8009B9CC: sll         $s1, $s5, 16
    ctx->r17 = S32(ctx->r21 << 16);
    // 0x8009B9D0: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8009B9D4: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x8009B9D8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B9DC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8009B9E0: jal         0x80070A70
    // 0x8009B9E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    sins_s16(rdram, ctx);
        goto after_9;
    // 0x8009B9E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    after_9:
    // 0x8009B9E8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8009B9EC: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B9F0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8009B9F4: jal         0x80070A6C
    // 0x8009B9F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    coss_s16(rdram, ctx);
        goto after_10;
    // 0x8009B9F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_10:
    // 0x8009B9FC: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009BA00: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8009BA04: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009BA08: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009BA0C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009BA10: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009BA14: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009BA18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009BA1C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009BA20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009BA24: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009BA28: mflo        $a2
    ctx->r6 = lo;
    // 0x8009BA2C: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8009BA30: addiu       $a2, $t3, 0x8C
    ctx->r6 = ADD32(ctx->r11, 0X8C);
    // 0x8009BA34: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009BA38: mflo        $t5
    ctx->r13 = lo;
    // 0x8009BA3C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009BA40: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    // 0x8009BA44: jal         0x80078F08
    // 0x8009BA48: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x8009BA48: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    after_11:
    // 0x8009BA4C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8009BA50: bne         $s0, $s6, L_8009B9CC
    if (ctx->r16 != ctx->r22) {
        // 0x8009BA54: addiu       $s5, $s5, 0x1999
        ctx->r21 = ADD32(ctx->r21, 0X1999);
            goto L_8009B9CC;
    }
    // 0x8009BA54: addiu       $s5, $s5, 0x1999
    ctx->r21 = ADD32(ctx->r21, 0X1999);
    // 0x8009BA58: jal         0x8007B820
    // 0x8009BA5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x8009BA5C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_12:
    // 0x8009BA60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA64: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BA68:
    // 0x8009BA68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BA6C: lw          $t2, 0x71A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A0);
    // 0x8009BA70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8009BA74: beq         $t2, $zero, L_8009BA98
    if (ctx->r10 == 0) {
        // 0x8009BA78: nop
    
            goto L_8009BA98;
    }
    // 0x8009BA78: nop

    // 0x8009BA7C: jal         0x8008239C
    // 0x8009BA80: nop

    postrace_render(rdram, ctx);
        goto after_13;
    // 0x8009BA80: nop

    after_13:
    // 0x8009BA84: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BA88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BA8C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA90: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
    // 0x8009BA94: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
L_8009BA98:
    // 0x8009BA98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009BA9C: lw          $t3, 0x7198($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7198);
    // 0x8009BAA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009BAA4: bne         $t3, $zero, L_8009BF68
    if (ctx->r11 != 0) {
        // 0x8009BAA8: nop
    
            goto L_8009BF68;
    }
    // 0x8009BAA8: nop

    // 0x8009BAAC: lw          $t5, 0x71A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X71A0);
    // 0x8009BAB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009BAB4: bne         $t5, $zero, L_8009BF68
    if (ctx->r13 != 0) {
        // 0x8009BAB8: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8009BF68;
    }
    // 0x8009BAB8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009BABC: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8009BAC0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BAC4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009BAC8: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009BACC: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BAD0: addiu       $fp, $fp, 0x1D74
    ctx->r30 = ADD32(ctx->r30, 0X1D74);
    // 0x8009BAD4: addiu       $s6, $s6, 0x7184
    ctx->r22 = ADD32(ctx->r22, 0X7184);
    // 0x8009BAD8: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BADC:
    // 0x8009BADC: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009BAE0: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8009BAE4: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8009BAE8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BAEC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8009BAF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009BAF4: andi        $v0, $a0, 0xF000
    ctx->r2 = ctx->r4 & 0XF000;
    // 0x8009BAF8: xor         $a2, $a3, $v0
    ctx->r6 = ctx->r7 ^ ctx->r2;
    // 0x8009BAFC: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8009BB00: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8009BB04: beq         $v0, $at, L_8009BB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB08: sra         $a2, $t8, 24
        ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
            goto L_8009BB4C;
    }
    // 0x8009BB08: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8009BB0C: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8009BB10: beq         $v0, $at, L_8009BB60
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB14: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_8009BB60;
    }
    // 0x8009BB14: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009BB18: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BB1C: beq         $v0, $at, L_8009BDD0
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB20: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8009BDD0;
    }
    // 0x8009BB20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009BB24: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8009BB28: beq         $v0, $at, L_8009BF30
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB2C: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_8009BF30;
    }
    // 0x8009BB2C: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8009BB30: addiu       $at, $zero, 0x5000
    ctx->r1 = ADD32(0, 0X5000);
    // 0x8009BB34: beq         $v0, $at, L_8009BF4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009BB38: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_8009BF4C;
    }
    // 0x8009BB38: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8009BB3C: beq         $v0, $a3, L_8009BB64
    if (ctx->r2 == ctx->r7) {
        // 0x8009BB40: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8009BB64;
    }
    // 0x8009BB40: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009BB44: b           L_8009BF54
    // 0x8009BB48: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_8009BF54;
    // 0x8009BB48: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009BB4C:
    // 0x8009BB4C: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x8009BB50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BB54: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8009BB58: b           L_8009BF50
    // 0x8009BB5C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
        goto L_8009BF50;
    // 0x8009BB5C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8009BB60:
    // 0x8009BB60: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_8009BB64:
    // 0x8009BB64: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009BB68: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x8009BB6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BB70: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8009BB74: sw          $t2, 0x71A8($at)
    MEM_W(0X71A8, ctx->r1) = ctx->r10;
    // 0x8009BB78: addu        $t5, $fp, $t3
    ctx->r13 = ADD32(ctx->r30, ctx->r11);
    // 0x8009BB7C: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009BB80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009BB84: andi        $t6, $v0, 0xF000
    ctx->r14 = ctx->r2 & 0XF000;
    // 0x8009BB88: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009BB8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009BB90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8009BB94: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8009BB98: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009BB9C: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x8009BBA0: bne         $t6, $zero, L_8009BBCC
    if (ctx->r14 != 0) {
        // 0x8009BBA4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8009BBCC;
    }
    // 0x8009BBA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8009BBA8:
    // 0x8009BBA8: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8009BBAC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009BBB0: addu        $t1, $fp, $t9
    ctx->r9 = ADD32(ctx->r30, ctx->r25);
    // 0x8009BBB4: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009BBB8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8009BBBC: andi        $t2, $v0, 0xF000
    ctx->r10 = ctx->r2 & 0XF000;
    // 0x8009BBC0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009BBC4: beq         $t2, $zero, L_8009BBA8
    if (ctx->r10 == 0) {
        // 0x8009BBC8: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8009BBA8;
    }
    // 0x8009BBC8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_8009BBCC:
    // 0x8009BBCC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8009BBD0: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8009BBD4: subu        $v1, $a1, $s0
    ctx->r3 = SUB32(ctx->r5, ctx->r16);
    // 0x8009BBD8: bne         $t4, $zero, L_8009BBE8
    if (ctx->r12 != 0) {
        // 0x8009BBDC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009BBE8;
    }
    // 0x8009BBDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009BBE0: b           L_8009BBEC
    // 0x8009BBE4: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
        goto L_8009BBEC;
    // 0x8009BBE4: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
L_8009BBE8:
    // 0x8009BBE8: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_8009BBEC:
    // 0x8009BBEC: bne         $v1, $at, L_8009BC00
    if (ctx->r3 != ctx->r1) {
        // 0x8009BBF0: addiu       $t6, $zero, 0x1E0
        ctx->r14 = ADD32(0, 0X1E0);
            goto L_8009BC00;
    }
    // 0x8009BBF0: addiu       $t6, $zero, 0x1E0
    ctx->r14 = ADD32(0, 0X1E0);
    // 0x8009BBF4: addiu       $s2, $s2, -0xE
    ctx->r18 = ADD32(ctx->r18, -0XE);
    // 0x8009BBF8: b           L_8009BC24
    // 0x8009BBFC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
        goto L_8009BC24;
    // 0x8009BBFC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_8009BC00:
    // 0x8009BC00: beq         $a2, $zero, L_8009BC1C
    if (ctx->r6 == 0) {
        // 0x8009BC04: sll         $t5, $v1, 4
        ctx->r13 = S32(ctx->r3 << 4);
            goto L_8009BC1C;
    }
    // 0x8009BC04: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x8009BC08: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8009BC0C: subu        $s2, $s2, $t3
    ctx->r18 = SUB32(ctx->r18, ctx->r11);
    // 0x8009BC10: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x8009BC14: b           L_8009BC24
    // 0x8009BC18: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
        goto L_8009BC24;
    // 0x8009BC18: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009BC1C:
    // 0x8009BC1C: subu        $s2, $s2, $t5
    ctx->r18 = SUB32(ctx->r18, ctx->r13);
    // 0x8009BC20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_8009BC24:
    // 0x8009BC24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC28: sh          $t6, 0x20D0($at)
    MEM_H(0X20D0, ctx->r1) = ctx->r14;
    // 0x8009BC2C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BC30: bne         $v0, $at, L_8009BC48
    if (ctx->r2 != ctx->r1) {
        // 0x8009BC34: addiu       $t8, $zero, -0xA0
        ctx->r24 = ADD32(0, -0XA0);
            goto L_8009BC48;
    }
    // 0x8009BC34: addiu       $t8, $zero, -0xA0
    ctx->r24 = ADD32(0, -0XA0);
    // 0x8009BC38: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8009BC3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC40: b           L_8009BC50
    // 0x8009BC44: sh          $t7, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r15;
        goto L_8009BC50;
    // 0x8009BC44: sh          $t7, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r15;
L_8009BC48:
    // 0x8009BC48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC4C: sh          $t8, 0x20D8($at)
    MEM_H(0X20D8, ctx->r1) = ctx->r24;
L_8009BC50:
    // 0x8009BC50: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BC54: beq         $at, $zero, L_8009BD60
    if (ctx->r1 == 0) {
        // 0x8009BC58: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009BD60;
    }
    // 0x8009BC58: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009BC5C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009BC60: sll         $t9, $s4, 1
    ctx->r25 = S32(ctx->r20 << 1);
    // 0x8009BC64: addu        $s1, $fp, $t9
    ctx->r17 = ADD32(ctx->r30, ctx->r25);
    // 0x8009BC68: addiu       $s0, $s0, 0x20D0
    ctx->r16 = ADD32(ctx->r16, 0X20D0);
L_8009BC6C:
    // 0x8009BC6C: sh          $s2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r18;
    // 0x8009BC70: sh          $s2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r18;
    // 0x8009BC74: beq         $a2, $zero, L_8009BD04
    if (ctx->r6 == 0) {
        // 0x8009BC78: sh          $s2, 0xA($s0)
        MEM_H(0XA, ctx->r16) = ctx->r18;
            goto L_8009BD04;
    }
    // 0x8009BC78: sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    // 0x8009BC7C: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x8009BC80: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8009BC84: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8009BC88: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x8009BC8C: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x8009BC90: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
    // 0x8009BC94: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8009BC98: lb          $a0, 0x0($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X0);
    // 0x8009BC9C: sb          $a2, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r6;
    // 0x8009BCA0: jal         0x8006C01C
    // 0x8009BCA4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    level_name(rdram, ctx);
        goto after_14;
    // 0x8009BCA4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    after_14:
    // 0x8009BCA8: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009BCAC: addiu       $v1, $s2, 0xE
    ctx->r3 = ADD32(ctx->r18, 0XE);
    // 0x8009BCB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009BCB4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009BCB8: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009BCBC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8009BCC0: sh          $v1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r3;
    // 0x8009BCC4: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8009BCC8: sh          $v1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r3;
    // 0x8009BCCC: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x8009BCD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009BCD4: lw          $t7, 0x2014($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2014);
    // 0x8009BCD8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009BCDC: lb          $a2, 0x5B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X5B);
    // 0x8009BCE0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BCE4: addiu       $t9, $t9, 0x1D74
    ctx->r25 = ADD32(ctx->r25, 0X1D74);
    // 0x8009BCE8: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8009BCEC: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BCF0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8009BCF4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8009BCF8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8009BCFC: b           L_8009BD4C
    // 0x8009BD00: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
        goto L_8009BD4C;
    // 0x8009BD00: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
L_8009BD04:
    // 0x8009BD04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009BD08: addiu       $t2, $t2, 0x1D74
    ctx->r10 = ADD32(ctx->r10, 0X1D74);
    // 0x8009BD0C: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x8009BD10: andi        $t4, $s3, 0x1
    ctx->r12 = ctx->r19 & 0X1;
    // 0x8009BD14: beq         $t4, $zero, L_8009BD28
    if (ctx->r12 == 0) {
        // 0x8009BD18: addu        $a0, $t1, $t2
        ctx->r4 = ADD32(ctx->r9, ctx->r10);
            goto L_8009BD28;
    }
    // 0x8009BD18: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x8009BD1C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009BD20: sb          $t3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r11;
    // 0x8009BD24: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
L_8009BD28:
    // 0x8009BD28: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009BD2C: sb          $s5, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r21;
    // 0x8009BD30: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009BD34: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8009BD38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009BD3C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8009BD40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009BD44: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8009BD48: sw          $t8, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r24;
L_8009BD4C:
    // 0x8009BD4C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009BD50: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x8009BD54: addu        $s2, $s2, $s7
    ctx->r18 = ADD32(ctx->r18, ctx->r23);
    // 0x8009BD58: bne         $at, $zero, L_8009BC6C
    if (ctx->r1 != 0) {
        // 0x8009BD5C: addiu       $s7, $zero, 0x20
        ctx->r23 = ADD32(0, 0X20);
            goto L_8009BC6C;
    }
    // 0x8009BD5C: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009BD60:
    // 0x8009BD60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BD64: addiu       $a0, $a0, 0x20D0
    ctx->r4 = ADD32(ctx->r4, 0X20D0);
    // 0x8009BD68: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x8009BD6C: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x8009BD70: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x8009BD74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BD78: lw          $t2, 0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A8);
    // 0x8009BD7C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009BD80: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8009BD84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009BD88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009BD8C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009BD90: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009BD94: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009BD98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009BD9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009BDA0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009BDA4: jal         0x800822A4
    // 0x8009BDA8: nop

    postrace_offsets(rdram, ctx);
        goto after_15;
    // 0x8009BDA8: nop

    after_15:
    // 0x8009BDAC: jal         0x8008239C
    // 0x8009BDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_16;
    // 0x8009BDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8009BDB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BDB8: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BDBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BDC0: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
    // 0x8009BDC4: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BDC8: b           L_8009BF50
    // 0x8009BDCC: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BF50;
    // 0x8009BDCC: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BDD0:
    // 0x8009BDD0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009BDD4: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009BDD8: and         $t3, $a0, $at
    ctx->r11 = ctx->r4 & ctx->r1;
    // 0x8009BDDC: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009BDE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BDE4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8009BDE8: sw          $t3, 0x71A8($at)
    MEM_W(0X71A8, ctx->r1) = ctx->r11;
    // 0x8009BDEC: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BDF0: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
    // 0x8009BDF4: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009BDF8: andi        $t8, $v0, 0xF000
    ctx->r24 = ctx->r2 & 0XF000;
    // 0x8009BDFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009BE00: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009BE04: bne         $t8, $zero, L_8009BE30
    if (ctx->r24 != 0) {
        // 0x8009BE08: sw          $t9, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r25;
            goto L_8009BE30;
    }
    // 0x8009BE08: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
L_8009BE0C:
    // 0x8009BE0C: addiu       $t1, $a1, 0x1
    ctx->r9 = ADD32(ctx->r5, 0X1);
    // 0x8009BE10: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009BE14: addu        $t4, $fp, $t2
    ctx->r12 = ADD32(ctx->r30, ctx->r10);
    // 0x8009BE18: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x8009BE1C: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x8009BE20: andi        $t3, $v0, 0xF000
    ctx->r11 = ctx->r2 & 0XF000;
    // 0x8009BE24: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8009BE28: beq         $t3, $zero, L_8009BE0C
    if (ctx->r11 == 0) {
        // 0x8009BE2C: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8009BE0C;
    }
    // 0x8009BE2C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_8009BE30:
    // 0x8009BE30: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009BE34: addiu       $v1, $v1, 0x20D0
    ctx->r3 = ADD32(ctx->r3, 0X20D0);
    // 0x8009BE38: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8009BE3C: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009BE40: bne         $v0, $at, L_8009BE50
    if (ctx->r2 != ctx->r1) {
        // 0x8009BE44: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8009BE50;
    }
    // 0x8009BE44: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8009BE48: b           L_8009BE58
    // 0x8009BE4C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
        goto L_8009BE58;
    // 0x8009BE4C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
L_8009BE50:
    // 0x8009BE50: addiu       $t5, $zero, -0xA0
    ctx->r13 = ADD32(0, -0XA0);
    // 0x8009BE54: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
L_8009BE58:
    // 0x8009BE58: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BE5C: beq         $at, $zero, L_8009BEB0
    if (ctx->r1 == 0) {
        // 0x8009BE60: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009BEB0;
    }
    // 0x8009BE60: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009BE64: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8009BE68: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8009BE6C: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    // 0x8009BE70: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009BE74: addiu       $t2, $t2, 0x20D0
    ctx->r10 = ADD32(ctx->r10, 0X20D0);
    // 0x8009BE78: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8009BE7C: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x8009BE80: addu        $s1, $fp, $t6
    ctx->r17 = ADD32(ctx->r30, ctx->r14);
    // 0x8009BE84: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_8009BE88:
    // 0x8009BE88: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009BE8C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8009BE90: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009BE94: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8009BE98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8009BE9C: slt         $at, $s4, $a1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009BEA0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009BEA4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009BEA8: bne         $at, $zero, L_8009BE88
    if (ctx->r1 != 0) {
        // 0x8009BEAC: sw          $t6, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r14;
            goto L_8009BE88;
    }
    // 0x8009BEAC: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
L_8009BEB0:
    // 0x8009BEB0: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x8009BEB4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009BEB8: lw          $t2, 0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71A8);
    // 0x8009BEBC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x8009BEC0: sll         $t8, $s4, 5
    ctx->r24 = S32(ctx->r20 << 5);
    // 0x8009BEC4: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009BEC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BECC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8009BED0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009BED4: sw          $zero, 0x2104($at)
    MEM_W(0X2104, ctx->r1) = 0;
    // 0x8009BED8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009BEDC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009BEE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009BEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BEE8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009BEEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009BEF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009BEF4: addiu       $a0, $a0, 0x20D0
    ctx->r4 = ADD32(ctx->r4, 0X20D0);
    // 0x8009BEF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009BEFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009BF00: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009BF04: jal         0x800822A4
    // 0x8009BF08: nop

    postrace_offsets(rdram, ctx);
        goto after_17;
    // 0x8009BF08: nop

    after_17:
    // 0x8009BF0C: jal         0x8008239C
    // 0x8009BF10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_18;
    // 0x8009BF10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x8009BF14: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009BF18: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009BF1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF20: sw          $t4, 0x71A0($at)
    MEM_W(0X71A0, ctx->r1) = ctx->r12;
    // 0x8009BF24: addiu       $t0, $t0, 0x1EB8
    ctx->r8 = ADD32(ctx->r8, 0X1EB8);
    // 0x8009BF28: b           L_8009BF50
    // 0x8009BF2C: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BF50;
    // 0x8009BF2C: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009BF30:
    // 0x8009BF30: sw          $t3, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r11;
    // 0x8009BF34: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009BF38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009BF40: sw          $t5, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = ctx->r13;
    // 0x8009BF44: b           L_8009BF50
    // 0x8009BF48: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
        goto L_8009BF50;
    // 0x8009BF48: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_8009BF4C:
    // 0x8009BF4C: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
L_8009BF50:
    // 0x8009BF50: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009BF54:
    // 0x8009BF54: nop

    // 0x8009BF58: beq         $t8, $zero, L_8009BADC
    if (ctx->r24 == 0) {
        // 0x8009BF5C: nop
    
            goto L_8009BADC;
    }
    // 0x8009BF5C: nop

    // 0x8009BF60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BF64: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BF68:
    // 0x8009BF68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009BF6C: lw          $t9, 0x6964($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6964);
    // 0x8009BF70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009BF74: bne         $t9, $zero, L_8009BFA8
    if (ctx->r25 != 0) {
        // 0x8009BF78: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009BFA8;
    }
    // 0x8009BF78: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009BF7C: lw          $t1, -0x604($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X604);
    // 0x8009BF80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009BF84: bne         $t1, $zero, L_8009BFA8
    if (ctx->r9 != 0) {
        // 0x8009BF88: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8009BFA8;
    }
    // 0x8009BF88: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8009BF8C:
    // 0x8009BF8C: jal         0x8006A794
    // 0x8009BF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_19;
    // 0x8009BF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8009BF94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009BF98: bne         $s0, $s1, L_8009BF8C
    if (ctx->r16 != ctx->r17) {
        // 0x8009BF9C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009BF8C;
    }
    // 0x8009BF9C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8009BFA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BFA4: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
L_8009BFA8:
    // 0x8009BFA8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009BFAC: addiu       $s0, $s0, 0x6980
    ctx->r16 = ADD32(ctx->r16, 0X6980);
    // 0x8009BFB0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009BFB4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8009BFB8: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8009BFBC: beq         $at, $zero, L_8009C148
    if (ctx->r1 == 0) {
        // 0x8009BFC0: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8009C148;
    }
    // 0x8009BFC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8009BFC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009BFC8: addu        $at, $at, $t2
    gpr jr_addend_8009BFD4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009BFCC: lw          $t2, -0x74FC($at)
    ctx->r10 = ADD32(ctx->r1, -0X74FC);
    // 0x8009BFD0: nop

    // 0x8009BFD4: jr          $t2
    // 0x8009BFD8: nop

    switch (jr_addend_8009BFD4 >> 2) {
        case 0: goto L_8009BFDC; break;
        case 1: goto L_8009C01C; break;
        case 2: goto L_8009C04C; break;
        case 3: goto L_8009C08C; break;
        case 4: goto L_8009C0E0; break;
        default: switch_error(__func__, 0x8009BFD4, 0x800E8B04);
    }
    // 0x8009BFD8: nop

L_8009BFDC:
    // 0x8009BFDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BFE0: addiu       $v1, $v1, 0x718C
    ctx->r3 = ADD32(ctx->r3, 0X718C);
    // 0x8009BFE4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8009BFE8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8009BFEC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009BFF0: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8009BFF4: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009BFF8: lb          $a1, 0x2($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2);
    // 0x8009BFFC: jal         0x800C79B8
    // 0x8009C000: nop

    bgload_start(rdram, ctx);
        goto after_20;
    // 0x8009C000: nop

    after_20:
    // 0x8009C004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C008: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009C00C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009C010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C014: b           L_8009C148
    // 0x8009C018: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
        goto L_8009C148;
    // 0x8009C018: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
L_8009C01C:
    // 0x8009C01C: jal         0x800C7940
    // 0x8009C020: nop

    bgload_active(rdram, ctx);
        goto after_21;
    // 0x8009C020: nop

    after_21:
    // 0x8009C024: bne         $v0, $zero, L_8009C148
    if (ctx->r2 != 0) {
        // 0x8009C028: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009C148;
    }
    // 0x8009C028: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C02C: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C030: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009C034: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8009C038: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009C03C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009C040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C044: b           L_8009C148
    // 0x8009C048: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
        goto L_8009C148;
    // 0x8009C048: sw          $zero, 0x7198($at)
    MEM_W(0X7198, ctx->r1) = 0;
L_8009C04C:
    // 0x8009C04C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C050: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C054: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8009C058: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009C05C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8009C060: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8009C064: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x8009C068: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8009C06C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8009C070: bgtz        $t4, L_8009C148
    if (SIGNED(ctx->r12) > 0) {
        // 0x8009C074: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_8009C148;
    }
    // 0x8009C074: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8009C078: addiu       $t7, $t4, 0x258
    ctx->r15 = ADD32(ctx->r12, 0X258);
    // 0x8009C07C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009C080: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009C084: b           L_8009C148
    // 0x8009C088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8009C148;
    // 0x8009C088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8009C08C:
    // 0x8009C08C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C090: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C094: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009C098: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8009C09C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009C0A0: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8009C0A4: blez        $v0, L_8009C0C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009C0A8: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8009C0C0;
    }
    // 0x8009C0A8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8009C0AC: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0B0: nop

    // 0x8009C0B4: subu        $t3, $v0, $t4
    ctx->r11 = SUB32(ctx->r2, ctx->r12);
    // 0x8009C0B8: b           L_8009C0C4
    // 0x8009C0BC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8009C0C4;
    // 0x8009C0BC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8009C0C0:
    // 0x8009C0C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009C0C4:
    // 0x8009C0C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009C0C8: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009C0CC: bgtz        $t5, L_8009C14C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009C0D0: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009C14C;
    }
    // 0x8009C0D0: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009C0D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009C0D8: b           L_8009C148
    // 0x8009C0DC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_8009C148;
    // 0x8009C0DC: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_8009C0E0:
    // 0x8009C0E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C0E4: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8009C0E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009C0EC: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0F0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8009C0F4: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009C0F8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8009C0FC: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8009C100: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009C104: bgtz        $t9, L_8009C148
    if (SIGNED(ctx->r25) > 0) {
        // 0x8009C108: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_8009C148;
    }
    // 0x8009C108: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8009C10C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C110: addiu       $v1, $v1, 0x718C
    ctx->r3 = ADD32(ctx->r3, 0X718C);
    // 0x8009C114: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009C118: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009C11C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8009C120: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8009C124: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009C128: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009C12C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009C130: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8009C134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C138: bgez        $t2, L_8009C14C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009C13C: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009C14C;
    }
    // 0x8009C13C: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009C140: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8009C144: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8009C148:
    // 0x8009C148: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
L_8009C14C:
    // 0x8009C14C: bne         $t4, $zero, L_8009C168
    if (ctx->r12 != 0) {
        // 0x8009C150: andi        $t3, $s2, 0x4000
        ctx->r11 = ctx->r18 & 0X4000;
            goto L_8009C168;
    }
    // 0x8009C150: andi        $t3, $s2, 0x4000
    ctx->r11 = ctx->r18 & 0X4000;
    // 0x8009C154: bne         $t3, $zero, L_8009C16C
    if (ctx->r11 != 0) {
        // 0x8009C158: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009C16C;
    }
    // 0x8009C158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C15C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8009C160: nop

    // 0x8009C164: beq         $t5, $zero, L_8009C194
    if (ctx->r13 == 0) {
        // 0x8009C168: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009C194;
    }
L_8009C168:
    // 0x8009C168: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8009C16C:
    // 0x8009C16C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C170: jal         0x800C06A0
    // 0x8009C174: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x8009C174: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    after_22:
    // 0x8009C178: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C17C: jal         0x800C06F8
    // 0x8009C180: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_23;
    // 0x8009C180: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_23:
    // 0x8009C184: jal         0x800C0690
    // 0x8009C188: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_24;
    // 0x8009C188: nop

    after_24:
    // 0x8009C18C: jal         0x80000C98
    // 0x8009C190: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_25;
    // 0x8009C190: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_25:
L_8009C194:
    // 0x8009C194: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C198: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009C19C: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8009C1A0: blez        $v0, L_8009C1F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009C1A4: addu        $t8, $v0, $t7
        ctx->r24 = ADD32(ctx->r2, ctx->r15);
            goto L_8009C1F8;
    }
    // 0x8009C1A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009C1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C1AC: jal         0x800C7940
    // 0x8009C1B0: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    bgload_active(rdram, ctx);
        goto after_26;
    // 0x8009C1B0: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    after_26:
    // 0x8009C1B4: bne         $v0, $zero, L_8009C1F8
    if (ctx->r2 != 0) {
        // 0x8009C1B8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8009C1F8;
    }
    // 0x8009C1B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009C1BC: lw          $t9, -0x604($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X604);
    // 0x8009C1C0: nop

    // 0x8009C1C4: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x8009C1C8: bne         $at, $zero, L_8009C1FC
    if (ctx->r1 != 0) {
        // 0x8009C1CC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8009C1FC;
    }
    // 0x8009C1CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8009C1D0: jal         0x80000B28
    // 0x8009C1D4: nop

    music_change_on(rdram, ctx);
        goto after_27;
    // 0x8009C1D4: nop

    after_27:
    // 0x8009C1D8: jal         0x8009C234
    // 0x8009C1DC: nop

    credits_free(rdram, ctx);
        goto after_28;
    // 0x8009C1DC: nop

    after_28:
    // 0x8009C1E0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8009C1E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8009C1E8: jal         0x8006E528
    // 0x8009C1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_29;
    // 0x8009C1EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x8009C1F0: jal         0x80081820
    // 0x8009C1F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_30;
    // 0x8009C1F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
L_8009C1F8:
    // 0x8009C1F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8009C1FC:
    // 0x8009C1FC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8009C200: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C204: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009C208: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8009C20C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8009C210: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C214: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8009C218: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8009C21C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8009C220: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8009C224: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8009C228: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8009C22C: jr          $ra
    // 0x8009C230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009C230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void credits_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C23C: jal         0x80000BE0
    // 0x8009C240: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x8009C240: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8009C244: jal         0x800C06A0
    // 0x8009C248: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_1;
    // 0x8009C248: nop

    after_1:
    // 0x8009C24C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C250: jal         0x80066AD4
    // 0x8009C254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x8009C254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009C258: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8009C25C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009C260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C264: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009C268: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009C26C: jal         0x80066CE8
    // 0x8009C270: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009C270: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x8009C274: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C278: jal         0x8009C9EC
    // 0x8009C27C: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    menu_assetgroup_free(rdram, ctx);
        goto after_4;
    // 0x8009C27C: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    after_4:
    // 0x8009C280: jal         0x800C478C
    // 0x8009C284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_5;
    // 0x8009C284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8009C288: jal         0x8006F7A4
    // 0x8009C28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_gIntDisFlag(rdram, ctx);
        goto after_6;
    // 0x8009C28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009C290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009C298: jr          $ra
    // 0x8009C29C: nop

    return;
    // 0x8009C29C: nop

;}
RECOMP_FUNC void menu_camera_centre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009C2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C2A8: jal         0x8006676C
    // 0x8009C2AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x8009C2AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009C2B0: jal         0x80066828
    // 0x8009C2B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8009C2B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8009C2B8: jal         0x80069F60
    // 0x8009C2BC: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x8009C2BC: nop

    after_2:
    // 0x8009C2C0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009C2C4: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x8009C2C8: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x8009C2CC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009C2D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009C2D4: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8009C2D8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009C2DC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009C2E0: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x8009C2E4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009C2E8: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x8009C2EC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8009C2F0: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009C2F4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x8009C2F8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8009C2FC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009C300: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8009C304: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8009C308: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8009C30C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8009C310: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8009C314: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8009C318: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8009C31C: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8009C320: jal         0x8001D614
    // 0x8009C324: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x8009C324: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8009C328: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009C32C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009C330: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009C334: jal         0x80066F1C
    // 0x8009C338: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    viewport_main(rdram, ctx);
        goto after_4;
    // 0x8009C338: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_4:
    // 0x8009C33C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8009C340: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8009C344: nop

    // 0x8009C348: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8009C34C: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8009C350: nop

    // 0x8009C354: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8009C358: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8009C35C: nop

    // 0x8009C360: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x8009C364: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009C368: nop

    // 0x8009C36C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009C370: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009C374: nop

    // 0x8009C378: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8009C37C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8009C380: nop

    // 0x8009C384: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8009C388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C38C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009C390: jr          $ra
    // 0x8009C394: nop

    return;
    // 0x8009C394: nop

;}
RECOMP_FUNC void func_8009BE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C398: jr          $ra
    // 0x8009C39C: nop

    return;
    // 0x8009C39C: nop

;}
RECOMP_FUNC void reset_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C3A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3A4: sb          $zero, 0x69FC($at)
    MEM_B(0X69FC, ctx->r1) = 0;
    // 0x8009C3A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3AC: sb          $zero, 0x6A04($at)
    MEM_B(0X6A04, ctx->r1) = 0;
    // 0x8009C3B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3B4: sb          $zero, 0x69F4($at)
    MEM_B(0X69F4, ctx->r1) = 0;
    // 0x8009C3B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3BC: sb          $zero, 0x69F8($at)
    MEM_B(0X69F8, ctx->r1) = 0;
    // 0x8009C3C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3C4: sb          $zero, 0x6A08($at)
    MEM_B(0X6A08, ctx->r1) = 0;
    // 0x8009C3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3CC: sb          $zero, 0x6A0C($at)
    MEM_B(0X6A0C, ctx->r1) = 0;
    // 0x8009C3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3D4: sb          $zero, 0x69FD($at)
    MEM_B(0X69FD, ctx->r1) = 0;
    // 0x8009C3D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3DC: sb          $zero, 0x6A05($at)
    MEM_B(0X6A05, ctx->r1) = 0;
    // 0x8009C3E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3E4: sb          $zero, 0x69F5($at)
    MEM_B(0X69F5, ctx->r1) = 0;
    // 0x8009C3E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3EC: sb          $zero, 0x69F9($at)
    MEM_B(0X69F9, ctx->r1) = 0;
    // 0x8009C3F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3F4: sb          $zero, 0x6A09($at)
    MEM_B(0X6A09, ctx->r1) = 0;
    // 0x8009C3F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3FC: sb          $zero, 0x6A0D($at)
    MEM_B(0X6A0D, ctx->r1) = 0;
    // 0x8009C400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C404: sb          $zero, 0x69FE($at)
    MEM_B(0X69FE, ctx->r1) = 0;
    // 0x8009C408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C40C: sb          $zero, 0x6A06($at)
    MEM_B(0X6A06, ctx->r1) = 0;
    // 0x8009C410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C414: sb          $zero, 0x69F6($at)
    MEM_B(0X69F6, ctx->r1) = 0;
    // 0x8009C418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C41C: sb          $zero, 0x69FA($at)
    MEM_B(0X69FA, ctx->r1) = 0;
    // 0x8009C420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C424: sb          $zero, 0x6A0A($at)
    MEM_B(0X6A0A, ctx->r1) = 0;
    // 0x8009C428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C42C: sb          $zero, 0x6A0E($at)
    MEM_B(0X6A0E, ctx->r1) = 0;
    // 0x8009C430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C434: sb          $zero, 0x69FF($at)
    MEM_B(0X69FF, ctx->r1) = 0;
    // 0x8009C438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C43C: sb          $zero, 0x6A07($at)
    MEM_B(0X6A07, ctx->r1) = 0;
    // 0x8009C440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C444: sb          $zero, 0x69F7($at)
    MEM_B(0X69F7, ctx->r1) = 0;
    // 0x8009C448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C44C: sb          $zero, 0x69FB($at)
    MEM_B(0X69FB, ctx->r1) = 0;
    // 0x8009C450: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C454: sb          $zero, 0x6A0B($at)
    MEM_B(0X6A0B, ctx->r1) = 0;
    // 0x8009C458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C45C: jr          $ra
    // 0x8009C460: sb          $zero, 0x6A0F($at)
    MEM_B(0X6A0F, ctx->r1) = 0;
    return;
    // 0x8009C460: sb          $zero, 0x6A0F($at)
    MEM_B(0X6A0F, ctx->r1) = 0;
;}
RECOMP_FUNC void update_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C464: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009C468: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009C46C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009C470: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009C474: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C478: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C47C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C480: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009C484: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009C488: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009C48C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009C490: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009C494: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009C498: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009C49C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009C4A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009C4A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009C4A8: addiu       $s7, $s7, 0x6A04
    ctx->r23 = ADD32(ctx->r23, 0X6A04);
    // 0x8009C4AC: addiu       $s6, $s6, 0x69FC
    ctx->r22 = ADD32(ctx->r22, 0X69FC);
    // 0x8009C4B0: addiu       $s3, $s3, 0x6A0C
    ctx->r19 = ADD32(ctx->r19, 0X6A0C);
    // 0x8009C4B4: addiu       $s2, $s2, 0x6A08
    ctx->r18 = ADD32(ctx->r18, 0X6A08);
    // 0x8009C4B8: addiu       $s1, $s1, 0x69F8
    ctx->r17 = ADD32(ctx->r17, 0X69F8);
    // 0x8009C4BC: addiu       $s0, $s0, 0x69F4
    ctx->r16 = ADD32(ctx->r16, 0X69F4);
    // 0x8009C4C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009C4C4: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
L_8009C4C8:
    // 0x8009C4C8: jal         0x8006A7DC
    // 0x8009C4CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_x(rdram, ctx);
        goto after_0;
    // 0x8009C4CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8009C4D0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8009C4D4: jal         0x8006A820
    // 0x8009C4D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_y(rdram, ctx);
        goto after_1;
    // 0x8009C4D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8009C4DC: slti        $at, $s4, -0x23
    ctx->r1 = SIGNED(ctx->r20) < -0X23 ? 1 : 0;
    // 0x8009C4E0: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x8009C4E4: beq         $at, $zero, L_8009C508
    if (ctx->r1 == 0) {
        // 0x8009C4E8: sb          $zero, 0x0($s7)
        MEM_B(0X0, ctx->r23) = 0;
            goto L_8009C508;
    }
    // 0x8009C4E8: sb          $zero, 0x0($s7)
    MEM_B(0X0, ctx->r23) = 0;
    // 0x8009C4EC: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8009C4F0: nop

    // 0x8009C4F4: slti        $at, $t6, -0x23
    ctx->r1 = SIGNED(ctx->r14) < -0X23 ? 1 : 0;
    // 0x8009C4F8: bne         $at, $zero, L_8009C50C
    if (ctx->r1 != 0) {
        // 0x8009C4FC: slti        $at, $s4, 0x24
        ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
            goto L_8009C50C;
    }
    // 0x8009C4FC: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
    // 0x8009C500: sb          $fp, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r30;
    // 0x8009C504: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C508:
    // 0x8009C508: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
L_8009C50C:
    // 0x8009C50C: bne         $at, $zero, L_8009C530
    if (ctx->r1 != 0) {
        // 0x8009C510: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8009C530;
    }
    // 0x8009C510: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8009C514: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8009C518: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009C51C: slti        $at, $t7, 0x24
    ctx->r1 = SIGNED(ctx->r15) < 0X24 ? 1 : 0;
    // 0x8009C520: beq         $at, $zero, L_8009C534
    if (ctx->r1 == 0) {
        // 0x8009C524: slti        $at, $v0, -0x23
        ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
            goto L_8009C534;
    }
    // 0x8009C524: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009C528: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x8009C52C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C530:
    // 0x8009C530: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
L_8009C534:
    // 0x8009C534: beq         $at, $zero, L_8009C558
    if (ctx->r1 == 0) {
        // 0x8009C538: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8009C558;
    }
    // 0x8009C538: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009C53C: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8009C540: nop

    // 0x8009C544: slti        $at, $t9, -0x23
    ctx->r1 = SIGNED(ctx->r25) < -0X23 ? 1 : 0;
    // 0x8009C548: bne         $at, $zero, L_8009C55C
    if (ctx->r1 != 0) {
        // 0x8009C54C: slti        $at, $v0, 0x24
        ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
            goto L_8009C55C;
    }
    // 0x8009C54C: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C550: sb          $fp, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r30;
    // 0x8009C554: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C558:
    // 0x8009C558: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
L_8009C55C:
    // 0x8009C55C: bne         $at, $zero, L_8009C580
    if (ctx->r1 != 0) {
        // 0x8009C560: nop
    
            goto L_8009C580;
    }
    // 0x8009C560: nop

    // 0x8009C564: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8009C568: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009C56C: slti        $at, $t0, 0x24
    ctx->r1 = SIGNED(ctx->r8) < 0X24 ? 1 : 0;
    // 0x8009C570: beq         $at, $zero, L_8009C580
    if (ctx->r1 == 0) {
        // 0x8009C574: nop
    
            goto L_8009C580;
    }
    // 0x8009C574: nop

    // 0x8009C578: sb          $t1, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r9;
    // 0x8009C57C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C580:
    // 0x8009C580: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // 0x8009C584: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8009C588: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8009C58C: slti        $at, $v1, -0x23
    ctx->r1 = SIGNED(ctx->r3) < -0X23 ? 1 : 0;
    // 0x8009C590: beq         $at, $zero, L_8009C5B0
    if (ctx->r1 == 0) {
        // 0x8009C594: slti        $at, $v1, 0x24
        ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
            goto L_8009C5B0;
    }
    // 0x8009C594: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x8009C598: lb          $t2, 0x0($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X0);
    // 0x8009C59C: nop

    // 0x8009C5A0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8009C5A4: b           L_8009C5D0
    // 0x8009C5A8: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
        goto L_8009C5D0;
    // 0x8009C5A8: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
    // 0x8009C5AC: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
L_8009C5B0:
    // 0x8009C5B0: bne         $at, $zero, L_8009C5CC
    if (ctx->r1 != 0) {
        // 0x8009C5B4: nop
    
            goto L_8009C5CC;
    }
    // 0x8009C5B4: nop

    // 0x8009C5B8: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x8009C5BC: nop

    // 0x8009C5C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009C5C4: b           L_8009C5D0
    // 0x8009C5C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
        goto L_8009C5D0;
    // 0x8009C5C8: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
L_8009C5CC:
    // 0x8009C5CC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C5D0:
    // 0x8009C5D0: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8009C5D4: nop

    // 0x8009C5D8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8009C5DC: bne         $at, $zero, L_8009C5EC
    if (ctx->r1 != 0) {
        // 0x8009C5E0: nop
    
            goto L_8009C5EC;
    }
    // 0x8009C5E0: nop

    // 0x8009C5E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8009C5E8: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C5EC:
    // 0x8009C5EC: sb          $s4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r20;
    // 0x8009C5F0: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8009C5F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009C5F8: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009C5FC: beq         $at, $zero, L_8009C618
    if (ctx->r1 == 0) {
        // 0x8009C600: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8009C618;
    }
    // 0x8009C600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009C604: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x8009C608: nop

    // 0x8009C60C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8009C610: b           L_8009C63C
    // 0x8009C614: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
        goto L_8009C63C;
    // 0x8009C614: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
L_8009C618:
    // 0x8009C618: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C61C: bne         $at, $zero, L_8009C638
    if (ctx->r1 != 0) {
        // 0x8009C620: nop
    
            goto L_8009C638;
    }
    // 0x8009C620: nop

    // 0x8009C624: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x8009C628: nop

    // 0x8009C62C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009C630: b           L_8009C63C
    // 0x8009C634: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_8009C63C;
    // 0x8009C634: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_8009C638:
    // 0x8009C638: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C63C:
    // 0x8009C63C: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x8009C640: nop

    // 0x8009C644: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8009C648: bne         $at, $zero, L_8009C65C
    if (ctx->r1 != 0) {
        // 0x8009C64C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8009C65C;
    }
    // 0x8009C64C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009C650: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8009C654: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8009C658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8009C65C:
    // 0x8009C65C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009C660: bne         $s5, $at, L_8009C4C8
    if (ctx->r21 != ctx->r1) {
        // 0x8009C664: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009C4C8;
    }
    // 0x8009C664: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009C668: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C66C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C670: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C674: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C678: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009C67C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009C680: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009C684: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009C688: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009C68C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009C690: jr          $ra
    // 0x8009C694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009C694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void reset_character_id_slots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C698: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C69C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C6A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C6A4: sw          $t6, -0x5B8($at)
    MEM_W(-0X5B8, ctx->r1) = ctx->r14;
    // 0x8009C6A8: addiu       $v1, $v1, 0x6990
    ctx->r3 = ADD32(ctx->r3, 0X6990);
    // 0x8009C6AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009C6B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8009C6B4:
    // 0x8009C6B4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8009C6B8: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x8009C6BC: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8009C6C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8009C6C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009C6C8: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8009C6CC: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x8009C6D0: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8009C6D4: bne         $v0, $a0, L_8009C6B4
    if (ctx->r2 != ctx->r4) {
        // 0x8009C6D8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8009C6B4;
    }
    // 0x8009C6D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009C6DC: jr          $ra
    // 0x8009C6E0: nop

    return;
    // 0x8009C6E0: nop

;}
RECOMP_FUNC void get_save_file_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C6E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C6E8: lw          $v0, -0x5B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5B4);
    // 0x8009C6EC: jr          $ra
    // 0x8009C6F0: nop

    return;
    // 0x8009C6F0: nop

;}
RECOMP_FUNC void get_track_id_to_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C6FC: jal         0x8006ECD0
    // 0x8009C700: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009C700: nop

    after_0:
    // 0x8009C704: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C708: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C70C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009C710: bne         $t6, $zero, L_8009C74C
    if (ctx->r14 != 0) {
        // 0x8009C714: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C74C;
    }
    // 0x8009C714: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C718: lw          $t7, -0x608($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X608);
    // 0x8009C71C: nop

    // 0x8009C720: bne         $t7, $zero, L_8009C74C
    if (ctx->r15 != 0) {
        // 0x8009C724: nop
    
            goto L_8009C74C;
    }
    // 0x8009C724: nop

    // 0x8009C728: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x8009C72C: nop

    // 0x8009C730: beq         $t8, $zero, L_8009C740
    if (ctx->r24 == 0) {
        // 0x8009C734: nop
    
            goto L_8009C740;
    }
    // 0x8009C734: nop

    // 0x8009C738: b           L_8009C75C
    // 0x8009C73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009C75C;
    // 0x8009C73C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009C740:
    // 0x8009C740: lbu         $v0, 0x49($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X49);
    // 0x8009C744: b           L_8009C760
    // 0x8009C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C760;
    // 0x8009C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C74C:
    // 0x8009C74C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C754: lw          $v0, -0x5AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5AC);
    // 0x8009C758: sw          $zero, -0x608($at)
    MEM_W(-0X608, ctx->r1) = 0;
L_8009C75C:
    // 0x8009C75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C760:
    // 0x8009C760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C764: jr          $ra
    // 0x8009C768: nop

    return;
    // 0x8009C768: nop

;}
RECOMP_FUNC void get_character_id_from_slot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C76C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C770: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C774: lb          $v0, 0x6990($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6990);
    // 0x8009C778: jr          $ra
    // 0x8009C77C: nop

    return;
    // 0x8009C77C: nop

;}
RECOMP_FUNC void get_character_id_from_slot_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C780: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C784: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C788: lb          $v0, 0x6990($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6990);
    // 0x8009C78C: jr          $ra
    // 0x8009C790: nop

    return;
    // 0x8009C790: nop

;}
RECOMP_FUNC void get_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C794: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C798: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C79C: lb          $v0, 0x6F80($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6F80);
    // 0x8009C7A0: jr          $ra
    // 0x8009C7A4: nop

    return;
    // 0x8009C7A4: nop

;}
RECOMP_FUNC void set_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C7AC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009C7B0: jr          $ra
    // 0x8009C7B4: sb          $a1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r5;
    return;
    // 0x8009C7B4: sb          $a1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void charselect_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C7BC: jr          $ra
    // 0x8009C7C0: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
    return;
    // 0x8009C7C0: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
;}
RECOMP_FUNC void get_player_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7C4: bltz        $a0, L_8009C7D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009C7C8: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8009C7D4;
    }
    // 0x8009C7C8: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8009C7CC: bne         $at, $zero, L_8009C7DC
    if (ctx->r1 != 0) {
        // 0x8009C7D0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009C7DC;
    }
    // 0x8009C7D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8009C7D4:
    // 0x8009C7D4: jr          $ra
    // 0x8009C7D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C7D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C7DC:
    // 0x8009C7DC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8009C7E0: lb          $t6, 0x6974($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6974);
    // 0x8009C7E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C7E8: bne         $t6, $zero, L_8009C7F8
    if (ctx->r14 != 0) {
        // 0x8009C7EC: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_8009C7F8;
    }
    // 0x8009C7EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C7F0: jr          $ra
    // 0x8009C7F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C7F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C7F8:
    // 0x8009C7F8: lb          $v0, 0x6988($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6988);
    // 0x8009C7FC: nop

    // 0x8009C800: jr          $ra
    // 0x8009C804: nop

    return;
    // 0x8009C804: nop

;}
RECOMP_FUNC void enable_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C80C: jr          $ra
    // 0x8009C810: sw          $a0, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r4;
    return;
    // 0x8009C810: sw          $a0, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void is_in_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C814: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C818: lw          $v0, -0x5C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C8);
    // 0x8009C81C: jr          $ra
    // 0x8009C820: nop

    return;
    // 0x8009C820: nop

;}
RECOMP_FUNC void set_magic_code_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C824: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C828: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009C82C: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8009C830: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, 0X318);
    // 0x8009C834: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009C838: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009C83C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8009C840: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x8009C844: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C848: jr          $ra
    // 0x8009C84C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x8009C84C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void get_filtered_cheats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C858: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C85C: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C860: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009C864: lw          $s0, 0x318($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X318);
    // 0x8009C868: beq         $t6, $zero, L_8009C87C
    if (ctx->r14 == 0) {
        // 0x8009C86C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009C87C;
    }
    // 0x8009C86C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C870: jal         0x8000E4C8
    // 0x8009C874: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_0;
    // 0x8009C874: nop

    after_0:
    // 0x8009C878: beq         $v0, $zero, L_8009C88C
    if (ctx->r2 == 0) {
        // 0x8009C87C: lui         $at, 0x1B40
        ctx->r1 = S32(0X1B40 << 16);
            goto L_8009C88C;
    }
L_8009C87C:
    // 0x8009C87C: lui         $at, 0x1B40
    ctx->r1 = S32(0X1B40 << 16);
    // 0x8009C880: ori         $at, $at, 0x133
    ctx->r1 = ctx->r1 | 0X133;
    // 0x8009C884: and         $t7, $s0, $at
    ctx->r15 = ctx->r16 & ctx->r1;
    // 0x8009C888: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8009C88C:
    // 0x8009C88C: jal         0x8006B480
    // 0x8009C890: nop

    level_is_race(rdram, ctx);
        goto after_1;
    // 0x8009C890: nop

    after_1:
    // 0x8009C894: bne         $v0, $zero, L_8009C8A4
    if (ctx->r2 != 0) {
        // 0x8009C898: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_8009C8A4;
    }
    // 0x8009C898: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8009C89C: and         $t8, $s0, $at
    ctx->r24 = ctx->r16 & ctx->r1;
    // 0x8009C8A0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8009C8A4:
    // 0x8009C8A4: jal         0x8006ECD0
    // 0x8009C8A8: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009C8A8: nop

    after_2:
    // 0x8009C8AC: lbu         $a0, 0x49($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X49);
    // 0x8009C8B0: jal         0x8006B38C
    // 0x8009C8B4: nop

    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x8009C8B4: nop

    after_3:
    // 0x8009C8B8: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x8009C8BC: beq         $t9, $zero, L_8009C8D4
    if (ctx->r25 == 0) {
        // 0x8009C8C0: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009C8D4;
    }
    // 0x8009C8C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009C8C4: lui         $at, 0xFFF0
    ctx->r1 = S32(0XFFF0 << 16);
    // 0x8009C8C8: ori         $at, $at, 0x677F
    ctx->r1 = ctx->r1 | 0X677F;
    // 0x8009C8CC: and         $t0, $s0, $at
    ctx->r8 = ctx->r16 & ctx->r1;
    // 0x8009C8D0: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_8009C8D4:
    // 0x8009C8D4: lw          $t1, -0x5EC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5EC);
    // 0x8009C8D8: nop

    // 0x8009C8DC: beq         $t1, $zero, L_8009C8FC
    if (ctx->r9 == 0) {
        // 0x8009C8E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009C8FC;
    }
    // 0x8009C8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C8E4: jal         0x8006B480
    // 0x8009C8E8: nop

    level_is_race(rdram, ctx);
        goto after_4;
    // 0x8009C8E8: nop

    after_4:
    // 0x8009C8EC: beq         $v0, $zero, L_8009C8F8
    if (ctx->r2 == 0) {
        // 0x8009C8F0: ori         $t2, $s0, 0x4
        ctx->r10 = ctx->r16 | 0X4;
            goto L_8009C8F8;
    }
    // 0x8009C8F0: ori         $t2, $s0, 0x4
    ctx->r10 = ctx->r16 | 0X4;
    // 0x8009C8F4: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8009C8F8:
    // 0x8009C8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009C8FC:
    // 0x8009C8FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8009C900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C904: jr          $ra
    // 0x8009C908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009C908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_number_of_active_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C90C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C910: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8009C914: jr          $ra
    // 0x8009C918: nop

    return;
    // 0x8009C918: nop

;}
RECOMP_FUNC void get_active_player_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C91C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C924: jal         0x8006BFF0
    // 0x8009C928: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x8009C928: nop

    after_0:
    // 0x8009C92C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C930: lw          $t6, -0x5C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C0);
    // 0x8009C934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C938: beq         $t6, $zero, L_8009C970
    if (ctx->r14 == 0) {
        // 0x8009C93C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C970;
    }
    // 0x8009C93C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C940: lw          $t7, -0x5C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C8);
    // 0x8009C944: nop

    // 0x8009C948: bne         $t7, $zero, L_8009C970
    if (ctx->r15 != 0) {
        // 0x8009C94C: nop
    
            goto L_8009C970;
    }
    // 0x8009C94C: nop

    // 0x8009C950: lb          $v1, 0x4C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X4C);
    // 0x8009C954: nop

    // 0x8009C958: beq         $v1, $zero, L_8009C968
    if (ctx->r3 == 0) {
        // 0x8009C95C: andi        $t8, $v1, 0x40
        ctx->r24 = ctx->r3 & 0X40;
            goto L_8009C968;
    }
    // 0x8009C95C: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x8009C960: beq         $t8, $zero, L_8009C970
    if (ctx->r24 == 0) {
        // 0x8009C964: nop
    
            goto L_8009C970;
    }
    // 0x8009C964: nop

L_8009C968:
    // 0x8009C968: b           L_8009C97C
    // 0x8009C96C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8009C97C;
    // 0x8009C96C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8009C970:
    // 0x8009C970: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C974: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8009C978: nop

L_8009C97C:
    // 0x8009C97C: jr          $ra
    // 0x8009C980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009C980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_multiplayer_racer_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C984: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C988: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C98C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C990: bne         $t6, $zero, L_8009C9A0
    if (ctx->r14 != 0) {
        // 0x8009C994: nop
    
            goto L_8009C9A0;
    }
    // 0x8009C994: nop

    // 0x8009C998: jr          $ra
    // 0x8009C99C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C99C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C9A0:
    // 0x8009C9A0: lw          $t7, 0x1568($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1568);
    // 0x8009C9A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C9A8: beq         $t7, $zero, L_8009C9B8
    if (ctx->r15 == 0) {
        // 0x8009C9AC: nop
    
            goto L_8009C9B8;
    }
    // 0x8009C9AC: nop

    // 0x8009C9B0: jr          $ra
    // 0x8009C9B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C9B4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C9B8:
    // 0x8009C9B8: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X990);
    // 0x8009C9BC: nop

    // 0x8009C9C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009C9C4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009C9C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009C9CC: jr          $ra
    // 0x8009C9D0: nop

    return;
    // 0x8009C9D0: nop

;}
RECOMP_FUNC void get_all_save_files_ptr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C9D8: jr          $ra
    // 0x8009C9DC: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
    return;
    // 0x8009C9DC: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
;}
RECOMP_FUNC void menu_title_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C9E4: jr          $ra
    // 0x8009C9E8: sw          $zero, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = 0;
    return;
    // 0x8009C9E8: sw          $zero, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = 0;
;}
RECOMP_FUNC void menu_assetgroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C9F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C9F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C9F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C9FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CA00: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CA04: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CA08: beq         $s2, $t6, L_8009CA38
    if (ctx->r18 == ctx->r14) {
        // 0x8009CA0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CA38;
    }
    // 0x8009CA0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CA10: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CA14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CA18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CA1C:
    // 0x8009CA1C: jal         0x8009CA4C
    // 0x8009CA20: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8009CA20: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CA24: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CA28: nop

    // 0x8009CA2C: bne         $s2, $s1, L_8009CA1C
    if (ctx->r18 != ctx->r17) {
        // 0x8009CA30: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CA1C;
    }
    // 0x8009CA30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CA38:
    // 0x8009CA38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CA3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CA40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CA44: jr          $ra
    // 0x8009CA48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CA48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_asset_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CA4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009CA50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009CA54: addiu       $t6, $t6, 0x6CF0
    ctx->r14 = ADD32(ctx->r14, 0X6CF0);
    // 0x8009CA58: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8009CA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CA60: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009CA64: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x8009CA68: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8009CA6C: beq         $t9, $zero, L_8009CB48
    if (ctx->r25 == 0) {
        // 0x8009CA70: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009CB48;
    }
    // 0x8009CA70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009CA74: addiu       $t1, $t1, 0x6AF0
    ctx->r9 = ADD32(ctx->r9, 0X6AF0);
    // 0x8009CA78: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8009CA7C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8009CA80: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8009CA84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CA88: beq         $v0, $zero, L_8009CB20
    if (ctx->r2 == 0) {
        // 0x8009CA8C: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8009CB20;
    }
    // 0x8009CA8C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009CA90: lw          $t3, -0x330($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X330);
    // 0x8009CA94: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8009CA98: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009CA9C: lh          $v1, 0x0($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X0);
    // 0x8009CAA0: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CAA4: andi        $t6, $v1, 0xC000
    ctx->r14 = ctx->r3 & 0XC000;
    // 0x8009CAA8: bne         $t6, $at, L_8009CAE4
    if (ctx->r14 != ctx->r1) {
        // 0x8009CAAC: andi        $t8, $v1, 0x8000
        ctx->r24 = ctx->r3 & 0X8000;
            goto L_8009CAE4;
    }
    // 0x8009CAAC: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    // 0x8009CAB0: beq         $v0, $zero, L_8009CAE4
    if (ctx->r2 == 0) {
        // 0x8009CAB4: nop
    
            goto L_8009CAE4;
    }
    // 0x8009CAB4: nop

    // 0x8009CAB8: jal         0x800712F0
    // 0x8009CABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8009CABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009CAC0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009CAC4: nop

    // 0x8009CAC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8009CACC: jal         0x8007B70C
    // 0x8009CAD0: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x8009CAD0: nop

    after_1:
    // 0x8009CAD4: jal         0x800712F0
    // 0x8009CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_2;
    // 0x8009CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8009CADC: b           L_8009CB20
    // 0x8009CAE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CAE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CAE4:
    // 0x8009CAE4: beq         $t8, $zero, L_8009CAFC
    if (ctx->r24 == 0) {
        // 0x8009CAE8: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_8009CAFC;
    }
    // 0x8009CAE8: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8009CAEC: jal         0x8007D100
    // 0x8009CAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_3;
    // 0x8009CAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8009CAF4: b           L_8009CB20
    // 0x8009CAF8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CAF8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CAFC:
    // 0x8009CAFC: beq         $t9, $zero, L_8009CB14
    if (ctx->r25 == 0) {
        // 0x8009CB00: nop
    
            goto L_8009CB14;
    }
    // 0x8009CB00: nop

    // 0x8009CB04: jal         0x8000FFB8
    // 0x8009CB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_4;
    // 0x8009CB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8009CB0C: b           L_8009CB20
    // 0x8009CB10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009CB20;
    // 0x8009CB10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CB14:
    // 0x8009CB14: jal         0x80060180
    // 0x8009CB18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_5;
    // 0x8009CB18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8009CB1C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009CB20:
    // 0x8009CB20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009CB24: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8009CB28: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CB2C: addiu       $v0, $v0, -0x328
    ctx->r2 = ADD32(ctx->r2, -0X328);
    // 0x8009CB30: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8009CB34: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8009CB38: nop

    // 0x8009CB3C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009CB40: jal         0x8001004C
    // 0x8009CB44: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8009CB44: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    after_6:
L_8009CB48:
    // 0x8009CB48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009CB4C: lh          $t4, -0x328($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X328);
    // 0x8009CB50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009CB54: bne         $t4, $zero, L_8009CBAC
    if (ctx->r12 != 0) {
        // 0x8009CB58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CBAC;
    }
    // 0x8009CB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CB5C: lw          $a0, -0x324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X324);
    // 0x8009CB60: nop

    // 0x8009CB64: beq         $a0, $zero, L_8009CB7C
    if (ctx->r4 == 0) {
        // 0x8009CB68: nop
    
            goto L_8009CB7C;
    }
    // 0x8009CB68: nop

    // 0x8009CB6C: jal         0x80071380
    // 0x8009CB70: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8009CB70: nop

    after_7:
    // 0x8009CB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CB78: sw          $zero, -0x324($at)
    MEM_W(-0X324, ctx->r1) = 0;
L_8009CB7C:
    // 0x8009CB7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009CB80: lw          $a0, -0x330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X330);
    // 0x8009CB84: nop

    // 0x8009CB88: beq         $a0, $zero, L_8009CBAC
    if (ctx->r4 == 0) {
        // 0x8009CB8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CBAC;
    }
    // 0x8009CB8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CB90: jal         0x80071380
    // 0x8009CB94: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8009CB94: nop

    after_8:
    // 0x8009CB98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CB9C: sw          $zero, -0x330($at)
    MEM_W(-0X330, ctx->r1) = 0;
    // 0x8009CBA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CBA4: sh          $zero, -0x32C($at)
    MEM_H(-0X32C, ctx->r1) = 0;
    // 0x8009CBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CBAC:
    // 0x8009CBAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009CBB0: jr          $ra
    // 0x8009CBB4: nop

    return;
    // 0x8009CBB4: nop

;}
RECOMP_FUNC void menu_assetgroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CBBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CBC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009CBC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009CBC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CBCC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CBD0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CBD4: beq         $s2, $t6, L_8009CC04
    if (ctx->r18 == ctx->r14) {
        // 0x8009CBD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CC04;
    }
    // 0x8009CBD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CBDC: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CBE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CBE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CBE8:
    // 0x8009CBE8: jal         0x8009CC18
    // 0x8009CBEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_load(rdram, ctx);
        goto after_0;
    // 0x8009CBEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CBF0: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CBF4: nop

    // 0x8009CBF8: bne         $s2, $s1, L_8009CBE8
    if (ctx->r18 != ctx->r17) {
        // 0x8009CBFC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CBE8;
    }
    // 0x8009CBFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CC04:
    // 0x8009CC04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CC08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CC0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CC10: jr          $ra
    // 0x8009CC14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CC14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009CC1C: addiu       $t0, $t0, -0x330
    ctx->r8 = ADD32(ctx->r8, -0X330);
    // 0x8009CC20: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8009CC24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009CC28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CC2C: bne         $a2, $zero, L_8009CCC8
    if (ctx->r6 != 0) {
        // 0x8009CC30: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8009CCC8;
    }
    // 0x8009CC30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009CC34: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8009CC38: jal         0x80076EE4
    // 0x8009CC3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8009CC3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8009CC40: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009CC44: addiu       $a1, $a1, -0x32C
    ctx->r5 = ADD32(ctx->r5, -0X32C);
    // 0x8009CC48: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8009CC4C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009CC50: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009CC54: addiu       $t0, $t0, -0x330
    ctx->r8 = ADD32(ctx->r8, -0X330);
    // 0x8009CC58: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8009CC5C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8009CC60: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CC64: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009CC68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009CC6C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CC70: beq         $a0, $t8, L_8009CCA0
    if (ctx->r4 == ctx->r24) {
        // 0x8009CC74: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8009CCA0;
    }
    // 0x8009CC74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8009CC78: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009CC7C:
    // 0x8009CC7C: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8009CC80: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009CC84: nop

    // 0x8009CC88: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8009CC8C: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8009CC90: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8009CC94: nop

    // 0x8009CC98: bne         $a0, $t3, L_8009CC7C
    if (ctx->r4 != ctx->r11) {
        // 0x8009CC9C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8009CC7C;
    }
    // 0x8009CC9C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009CCA0:
    // 0x8009CCA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CCA4: blez        $v1, L_8009CCC8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009CCA8: sh          $zero, -0x328($at)
        MEM_H(-0X328, ctx->r1) = 0;
            goto L_8009CCC8;
    }
    // 0x8009CCA8: sh          $zero, -0x328($at)
    MEM_H(-0X328, ctx->r1) = 0;
    // 0x8009CCAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009CCB0: addiu       $v0, $t4, 0x6CF0
    ctx->r2 = ADD32(ctx->r12, 0X6CF0);
    // 0x8009CCB4: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8009CCB8:
    // 0x8009CCB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009CCBC: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8009CCC0: bne         $at, $zero, L_8009CCB8
    if (ctx->r1 != 0) {
        // 0x8009CCC4: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8009CCB8;
    }
    // 0x8009CCC4: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
L_8009CCC8:
    // 0x8009CCC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009CCCC: addiu       $t5, $t5, 0x6CF0
    ctx->r13 = ADD32(ctx->r13, 0X6CF0);
    // 0x8009CCD0: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x8009CCD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8009CCD8: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8009CCDC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8009CCE0: bne         $t8, $zero, L_8009CDD8
    if (ctx->r24 != 0) {
        // 0x8009CCE4: addu        $t1, $a2, $t9
        ctx->r9 = ADD32(ctx->r6, ctx->r25);
            goto L_8009CDD8;
    }
    // 0x8009CCE4: addu        $t1, $a2, $t9
    ctx->r9 = ADD32(ctx->r6, ctx->r25);
    // 0x8009CCE8: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009CCEC: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CCF0: andi        $t2, $v0, 0xC000
    ctx->r10 = ctx->r2 & 0XC000;
    // 0x8009CCF4: bne         $t2, $at, L_8009CD20
    if (ctx->r10 != ctx->r1) {
        // 0x8009CCF8: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_8009CD20;
    }
    // 0x8009CCF8: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x8009CCFC: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD00: jal         0x8007B2C4
    // 0x8009CD04: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8009CD04: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8009CD08: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD10: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8009CD14: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8009CD18: b           L_8009CDB8
    // 0x8009CD1C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD1C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD20:
    // 0x8009CD20: beq         $t4, $zero, L_8009CD50
    if (ctx->r12 == 0) {
        // 0x8009CD24: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_8009CD50;
    }
    // 0x8009CD24: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x8009CD28: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD30: jal         0x8007C57C
    // 0x8009CD34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x8009CD34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8009CD38: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD40: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8009CD44: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009CD48: b           L_8009CDB8
    // 0x8009CD4C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD4C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD50:
    // 0x8009CD50: beq         $t6, $zero, L_8009CD98
    if (ctx->r14 == 0) {
        // 0x8009CD54: andi        $a0, $v0, 0x3FFF
        ctx->r4 = ctx->r2 & 0X3FFF;
            goto L_8009CD98;
    }
    // 0x8009CD54: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD58: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8009CD5C: sb          $v0, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r2;
    // 0x8009CD60: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8009CD64: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8009CD68: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8009CD6C: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8009CD70: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009CD74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD78: jal         0x8000EA54
    // 0x8009CD7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8009CD7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_3:
    // 0x8009CD80: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD88: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8009CD8C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009CD90: b           L_8009CDB8
    // 0x8009CD94: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD94: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD98:
    // 0x8009CD98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD9C: jal         0x8005FB3C
    // 0x8009CDA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    object_model_init(rdram, ctx);
        goto after_4;
    // 0x8009CDA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009CDA4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CDA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CDAC: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8009CDB0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009CDB4: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CDB8:
    // 0x8009CDB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8009CDBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009CDC0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009CDC4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x8009CDC8: lh          $t4, -0x328($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X328);
    // 0x8009CDCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CDD0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009CDD4: sh          $t5, -0x328($at)
    MEM_H(-0X328, ctx->r1) = ctx->r13;
L_8009CDD8:
    // 0x8009CDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CDDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009CDE0: jr          $ra
    // 0x8009CDE4: nop

    return;
    // 0x8009CDE4: nop

;}
RECOMP_FUNC void menu_imagegroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CDE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CDEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CDF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009CDF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009CDF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CDFC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CE00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CE04: beq         $s2, $t6, L_8009CE34
    if (ctx->r18 == ctx->r14) {
        // 0x8009CE08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CE34;
    }
    // 0x8009CE08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CE0C: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CE10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CE14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CE18:
    // 0x8009CE18: jal         0x8009CE48
    // 0x8009CE1C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_image_load(rdram, ctx);
        goto after_0;
    // 0x8009CE1C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CE20: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CE24: nop

    // 0x8009CE28: bne         $s2, $s1, L_8009CE18
    if (ctx->r18 != ctx->r17) {
        // 0x8009CE2C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CE18;
    }
    // 0x8009CE2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CE30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CE34:
    // 0x8009CE34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CE38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CE3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE40: jr          $ra
    // 0x8009CE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_image_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CE48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009CE4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009CE50: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009CE54: addiu       $s1, $s1, -0x324
    ctx->r17 = ADD32(ctx->r17, -0X324);
    // 0x8009CE58: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8009CE5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009CE60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8009CE64: bne         $a2, $zero, L_8009CE84
    if (ctx->r6 != 0) {
        // 0x8009CE68: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8009CE84;
    }
    // 0x8009CE68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009CE6C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8009CE70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8009CE74: jal         0x80070EDC
    // 0x8009CE78: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8009CE78: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    after_0:
    // 0x8009CE7C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009CE80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8009CE84:
    // 0x8009CE84: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009CE88: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009CE8C: addiu       $t7, $t7, -0x570
    ctx->r15 = ADD32(ctx->r15, -0X570);
    // 0x8009CE90: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x8009CE94: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8009CE98: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8009CE9C: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x8009CEA0: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8009CEA4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEA8: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x8009CEAC: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8009CEB0: sh          $t0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r8;
    // 0x8009CEB4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEB8: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x8009CEBC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8009CEC0: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x8009CEC4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEC8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009CECC: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x8009CED0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8009CED4: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x8009CED8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEDC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009CEE0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8009CEE4: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8009CEE8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEEC: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8009CEF0: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x8009CEF4: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009CEF8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEFC: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8009CF00: addu        $t3, $t4, $s0
    ctx->r11 = ADD32(ctx->r12, ctx->r16);
    // 0x8009CF04: swc1        $f8, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f8.u32l;
    // 0x8009CF08: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF0C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009CF10: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8009CF14: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x8009CF18: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF1C: lh          $t6, 0x18($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X18);
    // 0x8009CF20: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8009CF24: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x8009CF28: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009CF2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF30: jal         0x8006FB8C
    // 0x8009CF34: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009CF34: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_1:
    // 0x8009CF38: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF40: addu        $t0, $t1, $s0
    ctx->r8 = ADD32(ctx->r9, ctx->r16);
    // 0x8009CF44: sb          $v0, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r2;
    // 0x8009CF48: jal         0x8006FB8C
    // 0x8009CF4C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8009CF4C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8009CF50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF58: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x8009CF5C: sb          $v0, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r2;
    // 0x8009CF60: jal         0x8006FB8C
    // 0x8009CF64: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8009CF64: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8009CF68: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009CF70: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x8009CF74: sb          $v0, 0x1C($t5)
    MEM_B(0X1C, ctx->r13) = ctx->r2;
    // 0x8009CF78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF7C: lb          $t7, 0x1D($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D);
    // 0x8009CF80: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8009CF84: sb          $t7, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r15;
    // 0x8009CF88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CF8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8009CF90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8009CF94: jr          $ra
    // 0x8009CF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009CF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menu_imagegroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF9C: jr          $ra
    // 0x8009CFA0: nop

    return;
    // 0x8009CFA0: nop

;}
RECOMP_FUNC void menu_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFA4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CFA8: addiu       $t3, $t3, -0x324
    ctx->r11 = ADD32(ctx->r11, -0X324);
    // 0x8009CFAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009CFB0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8009CFB4: sll         $t0, $a0, 5
    ctx->r8 = S32(ctx->r4 << 5);
    // 0x8009CFB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CFBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009CFC0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009CFC4: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8009CFC8: lh          $a1, 0x6($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X6);
    // 0x8009CFCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009CFD0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8009CFD4: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8009CFD8: lw          $t2, 0x6AF0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6AF0);
    // 0x8009CFDC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009CFE0: beq         $t2, $zero, L_8009D2B4
    if (ctx->r10 == 0) {
        // 0x8009CFE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009D2B4;
    }
    // 0x8009CFE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CFE8: lw          $t9, -0x330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X330);
    // 0x8009CFEC: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x8009CFF0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8009CFF4: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009CFF8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CFFC: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x8009D000: beq         $t6, $at, L_8009D2B0
    if (ctx->r14 == ctx->r1) {
        // 0x8009D004: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_8009D2B0;
    }
    // 0x8009D004: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8009D008: beq         $t7, $zero, L_8009D0A8
    if (ctx->r15 == 0) {
        // 0x8009D00C: andi        $t5, $v0, 0x8000
        ctx->r13 = ctx->r2 & 0X8000;
            goto L_8009D0A8;
    }
    // 0x8009D00C: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x8009D010: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009D014: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8009D018: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8009D01C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D020: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8009D024: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8009D028: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D02C: sh          $t5, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r13;
    // 0x8009D030: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009D034: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D038: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x8009D03C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009D040: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D044: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8009D048: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009D04C: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8009D050: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009D054: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009D058: addiu       $a0, $s0, 0x693C
    ctx->r4 = ADD32(ctx->r16, 0X693C);
    // 0x8009D05C: swc1        $f8, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f8.u32l;
    // 0x8009D060: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009D064: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D068: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8009D06C: lw          $t7, -0x618($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X618);
    // 0x8009D070: addiu       $a2, $a2, 0x694C
    ctx->r6 = ADD32(ctx->r6, 0X694C);
    // 0x8009D074: bne         $t7, $zero, L_8009D094
    if (ctx->r15 != 0) {
        // 0x8009D078: addiu       $a1, $a1, 0x6944
        ctx->r5 = ADD32(ctx->r5, 0X6944);
            goto L_8009D094;
    }
    // 0x8009D078: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D07C: lb          $t8, 0x1D($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D);
    // 0x8009D080: nop

    // 0x8009D084: sh          $t8, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r24;
    // 0x8009D088: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8009D08C: nop

    // 0x8009D090: sb          $t9, 0x3A($t2)
    MEM_B(0X3A, ctx->r10) = ctx->r25;
L_8009D094:
    // 0x8009D094: lw          $t4, -0x31C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X31C);
    // 0x8009D098: jal         0x80012D5C
    // 0x8009D09C: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    render_object(rdram, ctx);
        goto after_0;
    // 0x8009D09C: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    after_0:
    // 0x8009D0A0: b           L_8009D2B4
    // 0x8009D0A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8009D2B4;
    // 0x8009D0A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009D0A8:
    // 0x8009D0A8: beq         $t5, $zero, L_8009D17C
    if (ctx->r13 == 0) {
        // 0x8009D0AC: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009D17C;
    }
    // 0x8009D0AC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D0B0: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D0B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D0B8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009D0BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D0C0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D0C4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D0C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D0CC: lbu         $t9, -0x5DC($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X5DC);
    // 0x8009D0D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D0D4: lbu         $t6, -0x5D8($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X5D8);
    // 0x8009D0D8: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x8009D0DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8009D0E0: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8009D0E4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009D0E8: lbu         $t5, -0x5D4($t9)
    ctx->r13 = MEM_BU(ctx->r25, -0X5D4);
    // 0x8009D0EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D0F0: lw          $t7, -0x31C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X31C);
    // 0x8009D0F4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8009D0F8: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x8009D0FC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8009D100: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x8009D104: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009D108: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D10C: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8009D110: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D114: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009D118: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8009D11C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D120: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D124: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009D128: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D12C: lw          $t8, -0x5CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5CC);
    // 0x8009D130: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8009D134: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D138: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D13C: sll         $t9, $t4, 5
    ctx->r25 = S32(ctx->r12 << 5);
    // 0x8009D140: addiu       $a2, $a2, 0x694C
    ctx->r6 = ADD32(ctx->r6, 0X694C);
    // 0x8009D144: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D148: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009D14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D150: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009D154: jal         0x80068E34
    // 0x8009D158: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    render_ortho_triangle_image(rdram, ctx);
        goto after_1;
    // 0x8009D158: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    after_1:
    // 0x8009D15C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D160: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009D164: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D168: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D16C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8009D170: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009D174: b           L_8009D2B0
    // 0x8009D178: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8009D2B0;
    // 0x8009D178: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8009D17C:
    // 0x8009D17C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009D180: addiu       $t1, $t1, -0x31C
    ctx->r9 = ADD32(ctx->r9, -0X31C);
    // 0x8009D184: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8009D188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D18C: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8009D190: beq         $at, $zero, L_8009D1CC
    if (ctx->r1 == 0) {
        // 0x8009D194: addiu       $a1, $a1, 0x6944
        ctx->r5 = ADD32(ctx->r5, 0X6944);
            goto L_8009D1CC;
    }
    // 0x8009D194: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D198: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D19C: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D1A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1A4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8009D1A8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8009D1AC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009D1B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009D1B4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009D1B8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009D1BC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8009D1C0: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x8009D1C4: b           L_8009D1F0
    // 0x8009D1C8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_8009D1F0;
    // 0x8009D1C8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_8009D1CC:
    // 0x8009D1CC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D1D0: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D1D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1D8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8009D1DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D1E0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009D1E4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009D1E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009D1EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8009D1F0:
    // 0x8009D1F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1F4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8009D1F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D1FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D200: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x8009D204: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009D208: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D20C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009D210: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8009D214: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009D218: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009D21C: lw          $a3, -0x62C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X62C);
    // 0x8009D220: sll         $t5, $t9, 5
    ctx->r13 = S32(ctx->r25 << 5);
    // 0x8009D224: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8009D228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D22C: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x8009D230: jal         0x800696C4
    // 0x8009D234: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8009D234: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8009D238: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009D23C: addiu       $t3, $t3, -0x324
    ctx->r11 = ADD32(ctx->r11, -0X324);
    // 0x8009D240: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009D244: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8009D248: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D24C: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8009D250: lh          $t4, 0x6($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X6);
    // 0x8009D254: nop

    // 0x8009D258: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8009D25C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8009D260: lw          $v0, 0x6AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AF0);
    // 0x8009D264: nop

    // 0x8009D268: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D26C: jal         0x8009D2C0
    // 0x8009D270: nop

    render_track_selection_viewport_border(rdram, ctx);
        goto after_3;
    // 0x8009D270: nop

    after_3:
    // 0x8009D274: jal         0x80069C80
    // 0x8009D278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_4;
    // 0x8009D278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009D27C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D280: lw          $t5, -0x31C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X31C);
    // 0x8009D284: nop

    // 0x8009D288: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x8009D28C: beq         $at, $zero, L_8009D2B4
    if (ctx->r1 == 0) {
        // 0x8009D290: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009D2B4;
    }
    // 0x8009D290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009D294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D298: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8009D29C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D2A0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009D2A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009D2A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D2AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8009D2B0:
    // 0x8009D2B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009D2B4:
    // 0x8009D2B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009D2B8: jr          $ra
    // 0x8009D2BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009D2BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void render_track_selection_viewport_border(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D2C0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009D2C4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D2C8: lw          $t7, -0x31C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X31C);
    // 0x8009D2CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009D2D0: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8009D2D4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8009D2D8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8009D2DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009D2E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009D2E4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009D2E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009D2EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009D2F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009D2F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009D2F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009D2FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D300: beq         $t7, $at, L_8009D310
    if (ctx->r15 == ctx->r1) {
        // 0x8009D304: sw          $t6, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r14;
            goto L_8009D310;
    }
    // 0x8009D304: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8009D308: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8009D30C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_8009D310:
    // 0x8009D310: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009D314: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8009D318: blez        $a2, L_8009D47C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009D31C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8009D47C;
    }
    // 0x8009D31C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8009D320: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009D324: addiu       $s1, $s1, 0x693C
    ctx->r17 = ADD32(ctx->r17, 0X693C);
L_8009D328:
    // 0x8009D328: lw          $t9, 0x38($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X38);
    // 0x8009D32C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009D330: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x8009D334: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8009D338: nop

    // 0x8009D33C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x8009D340: bne         $t3, $zero, L_8009D46C
    if (ctx->r11 != 0) {
        // 0x8009D344: nop
    
            goto L_8009D46C;
    }
    // 0x8009D344: nop

    // 0x8009D348: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8009D34C: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x8009D350: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009D354: lh          $t4, 0xE($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE);
    // 0x8009D358: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8009D35C: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x8009D360: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x8009D364: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009D368: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8009D36C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8009D370: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8009D374: subu        $s0, $t4, $v1
    ctx->r16 = SUB32(ctx->r12, ctx->r3);
    // 0x8009D378: subu        $s2, $t5, $a0
    ctx->r18 = SUB32(ctx->r13, ctx->r4);
    // 0x8009D37C: addu        $fp, $t6, $t7
    ctx->r30 = ADD32(ctx->r14, ctx->r15);
    // 0x8009D380: bne         $a1, $at, L_8009D398
    if (ctx->r5 != ctx->r1) {
        // 0x8009D384: addu        $t0, $t8, $t9
        ctx->r8 = ADD32(ctx->r24, ctx->r25);
            goto L_8009D398;
    }
    // 0x8009D384: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8009D388: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009D38C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8009D390: b           L_8009D3B8
    // 0x8009D394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8009D3B8;
    // 0x8009D394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8009D398:
    // 0x8009D398: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8009D39C: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x8009D3A0: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8009D3A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009D3A8: sll         $t5, $a3, 14
    ctx->r13 = S32(ctx->r7 << 14);
    // 0x8009D3AC: lw          $s3, 0x0($t4)
    ctx->r19 = MEM_W(ctx->r12, 0X0);
    // 0x8009D3B0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009D3B4: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
L_8009D3B8:
    // 0x8009D3B8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8009D3BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009D3C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8009D3C4: jal         0x8007B938
    // 0x8009D3C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8009D3C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x8009D3CC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009D3D0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8009D3D4: addu        $a0, $fp, $t1
    ctx->r4 = ADD32(ctx->r30, ctx->r9);
    // 0x8009D3D8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8009D3DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D3E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8009D3E4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8009D3E8: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x8009D3EC: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x8009D3F0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8009D3F4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8009D3F8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009D3FC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8009D400: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8009D404: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009D408: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8009D40C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8009D410: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8009D414: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8009D418: or          $t3, $t5, $t2
    ctx->r11 = ctx->r13 | ctx->r10;
    // 0x8009D41C: addiu       $t6, $s2, -0x1
    ctx->r14 = ADD32(ctx->r18, -0X1);
    // 0x8009D420: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009D424: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8009D428: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009D42C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8009D430: or          $t8, $t7, $s4
    ctx->r24 = ctx->r15 | ctx->r20;
    // 0x8009D434: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8009D438: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009D43C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8009D440: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8009D444: sll         $t3, $s2, 4
    ctx->r11 = S32(ctx->r18 << 4);
    // 0x8009D448: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8009D44C: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x8009D450: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8009D454: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8009D458: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x8009D45C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D460: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D464: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009D468: nop

L_8009D46C:
    // 0x8009D46C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009D470: slt         $at, $s6, $a2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8009D474: bne         $at, $zero, L_8009D328
    if (ctx->r1 != 0) {
        // 0x8009D478: addiu       $s7, $s7, 0xC
        ctx->r23 = ADD32(ctx->r23, 0XC);
            goto L_8009D328;
    }
    // 0x8009D478: addiu       $s7, $s7, 0xC
    ctx->r23 = ADD32(ctx->r23, 0XC);
L_8009D47C:
    // 0x8009D47C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009D480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D484: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D488: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009D48C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009D490: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009D494: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009D498: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009D49C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009D4A0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009D4A4: jr          $ra
    // 0x8009D4A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8009D4A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void dialogue_npc_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D4B0: addiu       $t6, $t6, -0x59C
    ctx->r14 = ADD32(ctx->r14, -0X59C);
    // 0x8009D4B4: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8009D4B8: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8009D4BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D4C0: bne         $t7, $zero, L_8009D4EC
    if (ctx->r15 != 0) {
        // 0x8009D4C4: addiu       $t8, $t8, -0x599
        ctx->r24 = ADD32(ctx->r24, -0X599);
            goto L_8009D4EC;
    }
    // 0x8009D4C4: addiu       $t8, $t8, -0x599
    ctx->r24 = ADD32(ctx->r24, -0X599);
    // 0x8009D4C8: beq         $v0, $t8, L_8009D4E0
    if (ctx->r2 == ctx->r24) {
        // 0x8009D4CC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009D4E0;
    }
    // 0x8009D4CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009D4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D4D4: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
    // 0x8009D4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D4DC: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009D4E0:
    // 0x8009D4E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D4E4: sb          $v1, -0x5A0($at)
    MEM_B(-0X5A0, ctx->r1) = ctx->r3;
    // 0x8009D4E8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8009D4EC:
    // 0x8009D4EC: jr          $ra
    // 0x8009D4F0: nop

    return;
    // 0x8009D4F0: nop

;}
RECOMP_FUNC void dialogue_try_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009D4F8: addiu       $v0, $v0, -0x5A0
    ctx->r2 = ADD32(ctx->r2, -0X5A0);
    // 0x8009D4FC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D504: beq         $t6, $zero, L_8009D520
    if (ctx->r14 == 0) {
        // 0x8009D508: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009D520;
    }
    // 0x8009D508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D50C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8009D510: jal         0x800C5B80
    // 0x8009D514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x8009D514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009D518: jal         0x8009C3A0
    // 0x8009D51C: nop

    reset_controller_sticks(rdram, ctx);
        goto after_1;
    // 0x8009D51C: nop

    after_1:
L_8009D520:
    // 0x8009D520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D528: jr          $ra
    // 0x8009D52C: nop

    return;
    // 0x8009D52C: nop

;}
RECOMP_FUNC void npc_dialogue_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D530: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D53C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009D540: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009D544: jal         0x800C3958
    // 0x8009D548: sb          $zero, -0x59C($at)
    MEM_B(-0X59C, ctx->r1) = 0;
    textbox_visible(rdram, ctx);
        goto after_0;
    // 0x8009D548: sb          $zero, -0x59C($at)
    MEM_B(-0X59C, ctx->r1) = 0;
    after_0:
    // 0x8009D54C: beq         $v0, $zero, L_8009D56C
    if (ctx->r2 == 0) {
        // 0x8009D550: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8009D56C;
    }
    // 0x8009D550: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D554: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009D558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D55C: beq         $t7, $at, L_8009D56C
    if (ctx->r15 == ctx->r1) {
        // 0x8009D560: nop
    
            goto L_8009D56C;
    }
    // 0x8009D560: nop

    // 0x8009D564: b           L_8009D64C
    // 0x8009D568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D64C;
    // 0x8009D568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D56C:
    // 0x8009D56C: lb          $t8, -0x5A0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X5A0);
    // 0x8009D570: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009D574: beq         $t8, $zero, L_8009D584
    if (ctx->r24 == 0) {
        // 0x8009D578: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009D584;
    }
    // 0x8009D578: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D57C: b           L_8009D64C
    // 0x8009D580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D64C;
    // 0x8009D580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D584:
    // 0x8009D584: beq         $t9, $at, L_8009D594
    if (ctx->r25 == ctx->r1) {
        // 0x8009D588: nop
    
            goto L_8009D594;
    }
    // 0x8009D588: nop

    // 0x8009D58C: jal         0x8006F5C8
    // 0x8009D590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_1;
    // 0x8009D590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8009D594:
    // 0x8009D594: jal         0x8009C464
    // 0x8009D598: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x8009D598: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x8009D59C: jal         0x800C59F4
    // 0x8009D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x8009D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8009D5A4: jal         0x800C5B54
    // 0x8009D5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    open_dialogue_box(rdram, ctx);
        goto after_4;
    // 0x8009D5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8009D5AC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8009D5B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009D5B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D5B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D5BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D5C0: jal         0x800C551C
    // 0x8009D5C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x8009D5C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8009D5C8: jal         0x8001F484
    // 0x8009D5CC: nop

    func_8001F450(rdram, ctx);
        goto after_6;
    // 0x8009D5CC: nop

    after_6:
    // 0x8009D5D0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8009D5D4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009D5D8: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8009D5DC: beq         $at, $zero, L_8009D648
    if (ctx->r1 == 0) {
        // 0x8009D5E0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8009D648;
    }
    // 0x8009D5E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8009D5E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009D5E8: addu        $at, $at, $t1
    gpr jr_addend_8009D5F4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009D5EC: lw          $t1, -0x74E8($at)
    ctx->r9 = ADD32(ctx->r1, -0X74E8);
    // 0x8009D5F0: nop

    // 0x8009D5F4: jr          $t1
    // 0x8009D5F8: nop

    switch (jr_addend_8009D5F4 >> 2) {
        case 0: goto L_8009D5FC; break;
        case 1: goto L_8009D648; break;
        case 2: goto L_8009D60C; break;
        case 3: goto L_8009D61C; break;
        case 4: goto L_8009D62C; break;
        case 5: goto L_8009D63C; break;
        default: switch_error(__func__, 0x8009D5F4, 0x800E8B18);
    }
    // 0x8009D5F8: nop

L_8009D5FC:
    // 0x8009D5FC: jal         0x8009D8A4
    // 0x8009D600: nop

    taj_menu_loop(rdram, ctx);
        goto after_7;
    // 0x8009D600: nop

    after_7:
    // 0x8009D604: b           L_8009D648
    // 0x8009D608: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D608: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D60C:
    // 0x8009D60C: jal         0x8009E080
    // 0x8009D610: nop

    tt_menu_loop(rdram, ctx);
        goto after_8;
    // 0x8009D610: nop

    after_8:
    // 0x8009D614: b           L_8009D648
    // 0x8009D618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D61C:
    // 0x8009D61C: jal         0x800C3ABC
    // 0x8009D620: nop

    dialogue_challenge_loop(rdram, ctx);
        goto after_9;
    // 0x8009D620: nop

    after_9:
    // 0x8009D624: b           L_8009D648
    // 0x8009D628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D62C:
    // 0x8009D62C: jal         0x8009ED2C
    // 0x8009D630: nop

    trophy_race_cabinet_menu_loop(rdram, ctx);
        goto after_10;
    // 0x8009D630: nop

    after_10:
    // 0x8009D634: b           L_8009D648
    // 0x8009D638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D648;
    // 0x8009D638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D63C:
    // 0x8009D63C: jal         0x8009DF38
    // 0x8009D640: nop

    dialogue_race_defeat(rdram, ctx);
        goto after_11;
    // 0x8009D640: nop

    after_11:
    // 0x8009D644: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D648:
    // 0x8009D648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009D64C:
    // 0x8009D64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D654: jr          $ra
    // 0x8009D658: nop

    return;
    // 0x8009D658: nop

;}
RECOMP_FUNC void set_option_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D65C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D660: bne         $a0, $zero, L_8009D6C4
    if (ctx->r4 != 0) {
        // 0x8009D664: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009D6C4;
    }
    // 0x8009D664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D668: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8009D66C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009D670: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009D674: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009D678: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D67C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D684: jal         0x800C5560
    // 0x8009D688: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D688: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_0:
    // 0x8009D68C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D690: lb          $t8, -0x594($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X594);
    // 0x8009D694: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D698: beq         $t8, $zero, L_8009D6E8
    if (ctx->r24 == 0) {
        // 0x8009D69C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009D6E8;
    }
    // 0x8009D69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D6A0: addiu       $t9, $zero, 0x5A
    ctx->r25 = ADD32(0, 0X5A);
    // 0x8009D6A4: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x8009D6A8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009D6AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D6B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D6B4: jal         0x800C5560
    // 0x8009D6B8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_1;
    // 0x8009D6B8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_1:
    // 0x8009D6BC: b           L_8009D6EC
    // 0x8009D6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D6EC;
    // 0x8009D6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D6C4:
    // 0x8009D6C4: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x8009D6C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009D6CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D6D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D6D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D6D8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x8009D6DC: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8009D6E0: jal         0x800C5560
    // 0x8009D6E4: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x8009D6E4: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    after_2:
L_8009D6E8:
    // 0x8009D6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D6EC:
    // 0x8009D6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D6F0: sb          $zero, -0x594($at)
    MEM_B(-0X594, ctx->r1) = 0;
    // 0x8009D6F4: jr          $ra
    // 0x8009D6F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D6F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void render_dialogue_option(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D6FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009D700: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009D704: lb          $t7, 0x6A78($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6A78);
    // 0x8009D708: lb          $t6, 0x6AA4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6AA4);
    // 0x8009D70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D710: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009D714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D718: xor         $a0, $t6, $t7
    ctx->r4 = ctx->r14 ^ ctx->r15;
    // 0x8009D71C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009D720: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009D724: jal         0x8009D65C
    // 0x8009D728: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D728: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    after_0:
    // 0x8009D72C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D730: addiu       $v0, $v0, 0x6AA4
    ctx->r2 = ADD32(ctx->r2, 0X6AA4);
    // 0x8009D734: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009D738: lb          $t9, 0x6A78($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6A78);
    // 0x8009D73C: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8009D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D744: bne         $t8, $t9, L_8009D758
    if (ctx->r24 != ctx->r25) {
        // 0x8009D748: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_8009D758;
    }
    // 0x8009D748: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D74C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8009D750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D754: sb          $t0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r8;
L_8009D758:
    // 0x8009D758: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D75C: lb          $a2, 0x6AAE($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X6AAE);
    // 0x8009D760: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009D764: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D768: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D76C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D770: jal         0x800C56C8
    // 0x8009D774: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    render_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x8009D774: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x8009D778: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D77C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D780: addiu       $v1, $v1, 0x6AAE
    ctx->r3 = ADD32(ctx->r3, 0X6AAE);
    // 0x8009D784: addiu       $v0, $v0, 0x6AA4
    ctx->r2 = ADD32(ctx->r2, 0X6AA4);
    // 0x8009D788: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8009D78C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009D790: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D798: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009D79C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D7A0: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8009D7A4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D7A8: jr          $ra
    // 0x8009D7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void handle_menu_joystick_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D7B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D7B4: lb          $v0, 0x6A04($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6A04);
    // 0x8009D7B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D7BC: bgez        $v0, L_8009D7EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D7C0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009D7EC;
    }
    // 0x8009D7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D7C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D7C8: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, 0X6A78);
    // 0x8009D7CC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D7D0: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D7D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D7D8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D7DC: jal         0x80001D04
    // 0x8009D7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8009D7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009D7E4: b           L_8009D810
    // 0x8009D7E8: nop

        goto L_8009D810;
    // 0x8009D7E8: nop

L_8009D7EC:
    // 0x8009D7EC: blez        $v0, L_8009D810
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009D7F0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8009D810;
    }
    // 0x8009D7F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009D7F4: lb          $t8, 0x6A78($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6A78);
    // 0x8009D7F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D7FC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8009D800: sb          $t9, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r25;
    // 0x8009D804: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D808: jal         0x80001D04
    // 0x8009D80C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8009D80C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8009D810:
    // 0x8009D810: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D814: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009D818: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D81C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009D820: bgez        $v0, L_8009D840
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D824: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8009D840;
    }
    // 0x8009D824: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009D828: lb          $t0, 0x6AA4($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6AA4);
    // 0x8009D82C: nop

    // 0x8009D830: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8009D834: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8009D838: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D83C: nop

L_8009D840:
    // 0x8009D840: lb          $t2, 0x6AA4($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6AA4);
    // 0x8009D844: nop

    // 0x8009D848: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009D84C: bne         $at, $zero, L_8009D85C
    if (ctx->r1 != 0) {
        // 0x8009D850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009D85C;
    }
    // 0x8009D850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D854: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009D858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009D85C:
    // 0x8009D85C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D860: jr          $ra
    // 0x8009D864: nop

    return;
    // 0x8009D864: nop

;}
RECOMP_FUNC void func_8009D324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D86C: jr          $ra
    // 0x8009D870: sb          $zero, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = 0;
    return;
    // 0x8009D870: sb          $zero, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = 0;
;}
