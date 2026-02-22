#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 3

#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

sem_t mutex; // Mutual exclusion
sem_t S[N];  // One semaphore per philosopher

int LEFT(int i) { return (i + N - 1) % N; }
int RIGHT(int i) { return (i + 1) % N; }

void test(int i)
{
    if (state[i] == HUNGRY &&
        state[LEFT(i)] != EATING &&
        state[RIGHT(i)] != EATING)
    {

        state[i] = EATING;
        sem_post(&S[i]);
    }
}

void take_fork(int i)
{

    sem_wait(&mutex);

    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i);

    test(i);

    sem_post(&mutex);

    sem_wait(&S[i]);
}

void put_fork(int i)
{

    sem_wait(&mutex);

    state[i] = THINKING;
    printf("Philosopher %d STOPPED EATING\n", i);

    test(LEFT(i));
    test(RIGHT(i));

    sem_post(&mutex);
}

void *philosopher(void *num)
{

    int i = *(int *)num;

    // Replace while with for loop for better output
    while (1)
    {

        printf("Philosopher %d is THINKING\n", i);
        sleep(1);

        take_fork(i);

        printf("Philosopher %d is EATING\n", i);
        sleep(2);

        put_fork(i);
    }

    printf("Philosopher %d FINISHED EATING\n", i);

    return NULL;
}

int main()
{

    pthread_t thread_id[N];
    int phil[N];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    for (int i = 0; i < N; i++)
    {
        phil[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);

    return 0;
}
