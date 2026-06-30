int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int maxFreq = 0;
    int left = 0;
    int result = 0;
    int n = strlen(s);
    
    for (int right = 0; right < n; right++) {
        int idx = s[right] - 'A';
        count[idx]++;
        if (count[idx] > maxFreq) {
            maxFreq = count[idx];
        }
        
        while ((right - left + 1) - maxFreq > k) {
            count[s[left] - 'A']--;
            left++;
        }
        
        int windowLen = right - left + 1;
        if (windowLen > result) {
            result = windowLen;
        }
    }
    
    return result;
}
