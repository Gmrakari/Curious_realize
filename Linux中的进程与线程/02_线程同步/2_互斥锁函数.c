

/*
 * Date:2021-11-15 10:32
 * filename:2_互斥锁函数.c
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

//创建一把互斥锁
//全局变量，多个线程共享
pthread_mutex_t mutex;


//线程函数
void* funA_num(void* arg) {
	for (int i = 0; i < MAX;++i) {
		//如果线程A加锁成功，不阻塞
		//如果B加锁成功，线程A阻塞
		pthread_mutex_lock(&mutex);
		int cur = number;
		cur++;
		usleep(10);
		number = cur;
		pthread_mutex_unlock(&mutex);
		printf("Thread A, id = %lu, number = %d\n",pthread_self(),number);
	}
	return NULL;
}

void* funB_num(void* arg) {
	for (int i = 0; i < MAX;++i) {
		//a加锁成功，b线程访问这把锁的时候是锁定的
		//线程B先阻塞，a线程解锁之后阻塞解除
		//线程B加锁成功了
		pthread_mutex_lock(&mutex);
		int cur = number;
		cur++;
		number = cur;
		pthread_mutex_unlock(&mutex);
		printf("Thread B, id = %lu, number = %d\n", pthread_self(), number);
		usleep(5);
	}
	return NULL;
}

int main() {
	pthread_t p1, p2;

	//初始化互斥锁
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&p1, NULL, funA_num, NULL);
	pthread_create(&p2, NULL, funB_num, NULL);

	//阻塞 资源回收
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	//销毁互斥锁
	//线程销毁之后，再去释放互斥锁
	pthread_mutex_destroy(&mutex);
	return 0;
}
