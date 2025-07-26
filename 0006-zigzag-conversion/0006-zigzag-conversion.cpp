class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s; // edge case

        vector<string> rows(min(numRows, (int)s.size()));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows)
            result += row;

        return result;
    }
};