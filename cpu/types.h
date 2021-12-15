#ifndef EFF39097_5681_4782_9981_B9ED69B6CB4F
#define EFF39097_5681_4782_9981_B9ED69B6CB4F

typedef unsigned int   u32;
typedef          int   s32;
typedef unsigned short u16;
typedef          short s16;
typedef unsigned char  u8;
typedef          char  s8;

#define low_16(address) (u16)((address) & 0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

#endif /* EFF39097_5681_4782_9981_B9ED69B6CB4F */
