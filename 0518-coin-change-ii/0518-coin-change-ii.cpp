class Solution {
public:
    int change(int amount, const vector<int>& coins) {
        const int N = coins.size();
        // return countWaysTopDown(amount, coins, N);
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

    int countWaysBottomUp(int T, const vector<int>& coins, const int N) {
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