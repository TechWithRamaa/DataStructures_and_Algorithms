class Solution {
public:
    // unbounded knapsack
    int change(int amount, vector<int>& coins) {
        int N = coins.size();

        // dp[i][a] = number of ways to make 'a' using first i coins
        vector<vector<unsigned long long>> dp(N + 1, vector<unsigned long long>(amount + 1, 0)); 

        // Base Case: To form amount = 0, we need 0 coins
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1; // possible but 0 coins required => there s always 1 way of doing it
        }

        // Fill the table
        for (int i = 1; i <= N; i++) {          // i = 1..n (coin index)
            for (int a = 1; a <= amount; a++) { // a = 1..amount
                unsigned long long notTake = dp[i - 1][a];     // Don't take the i-th coin

                unsigned long long take = 0; // zero ways
                if (coins[i - 1] <= a) {
                    // Take the coin (i-th coin is coins[i-1])
                    // Since we can use the same coin unlimited times, we stay
                    // on row i
                    take = dp[i][a - coins[i - 1]];
                }

                dp[i][a] = take + notTake;
            }
        }

        return dp[N][amount] >= INT_MAX ? 0 : dp[N][amount];
    }
};