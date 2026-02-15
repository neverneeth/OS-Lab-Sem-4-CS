#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t resource;
sem_t readTry;
sem_t rmutex;

int readCount=0;
int sharedData=0;

void* reader(void *arg)
{
	int id = *((int*)arg);

	for(int i=0;i<4;i++)
	{
		sem_wait(&readTry);
		sem_wait(&rmutex);
		readCount++;

		if(readCount==1)
			sem_wait(&resource);

		sem_post(&rmutex);
		sem_post(&readTry);

		//Critical section 
		printf("Reader %d is reading %d \n",id,sharedData);
		sleep(1);

		sem_wait(&rmutex);
		readCount--;

		if(readCount==0)
			sem_post(&resource);

		sem_post(&rmutex);

		sleep(1);
	}
}

void* writer(void* arg)
{
	int id = *((int*)arg);

	for(int i=0;i<4;i++)
	{
		sem_wait(&readTry);
		sem_wait(&resource);

		sharedData++;
		printf("Writer %d is writing %d \n",id,sharedData);
		sleep(2);

		sem_post(&resource);
		sem_post(&readTry);

		sleep(2);
	}
}

int main()
{
	pthread_t r[3],w[2];

	int r_id[3] = {1,2,3};
	int w_id[2]={1,2};

	sem_init(&resource,0,1);
	sem_init(&readTry,0,1);
	sem_init(&rmutex,0,1);

	for(int i=0;i<3;i++)
		pthread_create(&r[i],NULL,reader,&r_id[i]);

	for(int i=0;i<2;i++)
		pthread_create(&w[i],NULL,writer,&w_id[i]);



	for (int i = 0; i < 3; i++)
        pthread_join(r[i], NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    // Destroy semaphores
    sem_destroy(&resource);
    sem_destroy(&readTry);
    sem_destroy(&rmutex);

    return 0;
}