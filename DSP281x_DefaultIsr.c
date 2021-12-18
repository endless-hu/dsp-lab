//###########################################################################
//
// FILE:	DSP281x_DefaultIsr.c
//
// TITLE:	DSP281x Device Default Interrupt Service Routines.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Search & Replace PieCtrl. with PieCtrlRegs.
//      |             |      | Added PIE Ack statements for XINT1 and XINT2 ISRs
//      |             |      | Changed the order to match the PIE vector table
//      |             |      | Changed USER0-USER11 to USER1-USER12
//###########################################################################

#include "DSP281x_Device.h"    // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"  // DSP281x Examples Include File
#include "main.h"

extern Uint32 time;
extern SysFlags flag;
extern Uint16 AD1;
extern Uint16 AD2;
extern const unsigned int LEDCode[33];

// Note CPU-Timer1 ISR is reserved for TI use.
interrupt void INT13_ISR(void)  // INT13 or CPU-Timer1
{
  // Insert ISR Code here
  //锟节此诧拷锟斤拷ISR
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");  //锟斤拷锟斤拷锟节碉拷锟皆碉拷时锟斤拷锟斤拷锟斤拷锟斤拷停锟斤拷锟斤拷锟斤拷锟斤拷
                        //锟斤拷锟斤拷芯锟斤拷锟斤拷ISR时锟斤拷要锟斤拷锟斤拷锟斤拷锟斤拷删锟斤拷锟斤拷
  for (;;)
    ;
}

// Note CPU-Timer2 ISR is reserved for TI use.
interrupt void INT14_ISR(void)  // CPU-Timer2
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void DATALOG_ISR(void)  // Datalogging interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void RTOSINT_ISR(void)  // RTOS interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void EMUINT_ISR(void)  // Emulation interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void NMI_ISR(void)  // Non-maskable interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void ILLEGAL_ISR(void)  // Illegal operation TRAP
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("          ESTOP0");
  for (;;)
    ;
}

interrupt void USER1_ISR(void)  // User Defined trap 1
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER2_ISR(void)  // User Defined trap 2
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER3_ISR(void)  // User Defined trap 3
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER4_ISR(void)  // User Defined trap 4
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER5_ISR(void)  // User Defined trap 5
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER6_ISR(void)  // User Defined trap 6
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER7_ISR(void)  // User Defined trap 7
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER8_ISR(void)  // User Defined trap 8
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER9_ISR(void)  // User Defined trap 9
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER10_ISR(void)  // User Defined trap 10
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER11_ISR(void)  // User Defined trap 11
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void USER12_ISR(void)  // User Defined trap 12
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// -----------------------------------------------------------
// PIE Group 1 - MUXed into CPU INT1
// -----------------------------------------------------------

// INT1.1
interrupt void PDPINTA_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT1.2
interrupt void PDPINTB_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT1.3 - Reserved

