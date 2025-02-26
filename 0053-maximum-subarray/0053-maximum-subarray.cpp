class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int runningSum = 0;

        for(int num : nums) {
            runningSum += num;
            maxSum = max(runningSum, maxSum);

            if(runningSum < 0) {
                runningSum = 0;
            }
        }

        return maxSum;
    }
};