int maxNumberOfBalloons(char* text) {
    int count[26] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        count[text[i] - 'a']++;
    }
    
    int b = count['b' - 'a'];
    int a = count['a' - 'a'];
    int l = count['l' - 'a'] / 2;
    int o = count['o' - 'a'] / 2;
    int n = count['n' - 'a'];
    
    int result = b;
    if (a < result) result = a;
    if (l < result) result = l;
    if (o < result) result = o;
    if (n < result) result = n;
    
    return result;
}
