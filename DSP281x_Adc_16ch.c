//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_Adc.c
//
// TITLE:	DSP28 ADC Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#include "DSP281x_Device.h"

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void) {
  AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;   //双序列
  AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;  //顺序采样
  AdcRegs.ADCTRL1.bit.CONT_RUN = 0;   //启停方式
  AdcRegs.ADCTRL1.bit.CPS = 1;        // 核时钟预定标器
  //:ADC_CLK=ADCLKPS/2=3.125M
  AdcRegs.ADCTRL1.bit.ACQ_PS = 0xf;  // 采样窗口
  AdcRegs.ADCTRL3.bit.ADCCLKPS = 0x2;
  ////:ADCLKPS=HSPCLK/4=6.25M
  AdcRegs.ADCMAXCONV.all = 0x0000;  //转换通道数:1
  AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0xf;
}

//===========================================================================
// No more.
//===========================================================================
