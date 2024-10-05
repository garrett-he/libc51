#include <mcs51/8051.h>
#define __STC_Y2__
#include "include/delay.h"

void delay() {
    delay_1200kcct();
}

void main() {
    while(1) {
        P1 = 0xFF;
        delay();
        P1 = 0x00;
        delay();
    }
}