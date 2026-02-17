#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void level_properties_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C524: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C528: jr          $ra
    // 0x8006C52C: sh          $zero, -0x2768($at)
    MEM_H(-0X2768, ctx->r1) = 0;
    return;
    // 0x8006C52C: sh          $zero, -0x2768($at)
    MEM_H(-0X2768, ctx->r1) = 0;
;}
RECOMP_FUNC void level_properties_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C530: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C534: lh          $v0, -0x2768($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2768);
    // 0x8006C538: jr          $ra
    // 0x8006C53C: nop

    return;
    // 0x8006C53C: nop

;}
RECOMP_FUNC void func_8006C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C544: addiu       $a0, $a0, -0x2760
    ctx->r4 = ADD32(ctx->r4, -0X2760);
    // 0x8006C548: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006C54C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C550: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006C554: bne         $at, $zero, L_8006C564
    if (ctx->r1 != 0) {
        // 0x8006C558: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006C564;
    }
    // 0x8006C558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C55C: jr          $ra
    // 0x8006C560: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8006C560: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8006C564:
    // 0x8006C564: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006C568: jr          $ra
    // 0x8006C56C: nop

    return;
    // 0x8006C56C: nop

;}
RECOMP_FUNC void thread3_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C578: jal         0x8006C620
    // 0x8006C57C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    init_game(rdram, ctx);
        goto after_0;
    // 0x8006C57C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C580: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C584: lw          $a0, -0x2714($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2714);
    // 0x8006C588: jal         0x8006A404
    // 0x8006C58C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    input_update(rdram, ctx);
        goto after_1;
    // 0x8006C58C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8006C590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C594: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    // 0x8006C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C59C: sw          $zero, 0x3AA0($at)
    MEM_W(0X3AA0, ctx->r1) = 0;
    // 0x8006C5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C5A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006C5A8: sw          $t6, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r14;
L_8006C5AC:
    // 0x8006C5AC: jal         0x8006ED00
    // 0x8006C5B0: nop

    is_reset_pressed(rdram, ctx);
        goto after_2;
    // 0x8006C5B0: nop

    after_2:
    // 0x8006C5B4: beq         $v0, $zero, L_8006C5F0
    if (ctx->r2 == 0) {
        // 0x8006C5B8: nop
    
            goto L_8006C5F0;
    }
    // 0x8006C5B8: nop

    // 0x8006C5BC: jal         0x80072954
    // 0x8006C5C0: nop

    rumble_kill(rdram, ctx);
        goto after_3;
    // 0x8006C5C0: nop

    after_3:
    // 0x8006C5C4: jal         0x80002A74
    // 0x8006C5C8: nop

    audioStopThread(rdram, ctx);
        goto after_4;
    // 0x8006C5C8: nop

    after_4:
    // 0x8006C5CC: jal         0x800C791C
    // 0x8006C5D0: nop

    bgload_kill(rdram, ctx);
        goto after_5;
    // 0x8006C5D0: nop

    after_5:
    // 0x8006C5D4: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x8006C5D8: jal         0x800CD7A0
    // 0x8006C5DC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_6;
    // 0x8006C5DC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_6:
    // 0x8006C5E0: jal         0x800CD7B0
    // 0x8006C5E4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_7;
    // 0x8006C5E4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_7:
L_8006C5E8:
    // 0x8006C5E8: b           L_8006C5E8
    pause_self(rdram);
    // 0x8006C5EC: nop

L_8006C5F0:
    // 0x8006C5F0: jal         0x8006C84C
    // 0x8006C5F4: nop

    main_game_loop(rdram, ctx);
        goto after_8;
    // 0x8006C5F4: nop

    after_8:
    // 0x8006C5F8: jal         0x80066070
    // 0x8006C5FC: nop

    thread3_verify_stack(rdram, ctx);
        goto after_9;
    // 0x8006C5FC: nop

    after_9:
    // 0x8006C600: b           L_8006C5AC
    // 0x8006C604: nop

        goto L_8006C5AC;
    // 0x8006C604: nop

    // 0x8006C608: nop

    // 0x8006C60C: nop

    // 0x8006C610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C618: jr          $ra
    // 0x8006C61C: nop

    return;
    // 0x8006C61C: nop

;}
RECOMP_FUNC void init_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C628: jal         0x80070D70
    // 0x8006C62C: nop

    mempool_init_main(rdram, ctx);
        goto after_0;
    // 0x8006C62C: nop

    after_0:
    // 0x8006C630: jal         0x800C66D0
    // 0x8006C634: nop

    gzip_init(rdram, ctx);
        goto after_1;
    // 0x8006C634: nop

    after_1:
    // 0x8006C638: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C640: jal         0x8006F72C
    // 0x8006C644: sb          $t6, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = ctx->r14;
    drm_validate_imem(rdram, ctx);
        goto after_2;
    // 0x8006C644: sb          $t6, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = ctx->r14;
    after_2:
    // 0x8006C648: beq         $v0, $zero, L_8006C658
    if (ctx->r2 == 0) {
        // 0x8006C64C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006C658;
    }
    // 0x8006C64C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C650: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C654: sb          $zero, -0x271C($at)
    MEM_B(-0X271C, ctx->r1) = 0;
L_8006C658:
    // 0x8006C658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C65C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006C660: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8006C664: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
    // 0x8006C668: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C66C: bne         $v0, $zero, L_8006C680
    if (ctx->r2 != 0) {
        // 0x8006C670: sw          $zero, 0x3A98($at)
        MEM_W(0X3A98, ctx->r1) = 0;
            goto L_8006C680;
    }
    // 0x8006C670: sw          $zero, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = 0;
    // 0x8006C674: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8006C678: b           L_8006C6A4
    // 0x8006C67C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_8006C6A4;
    // 0x8006C67C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8006C680:
    // 0x8006C680: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C684: bne         $v0, $at, L_8006C698
    if (ctx->r2 != ctx->r1) {
        // 0x8006C688: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006C698;
    }
    // 0x8006C688: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C68C: b           L_8006C6A4
    // 0x8006C690: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_8006C6A4;
    // 0x8006C690: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8006C694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8006C698:
    // 0x8006C698: bne         $v0, $at, L_8006C6A4
    if (ctx->r2 != ctx->r1) {
        // 0x8006C69C: addiu       $t8, $zero, 0x1C
        ctx->r24 = ADD32(0, 0X1C);
            goto L_8006C6A4;
    }
    // 0x8006C69C: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8006C6A0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8006C6A4:
    // 0x8006C6A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C6A8: lbu         $a3, 0x27($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X27);
    // 0x8006C6AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006C6B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006C6B4: addiu       $a1, $a1, 0x3A68
    ctx->r5 = ADD32(ctx->r5, 0X3A68);
    // 0x8006C6B8: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    // 0x8006C6BC: jal         0x800797A0
    // 0x8006C6C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    osCreateScheduler(rdram, ctx);
        goto after_3;
    // 0x8006C6C0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x8006C6C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C6C8: jal         0x8006F1F8
    // 0x8006C6CC: sb          $zero, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = 0;
    drm_validate_dmem(rdram, ctx);
        goto after_4;
    // 0x8006C6CC: sb          $zero, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = 0;
    after_4:
    // 0x8006C6D0: bne         $v0, $zero, L_8006C6E4
    if (ctx->r2 != 0) {
        // 0x8006C6D4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006C6E4;
    }
    // 0x8006C6D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006C6D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006C6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C6E0: sb          $t1, -0x26F0($at)
    MEM_B(-0X26F0, ctx->r1) = ctx->r9;
L_8006C6E4:
    // 0x8006C6E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C6E8: jal         0x8007A760
    // 0x8006C6EC: addiu       $a1, $a1, 0x17E0
    ctx->r5 = ADD32(ctx->r5, 0X17E0);
    video_init(rdram, ctx);
        goto after_5;
    // 0x8006C6EC: addiu       $a1, $a1, 0x17E0
    ctx->r5 = ADD32(ctx->r5, 0X17E0);
    after_5:
    // 0x8006C6F0: jal         0x80076E00
    // 0x8006C6F4: nop

    pi_init(rdram, ctx);
        goto after_6;
    // 0x8006C6F4: nop

    after_6:
    // 0x8006C6F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C6FC: jal         0x80078550
    // 0x8006C700: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    gfxtask_init(rdram, ctx);
        goto after_7;
    // 0x8006C700: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    after_7:
    // 0x8006C704: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C708: jal         0x80000450
    // 0x8006C70C: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    audio_init(rdram, ctx);
        goto after_8;
    // 0x8006C70C: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    after_8:
    // 0x8006C710: jal         0x80008040
    // 0x8006C714: nop

    audspat_init(rdram, ctx);
        goto after_9;
    // 0x8006C714: nop

    after_9:
    // 0x8006C718: jal         0x8006A34C
    // 0x8006C71C: nop

    input_init(rdram, ctx);
        goto after_10;
    // 0x8006C71C: nop

    after_10:
    // 0x8006C720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C724: jal         0x8007B0C0
    // 0x8006C728: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    tex_init_textures(rdram, ctx);
        goto after_11;
    // 0x8006C728: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    after_11:
    // 0x8006C72C: jal         0x8005F9F0
    // 0x8006C730: nop

    allocate_object_model_pools(rdram, ctx);
        goto after_12;
    // 0x8006C730: nop

    after_12:
    // 0x8006C734: jal         0x8000BF8C
    // 0x8006C738: nop

    allocate_object_pools(rdram, ctx);
        goto after_13;
    // 0x8006C738: nop

    after_13:
    // 0x8006C73C: jal         0x800B63E8
    // 0x8006C740: nop

    debug_text_init(rdram, ctx);
        goto after_14;
    // 0x8006C740: nop

    after_14:
    // 0x8006C744: jal         0x80059920
    // 0x8006C748: nop

    allocate_ghost_data(rdram, ctx);
        goto after_15;
    // 0x8006C748: nop

    after_15:
    // 0x8006C74C: jal         0x800AEA90
    // 0x8006C750: nop

    init_particle_assets(rdram, ctx);
        goto after_16;
    // 0x8006C750: nop

    after_16:
    // 0x8006C754: jal         0x800AB750
    // 0x8006C758: nop

    weather_init(rdram, ctx);
        goto after_17;
    // 0x8006C758: nop

    after_17:
    // 0x8006C75C: jal         0x8006E5FC
    // 0x8006C760: nop

    calc_and_alloc_heap_for_settings(rdram, ctx);
        goto after_18;
    // 0x8006C760: nop

    after_18:
    // 0x8006C764: jal         0x8006F21C
    // 0x8006C768: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_19;
    // 0x8006C768: nop

    after_19:
    // 0x8006C76C: jal         0x800C4160
    // 0x8006C770: nop

    load_fonts(rdram, ctx);
        goto after_20;
    // 0x8006C770: nop

    after_20:
    // 0x8006C774: jal         0x80075D70
    // 0x8006C778: nop

    init_controller_paks(rdram, ctx);
        goto after_21;
    // 0x8006C778: nop

    after_21:
    // 0x8006C77C: jal         0x80081668
    // 0x8006C780: nop

    init_save_data(rdram, ctx);
        goto after_22;
    // 0x8006C780: nop

    after_22:
    // 0x8006C784: jal         0x800C78B0
    // 0x8006C788: nop

    bgload_init(rdram, ctx);
        goto after_23;
    // 0x8006C788: nop

    after_23:
    // 0x8006C78C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C794: addiu       $a1, $a1, 0x3AC4
    ctx->r5 = ADD32(ctx->r5, 0X3AC4);
    // 0x8006C798: addiu       $a0, $a0, 0x3AC8
    ctx->r4 = ADD32(ctx->r4, 0X3AC8);
    // 0x8006C79C: jal         0x800C8D80
    // 0x8006C7A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_24;
    // 0x8006C7A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x8006C7A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C7AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C7B0: addiu       $a2, $a2, 0x3AC8
    ctx->r6 = ADD32(ctx->r6, 0X3AC8);
    // 0x8006C7B4: addiu       $a1, $a1, 0x3AB8
    ctx->r5 = ADD32(ctx->r5, 0X3AB8);
    // 0x8006C7B8: addiu       $a0, $a0, 0x17E0
    ctx->r4 = ADD32(ctx->r4, 0X17E0);
    // 0x8006C7BC: jal         0x800798D0
    // 0x8006C7C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    osScAddClient(rdram, ctx);
        goto after_25;
    // 0x8006C7C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_25:
    // 0x8006C7C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7C8: sw          $zero, 0x3AE0($at)
    MEM_W(0X3AE0, ctx->r1) = 0;
    // 0x8006C7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7D0: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006C7D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C7DC: addiu       $t0, $t0, 0x3A68
    ctx->r8 = ADD32(ctx->r8, 0X3A68);
    // 0x8006C7E0: sw          $zero, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = 0;
    // 0x8006C7E4: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x8006C7E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006C7EC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006C7F0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006C7F4: lw          $t4, 0x1770($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1770);
    // 0x8006C7F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C7FC: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006C800: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006C804: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8006C808: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8006C80C: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006C810: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006C814: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8006C818: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006C81C: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006C820: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006C824: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006C828: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C82C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8006C830: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006C834: jal         0x800CD7C0
    // 0x8006C838: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    osSetTime_recomp(rdram, ctx);
        goto after_26;
    // 0x8006C838: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_26:
    // 0x8006C83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006C844: jr          $ra
    // 0x8006C848: nop

    return;
    // 0x8006C848: nop

;}
RECOMP_FUNC void main_game_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C84C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C854: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C858: jal         0x800CD7C0
    // 0x8006C85C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C85C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8006C860: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006C864: lw          $t6, -0x2710($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2710);
    // 0x8006C868: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006C86C: bne         $t6, $at, L_8006C8EC
    if (ctx->r14 != ctx->r1) {
        // 0x8006C870: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8006C8EC;
    }
    // 0x8006C870: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C874: lw          $t7, 0x3A68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A68);
    // 0x8006C878: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C87C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006C880: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006C884: lw          $t9, 0x1770($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1770);
    // 0x8006C888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C88C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C898: jal         0x8007A720
    // 0x8006C89C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    rsp_segment(rdram, ctx);
        goto after_1;
    // 0x8006C89C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    after_1:
    // 0x8006C8A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8A4: lw          $a2, 0x6874($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6874);
    // 0x8006C8A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8AC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8B0: jal         0x8007A720
    // 0x8006C8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_2;
    // 0x8006C8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8006C8B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8BC: lw          $a2, 0x6880($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6880);
    // 0x8006C8C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8C4: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8C8: jal         0x8007A720
    // 0x8006C8CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_3;
    // 0x8006C8CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8006C8D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8D4: lw          $a2, 0x6874($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6874);
    // 0x8006C8D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8DC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006C8E4: jal         0x8007A720
    // 0x8006C8E8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_4;
    // 0x8006C8E8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_4:
L_8006C8EC:
    // 0x8006C8EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C8F0: lb          $v1, -0x26A0($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26A0);
    // 0x8006C8F4: nop

    // 0x8006C8F8: bne         $v1, $zero, L_8006C94C
    if (ctx->r3 != 0) {
        // 0x8006C8FC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006C94C;
    }
    // 0x8006C8FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C900: lw          $t0, 0x3A68($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3A68);
    // 0x8006C904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C908: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006C90C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8006C910: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C914: lw          $a1, 0x1778($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1778);
    // 0x8006C918: lw          $a0, 0x1770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1770);
    // 0x8006C91C: jal         0x800778A0
    // 0x8006C920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gfxtask_run_xbus(rdram, ctx);
        goto after_5;
    // 0x8006C920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8006C924: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C928: addiu       $a3, $a3, 0x3A68
    ctx->r7 = ADD32(ctx->r7, 0X3A68);
    // 0x8006C92C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8006C930: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C934: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8006C938: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C93C: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x8006C940: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8006C944: lb          $v1, -0x26A0($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26A0);
    // 0x8006C948: nop

L_8006C94C:
    // 0x8006C94C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C950: beq         $v1, $zero, L_8006C964
    if (ctx->r3 == 0) {
        // 0x8006C954: addiu       $a3, $a3, 0x3A68
        ctx->r7 = ADD32(ctx->r7, 0X3A68);
            goto L_8006C964;
    }
    // 0x8006C954: addiu       $a3, $a3, 0x3A68
    ctx->r7 = ADD32(ctx->r7, 0X3A68);
    // 0x8006C958: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8006C95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C960: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
L_8006C964:
    // 0x8006C964: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8006C968: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006C96C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006C970: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006C974: lw          $t8, 0x1770($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1770);
    // 0x8006C978: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C97C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C980: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C984: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006C988: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006C98C: lw          $t9, 0x1780($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1780);
    // 0x8006C990: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C998: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8006C99C: lw          $t0, 0x1790($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1790);
    // 0x8006C9A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C9A4: sw          $t9, 0x1788($at)
    MEM_W(0X1788, ctx->r1) = ctx->r25;
    // 0x8006C9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C9AC: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8006C9B0: lw          $t1, 0x17A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X17A0);
    // 0x8006C9B4: sw          $t0, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r8;
    // 0x8006C9B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C9BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C9C4: jal         0x8007A720
    // 0x8006C9C8: sw          $t1, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r9;
    rsp_segment(rdram, ctx);
        goto after_6;
    // 0x8006C9C8: sw          $t1, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r9;
    after_6:
    // 0x8006C9CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C9D0: lw          $a2, 0x6878($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6878);
    // 0x8006C9D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C9D8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C9DC: jal         0x8007A720
    // 0x8006C9E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_7;
    // 0x8006C9E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8006C9E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C9E8: lw          $a2, 0x6880($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6880);
    // 0x8006C9EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C9F0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C9F4: jal         0x8007A720
    // 0x8006C9F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_8;
    // 0x8006C9F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8006C9FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CA00: lw          $a2, 0x6878($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6878);
    // 0x8006CA04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA08: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006CA0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006CA10: jal         0x8007A720
    // 0x8006CA14: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_9;
    // 0x8006CA14: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_9:
    // 0x8006CA18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA1C: jal         0x8007852C
    // 0x8006CA20: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rsp_init(rdram, ctx);
        goto after_10;
    // 0x8006CA20: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_10:
    // 0x8006CA24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA28: jal         0x800784A4
    // 0x8006CA2C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_11;
    // 0x8006CA2C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_11:
    // 0x8006CA30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CA38: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CA3C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006CA40: jal         0x80077FEC
    // 0x8006CA44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bgdraw_render(rdram, ctx);
        goto after_12;
    // 0x8006CA44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8006CA48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CA4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006CA50: lw          $a1, -0x268C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X268C);
    // 0x8006CA54: lw          $a0, -0x2714($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2714);
    // 0x8006CA58: jal         0x8006A404
    // 0x8006CA5C: nop

    input_update(rdram, ctx);
        goto after_13;
    // 0x8006CA5C: nop

    after_13:
    // 0x8006CA60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CA64: jal         0x800B7BFC
    // 0x8006CA68: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    get_lockup_status(rdram, ctx);
        goto after_14;
    // 0x8006CA68: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    after_14:
    // 0x8006CA6C: beq         $v0, $zero, L_8006CA88
    if (ctx->r2 == 0) {
        // 0x8006CA70: nop
    
            goto L_8006CA88;
    }
    // 0x8006CA70: nop

    // 0x8006CA74: jal         0x800B7D30
    // 0x8006CA78: nop

    render_epc_lock_up_display(rdram, ctx);
        goto after_15;
    // 0x8006CA78: nop

    after_15:
    // 0x8006CA7C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8006CA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CA84: sw          $t2, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r10;
