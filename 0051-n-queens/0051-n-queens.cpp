class Solution {
public:
    vector<vector<string>> solveNQueens(const int N) {
        vector<vector<string>> possibleArrangements;
        vector<vector<char>> board(N, vector<char>(N, '.')); // Initialize the board

        solveNQueens(0, possibleArrangements, board, N);

        return possibleArrangements;
    }
private:
    void solveNQueens(int column, vector<vector<string>>& possibleArrangements, vector<vector<char>>& board, const int& N) {
        // Goal: If we've placed queens in all columns, add the arrangement to the result
        if (column == N) {
            possibleArrangements.push_back(constructBoard(board));
            return;
        }

        // Try all rows for the current column
        for (int row = 0; row < N; row++) {
            if (board[row][column] == '.' && isValidCell(row, column, board, N)) {
                board[row][column] = 'Q';  // Make a choice (place the queen)
                solveNQueens(column + 1, possibleArrangements, board, N);  // Solve the sub-problem for the next column
                board[row][column] = '.';  // Undo the choice (backtrack)
            }
        }
    }

    bool isValidCell(const int& row, const int& column, const vector<vector<char>>& board, const int& N) {
        // Check if there's a Queen in the current row's left side
        for (int i = column; i >= 0; i--) {
            if (board[row][i] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check bottom-left diagonal
        for (int i = row, j = column; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    vector<string> constructBoard(const vector<vector<char>>& board) {
        vector<string> boardAsList;
        
        for (const auto& row : board) {
            string rowStr(row.begin(), row.end());  // Convert the row to a string
            boardAsList.push_back(rowStr);
        }

        return boardAsList;
    }
};
