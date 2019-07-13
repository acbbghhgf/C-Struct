/*************************************************************************
	> File Name: cmd.h
	> Author: 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 16时43分22秒
 ************************************************************************/

#ifndef _CMD_H
#define _CMD_H


#define ARRAY(l)  sizeof(l)/sizeof(l[0])

typedef void (*cb_t)(void);

typedef struct cmd{
    char cmd_name[32];
    cb_t cb;
}cmd_t;

void *find_cmd(char *cmd_name);
#endif
