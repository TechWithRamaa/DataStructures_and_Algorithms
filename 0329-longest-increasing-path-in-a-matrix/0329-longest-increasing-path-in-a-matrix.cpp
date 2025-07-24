class Solution {
public:
    int m, n;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != 0)
            return dp[i][j];

        int maxLen = 1; // At minimum, the path includes (i, j) itself

        for (auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                int len = 1 + dfs(ni, nj, matrix, dp);
                maxLen = max(maxLen, len);
            }
        }

        dp[i][j] = maxLen;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};