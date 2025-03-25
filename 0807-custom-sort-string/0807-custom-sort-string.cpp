class Solution {
public:
    string customSortString(string order, string s) {
        // Count frequency of characters in s
        unordered_map<char, int> freq;
        for (char ch : s) 
            freq[ch]++;

        string result;

        // Append characters in `order` first, preserving frequency
        for (char ch : order) {
            if (freq.count(ch)) {
                result.append(freq[ch], ch); // Append ch `freq[ch]` times
                freq.erase(ch);              // Remove from map once processed
            }
        }

        // Append remaining characters from `s`
        for (auto& [ch, count] : freq) 
            result.append(count, ch); // Append remaining characters

        return result;
    }
};