struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    struct ListNode* prevGroupTail = head;
    int groupSize = 2;
    struct ListNode* curr = head->next;
    
    while (curr) {
        struct ListNode* groupStart = curr;
        struct ListNode* last = curr;
        int count = 1;
        struct ListNode* nextGroupStart = curr->next;
        
        while (nextGroupStart && count < groupSize) {
            last = nextGroupStart;
            nextGroupStart = nextGroupStart->next;
            count++;
        }
        
        if (count % 2 == 0) {
            struct ListNode* prev = nextGroupStart;
            struct ListNode* c = groupStart;
            for (int i = 0; i < count; i++) {
                struct ListNode* nxt = c->next;
                c->next = prev;
                prev = c;
                c = nxt;
            }
            prevGroupTail->next = prev;
            prevGroupTail = groupStart;
        } else {
            prevGroupTail = last;
        }
        
        curr = nextGroupStart;
        groupSize++;
    }
    
    return head;
}
