class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top();
                s.pop(); 

                int a = s.top();
                s.pop();
                
                int result = 0;

                if (token == "+") {
                    result = a + b;
                } else if (token == "-") {
                    result = a - b;
                } else if (token == "*") {
                    result = a * b;
                } else if (token == "/") {
                    result = a / b;
                }

                s.push(result);
            } else {
                s.push(stoi(token));
            }
        }
        
        int result = s.top();
        s.pop();

        return result;
    }
};