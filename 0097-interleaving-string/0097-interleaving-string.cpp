class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N = s1.size(), M = s2.size(), T = s3.size();
        if (N + M != T)
            return false;

        vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) 
                    dp[i][j] = dp[i][j] || dp[i - 1][j];

                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[N][M];
    }
};