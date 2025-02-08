class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        for(int i = 0; i < ROWS; i++) {
            if(board[i][0] == 'O')
                dfs(i, 0, board);
            if(board[i][COLS - 1] == 'O')
                dfs(i, COLS - 1, board);
        }

        for(int j = 0; j < COLS; j++) {
            if(board[0][j] == 'O')
                dfs(0, j, board);
            if(board[ROWS - 1][j] == 'O')
                dfs(ROWS - 1, j, board);    
        }

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == 'O') 
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        if(board[row][col] != 'O') return;

        board[row][col] = '#';

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(auto [aRow, aCol] : directions) {
            int nextRow = aRow + row;
            int nextCol = aCol + col;

            if(isWithinBounds(nextRow, nextCol, ROWS, COLS) && board[nextRow][nextCol] == 'O')
                dfs(nextRow, nextCol, board);
        }

    }

    bool isWithinBounds(int row, int col, int ROWS, int COLS) {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
 };