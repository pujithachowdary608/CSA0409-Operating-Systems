1.
a)Multi-user Operating System
b)Process Management,Memory management
c)#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    } 
    else (pid > 0) {
        printf("Parent Process\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    } 
    return 0;
}
