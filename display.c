#include "main.h"

unsigned int timer[6] = {0, 0, 0, 0, 0, 0};
extern Uint32 time;
extern SysFlags flag;

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
  display();
}

void display_time() {
  int i, j;
  for (i = 0; i < 8; i++) {
    if (i > 5) {
      SpiaRegs.SPITXBUF = LEDCode[19];
    } else if (i % 2 == 0) {
      SpiaRegs.SPITXBUF = LEDCode[timer[i]];
    } else {
      SpiaRegs.SPITXBUF = LEDCode[timer[i] + 20];
    }
    SpiaRegs.SPIRXBUF = SpiaRegs.SPIRXBUF;
  }
}

void display_adc() {}

void display_latch() { GpioDataRegs.GPADAT.bit.GPIOA11 = 1; }