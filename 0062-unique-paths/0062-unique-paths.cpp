/* Recursion ~ O ( 2 ^ n )
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1; 

        int noOfLeftPaths = uniquePaths(m, n - 1);
        int noOfTopPaths = uniquePaths(m-1, n);

        return noOfLeftPaths + noOfTopPaths;
    }
};
*/

class Solution {
public:
    // Top-Down
     int solveR(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0)
            return 1;

        if (dp[m][n] != -1) 
            return dp[m][n]; 

        int noOfLeftPaths = solveR(m, n - 1, dp);
        int noOfTopPaths = solveR(m - 1, n, dp);

        return dp[m][n] = noOfLeftPaths + noOfTopPaths;
    }

    int uniquePathsR(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, -1));  
        return solveR(m - 1, n - 1, dp);
    }

    /* Bottom-Up
    
    dp[i][j] = the number of unique paths to reach cell (i,j)
    
    To reach (i,j), we could have come:
    From the top: (i-1, j)
    From the left: (i, j-1)

    dp[i][j]=dp[i−1][j]+dp[i][j−1]
    */

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base cases: first row and first column
        for (int j = 0; j < n; j++) 
            dp[0][j] = 1; // There is only 1 way to reach any cell in the first row – by moving right from (0,0)
        for (int i = 0; i < m; i++) 
            dp[i][0] = 1; // There is only 1 way to reach any cell in the first column – by moving down from (0,0)

        // Fill the remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};