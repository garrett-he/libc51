    .globl _delay_120cct_12t
    .globl _delay_1200cct_12t
    .globl _delay_12kcct_12t
    .globl _delay_120kcct_12t
    .globl _delay_1200kcct_12t
    .globl _delay_12mcct_12t

    .area DELAY_12T (CODE)

; =========================================================
; void delay_120cct_12t(void)
; =========================================================
_delay_120cct_12t:
        nop
        nop
        nop
        nop
        nop
        nop
        ret

; =========================================================
; void delay_1200cct_12t(void)
; =========================================================
_delay_1200cct_12t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0x26

    delay_1200cct_12t_loop0:
        mov r6, #0x0f

    delay_1200cct_12t_loop1:
        djnz r6, delay_1200cct_12t_loop1
        djnz r7, delay_1200cct_12t_loop0

        pop psw
        nop
        nop
        ret

; =========================================================
; void delay_12kcct_12t(void)
; =========================================================
_delay_12kcct_12t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xe5

    delay_12kcct_12t_loop0:
        mov r6, #0x1a

    delay_12kcct_12t_loop1:
        djnz r6, delay_12kcct_12t_loop1
        djnz r7, delay_12kcct_12t_loop0

        pop psw
        nop
        ret

; =========================================================
; void delay_120kcct_12t(void)
; =========================================================
_delay_120kcct_12t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xb4

    delay_120kcct_12t_loop0:
        mov r6, #0x05

    delay_120kcct_12t_loop1:
        mov r5, #0x42

    delay_120kcct_12t_loop2:
        djnz r5, delay_120kcct_12t_loop2
        djnz r6, delay_120kcct_12t_loop1
        djnz r7, delay_120kcct_12t_loop0

        pop psw
        nop
        nop
        ret

; =========================================================
; void delay_1200kcct_12t(void)
; =========================================================
_delay_1200kcct_12t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xfb

    delay_1200kcct_12t_loop0:
        mov r6, #0x42

    delay_1200kcct_12t_loop1:
        mov r5, #0x24

    delay_1200kcct_12t_loop2:
        djnz r5, delay_1200kcct_12t_loop2
        djnz r6, delay_1200kcct_12t_loop1
        djnz r7, delay_1200kcct_12t_loop0

        pop psw
        nop
        nop
        ret

; =========================================================
; void delay_12mcct_12t(void)
; =========================================================
_delay_12mcct_12t:
        push psw
        setb 0xd3
        setb 0xd4

        mov r7, #0xd0

    delay_12mcct_12t_loop0:
        mov r6, #0x81

    delay_12mcct_12t_loop1:
        mov r5, #0xde

    delay_12mcct_12t_loop2:
        djnz r5, delay_12mcct_12t_loop2
        djnz r6, delay_12mcct_12t_loop1
        djnz r7, delay_12mcct_12t_loop0

        pop psw
        nop
        nop
        ret
