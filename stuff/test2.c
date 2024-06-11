#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread function that prints a message and returns an integer value
void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d: Hello from the thread!\n", thread_num);
    
    // Return the thread number as the thread's return value
    int* ret_val = malloc(sizeof(int));
    *ret_val = thread_num;
    pthread_exit(ret_val);
}

int main() {
    pthread_t thread1, thread2;
    int thread_arg1 = 1, thread_arg2 = 2;
    int* thread_ret1;
    int* thread_ret2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, thread_function, &thread_arg1) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, thread_function, &thread_arg2) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    // Wait for the first thread to finish
    if (pthread_join(thread1, (void**)&thread_ret1) != 0) {
        fprintf(stderr, "Error joining thread 1\n");
        return 1;
    }

    // Wait for the second thread to finish
    if (pthread_join(thread2, (void**)&thread_ret2) != 0) {
        fprintf(stderr, "Error joining thread 2\n");
        return 1;
    }

    // Print the return values from the threads
    printf("Thread 1 returned %d\n", *thread_ret1);
    printf("Thread 2 returned %d\n", *thread_ret2);

    // Free the allocated memory
    free(thread_ret1);
    free(thread_ret2);

    return 0;
}
