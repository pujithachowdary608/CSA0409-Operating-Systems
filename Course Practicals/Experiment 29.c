-> CODE :

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;
    char data[] = "Hello UNIX";
    char buffer[20];
    fd = open("file.txt", O_CREAT | O_RDWR, 0644);
    if(fd == -1)
    {
        printf("File cannot be opened\n");
        return 1;
    }
    write(fd, data, sizeof(data));
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, sizeof(data));
    buffer[sizeof(data) - 1] = '\0';
    printf("File Content: %s\n", buffer);
    close(fd);
    return 0;
}

-> OUTPUT :

File Content: Hello UNIX
