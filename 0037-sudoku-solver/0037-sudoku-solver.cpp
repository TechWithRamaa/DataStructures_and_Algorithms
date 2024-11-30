class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, board.size());
    }
private:
    bool solveSudoku(vector<vector<char>>& board, const int N) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValidChoice(row, col, digit, board, N)) {
                            board[row][col] = digit;  // Making a choice

                            if (solveSudoku(board, N))  // Recursion | Solving next sub-problem
                                return true;

                            board[row][col] = '.';  // Undo making choice
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidChoice(const int& row, const int& column, const char& digit, const vector<vector<char>>& board, const int& N) {
        for (int i = 0; i < N; i++) {
            // Checking for digit in the same row and column
            if (board[row][i] == digit || board[i][column] == digit) 
                return false;

            // Checking for digit in the same 3x3 sub-grid
            int subGridRow = 3 * (row / 3) + i / 3;
            int subGridCol = 3 * (column / 3) + i % 3;
            
            if (board[subGridRow][subGridCol] == digit) 
                return false;
        }
        return true;
    }
};