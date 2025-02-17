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
     int solve(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0)
            return 1;

        if (dp[m][n] != -1) 
            return dp[m][n]; 

        int noOfLeftPaths = solve(m, n - 1, dp);
        int noOfTopPaths = solve(m - 1, n, dp);

        return dp[m][n] = noOfLeftPaths + noOfTopPaths;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, -1));  
        return solve(m - 1, n - 1, dp);
    }
};