// INT1.4
interrupt void XINT1_ISR(void) {
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT1.5
interrupt void XINT2_ISR(void) {
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT1.6
interrupt void ADCINT_ISR(void)  // ADC
{
  // Insert ISR Code here

  AD1 = AdcRegs.ADCRESULT0 >> 4;
  AD2 = (AD1 * 3 * 1000) / 4095;  //瀹為檯AD鍊�*1000

  AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;    // reset SEQ1
  AdcRegs.ADCST.bit.INT_SEQ1_CLR = 0;  // clear the flag

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  // S/W/鍚姩
}

// INT1.7
interrupt void TINT0_ISR(void)  // CPU-Timer 0
{
  // CALLED EVERY 10 MS!!!
  // Insert ISR Code here
  static Uint16 cnt;
  cnt++;

  Keyscan();

  // time adjustment
  switch (flag.clock_speed) {
    case HIGH_SPEED: {
      if (flag.clock_start == CLOCK_START) {
        time++;
      }
    } break;

    case MEDIUM_SPEED: {
      if (flag.clock_start == CLOCK_START && cnt % 10 == 0) {
        time++;
      }
    } break;

    case LOW_SPEED: {
      if (flag.clock_start == CLOCK_START && cnt % 100 == 0) {
        time++;
      }
    } break;

    default:
      // Next two lines for debug only to halt the processor here
      asm("      ESTOP0");
      for (;;)
        ;
  }
  time_adj();

  // ADC adjustment, start ADC conversion EVERY 100 MS
  if (cnt == 10) {
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  // S/W/鍚姩
  }

  if (cnt == 20) {
    cnt = 0;
  }

  if (cnt % 2 == 0) {
    display();
  } else {
    display_latch();
  }

  PieCtrlRegs.PIEACK.all = 0x1;
  CpuTimer0Regs.TCR.all = 0xf000;

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

// INT1.8
interrupt void WAKEINT_ISR(void)  // WD
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// -----------------------------------------------------------
// PIE Group 2 - MUXed into CPU INT2
// -----------------------------------------------------------

// INT2.1
interrupt void CMP1INT_ISR(void)  // EV-A
{
  // Insert ISR Code here
  GpioDataRegs.GPFTOGGLE.all = 0x0900;  // 0000 1001 0000 0000

  // int i;
  // GpioDataRegs.GPBTOGGLE.all = 0x1100;  // 0001 0001 0000 0000
  // GpioDataRegs.GPEDAT.all = 0xFFFA;
  // for (i = 0; i < 100; i++) {
  // }
  // GpioDataRegs.GPEDAT.all = 0xFFFF;

  EvaRegs.EVAIFRA.all = 2;  // 缃綅CMPR1涓柇鏍囧織

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}

// INT2.2
interrupt void CMP2INT_ISR(void)  // EV-A
{
  // Insert ISR Code here
  GpioDataRegs.GPFTOGGLE.all = 0x1200;  // 0001 0010 0000 0000

  // int i;
  // GpioDataRegs.GPBTOGGLE.all = 0x2200;  // 0010 0010 0000 0000
  // GpioDataRegs.GPEDAT.all = 0xFFFA;
  // for (i = 0; i < 100; i++) {
  // }
  // GpioDataRegs.GPEDAT.all = 0xFFFF;

  EvaRegs.EVAIFRA.all = 4;  // 缃綅CMPR2涓柇鏍囧織
  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}

// INT2.3
interrupt void CMP3INT_ISR(void)  // EV-A
{
  // Insert ISR Code here
  GpioDataRegs.GPFTOGGLE.all = 0x2400;  // 0010 0100 0000 0000

  // int i;
  // GpioDataRegs.GPBTOGGLE.all = 0x2200;  // 0010 0010 0000 0000
  // GpioDataRegs.GPEDAT.all = 0xFFFA;
  // for (i = 0; i < 100; i++) {
  // }
  // GpioDataRegs.GPEDAT.all = 0xFFFF;

  EvaRegs.EVAIFRA.all = 8;  // 缃綅CMPR3涓柇鏍囧織
  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}

// INT2.4
interrupt void T1PINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  GpioDataRegs.GPFDAT.all = 0x0700;  // 0000 0111 0000 0000

  EvaRegs.CMPR1 = AD2PWM(AD2) / 3;
  EvaRegs.CMPR2 = AD2PWM(AD2) / 3 + 55;
  EvaRegs.CMPR3 = AD2PWM(AD2) / 3 + 110;

  // EvaRegs.EVAIFRA.bit.T1PINT = 1;
  EvaRegs.EVAIFRA.all = 0x80;  // set the P1INT flag
  // To receive more interrupts from this PIE group, acknowledge this interrupt
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}

// INT2.5
interrupt void T1CINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT2.6
interrupt void T1UFINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT2.7
interrupt void T1OFINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT2.8 - Reserved

// -----------------------------------------------------------
// PIE Group 3 - MUXed into CPU INT3
// -----------------------------------------------------------

// INT 3.1
interrupt void T2PINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.2
interrupt void T2CINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.3
interrupt void T2UFINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.4
interrupt void T2OFINT_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.5
interrupt void CAPINT1_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.6
interrupt void CAPINT2_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.7
interrupt void CAPINT3_ISR(void)  // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT3.8 - Reserved

// -----------------------------------------------------------
// PIE Group 4 - MUXed into CPU INT4
// -----------------------------------------------------------

// INT 4.1
interrupt void CMP4INT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.2
interrupt void CMP5INT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.3
interrupt void CMP6INT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.4
interrupt void T3PINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.5
interrupt void T3CINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.6
interrupt void T3UFINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.7
interrupt void T3OFINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT4.8 -- Reserved

// -----------------------------------------------------------
// PIE Group 5 - MUXed into CPU INT5
// -----------------------------------------------------------

// INT 5.1
interrupt void T4PINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.2
interrupt void T4CINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.3
interrupt void T4UFINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.4
interrupt void T4OFINT_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.5
interrupt void CAPINT4_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.6
interrupt void CAPINT5_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.7
interrupt void CAPINT6_ISR(void)  // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT5.8 - Reserved

// -----------------------------------------------------------
// PIE Group 6 - MUXed into CPU INT6
// -----------------------------------------------------------

// INT6.1
interrupt void SPIRXINTA_ISR(void)  // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT6.2
interrupt void SPITXINTA_ISR(void)  // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT6.3 - Reserved
// INT6.4 - Reserved

// INT6.5
interrupt void MRINTA_ISR(void)  // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT6.6
interrupt void MXINTA_ISR(void)  // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT6.7 - Reserved
// INT6.8 - Reserved

// -----------------------------------------------------------
// PIE Group 7 - MUXed into CPU INT7
// -----------------------------------------------------------

// INT7.1 - Reserved
// INT7.2 - Reserved
// INT7.3 - Reserved
// INT7.4 - Reserved
// INT7.5 - Reserved
// INT7.6 - Reserved
// INT7.7 - Reserved
// INT7.8 - Reserved

// -----------------------------------------------------------
// PIE Group 8 - MUXed into CPU INT8
// -----------------------------------------------------------

// INT8.1 - Reserved
// INT8.2 - Reserved
// INT8.3 - Reserved
// INT8.4 - Reserved
// INT8.5 - Reserved
// INT8.6 - Reserved
// INT8.7 - Reserved
// INT8.8 - Reserved

// -----------------------------------------------------------
// PIE Group 9 - MUXed into CPU INT9
// -----------------------------------------------------------

// INT9.1
interrupt void SCIRXINTA_ISR(void)  // SCI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT9.2
interrupt void SCITXINTA_ISR(void)  // SCI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT9.3
interrupt void SCIRXINTB_ISR(void)  // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT9.4
interrupt void SCITXINTB_ISR(void)  // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT9.5
interrupt void ECAN0INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// INT9.6
interrupt void ECAN1INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("      ESTOP0");
  for (;;)
    ;
}

// -----------------------------------------------------------
// PIE Group 10 - MUXed into CPU INT10
// -----------------------------------------------------------

// INT10.1 - Reserved
// INT10.2 - Reserved
// INT10.3 - Reserved
// INT10.4 - Reserved
// INT10.5 - Reserved
// INT10.6 - Reserved
// INT10.7 - Reserved
// INT10.8 - Reserved

// -----------------------------------------------------------
// PIE Group 11 - MUXed into CPU INT11
// -----------------------------------------------------------

// INT11.1 - Reserved
// INT11.2 - Reserved
// INT11.3 - Reserved
// INT11.4 - Reserved
// INT11.5 - Reserved
// INT11.6 - Reserved
// INT11.7 - Reserved
// INT11.8 - Reserved

// -----------------------------------------------------------
// PIE Group 12 - MUXed into CPU INT12
// -----------------------------------------------------------

// INT12.1 - Reserved
// INT12.2 - Reserved
// INT12.3 - Reserved
// INT12.4 - Reserved
// INT12.5 - Reserved
// INT12.6 - Reserved
// INT12.7 - Reserved
// INT12.8 - Reserved

//---------------------------------------------------------------------------
// Catch All Default ISRs:
//

interrupt void EMPTY_ISR(void)  // Empty ISR - only does a return.
{  //锟斤拷锟斤拷锟教ｏ拷锟斤拷锟斤拷锟斤拷纱锟斤拷卸喜锟斤拷锟斤拷姆锟斤拷亍锟�
}

interrupt void PIE_RESERVED(void)  // Reserved space.  For test.
{
  asm("      ESTOP0");
  for (;;)
    ;
}

interrupt void rsvd_ISR(void)  // For test
{
  asm("      ESTOP0");
  for (;;)
    ;
}

//===========================================================================
// No more.
//===========================================================================
