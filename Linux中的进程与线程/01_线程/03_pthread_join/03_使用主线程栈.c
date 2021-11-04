

/*
 * Date:2021-11-05 07:22
 * filename:03_使用主线程栈.c
 *
 */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct Person {
	int id;
	char name[36];
	int age;
};

void* working(void* arg) {
	struct Person* p = (struct Person*)arg;
	printf("child pthread,pthread id:%ld\n",pthread_self());
	for(int i = 0;i < 9;i++) {
		printf("child == i: = %d\n",i);
		if (i == 6) {
			//使用主线程的内存栈
			p->age = 12;
			strcpy(p->name, "tom");
			p->id = 100;

			//该函数的参数将这个地址传递给了主线程的pthread_join()
			pthread_exit(p);
		}
	}
	return NULL;
}

int main() {
	pthread_t tid;
	
	struct Person p;

	//主线程的内存传递给子线程
	pthread_create(&tid, NULL, working, &p);

	printf("child pthread create successfully, pthread id :%ld\n",tid);
	
	//2.子线程不会执行下边的代码，主线程执行
	printf("主线程，id:%ld\n",pthread_self());
	for (int i = 0;i < 3;i++) {
		printf("i = %d\n",i);
	}

	void* ptr = NULL;
	//ptr是一个传出参数，在函数内部让这个指针指向一块有效内存
	//这个内存地址就是pthread_exit()参数指向的内存
	//
	pthread_join(tid, &ptr);

	//print
	printf("name:%s, age:%d, id:%d\n",p.name, p.age, p.id);
	printf("child pthread source callback successfully\n");
	return 0;
}

/*
 * 在上面的程序中，调用pthread_create()创建子线程，并将主线程中的栈空间变量p的地址传递到了子线程中，
 * 在子线程中将要传递出的数据写入到了这块内存中。也就是说在程序中main()函数中，通过了指针变量ptr或者
 * 通过结构体变量p都可以读出子线程传出的数据
 */
