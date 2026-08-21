-> CODE :

#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    char word[50], line[200];
    fp = fopen("sample.txt", "w");
    fprintf(fp, "Operating System is important.\n");
    fprintf(fp, "Linux is an operating system.\n");
    fprintf(fp, "UNIX is a powerful operating system.\n");
    fprintf(fp, "C programming is useful.\n");
    fclose(fp);
    printf("Enter word to search: ");
    scanf("%s", word);
    fp = fopen("sample.txt", "r");
    printf("\nMatching lines:\n");
    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, word) != NULL)
            printf("%s", line);
    }
    fclose(fp);
    return 0;
}

-> OUTPUT :

Enter word to search: operating
Matching lines:
Operating System is important.
Linux is an operating system.
UNIX is a powerful operating system.
  
