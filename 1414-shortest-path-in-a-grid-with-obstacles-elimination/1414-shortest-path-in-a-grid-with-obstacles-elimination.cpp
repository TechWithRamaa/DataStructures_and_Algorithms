class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // If k is large enough to walk through any path ignoring obstacles
        if (k >= m + n - 2) return m + n - 2;

        // BFS queue: (row, col, remaining_k)
        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});

        // visited[i][j][k]: true if we've been to (i,j) with k obstacle removals left
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        visited[0][0][k] = true;

        int steps = 0;
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, rem] = q.front(); q.pop();

                if (x == m - 1 && y == n - 1) return steps;

                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        int new_rem = rem - grid[nx][ny];  // if obstacle, consume 1 from rem

                        if (new_rem >= 0 && !visited[nx][ny][new_rem]) {
                            visited[nx][ny][new_rem] = true;
                            q.push({nx, ny, new_rem});
                        }
                    }
                }
            }
            steps++; // After each level of BFS
        }

        return -1;  // no path found
    }
};
