#include <string.h>
#include <stdlib.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    if (sLen == 0 || tLen == 0 || tLen > sLen) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    int need[128] = {0};
    int window[128] = {0};

    int required = 0; 
    for (int i = 0; i < tLen; i++) {
        if (need[(unsigned char)t[i]] == 0) required++;
        need[(unsigned char)t[i]]++;
    }

    int left = 0, formed = 0;
    int bestLen = INT_MAX, bestLeft = 0;

    for (int right = 0; right < sLen; right++) {
        unsigned char c = (unsigned char)s[right];
        window[c]++;

        if (need[c] > 0 && window[c] == need[c]) {
            formed++;
        }

        while (formed == required) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestLeft = left;
            }

            unsigned char lc = (unsigned char)s[left];
            window[lc]--;
            if (need[lc] > 0 && window[lc] < need[lc]) {
                formed--;
            }
            left++;
        }
    }

    if (bestLen == INT_MAX) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    char* result = (char*)malloc(bestLen + 1);
    memcpy(result, s + bestLeft, bestLen);
    result[bestLen] = '\0';
    return result;
}
