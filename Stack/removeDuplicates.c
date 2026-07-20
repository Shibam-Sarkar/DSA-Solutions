char* removeDuplicates(char* s, int k) {
    int n = strlen(s);
    
    char* result = (char*)malloc(n + 1);
    
    char* charStack = (char*)malloc(n);
    int* countStack = (int*)malloc(n * sizeof(int));
    int top = -1; 
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        
        if (top >= 0 && charStack[top] == c) {
            countStack[top]++;
            if (countStack[top] == k) {
                top--; 
            }
        } else {
            top++;
            charStack[top] = c;
            countStack[top] = 1;
        }
    }
    
    int idx = 0;
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < countStack[i]; j++) {
            result[idx++] = charStack[i];
        }
    }
    result[idx] = '\0';
    
    free(charStack);
    free(countStack);
    
    return result;
}
