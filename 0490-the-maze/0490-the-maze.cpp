class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start[0]][start[1]] = true;

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // right, down, left, up

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            // Check if destination reached
            if (x == destination[0] && y == destination[1]) return true;

            for (auto& dir : dirs) {
                int nx = x, ny = y;

                // Roll the ball until it hits a wall
                while (nx + dir[0] >= 0 && nx + dir[0] < m &&
                       ny + dir[1] >= 0 && ny + dir[1] < n &&
                       maze[nx + dir[0]][ny + dir[1]] == 0) {
                    nx += dir[0];
                    ny += dir[1];
                }

                // Only consider new stopping position if not visited
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};
