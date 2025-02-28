class Solution {
public:
    // Approach 1
    // DP (LCS problem)
    // TC ~ O ( n ^ 2 )
    // TLE at 29/49
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 1: Compute LCS using DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Build SCS using LCS information
        int i = m, j = n;
        string scs;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1];
                i--;
            } else {
                scs += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters from str1 and str2
        while (i > 0)
            scs += str1[--i];
        while (j > 0)
            scs += str2[--j];

        reverse(scs.begin(), scs.end());
        return scs;
    }

    // Approach 2
    // Recursion
    // TC ~ O ( Exponential )
    // TLE at 29/49
    string shortestCommonSupersequence2(string str1, string str2) {
        if (str1.empty())
            return str2;
        if (str2.empty())
            return str1;

        if (str1[0] == str2[0])
            return str1[0] +
                   shortestCommonSupersequence(str1.substr(1), str2.substr(1));

        string option1 =
            str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
        string option2 =
            str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

        return option1.size() < option2.size() ? option1 : option2;
    }

    // Approach 3
    // Recursion + Memozation
    // TC ~ O ( Exponential )
    // TLE at 46/49
    string shortestCommonSupersequence3(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<string>> dp;
        dp.assign(m + 1, vector<string>(n + 1, ""));
        return scs_memo(str1, str2, m, n, dp);
    }

private:
    string scs_memo(string str1, string str2, int i, int j,
                    vector<vector<string>>& dp) {
        if (i == 0)
            return str2.substr(0, j);
        if (j == 0)
            return str1.substr(0, i);

        if (!dp[i][j].empty())
            return dp[i][j];

        if (str1[i - 1] == str2[j - 1])
            return dp[i][j] =
                       scs_memo(str1, str2, i - 1, j - 1, dp) + str1[i - 1];

        string option1 = scs_memo(str1, str2, i - 1, j, dp) + str1[i - 1];
        string option2 = scs_memo(str1, str2, i, j - 1, dp) + str2[j - 1];

        return dp[i][j] = (option1.size() < option2.size()) ? option1 : option2;
    }
};