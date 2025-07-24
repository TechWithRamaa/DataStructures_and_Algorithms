class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][0] = -prices[0]; // holding
        dp[0][1] = 0;          // sold
        dp[0][2] = 0;          // rest

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);   // buy or carry forward
            dp[i][1] = dp[i - 1][0] + prices[i];        // sell
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]); // rest
        }

        return max(dp[n - 1][1], dp[n - 1][2]); // can't end holding
    }
    
    int maxProfitr(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return helper(prices, 0, false, memo);
    }

private:
    int helper(vector<int>& prices, int i, bool holding,
               vector<vector<int>>& memo) {
        if (i >= prices.size())
            return 0;

        if (memo[i][holding] != -1)
            return memo[i][holding];

        if (holding) {
            // Choice: Sell or Hold
            return memo[i][holding] =
                       max(prices[i] + helper(prices, i + 2, false, memo),
                           helper(prices, i + 1, true, memo));
        } else {
            // Choice: Buy or Skip
            return memo[i][holding] =
                       max(-prices[i] + helper(prices, i + 1, true, memo),
                           helper(prices, i + 1, false, memo));
        }
    }
};