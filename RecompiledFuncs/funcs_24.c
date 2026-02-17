#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80080BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008101C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80081020: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80081024: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80081028: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008102C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081030: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081034: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008103C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80081040: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081044: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80081048: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008104C: addiu       $t8, $t8, 0x21F0
    ctx->r24 = ADD32(ctx->r24, 0X21F0);
    // 0x80081050: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80081054: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80081058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008105C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80081060: lw          $t1, 0x2338($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2338);
    // 0x80081064: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80081068: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8008106C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80081070: blez        $t1, L_8008126C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80081074: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8008126C;
    }
    // 0x80081074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80081078: lui         $s6, 0xE
    ctx->r22 = S32(0XE << 16);
    // 0x8008107C: lui         $s1, 0xE
    ctx->r17 = S32(0XE << 16);
    // 0x80081080: lui         $ra, 0x702
    ctx->r31 = S32(0X702 << 16);
    // 0x80081084: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80081088: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008108C: addiu       $t2, $t2, 0x2334
    ctx->r10 = ADD32(ctx->r10, 0X2334);
    // 0x80081090: addiu       $t3, $t3, 0x71EC
    ctx->r11 = ADD32(ctx->r11, 0X71EC);
    // 0x80081094: ori         $ra, $ra, 0x10
    ctx->r31 = ctx->r31 | 0X10;
    // 0x80081098: addiu       $s1, $s1, 0x2230
    ctx->r17 = ADD32(ctx->r17, 0X2230);
    // 0x8008109C: addiu       $s6, $s6, 0x2220
    ctx->r22 = ADD32(ctx->r22, 0X2220);
    // 0x800810A0: lui         $s5, 0x500
    ctx->r21 = S32(0X500 << 16);
    // 0x800810A4: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
    // 0x800810A8: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x800810AC: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x800810B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800810B4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
L_800810B8:
    // 0x800810B8: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800810BC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800810C0: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x800810C4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800810C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800810CC: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800810D0: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x800810D4: nop

    // 0x800810D8: bne         $t6, $zero, L_8008125C
    if (ctx->r14 != 0) {
        // 0x800810DC: nop
    
            goto L_8008125C;
    }
    // 0x800810DC: nop

    // 0x800810E0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800810E4: nop

    // 0x800810E8: beq         $v1, $zero, L_80081160
    if (ctx->r3 == 0) {
        // 0x800810EC: nop
    
            goto L_80081160;
    }
    // 0x800810EC: nop

    // 0x800810F0: beq         $t0, $s0, L_80081110
    if (ctx->r8 == ctx->r16) {
        // 0x800810F4: nop
    
            goto L_80081110;
    }
    // 0x800810F4: nop

    // 0x800810F8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800810FC: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80081100: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80081104: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80081108: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8008110C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80081110:
    // 0x80081110: beq         $t5, $v1, L_80081180
    if (ctx->r13 == ctx->r3) {
        // 0x80081114: nop
    
            goto L_80081180;
    }
    // 0x80081114: nop

    // 0x80081118: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008111C: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x80081120: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80081124: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80081128: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x8008112C: nop

    // 0x80081130: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80081134: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80081138: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x8008113C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80081140: or          $t8, $t6, $s2
    ctx->r24 = ctx->r14 | ctx->r18;
    // 0x80081144: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80081148: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008114C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80081150: nop

    // 0x80081154: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80081158: b           L_80081180
    // 0x8008115C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80081180;
    // 0x8008115C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80081160:
    // 0x80081160: beq         $t0, $zero, L_80081180
    if (ctx->r8 == 0) {
        // 0x80081164: nop
    
            goto L_80081180;
    }
    // 0x80081164: nop

    // 0x80081168: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008116C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80081170: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80081174: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80081178: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8008117C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80081180:
    // 0x80081180: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80081184: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x80081188: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008118C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80081190: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80081194: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80081198: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008119C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800811A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800811A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800811A8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800811AC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800811B0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800811B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800811B8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800811BC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800811C0: nop

    // 0x800811C4: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x800811C8: andi        $t8, $t6, 0x6
    ctx->r24 = ctx->r14 & 0X6;
    // 0x800811CC: ori         $t9, $t8, 0x98
    ctx->r25 = ctx->r24 | 0X98;
    // 0x800811D0: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800811D4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800811D8: or          $t8, $t6, $s4
    ctx->r24 = ctx->r14 | ctx->r20;
    // 0x800811DC: ori         $t9, $t8, 0x170
    ctx->r25 = ctx->r24 | 0X170;
    // 0x800811E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800811E4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800811E8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800811EC: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x800811F0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800811F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800811F8: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800811FC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80081200: ori         $t6, $t0, 0x90
    ctx->r14 = ctx->r8 | 0X90;
    // 0x80081204: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80081208: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008120C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80081210: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80081214: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80081218: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8008121C: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80081220: or          $t7, $t8, $s5
    ctx->r15 = ctx->r24 | ctx->r21;
    // 0x80081224: ori         $t6, $t7, 0xA0
    ctx->r14 = ctx->r15 | 0XA0;
    // 0x80081228: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008122C: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80081230: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80081234: sll         $t8, $a3, 5
    ctx->r24 = S32(ctx->r7 << 5);
    // 0x80081238: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8008123C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80081240: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80081244: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80081248: nop

    // 0x8008124C: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80081250: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80081254: lw          $t1, 0x2338($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2338);
    // 0x80081258: nop

L_8008125C:
    // 0x8008125C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80081260: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80081264: bne         $at, $zero, L_800810B8
    if (ctx->r1 != 0) {
        // 0x80081268: nop
    
            goto L_800810B8;
    }
    // 0x80081268: nop

L_8008126C:
    // 0x8008126C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80081270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081274: addiu       $t2, $t2, 0x2334
    ctx->r10 = ADD32(ctx->r10, 0X2334);
    // 0x80081278: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x8008127C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80081280: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80081284: subu        $t8, $s0, $t9
    ctx->r24 = SUB32(ctx->r16, ctx->r25);
    // 0x80081288: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8008128C: jal         0x8007B820
    // 0x80081290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80081290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80081294: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80081298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008129C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800812A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800812A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800812A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800812AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800812B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800812B4: jr          $ra
    // 0x800812B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800812B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void menu_geometry_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800812BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800812C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800812C4: addiu       $v0, $v0, 0x2334
    ctx->r2 = ADD32(ctx->r2, 0X2334);
    // 0x800812C8: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x800812CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800812D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800812D4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800812D8: jr          $ra
    // 0x800812DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800812DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_80080E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800812E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800812E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800812E8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800812EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800812F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800812F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800812F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800812FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081300: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081304: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008130C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80081310: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081314: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081318: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8008131C: addiu       $t8, $t8, 0x21F0
    ctx->r24 = ADD32(ctx->r24, 0X21F0);
    // 0x80081320: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80081324: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80081328: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008132C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80081330: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x80081334: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80081338: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8008133C: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80081340: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80081344: addiu       $t7, $t7, 0x2240
    ctx->r15 = ADD32(ctx->r15, 0X2240);
    // 0x80081348: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8008134C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80081350: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80081354: lw          $fp, 0x54($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X54);
    // 0x80081358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008135C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80081360: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80081364: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80081368: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8008136C: lui         $s1, 0xF600
    ctx->r17 = S32(0XF600 << 16);
L_80081370:
    // 0x80081370: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80081374: addiu       $t6, $t6, 0x2348
    ctx->r14 = ADD32(ctx->r14, 0X2348);
    // 0x80081378: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8008137C: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80081380: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80081384: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x80081388: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8008138C: lh          $ra, 0x6($v0)
    ctx->r31 = MEM_H(ctx->r2, 0X6);
    // 0x80081390: or          $t1, $s5, $zero
    ctx->r9 = ctx->r21 | 0;
    // 0x80081394: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80081398: beq         $s4, $zero, L_800813D8
    if (ctx->r20 == 0) {
        // 0x8008139C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800813D8;
    }
    // 0x8008139C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800813A0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800813A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800813A8: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
    // 0x800813AC: beq         $s4, $at, L_800813EC
    if (ctx->r20 == ctx->r1) {
        // 0x800813B0: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_800813EC;
    }
    // 0x800813B0: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800813B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800813B8: beq         $s4, $at, L_8008140C
    if (ctx->r20 == ctx->r1) {
        // 0x800813BC: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8008140C;
    }
    // 0x800813BC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800813C0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800813C4: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800813C8: addiu       $a3, $s5, 0x1
    ctx->r7 = ADD32(ctx->r21, 0X1);
    // 0x800813CC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800813D0: b           L_8008141C
    // 0x800813D4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_8008141C;
    // 0x800813D4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_800813D8:
    // 0x800813D8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800813DC: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x800813E0: addiu       $t0, $s3, 0x1
    ctx->r8 = ADD32(ctx->r19, 0X1);
    // 0x800813E4: b           L_8008141C
    // 0x800813E8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
        goto L_8008141C;
    // 0x800813E8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_800813EC:
    // 0x800813EC: addu        $t1, $s5, $s6
    ctx->r9 = ADD32(ctx->r21, ctx->r22);
    // 0x800813F0: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800813F4: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800813F8: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800813FC: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80081400: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80081404: b           L_8008141C
    // 0x80081408: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_8008141C;
    // 0x80081408: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_8008140C:
    // 0x8008140C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80081410: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80081414: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80081418: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_8008141C:
    // 0x8008141C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081420: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80081424: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80081428: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008142C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80081430: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80081434: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80081438: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8008143C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80081440: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80081444: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80081448: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8008144C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80081450: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80081454: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80081458: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8008145C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80081460: blez        $s2, L_800815EC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80081464: sw          $t9, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r25;
            goto L_800815EC;
    }
    // 0x80081464: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80081468: andi        $v0, $s2, 0x1
    ctx->r2 = ctx->r18 & 0X1;
    // 0x8008146C: beq         $v0, $zero, L_800814F4
    if (ctx->r2 == 0) {
        // 0x80081470: nop
    
            goto L_800814F4;
    }
    // 0x80081470: nop

    // 0x80081474: bltz        $a3, L_800814E0
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081478: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800814E0;
    }
    // 0x80081478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008147C: bltz        $t0, L_800814E0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081480: andi        $t6, $a3, 0x3FF
        ctx->r14 = ctx->r7 & 0X3FF;
            goto L_800814E0;
    }
    // 0x80081480: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x80081484: bgez        $t1, L_80081494
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081488: sll         $t8, $t6, 14
        ctx->r24 = S32(ctx->r14 << 14);
            goto L_80081494;
    }
    // 0x80081488: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8008148C: b           L_80081498
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081498;
    // 0x80081490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80081494:
    // 0x80081494: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081498:
    // 0x80081498: bgez        $a2, L_800814A8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008149C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800814A8;
    }
    // 0x8008149C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800814A0: b           L_800814A8
    // 0x800814A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800814A8;
    // 0x800814A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800814A8:
    // 0x800814A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800814AC: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x800814B0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800814B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800814B8: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x800814BC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800814C0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800814C4: andi        $t6, $a0, 0x3FF
    ctx->r14 = ctx->r4 & 0X3FF;
    // 0x800814C8: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x800814CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800814D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800814D4: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800814D8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800814DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800814E0:
    // 0x800814E0: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800814E4: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x800814E8: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800814EC: beq         $t2, $s2, L_800815EC
    if (ctx->r10 == ctx->r18) {
        // 0x800814F0: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800815EC;
    }
    // 0x800814F0: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_800814F4:
    // 0x800814F4: bltz        $a3, L_80081560
    if (SIGNED(ctx->r7) < 0) {
        // 0x800814F8: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80081560;
    }
    // 0x800814F8: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800814FC: bltz        $t0, L_80081560
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081500: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_80081560;
    }
    // 0x80081500: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x80081504: bgez        $t1, L_80081514
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081508: sll         $t8, $t9, 14
        ctx->r24 = S32(ctx->r25 << 14);
            goto L_80081514;
    }
    // 0x80081508: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8008150C: b           L_80081518
    // 0x80081510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081518;
    // 0x80081510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80081514:
    // 0x80081514: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081518:
    // 0x80081518: bgez        $a2, L_80081528
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008151C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80081528;
    }
    // 0x8008151C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081520: b           L_80081528
    // 0x80081524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80081528;
    // 0x80081524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80081528:
    // 0x80081528: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008152C: or          $t7, $t8, $s1
    ctx->r15 = ctx->r24 | ctx->r17;
    // 0x80081530: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081534: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80081538: andi        $t6, $t0, 0x3FF
    ctx->r14 = ctx->r8 & 0X3FF;
    // 0x8008153C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80081540: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80081544: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x80081548: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x8008154C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081550: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80081554: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80081558: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8008155C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80081560:
    // 0x80081560: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80081564: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80081568: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008156C: bltz        $a3, L_800815D8
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081570: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800815D8;
    }
    // 0x80081570: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
    // 0x80081574: bltz        $t0, L_800815D8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081578: andi        $t7, $a3, 0x3FF
        ctx->r15 = ctx->r7 & 0X3FF;
            goto L_800815D8;
    }
    // 0x80081578: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x8008157C: bgez        $t1, L_8008158C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081580: sll         $t8, $t7, 14
        ctx->r24 = S32(ctx->r15 << 14);
            goto L_8008158C;
    }
    // 0x80081580: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80081584: b           L_80081590
    // 0x80081588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081590;
    // 0x80081588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008158C:
    // 0x8008158C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081590:
    // 0x80081590: bgez        $a2, L_800815A0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80081594: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800815A0;
    }
    // 0x80081594: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081598: b           L_800815A0
    // 0x8008159C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800815A0;
    // 0x8008159C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800815A0:
    // 0x800815A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800815A4: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800815A8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800815AC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800815B0: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x800815B4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800815B8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800815BC: andi        $t7, $a0, 0x3FF
    ctx->r15 = ctx->r4 & 0X3FF;
    // 0x800815C0: andi        $t9, $a1, 0x3FF
    ctx->r25 = ctx->r5 & 0X3FF;
    // 0x800815C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800815C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800815CC: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x800815D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800815D4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800815D8:
    // 0x800815D8: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800815DC: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x800815E0: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x800815E4: bne         $t2, $s2, L_800814F4
    if (ctx->r10 != ctx->r18) {
        // 0x800815E8: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800814F4;
    }
    // 0x800815E8: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_800815EC:
    // 0x800815EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800815F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800815F4: bne         $s4, $at, L_80081370
    if (ctx->r20 != ctx->r1) {
        // 0x800815F8: nop
    
            goto L_80081370;
    }
    // 0x800815F8: nop

    // 0x800815FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081600: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80081604: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80081608: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8008160C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80081610: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80081614: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081618: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008161C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80081620: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80081624: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80081628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008162C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80081630: jal         0x8007B820
    // 0x80081634: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80081634: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    after_0:
    // 0x80081638: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008163C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80081644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80081648: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008164C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081650: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081654: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80081658: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008165C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80081660: jr          $ra
    // 0x80081664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80081664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void init_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008166C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081670: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80081674: jal         0x8006B464
    // 0x80081678: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80081678: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8008167C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80081680: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80081684: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80081688: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008168C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80081690: addiu       $v1, $v1, 0x11B
    ctx->r3 = ADD32(ctx->r3, 0X11B);
    // 0x80081694: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80081698: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x8008169C: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800816A0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800816A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800816A8: jal         0x80070EDC
    // 0x800816AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800816AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800816B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800816B4: addiu       $a0, $a0, 0x6AD0
    ctx->r4 = ADD32(ctx->r4, 0X6AD0);
    // 0x800816B8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800816BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800816C0: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x800816C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800816C8: lw          $t1, 0x6AD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6AD0);
    // 0x800816CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800816D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800816D4: addiu       $t2, $t1, 0x118
    ctx->r10 = ADD32(ctx->r9, 0X118);
    // 0x800816D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800816DC: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800816E0: lw          $t3, 0x6AD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6AD0);
    // 0x800816E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800816E8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800816EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800816F0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800816F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800816F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800816FC: addu        $v1, $a3, $a3
    ctx->r3 = ADD32(ctx->r7, ctx->r7);
    // 0x80081700: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80081704: sw          $t7, 0x6AD4($at)
    MEM_W(0X6AD4, ctx->r1) = ctx->r15;
    // 0x80081708: lw          $t8, 0x6AD4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6AD4);
    // 0x8008170C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081710: addiu       $t9, $t8, 0x118
    ctx->r25 = ADD32(ctx->r24, 0X118);
    // 0x80081714: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80081718: lw          $t0, 0x6AD4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6AD4);
    // 0x8008171C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80081720: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80081724: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80081728: addu        $t1, $t2, $a2
    ctx->r9 = ADD32(ctx->r10, ctx->r6);
    // 0x8008172C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80081730: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80081734: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80081738: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8008173C: sw          $t5, 0x6AD8($at)
    MEM_W(0X6AD8, ctx->r1) = ctx->r13;
    // 0x80081740: lw          $t3, 0x6AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6AD8);
    // 0x80081744: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80081748: addiu       $t6, $t3, 0x118
    ctx->r14 = ADD32(ctx->r11, 0X118);
    // 0x8008174C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80081750: lw          $t7, 0x6AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6AD8);
    // 0x80081754: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80081758: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8008175C: nop

    // 0x80081760: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x80081764: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80081768: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8008176C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80081770: addu        $t1, $t2, $v1
    ctx->r9 = ADD32(ctx->r10, ctx->r3);
    // 0x80081774: sw          $t1, 0x6ADC($at)
    MEM_W(0X6ADC, ctx->r1) = ctx->r9;
    // 0x80081778: lw          $t0, 0x6ADC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6ADC);
    // 0x8008177C: nop

    // 0x80081780: addiu       $t4, $t0, 0x118
    ctx->r12 = ADD32(ctx->r8, 0X118);
    // 0x80081784: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80081788: lw          $t5, 0x6ADC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6ADC);
    // 0x8008178C: nop

    // 0x80081790: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80081794: nop

    // 0x80081798: addu        $t3, $t6, $a2
    ctx->r11 = ADD32(ctx->r14, ctx->r6);
    // 0x8008179C: jal         0x8001E2D0
    // 0x800817A0: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x800817A0: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    after_2:
    // 0x800817A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800817A8: addiu       $v1, $v1, 0x71F0
    ctx->r3 = ADD32(ctx->r3, 0X71F0);
    // 0x800817AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800817B0: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x800817B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800817B8: addiu       $a0, $zero, 0x1400
    ctx->r4 = ADD32(0, 0X1400);
    // 0x800817BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800817C0: jal         0x80070EDC
    // 0x800817C4: sw          $t8, 0x71F8($at)
    MEM_W(0X71F8, ctx->r1) = ctx->r24;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800817C4: sw          $t8, 0x71F8($at)
    MEM_W(0X71F8, ctx->r1) = ctx->r24;
    after_3:
    // 0x800817C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800817CC: sw          $v0, -0x5E0($at)
    MEM_W(-0X5E0, ctx->r1) = ctx->r2;
    // 0x800817D0: jal         0x8007FD50
    // 0x800817D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x800817D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800817D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800817DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800817E0: addiu       $v1, $v1, 0x6CF0
    ctx->r3 = ADD32(ctx->r3, 0X6CF0);
    // 0x800817E4: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
L_800817E8:
    // 0x800817E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800817EC: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800817F0: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800817F4: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x800817F8: bne         $v0, $v1, L_800817E8
    if (ctx->r2 != ctx->r3) {
        // 0x800817FC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800817E8;
    }
    // 0x800817FC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80081800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081804: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80081808: jr          $ra
    // 0x8008180C: nop

    return;
    // 0x8008180C: nop

;}
RECOMP_FUNC void reset_title_logo_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081810: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081818: jr          $ra
    // 0x8008181C: sw          $t6, -0x628($at)
    MEM_W(-0X628, ctx->r1) = ctx->r14;
    return;
    // 0x8008181C: sw          $t6, -0x628($at)
    MEM_W(-0X628, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008182C: jal         0x8009C3A0
    // 0x80081830: sw          $a0, -0x610($at)
    MEM_W(-0X610, ctx->r1) = ctx->r4;
    reset_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x80081830: sw          $a0, -0x610($at)
    MEM_W(-0X610, ctx->r1) = ctx->r4;
    after_0:
    // 0x80081834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008183C: sw          $t6, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r14;
    // 0x80081840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081844: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80081848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008184C: sw          $zero, 0x6968($at)
    MEM_W(0X6968, ctx->r1) = 0;
    // 0x80081850: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081854: sb          $zero, 0x6DC8($at)
    MEM_B(0X6DC8, ctx->r1) = 0;
    // 0x80081858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008185C: sw          $zero, 0x6DA8($at)
    MEM_W(0X6DA8, ctx->r1) = 0;
    // 0x80081860: sw          $zero, 0x6DAC($at)
    MEM_W(0X6DAC, ctx->r1) = 0;
    // 0x80081864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081868: sw          $zero, 0x6DB0($at)
    MEM_W(0X6DB0, ctx->r1) = 0;
    // 0x8008186C: jal         0x80001844
    // 0x80081870: sw          $zero, 0x6DB4($at)
    MEM_W(0X6DB4, ctx->r1) = 0;
    music_stop(rdram, ctx);
        goto after_1;
    // 0x80081870: sw          $zero, 0x6DB4($at)
    MEM_W(0X6DB4, ctx->r1) = 0;
    after_1:
    // 0x80081874: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081878: lw          $t7, -0x610($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X610);
    // 0x8008187C: nop

    // 0x80081880: sltiu       $at, $t7, 0x1D
    ctx->r1 = ctx->r15 < 0X1D ? 1 : 0;
    // 0x80081884: beq         $at, $zero, L_800819DC
    if (ctx->r1 == 0) {
        // 0x80081888: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800819DC;
    }
    // 0x80081888: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008188C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081890: addu        $at, $at, $t7
    gpr jr_addend_8008189C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80081894: lw          $t7, -0x77EC($at)
    ctx->r15 = ADD32(ctx->r1, -0X77EC);
    // 0x80081898: nop

    // 0x8008189C: jr          $t7
    // 0x800818A0: nop

    switch (jr_addend_8008189C >> 2) {
        case 0: goto L_800818B4; break;
        case 1: goto L_800818A4; break;
        case 2: goto L_800819DC; break;
        case 3: goto L_80081914; break;
        case 4: goto L_800819DC; break;
        case 5: goto L_80081954; break;
        case 6: goto L_80081934; break;
        case 7: goto L_800819DC; break;
        case 8: goto L_800819DC; break;
        case 9: goto L_800819DC; break;
        case 10: goto L_800818F4; break;
        case 11: goto L_80081904; break;
        case 12: goto L_800818C4; break;
        case 13: goto L_800818D4; break;
        case 14: goto L_800818E4; break;
        case 15: goto L_80081944; break;
        case 16: goto L_800819DC; break;
        case 17: goto L_80081964; break;
        case 18: goto L_800819DC; break;
        case 19: goto L_80081924; break;
        case 20: goto L_80081974; break;
        case 21: goto L_80081984; break;
        case 22: goto L_800819DC; break;
        case 23: goto L_80081994; break;
        case 24: goto L_800819A4; break;
        case 25: goto L_800819B4; break;
        case 26: goto L_800819C4; break;
        case 27: goto L_800819DC; break;
        case 28: goto L_800819D4; break;
        default: switch_error(__func__, 0x8008189C, 0x800E8814);
    }
    // 0x800818A0: nop

L_800818A4:
    // 0x800818A4: jal         0x80082EFC
    // 0x800818A8: nop

    menu_logos_screen_init(rdram, ctx);
        goto after_2;
    // 0x800818A8: nop

    after_2:
    // 0x800818AC: b           L_800819E0
    // 0x800818B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818B4:
    // 0x800818B4: jal         0x80083974
    // 0x800818B8: nop

    menu_title_screen_init(rdram, ctx);
        goto after_3;
    // 0x800818B8: nop

    after_3:
    // 0x800818BC: b           L_800819E0
    // 0x800818C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818C4:
    // 0x800818C4: jal         0x80084594
    // 0x800818C8: nop

    menu_options_init(rdram, ctx);
        goto after_4;
    // 0x800818C8: nop

    after_4:
    // 0x800818CC: b           L_800819E0
    // 0x800818D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818D4:
    // 0x800818D4: jal         0x80084B8C
    // 0x800818D8: nop

    menu_audio_options_init(rdram, ctx);
        goto after_5;
    // 0x800818D8: nop

    after_5:
    // 0x800818DC: b           L_800819E0
    // 0x800818E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818E4:
    // 0x800818E4: jal         0x800856A8
    // 0x800818E8: nop

    menu_save_options_init(rdram, ctx);
        goto after_6;
    // 0x800818E8: nop

    after_6:
    // 0x800818EC: b           L_800819E0
    // 0x800818F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800818F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800818F4:
    // 0x800818F4: jal         0x80089A78
    // 0x800818F8: nop

    menu_magic_codes_init(rdram, ctx);
        goto after_7;
    // 0x800818F8: nop

    after_7:
    // 0x800818FC: b           L_800819E0
    // 0x80081900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081904:
    // 0x80081904: jal         0x8008A998
    // 0x80081908: nop

    menu_magic_codes_list_init(rdram, ctx);
        goto after_8;
    // 0x80081908: nop

    after_8:
    // 0x8008190C: b           L_800819E0
    // 0x80081910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081914:
    // 0x80081914: jal         0x8008B484
    // 0x80081918: nop

    menu_character_select_init(rdram, ctx);
        goto after_9;
    // 0x80081918: nop

    after_9:
    // 0x8008191C: b           L_800819E0
    // 0x80081920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081924:
    // 0x80081924: jal         0x8008C9C0
    // 0x80081928: nop

    menu_game_select_init(rdram, ctx);
        goto after_10;
    // 0x80081928: nop

    after_10:
    // 0x8008192C: b           L_800819E0
    // 0x80081930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081934:
    // 0x80081934: jal         0x8008CFB4
    // 0x80081938: nop

    menu_file_select_init(rdram, ctx);
        goto after_11;
    // 0x80081938: nop

    after_11:
    // 0x8008193C: b           L_800819E0
    // 0x80081940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081944:
    // 0x80081944: jal         0x8008EC58
    // 0x80081948: nop

    menu_track_select_init(rdram, ctx);
        goto after_12;
    // 0x80081948: nop

    after_12:
    // 0x8008194C: b           L_800819E0
    // 0x80081950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081954:
    // 0x80081954: jal         0x800931CC
    // 0x80081958: nop

    menu_adventure_track_init(rdram, ctx);
        goto after_13;
    // 0x80081958: nop

    after_13:
    // 0x8008195C: b           L_800819E0
    // 0x80081960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081964:
    // 0x80081964: jal         0x80096D4C
    // 0x80081968: nop

    menu_results_init(rdram, ctx);
        goto after_14;
    // 0x80081968: nop

    after_14:
    // 0x8008196C: b           L_800819E0
    // 0x80081970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081974:
    // 0x80081974: jal         0x800987A8
    // 0x80081978: nop

    menu_trophy_race_round_init(rdram, ctx);
        goto after_15;
    // 0x80081978: nop

    after_15:
    // 0x8008197C: b           L_800819E0
    // 0x80081980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081984:
    // 0x80081984: jal         0x80098F60
    // 0x80081988: nop

    menu_trophy_race_rankings_init(rdram, ctx);
        goto after_16;
    // 0x80081988: nop

    after_16:
    // 0x8008198C: b           L_800819E0
    // 0x80081990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x80081990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081994:
    // 0x80081994: jal         0x8009B1D4
    // 0x80081998: nop

    menu_cinematic_init(rdram, ctx);
        goto after_17;
    // 0x80081998: nop

    after_17:
    // 0x8008199C: b           L_800819E0
    // 0x800819A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819A4:
    // 0x800819A4: jal         0x80099F98
    // 0x800819A8: nop

    menu_ghost_data_init(rdram, ctx);
        goto after_18;
    // 0x800819A8: nop

    after_18:
    // 0x800819AC: b           L_800819E0
    // 0x800819B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819B4:
    // 0x800819B4: jal         0x8009B484
    // 0x800819B8: nop

    menu_credits_init(rdram, ctx);
        goto after_19;
    // 0x800819B8: nop

    after_19:
    // 0x800819BC: b           L_800819E0
    // 0x800819C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819C4:
    // 0x800819C4: jal         0x8008896C
    // 0x800819C8: nop

    menu_boot_init(rdram, ctx);
        goto after_20;
    // 0x800819C8: nop

    after_20:
    // 0x800819CC: b           L_800819E0
    // 0x800819D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800819E0;
    // 0x800819D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819D4:
    // 0x800819D4: jal         0x8008C86C
    // 0x800819D8: nop

    menu_caution_init(rdram, ctx);
        goto after_21;
    // 0x800819D8: nop

    after_21:
L_800819DC:
    // 0x800819DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800819E0:
    // 0x800819E0: ori         $t8, $zero, 0xD000
    ctx->r24 = 0 | 0XD000;
    // 0x800819E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800819E8: sw          $t8, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = ctx->r24;
    // 0x800819EC: jr          $ra
    // 0x800819F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800819F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800819F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800819F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800819FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80081A00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80081A04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80081A08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80081A0C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80081A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A14: sw          $t7, 0x693C($at)
    MEM_W(0X693C, ctx->r1) = ctx->r15;
    // 0x80081A18: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80081A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A20: sw          $t9, 0x6944($at)
    MEM_W(0X6944, ctx->r1) = ctx->r25;
    // 0x80081A24: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80081A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A2C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    // 0x80081A30: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80081A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A38: jal         0x8009C464
    // 0x80081A3C: sw          $t3, 0x6950($at)
    MEM_W(0X6950, ctx->r1) = ctx->r11;
    update_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x80081A3C: sw          $t3, 0x6950($at)
    MEM_W(0X6950, ctx->r1) = ctx->r11;
    after_0:
    // 0x80081A40: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081A44: lw          $t4, -0x610($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X610);
    // 0x80081A48: nop

    // 0x80081A4C: sltiu       $at, $t4, 0x1D
    ctx->r1 = ctx->r12 < 0X1D ? 1 : 0;
    // 0x80081A50: beq         $at, $zero, L_80081BFC
    if (ctx->r1 == 0) {
        // 0x80081A54: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80081BFC;
    }
    // 0x80081A54: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80081A58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081A5C: addu        $at, $at, $t4
    gpr jr_addend_80081A68 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80081A60: lw          $t4, -0x7778($at)
    ctx->r12 = ADD32(ctx->r1, -0X7778);
    // 0x80081A64: nop

    // 0x80081A68: jr          $t4
    // 0x80081A6C: nop

    switch (jr_addend_80081A68 >> 2) {
        case 0: goto L_80081A84; break;
        case 1: goto L_80081A70; break;
        case 2: goto L_80081BFC; break;
        case 3: goto L_80081AFC; break;
        case 4: goto L_80081BFC; break;
        case 5: goto L_80081B4C; break;
        case 6: goto L_80081B10; break;
        case 7: goto L_80081BFC; break;
        case 8: goto L_80081BFC; break;
        case 9: goto L_80081BFC; break;
        case 10: goto L_80081AD4; break;
        case 11: goto L_80081AE8; break;
        case 12: goto L_80081A98; break;
        case 13: goto L_80081AAC; break;
        case 14: goto L_80081AC0; break;
        case 15: goto L_80081B38; break;
        case 16: goto L_80081BFC; break;
        case 17: goto L_80081B60; break;
        case 18: goto L_80081BFC; break;
        case 19: goto L_80081B24; break;
        case 20: goto L_80081B74; break;
        case 21: goto L_80081B88; break;
        case 22: goto L_80081BFC; break;
        case 23: goto L_80081B9C; break;
        case 24: goto L_80081BB0; break;
        case 25: goto L_80081BC4; break;
        case 26: goto L_80081BD8; break;
        case 27: goto L_80081BFC; break;
        case 28: goto L_80081BEC; break;
        default: switch_error(__func__, 0x80081A68, 0x800E8888);
    }
    // 0x80081A6C: nop

L_80081A70:
    // 0x80081A70: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A74: jal         0x80082FD4
    // 0x80081A78: nop

    menu_logo_screen_loop(rdram, ctx);
        goto after_1;
    // 0x80081A78: nop

    after_1:
    // 0x80081A7C: b           L_80081BFC
    // 0x80081A80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081A80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081A84:
    // 0x80081A84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A88: jal         0x80083E1C
    // 0x80081A8C: nop

    menu_title_screen_loop(rdram, ctx);
        goto after_2;
    // 0x80081A8C: nop

    after_2:
    // 0x80081A90: b           L_80081BFC
    // 0x80081A94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081A94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081A98:
    // 0x80081A98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A9C: jal         0x80084794
    // 0x80081AA0: nop

    menu_options_loop(rdram, ctx);
        goto after_3;
    // 0x80081AA0: nop

    after_3:
    // 0x80081AA4: b           L_80081BFC
    // 0x80081AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AAC:
    // 0x80081AAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AB0: jal         0x800850AC
    // 0x80081AB4: nop

    menu_audio_options_loop(rdram, ctx);
        goto after_4;
    // 0x80081AB4: nop

    after_4:
    // 0x80081AB8: b           L_80081BFC
    // 0x80081ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AC0:
    // 0x80081AC0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AC4: jal         0x80087FD0
    // 0x80081AC8: nop

    menu_save_options_loop(rdram, ctx);
        goto after_5;
    // 0x80081AC8: nop

    after_5:
    // 0x80081ACC: b           L_80081BFC
    // 0x80081AD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AD4:
    // 0x80081AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AD8: jal         0x8008A174
    // 0x80081ADC: nop

    menu_magic_codes_loop(rdram, ctx);
        goto after_6;
    // 0x80081ADC: nop

    after_6:
    // 0x80081AE0: b           L_80081BFC
    // 0x80081AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AE8:
    // 0x80081AE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AEC: jal         0x8008ADE0
    // 0x80081AF0: nop

    menu_magic_codes_list_loop(rdram, ctx);
        goto after_7;
    // 0x80081AF0: nop

    after_7:
    // 0x80081AF4: b           L_80081BFC
    // 0x80081AF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AFC:
    // 0x80081AFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B00: jal         0x8008C1DC
    // 0x80081B04: nop

    menu_character_select_loop(rdram, ctx);
        goto after_8;
    // 0x80081B04: nop

    after_8:
    // 0x80081B08: b           L_80081BFC
    // 0x80081B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B10:
    // 0x80081B10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B14: jal         0x8008E328
    // 0x80081B18: nop

    menu_file_select_loop(rdram, ctx);
        goto after_9;
    // 0x80081B18: nop

    after_9:
    // 0x80081B1C: b           L_80081BFC
    // 0x80081B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B24:
    // 0x80081B24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B28: jal         0x8008CC74
    // 0x80081B2C: nop

    menu_game_select_loop(rdram, ctx);
        goto after_10;
    // 0x80081B2C: nop

    after_10:
    // 0x80081B30: b           L_80081BFC
    // 0x80081B34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B38:
    // 0x80081B38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B3C: jal         0x8008F6EC
    // 0x80081B40: nop

    menu_track_select_loop(rdram, ctx);
        goto after_11;
    // 0x80081B40: nop

    after_11:
    // 0x80081B44: b           L_80081BFC
    // 0x80081B48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B4C:
    // 0x80081B4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B50: jal         0x80093B04
    // 0x80081B54: nop

    menu_adventure_track_loop(rdram, ctx);
        goto after_12;
    // 0x80081B54: nop

    after_12:
    // 0x80081B58: b           L_80081BFC
    // 0x80081B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B60:
    // 0x80081B60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B64: jal         0x800977E4
    // 0x80081B68: nop

    menu_results_loop(rdram, ctx);
        goto after_13;
    // 0x80081B68: nop

    after_13:
    // 0x80081B6C: b           L_80081BFC
    // 0x80081B70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B74:
    // 0x80081B74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B78: jal         0x80098AD8
    // 0x80081B7C: nop

    menu_trophy_race_round_loop(rdram, ctx);
        goto after_14;
    // 0x80081B7C: nop

    after_14:
    // 0x80081B80: b           L_80081BFC
    // 0x80081B84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B88:
    // 0x80081B88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B8C: jal         0x80099510
    // 0x80081B90: nop

    menu_trophy_race_rankings_loop(rdram, ctx);
        goto after_15;
    // 0x80081B90: nop

    after_15:
    // 0x80081B94: b           L_80081BFC
    // 0x80081B98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B9C:
    // 0x80081B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BA0: jal         0x8009B238
    // 0x80081BA4: nop

    menu_cinematic_loop(rdram, ctx);
        goto after_16;
    // 0x80081BA4: nop

    after_16:
    // 0x80081BA8: b           L_80081BFC
    // 0x80081BAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BB0:
    // 0x80081BB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BB4: jal         0x8009AD10
    // 0x80081BB8: nop

    menu_ghost_data_loop(rdram, ctx);
        goto after_17;
    // 0x80081BB8: nop

    after_17:
    // 0x80081BBC: b           L_80081BFC
    // 0x80081BC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BC4:
    // 0x80081BC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BC8: jal         0x8009B870
    // 0x80081BCC: nop

    menu_credits_loop(rdram, ctx);
        goto after_18;
    // 0x80081BCC: nop

    after_18:
    // 0x80081BD0: b           L_80081BFC
    // 0x80081BD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BD8:
    // 0x80081BD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BDC: jal         0x80088A84
    // 0x80081BE0: nop

    menu_boot_loop(rdram, ctx);
        goto after_19;
    // 0x80081BE0: nop

    after_19:
    // 0x80081BE4: b           L_80081BFC
    // 0x80081BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BEC:
    // 0x80081BEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BF0: jal         0x8008C8B4
    // 0x80081BF4: nop

    menu_caution_loop(rdram, ctx);
        goto after_20;
    // 0x80081BF4: nop

    after_20:
    // 0x80081BF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BFC:
    // 0x80081BFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80081C00: lw          $t5, 0x693C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X693C);
    // 0x80081C04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80081C08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80081C0C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80081C10: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80081C14: lw          $t7, 0x6944($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6944);
    // 0x80081C18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80081C1C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80081C20: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80081C24: lw          $t9, 0x694C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X694C);
    // 0x80081C28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80081C2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80081C30: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80081C34: lw          $t1, 0x6950($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6950);
    // 0x80081C38: nop

    // 0x80081C3C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80081C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081C44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80081C48: jr          $ra
    // 0x80081C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void menu_timestamp_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C50: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80081C54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C58: lbu         $t7, 0x73($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X73);
    // 0x80081C5C: sb          $a3, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r7;
    // 0x80081C60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C64: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x80081C68: lbu         $t9, 0x7B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7B);
    // 0x80081C6C: sb          $t7, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r15;
    // 0x80081C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081C74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C78: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80081C7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80081C80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80081C84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80081C88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80081C8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081C90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081C94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081C98: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80081C9C: bne         $t9, $zero, L_80081CF4
    if (ctx->r25 != 0) {
        // 0x80081CA0: sb          $t8, -0x5D4($at)
        MEM_B(-0X5D4, ctx->r1) = ctx->r24;
            goto L_80081CF4;
    }
    // 0x80081CA0: sb          $t8, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r24;
    // 0x80081CA4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80081CA8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081CAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081CB0: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80081CB4: addiu       $t1, $a2, -0x2
    ctx->r9 = ADD32(ctx->r6, -0X2);
    // 0x80081CB8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081CBC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80081CC0: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80081CC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081CC8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081CCC: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80081CD0: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80081CD4: swc1        $f10, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f10.u32l;
    // 0x80081CD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80081CDC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80081CE0: addiu       $s0, $a1, -0x27
    ctx->r16 = ADD32(ctx->r5, -0X27);
    // 0x80081CE4: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80081CE8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80081CEC: b           L_80081D40
    // 0x80081CF0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
        goto L_80081D40;
    // 0x80081CF0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_80081CF4:
    // 0x80081CF4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80081CF8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081CFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081D00: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80081D04: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x80081D08: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80081D0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80081D10: swc1        $f18, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f18.u32l;
    // 0x80081D14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081D18: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081D1C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80081D20: swc1        $f6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f6.u32l;
    // 0x80081D24: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80081D28: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80081D2C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80081D30: addiu       $s0, $s0, -0x1C
    ctx->r16 = ADD32(ctx->r16, -0X1C);
    // 0x80081D34: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x80081D38: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80081D3C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80081D40:
    // 0x80081D40: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80081D44: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80081D48: jal         0x800597E0
    // 0x80081D4C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    get_timestamp_from_frames(rdram, ctx);
        goto after_0;
    // 0x80081D4C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80081D50: jal         0x80068748
    // 0x80081D54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80081D54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80081D58: jal         0x8007C36C
    // 0x80081D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x80081D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80081D60: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80081D64: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80081D68: div         $zero, $t0, $s4
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r20)));
    // 0x80081D6C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081D70: sll         $s1, $s3, 5
    ctx->r17 = S32(ctx->r19 << 5);
    // 0x80081D74: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80081D78: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081D7C: bne         $s4, $zero, L_80081D88
    if (ctx->r20 != 0) {
        // 0x80081D80: nop
    
            goto L_80081D88;
    }
    // 0x80081D80: nop

    // 0x80081D84: break       7
    do_break(2148015492);
L_80081D88:
    // 0x80081D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081D8C: bne         $s4, $at, L_80081DA0
    if (ctx->r20 != ctx->r1) {
        // 0x80081D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081DA0;
    }
    // 0x80081D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081D94: bne         $t0, $at, L_80081DA0
    if (ctx->r8 != ctx->r1) {
        // 0x80081D98: nop
    
            goto L_80081DA0;
    }
    // 0x80081D98: nop

    // 0x80081D9C: break       6
    do_break(2148015516);
L_80081DA0:
    // 0x80081DA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081DA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081DA8: mflo        $t1
    ctx->r9 = lo;
    // 0x80081DAC: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    // 0x80081DB0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081DB4: nop

    // 0x80081DB8: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081DBC: jal         0x8009CFA4
    // 0x80081DC0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_3;
    // 0x80081DC0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    after_3:
    // 0x80081DC4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80081DC8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80081DCC: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081DD0: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081DD4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80081DD8: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081DDC: bne         $s4, $zero, L_80081DE8
    if (ctx->r20 != 0) {
        // 0x80081DE0: nop
    
            goto L_80081DE8;
    }
    // 0x80081DE0: nop

    // 0x80081DE4: break       7
    do_break(2148015588);
L_80081DE8:
    // 0x80081DE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081DEC: bne         $s4, $at, L_80081E00
    if (ctx->r20 != ctx->r1) {
        // 0x80081DF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081E00;
    }
    // 0x80081DF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081DF4: bne         $t6, $at, L_80081E00
    if (ctx->r14 != ctx->r1) {
        // 0x80081DF8: nop
    
            goto L_80081E00;
    }
    // 0x80081DF8: nop

    // 0x80081DFC: break       6
    do_break(2148015612);
L_80081E00:
    // 0x80081E00: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081E04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081E08: mfhi        $t7
    ctx->r15 = hi;
    // 0x80081E0C: sh          $t7, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r15;
    // 0x80081E10: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081E14: nop

    // 0x80081E18: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80081E1C: jal         0x8009CFA4
    // 0x80081E20: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x80081E20: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    after_4:
    // 0x80081E24: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80081E28: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80081E2C: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80081E30: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80081E34: sll         $v0, $s5, 5
    ctx->r2 = S32(ctx->r21 << 5);
    // 0x80081E38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081E3C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80081E40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80081E44: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x80081E48: jal         0x8009CFA4
    // 0x80081E4C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x80081E4C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_5:
    // 0x80081E50: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80081E54: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80081E58: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081E5C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081E60: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x80081E64: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80081E68: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081E6C: bne         $s4, $zero, L_80081E78
    if (ctx->r20 != 0) {
        // 0x80081E70: nop
    
            goto L_80081E78;
    }
    // 0x80081E70: nop

    // 0x80081E74: break       7
    do_break(2148015732);
L_80081E78:
    // 0x80081E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081E7C: bne         $s4, $at, L_80081E90
    if (ctx->r20 != ctx->r1) {
        // 0x80081E80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081E90;
    }
    // 0x80081E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081E84: bne         $t6, $at, L_80081E90
    if (ctx->r14 != ctx->r1) {
        // 0x80081E88: nop
    
            goto L_80081E90;
    }
    // 0x80081E88: nop

    // 0x80081E8C: break       6
    do_break(2148015756);
L_80081E90:
    // 0x80081E90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081E98: mflo        $t8
    ctx->r24 = lo;
    // 0x80081E9C: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x80081EA0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081EA4: nop

    // 0x80081EA8: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80081EAC: jal         0x8009CFA4
    // 0x80081EB0: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80081EB0: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    after_6:
    // 0x80081EB4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80081EB8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081EBC: div         $zero, $t1, $s4
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r20)));
    // 0x80081EC0: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081EC4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081EC8: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081ECC: bne         $s4, $zero, L_80081ED8
    if (ctx->r20 != 0) {
        // 0x80081ED0: nop
    
            goto L_80081ED8;
    }
    // 0x80081ED0: nop

    // 0x80081ED4: break       7
    do_break(2148015828);
L_80081ED8:
    // 0x80081ED8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081EDC: bne         $s4, $at, L_80081EF0
    if (ctx->r20 != ctx->r1) {
        // 0x80081EE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081EF0;
    }
    // 0x80081EE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081EE4: bne         $t1, $at, L_80081EF0
    if (ctx->r9 != ctx->r1) {
        // 0x80081EE8: nop
    
            goto L_80081EF0;
    }
    // 0x80081EE8: nop

    // 0x80081EEC: break       6
    do_break(2148015852);
L_80081EF0:
    // 0x80081EF0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081EF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081EF8: mfhi        $t3
    ctx->r11 = hi;
    // 0x80081EFC: sh          $t3, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r11;
    // 0x80081F00: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80081F04: nop

    // 0x80081F08: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80081F0C: jal         0x8009CFA4
    // 0x80081F10: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x80081F10: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    after_7:
    // 0x80081F14: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80081F18: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80081F1C: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80081F20: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80081F24: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80081F28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081F2C: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80081F30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80081F34: jal         0x8009CFA4
    // 0x80081F38: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x80081F38: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    after_8:
    // 0x80081F3C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80081F40: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80081F44: div         $zero, $t4, $s4
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r20)));
    // 0x80081F48: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80081F4C: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80081F50: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80081F54: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081F58: bne         $s4, $zero, L_80081F64
    if (ctx->r20 != 0) {
        // 0x80081F5C: nop
    
            goto L_80081F64;
    }
    // 0x80081F5C: nop

    // 0x80081F60: break       7
    do_break(2148015968);
L_80081F64:
    // 0x80081F64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081F68: bne         $s4, $at, L_80081F7C
    if (ctx->r20 != ctx->r1) {
        // 0x80081F6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081F7C;
    }
    // 0x80081F6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081F70: bne         $t4, $at, L_80081F7C
    if (ctx->r12 != ctx->r1) {
        // 0x80081F74: nop
    
            goto L_80081F7C;
    }
    // 0x80081F74: nop

    // 0x80081F78: break       6
    do_break(2148015992);
L_80081F7C:
    // 0x80081F7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081F80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081F84: mflo        $t3
    ctx->r11 = lo;
    // 0x80081F88: sh          $t3, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r11;
    // 0x80081F8C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081F90: nop

    // 0x80081F94: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80081F98: jal         0x8009CFA4
    // 0x80081F9C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x80081F9C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    after_9:
    // 0x80081FA0: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80081FA4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081FA8: div         $zero, $t9, $s4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r20)));
    // 0x80081FAC: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081FB0: addu        $t1, $t2, $s1
    ctx->r9 = ADD32(ctx->r10, ctx->r17);
    // 0x80081FB4: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081FB8: bne         $s4, $zero, L_80081FC4
    if (ctx->r20 != 0) {
        // 0x80081FBC: nop
    
            goto L_80081FC4;
    }
    // 0x80081FBC: nop

    // 0x80081FC0: break       7
    do_break(2148016064);
L_80081FC4:
    // 0x80081FC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081FC8: bne         $s4, $at, L_80081FDC
    if (ctx->r20 != ctx->r1) {
        // 0x80081FCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081FDC;
    }
    // 0x80081FCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081FD0: bne         $t9, $at, L_80081FDC
    if (ctx->r25 != ctx->r1) {
        // 0x80081FD4: nop
    
            goto L_80081FDC;
    }
    // 0x80081FD4: nop

    // 0x80081FD8: break       6
    do_break(2148016088);
L_80081FDC:
    // 0x80081FDC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081FE4: mfhi        $t0
    ctx->r8 = hi;
    // 0x80081FE8: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x80081FEC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081FF0: nop

    // 0x80081FF4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081FF8: jal         0x8009CFA4
    // 0x80081FFC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x80081FFC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    after_10:
    // 0x80082000: jal         0x80068748
    // 0x80082004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x80082004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80082008: jal         0x8007C36C
    // 0x8008200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_12;
    // 0x8008200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80082010: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082018: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x8008201C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082020: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80082024: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082028: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008202C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082030: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80082034: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082038: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008203C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80082040: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80082044: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80082048: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008204C: jr          $ra
    // 0x80082050: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80082050: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void menu_number_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082054: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80082058: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008205C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80082060: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80082064: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80082068: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008206C: lui         $s0, 0x3B9A
    ctx->r16 = S32(0X3B9A << 16);
    // 0x80082070: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80082074: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80082078: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008207C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80082080: ori         $s0, $s0, 0xCA00
    ctx->r16 = ctx->r16 | 0XCA00;
    // 0x80082084: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80082088: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8008208C: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80082090: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
L_80082094:
    // 0x80082094: bne         $at, $zero, L_800820F0
    if (ctx->r1 != 0) {
        // 0x80082098: nop
    
            goto L_800820F0;
    }
    // 0x80082098: nop

    // 0x8008209C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800820A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800820A4: bne         $s0, $zero, L_800820B0
    if (ctx->r16 != 0) {
        // 0x800820A8: nop
    
            goto L_800820B0;
    }
    // 0x800820A8: nop

    // 0x800820AC: break       7
    do_break(2148016300);
L_800820B0:
    // 0x800820B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800820B4: bne         $s0, $at, L_800820C8
    if (ctx->r16 != ctx->r1) {
        // 0x800820B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800820C8;
    }
    // 0x800820B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800820BC: bne         $s1, $at, L_800820C8
    if (ctx->r17 != ctx->r1) {
        // 0x800820C0: nop
    
            goto L_800820C8;
    }
    // 0x800820C0: nop

    // 0x800820C4: break       6
    do_break(2148016324);
L_800820C8:
    // 0x800820C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800820CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800820D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800820D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800820D8: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x800820DC: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800820E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800820E4: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800820E8: b           L_80082104
    // 0x800820EC: nop

        goto L_80082104;
    // 0x800820EC: nop

L_800820F0:
    // 0x800820F0: beq         $t0, $zero, L_80082104
    if (ctx->r8 == 0) {
        // 0x800820F4: nop
    
            goto L_80082104;
    }
    // 0x800820F4: nop

    // 0x800820F8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800820FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80082100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80082104:
    // 0x80082104: div         $zero, $s0, $a1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r5)));
    // 0x80082108: bne         $a1, $zero, L_80082114
    if (ctx->r5 != 0) {
        // 0x8008210C: nop
    
            goto L_80082114;
    }
    // 0x8008210C: nop

    // 0x80082110: break       7
    do_break(2148016400);
L_80082114:
    // 0x80082114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082118: bne         $a1, $at, L_8008212C
    if (ctx->r5 != ctx->r1) {
        // 0x8008211C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008212C;
    }
    // 0x8008211C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80082120: bne         $s0, $at, L_8008212C
    if (ctx->r16 != ctx->r1) {
        // 0x80082124: nop
    
            goto L_8008212C;
    }
    // 0x80082124: nop

    // 0x80082128: break       6
    do_break(2148016424);
L_8008212C:
    // 0x8008212C: mflo        $s0
    ctx->r16 = lo;
    // 0x80082130: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80082134: beq         $at, $zero, L_80082094
    if (ctx->r1 == 0) {
        // 0x80082138: slt         $at, $s1, $s0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80082094;
    }
    // 0x80082138: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008213C: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x80082140: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x80082144: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80082148: beq         $t7, $zero, L_80082168
    if (ctx->r15 == 0) {
        // 0x8008214C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80082168;
    }
    // 0x8008214C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80082150: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80082154: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x80082158: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008215C: subu        $s4, $s4, $t8
    ctx->r20 = SUB32(ctx->r20, ctx->r24);
    // 0x80082160: b           L_80082190
    // 0x80082164: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
        goto L_80082190;
    // 0x80082164: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80082168:
    // 0x80082168: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8008216C: beq         $t9, $zero, L_8008218C
    if (ctx->r25 == 0) {
        // 0x80082170: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_8008218C;
    }
    // 0x80082170: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80082174: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80082178: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008217C: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80082180: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80082184: b           L_80082190
    // 0x80082188: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
        goto L_80082190;
    // 0x80082188: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
L_8008218C:
    // 0x8008218C: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80082190:
    // 0x80082190: andi        $t3, $v0, 0x8
    ctx->r11 = ctx->r2 & 0X8;
    // 0x80082194: beq         $t3, $zero, L_800821A4
    if (ctx->r11 == 0) {
        // 0x80082198: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800821A4;
    }
    // 0x80082198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008219C: b           L_800821B4
    // 0x800821A0: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
        goto L_800821B4;
    // 0x800821A0: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
L_800821A4:
    // 0x800821A4: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    // 0x800821A8: beq         $t4, $zero, L_800821B8
    if (ctx->r12 == 0) {
        // 0x800821AC: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_800821B8;
    }
    // 0x800821AC: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800821B0: addiu       $a2, $a2, -0x7
    ctx->r6 = ADD32(ctx->r6, -0X7);
L_800821B4:
    // 0x800821B4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_800821B8:
    // 0x800821B8: sb          $a3, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r7;
    // 0x800821BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821C0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800821C4: sb          $t5, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r13;
    // 0x800821C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821CC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800821D0: sb          $t6, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r14;
    // 0x800821D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800821DC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800821E0: jal         0x8007C36C
    // 0x800821E4: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x800821E4: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    after_0:
    // 0x800821E8: jal         0x80068748
    // 0x800821EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800821EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800821F0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800821F4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800821F8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800821FC: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80082200: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082204: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80082208: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008220C: blez        $s3, L_8008224C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80082210: swc1        $f6, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
            goto L_8008224C;
    }
    // 0x80082210: swc1        $f6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
    // 0x80082214: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
L_80082218:
    // 0x80082218: mtc1        $s4, $f8
    ctx->f8.u32l = ctx->r20;
    // 0x8008221C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80082220: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082228: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x8008222C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80082230: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80082234: jal         0x8009CFA4
    // 0x80082238: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x80082238: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    after_2:
    // 0x8008223C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80082240: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80082244: bne         $s0, $s3, L_80082218
    if (ctx->r16 != ctx->r19) {
        // 0x80082248: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80082218;
    }
    // 0x80082248: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_8008224C:
    // 0x8008224C: jal         0x8007C36C
    // 0x80082250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x80082250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80082254: jal         0x80068748
    // 0x80082258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x80082258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8008225C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082264: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x80082268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008226C: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80082278: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008227C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082280: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80082284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082288: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008228C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082290: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80082294: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80082298: sw          $t3, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r11;
    // 0x8008229C: jr          $ra
    // 0x800822A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800822A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void postrace_offsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800822A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800822A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800822AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800822B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800822B4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800822B8: sw          $a0, -0x2E8($at)
    MEM_W(-0X2E8, ctx->r1) = ctx->r4;
    // 0x800822BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800822C0: sw          $zero, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = 0;
    // 0x800822C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800822C8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800822CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800822D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800822D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800822D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800822DC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800822E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800822E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800822E8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800822EC: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800822F0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800822F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800822F8: addiu       $v0, $v0, 0x6DF8
    ctx->r2 = ADD32(ctx->r2, 0X6DF8);
    // 0x800822FC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80082300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80082304: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80082308: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008230C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082314: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80082318: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008231C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80082320: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80082324: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80082328: sw          $t9, 0x6DFC($at)
    MEM_W(0X6DFC, ctx->r1) = ctx->r25;
    // 0x8008232C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80082330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082334: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80082338: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008233C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80082340: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082344: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008234C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80082350: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80082354: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80082358: sw          $t1, 0x6E00($at)
    MEM_W(0X6E00, ctx->r1) = ctx->r9;
    // 0x8008235C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082360: sw          $zero, 0x6DF4($at)
    MEM_W(0X6DF4, ctx->r1) = 0;
    // 0x80082364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082368: sw          $t2, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = ctx->r10;
    // 0x8008236C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082370: sw          $t3, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = ctx->r11;
    // 0x80082374: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80082378: nop

    // 0x8008237C: blez        $t4, L_80082390
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80082380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80082390;
    }
    // 0x80082380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082384: jal         0x80001D04
    // 0x80082388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80082388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008238C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80082390:
    // 0x80082390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80082394: jr          $ra
    // 0x80082398: nop

    return;
    // 0x80082398: nop

;}
RECOMP_FUNC void postrace_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008239C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800823A0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800823A4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800823A8: addiu       $s2, $s2, -0x2EC
    ctx->r18 = ADD32(ctx->r18, -0X2EC);
    // 0x800823AC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800823B0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800823B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800823B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800823BC: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x800823C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800823C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800823C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800823CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800823D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800823D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800823D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800823DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800823E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800823E4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800823E8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800823EC: beq         $s6, $a3, L_80082608
    if (ctx->r22 == ctx->r7) {
        // 0x800823F0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80082608;
    }
    // 0x800823F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800823F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800823F8: lw          $t7, 0x6964($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6964);
    // 0x800823FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80082400: bne         $t7, $zero, L_80082440
    if (ctx->r15 != 0) {
        // 0x80082404: nop
    
            goto L_80082440;
    }
    // 0x80082404: nop

    // 0x80082408: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008240C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80082410: blez        $t8, L_80082440
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80082414: nop
    
            goto L_80082440;
    }
    // 0x80082414: nop

L_80082418:
    // 0x80082418: jal         0x8006A794
    // 0x8008241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80082420: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80082424: lw          $t9, -0x5C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5C4);
    // 0x80082428: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008242C: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80082430: bne         $at, $zero, L_80082418
    if (ctx->r1 != 0) {
        // 0x80082434: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_80082418;
    }
    // 0x80082434: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x80082438: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8008243C: nop

L_80082440:
    // 0x80082440: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80082444: addiu       $s0, $s0, 0x6DF4
    ctx->r16 = ADD32(ctx->r16, 0X6DF4);
    // 0x80082448: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8008244C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80082450: addu        $t1, $t0, $s3
    ctx->r9 = ADD32(ctx->r8, ctx->r19);
    // 0x80082454: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80082458: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008245C: addiu       $s5, $s5, 0x6E00
    ctx->r21 = ADD32(ctx->r21, 0X6E00);
    // 0x80082460: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80082464:
    // 0x80082464: beq         $a3, $zero, L_80082484
    if (ctx->r7 == 0) {
        // 0x80082468: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80082484;
    }
    // 0x80082468: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8008246C: beq         $v0, $s3, L_800824E4
    if (ctx->r2 == ctx->r19) {
        // 0x80082470: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800824E4;
    }
    // 0x80082470: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082474: beq         $v0, $s4, L_80082588
    if (ctx->r2 == ctx->r20) {
        // 0x80082478: andi        $t9, $s1, 0x9000
        ctx->r25 = ctx->r17 & 0X9000;
            goto L_80082588;
    }
    // 0x80082478: andi        $t9, $s1, 0x9000
    ctx->r25 = ctx->r17 & 0X9000;
    // 0x8008247C: b           L_800825D0
    // 0x80082480: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x80082480: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082484:
    // 0x80082484: andi        $t2, $s1, 0x9000
    ctx->r10 = ctx->r17 & 0X9000;
    // 0x80082488: beq         $t2, $zero, L_800824A4
    if (ctx->r10 == 0) {
        // 0x8008248C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800824A4;
    }
    // 0x8008248C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082490: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80082494: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x80082498: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008249C: b           L_800825CC
    // 0x800824A0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_800825CC;
    // 0x800824A0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_800824A4:
    // 0x800824A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800824A8: lw          $v1, 0x6DF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DF8);
    // 0x800824AC: nop

    // 0x800824B0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800824B4: bne         $at, $zero, L_800824CC
    if (ctx->r1 != 0) {
        // 0x800824B8: subu        $t3, $v0, $v1
        ctx->r11 = SUB32(ctx->r2, ctx->r3);
            goto L_800824CC;
    }
    // 0x800824B8: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x800824BC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800824C0: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x800824C4: b           L_800825CC
    // 0x800824C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_800825CC;
    // 0x800824C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_800824CC:
    // 0x800824CC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800824D0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800824D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800824D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800824DC: b           L_800825CC
    // 0x800824E0: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
        goto L_800825CC;
    // 0x800824E0: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
L_800824E4:
    // 0x800824E4: lw          $v1, 0x6DFC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DFC);
    // 0x800824E8: andi        $v0, $s1, 0x9000
    ctx->r2 = ctx->r17 & 0X9000;
    // 0x800824EC: bgez        $v1, L_800824F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800824F0: nop
    
            goto L_800824F8;
    }
    // 0x800824F0: nop

    // 0x800824F4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800824F8:
    // 0x800824F8: beq         $v0, $zero, L_80082530
    if (ctx->r2 == 0) {
        // 0x800824FC: nop
    
            goto L_80082530;
    }
    // 0x800824FC: nop

    // 0x80082500: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80082504: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80082508: slt         $at, $zero, $t5
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8008250C: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x80082510: beq         $at, $zero, L_80082524
    if (ctx->r1 == 0) {
        // 0x80082514: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80082524;
    }
    // 0x80082514: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80082518: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008251C: jal         0x80001D04
    // 0x80082520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80082520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80082524:
    // 0x80082524: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80082528: b           L_800825D0
    // 0x8008252C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x8008252C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082530:
    // 0x80082530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082534: nop

    // 0x80082538: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008253C: bne         $at, $zero, L_80082570
    if (ctx->r1 != 0) {
        // 0x80082540: subu        $t6, $v0, $v1
        ctx->r14 = SUB32(ctx->r2, ctx->r3);
            goto L_80082570;
    }
    // 0x80082540: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80082544: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80082548: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008254C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80082550: beq         $at, $zero, L_80082564
    if (ctx->r1 == 0) {
        // 0x80082554: sw          $s4, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r20;
            goto L_80082564;
    }
    // 0x80082554: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x80082558: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008255C: jal         0x80001D04
    // 0x80082560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80082560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80082564:
    // 0x80082564: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80082568: b           L_800825D0
    // 0x8008256C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_800825D0;
    // 0x8008256C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082570:
    // 0x80082570: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80082574: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80082578: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008257C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082580: b           L_800825CC
    // 0x80082584: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
        goto L_800825CC;
    // 0x80082584: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_80082588:
    // 0x80082588: bne         $t9, $zero, L_800825A8
    if (ctx->r25 != 0) {
        // 0x8008258C: nop
    
            goto L_800825A8;
    }
    // 0x8008258C: nop

    // 0x80082590: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082594: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80082598: nop

    // 0x8008259C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800825A0: bne         $at, $zero, L_800825B4
    if (ctx->r1 != 0) {
        // 0x800825A4: nop
    
            goto L_800825B4;
    }
    // 0x800825A4: nop

L_800825A8:
    // 0x800825A8: sw          $s6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r22;
    // 0x800825AC: b           L_800825CC
    // 0x800825B0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
        goto L_800825CC;
    // 0x800825B0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
L_800825B4:
    // 0x800825B4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800825B8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800825BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800825C0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800825C4: nop

    // 0x800825C8: div.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
L_800825CC:
    // 0x800825CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800825D0:
    // 0x800825D0: nop

    // 0x800825D4: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800825D8: nop

    // 0x800825DC: bc1f        L_800825EC
    if (!c1cs) {
        // 0x800825E0: nop
    
            goto L_800825EC;
    }
    // 0x800825E0: nop

    // 0x800825E4: bne         $s6, $a3, L_80082464
    if (ctx->r22 != ctx->r7) {
        // 0x800825E8: nop
    
            goto L_80082464;
    }
    // 0x800825E8: nop

L_800825EC:
    // 0x800825EC: beq         $s6, $a3, L_80082608
    if (ctx->r22 == ctx->r7) {
        // 0x800825F0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80082608;
    }
    // 0x800825F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800825F4: lw          $a1, -0x2E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2E8);
    // 0x800825F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800825FC: jal         0x8008263C
    // 0x80082600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x80082600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80082604: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80082608:
    // 0x80082608: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008260C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80082610: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80082614: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80082618: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008261C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80082620: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80082624: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80082628: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008262C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80082630: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80082634: jr          $ra
    // 0x80082638: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80082638: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void draw_menu_elements(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008263C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80082640: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x80082644: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80082648: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8008264C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80082650: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80082654: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80082658: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8008265C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80082660: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80082664: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80082668: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8008266C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80082670: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80082674: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80082678: swc1        $f23, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8008267C: swc1        $f22, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f22.u32l;
    // 0x80082680: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80082684: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80082688: beq         $a0, $at, L_80082CC8
    if (ctx->r4 == ctx->r1) {
        // 0x8008268C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80082CC8;
    }
    // 0x8008268C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80082690: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80082694: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80082698: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008269C: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x800826A0: jal         0x8006816C
    // 0x800826A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x800826A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x800826A8: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x800826AC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800826B0: beq         $s1, $zero, L_80082C88
    if (ctx->r17 == 0) {
        // 0x800826B4: lui         $s7, 0x800E
        ctx->r23 = S32(0X800E << 16);
            goto L_80082C88;
    }
    // 0x800826B4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800826B8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800826BC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800826C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800826C4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800826C8: addiu       $s4, $s4, -0x324
    ctx->r20 = ADD32(ctx->r20, -0X324);
    // 0x800826CC: addiu       $fp, $fp, -0x2E4
    ctx->r30 = ADD32(ctx->r30, -0X2E4);
    // 0x800826D0: addiu       $s7, $s7, -0x2E0
    ctx->r23 = ADD32(ctx->r23, -0X2E0);
L_800826D4:
    // 0x800826D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800826D8: addiu       $t7, $t7, 0x6DF0
    ctx->r15 = ADD32(ctx->r15, 0X6DF0);
    // 0x800826DC: beq         $t7, $s1, L_80082C78
    if (ctx->r15 == ctx->r17) {
        // 0x800826E0: nop
    
            goto L_80082C78;
    }
    // 0x800826E0: nop

    // 0x800826E4: bne         $a0, $zero, L_80082770
    if (ctx->r4 != 0) {
        // 0x800826E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80082770;
    }
    // 0x800826E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800826EC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800826F0: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800826F4: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800826F8: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800826FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80082700: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80082704: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082708: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x8008270C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80082710: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80082714: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80082718: nop

    // 0x8008271C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80082720: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082724: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082728: nop

    // 0x8008272C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80082730: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80082734: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80082738: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008273C: addu        $s2, $t1, $v0
    ctx->r18 = ADD32(ctx->r9, ctx->r2);
    // 0x80082740: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80082744: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80082748: nop

    // 0x8008274C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80082750: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082754: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082758: nop

    // 0x8008275C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80082760: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80082764: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80082768: b           L_8008280C
    // 0x8008276C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
        goto L_8008280C;
    // 0x8008276C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
L_80082770:
    // 0x80082770: bne         $a0, $at, L_80082788
    if (ctx->r4 != ctx->r1) {
        // 0x80082774: nop
    
            goto L_80082788;
    }
    // 0x80082774: nop

    // 0x80082778: lh          $s2, 0x4($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X4);
    // 0x8008277C: lh          $s3, 0x6($s0)
    ctx->r19 = MEM_H(ctx->r16, 0X6);
    // 0x80082780: b           L_80082810
    // 0x80082784: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_80082810;
    // 0x80082784: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80082788:
    // 0x80082788: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8008278C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80082790: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80082794: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80082798: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008279C: lh          $t0, 0xA($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA);
    // 0x800827A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800827A4: subu        $t1, $t0, $v1
    ctx->r9 = SUB32(ctx->r8, ctx->r3);
    // 0x800827A8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800827AC: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800827B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800827B4: nop

    // 0x800827B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800827BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800827C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800827C4: nop

    // 0x800827C8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800827CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800827D0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800827D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800827D8: addu        $s2, $t9, $v0
    ctx->r18 = ADD32(ctx->r25, ctx->r2);
    // 0x800827DC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800827E0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800827E4: nop

    // 0x800827E8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800827EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800827F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800827F4: nop

    // 0x800827F8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800827FC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80082800: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80082804: addu        $s3, $t3, $v1
    ctx->r19 = ADD32(ctx->r11, ctx->r3);
    // 0x80082808: nop

L_8008280C:
    // 0x8008280C: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80082810:
    // 0x80082810: nop

    // 0x80082814: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80082818: beq         $at, $zero, L_80082C78
    if (ctx->r1 == 0) {
        // 0x8008281C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80082C78;
    }
    // 0x8008281C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082820: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082824: addu        $at, $at, $t4
    gpr jr_addend_80082830 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80082828: lw          $t4, -0x7704($at)
    ctx->r12 = ADD32(ctx->r1, -0X7704);
    // 0x8008282C: nop

    // 0x80082830: jr          $t4
    // 0x80082834: nop

    switch (jr_addend_80082830 >> 2) {
        case 0: goto L_80082838; break;
        case 1: goto L_800828A4; break;
        case 2: goto L_80082908; break;
        case 3: goto L_80082974; break;
        case 4: goto L_800829BC; break;
        case 5: goto L_80082A58; break;
        case 6: goto L_80082BB0; break;
        case 7: goto L_80082C10; break;
        default: switch_error(__func__, 0x80082830, 0x800E88FC);
    }
    // 0x80082834: nop

L_80082838:
    // 0x80082838: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x8008283C: lh          $a1, 0x1A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A);
    // 0x80082840: lh          $a2, 0x1C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1C);
    // 0x80082844: lh          $a3, 0x1E($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X1E);
    // 0x80082848: jal         0x800C492C
    // 0x8008284C: nop

    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008284C: nop

    after_1:
    // 0x80082850: lbu         $t5, 0x10($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X10);
    // 0x80082854: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80082858: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8008285C: lbu         $a2, 0xE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XE);
    // 0x80082860: lbu         $a3, 0xF($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XF);
    // 0x80082864: jal         0x800C48E4
    // 0x80082868: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80082868: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8008286C: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    // 0x80082870: jal         0x800C484C
    // 0x80082874: nop

    set_text_font(rdram, ctx);
        goto after_3;
    // 0x80082874: nop

    after_3:
    // 0x80082878: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8008287C: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x80082880: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80082884: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082888: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8008288C: addu        $a2, $s3, $t6
    ctx->r6 = ADD32(ctx->r19, ctx->r14);
    // 0x80082890: jal         0x800C49A0
    // 0x80082894: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80082894: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80082898: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008289C: b           L_80082C7C
    // 0x800828A0: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x800828A0: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800828A4:
    // 0x800828A4: beq         $s5, $zero, L_800828B4
    if (ctx->r21 == 0) {
        // 0x800828A8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800828B4;
    }
    // 0x800828A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800828AC: jal         0x8007B820
    // 0x800828B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800828B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_5:
L_800828B4:
    // 0x800828B4: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x800828B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800828BC: sw          $t8, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r24;
    // 0x800828C0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800828C4: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x800828C8: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x800828CC: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x800828D0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800828D4: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x800828D8: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800828DC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800828E0: lbu         $t4, 0x11($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X11);
    // 0x800828E4: negu        $t0, $s3
    ctx->r8 = SUB32(0, ctx->r19);
    // 0x800828E8: subu        $a2, $t0, $t1
    ctx->r6 = SUB32(ctx->r8, ctx->r9);
    // 0x800828EC: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x800828F0: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x800828F4: jal         0x80081C50
    // 0x800828F8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    menu_timestamp_render(rdram, ctx);
        goto after_6;
    // 0x800828F8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_6:
    // 0x800828FC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082900: b           L_80082C7C
    // 0x80082904: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082904: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082908:
    // 0x80082908: beq         $s5, $zero, L_80082920
    if (ctx->r21 == 0) {
        // 0x8008290C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082920;
    }
    // 0x8008290C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082910: jal         0x8007B820
    // 0x80082914: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x80082914: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_7:
    // 0x80082918: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x8008291C: nop

L_80082920:
    // 0x80082920: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x80082924: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80082928: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x8008292C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082930: lbu         $t8, 0xE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XE);
    // 0x80082934: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80082938: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008293C: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80082940: negu        $t5, $s3
    ctx->r13 = SUB32(0, ctx->r19);
    // 0x80082944: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80082948: lbu         $t0, 0x11($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X11);
    // 0x8008294C: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80082950: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80082954: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x80082958: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x8008295C: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x80082960: jal         0x80082054
    // 0x80082964: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    menu_number_render(rdram, ctx);
        goto after_8;
    // 0x80082964: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_8:
    // 0x80082968: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008296C: b           L_80082C7C
    // 0x80082970: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082970: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082974:
    // 0x80082974: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    // 0x80082978: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x8008297C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082980: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082984: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082988: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008298C: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x80082990: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80082994: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80082998: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x8008299C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800829A0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800829A4: addu        $a3, $s3, $t2
    ctx->r7 = ADD32(ctx->r19, ctx->r10);
    // 0x800829A8: jal         0x80078F08
    // 0x800829AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    texrect_draw(rdram, ctx);
        goto after_9;
    // 0x800829AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_9:
    // 0x800829B0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800829B4: b           L_80082C7C
    // 0x800829B8: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x800829B8: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800829BC:
    // 0x800829BC: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x800829C0: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x800829C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800829C8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800829CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800829D0: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800829D4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800829D8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800829DC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800829E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800829E4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800829E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800829EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800829F0: lh          $t0, 0x1A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A);
    // 0x800829F4: nop

    // 0x800829F8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800829FC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80082A00: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80082A04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80082A08: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80082A0C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80082A10: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80082A14: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x80082A18: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80082A1C: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x80082A20: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80082A24: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80082A28: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80082A2C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80082A30: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80082A34: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80082A38: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80082A3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80082A40: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x80082A44: jal         0x80079150
    // 0x80082A48: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x80082A48: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_10:
    // 0x80082A4C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082A50: b           L_80082C7C
    // 0x80082A54: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082A54: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082A58:
    // 0x80082A58: beq         $s5, $zero, L_80082A68
    if (ctx->r21 == 0) {
        // 0x80082A5C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082A68;
    }
    // 0x80082A5C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082A60: jal         0x8007B820
    // 0x80082A64: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x80082A64: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_11:
L_80082A68:
    // 0x80082A68: jal         0x80068748
    // 0x80082A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x80082A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80082A70: jal         0x8007C36C
    // 0x80082A74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x80082A74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80082A78: addiu       $t3, $s2, -0xA0
    ctx->r11 = ADD32(ctx->r18, -0XA0);
    // 0x80082A7C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80082A80: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80082A84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082A88: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80082A8C: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x80082A90: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80082A94: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80082A98: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80082A9C: negu        $t7, $s3
    ctx->r15 = SUB32(0, ctx->r19);
    // 0x80082AA0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80082AA4: addiu       $t0, $t9, 0x78
    ctx->r8 = ADD32(ctx->r25, 0X78);
    // 0x80082AA8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80082AAC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80082AB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082AB4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80082AB8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80082ABC: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x80082AC0: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80082AC4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80082AC8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082ACC: lbu         $t6, 0x11($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X11);
    // 0x80082AD0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80082AD4: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80082AD8: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x80082ADC: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80082AE0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80082AE4: lh          $t0, 0x18($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X18);
    // 0x80082AE8: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x80082AEC: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x80082AF0: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
    // 0x80082AF4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80082AF8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082AFC: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x80082B00: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x80082B04: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80082B08: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80082B0C: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80082B10: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80082B14: lh          $t1, 0x1C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1C);
    // 0x80082B18: sll         $t0, $t4, 5
    ctx->r8 = S32(ctx->r12 << 5);
    // 0x80082B1C: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x80082B20: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80082B24: lh          $t8, 0x1E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1E);
    // 0x80082B28: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80082B2C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80082B30: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082B34: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80082B38: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80082B3C: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80082B40: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80082B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B48: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80082B4C: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x80082B50: nop

    // 0x80082B54: sb          $t4, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r12;
    // 0x80082B58: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x80082B5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B60: sb          $t3, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r11;
    // 0x80082B64: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80082B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B6C: sb          $t0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r8;
    // 0x80082B70: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80082B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B78: sb          $t1, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = ctx->r9;
    // 0x80082B7C: lbu         $t2, 0x10($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X10);
    // 0x80082B80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B84: sw          $t2, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r10;
    // 0x80082B88: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80082B8C: jal         0x8009CFA4
    // 0x80082B90: nop

    menu_element_render(rdram, ctx);
        goto after_14;
    // 0x80082B90: nop

    after_14:
    // 0x80082B94: jal         0x80068748
    // 0x80082B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x80082B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80082B9C: jal         0x8007C36C
    // 0x80082BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x80082BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80082BA4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082BA8: b           L_80082C7C
    // 0x80082BAC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082BAC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082BB0:
    // 0x80082BB0: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x80082BB4: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x80082BB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80082BBC: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x80082BC0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80082BC4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80082BC8: lh          $t7, 0x1E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E);
    // 0x80082BCC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082BD0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80082BD4: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80082BD8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80082BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80082BE0: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082BE4: addu        $a2, $s3, $t8
    ctx->r6 = ADD32(ctx->r19, ctx->r24);
    // 0x80082BE8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80082BEC: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80082BF0: nop

    // 0x80082BF4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80082BF8: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80082BFC: jal         0x800812E0
    // 0x80082C00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80080E90(rdram, ctx);
        goto after_17;
    // 0x80082C00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_17:
    // 0x80082C04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082C08: b           L_80082C7C
    // 0x80082C0C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082C0C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082C10:
    // 0x80082C10: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x80082C14: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x80082C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80082C1C: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x80082C20: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80082C24: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80082C28: lh          $t6, 0x1E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1E);
    // 0x80082C2C: addu        $a2, $s3, $t1
    ctx->r6 = ADD32(ctx->r19, ctx->r9);
    // 0x80082C30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80082C34: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x80082C38: lbu         $t5, 0xC($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XC);
    // 0x80082C3C: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80082C40: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80082C44: sll         $t7, $t5, 24
    ctx->r15 = S32(ctx->r13 << 24);
    // 0x80082C48: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x80082C4C: or          $t3, $t7, $t4
    ctx->r11 = ctx->r15 | ctx->r12;
    // 0x80082C50: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80082C54: or          $t2, $t3, $t1
    ctx->r10 = ctx->r11 | ctx->r9;
    // 0x80082C58: or          $t6, $t2, $t8
    ctx->r14 = ctx->r10 | ctx->r24;
    // 0x80082C5C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80082C60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80082C64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082C68: jal         0x800809D0
    // 0x80082C6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80080580(rdram, ctx);
        goto after_18;
    // 0x80082C6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x80082C70: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082C74: nop

L_80082C78:
    // 0x80082C78: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082C7C:
    // 0x80082C7C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80082C80: bne         $s1, $zero, L_800826D4
    if (ctx->r17 != 0) {
        // 0x80082C84: nop
    
            goto L_800826D4;
    }
    // 0x80082C84: nop

L_80082C88:
    // 0x80082C88: beq         $s5, $zero, L_80082C9C
    if (ctx->r21 == 0) {
        // 0x80082C8C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80082C9C;
    }
    // 0x80082C8C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082C90: jal         0x8007B820
    // 0x80082C94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rendermode_reset(rdram, ctx);
        goto after_19;
    // 0x80082C94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_19:
    // 0x80082C98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80082C9C:
    // 0x80082C9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CA0: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x80082CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CA8: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082CAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CB0: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x80082CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CB8: sb          $zero, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = 0;
    // 0x80082CBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80082CC4: sw          $t5, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r13;
L_80082CC8:
    // 0x80082CC8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80082CCC: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80082CD0: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80082CD4: lwc1        $f23, 0x40($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80082CD8: lwc1        $f22, 0x44($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80082CDC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80082CE0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80082CE4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80082CE8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80082CEC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80082CF0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80082CF4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80082CF8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80082CFC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80082D00: jr          $ra
    // 0x80082D04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80082D04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void trackmenu_set_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082D10: jal         0x8006ECD0
    // 0x80082D14: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80082D14: nop

    after_0:
    // 0x80082D18: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80082D1C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80082D20: jal         0x8006B464
    // 0x80082D24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    level_count(rdram, ctx);
        goto after_1;
    // 0x80082D24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80082D28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80082D2C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80082D30: blez        $t6, L_80082DB4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80082D34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082DB4;
    }
    // 0x80082D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082D38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082D3C: addiu       $a0, $a0, 0x6AD0
    ctx->r4 = ADD32(ctx->r4, 0X6AD0);
    // 0x80082D40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80082D44:
    // 0x80082D44: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80082D48: nop

    // 0x80082D4C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80082D50: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80082D54: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80082D58:
    // 0x80082D58: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80082D5C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x80082D60: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80082D64: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80082D68: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80082D6C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80082D70: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80082D74: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80082D78: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80082D7C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80082D80: nop

    // 0x80082D84: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x80082D88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80082D8C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80082D90: nop

    // 0x80082D94: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80082D98: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80082D9C: bne         $at, $zero, L_80082D58
    if (ctx->r1 != 0) {
        // 0x80082DA0: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80082D58;
    }
    // 0x80082DA0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80082DA4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082DA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80082DAC: bne         $a1, $t2, L_80082D44
    if (ctx->r5 != ctx->r10) {
        // 0x80082DB0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80082D44;
    }
    // 0x80082DB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80082DB4:
    // 0x80082DB4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80082DB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082DBC: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x80082DC0: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80082DC4: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x80082DC8: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80082DCC: addiu       $v1, $v1, 0x6ADC
    ctx->r3 = ADD32(ctx->r3, 0X6ADC);
    // 0x80082DD0: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
L_80082DD4:
    // 0x80082DD4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80082DD8: lhu         $t3, 0xE($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0XE);
    // 0x80082DDC: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80082DE0: lhu         $t0, 0x8($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X8);
    // 0x80082DE4: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80082DE8: sh          $t6, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r14;
    // 0x80082DEC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80082DF0: lhu         $t1, 0xC($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XC);
    // 0x80082DF4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80082DF8: lw          $t5, 0x10($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X10);
    // 0x80082DFC: or          $t9, $t0, $t8
    ctx->r25 = ctx->r8 | ctx->r24;
    // 0x80082E00: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x80082E04: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80082E08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80082E0C: lhu         $t4, 0xC($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0XC);
    // 0x80082E10: nop

    // 0x80082E14: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x80082E18: sh          $t3, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r11;
    // 0x80082E1C: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80082E20: nop

    // 0x80082E24: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80082E28: nop

    // 0x80082E2C: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x80082E30: bne         $v0, $v1, L_80082DD4
    if (ctx->r2 != ctx->r3) {
        // 0x80082E34: sw          $t0, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r8;
            goto L_80082DD4;
    }
    // 0x80082E34: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    // 0x80082E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082E3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082E40: jr          $ra
    // 0x80082E44: nop

    return;
    // 0x80082E44: nop

;}
RECOMP_FUNC void menu_missing_controller(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80082E4C: addiu       $v0, $v0, -0x614
    ctx->r2 = ADD32(ctx->r2, -0X614);
    // 0x80082E50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80082E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082E58: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80082E5C: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x80082E60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082E64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082E68: beq         $t9, $zero, L_80082EEC
    if (ctx->r25 == 0) {
        // 0x80082E6C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80082EEC;
    }
    // 0x80082E6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80082E70: jal         0x8009F064
    // 0x80082E74: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x80082E74: nop

    after_0:
    // 0x80082E78: jal         0x8007FD50
    // 0x80082E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_1;
    // 0x80082E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80082E80: jal         0x800C484C
    // 0x80082E84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80082E84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80082E88: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80082E8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082E90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80082E94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80082E98: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082E9C: jal         0x800C48E4
    // 0x80082EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80082EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80082EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082EB0: jal         0x800C492C
    // 0x80082EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_4;
    // 0x80082EB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80082EB8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80082EBC: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80082EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082EC4: bne         $t1, $zero, L_80082ED0
    if (ctx->r9 != 0) {
        // 0x80082EC8: addiu       $a2, $zero, 0xD0
        ctx->r6 = ADD32(0, 0XD0);
            goto L_80082ED0;
    }
    // 0x80082EC8: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x80082ECC: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_80082ED0:
    // 0x80082ED0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082ED4: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80082ED8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80082EDC: lw          $a3, 0x25C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X25C);
    // 0x80082EE0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082EE4: jal         0x800C49A0
    // 0x80082EE8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80082EE8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_5:
L_80082EEC:
    // 0x80082EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082EF4: jr          $ra
    // 0x80082EF8: nop

    return;
    // 0x80082EF8: nop

;}
RECOMP_FUNC void menu_logos_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082F00: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80082F04: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80082F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082F14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082F24: jal         0x80077FAC
    // 0x80082F28: swc1        $f4, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f4.u32l;
    bgdraw_fillcolour(rdram, ctx);
        goto after_0;
    // 0x80082F28: swc1        $f4, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80082F2C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082F30: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F38: bne         $t6, $zero, L_80082F80
    if (ctx->r14 != 0) {
        // 0x80082F3C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082F80;
    }
    // 0x80082F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F40: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x80082F44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082F50: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80082F54: jal         0x80066B80
    // 0x80082F58: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_1;
    // 0x80082F58: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_1:
    // 0x80082F5C: addiu       $t8, $zero, 0x11C
    ctx->r24 = ADD32(0, 0X11C);
    // 0x80082F60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80082F64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082F68: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082F6C: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082F70: jal         0x80066CE8
    // 0x80082F74: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_2;
    // 0x80082F74: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x80082F78: b           L_80082FB0
    // 0x80082F7C: nop

        goto L_80082FB0;
    // 0x80082F7C: nop

L_80082F80:
    // 0x80082F80: addiu       $t9, $zero, 0xC4
    ctx->r25 = ADD32(0, 0XC4);
    // 0x80082F84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80082F88: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80082F8C: jal         0x80066B80
    // 0x80082F90: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80082F90: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x80082F94: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80082F98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082FA0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082FA4: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082FA8: jal         0x80066CE8
    // 0x80082FAC: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_4;
    // 0x80082FAC: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
L_80082FB0:
    // 0x80082FB0: jal         0x80066850
    // 0x80082FB4: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_5;
    // 0x80082FB4: nop

    after_5:
    // 0x80082FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082FBC: jal         0x80066A58
    // 0x80082FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_6;
    // 0x80082FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80082FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082FCC: jr          $ra
    // 0x80082FD0: nop

    return;
    // 0x80082FD0: nop

;}
RECOMP_FUNC void menu_logo_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FD4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082FD8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082FDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082FE4: bne         $t6, $zero, L_80083068
    if (ctx->r14 != 0) {
        // 0x80082FE8: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80083068;
    }
    // 0x80082FE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80082FEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082FF0: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x80082FF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082FF8: lwc1        $f4, -0x76E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76E4);
    // 0x80082FFC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80083000: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80083004: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80083008: bc1f        L_80083040
    if (!c1cs) {
        // 0x8008300C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80083040;
    }
    // 0x8008300C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083010: lw          $t8, -0x604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X604);
    // 0x80083014: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083018: bne         $t8, $zero, L_80083044
    if (ctx->r24 != 0) {
        // 0x8008301C: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80083044;
    }
    // 0x8008301C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80083020: jal         0x800C06F8
    // 0x80083024: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80083024: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    after_0:
    // 0x80083028: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008302C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083030: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x80083034: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083038: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008303C: nop

L_80083040:
    // 0x80083040: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80083044:
    // 0x80083044: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80083048: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8008304C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083050: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80083054: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083058: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008305C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80083060: b           L_800830E0
    // 0x80083064: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
        goto L_800830E0;
    // 0x80083064: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
L_80083068:
    // 0x80083068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008306C: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x80083070: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083074: lwc1        $f4, -0x76E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76E0);
    // 0x80083078: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8008307C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80083080: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80083084: bc1f        L_800830C0
    if (!c1cs) {
        // 0x80083088: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_800830C0;
    }
    // 0x80083088: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008308C: lw          $t1, -0x604($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X604);
    // 0x80083090: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083094: bne         $t1, $zero, L_800830C0
    if (ctx->r9 != 0) {
        // 0x80083098: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_800830C0;
    }
    // 0x80083098: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008309C: jal         0x800C06F8
    // 0x800830A0: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x800830A0: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    after_1:
    // 0x800830A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800830A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800830AC: sw          $t2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r10;
    // 0x800830B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830B4: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x800830B8: nop

    // 0x800830BC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_800830C0:
    // 0x800830C0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800830C4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800830C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800830CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800830D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830D4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800830D8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800830DC: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
L_800830E0:
    // 0x800830E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830E4: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x800830E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800830EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800830F0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800830F4: nop

    // 0x800830F8: bc1f        L_80083144
    if (!c1cs) {
        // 0x800830FC: lui         $at, 0x4021
        ctx->r1 = S32(0X4021 << 16);
            goto L_80083144;
    }
    // 0x800830FC: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80083100: jal         0x80066AD4
    // 0x80083104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x80083104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80083108: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x8008310C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80083110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80083114: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80083118: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8008311C: jal         0x80066CE8
    // 0x80083120: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x80083120: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x80083124: jal         0x800833FC
    // 0x80083128: nop

    init_title_screen_variables(rdram, ctx);
        goto after_4;
    // 0x80083128: nop

    after_4:
    // 0x8008312C: jal         0x80081820
    // 0x80083130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_5;
    // 0x80083130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80083134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083138: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008313C: nop

    // 0x80083140: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
L_80083144:
    // 0x80083144: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80083148: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008314C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80083150: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80083154: nop

    // 0x80083158: bc1f        L_800833F0
    if (!c1cs) {
        // 0x8008315C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800833F0;
    }
    // 0x8008315C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083160: jal         0x800C484C
    // 0x80083164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x80083164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80083168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008316C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083174: jal         0x800C492C
    // 0x80083178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_7;
    // 0x80083178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8008317C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80083180: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80083184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083188: lwc1        $f10, 0x69F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008318C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80083190: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80083194: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80083198: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8008319C: bc1f        L_80083200
    if (!c1cs) {
        // 0x800831A0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80083200;
    }
    // 0x800831A0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800831A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800831A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800831AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800831B0: c.le.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d <= ctx->f0.d;
    // 0x800831B4: nop

    // 0x800831B8: bc1f        L_80083200
    if (!c1cs) {
        // 0x800831BC: nop
    
            goto L_80083200;
    }
    // 0x800831BC: nop

    // 0x800831C0: sub.d       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f12.d - ctx->f0.d;
    // 0x800831C4: lwc1        $f5, -0x76D8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X76D8);
    // 0x800831C8: lwc1        $f4, -0x76D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76D4);
    // 0x800831CC: nop

    // 0x800831D0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800831D4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800831D8: nop

    // 0x800831DC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800831E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800831E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800831E8: nop

    // 0x800831EC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800831F0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800831F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800831F8: b           L_8008327C
    // 0x800831FC: nop

        goto L_8008327C;
    // 0x800831FC: nop

L_80083200:
    // 0x80083200: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x80083204: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80083208: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008320C: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80083210: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80083214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083218: bc1f        L_8008327C
    if (!c1cs) {
        // 0x8008321C: nop
    
            goto L_8008327C;
    }
    // 0x8008321C: nop

    // 0x80083220: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80083224: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80083228: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008322C: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80083230: nop

    // 0x80083234: bc1f        L_8008327C
    if (!c1cs) {
        // 0x80083238: nop
    
            goto L_8008327C;
    }
    // 0x80083238: nop

    // 0x8008323C: sub.d       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f0.d - ctx->f2.d;
    // 0x80083240: lwc1        $f19, -0x76D0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X76D0);
    // 0x80083244: lwc1        $f18, -0x76CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76CC);
    // 0x80083248: nop

    // 0x8008324C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80083250: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80083254: nop

    // 0x80083258: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8008325C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083264: nop

    // 0x80083268: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008326C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80083270: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80083274: b           L_8008327C
    // 0x80083278: nop

        goto L_8008327C;
    // 0x80083278: nop

L_8008327C:
    // 0x8008327C: beq         $v0, $zero, L_8008334C
    if (ctx->r2 == 0) {
        // 0x80083280: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008334C;
    }
    // 0x80083280: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083288: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008328C: jal         0x800C48E4
    // 0x80083290: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80083290: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80083294: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083298: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008329C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832A0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800832A4: addiu       $a2, $a2, 0xD4
    ctx->r6 = ADD32(ctx->r6, 0XD4);
    // 0x800832A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800832AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800832B0: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800832B8: jal         0x800C49A0
    // 0x800832BC: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x800832BC: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    after_9:
    // 0x800832C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800832C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800832C8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832CC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800832D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800832D4: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832D8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800832DC: jal         0x800C49A0
    // 0x800832E0: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x800832E0: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    after_10:
    // 0x800832E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800832E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800832EC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832F0: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800832F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800832F8: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832FC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80083300: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80083304: jal         0x800C49A0
    // 0x80083308: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80083308: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    after_11:
    // 0x8008330C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083310: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083314: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80083318: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8008331C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80083320: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x80083324: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80083328: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008332C: jal         0x800C49A0
    // 0x80083330: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80083330: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    after_12:
    // 0x80083334: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083338: lwc1        $f8, 0x69F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008333C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80083340: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80083344: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80083348: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_8008334C:
    // 0x8008334C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80083350: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80083354: addiu       $t2, $t1, 0xD4
    ctx->r10 = ADD32(ctx->r9, 0XD4);
    // 0x80083358: bc1f        L_800833AC
    if (!c1cs) {
        // 0x8008335C: sw          $t2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r10;
            goto L_800833AC;
    }
    // 0x8008335C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80083360: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80083364: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80083368: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008336C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083370: lwc1        $f19, -0x76C8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X76C8);
    // 0x80083374: lwc1        $f18, -0x76C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76C4);
    // 0x80083378: sub.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d - ctx->f0.d;
    // 0x8008337C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80083380: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80083384: nop

    // 0x80083388: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8008338C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083390: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083394: nop

    // 0x80083398: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008339C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800833A0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800833A4: b           L_800833B4
    // 0x800833A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_800833B4;
    // 0x800833A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800833AC:
    // 0x800833AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800833B0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800833B4:
    // 0x800833B4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800833B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800833BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800833C0: jal         0x800C48E4
    // 0x800833C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x800833C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
    // 0x800833C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800833CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800833D0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800833D4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800833D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800833DC: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800833E0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800833E4: jal         0x800C49A0
    // 0x800833E8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x800833E8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_14:
    // 0x800833EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800833F0:
    // 0x800833F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800833F4: jr          $ra
    // 0x800833F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800833F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void init_title_screen_variables(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083400: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x80083404: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80083408: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008340C: lw          $t6, 0x69E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69E8);
    // 0x80083410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083414: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80083418: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8008341C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80083420: beq         $t9, $zero, L_8008344C
    if (ctx->r25 == 0) {
        // 0x80083424: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_8008344C;
    }
    // 0x80083424: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80083428: jal         0x8009C824
    // 0x8008342C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_0;
    // 0x8008342C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80083430: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083434: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083438: lw          $t1, 0x69EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X69EC);
    // 0x8008343C: lw          $t0, 0x69E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X69E8);
    // 0x80083440: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083444: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80083448: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_8008344C:
    // 0x8008344C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80083450: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083454: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80083458: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008345C: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083460: bne         $t5, $at, L_8008348C
    if (ctx->r13 != ctx->r1) {
        // 0x80083464: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_8008348C;
    }
    // 0x80083464: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80083468: jal         0x8009C824
    // 0x8008346C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_1;
    // 0x8008346C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80083470: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80083474: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083478: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8008347C: lw          $t6, 0x69E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69E8);
    // 0x80083480: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80083484: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80083488: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_8008348C:
    // 0x8008348C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80083490: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80083494: beq         $t1, $zero, L_800834A8
    if (ctx->r9 == 0) {
        // 0x80083498: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800834A8;
    }
    // 0x80083498: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008349C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800834A0: b           L_800834AC
    // 0x800834A4: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
        goto L_800834AC;
    // 0x800834A4: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
L_800834A8:
    // 0x800834A8: sw          $zero, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = 0;
L_800834AC:
    // 0x800834AC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800834B0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800834B4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800834B8: bne         $t7, $zero, L_800834C8
    if (ctx->r15 != 0) {
        // 0x800834BC: nop
    
            goto L_800834C8;
    }
    // 0x800834BC: nop

    // 0x800834C0: jal         0x800C3014
    // 0x800834C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_2;
    // 0x800834C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_800834C8:
    // 0x800834C8: jal         0x8009F064
    // 0x800834CC: nop

    get_language(rdram, ctx);
        goto after_3;
    // 0x800834CC: nop

    after_3:
    // 0x800834D0: jal         0x8007FD50
    // 0x800834D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x800834D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800834D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800834DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800834E0: jr          $ra
    // 0x800834E4: nop

    return;
    // 0x800834E4: nop

;}
RECOMP_FUNC void func_80083098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834E8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800834EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800834F0: lw          $v0, 0x6EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EA0);
    // 0x800834F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800834F8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800834FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80083500: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80083504: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80083508: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008350C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80083510: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80083514: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80083518: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8008351C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80083520: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80083524: beq         $at, $zero, L_8008394C
    if (ctx->r1 == 0) {
        // 0x80083528: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_8008394C;
    }
    // 0x80083528: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8008352C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083530: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80083534: addiu       $v1, $v1, 0x6E98
    ctx->r3 = ADD32(ctx->r3, 0X6E98);
    // 0x80083538: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8008353C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80083540: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083544: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80083548: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008354C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80083550: addiu       $t7, $t7, -0x244
    ctx->r15 = ADD32(ctx->r15, -0X244);
    // 0x80083554: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083558: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8008355C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80083560: jal         0x800C484C
    // 0x80083564: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x80083564: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80083568: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008356C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083574: jal         0x800C492C
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008357C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80083580: addiu       $s2, $s2, -0x8C
    ctx->r18 = ADD32(ctx->r18, -0X8C);
    // 0x80083584: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80083588: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008358C: blez        $a0, L_80083690
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80083590: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80083690;
    }
    // 0x80083590: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083594: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083598: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8008359C: addiu       $s5, $s5, -0x88
    ctx->r21 = ADD32(ctx->r21, -0X88);
    // 0x800835A0: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x800835A4: addiu       $s0, $s0, 0x6E18
    ctx->r16 = ADD32(ctx->r16, 0X6E18);
    // 0x800835A8: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_800835AC:
    // 0x800835AC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800835B0: nop

    // 0x800835B4: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800835B8: mflo        $t0
    ctx->r8 = lo;
    // 0x800835BC: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x800835C0: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x800835C4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800835C8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800835CC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800835D0: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x800835D4: jal         0x800C48E4
    // 0x800835D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x800835D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800835DC: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x800835E0: lh          $a2, 0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XA);
    // 0x800835E4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800835E8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800835EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800835F0: jal         0x800C49A0
    // 0x800835F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_3;
    // 0x800835F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x800835F8: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800835FC: nop

    // 0x80083600: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80083604: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80083608: bne         $at, $zero, L_80083678
    if (ctx->r1 != 0) {
        // 0x8008360C: sw          $t3, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r11;
            goto L_80083678;
    }
    // 0x8008360C: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x80083610: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80083614: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80083618: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8008361C: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80083620: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80083624: beq         $at, $zero, L_80083684
    if (ctx->r1 == 0) {
        // 0x80083628: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80083684;
    }
    // 0x80083628: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008362C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80083630: addiu       $t8, $t8, 0x6E18
    ctx->r24 = ADD32(ctx->r24, 0X6E18);
    // 0x80083634: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x80083638: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8008363C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80083640: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80083644:
    // 0x80083644: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80083648: lh          $t2, 0x18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X18);
    // 0x8008364C: lh          $t3, 0x1A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1A);
    // 0x80083650: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80083654: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80083658: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008365C: sw          $t1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r9;
    // 0x80083660: sh          $t2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r10;
    // 0x80083664: sh          $t3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r11;
    // 0x80083668: bne         $at, $zero, L_80083644
    if (ctx->r1 != 0) {
        // 0x8008366C: sw          $t4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r12;
            goto L_80083644;
    }
    // 0x8008366C: sw          $t4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r12;
    // 0x80083670: b           L_80083688
    // 0x80083674: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80083688;
    // 0x80083674: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083678:
    // 0x80083678: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008367C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083680: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80083684:
    // 0x80083684: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083688:
    // 0x80083688: bne         $at, $zero, L_800835AC
    if (ctx->r1 != 0) {
        // 0x8008368C: nop
    
            goto L_800835AC;
    }
    // 0x8008368C: nop

L_80083690:
    // 0x80083690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083694: lwc1        $f16, 0x6E98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E98);
    // 0x80083698: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8008369C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800836A0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800836A4: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x800836A8: bc1f        L_800838D4
    if (!c1cs) {
        // 0x800836AC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800838D4;
    }
    // 0x800836AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800836B0: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800836B4: nop

    // 0x800836B8: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800836BC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800836C0: nop

    // 0x800836C4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800836C8: nop

    // 0x800836CC: bc1f        L_8008377C
    if (!c1cs) {
        // 0x800836D0: nop
    
            goto L_8008377C;
    }
    // 0x800836D0: nop

    // 0x800836D4: lwc1        $f12, 0x14($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800836D8: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x800836DC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800836E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800836E4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800836E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800836EC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800836F0: nop

    // 0x800836F4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800836F8: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800836FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80083700: nop

    // 0x80083704: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80083708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008370C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083710: nop

    // 0x80083714: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80083718: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8008371C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80083720: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80083724: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083728: lwc1        $f14, 0x18($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8008372C: nop

    // 0x80083730: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80083734: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80083738: nop

    // 0x8008373C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083740: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80083744: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80083748: nop

    // 0x8008374C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80083750: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083754: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083758: nop

    // 0x8008375C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083760: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80083764: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80083768: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8008376C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80083770: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80083774: b           L_800838D4
    // 0x80083778: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
        goto L_800838D4;
    // 0x80083778: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_8008377C:
    // 0x8008377C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80083780: nop

    // 0x80083784: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80083788: nop

    // 0x8008378C: bc1f        L_800837F8
    if (!c1cs) {
        // 0x80083790: nop
    
            goto L_800837F8;
    }
    // 0x80083790: nop

    // 0x80083794: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80083798: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8008379C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800837A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800837A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800837A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800837AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800837B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800837B4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800837B8: nop

    // 0x800837BC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800837C0: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x800837C4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800837C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800837CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800837D0: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800837D4: nop

    // 0x800837D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800837DC: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800837E0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800837E4: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800837E8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800837EC: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800837F0: b           L_800838D4
    // 0x800837F4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
        goto L_800838D4;
    // 0x800837F4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800837F8:
    // 0x800837F8: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800837FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083800: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80083804: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80083808: addiu       $v0, $v0, 0x6EA0
    ctx->r2 = ADD32(ctx->r2, 0X6EA0);
    // 0x8008380C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80083810: nop

    // 0x80083814: bc1f        L_800838C4
    if (!c1cs) {
        // 0x80083818: nop
    
            goto L_800838C4;
    }
    // 0x80083818: nop

    // 0x8008381C: lwc1        $f12, 0x1C($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80083820: lwc1        $f8, 0x24($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80083824: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80083828: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008382C: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80083830: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80083834: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80083838: nop

    // 0x8008383C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083840: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80083844: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80083848: nop

    // 0x8008384C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80083850: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083854: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083858: nop

    // 0x8008385C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083860: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80083864: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80083868: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008386C: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80083870: lwc1        $f14, 0x20($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083874: nop

    // 0x80083878: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8008387C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80083880: nop

    // 0x80083884: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80083888: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8008388C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80083890: nop

    // 0x80083894: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80083898: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008389C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800838A0: nop

    // 0x800838A4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800838A8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800838AC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800838B0: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x800838B4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800838B8: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x800838BC: b           L_800838D4
    // 0x800838C0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_800838D4;
    // 0x800838C0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_800838C4:
    // 0x800838C4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800838C8: nop

    // 0x800838CC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800838D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800838D4:
    // 0x800838D4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800838D8: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800838DC: beq         $t7, $zero, L_8008394C
    if (ctx->r15 == 0) {
        // 0x800838E0: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_8008394C;
    }
    // 0x800838E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800838E4: beq         $at, $zero, L_80083920
    if (ctx->r1 == 0) {
        // 0x800838E8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80083920;
    }
    // 0x800838E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800838EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800838F0: addiu       $t8, $t8, 0x6E18
    ctx->r24 = ADD32(ctx->r24, 0X6E18);
    // 0x800838F4: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x800838F8: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800838FC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80083900: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80083904: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80083908: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x8008390C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80083910: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80083914: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80083918: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8008391C: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
L_80083920:
    // 0x80083920: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80083924: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80083928: jal         0x800C48E4
    // 0x8008392C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008392C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_4:
    // 0x80083930: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80083934: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80083938: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8008393C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80083940: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80083944: jal         0x800C49A0
    // 0x80083948: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80083948: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_5:
L_8008394C:
    // 0x8008394C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80083950: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80083954: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80083958: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008395C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80083960: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80083964: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80083968: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008396C: jr          $ra
    // 0x80083970: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80083970: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void menu_title_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083974: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008397C: sw          $t6, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = ctx->r14;
    // 0x80083980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083988: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008398C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083990: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083994: jal         0x8009C698
    // 0x80083998: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    reset_character_id_slots(rdram, ctx);
        goto after_0;
    // 0x80083998: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    after_0:
    // 0x8008399C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839A0: sw          $zero, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = 0;
    // 0x800839A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839A8: sw          $zero, -0x624($at)
    MEM_W(-0X624, ctx->r1) = 0;
    // 0x800839AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839B0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800839B4: jal         0x8006A674
    // 0x800839B8: sw          $t7, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r15;
    input_assign_players(rdram, ctx);
        goto after_1;
    // 0x800839B8: sw          $t7, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r15;
    after_1:
    // 0x800839BC: jal         0x80000B34
    // 0x800839C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    music_play(rdram, ctx);
        goto after_2;
    // 0x800839C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800839C4: jal         0x80001AEC
    // 0x800839C8: nop

    music_volume(rdram, ctx);
        goto after_3;
    // 0x800839C8: nop

    after_3:
    // 0x800839CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800839D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839D4: sw          $v0, -0x320($at)
    MEM_W(-0X320, ctx->r1) = ctx->r2;
    // 0x800839D8: addiu       $v1, $v1, -0x628
    ctx->r3 = ADD32(ctx->r3, -0X628);
    // 0x800839DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800839E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800839E4: beq         $t8, $zero, L_800839FC
    if (ctx->r24 == 0) {
        // 0x800839E8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800839FC;
    }
    // 0x800839E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800839EC: sw          $zero, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = 0;
    // 0x800839F0: b           L_80083A04
    // 0x800839F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80083A04;
    // 0x800839F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800839F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800839FC:
    // 0x800839FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A00: sw          $t9, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = ctx->r25;
L_80083A04:
    // 0x80083A04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80083A08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A0C: swc1        $f4, 0x6E10($at)
    MEM_W(0X6E10, ctx->r1) = ctx->f4.u32l;
    // 0x80083A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083A18: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80083A1C: jal         0x8009CBB8
    // 0x80083A20: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_load(rdram, ctx);
        goto after_4;
    // 0x80083A20: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_4:
    // 0x80083A24: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80083A28: lh          $t0, -0x2BC($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2BC);
    // 0x80083A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083A30: addiu       $a0, $a0, 0x6AF0
    ctx->r4 = ADD32(ctx->r4, 0X6AF0);
    // 0x80083A34: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80083A38: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083A3C: lh          $t4, -0x2BA($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2BA);
    // 0x80083A40: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80083A44: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80083A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083A4C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083A50: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80083A54: lh          $t8, -0x2B8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2B8);
    // 0x80083A58: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083A5C: sw          $t3, -0x2A4($at)
    MEM_W(-0X2A4, ctx->r1) = ctx->r11;
    // 0x80083A60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80083A64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083A68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80083A6C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80083A70: sw          $t7, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = ctx->r15;
    // 0x80083A74: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80083A78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80083A7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083A80: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083A84: addiu       $a1, $a1, -0x2A6
    ctx->r5 = ADD32(ctx->r5, -0X2A6);
    // 0x80083A88: addiu       $v0, $v0, -0x2B6
    ctx->r2 = ADD32(ctx->r2, -0X2B6);
    // 0x80083A8C: addiu       $v1, $v1, -0x28C
    ctx->r3 = ADD32(ctx->r3, -0X28C);
    // 0x80083A90: sw          $t1, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r9;
L_80083A94:
    // 0x80083A94: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80083A98: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80083A9C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80083AA0: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80083AA4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80083AA8: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x80083AAC: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x80083AB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80083AB4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80083AB8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80083ABC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80083AC0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083AC4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80083AC8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80083ACC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083AD0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80083AD4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80083AD8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80083ADC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80083AE0: sw          $t9, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r25;
    // 0x80083AE4: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x80083AE8: bne         $v0, $a1, L_80083A94
    if (ctx->r2 != ctx->r5) {
        // 0x80083AEC: sw          $t3, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r11;
            goto L_80083A94;
    }
    // 0x80083AEC: sw          $t3, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r11;
    // 0x80083AF0: jal         0x80000BE0
    // 0x80083AF4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    music_voicelimit_set(rdram, ctx);
        goto after_5;
    // 0x80083AF4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_5:
    // 0x80083AF8: jal         0x80066300
    // 0x80083AFC: nop

    cam_shake_off(rdram, ctx);
        goto after_6;
    // 0x80083AFC: nop

    after_6:
    // 0x80083B00: jal         0x800C484C
    // 0x80083B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80083B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80083B08: jal         0x800C46D0
    // 0x80083B0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x80083B0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80083B10: jal         0x80000890
    // 0x80083B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_reset(rdram, ctx);
        goto after_9;
    // 0x80083B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80083B18: jal         0x8000E4BC
    // 0x80083B1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x80083B1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80083B20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B24: sw          $zero, 0x6E04($at)
    MEM_W(0X6E04, ctx->r1) = 0;
    // 0x80083B28: jal         0x8001E2D0
    // 0x80083B2C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x80083B2C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_11:
    // 0x80083B30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083B34: addiu       $a0, $a0, 0x6E14
    ctx->r4 = ADD32(ctx->r4, 0X6E14);
    // 0x80083B38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80083B3C: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x80083B40: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80083B44: addiu       $a2, $a2, 0x6E08
    ctx->r6 = ADD32(ctx->r6, 0X6E08);
    // 0x80083B48: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083B4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80083B50: bne         $a1, $at, L_80083B64
    if (ctx->r5 != ctx->r1) {
        // 0x80083B54: sh          $zero, 0x0($a2)
        MEM_H(0X0, ctx->r6) = 0;
            goto L_80083B64;
    }
    // 0x80083B54: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80083B58: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x80083B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083B60: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80083B64:
    // 0x80083B64: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80083B68: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80083B6C: jal         0x8006E528
    // 0x80083B70: nop

    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x80083B70: nop

    after_12:
    // 0x80083B74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80083B78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B7C: swc1        $f6, 0x6E98($at)
    MEM_W(0X6E98, ctx->r1) = ctx->f6.u32l;
    // 0x80083B80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B84: sw          $zero, 0x6EA0($at)
    MEM_W(0X6EA0, ctx->r1) = 0;
    // 0x80083B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B8C: sw          $zero, 0x6E9C($at)
    MEM_W(0X6E9C, ctx->r1) = 0;
    // 0x80083B90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083B94: sw          $zero, -0x8C($at)
    MEM_W(-0X8C, ctx->r1) = 0;
    // 0x80083B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083BA0: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80083BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083BA8: sw          $zero, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = 0;
    // 0x80083BAC: jr          $ra
    // 0x80083BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80083BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void render_title_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80083BB8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80083BBC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083BC0: addiu       $s0, $s0, 0x6E0C
    ctx->r16 = ADD32(ctx->r16, 0X6E0C);
    // 0x80083BC4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083BC8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80083BCC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80083BD0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80083BD4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80083BD8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80083BDC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80083BE0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80083BE4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80083BE8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80083BEC: beq         $t6, $zero, L_80083DBC
    if (ctx->r14 == 0) {
        // 0x80083BF0: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_80083DBC;
    }
    // 0x80083BF0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80083BF4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083BF8: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80083BFC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80083C00: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80083C04: jal         0x8006816C
    // 0x80083C08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80083C08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80083C0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80083C10: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x80083C14: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80083C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083C1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083C20: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80083C24: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80083C28: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80083C2C: addiu       $s7, $s7, -0x31C
    ctx->r23 = ADD32(ctx->r23, -0X31C);
    // 0x80083C30: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80083C34: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80083C38: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80083C3C: jal         0x80068748
    // 0x80083C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80083C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80083C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80083C48: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80083C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083C50: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083C54: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80083C58: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80083C5C: bc1t        L_80083C9C
    if (c1cs) {
        // 0x80083C60: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80083C9C;
    }
    // 0x80083C60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083C64: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083C68: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x80083C6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80083C70: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80083C74: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80083C78: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80083C7C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083C80: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x80083C84: lui         $a3, 0x4250
    ctx->r7 = S32(0X4250 << 16);
    // 0x80083C88: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80083C8C: jal         0x80079150
    // 0x80083C90: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_2;
    // 0x80083C90: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80083C94: b           L_80083CC8
    // 0x80083C98: nop

        goto L_80083CC8;
    // 0x80083C98: nop

L_80083C9C:
    // 0x80083C9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80083CA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80083CA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80083CA8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80083CAC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80083CB0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80083CB4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80083CB8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80083CBC: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80083CC0: jal         0x80078F08
    // 0x80083CC4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_3;
    // 0x80083CC4: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_3:
L_80083CC8:
    // 0x80083CC8: jal         0x8006F708
    // 0x80083CCC: nop

    is_controller_missing(rdram, ctx);
        goto after_4;
    // 0x80083CCC: nop

    after_4:
    // 0x80083CD0: bne         $v0, $zero, L_80083DF0
    if (ctx->r2 != 0) {
        // 0x80083CD4: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_80083DF0;
    }
    // 0x80083CD4: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80083CD8: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80083CDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80083CE0: bne         $t5, $zero, L_80083CF0
    if (ctx->r13 != 0) {
        // 0x80083CE4: addiu       $s2, $zero, 0xC0
        ctx->r18 = ADD32(0, 0XC0);
            goto L_80083CF0;
    }
    // 0x80083CE4: addiu       $s2, $zero, 0xC0
    ctx->r18 = ADD32(0, 0XC0);
    // 0x80083CE8: b           L_80083CF0
    // 0x80083CEC: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
        goto L_80083CF0;
    // 0x80083CEC: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
L_80083CF0:
    // 0x80083CF0: jal         0x800C484C
    // 0x80083CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x80083CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80083CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80083CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083D04: jal         0x800C492C
    // 0x80083D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x80083D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80083D0C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80083D10: lw          $t6, -0x2DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2DC);
    // 0x80083D14: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80083D18: beq         $t6, $zero, L_80083DF0
    if (ctx->r14 == 0) {
        // 0x80083D1C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80083DF0;
    }
    // 0x80083D1C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083D20: addiu       $t8, $t8, -0x2DC
    ctx->r24 = ADD32(ctx->r24, -0X2DC);
    // 0x80083D24: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80083D28: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80083D2C: addiu       $s3, $s3, -0x624
    ctx->r19 = ADD32(ctx->r19, -0X624);
    // 0x80083D30: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x80083D34: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80083D38: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_80083D3C:
    // 0x80083D3C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80083D40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80083D44: bne         $s1, $t9, L_80083D70
    if (ctx->r17 != ctx->r25) {
        // 0x80083D48: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80083D70;
    }
    // 0x80083D48: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083D4C: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x80083D50: nop

    // 0x80083D54: andi        $t0, $a3, 0x1F
    ctx->r8 = ctx->r7 & 0X1F;
    // 0x80083D58: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80083D5C: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80083D60: bne         $at, $zero, L_80083D74
    if (ctx->r1 != 0) {
        // 0x80083D64: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_80083D74;
    }
    // 0x80083D64: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80083D68: b           L_80083D74
    // 0x80083D6C: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
        goto L_80083D74;
    // 0x80083D6C: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
L_80083D70:
    // 0x80083D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80083D74:
    // 0x80083D74: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80083D78: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80083D7C: jal         0x800C48E4
    // 0x80083D80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80083D80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x80083D84: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80083D88: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80083D8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80083D90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083D94: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80083D98: jal         0x800C49A0
    // 0x80083D9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80083D9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80083DA0: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80083DA4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80083DA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083DAC: bne         $t4, $zero, L_80083D3C
    if (ctx->r12 != 0) {
        // 0x80083DB0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80083D3C;
    }
    // 0x80083DB0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80083DB4: b           L_80083DF4
    // 0x80083DB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80083DF4;
    // 0x80083DB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80083DBC:
    // 0x80083DBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083DC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80083DC4: lw          $t5, 0x6E04($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6E04);
    // 0x80083DC8: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083DCC: nop

    // 0x80083DD0: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80083DD4: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80083DD8: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80083DDC: nop

    // 0x80083DE0: bne         $t7, $t8, L_80083DF4
    if (ctx->r15 != ctx->r24) {
        // 0x80083DE4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80083DF4;
    }
    // 0x80083DE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80083DE8: jal         0x800834E8
    // 0x80083DEC: nop

    func_80083098(rdram, ctx);
        goto after_9;
    // 0x80083DEC: nop

    after_9:
L_80083DF0:
    // 0x80083DF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80083DF4:
    // 0x80083DF4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80083DF8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80083DFC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80083E00: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80083E04: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80083E08: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80083E0C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80083E10: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80083E14: jr          $ra
    // 0x80083E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80083E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void menu_title_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80083E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083E24: jal         0x80069F60
    // 0x80083E28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80083E28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80083E2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083E30: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80083E34: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80083E38: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80083E3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80083E40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80083E44: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x80083E48: jal         0x8008E9A4
    // 0x80083E4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    menu_input(rdram, ctx);
        goto after_1;
    // 0x80083E4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x80083E50: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80083E54: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80083E58: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80083E5C: bne         $t1, $zero, L_80083E88
    if (ctx->r9 != 0) {
        // 0x80083E60: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083E88;
    }
    // 0x80083E60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083E64: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083E68: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80083E6C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80083E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083E74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083E78: nop

    // 0x80083E7C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80083E80: b           L_80083EA4
    // 0x80083E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_80083EA4;
    // 0x80083E84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_80083E88:
    // 0x80083E88: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80083E8C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80083E90: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80083E94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80083E98: nop

    // 0x80083E9C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80083EA0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80083EA4:
    // 0x80083EA4: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083EA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80083EAC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80083EB0: beq         $at, $zero, L_80083ED0
    if (ctx->r1 == 0) {
        // 0x80083EB4: nop
    
            goto L_80083ED0;
    }
    // 0x80083EB4: nop

    // 0x80083EB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80083EBC: jal         0x80083BB4
    // 0x80083EC0: nop

    render_title_screen(rdram, ctx);
        goto after_2;
    // 0x80083EC0: nop

    after_2:
    // 0x80083EC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083EC8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083ECC: nop

L_80083ED0:
    // 0x80083ED0: beq         $v0, $zero, L_80083EE8
    if (ctx->r2 == 0) {
        // 0x80083ED4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80083EE8;
    }
    // 0x80083ED4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083ED8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083EDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083EE0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80083EE4: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_80083EE8:
    // 0x80083EE8: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80083EEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083EF0: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083EF4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80083EF8: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80083EFC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80083F00: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80083F04: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083F08: bne         $t8, $t9, L_80083F28
    if (ctx->r24 != ctx->r25) {
        // 0x80083F0C: addiu       $a3, $a3, 0x6E08
        ctx->r7 = ADD32(ctx->r7, 0X6E08);
            goto L_80083F28;
    }
    // 0x80083F0C: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083F10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083F14: lw          $t1, 0x6978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6978);
    // 0x80083F18: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083F1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083F20: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80083F24: sw          $t3, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r11;
L_80083F28:
    // 0x80083F28: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083F30: blez        $v1, L_80083FA8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80083F34: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083FA8;
    }
    // 0x80083F34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F38: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083F3C: nop

    // 0x80083F40: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x80083F44: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x80083F48: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80083F50: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x80083F54: beq         $at, $zero, L_80083F90
    if (ctx->r1 == 0) {
        // 0x80083F58: addu        $t7, $v1, $t6
        ctx->r15 = ADD32(ctx->r3, ctx->r14);
            goto L_80083F90;
    }
    // 0x80083F58: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80083F5C: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80083F60: bne         $at, $zero, L_80083F90
    if (ctx->r1 != 0) {
        // 0x80083F64: addiu       $a0, $zero, -0x300
        ctx->r4 = ADD32(0, -0X300);
            goto L_80083F90;
    }
    // 0x80083F64: addiu       $a0, $zero, -0x300
    ctx->r4 = ADD32(0, -0X300);
    // 0x80083F68: jal         0x80000C98
    // 0x80083F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80083F6C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_3:
    // 0x80083F70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083F74: jal         0x800C06F8
    // 0x80083F78: addiu       $a0, $a0, 0x2388
    ctx->r4 = ADD32(ctx->r4, 0X2388);
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x80083F78: addiu       $a0, $a0, 0x2388
    ctx->r4 = ADD32(ctx->r4, 0X2388);
    after_4:
    // 0x80083F7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083F80: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083F84: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083F88: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083F8C: nop

L_80083F90:
    // 0x80083F90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F94: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083F98: bgtz        $v1, L_80083FB4
    if (SIGNED(ctx->r3) > 0) {
        // 0x80083F9C: nop
    
            goto L_80083FB4;
    }
    // 0x80083F9C: nop

    // 0x80083FA0: b           L_80083FB4
    // 0x80083FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80083FB4;
    // 0x80083FA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80083FA8:
    // 0x80083FA8: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80083FAC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80083FB0: nop

L_80083FB4:
    // 0x80083FB4: bne         $v0, $zero, L_800840B4
    if (ctx->r2 != 0) {
        // 0x80083FB8: nop
    
            goto L_800840B4;
    }
    // 0x80083FB8: nop

    // 0x80083FBC: jal         0x800214F8
    // 0x80083FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800214C4(rdram, ctx);
        goto after_5;
    // 0x80083FC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x80083FC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083FC8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083FCC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083FD0: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80083FD4: bne         $v0, $zero, L_80083FE4
    if (ctx->r2 != 0) {
        // 0x80083FD8: addiu       $a3, $a3, 0x6E08
        ctx->r7 = ADD32(ctx->r7, 0X6E08);
            goto L_80083FE4;
    }
    // 0x80083FD8: addiu       $a3, $a3, 0x6E08
    ctx->r7 = ADD32(ctx->r7, 0X6E08);
    // 0x80083FDC: beq         $a2, $zero, L_800840B4
    if (ctx->r6 == 0) {
        // 0x80083FE0: nop
    
            goto L_800840B4;
    }
    // 0x80083FE0: nop

L_80083FE4:
    // 0x80083FE4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80083FE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083FEC: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80083FF0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80083FF4: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x80083FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083FFC: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80084000: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x80084004: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80084008: bne         $t2, $at, L_80084018
    if (ctx->r10 != ctx->r1) {
        // 0x8008400C: addiu       $t6, $zero, 0x5DC
        ctx->r14 = ADD32(0, 0X5DC);
            goto L_80084018;
    }
    // 0x8008400C: addiu       $t6, $zero, 0x5DC
    ctx->r14 = ADD32(0, 0X5DC);
    // 0x80084010: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80084014: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80084018:
    // 0x80084018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008401C: addiu       $v0, $v0, 0x6E0C
    ctx->r2 = ADD32(ctx->r2, 0X6E0C);
    // 0x80084020: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80084024: nop

    // 0x80084028: bne         $t4, $zero, L_80084034
    if (ctx->r12 != 0) {
        // 0x8008402C: nop
    
            goto L_80084034;
    }
    // 0x8008402C: nop

    // 0x80084030: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80084034:
    // 0x80084034: lb          $a1, 0x1($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X1);
    // 0x80084038: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008403C: bne         $a1, $at, L_8008404C
    if (ctx->r5 != ctx->r1) {
        // 0x80084040: sh          $zero, 0x0($a3)
        MEM_H(0X0, ctx->r7) = 0;
            goto L_8008404C;
    }
    // 0x80084040: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80084044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084048: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
L_8008404C:
    // 0x8008404C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80084050: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80084054: jal         0x8006E528
    // 0x80084058: nop

    load_level_for_menu(rdram, ctx);
        goto after_6;
    // 0x80084058: nop

    after_6:
    // 0x8008405C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80084060: addiu       $t0, $t0, 0x6E04
    ctx->r8 = ADD32(ctx->r8, 0X6E04);
    // 0x80084064: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084068: lw          $v0, 0x6E14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E14);
    // 0x8008406C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80084070: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x80084074: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80084078: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8008407C: nop

    // 0x80084080: bne         $t9, $t1, L_800840B4
    if (ctx->r25 != ctx->r9) {
        // 0x80084084: nop
    
            goto L_800840B4;
    }
    // 0x80084084: nop

    // 0x80084088: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008408C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084090: swc1        $f8, 0x6E98($at)
    MEM_W(0X6E98, ctx->r1) = ctx->f8.u32l;
    // 0x80084094: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084098: sw          $zero, 0x6EA0($at)
    MEM_W(0X6EA0, ctx->r1) = 0;
    // 0x8008409C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800840A0: sw          $zero, 0x6E9C($at)
    MEM_W(0X6E9C, ctx->r1) = 0;
    // 0x800840A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800840A8: sw          $zero, -0x8C($at)
    MEM_W(-0X8C, ctx->r1) = 0;
    // 0x800840AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800840B0: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
L_800840B4:
    // 0x800840B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800840B8: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800840BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800840C0: nop

    // 0x800840C4: beq         $v0, $zero, L_800841FC
    if (ctx->r2 == 0) {
        // 0x800840C8: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_800841FC;
    }
    // 0x800840C8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800840CC: beq         $at, $zero, L_80084138
    if (ctx->r1 == 0) {
        // 0x800840D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80084138;
    }
    // 0x800840D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800840D4: bne         $v0, $at, L_800840F4
    if (ctx->r2 != ctx->r1) {
        // 0x800840D8: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800840F4;
    }
    // 0x800840D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800840DC: jal         0x80001D04
    // 0x800840E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800840E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800840E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800840E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800840EC: lw          $v0, 0x6E0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E0C);
    // 0x800840F0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_800840F4:
    // 0x800840F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800840F8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800840FC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80084100: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x80084104: bne         $at, $zero, L_800841FC
    if (ctx->r1 != 0) {
        // 0x80084108: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_800841FC;
    }
    // 0x80084108: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8008410C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80084110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80084114: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80084118: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008411C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80084120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084124: jal         0x80001D04
    // 0x80084128: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x80084128: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    after_8:
    // 0x8008412C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084130: b           L_800841FC
    // 0x80084134: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_800841FC;
    // 0x80084134: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084138:
    // 0x80084138: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008413C: addiu       $v0, $v0, 0x6E10
    ctx->r2 = ADD32(ctx->r2, 0X6E10);
    // 0x80084140: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80084144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80084148: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8008414C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80084150: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80084154: nop

    // 0x80084158: bc1f        L_800841FC
    if (!c1cs) {
        // 0x8008415C: nop
    
            goto L_800841FC;
    }
    // 0x8008415C: nop

    // 0x80084160: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80084164: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80084168: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8008416C: lwc1        $f6, -0x76C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76C0);
    // 0x80084170: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80084174: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80084178: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8008417C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80084180: bc1f        L_800841B8
    if (!c1cs) {
        // 0x80084184: nop
    
            goto L_800841B8;
    }
    // 0x80084184: nop

    // 0x80084188: lw          $t7, 0x6980($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6980);
    // 0x8008418C: addiu       $a0, $zero, 0x105
    ctx->r4 = ADD32(0, 0X105);
    // 0x80084190: bne         $t7, $zero, L_800841B8
    if (ctx->r15 != 0) {
        // 0x80084194: nop
    
            goto L_800841B8;
    }
    // 0x80084194: nop

    // 0x80084198: jal         0x80001D04
    // 0x8008419C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008419C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800841A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800841A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800841A8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800841AC: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800841B0: b           L_800841FC
    // 0x800841B4: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
        goto L_800841FC;
    // 0x800841B4: sw          $t8, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r24;
L_800841B8:
    // 0x800841B8: lwc1        $f8, -0x76BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X76BC);
    // 0x800841BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800841C0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800841C4: nop

    // 0x800841C8: bc1f        L_800841FC
    if (!c1cs) {
        // 0x800841CC: nop
    
            goto L_800841FC;
    }
    // 0x800841CC: nop

    // 0x800841D0: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x800841D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800841D8: bne         $t9, $at, L_800841FC
    if (ctx->r25 != ctx->r1) {
        // 0x800841DC: addiu       $a0, $zero, 0x106
        ctx->r4 = ADD32(0, 0X106);
            goto L_800841FC;
    }
    // 0x800841DC: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x800841E0: jal         0x80001D04
    // 0x800841E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800841E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800841E8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800841EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800841F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800841F4: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
    // 0x800841F8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_800841FC:
    // 0x800841FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084200: lwc1        $f0, 0x6E10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E10);
    // 0x80084204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80084208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8008420C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80084210: nop

    // 0x80084214: bc1f        L_80084344
    if (!c1cs) {
        // 0x80084218: nop
    
            goto L_80084344;
    }
    // 0x80084218: nop

    // 0x8008421C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80084220: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80084224: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80084228: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8008422C: bc1f        L_8008428C
    if (!c1cs) {
        // 0x80084230: nop
    
            goto L_8008428C;
    }
    // 0x80084230: nop

    // 0x80084234: lw          $t2, -0x320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X320);
    // 0x80084238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008423C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80084240: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80084244: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80084248: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8008424C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80084250: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80084254: nop

    // 0x80084258: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8008425C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80084260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80084264: nop

    // 0x80084268: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008426C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80084270: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80084274: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x80084278: jal         0x80001990
    // 0x8008427C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    music_volume_set(rdram, ctx);
        goto after_11;
    // 0x8008427C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_11:
    // 0x80084280: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084284: b           L_80084344
    // 0x80084288: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x80084288: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_8008428C:
    // 0x8008428C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80084290: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084294: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80084298: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8008429C: bc1f        L_800842C4
    if (!c1cs) {
        // 0x800842A0: nop
    
            goto L_800842C4;
    }
    // 0x800842A0: nop

    // 0x800842A4: lw          $a0, -0x320($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X320);
    // 0x800842A8: nop

    // 0x800842AC: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800842B0: jal         0x80001990
    // 0x800842B4: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_12;
    // 0x800842B4: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_12:
    // 0x800842B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800842BC: b           L_80084344
    // 0x800842C0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x800842C0: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_800842C4:
    // 0x800842C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800842C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800842CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800842D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800842D4: bc1f        L_80084330
    if (!c1cs) {
        // 0x800842D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80084330;
    }
    // 0x800842D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800842DC: lw          $t7, -0x320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X320);
    // 0x800842E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800842E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800842E8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800842EC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800842F0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800842F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800842F8: nop

    // 0x800842FC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80084300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80084304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80084308: nop

    // 0x8008430C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80084310: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80084314: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80084318: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8008431C: jal         0x80001990
    // 0x80084320: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    music_volume_set(rdram, ctx);
        goto after_13;
    // 0x80084320: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_13:
    // 0x80084324: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084328: b           L_80084344
    // 0x8008432C: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
        goto L_80084344;
    // 0x8008432C: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084330:
    // 0x80084330: lbu         $a0, -0x31D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X31D);
    // 0x80084334: jal         0x80001990
    // 0x80084338: nop

    music_volume_set(rdram, ctx);
        goto after_14;
    // 0x80084338: nop

    after_14:
    // 0x8008433C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084340: addiu       $v1, $v1, 0x6E0C
    ctx->r3 = ADD32(ctx->r3, 0X6E0C);
L_80084344:
    // 0x80084344: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80084348: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008434C: bne         $t1, $zero, L_80084374
    if (ctx->r9 != 0) {
        // 0x80084350: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80084374;
    }
    // 0x80084350: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084354: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x80084358: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8008435C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80084360: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80084364: beq         $t3, $zero, L_80084484
    if (ctx->r11 == 0) {
        // 0x80084368: nop
    
            goto L_80084484;
    }
    // 0x80084368: nop

    // 0x8008436C: b           L_80084484
    // 0x80084370: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_80084484;
    // 0x80084370: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80084374:
    // 0x80084374: lw          $t5, -0x604($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X604);
    // 0x80084378: nop

    // 0x8008437C: bne         $t5, $zero, L_80084484
    if (ctx->r13 != 0) {
        // 0x80084380: nop
    
            goto L_80084484;
    }
    // 0x80084380: nop

    // 0x80084384: jal         0x8006F708
    // 0x80084388: nop

    is_controller_missing(rdram, ctx);
        goto after_15;
    // 0x80084388: nop

    after_15:
    // 0x8008438C: bne         $v0, $zero, L_80084484
    if (ctx->r2 != 0) {
        // 0x80084390: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80084484;
    }
    // 0x80084390: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084394: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084398: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x8008439C: lh          $v1, 0x6DD8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD8);
    // 0x800843A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800843A4: bgez        $v1, L_800843C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800843A8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800843C8;
    }
    // 0x800843A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800843AC: bgtz        $v0, L_800843C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800843B0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800843C8;
    }
    // 0x800843B0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800843B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800843B8: sw          $t6, -0x624($at)
    MEM_W(-0X624, ctx->r1) = ctx->r14;
    // 0x800843BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800843C0: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x800843C4: nop

L_800843C8:
    // 0x800843C8: blez        $v1, L_800843EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800843CC: nop
    
            goto L_800843EC;
    }
    // 0x800843CC: nop

    // 0x800843D0: blez        $v0, L_800843EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800843D4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800843EC;
    }
    // 0x800843D4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800843D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800843DC: sw          $t7, -0x624($at)
    MEM_W(-0X624, ctx->r1) = ctx->r15;
    // 0x800843E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800843E4: lw          $v0, -0x624($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X624);
    // 0x800843E8: nop

L_800843EC:
    // 0x800843EC: beq         $a0, $v0, L_800843FC
    if (ctx->r4 == ctx->r2) {
        // 0x800843F0: nop
    
            goto L_800843FC;
    }
    // 0x800843F0: nop

    // 0x800843F4: jal         0x80001D04
    // 0x800843F8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x800843F8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_16:
L_800843FC:
    // 0x800843FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084400: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x80084404: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80084408: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008440C: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x80084410: beq         $t9, $zero, L_80084484
    if (ctx->r25 == 0) {
        // 0x80084414: nop
    
            goto L_80084484;
    }
    // 0x80084414: nop

    // 0x80084418: lw          $t1, 0x6D84($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6D84);
    // 0x8008441C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80084420: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x80084424: bne         $t2, $zero, L_80084450
    if (ctx->r10 != 0) {
        // 0x80084428: nop
    
            goto L_80084450;
    }
    // 0x80084428: nop

L_8008442C:
    // 0x8008442C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80084430: blez        $a2, L_80084450
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80084434: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80084450;
    }
    // 0x80084434: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80084438: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8008443C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80084440: nop

    // 0x80084444: andi        $t6, $t5, 0x9000
    ctx->r14 = ctx->r13 & 0X9000;
    // 0x80084448: beq         $t6, $zero, L_8008442C
    if (ctx->r14 == 0) {
        // 0x8008444C: nop
    
            goto L_8008442C;
    }
    // 0x8008444C: nop

L_80084450:
    // 0x80084450: jal         0x8008B3B8
    // 0x80084454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    titlescreen_controller_assign(rdram, ctx);
        goto after_17;
    // 0x80084454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x80084458: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008445C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084460: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084464: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x80084468: jal         0x800C06F8
    // 0x8008446C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_18;
    // 0x8008446C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_18:
    // 0x80084470: jal         0x800C0690
    // 0x80084474: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_19;
    // 0x80084474: nop

    after_19:
    // 0x80084478: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008447C: jal         0x80001D04
    // 0x80084480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x80084480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
L_80084484:
    // 0x80084484: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80084488: lw          $t8, -0x604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X604);
    // 0x8008448C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084490: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x80084494: bne         $at, $zero, L_80084538
    if (ctx->r1 != 0) {
        // 0x80084498: nop
    
            goto L_80084538;
    }
    // 0x80084498: nop

    // 0x8008449C: jal         0x80084550
    // 0x800844A0: nop

    titlescreen_free(rdram, ctx);
        goto after_21;
    // 0x800844A0: nop

    after_21:
    // 0x800844A4: jal         0x800C06A0
    // 0x800844A8: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x800844A8: nop

    after_22:
    // 0x800844AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800844B0: lw          $t9, -0x624($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X624);
    // 0x800844B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800844B8: bne         $t9, $zero, L_80084518
    if (ctx->r25 != 0) {
        // 0x800844BC: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_80084518;
    }
    // 0x800844BC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800844C0: jal         0x8009F214
    // 0x800844C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_23;
    // 0x800844C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_23:
    // 0x800844C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800844CC: beq         $v0, $zero, L_800844D8
    if (ctx->r2 == 0) {
        // 0x800844D0: nop
    
            goto L_800844D8;
    }
    // 0x800844D0: nop

    // 0x800844D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800844D8:
    // 0x800844D8: jal         0x8009F1FC
    // 0x800844DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_24;
    // 0x800844DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_24:
    // 0x800844E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800844E4: beq         $v0, $zero, L_800844F4
    if (ctx->r2 == 0) {
        // 0x800844E8: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800844F4;
    }
    // 0x800844E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800844EC: xori        $t1, $a2, 0x3
    ctx->r9 = ctx->r6 ^ 0X3;
    // 0x800844F0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_800844F4:
    // 0x800844F4: jal         0x8006E528
    // 0x800844F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_25;
    // 0x800844F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_25:
    // 0x800844FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084500: jal         0x8008B36C
    // 0x80084504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_26;
    // 0x80084504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80084508: jal         0x80081820
    // 0x8008450C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_27;
    // 0x8008450C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_27:
    // 0x80084510: b           L_80084540
    // 0x80084514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084540;
    // 0x80084514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084518:
    // 0x80084518: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8008451C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80084520: jal         0x8006E528
    // 0x80084524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_28;
    // 0x80084524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80084528: jal         0x80081820
    // 0x8008452C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_29;
    // 0x8008452C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_29:
    // 0x80084530: b           L_80084540
    // 0x80084534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084540;
    // 0x80084534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084538:
    // 0x80084538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008453C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80084540:
    // 0x80084540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084544: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80084548: jr          $ra
    // 0x8008454C: nop

    return;
    // 0x8008454C: nop

;}
RECOMP_FUNC void titlescreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084558: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008455C: jal         0x8009C9EC
    // 0x80084560: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80084560: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_0:
    // 0x80084564: jal         0x80000BE0
    // 0x80084568: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80084568: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x8008456C: jal         0x80066310
    // 0x80084570: nop

    cam_shake_on(rdram, ctx);
        goto after_2;
    // 0x80084570: nop

    after_2:
    // 0x80084574: jal         0x800C478C
    // 0x80084578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_3;
    // 0x80084578: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8008457C: jal         0x80000890
    // 0x80084580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sound_volume_reset(rdram, ctx);
        goto after_4;
    // 0x80084580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80084584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008458C: jr          $ra
    // 0x80084590: nop

    return;
    // 0x80084590: nop

;}
RECOMP_FUNC void menu_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008459C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x800845A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800845A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800845A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800845AC: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800845B0: jal         0x800C06F8
    // 0x800845B4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x800845B4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x800845B8: jal         0x800C46D0
    // 0x800845BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_1;
    // 0x800845BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800845C0: jal         0x800C484C
    // 0x800845C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x800845C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800845C8: jal         0x80000BE0
    // 0x800845CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x800845CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x800845D0: jal         0x80000B34
    // 0x800845D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_4;
    // 0x800845D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_4:
    // 0x800845D8: jal         0x80000B18
    // 0x800845DC: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x800845DC: nop

    after_5:
    // 0x800845E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800845E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800845E8: jr          $ra
    // 0x800845EC: nop

    return;
    // 0x800845EC: nop

;}
RECOMP_FUNC void optionscreen_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800845F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800845F8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800845FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80084600: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80084604: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80084608: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008460C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80084610: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80084614: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80084618: jal         0x800C484C
    // 0x8008461C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008461C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80084620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008462C: jal         0x800C492C
    // 0x80084630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x80084630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80084634: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80084638: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008463C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084648: jal         0x800C48E4
    // 0x8008464C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008464C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80084650: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80084654: addiu       $s0, $s0, -0x5E0
    ctx->r16 = ADD32(ctx->r16, -0X5E0);
    // 0x80084658: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008465C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80084660: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80084664: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80084668: lw          $a3, 0x90($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X90);
    // 0x8008466C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80084670: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80084674: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80084678: jal         0x800C49A0
    // 0x8008467C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008467C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x80084680: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80084684: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80084688: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008468C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80084690: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80084694: jal         0x800C48E4
    // 0x80084698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80084698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008469C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800846A0: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800846A4: lw          $a3, 0x90($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X90);
    // 0x800846A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800846AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800846B0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800846B4: jal         0x800C49A0
    // 0x800846B8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x800846B8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x800846BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800846C0: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
    // 0x800846C4: jal         0x800C484C
    // 0x800846C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x800846C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800846CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800846D0: lw          $t2, -0x70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X70);
    // 0x800846D4: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800846D8: beq         $t2, $zero, L_8008476C
    if (ctx->r10 == 0) {
        // 0x800846DC: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008476C;
    }
    // 0x800846DC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800846E0: addiu       $t4, $t4, -0x70
    ctx->r12 = ADD32(ctx->r12, -0X70);
    // 0x800846E4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800846E8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800846EC: addiu       $s3, $s3, -0x620
    ctx->r19 = ADD32(ctx->r19, -0X620);
    // 0x800846F0: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x800846F4: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x800846F8: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_800846FC:
    // 0x800846FC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80084700: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80084704: bne         $s1, $t5, L_80084728
    if (ctx->r17 != ctx->r13) {
        // 0x80084708: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80084728;
    }
    // 0x80084708: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008470C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80084710: nop

    // 0x80084714: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80084718: bne         $at, $zero, L_8008472C
    if (ctx->r1 != 0) {
        // 0x8008471C: sll         $a3, $v0, 3
        ctx->r7 = S32(ctx->r2 << 3);
            goto L_8008472C;
    }
    // 0x8008471C: sll         $a3, $v0, 3
    ctx->r7 = S32(ctx->r2 << 3);
    // 0x80084720: b           L_8008472C
    // 0x80084724: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
        goto L_8008472C;
    // 0x80084724: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
L_80084728:
    // 0x80084728: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008472C:
    // 0x8008472C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80084730: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80084734: jal         0x800C48E4
    // 0x80084738: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80084738: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x8008473C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80084740: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80084744: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084748: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008474C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80084750: jal         0x800C49A0
    // 0x80084754: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80084754: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80084758: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008475C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084760: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80084764: bne         $t8, $zero, L_800846FC
    if (ctx->r24 != 0) {
        // 0x80084768: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_800846FC;
    }
    // 0x80084768: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_8008476C:
    // 0x8008476C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80084770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80084774: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80084778: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008477C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80084780: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80084784: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80084788: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008478C: jr          $ra
    // 0x80084790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80084790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void menu_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084794: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084798: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008479C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800847A0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800847A4: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800847A8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800847AC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800847B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800847B4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800847B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800847BC: beq         $v0, $zero, L_800847E4
    if (ctx->r2 == 0) {
        // 0x800847C0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800847E4;
    }
    // 0x800847C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800847C4: blez        $v0, L_800847DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800847C8: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_800847DC;
    }
    // 0x800847C8: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x800847CC: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800847D0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800847D4: b           L_800847E4
    // 0x800847D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800847E4;
    // 0x800847D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800847DC:
    // 0x800847DC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800847E0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800847E4:
    // 0x800847E4: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x800847E8: bne         $at, $zero, L_80084808
    if (ctx->r1 != 0) {
        // 0x800847EC: slti        $at, $v0, 0x23
        ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
            goto L_80084808;
    }
    // 0x800847EC: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x800847F0: beq         $at, $zero, L_80084808
    if (ctx->r1 == 0) {
        // 0x800847F4: nop
    
            goto L_80084808;
    }
    // 0x800847F4: nop

    // 0x800847F8: jal         0x800845F0
    // 0x800847FC: nop

    optionscreen_render(rdram, ctx);
        goto after_0;
    // 0x800847FC: nop

    after_0:
    // 0x80084800: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084804: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084808:
    // 0x80084808: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008480C: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x80084810: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084814: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80084818: bne         $t3, $zero, L_800848A0
    if (ctx->r11 != 0) {
        // 0x8008481C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800848A0;
    }
    // 0x8008481C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80084820: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80084824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084828: bne         $t4, $zero, L_800848A0
    if (ctx->r12 != 0) {
        // 0x8008482C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800848A0;
    }
    // 0x8008482C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084830: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084834: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x80084838: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8008483C:
    // 0x8008483C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80084840: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80084844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80084848: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8008484C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80084850: jal         0x8006A794
    // 0x80084854: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80084854: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80084858: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008485C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80084860: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80084864: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80084868: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8008486C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80084870: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x80084874: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x80084878: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008487C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80084880: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084884: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80084888: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x8008488C: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80084890: bne         $a0, $at, L_8008483C
    if (ctx->r4 != ctx->r1) {
        // 0x80084894: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_8008483C;
    }
    // 0x80084894: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80084898: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008489C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_800848A0:
    // 0x800848A0: andi        $t7, $a2, 0x4000
    ctx->r15 = ctx->r6 & 0X4000;
    // 0x800848A4: bne         $t7, $zero, L_800848C8
    if (ctx->r15 != 0) {
        // 0x800848A8: andi        $v1, $a2, 0x9000
        ctx->r3 = ctx->r6 & 0X9000;
            goto L_800848C8;
    }
    // 0x800848A8: andi        $v1, $a2, 0x9000
    ctx->r3 = ctx->r6 & 0X9000;
    // 0x800848AC: beq         $v1, $zero, L_80084908
    if (ctx->r3 == 0) {
        // 0x800848B0: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80084908;
    }
    // 0x800848B0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800848B4: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x800848B8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800848BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800848C0: bne         $t8, $at, L_80084908
    if (ctx->r24 != ctx->r1) {
        // 0x800848C4: nop
    
            goto L_80084908;
    }
    // 0x800848C4: nop

L_800848C8:
    // 0x800848C8: jal         0x80000C98
    // 0x800848CC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x800848CC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_2:
    // 0x800848D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800848D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800848D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800848DC: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x800848E0: jal         0x800C06F8
    // 0x800848E4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x800848E4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x800848E8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800848EC: jal         0x80001D04
    // 0x800848F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800848F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800848F4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800848F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800848FC: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084900: b           L_80084AB0
    // 0x80084904: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084904: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084908:
    // 0x80084908: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008490C: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084910: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084914: beq         $v1, $zero, L_80084948
    if (ctx->r3 == 0) {
        // 0x80084918: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80084948;
    }
    // 0x80084918: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008491C: bne         $at, $zero, L_80084948
    if (ctx->r1 != 0) {
        // 0x80084920: addiu       $t2, $zero, 0x1F
        ctx->r10 = ADD32(0, 0X1F);
            goto L_80084948;
    }
    // 0x80084920: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80084924: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80084928: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008492C: jal         0x80001D04
    // 0x80084930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80084930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80084934: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084938: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008493C: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084940: b           L_80084AB0
    // 0x80084944: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084944: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084948:
    // 0x80084948: bne         $v0, $zero, L_800849AC
    if (ctx->r2 != 0) {
        // 0x8008494C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800849AC;
    }
    // 0x8008494C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80084950: beq         $a3, $zero, L_800849AC
    if (ctx->r7 == 0) {
        // 0x80084954: nop
    
            goto L_800849AC;
    }
    // 0x80084954: nop

    // 0x80084958: jal         0x8009F064
    // 0x8008495C: nop

    get_language(rdram, ctx);
        goto after_6;
    // 0x8008495C: nop

    after_6:
    // 0x80084960: sra         $t4, $v0, 31
    ctx->r12 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80084964: bne         $t4, $zero, L_80084984
    if (ctx->r12 != 0) {
        // 0x80084968: nop
    
            goto L_80084984;
    }
    // 0x80084968: nop

    // 0x8008496C: bne         $v0, $zero, L_80084984
    if (ctx->r2 != 0) {
        // 0x80084970: nop
    
            goto L_80084984;
    }
    // 0x80084970: nop

    // 0x80084974: jal         0x8009F0D8
    // 0x80084978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_language(rdram, ctx);
        goto after_7;
    // 0x80084978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8008497C: b           L_80084990
    // 0x80084980: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
        goto L_80084990;
    // 0x80084980: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_80084984:
    // 0x80084984: jal         0x8009F0D8
    // 0x80084988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_language(rdram, ctx);
        goto after_8;
    // 0x80084988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8008498C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_80084990:
    // 0x80084990: jal         0x80001D04
    // 0x80084994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x80084994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80084998: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008499C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800849A0: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x800849A4: b           L_80084AB0
    // 0x800849A8: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x800849A8: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_800849AC:
    // 0x800849AC: bne         $v0, $at, L_80084A50
    if (ctx->r2 != ctx->r1) {
        // 0x800849B0: nop
    
            goto L_80084A50;
    }
    // 0x800849B0: nop

    // 0x800849B4: beq         $a3, $zero, L_80084A50
    if (ctx->r7 == 0) {
        // 0x800849B8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80084A50;
    }
    // 0x800849B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800849BC: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x800849C0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800849C4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800849C8: beq         $t9, $zero, L_80084A08
    if (ctx->r25 == 0) {
        // 0x800849CC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80084A08;
    }
    // 0x800849CC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800849D0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800849D4: jal         0x80001D04
    // 0x800849D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800849D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800849DC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800849E0: jal         0x8009F000
    // 0x800849E4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_11;
    // 0x800849E4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_11:
    // 0x800849E8: jal         0x800C3014
    // 0x800849EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_12;
    // 0x800849EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800849F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800849F4: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x800849F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800849FC: lw          $t2, 0x2DC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2DC);
    // 0x80084A00: b           L_80084A3C
    // 0x80084A04: sw          $t2, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r10;
        goto L_80084A3C;
    // 0x80084A04: sw          $t2, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r10;
L_80084A08:
    // 0x80084A08: jal         0x80001D04
    // 0x80084A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x80084A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80084A10: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80084A14: jal         0x8009EFBC
    // 0x80084A18: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    set_eeprom_settings_value(rdram, ctx);
        goto after_14;
    // 0x80084A18: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_14:
    // 0x80084A1C: jal         0x800C3014
    // 0x80084A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_subtitles(rdram, ctx);
        goto after_15;
    // 0x80084A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80084A24: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80084A28: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80084A2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084A30: lw          $t5, 0x2D8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2D8);
    // 0x80084A34: nop

    // 0x80084A38: sw          $t5, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r13;
L_80084A3C:
    // 0x80084A3C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084A40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084A44: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084A48: b           L_80084AB0
    // 0x80084A4C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084A4C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084A50:
    // 0x80084A50: bgez        $t0, L_80084A74
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80084A54: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80084A74;
    }
    // 0x80084A54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80084A58: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80084A5C: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80084A60: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80084A64: bne         $at, $zero, L_80084A74
    if (ctx->r1 != 0) {
        // 0x80084A68: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80084A74;
    }
    // 0x80084A68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80084A6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80084A70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80084A74:
    // 0x80084A74: blez        $t0, L_80084A90
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80084A78: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80084A90;
    }
    // 0x80084A78: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80084A7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80084A80: bgez        $t8, L_80084A90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80084A84: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80084A90;
    }
    // 0x80084A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80084A88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80084A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084A90:
    // 0x80084A90: beq         $v1, $v0, L_80084AB0
    if (ctx->r3 == ctx->r2) {
        // 0x80084A94: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80084AB0;
    }
    // 0x80084A94: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80084A98: jal         0x80001D04
    // 0x80084A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x80084A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80084AA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084AA4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084AA8: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084AAC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084AB0:
    // 0x80084AB0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80084AB4: nop

    // 0x80084AB8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80084ABC: bne         $at, $zero, L_80084B2C
    if (ctx->r1 != 0) {
        // 0x80084AC0: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_80084B2C;
    }
    // 0x80084AC0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x80084AC4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084ACC: bne         $v0, $at, L_80084AF0
    if (ctx->r2 != ctx->r1) {
        // 0x80084AD0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80084AF0;
    }
    // 0x80084AD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80084AD4: jal         0x80084B6C
    // 0x80084AD8: nop

    optionscreen_free(rdram, ctx);
        goto after_17;
    // 0x80084AD8: nop

    after_17:
    // 0x80084ADC: jal         0x80081820
    // 0x80084AE0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x80084AE0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_18:
    // 0x80084AE4: b           L_80084B5C
    // 0x80084AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084AEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80084AF0:
    // 0x80084AF0: bne         $v0, $at, L_80084B10
    if (ctx->r2 != ctx->r1) {
        // 0x80084AF4: nop
    
            goto L_80084B10;
    }
    // 0x80084AF4: nop

    // 0x80084AF8: jal         0x80084B6C
    // 0x80084AFC: nop

    optionscreen_free(rdram, ctx);
        goto after_19;
    // 0x80084AFC: nop

    after_19:
    // 0x80084B00: jal         0x80081820
    // 0x80084B04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x80084B04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_20:
    // 0x80084B08: b           L_80084B5C
    // 0x80084B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084B10:
    // 0x80084B10: jal         0x80084B6C
    // 0x80084B14: nop

    optionscreen_free(rdram, ctx);
        goto after_21;
    // 0x80084B14: nop

    after_21:
    // 0x80084B18: jal         0x80081820
    // 0x80084B1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_22;
    // 0x80084B1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_22:
    // 0x80084B20: b           L_80084B5C
    // 0x80084B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084B28: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_80084B2C:
    // 0x80084B2C: beq         $at, $zero, L_80084B54
    if (ctx->r1 == 0) {
        // 0x80084B30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80084B54;
    }
    // 0x80084B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084B34: jal         0x80000B28
    // 0x80084B38: nop

    music_change_on(rdram, ctx);
        goto after_23;
    // 0x80084B38: nop

    after_23:
    // 0x80084B3C: jal         0x80084B6C
    // 0x80084B40: nop

    optionscreen_free(rdram, ctx);
        goto after_24;
    // 0x80084B40: nop

    after_24:
    // 0x80084B44: jal         0x80081820
    // 0x80084B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_25;
    // 0x80084B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80084B4C: b           L_80084B5C
    // 0x80084B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084B54:
    // 0x80084B54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B58: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80084B5C:
    // 0x80084B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084B60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80084B64: jr          $ra
    // 0x80084B68: nop

    return;
    // 0x80084B68: nop

;}
RECOMP_FUNC void optionscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084B74: jal         0x800C478C
    // 0x80084B78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80084B78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80084B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084B84: jr          $ra
    // 0x80084B88: nop

    return;
    // 0x80084B88: nop

;}
RECOMP_FUNC void menu_audio_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B90: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x80084B94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B98: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80084B9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084BA0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80084BA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084BAC: sw          $zero, 0x6FBC($at)
    MEM_W(0X6FBC, ctx->r1) = 0;
    // 0x80084BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084BB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084BB8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80084BBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BC0: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x80084BC4: jal         0x8009CBB8
    // 0x80084BC8: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x80084BC8: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    after_0:
    // 0x80084BCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BD0: jal         0x8009CDE8
    // 0x80084BD4: addiu       $a0, $a0, -0x48
    ctx->r4 = ADD32(ctx->r4, -0X48);
    menu_imagegroup_load(rdram, ctx);
        goto after_1;
    // 0x80084BD4: addiu       $a0, $a0, -0x48
    ctx->r4 = ADD32(ctx->r4, -0X48);
    after_1:
    // 0x80084BD8: jal         0x8008E968
    // 0x80084BDC: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x80084BDC: nop

    after_2:
    // 0x80084BE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BE4: jal         0x800C06F8
    // 0x80084BE8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80084BE8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_3:
    // 0x80084BEC: jal         0x8008043C
    // 0x80084BF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x80084BF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80084BF4: jal         0x80001AFC
    // 0x80084BF8: nop

    music_volume_config(rdram, ctx);
        goto after_5;
    // 0x80084BF8: nop

    after_5:
    // 0x80084BFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084C00: jal         0x8000317C
    // 0x80084C04: sw          $v0, 0x44($at)
    MEM_W(0X44, ctx->r1) = ctx->r2;
    sndp_get_global_volume(rdram, ctx);
        goto after_6;
    // 0x80084C04: sw          $v0, 0x44($at)
    MEM_W(0X44, ctx->r1) = ctx->r2;
    after_6:
    // 0x80084C08: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084C0C: lw          $t7, 0x318($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X318);
    // 0x80084C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084C14: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80084C18: beq         $t8, $zero, L_80084C54
    if (ctx->r24 == 0) {
        // 0x80084C1C: sw          $v0, 0x40($at)
        MEM_W(0X40, ctx->r1) = ctx->r2;
            goto L_80084C54;
    }
    // 0x80084C1C: sw          $v0, 0x40($at)
    MEM_W(0X40, ctx->r1) = ctx->r2;
    // 0x80084C20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084C24: lw          $t9, 0x6FA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FA0);
    // 0x80084C28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084C2C: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x80084C30: addiu       $t0, $zero, 0xD4
    ctx->r8 = ADD32(0, 0XD4);
    // 0x80084C34: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x80084C38: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80084C3C: jal         0x80000BE0
    // 0x80084C40: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    music_voicelimit_set(rdram, ctx);
        goto after_7;
    // 0x80084C40: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    after_7:
    // 0x80084C44: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80084C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084C4C: b           L_80084C74
    // 0x80084C50: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
        goto L_80084C74;
    // 0x80084C50: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_80084C54:
    // 0x80084C54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084C58: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x80084C5C: addiu       $t2, $zero, 0xC0
    ctx->r10 = ADD32(0, 0XC0);
    // 0x80084C60: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80084C64: sh          $t2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r10;
    // 0x80084C68: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80084C6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084C70: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
L_80084C74:
    // 0x80084C74: jal         0x800C46D0
    // 0x80084C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x80084C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80084C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084C84: jr          $ra
    // 0x80084C88: nop

    return;
    // 0x80084C88: nop

;}
RECOMP_FUNC void func_80084854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80084C90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084C94: addiu       $a1, $a1, 0x6FA0
    ctx->r5 = ADD32(ctx->r5, 0X6FA0);
    // 0x80084C98: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80084C9C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80084CA0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80084CA4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80084CA8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80084CAC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80084CB0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80084CB4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80084CB8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80084CBC: lw          $s3, 0x3C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X3C);
    // 0x80084CC0: slti        $at, $t6, 0x30
    ctx->r1 = SIGNED(ctx->r14) < 0X30 ? 1 : 0;
    // 0x80084CC4: bne         $at, $zero, L_80084CE0
    if (ctx->r1 != 0) {
        // 0x80084CC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80084CE0;
    }
    // 0x80084CC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80084CCC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80084CD0: nop

    // 0x80084CD4: slti        $at, $t7, 0x3A
    ctx->r1 = SIGNED(ctx->r15) < 0X3A ? 1 : 0;
    // 0x80084CD8: bne         $at, $zero, L_80084D0C
    if (ctx->r1 != 0) {
        // 0x80084CDC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80084D0C;
    }
    // 0x80084CDC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80084CE0:
    // 0x80084CE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084CE4: addu        $t8, $v1, $s1
    ctx->r24 = ADD32(ctx->r3, ctx->r17);
    // 0x80084CE8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x80084CEC: nop

    // 0x80084CF0: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80084CF4: bne         $at, $zero, L_80084CE0
    if (ctx->r1 != 0) {
        // 0x80084CF8: nop
    
            goto L_80084CE0;
    }
    // 0x80084CF8: nop

    // 0x80084CFC: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80084D00: beq         $at, $zero, L_80084CE0
    if (ctx->r1 == 0) {
        // 0x80084D04: nop
    
            goto L_80084CE0;
    }
    // 0x80084D04: nop

    // 0x80084D08: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80084D0C:
    // 0x80084D0C: div         $zero, $s3, $a0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r4)));
    // 0x80084D10: addu        $t0, $v1, $s1
    ctx->r8 = ADD32(ctx->r3, ctx->r17);
    // 0x80084D14: bne         $a0, $zero, L_80084D20
    if (ctx->r4 != 0) {
        // 0x80084D18: nop
    
            goto L_80084D20;
    }
    // 0x80084D18: nop

    // 0x80084D1C: break       7
    do_break(2148027676);
L_80084D20:
    // 0x80084D20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80084D24: bne         $a0, $at, L_80084D38
    if (ctx->r4 != ctx->r1) {
        // 0x80084D28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80084D38;
    }
    // 0x80084D28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80084D2C: bne         $s3, $at, L_80084D38
    if (ctx->r19 != ctx->r1) {
        // 0x80084D30: nop
    
            goto L_80084D38;
    }
    // 0x80084D30: nop

    // 0x80084D34: break       6
    do_break(2148027700);
L_80084D38:
    // 0x80084D38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084D3C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80084D40: addiu       $s2, $s2, 0x693C
    ctx->r18 = ADD32(ctx->r18, 0X693C);
    // 0x80084D44: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084D48: mflo        $v0
    ctx->r2 = lo;
    // 0x80084D4C: addiu       $t9, $v0, 0x30
    ctx->r25 = ADD32(ctx->r2, 0X30);
    // 0x80084D50: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x80084D54: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084D58: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80084D5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084D60: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80084D64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084D68: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80084D6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084D70: mflo        $t1
    ctx->r9 = lo;
    // 0x80084D74: subu        $s3, $s3, $t1
    ctx->r19 = SUB32(ctx->r19, ctx->r9);
    // 0x80084D78: addiu       $t2, $s3, 0x30
    ctx->r10 = ADD32(ctx->r19, 0X30);
    // 0x80084D7C: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
    // 0x80084D80: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80084D84: lw          $s3, 0x695C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X695C);
    // 0x80084D88: nop

    // 0x80084D8C: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x80084D90: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x80084D94: bne         $at, $zero, L_80084DA4
    if (ctx->r1 != 0) {
        // 0x80084D98: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80084DA4;
    }
    // 0x80084D98: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80084D9C: addiu       $t6, $zero, 0x1FF
    ctx->r14 = ADD32(0, 0X1FF);
    // 0x80084DA0: subu        $s3, $t6, $t5
    ctx->r19 = SUB32(ctx->r14, ctx->r13);
L_80084DA4:
    // 0x80084DA4: lw          $t7, 0x48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X48);
    // 0x80084DA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084DAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80084DB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80084DB4: lw          $t9, 0x6F90($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F90);
    // 0x80084DB8: jal         0x8006816C
    // 0x80084DBC: sw          $t9, -0x38($at)
    MEM_W(-0X38, ctx->r1) = ctx->r25;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80084DBC: sw          $t9, -0x38($at)
    MEM_W(-0X38, ctx->r1) = ctx->r25;
    after_0:
    // 0x80084DC0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80084DC4: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x80084DC8: lui         $s1, 0xFFC0
    ctx->r17 = S32(0XFFC0 << 16);
    // 0x80084DCC: bne         $t0, $zero, L_80084DDC
    if (ctx->r8 != 0) {
        // 0x80084DD0: ori         $s1, $s1, 0x40FF
        ctx->r17 = ctx->r17 | 0X40FF;
            goto L_80084DDC;
    }
    // 0x80084DD0: ori         $s1, $s1, 0x40FF
    ctx->r17 = ctx->r17 | 0X40FF;
    // 0x80084DD4: b           L_80084DE0
    // 0x80084DD8: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
        goto L_80084DE0;
    // 0x80084DD8: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
L_80084DDC:
    // 0x80084DDC: addiu       $s0, $zero, 0x71
    ctx->r16 = ADD32(0, 0X71);
L_80084DE0:
    // 0x80084DE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80084DE4: lw          $t5, 0x6C00($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C00);
    // 0x80084DE8: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80084DEC: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80084DF0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80084DF4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80084DF8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80084DFC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80084E00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80084E04: subu        $a2, $t1, $s0
    ctx->r6 = SUB32(ctx->r9, ctx->r16);
    // 0x80084E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084E0C: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x80084E10: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80084E14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084E18: jal         0x800809D0
    // 0x80084E1C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_80080580(rdram, ctx);
        goto after_1;
    // 0x80084E1C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_1:
    // 0x80084E20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80084E24: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80084E28: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80084E2C: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80084E30: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80084E34: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80084E38: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80084E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80084E40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084E44: subu        $a2, $t6, $s0
    ctx->r6 = SUB32(ctx->r14, ctx->r16);
    // 0x80084E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084E4C: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x80084E50: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80084E54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084E58: jal         0x800809D0
    // 0x80084E5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x80084E5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x80084E60: jal         0x80081018
    // 0x80084E64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x80084E64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80084E68: jal         0x800C59F4
    // 0x80084E6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_4;
    // 0x80084E6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x80084E70: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084E74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084E78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084E80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084E84: jal         0x800C551C
    // 0x80084E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80084E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80084E8C: addiu       $t3, $zero, 0x7B
    ctx->r11 = ADD32(0, 0X7B);
    // 0x80084E90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80084E94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084E98: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084E9C: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    // 0x80084EA0: jal         0x800C543C
    // 0x80084EA4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_6;
    // 0x80084EA4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_6:
    // 0x80084EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084EB4: jal         0x800C60B8
    // 0x80084EB8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_7;
    // 0x80084EB8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_7:
    // 0x80084EBC: addiu       $t2, $zero, 0xA3
    ctx->r10 = ADD32(0, 0XA3);
    // 0x80084EC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80084EC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084EC8: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084ECC: addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    // 0x80084ED0: jal         0x800C543C
    // 0x80084ED4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80084ED4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_8:
    // 0x80084ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084EE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084EE4: jal         0x800C60B8
    // 0x80084EE8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x80084EE8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_9:
    // 0x80084EEC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084EF0: lw          $a2, 0x40($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X40);
    // 0x80084EF4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80084EF8: addiu       $s0, $s0, 0x9AC
    ctx->r16 = ADD32(ctx->r16, 0X9AC);
    // 0x80084EFC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80084F00: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80084F04: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80084F08: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80084F0C: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084F10: addiu       $a2, $t4, 0x60
    ctx->r6 = ADD32(ctx->r12, 0X60);
    // 0x80084F14: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80084F18: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80084F1C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80084F20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80084F24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084F2C: jal         0x80078F08
    // 0x80084F30: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    texrect_draw(rdram, ctx);
        goto after_10;
    // 0x80084F30: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_10:
    // 0x80084F34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084F38: lw          $a2, 0x44($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X44);
    // 0x80084F3C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80084F40: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084F44: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80084F48: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80084F4C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084F50: addiu       $a2, $t9, 0x60
    ctx->r6 = ADD32(ctx->r25, 0X60);
    // 0x80084F54: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80084F58: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80084F5C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80084F60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80084F64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084F68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084F6C: jal         0x80078F08
    // 0x80084F70: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80084F70: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_11:
    // 0x80084F74: jal         0x8007B820
    // 0x80084F78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x80084F78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80084F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084F88: jal         0x800C492C
    // 0x80084F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80084F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80084F90: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80084F94: lw          $t4, 0x6980($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6980);
    // 0x80084F98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80084F9C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80084FA0: beq         $at, $zero, L_80084FB8
    if (ctx->r1 == 0) {
        // 0x80084FA4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80084FB8;
    }
    // 0x80084FA4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084FA8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80084FAC: lh          $s1, 0x7206($s1)
    ctx->r17 = MEM_H(ctx->r17, 0X7206);
    // 0x80084FB0: b           L_80084FEC
    // 0x80084FB4: nop

        goto L_80084FEC;
    // 0x80084FB4: nop

L_80084FB8:
    // 0x80084FB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084FBC: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80084FC0: nop

    // 0x80084FC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80084FC8: beq         $at, $zero, L_80084FDC
    if (ctx->r1 == 0) {
        // 0x80084FCC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80084FDC;
    }
    // 0x80084FCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80084FD0: b           L_80084FEC
    // 0x80084FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80084FEC;
    // 0x80084FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80084FD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80084FDC:
    // 0x80084FDC: bne         $v0, $at, L_80084FEC
    if (ctx->r2 != ctx->r1) {
        // 0x80084FE0: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80084FEC;
    }
    // 0x80084FE0: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80084FE4: b           L_80084FEC
    // 0x80084FE8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_80084FEC;
    // 0x80084FE8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_80084FEC:
    // 0x80084FEC: lw          $t5, -0x38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38);
    // 0x80084FF0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80084FF4: beq         $t5, $zero, L_80085090
    if (ctx->r13 == 0) {
        // 0x80084FF8: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80085090;
    }
    // 0x80084FF8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084FFC: addiu       $t7, $t7, -0x44
    ctx->r15 = ADD32(ctx->r15, -0X44);
    // 0x80085000: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x80085004: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80085008: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8008500C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
L_80085010:
    // 0x80085010: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x80085014: jal         0x800C484C
    // 0x80085018: nop

    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80085018: nop

    after_14:
    // 0x8008501C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80085020: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085024: bne         $s0, $t0, L_80085048
    if (ctx->r16 != ctx->r8) {
        // 0x80085028: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80085048;
    }
    // 0x80085028: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008502C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80085030: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80085034: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085038: jal         0x800C48E4
    // 0x8008503C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x8008503C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_15:
    // 0x80085040: b           L_80085068
    // 0x80085044: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
        goto L_80085068;
    // 0x80085044: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80085048:
    // 0x80085048: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x8008504C: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    // 0x80085050: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80085054: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    // 0x80085058: lbu         $a3, 0x7($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X7);
    // 0x8008505C: jal         0x800C48E4
    // 0x80085060: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x80085060: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_16:
    // 0x80085064: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80085068:
    // 0x80085068: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008506C: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80085070: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80085074: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80085078: jal         0x800C49A0
    // 0x8008507C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    draw_text(rdram, ctx);
        goto after_17;
    // 0x8008507C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_17:
    // 0x80085080: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x80085084: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80085088: bne         $t4, $zero, L_80085010
    if (ctx->r12 != 0) {
        // 0x8008508C: nop
    
            goto L_80085010;
    }
    // 0x8008508C: nop

L_80085090:
    // 0x80085090: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80085094: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80085098: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8008509C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800850A0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800850A4: jr          $ra
    // 0x800850A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800850A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void menu_audio_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800850B0: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x800850B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800850B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800850BC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800850C0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800850C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800850C8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800850CC: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800850D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800850D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800850D8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800850DC: beq         $v0, $zero, L_80085104
    if (ctx->r2 == 0) {
        // 0x800850E0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80085104;
    }
    // 0x800850E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800850E4: blez        $v0, L_800850FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800850E8: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_800850FC;
    }
    // 0x800850E8: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x800850EC: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800850F0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800850F4: b           L_80085104
    // 0x800850F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80085104;
    // 0x800850F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800850FC:
    // 0x800850FC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80085100: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80085104:
    // 0x80085104: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80085108: bne         $at, $zero, L_80085128
    if (ctx->r1 != 0) {
        // 0x8008510C: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80085128;
    }
    // 0x8008510C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80085110: beq         $at, $zero, L_80085128
    if (ctx->r1 == 0) {
        // 0x80085114: nop
    
            goto L_80085128;
    }
    // 0x80085114: nop

    // 0x80085118: jal         0x80084C8C
    // 0x8008511C: nop

    func_80084854(rdram, ctx);
        goto after_0;
    // 0x8008511C: nop

    after_0:
    // 0x80085120: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085124: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80085128:
    // 0x80085128: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008512C: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x80085130: nop

    // 0x80085134: bne         $t3, $zero, L_800855E8
    if (ctx->r11 != 0) {
        // 0x80085138: nop
    
            goto L_800855E8;
    }
    // 0x80085138: nop

    // 0x8008513C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80085140: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80085144: bne         $t4, $zero, L_800855E8
    if (ctx->r12 != 0) {
        // 0x80085148: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800855E8;
    }
    // 0x80085148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008514C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80085150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085154: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80085158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008515C: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x80085160: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x80085164: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80085168:
    // 0x80085168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008516C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80085170: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80085174: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80085178: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8008517C: jal         0x8006A794
    // 0x80085180: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80085180: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80085184: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80085188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008518C: or          $t6, $t5, $v0
    ctx->r14 = ctx->r13 | ctx->r2;
    // 0x80085190: jal         0x8006A7DC
    // 0x80085194: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    input_clamp_stick_x(rdram, ctx);
        goto after_2;
    // 0x80085194: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_2:
    // 0x80085198: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008519C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800851A0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800851A4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800851A8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800851AC: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x800851B0: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x800851B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800851B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800851BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800851C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800851C4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800851C8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800851CC: bne         $s0, $at, L_80085168
    if (ctx->r16 != ctx->r1) {
        // 0x800851D0: addu        $a3, $a3, $t8
        ctx->r7 = ADD32(ctx->r7, ctx->r24);
            goto L_80085168;
    }
    // 0x800851D0: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800851D4: bgez        $a2, L_800851F0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800851D8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800851F0;
    }
    // 0x800851D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800851DC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800851E0: blez        $a2, L_80085204
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800851E4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80085204;
    }
    // 0x800851E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800851E8: b           L_80085200
    // 0x800851EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80085200;
    // 0x800851EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800851F0:
    // 0x800851F0: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    // 0x800851F4: bgez        $a2, L_80085204
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800851F8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80085204;
    }
    // 0x800851F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800851FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80085200:
    // 0x80085200: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80085204:
    // 0x80085204: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80085208: andi        $t2, $a0, 0x9000
    ctx->r10 = ctx->r4 & 0X9000;
    // 0x8008520C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80085210: beq         $t2, $zero, L_80085234
    if (ctx->r10 == 0) {
        // 0x80085214: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80085234;
    }
    // 0x80085214: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80085218: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008521C: lh          $t4, 0x7206($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7206);
    // 0x80085220: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x80085224: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80085228: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008522C: beq         $t3, $t5, L_8008524C
    if (ctx->r11 == ctx->r13) {
        // 0x80085230: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8008524C;
    }
    // 0x80085230: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80085234:
    // 0x80085234: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80085238: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008523C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80085240: beq         $t7, $zero, L_80085288
    if (ctx->r15 == 0) {
        // 0x80085244: addiu       $v1, $v1, 0x6980
        ctx->r3 = ADD32(ctx->r3, 0X6980);
            goto L_80085288;
    }
    // 0x80085244: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x80085248: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8008524C:
    // 0x8008524C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085250: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085254: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    // 0x80085258: jal         0x800C06F8
    // 0x8008525C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008525C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x80085260: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085264: lw          $t9, 0x6978($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6978);
    // 0x80085268: nop

    // 0x8008526C: bltz        $t9, L_80085280
    if (SIGNED(ctx->r25) < 0) {
        // 0x80085270: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80085280;
    }
    // 0x80085270: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80085274: jal         0x80000C98
    // 0x80085278: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x80085278: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x8008527C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80085280:
    // 0x80085280: b           L_80085538
    // 0x80085284: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80085538;
    // 0x80085284: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80085288:
    // 0x80085288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008528C: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80085290: bgez        $a3, L_800852C0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80085294: nop
    
            goto L_800852C0;
    }
    // 0x80085294: nop

    // 0x80085298: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008529C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800852A0: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x800852A4: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800852A8: beq         $at, $zero, L_800852C0
    if (ctx->r1 == 0) {
        // 0x800852AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800852C0;
    }
    // 0x800852AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800852B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852B4: sh          $t5, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = ctx->r13;
    // 0x800852B8: b           L_80085538
    // 0x800852BC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085538;
    // 0x800852BC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_800852C0:
    // 0x800852C0: blez        $a3, L_800852E4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800852C4: nop
    
            goto L_800852E4;
    }
    // 0x800852C4: nop

    // 0x800852C8: blez        $v0, L_800852E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800852CC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800852E4;
    }
    // 0x800852CC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800852D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800852D8: sh          $t7, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = ctx->r15;
    // 0x800852DC: b           L_80085538
    // 0x800852E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80085538;
    // 0x800852E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800852E4:
    // 0x800852E4: bne         $v0, $zero, L_8008536C
    if (ctx->r2 != 0) {
        // 0x800852E8: nop
    
            goto L_8008536C;
    }
    // 0x800852E8: nop

    // 0x800852EC: beq         $t0, $zero, L_8008536C
    if (ctx->r8 == 0) {
        // 0x800852F0: nop
    
            goto L_8008536C;
    }
    // 0x800852F0: nop

    // 0x800852F4: bgez        $t0, L_80085318
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800852F8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80085318;
    }
    // 0x800852F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800852FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085300: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80085304: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80085308: nop

    // 0x8008530C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80085310: b           L_8008532C
    // 0x80085314: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_8008532C;
    // 0x80085314: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80085318:
    // 0x80085318: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x8008531C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80085320: nop

    // 0x80085324: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80085328: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8008532C:
    // 0x8008532C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80085330: nop

    // 0x80085334: bgez        $a0, L_80085348
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80085338: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80085348;
    }
    // 0x80085338: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8008533C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085340: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80085344: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80085348:
    // 0x80085348: bne         $at, $zero, L_80085358
    if (ctx->r1 != 0) {
        // 0x8008534C: nop
    
            goto L_80085358;
    }
    // 0x8008534C: nop

    // 0x80085350: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80085354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80085358:
    // 0x80085358: jal         0x80065E10
    // 0x8008535C: nop

    set_stereo_pan_mode(rdram, ctx);
        goto after_5;
    // 0x8008535C: nop

    after_5:
    // 0x80085360: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80085364: b           L_80085538
    // 0x80085368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085538;
    // 0x80085368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_8008536C:
    // 0x8008536C: beq         $a2, $zero, L_8008548C
    if (ctx->r6 == 0) {
        // 0x80085370: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008548C;
    }
    // 0x80085370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085374: beq         $v0, $at, L_80085380
    if (ctx->r2 == ctx->r1) {
        // 0x80085378: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80085380;
    }
    // 0x80085378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008537C: bne         $v0, $at, L_8008548C
    if (ctx->r2 != ctx->r1) {
        // 0x80085380: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008548C;
    }
L_80085380:
    // 0x80085380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085384: bne         $v0, $at, L_800853D4
    if (ctx->r2 != ctx->r1) {
        // 0x80085388: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800853D4;
    }
    // 0x80085388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008538C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80085390: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80085394: nop

    // 0x80085398: addu        $v0, $t7, $a2
    ctx->r2 = ADD32(ctx->r15, ctx->r6);
    // 0x8008539C: bgez        $v0, L_800853B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800853A0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800853B0;
    }
    // 0x800853A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800853A4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800853A8: b           L_800853C4
    // 0x800853AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800853C4;
    // 0x800853AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800853B0:
    // 0x800853B0: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800853B4: bne         $at, $zero, L_800853C4
    if (ctx->r1 != 0) {
        // 0x800853B8: nop
    
            goto L_800853C4;
    }
    // 0x800853B8: nop

    // 0x800853BC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800853C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800853C4:
    // 0x800853C4: jal         0x80003160
    // 0x800853C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_set_global_volume(rdram, ctx);
        goto after_6;
    // 0x800853C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800853CC: b           L_80085538
    // 0x800853D0: nop

        goto L_80085538;
    // 0x800853D0: nop

L_800853D4:
    // 0x800853D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800853D8: bne         $v0, $at, L_80085538
    if (ctx->r2 != ctx->r1) {
        // 0x800853DC: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80085538;
    }
    // 0x800853DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800853E0: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // 0x800853E4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800853E8: nop

    // 0x800853EC: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x800853F0: bgez        $v0, L_80085404
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800853F4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80085404;
    }
    // 0x800853F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800853F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800853FC: b           L_80085418
    // 0x80085400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085418;
    // 0x80085400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80085404:
    // 0x80085404: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80085408: bne         $at, $zero, L_80085418
    if (ctx->r1 != 0) {
        // 0x8008540C: nop
    
            goto L_80085418;
    }
    // 0x8008540C: nop

    // 0x80085410: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80085414: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80085418:
    // 0x80085418: jal         0x80001A3C
    // 0x8008541C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    music_volume_config_set(rdram, ctx);
        goto after_7;
    // 0x8008541C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80085420: jal         0x800015C8
    // 0x80085424: nop

    music_is_playing(rdram, ctx);
        goto after_8;
    // 0x80085424: nop

    after_8:
    // 0x80085428: bne         $v0, $zero, L_80085538
    if (ctx->r2 != 0) {
        // 0x8008542C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80085538;
    }
    // 0x8008542C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80085430: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x80085434: nop

    // 0x80085438: bltz        $t5, L_80085464
    if (SIGNED(ctx->r13) < 0) {
        // 0x8008543C: nop
    
            goto L_80085464;
    }
    // 0x8008543C: nop

    // 0x80085440: jal         0x80000B28
    // 0x80085444: nop

    music_change_on(rdram, ctx);
        goto after_9;
    // 0x80085444: nop

    after_9:
    // 0x80085448: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008544C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80085450: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x80085454: jal         0x80000B34
    // 0x80085458: nop

    music_play(rdram, ctx);
        goto after_10;
    // 0x80085458: nop

    after_10:
    // 0x8008545C: b           L_80085538
    // 0x80085460: nop

        goto L_80085538;
    // 0x80085460: nop

L_80085464:
    // 0x80085464: jal         0x80000B28
    // 0x80085468: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x80085468: nop

    after_11:
    // 0x8008546C: jal         0x80000BE0
    // 0x80085470: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x80085470: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x80085474: jal         0x80000B34
    // 0x80085478: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_13;
    // 0x80085478: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_13:
    // 0x8008547C: jal         0x80000B18
    // 0x80085480: nop

    music_change_off(rdram, ctx);
        goto after_14;
    // 0x80085480: nop

    after_14:
    // 0x80085484: b           L_80085538
    // 0x80085488: nop

        goto L_80085538;
    // 0x80085488: nop

L_8008548C:
    // 0x8008548C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80085490: nop

    // 0x80085494: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80085498: bne         $at, $zero, L_80085538
    if (ctx->r1 != 0) {
        // 0x8008549C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80085538;
    }
    // 0x8008549C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800854A0: bne         $v0, $at, L_80085538
    if (ctx->r2 != ctx->r1) {
        // 0x800854A4: nop
    
            goto L_80085538;
    }
    // 0x800854A4: nop

    // 0x800854A8: bgez        $t0, L_800854D0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800854AC: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_800854D0;
    }
    // 0x800854AC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800854B0: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800854B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800854B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800854BC: blez        $v1, L_800854D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800854C0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800854D0;
    }
    // 0x800854C0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800854C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800854C8: b           L_80085508
    // 0x800854CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80085508;
    // 0x800854CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800854D0:
    // 0x800854D0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800854D4: blez        $t0, L_80085508
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800854D8: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80085508;
    }
    // 0x800854D8: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800854DC: jal         0x80002110
    // 0x800854E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    music_sequence_count(rdram, ctx);
        goto after_15;
    // 0x800854E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_15:
    // 0x800854E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800854E8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800854EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800854F0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800854F4: beq         $at, $zero, L_80085508
    if (ctx->r1 == 0) {
        // 0x800854F8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80085508;
    }
    // 0x800854F8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800854FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80085500: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80085504: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
L_80085508:
    // 0x80085508: beq         $a0, $zero, L_80085538
    if (ctx->r4 == 0) {
        // 0x8008550C: nop
    
            goto L_80085538;
    }
    // 0x8008550C: nop

    // 0x80085510: jal         0x80000B28
    // 0x80085514: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x80085514: nop

    after_16:
    // 0x80085518: jal         0x80000BE0
    // 0x8008551C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_17;
    // 0x8008551C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_17:
    // 0x80085520: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x80085524: jal         0x80000B34
    // 0x80085528: nop

    music_play(rdram, ctx);
        goto after_18;
    // 0x80085528: nop

    after_18:
    // 0x8008552C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80085530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085534: sw          $t3, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r11;
L_80085538:
    // 0x80085538: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008553C: lh          $t5, 0x7206($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7206);
    // 0x80085540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085544: bne         $t5, $at, L_80085574
    if (ctx->r13 != ctx->r1) {
        // 0x80085548: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80085574;
    }
    // 0x80085548: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008554C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085550: addiu       $a1, $a1, 0x6FBC
    ctx->r5 = ADD32(ctx->r5, 0X6FBC);
    // 0x80085554: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80085558: nop

    // 0x8008555C: bne         $t6, $zero, L_80085594
    if (ctx->r14 != 0) {
        // 0x80085560: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80085594;
    }
    // 0x80085560: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085564: jal         0x80001D04
    // 0x80085568: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    sound_play(rdram, ctx);
        goto after_19;
    // 0x80085568: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    after_19:
    // 0x8008556C: b           L_80085594
    // 0x80085570: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_80085594;
    // 0x80085570: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80085574:
    // 0x80085574: addiu       $a1, $a1, 0x6FBC
    ctx->r5 = ADD32(ctx->r5, 0X6FBC);
    // 0x80085578: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008557C: nop

    // 0x80085580: beq         $a0, $zero, L_80085594
    if (ctx->r4 == 0) {
        // 0x80085584: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80085594;
    }
    // 0x80085584: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085588: jal         0x8000488C
    // 0x8008558C: nop

    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x8008558C: nop

    after_20:
    // 0x80085590: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80085594:
    // 0x80085594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085598: bne         $t7, $at, L_800855B0
    if (ctx->r15 != ctx->r1) {
        // 0x8008559C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800855B0;
    }
    // 0x8008559C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800855A0: jal         0x80001D04
    // 0x800855A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x800855A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x800855A8: b           L_800855E8
    // 0x800855AC: nop

        goto L_800855E8;
    // 0x800855AC: nop

L_800855B0:
    // 0x800855B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800855B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800855B8: bne         $t8, $at, L_800855D0
    if (ctx->r24 != ctx->r1) {
        // 0x800855BC: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800855D0;
    }
    // 0x800855BC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800855C0: jal         0x80001D04
    // 0x800855C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x800855C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x800855C8: b           L_800855E8
    // 0x800855CC: nop

        goto L_800855E8;
    // 0x800855CC: nop

L_800855D0:
    // 0x800855D0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800855D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800855D8: bne         $t9, $at, L_800855E8
    if (ctx->r25 != ctx->r1) {
        // 0x800855DC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800855E8;
    }
    // 0x800855DC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800855E0: jal         0x80001D04
    // 0x800855E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x800855E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_800855E8:
    // 0x800855E8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800855EC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800855F0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800855F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800855F8: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x800855FC: beq         $at, $zero, L_8008561C
    if (ctx->r1 == 0) {
        // 0x80085600: nop
    
            goto L_8008561C;
    }
    // 0x80085600: nop

    // 0x80085604: jal         0x80085634
    // 0x80085608: nop

    soundoptions_free(rdram, ctx);
        goto after_24;
    // 0x80085608: nop

    after_24:
    // 0x8008560C: jal         0x80081820
    // 0x80085610: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_25;
    // 0x80085610: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_25:
    // 0x80085614: b           L_80085624
    // 0x80085618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085624;
    // 0x80085618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008561C:
    // 0x8008561C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085620: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80085624:
    // 0x80085624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085628: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008562C: jr          $ra
    // 0x80085630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80085630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void soundoptions_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085634: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085638: lw          $a0, 0x6FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FBC);
    // 0x8008563C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085640: beq         $a0, $zero, L_80085650
    if (ctx->r4 == 0) {
        // 0x80085644: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80085650;
    }
    // 0x80085644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085648: jal         0x8000488C
    // 0x8008564C: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8008564C: nop

    after_0:
L_80085650:
    // 0x80085650: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80085654: lw          $t6, 0x6978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6978);
    // 0x80085658: nop

    // 0x8008565C: bltz        $t6, L_80085684
    if (SIGNED(ctx->r14) < 0) {
        // 0x80085660: nop
    
            goto L_80085684;
    }
    // 0x80085660: nop

    // 0x80085664: jal         0x80000BE0
    // 0x80085668: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80085668: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x8008566C: jal         0x80000B34
    // 0x80085670: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_2;
    // 0x80085670: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x80085674: jal         0x80000C98
    // 0x80085678: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80085678: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x8008567C: jal         0x80000B18
    // 0x80085680: nop

    music_change_off(rdram, ctx);
        goto after_4;
    // 0x80085680: nop

    after_4:
L_80085684:
    // 0x80085684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085688: jal         0x8009C9EC
    // 0x8008568C: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    menu_assetgroup_free(rdram, ctx);
        goto after_5;
    // 0x8008568C: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    after_5:
    // 0x80085690: jal         0x800C478C
    // 0x80085694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_6;
    // 0x80085694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x80085698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008569C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800856A0: jr          $ra
    // 0x800856A4: nop

    return;
    // 0x800856A4: nop

;}
RECOMP_FUNC void menu_save_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800856AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856B0: sw          $v0, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = ctx->r2;
    // 0x800856B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856B8: sw          $zero, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = 0;
    // 0x800856BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856C0: sw          $v0, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r2;
    // 0x800856C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856C8: sw          $v0, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r2;
    // 0x800856CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856D0: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x800856D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856D8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x800856DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800856E0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800856E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800856EC: sw          $v0, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r2;
    // 0x800856F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800856F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856F8: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x800856FC: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x80085700: jal         0x80070EDC
    // 0x80085704: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80085704: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80085708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008570C: sw          $v0, 0x7024($at)
    MEM_W(0X7024, ctx->r1) = ctx->r2;
    // 0x80085710: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    // 0x80085714: jal         0x80070EDC
    // 0x80085718: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80085718: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x8008571C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80085720: addiu       $v1, $v1, 0x6FCC
    ctx->r3 = ADD32(ctx->r3, 0X6FCC);
    // 0x80085724: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80085728: addiu       $t7, $v0, 0x500
    ctx->r15 = ADD32(ctx->r2, 0X500);
    // 0x8008572C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085730: sw          $t7, 0x6FC4($at)
    MEM_W(0X6FC4, ctx->r1) = ctx->r15;
    // 0x80085734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085738: sw          $zero, 0x6FC8($at)
    MEM_W(0X6FC8, ctx->r1) = 0;
    // 0x8008573C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80085744: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x80085748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008574C: swc1        $f0, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f0.u32l;
    // 0x80085750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085754: sw          $zero, 0x6FC0($at)
    MEM_W(0X6FC0, ctx->r1) = 0;
    // 0x80085758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008575C: sw          $zero, 0x71A4($at)
    MEM_W(0X71A4, ctx->r1) = 0;
    // 0x80085760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085768: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    // 0x8008576C: jal         0x8009CBB8
    // 0x80085770: swc1        $f0, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f0.u32l;
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80085770: swc1        $f0, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f0.u32l;
    after_2:
    // 0x80085774: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085778: jal         0x8009CDE8
    // 0x8008577C: addiu       $a0, $a0, 0x22C
    ctx->r4 = ADD32(ctx->r4, 0X22C);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8008577C: addiu       $a0, $a0, 0x22C
    ctx->r4 = ADD32(ctx->r4, 0X22C);
    after_3:
    // 0x80085780: jal         0x8008043C
    // 0x80085784: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x80085784: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x80085788: jal         0x800C46D0
    // 0x8008578C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x8008578C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80085790: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80085794: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x80085798: lw          $t8, 0x11C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X11C);
    // 0x8008579C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857A0: sw          $t8, 0x190($at)
    MEM_W(0X190, ctx->r1) = ctx->r24;
    // 0x800857A4: lw          $t9, 0x120($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X120);
    // 0x800857A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857AC: sw          $t9, 0x1A0($at)
    MEM_W(0X1A0, ctx->r1) = ctx->r25;
    // 0x800857B0: lw          $t0, 0x12C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X12C);
    // 0x800857B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857B8: sw          $t0, 0x1B0($at)
    MEM_W(0X1B0, ctx->r1) = ctx->r8;
    // 0x800857BC: lw          $t1, 0x128($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X128);
    // 0x800857C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857C4: sw          $t1, 0x1C0($at)
    MEM_W(0X1C0, ctx->r1) = ctx->r9;
    // 0x800857C8: lw          $t2, 0x124($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X124);
    // 0x800857CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857D0: sw          $t2, 0x1D0($at)
    MEM_W(0X1D0, ctx->r1) = ctx->r10;
    // 0x800857D4: lw          $t3, 0x118($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X118);
    // 0x800857D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857DC: jal         0x8008E968
    // 0x800857E0: sw          $t3, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = ctx->r11;
    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x800857E0: sw          $t3, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = ctx->r11;
    after_6:
    // 0x800857E4: jal         0x8006EDE8
    // 0x800857E8: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_7;
    // 0x800857E8: nop

    after_7:
    // 0x800857EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800857F0: jal         0x800C06F8
    // 0x800857F4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x800857F4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_8:
    // 0x800857F8: jal         0x800724D8
    // 0x800857FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_enable(rdram, ctx);
        goto after_9;
    // 0x800857FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80085800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085808: jr          $ra
    // 0x8008580C: nop

    return;
    // 0x8008580C: nop

;}
RECOMP_FUNC void savemenu_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085810: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80085814: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80085818: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008581C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80085820: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80085824: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80085828: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8008582C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80085830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80085834: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80085838: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x8008583C: beq         $at, $zero, L_80085C68
    if (ctx->r1 == 0) {
        // 0x80085840: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80085C68;
    }
    // 0x80085840: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085844: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80085848: addu        $at, $at, $t8
    gpr jr_addend_80085854 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008584C: lw          $t8, -0x76B8($at)
    ctx->r24 = ADD32(ctx->r1, -0X76B8);
    // 0x80085850: nop

    // 0x80085854: jr          $t8
    // 0x80085858: nop

    switch (jr_addend_80085854 >> 2) {
        case 0: goto L_8008585C; break;
        case 1: goto L_8008597C; break;
        case 2: goto L_800859B4; break;
        case 3: goto L_80085AD0; break;
        case 4: goto L_80085B1C; break;
        case 5: goto L_80085B68; break;
        case 6: goto L_80085C68; break;
        case 7: goto L_80085BB4; break;
        case 8: goto L_80085C00; break;
        case 9: goto L_80085C30; break;
        default: switch_error(__func__, 0x80085854, 0x800E8948);
    }
    // 0x80085858: nop

L_8008585C:
    // 0x8008585C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085860: addiu       $t9, $t9, 0x190
    ctx->r25 = ADD32(ctx->r25, 0X190);
    // 0x80085864: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80085868: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8008586C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80085870: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80085874: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80085878: lw          $v0, 0x6AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AD0);
    // 0x8008587C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085880: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x80085884: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x80085888: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x8008588C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085890: bne         $t3, $zero, L_80085950
    if (ctx->r11 != 0) {
        // 0x80085894: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80085950;
    }
    // 0x80085894: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80085898: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x8008589C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800858A0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800858A4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800858A8: jal         0x80097C34
    // 0x800858AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_0;
    // 0x800858AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800858B0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800858B4: jal         0x80097D0C
    // 0x800858B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    filename_trim(rdram, ctx);
        goto after_1;
    // 0x800858B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x800858BC: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x800858C0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800858C4: lbu         $t5, 0x6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6);
    // 0x800858C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800858CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800858D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800858D4: lw          $v0, 0x6AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AD0);
    // 0x800858D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800858DC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800858E0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800858E4: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800858E8: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800858EC: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x800858F0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800858F4: bne         $a0, $zero, L_80085900
    if (ctx->r4 != 0) {
        // 0x800858F8: nop
    
            goto L_80085900;
    }
    // 0x800858F8: nop

    // 0x800858FC: break       7
    do_break(2148030716);
L_80085900:
    // 0x80085900: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085904: bne         $a0, $at, L_80085918
    if (ctx->r4 != ctx->r1) {
        // 0x80085908: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80085918;
    }
    // 0x80085908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008590C: bne         $v1, $at, L_80085918
    if (ctx->r3 != ctx->r1) {
        // 0x80085910: nop
    
            goto L_80085918;
    }
    // 0x80085910: nop

    // 0x80085914: break       6
    do_break(2148030740);
L_80085918:
    // 0x80085918: mflo        $t8
    ctx->r24 = lo;
    // 0x8008591C: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80085920: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80085924: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085928: mflo        $t2
    ctx->r10 = lo;
    // 0x8008592C: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x80085930: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x80085934: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x80085938: nop

    // 0x8008593C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80085940: beq         $t5, $zero, L_80085964
    if (ctx->r13 == 0) {
        // 0x80085944: nop
    
            goto L_80085964;
    }
    // 0x80085944: nop

    // 0x80085948: b           L_80085964
    // 0x8008594C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085964;
    // 0x8008594C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085950:
    // 0x80085950: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085954: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80085958: lw          $t7, 0x930($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X930);
    // 0x8008595C: nop

    // 0x80085960: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_80085964:
    // 0x80085964: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085968: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8008596C: nop

    // 0x80085970: lw          $t9, 0x1DC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1DC);
    // 0x80085974: b           L_80085C98
    // 0x80085978: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085C98;
    // 0x80085978: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8008597C:
    // 0x8008597C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085980: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085984: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085988: addiu       $t2, $t2, 0x1A0
    ctx->r10 = ADD32(ctx->r10, 0X1A0);
    // 0x8008598C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085990: lw          $t3, 0x1E0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1E0);
    // 0x80085994: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085998: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8008599C: lw          $t4, 0x1DC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1DC);
    // 0x800859A0: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x800859A4: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x800859A8: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x800859AC: b           L_80085C98
    // 0x800859B0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085C98;
    // 0x800859B0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800859B4:
    // 0x800859B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800859B8: addiu       $t5, $t5, 0x190
    ctx->r13 = ADD32(ctx->r13, 0X190);
    // 0x800859BC: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800859C0: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x800859C4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800859C8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800859CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800859D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800859D4: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800859D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800859DC: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x800859E0: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x800859E4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x800859E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800859EC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800859F0: jal         0x80097C34
    // 0x800859F4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x800859F4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800859F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800859FC: lw          $a2, 0x2390($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2390);
    // 0x80085A00: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80085A04: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80085A08: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80085A0C: beq         $t8, $zero, L_80085A38
    if (ctx->r24 == 0) {
        // 0x80085A10: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80085A38;
    }
    // 0x80085A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085A14: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80085A18: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80085A1C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80085A20:
    // 0x80085A20: sb          $a0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r4;
    // 0x80085A24: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80085A28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80085A2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80085A30: bne         $a0, $zero, L_80085A20
    if (ctx->r4 != 0) {
        // 0x80085A34: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80085A20;
    }
    // 0x80085A34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80085A38:
    // 0x80085A38: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80085A3C: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x80085A40: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80085A44: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80085A48: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x80085A4C: sb          $t4, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r12;
    // 0x80085A50: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80085A54: sb          $t3, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r11;
    // 0x80085A58: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80085A5C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085A60: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80085A64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085A68: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80085A6C: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x80085A70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80085A74: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80085A78: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80085A7C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80085A80: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x80085A84: bne         $a0, $zero, L_80085A90
    if (ctx->r4 != 0) {
        // 0x80085A88: nop
    
            goto L_80085A90;
    }
    // 0x80085A88: nop

    // 0x80085A8C: break       7
    do_break(2148031116);
L_80085A90:
    // 0x80085A90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085A94: bne         $a0, $at, L_80085AA8
    if (ctx->r4 != ctx->r1) {
        // 0x80085A98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80085AA8;
    }
    // 0x80085A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80085A9C: bne         $v1, $at, L_80085AA8
    if (ctx->r3 != ctx->r1) {
        // 0x80085AA0: nop
    
            goto L_80085AA8;
    }
    // 0x80085AA0: nop

    // 0x80085AA4: break       6
    do_break(2148031140);
L_80085AA8:
    // 0x80085AA8: mflo        $t2
    ctx->r10 = lo;
    // 0x80085AAC: mfhi        $t3
    ctx->r11 = hi;
    // 0x80085AB0: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80085AB4: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x80085AB8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x80085ABC: nop

    // 0x80085AC0: beq         $t4, $zero, L_80085C9C
    if (ctx->r12 == 0) {
        // 0x80085AC4: lw          $a1, 0x84($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X84);
            goto L_80085C9C;
    }
    // 0x80085AC4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085AC8: b           L_80085C98
    // 0x80085ACC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085C98;
    // 0x80085ACC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085AD0:
    // 0x80085AD0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085AD4: addiu       $t5, $t5, 0x1A0
    ctx->r13 = ADD32(ctx->r13, 0X1A0);
    // 0x80085AD8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80085ADC: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085AE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085AE4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80085AE8: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80085AEC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80085AF0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085AF4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80085AF8: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x80085AFC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80085B00: lw          $t4, 0x158($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X158);
    // 0x80085B04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085B08: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80085B0C: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085B10: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085B14: b           L_80085C98
    // 0x80085B18: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085C98;
    // 0x80085B18: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_80085B1C:
    // 0x80085B1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80085B20: addiu       $t6, $t6, 0x1B0
    ctx->r14 = ADD32(ctx->r14, 0X1B0);
    // 0x80085B24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085B28: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085B2C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80085B30: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085B34: lw          $t7, 0x1E4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1E4);
    // 0x80085B38: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80085B3C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085B40: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80085B44: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80085B48: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80085B4C: lw          $t2, 0x158($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X158);
    // 0x80085B50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085B54: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80085B58: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085B5C: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085B60: b           L_80085C98
    // 0x80085B64: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
        goto L_80085C98;
    // 0x80085B64: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
L_80085B68:
    // 0x80085B68: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80085B6C: addiu       $t3, $t3, 0x1C0
    ctx->r11 = ADD32(ctx->r11, 0X1C0);
    // 0x80085B70: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085B74: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085B78: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085B7C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80085B80: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80085B84: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80085B88: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085B8C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80085B90: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80085B94: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80085B98: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x80085B9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085BA0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80085BA4: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085BA8: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085BAC: b           L_80085C98
    // 0x80085BB0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085C98;
    // 0x80085BB0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_80085BB4:
    // 0x80085BB4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085BB8: addiu       $t2, $t2, 0x1D0
    ctx->r10 = ADD32(ctx->r10, 0X1D0);
    // 0x80085BBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085BC0: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085BC4: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085BC8: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085BCC: lw          $t4, 0x1E8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1E8);
    // 0x80085BD0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80085BD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085BD8: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x80085BDC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80085BE0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085BE4: lw          $t7, 0x158($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X158);
    // 0x80085BE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085BEC: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80085BF0: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085BF4: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085BF8: b           L_80085C98
    // 0x80085BFC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_80085C98;
    // 0x80085BFC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_80085C00:
    // 0x80085C00: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085C04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085C08: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80085C0C: addiu       $t8, $t8, 0x1B0
    ctx->r24 = ADD32(ctx->r24, 0X1B0);
    // 0x80085C10: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80085C14: lw          $t2, 0x1EC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1EC);
    // 0x80085C18: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C1C: lw          $t0, 0x6C04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C04);
    // 0x80085C20: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80085C24: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80085C28: b           L_80085C98
    // 0x80085C2C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
        goto L_80085C98;
    // 0x80085C2C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
L_80085C30:
    // 0x80085C30: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80085C34: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085C38: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085C3C: addiu       $t3, $t3, 0x190
    ctx->r11 = ADD32(ctx->r11, 0X190);
    // 0x80085C40: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085C44: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x80085C48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C4C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085C50: lw          $t6, 0x1DC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1DC);
    // 0x80085C54: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x80085C58: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x80085C5C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085C60: b           L_80085C98
    // 0x80085C64: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
        goto L_80085C98;
    // 0x80085C64: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
L_80085C68:
    // 0x80085C68: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085C6C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085C70: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80085C74: addiu       $t5, $t5, 0x1E0
    ctx->r13 = ADD32(ctx->r13, 0X1E0);
    // 0x80085C78: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80085C7C: lw          $t8, 0x144($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X144);
    // 0x80085C80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C84: lui         $t1, 0x8080
    ctx->r9 = S32(0X8080 << 16);
    // 0x80085C88: lw          $t0, 0x6C04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C04);
    // 0x80085C8C: ori         $t1, $t1, 0x80FF
    ctx->r9 = ctx->r9 | 0X80FF;
    // 0x80085C90: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80085C94: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_80085C98:
    // 0x80085C98: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
L_80085C9C:
    // 0x80085C9C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80085CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085CA4: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80085CA8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80085CAC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80085CB0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085CB4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80085CB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80085CBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085CC0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085CC4: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x80085CC8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80085CCC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80085CD0: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x80085CD4: jal         0x800809D0
    // 0x80085CD8: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    func_80080580(rdram, ctx);
        goto after_3;
    // 0x80085CD8: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    after_3:
    // 0x80085CDC: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80085CE0: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x80085CE4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80085CE8: bne         $v1, $zero, L_80085CF4
    if (ctx->r3 != 0) {
        // 0x80085CEC: addiu       $t7, $t5, 0xC
        ctx->r15 = ADD32(ctx->r13, 0XC);
            goto L_80085CF4;
    }
    // 0x80085CEC: addiu       $t7, $t5, 0xC
    ctx->r15 = ADD32(ctx->r13, 0XC);
    // 0x80085CF0: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
L_80085CF4:
    // 0x80085CF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80085CF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085CFC: beq         $v0, $at, L_80085D38
    if (ctx->r2 == ctx->r1) {
        // 0x80085D00: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80085D38;
    }
    // 0x80085D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80085D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085D08: bne         $v0, $at, L_80085E4C
    if (ctx->r2 != ctx->r1) {
        // 0x80085D0C: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085E4C;
    }
    // 0x80085D0C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80085D10: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x80085D14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085D18: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80085D1C: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80085D20: lw          $t9, 0x6AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6AD0);
    // 0x80085D24: nop

    // 0x80085D28: lbu         $t3, 0x4B($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X4B);
    // 0x80085D2C: nop

    // 0x80085D30: bne         $t3, $zero, L_80085E4C
    if (ctx->r11 != 0) {
        // 0x80085D34: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085E4C;
    }
    // 0x80085D34: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_80085D38:
    // 0x80085D38: bne         $v1, $zero, L_80085D48
    if (ctx->r3 != 0) {
        // 0x80085D3C: addiu       $a1, $zero, 0x78
        ctx->r5 = ADD32(0, 0X78);
            goto L_80085D48;
    }
    // 0x80085D3C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80085D40: b           L_80085D48
    // 0x80085D44: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
        goto L_80085D48;
    // 0x80085D44: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
L_80085D48:
    // 0x80085D48: jal         0x80068748
    // 0x80085D4C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x80085D4C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80085D50: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80085D54: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80085D58: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085D5C: subu        $v0, $a1, $t4
    ctx->r2 = SUB32(ctx->r5, ctx->r12);
    // 0x80085D60: addiu       $t6, $v0, -0x31
    ctx->r14 = ADD32(ctx->r2, -0X31);
    // 0x80085D64: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80085D68: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x80085D6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80085D70: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80085D74: addiu       $t8, $v0, -0x18
    ctx->r24 = ADD32(ctx->r2, -0X18);
    // 0x80085D78: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
    // 0x80085D7C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80085D80: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80085D84: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80085D88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80085D8C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80085D90: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80085D94: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x80085D98: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80085D9C: jal         0x8007C36C
    // 0x80085DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x80085DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80085DA4: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80085DA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085DAC: addiu       $t4, $t3, -0x85
    ctx->r12 = ADD32(ctx->r11, -0X85);
    // 0x80085DB0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80085DB4: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80085DB8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80085DBC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80085DC0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085DC4: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x80085DC8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80085DCC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80085DD0: jal         0x8009CFA4
    // 0x80085DD4: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80085DD4: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    after_6:
    // 0x80085DD8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80085DDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085DE0: addiu       $t2, $t8, -0x7D
    ctx->r10 = ADD32(ctx->r24, -0X7D);
    // 0x80085DE4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80085DE8: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80085DEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80085DF0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80085DF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085DF8: swc1        $f6, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f6.u32l;
    // 0x80085DFC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80085E00: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80085E04: jal         0x8009CFA4
    // 0x80085E08: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x80085E08: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    after_7:
    // 0x80085E0C: jal         0x8007C36C
    // 0x80085E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x80085E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80085E14: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80085E18: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085E1C: addiu       $t5, $t6, -0x80
    ctx->r13 = ADD32(ctx->r14, -0X80);
    // 0x80085E20: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80085E24: lw          $t7, -0x324($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X324);
    // 0x80085E28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80085E2C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80085E30: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x80085E34: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80085E38: jal         0x8009CFA4
    // 0x80085E3C: nop

    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x80085E3C: nop

    after_9:
    // 0x80085E40: jal         0x80068748
    // 0x80085E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x80085E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80085E48: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_80085E4C:
    // 0x80085E4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085E50: beq         $t2, $zero, L_80085E90
    if (ctx->r10 == 0) {
        // 0x80085E54: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80085E90;
    }
    // 0x80085E54: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085E58: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80085E5C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80085E60: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80085E64: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80085E68: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80085E6C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80085E70: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80085E74: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80085E78: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80085E7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085E80: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80085E84: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x80085E88: jal         0x80078F08
    // 0x80085E8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80085E8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_11:
L_80085E90:
    // 0x80085E90: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80085E94: nop

    // 0x80085E98: beq         $t5, $zero, L_80085F34
    if (ctx->r13 == 0) {
        // 0x80085E9C: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_80085F34;
    }
    // 0x80085E9C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80085EA0: jal         0x800C484C
    // 0x80085EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_12;
    // 0x80085EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80085EA8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80085EAC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085EBC: jal         0x800C48E4
    // 0x80085EC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80085EC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x80085EC4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085EC8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085ECC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085ED0: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085ED4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80085ED8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085EDC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085EE0: addiu       $a1, $a1, 0x51
    ctx->r5 = ADD32(ctx->r5, 0X51);
    // 0x80085EE4: jal         0x800C49A0
    // 0x80085EE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x80085EE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_14:
    // 0x80085EEC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80085EF0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80085EF4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085EF8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80085EFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085F00: jal         0x800C48E4
    // 0x80085F04: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80085F04: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_15:
    // 0x80085F08: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085F0C: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085F10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085F14: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085F18: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80085F1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085F20: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085F24: addiu       $a1, $a1, 0x4F
    ctx->r5 = ADD32(ctx->r5, 0X4F);
    // 0x80085F28: jal         0x800C49A0
    // 0x80085F2C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80085F2C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_16:
    // 0x80085F30: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
L_80085F34:
    // 0x80085F34: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x80085F38: beq         $t3, $zero, L_80085FCC
    if (ctx->r11 == 0) {
        // 0x80085F3C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80085FCC;
    }
    // 0x80085F3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80085F40: jal         0x800C484C
    // 0x80085F44: addiu       $s0, $s0, 0x51
    ctx->r16 = ADD32(ctx->r16, 0X51);
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80085F44: addiu       $s0, $s0, 0x51
    ctx->r16 = ADD32(ctx->r16, 0X51);
    after_17:
    // 0x80085F48: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80085F4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80085F50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085F58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085F5C: jal         0x800C48E4
    // 0x80085F60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80085F60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x80085F64: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085F68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085F6C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085F70: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085F74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085F78: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085F7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80085F80: jal         0x800C49A0
    // 0x80085F84: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    draw_text(rdram, ctx);
        goto after_19;
    // 0x80085F84: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_19:
    // 0x80085F88: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80085F8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085F90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085F94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80085F98: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085F9C: jal         0x800C48E4
    // 0x80085FA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_20;
    // 0x80085FA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_20:
    // 0x80085FA4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085FA8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085FAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085FB0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085FB4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80085FB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085FBC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085FC0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x80085FC4: jal         0x800C49A0
    // 0x80085FC8: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80085FC8: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    after_21:
L_80085FCC:
    // 0x80085FCC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085FD0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80085FD4: jr          $ra
    // 0x80085FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80085FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void savemenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FDC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80085FE0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80085FE4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80085FE8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80085FEC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80085FF0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80085FF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80085FF8: jal         0x8007A970
    // 0x80085FFC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80085FFC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80086000: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086004: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x80086008: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008600C: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80086010: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80086014: addu        $at, $at, $t6
    gpr jr_addend_80086030 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80086018: lw          $t6, -0x7690($at)
    ctx->r14 = ADD32(ctx->r1, -0X7690);
    // 0x8008601C: andi        $s4, $v0, 0xFFFF
    ctx->r20 = ctx->r2 & 0XFFFF;
    // 0x80086020: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80086024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008602C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80086030: jr          $t6
    // 0x80086034: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    switch (jr_addend_80086030 >> 2) {
        case 0: goto L_80086070; break;
        case 1: goto L_80086038; break;
        case 2: goto L_80086038; break;
        case 3: goto L_80086040; break;
        case 4: goto L_80086040; break;
        case 5: goto L_80086048; break;
        case 6: goto L_80086054; break;
        case 7: goto L_80086064; break;
        default: switch_error(__func__, 0x80086030, 0x800E8970);
    }
    // 0x80086034: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80086038:
    // 0x80086038: b           L_80086070
    // 0x8008603C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x8008603C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80086040:
    // 0x80086040: b           L_80086070
    // 0x80086044: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086044: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80086048:
    // 0x80086048: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008604C: b           L_80086070
    // 0x80086050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80086054:
    // 0x80086054: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80086058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008605C: b           L_80086070
    // 0x80086060: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086060: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80086064:
    // 0x80086064: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80086068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008606C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80086070:
    // 0x80086070: andi        $t7, $v1, 0x8
    ctx->r15 = ctx->r3 & 0X8;
    // 0x80086074: beq         $t7, $zero, L_80086080
    if (ctx->r15 == 0) {
        // 0x80086078: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80086080;
    }
    // 0x80086078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008607C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80086080:
    // 0x80086080: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086084: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80086088: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008608C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80086090: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80086094: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80086098: jal         0x8006816C
    // 0x8008609C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x8008609C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x800860A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800860A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800860A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800860AC: jal         0x800C492C
    // 0x800860B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x800860B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x800860B4: jal         0x800C484C
    // 0x800860B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_3;
    // 0x800860B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800860BC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800860C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800860C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800860C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800860CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800860D0: jal         0x800C48E4
    // 0x800860D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x800860D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x800860D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800860DC: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x800860E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800860E4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800860E8: lw          $a3, 0x294($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X294);
    // 0x800860EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800860F0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800860F4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800860F8: jal         0x800C49A0
    // 0x800860FC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x800860FC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_5:
    // 0x80086100: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80086104: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086108: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008610C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80086110: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80086114: jal         0x800C48E4
    // 0x80086118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x80086118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8008611C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80086120: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80086124: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086128: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8008612C: lw          $a3, 0x294($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X294);
    // 0x80086130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80086134: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086138: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008613C: jal         0x800C49A0
    // 0x80086140: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_7;
    // 0x80086140: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_7:
    // 0x80086144: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80086148: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8008614C: beq         $t6, $zero, L_800861CC
    if (ctx->r14 == 0) {
        // 0x80086150: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800861CC;
    }
    // 0x80086150: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086154: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80086158: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008615C: bne         $t7, $zero, L_8008616C
    if (ctx->r15 != 0) {
        // 0x80086160: lui         $s1, 0x800E
        ctx->r17 = S32(0X800E << 16);
            goto L_8008616C;
    }
    // 0x80086160: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80086164: b           L_80086170
    // 0x80086168: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
        goto L_80086170;
    // 0x80086168: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
L_8008616C:
    // 0x8008616C: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
L_80086170:
    // 0x80086170: lw          $t8, 0x695C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X695C);
    // 0x80086174: addiu       $s1, $s1, 0x9BC
    ctx->r17 = ADD32(ctx->r17, 0X9BC);
    // 0x80086178: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x8008617C: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80086180: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
L_80086184:
    // 0x80086184: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086188: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008618C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80086190: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80086194: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80086198: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008619C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800861A0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800861A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800861A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800861AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800861B0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800861B4: jal         0x80078F08
    // 0x800861B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x800861B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x800861BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800861C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800861C4: bne         $s2, $at, L_80086184
    if (ctx->r18 != ctx->r1) {
        // 0x800861C8: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80086184;
    }
    // 0x800861C8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800861CC:
    // 0x800861CC: beq         $s3, $zero, L_800862F8
    if (ctx->r19 == 0) {
        // 0x800861D0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800862F8;
    }
    // 0x800861D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800861D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800861D8: lwc1        $f0, 0x719C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X719C);
    // 0x800861DC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800861E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800861E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800861E8: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x800861EC: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800861F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800861F4: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800861F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800861FC: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x80086200: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80086204: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80086208: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008620C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80086210: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80086214: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80086218: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008621C: nop

    // 0x80086220: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80086224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80086228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008622C: nop

    // 0x80086230: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80086234: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80086238: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008623C: subu        $v0, $t2, $t9
    ctx->r2 = SUB32(ctx->r10, ctx->r25);
    // 0x80086240: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80086244: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80086248: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x8008624C: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_800862AC;
    }
    // 0x8008624C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086250: lw          $t3, 0x6FC8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FC8);
    // 0x80086254: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086258: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008625C: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x80086260: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_800862AC;
    }
    // 0x80086260: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086264: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086268: addiu       $s3, $s3, 0x6FCC
    ctx->r19 = ADD32(ctx->r19, 0X6FCC);
L_8008626C:
    // 0x8008626C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80086270: sll         $t4, $s0, 4
    ctx->r12 = S32(ctx->r16 << 4);
    // 0x80086274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80086278: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8008627C: jal         0x80085810
    // 0x80086280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    savemenu_render_element(rdram, ctx);
        goto after_9;
    // 0x80086280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_9:
    // 0x80086284: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x80086288: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008628C: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x80086290: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800862AC;
    }
    // 0x80086290: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086294: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086298: lw          $t6, 0x6FC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FC8);
    // 0x8008629C: nop

    // 0x800862A0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800862A4: bne         $at, $zero, L_8008626C
    if (ctx->r1 != 0) {
        // 0x800862A8: nop
    
            goto L_8008626C;
    }
    // 0x800862A8: nop

L_800862AC:
    // 0x800862AC: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800862B0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800862B4: addiu       $s3, $s3, 0x6FCC
    ctx->r19 = ADD32(ctx->r19, 0X6FCC);
    // 0x800862B8: blez        $s1, L_800862F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800862BC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800862F8;
    }
    // 0x800862BC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800862C0: blez        $s2, L_800862FC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800862C4: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_800862FC;
    }
    // 0x800862C4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_800862C8:
    // 0x800862C8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800862CC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800862D0: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x800862D4: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800862D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800862DC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800862E0: jal         0x80085810
    // 0x800862E4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    savemenu_render_element(rdram, ctx);
        goto after_10;
    // 0x800862E4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x800862E8: blez        $s1, L_800862FC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800862EC: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_800862FC;
    }
    // 0x800862EC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800862F0: bgtz        $s0, L_800862C8
    if (SIGNED(ctx->r16) > 0) {
        // 0x800862F4: nop
    
            goto L_800862C8;
    }
    // 0x800862F4: nop

L_800862F8:
    // 0x800862F8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_800862FC:
    // 0x800862FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086300: beq         $t2, $zero, L_80086420
    if (ctx->r10 == 0) {
        // 0x80086304: nop
    
            goto L_80086420;
    }
    // 0x80086304: nop

    // 0x80086308: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008630C: lwc1        $f0, 0x71AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X71AC);
    // 0x80086310: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80086314: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80086318: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008631C: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x80086320: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80086324: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086328: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x8008632C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80086330: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80086334: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x80086338: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008633C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086340: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80086344: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80086348: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008634C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80086350: nop

    // 0x80086354: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80086358: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008635C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80086360: nop

    // 0x80086364: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80086368: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8008636C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80086370: subu        $s1, $t5, $t4
    ctx->r17 = SUB32(ctx->r13, ctx->r12);
    // 0x80086374: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80086378: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x8008637C: sw          $s1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r17;
            goto L_800863D4;
    }
    // 0x8008637C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80086380: lw          $t7, 0x6FC0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FC0);
    // 0x80086384: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086388: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008638C: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x80086390: addiu       $s3, $s3, 0x6FC4
        ctx->r19 = ADD32(ctx->r19, 0X6FC4);
            goto L_800863D4;
    }
    // 0x80086390: addiu       $s3, $s3, 0x6FC4
    ctx->r19 = ADD32(ctx->r19, 0X6FC4);
L_80086394:
    // 0x80086394: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80086398: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x8008639C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800863A0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x800863A4: jal         0x80085810
    // 0x800863A8: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    savemenu_render_element(rdram, ctx);
        goto after_11;
    // 0x800863A8: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    after_11:
    // 0x800863AC: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x800863B0: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800863B4: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x800863B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800863D4;
    }
    // 0x800863B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800863BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800863C0: lw          $t9, 0x6FC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FC0);
    // 0x800863C4: nop

    // 0x800863C8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800863CC: bne         $at, $zero, L_80086394
    if (ctx->r1 != 0) {
        // 0x800863D0: nop
    
            goto L_80086394;
    }
    // 0x800863D0: nop

L_800863D4:
    // 0x800863D4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800863D8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800863DC: addiu       $s3, $s3, 0x6FC4
    ctx->r19 = ADD32(ctx->r19, 0X6FC4);
    // 0x800863E0: blez        $s1, L_80086420
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800863E4: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80086420;
    }
    // 0x800863E4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800863E8: blez        $s2, L_80086420
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800863EC: nop
    
            goto L_80086420;
    }
    // 0x800863EC: nop

L_800863F0:
    // 0x800863F0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800863F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800863F8: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x800863FC: sll         $t5, $s0, 4
    ctx->r13 = S32(ctx->r16 << 4);
    // 0x80086400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80086404: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80086408: jal         0x80085810
    // 0x8008640C: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    savemenu_render_element(rdram, ctx);
        goto after_12;
    // 0x8008640C: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    after_12:
    // 0x80086410: blez        $s1, L_80086420
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80086414: nop
    
            goto L_80086420;
    }
    // 0x80086414: nop

    // 0x80086418: bgtz        $s0, L_800863F0
    if (SIGNED(ctx->r16) > 0) {
        // 0x8008641C: nop
    
            goto L_800863F0;
    }
    // 0x8008641C: nop

L_80086420:
    // 0x80086420: jal         0x800C484C
    // 0x80086424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_13;
    // 0x80086424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80086428: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008642C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80086430: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80086434: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80086438: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008643C: jal         0x800C48E4
    // 0x80086440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x80086440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80086444: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80086448: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008644C: beq         $t7, $zero, L_80086470
    if (ctx->r15 == 0) {
        // 0x80086450: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80086470;
    }
    // 0x80086450: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086454: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80086458: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008645C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80086460: addiu       $a3, $a3, -0x7868
    ctx->r7 = ADD32(ctx->r7, -0X7868);
    // 0x80086464: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086468: jal         0x800C49A0
    // 0x8008646C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008646C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_15:
L_80086470:
    // 0x80086470: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086478: beq         $t2, $zero, L_800864A0
    if (ctx->r10 == 0) {
        // 0x8008647C: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800864A0;
    }
    // 0x8008647C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086480: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80086484: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80086488: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8008648C: lw          $a3, 0x1F0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X1F0);
    // 0x80086490: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086494: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086498: jal         0x800C49A0
    // 0x8008649C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8008649C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_16:
L_800864A0:
    // 0x800864A0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800864A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800864A8: beq         $t5, $zero, L_800864C0
    if (ctx->r13 == 0) {
        // 0x800864AC: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800864C0;
    }
    // 0x800864AC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800864B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800864B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800864B8: jal         0x800C60B8
    // 0x800864BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_17;
    // 0x800864BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_17:
L_800864C0:
    // 0x800864C0: jal         0x800812BC
    // 0x800864C4: nop

    menu_geometry_end(rdram, ctx);
        goto after_18;
    // 0x800864C4: nop

    after_18:
    // 0x800864C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800864CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800864D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800864D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800864D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800864DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800864E0: jr          $ra
    // 0x800864E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800864E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void savemenu_check_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800864EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800864F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800864F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800864F8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800864FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80086500: beq         $t7, $zero, L_800865F8
    if (ctx->r15 == 0) {
        // 0x80086504: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_800865F8;
    }
    // 0x80086504: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80086508: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8008650C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086510: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086514: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x80086518: addiu       $t3, $t3, 0x6FE0
    ctx->r11 = ADD32(ctx->r11, 0X6FE0);
    // 0x8008651C: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80086520: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80086524: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80086528: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008652C: jal         0x800763EC
    // 0x80086530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x80086530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80086534: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80086538: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008653C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80086540: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80086544: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80086548: bne         $v0, $zero, L_800865B0
    if (ctx->r2 != 0) {
        // 0x8008654C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800865B0;
    }
    // 0x8008654C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80086550: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80086554: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80086558: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008655C: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x80086560: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80086564: nop

    // 0x80086568: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008656C: bne         $at, $zero, L_800865FC
    if (ctx->r1 != 0) {
        // 0x80086570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x80086570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086574: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086578: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8008657C: blez        $t8, L_800865FC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086580: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x80086580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086584: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80086588: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8008658C: nop

    // 0x80086590: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086594: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80086598: sb          $a0, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r4;
    // 0x8008659C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800865A0: nop

    // 0x800865A4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800865A8: b           L_800865F8
    // 0x800865AC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_800865F8;
    // 0x800865AC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800865B0:
    // 0x800865B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800865B4: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800865B8: bgez        $t6, L_800865D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800865BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800865D4;
    }
    // 0x800865BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800865C0: bne         $t7, $at, L_800865D4
    if (ctx->r15 != ctx->r1) {
        // 0x800865C4: nop
    
            goto L_800865D4;
    }
    // 0x800865C4: nop

    // 0x800865C8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800865CC: b           L_800865F8
    // 0x800865D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_800865F8;
    // 0x800865D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800865D4:
    // 0x800865D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800865D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800865DC: beq         $v1, $at, L_800865F8
    if (ctx->r3 == ctx->r1) {
        // 0x800865E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800865F8;
    }
    // 0x800865E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800865E4: beq         $v1, $at, L_800865F8
    if (ctx->r3 == ctx->r1) {
        // 0x800865E8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800865F8;
    }
    // 0x800865E8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800865EC: beq         $v1, $at, L_800865FC
    if (ctx->r3 == ctx->r1) {
        // 0x800865F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800865FC;
    }
    // 0x800865F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800865F4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800865F8:
    // 0x800865F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800865FC:
    // 0x800865FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086600: jr          $ra
    // 0x80086604: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80086604: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void savemenu_blank_save_destination(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008660C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80086610: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80086614: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80086618: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008661C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80086620: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80086624: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086628: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008662C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80086630: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80086634: addiu       $s3, $s3, 0x6AD0
    ctx->r19 = ADD32(ctx->r19, 0X6AD0);
    // 0x80086638: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008663C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086640: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80086644:
    // 0x80086644: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80086648: nop

    // 0x8008664C: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x80086650: nop

    // 0x80086654: beq         $t7, $zero, L_800866D4
    if (ctx->r15 == 0) {
        // 0x80086658: nop
    
            goto L_800866D4;
    }
    // 0x80086658: nop

    // 0x8008665C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80086660: nop

    // 0x80086664: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086668: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x8008666C: sb          $s4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r20;
    // 0x80086670: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80086674: nop

    // 0x80086678: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008667C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80086680: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x80086684: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086688: nop

    // 0x8008668C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086690: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80086694: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    // 0x80086698: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008669C: nop

    // 0x800866A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800866A4: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800866A8: jal         0x80073EA4
    // 0x800866AC: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800866AC: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    after_0:
    // 0x800866B0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800866B4: nop

    // 0x800866B8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800866BC: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x800866C0: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x800866C4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800866C8: nop

    // 0x800866CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800866D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800866D4:
    // 0x800866D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800866D8: bne         $s2, $s5, L_80086644
    if (ctx->r18 != ctx->r21) {
        // 0x800866DC: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80086644;
    }
    // 0x800866DC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800866E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800866E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800866E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800866EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800866F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800866F4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800866F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800866FC: jr          $ra
    // 0x80086700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80086700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void savemenu_load_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086704: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80086708: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008670C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80086710: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80086714: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80086718: addiu       $s2, $s2, 0x6FC8
    ctx->r18 = ADD32(ctx->r18, 0X6FC8);
    // 0x8008671C: lw          $s6, 0x6ADC($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X6ADC);
    // 0x80086720: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80086724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086728: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008672C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80086730: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80086734: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x80086738: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008673C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086744: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80086748: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008674C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80086750: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80086754: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80086758: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008675C: addiu       $s4, $s4, 0x6FCC
    ctx->r20 = ADD32(ctx->r20, 0X6FCC);
    // 0x80086760: addiu       $s1, $s1, 0x6AD0
    ctx->r17 = ADD32(ctx->r17, 0X6AD0);
    // 0x80086764: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80086768: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008676C: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
L_80086770:
    // 0x80086770: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80086774: nop

    // 0x80086778: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x8008677C: nop

    // 0x80086780: bne         $t7, $zero, L_8008680C
    if (ctx->r15 != 0) {
        // 0x80086784: nop
    
            goto L_8008680C;
    }
    // 0x80086784: nop

    // 0x80086788: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8008678C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80086790: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80086794: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80086798: sb          $s3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r19;
    // 0x8008679C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800867A0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800867A4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800867A8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800867AC: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    // 0x800867B0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800867B4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800867B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800867BC: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800867C0: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x800867C4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x800867C8: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800867CC: sb          $t8, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r24;
    // 0x800867D0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800867D4: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800867D8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800867DC: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800867E0: jal         0x80073EA4
    // 0x800867E4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800867E4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    after_0:
    // 0x800867E8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800867EC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800867F0: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x800867F4: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800867F8: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // 0x800867FC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80086800: nop

    // 0x80086804: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80086808: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_8008680C:
    // 0x8008680C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086810: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086814: bne         $s0, $at, L_80086770
    if (ctx->r16 != ctx->r1) {
        // 0x80086818: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80086770;
    }
    // 0x80086818: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008681C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086820: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80086824: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80086828: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8008682C: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80086830: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x80086834: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80086838: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8008683C: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x80086840: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80086844: jal         0x80073EAC
    // 0x80086848: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    get_time_data_file_size(rdram, ctx);
        goto after_1;
    // 0x80086848: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    after_1:
    // 0x8008684C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086850: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086854: sll         $t1, $t7, 4
    ctx->r9 = S32(ctx->r15 << 4);
    // 0x80086858: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8008685C: sw          $v0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r2;
    // 0x80086860: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086864: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80086868: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8008686C: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x80086870: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80086874: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80086878: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8008687C: sb          $t4, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r12;
    // 0x80086880: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086884: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80086888: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8008688C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80086890: lw          $s0, 0x7024($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7024);
    // 0x80086894: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086898: addiu       $fp, $sp, 0xB4
    ctx->r30 = ADD32(ctx->r29, 0XB4);
L_8008689C:
    // 0x8008689C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800868A0: lw          $t2, 0x6FD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6FD8);
    // 0x800868A4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800868A8: beq         $t2, $zero, L_80086BDC
    if (ctx->r10 == 0) {
        // 0x800868AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80086BDC;
    }
    // 0x800868AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800868B0: sw          $zero, 0x6FD4($at)
    MEM_W(0X6FD4, ctx->r1) = 0;
    // 0x800868B4: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_800868B8:
    // 0x800868B8: addiu       $t6, $sp, 0xA4
    ctx->r14 = ADD32(ctx->r29, 0XA4);
    // 0x800868BC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800868C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800868C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800868C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800868CC: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x800868D0: jal         0x800760B8
    // 0x800868D4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x800868D4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x800868D8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800868DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800868E0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800868E4: bne         $v1, $at, L_800868F8
    if (ctx->r3 != ctx->r1) {
        // 0x800868E8: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800868F8;
    }
    // 0x800868E8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800868EC: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x800868F0: bne         $at, $zero, L_800868B8
    if (ctx->r1 != 0) {
        // 0x800868F4: addiu       $t8, $sp, 0x60
        ctx->r24 = ADD32(ctx->r29, 0X60);
            goto L_800868B8;
    }
    // 0x800868F4: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_800868F8:
    // 0x800868F8: bne         $v0, $zero, L_80086B68
    if (ctx->r2 != 0) {
        // 0x800868FC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086B68;
    }
    // 0x800868FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086900: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80086904: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
L_80086908:
    // 0x80086908: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x8008690C: nop

    // 0x80086910: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80086914: bne         $at, $zero, L_80086B44
    if (ctx->r1 != 0) {
        // 0x80086918: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_80086B44;
    }
    // 0x80086918: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8008691C: beq         $at, $zero, L_80086B44
    if (ctx->r1 == 0) {
        // 0x80086920: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80086B44;
    }
    // 0x80086920: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086924: addiu       $a0, $a0, 0x6FE0
    ctx->r4 = ADD32(ctx->r4, 0X6FE0);
    // 0x80086928: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8008692C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086930: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80086934: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80086938: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x8008693C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80086940: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80086944: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x80086948: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8008694C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80086950: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086954: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x80086958: sb          $zero, 0x6($t3)
    MEM_B(0X6, ctx->r11) = 0;
    // 0x8008695C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086960: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80086964: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80086968: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x8008696C: sb          $s3, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r19;
    // 0x80086970: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086974: sll         $a3, $s3, 2
    ctx->r7 = S32(ctx->r19 << 2);
    // 0x80086978: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8008697C: addu        $t5, $sp, $a3
    ctx->r13 = ADD32(ctx->r29, ctx->r7);
    // 0x80086980: lw          $t5, 0x60($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X60);
    // 0x80086984: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80086988: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8008698C: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80086990: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x80086994: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086998: bne         $v1, $at, L_80086A54
    if (ctx->r3 != ctx->r1) {
        // 0x8008699C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80086A54;
    }
    // 0x8008699C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800869A0: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x800869A4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800869A8: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    // 0x800869AC: jal         0x80074074
    // 0x800869B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_3;
    // 0x800869B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
    // 0x800869B4: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x800869B8: bne         $v0, $zero, L_80086A40
    if (ctx->r2 != 0) {
        // 0x800869BC: nop
    
            goto L_80086A40;
    }
    // 0x800869BC: nop

    // 0x800869C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800869C4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800869C8: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x800869CC: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x800869D0: sw          $s0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r16;
    // 0x800869D4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800869D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800869DC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x800869E0: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x800869E4: sb          $t8, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r24;
    // 0x800869E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800869EC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800869F0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800869F4: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800869F8: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800869FC: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80086A00: sb          $t5, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r13;
    // 0x80086A04: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086A08: lw          $t1, 0x10($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X10);
    // 0x80086A0C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80086A10: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x80086A14: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x80086A18: sltu        $t8, $zero, $t2
    ctx->r24 = 0 < ctx->r10 ? 1 : 0;
    // 0x80086A1C: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80086A20: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x80086A24: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086A28: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80086A2C: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x80086A30: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086A34: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x80086A38: b           L_80086B34
    // 0x80086A3C: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
        goto L_80086B34;
    // 0x80086A3C: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
L_80086A40:
    // 0x80086A40: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80086A44: nop

    // 0x80086A48: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x80086A4C: b           L_80086B34
    // 0x80086A50: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
        goto L_80086B34;
    // 0x80086A50: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80086A54:
    // 0x80086A54: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80086A58: beq         $v1, $at, L_80086A68
    if (ctx->r3 == ctx->r1) {
        // 0x80086A5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80086A68;
    }
    // 0x80086A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086A60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086A64: bne         $v1, $at, L_80086B34
    if (ctx->r3 != ctx->r1) {
        // 0x80086A68: addiu       $t8, $sp, 0xF4
        ctx->r24 = ADD32(ctx->r29, 0XF4);
            goto L_80086B34;
    }
L_80086A68:
    // 0x80086A68: addiu       $t8, $sp, 0xF4
    ctx->r24 = ADD32(ctx->r29, 0XF4);
    // 0x80086A6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086A70: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80086A74: bne         $v1, $at, L_80086A80
    if (ctx->r3 != ctx->r1) {
        // 0x80086A78: addu        $s1, $fp, $a3
        ctx->r17 = ADD32(ctx->r30, ctx->r7);
            goto L_80086A80;
    }
    // 0x80086A78: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x80086A7C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80086A80:
    // 0x80086A80: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086A84: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086A88: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x80086A8C: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x80086A90: sw          $s0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r16;
    // 0x80086A94: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80086A98: nop

    // 0x80086A9C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x80086AA0: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x80086AA4: nop

    // 0x80086AA8: beq         $v1, $zero, L_80086AD0
    if (ctx->r3 == 0) {
        // 0x80086AAC: nop
    
            goto L_80086AD0;
    }
    // 0x80086AAC: nop

L_80086AB0:
    // 0x80086AB0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x80086AB4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80086AB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086ABC: addu        $t3, $t6, $v0
    ctx->r11 = ADD32(ctx->r14, ctx->r2);
    // 0x80086AC0: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x80086AC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086AC8: bne         $v1, $zero, L_80086AB0
    if (ctx->r3 != 0) {
        // 0x80086ACC: nop
    
            goto L_80086AB0;
    }
    // 0x80086ACC: nop

L_80086AD0:
    // 0x80086AD0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80086AD4: nop

    // 0x80086AD8: beq         $a0, $zero, L_80086B2C
    if (ctx->r4 == 0) {
        // 0x80086ADC: nop
    
            goto L_80086B2C;
    }
    // 0x80086ADC: nop

    // 0x80086AE0: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80086AE4: addiu       $t1, $zero, 0x2E
    ctx->r9 = ADD32(0, 0X2E);
    // 0x80086AE8: beq         $t8, $zero, L_80086B2C
    if (ctx->r24 == 0) {
        // 0x80086AEC: nop
    
            goto L_80086B2C;
    }
    // 0x80086AEC: nop

    // 0x80086AF0: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x80086AF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80086AF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086AFC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80086B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086B04: beq         $t9, $zero, L_80086B2C
    if (ctx->r25 == 0) {
        // 0x80086B08: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_80086B2C;
    }
    // 0x80086B08: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_80086B0C:
    // 0x80086B0C: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x80086B10: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80086B14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086B18: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x80086B1C: lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X0);
    // 0x80086B20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086B24: bne         $v1, $zero, L_80086B0C
    if (ctx->r3 != 0) {
        // 0x80086B28: nop
    
            goto L_80086B0C;
    }
    // 0x80086B28: nop

L_80086B2C:
    // 0x80086B2C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80086B30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80086B34:
    // 0x80086B34: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80086B38: nop

    // 0x80086B3C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80086B40: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80086B44:
    // 0x80086B44: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80086B48: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80086B4C: bne         $s3, $at, L_80086908
    if (ctx->r19 != ctx->r1) {
        // 0x80086B50: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80086908;
    }
    // 0x80086B50: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80086B54: jal         0x800763BC
    // 0x80086B58: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    cpak_free_files(rdram, ctx);
        goto after_4;
    // 0x80086B58: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    after_4:
    // 0x80086B5C: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086B60: b           L_80086BDC
    // 0x80086B64: nop

        goto L_80086BDC;
    // 0x80086B64: nop

L_80086B68:
    // 0x80086B68: bne         $v1, $at, L_80086BAC
    if (ctx->r3 != ctx->r1) {
        // 0x80086B6C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80086BAC;
    }
    // 0x80086B6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80086B70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086B74: lw          $t3, 0x6FD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FD8);
    // 0x80086B78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086B7C: bgez        $t3, L_80086B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80086B80: sw          $t6, 0x6FD4($at)
        MEM_W(0X6FD4, ctx->r1) = ctx->r14;
            goto L_80086B88;
    }
    // 0x80086B80: sw          $t6, 0x6FD4($at)
    MEM_W(0X6FD4, ctx->r1) = ctx->r14;
    // 0x80086B84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086B88:
    // 0x80086B88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086B8C: lw          $t8, 0x702C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X702C);
    // 0x80086B90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086B94: beq         $t8, $zero, L_80086BDC
    if (ctx->r24 == 0) {
        // 0x80086B98: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80086BDC;
    }
    // 0x80086B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086B9C: sw          $t1, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = ctx->r9;
    // 0x80086BA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086BA4: b           L_80086BDC
    // 0x80086BA8: sw          $zero, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = 0;
        goto L_80086BDC;
    // 0x80086BA8: sw          $zero, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = 0;
L_80086BAC:
    // 0x80086BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086BB0: bne         $v1, $at, L_80086BC0
    if (ctx->r3 != ctx->r1) {
        // 0x80086BB4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80086BC0;
    }
    // 0x80086BB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086BB8: b           L_80086BDC
    // 0x80086BBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80086BDC;
    // 0x80086BBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086BC0:
    // 0x80086BC0: lw          $t9, 0x6FD8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FD8);
    // 0x80086BC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80086BC8: bgez        $t9, L_80086BDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80086BCC: nop
    
            goto L_80086BDC;
    }
    // 0x80086BCC: nop

    // 0x80086BD0: bne         $v1, $at, L_80086BDC
    if (ctx->r3 != ctx->r1) {
        // 0x80086BD4: nop
    
            goto L_80086BDC;
    }
    // 0x80086BD4: nop

    // 0x80086BD8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80086BDC:
    // 0x80086BDC: beq         $s7, $zero, L_8008689C
    if (ctx->r23 == 0) {
        // 0x80086BE0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8008689C;
    }
    // 0x80086BE0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80086BE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80086BE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086BEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80086BF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80086BF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80086BF8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80086BFC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80086C00: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80086C04: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80086C08: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80086C0C: jr          $ra
    // 0x80086C10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80086C10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void savemenu_load_destinations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80086C18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086C1C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80086C20: addiu       $s0, $s0, 0x6FC0
    ctx->r16 = ADD32(ctx->r16, 0X6FC0);
    // 0x80086C24: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80086C28: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086C2C: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086C30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086C34: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086C38: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086C3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80086C40: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80086C44: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80086C48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80086C4C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80086C50: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80086C54: beq         $at, $zero, L_80086E4C
    if (ctx->r1 == 0) {
        // 0x80086C58: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80086E4C;
    }
    // 0x80086C58: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80086C5C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086C60: addu        $at, $at, $t0
    gpr jr_addend_80086C6C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80086C64: lw          $t0, -0x7670($at)
    ctx->r8 = ADD32(ctx->r1, -0X7670);
    // 0x80086C68: nop

    // 0x80086C6C: jr          $t0
    // 0x80086C70: nop

    switch (jr_addend_80086C6C >> 2) {
        case 0: goto L_80086C74; break;
        case 1: goto L_80086CC8; break;
        case 2: goto L_80086D00; break;
        case 3: goto L_80086D60; break;
        case 4: goto L_80086DD8; break;
        default: switch_error(__func__, 0x80086C6C, 0x800E8990);
    }
    // 0x80086C70: nop

L_80086C74:
    // 0x80086C74: lbu         $a0, 0x6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6);
    // 0x80086C78: jal         0x8006EDB8
    // 0x80086C7C: nop

    mark_read_save_file(rdram, ctx);
        goto after_0;
    // 0x80086C7C: nop

    after_0:
    // 0x80086C80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086C84: lw          $a0, 0x6FC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FC4);
    // 0x80086C88: jal         0x80086608
    // 0x80086C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_1;
    // 0x80086C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80086C90: jal         0x80073EA4
    // 0x80086C94: nop

    get_game_data_file_size(rdram, ctx);
        goto after_2;
    // 0x80086C94: nop

    after_2:
    // 0x80086C98: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086C9C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086CA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086CA4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80086CA8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80086CAC: addiu       $a1, $a1, 0x6FD8
    ctx->r5 = ADD32(ctx->r5, 0X6FD8);
    // 0x80086CB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086CB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086CB8: jal         0x800864E8
    // 0x80086CBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_3;
    // 0x80086CBC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80086CC0: b           L_80086E4C
    // 0x80086CC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086CC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086CC8:
    // 0x80086CC8: jal         0x80073EAC
    // 0x80086CCC: nop

    get_time_data_file_size(rdram, ctx);
        goto after_4;
    // 0x80086CCC: nop

    after_4:
    // 0x80086CD0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086CD4: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086CD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086CDC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80086CE0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80086CE4: addiu       $a1, $a1, 0x6FD8
    ctx->r5 = ADD32(ctx->r5, 0X6FD8);
    // 0x80086CE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086CEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086CF0: jal         0x800864E8
    // 0x80086CF4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_5;
    // 0x80086CF4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x80086CF8: b           L_80086E4C
    // 0x80086CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086D00:
    // 0x80086D00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086D04: lw          $a0, 0x6FC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FC4);
    // 0x80086D08: jal         0x80086608
    // 0x80086D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_6;
    // 0x80086D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80086D10: jal         0x80073EA4
    // 0x80086D14: nop

    get_game_data_file_size(rdram, ctx);
        goto after_7;
    // 0x80086D14: nop

    after_7:
    // 0x80086D18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80086D1C: lw          $t4, 0x7194($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7194);
    // 0x80086D20: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086D24: lw          $t3, 0x6FCC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FCC);
    // 0x80086D28: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086D2C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086D30: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80086D34: lbu         $t6, 0x6($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X6);
    // 0x80086D38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086D3C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086D40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086D44: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086D48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086D4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086D50: jal         0x800864E8
    // 0x80086D54: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    savemenu_check_space(rdram, ctx);
        goto after_8;
    // 0x80086D54: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_8:
    // 0x80086D58: b           L_80086E4C
    // 0x80086D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086D60:
    // 0x80086D60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086D64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086D68: lw          $t9, 0x6FC4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FC4);
    // 0x80086D6C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80086D70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80086D74: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80086D78: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80086D7C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086D80: nop

    // 0x80086D84: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80086D88: jal         0x80073EAC
    // 0x80086D8C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    get_time_data_file_size(rdram, ctx);
        goto after_9;
    // 0x80086D8C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    after_9:
    // 0x80086D90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086D94: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086D98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80086D9C: lw          $t5, 0x6FCC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6FCC);
    // 0x80086DA0: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80086DA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086DA8: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80086DAC: lbu         $t9, 0x6($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X6);
    // 0x80086DB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086DB4: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086DB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086DBC: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086DC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086DC8: jal         0x800864E8
    // 0x80086DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    savemenu_check_space(rdram, ctx);
        goto after_10;
    // 0x80086DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_10:
    // 0x80086DD0: b           L_80086E4C
    // 0x80086DD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086E4C;
    // 0x80086DD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086DD8:
    // 0x80086DD8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80086DDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086DE0: lw          $t8, 0x6FC4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FC4);
    // 0x80086DE4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80086DE8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80086DEC: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x80086DF0: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x80086DF4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80086DF8: nop

    // 0x80086DFC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x80086E00: jal         0x80074D74
    // 0x80086E04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    get_ghost_data_file_size(rdram, ctx);
        goto after_11;
    // 0x80086E04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    after_11:
    // 0x80086E08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086E0C: lw          $t0, 0x7194($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7194);
    // 0x80086E10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086E14: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086E18: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x80086E1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086E20: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80086E24: lbu         $t8, 0x6($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X6);
    // 0x80086E28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086E2C: lw          $a2, 0x6FC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6FC4);
    // 0x80086E30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086E34: addiu       $a1, $a1, 0x6FDC
    ctx->r5 = ADD32(ctx->r5, 0X6FDC);
    // 0x80086E38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086E3C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086E40: jal         0x800864E8
    // 0x80086E44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    savemenu_check_space(rdram, ctx);
        goto after_12;
    // 0x80086E44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x80086E48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086E4C:
    // 0x80086E4C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80086E50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086E54: lw          $t1, 0x6FC4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6FC4);
    // 0x80086E58: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x80086E5C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80086E60: addu        $t5, $t1, $t7
    ctx->r13 = ADD32(ctx->r9, ctx->r15);
    // 0x80086E64: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80086E68: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80086E70: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80086E74: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80086E78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086E7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086E80: jr          $ra
    // 0x80086E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80086E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void savemenu_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086E8C: lw          $t6, 0x7194($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7194);
    // 0x80086E90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086E94: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80086E98: lw          $t7, 0x71A4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71A4);
    // 0x80086E9C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086EA0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80086EA4: blez        $a0, L_80086F34
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80086EA8: cvt.s.w     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80086F34;
    }
    // 0x80086EA8: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086EAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80086EB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086EB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086EB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80086EBC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086EC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086EC4: lwc1        $f16, -0x765C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X765C);
    // 0x80086EC8: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x80086ECC: lw          $v0, 0x6FC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC8);
    // 0x80086ED0: addiu       $a1, $a1, 0x719C
    ctx->r5 = ADD32(ctx->r5, 0X719C);
    // 0x80086ED4: addiu       $a2, $a2, 0x6FC0
    ctx->r6 = ADD32(ctx->r6, 0X6FC0);
    // 0x80086ED8: addiu       $a3, $a3, 0x71AC
    ctx->r7 = ADD32(ctx->r7, 0X71AC);
L_80086EDC:
    // 0x80086EDC: blez        $v0, L_80086EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80086EE0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80086EFC;
    }
    // 0x80086EE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80086EE4: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80086EE8: nop

    // 0x80086EEC: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80086EF0: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086EF4: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80086EF8: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80086EFC:
    // 0x80086EFC: blez        $v1, L_80086F2C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80086F00: nop
    
            goto L_80086F2C;
    }
    // 0x80086F00: nop

    // 0x80086F04: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086F08: nop

    // 0x80086F0C: blez        $t8, L_80086F2C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086F10: nop
    
            goto L_80086F2C;
    }
    // 0x80086F10: nop

    // 0x80086F14: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80086F18: nop

    // 0x80086F1C: sub.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80086F20: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086F24: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80086F28: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_80086F2C:
    // 0x80086F2C: bgtz        $a0, L_80086EDC
    if (SIGNED(ctx->r4) > 0) {
        // 0x80086F30: nop
    
            goto L_80086EDC;
    }
    // 0x80086F30: nop

L_80086F34:
    // 0x80086F34: jr          $ra
    // 0x80086F38: nop

    return;
    // 0x80086F38: nop

;}
RECOMP_FUNC void savemenu_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086F44: jal         0x8006ECD0
    // 0x80086F48: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80086F48: nop

    after_0:
    // 0x80086F4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086F50: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086F54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086F58: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086F5C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086F60: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80086F64: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80086F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80086F6C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80086F70: sltiu       $at, $t2, 0xA
    ctx->r1 = ctx->r10 < 0XA ? 1 : 0;
    // 0x80086F74: beq         $at, $zero, L_80087634
    if (ctx->r1 == 0) {
        // 0x80086F78: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80087634;
    }
    // 0x80086F78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80086F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086F80: addu        $at, $at, $t2
    gpr jr_addend_80086F8C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80086F84: lw          $t2, -0x7658($at)
    ctx->r10 = ADD32(ctx->r1, -0X7658);
    // 0x80086F88: nop

    // 0x80086F8C: jr          $t2
    // 0x80086F90: nop

    switch (jr_addend_80086F8C >> 2) {
        case 0: goto L_80086F94; break;
        case 1: goto L_8008711C; break;
        case 2: goto L_800871BC; break;
        case 3: goto L_800873DC; break;
        case 4: goto L_800874F4; break;
        case 5: goto L_80087580; break;
        case 6: goto L_80087634; break;
        case 7: goto L_80087634; break;
        case 8: goto L_80087634; break;
        case 9: goto L_800875C8; break;
        default: switch_error(__func__, 0x80086F8C, 0x800E89A8);
    }
    // 0x80086F90: nop

L_80086F94:
    // 0x80086F94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086F98: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80086F9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086FA0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086FA4: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80086FA8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80086FAC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086FB0: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80086FB4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80086FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086FBC: beq         $v0, $at, L_80086FDC
    if (ctx->r2 == ctx->r1) {
        // 0x80086FC0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086FDC;
    }
    // 0x80086FC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086FC4: beq         $v0, $at, L_800870D4
    if (ctx->r2 == ctx->r1) {
        // 0x80086FC8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800870D4;
    }
    // 0x80086FC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086FCC: beq         $v0, $at, L_800870C0
    if (ctx->r2 == ctx->r1) {
        // 0x80086FD0: nop
    
            goto L_800870C0;
    }
    // 0x80086FD0: nop

    // 0x80086FD4: b           L_8008763C
    // 0x80086FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80086FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80086FDC:
    // 0x80086FDC: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x80086FE0: jal         0x8006EE58
    // 0x80086FE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_1;
    // 0x80086FE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80086FE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086FEC: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80086FF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086FF4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80086FF8: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80086FFC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087000: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80087004: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80087008: lbu         $t4, 0x6($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X6);
    // 0x8008700C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087010: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087014: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087018: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8008701C: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x80087020: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80087024: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x80087028: nop

    // 0x8008702C: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80087030: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80087034: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087038: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8008703C: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x80087040: lbu         $t3, 0x6($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X6);
    // 0x80087044: nop

    // 0x80087048: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8008704C: addu        $t7, $v1, $t5
    ctx->r15 = ADD32(ctx->r3, ctx->r13);
    // 0x80087050: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80087054: nop

    // 0x80087058: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x8008705C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80087060: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80087064: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x80087068: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8008706C: lbu         $t7, 0x6($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X6);
    // 0x80087070: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80087074: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80087078: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8008707C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80087080: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80087084: nop

    // 0x80087088: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8008708C: nop

    // 0x80087090: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x80087094: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80087098: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8008709C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800870A0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800870A4: lbu         $t4, 0x6($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X6);
    // 0x800870A8: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x800870AC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800870B0: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x800870B4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800870B8: b           L_80087638
    // 0x800870BC: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
        goto L_80087638;
    // 0x800870BC: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
L_800870C0:
    // 0x800870C0: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x800870C4: jal         0x800741B4
    // 0x800870C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_game_data_to_controller_pak(rdram, ctx);
        goto after_2;
    // 0x800870C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x800870CC: b           L_80087638
    // 0x800870D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800870D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800870D4:
    // 0x800870D4: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800870D8: jal         0x8006EEEC
    // 0x800870DC: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_3;
    // 0x800870DC: nop

    after_3:
    // 0x800870E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800870E4: lw          $t9, 0x7194($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7194);
    // 0x800870E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800870EC: lw          $t8, 0x6FCC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FCC);
    // 0x800870F0: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800870F4: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x800870F8: lbu         $t2, 0x6($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X6);
    // 0x800870FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087100: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087104: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80087108: addu        $t7, $v1, $t3
    ctx->r15 = ADD32(ctx->r3, ctx->r11);
    // 0x8008710C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80087110: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80087114: b           L_80087638
    // 0x80087118: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
        goto L_80087638;
    // 0x80087118: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
L_8008711C:
    // 0x8008711C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087120: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087124: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087128: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8008712C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087130: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80087134: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80087138: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x8008713C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80087140: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087144: beq         $v0, $at, L_8008716C
    if (ctx->r2 == ctx->r1) {
        // 0x80087148: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008716C;
    }
    // 0x80087148: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008714C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087150: bne         $v0, $at, L_8008763C
    if (ctx->r2 != ctx->r1) {
        // 0x80087154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x80087154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087158: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x8008715C: jal         0x800743A0
    // 0x80087160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_4;
    // 0x80087160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80087164: b           L_80087638
    // 0x80087168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x80087168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8008716C:
    // 0x8008716C: jal         0x8006E9B0
    // 0x80087170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_5;
    // 0x80087170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80087174: jal         0x8006EE3C
    // 0x80087178: nop

    mark_to_write_flap_and_course_times(rdram, ctx);
        goto after_6;
    // 0x80087178: nop

    after_6:
    // 0x8008717C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80087180: ori         $a1, $a1, 0xFFF0
    ctx->r5 = ctx->r5 | 0XFFF0;
    // 0x80087184: jal         0x8009F000
    // 0x80087188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_7;
    // 0x80087188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x8008718C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80087190: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80087194: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x80087198: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x8008719C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800871A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800871A4: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x800871A8: and         $t3, $t2, $a0
    ctx->r11 = ctx->r10 & ctx->r4;
    // 0x800871AC: and         $t5, $t7, $a0
    ctx->r13 = ctx->r15 & ctx->r4;
    // 0x800871B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800871B4: b           L_80087638
    // 0x800871B8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80087638;
    // 0x800871B8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800871BC:
    // 0x800871BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800871C0: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800871C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800871C8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800871CC: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800871D0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800871D4: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x800871D8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800871DC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800871E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800871E4: beq         $v0, $at, L_80087204
    if (ctx->r2 == ctx->r1) {
        // 0x800871E8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087204;
    }
    // 0x800871E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800871EC: beq         $v0, $at, L_800873C4
    if (ctx->r2 == ctx->r1) {
        // 0x800871F0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800873C4;
    }
    // 0x800871F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800871F4: beq         $v0, $at, L_80087364
    if (ctx->r2 == ctx->r1) {
        // 0x800871F8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80087364;
    }
    // 0x800871F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800871FC: b           L_8008763C
    // 0x80087200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087204:
    // 0x80087204: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087208: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x8008720C: jal         0x80074074
    // 0x80087210: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_8;
    // 0x80087210: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80087214: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087218: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008721C: lw          $t2, 0x10($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X10);
    // 0x80087220: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087224: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087228: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8008722C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087230: beq         $t3, $zero, L_80087260
    if (ctx->r11 == 0) {
        // 0x80087234: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087260;
    }
    // 0x80087234: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087238: jal         0x8009F1A4
    // 0x8008723C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_adventure_two_unlocked(rdram, ctx);
        goto after_9;
    // 0x8008723C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x80087240: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087244: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087248: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008724C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087250: bne         $v0, $zero, L_80087260
    if (ctx->r2 != 0) {
        // 0x80087254: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087260;
    }
    // 0x80087254: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087258: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8008725C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_80087260:
    // 0x80087260: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80087264: nop

    // 0x80087268: bne         $t5, $zero, L_8008763C
    if (ctx->r13 != 0) {
        // 0x8008726C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x8008726C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087270: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80087274: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80087278: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8008727C: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x80087280: lbu         $a0, 0x6($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X6);
    // 0x80087284: jal         0x8006EE58
    // 0x80087288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_10;
    // 0x80087288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_10:
    // 0x8008728C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087290: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087298: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8008729C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800872A0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800872A4: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x800872A8: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800872AC: lbu         $t4, 0x6($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X6);
    // 0x800872B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800872B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800872B8: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x800872BC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800872C0: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800872C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800872C8: lw          $t2, 0x10($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X10);
    // 0x800872CC: nop

    // 0x800872D0: sw          $t2, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r10;
    // 0x800872D4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800872D8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800872DC: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800872E0: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x800872E4: lbu         $t8, 0x6($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X6);
    // 0x800872E8: nop

    // 0x800872EC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800872F0: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x800872F4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800872F8: nop

    // 0x800872FC: sb          $zero, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = 0;
    // 0x80087300: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80087304: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80087308: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x8008730C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80087310: lbu         $t2, 0x6($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X6);
    // 0x80087314: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80087318: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8008731C: lh          $t3, 0x0($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X0);
    // 0x80087320: addu        $t5, $v1, $t7
    ctx->r13 = ADD32(ctx->r3, ctx->r15);
    // 0x80087324: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80087328: nop

    // 0x8008732C: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80087330: nop

    // 0x80087334: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x80087338: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008733C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087340: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x80087344: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x80087348: lbu         $t4, 0x6($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X6);
    // 0x8008734C: lw          $t8, 0x50($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X50);
    // 0x80087350: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80087354: addu        $t9, $v1, $t3
    ctx->r25 = ADD32(ctx->r3, ctx->r11);
    // 0x80087358: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8008735C: b           L_80087638
    // 0x80087360: sw          $t8, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r24;
        goto L_80087638;
    // 0x80087360: sw          $t8, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r24;
L_80087364:
    // 0x80087364: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087368: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x8008736C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087370: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x80087374: jal         0x80074074
    // 0x80087378: nop

    read_game_data_from_controller_pak(rdram, ctx);
        goto after_11;
    // 0x80087378: nop

    after_11:
    // 0x8008737C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087384: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087388: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x8008738C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087390: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087394: bne         $v0, $zero, L_80087638
    if (ctx->r2 != 0) {
        // 0x80087398: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80087638;
    }
    // 0x80087398: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008739C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800873A0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800873A4: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x800873A8: addu        $t4, $t6, $t5
    ctx->r12 = ADD32(ctx->r14, ctx->r13);
    // 0x800873AC: lbu         $a0, 0x6($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X6);
    // 0x800873B0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x800873B4: jal         0x800741B4
    // 0x800873B8: nop

    write_game_data_to_controller_pak(rdram, ctx);
        goto after_12;
    // 0x800873B8: nop

    after_12:
    // 0x800873BC: b           L_80087638
    // 0x800873C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800873C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800873C4:
    // 0x800873C4: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800873C8: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800873CC: jal         0x80076520
    // 0x800873D0: nop

    delete_file(rdram, ctx);
        goto after_13;
    // 0x800873D0: nop

    after_13:
    // 0x800873D4: b           L_80087638
    // 0x800873D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800873D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800873DC:
    // 0x800873DC: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800873E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800873E4: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x800873E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800873EC: beq         $t3, $zero, L_80087408
    if (ctx->r11 == 0) {
        // 0x800873F0: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087408;
    }
    // 0x800873F0: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800873F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800873F8:
    // 0x800873F8: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800873FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80087400: bne         $t9, $zero, L_800873F8
    if (ctx->r25 != 0) {
        // 0x80087404: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800873F8;
    }
    // 0x80087404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80087408:
    // 0x80087408: blez        $v1, L_80087420
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008740C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80087420;
    }
    // 0x8008740C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087410: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x80087414: lbu         $t2, -0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, -0X1);
    // 0x80087418: b           L_80087428
    // 0x8008741C: sb          $t2, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r10;
        goto L_80087428;
    // 0x8008741C: sb          $t2, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r10;
L_80087420:
    // 0x80087420: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x80087424: sb          $t7, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r15;
L_80087428:
    // 0x80087428: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x8008742C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80087430: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087434: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80087438: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x8008743C: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x80087440: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x80087444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087448: beq         $v0, $at, L_80087468
    if (ctx->r2 == ctx->r1) {
        // 0x8008744C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087468;
    }
    // 0x8008744C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087450: beq         $v0, $at, L_800874DC
    if (ctx->r2 == ctx->r1) {
        // 0x80087454: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800874DC;
    }
    // 0x80087454: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087458: beq         $v0, $at, L_80087484
    if (ctx->r2 == ctx->r1) {
        // 0x8008745C: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80087484;
    }
    // 0x8008745C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80087460: b           L_8008763C
    // 0x80087464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087468:
    // 0x80087468: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x8008746C: jal         0x80074270
    // 0x80087470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_14;
    // 0x80087470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x80087474: jal         0x8006EE3C
    // 0x80087478: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mark_to_write_flap_and_course_times(rdram, ctx);
        goto after_15;
    // 0x80087478: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_15:
    // 0x8008747C: b           L_8008763C
    // 0x80087480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087484:
    // 0x80087484: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087488: jal         0x80074270
    // 0x8008748C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_16;
    // 0x8008748C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_16:
    // 0x80087490: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087494: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087498: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008749C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800874A0: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800874A4: bne         $v0, $zero, L_800874CC
    if (ctx->r2 != 0) {
        // 0x800874A8: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_800874CC;
    }
    // 0x800874A8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800874AC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800874B0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800874B4: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x800874B8: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x800874BC: lbu         $a0, 0x6($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X6);
    // 0x800874C0: jal         0x800743A0
    // 0x800874C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_17;
    // 0x800874C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x800874C8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800874CC:
    // 0x800874CC: jal         0x8006ED9C
    // 0x800874D0: nop

    mark_to_read_flap_and_course_times(rdram, ctx);
        goto after_18;
    // 0x800874D0: nop

    after_18:
    // 0x800874D4: b           L_8008763C
    // 0x800874D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x800874D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800874DC:
    // 0x800874DC: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800874E0: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800874E4: jal         0x80076520
    // 0x800874E8: nop

    delete_file(rdram, ctx);
        goto after_19;
    // 0x800874E8: nop

    after_19:
    // 0x800874EC: b           L_80087638
    // 0x800874F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800874F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800874F4:
    // 0x800874F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800874F8: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800874FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087500: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80087504: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087508: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8008750C: sll         $t4, $t6, 4
    ctx->r12 = S32(ctx->r14 << 4);
    // 0x80087510: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x80087514: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80087518: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8008751C: beq         $v0, $at, L_80087568
    if (ctx->r2 == ctx->r1) {
        // 0x80087520: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80087568;
    }
    // 0x80087520: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087524: beq         $v0, $at, L_8008754C
    if (ctx->r2 == ctx->r1) {
        // 0x80087528: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8008754C;
    }
    // 0x80087528: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008752C: bne         $v0, $at, L_80087638
    if (ctx->r2 != ctx->r1) {
        // 0x80087530: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80087638;
    }
    // 0x80087530: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087538: sw          $t3, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r11;
    // 0x8008753C: lbu         $t8, 0x6($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X6);
    // 0x80087540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087544: b           L_80087638
    // 0x80087548: sw          $t8, 0x6A70($at)
    MEM_W(0X6A70, ctx->r1) = ctx->r24;
        goto L_80087638;
    // 0x80087548: sw          $t8, 0x6A70($at)
    MEM_W(0X6A70, ctx->r1) = ctx->r24;
L_8008754C:
    // 0x8008754C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087550: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087554: lbu         $a2, 0x6($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X6);
    // 0x80087558: jal         0x800765E0
    // 0x8008755C: nop

    copy_controller_pak_data(rdram, ctx);
        goto after_20;
    // 0x8008755C: nop

    after_20:
    // 0x80087560: b           L_80087638
    // 0x80087564: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x80087564: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087568:
    // 0x80087568: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x8008756C: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087570: jal         0x80076520
    // 0x80087574: nop

    delete_file(rdram, ctx);
        goto after_21;
    // 0x80087574: nop

    after_21:
    // 0x80087578: b           L_80087638
    // 0x8008757C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x8008757C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087580:
    // 0x80087580: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087584: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087588: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008758C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80087590: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087594: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80087598: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x8008759C: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800875A0: lbu         $t5, 0x0($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X0);
    // 0x800875A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800875A8: bne         $t5, $at, L_8008763C
    if (ctx->r13 != ctx->r1) {
        // 0x800875AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x800875AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800875B0: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800875B4: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800875B8: jal         0x80076520
    // 0x800875BC: nop

    delete_file(rdram, ctx);
        goto after_22;
    // 0x800875BC: nop

    after_22:
    // 0x800875C0: b           L_80087638
    // 0x800875C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800875C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800875C8:
    // 0x800875C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800875CC: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800875D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800875D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800875D8: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800875DC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800875E0: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x800875E4: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800875E8: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x800875EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800875F0: bne         $t9, $at, L_80087638
    if (ctx->r25 != ctx->r1) {
        // 0x800875F4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_80087638;
    }
    // 0x800875F4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800875F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800875FC: jal         0x8009F000
    // 0x80087600: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    unset_eeprom_settings_value(rdram, ctx);
        goto after_23;
    // 0x80087600: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    after_23:
    // 0x80087604: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80087608: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008760C: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x80087610: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x80087614: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80087618: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8008761C: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x80087620: and         $t6, $t7, $a0
    ctx->r14 = ctx->r15 & ctx->r4;
    // 0x80087624: and         $t3, $t5, $a0
    ctx->r11 = ctx->r13 & ctx->r4;
    // 0x80087628: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008762C: b           L_80087638
    // 0x80087630: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_80087638;
    // 0x80087630: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80087634:
    // 0x80087634: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80087638:
    // 0x80087638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008763C:
    // 0x8008763C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80087640: jr          $ra
    // 0x80087644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80087644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void savemenu_render_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087648: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008764C: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x80087650: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80087654: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80087658: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8008765C: sra         $t6, $a0, 30
    ctx->r14 = S32(SIGNED(ctx->r4) >> 30);
    // 0x80087660: and         $t8, $a0, $at
    ctx->r24 = ctx->r4 & ctx->r1;
    // 0x80087664: addiu       $s5, $s5, 0x60
    ctx->r21 = ADD32(ctx->r21, 0X60);
    // 0x80087668: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8008766C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80087670: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087674: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80087678: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8008767C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80087680: lw          $t0, 0x15C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X15C);
    // 0x80087684: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80087688: addiu       $s4, $s4, 0x7030
    ctx->r20 = ADD32(ctx->r20, 0X7030);
    // 0x8008768C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087690: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x80087694: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087698: sw          $t8, 0x5C($at)
    MEM_W(0X5C, ctx->r1) = ctx->r24;
    // 0x8008769C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800876A0: addiu       $a1, $a1, 0x7034
    ctx->r5 = ADD32(ctx->r5, 0X7034);
    // 0x800876A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800876A8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800876AC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800876B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800876B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800876B8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800876BC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800876C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800876C4: beq         $t1, $zero, L_800876E0
    if (ctx->r9 == 0) {
        // 0x800876C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800876E0;
    }
    // 0x800876C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800876CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800876D0:
    // 0x800876D0: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800876D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800876D8: bne         $t2, $zero, L_800876D0
    if (ctx->r10 != 0) {
        // 0x800876DC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800876D0;
    }
    // 0x800876DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800876E0:
    // 0x800876E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800876E4: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800876E8: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x800876EC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800876F0: nop

    // 0x800876F4: beq         $t4, $zero, L_8008771C
    if (ctx->r12 == 0) {
        // 0x800876F8: nop
    
            goto L_8008771C;
    }
    // 0x800876F8: nop

L_800876FC:
    // 0x800876FC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80087700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087704: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087708: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008770C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80087710: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80087714: bne         $t7, $zero, L_800876FC
    if (ctx->r15 != 0) {
        // 0x80087718: nop
    
            goto L_800876FC;
    }
    // 0x80087718: nop

L_8008771C:
    // 0x8008771C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80087720: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087724: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80087728: jal         0x800C59F4
    // 0x8008772C: sw          $t9, 0x7038($at)
    MEM_W(0X7038, ctx->r1) = ctx->r25;
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x8008772C: sw          $t9, 0x7038($at)
    MEM_W(0X7038, ctx->r1) = ctx->r25;
    after_0:
    // 0x80087730: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x80087734: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x80087738: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008773C: addiu       $t2, $t0, 0x78
    ctx->r10 = ADD32(ctx->r8, 0X78);
    // 0x80087740: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80087744: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x80087748: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008774C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80087750: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087754: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80087758: jal         0x800C543C
    // 0x8008775C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x8008775C: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    after_1:
    // 0x80087760: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80087764: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087768: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8008776C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087774: jal         0x800C551C
    // 0x80087778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80087778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8008777C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087788: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008778C: jal         0x800C55B0
    // 0x80087790: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x80087790: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80087794: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087798: jal         0x800C54DC
    // 0x8008779C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x8008779C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800877A0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800877A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800877A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800877AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800877B0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800877B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800877B8: jal         0x800C5560
    // 0x800877BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x800877BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x800877C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800877C4: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x800877C8: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800877CC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800877D0: addiu       $t5, $t5, 0x10C
    ctx->r13 = ADD32(ctx->r13, 0X10C);
    // 0x800877D4: lw          $a3, 0x100($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X100);
    // 0x800877D8: beq         $v1, $t5, L_800877F0
    if (ctx->r3 == ctx->r13) {
        // 0x800877DC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800877F0;
    }
    // 0x800877DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800877E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800877E4: addiu       $t6, $t6, 0x124
    ctx->r14 = ADD32(ctx->r14, 0X124);
    // 0x800877E8: bne         $v1, $t6, L_800877FC
    if (ctx->r3 != ctx->r14) {
        // 0x800877EC: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800877FC;
    }
    // 0x800877EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
L_800877F0:
    // 0x800877F0: lw          $a3, 0x260($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X260);
    // 0x800877F4: b           L_80087814
    // 0x800877F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80087814;
    // 0x800877F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800877FC:
    // 0x800877FC: addiu       $t7, $t7, 0x13C
    ctx->r15 = ADD32(ctx->r15, 0X13C);
    // 0x80087800: bne         $v1, $t7, L_80087814
    if (ctx->r3 != ctx->r15) {
        // 0x80087804: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80087814;
    }
    // 0x80087804: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087808: lw          $a3, 0x1F4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1F4);
    // 0x8008780C: nop

    // 0x80087810: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80087814:
    // 0x80087814: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80087818: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008781C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80087820: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80087824: jal         0x800C56C8
    // 0x80087828: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x80087828: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_6:
    // 0x8008782C: addiu       $s2, $zero, 0x34
    ctx->r18 = ADD32(0, 0X34);
    // 0x80087830: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80087834: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087838: jal         0x800C54DC
    // 0x8008783C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x8008783C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80087840: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80087844: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x80087848: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8008784C: addu        $t1, $v1, $s0
    ctx->r9 = ADD32(ctx->r3, ctx->r16);
    // 0x80087850: beq         $t0, $zero, L_800878A4
    if (ctx->r8 == 0) {
        // 0x80087854: nop
    
            goto L_800878A4;
    }
    // 0x80087854: nop

    // 0x80087858: lw          $s1, 0x0($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X0);
    // 0x8008785C: nop

L_80087860:
    // 0x80087860: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80087864: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80087868: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008786C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087870: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80087874: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087878: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008787C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80087880: jal         0x800C56C8
    // 0x80087884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x80087884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80087888: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8008788C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80087890: addu        $t5, $v1, $s0
    ctx->r13 = ADD32(ctx->r3, ctx->r16);
    // 0x80087894: lw          $s1, 0x0($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X0);
    // 0x80087898: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008789C: bne         $s1, $zero, L_80087860
    if (ctx->r17 != 0) {
        // 0x800878A0: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80087860;
    }
    // 0x800878A0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_800878A4:
    // 0x800878A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800878A8: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x800878AC: addu        $t6, $v1, $s0
    ctx->r14 = ADD32(ctx->r3, ctx->r16);
    // 0x800878B0: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800878B4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800878B8: beq         $s1, $zero, L_80087908
    if (ctx->r17 == 0) {
        // 0x800878BC: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80087908;
    }
    // 0x800878BC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800878C0: addiu       $s3, $s3, 0x7040
    ctx->r19 = ADD32(ctx->r19, 0X7040);
L_800878C4:
    // 0x800878C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800878C8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800878CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800878D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800878D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800878D8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800878DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800878E0: jal         0x800C56C8
    // 0x800878E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x800878E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x800878E8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800878EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800878F0: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800878F4: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x800878F8: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x800878FC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80087900: bne         $s1, $zero, L_800878C4
    if (ctx->r17 != 0) {
        // 0x80087904: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800878C4;
    }
    // 0x80087904: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80087908:
    // 0x80087908: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008790C: addiu       $v0, $v0, 0x6980
    ctx->r2 = ADD32(ctx->r2, 0X6980);
    // 0x80087910: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80087914: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80087918: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8008791C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80087920: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80087924: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80087928: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8008792C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80087930: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80087934: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80087938: jr          $ra
    // 0x8008793C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008793C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void savemenu_input_source(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087944: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008794C: beq         $t6, $zero, L_80087998
    if (ctx->r14 == 0) {
        // 0x80087950: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80087998;
    }
    // 0x80087950: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80087954: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80087958: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008795C: lw          $t8, 0x6FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FD0);
    // 0x80087960: lw          $t7, 0x6FD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FD4);
    // 0x80087964: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087968: beq         $t7, $t8, L_80087980
    if (ctx->r15 == ctx->r24) {
        // 0x8008796C: sw          $zero, 0x6980($at)
        MEM_W(0X6980, ctx->r1) = 0;
            goto L_80087980;
    }
    // 0x8008796C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80087970: jal         0x80087648
    // 0x80087974: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    savemenu_render_error(rdram, ctx);
        goto after_0;
    // 0x80087974: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80087978: b           L_80087A48
    // 0x8008797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087A48;
    // 0x8008797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087980:
    // 0x80087980: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087984: jal         0x80001D04
    // 0x80087988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008798C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80087990: b           L_80087A44
    // 0x80087994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_80087A44;
    // 0x80087994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80087998:
    // 0x80087998: andi        $t0, $a0, 0x9000
    ctx->r8 = ctx->r4 & 0X9000;
    // 0x8008799C: beq         $t0, $zero, L_800879BC
    if (ctx->r8 == 0) {
        // 0x800879A0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800879BC;
    }
    // 0x800879A0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800879A4: jal         0x80001D04
    // 0x800879A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800879A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800879AC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800879B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800879B4: b           L_80087A44
    // 0x800879B8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
        goto L_80087A44;
    // 0x800879B8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_800879BC:
    // 0x800879BC: bgez        $a1, L_800879FC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800879C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800879FC;
    }
    // 0x800879C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800879C4: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x800879C8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800879CC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800879D0: blez        $t2, L_800879FC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800879D4: nop
    
            goto L_800879FC;
    }
    // 0x800879D4: nop

    // 0x800879D8: jal         0x80001D04
    // 0x800879DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800879DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800879E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800879E4: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x800879E8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800879EC: nop

    // 0x800879F0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800879F4: b           L_80087A44
    // 0x800879F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_80087A44;
    // 0x800879F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800879FC:
    // 0x800879FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087A00: blez        $a1, L_80087A44
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80087A04: addiu       $v0, $v0, 0x7194
        ctx->r2 = ADD32(ctx->r2, 0X7194);
            goto L_80087A44;
    }
    // 0x80087A04: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x80087A08: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80087A0C: lw          $t6, 0x6FC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FC8);
    // 0x80087A10: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80087A14: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80087A18: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80087A1C: beq         $at, $zero, L_80087A44
    if (ctx->r1 == 0) {
        // 0x80087A20: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087A44;
    }
    // 0x80087A20: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087A24: jal         0x80001D04
    // 0x80087A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80087A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80087A2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087A30: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x80087A34: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80087A38: nop

    // 0x80087A3C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80087A40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80087A44:
    // 0x80087A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087A48:
    // 0x80087A48: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A4C: jr          $ra
    // 0x80087A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80087A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void savemenu_input_dest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087A58: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087A5C: beq         $t6, $zero, L_80087A80
    if (ctx->r14 == 0) {
        // 0x80087A60: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80087A80;
    }
    // 0x80087A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087A64: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087A68: jal         0x80001D04
    // 0x80087A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80087A70: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80087A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A78: b           L_80087B2C
    // 0x80087A7C: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
        goto L_80087B2C;
    // 0x80087A7C: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
L_80087A80:
    // 0x80087A80: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087A84: beq         $t8, $zero, L_80087AA4
    if (ctx->r24 == 0) {
        // 0x80087A88: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087AA4;
    }
    // 0x80087A88: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087A8C: jal         0x80001D04
    // 0x80087A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087A94: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80087A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A9C: b           L_80087B2C
    // 0x80087AA0: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80087B2C;
    // 0x80087AA0: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80087AA4:
    // 0x80087AA4: bgez        $a1, L_80087AE4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087AA8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80087AE4;
    }
    // 0x80087AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087AAC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AB0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80087AB4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087AB8: blez        $t0, L_80087AE4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80087ABC: nop
    
            goto L_80087AE4;
    }
    // 0x80087ABC: nop

    // 0x80087AC0: jal         0x80001D04
    // 0x80087AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80087AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80087AC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087ACC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AD0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80087AD4: nop

    // 0x80087AD8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80087ADC: b           L_80087B2C
    // 0x80087AE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_80087B2C;
    // 0x80087AE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80087AE4:
    // 0x80087AE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087AE8: blez        $a1, L_80087B2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80087AEC: addiu       $v0, $v0, 0x71A4
        ctx->r2 = ADD32(ctx->r2, 0X71A4);
            goto L_80087B2C;
    }
    // 0x80087AEC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80087AF4: lw          $t4, 0x6FC0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6FC0);
    // 0x80087AF8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80087AFC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80087B00: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80087B04: beq         $at, $zero, L_80087B2C
    if (ctx->r1 == 0) {
        // 0x80087B08: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087B2C;
    }
    // 0x80087B08: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087B0C: jal         0x80001D04
    // 0x80087B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80087B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80087B14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087B18: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087B1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80087B20: nop

    // 0x80087B24: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087B28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80087B2C:
    // 0x80087B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087B34: jr          $ra
    // 0x80087B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void savemenu_input_confirm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087B40: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087B48: beq         $t6, $zero, L_80087B6C
    if (ctx->r14 == 0) {
        // 0x80087B4C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80087B6C;
    }
    // 0x80087B4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80087B50: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087B54: jal         0x80001D04
    // 0x80087B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80087B5C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80087B60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B64: b           L_80087B94
    // 0x80087B68: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
        goto L_80087B94;
    // 0x80087B68: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
L_80087B6C:
    // 0x80087B6C: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087B70: beq         $t8, $zero, L_80087B94
    if (ctx->r24 == 0) {
        // 0x80087B74: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087B94;
    }
    // 0x80087B74: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087B78: jal         0x80001D04
    // 0x80087B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087B80: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80087B84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B88: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
    // 0x80087B8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B90: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
L_80087B94:
    // 0x80087B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087B9C: jr          $ra
    // 0x80087BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void savemenu_input_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BA4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80087BA8: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x80087BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087BB0: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80087BB4: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80087BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087BBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087BC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80087BC4: bne         $at, $zero, L_80087BD4
    if (ctx->r1 != 0) {
        // 0x80087BC8: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80087BD4;
    }
    // 0x80087BC8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80087BCC: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80087BD0: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_80087BD4:
    // 0x80087BD4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087BD8: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087BDC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087BE0: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80087BE4: addiu       $a1, $a1, 0x7034
    ctx->r5 = ADD32(ctx->r5, 0X7034);
    // 0x80087BE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80087BEC: andi        $t8, $t0, 0x7
    ctx->r24 = ctx->r8 & 0X7;
    // 0x80087BF0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80087BF4: blez        $a0, L_80087C48
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80087BF8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80087C48;
    }
    // 0x80087BF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80087BFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087C00: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087C04: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087C08: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
L_80087C0C:
    // 0x80087C0C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80087C10: nop

    // 0x80087C14: bne         $v1, $t9, L_80087C28
    if (ctx->r3 != ctx->r25) {
        // 0x80087C18: nop
    
            goto L_80087C28;
    }
    // 0x80087C18: nop

    // 0x80087C1C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80087C20: b           L_80087C34
    // 0x80087C24: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
        goto L_80087C34;
    // 0x80087C24: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
L_80087C28:
    // 0x80087C28: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80087C2C: nop

    // 0x80087C30: sb          $zero, 0x13($t3)
    MEM_B(0X13, ctx->r11) = 0;
L_80087C34:
    // 0x80087C34: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80087C38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80087C3C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80087C40: bne         $at, $zero, L_80087C0C
    if (ctx->r1 != 0) {
        // 0x80087C44: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80087C0C;
    }
    // 0x80087C44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80087C48:
    // 0x80087C48: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80087C4C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087C50: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x80087C54: bne         $t5, $zero, L_80087C7C
    if (ctx->r13 != 0) {
        // 0x80087C58: addiu       $a3, $a3, 0x7038
        ctx->r7 = ADD32(ctx->r7, 0X7038);
            goto L_80087C7C;
    }
    // 0x80087C58: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087C5C: andi        $v0, $t4, 0x9000
    ctx->r2 = ctx->r12 & 0X9000;
    // 0x80087C60: beq         $v0, $zero, L_80087E34
    if (ctx->r2 == 0) {
        // 0x80087C64: nop
    
            goto L_80087E34;
    }
    // 0x80087C64: nop

    // 0x80087C68: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80087C6C: nop

    // 0x80087C70: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087C74: bne         $t7, $a0, L_80087E34
    if (ctx->r15 != ctx->r4) {
        // 0x80087C78: nop
    
            goto L_80087E34;
    }
    // 0x80087C78: nop

L_80087C7C:
    // 0x80087C7C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087C84: jal         0x80001D04
    // 0x80087C88: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087C88: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80087C8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087C90: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087C94: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80087C98: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087C9C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80087CA0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80087CA4: beq         $t0, $zero, L_80087CD8
    if (ctx->r8 == 0) {
        // 0x80087CA8: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80087CD8;
    }
    // 0x80087CA8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80087CAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087CB0: beq         $t0, $at, L_80087CFC
    if (ctx->r8 == ctx->r1) {
        // 0x80087CB4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80087CFC;
    }
    // 0x80087CB4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80087CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087CBC: beq         $t0, $v0, L_80087D70
    if (ctx->r8 == ctx->r2) {
        // 0x80087CC0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80087D70;
    }
    // 0x80087CC0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80087CC4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087CC8: beq         $t0, $at, L_80087DE4
    if (ctx->r8 == ctx->r1) {
        // 0x80087CCC: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80087DE4;
    }
    // 0x80087CCC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80087CD0: b           L_80087FC4
    // 0x80087CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087FC4;
    // 0x80087CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087CD8:
    // 0x80087CD8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80087CDC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80087CE0: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80087CE4: bne         $t3, $zero, L_80087FC0
    if (ctx->r11 != 0) {
        // 0x80087CE8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087FC0;
    }
    // 0x80087CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087CEC: sw          $t5, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r13;
    // 0x80087CF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087CF4: b           L_80087FC0
    // 0x80087CF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087FC0;
    // 0x80087CF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80087CFC:
    // 0x80087CFC: lw          $t6, 0x5C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C);
    // 0x80087D00: nop

    // 0x80087D04: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80087D08: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80087D0C: beq         $at, $zero, L_80087D60
    if (ctx->r1 == 0) {
        // 0x80087D10: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80087D60;
    }
    // 0x80087D10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80087D14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087D18: addu        $at, $at, $t7
    gpr jr_addend_80087D24 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80087D1C: lw          $t7, -0x7630($at)
    ctx->r15 = ADD32(ctx->r1, -0X7630);
    // 0x80087D20: nop

    // 0x80087D24: jr          $t7
    // 0x80087D28: nop

    switch (jr_addend_80087D24 >> 2) {
        case 0: goto L_80087D44; break;
        case 1: goto L_80087D44; break;
        case 2: goto L_80087D44; break;
        case 3: goto L_80087D60; break;
        case 4: goto L_80087D2C; break;
        case 5: goto L_80087D60; break;
        case 6: goto L_80087D50; break;
        case 7: goto L_80087D60; break;
        case 8: goto L_80087D44; break;
        default: switch_error(__func__, 0x80087D24, 0x800E89D0);
    }
    // 0x80087D28: nop

L_80087D2C:
    // 0x80087D2C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80087D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D34: sw          $t8, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r24;
    // 0x80087D38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087D3C: b           L_80087FC0
    // 0x80087D40: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_80087FC0;
    // 0x80087D40: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_80087D44:
    // 0x80087D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D48: b           L_80087FC0
    // 0x80087D4C: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087D4C: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
L_80087D50:
    // 0x80087D50: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80087D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D58: b           L_80087FC0
    // 0x80087D5C: sw          $t2, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r10;
        goto L_80087FC0;
    // 0x80087D5C: sw          $t2, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r10;
L_80087D60:
    // 0x80087D60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087D64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D68: b           L_80087FC0
    // 0x80087D6C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
        goto L_80087FC0;
    // 0x80087D6C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
L_80087D70:
    // 0x80087D70: lw          $t5, 0x5C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5C);
    // 0x80087D74: nop

    // 0x80087D78: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x80087D7C: sltiu       $at, $t4, 0x9
    ctx->r1 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x80087D80: beq         $at, $zero, L_80087DD4
    if (ctx->r1 == 0) {
        // 0x80087D84: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80087DD4;
    }
    // 0x80087D84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087D88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087D8C: addu        $at, $at, $t4
    gpr jr_addend_80087D98 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80087D90: lw          $t4, -0x760C($at)
    ctx->r12 = ADD32(ctx->r1, -0X760C);
    // 0x80087D94: nop

    // 0x80087D98: jr          $t4
    // 0x80087D9C: nop

    switch (jr_addend_80087D98 >> 2) {
        case 0: goto L_80087DA0; break;
        case 1: goto L_80087DB8; break;
        case 2: goto L_80087DB8; break;
        case 3: goto L_80087DD4; break;
        case 4: goto L_80087DA0; break;
        case 5: goto L_80087DD4; break;
        case 6: goto L_80087DC4; break;
        case 7: goto L_80087DD4; break;
        case 8: goto L_80087DB8; break;
        default: switch_error(__func__, 0x80087D98, 0x800E89F4);
    }
    // 0x80087D9C: nop

L_80087DA0:
    // 0x80087DA0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80087DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DA8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x80087DAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80087DB0: b           L_80087FC0
    // 0x80087DB4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80087FC0;
    // 0x80087DB4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80087DB8:
    // 0x80087DB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DBC: b           L_80087FC0
    // 0x80087DC0: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087DC0: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
L_80087DC4:
    // 0x80087DC4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80087DC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DCC: b           L_80087FC0
    // 0x80087DD0: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
        goto L_80087FC0;
    // 0x80087DD0: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
L_80087DD4:
    // 0x80087DD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087DD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DDC: b           L_80087FC0
    // 0x80087DE0: sw          $t9, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r25;
        goto L_80087FC0;
    // 0x80087DE0: sw          $t9, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r25;
L_80087DE4:
    // 0x80087DE4: lw          $t2, 0x5C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5C);
    // 0x80087DE8: nop

    // 0x80087DEC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80087DF0: sltiu       $at, $t3, 0xA
    ctx->r1 = ctx->r11 < 0XA ? 1 : 0;
    // 0x80087DF4: beq         $at, $zero, L_80087FC0
    if (ctx->r1 == 0) {
        // 0x80087DF8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80087FC0;
    }
    // 0x80087DF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80087DFC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087E00: addu        $at, $at, $t3
    gpr jr_addend_80087E0C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80087E04: lw          $t3, -0x75E8($at)
    ctx->r11 = ADD32(ctx->r1, -0X75E8);
    // 0x80087E08: nop

    // 0x80087E0C: jr          $t3
    // 0x80087E10: nop

    switch (jr_addend_80087E0C >> 2) {
        case 0: goto L_80087E14; break;
        case 1: goto L_80087E14; break;
        case 2: goto L_80087E14; break;
        case 3: goto L_80087FC0; break;
        case 4: goto L_80087E14; break;
        case 5: goto L_80087FC0; break;
        case 6: goto L_80087E14; break;
        case 7: goto L_80087FC0; break;
        case 8: goto L_80087E2C; break;
        case 9: goto L_80087E2C; break;
        default: switch_error(__func__, 0x80087E0C, 0x800E8A18);
    }
    // 0x80087E10: nop

L_80087E14:
    // 0x80087E14: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80087E18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087E1C: sw          $t5, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r13;
    // 0x80087E20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087E24: b           L_80087FC0
    // 0x80087E28: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087FC0;
    // 0x80087E28: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80087E2C:
    // 0x80087E2C: b           L_80087FC0
    // 0x80087E30: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_80087FC0;
    // 0x80087E30: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_80087E34:
    // 0x80087E34: beq         $v0, $zero, L_80087F40
    if (ctx->r2 == 0) {
        // 0x80087E38: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80087F40;
    }
    // 0x80087E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087E3C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087E40: jal         0x80001D04
    // 0x80087E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80087E48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087E4C: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087E50: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80087E54: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80087E58: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80087E5C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80087E60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087E64: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x80087E68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087E70: beq         $v0, $at, L_80087ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80087E74: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80087ED8;
    }
    // 0x80087E74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087E78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80087E7C: beq         $v0, $at, L_80087E9C
    if (ctx->r2 == ctx->r1) {
        // 0x80087E80: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087E9C;
    }
    // 0x80087E80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087E84: beq         $v0, $at, L_80087F18
    if (ctx->r2 == ctx->r1) {
        // 0x80087E88: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80087F18;
    }
    // 0x80087E88: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80087E8C: beq         $v0, $at, L_80087ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80087E90: nop
    
            goto L_80087ED8;
    }
    // 0x80087E90: nop

    // 0x80087E94: b           L_80087FC4
    // 0x80087E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087FC4;
    // 0x80087E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087E9C:
    // 0x80087E9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087EA0: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x80087EA4: jal         0x8007601C
    // 0x80087EA8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    reformat_controller_pak(rdram, ctx);
        goto after_2;
    // 0x80087EA8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80087EAC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087EB0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087EB4: bne         $t0, $v0, L_80087EC8
    if (ctx->r8 != ctx->r2) {
        // 0x80087EB8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087EC8;
    }
    // 0x80087EB8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087EBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087EC0: b           L_80087FC0
    // 0x80087EC4: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087EC4: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
L_80087EC8:
    // 0x80087EC8: bne         $t0, $at, L_80087FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80087ECC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087FC0;
    }
    // 0x80087ECC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087ED0: b           L_80087FC0
    // 0x80087ED4: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087ED4: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
L_80087ED8:
    // 0x80087ED8: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x80087EDC: jal         0x80075F90
    // 0x80087EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    repair_controller_pak(rdram, ctx);
        goto after_3;
    // 0x80087EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_3:
    // 0x80087EE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087EE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087EEC: bne         $t0, $v0, L_80087F04
    if (ctx->r8 != ctx->r2) {
        // 0x80087EF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80087F04;
    }
    // 0x80087EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087EF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087EFC: b           L_80087FC0
    // 0x80087F00: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
        goto L_80087FC0;
    // 0x80087F00: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
L_80087F04:
    // 0x80087F04: bne         $t0, $at, L_80087FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80087F08: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80087FC0;
    }
    // 0x80087F08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F10: b           L_80087FC0
    // 0x80087F14: sw          $t9, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r25;
        goto L_80087FC0;
    // 0x80087F14: sw          $t9, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r25;
L_80087F18:
    // 0x80087F18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087F1C: bne         $t0, $v0, L_80087F34
    if (ctx->r8 != ctx->r2) {
        // 0x80087F20: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80087F34;
    }
    // 0x80087F20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80087F24: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80087F28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F2C: b           L_80087FC0
    // 0x80087F30: sw          $t2, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r10;
        goto L_80087FC0;
    // 0x80087F30: sw          $t2, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r10;
L_80087F34:
    // 0x80087F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F38: b           L_80087FC0
    // 0x80087F3C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
        goto L_80087FC0;
    // 0x80087F3C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
L_80087F40:
    // 0x80087F40: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80087F44: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80087F48: bgez        $t5, L_80087F88
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80087F4C: nop
    
            goto L_80087F88;
    }
    // 0x80087F4C: nop

    // 0x80087F50: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80087F54: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80087F58: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80087F5C: beq         $at, $zero, L_80087F88
    if (ctx->r1 == 0) {
        // 0x80087F60: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087F88;
    }
    // 0x80087F60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087F64: jal         0x80001D04
    // 0x80087F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80087F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80087F6C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087F70: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087F74: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80087F78: nop

    // 0x80087F7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80087F80: b           L_80087FC0
    // 0x80087F84: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80087FC0;
    // 0x80087F84: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80087F88:
    // 0x80087F88: blez        $t9, L_80087FC4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80087F8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087FC4;
    }
    // 0x80087F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F90: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80087F94: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087F98: blez        $t2, L_80087FC4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80087F9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087FC4;
    }
    // 0x80087F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087FA0: jal         0x80001D04
    // 0x80087FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80087FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80087FA8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087FAC: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087FB0: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80087FB4: nop

    // 0x80087FB8: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x80087FBC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80087FC0:
    // 0x80087FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087FC4:
    // 0x80087FC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087FC8: jr          $ra
    // 0x80087FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void menu_save_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FD0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087FD4: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80087FD8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80087FDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80087FE0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80087FE4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80087FE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80087FEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087FF0: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80087FF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80087FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80087FFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80088000: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80088004: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80088008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008800C: beq         $v0, $zero, L_80088034
    if (ctx->r2 == 0) {
        // 0x80088010: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80088034;
    }
    // 0x80088010: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80088014: blez        $v0, L_8008802C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80088018: subu        $t0, $v0, $s0
        ctx->r8 = SUB32(ctx->r2, ctx->r16);
            goto L_8008802C;
    }
    // 0x80088018: subu        $t0, $v0, $s0
    ctx->r8 = SUB32(ctx->r2, ctx->r16);
    // 0x8008801C: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80088020: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088024: b           L_80088034
    // 0x80088028: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
        goto L_80088034;
    // 0x80088028: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_8008802C:
    // 0x8008802C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088030: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
L_80088034:
    // 0x80088034: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80088038: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x8008803C: nop

    // 0x80088040: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80088044: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80088048: bne         $at, $zero, L_80088058
    if (ctx->r1 != 0) {
        // 0x8008804C: nop
    
            goto L_80088058;
    }
    // 0x8008804C: nop

    // 0x80088050: jal         0x80086E88
    // 0x80088054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_move(rdram, ctx);
        goto after_0;
    // 0x80088054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80088058:
    // 0x80088058: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008805C: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80088060: nop

    // 0x80088064: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80088068: bne         $at, $zero, L_8008808C
    if (ctx->r1 != 0) {
        // 0x8008806C: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_8008808C;
    }
    // 0x8008806C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80088070: beq         $at, $zero, L_8008808C
    if (ctx->r1 == 0) {
        // 0x80088074: nop
    
            goto L_8008808C;
    }
    // 0x80088074: nop

    // 0x80088078: jal         0x80085FDC
    // 0x8008807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_render(rdram, ctx);
        goto after_1;
    // 0x8008807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80088080: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80088084: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80088088: nop

L_8008808C:
    // 0x8008808C: beq         $v0, $zero, L_800880DC
    if (ctx->r2 == 0) {
        // 0x80088090: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800880DC;
    }
    // 0x80088090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088094: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80088098: bne         $at, $zero, L_800880BC
    if (ctx->r1 != 0) {
        // 0x8008809C: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800880BC;
    }
    // 0x8008809C: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800880A0: jal         0x80088328
    // 0x800880A4: nop

    savemenu_free(rdram, ctx);
        goto after_2;
    // 0x800880A4: nop

    after_2:
    // 0x800880A8: jal         0x80081820
    // 0x800880AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    menu_init(rdram, ctx);
        goto after_3;
    // 0x800880AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x800880B0: b           L_80088308
    // 0x800880B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80088308;
    // 0x800880B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800880B8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_800880BC:
    // 0x800880BC: beq         $at, $zero, L_800880D4
    if (ctx->r1 == 0) {
        // 0x800880C0: nop
    
            goto L_800880D4;
    }
    // 0x800880C0: nop

    // 0x800880C4: jal         0x80088328
    // 0x800880C8: nop

    savemenu_free(rdram, ctx);
        goto after_4;
    // 0x800880C8: nop

    after_4:
    // 0x800880CC: jal         0x80081820
    // 0x800880D0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x800880D0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
L_800880D4:
    // 0x800880D4: b           L_80088308
    // 0x800880D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80088308;
    // 0x800880D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800880DC:
    // 0x800880DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800880E0: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x800880E4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800880E8: bne         $t3, $zero, L_8008813C
    if (ctx->r11 != 0) {
        // 0x800880EC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8008813C;
    }
    // 0x800880EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800880F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800880F4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800880F8: addiu       $s2, $s2, 0x6A04
    ctx->r18 = ADD32(ctx->r18, 0X6A04);
    // 0x800880FC: addiu       $s1, $s1, 0x69FC
    ctx->r17 = ADD32(ctx->r17, 0X69FC);
    // 0x80088100: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80088104:
    // 0x80088104: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x80088108: lb          $t5, 0x0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X0);
    // 0x8008810C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80088110: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80088114: addu        $s4, $s4, $t4
    ctx->r20 = ADD32(ctx->r20, ctx->r12);
    // 0x80088118: jal         0x8006A794
    // 0x8008811C: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8008811C: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    after_6:
    // 0x80088120: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80088124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088128: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008812C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80088130: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80088134: bne         $s0, $at, L_80088104
    if (ctx->r16 != ctx->r1) {
        // 0x80088138: or          $a2, $a2, $v0
        ctx->r6 = ctx->r6 | ctx->r2;
            goto L_80088104;
    }
    // 0x80088138: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_8008813C:
    // 0x8008813C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088140: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x80088144: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088148: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x8008814C: beq         $t6, $zero, L_80088168
    if (ctx->r14 == 0) {
        // 0x80088150: sltiu       $at, $v0, 0x8
        ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
            goto L_80088168;
    }
    // 0x80088150: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80088154: jal         0x80087BA4
    // 0x80088158: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    savemenu_input_message(rdram, ctx);
        goto after_7;
    // 0x80088158: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x8008815C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088160: b           L_800882FC
    // 0x80088164: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882FC;
    // 0x80088164: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_80088168:
    // 0x80088168: beq         $at, $zero, L_800882E0
    if (ctx->r1 == 0) {
        // 0x8008816C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800882E0;
    }
    // 0x8008816C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80088170: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088174: addu        $at, $at, $t7
    gpr jr_addend_80088180 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80088178: lw          $t7, -0x75C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X75C0);
    // 0x8008817C: nop

    // 0x80088180: jr          $t7
    // 0x80088184: nop

    switch (jr_addend_80088180 >> 2) {
        case 0: goto L_80088188; break;
        case 1: goto L_80088198; break;
        case 2: goto L_800881C4; break;
        case 3: goto L_80088204; break;
        case 4: goto L_8008821C; break;
        case 5: goto L_8008825C; break;
        case 6: goto L_80088274; break;
        case 7: goto L_8008828C; break;
        default: switch_error(__func__, 0x80088180, 0x800E8A40);
    }
    // 0x80088184: nop

L_80088188:
    // 0x80088188: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008818C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088190: b           L_800882E0
    // 0x80088194: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
        goto L_800882E0;
    // 0x80088194: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
L_80088198:
    // 0x80088198: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008819C: addiu       $s0, $s0, 0x6978
    ctx->r16 = ADD32(ctx->r16, 0X6978);
    // 0x800881A0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800881A4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800881A8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800881AC: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x800881B0: bne         $at, $zero, L_800882E0
    if (ctx->r1 != 0) {
        // 0x800881B4: sw          $t0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r8;
            goto L_800882E0;
    }
    // 0x800881B4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800881B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881BC: b           L_800882E0
    // 0x800881C0: sw          $t2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r10;
        goto L_800882E0;
    // 0x800881C0: sw          $t2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r10;
L_800881C4:
    // 0x800881C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800881CC: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x800881D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881D4: jal         0x80086704
    // 0x800881D8: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
    savemenu_load_sources(rdram, ctx);
        goto after_8;
    // 0x800881D8: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
    after_8:
    // 0x800881DC: beq         $v0, $zero, L_800881F4
    if (ctx->r2 == 0) {
        // 0x800881E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800881F4;
    }
    // 0x800881E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800881E4: jal         0x80087648
    // 0x800881E8: nop

    savemenu_render_error(rdram, ctx);
        goto after_9;
    // 0x800881E8: nop

    after_9:
    // 0x800881EC: b           L_800882E0
    // 0x800881F0: nop

        goto L_800882E0;
    // 0x800881F0: nop

L_800881F4:
    // 0x800881F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800881F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881FC: b           L_800882E0
    // 0x80088200: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
        goto L_800882E0;
    // 0x80088200: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
L_80088204:
    // 0x80088204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088208: jal         0x80087940
    // 0x8008820C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_source(rdram, ctx);
        goto after_10;
    // 0x8008820C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80088210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088214: b           L_800882E0
    // 0x80088218: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088218: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_8008821C:
    // 0x8008821C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088220: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80088224: sw          $zero, 0x71A4($at)
    MEM_W(0X71A4, ctx->r1) = 0;
    // 0x80088228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008822C: jal         0x80086C14
    // 0x80088230: swc1        $f6, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f6.u32l;
    savemenu_load_destinations(rdram, ctx);
        goto after_11;
    // 0x80088230: swc1        $f6, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f6.u32l;
    after_11:
    // 0x80088234: beq         $v0, $zero, L_8008824C
    if (ctx->r2 == 0) {
        // 0x80088238: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8008824C;
    }
    // 0x80088238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008823C: jal         0x80087648
    // 0x80088240: nop

    savemenu_render_error(rdram, ctx);
        goto after_12;
    // 0x80088240: nop

    after_12:
    // 0x80088244: b           L_800882E0
    // 0x80088248: nop

        goto L_800882E0;
    // 0x80088248: nop

L_8008824C:
    // 0x8008824C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80088250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088254: b           L_800882E0
    // 0x80088258: sw          $t4, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r12;
        goto L_800882E0;
    // 0x80088258: sw          $t4, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r12;
L_8008825C:
    // 0x8008825C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088260: jal         0x80087A54
    // 0x80088264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_dest(rdram, ctx);
        goto after_13;
    // 0x80088264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_13:
    // 0x80088268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008826C: b           L_800882E0
    // 0x80088270: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088270: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_80088274:
    // 0x80088274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088278: jal         0x80087B3C
    // 0x8008827C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_confirm(rdram, ctx);
        goto after_14;
    // 0x8008827C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_14:
    // 0x80088280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088284: b           L_800882E0
    // 0x80088288: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088288: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_8008828C:
    // 0x8008828C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80088290: addiu       $s0, $s0, 0x6978
    ctx->r16 = ADD32(ctx->r16, 0X6978);
    // 0x80088294: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80088298: nop

    // 0x8008829C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800882A0: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800882A4: bne         $at, $zero, L_800882E0
    if (ctx->r1 != 0) {
        // 0x800882A8: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_800882E0;
    }
    // 0x800882A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800882AC: jal         0x80086F3C
    // 0x800882B0: nop

    savemenu_write(rdram, ctx);
        goto after_15;
    // 0x800882B0: nop

    after_15:
    // 0x800882B4: beq         $v0, $zero, L_800882CC
    if (ctx->r2 == 0) {
        // 0x800882B8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800882CC;
    }
    // 0x800882B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800882BC: jal         0x80087648
    // 0x800882C0: nop

    savemenu_render_error(rdram, ctx);
        goto after_16;
    // 0x800882C0: nop

    after_16:
    // 0x800882C4: b           L_800882E0
    // 0x800882C8: nop

        goto L_800882E0;
    // 0x800882C8: nop

L_800882CC:
    // 0x800882CC: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800882D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800882D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800882D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800882DC: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_800882E0:
    // 0x800882E0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800882E4: lw          $t0, -0x604($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X604);
    // 0x800882E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800882EC: beq         $t0, $zero, L_800882FC
    if (ctx->r8 == 0) {
        // 0x800882F0: nop
    
            goto L_800882FC;
    }
    // 0x800882F0: nop

    // 0x800882F4: jal         0x800C06F8
    // 0x800882F8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x800882F8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_17:
L_800882FC:
    // 0x800882FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088300: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80088304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80088308:
    // 0x80088308: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008830C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80088310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80088314: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80088318: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008831C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80088320: jr          $ra
    // 0x80088324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80088324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void savemenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008832C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088330: jal         0x800C478C
    // 0x80088334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80088334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80088338: jal         0x800803D8
    // 0x8008833C: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008833C: nop

    after_1:
    // 0x80088340: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088344: jal         0x8009C9EC
    // 0x80088348: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    menu_assetgroup_free(rdram, ctx);
        goto after_2;
    // 0x80088348: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    after_2:
    // 0x8008834C: jal         0x800C59F4
    // 0x80088350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80088350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80088354: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088358: lw          $a0, 0x6FCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8008835C: jal         0x80071380
    // 0x80088360: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80088360: nop

    after_4:
    // 0x80088364: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088368: lw          $a0, 0x7024($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7024);
    // 0x8008836C: jal         0x80071380
    // 0x80088370: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80088370: nop

    after_5:
    // 0x80088374: jal         0x800724D8
    // 0x80088378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_enable(rdram, ctx);
        goto after_6;
    // 0x80088378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8008837C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088384: jr          $ra
    // 0x80088388: nop

    return;
    // 0x80088388: nop

;}
RECOMP_FUNC void func_80087F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008838C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80088390: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80088394: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80088398: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008839C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800883A0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800883A4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800883A8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800883AC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800883B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800883B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800883B8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800883BC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800883C0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800883C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800883C8: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800883CC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800883D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800883D4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800883D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800883DC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800883E0: addiu       $s4, $s4, 0x6FFC
    ctx->r20 = ADD32(ctx->r20, 0X6FFC);
    // 0x800883E4: addiu       $s3, $s3, 0x6FF8
    ctx->r19 = ADD32(ctx->r19, 0X6FF8);
    // 0x800883E8: addiu       $s2, $s2, 0x6FF4
    ctx->r18 = ADD32(ctx->r18, 0X6FF4);
    // 0x800883EC: addiu       $s0, $s0, 0x6FF0
    ctx->r16 = ADD32(ctx->r16, 0X6FF0);
    // 0x800883F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800883F4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800883F8:
    // 0x800883F8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800883FC: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x80088400: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x80088404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80088408: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8008840C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80088410: jal         0x800763EC
    // 0x80088414: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x80088414: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_0:
    // 0x80088418: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8008841C: bne         $v0, $zero, L_80088468
    if (ctx->r2 != 0) {
        // 0x80088420: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80088468;
    }
    // 0x80088420: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80088424: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80088428: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8008842C: beq         $t6, $zero, L_80088444
    if (ctx->r14 == 0) {
        // 0x80088430: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80088444;
    }
    // 0x80088430: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088434: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80088438: nop

    // 0x8008843C: bne         $t7, $zero, L_80088460
    if (ctx->r15 != 0) {
        // 0x80088440: nop
    
            goto L_80088460;
    }
    // 0x80088440: nop

L_80088444:
    // 0x80088444: sb          $s5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r21;
    // 0x80088448: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8008844C: lbu         $t8, 0x7020($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7020);
    // 0x80088450: nop

    // 0x80088454: bne         $t8, $zero, L_80088460
    if (ctx->r24 != 0) {
        // 0x80088458: nop
    
            goto L_80088460;
    }
    // 0x80088458: nop

    // 0x8008845C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80088460:
    // 0x80088460: b           L_800884B4
    // 0x80088464: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_800884B4;
    // 0x80088464: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_80088468:
    // 0x80088468: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008846C: bne         $t2, $at, L_8008847C
    if (ctx->r10 != ctx->r1) {
        // 0x80088470: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8008847C;
    }
    // 0x80088470: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80088474: sb          $s5, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r21;
    // 0x80088478: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008847C:
    // 0x8008847C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088480: bne         $t2, $at, L_800884A0
    if (ctx->r10 != ctx->r1) {
        // 0x80088484: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800884A0;
    }
    // 0x80088484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80088488: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8008848C: jal         0x80075F90
    // 0x80088490: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    repair_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80088490: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_1:
    // 0x80088494: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80088498: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8008849C: nop

L_800884A0:
    // 0x800884A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800884A4: bne         $t2, $at, L_800884B4
    if (ctx->r10 != ctx->r1) {
        // 0x800884A8: nop
    
            goto L_800884B4;
    }
    // 0x800884A8: nop

    // 0x800884AC: sb          $s5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r21;
    // 0x800884B0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800884B4:
    // 0x800884B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800884B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800884BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800884C0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800884C4: blez        $s1, L_800883F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800884C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800883F8;
    }
    // 0x800884C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800884CC: beq         $fp, $zero, L_800884EC
    if (ctx->r30 == 0) {
        // 0x800884D0: nop
    
            goto L_800884EC;
    }
    // 0x800884D0: nop

    // 0x800884D4: bne         $s6, $zero, L_800884EC
    if (ctx->r22 != 0) {
        // 0x800884D8: nop
    
            goto L_800884EC;
    }
    // 0x800884D8: nop

    // 0x800884DC: bne         $s7, $zero, L_800884EC
    if (ctx->r23 != 0) {
        // 0x800884E0: nop
    
            goto L_800884EC;
    }
    // 0x800884E0: nop

    // 0x800884E4: beq         $v1, $zero, L_800884F4
    if (ctx->r3 == 0) {
        // 0x800884E8: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_800884F4;
    }
    // 0x800884E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_800884EC:
    // 0x800884EC: b           L_80088774
    // 0x800884F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80088774;
    // 0x800884F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800884F4:
    // 0x800884F4: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800884F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800884FC: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80088500: addiu       $a2, $a2, 0x70A0
    ctx->r6 = ADD32(ctx->r6, 0X70A0);
    // 0x80088504: bgez        $v0, L_80088544
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088508: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80088544;
    }
    // 0x80088508: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008850C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80088510: addiu       $t6, $t6, 0x6FF0
    ctx->r14 = ADD32(ctx->r14, 0X6FF0);
    // 0x80088514: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_80088518:
    // 0x80088518: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008851C: blez        $s1, L_8008852C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80088520: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8008852C;
    }
    // 0x80088520: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088524: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088528: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8008852C:
    // 0x8008852C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80088530: nop

    // 0x80088534: beq         $t7, $zero, L_80088518
    if (ctx->r15 == 0) {
        // 0x80088538: nop
    
            goto L_80088518;
    }
    // 0x80088538: nop

    // 0x8008853C: b           L_800885D0
    // 0x80088540: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_800885D0;
    // 0x80088540: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_80088544:
    // 0x80088544: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088548: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8008854C: lbu         $t8, 0x6FF0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6FF0);
    // 0x80088550: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80088554: beq         $t8, $zero, L_80088560
    if (ctx->r24 == 0) {
        // 0x80088558: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80088560;
    }
    // 0x80088558: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008855C: blez        $t9, L_80088594
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80088560: addiu       $t6, $t6, 0x6FF0
        ctx->r14 = ADD32(ctx->r14, 0X6FF0);
            goto L_80088594;
    }
L_80088560:
    // 0x80088560: addiu       $t6, $t6, 0x6FF0
    ctx->r14 = ADD32(ctx->r14, 0X6FF0);
    // 0x80088564: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_80088568:
    // 0x80088568: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008856C: blez        $s1, L_8008857C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80088570: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8008857C;
    }
    // 0x80088570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088574: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088578: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8008857C:
    // 0x8008857C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80088580: nop

    // 0x80088584: beq         $t7, $zero, L_80088568
    if (ctx->r15 == 0) {
        // 0x80088588: nop
    
            goto L_80088568;
    }
    // 0x80088588: nop

    // 0x8008858C: b           L_800885D0
    // 0x80088590: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_800885D0;
    // 0x80088590: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_80088594:
    // 0x80088594: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80088598: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008859C: bgez        $t8, L_800885CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800885A0: addiu       $t9, $t9, 0x6FF0
        ctx->r25 = ADD32(ctx->r25, 0X6FF0);
            goto L_800885CC;
    }
    // 0x800885A0: addiu       $t9, $t9, 0x6FF0
    ctx->r25 = ADD32(ctx->r25, 0X6FF0);
    // 0x800885A4: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
L_800885A8:
    // 0x800885A8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800885AC: bgez        $s1, L_800885BC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800885B0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800885BC;
    }
    // 0x800885B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800885B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800885B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800885BC:
    // 0x800885BC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800885C0: nop

    // 0x800885C4: beq         $t6, $zero, L_800885A8
    if (ctx->r14 == 0) {
        // 0x800885C8: nop
    
            goto L_800885A8;
    }
    // 0x800885C8: nop

L_800885CC:
    // 0x800885CC: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_800885D0:
    // 0x800885D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800885D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800885D8: addiu       $t9, $t9, 0x7120
    ctx->r25 = ADD32(ctx->r25, 0X7120);
    // 0x800885DC: addiu       $t8, $t8, 0x7130
    ctx->r24 = ADD32(ctx->r24, 0X7130);
    // 0x800885E0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800885E4: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x800885E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800885EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800885F0: addiu       $a3, $a3, 0x70E0
    ctx->r7 = ADD32(ctx->r7, 0X70E0);
    // 0x800885F4: jal         0x800760B8
    // 0x800885F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x800885F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800885FC: bne         $v0, $zero, L_80088770
    if (ctx->r2 != 0) {
        // 0x80088600: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80088770;
    }
    // 0x80088600: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80088604: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80088608: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008860C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088610: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80088614: addiu       $ra, $ra, 0x70A0
    ctx->r31 = ADD32(ctx->r31, 0X70A0);
    // 0x80088618: addiu       $a1, $a1, 0x7060
    ctx->r5 = ADD32(ctx->r5, 0X7060);
    // 0x8008861C: addiu       $t0, $t0, 0x70A0
    ctx->r8 = ADD32(ctx->r8, 0X70A0);
    // 0x80088620: addiu       $t1, $t1, 0x7130
    ctx->r9 = ADD32(ctx->r9, 0X7130);
    // 0x80088624: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80088628: addiu       $t5, $zero, 0x2D
    ctx->r13 = ADD32(0, 0X2D);
    // 0x8008862C: addiu       $t4, $zero, 0x2E
    ctx->r12 = ADD32(0, 0X2E);
L_80088630:
    // 0x80088630: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80088634: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x80088638: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x8008863C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80088640: beq         $a3, $zero, L_80088704
    if (ctx->r7 == 0) {
        // 0x80088644: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80088704;
    }
    // 0x80088644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088648: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8008864C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088650: addiu       $t8, $t8, 0x70E0
    ctx->r24 = ADD32(ctx->r24, 0X70E0);
    // 0x80088654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088658: beq         $t9, $zero, L_80088690
    if (ctx->r25 == 0) {
        // 0x8008865C: addu        $a2, $t3, $t8
        ctx->r6 = ADD32(ctx->r11, ctx->r24);
            goto L_80088690;
    }
    // 0x8008865C: addu        $a2, $t3, $t8
    ctx->r6 = ADD32(ctx->r11, ctx->r24);
    // 0x80088660: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_80088664:
    // 0x80088664: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088668: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008866C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80088670: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x80088674: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80088678: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008867C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80088680: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80088684: nop

    // 0x80088688: bne         $v1, $zero, L_80088664
    if (ctx->r3 != 0) {
        // 0x8008868C: nop
    
            goto L_80088664;
    }
    // 0x8008868C: nop

L_80088690:
    // 0x80088690: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80088694: nop

    // 0x80088698: beq         $a3, $zero, L_80088704
    if (ctx->r7 == 0) {
        // 0x8008869C: nop
    
            goto L_80088704;
    }
    // 0x8008869C: nop

    // 0x800886A0: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800886A4: nop

    // 0x800886A8: beq         $t6, $zero, L_80088704
    if (ctx->r14 == 0) {
        // 0x800886AC: nop
    
            goto L_80088704;
    }
    // 0x800886AC: nop

    // 0x800886B0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800886B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800886B8: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800886BC: sb          $t4, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r12;
    // 0x800886C0: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800886C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800886C8: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800886CC: nop

    // 0x800886D0: beq         $t9, $zero, L_80088704
    if (ctx->r25 == 0) {
        // 0x800886D4: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_80088704;
    }
    // 0x800886D4: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_800886D8:
    // 0x800886D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800886DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800886E0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800886E4: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x800886E8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800886EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800886F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800886F4: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800886F8: nop

    // 0x800886FC: bne         $v1, $zero, L_800886D8
    if (ctx->r3 != 0) {
        // 0x80088700: nop
    
            goto L_800886D8;
    }
    // 0x80088700: nop

L_80088704:
    // 0x80088704: bne         $a0, $zero, L_80088720
    if (ctx->r4 != 0) {
        // 0x80088708: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80088720;
    }
    // 0x80088708: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8008870C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088710: nop

    // 0x80088714: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80088718: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x8008871C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80088720:
    // 0x80088720: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80088724: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80088728: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8008872C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80088730: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80088734: bne         $a1, $ra, L_80088630
    if (ctx->r5 != ctx->r31) {
        // 0x80088738: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_80088630;
    }
    // 0x80088738: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8008873C: jal         0x800763BC
    // 0x80088740: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    cpak_free_files(rdram, ctx);
        goto after_3;
    // 0x80088740: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_3:
    // 0x80088744: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80088748: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008874C: addiu       $s0, $s0, 0x7170
    ctx->r16 = ADD32(ctx->r16, 0X7170);
    // 0x80088750: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80088754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80088758: jal         0x800763EC
    // 0x8008875C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_free_space(rdram, ctx);
        goto after_4;
    // 0x8008875C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80088760: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80088764: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80088768: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x8008876C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_80088770:
    // 0x80088770: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80088774:
    // 0x80088774: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80088778: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008877C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80088780: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80088784: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80088788: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008878C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80088790: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80088794: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80088798: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008879C: jr          $ra
    // 0x800887A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800887A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void check_for_controller_pak_errors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887A4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800887A8: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800887AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800887B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800887B4: addiu       $a3, $a3, 0x7188
    ctx->r7 = ADD32(ctx->r7, 0X7188);
    // 0x800887B8: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800887BC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800887C0: addiu       $t6, $t6, 0x6FF4
    ctx->r14 = ADD32(ctx->r14, 0X6FF4);
    // 0x800887C4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800887C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800887CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800887D0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800887D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800887D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800887DC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800887E0: addiu       $t0, $t0, 0x234
    ctx->r8 = ADD32(ctx->r8, 0X234);
    // 0x800887E4: addiu       $t1, $t1, -0x5E0
    ctx->r9 = ADD32(ctx->r9, -0X5E0);
    // 0x800887E8: addiu       $t3, $t3, 0x6FF8
    ctx->r11 = ADD32(ctx->r11, 0X6FF8);
    // 0x800887EC: addiu       $t4, $t4, 0x7020
    ctx->r12 = ADD32(ctx->r12, 0X7020);
    // 0x800887F0: addiu       $s1, $s1, 0x6FFC
    ctx->r17 = ADD32(ctx->r17, 0X6FFC);
    // 0x800887F4: addu        $a0, $zero, $t6
    ctx->r4 = ADD32(0, ctx->r14);
    // 0x800887F8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800887FC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80088800: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80088804: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80088808: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8008880C:
    // 0x8008880C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80088810: nop

    // 0x80088814: beq         $t7, $zero, L_80088874
    if (ctx->r15 == 0) {
        // 0x80088818: addu        $t8, $t3, $v1
        ctx->r24 = ADD32(ctx->r11, ctx->r3);
            goto L_80088874;
    }
    // 0x80088818: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
    // 0x8008881C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088820: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80088824: lw          $t8, 0x100($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X100);
    // 0x80088828: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8008882C: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x80088830: lw          $t9, 0x100($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X100);
    // 0x80088834: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80088838: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x8008883C: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x80088840: nop

    // 0x80088844: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x80088848: lw          $t9, 0x17C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X17C);
    // 0x8008884C: nop

    // 0x80088850: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x80088854: lw          $t6, 0x28C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28C);
    // 0x80088858: nop

    // 0x8008885C: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
    // 0x80088860: lw          $t7, 0x290($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X290);
    // 0x80088864: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80088868: b           L_80088940
    // 0x8008886C: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
        goto L_80088940;
    // 0x8008886C: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
    // 0x80088870: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
L_80088874:
    // 0x80088874: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80088878: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    // 0x8008887C: beq         $t9, $zero, L_800888E8
    if (ctx->r25 == 0) {
        // 0x80088880: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_800888E8;
    }
    // 0x80088880: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x80088884: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80088888: nop

    // 0x8008888C: bne         $t6, $zero, L_800888E8
    if (ctx->r14 != 0) {
        // 0x80088890: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_800888E8;
    }
    // 0x80088890: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x80088894: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088898: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8008889C: lw          $t7, 0x260($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X260);
    // 0x800888A0: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800888A4: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x800888A8: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x800888AC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800888B0: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800888B4: lw          $t7, 0x158($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X158);
    // 0x800888B8: nop

    // 0x800888BC: sw          $t7, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r15;
    // 0x800888C0: lw          $t8, 0x110($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X110);
    // 0x800888C4: nop

    // 0x800888C8: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
    // 0x800888CC: lw          $t9, 0x188($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X188);
    // 0x800888D0: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x800888D4: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x800888D8: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x800888DC: b           L_80088940
    // 0x800888E0: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
        goto L_80088940;
    // 0x800888E0: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
    // 0x800888E4: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_800888E8:
    // 0x800888E8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800888EC: nop

    // 0x800888F0: beq         $t7, $zero, L_80088940
    if (ctx->r15 == 0) {
        // 0x800888F4: nop
    
            goto L_80088940;
    }
    // 0x800888F4: nop

    // 0x800888F8: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800888FC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80088900: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x80088904: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80088908: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x8008890C: lw          $t9, 0x260($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X260);
    // 0x80088910: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80088914: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80088918: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x8008891C: nop

    // 0x80088920: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x80088924: lw          $t9, 0x2E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2E0);
    // 0x80088928: nop

    // 0x8008892C: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x80088930: lw          $t6, 0x2E4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2E4);
    // 0x80088934: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x80088938: sw          $s2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r18;
    // 0x8008893C: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
L_80088940:
    // 0x80088940: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80088944: bgtz        $v1, L_80088954
    if (SIGNED(ctx->r3) > 0) {
        // 0x80088948: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80088954;
    }
    // 0x80088948: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008894C: beq         $v0, $zero, L_8008880C
    if (ctx->r2 == 0) {
        // 0x80088950: nop
    
            goto L_8008880C;
    }
    // 0x80088950: nop

L_80088954:
    // 0x80088954: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80088958: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8008895C: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80088960: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80088964: jr          $ra
    // 0x80088968: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80088968: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void menu_boot_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008896C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088974: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088978: jal         0x800C06F8
    // 0x8008897C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008897C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x80088980: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088988: jal         0x80077F84
    // 0x8008898C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x8008898C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80088990: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088994: jal         0x8009CBB8
    // 0x80088998: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80088998: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_2:
    // 0x8008899C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800889A0: lh          $t6, -0x2BC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2BC);
    // 0x800889A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800889A8: addiu       $a0, $a0, 0x6AF0
    ctx->r4 = ADD32(ctx->r4, 0X6AF0);
    // 0x800889AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800889B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800889B4: lh          $t0, -0x2BA($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2BA);
    // 0x800889B8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800889BC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800889C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800889C4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800889C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800889CC: lh          $t4, -0x2B8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2B8);
    // 0x800889D0: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800889D4: sw          $t9, -0x2A4($at)
    MEM_W(-0X2A4, ctx->r1) = ctx->r25;
    // 0x800889D8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800889DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800889E0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800889E4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800889E8: sw          $t3, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = ctx->r11;
    // 0x800889EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800889F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800889F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800889F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800889FC: addiu       $a1, $a1, -0x2A6
    ctx->r5 = ADD32(ctx->r5, -0X2A6);
    // 0x80088A00: addiu       $v0, $v0, -0x2B6
    ctx->r2 = ADD32(ctx->r2, -0X2B6);
    // 0x80088A04: addiu       $v1, $v1, -0x28C
    ctx->r3 = ADD32(ctx->r3, -0X28C);
    // 0x80088A08: sw          $t7, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r15;
L_80088A0C:
    // 0x80088A0C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80088A10: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80088A14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088A18: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80088A1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80088A20: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x80088A24: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80088A28: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80088A2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80088A30: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80088A34: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80088A38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80088A3C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80088A40: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80088A44: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80088A48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80088A4C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80088A50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80088A54: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80088A58: sw          $t5, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r13;
    // 0x80088A5C: sw          $t3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r11;
    // 0x80088A60: bne         $v0, $a1, L_80088A0C
    if (ctx->r2 != ctx->r5) {
        // 0x80088A64: sw          $t9, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r25;
            goto L_80088A0C;
    }
    // 0x80088A64: sw          $t9, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r25;
    // 0x80088A68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088A70: sw          $zero, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = 0;
    // 0x80088A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088A78: sw          $zero, 0x71D8($at)
    MEM_W(0X71D8, ctx->r1) = 0;
    // 0x80088A7C: jr          $ra
    // 0x80088A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80088A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_boot_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80088A88: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80088A8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80088A90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80088A94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80088A98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80088A9C: bne         $t6, $zero, L_80088AA8
    if (ctx->r14 != 0) {
        // 0x80088AA0: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_80088AA8;
    }
    // 0x80088AA0: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x80088AA4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_80088AA8:
    // 0x80088AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088AAC: lw          $v0, 0x71E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71E0);
    // 0x80088AB0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80088AB4: beq         $v0, $zero, L_80088ADC
    if (ctx->r2 == 0) {
        // 0x80088AB8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088ADC;
    }
    // 0x80088AB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088AC0: beq         $v0, $at, L_80088B28
    if (ctx->r2 == ctx->r1) {
        // 0x80088AC4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088B28;
    }
    // 0x80088AC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088ACC: beq         $v0, $at, L_80088B90
    if (ctx->r2 == ctx->r1) {
        // 0x80088AD0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80088B90;
    }
    // 0x80088AD0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80088AD4: b           L_80088BE4
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
        goto L_80088BE4;
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088ADC:
    // 0x80088ADC: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088AE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088AE4: nop

    // 0x80088AE8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80088AEC: beq         $at, $zero, L_80088B0C
    if (ctx->r1 == 0) {
        // 0x80088AF0: addu        $t7, $v0, $a1
        ctx->r15 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B0C;
    }
    // 0x80088AF0: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80088AF4: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x80088AF8: bne         $at, $zero, L_80088BE0
    if (ctx->r1 != 0) {
        // 0x80088AFC: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80088BE0;
    }
    // 0x80088AFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80088B00: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80088B04: b           L_80088BE0
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80088BE0;
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80088B0C:
    // 0x80088B0C: jal         0x80088C60
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_init_cpak(rdram, ctx);
        goto after_0;
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80088B14: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088B1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B20: b           L_80088BE0
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
        goto L_80088BE0;
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
L_80088B28:
    // 0x80088B28: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088B2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088B30: nop

    // 0x80088B34: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80088B38: beq         $at, $zero, L_80088B5C
    if (ctx->r1 == 0) {
        // 0x80088B3C: addu        $t1, $v0, $a1
        ctx->r9 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B5C;
    }
    // 0x80088B3C: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
    // 0x80088B40: slti        $at, $t1, 0x8D
    ctx->r1 = SIGNED(ctx->r9) < 0X8D ? 1 : 0;
    // 0x80088B44: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80088B48: bne         $at, $zero, L_80088B7C
    if (ctx->r1 != 0) {
        // 0x80088B4C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80088B7C;
    }
    // 0x80088B4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80088B50: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x80088B54: b           L_80088B7C
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80088B7C;
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80088B5C:
    // 0x80088B5C: jal         0x80088C3C
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_free(rdram, ctx);
        goto after_1;
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80088B64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088B68: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80088B6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B70: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B74: lw          $v0, 0x71D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71D8);
    // 0x80088B78: sw          $t3, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r11;
L_80088B7C:
    // 0x80088B7C: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80088B80: bne         $at, $zero, L_80088BE4
    if (ctx->r1 != 0) {
        // 0x80088B84: slti        $at, $a3, 0x12C
        ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
            goto L_80088BE4;
    }
    // 0x80088B84: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x80088B88: b           L_80088BE0
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
        goto L_80088BE0;
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088B90:
    // 0x80088B90: lw          $t4, -0x604($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X604);
    // 0x80088B94: nop

    // 0x80088B98: beq         $t4, $zero, L_80088BCC
    if (ctx->r12 == 0) {
        // 0x80088B9C: addiu       $a3, $zero, 0x12C
        ctx->r7 = ADD32(0, 0X12C);
            goto L_80088BCC;
    }
    // 0x80088B9C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80088BA0: jal         0x800C06AC
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    check_fadeout_transition(rdram, ctx);
        goto after_2;
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_2:
    // 0x80088BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BAC: bne         $v0, $zero, L_80088BC8
    if (ctx->r2 != 0) {
        // 0x80088BB0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80088BC8;
    }
    // 0x80088BB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088BB4: addiu       $a0, $a0, -0x314
    ctx->r4 = ADD32(ctx->r4, -0X314);
    // 0x80088BB8: jal         0x800C06F8
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x80088BC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BC4: nop

L_80088BC8:
    // 0x80088BC8: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088BCC:
    // 0x80088BCC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80088BD0: jal         0x80089540
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    menu_controller_pak_loop(rdram, ctx);
        goto after_4;
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80088BD8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088BDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80088BE0:
    // 0x80088BE0: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088BE4:
    // 0x80088BE4: beq         $at, $zero, L_80088C2C
    if (ctx->r1 == 0) {
        // 0x80088BE8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80088C2C;
    }
    // 0x80088BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088BEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088BF0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80088BF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088BF8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80088BFC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088C00: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80088C04: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80088C08: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80088C0C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088C10: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80088C14: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088C18: jal         0x80078F08
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_5:
    // 0x80088C20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088C24: jal         0x8007B820
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_6:
L_80088C2C:
    // 0x80088C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088C30: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80088C34: jr          $ra
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
