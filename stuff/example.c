#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 1

int shared_resource = 0;
pthread_mutex_t mutex;

void* thread_function(void* arg)
{
    int i;
    for (i = 0; i < NUM_ITERATIONS; i++)
	{
        pthread_mutex_lock(&mutex); // Acquire lock
        shared_resource++; // Access shared resource
        pthread_mutex_unlock(&mutex); // Release lock
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    int i;
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, thread_function, NULL);

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&mutex);

    printf("Value of shared resource: %d\n", shared_resource);

    return 0;
}
