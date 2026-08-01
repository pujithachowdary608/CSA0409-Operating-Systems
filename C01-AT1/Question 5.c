a)File management is responsible for organizing and controlling files stored in secondary memory
Stores and retrieves files efficiently
Manages file creation, deletion, and organization
Protects data from unauthorized access
(b) open():Opens an existing file (or creates one with appropriate flags)
Returns a file descriptor used for file operations
close():Closes the opened file
Releases the file descriptor and saves system resources
c) #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd, n;
    char buffer[100];
    fd = open("student.txt", O_RDONLY);
    n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);
    close(fd);
    return 0;
}
