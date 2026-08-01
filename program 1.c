1) 
#include <stdio.h>
#include <unistd.h>
int main(){
     printf("current process ID: %d/n",getpid());
     return 0;
}

2)
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    fork();
    printf("Process ID:%d\n",getpid());
    fork();
    printf("Process ID: %d\n",getpid());
    wait(NULL);
    wait(NULL);
    return 0;
}

3)
#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1,rear = -1;
void enqueue(int x){
    if (rear== SIZE -1)
    printf("Queue FULL\n");
   else {
       if (front == -1)
           front = 0;
       queue[++rear] = x;
   }
}
void display() {
    int i;
    for (i= front; i <= rear; i++)
    {
        printf("P%d ",queue[i]);
    }
}
 int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("Ready Queue: ");
    display();
    return 0;
}

4)
#include <stdio.h>
int  main(){
    int process[] = {1,2,3,4};
    int i;
    printf("Execution order:\n");
    for(i=0;i<4;i++)
       printf("Executing Process P%d\n",process[i]);
       return 0;
}

5)
