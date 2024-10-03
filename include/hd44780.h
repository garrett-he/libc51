#ifndef __HD44780_H__
#define __HD44780_H__

#ifndef __HD44780_CONFIG__
#define __HD44780_CONFIG__

__sbit __at(0xa4) HD44780_RS;    /* P2.4 */
__sbit __at(0xa5) HD44780_RW;    /* P2.5 */
__sbit __at(0xa6) HD44780_EN;    /* P2.6 */
__sfr  __at(0x80) HD44780_DP;    /* P0   */

#endif /* __HD44780_CONFIG__ */

/*
 * Clears display and returns cursor to the home position.
 */
#define hd44780_clear() hd44780_write_command(0x01)

/*
 * Returns cursor to home position, and returns display being shifted
 * to the original position. DDRAM content remains unchanged.
 */
#define hd44780_cursor_home() hd44780_write_command(0x02)

/*
 * Sets cursor move direction and specifies to shift the display.
 */
#define hd44780_entry_mode_set(direction, shift) hd44780_write_command(0x04 | (direction) << 1 | (shift))

/*
 * Sets on/off of all display, cursor and blink of cursor position character.
 */
#define hd44780_display_control(display, cursor, blink) hd44780_write_command(0x08 | (display) << 2 | (cursor) << 1 | (blink))

/*
 * Sets cursor-move or display_shift and shift direction. DDRAM content
 * remains unchanged.
 */
#define hd44780_shift(s_d, direction) hd44780_write_command(0x10 | (s_d) << 3 | (direction) << 2)

/*
 * Sets interface data length, number of display line and character font.
 */
#define hd44780_function_set(dl, line, font) hd44780_write_command(0x20 | (dl) << 4 | (line) << 3 | (font) << 2)

/*
 * Sets the CGRAM address. CGRAM data are sent and received after this
 * setting.
 */
#define hd44780_set_cgram_addr(addr) hd44780_write_command(0x40 | (addr))

/*
 * Sets the DDRAM address. DDRAM data are sent and received after this
 * setting.
 */
#define hd44780_set_ddram_addr(addr) hd44780_write_command(0x80 | (addr))

/*
 * Reads busy flag indicating internal operation being performed and reads
 * CGRAM or DDRAM address counter contents (depending on previous
 * instruction).
 */
unsigned char hd44780_read_bf_and_ac(void);

/*
 * Writes data to CGRAM or DDRAM.
 */
void hd44780_write_data(unsigned char ch);

/*
 * Writes command.
 */
void hd44780_write_command(unsigned char ch);

/*
 * Reads data from CGRAM or DDRAM.
 */
unsigned char hd44780_read_data(void);

#endif /* __HD44780_H__ */
