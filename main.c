#include "main.h"
#include "KeyFunction.h"

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

void InitPIE(void) {
  EALLOW;
  PieCtrlRegs.PIEIFR1.all = 0x0000;
  PieCtrlRegs.PIEIER1.all = 0x0040;
  PieCtrlRegs.PIECRTL.bit.ENPIE = 0x1;
  PieCtrlRegs.PIEACK.all = 0x1;
  EDIS;
}


Uint32 time = 0;
int keyin = 0xffff;
ClockFlags flag;

void main(void) {
  InitSysCtrl();
  InitGpioBEF();
  InitCputimer();
  InitPIE();
  InitPieCtrl();
  InitPieVectTable();
  InitSpi();
  EnableInterrupts();
  EALLOW;
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

