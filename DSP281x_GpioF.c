//###########################################################################
//
// FILE:	DSP281x_Gpio.c
//
// TITLE:	DSP281x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | No change since previous version (v.58 Alpha)
//###########################################################################

#include "DSP281x_Device.h"    // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"  // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitGpio:
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known state.
//
void InitGpio(void) {
  EALLOW;
  // Set GPIO F port pins Output
  GpioMuxRegs.GPFMUX.all = 0x0000;
  GpioMuxRegs.GPFDIR.all = 0xFF00;  // upper byte as output/low byte as input

  GpioMuxRegs.GPBMUX.all = 0x0000;
  GpioMuxRegs.GPBDIR.all = 0xFF00;

  GpioMuxRegs.GPEMUX.all = 0x0000;
  GpioMuxRegs.GPEDIR.all = 0x0007;

  GpioMuxRegs.GPAMUX.bit.TDIRA_GPIOA11 = 0;
  GpioMuxRegs.GPADIR.bit.GPIOA11 = 1;
  EDIS;

  GpioDataRegs.GPADAT.bit.GPIOA11 = 0;
}

//===========================================================================
// No more.
//===========================================================================
