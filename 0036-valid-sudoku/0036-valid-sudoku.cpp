class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        unordered_set<string> alreadyPresent;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == '.')
                    continue;

                char c = board[i][j];
                string rowKey = string(1, c) + "@row" + to_string(i);
                string colKey = string(1, c) + "@col" + to_string(j);
                string boxKey =
                    string(1, c) + "@box" + to_string(i / 3) + to_string(j / 3);

                if (alreadyPresent.count(rowKey) ||
                    alreadyPresent.count(colKey) ||
                    alreadyPresent.count(boxKey)) {
                    return false; // c already present in one of the 3 attributes
                }

                alreadyPresent.insert(rowKey);
                alreadyPresent.insert(colKey);
                alreadyPresent.insert(boxKey);
            }
        }

        return true;
    }
};