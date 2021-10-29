

/*
 * Date:2021-10-29 20:49
 * filename:pthread_create.c
 *
 */

//pthread_create.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

//子线程的处理代码
void* working(void* arg) {
	printf("我是子线程，线程id:%ld\n", pthread_self());
	for(int i = 0; i < 9;i++) {
		printf("child == i: = %d\n", i);
	}
	return NULL;
}

int main() {
	//1.创建一个子进程
	pthread_t tid;
	pthread_create(&tid, NULL, working, NULL);
	printf("子线程创建成功,线程id:%ld\n",tid);

	//2.子线程不会执行下边的代码，主线程执行，除非然主线程执行完之后加sleep
	printf("我是主线程，线程id:%ld\n",pthread_self());
	for (int i = 0;i < 3; ++i) {
		printf("i = %d\n", i);
	}

	sleep(2);
	return 0;
}
