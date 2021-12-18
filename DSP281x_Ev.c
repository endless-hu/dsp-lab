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
                            // 浣� EvaRegs.GPTCONA.T1CMPOE 浣嶆湁鏁�
  // EvaRegs.GPTCONA.all = 0x0010;
  EvaRegs.GPTCONA.bit.T1CMPOE = 1;

  // EvaRegs.T1CON.bit.TMODE = 2;  // 10B, 杩炵画澧炶鏁版ā寮�, 瀵瑰簲绗�12~11浣�
  // EvaRegs.T1CON.bit.TPS = 7;  // 111B, 瀵归珮閫熷璁炬椂閽�128鍒嗛锛屽搴旂10~8浣�
  // 绗�7浣嶆槸淇濈暀浣�
  // EvaRegs.T1CON.bit.TENABLE = 1;  // 寮�濮嬭鏃�, 绗�6浣�
  // EvaRegs.T1CON.bit.TCLKS10 = 1;   // 01B, 閫夋嫨澶栭儴鏃堕挓婧�, 瀵瑰簲绗�5~4浣�
  // EvaRegs.T1CON.bit.TCLD10 = 2;   // 10B, 绔嬪嵆閲嶈浇姣旇緝瀵勫瓨鍣�, 瀵瑰簲绗�3~2浣�
  // EvaRegs.T1CON.bit.TECMPR = 1;  // 浣胯兘姣旇緝涓柇, 瀵瑰簲绗�1浣�
  // 绗�0浣嶆槸淇濈暀浣�, 鍙T2鍜孴4鏈夋晥; T2璇ヤ綅涓�1鏃禩2灏嗕娇鐢═1鐨勫懆鏈熷瘎瀛樺櫒
  EvaRegs.T1CON.all = 0x17ca;

  EvaRegs.T1PR = 340;  // 鍛ㄦ湡瀵勫瓨鍣�, 瀛樻斁鍛ㄦ湡璁℃暟鍊�

  EvaRegs.COMCONA.all = 0x82e0;  // 1000 0010 1110 0000
  /**                 浣胯兘姣旇緝鍗曞厓 <-+||| ||   |||
   *  褰揟1CNT==0鏃剁珛鍗抽噸杞紺MPRx <-----++| ||   |||
   *  Disable spatial vector PWM  <----+ ||  Enable CMPR1,2,3
   *                         Reload ACTRA When T1CNT==0
   */

  EvaRegs.ACTRA.all = 0x1;  // 姣旇緝杈撳嚭寮曡剼1浣庣數骞虫湁鏁堬紝鍏朵綑寮哄埗浣庣數骞�
  EvaRegs.DBTCONA.all = 00;  // 姝诲尯鎺у埗瀵勫瓨鍣紝杩欓噷灞忚斀鎵�鏈夋鍖哄畾鏃跺櫒
  EvaRegs.CMPR1 = AD2PWM(AD2) / 3 + 10;
  EvaRegs.CMPR2 = AD2PWM(AD2) / 3 + 55;
  EvaRegs.CMPR3 = AD2PWM(AD2) / 3 + 110;
  EvaRegs.EVAIMRA.all = 0x8e;
  EvaRegs.EVAIFRA.all = 0;
  EDIS;
}

//===========================================================================
// No more.
//===========================================================================
