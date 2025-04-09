class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int M = s.size(), N = t.size();

        if(M == 0 && N == 0)
            return false;
        
        if(M > N)
            return isOneEditDistance(t, s);
        
        if(M == 0 && N == 1)
            return 1;
        
        // smaller string differs by 2 or more edits
        // so short-circuit & return false
        if(M + 1 < N)
            return false;

        for(int i = 0; i < M; i++) {
            if(s[i] != t[i]) {
                if(M == N)
                    return s.substr(i + 1) == t.substr(i + 1); 
                else 
                    return s.substr(i) == t.substr(i + 1);
            }
        }

        return M + 1 == N;
    }
};