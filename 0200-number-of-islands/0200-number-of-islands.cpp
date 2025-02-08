class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    numOfIslands += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return numOfIslands;
    }

private:

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto [newRow, newCol] : directions) {
            int possibleRow = newRow + row;
            int possibleCol = newCol + col;

            if(isWithinBoundary(possibleRow, possibleCol, grid) 
            && isLand(possibleRow, possibleCol, grid) 
            && !isVisitedAlready(possibleRow, possibleCol, visited)) {
                dfs(possibleRow, possibleCol, grid, visited);
            }
        }
    }

    bool isLand(int possibleRow, int possibleCol, vector<vector<char>>& grid) {
        return grid[possibleRow][possibleCol] == '1'; 
    }

    bool isVisitedAlready(int possibleRow, int possibleCol, vector<vector<bool>>& visited) {
        return visited[possibleRow][possibleCol] == true;
    }

    bool isWithinBoundary(int possibleRow, int possibleCol, vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        return possibleRow >= 0 && possibleRow < ROWS && possibleCol >= 0 && possibleCol < COLS;
    }
};