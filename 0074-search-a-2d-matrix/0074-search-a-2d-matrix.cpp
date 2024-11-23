class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
        const int M = matrix.size();
        const int N = matrix[0].size();

        int left = 0, right = M * N - 1;    // Logically visualizing 2D matrix as 1D array

        while (left <= right) {
            // Divide And Conquer technique
            int mid = left + (right - left) / 2;
            
            // Convert logical 1D index to actual 2D matrix indices
            int midElement = matrix[mid / N][mid % N]; 

            if (midElement == target)
                return true;
            else if (midElement < target)
                left = mid + 1; // TARGET could be in right half
            else 
                right = mid - 1; // TARGET could be in left half
        }

        return false;
    }
};