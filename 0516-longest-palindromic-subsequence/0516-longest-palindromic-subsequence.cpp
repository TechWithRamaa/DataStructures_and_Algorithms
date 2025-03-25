class Solution {
public:
    // Approach 1 -> Top Down -> Recursion + Memoization - Inefficient

    // Approach 2 -> Bottom Up -> Filling DP array as if 
    // we are expanding from the center of the palindrome 
    // Dynamic Programming - Nested Loops - Tabulation
    // TC ~ O ( N ^ 2)
    // Very natural to fill the array if we think of core palindrome property
    // of expanding the center and finding for each length wise and skipping 
    // few characters if it dont match because we are fining palidromic sub-sequence

    // Approach 3 -> Bottom Up -> 
    // Dynamic Programming - Nested Loops - Space Optimization
    // TC ~ O ( N ^ 2)
    
    int longestPalindromeSubseq(string s) {
        int N = s.length();

        vector<vector<int>> dp(N, vector<int>(N, 0));

        // len = 1 palindromes are found
        for(int i = 0; i < N; i++)
            dp[i][i] = 1;

        // running the loop to find the palindromes of length above 2
        for(int len = 2; len <= N; len++) {
            for(int i = 0; i <= N - len; i++) {
                int j = i + len - 1;

                if(s[i] == s[j]) 
                    dp[i][j] = 2 + dp[i+1][j-1]; 
                else 
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    
            }
        }

        return dp[0][N-1];
    }
};