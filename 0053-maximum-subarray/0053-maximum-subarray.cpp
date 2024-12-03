class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int runningSum = nums[0];
        int largestSum = nums[0];
        // Kadane's algorithm
        for(int i = 1; i < nums.size(); i++) {
            // Join the existing community 
            if(runningSum >= 0) 
                runningSum += nums[i];
            else 
                runningSum = nums[i];

            largestSum = max(largestSum, runningSum);
        } 

        return largestSum;
    }
};