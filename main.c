#include "main.h"

Uint32 time = 0;
int keyin = 0xffff;
Uint16 AD2;
Uint16 AD1;
SysFlags flag;

void InitFlag() {
  flag.adc_start = ADC_START;
  flag.clock_start = CLOCK_START;
  flag.display_which = DISPLAY_CLOCK;
  flag.clock_speed = LOW_SPEED;
}

void main(void) {
  InitSysCtrl();
  AdcPowerUp();
  InitAdc();

  InitGpio();
  InitCpuTimers();  // CPU timer interrupts every 10 ms

  InitPieCtrl();
  InitPieVectTable();
  InitSpi();
  EnableInterrupts();
  InitEv();

  EALLOW;
  asm("  and IFR,#00H");
  asm("  or  IER,#01H");
  asm("  EINT");
  SysCtrlRegs.LPMCR0.all = 0x0;
  EDIS;

  InitFlag();

  display();
  for (;;) {
    KeyFunction();
  }
}
