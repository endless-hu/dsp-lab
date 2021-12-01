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

const unsigned int LEDCode[30] = {
    // start from "0"
    0xc000, 0xf900, 0xA400, 0xB000, 0x9900, 0x9200, 0x8200, 0xF800, 0x8000,
    0x9000,
    // "A"
    0x8800, 0x8300, 0xc600, 0xa100, 0x8600, 0x8e00,
    // other chars
    0x8c00, 0xbf00, 0xa700, 0xff00,
    // start from "0." (with DP on)
    0x4000, 0x7900, 0x2400, 0x3000, 0x1900, 0x1200, 0x0200, 0x7800, 0x0000,
    0x1000};

void InitCputimer(void) {
  EALLOW;
  CpuTimer0Regs.TPR.all = 149;
  CpuTimer0Regs.TPRH.all = 0;
  CpuTimer0Regs.PRD.all = 999999;
  CpuTimer0Regs.TCR.all = 0xf000;
  EDIS;
}

void InitGpioBEF(void) {
  EALLOW;
  GpioMuxRegs.GPFMUX.all = 0x0000;
  GpioMuxRegs.GPFDIR.all = 0xFF00;
  GpioMuxRegs.GPBMUX.all = 0x0000;
  GpioMuxRegs.GPBDIR.all = 0xFF00;
  GpioMuxRegs.GPEMUX.all = 0x0000;
  GpioMuxRegs.GPEDIR.all = 0x0007;

  GpioMuxRegs.GPAMUX.bit.TDIRA_GPIOA11 = 0;
  GpioMuxRegs.GPADIR.bit.GPIOA11 = 1;
  EDIS;
  GpioDataRegs.GPADAT.bit.GPIOA11 = 0;
}

interrupt void INT_1_7(void);
void InitPIE(void) {
  EALLOW;
  PieCtrlRegs.PIEIFR1.all = 0x0000;
  PieCtrlRegs.PIEIER1.all = 0x0040;
  PieCtrlRegs.PIECRTL.bit.ENPIE = 0x1;
  PieCtrlRegs.PIEACK.all = 0x1;
  EDIS;
}

unsigned int timer[6] = {0, 0, 0, 0, 0, 0};
Uint32 time = 0;
int keyin = 0xffff;
/** The structure of flag:
 *  0000 0000 0000 0001
 *                   ||
 *                   |+--> start bit, "1" represents at work
 *                   +--> setting bit, "1" represents in setting mode
 */
unsigned int flag = 1;

void display(void) {
  int i, j;
  for (i = 0; i < 8; i++) {
    GpioDataRegs.GPADAT.bit.GPIOA11 = 0;
    if (i > 5) {
      SpiaRegs.SPITXBUF = LEDCode[19];
    }
    else if (i % 2 == 0) {
      SpiaRegs.SPITXBUF = LEDCode[timer[i]];
    } else {
      SpiaRegs.SPITXBUF = LEDCode[timer[i]+20];
    }
    while (SpiaRegs.SPISTS.bit.INT_FLAG != 1) {
    }
    SpiaRegs.SPIRXBUF = SpiaRegs.SPIRXBUF;
  }
  GpioDataRegs.GPADAT.bit.GPIOA11 = 1;
  for (j = 0; j < 10; j++) {
  }
}

void time_adj() {
  timer[5] = time % 60 % 10;
  timer[4] = time % 60 / 10;
  timer[3] = time % 3600 / 60 % 10;
  timer[2] = time % 3600 / 60 / 10;
  timer[1] = time % 360000 / 3600 % 10;
  timer[0] = time % 360000 / 3600 / 10;
  display();
}

