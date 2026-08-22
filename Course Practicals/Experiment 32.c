-> CODE :

#include <stdio.h>
#include <dirent.h>
int main()
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if(dir == NULL)
    {
        printf("Cannot open directory\n");
        return 1;
    }
    printf("Directory contents:\n");
    while((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);
    closedir(dir);
    return 0;
}

-> OUTPUT :

Directory contents:
.
..
a.out
main.ccp
