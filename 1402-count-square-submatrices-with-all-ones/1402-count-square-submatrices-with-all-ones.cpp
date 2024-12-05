class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        int totalSquares = 0;

        for (int i = 0; i < M; i++) dp[i][0] = matrix[i][0];
        for (int j = 0; j < N; j++) dp[0][j] = matrix[0][j];

        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 1)  
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                else 
                    dp[i][j] = 0;
            }
        }
        
        for (int i = 0; i < M; i++) {
          for (int j = 0; j < N; j++) 
            totalSquares += dp[i][j];
        }
        
        return totalSquares;
    }

    int countSquaresTopDown(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        int totalSquares = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) 
                totalSquares += countSquares(matrix, i, j, dp);   
        }
        return totalSquares;
    }

private:
    int countSquares(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (matrix[i][j] == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j]; 
       
        dp[i][j] = 1 + min({countSquares(matrix, i - 1, j, dp),
                            countSquares(matrix, i, j - 1, dp),
                            countSquares(matrix, i - 1, j - 1, dp)});
        return dp[i][j];
    }
};