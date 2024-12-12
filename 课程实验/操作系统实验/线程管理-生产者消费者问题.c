/**
 * @file 线程管理-生产者消费者问题.c
 * @author Ainzs
 * @brief 先使用gcc链接pthread库进行编译（gcc -o producer_consumer 文件名.c -lpthread），再在命令行运行（.\producer_consumer）
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <pthread.h>
#include <windows.h>

#define N 100
#define true 1
#define producerNum 10
#define consumerNum 5
#define sleepTime 1000

typedef int semaphore;
typedef int item;

item buffer[N] = {0};
int in = 0;
int out = 0;
int proCount = 0;
semaphore mutex = 1, empty = N, full = 0, proCmutex = 1;

void * producer (void * a) {
    while (true) {
        empty--;
        while(mutex <= 0);
        mutex--;
        buffer[in] = proCount;

        // 添加部分：更新商品ID
        proCount++;

        in = (in + 1) % N;
        mutex++;
        full++;
        printf("\t\t\t\t create a product with ID: %d, position in buffer: %d\n", proCount, in);
        Sleep(sleepTime);
    }
}

void * consumer (void *b) {
    while (true) {
        full--;
        while(mutex <= 0);
        mutex--;
        int nextc = buffer[out];
        buffer[out] = 0;//消费完将缓冲区设置为 0
        out = (out + 1) % N;
        mutex++;
        empty++;
        printf("\t\t\t\t consume a product with ID: %d, position in buffer: %d\n", nextc, out);
        Sleep(sleepTime);
    }
}

int main () {
    pthread_t threadPool[producerNum+consumerNum];
    int i;
    for(i = 0; i < producerNum; i++) {
        pthread_t temp;
        if (pthread_create(&temp, NULL, producer, NULL) == -1) {
            printf("ERROR, fail to create producer %d\n", i);
            exit(1);
        }
        threadPool[i] = temp;
    }//创建生产者进程放入线程池

    for(i = 0; i < consumerNum; i++) {
        pthread_t temp;
        if (pthread_create(&temp, NULL, consumer, NULL) == -1) {
            printf("ERROR, fail to create consumer %d\n", i);
            exit(1);
        }
        threadPool[producerNum + i] = temp;
    }//创建消费者进程放入线程池

    void * result;
    for (i = 0; i < producerNum+consumerNum; i++) {
        if (pthread_join(threadPool[i], &result) == -1) {
            printf("ERROR, fail to run the thread pool\n");
            exit(1);
        }
    }//运行线程池

    return 0;
}