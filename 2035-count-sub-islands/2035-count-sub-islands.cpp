class Solution {
private:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x,
             int y, bool& isSubIsland) {

        if (grid1[x][y] == 0)
            isSubIsland = false;

        grid2[x][y] = 0;

        int possibleXDirections[] = {1, -1, 0, 0};
        int possibleYDirections[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newX = x + possibleXDirections[i];
            int newY = y + possibleYDirections[i];

            if (isWithInRange(newX, newY, grid2.size(), grid2[0].size()) && grid2[newX][newY] == 1)
                dfs(grid1, grid2, newX, newY, isSubIsland);
        }
    }

    bool isWithInRange(const int newX, const int newY, const int ROWS, const int COLS) {
        return (newX >= 0 && newX < ROWS) && (newY >= 0 && newY < COLS);
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        const int ROWS = grid2.size(), COLS = grid2[0].size();
        int count = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;
                    dfs(grid1, grid2, i, j, isSubIsland);

                    if (isSubIsland)
                        ++count;
                }
            }
        }

        return count;
    }
};