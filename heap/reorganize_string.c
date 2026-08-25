char* reorganizeString(char* s) {
    int n = strlen(s);
    int freq[26] = {0};

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    int maxChar = 0, maxFreq = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

    if (maxFreq > (n + 1) / 2)
        return "";

    char *ans = malloc((n + 1) * sizeof(char));
    int pos = 0;

    while (freq[maxChar] > 0) {
        ans[pos] = 'a' + maxChar;
        freq[maxChar]--;
        pos += 2;
    }

    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            if (pos >= n)
                pos = 1;

            ans[pos] = 'a' + i;
            freq[i]--;
            pos += 2;
        }
    }

    ans[n] = '\0';
    return ans;
}
