vpath %.S ./src/
vpath %.c ./src/

libc51.a: delay_12t.rel delay_1t.rel
	sdar -rc $@ $^

delay_1t.rel: delay_1t.S
	sdas8051 -o $@ $<

delay_12t.rel: delay_12t.S
	sdas8051 -o $@ $<
