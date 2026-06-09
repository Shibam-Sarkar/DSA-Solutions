bool backspaceCompare(char* s, char* t) {
    char stack_s[201], stack_t[201];
    int top_s = 0, top_t = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '#') {
            if (top_s > 0) top_s--;
        } else {
            stack_s[top_s++] = s[i];
        }
    }

    for (int i = 0; t[i]; i++) {
        if (t[i] == '#') {
            if (top_t > 0) top_t--;
        } else {
            stack_t[top_t++] = t[i];
        }
    }

    if (top_s != top_t) return false;

    for (int i = 0; i < top_s; i++) {
        if (stack_s[i] != stack_t[i]) return false;
    }

    return true;
}
