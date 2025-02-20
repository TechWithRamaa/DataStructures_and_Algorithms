class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int value =  c - 'A' + 1; // Convert 'A' to 1, 'B' to 2, ..., 'Z' to 26
            result = result * 26 + value; // Build the number in base 26
        }
        return result;
    }
};