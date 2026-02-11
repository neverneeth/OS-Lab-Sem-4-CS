#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Details{
	int rc, wc;
	sem_t mutex, w_mutex, rw_mutex, r_mutex;
} details;

void *writer(void *args){
	details *d = (details *)args;

	//Entry section
	sem_wait(&(d->w_mutex));
	d->wc++;
	if(d->wc == 1){
		sem_wait(&(d->r_mutex));
	}
	sem_post(&(d->w_mutex));

	//critical section
	sem_wait(&(d->rw_mutex));
	printf("\nWriter %d is writing...\n", d->wc);
	sleep(1);
	sem_post(&(d->rw_mutex));

	//exit section
	sem_wait(&(d->w_mutex));
	d->wc--;
	if(d->wc == 0){
		sem_post(&(d->r_mutex));
	}
	sem_post(&(d->w_mutex));


	return d;
}

