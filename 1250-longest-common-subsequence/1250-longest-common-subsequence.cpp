class Solution {
private:
    int helper(const string& text1, const string& text2, int ind1, int ind2,
               vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2])
            return dp[ind1][ind2] =
                       1 + helper(text1, text2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = max(helper(text1, text2, ind1 - 1, ind2, dp),
                                    helper(text1, text2, ind1, ind2 - 1, dp));
    }

    int longestCommonSubsequenceTopdown(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }

    int longestCommonSubsequenceBottomUp(string text1, string text2) {
        const int M = text1.size();
        const int N = text2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (text1[i - 1] == text2[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1]; 
                 else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
                
            }
        }

        return dp[M][N];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        //return longestCommonSubsequenceTopdown(text1, text2);
        return longestCommonSubsequenceBottomUp(text1, text2);
    }
};