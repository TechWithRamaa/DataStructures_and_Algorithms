class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int G = group.size();
        
        // dp[people][profit] = number of schemes
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1; // base case: 0 people, 0 profit — 1 way

        for (int k = 0; k < G; k++) {
            int g = group[k];    // people needed
            int p = profit[k];   // profit earned

            // Go backwards to avoid using updated states in same iteration
            for (int people = n; people >= g; people--) {
                for (int prof = minProfit; prof >= 0; prof--) {
                    int newProfit = min(minProfit, prof + p); // cap it at minProfit
                    dp[people][newProfit] = (dp[people][newProfit] + dp[people - g][prof]) % MOD;
                }
            }
        }

        // Sum all schemes with profit ≥ minProfit
        int result = 0;
        for (int people = 0; people <= n; people++) {
            result = (result + dp[people][minProfit]) % MOD;
        }

        return result;
    }
};