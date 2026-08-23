int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            count++;
        }
    }

    int result = (maxFreq - 1) * (n + 1) + count;

    return result > tasksSize ? result : tasksSize;
}
