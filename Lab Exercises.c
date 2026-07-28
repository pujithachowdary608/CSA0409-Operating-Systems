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
