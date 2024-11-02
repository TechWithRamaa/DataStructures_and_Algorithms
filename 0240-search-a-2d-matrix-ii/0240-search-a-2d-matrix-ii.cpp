class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
        const int NO_OF_ROWS = matrix.size();
        const int NO_OF_COLS = matrix[0].size();

        int x = 0, y = NO_OF_COLS - 1;

        while(x < NO_OF_ROWS && y >= 0) {
            if(target == matrix[x][y]) return true;
            else if (target > matrix[x][y]) x++;
            else if (target < matrix[x][y]) y--;
        }
        
        return false;
    }
};