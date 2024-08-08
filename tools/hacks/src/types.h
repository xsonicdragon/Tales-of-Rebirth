#ifndef __TYPES_H__
#define __TYPES_H__

#ifdef __GNUC__
#define PACKED __attribute__((__packed__))
#else
#define PACKED
#define __attribute__(x)
#endif

typedef signed char      s8;
typedef signed short     s16;
typedef signed int       s32;
typedef signed long long s64;
typedef signed long long s128 __attribute__((mode(TI)));

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef unsigned long long u128 __attribute__((mode(TI)));

typedef float  f32;
typedef double f64;

typedef volatile s8   vs8;
typedef volatile s16  vs16;
typedef volatile s32  vs32;
typedef volatile s64  vs64;
typedef volatile s128 vs128;

typedef volatile u8   vu8;
typedef volatile u16  vu16;
typedef volatile u32  vu32;
typedef volatile u64  vu64;
typedef volatile u128 vu128;

typedef volatile float  vf32;
typedef volatile double vf64;

#endif /* __TYPES_H__ */