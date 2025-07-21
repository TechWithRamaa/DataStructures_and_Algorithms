class Solution {
public:
    // dp[i] = number of ways to decode substring s[0..i-1] (the first i characters).
    int numDecodings(string s) {
        int N = s.size();
        
        if(N == 0 || s[0] == '0')
            return 0;

        vector<int> dp(N + 1, 0);
        dp[0] = 1; // base: empty string
        dp[1] = 1; // base: single character - actual first character at i - 1
        
        for(int i = 2; i <= N; i++) {
            if(s[i-1] != '0') 
                dp[i] += dp[i - 1];
            
            int twoDigit = stoi(s.substr(i-2, 2));

            if(twoDigit >= 10 && twoDigit <= 26) 
                dp[i] += dp[i-2];
        }

        return dp[N];
    }
};