class Solution {
public:
    vector<int> findBall(const vector<vector<int>>& grid) {
        const int board = grid[0].size();
        vector<int> result(board, 0);

        for (int j = 0; j < board; j++)
            result[j] = simulateBallPath(grid, j);

        return result;
    }

private:
    int simulateBallPath(const vector<vector<int>> grid,
                         const int startColumn) {
        int m = grid.size();
        int n = grid[0].size();

        int currentColumn = startColumn;
        for (int row = 0; row < m; row++) {
            if (grid[row][currentColumn] == 1) {
                if (currentColumn == n - 1 ||
                    grid[row][currentColumn + 1] == -1)
                    return -1;

                currentColumn++;
            } else {
                if (currentColumn == 0 || grid[row][currentColumn - 1] == 1)
                    return -1;

                currentColumn--;
            }
        }

        return currentColumn;
    }
};