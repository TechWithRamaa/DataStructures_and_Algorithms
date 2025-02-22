class TicTacToe {
private:
    int n;
    vector<int> rows, cols;
    int diagonals, antiDiagonals;
public:
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0), diagonals(0), antiDiagonals(0) {
        
    }
    
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;

        rows[row] += add;
        cols[col] += add;

        if(row == col) {
            diagonals += add;
        }

        if(row + col == n - 1) {
            antiDiagonals += add;
        }

        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonals) == n || abs(antiDiagonals) == n)
            return player;
        else 
            return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */