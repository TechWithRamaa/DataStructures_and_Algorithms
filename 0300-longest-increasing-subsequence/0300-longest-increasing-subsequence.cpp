class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // Use n instead of n+1
        return lis(0, -1, nums, dp);
    }

private:
    int lis(int index, int prev_index, vector<int>& nums, vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;  // Base case

        // Adjust prev_index + 1 only when prev_index is valid
        if (prev_index != -1 && dp[index][prev_index] != -1) 
            return dp[index][prev_index];

        int take = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            take = 1 + lis(index + 1, index, nums, dp);
        }
        int notTake = lis(index + 1, prev_index, nums, dp);

        // Store the result only if prev_index is valid
        if (prev_index != -1) 
            dp[index][prev_index] = max(take, notTake);

        return max(take, notTake);
    }
};