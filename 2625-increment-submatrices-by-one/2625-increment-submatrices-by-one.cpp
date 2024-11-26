class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Initialize a difference array
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        // Step 2: Process each query
        for (const auto& q : queries) {
            int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
            diff[row1][col1] += 1;
            if (col2 + 1 < n)
                diff[row1][col2 + 1] -= 1;
            if (row2 + 1 < n)
                diff[row2 + 1][col1] -= 1;
            if (row2 + 1 < n && col2 + 1 < n)
                diff[row2 + 1][col2 + 1] += 1;
        }

        // Step 3: Build the resultant matrix using prefix sums
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    diff[i][j] += diff[i - 1][j];
                if (j > 0)
                    diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0)
                    diff[i][j] -= diff[i - 1][j - 1];
                result[i][j] = diff[i][j];
            }
        }

        return result;
    }
};