L_8006CA88:
    // 0x8006CA88: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CA8C: lb          $t3, -0x26F0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X26F0);
    // 0x8006CA90: nop

    // 0x8006CA94: beq         $t3, $zero, L_8006CACC
    if (ctx->r11 == 0) {
        // 0x8006CA98: lui         $v1, 0x98
        ctx->r3 = S32(0X98 << 16);
            goto L_8006CACC;
    }
    // 0x8006CA98: lui         $v1, 0x98
    ctx->r3 = S32(0X98 << 16);
    // 0x8006CA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006CAA0: ori         $v1, $v1, 0x9680
    ctx->r3 = ctx->r3 | 0X9680;
L_8006CAA4:
    // 0x8006CAA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006CAA8: bne         $v0, $v1, L_8006CAA4
    if (ctx->r2 != ctx->r3) {
        // 0x8006CAAC: nop
    
            goto L_8006CAA4;
    }
    // 0x8006CAAC: nop

    // 0x8006CAB0: lui         $at, 0x131
    ctx->r1 = S32(0X131 << 16);
    // 0x8006CAB4: ori         $at, $at, 0x2D01
    ctx->r1 = ctx->r1 | 0X2D01;
    // 0x8006CAB8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006CABC: bne         $at, $zero, L_8006CACC
    if (ctx->r1 != 0) {
        // 0x8006CAC0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CACC;
    }
    // 0x8006CAC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAC4: jal         0x800B643C
    // 0x8006CAC8: addiu       $a0, $a0, 0x76C4
    ctx->r4 = ADD32(ctx->r4, 0X76C4);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x8006CAC8: addiu       $a0, $a0, 0x76C4
    ctx->r4 = ADD32(ctx->r4, 0X76C4);
    after_16:
L_8006CACC:
    // 0x8006CACC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CAD0: lw          $v0, 0x3A6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A6C);
    // 0x8006CAD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CAD8: beq         $v0, $at, L_8006CB08
    if (ctx->r2 == ctx->r1) {
        // 0x8006CADC: nop
    
            goto L_8006CB08;
    }
    // 0x8006CADC: nop

    // 0x8006CAE0: beq         $v0, $zero, L_8006CB2C
    if (ctx->r2 == 0) {
        // 0x8006CAE4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB2C;
    }
    // 0x8006CAE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CAEC: beq         $v0, $at, L_8006CB18
    if (ctx->r2 == ctx->r1) {
        // 0x8006CAF0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB18;
    }
    // 0x8006CAF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006CAF8: beq         $v0, $at, L_8006CB40
    if (ctx->r2 == ctx->r1) {
        // 0x8006CAFC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB40;
    }
    // 0x8006CAFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB00: b           L_8006CB4C
    // 0x8006CB04: nop

        goto L_8006CB4C;
    // 0x8006CB04: nop

L_8006CB08:
    // 0x8006CB08: jal         0x8006F67C
    // 0x8006CB0C: nop

    mode_intro(rdram, ctx);
        goto after_17;
    // 0x8006CB0C: nop

    after_17:
    // 0x8006CB10: b           L_8006CB4C
    // 0x8006CB14: nop

        goto L_8006CB4C;
    // 0x8006CB14: nop

L_8006CB18:
    // 0x8006CB18: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB1C: jal         0x8006DF38
    // 0x8006CB20: nop

    mode_menu(rdram, ctx);
        goto after_18;
    // 0x8006CB20: nop

    after_18:
    // 0x8006CB24: b           L_8006CB4C
    // 0x8006CB28: nop

        goto L_8006CB4C;
    // 0x8006CB28: nop

L_8006CB2C:
    // 0x8006CB2C: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB30: jal         0x8006CF30
    // 0x8006CB34: nop

    mode_game(rdram, ctx);
        goto after_19;
    // 0x8006CB34: nop

    after_19:
    // 0x8006CB38: b           L_8006CB4C
    // 0x8006CB3C: nop

        goto L_8006CB4C;
    // 0x8006CB3C: nop

L_8006CB40:
    // 0x8006CB40: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB44: jal         0x800B7CF4
    // 0x8006CB48: nop

    mode_lockup(rdram, ctx);
        goto after_20;
    // 0x8006CB48: nop

    after_20:
L_8006CB4C:
    // 0x8006CB4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB50: lbu         $a0, -0x2689($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2689);
    // 0x8006CB54: jal         0x80000D00
    // 0x8006CB58: nop

    sound_update_queue(rdram, ctx);
        goto after_21;
    // 0x8006CB58: nop

    after_21:
    // 0x8006CB5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB60: jal         0x800B64D8
    // 0x8006CB64: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    debug_text_print(rdram, ctx);
        goto after_22;
    // 0x8006CB64: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_22:
    // 0x8006CB68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CB70: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CB74: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006CB78: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CB7C: jal         0x800C5C5C
    // 0x8006CB80: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    render_dialogue_boxes(rdram, ctx);
        goto after_23;
    // 0x8006CB80: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_23:
    // 0x8006CB84: jal         0x800C5B80
    // 0x8006CB88: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_close(rdram, ctx);
        goto after_24;
    // 0x8006CB88: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_24:
    // 0x8006CB8C: jal         0x800C59F4
    // 0x8006CB90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_clear(rdram, ctx);
        goto after_25;
    // 0x8006CB90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x8006CB94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB98: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB9C: jal         0x800C09B4
    // 0x8006CBA0: nop

    transition_update(rdram, ctx);
        goto after_26;
    // 0x8006CBA0: nop

    after_26:
    // 0x8006CBA4: beq         $v0, $zero, L_8006CBC4
    if (ctx->r2 == 0) {
        // 0x8006CBA8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006CBC4;
    }
    // 0x8006CBA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CBB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CBB4: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006CBB8: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CBBC: jal         0x800C0AE8
    // 0x8006CBC0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    transition_render(rdram, ctx);
        goto after_27;
    // 0x8006CBC0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_27:
L_8006CBC4:
    // 0x8006CBC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006CBC8: lw          $t4, 0x3AA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3AA0);
    // 0x8006CBCC: nop

    // 0x8006CBD0: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8006CBD4: bne         $at, $zero, L_8006CBFC
    if (ctx->r1 != 0) {
        // 0x8006CBD8: nop
    
            goto L_8006CBFC;
    }
    // 0x8006CBD8: nop

    // 0x8006CBDC: jal         0x8006F708
    // 0x8006CBE0: nop

    is_controller_missing(rdram, ctx);
        goto after_28;
    // 0x8006CBE0: nop

    after_28:
    // 0x8006CBE4: beq         $v0, $zero, L_8006CBFC
    if (ctx->r2 == 0) {
        // 0x8006CBE8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006CBFC;
    }
    // 0x8006CBE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006CBF0: lw          $a1, -0x268C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X268C);
    // 0x8006CBF4: jal         0x80082E48
    // 0x8006CBF8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    menu_missing_controller(rdram, ctx);
        goto after_29;
    // 0x8006CBF8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_29:
L_8006CBFC:
    // 0x8006CBFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CC00: lw          $v0, 0x1778($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1778);
    // 0x8006CC04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CC08: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8006CC0C: sw          $t5, 0x1778($at)
    MEM_W(0X1778, ctx->r1) = ctx->r13;
    // 0x8006CC10: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006CC14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006CC18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CC1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CC20: lw          $v0, 0x1778($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1778);
    // 0x8006CC24: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006CC28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006CC2C: sw          $t7, 0x1778($at)
    MEM_W(0X1778, ctx->r1) = ctx->r15;
    // 0x8006CC30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CC34: jal         0x80066850
    // 0x8006CC38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    copy_viewports_to_stack(rdram, ctx);
        goto after_30;
    // 0x8006CC38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_30:
    // 0x8006CC3C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006CC40: lb          $t9, -0x26A0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X26A0);
    // 0x8006CC44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CC48: beq         $t9, $at, L_8006CC74
    if (ctx->r25 == ctx->r1) {
        // 0x8006CC4C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8006CC74;
    }
    // 0x8006CC4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006CC50: lb          $t0, -0x2704($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2704);
    // 0x8006CC54: nop

    // 0x8006CC58: bne         $t0, $zero, L_8006CC7C
    if (ctx->r8 != 0) {
        // 0x8006CC5C: nop
    
            goto L_8006CC7C;
    }
    // 0x8006CC5C: nop

    // 0x8006CC60: jal         0x80077EA4
    // 0x8006CC64: nop

    gfxtask_wait(rdram, ctx);
        goto after_31;
    // 0x8006CC64: nop

    after_31:
    // 0x8006CC68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC6C: b           L_8006CC7C
    // 0x8006CC70: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
        goto L_8006CC7C;
    // 0x8006CC70: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
L_8006CC74:
    // 0x8006CC74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC78: sb          $zero, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = 0;
L_8006CC7C:
    // 0x8006CC7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC80: jal         0x800713D8
    // 0x8006CC84: sb          $zero, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = 0;
    mempool_free_queue_clear(rdram, ctx);
        goto after_32;
    // 0x8006CC84: sb          $zero, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = 0;
    after_32:
    // 0x8006CC88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CC8C: lb          $t1, 0x3A95($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X3A95);
    // 0x8006CC90: nop

    // 0x8006CC94: bne         $t1, $zero, L_8006CCA4
    if (ctx->r9 != 0) {
        // 0x8006CC98: nop
    
            goto L_8006CCA4;
    }
    // 0x8006CC98: nop

    // 0x8006CC9C: jal         0x80066760
    // 0x8006CCA0: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_33;
    // 0x8006CCA0: nop

    after_33:
L_8006CCA4:
    // 0x8006CCA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006CCA8: lb          $t2, -0x26A0($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X26A0);
    // 0x8006CCAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CCB0: bne         $t2, $at, L_8006CCE8
    if (ctx->r10 != ctx->r1) {
        // 0x8006CCB4: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8006CCE8;
    }
    // 0x8006CCB4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8006CCB8: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8006CCBC: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CCC0: bne         $t3, $zero, L_8006CCD0
    if (ctx->r11 != 0) {
        // 0x8006CCC4: ori         $v0, $v0, 0x5800
        ctx->r2 = ctx->r2 | 0X5800;
            goto L_8006CCD0;
    }
    // 0x8006CCC4: ori         $v0, $v0, 0x5800
    ctx->r2 = ctx->r2 | 0X5800;
    // 0x8006CCC8: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CCCC: ori         $v0, $v0, 0x9400
    ctx->r2 = ctx->r2 | 0X9400;
L_8006CCD0:
    // 0x8006CCD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CCD4: lw          $a1, 0x6874($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6874);
    // 0x8006CCD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CCDC: lw          $a0, 0x6878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6878);
    // 0x8006CCE0: jal         0x80070D44
    // 0x8006CCE4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    dmacopy_doubleword(rdram, ctx);
        goto after_34;
    // 0x8006CCE4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    after_34:
L_8006CCE8:
    // 0x8006CCE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CCEC: lw          $a0, -0x2710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2710);
    // 0x8006CCF0: jal         0x8007ADDC
    // 0x8006CCF4: nop

    fb_update(rdram, ctx);
        goto after_35;
    // 0x8006CCF4: nop

    after_35:
    // 0x8006CCF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CCFC: sw          $v0, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r2;
    // 0x8006CD00: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8006CD04: bne         $at, $zero, L_8006CD14
    if (ctx->r1 != 0) {
        // 0x8006CD08: addiu       $t4, $zero, 0x6
        ctx->r12 = ADD32(0, 0X6);
            goto L_8006CD14;
    }
    // 0x8006CD08: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8006CD0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CD10: sw          $t4, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r12;
L_8006CD14:
    // 0x8006CD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CD1C: jr          $ra
    // 0x8006CD20: nop

    return;
    // 0x8006CD20: nop

;}
RECOMP_FUNC void load_next_ingame_level(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD24: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8006CD28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CD2C: sw          $t6, 0x3A80($at)
    MEM_W(0X3A80, ctx->r1) = ctx->r14;
    // 0x8006CD30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CD34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CD3C: bne         $a1, $at, L_8006CD5C
    if (ctx->r5 != ctx->r1) {
        // 0x8006CD40: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8006CD5C;
    }
    // 0x8006CD40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006CD44: jal         0x8009C6F4
    // 0x8006CD48: nop

    get_track_id_to_load(rdram, ctx);
        goto after_0;
    // 0x8006CD48: nop

    after_0:
    // 0x8006CD4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CD50: addiu       $v1, $v1, 0x3A74
    ctx->r3 = ADD32(ctx->r3, 0X3A74);
    // 0x8006CD54: b           L_8006CD68
    // 0x8006CD58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8006CD68;
    // 0x8006CD58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8006CD5C:
    // 0x8006CD5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CD60: addiu       $v1, $v1, 0x3A74
    ctx->r3 = ADD32(ctx->r3, 0X3A74);
    // 0x8006CD64: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
L_8006CD68:
    // 0x8006CD68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CD6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CD70: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006CD74: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006CD78: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8006CD7C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006CD80: jal         0x8006CD98
    // 0x8006CD84: nop

    load_level_game(rdram, ctx);
        goto after_1;
    // 0x8006CD84: nop

    after_1:
    // 0x8006CD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CD90: jr          $ra
    // 0x8006CD94: nop

    return;
    // 0x8006CD94: nop

;}
RECOMP_FUNC void load_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CD9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CDA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006CDA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006CDA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006CDAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006CDB0: jal         0x8006EF3C
    // 0x8006CDB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006CDB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006CDB8: jal         0x800712F0
    // 0x8006CDBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8006CDBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8006CDC0: jal         0x800660E0
    // 0x8006CDC4: nop

    cam_init(rdram, ctx);
        goto after_2;
    // 0x8006CDC4: nop

    after_2:
    // 0x8006CDC8: jal         0x800C35A0
    // 0x8006CDCC: nop

    load_game_text_table(rdram, ctx);
        goto after_3;
    // 0x8006CDCC: nop

    after_3:
    // 0x8006CDD0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CDD4: lw          $t6, 0x3A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A88);
    // 0x8006CDD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CDDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006CDE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006CDE4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CDE8: jal         0x8006B490
    // 0x8006CDEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_4;
    // 0x8006CDEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006CDF0: jal         0x80066450
    // 0x8006CDF4: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x8006CDF4: nop

    after_5:
    // 0x8006CDF8: jal         0x8009F230
    // 0x8006CDFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_6;
    // 0x8006CDFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006CE00: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8006CE04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006CE08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006CE0C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8006CE10: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8006CE14: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8006CE18: jal         0x800AEC88
    // 0x8006CE1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_7;
    // 0x8006CE1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x8006CE20: jal         0x8001BF54
    // 0x8006CE24: nop

    ainode_update(rdram, ctx);
        goto after_8;
    // 0x8006CE24: nop

    after_8:
    // 0x8006CE28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006CE2C: jal         0x800CD7C0
    // 0x8006CE30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x8006CE30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x8006CE34: jal         0x800712F0
    // 0x8006CE38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_10;
    // 0x8006CE38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x8006CE3C: jal         0x800724E4
    // 0x8006CE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_11;
    // 0x8006CE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x8006CE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CE4C: jr          $ra
    // 0x8006CE50: nop

    return;
    // 0x8006CE50: nop

;}
RECOMP_FUNC void unload_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CE5C: jal         0x800712F0
    // 0x8006CE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006CE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006CE64: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006CE68: lb          $t6, -0x2704($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2704);
    // 0x8006CE6C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006CE70: bne         $t6, $zero, L_8006CE9C
    if (ctx->r14 != 0) {
        // 0x8006CE74: nop
    
            goto L_8006CE9C;
    }
    // 0x8006CE74: nop

    // 0x8006CE78: lb          $t7, -0x26A0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X26A0);
    // 0x8006CE7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CE80: beq         $t7, $at, L_8006CE94
    if (ctx->r15 == ctx->r1) {
        // 0x8006CE84: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006CE94;
    }
    // 0x8006CE84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006CE88: jal         0x80077EA4
    // 0x8006CE8C: nop

    gfxtask_wait(rdram, ctx);
        goto after_1;
    // 0x8006CE8C: nop

    after_1:
    // 0x8006CE90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8006CE94:
    // 0x8006CE94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CE98: sb          $t8, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = ctx->r24;
