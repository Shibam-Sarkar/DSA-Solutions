class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> maxHeap;

        for (int x : arr) {
            maxHeap.push(x);

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};
