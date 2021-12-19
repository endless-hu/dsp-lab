#include "main.h"

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

Uint32 time = 0;
int keyin = 0xffff;
Uint16 AD2 = 0;
Uint16 AD1 = 0;
SysFlags flag;

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

void InitFlag() {
  flag.adc_start = ADC_START;
  flag.clock_start = CLOCK_START;
  flag.display_which = DISPLAY_CLOCK;
  flag.clock_speed = LOW_SPEED;
  flag.op_unit = MODOFF;
  GpioDataRegs.GPFDAT.all = 0x0700;  // 0000 0111
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
  IFR = 0x0;
  IER = 0X3;
  PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
  EDIS;

  InitFlag();

  EALLOW;
  PieCtrlRegs.PIEIER2.bit.INTx1 = 1;
  PieCtrlRegs.PIEIER2.bit.INTx2 = 1;
  PieCtrlRegs.PIEIER2.bit.INTx3 = 1;
  PieCtrlRegs.PIEIER2.bit.INTx4 = 1;
  EDIS;

  display();

  AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  // S/W/启动
  
  for (;;) {
    KeyFunction();
  }
}
