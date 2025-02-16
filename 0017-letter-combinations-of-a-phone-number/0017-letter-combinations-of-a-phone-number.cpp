class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<char, string> layoutMap = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> result;
        string current;
        letterCombinations(current, 0, result, digits, layoutMap);
        return result;
    }

private:
    void letterCombinations(string current, int i, vector<string>& result,
                            string& digits,
                            unordered_map<char, string>& layout) {
        // termination
        if (i == digits.length()) {
            result.push_back(current);
            return;
        }

        // explore - by including
        // backtrack
        // explore - by excluding

        for (char c : layout[digits[i]]) {
            letterCombinations(current + c, i + 1, result, digits, layout);
        }
    }
};