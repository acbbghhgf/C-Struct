/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月02日 星期二 22时13分13秒
 *********************************************************************/
#include "uart.h"
#include "led.h"
#include "strcmp.h"

static char buf[32];

int main(void){
    uart_init();
    led_init();

    while(1){
        uart_puts("\n Shell#");
        uart_gets("buf, 32");
        if(!my_strcmp(buf, "led on")){
            led_on();
        }
        else if(!my_strcmp(buf, "led off")){
            led_off();
        }
        uart_puts("\n you input msg is invaled");
    }
}
