class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> need(n, 0);
        for (auto& e : edges) {
            int i = e[0], j = e[1];
            need[j] |= (1 << i);
        }
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1)
                continue;
            int pos = __builtin_popcount(mask) + 1;
            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 0 && (mask & need[i]) == need[i]) {
                    int mask2 = mask | (1 << i);
                    dp[mask2] = max(dp[mask2], dp[mask] + score[i] * pos);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};