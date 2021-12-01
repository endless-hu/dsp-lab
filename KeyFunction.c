#include "main.h"

extern int keyin;
extern Uint32 time;
extern unsigned int flag;

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