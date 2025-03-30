class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freqMap;

        for(auto c : s) {
            freqMap[c]++;
        }

        stack<char> st;
        vector<bool> alreadyInStack(26, false);

        for(auto c : s) {
            freqMap[c]--;

            if(alreadyInStack[c - 'a'])
                continue;

            while(!st.empty() && st.top() > c && freqMap[st.top()] >= 1) {
                alreadyInStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            alreadyInStack[c - 'a'] = true;
        }

        string result;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};