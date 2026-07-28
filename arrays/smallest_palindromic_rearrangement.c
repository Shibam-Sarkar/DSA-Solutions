char* smallestPalindrome(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    char *ans = (char *)malloc((n + 1) * sizeof(char));

    int left = 0, right = n - 1;
    char mid = '\0';

    for (int i = 0; i < 26; i++) {
        while (freq[i] >= 2) {
            ans[left++] = 'a' + i;
            ans[right--] = 'a' + i;
            freq[i] -= 2;
        }
        if (freq[i] == 1)
            mid = 'a' + i;
    }

    if (left == right)
        ans[left] = mid;

    ans[n] = '\0';
    return ans;
}
