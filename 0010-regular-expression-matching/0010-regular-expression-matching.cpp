class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return isMatch(s, p, 0, 0, dp);
    }
private:
    bool isMatch(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        // when pattern is completely matched, string should be exhausted
        if(j == p.size())
            return i == s.size();
        
        if(dp[i][j] != -1)
            return dp[i][j];
    
        bool firstMatch = false;
        if((i < s.size() && (s[i] == p[j] || p[j] == '.')))
            firstMatch = true;

        if(((j + 1) < p.size()) && p[j + 1] == '*') 
            dp[i][j] = isMatch(s, p, i, j + 2, dp) || (firstMatch && isMatch(s, p, i + 1, j, dp));
        else 
            dp[i][j] = firstMatch && isMatch(s, p, i + 1, j + 1, dp);

         return dp[i][j];
    }
};