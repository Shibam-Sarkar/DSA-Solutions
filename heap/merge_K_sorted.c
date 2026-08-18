
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    struct ListNode* heap[10005];
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            int pos = heapSize++;
            heap[pos] = lists[i];

            // Heapify up
            while (pos > 0) {
                int parent = (pos - 1) / 2;

                if (heap[parent]->val <= heap[pos]->val)
                    break;

                struct ListNode* temp = heap[parent];
                heap[parent] = heap[pos];
                heap[pos] = temp;

                pos = parent;
            }
        }
    }

    // Dummy node for result
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    while (heapSize > 0) {
        struct ListNode* minNode = heap[0];

        tail->next = minNode;
        tail = tail->next;

        if (minNode->next != NULL) {
            heap[0] = minNode->next;
        } else {
            heap[0] = heap[--heapSize];
        }

        // Heapify down
        int pos = 0;

        while (1) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < heapSize &&
                heap[left]->val < heap[smallest]->val) {
                smallest = left;
            }

            if (right < heapSize &&
                heap[right]->val < heap[smallest]->val) {
                smallest = right;
            }

            if (smallest == pos)
                break;

            struct ListNode* temp = heap[pos];
            heap[pos] = heap[smallest];
            heap[smallest] = temp;

            pos = smallest;
        }
    }

    tail->next = NULL;

    return dummy.next;
}
