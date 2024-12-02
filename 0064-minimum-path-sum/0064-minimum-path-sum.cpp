class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        return minPathSumTopDown(grid);
    }
private:
    int minPathSumTopDown(const vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));

        return minPathSumTopDown(M - 1, N - 1, grid, dp);
    }

    int minPathSumTopDown(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = minPathSumTopDown(i - 1, j, grid, dp);
        int left = minPathSumTopDown(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
};