class Solution {
public:
    /*
    ✅ Problem Summary
    Given an m x n board with 'X' and 'O', capture all regions that are surrounded by 'X'.
    A region is captured if it is completely surrounded by 'X' on all sides.
    Captured regions should be changed from 'O' to 'X'.

    \U0001f50d Intuition:
    Only 'O's connected to the border are safe (can’t be captured).

    All other 'O's are surrounded and should be flipped to 'X'.

    ✅ Steps:
    Traverse the borders (1st row, last row, 1st col, last col).
    For every 'O' on the border, start DFS/BFS to mark it and all connected 'O's as safe (let's mark them 'S').

    After traversal:
        Flip all unmarked 'O' → 'X' (they are surrounded).
        Flip all 'S' back to 'O'.
    */
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
                if(board[i][j] == 'O') // unmarked O's are unsafe
                    board[i][j] = 'X'; // converted into surrounded enemy regions
                if(board[i][j] == '#') // marked O's are safe
                    board[i][j] = 'O'; // remains as safe land
            }
        }
    }

private:
    // DFS that extends neighbor Os 
    void dfs(int row, int col, vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        //if(board[row][col] != 'O') return; // prune - no need to explore X 

        board[row][col] = '#'; // mark as Safe

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