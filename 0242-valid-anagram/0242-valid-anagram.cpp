class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
    
    // Approach - Frequency
    // TC ~ O ( n )
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int count : freq) {
            if (count != 0)
                return false;
        }

        return true;
    }
};