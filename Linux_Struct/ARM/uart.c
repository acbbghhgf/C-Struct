/*************************************************************************
	> File Name: uart.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月02日 星期二 22时17分26秒
 ************************************************************************/

#include "uart.h"

void uart_init(void){
    UARTCLKENB &= ~(1 << 2);

    GPIODALTFN0 &= ~(3 << 28);
    GPIODALTFN0 |= (1 << 28);
    GPIODALTFN1 &= ~(3 << 4);
    GPIODALTFN1 |= (1 << 4);

    ULCON0 = 3;
    UCON0 = 5;

    UARTCLKGEN0 &= ~(0xFF << 5);
    UARTCLKGEN0 |= (0xF << 5);

    UBRDIV0 = 26;
    UFRACVAL0 = 2;

    UARTCLKENB |= (1 << 2);
}

void uart_putc(char c){
    while(!(UTRSTAT0 & 0x02));
    UTXH0 = c;
    if(c == '\n'){
        uart_putc('\r');
    }
}

void uart_puts(char *str){
    while(*str){
        uart_putc(*str);
        str++;
    }
}

char uart_getc(void){
    while(!(UTRSTAT0 & 0x1));
    return URXH0 & 0xFF;// return [0:7]
}

void uart_gets(char buf[], int len){
    int i;
    for(i = 0; i < len - 1; i++){
        buf[i] = uart_getc();
        // return display
        uart_putc(buf[i]);
        // \n break
        if(buf[i] == '\n'){
            break;
        }
    }
    buf[i] = '\0';
}
