#ifndef __INIT_H__
#define __INIT_H__

#include "types.h"

extern void* custom;
extern void* custom_temp;
extern void* _gp;
extern void (*rotate_thread_func)(void*);
extern int rotate_thread_id;
extern int rotate_thread_stack[];

void* memset(void*, int, unsigned int);
int printf(char*, ...);

typedef struct unk_main_struct {
    u8 pad[1638];
    u8 unk666;
    u8 unk667;
} unk_main_struct;

extern unk_main_struct gMain;

typedef struct ThreadParam {
    s32     status;
    void    (*entry)(void *);
    void    *stack;
    s32     stackSize;
    void    *gpReg;
    s32     initPriority;
    s32     currentPriority;
    u32     attr;
    u32     option;
    s32     waitType;
    s32     waitId;
    s32     wakeupCount;
} ThreadParam;

typedef struct unk_struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u16 unk18;
    u16 unk1A;
} unk_struct;

#endif /* __INIT_H__ */