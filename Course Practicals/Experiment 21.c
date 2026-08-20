-> CODE :

#include <stdio.h>
int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, k, pos;
    int fault = 0, hit = 0, found, min;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }
    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++)
    {
        found = 0;
        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                time[j] = i + 1;
                break;
            }
        
        if(found)
        {
            hit++;
        }
        else
        {
            fault++;
            pos = -1;
            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }
            if(pos == -1)
            {
                min = time[0];
                pos = 0;
                for(j = 1; j < f; j++)
                {
                    if(time[j] < min)
                    {
                        min = time[j];
                        pos = j;
                    }
                }
            }
            frame[pos] = pages[i];
            time[pos] = i + 1;
        }
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++)
        {
            if(frame[k] == -1)
                printf("- ");
            else
                printf("%d ", frame[k]);
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
3       3 1 2
4       3 4 2
5       3 4 5

Page Faults = 10
Page Hits = 2
