class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lis(0, -1, nums, dp);
    }

private:
    int lis(int index, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;  

        if (prevIndex != -1 && dp[index][prevIndex] != -1) 
            return dp[index][prevIndex];

        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + lis(index + 1, index, nums, dp);
        }

        int notTake = lis(index + 1, prevIndex, nums, dp);

        if (prevIndex != -1) 
            dp[index][prevIndex] = max(take, notTake);

        return max(take, notTake);
    }
};