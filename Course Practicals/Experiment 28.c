-> CODE :

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[20], n, head, disk, dir;
    int i, j, temp, total = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk);
    printf("Enter direction (1=Right, 0=Left): ");
    scanf("%d", &dir);
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    printf("\nSeek Sequence: %d", head);
    if(dir == 1)
    {
        for(i = 0; i < n; i++)
        {
            if(a[i] >= head)
            {
                total += abs(head - a[i]);
                head = a[i];
                printf(" -> %d", head);
            }
        }
        total += abs(head - (disk - 1));
        head = disk - 1;
        printf(" -> %d", head);
        total += disk - 1;
        head = 0;
        printf(" -> %d", head);
        for(i = 0; i < n; i++)
        {
            if(a[i] < head)
                continue;
            if(a[i] < (disk - 1))
            {
                total += abs(head - a[i]);
                head = a[i];
                printf(" -> %d", head);
            }
        }
    }
    else
    {
        for(i = n - 1; i >= 0; i--)
        {
            if(a[i] <= head)
            {
                total += abs(head - a[i]);
                head = a[i];
                printf(" -> %d", head);
            }
        }
        total += head;
        head = 0;
        printf(" -> %d", head);
        total += disk - 1;
        head = disk - 1;
        printf(" -> %d", head);
        for(i = n - 1; i >= 0; i--)
        {
            if(a[i] > 0 && a[i] > head)
                continue;
            if(a[i] > 0 && a[i] < head)
            {
                total += abs(head - a[i]);
                head = a[i];
                printf(" -> %d", head);
            }
        }
    }
    printf("\n\nTotal Head Movement = %d cylinders\n", total);
    return 0;
}

-> OUTPUT :

Enter number of requests: 8
Enter request queue:
98 183 37 122 14 124 65 67
Enter initial head position: 53
Enter disk size: 200
Enter direction (1=Right, 0=Left): 1

Seek Sequence: 53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 0 -> 14 -> 37

Total Head Movement = 331 cylinders
