//###########################################################################
//
// FILE:	DSP281x_Ev.c
//
// TITLE:	DSP281x Event Manager Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | No change since previous version (v.58 Alpha)
//###########################################################################

#include "DSP281x_Device.h"  // DSP281x Headerfile Include File
#include "main.h"

extern Uint16 AD2;
//---------------------------------------------------------------------------
// InitEv:
//---------------------------------------------------------------------------
// This function initializes to a known state.
//
void InitEv(void) {
  EALLOW;
  EvaRegs.EXTCONA.all = 1;  // allow independent enable/disable COMPR interrupt
                            // 使 EvaRegs.GPTCONA.T1CMPOE 位有效
  // EvaRegs.GPTCONA.all = 0x0010;
  EvaRegs.GPTCONA.bit.T1CMPOE = 1;

  // EvaRegs.T1CON.bit.TMODE = 2;  // 10B, 连续增计数模式, 对应第12~11位
  // EvaRegs.T1CON.bit.TPS = 7;  // 111B, 对高速外设时钟128分频，对应第10~8位
  // 第7位是保留位
  // EvaRegs.T1CON.bit.TENABLE = 1;  // 开始计时
  // EvaRegs.T1CON.bit.TCLD10 = 2;   // 10B, 立即重载比较寄存器
  // 第0位是保留位, 只对T2和T4有效; T2该位为1时T2将使用T1的周期寄存器
  EvaRegs.T1CON.all = 0x17ca;

  EvaRegs.T1PR = 340;  // 周期寄存器, 存放周期计数值

  EvaRegs.COMCONA.all = 0x82e0;  // 1000 0010 1110 0000
  /**                 使能比较单元 <-+||| ||   |||
   *  当T1CNT==0时立即重载CMPRx <-----++| ||   |||
   *  Disable spatial vector PWM  <----+ ||  Enable CMPR1
   *                         Reload ACTRA When T1CNT==0
   */

  EvaRegs.ACTRA.all = 0x1;  // 比较输出引脚1低电平有效，其余强制低电平
  EvaRegs.DBTCONA.all = 00;
  EvaRegs.CMPR1 = AD2PWM(AD2) / 3;
  EvaRegs.CMPR2 = AD2PWM(AD2) / 3 + 12;
  EvaRegs.CMPR3 = AD2PWM(AD2) / 3 + 14;
  EvaRegs.EVAIMRA.all = 0x8e;
  EvaRegs.EVAIFRA.all = 0;
  EDIS;
}

//===========================================================================
// No more.
//===========================================================================
