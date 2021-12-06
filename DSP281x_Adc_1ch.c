//###########################################################################
//
// FILE:	DSP281x_Adc.c
//
// TITLE:	DSP281x ADC Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | ADC_usDELAY changed from 5000L to 8000L
//###########################################################################

#include "DSP281x_Device.h"  // DSP281x Headerfile Include File

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void AdcPowerUp(void) {
  // To powerup the ADC the ADCENCLK bit should be set first to enable
  // clocks, followed by powering up the bandgap and reference circuitry.
  // After a 5ms delay the rest of the ADC can be powered up. After ADC
  // powerup, another 20us delay is required before performing the first
  // ADC conversion. Please note that for the delay function below to
  // operate correctly the CPU_CLOCK_SPEED define statement in the
  // DSP28_Examples.h file must contain the correct CPU clock period in
  // nanoseconds(nS). For example:

  int i;

  AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;  // Power up bandgap/reference circuitry
                                        //��϶�Ͳο���·�ϵ�
  for (i = 0; i < 1000000; i++)
    ;                               // Delay before powering up rest of ADC
                                    // ADC�ϵ縴λǰ������ʱ5ms
  AdcRegs.ADCTRL3.bit.ADCPWDN = 1;  // Power up rest of ADC
                                    // ADC�ϵ縴λ
  for (i = 0; i < 10000; i++)
    ;  // Delay after powering up ADC
       // ADC�ϵ縴λ����ʱ20us
}

//===========================================================================
// No more.
//===========================================================================
