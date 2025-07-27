class Solution {
public:
    // unbounded knapsack
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        const int INF = 1e9; // Large value to represent impossible states

        // dp[i][a] = minimum number of coins to make 'a' using first i coins
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, INF)); // (INF) to represent "impossible".

        // Base Case: To form amount = 0, we need 0 coins
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0; // possible but 0 coins required
        }

        // Fill the table
        for (int i = 1; i <= N; i++) {          // i = 1..n (coin index)
            for (int a = 1; a <= amount; a++) { // a = 1..amount
                int notTake = dp[i - 1][a];     // Don't take the i-th coin

                int take = INF; // (INF) to represent "impossible".
                if (coins[i - 1] <= a) {
                    // Take the coin (i-th coin is coins[i-1])
                    // Since we can use the same coin unlimited times, we stay
                    // on row i
                    take = 1 + dp[i][a - coins[i - 1]];
                }

                dp[i][a] = min(take, notTake);
            }
        }

        // If dp[n][amount] is INF, it means it's impossible to make that amount
        return (dp[N][amount] == INF) ? -1 : dp[N][amount];
    }
};