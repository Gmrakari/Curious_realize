

/*
 * Date:2021-11-16 15:07
 * filename:5-顺序打印ABC.c
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2, cond3;
int number = 10;
int g_num;


void* printA(void* arg) {
	while(1) {
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond1, &mutex);
		printf("A pthread_t id : %ld\n", pthread_self());
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void* printB(void* arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond2, &mutex);
		printf("B pthread_t id : %ld\n", pthread_self());
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void* printC(void* arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond3, &mutex);
		printf("C pthread_t id : %ld\n", pthread_self());
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void* run(void* arg) {
	while (1) {
		pthread_mutex_lock(&mutex);
		++g_num;
		pthread_mutex_unlock(&mutex);
		if ((g_num % 3) == 0)
			pthread_cond_signal(&cond3);	
		else if ((g_num % 3) == 1)
			pthread_cond_signal(&cond1);
		else if ((g_num % 3) == 2)
			pthread_cond_signal(&cond2);
		sleep(1);
	}
	return NULL;
}

int main() {
	pthread_mutex_init(&mutex, NULL);
	pthread_t tid1, tid2, tid3, tid4;

	pthread_create(&tid1, NULL, printA, NULL);
	pthread_create(&tid2, NULL, printB, NULL);
	pthread_create(&tid3, NULL, printC, NULL);
	pthread_create(&tid4, NULL, run, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	pthread_mutex_destroy(&mutex);

	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);
	pthread_cond_destroy(&cond3);
	return 0;
}
