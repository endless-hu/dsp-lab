#include "DSP281x_Device.h"
#include "DSP281x_GlobalPrototypes.h"

#define KEY(N) (~(1u << N))
#define KEY0 0
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4
#define KEY5 5
#define KEY6 6
#define KEY7 7
#define KEY8 8
#define KEY9 9
#define KEYA 10
#define KEYB 11
#define KEYC 12
#define KEYD 13
#define KEYE 14
#define KEYF 15

#define SET_FLAG(N) flag |= (1u << N)
#define UNSET_FLAG(N) flag &= ~(1u << N)
#define FLAG(N) (flag >> N)
#define START 0
#define SETTING 1