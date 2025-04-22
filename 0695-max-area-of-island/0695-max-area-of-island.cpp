class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int maxAreaOfIsland = INT_MIN;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int islandSize = dfs(grid, visited, i , j);
                    maxAreaOfIsland = max(maxAreaOfIsland, islandSize);
                }
            }
        }

        return maxAreaOfIsland == INT_MIN ? 0 : maxAreaOfIsland;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r , int c) {
        visited[r][c] = true;
        int area = 1;  // current cell counts as 1

        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(auto [dr, dc] : dir) {
            int nr = dr + r;
            int nc = dc + c;

            if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS 
                && grid[nr][nc] == 1 && !visited[nr][nc]) {
                    area += dfs(grid, visited, nr, nc);
            }
        }

        return area;
    }
};