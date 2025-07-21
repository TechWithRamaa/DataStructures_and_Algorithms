class Solution {
public:
    /*
    Is there any valid way to break the string?
    Why do we explore all possible splits?
    
    Because:

    If one segmentation path fails, another segmentation may succeed.
    We don't know which words from the dictionary to pick at each step (multiple choices), 
    so we need to check all possible partitions.
    */

    // dp[i] = true if the substring s[0...i-1] can be segmented into valid words.
    // For every position i in s, we check all possible splits s[j...i-1] where 0 <= j < i.
    // If dp[j] == true and s[j...i-1] is in wordDict, then dp[i] = true.
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());

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