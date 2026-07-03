
int* findAnagrams(char* s, char* p, int* returnSize) {
    int n = strlen(p);
    int m = strlen(s);

    *returnSize = 0;

    if (n > m) {
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * m); 
    int need[26] = {0};
    int window[26] = {0};

    for (int i = 0; i < n; i++) {
        need[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (need[i] == window[i]) matches++;
    }

    if (matches == 26) {
        result[(*returnSize)++] = 0;
    }

    for (int i = n; i < m; i++) {
        int add_idx = s[i] - 'a';
        int rem_idx = s[i - n] - 'a';

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

        if (matches == 26) {
            result[(*returnSize)++] = i - n + 1;
        }
    }

    return result;
}
