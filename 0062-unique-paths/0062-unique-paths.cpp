// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1) return 1;  // Base case
//             return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);  // Recursion
//     }
// };

class Solution {
public:
     int solve(int m, int n, vector<vector<int>>& dp) {
        if (m == 1 || n == 1) return 1;  // Base case
        if (dp[m][n] != -1) return dp[m][n];  // If already computed, return it

        return dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m + 1, vector<int>(n + 1, -1));  
        return solve(m, n, dp);
    }
};