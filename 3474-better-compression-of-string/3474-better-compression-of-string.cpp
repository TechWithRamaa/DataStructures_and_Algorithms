class Solution {
public:
    string betterCompression(string s) {
        map<char, int> freq; // ordered_map that maintains sorted order on the key or chars

        int i = 0, n = s.length();
        while (i < n) {
            char ch = s[i++];
            int count = 0;

            // Read the number part (can be multiple digits)
            while (i < n && isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }

            freq[ch] += count;
        }

        // Build final compressed string
        string result;
        for (auto& [ch, count] : freq) {
            result += ch + to_string(count);
        }

        return result;
    }
};