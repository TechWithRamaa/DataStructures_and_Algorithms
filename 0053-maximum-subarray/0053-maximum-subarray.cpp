class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = nums[0], windowSum = nums[0];
        int winStart = 0;

        for(int winEnd = 1; winEnd < nums.size(); winEnd++) {
            if(windowSum >= 0) 
                windowSum += nums[winEnd];
            else {
                winStart = winEnd;
                windowSum = nums[winEnd];
            } 

            largestSum = max(largestSum, windowSum);
        }

        return largestSum;
    }
};