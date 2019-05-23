/*************************************************************************
	> File Name: sem.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 21时49分51秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

char buf[32];
sem_t sem_r, sem_w;
void *function(void *arg);

int main(){
    pthread_t a_thread;
    if(sem_init(&sem_r, 0, 0) < 0){
        perror("sem_init");
        exit(-1);
    }
    if(sem_init(&sem_w, 0, 1) < 0){
        perror("sem_init");
        exit(-1);
    }
    if(pthread_create(&a_thread, NULL, function, NULL) != 0){
        printf("fail to pthread create\n");
        exit(-1);
    }
    printf("input 'quit' to exit\n");
    do{
        sem_wait(&sem_w);
        fgets(buf, 32, stdin);
        sem_post(&sem_r);
    }while(strncmp(buf, "quit", 4)!= 0);
    return 0;
}

void *function(void *arg){
    while(1){
        sem_wait(&sem_r);
        printf("you enter %lu characters\n", strlen(buf));
        sem_post(&sem_w);
    }
}
