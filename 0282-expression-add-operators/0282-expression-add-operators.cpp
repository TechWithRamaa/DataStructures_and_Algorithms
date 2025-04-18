class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        dfs(num, target, 0, 0, 0, "", result);
        return result;
    }

private:
    void dfs(const string& num, int target, int index, long eval,
     long prevOperand, string path, vector<string>& result) {

        if (index == num.size()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            // Avoid numbers with leading zero
            // checks if it is a single digit number or 
            // multi-digit number
            if (i != index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

            if (index == 0) {
                // First number, start without any operator
                dfs(num, target, i + 1, currNum, currNum, currStr, result);
            } else {
                // +
                dfs(num, target, i + 1, eval + currNum, currNum, path + "+" + currStr, result);
                // -
                dfs(num, target, i + 1, eval - currNum, -currNum, path + "-" + currStr, result);
                // *
                dfs(num, target, i + 1,
                    eval - prevOperand + prevOperand * currNum,
                    prevOperand * currNum,
                    path + "*" + currStr,
                    result);
            }
        }
    }
};
