class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        
        int result = coinChange(coins.size() - 1, coins, amount, dp);
        return (result == INT_MAX) ? -1 : result; 
    }

private:
    int coinChange(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;  
        if (index == 0) {
            if(amount % coins[index] == 0) {
                return amount / coins[index];
            } else {
                return INT_MAX; 
            } 
        } 
            

        if (dp[index][amount] != -1) return dp[index][amount]; 

        int take = INT_MAX;
        if (coins[index] <= amount) {
            int subResult = coinChange(index, coins, amount - coins[index], dp);
            if (subResult != INT_MAX) 
                take = 1 + subResult;
        }

        int notTake = coinChange(index - 1, coins, amount, dp);

        return dp[index][amount] = min(take, notTake);
    }
};