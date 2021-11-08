

/*
 * Date:2021-11-08 20:41
 * filename:04_线程分离_pthread_detach.c
 *
 */

/*
 * 某些情况下，程序汇总的主线程有属于自己的业务处理流程，如果让主线程负责子线程的资源回收，调用pthread_join()
 * 只要子线程不退出主线程就会一直被阻塞，主要线程的任务也就不能被执行了
 *
 * 在线程库函数中提供了线程分离函数pthread_detach(),调用这个函数之后指定的子线程就可以和主线程分离，当子线程退出的时候，
 * 其占用的内核资源就被系统的其他进程接管并回收了。
 * 线程分离之后在主线程中使用pthread_join()就回收不到子线程资源了
 *
 */

/*
#include <pthread.h>

//参数子线程的线程id，主线程就可以和这个子线程分离了
int pthread_detach(pthread_t thread);

//主线程中创建子线程，并调用线程分离函数，实现了主线程和子线程的分离
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void* working(void* arg) {
	printf("child pthread,pthread id:%ld\n",pthread_self());
	for (int i = 0;i < 9;i++) {
		printf("child == i: = %d\n",i);
	}
	return NULL;
}

int main() {
	//1.create child pthread
	pthread_t tid;
	pthread_create(&tid, NULL, working, NULL);

	printf("child pthread create successful, pthread id:%ld\n", tid);

	//2.child pthead do not run the following code,main pthread run
	printf("main pthread, pthread id:%ld\n",pthread_self());
	for (int i = 0;i < 3;++i) {
		printf("i = %d\n", i);	
	}

	//设置子线程和主线程分离
	pthread_detach(tid);

	//让主线程自己退出即可
	pthread_exit(NULL);
	return 0;
}



