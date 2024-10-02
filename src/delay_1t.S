    .globl _delay_12cct_1t
    .globl _delay_120cct_1t
    .globl _delay_1200cct_1t
    .globl _delay_12kcct_1t
    .globl _delay_120kcct_1t
    .globl _delay_1200kcct_1t
    .globl _delay_12mcct_1t

    .area DELAY_1T (CODE)

; =========================================================
; void delay_12cct_1t(void)
; =========================================================
_delay_12cct_1t:
        nop
        nop
        ret

; =========================================================
; void delay_120cct_1t(void)
; =========================================================
_delay_120cct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0x17

    delay_120cct_1t_loop0:
        djnz r7, delay_120cct_1t_loop0

        pop psw
        nop
        ret

; =========================================================
; void delay_1200cct_1t(void)
; =========================================================
_delay_1200cct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0x02

    delay_1200cct_1t_loop0:
        mov r6, #0x91

    delay_1200cct_1t_loop1:
        djnz r6, delay_1200cct_1t_loop1
        djnz r7, delay_1200cct_1t_loop0

        pop psw
        nop
        ret

; =========================================================
; void delay_12kcct_1t(void)
; =========================================================
_delay_12kcct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0x52

    delay_12kcct_1t_loop0:
        mov r6, #0x23

    delay_12kcct_1t_loop1:
        djnz r6, delay_12kcct_1t_loop1
        djnz r7, delay_12kcct_1t_loop0

        pop psw
        nop
        ret

; =========================================================
; void delay_120kcct_1t(void)
; =========================================================
_delay_120kcct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xb2

    delay_120kcct_1t_loop0:
        mov r6, #0x02

    delay_120kcct_1t_loop1:
        mov r5, #0x52

    delay_120kcct_1t_loop2:
        djnz r5, delay_120kcct_1t_loop2
        djnz r6, delay_120kcct_1t_loop1
        djnz r7, delay_120kcct_1t_loop0

        pop psw
        nop
        nop
        nop
        ret

; =========================================================
; void delay_1200kcct_1t(void)
; =========================================================
_delay_1200kcct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xc9

    delay_1200kcct_1t_loop0:
        mov r6, #0x8e

    delay_1200kcct_1t_loop1:
        mov r5, #0x09

    delay_1200kcct_1t_loop2:
        djnz r5, delay_1200kcct_1t_loop2
        djnz r6, delay_1200kcct_1t_loop1
        djnz r7, delay_1200kcct_1t_loop0

        pop psw
        nop
        nop
        nop
        ret

; =========================================================
; void delay_12mcct_1t(void)
; =========================================================
_delay_12mcct_1t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0x97

    delay_12mcct_1t_loop0:
        mov r6, #0x84

    delay_12mcct_1t_loop1:
        mov r5, #0x95

    delay_12mcct_1t_loop2:
        djnz r5, delay_12mcct_1t_loop2
        djnz r6, delay_12mcct_1t_loop1
        djnz r7, delay_12mcct_1t_loop0

        pop psw
        nop
        nop
        nop
        ret
