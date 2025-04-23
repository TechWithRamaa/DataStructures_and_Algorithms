class Solution {
public:
    int n;
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        queue<pair<int, int>> q; // to push the visited cells from Island 1
        bool exploredFirstIsland = false;

        // Step 1: Find and mark the first island using DFS
        for (int i = 0; i < n && !exploredFirstIsland; ++i) {
            for (int j = 0; j < n && !exploredFirstIsland; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    exploredFirstIsland = true;
                }
            }
        }

        // Step 2: BFS to reach the second island
        int steps = 0;
        while (!q.empty()) {

            int size = q.size();
            for(int k = 0; k < size; k++) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int x = i + d[0], y = j + d[1];

                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1)
                            return steps; // Found second island

                        if (grid[x][y] == 0) {
                            grid[x][y] = -1; // Mark visited
                            q.push({x, y});
                        }
                    }
                }
            }
            
            ++steps;
        }

        return -1; // Should not reach here
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        grid[i][j] = -1; // Mark as visited
        q.push({i, j});

        for (auto& d : dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                dfs(grid, nr, nc, q);
        }
    }
};
