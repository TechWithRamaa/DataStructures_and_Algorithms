class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(matrix, mid, n);

            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1; // all elements in this column above are ≤ mid
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
};

/*
    Perform binary search between the smallest and largest values in the matrix.
    For a mid value, count how many elements in the matrix are ≤ mid.
    If the count is less than k, move right.
    Else, move left.
*/