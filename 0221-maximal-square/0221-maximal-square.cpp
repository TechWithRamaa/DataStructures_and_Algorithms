class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();

        // Create a DP table to store the side length of the largest square ending at (i, j)
        // Note here, we dont store actural area of the square
        // we store only the side length ending at i
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int maxSide = 0;

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // top
                                       dp[i][j - 1],    // left
                                       dp[i - 1][j - 1] // top-left diagonal
                                   });
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide; // Return the area of the largest square
    }
};