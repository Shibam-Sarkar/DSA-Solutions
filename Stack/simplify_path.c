char* simplifyPath(char* path) {
    int n = strlen(path);
    
    char** stack = (char**)malloc(n * sizeof(char*));
    int top = -1;
    
    char* token = strtok(path, "/");
    
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
        
        } else if (strcmp(token, "..") == 0) {
            if (top >= 0) {
                free(stack[top]);
                top--;
            }
        } else {
            stack[++top] = (char*)malloc(strlen(token) + 1);
            strcpy(stack[top], token);
        }
        token = strtok(NULL, "/");
    }
    
    int resultLen = 1; 
    for (int i = 0; i <= top; i++) {
        resultLen += strlen(stack[i]) + 1; 
    }
    
    char* result = (char*)malloc(resultLen + 1);
    int idx = 0;
    result[idx++] = '/';
    
    for (int i = 0; i <= top; i++) {
        int len = strlen(stack[i]);
        memcpy(result + idx, stack[i], len);
        idx += len;
        if (i != top) {
            result[idx++] = '/';
        }
        free(stack[i]);
    }
    
    result[idx] = '\0';
    free(stack);
    
    return result;
}
