/*************************************************************************
    > File Name: udp_demo.c
    > Author: 
    > Mail: 
    > Created Time: 2019年05月26日 星期日 07时03分53秒
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>

#define BUFSIZE 128
#define QUIT_STR "quit"

void usage(char *s){
    printf("\n This is udp demo!\n");
    printf("\nUsage:\n\t %s serv_ip serv_port", s);
    printf("\n\t serv_ip: udp server ip address");
    printf("\n\t serv_port: udp server port \n\n");
}

int main(int argc, char **argv){
    int fd = -1;
    struct sockaddr_in sin;
    if(argc != 3){
        usage(argv[0]);
        printf("31\n");
        return -1;
    }
    int port = 0;
    port = atoi(argv[2]);
    if(port < 0 ||(port > 50000)){
        usage(argv[0]);
        printf("input port = [%d] 38\n", port);
        return -1;
    }

    if(fd = socket(AF_INET, SOCK_DGRAM, 0) < 0){
        perror("socket fail\n");
        return -1;
    }
    bzero(&sin, sizeof(sin));
    printf("-->port=[%d], addr=[%s]\n", port, argv[1]);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(argv[1]);
//    if(inet_pton(AF_INET, argv[1], (void *)&sin.sin_addr) != 1){
//        perror("inet_pton\n");
//        return -1;
//    }

    char buf[BUFSIZE];
    printf("UDP client starting ...OK\n");
    while(1){
        bzero(buf, BUFSIZE);
        printf("Please input the string to server:\n");
        if(fgets(buf, BUFSIZE -1, stdin) == NULL){
            perror("fgets fail\n");
            continue;
        }
        sendto(fd, buf, strlen(buf), 0, (struct sockaddr *)&sin, sizeof(sin));
        if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))){
            printf("Client is exited\n");
            break;
        }
    }
    printf("function over!\n");
    return 0;
}
