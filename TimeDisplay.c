#include "main.h"

unsigned int timer[6] = {0, 0, 0, 0, 0, 0};
extern Uint32 time;

void display(void) {
  int i, j;
  for (i = 0; i < 8; i++) {
    GpioDataRegs.GPADAT.bit.GPIOA11 = 0;
    if (i > 5) {
      SpiaRegs.SPITXBUF = LEDCode[19];
    } else if (i % 2 == 0) {
      SpiaRegs.SPITXBUF = LEDCode[timer[i]];
    } else {
      SpiaRegs.SPITXBUF = LEDCode[timer[i] + 20];
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