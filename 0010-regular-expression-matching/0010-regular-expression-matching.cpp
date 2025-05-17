class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.length(), N = p.length();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;

        // Initialize first row (empty string s)
        for (int j = 2; j <= N; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2]; // '*' cancels the char before it
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // one match
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // zero occurrence

                    // check one or more only if preceding char matches
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // more matches
                    }
                }
            }
        }

        return dp[M][N];
    }

    // Recursion + Memoization
    bool isMatch1(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return isMatch(s, p, 0, 0, dp);
    }

private:
    bool isMatch(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        // when pattern is completely matched, string should be exhausted
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch = false;
        if ((i < s.size() && (s[i] == p[j] || p[j] == '.')))
            firstMatch = true;

        if (((j + 1) < p.size()) && p[j + 1] == '*')
            dp[i][j] = isMatch(s, p, i, j + 2, dp) ||
                       (firstMatch && isMatch(s, p, i + 1, j, dp));
        else
            dp[i][j] = firstMatch && isMatch(s, p, i + 1, j + 1, dp);

        return dp[i][j];
    }
};