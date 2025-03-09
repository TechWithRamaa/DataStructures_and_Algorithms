class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},
                                           {'L', 50},  {'C', 100}, {'D', 500},
                                           {'M', 1000}};

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Check if we should subtract
            if (i < n - 1 && values[s[i]] < values[s[i + 1]]) {
                total -= values[s[i]]; // Subtract smaller value
            } else {
                total += values[s[i]]; // Add normally
            }
        }

        return total;
    }
};