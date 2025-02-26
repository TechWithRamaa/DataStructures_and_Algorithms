class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // Simply add 1 if it's not 9
                return digits;
            }
            digits[i] = 0; // If it's 9, set to 0 and continue
        }

        // If all were 9s, we need a new leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};