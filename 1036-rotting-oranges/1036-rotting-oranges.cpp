class Solution {
public:
     int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten; // Queue to store the position of rotten oranges
        int freshCount = 0; // Count of fresh oranges
        
        // Initialize the queue with the position of all rotten oranges
        // and count the number of fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges, no time is needed
        if (freshCount == 0) return 0;

        int minutes = 0; // Time elapsed
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4-directional movement

        // BFS to spread rot
        while (!rotten.empty()) {
            int size = rotten.size();
            bool rottenSpread = false; // Track if any fresh oranges become rotten

            for (int i = 0; i < size; ++i) {
                auto [x, y] = rotten.front();
                rotten.pop();

                // Explore neighbors
                for (auto& [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;

                    // Check if the cell is within bounds and contains a fresh orange
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // Mark as rotten
                        rotten.push({newX, newY}); // Add to the queue
                        freshCount--; // Decrease the count of fresh oranges
                        rottenSpread = true;
                    }
                }
            }

            // If any rotten oranges spread, increment the time
            if (rottenSpread) minutes++;
        }

        // If there are still fresh oranges, return -1
        return freshCount == 0 ? minutes : -1;
    }
};