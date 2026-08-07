-> CODE :

#include <stdio.h>
int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    for(i = 0; i < n; i++)
        allocation[i] = -1;
    for(i = 0; i < n; i++)
    {
        int worst = -1;
        for(j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
            }
        }
        if(worst != -1)
        {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

-> OUTPUT :

Enter number of memory blocks: 5
Enter sizes of memory blocks:
100
500
200
300
600
Enter number of processes: 4
Enter sizes of processes:
212
417
112
426

Process No.    Process Size    Block No.
1              212             5
2              417             2
3              112             5
4              426             Not Allocated
