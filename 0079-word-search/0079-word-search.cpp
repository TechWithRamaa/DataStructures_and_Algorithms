class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();

        if (word.size() > ROWS * COLS)
            return false;

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, visited, word, 0, board))
                        return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int i, int j, vector<vector<bool>>& visited, string& word,
             int index, vector<vector<char>>& board) {
        if (index == word.size())
            return true;

        int ROWS = board.size();
        int COLS = board[0].size();
        if (i < 0 || j < 0 || i >= ROWS || j >= COLS || visited[i][j] ||
            board[i][j] != word[index])
            return false;

        visited[i][j] = true;

        const vector<pair<int, int>> directions = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto [row, col] : directions) {
            int newRow = row + i;
            int newCol = col + j;
            if (dfs(newRow, newCol, visited, word, index + 1, board))
                return true;
        }
        visited[i][j] = false;

        return false;
    }
};