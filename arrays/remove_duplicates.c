#include <stdio.h>

int removeDuplicates(int a[], int n) {
    if (n == 0) return 0;

    int left = 0;
    int res = 1;
    int right = 1;

    while (right < n) {
        if (a[right] == a[right - 1]) {
            right++;
            continue;
        }
        a[left + 1] = a[right];
        left++;
        res++;
        right++;
    }

    return res;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int newLen = removeDuplicates(a, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLen; i++)
        printf("%d ", a[i]);

    printf("\n");
    printf("New length: %d\n", newLen);
    return 0;
}
