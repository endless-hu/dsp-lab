//###########################################################################
//
// FILE:   DSP281x_Spi.c
//
// TITLE:  DSP281x SPI Initialization & Support Functions.
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
// InitSPI:
//---------------------------------------------------------------------------
// This function initializes the SPI(s) to a known state.
//
void InitSpi(void) {
  // Initialize SPI-A:

  // tbd...
  SpiaRegs.SPICCR.all = 0x0047;  // 复位状态；
  SpiaRegs.SPICTL.all = 0x0006;  // 主模式，禁用中断
  SpiaRegs.SPIBRR = 0x007F;      // 配置波特率；
  SpiaRegs.SPICCR.all = SpiaRegs.SPICCR.all | 0x0080;
  // 退出复位状态；
  EALLOW;
  GpioMuxRegs.GPFMUX.all = 0x000F;  // 配置引脚；
  SpiaRegs.SPIFFTX.all = 0xE000;    //使能FIFO
  SpiaRegs.SPIFFCT.all = 8;         //帧间延时
  EDIS;
}

//===========================================================================
// No more.
//===========================================================================
