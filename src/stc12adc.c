#include <stdint.h>
#include <mcs51/stc12.h>
#include "../include/delay.h"
#include "../include/stc12adc.h"

void stc12adc_init(void) {
    P1ASF = 0xff; // Open 8 channels ADC function
    ADC_RES = 0; // Clear previous result

    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;

    delay_12kcct();    // ADC power-on and delay
}

uint8_t stc12adc_sample(uint8_t ch) {
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;

    __asm
    nop
    nop
    nop
    nop
    __endasm;

    while (!(ADC_CONTR & ADC_FLAG)); // Wait for the complete flag

    ADC_CONTR &= ~ADC_FLAG; // Close ADC

    return ADC_RES; // Return ADC result
}
