class Solution {
public:
    bool canPartition(vector<int> nums) {
        return canPartitionBottomUp(nums.size(), nums);
    }

private:
    bool canPartitionBottomUp(int s, const vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 == 1)
            return false;

        int target = totalSum / 2;
        int N = nums.size();

        vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));

        // Base Case: 0 sum is always possible
        for (int i = 0; i <= N; i++)
            dp[i][0] = true;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][target];
    }

    bool canPartitionTopDown(int N, const vector<int>& arr) {
        int totalSum = 0;

        for (int element : arr)
            totalSum += element;

        if (totalSum % 2 == 1)
            return false;
        else {
            int k = totalSum / 2;
            vector<vector<int>> dp(N, vector<int>(k + 1, -1));

            return subsetSum(N - 1, k, arr, dp);
        }
    }
    bool subsetSum(int index, int target, const vector<int>& arr,
                   vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (index == 0)
            return arr[0] == target;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool notTaken = subsetSum(index - 1, target, arr, dp);

        bool taken = false;
        if (arr[index] <= target)
            taken = subsetSum(index - 1, target - arr[index], arr, dp);

        return dp[index][target] = notTaken || taken;
    }
};