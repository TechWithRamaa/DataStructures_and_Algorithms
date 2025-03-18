class Solution {
public:
    int calculate(string s) {
        int result= 0;

        int number = 0;
        int sign = 1;
        stack<int> st;
        st.push(sign);

        for(auto c : s) {
            if(isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+' || c == '-' ) {
                result += number * sign;
                sign = (c == '+') ? st.top() : -(st.top()); 
                number = 0;
            } else if (c == '(') {
                st.push(sign);
            } else if (c == ')') {
                st.pop();
            } 
        }

        result += sign * number;
        return result;
    }
};