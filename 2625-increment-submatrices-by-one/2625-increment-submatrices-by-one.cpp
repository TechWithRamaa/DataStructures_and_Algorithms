class Solution {
public:
    vector<vector<int>> rangeAddQueries(const int N, const vector<vector<int>>& queries) {
        // Initialize a difference matrix
        vector<vector<int>> diff(N + 1, vector<int>(N + 1, 0));

        // Process each query and follow  2D difference array technique
        for (const auto& q : queries) {
            int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
            
            diff[row1][col1] += 1;  
            
            if (row2 + 1 < N)  diff[row2 + 1][col1] -= 1;
            
            if (col2 + 1 < N)  diff[row1][col2 + 1] -= 1;
            
            if (row2 + 1 < N && col2 + 1 < N)  diff[row2 + 1][col2 + 1] += 1;
        }

        // Build the resultant matrix using (Row-Wise Prefix sum and Column-wise Prefix sum)
        vector<vector<int>> result(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i > 0)  diff[i][j] += diff[i - 1][j];

                if (j > 0)  diff[i][j] += diff[i][j - 1];

                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];

                result[i][j] = diff[i][j];
            }
        }

        return result;
    }
};