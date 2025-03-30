class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freqMap;

        for (auto c : s) {
            freqMap[c]++;
        }

        stack<char> st;
        vector<bool> isCharacterPresentInStack(26, false);

        for (auto c : s) {
            freqMap[c]--;

            if (isCharacterPresentInStack[c - 'a'])
                continue;

            // step 1
            // pop larger characters
            // only if the top is a larger char & has future presence
            while (!st.empty() && st.top() > c && freqMap[st.top()] > 0) {
                isCharacterPresentInStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            isCharacterPresentInStack[c - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};