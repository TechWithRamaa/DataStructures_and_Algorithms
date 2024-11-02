class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return; // Early return if the matrix is empty
        
        const int ROWS = matrix.size();
        const int COLUMNS = matrix[0].size();

        bool isFirstRowHasZero = false;
        bool isFirstColumnHasZero = false;

        // Check if the first row has any zero
        for (int i = 0; i < COLUMNS; i++) {
            if (matrix[0][i] == 0) {
                isFirstRowHasZero = true; 
                break;
            }
        }

        // Check if the first column has any zero
        for (int i = 0; i < ROWS; i++) {
            if (matrix[i][0] == 0) {
                isFirstColumnHasZero = true; 
                break;
            }
        }

        // Use the first row and first column as markers
        for (int i = 1; i < ROWS; i++) {
            for (int j = 1; j < COLUMNS; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row
                    matrix[0][j] = 0; // Mark the column
                }
            }
        }

        // Set the cells to zero based on markers
        for (int i = 1; i < ROWS; i++) {
            for (int j = 1; j < COLUMNS; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the first column to zero if needed
        if (isFirstColumnHasZero) {
            for (int i = 0; i < ROWS; i++) {
                matrix[i][0] = 0;
            }
        }

        // Set the first row to zero if needed
        if (isFirstRowHasZero) {
            for (int i = 0; i < COLUMNS; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
