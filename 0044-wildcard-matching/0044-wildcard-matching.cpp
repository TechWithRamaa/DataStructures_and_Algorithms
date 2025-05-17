class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size();
        int N = p.size();

        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));

        dp[0][0] = true; // both of them empty

        // Empty string vs pattern
        for (int j = 1; j <= N; ++j) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }



        return dp[M][N];
    }
};