class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for(char current : s) {
            if(current == '(' || current == '[' || current == '{') {
                parentheses.push(current);
            } else if (current == ')' || current == ']' || current == '}') {
                if(parentheses.empty())
                  return false;
                char openingPair = parentheses.top();
                parentheses.pop();

                if((current == ')' && openingPair != '(') ||
                   (current == ']' && openingPair != '[') ||
                   (current == '}' && openingPair != '{')) {
                    return false; // Mismatched parentheses
                }
            
            }
        }
        
        return parentheses.empty();
    }
};