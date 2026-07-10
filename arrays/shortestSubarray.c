#include <stdlib.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    int n = numsSize;
    
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    int *dq = (int *)malloc((n + 1) * sizeof(int));
    int head = 0, tail = 0;
    
    int best = n + 1;
    
    for (int i = 0; i <= n; i++) {
        while (head < tail && prefix[i] - prefix[dq[head]] >= k) {
            if (i - dq[head] < best) {
                best = i - dq[head];
            }
            head++;
        }
        
        while (head < tail && prefix[dq[tail - 1]] >= prefix[i]) {
            tail--;
        }
        
        dq[tail++] = i;
    }
    
    free(prefix);
    free(dq);
    
    return (best <= n) ? best : -1;
}
