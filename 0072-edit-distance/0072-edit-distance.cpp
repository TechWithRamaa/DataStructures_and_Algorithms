class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistanceBottomUp(word1, word2);
        // return minDistanceTopDown(word1, word2);
    }

private:
    int minDistanceTopDown(const string& word1, const string& word2) {
        const int M = word1.size();
        const int N = word2.size();
        vector<vector<int>> dp(M, vector<int>(N, -1));

        return minDistanceTopDown(word1, word2, M - 1, N - 1, dp);
    }

    int minDistanceTopDown(const string& word1, const string& word2, int i,
                           int j, vector<vector<int>>& dp) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            dp[i][j] = minDistanceTopDown(word1, word2, i - 1, j - 1, dp);
        else {
            int insertOp = 1 + minDistanceTopDown(word1, word2, i, j - 1, dp);
            int deleteOp = 1 + minDistanceTopDown(word1, word2, i - 1, j, dp);
            int replaceOp =
                1 + minDistanceTopDown(word1, word2, i - 1, j - 1, dp);

            dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }

        return dp[i][j];
    }

    int minDistanceBottomUp(const string& word1, const string& word2) {
        const int M = word1.size();
        const int N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));

        // Base cases
        for (int i = 0; i <= M; i++)
            dp[i][0] = i; // Deletion operations
        for (int j = 0; j <= N; j++)
            dp[0][j] = j; // Insertion operations

        // Fill the DP table
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1 });
                
            }
        }
        return dp[M][N];
    }
};