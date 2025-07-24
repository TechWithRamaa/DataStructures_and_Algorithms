class Solution {
public:
    // dp[i][j] = true if s3[0...(i+j-1)] is formed by interleaving s1[0...(i-1)] and s2[0...(j-1)]
    bool isInterleave(string s1, string s2, string s3) {
        int N = s1.size(), M = s2.size(), T = s3.size();
        if (N + M != T)
            return false;

        vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
        dp[0][0] = true;

        /*
        Base Cases:
        dp[0][0] = true → empty strings interleave to form empty string.
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1] → only s1 is used.
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1] → only s2 is used.
        */

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) // The base cases are being handled inside the loop when i == 0 or j == 0.
                    dp[i][j] = dp[i][j] || dp[i - 1][j];

                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[N][M];
    }
};