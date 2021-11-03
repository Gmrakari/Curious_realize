

/*
 * Date:2021-11-03 23:03
 * filename:pthread_join.c
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * 阻塞函数，子线程在运行这个函数就阻塞
 * 子线程退出，函数接触阻塞，回收对应的子线程资源，类似与wait()
 *
 */

//int pthread_join(pthread_t thread, void **retval);

/*
 * 参数:
 * thread:要被回收的子线程的线程id
 * retval:二级指针，指向一级指针的地址，是一个传出参数，这个地址中存储了pthread_exit()传递出的数据
 * 如果不需要这个参数，可以指定为NULL
 * 返回值：
 * 线程回收成功返回0,回收失败返回错误号
 *
 */

struct Person {
	int id;
	char name[36];
	int age;
};

//child pthread
void* working(void *arg) {
	printf("i am child pthread, pthread id:%ld\n",pthread_self());
	for (int i = 0;i < 9;++i) {
		printf("child == i: = %d\n",i);
		if (i == 6) {
			struct Person p;
			p.age = 12;
			strcpy(p.name, "gmrakari");
			p.id = 100;

			//该函数的参数将这个地址传递给了主线程的pthread_join()
			pthread_exit(&p);
		}
	}
	return NULL;
}

int main() {
	//1.create child pthread
	pthread_t tid;
	pthread_create(&tid, NULL, working, NULL);

	printf("child pthread create successful,pthread id:%ld\n",tid);

	//2.child pthread did not run the following code,main pthread run
	printf("main pthread, pthread id:%ld\n",pthread_self());
	for (int i = 0;i < 3;++i) {
		printf("i = %d\n",i);
	}

	//3.blocking child pthread exit
	void *ptr = NULL;

	pthread_join(tid, &ptr);

	struct Person* pp = (struct Person*)ptr;

	printf("child pthread return data:name :%s, age:%d,id:%d\n",pp->name, pp->age, pp->id);
	printf("child pthread data and source has been callback successfully\n");
	return 0;
}