void Keyscan(void) {
  int i;
  unsigned int key1R, key2R;
  EALLOW;
  GpioMuxRegs.GPBDIR.all &= 0x00FF;
  EDIS;

  GpioDataRegs.GPEDAT.all = 0xFFF8;  // KEYA
  for (i = 0; i < 100; i++) {
  }
  key1R = GpioDataRegs.GPBDAT.all;
  for (i = 0; i < 30000; i++) {
  }
  if (key1R != GpioDataRegs.GPBDAT.all) key1R = 0xffff;

  GpioDataRegs.GPEDAT.all = 0xFFF9;  // KEYB
  for (i = 0; i < 100; i++) {
  }
  key2R = GpioDataRegs.GPBDAT.all;
  for (i = 0; i < 30000; i++) {
  }
  if (key2R != GpioDataRegs.GPBDAT.all) key2R = 0xffff;

  keyin = key2R & 0xff00 + key1R / 256;
}

void WaitKeyin(void) {
  int temp;
  while (keyin == 0xFFFF) {
    Keyscan();
  }
  temp = keyin;
  while (keyin != 0xFFFF) {
    Keyscan();
  }
  switch (temp) {
    case KEY(0):
      keyin = KEY0;
      break;
    case KEY(1):
      keyin = KEY1;
      break;
    case KEY(2):
      keyin = KEY2;
      break;
    case KEY(3):
      keyin = KEY3;
      break;
    case KEY(4):
      keyin = KEY4;
      break;
    case KEY(5):
      keyin = KEY5;
      break;
    case KEY(6):
      keyin = KEY6;
      break;
    case KEY(7):
      keyin = KEY7;
      break;
    case KEY(8):
      keyin = KEY8;
      break;
    case KEY(9):
      keyin = KEY9;
      break;
    case KEY(10):
      keyin = KEYA;
      break;
    case KEY(11):
      keyin = KEYB;
      break;
    case KEY(12):
      keyin = KEYC;
      break;
    case KEY(13):
      keyin = KEYD;
      break;
    case KEY(14):
      keyin = KEYE;
      break;
    case KEY(15):
      keyin = KEYF;
      break;
    default:
      keyin = 0x10;
      break;
  }
}

void KeyFunction() {
  WaitKeyin();  // {WaitKeyin()} while( keyin > 9 ) ;
  switch (keyin) {
    case KEYA:  // Ascend (inc sec)
      time++;
      break;

    case KEYB:  // dec
      time--;
      break;

    case KEYC:  // Clear
      time = 0;
      break;

    case KEYD:  // setting time, default sec,
      if (!FLAG(1)) {
        flag |= 0x0002;
      } else {
        // hit again to change setting among hour, min, sec
      }
      break;

    case KEYE:  // Enter (time set)
                // if not in setting mode, it will change the speed of clock in
                // 3 states
      if (!FLAG(SETTING)) {
        EALLOW;
        switch (CpuTimer0Regs.PRD.all) {
          case 999999:
            CpuTimer0Regs.PRD.all = 99999;
            break;
          case 99999:
            CpuTimer0Regs.PRD.all = 9999;
            break;
          default:
            CpuTimer0Regs.PRD.all = 999999;
            break;
        }
        EDIS;
      } else {
        UNSET_FLAG(SETTING);
      }
      break;

    case KEYF:  // start / stop
      EALLOW;
      // toggle the bit
      if (FLAG(START)) {
        UNSET_FLAG(START);
        PieCtrlRegs.PIECRTL.bit.ENPIE = 0x1;
      } else {
        SET_FLAG(START);
        PieCtrlRegs.PIECRTL.bit.ENPIE = 0x0;
      }
      EDIS;
      break;

    default:
      break;
  }
  time_adj();
  keyin = 0xffff;
}

void main(void) {
  InitSysCtrl();
  InitGpioBEF();
  InitCputimer();
  InitPIE();
  InitSpi();
  EALLOW;
  PieVectTable.TINT0 = &INT_1_7;
  asm("  and IFR,#00H");
  asm("  or  IER,#01H");
  asm("  EINT");
  SysCtrlRegs.LPMCR0.all = 0x0;
  EDIS;
  display();
  for (;;) {
    KeyFunction();
  }
}

interrupt void INT_1_7(void) {
  time++;
  if (time == 360000) {
    time = 0;
  }
  time_adj();
  PieCtrlRegs.PIEACK.all = 0x1;
  CpuTimer0Regs.TCR.all = 0xf000;
}
