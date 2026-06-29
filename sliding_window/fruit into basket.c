int totalFruit(int* fruits, int fruitsSize) {
    int count[fruitsSize];
    memset(count, 0, sizeof(int) * fruitsSize);

    int left = 0, types = 0, best = 0;

    for (int right = 0; right < fruitsSize; right++) {
        if (count[fruits[right]] == 0) types++;
        count[fruits[right]]++;        

        while (types > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) types--;
            left++;
        }

        if (right - left + 1 > best)
            best = right - left + 1;
    }

    return best;
}
