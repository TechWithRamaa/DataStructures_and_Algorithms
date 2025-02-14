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

        for (auto [aRow, aCol] : directions) {
            int nextRow = aRow + row;
            int nextCol = aCol + col;

            if(isWithinBoundary(nextRow, nextCol, grid) 
            && isLand(nextRow, nextCol, grid) 
            && !isVisitedAlready(nextRow, nextCol, visited)) {
                dfs(nextRow, nextCol, grid, visited);
            }
        }
    }

    bool isLand(int row, int col, vector<vector<char>>& grid) {
        return grid[row][col] == '1'; 
    }

    bool isVisitedAlready(int row, int col, vector<vector<bool>>& visited) {
        return visited[row][col] == true;
    }

    bool isWithinBoundary(int row, int col, vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
};