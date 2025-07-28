class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int x : nums) maxOR |= x;

        // dp[orValue] = number of ways to reach that OR value
        unordered_map<int, int> dp;
        dp[0] = 1; // base case: one way to get OR = 0 (empty subset)

        for (int num : nums) {
            unordered_map<int, int> new_dp = dp;

            for (auto [prevOR, count] : dp) {
                // ----- EXCLUDE num -----
                // new_dp[prevOR] already has count from previous dp

                // ----- INCLUDE num -----
                int newOR = prevOR | num;
                new_dp[newOR] += count;
            }

            dp = move(new_dp); // update dp with include + exclude results
        }

        return dp[maxOR];
    }
};

class SolutionDFS {
public:
    int count = 0;
    int maxOR = 0;

    void dfs(vector<int>& nums, int i, int currOR) {
        if (i == nums.size()) {
            if (currOR == maxOR) count++;
            return;
        }

        // Exclude nums[i]
        dfs(nums, i + 1, currOR);

        // Include nums[i]
        dfs(nums, i + 1, currOR | nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums) maxOR |= x;
        dfs(nums, 0, 0);
        return count;
    }
};
