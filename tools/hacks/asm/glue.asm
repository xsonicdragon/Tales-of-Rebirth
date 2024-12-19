
; #######################
; #       EXTERNs       #
; #######################

; Extern function references
.definelabel init_party_data,      0x00100360
.definelabel init_filesystem,      0x00101CA8
.definelabel rotate_thread_func,   0x001025B8
.definelabel func_00104F50,        0x00104F50
.definelabel func_00104F60,        0x00104F60
.definelabel func_00104F70,        0x00104F70
.definelabel func_00104F78,        0x00104F78
.definelabel fontenv_set_palette,  0x00104F88
.definelabel custom_strlen,        0x00106D10
.definelabel custom_memcpy,        0x00108F20
.definelabel alloc_EE,             0x00109500
.definelabel free_EE,              0x00109538
.definelabel init_heap,            0x0010BC10
.definelabel init_controller,      0x00110B50
.definelabel file_pls,             0x001158F0
.definelabel get_file_size,        0x00116E40
.definelabel init_memorycard,      0x00135368
.definelabel write_register,       0x00140CD8
.definelabel generate_sin,         0x00141B78

; Extern global references
.definelabel scratchpad_addr,      0x001FE2A0
.definelabel custom,               0x00236818
.definelabel gMain,                0x00236930
.definelabel custom_temp,          0x002368A0
.definelabel rotate_thread_stack,  0x00237090
.definelabel rotate_thread_id,     0x00237490
.definelabel _gp,                  0x0023AB70

; SDK functions
.definelabel sceGsResetGraph,      0x001995E8
.definelabel sceGsResetPath,       0x00199788
.definelabel sceGsPutDispEnv,      0x001997F0
.definelabel sceDmaReset,          0x0019BA50
.definelabel sceDevVu0Reset,       0x0019C130
.definelabel sceDevVif0Reset,      0x0019C5B0
.definelabel sceCdInit,            0x0019D710
.definelabel sceCdMode,            0x0019DE30
.definelabel CreateThread,         0x0019E160
.definelabel ChangeThreadPriority, 0x0019E1F0
.definelabel GetThreadId,          0x0019E250
.definelabel StartThread,          0x0019F4A0
.definelabel sceSifExitCmd,        0x001A1208
.definelabel sceSifInitRpc,        0x001A16E8
.definelabel sceFsReset,           0x001A3248
.definelabel sceOpen,              0x001A34B0
.definelabel sceClose,             0x001A3740
.definelabel sceLseek,             0x001A38B8
.definelabel sceRead,              0x001A3AF8
.definelabel sceSifInitIopHeap,    0x001A63D8
.definelabel sceSifAllocSysMemory, 0x001A64D0
.definelabel sceSifFreeSysMemory,  0x001A6550
.definelabel sceSifLoadFileReset,  0x001A6AB8
.definelabel sceSifSyncIop,        0x001A7808
.definelabel sceSifRebootIop,      0x001A7858
.definelabel sceVpu0Reset,         0x001AE6F0
.definelabel sceMpegInit,          0x001AF3C8
.definelabel memset,               0x001BFC34
.definelabel memcpy,               0x001BFA8C
.definelabel printf,               0x001C0C70
.definelabel strlen,               0x001C0080

