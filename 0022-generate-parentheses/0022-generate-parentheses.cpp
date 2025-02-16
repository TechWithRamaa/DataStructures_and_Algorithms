class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        generateParenthesis(n, n, current, result);

        return result;
    }

private:
    void generateParenthesis(int noOfOpen, int noOfClose, string current,
                             vector<string>& result) {
        if (noOfClose == 0) {
            result.push_back(current);
            return;
        }

        if (noOfOpen > 0)
            generateParenthesis(noOfOpen - 1, noOfClose, current + "(", result);

        if (noOfClose > noOfOpen)
            generateParenthesis(noOfOpen, noOfClose - 1, current + ")", result);
    }
};