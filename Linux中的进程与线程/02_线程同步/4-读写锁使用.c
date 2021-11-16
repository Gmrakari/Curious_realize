

/*
 * Date:2021-11-16 10:53
 * filename:4-读写锁使用.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t rwlock;
int number = 0;

//读线程
//多个线程如果处理动作相同，可以使用相同的处理函数
//每个线程中的栈资源是独享
void* th_read(void *arg) {
	while(number < 50) {
		pthread_rwlock_rdlock(&rwlock);
		printf("read number = %d,tid = %ld\n",number, pthread_self());
		pthread_rwlock_unlock(&rwlock);

		//添加sleep目的是要看到多个线程交替工作
		usleep(rand() % 100);
	}
	return NULL;
} 

//写线程
//独占
void* th_write(void *arg) {
	while(number < 50) {
		pthread_rwlock_wrlock(&rwlock);
		int cur = number;
		cur++;
		number = cur;
		printf("write number = %d,tid = %ld\n",number, pthread_self());
		pthread_rwlock_unlock(&rwlock);

		//添加sleep目的是要看到多个线程交替工作
		usleep(rand() % 100);
	}
}

int main() {
	//初始化读写锁
	pthread_rwlock_init(&rwlock, NULL);

	pthread_t wtid[3],rtid[5];

	for (int i = 0;i < 3;++i) {
		pthread_create(&wtid[i], NULL, th_read, NULL);
	}

	for (int i = 0; i < 5; ++i) {
		pthread_create(&rtid[i], NULL, th_write, NULL);
	}

	//释放资源
	for (int i = 0;i < 3;++i) {
		pthread_join(wtid[i], NULL);
	}

	for (int i = 0; i < 5; ++i) {
		pthread_join(rtid[i], NULL);
	}

	//销毁锁
	pthread_rwlock_destroy(&rwlock);
	return 0;

}