L_8006CE9C:
    // 0x8006CE9C: jal         0x8006C13C
    // 0x8006CEA0: nop

    level_free(rdram, ctx);
        goto after_2;
    // 0x8006CEA0: nop

    after_2:
    // 0x8006CEA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CEA8: jal         0x800C06F8
    // 0x8006CEAC: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8006CEAC: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    after_3:
    // 0x8006CEB0: jal         0x800AE7D0
    // 0x8006CEB4: nop

    reset_particles(rdram, ctx);
        goto after_4;
    // 0x8006CEB4: nop

    after_4:
    // 0x8006CEB8: jal         0x800A057C
    // 0x8006CEBC: nop

    hud_free(rdram, ctx);
        goto after_5;
    // 0x8006CEBC: nop

    after_5:
    // 0x8006CEC0: jal         0x800C3624
    // 0x8006CEC4: nop

    free_game_text_table(rdram, ctx);
        goto after_6;
    // 0x8006CEC4: nop

    after_6:
    // 0x8006CEC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006CECC: lw          $t9, 0x3A68($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A68);
    // 0x8006CED0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CED4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006CED8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006CEDC: lw          $t1, 0x1770($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1770);
    // 0x8006CEE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CEE4: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006CEE8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8006CEEC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8006CEF0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006CEF4: lui         $t3, 0xE900
    ctx->r11 = S32(0XE900 << 16);
    // 0x8006CEF8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006CEFC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8006CF00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006CF04: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006CF08: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006CF0C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006CF10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006CF14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CF18: jal         0x800712F0
    // 0x8006CF1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    mempool_free_timer(rdram, ctx);
        goto after_7;
    // 0x8006CF1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_7:
    // 0x8006CF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CF28: jr          $ra
    // 0x8006CF2C: nop

    return;
    // 0x8006CF2C: nop

;}
RECOMP_FUNC void mode_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF30: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006CF34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006CF38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006CF3C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006CF40: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8006CF44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006CF48: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006CF4C: jal         0x8009C91C
    // 0x8006CF50: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    get_active_player_count(rdram, ctx);
        goto after_0;
    // 0x8006CF50: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x8006CF54: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF58: nop

    // 0x8006CF5C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CF60: beq         $at, $zero, L_8006CFB0
    if (ctx->r1 == 0) {
        // 0x8006CF64: nop
    
            goto L_8006CFB0;
    }
    // 0x8006CF64: nop

    // 0x8006CF68: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CF6C:
    // 0x8006CF6C: jal         0x8006A768
    // 0x8006CF70: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x8006CF70: nop

    after_1:
    // 0x8006CF74: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF78: jal         0x8006A794
    // 0x8006CF7C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8006CF7C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    after_2:
    // 0x8006CF80: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006CF84: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CF88: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8006CF8C: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8006CF90: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8006CF94: jal         0x8009C91C
    // 0x8006CF98: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    get_active_player_count(rdram, ctx);
        goto after_3;
    // 0x8006CF98: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    after_3:
    // 0x8006CF9C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006CFA0: nop

    // 0x8006CFA4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CFA8: bne         $at, $zero, L_8006CF6C
    if (ctx->r1 != 0) {
        // 0x8006CFAC: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_8006CF6C;
    }
    // 0x8006CFAC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CFB0:
    // 0x8006CFB0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CFB4: lb          $t3, -0x271C($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X271C);
    // 0x8006CFB8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CFBC: beq         $t3, $zero, L_8006CFCC
    if (ctx->r11 == 0) {
        // 0x8006CFC0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006CFCC;
    }
    // 0x8006CFC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CFC4: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x8006CFC8: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_8006CFCC:
    // 0x8006CFCC: lb          $t6, 0x3A95($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A95);
    // 0x8006CFD0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006CFD4: bne         $t6, $zero, L_8006D0A0
    if (ctx->r14 != 0) {
        // 0x8006CFD8: nop
    
            goto L_8006D0A0;
    }
    // 0x8006CFD8: nop

    // 0x8006CFDC: jal         0x80010994
    // 0x8006CFE0: nop

    obj_update(rdram, ctx);
        goto after_4;
    // 0x8006CFE0: nop

    after_4:
    // 0x8006CFE4: jal         0x80066750
    // 0x8006CFE8: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_5;
    // 0x8006CFE8: nop

    after_5:
    // 0x8006CFEC: beq         $v0, $zero, L_8006D008
    if (ctx->r2 == 0) {
        // 0x8006CFF0: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_8006D008;
    }
    // 0x8006CFF0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CFF4: jal         0x8001139C
    // 0x8006CFF8: nop

    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x8006CFF8: nop

    after_6:
    // 0x8006CFFC: beq         $v0, $zero, L_8006D084
    if (ctx->r2 == 0) {
        // 0x8006D000: nop
    
            goto L_8006D084;
    }
    // 0x8006D000: nop

    // 0x8006D004: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_8006D008:
    // 0x8006D008: nop

    // 0x8006D00C: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8006D010: beq         $t8, $zero, L_8006D084
    if (ctx->r24 == 0) {
        // 0x8006D014: nop
    
            goto L_8006D084;
    }
    // 0x8006D014: nop

    // 0x8006D018: jal         0x8006C530
    // 0x8006D01C: nop

    level_properties_get(rdram, ctx);
        goto after_7;
    // 0x8006D01C: nop

    after_7:
    // 0x8006D020: bne         $v0, $zero, L_8006D084
    if (ctx->r2 != 0) {
        // 0x8006D024: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8006D084;
    }
    // 0x8006D024: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006D028: lb          $t9, -0x2700($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2700);
    // 0x8006D02C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006D030: bne         $t9, $zero, L_8006D084
    if (ctx->r25 != 0) {
        // 0x8006D034: nop
    
            goto L_8006D084;
    }
    // 0x8006D034: nop

    // 0x8006D038: lw          $t1, 0x3A6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3A6C);
    // 0x8006D03C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006D040: bne         $t1, $zero, L_8006D084
    if (ctx->r9 != 0) {
        // 0x8006D044: nop
    
            goto L_8006D084;
    }
    // 0x8006D044: nop

    // 0x8006D048: lb          $t2, 0x3A96($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X3A96);
    // 0x8006D04C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006D050: bne         $t2, $zero, L_8006D084
    if (ctx->r10 != 0) {
        // 0x8006D054: nop
    
            goto L_8006D084;
    }
    // 0x8006D054: nop

    // 0x8006D058: lh          $t3, -0x26FC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X26FC);
    // 0x8006D05C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D060: bne         $t3, $zero, L_8006D084
    if (ctx->r11 != 0) {
        // 0x8006D064: addiu       $a0, $a0, -0x26F8
        ctx->r4 = ADD32(ctx->r4, -0X26F8);
            goto L_8006D084;
    }
    // 0x8006D064: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D068: lb          $t4, 0x0($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X0);
    // 0x8006D06C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006D070: bne         $t4, $zero, L_8006D084
    if (ctx->r12 != 0) {
        // 0x8006D074: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D084;
    }
    // 0x8006D074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D078: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006D07C: jal         0x80093F44
    // 0x8006D080: sb          $t5, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r13;
    menu_pause_init(rdram, ctx);
        goto after_8;
    // 0x8006D080: sb          $t5, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r13;
    after_8:
L_8006D084:
    // 0x8006D084: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D088: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D08C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D090: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006D094: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006D098: b           L_8006D0C4
    // 0x8006D09C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
        goto L_8006D0C4;
    // 0x8006D09C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006D0A0:
    // 0x8006D0A0: jal         0x80028FE0
    // 0x8006D0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_9;
    // 0x8006D0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8006D0A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D0AC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006D0B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D0B4: lb          $v1, -0x26F8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26F8);
    // 0x8006D0B8: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006D0BC: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    // 0x8006D0C0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006D0C4:
    // 0x8006D0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D0C8: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8006D0CC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006D0D0: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006D0D4: nop

    // 0x8006D0D8: bgez        $t8, L_8006D0E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006D0DC: nop
    
            goto L_8006D0E4;
    }
    // 0x8006D0DC: nop

    // 0x8006D0E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8006D0E4:
    // 0x8006D0E4: beq         $v0, $zero, L_8006D0F0
    if (ctx->r2 == 0) {
        // 0x8006D0E8: nop
    
            goto L_8006D0F0;
    }
    // 0x8006D0E8: nop

    // 0x8006D0EC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D0F0:
    // 0x8006D0F0: jal         0x8001004C
    // 0x8006D0F4: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8006D0F4: nop

    after_10:
    // 0x8006D0F8: jal         0x8001BF54
    // 0x8006D0FC: nop

    ainode_update(rdram, ctx);
        goto after_11;
    // 0x8006D0FC: nop

    after_11:
    // 0x8006D100: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006D104: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D108: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D10C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D110: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D114: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006D118: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D11C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006D120: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006D124: jal         0x80024D94
    // 0x8006D128: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_scene(rdram, ctx);
        goto after_12;
    // 0x8006D128: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_12:
    // 0x8006D12C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006D130: lw          $t1, 0x3A6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3A6C);
    // 0x8006D134: addiu       $at, $zero, -0x2031
    ctx->r1 = ADD32(0, -0X2031);
    // 0x8006D138: bne         $t1, $zero, L_8006D148
    if (ctx->r9 != 0) {
        // 0x8006D13C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006D148;
    }
    // 0x8006D13C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006D140: and         $t2, $s0, $at
    ctx->r10 = ctx->r16 & ctx->r1;
    // 0x8006D144: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D148:
    // 0x8006D148: lb          $t3, 0x3A96($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X3A96);
    // 0x8006D14C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D150: beq         $t3, $zero, L_8006D264
    if (ctx->r11 == 0) {
        // 0x8006D154: addiu       $a0, $a0, 0x1778
        ctx->r4 = ADD32(ctx->r4, 0X1778);
            goto L_8006D264;
    }
    // 0x8006D154: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006D158: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D15C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D160: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006D164: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D168: jal         0x80095C2C
    // 0x8006D16C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    menu_postrace(rdram, ctx);
        goto after_13;
    // 0x8006D16C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    after_13:
    // 0x8006D170: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8006D174: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x8006D178: beq         $at, $zero, L_8006D264
    if (ctx->r1 == 0) {
        // 0x8006D17C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D264;
    }
    // 0x8006D17C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D180: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006D184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D188: addu        $at, $at, $t4
    gpr jr_addend_8006D194 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006D18C: lw          $t4, 0x76E4($at)
    ctx->r12 = ADD32(ctx->r1, 0X76E4);
    // 0x8006D190: nop

    // 0x8006D194: jr          $t4
    // 0x8006D198: nop

    switch (jr_addend_8006D194 >> 2) {
        case 0: goto L_8006D1A8; break;
        case 1: goto L_8006D19C; break;
        case 2: goto L_8006D264; break;
        case 3: goto L_8006D1C0; break;
        case 4: goto L_8006D1DC; break;
        case 5: goto L_8006D264; break;
        case 6: goto L_8006D264; break;
        case 7: goto L_8006D1F0; break;
        case 8: goto L_8006D204; break;
        case 9: goto L_8006D218; break;
        case 10: goto L_8006D22C; break;
        case 11: goto L_8006D240; break;
        case 12: goto L_8006D254; break;
        default: switch_error(__func__, 0x8006D194, 0x800E76E4);
    }
    // 0x8006D198: nop

L_8006D19C:
    // 0x8006D19C: ori         $t5, $s0, 0x2020
    ctx->r13 = ctx->r16 | 0X2020;
    // 0x8006D1A0: b           L_8006D264
    // 0x8006D1A4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8006D264;
    // 0x8006D1A4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8006D1A8:
    // 0x8006D1A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D1AC: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006D1B0: jal         0x8006DB30
    // 0x8006D1B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8006D8F0(rdram, ctx);
        goto after_14;
    // 0x8006D1B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_14:
    // 0x8006D1B8: b           L_8006D268
    // 0x8006D1BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
        goto L_8006D268;
    // 0x8006D1BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006D1C0:
    // 0x8006D1C0: jal         0x8006C524
    // 0x8006D1C4: nop

    level_properties_reset(rdram, ctx);
        goto after_15;
    // 0x8006D1C4: nop

    after_15:
    // 0x8006D1C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D1CC: ori         $t6, $s0, 0x30
    ctx->r14 = ctx->r16 | 0X30;
    // 0x8006D1D0: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    // 0x8006D1D4: b           L_8006D264
    // 0x8006D1D8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D264;
    // 0x8006D1D8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D1DC:
    // 0x8006D1DC: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D1E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D1E4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8006D1E8: b           L_8006D264
    // 0x8006D1EC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D264;
    // 0x8006D1EC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006D1F0:
    // 0x8006D1F0: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D1F4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006D1F8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8006D1FC: b           L_8006D264
    // 0x8006D200: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D264;
    // 0x8006D200: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006D204:
    // 0x8006D204: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006D208: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006D20C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8006D210: b           L_8006D264
    // 0x8006D214: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D264;
    // 0x8006D214: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D218:
    // 0x8006D218: ori         $t4, $s0, 0x20
    ctx->r12 = ctx->r16 | 0X20;
    // 0x8006D21C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8006D220: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8006D224: b           L_8006D264
    // 0x8006D228: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
        goto L_8006D264;
    // 0x8006D228: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_8006D22C:
    // 0x8006D22C: ori         $t6, $s0, 0x20
    ctx->r14 = ctx->r16 | 0X20;
    // 0x8006D230: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8006D234: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8006D238: b           L_8006D264
    // 0x8006D23C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D264;
    // 0x8006D23C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D240:
    // 0x8006D240: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D244: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8006D248: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8006D24C: b           L_8006D264
    // 0x8006D250: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_8006D264;
    // 0x8006D250: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8006D254:
    // 0x8006D254: ori         $t1, $s0, 0x20
    ctx->r9 = ctx->r16 | 0X20;
    // 0x8006D258: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8006D25C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8006D260: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8006D264:
    // 0x8006D264: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006D268:
    // 0x8006D268: jal         0x800C3998
    // 0x8006D26C: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_16;
    // 0x8006D26C: nop

    after_16:
    // 0x8006D270: jal         0x800C3958
    // 0x8006D274: nop

    textbox_visible(rdram, ctx);
        goto after_17;
    // 0x8006D274: nop

    after_17:
    // 0x8006D278: beq         $v0, $zero, L_8006D2B0
    if (ctx->r2 == 0) {
        // 0x8006D27C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D2B0;
    }
    // 0x8006D27C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D284: bne         $v0, $at, L_8006D294
    if (ctx->r2 != ctx->r1) {
        // 0x8006D288: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8006D294;
    }
    // 0x8006D288: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D28C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D290: sb          $t3, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = ctx->r11;
L_8006D294:
    // 0x8006D294: jal         0x800C3958
    // 0x8006D298: nop

    textbox_visible(rdram, ctx);
        goto after_18;
    // 0x8006D298: nop

    after_18:
    // 0x8006D29C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D2A0: beq         $v0, $at, L_8006D2B0
    if (ctx->r2 == ctx->r1) {
        // 0x8006D2A4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D2B0;
    }
    // 0x8006D2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D2A8: jal         0x80094AE8
    // 0x8006D2AC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_19;
    // 0x8006D2AC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    after_19:
L_8006D2B0:
    // 0x8006D2B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006D2B4: lb          $t4, 0x3A95($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X3A95);
    // 0x8006D2B8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8006D2BC: beq         $t4, $zero, L_8006D400
    if (ctx->r12 == 0) {
        // 0x8006D2C0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D400;
    }
    // 0x8006D2C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D2C4: jal         0x80094674
    // 0x8006D2C8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    menu_pause_loop(rdram, ctx);
        goto after_20;
    // 0x8006D2C8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_20:
    // 0x8006D2CC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8006D2D0: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x8006D2D4: beq         $at, $zero, L_8006D400
    if (ctx->r1 == 0) {
        // 0x8006D2D8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D400;
    }
    // 0x8006D2D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D2DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006D2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D2E4: addu        $at, $at, $t5
    gpr jr_addend_8006D2F0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8006D2E8: lw          $t5, 0x7718($at)
    ctx->r13 = ADD32(ctx->r1, 0X7718);
    // 0x8006D2EC: nop

    // 0x8006D2F0: jr          $t5
    // 0x8006D2F4: nop

    switch (jr_addend_8006D2F0 >> 2) {
        case 0: goto L_8006D2F8; break;
        case 1: goto L_8006D304; break;
        case 2: goto L_8006D348; break;
        case 3: goto L_8006D3DC; break;
        case 4: goto L_8006D38C; break;
        case 5: goto L_8006D3BC; break;
        case 6: goto L_8006D3C8; break;
        case 7: goto L_8006D400; break;
        case 8: goto L_8006D400; break;
        case 9: goto L_8006D400; break;
        case 10: goto L_8006D400; break;
        case 11: goto L_8006D3A4; break;
        default: switch_error(__func__, 0x8006D2F0, 0x800E7718);
    }
    // 0x8006D2F4: nop

L_8006D2F8:
    // 0x8006D2F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D2FC: b           L_8006D400
    // 0x8006D300: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D300: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D304:
    // 0x8006D304: jal         0x80001050
    // 0x8006D308: nop

    sound_clear_delayed(rdram, ctx);
        goto after_21;
    // 0x8006D308: nop

    after_21:
    // 0x8006D30C: jal         0x800C36A4
    // 0x8006D310: nop

    reset_delayed_text(rdram, ctx);
        goto after_22;
    // 0x8006D310: nop

    after_22:
    // 0x8006D314: jal         0x8002359C
    // 0x8006D318: nop

    func_80023568(rdram, ctx);
        goto after_23;
    // 0x8006D318: nop

    after_23:
    // 0x8006D31C: beq         $v0, $zero, L_8006D340
    if (ctx->r2 == 0) {
        // 0x8006D320: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D340;
    }
    // 0x8006D320: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D324: jal         0x8009F1C4
    // 0x8006D328: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8006D328: nop

    after_24:
    // 0x8006D32C: beq         $v0, $zero, L_8006D340
    if (ctx->r2 == 0) {
        // 0x8006D330: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D340;
    }
    // 0x8006D330: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D334: jal         0x8006F5D8
    // 0x8006D338: nop

    swap_lead_player(rdram, ctx);
        goto after_25;
    // 0x8006D338: nop

    after_25:
    // 0x8006D33C: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
