class Solution {
public:
    // approach 1 - BruteForce ~ O (n ^ 2)
    // approach 2 - Binary Search on Each Row ~ O ( n * log m) 
    // approach 3 - Binary Search on Specifc Row ~ O ( n + log m) 
    // approach 4 - Saddle Back Search ~ O ( m + n )
    bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
        const int NO_OF_ROWS = matrix.size();
        const int NO_OF_COLS = matrix[0].size();

        // Saddleback search - Search Space Reduction 
        int x = 0, y = NO_OF_COLS - 1;

        while(x < NO_OF_ROWS && y >= 0) {
            if(target == matrix[x][y])
                return true;
            else if (target > matrix[x][y]) 
                x++; // search in increasing side
            else if (target < matrix[x][y]) 
                y--; // search in decreasing side
        }
        
        return false;
    }
};