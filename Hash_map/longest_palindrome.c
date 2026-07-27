int longestPalindrome(char* s) {
    int count[128] = {0};
    int len = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
    }
    
    int hasOdd = 0;
    for (int i = 0; i < 128; i++) {
        len += (count[i] / 2) * 2;   
        if (count[i] % 2 == 1) {
            hasOdd = 1;
        }
    }
    
    return hasOdd ? len + 1 : len;
}