L_8006D340:
    // 0x8006D340: b           L_8006D400
    // 0x8006D344: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D400;
    // 0x8006D344: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D348:
    // 0x8006D348: jal         0x80001050
    // 0x8006D34C: nop

    sound_clear_delayed(rdram, ctx);
        goto after_26;
    // 0x8006D34C: nop

    after_26:
    // 0x8006D350: jal         0x800C36A4
    // 0x8006D354: nop

    reset_delayed_text(rdram, ctx);
        goto after_27;
    // 0x8006D354: nop

    after_27:
    // 0x8006D358: jal         0x8002359C
    // 0x8006D35C: nop

    func_80023568(rdram, ctx);
        goto after_28;
    // 0x8006D35C: nop

    after_28:
    // 0x8006D360: beq         $v0, $zero, L_8006D384
    if (ctx->r2 == 0) {
        // 0x8006D364: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D384;
    }
    // 0x8006D364: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D368: jal         0x8009F1C4
    // 0x8006D36C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_29;
    // 0x8006D36C: nop

    after_29:
    // 0x8006D370: beq         $v0, $zero, L_8006D384
    if (ctx->r2 == 0) {
        // 0x8006D374: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D384;
    }
    // 0x8006D374: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D378: jal         0x8006F5D8
    // 0x8006D37C: nop

    swap_lead_player(rdram, ctx);
        goto after_30;
    // 0x8006D37C: nop

    after_30:
    // 0x8006D380: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
L_8006D384:
    // 0x8006D384: b           L_8006D400
    // 0x8006D388: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D400;
    // 0x8006D388: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006D38C:
    // 0x8006D38C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D390: jal         0x800C36A4
    // 0x8006D394: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    reset_delayed_text(rdram, ctx);
        goto after_31;
    // 0x8006D394: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_31:
    // 0x8006D398: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D39C: b           L_8006D400
    // 0x8006D3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D400;
    // 0x8006D3A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006D3A4:
    // 0x8006D3A4: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8006D3A8: jal         0x800C36A4
    // 0x8006D3AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    reset_delayed_text(rdram, ctx);
        goto after_32;
    // 0x8006D3AC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_32:
    // 0x8006D3B0: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006D3B4: b           L_8006D400
    // 0x8006D3B8: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D400;
    // 0x8006D3B8: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D3BC:
    // 0x8006D3BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D3C0: b           L_8006D400
    // 0x8006D3C4: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D3C4: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D3C8:
    // 0x8006D3C8: jal         0x80022E4C
    // 0x8006D3CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mode_end_taj_race(rdram, ctx);
        goto after_33;
    // 0x8006D3CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x8006D3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D3D4: b           L_8006D400
    // 0x8006D3D8: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
        goto L_8006D400;
    // 0x8006D3D8: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
L_8006D3DC:
    // 0x8006D3DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D3E0: jal         0x80001050
    // 0x8006D3E4: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    sound_clear_delayed(rdram, ctx);
        goto after_34;
    // 0x8006D3E4: sb          $zero, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = 0;
    after_34:
    // 0x8006D3E8: jal         0x800C36A4
    // 0x8006D3EC: nop

    reset_delayed_text(rdram, ctx);
        goto after_35;
    // 0x8006D3EC: nop

    after_35:
    // 0x8006D3F0: jal         0x8006C524
    // 0x8006D3F4: nop

    level_properties_reset(rdram, ctx);
        goto after_36;
    // 0x8006D3F4: nop

    after_36:
    // 0x8006D3F8: ori         $t3, $s0, 0x30
    ctx->r11 = ctx->r16 | 0X30;
    // 0x8006D3FC: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_8006D400:
    // 0x8006D400: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D404: jal         0x800784A4
    // 0x8006D408: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_37;
    // 0x8006D408: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_37:
    // 0x8006D40C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D410: jal         0x800774A0
    // 0x8006D414: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_draw(rdram, ctx);
        goto after_38;
    // 0x8006D414: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_38:
    // 0x8006D418: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D41C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D420: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D424: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006D428: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006D42C: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006D430: jal         0x800A89D0
    // 0x8006D434: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    hud_render_general(rdram, ctx);
        goto after_39;
    // 0x8006D434: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_39:
    // 0x8006D438: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D43C: jal         0x800776B8
    // 0x8006D440: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_clear_coverage(rdram, ctx);
        goto after_40;
    // 0x8006D440: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_40:
    // 0x8006D444: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006D448: lb          $t4, -0x26F4($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X26F4);
    // 0x8006D44C: nop

    // 0x8006D450: beq         $t4, $zero, L_8006D48C
    if (ctx->r12 == 0) {
        // 0x8006D454: nop
    
            goto L_8006D48C;
    }
    // 0x8006D454: nop

    // 0x8006D458: jal         0x800214F8
    // 0x8006D45C: nop

    func_800214C4(rdram, ctx);
        goto after_41;
    // 0x8006D45C: nop

    after_41:
    // 0x8006D460: beq         $v0, $zero, L_8006D48C
    if (ctx->r2 == 0) {
        // 0x8006D464: addiu       $t5, $zero, 0x23
        ctx->r13 = ADD32(0, 0X23);
            goto L_8006D48C;
    }
    // 0x8006D464: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x8006D468: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D46C: sw          $t5, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r13;
    // 0x8006D470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D474: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D478: sw          $t6, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r14;
    // 0x8006D47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D480: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006D484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D488: sb          $zero, -0x26F4($at)
    MEM_B(-0X26F4, ctx->r1) = 0;
L_8006D48C:
    // 0x8006D48C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006D490: addiu       $t0, $t0, -0x2700
    ctx->r8 = ADD32(ctx->r8, -0X2700);
    // 0x8006D494: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8006D498: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8006D49C: beq         $v0, $zero, L_8006D4E4
    if (ctx->r2 == 0) {
        // 0x8006D4A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D4E4;
    }
    // 0x8006D4A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D4A4: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8006D4A8: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8006D4AC: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8006D4B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006D4B4: bgtz        $t9, L_8006D4E4
    if (SIGNED(ctx->r25) > 0) {
        // 0x8006D4B8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006D4E4;
    }
    // 0x8006D4B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D4BC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006D4C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D4C4: jal         0x8006C3EC
    // 0x8006D4C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_42;
    // 0x8006D4C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_42:
    // 0x8006D4CC: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8006D4D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D4D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8006D4D8: jal         0x8006C3EC
    // 0x8006D4DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    level_properties_push(rdram, ctx);
        goto after_43;
    // 0x8006D4DC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_43:
    // 0x8006D4E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006D4E4:
    // 0x8006D4E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D4E8: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
    // 0x8006D4EC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8006D4F0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8006D4F4: blez        $v0, L_8006D5C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006D4F8: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8006D5C0;
    }
    // 0x8006D4F8: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8006D4FC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x8006D500: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8006D504: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D508: bgtz        $t3, L_8006D5C0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8006D50C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006D5C0;
    }
    // 0x8006D50C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D510: lb          $v0, 0x3AA4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3AA4);
    // 0x8006D514: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006D518: beq         $v0, $at, L_8006D54C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D51C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8006D54C;
    }
    // 0x8006D51C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006D520: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D524: beq         $v0, $at, L_8006D554
    if (ctx->r2 == ctx->r1) {
        // 0x8006D528: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8006D554;
    }
    // 0x8006D528: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006D52C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006D530: beq         $v0, $at, L_8006D57C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D534: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006D57C;
    }
    // 0x8006D534: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D538: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D53C: beq         $v0, $at, L_8006D588
    if (ctx->r2 == ctx->r1) {
        // 0x8006D540: nop
    
            goto L_8006D588;
    }
    // 0x8006D540: nop

    // 0x8006D544: b           L_8006D5B4
    // 0x8006D548: nop

        goto L_8006D5B4;
    // 0x8006D548: nop

L_8006D54C:
    // 0x8006D54C: b           L_8006D5B4
    // 0x8006D550: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
        goto L_8006D5B4;
    // 0x8006D550: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
L_8006D554:
    // 0x8006D554: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8006D558: jal         0x80098744
    // 0x8006D55C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    trophyround_adventure(rdram, ctx);
        goto after_44;
    // 0x8006D55C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_44:
    // 0x8006D560: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D564: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8006D568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D56C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D570: sw          $t5, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r13;
    // 0x8006D574: b           L_8006D5B4
    // 0x8006D578: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
        goto L_8006D5B4;
    // 0x8006D578: addiu       $a0, $a0, -0x26FC
    ctx->r4 = ADD32(ctx->r4, -0X26FC);
L_8006D57C:
    // 0x8006D57C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D580: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D584: sb          $t6, -0x26F4($at)
    MEM_B(-0X26F4, ctx->r1) = ctx->r14;
L_8006D588:
    // 0x8006D588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D58C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006D590: lb          $t8, 0x3AA5($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X3AA5);
    // 0x8006D594: sw          $t7, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r15;
    // 0x8006D598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D59C: sw          $t8, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r24;
    // 0x8006D5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5A4: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006D5A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5AC: sw          $zero, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = 0;
    // 0x8006D5B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D5B4:
    // 0x8006D5B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D5B8: sb          $zero, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = 0;
    // 0x8006D5BC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8006D5C0:
    // 0x8006D5C0: beq         $v1, $zero, L_8006D68C
    if (ctx->r3 == 0) {
        // 0x8006D5C4: nop
    
            goto L_8006D68C;
    }
    // 0x8006D5C4: nop

    // 0x8006D5C8: jal         0x8006C530
    // 0x8006D5CC: nop

    level_properties_get(rdram, ctx);
        goto after_45;
    // 0x8006D5CC: nop

    after_45:
    // 0x8006D5D0: beq         $v0, $zero, L_8006D7A0
    if (ctx->r2 == 0) {
        // 0x8006D5D4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D7A0;
    }
    // 0x8006D5D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D5D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D5DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D5E0: addiu       $a3, $a3, 0x3A88
    ctx->r7 = ADD32(ctx->r7, 0X3A88);
    // 0x8006D5E4: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006D5E8: addiu       $a0, $a0, 0x3A74
    ctx->r4 = ADD32(ctx->r4, 0X3A74);
    // 0x8006D5EC: jal         0x8006C46C
    // 0x8006D5F0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_46;
    // 0x8006D5F0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_46:
    // 0x8006D5F4: jal         0x8006F66C
    // 0x8006D5F8: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_47;
    // 0x8006D5F8: nop

    after_47:
    // 0x8006D5FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D600: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006D604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D608: bgez        $v0, L_8006D678
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D60C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8006D678;
    }
    // 0x8006D60C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006D610: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D614: beq         $v0, $at, L_8006D624
    if (ctx->r2 == ctx->r1) {
        // 0x8006D618: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D624;
    }
    // 0x8006D618: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D61C: bne         $v0, $at, L_8006D660
    if (ctx->r2 != ctx->r1) {
        // 0x8006D620: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8006D660;
    }
    // 0x8006D620: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8006D624:
    // 0x8006D624: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D628: bne         $v0, $at, L_8006D64C
    if (ctx->r2 != ctx->r1) {
        // 0x8006D62C: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D64C;
    }
    // 0x8006D62C: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D630: jal         0x8009F1C4
    // 0x8006D634: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_48;
    // 0x8006D634: nop

    after_48:
    // 0x8006D638: beq         $v0, $zero, L_8006D64C
    if (ctx->r2 == 0) {
        // 0x8006D63C: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D64C;
    }
    // 0x8006D63C: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D640: jal         0x8006F5D8
    // 0x8006D644: nop

    swap_lead_player(rdram, ctx);
        goto after_49;
    // 0x8006D644: nop

    after_49:
    // 0x8006D648: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
L_8006D64C:
    // 0x8006D64C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006D650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D654: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8006D658: b           L_8006D7A0
    // 0x8006D65C: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
        goto L_8006D7A0;
    // 0x8006D65C: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
