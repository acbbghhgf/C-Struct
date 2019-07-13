/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 15时55分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"cmd.h"

//extern void *find_cmd(char *cmd_name);

int main(){
    char msg[128] = {0};
    char buf[64] = {0};
    int ret = 0;
    cb_t cmd_cb;
    while(1){
        gets(msg);
        //ret = scanf("%s", msg);
        if(msg == NULL){
//            perror("scanf\n");
            printf("gets error\n");
        }
        if(!strcmp(msg, "quit")){
            printf("quit...\n");
            break;
        }
        printf("ypu input msg :\n");
        puts(msg);
        cmd_cb = find_cmd(msg);
        if(cmd_cb != NULL){
            cmd_cb();
        }
    }
}
