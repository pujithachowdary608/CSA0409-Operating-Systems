a)fork():Creates a new child process
Returns 0 in the child process and the child's PID in the parent process
-exec():Replaces the current process with a new program
If successful, the new program starts executing and the old program is replaced
(b)-wait():makes the parent process wait until the child process finishes execution
(c) #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
    } else (pid > 0);{
        wait(NULL);
        printf("Child process completed.\n");
    } 
    return 0;
}
