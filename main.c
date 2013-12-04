#include <msp430g2553.h>
#include "sensor.h"

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  //enable ADC10 subsystem
  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK

  //set up LEDs as outputs
  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1DIR |= BIT6;							// Set P1.6 to output direction

  ADC10CTL0 &= ~ENC; 							//clearing core, stop the sample and conversion sequence
  ADC10CTL1 = INCH_4;                       // input A4
  ADC10AE0 |= BIT4;                         // PA.1 ADC option select




  for (;;)
  {
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start, do this for each sensor
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

    if (ADC10MEM < 0x1FF)
      P1OUT &= ~0x01;                       // Clear P1.0 LED off
    else
      P1OUT |= 0x01;                        // Set P1.0 LED on
  }

    return 0;
}



