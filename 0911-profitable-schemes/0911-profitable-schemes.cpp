class Solution {
public:
    const int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        int m = group.size();

        // dp[people][profit] = number of ways
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1; // 1 way to do nothing with 0 people and 0 profit

        for (int i = 0; i < m; i++) {
            int g = group[i];  // people required for current crime
            int p = profit[i]; // profit of current crime

            // Make a copy of current dp to update new states (bottom-up)
            vector<vector<int>> newDp = dp;

            for (int people = 0; people <= n; people++) {
                for (int prof = 0; prof <= minProfit; prof++) {

                    // ⚠️ Exclude: just keep previous value (already in newDp)

                    // ✅ Include current crime if we have enough people
                    if (people + g <= n) {
                        int newProfit = min(minProfit, prof + p); // Cap profit
                        newDp[people + g][newProfit] =
                            (newDp[people + g][newProfit] + dp[people][prof]) %
                            MOD;
                    }
                }
            }

            dp = newDp; // Update dp for the next crime
        }

        // Total schemes with any number of people, but profit >= minProfit
        int result = 0;
        for (int people = 0; people <= n; people++) {
            result = (result + dp[people][minProfit]) % MOD;
        }

        return result;
    }
};