class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int window_sum = 0;
        for (int i = 0; i < k; i++)
            window_sum += arr[i];
        
        int max_sum = window_sum;
        
        for (int i = k; i < n; i++) {
            window_sum += arr[i] - arr[i - k];
            if (window_sum > max_sum)
                max_sum = window_sum;
        }
        
        return max_sum;
    }
};
