class Solution {
public:
     int maxCoins(vector<int>& nums) {
        return maxCoinsTopDown(nums);        
    }
    

private:
    int maxCoinsBottomUp(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return burst(nums, 0, n + 1, dp);
    }

    int maxCoinsTopDown(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return burst(nums, 0, n + 1, dp);
    }

    int burst(const vector<int>& nums, int left, int right,
              vector<vector<int>>& dp) {
        if (left + 1 == right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int maxCoins = 0;

        for (int k = left + 1; k < right; k++) {
            int coins = nums[left] * nums[k] * nums[right] +
                        burst(nums, left, k, dp) + burst(nums, k, right, dp);

            maxCoins = max(maxCoins, coins);
        }

        return dp[left][right] = maxCoins;
    }
};