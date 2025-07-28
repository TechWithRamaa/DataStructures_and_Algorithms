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
