/*
 * Date:2021-12-08 19:00
 * filename:6_条件变量-生产者和消费者模型.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_cond_t cond;
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
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		//init Node
		newNode->number = rand() % 1000;//0-999
		newNode->next = head;
		head = newNode;
		printf("生产者, id:%ld, number:%d\n", pthread_self(), newNode->number);
		pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&cond);
		//usleep(rand() % 100);//睡眠时间在3秒之内
		sleep(3);
	}
	return NULL;
}

//消费者
void* consumer(void* arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		while (head == NULL) {
			//阻塞消费者线程
			pthread_cond_wait(&cond, &mutex);
		}
		struct Node* node = head;//取出头节点
		printf("消费者, id:%ld, number:%d\n", pthread_self(), node->number);
		head = head->next;
		free(node);
		pthread_mutex_unlock(&mutex);
		//usleep(rand() % 100);
		sleep(3);
		printf("\n");
	}
	return NULL;
}

int main() {

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

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
	pthread_cond_destroy(&cond);
	return 0;
}
