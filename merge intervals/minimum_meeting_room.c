#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int start[], int end[], int n) {
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (start[i] < end[j]) {
            rooms++;
            i++;
            if (rooms > maxRooms)
                maxRooms = rooms;
        } else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter end times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &end[i]);

    printf("%d\n", minMeetingRooms(start, end, n));

    return 0;
}
