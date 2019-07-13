/*************************************************************************
	> File Name: cmd.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 16时46分01秒
 ************************************************************************/

#include<stdio.h>
#include"cmd.h"

void ls_cmd(void);
void ww_cmd(void);

cmd_t cmd_list[] = {
    {"ls", ls_cmd},
    {"ww", ww_cmd},
};

void *find_cmd(char *cmd_name){
    int i = 0;
    for(i = 0; i < ARRAY(cmd_list); i++){
        if(!strcmp(cmd_name, cmd_list[i].cmd_name)){
            return cmd_list[i].cb;
        }
    }
    printf("not found cmd name\n");
    return NULL;
}

void ls_cmd(void){
    printf("run cmd is ls!!!\n");
}

void ww_cmd(void){
    printf("run cmd is ww!!!\n");
}

