class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        prefixSum = vector<vector<int>>(ROWS, vector<int>(COLS, 0));

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                int top = i > 0 ? prefixSum[i - 1][j] : 0;
                int left = j > 0 ? prefixSum[i][j - 1] : 0;
                int topLeft = i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0;

                prefixSum[i][j] = matrix[i][j] + top + left - topLeft;
            } 
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int top = r1 > 0 ? prefixSum[r1 - 1][c2] : 0;
        int left = c1 > 0 ? prefixSum[r2][c1 - 1] : 0;
        int topLeft = r1 > 0 && c1 > 0 ? prefixSum[r1 - 1][c1 - 1] : 0;

        return prefixSum[r2][c2] - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */