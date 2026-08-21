-> CODE :

#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("file.txt", "w");
    if(fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }
    fprintf(fp, "Hello, this is a file management program.");
    fclose(fp);
    printf("File created successfully.\n");
    fp = fopen("file.txt", "r");
    printf("File content: ");
    while((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    rename("file.txt", "newfile.txt");
    printf("\nFile renamed successfully.\n");
    remove("newfile.txt");
    printf("File deleted successfully.\n");
    return 0;
}

-> OUTPUT :

File created successfully.
File content: Hello, this is a file management program.
File renamed successfully.
File deleted successfully.
