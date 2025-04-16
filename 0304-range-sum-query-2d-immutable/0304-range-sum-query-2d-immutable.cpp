class NumMatrix {
private:
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        prefixSum = vector<vector<int>>(M, vector<int>(N, 0));
        
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                int top = r > 0 ? prefixSum[r - 1][c] : 0;
                int left = c > 0 ? prefixSum[r][c - 1] : 0;
                int topLeft = r > 0 && c > 0 ? prefixSum[r - 1][c - 1] : 0;

                prefixSum[r][c] = matrix[r][c] + top + left - topLeft;
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
;