; Autogenerated names
.definelabel func_001002A8,        0x001002A8
.definelabel func_001002E8,        0x001002E8
.definelabel func_001005A8,        0x001005A8
.definelabel func_00100760,        0x00100760
.definelabel func_00101E18,        0x00101E18
.definelabel func_00102608,        0x00102608
.definelabel func_00103100,        0x00103100
.definelabel func_00103650,        0x00103650
.definelabel func_001045F0,        0x001045F0
.definelabel func_00104620,        0x00104620
.definelabel func_00108668,        0x00108668
.definelabel func_00108710,        0x00108710
.definelabel func_0010BD10,        0x0010BD10
.definelabel func_0010D288,        0x0010D288
.definelabel func_0010D408,        0x0010D408
.definelabel func_0010D440,        0x0010D440
.definelabel func_0010E1E8,        0x0010E1E8
.definelabel func_0010EA78,        0x0010EA78
.definelabel func_0010ED38,        0x0010ED38
.definelabel func_0010EEF8,        0x0010EEF8
.definelabel func_0010F148,        0x0010F148
.definelabel func_0010F3E0,        0x0010F3E0
.definelabel func_0010F830,        0x0010F830
.definelabel func_00113BC0,        0x00113BC0
.definelabel func_00117120,        0x00117120
.definelabel func_00118C50,        0x00118C50
.definelabel func_00119010,        0x00119010
.definelabel func_0011A2C0,        0x0011A2C0
.definelabel func_00121460,        0x00121460
.definelabel func_0012ACA8,        0x0012ACA8
.definelabel func_0012B268,        0x0012B268
.definelabel func_0012BF58,        0x0012BF58
.definelabel func_0012D940,        0x0012D940
.definelabel func_0012D9D0,        0x0012D9D0
.definelabel func_001312D8,        0x001312D8
.definelabel func_00131950,        0x00131950
.definelabel func_00131990,        0x00131990
.definelabel func_0013FFB0,        0x0013FFB0
.definelabel func_001407F0,        0x001407F0
.definelabel func_001492B8,        0x001492B8
.definelabel func_001533C0,        0x001533C0
.definelabel func_00171C18,        0x00171C18
.definelabel func_00171F18,        0x00171F18
.definelabel func_00176C80,        0x00176C80
.definelabel func_0017A5A0,        0x0017A5A0
.definelabel func_0017A660,        0x0017A660

.definelabel fntenv_make_default,  0x00104eb8
.definelabel draw_string,          0x00104868
.definelabel btl_font_env,         0x00357ED0
.definelabel get_str_width,        0x00104a48
.definelabel sprintf,              0x001c0ed0
.definelabel getBtlVoiceTimer,     0x00330108
.definelabel battle_pause,         0x00354A4F
.definelabel getMonsterName,       0x00149f48 
.definelabel custom_strcmp,        0x00170a10
.definelabel strcmp,               0x001bfe1c
.definelabel getEncodedCharName,   0x00107138
.definelabel printbtlwindowstr,    0x00303898
.definelabel btl_item_count,       0x00357E8C
.definelabel btl_auto_cooking,     0x00236090
.definelabel btl_cooking_flag,     0x00357EAC
.definelabel func_0010FC50,        0x0010FC50
.definelabel map2d_DebugInit,      0x0033d9c0
.definelabel map2d_DebugMessage,   0x0033a5f8
.definelabel map2d_linehit,        0x0036fd08
.definelabel pad_held_buttons,     0x00242DDC
.definelabel fontenv_tex0,         0x002376F0
.definelabel story_tex0,           0x00249628
.definelabel status_disp_colors,   0x00349618
.definelabel status_disp_349630,   0x00349630
.definelabel func_0014b218,        0x0014b218
.definelabel func_00149f48,        0x00149f48
.definelabel getbtlrevisionstr,    0x00300700
.definelabel func_00149f30,        0x00149f30
.definelabel strcat,               0x001bfcec
.definelabel gBtlStruct,           0x0034b900
.definelabel func_00104F30,        0x00104F30
.definelabel func_001052F0,        0x001052F0
.definelabel fontenv_render,        0x001062C8
.definelabel func_00105030,        0x00105030
.definelabel func_00105568,        0x00105568
.definelabel func_00105268,        0x00105268
.definelabel fontenv_glyphs,       0x00237518
.definelabel encount_group_no,     0x00236fe0       ; halfword
.definelabel checkBtlFinality,     0x0030c0c8       
.definelabel btl_unk813e,          0x00353A3E       ; halfword
.definelabel btl_unka790,          0x00356090       ; byte
.definelabel btl_unk8151,          0x00353A51       ; byte - intro demo battle flag