#include "DSP281x_Device.h"
#include "DSP281x_GlobalPrototypes.h"
#include "KeyFunction.h"
#include "display.h"

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

// LED code macro
#define BLANK 19
#define S 30
#define N 31
#define H 32
const unsigned int LEDCode[33] = {
    // start from "0"
    0xc000, 0xf900, 0xA400, 0xB000, 0x9900, 0x9200, 0x8200, 0xF800, 0x8000,
    0x9000,
    // "A"
    0x8800, 0x8300, 0xc600, 0xa100, 0x8600, 0x8e00,
    // other chars
    0x8c00, 0xbf00, 0xa700, 0xff00,
    // 20 -> start from "0." (with DP on)
    0x4000, 0x7900, 0x2400, 0x3000, 0x1900, 0x1200, 0x0200, 0x7800, 0x0000,
    0x1000,
    // 30 -> 'S', 'N', 'H'
    0x9200, 0xC800, 0x8900};

// state macro
#define CLOCK_START 1
#define CLOCK_STOP 0
#define ADC_START 1
#define ADC_STOP 0
#define DISPLAY_CLOCK 0
#define DISPLAY_ADC 1
// speed macro
#define HIGH_SPEED 2
#define MEDIUM_SPEED 1
#define LOW_SPEED 0
// modification macro
#define SEC 0
#define TEN_SEC 1
#define MIN 2
#define TEN_MIN 3
#define HOUR 4
#define TEN_HOUR 5
#define MODOFF 6

typedef struct Flags {
  Uint16 clock_start : 1;
  Uint16 adc_start : 1;
  // 0 -> display clock; 1 -> display ADC
  Uint16 display_which : 1;
  // 0 -> inc per second; 1 -> inc per 100 ms; 2 -> inc per 10 ms
  Uint16 clock_speed : 2;
  // 0 -> second; 1 -> ten seconds; 2 -> minute;
  // 3 -> ten minutes; 4 -> hour; 5 -> ten hours;
  // 6 -> no modification
  Uint16 op_unit : 3;
  Uint16 rsvd : 8;
} SysFlags;