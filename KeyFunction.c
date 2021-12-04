#include "main.h"

extern int keyin;
extern Uint32 time;
extern SysFlags flag;
int keyin1, keyin2, keyin3;

void Keyscan(void) {
  int i;
  unsigned int key1R, key2R;
  EALLOW;
  GpioMuxRegs.GPBDIR.all &= 0x00FF;
  EDIS;

  GpioDataRegs.GPEDAT.all = 0xFFF8;  // KEYA
  for (i = 0; i < 5; i++) {
  }
  key1R = GpioDataRegs.GPBDAT.all;

  GpioDataRegs.GPEDAT.all = 0xFFF9;  // KEYB
  for (i = 0; i < 5; i++) {
  }
  key2R = GpioDataRegs.GPBDAT.all;

  keyin1 = key2R & 0xff00 + key1R / 256;

  if (keyin2 != keyin1) {
    keyin2 = keyin1;
  } else {
    keyin3 = keyin2;
  }
}

void WaitKeyin(void) {
  do {
    ;
  } while (keyin3 == 0xFFFF);
  keyin = keyin3;
  do {
    ;
  } while (keyin3 != 0xFFFF);

  switch (keyin) {
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
  WaitKeyin();

  switch (keyin) {
    case KEY0:  // Decrease Time
      if (flag.display_which == DISPLAY_CLOCK) {
        switch (flag.op_unit) {
          case SEC:
            time++;
            break;
          case TEN_SEC:
            time += 10;
            break;
          case MIN:
            time += 60;
            break;
          case TEN_MIN:
            time += 600;
            break;
          case HOUR:
            time += 3600;
            break;
          case TEN_HOUR:
            time += 36000;
            break;
          case MODOFF:
            break;
          default:
            // ERROR, stop the system
            for (;;)
              ;
            break;
        }
      }
      break;

    case KEY1:  // Increase Time
      if (flag.display_which == DISPLAY_CLOCK) {
        switch (flag.op_unit) {
          case SEC:
            time++;
            break;
          case TEN_SEC:
            time += 10;
            break;
          case MIN:
            time += 60;
            break;
          case TEN_MIN:
            time += 600;
            break;
          case HOUR:
            time += 3600;
            break;
          case TEN_HOUR:
            time += 36000;
            break;
          case MODOFF:
            break;
          default:
            // ERROR, stop the system
            for (;;)
              ;
            break;
        }
      }
      break;

    case KEYC:  // Clear and Stop clock
      time = 0;
      flag.clock_start = CLOCK_STOP;
      break;

    case KEYD:  // change the time modification unit
      if (flag.display_which == DISPLAY_CLOCK) {
        switch (flag.op_unit) {
          case SEC:
            flag.op_unit = TEN_SEC;
            break;
          case TEN_SEC:
            flag.op_unit = MIN;
            break;
          case MIN:
            flag.op_unit = TEN_MIN;
            break;
          case TEN_MIN:
            flag.op_unit = HOUR;
            break;
          case HOUR:
            flag.op_unit = TEN_HOUR;
            break;
          case TEN_HOUR:
            flag.op_unit = MODOFF;
            break;
          case MODOFF:
            flag.op_unit = SEC;

          default:
            // ERROR, stop the system
            for (;;)
              ;
            break;
        }
      }
      break;

    case KEYE:  // change the speed of clock in 3 states
      switch (flag.clock_speed) {
        case HIGH_SPEED:
          flag.clock_speed = MEDIUM_SPEED;
          break;
        case MEDIUM_SPEED:
          flag.clock_speed = LOW_SPEED;
          break;
        case LOW_SPEED:
          flag.clock_speed = HIGH_SPEED;
          break;
        default:
          // ERROR, stop the system
          for (;;)
            ;
          break;
      }
      break;

    case KEYF:  // start / stop
      if (flag.display_which == DISPLAY_CLOCK) {
        // toggle the bit
        flag.clock_start = ~flag.clock_start;
      }
      break;

    default:
      break;
  }
  time_adj();
  keyin = 0xffff;
}