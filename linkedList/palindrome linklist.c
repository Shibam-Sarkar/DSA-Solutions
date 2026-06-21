struct ListNode* reverseList(struct ListNode* node) {
    struct ListNode* prev = NULL;
    while (node) {
        struct ListNode* nxt = node->next;
        node->next = prev;
        prev = node;
        node = nxt;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = reverseList(slow->next);

    struct ListNode* first = head;
    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }

    return true;
}
