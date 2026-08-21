-> CODE :

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;
int shared = 0;
void *process(void *arg)
{
    int i;
    sem_wait(&mutex);
    printf("Process entered critical section\n");
    for(i = 0; i < 5; i++)
        shared++;
    printf("Process leaving critical section\n");
    sem_post(&mutex);
    return NULL;
}
int main()
{
    pthread_t p1, p2;
    sem_init(&mutex, 0, 1);
    pthread_create(&p1, NULL, process, NULL);
    pthread_create(&p2, NULL, process, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("\nFinal shared value = %d\n", shared);
    sem_destroy(&mutex);
    return 0;
}

-> OUTPUT :

Process entered critical section
Process leaving critical section
Process entered critical section
Process leaving critical section

Final shared value = 10
