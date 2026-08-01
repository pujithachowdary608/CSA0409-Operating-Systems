a)open() – Open the source and destination files
-read() – Read data from the source file
write() – Write data to the destination file
close() – Close both files after the copy operation
b) Purpose of any two system calls
read()
c) #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int first, second, n;
    char buffer[100];
    first = open("source.txt", O_RDONLY);
    second = open("destination.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    while ((n = read(first, buffer, sizeof(buffer))) > 0) {
        write(second, buffer, n);
    }
    close(first);
    close(second);
    return 0;
}
