class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ROWS = rooms.size();
        int COLS = rooms[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [nr, nc] : dir) {
                int nextR = nr + row;
                int nextC = nc + col;

                if (nextR >= 0 && nextR < ROWS && nextC >= 0 && nextC < COLS &&
                    rooms[nextR][nextC] == INT_MAX) {
                    rooms[nextR][nextC] = rooms[row][col] + 1;
                    q.push({nextR, nextC});
                }
            }
        }
    }
};