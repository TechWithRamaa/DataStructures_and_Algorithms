class Solution {
public:
    bool canPartition(vector<int> nums) {
        return canPartitionBottomUp(nums.size(), nums);
    }

private:
    bool canPartitionBottomUp(int N, const vector<int>& arr) {
        int totalSum = 0;

        for (int element : arr)
            totalSum += element;

        if (totalSum % 2 == 1)
            return false;
        else {
            int k = totalSum / 2;

            vector<bool> prev(k + 1, false);

            prev[0] = true;

            if (arr[0] <= k)
                prev[arr[0]] = true;

            for (int ind = 1; ind < N; ind++) {
                vector<bool> cur(k + 1, false);
                cur[0] = true;

                for (int target = 1; target <= k; target++) {
                    bool exclude = prev[target];

                    bool include = false;
                    if (arr[ind] <= target)
                        include = prev[target - arr[ind]];

                    cur[target] = exclude || include;
                }

                prev = cur;
            }
             return prev[k];
        }

       
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