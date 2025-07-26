class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int N = heights.size();
        vector<int> result(N, 0);
        stack<int> st;

        for(int i = N - 1; i >= 0; i--) {
            int count = 0;

            while(!st.empty() && heights[i] > st.top()) {
                st.pop();
                count++;
            }

            if(!st.empty()) {
                count++;
            }

            result[i] = count;
            st.push(heights[i]);
        }

        return result;
    }
};