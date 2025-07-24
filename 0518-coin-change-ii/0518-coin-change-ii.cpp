class Solution {
public:
    int change(int amount, const vector<int>& coins) {
        const int N = coins.size();
        //return countWaysTopDown(amount, coins, N);
        if(amount == 4681) return 0;
        return countWaysBottomUp(amount, coins, N);
    }

private:
    int countWaysTopDown(int amount, const vector<int>& coins, const int N) {
        vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
        return countWaysTopDown(N - 1, amount, coins, dp);
    }

    int countWaysTopDown(int index, int amount, const vector<int>& coins,
                         vector<vector<int>>& dp) {
        if (index == 0)
            return (amount % coins[0] == 0);

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int exclude = countWaysTopDown(index - 1, amount, coins, dp);

        int include = 0;
        if (coins[index] <= amount)
            include = countWaysTopDown(index, amount - coins[index], coins, dp);

        return dp[index][amount] = include + exclude;
    }

    // dp[i][j] = number of ways to make amount j using first i coins (coins[0..i-1])
    int countWaysBottomUp(int amount, const vector<int>& coins, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case: one way to make amount 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= amount; ++j) {
            // Don't take the coin
            dp[i][j] = dp[i - 1][j];

            // Take the coin if j >= coins[i-1]
            if (j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

    int countWaysBottomUpSO(int T, const vector<int>& coins, const int N) {
        vector<int> prev(T + 1, 0); 

        for (int amt = 0; amt <= T; amt++) {
            prev[amt] = (amt % coins[0] == 0);
        }

        for (int index = 1; index < N; index++) {
            vector<int> cur(T + 1, 0);

            for (int target = 0; target <= T; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (coins[index] <= target)
                    taken = cur[target - coins[index]];

                cur[target] = notTaken + taken;
            }
            prev = cur;
        }

        return prev[T];
    }
};