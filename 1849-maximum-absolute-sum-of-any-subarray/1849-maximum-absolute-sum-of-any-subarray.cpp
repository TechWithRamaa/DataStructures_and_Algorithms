class Solution {
public:
    // Kadane's Algorithm ~ O ( n )
    // 2 styles are there

     int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currentMaxSum = 0, currentMinSum = 0;

        for (auto num : nums) {
            currentMaxSum += num;
            maxSum = max(maxSum, currentMaxSum);

            currentMinSum += num;
            minSum = min(minSum, currentMinSum);

            if(currentMaxSum < 0) {
                currentMaxSum = 0;
            }

            if(currentMinSum > 0) {
                currentMinSum = 0;
            }
        }

        return max(maxSum, abs(minSum));
    }

    int maxAbsoluteSum2(vector<int>& nums) {
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