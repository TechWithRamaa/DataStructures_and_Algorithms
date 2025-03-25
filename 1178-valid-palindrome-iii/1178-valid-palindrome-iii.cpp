class Solution {
public:
    // The solution is extended from Longest Palindrome Subsequence problem
    // LC - 516
    // TC ~ O ( N * N )
    bool isValidPalindrome(string s, int k) {
        int lps = longestPalindromeSubsequence(s);
        return s.size() - lps <= k;
    }

private:
    int longestPalindromeSubsequence(string s) {
        int N = s.size();

        vector<vector<int>> dp(N, vector<int>(N, 0));

        for(int i = 0; i < N; i++) 
            dp[i][i] = 1;

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