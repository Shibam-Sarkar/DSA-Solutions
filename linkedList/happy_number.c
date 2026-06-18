#include <stdbool.h>

int getNext(int n);  

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    return fast == 1;
}

int getNext(int n) {
    int total = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        total += digit * digit;
    }
    return total;
}
