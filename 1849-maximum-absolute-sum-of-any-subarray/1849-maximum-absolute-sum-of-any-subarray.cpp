class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currentMaxSum = 0, currentMinSum = 0;

        for (auto num : nums) {
            // Track maximum subarray sum (Kadane's)
            currentMaxSum = max(num, currentMaxSum + num);
            maxSum = max(maxSum, currentMaxSum);

            // Track minimum subarray sum (Kadane's variation)
            currentMinSum = min(num, currentMinSum + num);
            minSum = min(minSum, currentMinSum);
        }

        return max(maxSum, abs(minSum));
    }
};