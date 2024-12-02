class Solution {
public:
    bool canPartition(vector<int> nums) {
        return canPartition(nums.size(), nums);
    }
    
private:
    bool canPartition(int N, const vector<int>& arr) {
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

    bool subsetSum(int index, int target, const vector<int>& arr, vector<vector<int>>& dp) {
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