vpath %.S ./src/
vpath %.c ./src/

libc51.a: delay_12t.rel delay_1t.rel hd44780.rel
	sdar -rc $@ $^

hd44780.rel: hd44780.c
	sdcc -c -o $@ $<

delay_1t.rel: delay_1t.S
	sdas8051 -o $@ $<

delay_12t.rel: delay_12t.S
	sdas8051 -o $@ $<
