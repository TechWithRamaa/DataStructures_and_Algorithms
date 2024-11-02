class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }

    void transpose(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        for(int i = 0; i < N - 1; i++) {
            for(int j = i + 1; j < N; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void reverse(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        for(int i = 0; i < N; i++) {
            int left = 0,  right = N - 1;

            while(left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }
    }
};