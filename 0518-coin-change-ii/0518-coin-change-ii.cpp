class Solution {
public:
    int change(int amount, const vector<int>& coins) {
        const int N = coins.size();
        vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
        return countWays(N - 1, amount, coins, dp);
    }

private:
    int countWays(int index, int amount, const vector<int>& coins, vector<vector<int>>& dp) {
        if(index == 0)
            return (amount % coins[0] == 0);

        if (dp[index][amount] != -1)
            return dp[index][amount]; 

        int exclude = countWays(index - 1, amount, coins, dp);
        int include = 0;
        if(coins[index] <= amount)
            include = countWays(index, amount - coins[index], coins, dp);
       

        return dp[index][amount] = include + exclude; 
    }
};