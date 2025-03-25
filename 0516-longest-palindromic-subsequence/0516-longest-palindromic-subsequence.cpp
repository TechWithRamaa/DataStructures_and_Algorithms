class Solution {
public:
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