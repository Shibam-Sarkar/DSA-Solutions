struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* node = head;
    int count = 0;
    while (node && count < k) {
        node = node->next;
        count++;
    }
    
    if (count < k) {
        return head;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    for (int i = 0; i < k; i++) {
        struct ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    head->next = reverseKGroup(curr, k);
    
    return prev;
}
