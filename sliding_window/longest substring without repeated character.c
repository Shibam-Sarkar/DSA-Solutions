nt lengthOfLongestSubstring(char* s) {
    int last_seen[128];
    memset(last_seen, -1, sizeof(last_seen));

    int left = 0;
    int max_len = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        int c = s[right];

        if (last_seen[c] >= left)
            left = last_seen[c] + 1;

        last_seen[c] = right;
        int window = right - left + 1;
        if (window > max_len)
            max_len = window;
    }

    return max_len;
}
