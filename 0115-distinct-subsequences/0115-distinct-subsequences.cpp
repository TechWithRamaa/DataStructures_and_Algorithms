class Solution {
public:
    // Let dp[i][j] represent the number of distinct subsequences of s[0..i-1] that equals t[0..j-1]
    /*
    Transition:
    If s[i-1] == t[j-1], we have two options:

        Match this character: dp[i-1][j-1]
        Skip this character from s: dp[i-1][j]
        So: dp[i][j] = dp[i-1][j-1] + dp[i-1][j]    
    Else:
        We can only skip this character: dp[i][j] = dp[i-1][j]

    Base Case Initialization:
    dp[0][0] = 1 → Empty string matches empty string.
    dp[i][0] = 1 for all i → There's always 1 way to form an empty string t from any prefix of s: by deleting all characters.
    dp[0][j > 0] = 0 → You can't form a non-empty t from an empty s.
    */
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // base case
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return (int)dp[m][n];
    }
};