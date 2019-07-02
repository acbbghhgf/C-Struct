/*************************************************************************
	> File Name: uart.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月02日 星期二 22时31分49秒
 ************************************************************************/

#ifndef _UART_H
#define _UART_H

//uart conf
#define ULCON0      (*(unsigned long *)0xC00A1000)
#define UCON0       (*(unsigned long *)0xC00A1004)
#define UTRSTAT0    (*(unsigned long *)0xC00A1010)
#define UTXH0       (*(unsigned long *)0xC00A1020)
#define URXH0       (*(unsigned long *)0xC00A1024)
#define UBRDIV0     (*(unsigned long *)0xC00A1028)
#define UFRACVAL0   (*(unsigned long *)0xC00A102C)

//gpio conf
#define GPIODALTFN0 (*(unsigned long *)0xC001D020)
#define GPIODALTFN1 (*(unsigned long *)0xC001D024)

//uart clk conf
#define UARTCLKENB  (*(unsigned long *)0xC00A9000)
#define UARTCLKGEN0 (*(unsigned long *)0xC00A9004)

extern void uart_init(void);
extern void uart_putc(char c);
extern void uart_puts(char *str);
extern char uart_getc(void);
extern void uart_gets(char buf[], int len);


#endif
