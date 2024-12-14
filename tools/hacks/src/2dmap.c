#include "rebirth.h"
#include "types.h"
#include "sceio.h"

extern u16 func_0010FC50();

DATA int is_show_debug = 0;
extern u8 map2d_linehit;
extern u16 pad_held_buttons;
extern u8 is_map2d_debug_enabled;

typedef struct unk_btl_sub1 {
    u8 unk0[0x49];
    u8 unk49[4];
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u8 unk58;
    u8 unk59;
    s8 unk5A;
    u8 unk5B;
    u8 unk5C;
    u8 unk5D;
} unk_btl_sub1;

typedef struct unk_btl_sub2 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} unk_btl_sub2;

typedef struct unk_btl_sub0 {
    u8 unk0[0x2e4];
    u32 unk2E4;
    u8 unk2E8[0x320 - 0x2E8];
    unk_btl_sub2 unk320[1];
    u8 unk326[0x340 - 0x326];
    unk_btl_sub1* unk340;
    u8 unk344[0x419 - 0x344];
    u8 unk419;
} unk_btl_sub0;

// typedef struct unk_struct_0 {
//     u8 color_rgba[0x14];
// } unk_struct_0;

typedef struct _btl_struct {
    u8 unk0[0x8120];
    u32 unk8120;
    u8 unk8124[0xb388 - 0x8124];
    s8 unkB388;
    unk_btl_sub0* unkB38C;
    u8 unkC5CF[0xc5cf - 0xB390];
    fontenv_struct fontenv_0;
} btl_struct;

typedef struct _spoint {
    u16 x;
    u16 y;
} spoint;

extern btl_struct gBtlStruct;

char* func_00149F30(int);
char* func_00149F48(int);
char* getBtlStr(int);
char* custom_strlen(char*);
int sprintf(char*, const char*, ...);
char* strcat(char*, char*);
char* getBtlRevisionStr(u8);

extern u8 status_disp_colors;
extern u8 status_disp_349630;

