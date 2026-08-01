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
#include <stdio.h>
int main() {
    FILE *fp;
    char str[100];
    fp= fopen("sample.txt", "w");
    fprintf(fp,"Hello operating system");
    fclose(fp);
    fp=fopen("sample.txt","r");
    fgets(str,100,fp);
    printf("File Content: %s",str);
    fclose(fp);
    return 0;
}

6)
#include<stdio.h>
int main(){
    int pages[] = {1,2,3,1,4,5};
    int frame[3] = {-1,-1,-1};
    int i,j,k=0,flag;
    for(i=0;i<6;i++){
        flag=0;
        for(j=0;j<3;j++)
           if(frame[j]==pages[i])
              flag=1;
        if(flag==0){
            frame[k]=pages[i];
            k=(k+1)%3;
        }
        printf("Frames: ");
        for(j=0;j<3;j++)
           printf("%d", frame[j]);
        printf("\n");
}
  return 0;
}