L_8006D660:
    // 0x8006D660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D664: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8006D668: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D66C: sw          $t2, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r10;
    // 0x8006D670: b           L_8006D7A0
    // 0x8006D674: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_8006D7A0;
    // 0x8006D674: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_8006D678:
    // 0x8006D678: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
    // 0x8006D67C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D680: sw          $t4, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r12;
    // 0x8006D684: b           L_8006D7A0
    // 0x8006D688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8006D7A0;
    // 0x8006D688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D68C:
    // 0x8006D68C: jal         0x8006C540
    // 0x8006D690: nop

    func_8006C300(rdram, ctx);
        goto after_50;
    // 0x8006D690: nop

    after_50:
    // 0x8006D694: jal         0x8006C530
    // 0x8006D698: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    level_properties_get(rdram, ctx);
        goto after_51;
    // 0x8006D698: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_51:
    // 0x8006D69C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D6A0: beq         $v0, $zero, L_8006D7A0
    if (ctx->r2 == 0) {
        // 0x8006D6A4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8006D7A0;
    }
    // 0x8006D6A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006D6A8: lh          $t5, -0x26FC($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X26FC);
    // 0x8006D6AC: nop

    // 0x8006D6B0: bne         $t5, $zero, L_8006D7A4
    if (ctx->r13 != 0) {
        // 0x8006D6B4: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6B4: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D6B8: jal         0x800214F8
    // 0x8006D6BC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800214C4(rdram, ctx);
        goto after_52;
    // 0x8006D6BC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_52:
    // 0x8006D6C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D6C4: bne         $v0, $zero, L_8006D6E8
    if (ctx->r2 != 0) {
        // 0x8006D6C8: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D6E8;
    }
    // 0x8006D6C8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D6CC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8006D6D0: nop

    // 0x8006D6D4: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8006D6D8: beq         $t7, $zero, L_8006D7A4
    if (ctx->r15 == 0) {
        // 0x8006D6DC: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6DC: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D6E0: beq         $v1, $zero, L_8006D7A4
    if (ctx->r3 == 0) {
        // 0x8006D6E4: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D7A4;
    }
    // 0x8006D6E4: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D6E8:
    // 0x8006D6E8: beq         $v1, $zero, L_8006D6F8
    if (ctx->r3 == 0) {
        // 0x8006D6EC: nop
    
            goto L_8006D6F8;
    }
    // 0x8006D6EC: nop

    // 0x8006D6F0: jal         0x80000B28
    // 0x8006D6F4: nop

    music_change_on(rdram, ctx);
        goto after_53;
    // 0x8006D6F4: nop

    after_53:
L_8006D6F8:
    // 0x8006D6F8: jal         0x8006F66C
    // 0x8006D6FC: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_54;
    // 0x8006D6FC: nop

    after_54:
    // 0x8006D700: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D704: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D708: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D70C: addiu       $a3, $a3, 0x3A88
    ctx->r7 = ADD32(ctx->r7, 0X3A88);
    // 0x8006D710: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006D714: addiu       $a0, $a0, 0x3A74
    ctx->r4 = ADD32(ctx->r4, 0X3A74);
    // 0x8006D718: jal         0x8006C46C
    // 0x8006D71C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_55;
    // 0x8006D71C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_55:
    // 0x8006D720: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D724: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006D728: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D72C: bgez        $v0, L_8006D79C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D730: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D79C;
    }
    // 0x8006D730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D738: beq         $v0, $at, L_8006D748
    if (ctx->r2 == ctx->r1) {
        // 0x8006D73C: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D748;
    }
    // 0x8006D73C: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D740: bne         $v0, $at, L_8006D784
    if (ctx->r2 != ctx->r1) {
        // 0x8006D744: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8006D784;
    }
    // 0x8006D744: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006D748:
    // 0x8006D748: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D74C: bne         $v0, $at, L_8006D770
    if (ctx->r2 != ctx->r1) {
        // 0x8006D750: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D770;
    }
    // 0x8006D750: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D754: jal         0x8009F1C4
    // 0x8006D758: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_56;
    // 0x8006D758: nop

    after_56:
    // 0x8006D75C: beq         $v0, $zero, L_8006D770
    if (ctx->r2 == 0) {
        // 0x8006D760: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D770;
    }
    // 0x8006D760: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D764: jal         0x8006F5D8
    // 0x8006D768: nop

    swap_lead_player(rdram, ctx);
        goto after_57;
    // 0x8006D768: nop

    after_57:
    // 0x8006D76C: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
L_8006D770:
    // 0x8006D770: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8006D774: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D778: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8006D77C: b           L_8006D7A0
    // 0x8006D780: sw          $t9, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r25;
        goto L_8006D7A0;
    // 0x8006D780: sw          $t9, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r25;
L_8006D784:
    // 0x8006D784: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D788: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8006D78C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D790: sw          $t1, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r9;
    // 0x8006D794: b           L_8006D7A0
    // 0x8006D798: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
        goto L_8006D7A0;
    // 0x8006D798: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_8006D79C:
    // 0x8006D79C: sw          $t3, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r11;
L_8006D7A0:
    // 0x8006D7A0: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D7A4:
    // 0x8006D7A4: beq         $t4, $zero, L_8006D7B8
    if (ctx->r12 == 0) {
        // 0x8006D7A8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8006D7B8;
    }
    // 0x8006D7A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006D7AC: lw          $t5, 0x3A6C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A6C);
    // 0x8006D7B0: nop

    // 0x8006D7B4: beq         $t5, $zero, L_8006D7C8
    if (ctx->r13 == 0) {
        // 0x8006D7B8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006D7C8;
    }
L_8006D7B8:
    // 0x8006D7B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D7BC: lw          $t6, 0x3A7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A7C);
    // 0x8006D7C0: nop

    // 0x8006D7C4: beq         $t6, $zero, L_8006DA78
    if (ctx->r14 == 0) {
        // 0x8006D7C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006DA78;
    }
L_8006D7C8:
    // 0x8006D7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7CC: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006D7D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D7D4: sh          $zero, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = 0;
    // 0x8006D7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7DC: jal         0x8006CE54
    // 0x8006D7E0: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_58;
    // 0x8006D7E0: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    after_58:
    // 0x8006D7E4: jal         0x8009C6E4
    // 0x8006D7E8: nop

    get_save_file_index(rdram, ctx);
        goto after_59;
    // 0x8006D7E8: nop

    after_59:
    // 0x8006D7EC: jal         0x8006EE88
    // 0x8006D7F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_60;
    // 0x8006D7F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x8006D7F4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8006D7F8: nop

    // 0x8006D7FC: beq         $t7, $zero, L_8006D94C
    if (ctx->r15 == 0) {
        // 0x8006D800: nop
    
            goto L_8006D94C;
    }
    // 0x8006D800: nop

    // 0x8006D804: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8006D808: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D80C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006D810: addiu       $s0, $s0, 0x3A94
    ctx->r16 = ADD32(ctx->r16, 0X3A94);
    // 0x8006D814: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x8006D818: beq         $at, $zero, L_8006DA70
    if (ctx->r1 == 0) {
        // 0x8006D81C: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8006DA70;
    }
    // 0x8006D81C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8006D820: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006D824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D828: addu        $at, $at, $t9
    gpr jr_addend_8006D834 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006D82C: lw          $t9, 0x7748($at)
    ctx->r25 = ADD32(ctx->r1, 0X7748);
    // 0x8006D830: nop

    // 0x8006D834: jr          $t9
    // 0x8006D838: nop

    switch (jr_addend_8006D834 >> 2) {
        case 0: goto L_8006D83C; break;
        case 1: goto L_8006D854; break;
        case 2: goto L_8006D86C; break;
        case 3: goto L_8006D884; break;
        case 4: goto L_8006D89C; break;
        case 5: goto L_8006D8B4; break;
        case 6: goto L_8006D914; break;
        case 7: goto L_8006D934; break;
        default: switch_error(__func__, 0x8006D834, 0x800E7748);
    }
    // 0x8006D838: nop

L_8006D83C:
    // 0x8006D83C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006D840: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D844: jal         0x8006DC68
    // 0x8006D848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_61;
    // 0x8006D848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_61:
    // 0x8006D84C: b           L_8006DA70
    // 0x8006D850: nop

        goto L_8006DA70;
    // 0x8006D850: nop

L_8006D854:
    // 0x8006D854: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8006D858: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D85C: jal         0x8006DC68
    // 0x8006D860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_62;
    // 0x8006D860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_62:
    // 0x8006D864: b           L_8006DA70
    // 0x8006D868: nop

        goto L_8006DA70;
    // 0x8006D868: nop

L_8006D86C:
    // 0x8006D86C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8006D870: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D874: jal         0x8006DC68
    // 0x8006D878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_63;
    // 0x8006D878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8006D87C: b           L_8006DA70
    // 0x8006D880: nop

        goto L_8006DA70;
    // 0x8006D880: nop

L_8006D884:
    // 0x8006D884: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8006D888: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D88C: jal         0x8006DC68
    // 0x8006D890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_64;
    // 0x8006D890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8006D894: b           L_8006DA70
    // 0x8006D898: nop

        goto L_8006DA70;
    // 0x8006D898: nop

L_8006D89C:
    // 0x8006D89C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8006D8A0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D8A4: jal         0x8006DC68
    // 0x8006D8A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_65;
    // 0x8006D8A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8006D8AC: b           L_8006DA70
    // 0x8006D8B0: nop

        goto L_8006DA70;
    // 0x8006D8B0: nop

L_8006D8B4:
    // 0x8006D8B4: jal         0x8009F214
    // 0x8006D8B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_66;
    // 0x8006D8B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_66:
    // 0x8006D8BC: beq         $v0, $zero, L_8006D8D4
    if (ctx->r2 == 0) {
        // 0x8006D8C0: nop
    
            goto L_8006D8D4;
    }
    // 0x8006D8C0: nop

    // 0x8006D8C4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8006D8C8: nop

    // 0x8006D8CC: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8006D8D0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8006D8D4:
    // 0x8006D8D4: jal         0x8009F1FC
    // 0x8006D8D8: nop

    is_tt_unlocked(rdram, ctx);
        goto after_67;
    // 0x8006D8D8: nop

    after_67:
    // 0x8006D8DC: beq         $v0, $zero, L_8006D8F4
    if (ctx->r2 == 0) {
        // 0x8006D8E0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006D8F4;
    }
    // 0x8006D8E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006D8E4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8006D8E8: nop

    // 0x8006D8EC: xori        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 ^ 0X3;
    // 0x8006D8F0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_8006D8F4:
    // 0x8006D8F4: jal         0x8008B36C
    // 0x8006D8F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_68;
    // 0x8006D8F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_68:
    // 0x8006D8FC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8006D900: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006D904: jal         0x8006DC68
    // 0x8006D908: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    load_menu_with_level_background(rdram, ctx);
        goto after_69;
    // 0x8006D908: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_69:
    // 0x8006D90C: b           L_8006DA70
    // 0x8006D910: nop

        goto L_8006DA70;
    // 0x8006D910: nop

L_8006D914:
    // 0x8006D914: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006D918: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x8006D91C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006D920: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D924: jal         0x8006DC68
    // 0x8006D928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_70;
    // 0x8006D928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_70:
    // 0x8006D92C: b           L_8006DA70
    // 0x8006D930: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8006DA70;
    // 0x8006D930: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8006D934:
    // 0x8006D934: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006D938: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D93C: jal         0x8006DC68
    // 0x8006D940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_71;
    // 0x8006D940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_71:
    // 0x8006D944: b           L_8006DA70
    // 0x8006D948: nop

        goto L_8006DA70;
    // 0x8006D948: nop

L_8006D94C:
    // 0x8006D94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D950: lw          $t6, 0x3A7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A7C);
    // 0x8006D954: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D958: bne         $t6, $at, L_8006D9B4
    if (ctx->r14 != ctx->r1) {
        // 0x8006D95C: andi        $t9, $s0, 0x10
        ctx->r25 = ctx->r16 & 0X10;
            goto L_8006D9B4;
    }
    // 0x8006D95C: andi        $t9, $s0, 0x10
    ctx->r25 = ctx->r16 & 0X10;
    // 0x8006D960: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D964: addiu       $v0, $v0, 0x17D0
    ctx->r2 = ADD32(ctx->r2, 0X17D0);
    // 0x8006D968: lb          $t7, 0x2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2);
    // 0x8006D96C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D970: bne         $t7, $at, L_8006D990
    if (ctx->r15 != ctx->r1) {
        // 0x8006D974: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8006D990;
    }
    // 0x8006D974: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D978: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006D97C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D980: jal         0x8006DC68
    // 0x8006D984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_72;
    // 0x8006D984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_72:
    // 0x8006D988: b           L_8006DA70
    // 0x8006D98C: nop

        goto L_8006DA70;
    // 0x8006D98C: nop

L_8006D990:
    // 0x8006D990: addiu       $s0, $s0, 0x3A94
    ctx->r16 = ADD32(ctx->r16, 0X3A94);
    // 0x8006D994: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D998: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006D99C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8006D9A0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D9A4: jal         0x8006DC68
    // 0x8006D9A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_73;
    // 0x8006D9A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_73:
    // 0x8006D9AC: b           L_8006DA70
    // 0x8006D9B0: nop

        goto L_8006DA70;
    // 0x8006D9B0: nop

L_8006D9B4:
    // 0x8006D9B4: bne         $t9, $zero, L_8006DA50
    if (ctx->r25 != 0) {
        // 0x8006D9B8: andi        $t1, $s0, 0x2000
        ctx->r9 = ctx->r16 & 0X2000;
            goto L_8006DA50;
    }
    // 0x8006D9B8: andi        $t1, $s0, 0x2000
    ctx->r9 = ctx->r16 & 0X2000;
    // 0x8006D9BC: bne         $t1, $zero, L_8006DA20
    if (ctx->r9 != 0) {
        // 0x8006D9C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006DA20;
    }
    // 0x8006D9C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D9C4: addiu       $v0, $v0, 0x17D0
    ctx->r2 = ADD32(ctx->r2, 0X17D0);
    // 0x8006D9C8: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x8006D9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9D0: sw          $t2, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r10;
    // 0x8006D9D4: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x8006D9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9DC: sw          $t3, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = ctx->r11;
    // 0x8006D9E0: lb          $t4, 0x1($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1);
    // 0x8006D9E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D9E8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8006D9EC: lb          $t6, 0x8($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X8);
    // 0x8006D9F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9F4: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006D9F8: jal         0x8006B2EC
    // 0x8006D9FC: sw          $t6, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r14;
    leveltable_vehicle_default(rdram, ctx);
        goto after_74;
    // 0x8006D9FC: sw          $t6, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r14;
    after_74:
    // 0x8006DA00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DA04: lw          $t7, 0x3A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A88);
    // 0x8006DA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA0C: bgez        $t7, L_8006DA20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006DA10: sw          $v0, 0x3A98($at)
        MEM_W(0X3A98, ctx->r1) = ctx->r2;
            goto L_8006DA20;
    }
    // 0x8006DA10: sw          $v0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r2;
    // 0x8006DA14: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006DA18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA1C: sw          $t8, 0x3A88($at)
    MEM_W(0X3A88, ctx->r1) = ctx->r24;
L_8006DA20:
    // 0x8006DA20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DA24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DA28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DA2C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DA30: lw          $a3, 0x3A98($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3A98);
    // 0x8006DA34: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006DA38: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006DA3C: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006DA40: jal         0x8006CD98
    // 0x8006DA44: nop

    load_level_game(rdram, ctx);
        goto after_75;
    // 0x8006DA44: nop

    after_75:
    // 0x8006DA48: b           L_8006DA70
    // 0x8006DA4C: nop

        goto L_8006DA70;
    // 0x8006DA4C: nop

L_8006DA50:
    // 0x8006DA50: jal         0x8009C6E4
    // 0x8006DA54: nop

    get_save_file_index(rdram, ctx);
        goto after_76;
    // 0x8006DA54: nop

    after_76:
    // 0x8006DA58: jal         0x8006EE88
    // 0x8006DA5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_77;
    // 0x8006DA5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_77:
    // 0x8006DA60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006DA64: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DA68: jal         0x8006DC68
    // 0x8006DA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_78;
    // 0x8006DA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_78:
L_8006DA70:
    // 0x8006DA70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA74: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
L_8006DA78:
    // 0x8006DA78: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006DA7C: lw          $t9, 0x3A78($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A78);
    // 0x8006DA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA84: beq         $t9, $zero, L_8006DAD8
    if (ctx->r25 == 0) {
        // 0x8006DA88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006DAD8;
    }
    // 0x8006DA88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006DA8C: jal         0x8006CE54
    // 0x8006DA90: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_79;
    // 0x8006DA90: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    after_79:
    // 0x8006DA94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DA98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DA9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DAA0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DAA4: lw          $a3, 0x3A98($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3A98);
    // 0x8006DAA8: lw          $a2, 0x3A84($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3A84);
    // 0x8006DAAC: lw          $a1, 0x3A80($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3A80);
    // 0x8006DAB0: lw          $a0, 0x3A74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A74);
    // 0x8006DAB4: jal         0x8006CD98
    // 0x8006DAB8: nop

    load_level_game(rdram, ctx);
        goto after_80;
    // 0x8006DAB8: nop

    after_80:
    // 0x8006DABC: jal         0x8009C6E4
    // 0x8006DAC0: nop

    get_save_file_index(rdram, ctx);
        goto after_81;
    // 0x8006DAC0: nop

    after_81:
    // 0x8006DAC4: jal         0x8006EE88
    // 0x8006DAC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_82;
    // 0x8006DAC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_82:
    // 0x8006DACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DAD0: sw          $zero, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = 0;
    // 0x8006DAD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006DAD8:
    // 0x8006DAD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006DADC: jr          $ra
    // 0x8006DAE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006DAE0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void set_drumstick_unlock_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAE4: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8006DAE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006DAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAF0: sb          $t6, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = ctx->r14;
    // 0x8006DAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DAFC: jal         0x80094AE8
    // 0x8006DB00: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_0;
    // 0x8006DB00: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    after_0:
    // 0x8006DB04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DB08: jal         0x800C06F8
    // 0x8006DB0C: addiu       $a0, $a0, -0x2688
    ctx->r4 = ADD32(ctx->r4, -0X2688);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006DB0C: addiu       $a0, $a0, -0x2688
    ctx->r4 = ADD32(ctx->r4, -0X2688);
    after_1:
    // 0x8006DB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DB14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DB18: jr          $ra
    // 0x8006DB1C: nop

    return;
    // 0x8006DB1C: nop

;}
RECOMP_FUNC void race_postrace_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB20: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x8006DB24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB28: jr          $ra
    // 0x8006DB2C: sb          $t6, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = ctx->r14;
    return;
    // 0x8006DB2C: sb          $t6, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8006D8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DB34: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006DB38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006DB3C: beq         $t6, $at, L_8006DBA0
    if (ctx->r14 == ctx->r1) {
        // 0x8006DB40: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006DBA0;
    }
    // 0x8006DB40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006DB44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DB48: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x8006DB4C: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x8006DB50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB54: sw          $t7, 0x3A74($at)
    MEM_W(0X3A74, ctx->r1) = ctx->r15;
    // 0x8006DB58: lb          $v1, 0xF($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XF);
    // 0x8006DB5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DB60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DB64: addiu       $a2, $a2, 0x3A88
    ctx->r6 = ADD32(ctx->r6, 0X3A88);
    // 0x8006DB68: addiu       $a1, $a1, 0x3A84
    ctx->r5 = ADD32(ctx->r5, 0X3A84);
    // 0x8006DB6C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006DB70: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x8006DB74: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8006DB78: bltz        $v1, L_8006DB84
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006DB7C: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8006DB84;
    }
    // 0x8006DB7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8006DB80: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8006DB84:
    // 0x8006DB84: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x8006DB88: lb          $v1, 0x8($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X8);
    // 0x8006DB8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006DB90: bltz        $v1, L_8006DB9C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006DB94: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006DB9C;
    }
    // 0x8006DB94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB98: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006DB9C:
    // 0x8006DB9C: sw          $t0, 0x3A78($at)
    MEM_W(0X3A78, ctx->r1) = ctx->r8;
L_8006DBA0:
    // 0x8006DBA0: jr          $ra
    // 0x8006DBA4: nop

    return;
    // 0x8006DBA4: nop

;}
RECOMP_FUNC void func_8006D968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DBAC: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006DBB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006DBB4: beq         $t6, $at, L_8006DC44
    if (ctx->r14 == ctx->r1) {
        // 0x8006DBB8: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006DC44;
    }
    // 0x8006DBB8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DBBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DBC0: lw          $t7, 0x3A74($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A74);
    // 0x8006DBC4: addiu       $a2, $a2, 0x17D0
    ctx->r6 = ADD32(ctx->r6, 0X17D0);
    // 0x8006DBC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006DBCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DBD0: addiu       $v0, $v0, 0x17D2
    ctx->r2 = ADD32(ctx->r2, 0X17D2);
    // 0x8006DBD4: addiu       $v1, $v1, 0x17D0
    ctx->r3 = ADD32(ctx->r3, 0X17D0);
    // 0x8006DBD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006DBDC: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_8006DBE0:
    // 0x8006DBE0: lb          $t8, 0x8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X8);
    // 0x8006DBE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006DBE8: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x8006DBEC: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x8006DBF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006DBF4: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8006DBF8: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8006DBFC: nop

    // 0x8006DC00: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x8006DC04: lb          $t1, 0xD($a1)
    ctx->r9 = MEM_B(ctx->r5, 0XD);
    // 0x8006DC08: nop

    // 0x8006DC0C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
    // 0x8006DC10: lb          $t2, 0x11($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X11);
    // 0x8006DC14: nop

    // 0x8006DC18: sb          $t2, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r10;
    // 0x8006DC1C: lb          $t3, 0x13($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X13);
    // 0x8006DC20: bne         $v1, $v0, L_8006DBE0
    if (ctx->r3 != ctx->r2) {
        // 0x8006DC24: sb          $t3, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r11;
            goto L_8006DBE0;
    }
    // 0x8006DC24: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x8006DC28: lb          $t4, 0x16($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X16);
    // 0x8006DC2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006DC30: sb          $t4, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r12;
    // 0x8006DC34: lb          $t5, 0x17($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X17);
    // 0x8006DC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC3C: sb          $t5, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r13;
    // 0x8006DC40: sw          $t6, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r14;
L_8006DC44:
    // 0x8006DC44: jr          $ra
    // 0x8006DC48: nop

    return;
    // 0x8006DC48: nop

;}
RECOMP_FUNC void get_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DC50: lw          $v0, 0x3A6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A6C);
    // 0x8006DC54: jr          $ra
    // 0x8006DC58: nop

    return;
    // 0x8006DC58: nop

;}
RECOMP_FUNC void set_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC60: jr          $ra
    // 0x8006DC64: sw          $a0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r4;
    return;
    // 0x8006DC64: sw          $a0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void load_menu_with_level_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DC6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DC70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DC74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DC78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DC7C: jal         0x8006EF3C
    // 0x8006DC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006DC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DC84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC8C: sw          $v0, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r2;
    // 0x8006DC90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC94: sw          $v0, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = ctx->r2;
    // 0x8006DC98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006DC9C: jal         0x80004A60
    // 0x8006DCA0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x8006DCA0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x8006DCA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006DCA8: jal         0x80004A60
    // 0x8006DCAC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x8006DCAC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_2:
    // 0x8006DCB0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006DCB4: jal         0x80004A60
    // 0x8006DCB8: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x8006DCB8: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_3:
    // 0x8006DCBC: jal         0x800660E0
    // 0x8006DCC0: nop

    cam_init(rdram, ctx);
        goto after_4;
    // 0x8006DCC0: nop

    after_4:
    // 0x8006DCC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DCC8: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
    // 0x8006DCCC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DCD0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006DCD4: bne         $t6, $zero, L_8006DD08
    if (ctx->r14 != 0) {
        // 0x8006DCD8: nop
    
            goto L_8006DD08;
    }
    // 0x8006DCD8: nop

    // 0x8006DCDC: bgez        $a0, L_8006DCF0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006DCE0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8006DCF0;
    }
    // 0x8006DCE0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DCE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DCE8: b           L_8006DD08
    // 0x8006DCEC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8006DD08;
    // 0x8006DCEC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8006DCF0:
    // 0x8006DCF0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006DCF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DCF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006DCFC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006DD00: jal         0x8006DD7C
    // 0x8006DD04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    load_level_menu(rdram, ctx);
        goto after_5;
    // 0x8006DD04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