// TODO: Move these 2 functions
void printBtlEnemyStatusDisp(void) {
    spoint coord;
    char final_string[32];
    int local_100[4];
    int local_101[4];
    u8* pbVar14;
    unk_btl_sub0* temp_s3 = gBtlStruct.unkB38C;
    RGBA_color* colors = &status_disp_colors;
    s32 opacity = gBtlStruct.unkB388 << 4;
    int cVar5 = func_0014B218(temp_s3->unk419);
    char* uStack_c0 = &status_disp_349630;
    int i;
    int j;
    int k;
    int local_b0;
    int iVar8;
    u8* var_s2;
    int var_a2;
    unk_btl_sub2* var_s0_1;
    int current_str_len;

    gBtlStruct.fontenv_0.unk_20 = 0x40;
    
    coord.x = 0x100 - ((8 - gBtlStruct.unkB388) * 0x100);
    coord.y = 0x280;
    
    printBtlWindowStr(func_00149F48(temp_s3->unk419), 0x1, opacity, &coord, 0x1, NULL);
    coord.y += 0xF0;

    if (cVar5 >= 0x10) {
        sprintf(final_string, "HP%6d", temp_s3->unk2E4);
    } else {
        sprintf(final_string, "HP ???");
    }

    // Make HP string big
    gBtlStruct.fontenv_0.font_type |= 1;
    printBtlWindowStr(final_string, 0x1, opacity, &coord, 0x1, NULL);
    gBtlStruct.fontenv_0.font_type &= ~1;
    // Rest are normal

    coord.y += 0x1E0;
    local_b0 = (cVar5 < '(');
    var_s2 = temp_s3->unk340->unk49;
    for (i = 0, j = 0; i < 4; i++) {
        if (*var_s2 != '\0') {
            local_100[j++] = i;
        }
        var_s2++;
    }

    if (j != 0x0) {
        k = local_100[(gBtlStruct.unk8120 / 0x30) % j];
        pbVar14 = ((u8*)temp_s3->unk340 + (k + 0x49));
        // 弱点 (Weak)
        // 鋼体 (Iron S.)
        // 半減 (Resist)
        // 防御 (Durab.)
        sprintf(final_string, "%s:", func_00149F30(k + 0x5));
        current_str_len = strlen(final_string);
        if (uStack_c0[k] <= cVar5) {
            for (i = 0; i < 8; i++) {
                if (((pbVar14[0] >> i) & 0x1)) {
                    // 斬 (Slash)
                    // 打 (Blunt)
                    // 地 (Earth)
                    // 風 (Wind)
                    // 火 (Fire)
                    // 水 (Water)
                    // 光 (Light)
                    // 闇 (Dark)
                    char* element_str = func_00149F30(i + 0x9);
                    int element_str_len = custom_strlen(element_str);
                    memcpy(&final_string[current_str_len], element_str, element_str_len);
                    current_str_len += element_str_len;
                } else {
                    memcpy(&final_string[current_str_len], " ", 1);
                    current_str_len += 1;
                }
            }
        } else {
            strcat(final_string, getBtlStr(0x9e)); // "？" (?)
        }
        printBtlWindowStr(final_string, 0x1, opacity, &coord, 0x1, &colors[k + 1]);
    } else {
        printBtlWindowStr(" ", 0x1, opacity, &coord, 0x1, NULL);
    }

    coord.y += 0xF0;
    var_s0_1 = temp_s3->unk320;
    for (i = 0, j = 0x0; i < 4; i++) {
        if (var_s0_1->unk0 != '\0') {
            local_100[j++] = i;
        }
        var_s0_1++;
    }

    if (j != 0x0) {
        pbVar14 = (char*)getBtlRevisionStr(temp_s3->unk320[local_100[(gBtlStruct.unk8120 / 0x30) % j]].unk0);
        printBtlWindowStr(pbVar14, 0x1, opacity, &coord, 0x1, (var_s0_1->unk0 & 0x80) ? &colors[3] : &colors[1]);
    } else {
        printBtlWindowStr(" ", 0x1, opacity, &coord, 0x1, NULL);
    }

    if (local_b0 == 0x0) {
        var_a2 = 0;
        
        coord.y += 0xf0;
        
        if (temp_s3->unk340->unk5A != '\0') {
            local_100[var_a2++] = 0x1;
        }
        
        if ((temp_s3->unk340->unk5D & 0x1) != 0x0) {
            local_100[var_a2++] = 0x2;
        }
        
        if ((temp_s3->unk340->unk5D & 0x2) != 0x0) {
            local_100[var_a2++] = 0x3;
        }
        
        if (var_a2 != 0x0) {
            iVar8 = local_100[(gBtlStruct.unk8120 / 0x30) % var_a2];
        } else {
            iVar8 = 0x0;
        }

        switch (iVar8) {
            case 1:
                // ＲＧ一定以上 (High RG)
                // ＲＧ一定以下 (Low RG)
                // ＨＰ一定以上 (High HP)
                // ＨＰ一定以下 (Low HP)
                // 味方ＲＧ一定以上 (High Ally RG)
                // 味方ＲＧ一定以下 (Low Ally RG)
                // 常時 (Continuous)
                pbVar14 = func_00149F30(temp_s3->unk340->unk5A + 0x14);
                break;
            case 2:
                pbVar14 = func_00149F30(0x1c); // 特定攻撃前 (Before Attacking)
                break;
            case 3:
                pbVar14 = func_00149F30(0x1d); // 特定攻撃後 (After Attacking)
                break;
            case 0:
            default:
                pbVar14 = 0;
                break;
        }

        if (((pbVar14 != 0x0) && (0x0 < iVar8)) && (iVar8 < 0x4)) {
            // "%s:%s", 防御行動 (Guards)
            sprintf(final_string, func_00149F30(0x13), func_00149F30(0x12), pbVar14);
            printBtlWindowStr(final_string, 0x1, opacity, &coord, 0x1, NULL);
        }
    }

    gBtlStruct.fontenv_0.unk_20 = 0;
}

extern u64 fontenv_tex0;
extern u64 story_tex0;
void update_tex0() {
    // The game does this nifty thing where it allocates a 64x32 texture 
    // (A "Page") for the main textures, the allocation is at the end of VRAM
    // and for some reason making the texture bigger breaks rendering, but 
    // keeping it smaller doesn't (but shuffles the palettes).
    // So we'll do a hack and shift the CBP of the relevant TEX0 registers
    // used for the text and let the rest of the game deal with the problem.
    fontenv_tex0 &= ~SCE_GS_SET_TEX0(0, 0, 0, 0, 0, 0, 0, 0x3FFF, 0, 0, 0, 0);
    story_tex0 &= ~SCE_GS_SET_TEX0(0, 0, 0, 0, 0, 0, 0, 0x3FFF, 0, 0, 0, 0);
    fontenv_tex0 |= SCE_GS_SET_TEX0(0, 0, 0, 0, 0, 0, 0, 0x3AE3, 0, 0, 0, 0);
    story_tex0 |= SCE_GS_SET_TEX0(0, 0, 0, 0, 0, 0, 0, 0x3AE3, 0, 0, 0, 0);
}

void show_debug_view() {
    u16 buttons = pad_held_buttons;

    if (!is_map2d_debug_enabled) {
        return;
    }

    if ((buttons & 0x0C) == 0x0C) {
        // if L1+R1 pressed
        is_show_debug = 1;
    } else if ((buttons & 0x03) == 0x03) {
        // if L2+R2 pressed
        is_show_debug = 0;
    }
    
    if ((buttons & 0x84) == 0x84) {
        // if L1+▢ pressed
        map2d_linehit = 0x90;
    } else if ((buttons & 0x88) == 0x88) {
        // if R1+▢ pressed
        map2d_linehit = 0x80;
    }

    if (is_show_debug) {
        map2d_DebugInit();
        map2d_DebugMessage();
    }
}
