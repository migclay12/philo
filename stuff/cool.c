#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
// 31: Red
// 32: Green
// 33: Yellow
// 34: Blue
// 35: Magenta
// 36: Cyan
void *philosopher(void *arg)
{
    int id = *((int *)arg);
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (1)
	{
        printf("\033[0;32mPhilosopher %d is thinking.\n\033[0m", id);
        usleep(rand() % 1000000);  // Thinking

        printf("\033[0;33mPhilosopher %d is hungry.\n\033[0m", id);

        // Acquire the forks
        pthread_mutex_lock(&forks[left_fork]);
        printf("\033[0;34mPhilosopher %d picked up fork %d (left).\n\033[0m", id, left_fork);
        pthread_mutex_lock(&forks[right_fork]);
        printf("\033[0;34mPhilosopher %d picked up fork %d (right).\n\033[0m", id, right_fork);

        // Eating
        printf("\033[0;31mPhilosopher %d is eating.\n\033[0m", id);
        usleep(rand() % 1000000);  // Eating

        // Release the forks
        pthread_mutex_unlock(&forks[right_fork]);
        printf("\033[0;35mPhilosopher %d put down fork %d (right).\n\033[0", id, right_fork);
        pthread_mutex_unlock(&forks[left_fork]);
        printf("\033[0;35mPhilosopher %d put down fork %d (left).\n\033[0", id, left_fork);
    }

    return NULL;
}

int main()
{
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    // Initialize mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
        pthread_mutex_init(&forks[i], NULL);

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
	{
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
	}

    // Wait for philosopher threads to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
        pthread_join(philosophers[i], NULL);

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
        pthread_mutex_destroy(&forks[i]);

    return 0;
}
