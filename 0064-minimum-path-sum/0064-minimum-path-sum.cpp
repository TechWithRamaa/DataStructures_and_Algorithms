class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));

        return minPathSum(M - 1, N - 1, grid, dp);
    }
private:
    int minPathSum(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = minPathSum(i - 1, j, grid, dp);
        int left = minPathSum(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
};