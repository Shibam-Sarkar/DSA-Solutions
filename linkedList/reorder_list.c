void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;

    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow->next;
    slow->next = NULL;
    while (curr) {
        struct ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    struct ListNode *first = head, *second = prev;
    while (second) {
        struct ListNode *tmp1 = first->next, *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
