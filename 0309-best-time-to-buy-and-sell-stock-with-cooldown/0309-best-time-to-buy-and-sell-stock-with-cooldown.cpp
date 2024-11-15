class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2, -1));
        return helper(prices, 0, false, memo); 
    }

private:
    int helper(vector<int>& prices, int i, bool holding, vector<vector<int>>& memo) {
        if (i >= prices.size())
            return 0; 

        if (memo[i][holding] != -1)
            return memo[i][holding]; 

        if (holding) {
            // Choice: Sell or Hold
            return memo[i][holding] =
                       max(prices[i] + helper(prices, i + 2, false, memo), helper(prices, i + 1, true, memo));
        } else {
            // Choice: Buy or Skip
            return memo[i][holding] = max(
                       -prices[i] + helper(prices, i + 1, true, memo), helper(prices, i + 1, false, memo));
        }
    }
};