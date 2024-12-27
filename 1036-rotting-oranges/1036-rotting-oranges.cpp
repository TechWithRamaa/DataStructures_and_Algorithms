class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        queue<pair<int, int>> rotten;
        int freshCount = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0)
            return 0;

        int minutes = 0; 
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!rotten.empty()) {
            int size = rotten.size();
            bool rottenSpread = false; 

            for (int i = 0; i < size; i++) {
                auto [x, y] = rotten.front();
                rotten.pop();

                for (auto& [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;

                    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;      
                        rotten.push({newX, newY}); 
                        freshCount--; 
                        rottenSpread = true;
                    }
                }
            }

            if (rottenSpread)
                minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }
};