#include <stdint.h>
#include <mcs51/8052.h>
#include "../include/delay.h"
#include "../include/hd44780.h"

#define HD44780_BUSY_FLAG (1 << 7)

unsigned char hd44780_read_bf_and_ac(void) {
    unsigned char ch;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_RS = 0;
    HD44780_RW = 1;
    HD44780_EN = 1;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    ch = HD44780_DP;

    HD44780_EN = 0;

    return ch;

}

void hd44780_write_command(unsigned char ch) {
    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_RS = 0;
    HD44780_RW = 0;
    HD44780_EN = 1;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_DP = ch;

    HD44780_EN = 0;

}

void hd44780_write_data(unsigned char ch) {
    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_RS = 1;
    HD44780_RW = 0;
    HD44780_EN = 1;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_DP = ch;

    HD44780_EN = 0;

}

unsigned char hd44780_read_data(void) {
    unsigned char ch;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    HD44780_RS = 1;
    HD44780_RW = 1;
    HD44780_EN = 1;

    while (hd44780_read_bf_and_ac() & HD44780_BUSY_FLAG);

    ch = HD44780_DP;

    HD44780_EN = 0;

    return ch;
}
