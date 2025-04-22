class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Directions for 4-directional movement (up, down, left, right)
        vector<int> directions = {-1, 0, 1, 0, -1, 0};

        // Function to perform BFS to find and mark the first island
        auto bfs = [&](int startX, int startY) {
            queue<pair<int, int>> q;
            q.push({startX, startY});
            visited[startX][startY] = true;
            vector<pair<int, int>> islandCells;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                islandCells.push_back({x, y});

                for (int i = 0; i < 4; ++i) {
                    int newX = x + directions[i];
                    int newY = y + directions[i + 1];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                        !visited[newX][newY] && grid[newX][newY] == 1) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
            return islandCells;
        };

        // Step 1: Find the first island
        vector<pair<int, int>> firstIslandCells;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    firstIslandCells = bfs(i, j);
                    break;
                }
            }
            if (!firstIslandCells.empty())
                break;
        }

        // Step 2: Perform BFS from the boundary of the first island to find the
        // shortest bridge
        queue<pair<int, int>> q;
        for (const auto& [x, y] : firstIslandCells) {
            q.push({x, y});
        }

        vector<vector<bool>> distVisited(n, vector<bool>(n, false));
        for (const auto& [x, y] : firstIslandCells) {
            distVisited[x][y] = true;
        }

        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int newX = x + directions[j];
                    int newY = y + directions[j + 1];

                    if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                        !distVisited[newX][newY]) {
                        distVisited[newX][newY] = true;

                        if (grid[newX][newY] == 1) {
                            return distance;
                        }

                        q.push({newX, newY});
                    }
                }
            }
            distance++;
        }

        return -1; // This should never happen as there are always two islands
    }
};