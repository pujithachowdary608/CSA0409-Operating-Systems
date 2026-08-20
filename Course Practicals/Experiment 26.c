-> CODE :

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, head, total = 0;
    int request[20];
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("\nDisk Head Movement:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d -> %d", head, request[i]);
        total += abs(head - request[i]);
        head = request[i];
        if(i < n - 1)
            printf("\n");
    }
    printf("\n\nTotal Head Movement = %d cylinders\n", total);
    return 0;
}

-> OUTPUT :

Enter number of requests: 8
Enter request queue:
98 183 37 122 14 124 65 67
Enter initial head position: 53
Disk Head Movement:
53 -> 98
98 -> 183
183 -> 37
37 -> 122
122 -> 14
14 -> 124
124 -> 65
65 -> 67
  
Total Head Movement = 640 cylinders
