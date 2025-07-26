class Solution {
public:
    /*
    Intuition Recap:
        Traverse from right to left
        Stack keeps people to the right, in monotonic decreasing order
        Pop and count everyone smaller than you
        If one taller person remains (at top), count them too
    */
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