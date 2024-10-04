#ifndef __STC12ADC_H__
#define __STC12ADC_H__

#include <stdint.h>

#ifndef STC12ADC_PIN
#define STC12ADC_PIN

#define ADC_PIN 0

#endif /* STC12ADC_PIN */

#define ADC_POWER   0x80    // ADC power control bit
#define ADC_FLAG    0x10    // ADC complete flag
#define ADC_START   0x08    // ADC start control bit
#define ADC_SPEEDLL 0x00    // 540 clocks
#define ADC_SPEEDL  0x20    // 360 clocks
#define ADC_SPEEDH  0x40    // 180 clocks
#define ADC_SPEEDHH 0x60    // 90 clocks

__sfr __at(0xBC) ADC_CONTR;     // ADC control register
__sfr __at(0xBD) ADC_RES;       // ADC high 8-bit result register
__sfr __at(0xBE) ADC_LOW2;      // ADC low 2-bit result register
__sfr __at(0x9D) P1ASF;         // P1 secondary function control register

void stc12adc_init(void);

uint8_t stc12adc_sample(uint8_t ch);

#endif /* __STC12ADC_H__ */
