class Solution {
public:
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