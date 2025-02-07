class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if(grid[0][0] == 1 || grid[ROWS - 1][COLS - 1] == 1) return -1;

        vector<pair<int, int>> adjacentCells = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS));
        queue<pair<int, int>> iNodesQueue;
        iNodesQueue.push({0, 0});
        visited[0][0] = 1;

        int steps = 1;

        while(!iNodesQueue.empty()) {
            int size = iNodesQueue.size();

            for(int i = 0; i < size; i++) {
                auto [r, c] = iNodesQueue.front();
                iNodesQueue.pop();

                if(r == ROWS - 1 && c == COLS - 1) return steps;

                for(auto [newRow, newCol] : adjacentCells) {
                    int possibleRow = r + newRow;
                    int possibleCol = c + newCol;

                    if(isNextMoveWithinBoundary(possibleRow, possibleCol, grid)
                     && !isNextCellAlreadyVisited(possibleRow, possibleCol, visited)
                     && isClearCell(possibleRow, possibleCol, grid)) {
                        iNodesQueue.push({possibleRow, possibleCol});
                        visited[possibleRow][possibleCol] = true;
                    }
                }
            }
            steps += 1;
        } 

        return -1;  
    }
private:
    bool isNextMoveWithinBoundary(int possibleRow, int possibleCol, vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        return possibleRow >= 0 && possibleRow < ROWS && possibleCol >= 0 && possibleCol < COLS;
    }

    bool isNextCellAlreadyVisited(int possibleRow, int possibleCol, vector<vector<bool>>& visited) {
        return visited[possibleRow][possibleCol];
    }

     bool isClearCell(int possibleRow, int possibleCol, vector<vector<int>>& grid) {
        return grid[possibleRow][possibleCol] == 0;
    }
};