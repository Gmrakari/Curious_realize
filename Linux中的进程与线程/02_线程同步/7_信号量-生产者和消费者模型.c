/*
 * Date:2021-12-09 10:49
 * filename:7_信号量-生产者和消费者模型
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


//生产者信号量
sem_t semp;
//消费者信号量
sem_t semc;

pthread_mutex_t mutex;

//链表的结点类型
struct Node {
	int number;
	struct Node* next;
};

//头节点
struct Node* head = NULL;

//生产者
void* producer(void* arg) {
	while(1) {
		pthread_mutex_lock(&mutex);
		sem_wait(&semp);
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		//init Node
		newNode->number = rand() % 1000;//0-999
		newNode->next = head;
		head = newNode;
		printf("生产者, id:%ld, number:%d\n", pthread_self(), newNode->number);
		pthread_mutex_unlock(&mutex);
		sem_post(&semc);
		//usleep(rand() % 100);//睡眠时间在3秒之内
		sleep(3);
	}
	return NULL;
}

//消费者
void* consumer(void* arg) {
	while (1) {
		sem_wait(&semc);
		pthread_mutex_lock(&mutex);
		struct Node* node = head;//取出头节点
		printf("消费者, id:%ld, number:%d\n", pthread_self(), node->number);
		head = head->next;
		free(node);
		pthread_mutex_unlock(&mutex);
		sem_post(&semp);
		//usleep(rand() % 100);
		sleep(3);
	}
	return NULL;
}

int main() {

	int sem_init(sem_t *sem, int pshared, unsigned int value);
	//第二个参数pshared 0 -> 线程 1 -> 进程
	sem_init(&semp, 0, 5);
	sem_init(&semc, 0, 0);

	pthread_mutex_init(&mutex, NULL);

	pthread_t t1[5], t2[5];

	for (int i = 0;i < 5; ++i) {
		pthread_create(&t1[i], NULL, producer, NULL);
	}

	for (int i = 0;i < 5; ++i) {
		pthread_create(&t2[i], NULL, consumer, NULL);
	}

	for (int i = 0;i < 5; ++i) {
		pthread_join(t1[i], NULL);
		pthread_join(t2[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&semp);
	sem_destroy(&semc);

	return 0;
}
