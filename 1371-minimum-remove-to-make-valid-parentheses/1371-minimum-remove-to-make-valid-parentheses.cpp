class Solution {
public:
    // Approach 1 
    // Using Stack to mark ) or ( as invalid
    // Constructing result by eliminating invalid parenthesis
    // TC ~ O ( N ) and SC ~ O ( N )
    string minRemoveToMakeValid(string s) {
        stack<int> openParentheses;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                openParentheses.push(i);
            } else if (s[i] == ')') {
                if(!openParentheses.empty()) {
                    openParentheses.pop();
                } else {
                    s[i] = '#';
                }
            }
        }

        while(!openParentheses.empty()) {
            s[openParentheses.top()] = '#';
            openParentheses.pop();
        }

        string validString;
        for(char c : s) {
            if(c != '#') {
                validString += c;
            }
        }

        return validString;
    }
};