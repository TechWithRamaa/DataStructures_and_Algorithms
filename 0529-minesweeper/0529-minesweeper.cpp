class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        if (board[click[0]][click[1]] != 'E') {
            return board;
        }

        queue<pair<int, int>> q;
        q.push({click[0], click[1]});

        const vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1},
                                                   {1, 1},  {1, 0},  {1, -1},
                                                   {0, -1}, {-1, -1}};
        int M = board.size();
        int N = board[0].size();

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            int mineCountAtCurrentLevel = 0;
            vector<pair<int, int>> neighbors;

            for (auto [pr, pc] : directions) {
                int nr = pr + row;
                int nc = pc + col;

                if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                    if (board[nr][nc] == 'M') {
                        mineCountAtCurrentLevel++;
                    }
                    neighbors.push_back({nr, nc});
                }
            }

            if (mineCountAtCurrentLevel > 0) {
                board[row][col] = mineCountAtCurrentLevel + '0';
            } else {
                board[row][col] = 'B';

                for(auto [nr, nc] : neighbors) {
                     if (board[nr][nc] == 'E') {
                        board[nr][nc] = 'B';
                        q.push({nr, nc});
                    }
                }
            }
        }

        return board;
    }
};