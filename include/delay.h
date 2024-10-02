#ifndef __DELAY_H__
#define __DELAY_H__

void delay_12cct_1t(void);
void delay_120cct_1t(void);
void delay_1200cct_1t(void);
void delay_12kcct_1t(void);
void delay_120kcct_1t(void);
void delay_1200kcct_1t(void);
void delay_12mcct_1t(void);

#define delay_12cct_12t() __asm nop __endasm
void delay_120cct_12t(void);
void delay_1200cct_12t(void);
void delay_12kcct_12t(void);
void delay_120kcct_12t(void);
void delay_1200kcct_12t(void);
void delay_12mcct_12t(void);

#ifdef __STC_Y2__
    #define delay_12cct delay_12cct_1t
    #define delay_120cct delay_120cct_1t
    #define delay_1200cct delay_1200cct_1t
    #define delay_12kcct delay_12kcct_1t
    #define delay_120kcct delay_120kcct_1t
    #define delay_1200kcct delay_1200kcct_1t
    #define delay_12mcct delay_12mcct_1t
#else
    #define delay_12cct delay_12cct_12t
    #define delay_120cct delay_120cct_12t
    #define delay_1200cct delay_1200cct_12t
    #define delay_12kcct delay_12kcct_12t
    #define delay_120kcct delay_120kcct_12t
    #define delay_1200kcct delay_1200kcct_12t
    #define delay_12mcct delay_12mcct_12t
#endif /* __STC_Y2__ */

#endif /* __DELAY_H__ */
