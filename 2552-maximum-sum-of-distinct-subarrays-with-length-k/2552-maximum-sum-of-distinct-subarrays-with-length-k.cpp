class Solution {
public:
    // Dynamic Window Sliding
    // Cant use fixed even though k length subarray is expected
    // as we had to ensure subarray elements must be distinct within the window
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSubArraySum = 0;
        int N = nums.size();
        
        int left = 0;
        long long runningSum = 0;
        unordered_set<int> distinctNumbers;
        for (int right = 0; right < N; right++) {

            while (distinctNumbers.count(nums[right])) {
                distinctNumbers.erase(nums[left]);
                runningSum -= nums[left];
                left++;
            }

            distinctNumbers.insert(nums[right]);
            runningSum += nums[right];

            if (k == right - left + 1) {
                maxSubArraySum = max(maxSubArraySum, runningSum);

                distinctNumbers.erase(nums[left]);
                runningSum -= nums[left];
                left++;
            }
        }

        return maxSubArraySum;
    }
};