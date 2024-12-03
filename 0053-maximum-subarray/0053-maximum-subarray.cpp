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

            // Start new business
            // As runningSum becomes negative
            // it is better to not join the existing business with debt
            // so resetting to zero or starting a new business
            if(runningSum > largestSum)
                largestSum = runningSum;
        } 

        return largestSum;
    }
};