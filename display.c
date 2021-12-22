#include "main.h"

unsigned int timer[6] = {0, 0, 0, 0, 0, 0};
extern Uint32 time;
extern SysFlags flag;
extern Uint16 AD1;
extern Uint16 AD2;
extern const unsigned int LEDCode[33];

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
}

void display_time() {
  SpiaRegs.SPITXBUF = LEDCode[timer[5]];
  SpiaRegs.SPITXBUF = LEDCode[timer[4]];
  SpiaRegs.SPITXBUF = LEDCode[33];
  SpiaRegs.SPITXBUF = LEDCode[timer[3]];
  SpiaRegs.SPITXBUF = LEDCode[timer[2]];
  SpiaRegs.SPITXBUF = LEDCode[33];
  SpiaRegs.SPITXBUF = LEDCode[timer[1]];
  SpiaRegs.SPITXBUF = LEDCode[timer[0]];
}

void display_adc() {
  int i;
  Uint16 code[8] = {
      AD2 / 1000,      (AD2 % 1000) / 100, (AD2 % 100) / 10, BLANK,
      AD1 / 1000 + 20, (AD1 % 1000) / 100, (AD1 % 100) / 10, AD1 % 10};
  for (i = 0; i < 8; i++) {
    SpiaRegs.SPITXBUF = LEDCode[code[i]];
  }
}

void display_latch() { GpioDataRegs.GPADAT.bit.GPIOA11 = 1; }
