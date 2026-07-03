#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    if (n > m) return false;

    int need[26] = {0};
    int window[26] = {0};

    for (int i = 0; i < n; i++) {
        need[s1[i] - 'a']++;
        window[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (need[i] == window[i]) matches++;
    }

    if (matches == 26) return true;

    for (int i = n; i < m; i++) {
        int add_idx = s2[i] - 'a';
        int rem_idx = s2[i - n] - 'a';

        window[add_idx]++;
        if (window[add_idx] == need[add_idx]) {
            matches++;
        } else if (window[add_idx] == need[add_idx] + 1) {
            matches--;
        }

        window[rem_idx]--;
        if (window[rem_idx] == need[rem_idx]) {
            matches++;
        } else if (window[rem_idx] == need[rem_idx] - 1) {
            matches--;
        }

        if (matches == 26) return true;
    }

    return false;
}
