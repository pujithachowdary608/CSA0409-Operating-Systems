1)
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Process creation failed!\n");
    }
    else if (pid == 0) {
        printf("\n--- Child Process ---\n");
        printf("Child Process ID (PID) : %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
    }
    else {
        printf("\n--- Parent Process ---\n");
        printf("Parent Process ID (PID): %d\n", getpid());
        printf("Parent's Parent ID (PPID): %d\n", getppid());
        printf("Child Process ID: %d\n", pid);
    }
    return 0;
}
Output:
--- Parent Process ---
Parent Process ID (PID): 12554
Parent's Parent ID (PPID): 12543
Child Process ID: 12555

--- Child Process ---
Child Process ID (PID) : 12555
Parent Process ID (PPID): 12554

2) 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int src, dest;
    char buffer[100];
    int bytesRead;
    src = open("source.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (src < 0) {
        printf("Error creating source file.\n");
        return 1;
    }
    write(src, "Operating Systems Lab\nFile Copy using System Calls\n", 52);
    close(src);
    src = open("source.txt", O_RDONLY);
    if (src < 0) {
        printf("Error opening source file.\n");
        return 1;
    }
    dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        printf("Error creating destination file.\n");
        close(src);
        return 1;
    }
    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }
    close(src);
    close(dest);
    printf("File copied successfully.\n");
    dest = open("destination.txt", O_RDONLY);
    printf("\nContents of destination.txt:\n");
    while ((bytesRead = read(dest, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }
    close(dest);
    return 0;
}
Output:
Contents of destination.txt:
Operating Systems Lab
File Copy using System Calls

3)
#include <stdio.h>
int main() {
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time of Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
    return 0;
}
Output:
Enter the number of processes: 4
Enter Burst Time of Process P1: 5
Enter Burst Time of Process P2: 3
Enter Burst Time of Process P3: 8
Enter Burst Time of Process P4: 6

Process Burst Time      Waiting Time    Turnaround Time
P1      5               0               5
P2      3               5               8
P3      8               8               16
P4      6               16              22

Average Waiting Time = 7.25
Average Turnaround Time = 12.75

4)
#include <stdio.h>
int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20], temp;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time of Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
    return 0;
}
Output:
Enter the number of processes: 4
Enter Burst Time of Process P1: 6
Enter Burst Time of Process P2: 8
Enter Burst Time of Process P3: 7
Enter Burst Time of Process P4: 3
Process Burst Time      Waiting Time    Turnaround Time
P4      3               0               3
P1      6               3               9
P3      7               9               16
P2      8               16              24
Average Waiting Time = 7.00
Average Turnaround Time = 13.00

5)
#include <stdio.h>
int main() {
    int n, i, j;
    int bt[10], p[10], wt[10], tat[10], temp;
    float avgwt = 0, avgtat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        printf("P%d BT Priority: ", i + 1);
        scanf("%d%d", &bt[i], &p[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i] > p[j]) {
                temp = p[i]; p[i] = p[j]; p[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }
    printf("\nPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);
    return 0;
}
Output:
Enter number of processes: 5
Enter Burst Time and Priority:
P1 BT Priority: 6
7
P2 BT Priority: 10
6
P3 BT Priority: 6
8
P4 BT Priority: 
9
8
P5 BT Priority: 9
6
Priority        BT      WT      TAT
6               10      0       10
6               9       10      19
7               6       19      25
8               9       25      34
8               6       34      40

Average Waiting Time = 17.60
Average Turnaround Time = 25.60

6)
#include <stdio.h>
struct Process {
    int pid, bt, pr;
};
int main() {
    int n, i, j;
    struct Process p[10], temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d%d", &p[i].bt, &p[i].pr);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].pr > p[j].pr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nExecution Order:\n");
    for(i = 0; i < n; i++)
        printf("P%d ", p[i].pid);
    return 0;
}
Output:
Enter number of processes: 4
Enter Burst Time and Priority:
5 2
3 1
6 4
2 3
Execution Order:
P2 P1 P4 P3 

7)
#include <stdio.h>
int main() {
    int n, i, j, temp;
    int bt[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    printf("\nExecution Order:\n");
    for(i = 0; i < n; i++)
        printf("%d ", bt[i]);
    return 0;
}
Output:
Enter number of processes: 4
Enter Burst Time:
6
2
8
4
Execution Order:
2 4 6 8 

8)
#include <stdio.h>
int main() {
    int bt[10], rem[10], n, tq;
    int i, time = 0, done;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    printf("\nExecution Order:\n");
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                }
                printf("P%d ", i + 1);
            }
        }
    } while(!done);
    return 0;
}
Output:
Enter number of processes: 3
Enter Burst Time:
5
4
2
Enter Time Quantum: 2
Execution Order:
P1 P2 P3 P1 P2 P1 

9)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    key_t key = 1234;
    int shmid;
    char *str;
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    str = (char *)shmat(shmid, NULL, 0);
    printf("Writing to shared memory...\n");
    strcpy(str, "Hello from Shared Memory!");
    printf("Data in shared memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
Output:
Writing to shared memory...
Data in shared memory: Hello from Shared Memory!

10)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct message {
    long msg_type;
    char msg_text[100];
};
int main()
{
    key_t key = 1234;
    int msgid;
    struct message msg;
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Hello Message Queue");
    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
    printf("Received Message: %s\n", msg.msg_text);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
Output:
Received Message: Hello Message Queue

11)
#include <stdio.h>
#include <pthread.h>
void *display(void *arg)
{
    printf("Thread is executing.\n");
    return NULL;
}
int main()
{
    pthread_t t1;
    pthread_create(&t1, NULL, display, NULL);
    pthread_join(t1, NULL);
    printf("Thread execution completed.\n");
    return 0;
}
Output:
Thread is executing.
Thread execution completed.
