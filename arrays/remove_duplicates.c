#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int left = 0;
    for (int right = 1; right < n; right++) {
        if (arr[right] != arr[left]) {
            left++;
            arr[left] = arr[right];
        }
    }
    return left + 1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int newLen = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLen; i++)
        printf("%d ", arr[i]);

    printf("\n");
    printf("New length: %d\n", newLen);
    return 0;
}
