

/*
 * Date:2021-11-02 10:51
 * filename:pthread_exit.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//child pthread
void* working(void* arg) {
	sleep(1);
	printf("child pthread id : %ld\n", pthread_self());
	for (int i = 0; i < 5;i++) {
		//printf("i == %d\n",i);
		if (i == 3) {
			pthread_exit(NULL);
		}
		printf("child i = %d\n",i);
	}
  return NULL;
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, working, NULL);
	for (int i = 0;i < 5;i++) {
		printf("主线程:i = %d\n",i);
	}
	printf("主线程: %ld\n",pthread_self());
	// 主线程调用退出函数退出, 地址空间不会被释放
	pthread_exit(NULL);
	return 0;
}
