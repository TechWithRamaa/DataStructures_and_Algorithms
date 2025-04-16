class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());

        // dp[i] = can we form s[0..i-1] using words from dict
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; 

        int N = s.size();
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && dictionary.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};