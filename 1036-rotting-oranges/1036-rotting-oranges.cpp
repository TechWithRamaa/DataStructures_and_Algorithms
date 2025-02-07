class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int freshOrangesCount = 0;
        int minMinutesTaken = 0;

        queue<pair<int, int>> rottenQueue;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOrangesCount += 1;
                }
            }
        }

        if(!freshOrangesCount) return 0;

        vector<pair<int, int>> adjacentDirections = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!rottenQueue.empty()) {
            int numberOfRottenOrangesAtCurrentLevel = rottenQueue.size();
            bool rottedAnyOrange = false;

            for(int i = 0; i < numberOfRottenOrangesAtCurrentLevel; i++) {
                auto [rottenRow, rottenColumn] = rottenQueue.front();
                rottenQueue.pop();

                for(auto& possibleNextCell : adjacentDirections) {
                    int newRow = possibleNextCell.first + rottenRow;
                    int newCol = possibleNextCell.second + rottenColumn;

                    if(isNextMoveWithinBoundary(newRow, newCol, grid) && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshOrangesCount--;
                        rottedAnyOrange = true;
                        rottenQueue.push({newRow, newCol});
                    }
                }
            }
            
            if (rottedAnyOrange) minMinutesTaken += 1;
        }

        return freshOrangesCount == 0 ? minMinutesTaken : -1;
    }

private:
    bool isNextMoveWithinBoundary(int i, int j, vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        return i >= 0 && i < ROWS && j >= 0 && j < COLS;
    }
};