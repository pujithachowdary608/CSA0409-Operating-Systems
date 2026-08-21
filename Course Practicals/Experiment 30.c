-> CODE :

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main()
{
    int fd;
    struct stat st;
    DIR *dir;
    struct dirent *entry;
    fd = open("file.txt", O_CREAT | O_RDWR, 0644);
    if(fd == -1)
    {
        printf("File cannot be opened\n");
        return 1;
    }
    printf("File Descriptor: %d\n", fcntl(fd, F_GETFD));
    lseek(fd, 0, SEEK_END);
    printf("File pointer moved to end\n");
    stat("file.txt", &st);
    printf("File Size: %ld bytes\n", st.st_size);
    dir = opendir(".");
    if(dir == NULL)
    {
        printf("Directory cannot be opened\n");
        close(fd);
        return 1;
    }
    printf("\nDirectory Contents:\n");
    while((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);
    closedir(dir);
    close(fd);
    return 0;
}

-> OUTPUT :

File Descriptor: 0
File pointer moved to end
File Size: 0 bytes

Directory Contents:
.
..
file.txt
a.out
main.cpp
