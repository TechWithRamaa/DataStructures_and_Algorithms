class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> visitedAtlantic(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> visitedPacific(ROWS, vector<bool>(COLS, false));

        for (int i = 0; i < ROWS; i++) {
            dfs(i, 0, heights, visitedPacific);
            dfs(i, COLS - 1, heights, visitedAtlantic);
        }

        for (int j = 0; j < COLS; j++) {
            dfs(0, j, heights, visitedPacific);
            dfs(ROWS - 1, j, heights, visitedAtlantic);
        }

        vector<vector<int>> results;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (visitedAtlantic[i][j] && visitedPacific[i][j]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }

private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS
                && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }
};