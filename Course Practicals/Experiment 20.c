-> CODE :

#include <stdio.h>
int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k = 0;
    int fault = 0, hit = 0, found;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frame[i] = -1;
    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++)
    {
        found = 0;
        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if(found)
        {
            hit++;
        }
        else
        {
            frame[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("\nPage Faults = %d\n", fault);
    printf("Page Hits = %d\n", hit);
    return 0;
}

-> OUTPUT :

Enter number of pages: 12
Enter page reference string:
1 2 3 4 1 2 5 1 2 3 4 5
Enter number of frames: 3
  Page    Frames
1       1 - -
2       1 2 -
3       1 2 3
4       4 2 3
1       4 1 3
2       4 1 2
5       5 1 2
1       5 1 2
2       5 1 2
3       5 3 2
4       5 3 4
5       5 3 4

Page Faults = 9
Page Hits = 3
