class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for(char c: s) {
            freq[c - 'a']++;
        }

        for(char c: t) {
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};