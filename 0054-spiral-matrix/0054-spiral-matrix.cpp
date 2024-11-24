class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> result;

        const int ROWS = matrix.size();
        const int COLUMNS = matrix[0].size();

        int top = 0, left = 0;
        int bottom = ROWS - 1, right = COLUMNS - 1;

        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int index = left; index <= right; index++)
                result.push_back(matrix[top][index]);
            top++;

            // Traverse downwards
            for (int index = top; index <= bottom; index++)
                result.push_back(matrix[index][right]);
            right--;

            // Check again in case boundaries crossed before reverse traveral

            // Traverse from right to left
            for (int index = right; index >= left && top <= bottom; index--)
                result.push_back(matrix[bottom][index]);
            bottom--;

            // Check again in case boundaries crossed before reverse traveral

            // Traverse upwards
            for (int index = bottom; index >= top && left <= right; index--)
                result.push_back(matrix[index][left]);
            left++;
        }

        return result;
    }
};