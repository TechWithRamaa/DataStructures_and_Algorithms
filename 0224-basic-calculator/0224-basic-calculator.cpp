class Solution {
public:
    /*
    Use a sign stack when the effect of a + or - operator 
    can cascade through nested parentheses, and 
    each scope needs to preserve its own sign context.
    */
    int calculate(string s) {
        stack<int> signStack;
        int result = 0;
        int sign = 1;  // +1 by default
        int i = 0;

        signStack.push(1);  // global sign context

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue;  // already moved `i` forward in the number loop
            }
            else if (c == '+') {
                sign = signStack.top();  // use current context sign
            }
            else if (c == '-') {
                sign = -signStack.top();  // flip sign in current context
            }
            else if (c == '(') {
                signStack.push(sign);  // push current sign to apply inside parens
            }
            else if (c == ')') {
                signStack.pop();  // pop the sign context
            }

            i++;
        }

        return result;
    }
};
