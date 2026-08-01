a)Create/Open a file-open()
 Writing in a file-write()                      
 Reading a file-read()                       
 Closing a file-close()      
b)open()
Opens an existing file or creates a new file (using O_CREAT)
write()
Writes data from memory to the specified file
Returns the number of bytes successfully written
c)#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int file;
    char name[] = "Puji";
    file = open("student.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(file, name, sizeof(name) - 1);
    close(file);
    return 0;
}
