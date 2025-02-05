class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, n, "", result);
        return result;
    }

private:
    void generateParenthesis(int open, int close, string current, vector<string>& result) {
        if(open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if(open > 0) {
            generateParenthesis(open - 1, close, current + "(", result);
        }

        if(close > open) {
            generateParenthesis(open, close - 1, current + ")", result);
        }
            
    }
};