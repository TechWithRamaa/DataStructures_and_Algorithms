class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistanceTopDown(word1, word2);
    }

private:
    int minDistanceTopDown(const string& word1, const string& word2) {
        const int M = word1.size();
        const int N = word2.size();
        vector<vector<int>> dp(M, vector<int>(N, -1));

        return minDistanceTopDown(word1, word2, M-1, N-1, dp);
    }

    int minDistanceTopDown(const string& word1, const string& word2, int i, int j, vector<vector<int>>& dp) {
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j])
            dp[i][j] = minDistanceTopDown(word1, word2, i-1, j-1, dp);
        else {
            int insertOp = 1 + minDistanceTopDown(word1, word2, i, j-1, dp);
            int deleteOp = 1 + minDistanceTopDown(word1, word2, i-1, j, dp);
            int replaceOp = 1 + minDistanceTopDown(word1, word2, i-1, j-1, dp);

            dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }

        return dp[i][j];
    }
};