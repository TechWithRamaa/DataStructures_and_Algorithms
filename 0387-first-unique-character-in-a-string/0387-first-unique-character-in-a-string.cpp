class Solution {
public:
    // Approach 1 -> TC ~ O ( n )
    // Using HashMap or Vector as Frequence Map
    int firstUniqChar1(string s) {
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

    // Approach 2 -> TC ~ O ( n )
    // Queue based, most suited for dynamic stream of data
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<int> q;

        // Process characters
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            freq[c - 'a']++;
            q.push(i);

            // Remove non-unique elements
            while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};