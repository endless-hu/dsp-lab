#include "main.h"

unsigned int timer[6] = {0, 0, 0, 0, 0, 0};
extern Uint32 time;
extern SysFlags flag;
extern Uint16 AD1;
extern Uint16 AD2;
extern unsigned int LEDCode[33];

void display(void) {
  GpioDataRegs.GPADAT.bit.GPIOA11 = 0;
  if (flag.display_which == DISPLAY_CLOCK) {
    display_time();
  } else {
    display_adc();
  }
}

void time_adj() {
  if (time == 360000) {
    time = 0;
  }
  timer[5] = time % 60 % 10;
  timer[4] = time % 60 / 10;
  timer[3] = time % 3600 / 60 % 10;
  timer[2] = time % 3600 / 60 / 10;
  timer[1] = time % 360000 / 3600 % 10;
  timer[0] = time % 360000 / 3600 / 10;
  if (flag.display_which == DISPLAY_CLOCK) {
    display_time();
  }
}

void display_time() {
  int i, j;
  for (i = 0; i < 8; i++) {
    if (i > 5) {
      switch (flag.op_unit) {
        case MODOFF:
          SpiaRegs.SPITXBUF = LEDCode[BLANK];
          break;

        case SEC:
          // display 'S' at the last bit
          if (i == 6) {
            SpiaRegs.SPITXBUF = LEDCode[BLANK];
          } else {
            SpiaRegs.SPITXBUF = LEDCode[S];
          }
          break;

        case TEN_SEC:
          // display 'SS' at the last two bits
          SpiaRegs.SPITXBUF = LEDCode[S];
          break;

        case MIN:
          // display 'N' at the last bit
          if (i == 6) {
            SpiaRegs.SPITXBUF = LEDCode[BLANK];
          } else {
            SpiaRegs.SPITXBUF = LEDCode[N];
          }
          break;

        case TEN_MIN:
          // display 'NN' at the last two bits
          SpiaRegs.SPITXBUF = LEDCode[S];
          break;

        case HOUR:
          // display 'H' at the last bit
          if (i == 6) {
            SpiaRegs.SPITXBUF = LEDCode[BLANK];
          } else {
            SpiaRegs.SPITXBUF = LEDCode[H];
          }
          break;

        case TEN_HOUR:
          // display 'NN' at the last two bits
          SpiaRegs.SPITXBUF = LEDCode[H];
          break;

        default:
          // ERROR, stop the system
          for (;;)
            ;
          break;
      }
    } else if (i % 2 == 0) {
      SpiaRegs.SPITXBUF = LEDCode[timer[i]];
    } else {
      SpiaRegs.SPITXBUF = LEDCode[timer[i] + 20];
    }
  }
}

void display_adc() {
  int i;
  Uint16 code[8] = {
      AD2 / 1000 + 20, (AD2 % 1000) / 100, (AD2 % 100) / 10, BLANK,
      AD1 / 1000,      (AD1 % 1000) / 100, (AD1 % 100) / 10, AD1 % 10};
  for (i = 0; i < 8; i++) {
    SpiaRegs.SPITXBUF = LEDCode[code[i]];
  }
}

void display_latch() { GpioDataRegs.GPADAT.bit.GPIOA11 = 1; }
