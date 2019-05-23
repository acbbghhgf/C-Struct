/*************************************************************************
	> File Name: mutex.c
	> Author: 
	> Mail: 
	> Created Time: 2019年05月23日 星期四 22时10分26秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
/*
 * 定义宏LOCK，能确保value1 == value2
 * 如果不使用锁，不能确保两个值相等。
* */
unsigned int count, value1, value2;
pthread_mutex_t lock;

void *function(void *arg);

int main(){
    pthread_t a_thread;
    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("fail to pthread_mutex_init \n");
        goto end;
    }
    if(pthread_create(&a_thread, NULL, function, NULL) != 0){
        printf("fail to pthread_create\n");
        goto end;
    }
    while(1){
        count++;
        #ifdef LOCK
        pthread_mutex_lock(&lock);
        #endif
        value1 = count;
        value2 = count;
        #ifdef LOCK
        pthread_mutex_unlock(&lock);
        #endif
    }

end:
    pthread_join(a_thread, NULL);
    return 0;
}

void *function(void *arg){
    while(1){
        #ifdef LOCK
        pthread_mutex_lock(&lock);
        #endif
        if(value1 != value2){
            printf("value1 = %u, value2 = %u \n", value1, value2);
            sleep(1);
        }
        #ifdef LOCK
        pthread_mutex_unlock(&lock);
        #endif
    }
    return NULL;
}
