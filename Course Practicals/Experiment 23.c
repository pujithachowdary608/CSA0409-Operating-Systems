-> CODE :

#include <stdio.h>
struct File
{
    char name[20];
    int start;
    int length;
};
int main()
{
    struct File f[10];
    int n, i, r, block;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter file name: ");
        scanf("%s", f[i].name);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        printf("Enter number of blocks: ");
        scanf("%d", &f[i].length);
    }
    printf("\nFile\tStart\tLength\n");
    for(i = 0; i < n; i++)
        printf("%s\t%d\t%d\n",
               f[i].name, f[i].start, f[i].length);
    printf("\nEnter file number to access (1-%d): ", n);
    scanf("%d", &i);
    printf("Enter record/block number to access: ");
    scanf("%d", &r);
    if(r >= 1 && r <= f[i - 1].length)
    {
        block = f[i - 1].start + r - 1;
        printf("File: %s\n", f[i - 1].name);
        printf("Record %d is stored in block %d\n", r, block);
    }
    else
    {
        printf("Invalid record number\n");
    }
    return 0;
}

-> OUTPUT :

Enter number of files: 2
  
Enter file name: A
Enter starting block: 10
Enter number of blocks: 5

Enter file name: B
Enter starting block: 20
Enter number of blocks: 4

  File     Start    Length
A        10       5
B        20       4
  
Enter file number to access (1-2): 1
Enter record/block number to access: 3
File: A
Record 3 is stored in block 12
