

/*
 * Date:2021-11-15 10:13
 * filename:01_双线程数数.c
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

#define MAX 50
int number;

//线程函数
void* funA_num(void* arg) {
	for (int i = 0; i < MAX;++i) {
		int cur = number;
		cur++;
		usleep(10);
		number = cur;
		printf("Thread A, id = %lu, number = %d\n",pthread_self(),number);
	}
	return NULL;
}

void* funB_num(void* arg) {
	for (int i = 0; i < MAX;++i) {
		int cur = number;
		cur++;
		number = cur;
		printf("Thread B, id = %lu, number = %d\n", pthread_self(), number);
		usleep(5);
	}
	return NULL;
}

int main() {
	pthread_t p1, p2;

	//创建俩线程
	
	pthread_create(&p1, NULL, funA_num, NULL);
	pthread_create(&p2, NULL, funB_num, NULL);

	//阻塞资源回收
	pthread_join(p1, NULL);	
	pthread_join(p2, NULL);	

	return 0;
}
