#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    
    if (k >= n) {
        char* result = (char*)malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    
    char* stack = (char*)malloc(n + 1);
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char digit = num[i];
        while (top >= 0 && k > 0 && stack[top] > digit) {
            top--;
            k--;
        }
        stack[++top] = digit;
    }
    
    top -= k;
    
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }
    
    int len = top - start + 1;
    
    char* result;
    if (len <= 0) {
        result = (char*)malloc(2);
        result[0] = '0';
        result[1] = '\0';
    } else {
        result = (char*)malloc(len + 1);
        memcpy(result, stack + start, len);
        result[len] = '\0';
    }
    
    free(stack);
    return result;
}
