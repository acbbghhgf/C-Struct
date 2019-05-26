/*************************************************************************
	> File Name: udp_demo.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月25日 星期六 07时04分23秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<string.h>
#include<arpa/inet.h>

#define BUFSIZE 128
#define SERV_PORT 8888
#define QUIT_STR "quit"

int main(){
    //create socket
    int fd = -1;
    fd = socket(AF_INET,SOCK_DGRAM, 0);
    if(fd < 0){
        perror("socket fail\n");
        return -1;
    }
    int b_reuse = 1;
    //bind setopt
    //setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof(int));
    //bind
    struct sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    int ret = bind(fd, (struct sockaddr *)&sin, sizeof(sin));
    if(ret < 0){
        perror("bind fail\n");
        return -1;
    }
    char buf[BUFSIZE];
    struct sockaddr_in client_sin;
    socklen_t addrlen = sizeof(client_sin);
    char ipv4_addr[16];
    while(1){
        bzero(buf, BUFSIZE);
        bzero(ipv4_addr, sizeof(ipv4_addr));
        printf("recv msg waiting...\n");
        ret = recvfrom(fd, buf, sizeof(buf), 0,(struct sockaddr *)&client_sin, &addrlen);
        printf("recv msg success\n");
        if(ret < 0){
            perror("recvfrom fail\n");
            continue;
        }
        if(!inet_ntop(AF_INET, (void *)&client_sin.sin_addr, ipv4_addr, sizeof(client_sin))){
            perror("inet_ntop fail\n");
            return -1;
        }
        printf("Recived from(%s:%d), data: %s\n", ipv4_addr, ntohs(client_sin.sin_port), buf);
        if(!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))){//recv quit
            printf("Client(%s:%d) is exiting!\n", ipv4_addr, ntohs(client_sin.sin_port));
            break;
        }
    }
    printf("function over\n");
    return 0;
}
