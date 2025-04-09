class Solution {
public:
    // Greedy 
    // DP is not needed as we just need to check exactly 1 distance away
    // and return TRUE or FALSE
    bool isOneEditDistance(string s, string t) {
        int M = s.size(), N = t.size();

        if(M > N)
            return isOneEditDistance(t, s); // ensure s is always shorter or equal

        if(M + 1 < N)
            return false;

        for(int i = 0; i < M; i++) {
            if(s[i] != t[i]) {
                if(M == N)
                    return s.substr(i + 1) == t.substr(i + 1); // replacement
                else
                    return s.substr(i) == t.substr(i + 1);     // insertion
            }
        }

        // if all previous characters are the same,
        // check if t has exactly one extra character
        return (M + 1 == N);
    }
};
