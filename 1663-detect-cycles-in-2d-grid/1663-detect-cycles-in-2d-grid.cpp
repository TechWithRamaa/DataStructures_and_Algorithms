class Solution {
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,
             int y, int parentX, int parentY) {

        visited[x][y] = true;

        vector<int> directions = {0, 1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            int newX = x + directions[d];
            int newY = y + directions[d + 1];

            if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                newY < grid[0].size() && grid[newX][newY] == grid[x][y]) {
                if (!visited[newX][newY]) {
                    if (dfs(grid, visited, newX, newY, x, y))
                        return true;
                } else if (newX != parentX || newY != parentY)
                    return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};