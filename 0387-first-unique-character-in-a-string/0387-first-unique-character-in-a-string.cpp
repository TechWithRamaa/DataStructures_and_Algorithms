class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Find the first character with count 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1)
                return i;
        }

        return -1;
    }
};