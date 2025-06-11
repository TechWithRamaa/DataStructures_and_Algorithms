class Solution {
public:
    // Kadane's Variation in two different styles
    // TC ~ O ( n )
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

    int maxSubArray1(vector<int>& nums) {
        int maxSum = INT_MIN;
        int runningSum = 0;

        for(int num : nums) {
            runningSum = max(num, runningSum + num);
            maxSum = max(runningSum, maxSum);
        }

        return maxSum;
    }
};