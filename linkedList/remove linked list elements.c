struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* current = &dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* toDelete = current->next;
            current->next = current->next->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }
    
    return dummy.next;
}