L_8006DD08:
    // 0x8006DD08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DD0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006DD10: beq         $a0, $at, L_8006DD28
    if (ctx->r4 == ctx->r1) {
        // 0x8006DD14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006DD28;
    }
    // 0x8006DD14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DD18: beq         $a0, $at, L_8006DD28
    if (ctx->r4 == ctx->r1) {
        // 0x8006DD1C: nop
    
            goto L_8006DD28;
    }
    // 0x8006DD1C: nop

    // 0x8006DD20: bne         $a0, $zero, L_8006DD38
    if (ctx->r4 != 0) {
        // 0x8006DD24: nop
    
            goto L_8006DD38;
    }
    // 0x8006DD24: nop

L_8006DD28:
    // 0x8006DD28: jal         0x80081810
    // 0x8006DD2C: nop

    reset_title_logo_scale(rdram, ctx);
        goto after_6;
    // 0x8006DD2C: nop

    after_6:
    // 0x8006DD30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DD34: nop

L_8006DD38:
    // 0x8006DD38: jal         0x80081820
    // 0x8006DD3C: nop

    menu_init(rdram, ctx);
        goto after_7;
    // 0x8006DD3C: nop

    after_7:
    // 0x8006DD40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DD44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD48: sw          $zero, 0x3A84($at)
    MEM_W(0X3A84, ctx->r1) = 0;
    // 0x8006DD4C: jr          $ra
    // 0x8006DD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006DD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD58: jr          $ra
    // 0x8006DD5C: sw          $a0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r4;
    return;
    // 0x8006DD5C: sw          $a0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void set_vehicle_id_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD64: jr          $ra
    // 0x8006DD68: sw          $a0, 0x3A9C($at)
    MEM_W(0X3A9C, ctx->r1) = ctx->r4;
    return;
    // 0x8006DD68: sw          $a0, 0x3A9C($at)
    MEM_W(0X3A9C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DD70: lw          $v0, 0x3A98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A98);
    // 0x8006DD74: jr          $ra
    // 0x8006DD78: nop

    return;
    // 0x8006DD78: nop

;}
RECOMP_FUNC void load_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DD80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DD84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DD88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DD8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DD90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006DD94: jal         0x800712F0
    // 0x8006DD98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DD98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DD9C: jal         0x800660E0
    // 0x8006DDA0: nop

    cam_init(rdram, ctx);
        goto after_1;
    // 0x8006DDA0: nop

    after_1:
    // 0x8006DDA4: jal         0x800C35A0
    // 0x8006DDA8: nop

    load_game_text_table(rdram, ctx);
        goto after_2;
    // 0x8006DDA8: nop

    after_2:
    // 0x8006DDAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8006DDB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DDB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006DDB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006DDBC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DDC0: jal         0x8006B490
    // 0x8006DDC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_3;
    // 0x8006DDC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8006DDC8: jal         0x80066450
    // 0x8006DDCC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_4;
    // 0x8006DDCC: nop

    after_4:
    // 0x8006DDD0: jal         0x8009F230
    // 0x8006DDD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_5;
    // 0x8006DDD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8006DDD8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8006DDDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006DDE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8006DDE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006DDE8: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8006DDEC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8006DDF0: jal         0x800AEC88
    // 0x8006DDF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_6;
    // 0x8006DDF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8006DDF8: jal         0x8001BF54
    // 0x8006DDFC: nop

    ainode_update(rdram, ctx);
        goto after_7;
    // 0x8006DDFC: nop

    after_7:
    // 0x8006DE00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006DE04: jal         0x800CD7C0
    // 0x8006DE08: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8006DE08: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x8006DE0C: jal         0x800712F0
    // 0x8006DE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_9;
    // 0x8006DE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8006DE14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DE18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DE1C: jr          $ra
    // 0x8006DE20: nop

    return;
    // 0x8006DE20: nop

;}
RECOMP_FUNC void unload_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DE28: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
    // 0x8006DE2C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE34: bne         $t6, $zero, L_8006DE88
    if (ctx->r14 != 0) {
        // 0x8006DE38: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006DE88;
    }
    // 0x8006DE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DE40: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8006DE44: jal         0x800712F0
    // 0x8006DE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DE4C: jal         0x8006C13C
    // 0x8006DE50: nop

    level_free(rdram, ctx);
        goto after_1;
    // 0x8006DE50: nop

    after_1:
    // 0x8006DE54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DE58: jal         0x800C06F8
    // 0x8006DE5C: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006DE5C: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    after_2:
    // 0x8006DE60: jal         0x800AE7D0
    // 0x8006DE64: nop

    reset_particles(rdram, ctx);
        goto after_3;
    // 0x8006DE64: nop

    after_3:
    // 0x8006DE68: jal         0x800A057C
    // 0x8006DE6C: nop

    hud_free(rdram, ctx);
        goto after_4;
    // 0x8006DE6C: nop

    after_4:
    // 0x8006DE70: jal         0x800C3624
    // 0x8006DE74: nop

    free_game_text_table(rdram, ctx);
        goto after_5;
    // 0x8006DE74: nop

    after_5:
    // 0x8006DE78: jal         0x800712F0
    // 0x8006DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_6;
    // 0x8006DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8006DE80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DE84: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
L_8006DE88:
    // 0x8006DE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE8C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DE90: jr          $ra
    // 0x8006DE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006DE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void update_menu_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DEA0: jal         0x800C7940
    // 0x8006DEA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bgload_active(rdram, ctx);
        goto after_0;
    // 0x8006DEA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006DEA8: bne         $v0, $zero, L_8006DF2C
    if (ctx->r2 != 0) {
        // 0x8006DEAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006DF2C;
    }
    // 0x8006DEAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DEB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DEB4: jal         0x80010994
    // 0x8006DEB8: nop

    obj_update(rdram, ctx);
        goto after_1;
    // 0x8006DEB8: nop

    after_1:
    // 0x8006DEBC: jal         0x8001004C
    // 0x8006DEC0: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_2;
    // 0x8006DEC0: nop

    after_2:
    // 0x8006DEC4: jal         0x8001BF54
    // 0x8006DEC8: nop

    ainode_update(rdram, ctx);
        goto after_3;
    // 0x8006DEC8: nop

    after_3:
    // 0x8006DECC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006DED0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DED4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DED8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DEDC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DEE0: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006DEE4: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006DEE8: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006DEEC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006DEF0: jal         0x80024D94
    // 0x8006DEF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_scene(rdram, ctx);
        goto after_4;
    // 0x8006DEF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006DEF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DEFC: jal         0x800C3998
    // 0x8006DF00: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_5;
    // 0x8006DF00: nop

    after_5:
    // 0x8006DF04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF08: jal         0x800784A4
    // 0x8006DF0C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_6;
    // 0x8006DF0C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_6:
    // 0x8006DF10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF14: jal         0x800774A0
    // 0x8006DF18: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_draw(rdram, ctx);
        goto after_7;
    // 0x8006DF18: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_7:
    // 0x8006DF1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF20: jal         0x800776B8
    // 0x8006DF24: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_clear_coverage(rdram, ctx);
        goto after_8;
    // 0x8006DF24: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_8:
    // 0x8006DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006DF2C:
    // 0x8006DF2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DF30: jr          $ra
    // 0x8006DF34: nop

    return;
    // 0x8006DF34: nop

;}
RECOMP_FUNC void mode_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DF40: lb          $t6, 0x3A94($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A94);
    // 0x8006DF44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006DF48: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006DF4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DF50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006DF54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006DF58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006DF5C: bne         $t6, $zero, L_8006DF80
    if (ctx->r14 != 0) {
        // 0x8006DF60: sb          $zero, 0x3A96($at)
        MEM_B(0X3A96, ctx->r1) = 0;
            goto L_8006DF80;
    }
    // 0x8006DF60: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006DF64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DF68: lw          $t7, 0x3A70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A70);
    // 0x8006DF6C: nop

    // 0x8006DF70: beq         $t7, $zero, L_8006DF84
    if (ctx->r15 == 0) {
        // 0x8006DF74: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8006DF84;
    }
    // 0x8006DF74: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8006DF78: jal         0x8006DE98
    // 0x8006DF7C: nop

    update_menu_scene(rdram, ctx);
        goto after_0;
    // 0x8006DF7C: nop

    after_0:
L_8006DF80:
    // 0x8006DF80: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8006DF84:
    // 0x8006DF84: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006DF88: addiu       $s0, $s0, 0x1778
    ctx->r16 = ADD32(ctx->r16, 0X1778);
    // 0x8006DF8C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DF90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DF94: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DF98: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006DF9C: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006DFA0: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006DFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006DFA8: jal         0x800819F4
    // 0x8006DFAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    menu_loop(rdram, ctx);
        goto after_1;
    // 0x8006DFAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8006DFB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006DFB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DFB8: sw          $t9, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = ctx->r25;
    // 0x8006DFBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006DFC0: bne         $v0, $at, L_8006DFD4
    if (ctx->r2 != ctx->r1) {
        // 0x8006DFC4: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_8006DFD4;
    }
    // 0x8006DFC4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006DFC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DFCC: b           L_8006E518
    // 0x8006DFD0: sw          $zero, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = 0;
        goto L_8006E518;
    // 0x8006DFD0: sw          $zero, 0x3A70($at)
    MEM_W(0X3A70, ctx->r1) = 0;
L_8006DFD4:
    // 0x8006DFD4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8006DFD8: beq         $v0, $v1, L_8006E0D0
    if (ctx->r2 == ctx->r3) {
        // 0x8006DFDC: andi        $t4, $v0, 0x200
        ctx->r12 = ctx->r2 & 0X200;
            goto L_8006E0D0;
    }
    // 0x8006DFDC: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x8006DFE0: beq         $t4, $zero, L_8006E0D0
    if (ctx->r12 == 0) {
        // 0x8006DFE4: nop
    
            goto L_8006E0D0;
    }
    // 0x8006DFE4: nop

    // 0x8006DFE8: jal         0x8006DE24
    // 0x8006DFEC: nop

    unload_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006DFEC: nop

    after_2:
    // 0x8006DFF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006DFF4: lw          $t5, 0x3A68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A68);
    // 0x8006DFF8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DFFC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006E000: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006E004: lw          $t7, 0x1770($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1770);
    // 0x8006E008: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006E00C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006E010: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006E014: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E018: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E01C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006E020: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E024: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006E028: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006E02C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006E030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E034: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006E038: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E03C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E040: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E044: andi        $a0, $t6, 0x7F
    ctx->r4 = ctx->r14 & 0X7F;
    // 0x8006E048: jal         0x8006B2EC
    // 0x8006E04C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x8006E04C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    after_3:
    // 0x8006E050: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E054: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E058: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E05C: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E060: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E064: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E068: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006E06C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006E070: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E074: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8006E078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E07C: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E084: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006E088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E08C: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006E090: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E094: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E098: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E09C: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E0A0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E0A4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E0A8: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E0AC: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E0B0: jal         0x8006CD98
    // 0x8006E0B4: nop

    load_level_game(rdram, ctx);
        goto after_4;
    // 0x8006E0B4: nop

    after_4:
    // 0x8006E0B8: jal         0x8009C6E4
    // 0x8006E0BC: nop

    get_save_file_index(rdram, ctx);
        goto after_5;
    // 0x8006E0BC: nop

    after_5:
    // 0x8006E0C0: jal         0x8006EE88
    // 0x8006E0C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_6;
    // 0x8006E0C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006E0C8: b           L_8006E51C
    // 0x8006E0CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E0CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E0D0:
    // 0x8006E0D0: beq         $v0, $v1, L_8006E338
    if (ctx->r2 == ctx->r3) {
        // 0x8006E0D4: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_8006E338;
    }
    // 0x8006E0D4: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x8006E0D8: beq         $t9, $zero, L_8006E33C
    if (ctx->r25 == 0) {
        // 0x8006E0DC: andi        $t4, $v0, 0x80
        ctx->r12 = ctx->r2 & 0X80;
            goto L_8006E33C;
    }
    // 0x8006E0DC: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x8006E0E0: jal         0x8006CE54
    // 0x8006E0E4: nop

    unload_level_game(rdram, ctx);
        goto after_7;
    // 0x8006E0E4: nop

    after_7:
    // 0x8006E0E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E0EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E0F0: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    // 0x8006E0F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E0F8: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x8006E0FC: sb          $zero, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = 0;
    // 0x8006E100: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006E104: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x8006E108: beq         $at, $zero, L_8006E320
    if (ctx->r1 == 0) {
        // 0x8006E10C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8006E320;
    }
    // 0x8006E10C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006E110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E114: addu        $at, $at, $t6
    gpr jr_addend_8006E120 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006E118: lw          $t6, 0x7768($at)
    ctx->r14 = ADD32(ctx->r1, 0X7768);
    // 0x8006E11C: nop

    // 0x8006E120: jr          $t6
    // 0x8006E124: nop

    switch (jr_addend_8006E120 >> 2) {
        case 0: goto L_8006E1B0; break;
        case 1: goto L_8006E24C; break;
        case 2: goto L_8006E294; break;
        case 3: goto L_8006E320; break;
        case 4: goto L_8006E128; break;
        case 5: goto L_8006E320; break;
        case 6: goto L_8006E320; break;
        case 7: goto L_8006E320; break;
        case 8: goto L_8006E320; break;
        case 9: goto L_8006E320; break;
        case 10: goto L_8006E320; break;
        case 11: goto L_8006E320; break;
        case 12: goto L_8006E320; break;
        case 13: goto L_8006E140; break;
        default: switch_error(__func__, 0x8006E120, 0x800E7768);
    }
    // 0x8006E124: nop

L_8006E128:
    // 0x8006E128: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006E12C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006E130: jal         0x8006DC68
    // 0x8006E134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_8;
    // 0x8006E134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8006E138: b           L_8006E51C
    // 0x8006E13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E140:
    // 0x8006E140: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E144: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E148: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E14C: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E150: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E154: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E158: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006E15C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006E160: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E164: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8006E168: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E16C: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E170: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E174: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E178: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E17C: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E180: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E184: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E188: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E18C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E190: jal         0x8006CD98
    // 0x8006E194: nop

    load_level_game(rdram, ctx);
        goto after_9;
    // 0x8006E194: nop

    after_9:
    // 0x8006E198: jal         0x8009C6E4
    // 0x8006E19C: nop

    get_save_file_index(rdram, ctx);
        goto after_10;
    // 0x8006E19C: nop

    after_10:
    // 0x8006E1A0: jal         0x8006EE88
    // 0x8006E1A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_11;
    // 0x8006E1A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006E1A8: b           L_8006E51C
    // 0x8006E1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E1AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E1B0:
    // 0x8006E1B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E1B4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E1B8: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8006E1BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E1C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E1C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E1C8: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E1CC: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E1D0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E1D4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006E1D8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006E1DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8006E1E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E1E4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006E1E8: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E1EC: lb          $v0, 0xF($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XF);
    // 0x8006E1F0: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x8006E1F4: bltz        $v0, L_8006E200
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006E1F8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8006E200;
    }
    // 0x8006E1F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E1FC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8006E200:
    // 0x8006E200: addu        $t4, $a1, $v1
    ctx->r12 = ADD32(ctx->r5, ctx->r3);
    // 0x8006E204: lb          $v0, 0x8($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X8);
    // 0x8006E208: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E20C: bltz        $v0, L_8006E218
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006E210: addiu       $v1, $v1, 0x3A80
        ctx->r3 = ADD32(ctx->r3, 0X3A80);
            goto L_8006E218;
    }
    // 0x8006E210: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E214: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_8006E218:
    // 0x8006E218: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E21C: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E220: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E224: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E228: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E22C: jal         0x8006CD98
    // 0x8006E230: nop

    load_level_game(rdram, ctx);
        goto after_12;
    // 0x8006E230: nop

    after_12:
    // 0x8006E234: jal         0x8009C6E4
    // 0x8006E238: nop

    get_save_file_index(rdram, ctx);
        goto after_13;
    // 0x8006E238: nop

    after_13:
    // 0x8006E23C: jal         0x8006EE88
    // 0x8006E240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_14;
    // 0x8006E240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8006E244: b           L_8006E51C
    // 0x8006E248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E24C:
    // 0x8006E24C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E250: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E254: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E25C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E260: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E264: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E268: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E26C: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E270: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E274: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E278: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E27C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E280: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E284: jal         0x8006CD98
    // 0x8006E288: nop

    load_level_game(rdram, ctx);
        goto after_15;
    // 0x8006E288: nop

    after_15:
    // 0x8006E28C: b           L_8006E51C
    // 0x8006E290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E294:
    // 0x8006E294: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E298: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E29C: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E2A0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E2A4: lb          $t7, 0x1($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1);
    // 0x8006E2A8: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006E2AC: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8006E2B0: lb          $t6, 0xF($a1)
    ctx->r14 = MEM_B(ctx->r5, 0XF);
    // 0x8006E2B4: lb          $t9, 0x8($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X8);
    // 0x8006E2B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E2BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E2C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E2C4: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E2C8: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E2CC: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E2D0: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8006E2D4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8006E2D8: jal         0x8006B2EC
    // 0x8006E2DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    leveltable_vehicle_default(rdram, ctx);
        goto after_16;
    // 0x8006E2DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    after_16:
    // 0x8006E2E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E2E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E2E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E2EC: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E2F0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E2F4: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E2F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E2FC: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E300: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E304: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E308: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E30C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006E310: jal         0x8006CD98
    // 0x8006E314: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_17;
    // 0x8006E314: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x8006E318: b           L_8006E51C
    // 0x8006E31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E320:
    // 0x8006E320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E324: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006E328: jal         0x8006DC68
    // 0x8006E32C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_18;
    // 0x8006E32C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x8006E330: b           L_8006E51C
    // 0x8006E334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E51C;
    // 0x8006E334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E338:
    // 0x8006E338: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
