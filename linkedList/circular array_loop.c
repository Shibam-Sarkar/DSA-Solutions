int nextIndex(int* nums, int n, int i) {
    return ((i + nums[i]) % n + n) % n;
}

bool circularArrayLoop(int* nums, int numsSize) {
    int n = numsSize;

    for (int i = 0; i < n; i++) {

        if (nums[i] == 0)
            continue;

        bool forward = nums[i] > 0;

        int slow = i;
        int fast = i;

        while (1) {
            int nextSlow = nextIndex(nums, n, slow);

            if ((nums[nextSlow] > 0) != forward)
                break;

            int nextFast = nextIndex(nums, n, fast);

            if ((nums[nextFast] > 0) != forward)
                break;

            nextFast = nextIndex(nums, n, nextFast);

            if ((nums[nextFast] > 0) != forward)
                break;

            slow = nextSlow;
            fast = nextFast;

            if (slow == fast) {

                if (slow == nextIndex(nums, n, slow))
                    break;

                return true;
            }
        }
        int curr = i;

        while (nums[curr] != 0 &&
               (nums[curr] > 0) == forward) {

            int nxt = nextIndex(nums, n, curr);
            nums[curr] = 0;
            curr = nxt;
        }
    }

    return false;
}
