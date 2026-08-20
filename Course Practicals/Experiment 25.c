-> CODE :

#include <stdio.h>
int main()
{
    int block[20], next[20];
    int n, i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);
    for(i = 0; i < n - 1; i++)
        next[i] = block[i + 1];
    next[n - 1] = -1;
    printf("\nFirst Block = %d", block[0]);
    printf("\nLast Block  = %d", block[n - 1]);
    printf("\n\nLinked Allocation:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d -> ", block[i]);
    }
    printf("NULL\n");
    printf("\nBlock\tNext Block\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\n", block[i], next[i]);
    return 0;
}

-> OUTPUT :

Enter number of blocks: 5
Enter block numbers:
10 25 7 18 30
First Block = 10
Last Block  = 30

Linked Allocation:
10 -> 25 -> 7 -> 18 -> 30 -> NULL

Block   Next Block
10      25
25      7
7       18
18      30
30      -1