L_8006E33C:
    // 0x8006E33C: beq         $t4, $zero, L_8006E45C
    if (ctx->r12 == 0) {
        // 0x8006E340: nop
    
            goto L_8006E45C;
    }
    // 0x8006E340: nop

    // 0x8006E344: beq         $v0, $v1, L_8006E45C
    if (ctx->r2 == ctx->r3) {
        // 0x8006E348: nop
    
            goto L_8006E45C;
    }
    // 0x8006E348: nop

    // 0x8006E34C: jal         0x8006DE24
    // 0x8006E350: nop

    unload_level_menu(rdram, ctx);
        goto after_19;
    // 0x8006E350: nop

    after_19:
    // 0x8006E354: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E358: lw          $t5, 0x3A68($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3A68);
    // 0x8006E35C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E360: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006E364: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006E368: lw          $t7, 0x1770($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1770);
    // 0x8006E36C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E370: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006E374: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006E378: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E37C: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006E380: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006E384: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E388: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E38C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E390: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006E394: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006E398: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E39C: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006E3A0: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E3A4: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    // 0x8006E3A8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006E3AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E3B0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006E3B4: andi        $t6, $t2, 0x7F
    ctx->r14 = ctx->r10 & 0X7F;
    // 0x8006E3B8: sb          $t6, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r14;
    // 0x8006E3BC: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8006E3C0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8006E3C4: lb          $t8, 0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2);
    // 0x8006E3C8: lb          $t9, 0x4($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X4);
    // 0x8006E3CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E3D0: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E3D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E3D8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006E3DC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8006E3E0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E3E4: lb          $t4, 0xC($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XC);
    // 0x8006E3E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E3EC: addiu       $t3, $t3, 0x3A88
    ctx->r11 = ADD32(ctx->r11, 0X3A88);
    // 0x8006E3F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E3F4: jal         0x8009C794
    // 0x8006E3F8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    get_player_selected_vehicle(rdram, ctx);
        goto after_20;
    // 0x8006E3F8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    after_20:
    // 0x8006E3FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E400: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E404: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E408: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E40C: lbu         $t6, 0x4A($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4A);
    // 0x8006E410: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E414: addiu       $t1, $t1, 0x3A84
    ctx->r9 = ADD32(ctx->r9, 0X3A84);
    // 0x8006E418: addiu       $t0, $t0, 0x3A74
    ctx->r8 = ADD32(ctx->r8, 0X3A74);
    // 0x8006E41C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E420: addiu       $v1, $v1, 0x3A80
    ctx->r3 = ADD32(ctx->r3, 0X3A80);
    // 0x8006E424: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E428: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E42C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8006E430: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8006E434: jal         0x8006CD98
    // 0x8006E438: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_21;
    // 0x8006E438: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x8006E43C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006E440: lw          $t8, 0x3A9C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3A9C);
    // 0x8006E444: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E44C: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E450: sw          $zero, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = 0;
    // 0x8006E454: b           L_8006E518
    // 0x8006E458: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_8006E518;
    // 0x8006E458: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8006E45C:
    // 0x8006E45C: blez        $v0, L_8006E51C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006E460: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E460: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E464: jal         0x8006DE24
    // 0x8006E468: nop

    unload_level_menu(rdram, ctx);
        goto after_22;
    // 0x8006E468: nop

    after_22:
    // 0x8006E46C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E470: lw          $t9, 0x3A68($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A68);
    // 0x8006E474: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E478: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006E47C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006E480: lw          $t5, 0x1770($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1770);
    // 0x8006E484: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x8006E488: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006E48C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8006E490: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8006E494: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8006E498: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8006E49C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E4A0: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8006E4A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006E4A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E4AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E4B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006E4B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E4BC: addiu       $t2, $t2, 0x3A98
    ctx->r10 = ADD32(ctx->r10, 0X3A98);
    // 0x8006E4C0: sw          $zero, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = 0;
    // 0x8006E4C4: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006E4C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E4CC: jal         0x8006CD24
    // 0x8006E4D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_next_ingame_level(rdram, ctx);
        goto after_23;
    // 0x8006E4D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_23:
    // 0x8006E4D4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E4D8: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E4DC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E4E0: nop

    // 0x8006E4E4: lbu         $t5, 0x4B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4B);
    // 0x8006E4E8: nop

    // 0x8006E4EC: beq         $t5, $zero, L_8006E51C
    if (ctx->r13 == 0) {
        // 0x8006E4F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E4F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E4F4: jal         0x8009C814
    // 0x8006E4F8: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_24;
    // 0x8006E4F8: nop

    after_24:
    // 0x8006E4FC: bne         $v0, $zero, L_8006E51C
    if (ctx->r2 != 0) {
        // 0x8006E500: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E51C;
    }
    // 0x8006E500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E504: jal         0x80000B28
    // 0x8006E508: nop

    music_change_on(rdram, ctx);
        goto after_25;
    // 0x8006E508: nop

    after_25:
    // 0x8006E50C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E510: nop

    // 0x8006E514: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
L_8006E518:
    // 0x8006E518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E51C:
    // 0x8006E51C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006E520: jr          $ra
    // 0x8006E524: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006E524: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_level_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E52C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006E530: lb          $t6, 0x3A94($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A94);
    // 0x8006E534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E53C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E540: bne         $t6, $zero, L_8006E5AC
    if (ctx->r14 != 0) {
        // 0x8006E544: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8006E5AC;
    }
    // 0x8006E544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006E548: jal         0x8006DE24
    // 0x8006E54C: nop

    unload_level_menu(rdram, ctx);
        goto after_0;
    // 0x8006E54C: nop

    after_0:
    // 0x8006E550: jal         0x800C7940
    // 0x8006E554: nop

    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8006E554: nop

    after_1:
    // 0x8006E558: bne         $v0, $zero, L_8006E5AC
    if (ctx->r2 != 0) {
        // 0x8006E55C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8006E5AC;
    }
    // 0x8006E55C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E560: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E564: lw          $t7, 0x3A68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A68);
    // 0x8006E568: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E56C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006E570: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006E574: lw          $t9, 0x1770($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1770);
    // 0x8006E578: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006E57C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006E580: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8006E584: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006E588: lui         $t1, 0xE900
    ctx->r9 = S32(0XE900 << 16);
    // 0x8006E58C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8006E590: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8006E594: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006E598: lui         $t3, 0xB800
    ctx->r11 = S32(0XB800 << 16);
    // 0x8006E59C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8006E5A0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006E5A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E5A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8006E5AC:
    // 0x8006E5AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006E5B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006E5B4: beq         $t4, $at, L_8006E5E4
    if (ctx->r12 == ctx->r1) {
        // 0x8006E5B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8006E5E4;
    }
    // 0x8006E5B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006E5BC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006E5C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006E5C4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8006E5C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006E5CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006E5D0: jal         0x8006DD7C
    // 0x8006E5D4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    load_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006E5D4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8006E5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E5DC: b           L_8006E5EC
    // 0x8006E5E0: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
        goto L_8006E5EC;
    // 0x8006E5E0: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
L_8006E5E4:
    // 0x8006E5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E5E8: sb          $t6, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = ctx->r14;
L_8006E5EC:
    // 0x8006E5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E5F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E5F4: jr          $ra
    // 0x8006E5F8: nop

    return;
    // 0x8006E5F8: nop

;}
RECOMP_FUNC void calc_and_alloc_heap_for_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006E600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E604: jal         0x8006A8F0
    // 0x8006E608: nop

    level_global_init(rdram, ctx);
        goto after_0;
    // 0x8006E608: nop

    after_0:
    // 0x8006E60C: jal         0x8009C698
    // 0x8006E610: nop

    reset_character_id_slots(rdram, ctx);
        goto after_1;
    // 0x8006E610: nop

    after_1:
    // 0x8006E614: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006E618: jal         0x8006B464
    // 0x8006E61C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8006E61C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8006E620: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8006E624: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E628: addiu       $v1, $zero, 0x118
    ctx->r3 = ADD32(0, 0X118);
    // 0x8006E62C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8006E630: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x8006E634: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006E638: addu        $t0, $a2, $t8
    ctx->r8 = ADD32(ctx->r6, ctx->r24);
    // 0x8006E63C: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8006E640: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8006E644: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8006E648: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8006E64C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8006E650: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E654: addu        $ra, $t5, $v0
    ctx->r31 = ADD32(ctx->r13, ctx->r2);
    // 0x8006E658: addu        $t9, $ra, $v0
    ctx->r25 = ADD32(ctx->r31, ctx->r2);
    // 0x8006E65C: addu        $t7, $t9, $v0
    ctx->r15 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E660: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8006E664: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006E668: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E66C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E670: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    // 0x8006E674: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006E678: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8006E67C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8006E680: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8006E684: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8006E688: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8006E68C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8006E690: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8006E694: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8006E698: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8006E69C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8006E6A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006E6A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8006E6A8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8006E6AC: jal         0x80070EDC
    // 0x8006E6B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8006E6B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8006E6B4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006E6B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006E6BC: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    // 0x8006E6C0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006E6C4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E6C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006E6CC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006E6D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E6D8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8006E6DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006E6E0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6E4: nop

    // 0x8006E6E8: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x8006E6EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006E6F4: nop

    // 0x8006E6F8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E6FC: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x8006E700: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E704: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E708: nop

    // 0x8006E70C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E710: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8006E714: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E718: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8006E71C: nop

    // 0x8006E720: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E724: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x8006E728: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E72C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006E730: nop

    // 0x8006E734: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E738: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8006E73C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E740: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006E744: nop

    // 0x8006E748: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E74C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8006E750: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E754: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E758: nop

    // 0x8006E75C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E760: sw          $t8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r24;
    // 0x8006E764: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E768: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8006E76C: nop

    // 0x8006E770: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E774: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8006E778: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E77C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8006E780: nop

    // 0x8006E784: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E788: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x8006E78C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E790: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006E794: nop

    // 0x8006E798: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E79C: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
    // 0x8006E7A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7A4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006E7A8: nop

    // 0x8006E7AC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E7B0: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x8006E7B4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006E7BC: nop

    // 0x8006E7C0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E7C4: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x8006E7C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7CC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8006E7D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E7D4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E7D8: sw          $t8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r24;
    // 0x8006E7DC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7E0: addiu       $t9, $t9, 0x17D0
    ctx->r25 = ADD32(ctx->r25, 0X17D0);
    // 0x8006E7E4: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8006E7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E7EC: addiu       $t7, $zero, 0x107
    ctx->r15 = ADD32(0, 0X107);
    // 0x8006E7F0: sw          $t7, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r15;
    // 0x8006E7F4: jr          $ra
    // 0x8006E7F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006E7F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void init_racer_headers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E800: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006E804: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006E808: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006E80C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006E810: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006E814: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E818: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E81C: jal         0x8009C90C
    // 0x8006E820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_number_of_active_players(rdram, ctx);
        goto after_0;
    // 0x8006E820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006E824: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E828: addiu       $s0, $s0, 0x3A90
    ctx->r16 = ADD32(ctx->r16, 0X3A90);
    // 0x8006E82C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E830: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006E834: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006E838: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x8006E83C: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8006E840: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8006E844: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8006E848: sb          $v0, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r2;
L_8006E84C:
    // 0x8006E84C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006E854: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E858: jal         0x8009C76C
    // 0x8006E85C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_1;
    // 0x8006E85C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    after_1:
    // 0x8006E860: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E864: nop

    // 0x8006E868: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E86C: sb          $v0, 0x59($t0)
    MEM_B(0X59, ctx->r8) = ctx->r2;
    // 0x8006E870: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8006E874: nop

    // 0x8006E878: lbu         $t1, 0x4A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4A);
    // 0x8006E87C: addu        $t2, $v1, $s3
    ctx->r10 = ADD32(ctx->r3, ctx->r19);
    // 0x8006E880: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8006E884: bne         $at, $zero, L_8006E894
    if (ctx->r1 != 0) {
        // 0x8006E888: nop
    
            goto L_8006E894;
    }
    // 0x8006E888: nop

    // 0x8006E88C: b           L_8006E8C8
    // 0x8006E890: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
        goto L_8006E8C8;
    // 0x8006E890: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
L_8006E894:
    // 0x8006E894: jal         0x8009F1C4
    // 0x8006E898: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8006E898: nop

    after_2:
    // 0x8006E89C: beq         $v0, $zero, L_8006E8B8
    if (ctx->r2 == 0) {
        // 0x8006E8A0: nop
    
            goto L_8006E8B8;
    }
    // 0x8006E8A0: nop

    // 0x8006E8A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8A8: subu        $t3, $s5, $s1
    ctx->r11 = SUB32(ctx->r21, ctx->r17);
    // 0x8006E8AC: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8006E8B0: b           L_8006E8C8
    // 0x8006E8B4: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
        goto L_8006E8C8;
    // 0x8006E8B4: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
L_8006E8B8:
    // 0x8006E8B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8BC: subu        $t6, $s6, $s1
    ctx->r14 = SUB32(ctx->r22, ctx->r17);
    // 0x8006E8C0: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E8C4: sb          $t6, 0x5A($t8)
    MEM_B(0X5A, ctx->r24) = ctx->r14;
L_8006E8C8:
    // 0x8006E8C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E8D0: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E8D4: sb          $zero, 0x5B($t0)
    MEM_B(0X5B, ctx->r8) = 0;
L_8006E8D8:
    // 0x8006E8D8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8006E8DC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E8E0: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8006E8E4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8006E8E8: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8006E8EC: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E8F0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E8F4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8006E8F8: bne         $at, $zero, L_8006E8D8
    if (ctx->r1 != 0) {
        // 0x8006E8FC: sh          $zero, 0x5C($t3)
        MEM_H(0X5C, ctx->r11) = 0;
            goto L_8006E8D8;
    }
    // 0x8006E8FC: sh          $zero, 0x5C($t3)
    MEM_H(0X5C, ctx->r11) = 0;
    // 0x8006E900: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E908: addu        $t7, $t5, $s3
    ctx->r15 = ADD32(ctx->r13, ctx->r19);
    // 0x8006E90C: sh          $zero, 0x64($t7)
    MEM_H(0X64, ctx->r15) = 0;
L_8006E910:
    // 0x8006E910: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8006E914: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E918: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006E91C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006E920: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006E924: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E928: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E92C: bne         $v0, $s2, L_8006E910
    if (ctx->r2 != ctx->r18) {
        // 0x8006E930: sh          $zero, 0x66($t0)
        MEM_H(0X66, ctx->r8) = 0;
            goto L_8006E910;
    }
    // 0x8006E930: sh          $zero, 0x66($t0)
    MEM_H(0X66, ctx->r8) = 0;
    // 0x8006E934: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006E938: bne         $s1, $s4, L_8006E84C
    if (ctx->r17 != ctx->r20) {
        // 0x8006E93C: addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
            goto L_8006E84C;
    }
    // 0x8006E93C: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8006E940: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E944: nop

    // 0x8006E948: sb          $zero, 0x114($t1)
    MEM_B(0X114, ctx->r9) = 0;
    // 0x8006E94C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006E950: nop

    // 0x8006E954: sb          $zero, 0x115($t2)
    MEM_B(0X115, ctx->r10) = 0;
    // 0x8006E958: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E95C: nop

    // 0x8006E960: sb          $zero, 0x116($t4)
    MEM_B(0X116, ctx->r12) = 0;
    // 0x8006E964: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8006E968: nop

    // 0x8006E96C: sb          $zero, 0x117($t3)
    MEM_B(0X117, ctx->r11) = 0;
    // 0x8006E970: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E974: nop

    // 0x8006E978: sb          $zero, 0x48($t5)
    MEM_B(0X48, ctx->r13) = 0;
    // 0x8006E97C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E980: nop

    // 0x8006E984: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x8006E988: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006E98C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006E990: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E994: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006E998: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006E99C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E9A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E9A8: jr          $ra
    // 0x8006E9AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E9AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void clear_lap_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006E9B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006E9B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006E9BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006E9C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8006E9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E9C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8006E9CC: jal         0x8006B464
    // 0x8006E9D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006E9D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8006E9D4: jal         0x8001E2D0
    // 0x8006E9D8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8006E9D8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_1:
    // 0x8006E9DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8006E9E0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006E9E4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8006E9E8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006E9EC:
    // 0x8006E9EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006E9F0: blez        $t6, L_8006EBB4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006E9F4: andi        $t2, $s1, 0x1
        ctx->r10 = ctx->r17 & 0X1;
            goto L_8006EBB4;
    }
    // 0x8006E9F4: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x8006E9F8: andi        $v1, $t6, 0x1
    ctx->r3 = ctx->r14 & 0X1;
    // 0x8006E9FC: beq         $v1, $zero, L_8006EA7C
    if (ctx->r3 == 0) {
        // 0x8006EA00: andi        $t3, $s1, 0x2
        ctx->r11 = ctx->r17 & 0X2;
            goto L_8006EA7C;
    }
    // 0x8006EA00: andi        $t3, $s1, 0x2
    ctx->r11 = ctx->r17 & 0X2;
    // 0x8006EA04: beq         $t2, $zero, L_8006EA38
    if (ctx->r10 == 0) {
        // 0x8006EA08: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006EA38;
    }
    // 0x8006EA08: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA0C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006EA10: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006EA14: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA18: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8006EA1C: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x8006EA20: nop

    // 0x8006EA24: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006EA28: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8006EA2C: lhu         $t5, 0x4($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X4);
    // 0x8006EA30: nop

    // 0x8006EA34: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006EA38:
    // 0x8006EA38: beq         $t3, $zero, L_8006EA6C
    if (ctx->r11 == 0) {
        // 0x8006EA3C: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006EA6C;
    }
    // 0x8006EA3C: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA40: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006EA44: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006EA48: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA4C: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x8006EA50: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8006EA54: nop

    // 0x8006EA58: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006EA5C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EA60: lhu         $t5, 0x0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X0);
    // 0x8006EA64: nop

    // 0x8006EA68: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006EA6C:
    // 0x8006EA6C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006EA70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006EA74: beq         $a3, $t7, L_8006EBB4
    if (ctx->r7 == ctx->r15) {
        // 0x8006EA78: nop
    
            goto L_8006EBB4;
    }
    // 0x8006EA78: nop

