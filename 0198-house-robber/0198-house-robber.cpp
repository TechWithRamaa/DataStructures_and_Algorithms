class Solution {
public:
 int f(vector<int> & nums, int house, vector<int>& dp) 
    {
        //base
        if(house>=nums.size()) return 0;

        if(dp[house] != -1) return dp[house];

        //rec
        return dp[house] = max(nums[house] + f(nums, house+2, dp), f(nums, house+3,dp));
    }

public:
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(), -1);
        // return f(nums, 0, dp);

        if(nums.size() == 1) {
            return nums[0];
        }

        int maxRob = 0, secondLast = 0, last = 0;
        for(int i = 0; i < nums.size(); i++) {
            int rob = nums[i] + secondLast;
            int dontRob = last;

            int currentRob = max(rob, dontRob);
            maxRob = max(maxRob, currentRob);

            secondLast = last;
            last = currentRob;
        }

        return maxRob;
    }
};