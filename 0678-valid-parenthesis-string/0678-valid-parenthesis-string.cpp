class Solution {
public:
    // Greedy Bounds
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(const auto& ch : s) {
            if(ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low = max(0, low - 1);
                high--;
            } else {
                low = max(0, low - 1);
                high++;
            }

            if(high < 0) // too many unmatched ')' parentheses
                return false;
        }

        return low == 0;
    }
};