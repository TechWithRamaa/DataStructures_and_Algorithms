class Solution {
    public void rotate(int[][] matrix) {
        final int noOfRows = matrix.length;
        final int noOfCols = matrix[0].length;

        transpose(matrix, noOfRows, noOfCols);
        reverse(matrix, noOfRows, noOfCols);
    }

    private void transpose(final int[][] matrix, final int rows, final int cols) {
        for(int i = 0; i < rows - 1; i++) {
            for(int j = i+1; j < cols; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    private void reverse(final int[][] matrix, final int rows, final int cols) {
        for(int i = 0; i < rows; i++) {
            int left = 0;
            int right = cols-1;

             while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;
            }
        }
    }
}