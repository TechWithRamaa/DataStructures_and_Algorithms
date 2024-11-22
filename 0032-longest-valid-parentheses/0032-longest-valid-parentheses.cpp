class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                st.push(i); // Push index of '('
            else {
                st.pop(); // Try to match with previous '('
                if (st.empty())
                    st.push(i); // Push current ')' index if unmatched
                else
                    maxLength = max(maxLength, i - st.top()); // Valid substring length
            }
        }

        return maxLength;
    }
};