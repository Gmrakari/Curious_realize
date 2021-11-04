

/*
 * Date:2021-11-04 23:26
 * filename:02_使用全局变量.c
 *
 */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * 位于同一虚拟地址空间中的线程，虽然不能共享栈区数据，但是可以共享全局数据区和堆区数据，
 * 因此在子线程退出的时候可以将传出数据存储到全局变量、静态变量或者堆区内存中。
 */

struct Person {
	int id;
	char name[36];
	int age;
};

struct Person p;	//定义全局变量

void* working(void* arg) {
	printf("child pthread:%ld\n",pthread_self());
	for (int i = 0;i < 9; ++i) {
		printf("child == i:=%d\n", i);
		if (i == 6) {
			p.age = 12;
			strcpy(p.name, "tom");
			p.id = 100;
			pthread_exit(&p);
		}
	}
	return NULL;
}

int main() {
	pthread_t tid;

	pthread_create(&tid, NULL, working, NULL);

	printf("child pthread create successfully, pthread id:%ld\n",tid);
	printf("main pthread, pthread id :%ld\n", pthread_self());
	for (int i = 0;i < 3;i++) {
		printf("i = %d\n",i);
	}

	void* ptr = NULL;
	pthread_join(tid, &ptr);
	struct Person* pp = (struct Person*)ptr;
	printf("name:%s, age:%d,id:%d\n",pp->name, pp->age, pp->id);
	printf("pthread source callback succeefully\n");
	return 0;
}
