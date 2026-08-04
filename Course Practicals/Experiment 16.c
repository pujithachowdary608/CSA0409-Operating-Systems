-> CODE :

#include <stdio.h>
int main()
{
    int blockSize[20], processSize[20], allocation[20];
    int m, n, i, j, choice;
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
    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    for(i = 0; i < n; i++)
        allocation[i] = -1;
    if(choice == 1)
    {
        // First Fit
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(blockSize[j] >= processSize[i])
                {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }
    }
    else if(choice == 2)
    {
        // Best Fit
        for(i = 0; i < n; i++)
        {
            int best = -1;
            for(j = 0; j < m; j++)
            {
                if(blockSize[j] >= processSize[i])
                {
                    if(best == -1 || blockSize[j] < blockSize[best])
                        best = j;
                }
            }
            if(best != -1)
            {
                allocation[i] = best;
                blockSize[best] -= processSize[i];
            }
        }
    }
    else if(choice == 3)
    {
        // Worst Fit
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
    }
    else
    {
        printf("Invalid Choice\n");
        return 0;
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
200
600
700
400
Enter number of processes: 4
Enter sizes of processes:
213 
406
390
170

1. First Fit
2. Best Fit
3. Worst Fit
Enter your choice: 1

Process No.     Process Size    Block No.
1               213             3
2               406             4
3               390             5
4               170             2
