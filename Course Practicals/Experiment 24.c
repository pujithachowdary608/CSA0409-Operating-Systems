-> CODE :

#include <stdio.h>
int main()
{
    int index[20], n, i, block, found = 0;
    char file[20];
    printf("Enter file name: ");
    scanf("%s", file);
    printf("Enter index block number: ");
    scanf("%d", &block);
    printf("Enter number of file blocks: ");
    scanf("%d", &n);
    printf("Enter file block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &index[i]);
    printf("\nFile Name       : %s", file);
    printf("\nIndex Block     : %d", block);
    printf("\nFile Blocks     : ");
    for(i = 0; i < n; i++)
        printf("%d ", index[i]);
    printf("\n\nEnter block to search: ");
    scanf("%d", &block);
    for(i = 0; i < n; i++)
    {
        if(index[i] == block)
        {
            printf("Block %d is present at index %d\n", block, i + 1);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Block %d is not present\n", block);
    return 0;
}

-> OUTPUT :

Enter file name: A
Enter index block number: 5
Enter number of file blocks: 4
Enter file block numbers:
10 15 20 25

Enter block to search: 20
File Name       : A
Index Block     : 5
File Blocks     : 10 15 20 25

Enter block to search: 20
Block 20 is present at index 3
