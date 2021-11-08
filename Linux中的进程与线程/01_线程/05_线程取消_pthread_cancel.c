

/*
 * Date:2021-11-08 20:58
 * filename:05_线程取消_pthread_cancel.c
 *
 */

/*
 * 线程取消的意思是在某些特定情况下在一个线程中杀死另一个线程
 * 使用这个函数杀死一个线程需要分两步
 *
 * 1、在线程A中调用线程取消函数(pthread_cancel),指定杀死线程B，这时候线程B是死不了的
 * 2、在线程B中进程一次系统调用(从用户区切换到内核区)，否则线程B可以一直运行
 *
 */

/*
 * 主线程调用线程取消函数，只要在子线程中进行了系统调用，当子线程执行到了这个位置就挂掉了
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void* working(void* arg) {
	int j = 0;
	for (int i = 0;i < 9;i++) {
		j++;
	}
	//这个函数会调用系统函数，因此这是个间接的系统调用
	printf("child pthread, phread id :%ld\n",pthread_self());
	for (int i = 0;i < 9;++i) {
		printf("child i : %d\n",i);
	}
	return NULL;
}

int main() {
	//1.create a child pthread
	pthread_t tid;
	pthread_create(&tid, NULL, working, NULL);

	printf("child pthread create successful, pthread id : %ld\n", tid);

	//2.子线程不会执行下边的代码，主线程执行
	printf("main pthread,pthread id : %ld\n",pthread_self());
	for (int i = 0;i < 3;i++) {
		printf("i = %d\n",i);
	}

	//杀死子线程,如果子线程中做系统调用，子线程就结束了
	pthread_cancel(tid);

	//让主线程自己退出即可
	pthread_exit(NULL);

	return 0;
}
