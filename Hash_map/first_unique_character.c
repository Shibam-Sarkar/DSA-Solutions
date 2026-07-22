int firstUniqChar(char* s) {
    int counts[26] = {0};
    int i;
    
    for (i = 0; s[i] != '\0'; i++) {
        counts[s[i] - 'a']++;
    }
    
    for (i = 0; s[i] != '\0'; i++) {
        if (counts[s[i] - 'a'] == 1) {
            return i;
        }
    }
