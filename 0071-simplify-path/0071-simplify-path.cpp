class Solution {
public:
    // Tokenization + Stack 
    // ~ O ( n )
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;

        string result = "";
        stack<string> st;

        while(getline(ss, token, '/')) {
            if(token == "." || token == "")
                continue;

            if(token == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token);
            }
        }

        while(!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};