L_8006EA7C:
    // 0x8006EA7C: beq         $t2, $zero, L_8006EAC4
    if (ctx->r10 == 0) {
        // 0x8006EA80: nop
    
            goto L_8006EAC4;
    }
    // 0x8006EA80: nop

    // 0x8006EA84: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EA88: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA8C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA90: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006EA94: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EA98: mflo        $t8
    ctx->r24 = lo;
    // 0x8006EA9C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EAA0: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006EAA4: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EAA8: lhu         $t6, 0x6($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6);
    // 0x8006EAAC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EAB0: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8006EAB4: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006EAB8: lhu         $t9, 0x4($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4);
    // 0x8006EABC: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EAC0: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8006EAC4:
    // 0x8006EAC4: beq         $t3, $zero, L_8006EB0C
    if (ctx->r11 == 0) {
        // 0x8006EAC8: nop
    
            goto L_8006EB0C;
    }
    // 0x8006EAC8: nop

    // 0x8006EACC: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EAD0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EAD4: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EAD8: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006EADC: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EAE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006EAE4: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x8006EAE8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8006EAEC: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EAF0: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006EAF4: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EAF8: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8006EAFC: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EB00: lhu         $t8, 0x0($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X0);
    // 0x8006EB04: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB08: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
L_8006EB0C:
    // 0x8006EB0C: beq         $t2, $zero, L_8006EB58
    if (ctx->r10 == 0) {
        // 0x8006EB10: nop
    
            goto L_8006EB58;
    }
    // 0x8006EB10: nop

    // 0x8006EB14: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EB18: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EB1C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EB20: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006EB24: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EB28: mflo        $t9
    ctx->r25 = lo;
    // 0x8006EB2C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006EB30: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8006EB34: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EB38: lhu         $t8, 0x1E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1E);
    // 0x8006EB3C: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EB40: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x8006EB44: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006EB48: lhu         $t6, 0x1C($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1C);
    // 0x8006EB4C: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB50: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006EB54: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
L_8006EB58:
    // 0x8006EB58: beq         $t3, $zero, L_8006EBA8
    if (ctx->r11 == 0) {
        // 0x8006EB5C: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006EBA8;
    }
    // 0x8006EB5C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006EB60: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EB64: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EB68: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EB6C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006EB70: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EB74: mflo        $t8
    ctx->r24 = lo;
    // 0x8006EB78: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EB7C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006EB80: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EB84: lhu         $t6, 0x1A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1A);
    // 0x8006EB88: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EB8C: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x8006EB90: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EB94: lhu         $t9, 0x18($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X18);
    // 0x8006EB98: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB9C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006EBA0: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x8006EBA4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006EBA8:
    // 0x8006EBA8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8006EBAC: bne         $a3, $t6, L_8006EA7C
    if (ctx->r7 != ctx->r14) {
        // 0x8006EBB0: nop
    
            goto L_8006EA7C;
    }
    // 0x8006EBB0: nop

L_8006EBB4:
    // 0x8006EBB4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006EBB8: bne         $t0, $t4, L_8006E9EC
    if (ctx->r8 != ctx->r12) {
        // 0x8006EBBC: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006E9EC;
    }
    // 0x8006EBBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006EBC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EBC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006EBC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006EBCC: jr          $ra
    // 0x8006EBD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006EBD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void clear_game_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EBD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EBDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006EBE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006EBE4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8006EBE8: jal         0x8006B464
    // 0x8006EBEC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006EBEC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8006EBF0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006EBF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EBF8: sb          $t6, 0x4B($a2)
    MEM_B(0X4B, ctx->r6) = ctx->r14;
    // 0x8006EBFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8006EC00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006EC04: blez        $t7, L_8006EC34
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006EC08: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006EC34;
    }
    // 0x8006EC08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006EC0C:
    // 0x8006EC0C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8006EC10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006EC14: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EC18: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x8006EC1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006EC20: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8006EC24: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006EC28: bne         $at, $zero, L_8006EC0C
    if (ctx->r1 != 0) {
        // 0x8006EC2C: nop
    
            goto L_8006EC0C;
    }
    // 0x8006EC2C: nop

    // 0x8006EC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006EC34:
    // 0x8006EC34: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EC38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006EC3C: blez        $t1, L_8006EC68
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006EC40: nop
    
            goto L_8006EC68;
    }
    // 0x8006EC40: nop

L_8006EC44:
    // 0x8006EC44: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x8006EC48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006EC4C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8006EC50: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8006EC54: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EC58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006EC5C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006EC60: bne         $at, $zero, L_8006EC44
    if (ctx->r1 != 0) {
        // 0x8006EC64: nop
    
            goto L_8006EC44;
    }
    // 0x8006EC64: nop

L_8006EC68:
    // 0x8006EC68: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8006EC6C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x8006EC70: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x8006EC74: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x8006EC78: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x8006EC7C: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x8006EC80: sb          $zero, 0x16($a2)
    MEM_B(0X16, ctx->r6) = 0;
    // 0x8006EC84: sb          $zero, 0x17($a2)
    MEM_B(0X17, ctx->r6) = 0;
    // 0x8006EC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EC90: jr          $ra
    // 0x8006EC94: nop

    return;
    // 0x8006EC94: nop

;}
RECOMP_FUNC void reset_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ECA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ECA4: lw          $a0, 0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A90);
    // 0x8006ECA8: jal         0x8006E9B0
    // 0x8006ECAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x8006ECAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8006ECB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ECB4: lw          $a0, 0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A90);
    // 0x8006ECB8: jal         0x8006EBD4
    // 0x8006ECBC: nop

    clear_game_progress(rdram, ctx);
        goto after_1;
    // 0x8006ECBC: nop

    after_1:
    // 0x8006ECC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ECC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ECC8: jr          $ra
    // 0x8006ECCC: nop

    return;
    // 0x8006ECCC: nop

;}
RECOMP_FUNC void get_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECD4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006ECD8: jr          $ra
    // 0x8006ECDC: nop

    return;
    // 0x8006ECDC: nop

;}
RECOMP_FUNC void is_game_paused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECE4: lb          $v0, 0x3A95($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A95);
    // 0x8006ECE8: jr          $ra
    // 0x8006ECEC: nop

    return;
    // 0x8006ECEC: nop

;}
RECOMP_FUNC void is_postrace_viewport_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECF4: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006ECF8: jr          $ra
    // 0x8006ECFC: nop

    return;
    // 0x8006ECFC: nop

;}
RECOMP_FUNC void is_reset_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ED04: lw          $v1, 0x3AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3AE0);
    // 0x8006ED08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED0C: bne         $v1, $zero, L_8006ED44
    if (ctx->r3 != 0) {
        // 0x8006ED10: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006ED44;
    }
    // 0x8006ED10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ED18: addiu       $a0, $a0, 0x3AC8
    ctx->r4 = ADD32(ctx->r4, 0X3AC8);
    // 0x8006ED1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006ED20: jal         0x800C9110
    // 0x8006ED24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006ED24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006ED28: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8006ED2C: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x8006ED30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006ED34: sw          $t6, 0x3AE0($at)
    MEM_W(0X3AE0, ctx->r1) = ctx->r14;
    // 0x8006ED38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ED3C: lw          $v1, 0x3AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3AE0);
    // 0x8006ED40: nop

L_8006ED44:
    // 0x8006ED44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED4C: jr          $ra
    // 0x8006ED50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006ED50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_ingame_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED54: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ED58: lw          $v0, 0x3A74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A74);
    // 0x8006ED5C: jr          $ra
    // 0x8006ED60: nop

    return;
    // 0x8006ED60: nop

;}
RECOMP_FUNC void mark_to_read_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ED68: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006ED6C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ED70: nop

    // 0x8006ED74: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8006ED78: jr          $ra
    // 0x8006ED7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ED7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_to_read_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ED84: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006ED88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ED8C: nop

    // 0x8006ED90: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006ED94: jr          $ra
    // 0x8006ED98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ED98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_to_read_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDA0: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDA8: nop

    // 0x8006EDAC: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8006EDB0: jr          $ra
    // 0x8006EDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDBC: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDC4: addiu       $at, $zero, -0x301
    ctx->r1 = ADD32(0, -0X301);
    // 0x8006EDC8: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EDCC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EDD0: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8006EDD4: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006EDD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EDDC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EDE0: jr          $ra
    // 0x8006EDE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EDE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void mark_read_all_save_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDEC: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDF4: nop

    // 0x8006EDF8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8006EDFC: jr          $ra
    // 0x8006EE00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_to_write_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE08: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE10: nop

    // 0x8006EE14: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8006EE18: jr          $ra
    // 0x8006EE1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_to_write_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE24: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE2C: nop

    // 0x8006EE30: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8006EE34: jr          $ra
    // 0x8006EE38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_to_write_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE40: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE44: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE48: nop

    // 0x8006EE4C: ori         $t7, $t6, 0x30
    ctx->r15 = ctx->r14 | 0X30;
    // 0x8006EE50: jr          $ra
    // 0x8006EE54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void force_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE5C: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE64: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EE68: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EE6C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EE70: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8006EE74: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8006EE78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EE7C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EE80: jr          $ra
    // 0x8006EE84: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EE84: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void safe_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006EE8C: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006EE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE98: bne         $t6, $zero, L_8006EEDC
    if (ctx->r14 != 0) {
        // 0x8006EE9C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8006EEDC;
    }
    // 0x8006EE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EEA0: jal         0x8009C814
    // 0x8006EEA4: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006EEA4: nop

    after_0:
    // 0x8006EEA8: bne         $v0, $zero, L_8006EEDC
    if (ctx->r2 != 0) {
        // 0x8006EEAC: addiu       $at, $zero, -0xC01
        ctx->r1 = ADD32(0, -0XC01);
            goto L_8006EEDC;
    }
    // 0x8006EEAC: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EEB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EEB4: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EEB8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006EEBC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006EEC0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8006EEC4: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8006EEC8: sll         $t3, $t2, 10
    ctx->r11 = S32(ctx->r10 << 10);
    // 0x8006EECC: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8006EED0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006EED4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8006EED8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8006EEDC:
    // 0x8006EEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEE4: jr          $ra
    // 0x8006EEE8: nop

    return;
    // 0x8006EEE8: nop

;}
RECOMP_FUNC void mark_save_file_to_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEEC: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x8006EEF0: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x8006EEF4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8006EEF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006EEFC: jr          $ra
    // 0x8006EF00: sw          $t8, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r24;
    return;
    // 0x8006EF00: sw          $t8, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void mark_read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EF08: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EF0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF10: nop

    // 0x8006EF14: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8006EF18: jr          $ra
    // 0x8006EF1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EF1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mark_write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EF24: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EF28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF2C: nop

    // 0x8006EF30: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x8006EF34: jr          $ra
    // 0x8006EF38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EF38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EF40: addiu       $v0, $v0, 0x3A8C
    ctx->r2 = ADD32(ctx->r2, 0X3A8C);
    // 0x8006EF44: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006EF4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EF50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006EF54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006EF58: beq         $a0, $t6, L_8006F150
    if (ctx->r4 == ctx->r14) {
        // 0x8006EF5C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006F150;
    }
    // 0x8006EF5C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006EF60: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8006EF64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006EF68: jal         0x800712F0
    // 0x8006EF6C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006EF6C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006EF70: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006EF74: addiu       $s1, $s1, 0x1770
    ctx->r17 = ADD32(ctx->r17, 0X1770);
    // 0x8006EF78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006EF7C: jal         0x80071380
    // 0x8006EF80: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8006EF80: nop

    after_1:
    // 0x8006EF84: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006EF88: jal         0x80071380
    // 0x8006EF8C: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006EF8C: nop

    after_2:
    // 0x8006EF90: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8006EF94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8006EF98: addiu       $t8, $t8, -0x26B0
    ctx->r24 = ADD32(ctx->r24, -0X26B0);
    // 0x8006EF9C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006EFA0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006EFA4: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8006EFA8: addiu       $t9, $t9, -0x26E0
    ctx->r25 = ADD32(ctx->r25, -0X26E0);
    // 0x8006EFAC: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8006EFB0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006EFB4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006EFB8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006EFBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006EFC0: addiu       $t5, $t5, -0x26D0
    ctx->r13 = ADD32(ctx->r13, -0X26D0);
    // 0x8006EFC4: addiu       $t4, $t4, -0x26C0
    ctx->r12 = ADD32(ctx->r12, -0X26C0);
    // 0x8006EFC8: addu        $a3, $t7, $t4
    ctx->r7 = ADD32(ctx->r15, ctx->r12);
    // 0x8006EFCC: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x8006EFD0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8006EFD4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8006EFD8: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x8006EFDC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006EFE0: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8006EFE4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8006EFE8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006EFEC: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8006EFF0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8006EFF4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8006EFF8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8006EFFC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006F000: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // 0x8006F004: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F00C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8006F010: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006F014: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006F018: jal         0x80071138
    // 0x8006F01C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    mempool_alloc_fixed(rdram, ctx);
        goto after_3;
    // 0x8006F01C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // 0x8006F020: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F024: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8006F028: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006F02C: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006F030: jal         0x80071138
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_4;
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006F038: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006F03C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8006F040: beq         $s0, $zero, L_8006F050
    if (ctx->r16 == 0) {
        // 0x8006F044: nop
    
            goto L_8006F050;
    }
    // 0x8006F044: nop

    // 0x8006F048: bne         $v0, $zero, L_8006F094
    if (ctx->r2 != 0) {
        // 0x8006F04C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8006F094;
    }
    // 0x8006F04C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8006F050:
    // 0x8006F050: beq         $s0, $zero, L_8006F064
    if (ctx->r16 == 0) {
        // 0x8006F054: nop
    
            goto L_8006F064;
    }
    // 0x8006F054: nop

    // 0x8006F058: jal         0x80071380
    // 0x8006F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006F060: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8006F064:
    // 0x8006F064: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F068: nop

    // 0x8006F06C: beq         $a1, $zero, L_8006F080
    if (ctx->r5 == 0) {
        // 0x8006F070: nop
    
            goto L_8006F080;
    }
    // 0x8006F070: nop

    // 0x8006F074: jal         0x80071380
    // 0x8006F078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006F078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x8006F07C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_8006F080:
    // 0x8006F080: jal         0x8006F21C
    // 0x8006F084: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_7;
    // 0x8006F084: nop

    after_7:
    // 0x8006F088: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006F08C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006F090: nop

L_8006F094:
    // 0x8006F094: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F098: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006F09C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8006F0A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0A4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8006F0A8: addu        $t4, $v1, $s0
    ctx->r12 = ADD32(ctx->r3, ctx->r16);
    // 0x8006F0AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006F0B0: sw          $t4, 0x1780($at)
    MEM_W(0X1780, ctx->r1) = ctx->r12;
    // 0x8006F0B4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006F0B8: addiu       $t2, $t2, 0x1780
    ctx->r10 = ADD32(ctx->r10, 0X1780);
    // 0x8006F0BC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8006F0C0: sll         $a3, $a2, 6
    ctx->r7 = S32(ctx->r6 << 6);
    // 0x8006F0C4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8006F0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0CC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006F0D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006F0D4: sw          $t8, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = ctx->r24;
    // 0x8006F0D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006F0DC: addiu       $t3, $t3, 0x17A0
    ctx->r11 = ADD32(ctx->r11, 0X17A0);
    // 0x8006F0E0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8006F0E4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006F0E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0EC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8006F0F0: sw          $t4, 0x1790($at)
    MEM_W(0X1790, ctx->r1) = ctx->r12;
    // 0x8006F0F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0F8: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x8006F0FC: sw          $t6, 0x1784($at)
    MEM_W(0X1784, ctx->r1) = ctx->r14;
    // 0x8006F100: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8006F104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F108: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006F10C: sw          $t8, 0x17A4($at)
    MEM_W(0X17A4, ctx->r1) = ctx->r24;
    // 0x8006F110: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8006F114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F118: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x8006F11C: sw          $t5, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = ctx->r13;
    // 0x8006F120: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F124: sw          $v0, 0x3AA8($at)
    MEM_W(0X3AA8, ctx->r1) = ctx->r2;
    // 0x8006F128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F12C: sw          $a2, 0x3AAC($at)
    MEM_W(0X3AAC, ctx->r1) = ctx->r6;
    // 0x8006F130: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006F134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F138: sw          $t0, 0x3AB0($at)
    MEM_W(0X3AB0, ctx->r1) = ctx->r8;
    // 0x8006F13C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8006F140: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006F148: jal         0x800712F0
    // 0x8006F14C: sw          $t6, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r14;
    mempool_free_timer(rdram, ctx);
        goto after_8;
    // 0x8006F14C: sw          $t6, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r14;
    after_8:
L_8006F150:
    // 0x8006F150: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F154: lw          $v1, 0x3A68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3A68);
    // 0x8006F158: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006F15C: addiu       $s1, $s1, 0x1770
    ctx->r17 = ADD32(ctx->r17, 0X1770);
    // 0x8006F160: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8006F164: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8006F168: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006F16C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006F170: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006F174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006F178: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8006F17C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006F180: lw          $t5, 0x1780($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1780);
    // 0x8006F184: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006F188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F18C: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8006F190: lw          $t4, 0x17A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X17A0);
    // 0x8006F194: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006F198: sw          $t5, 0x1788($at)
    MEM_W(0X1788, ctx->r1) = ctx->r13;
    // 0x8006F19C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F1A0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006F1A4: lw          $t6, 0x1790($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1790);
    // 0x8006F1A8: sw          $t4, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r12;
    // 0x8006F1AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F1B0: sw          $t6, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r14;
    // 0x8006F1B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006F1B8: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x8006F1BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006F1C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8006F1C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006F1C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006F1CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006F1D0: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006F1D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006F1D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006F1DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006F1E0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006F1E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F1E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1F0: jr          $ra
    // 0x8006F1F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006F1F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void drm_validate_dmem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1F8: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x8006F1FC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8006F200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006F204: beq         $t7, $at, L_8006F214
    if (ctx->r15 == ctx->r1) {
        // 0x8006F208: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F214;
    }
    // 0x8006F208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F20C: jr          $ra
    // 0x8006F210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006F210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F214:
    // 0x8006F214: jr          $ra
    // 0x8006F218: nop

    return;
    // 0x8006F218: nop

;}
