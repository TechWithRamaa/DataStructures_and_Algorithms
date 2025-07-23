class Solution {
public:
    // Approach 1
    // Using Stack to mark ) or ( as invalid
    // Constructing result by eliminating invalid parenthesis
    // TC ~ O ( N ) and SC ~ O ( N )
    string minRemoveToMakeValid1(string s) {
        stack<int> openParentheses;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openParentheses.push(i);
            } else if (s[i] == ')') {
                if (!openParentheses.empty()) {
                    openParentheses.pop();
                } else {
                    s[i] = '#';
                }
            }
        }

        while (!openParentheses.empty()) {
            s[openParentheses.top()] = '#';
            openParentheses.pop();
        }

        string validString;
        for (char c : s) {
            if (c != '#') {
                validString += c;
            }
        }

        return validString;
    }

    // Approach 2
    // Greedy Approach
    // TC ~ O ( N + N ) Two pass
    string minRemoveToMakeValid(string s) {
        string intermediate;
        string finalResult;

        // removes extra )
        int openCount = 0;
        for (char c : s) {
            if (c == '(')
                openCount++;

            if (c == ')') {
                if (openCount == 0)
                    continue;

                openCount--;
            }

            intermediate.push_back(c);
        }

        // cout << intermediate << endl;

        // removes extra (
        int closedCount = 0;
        for (int i = intermediate.size() - 1; i >= 0 ; i--) {
            if (intermediate[i] == ')')
                closedCount++;

            if (intermediate[i] == '(') {
                if (closedCount == 0)
                    continue;

                closedCount--;
            }

            finalResult.push_back(intermediate[i]);            
        }

        // cout << finalResult;

        reverse(finalResult.begin(), finalResult.end());;
        return finalResult;
    }
};