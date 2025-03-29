class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();

        vector<int> nextWarmerDaysIn(N, 0);

        // Next Greater Element // Monotonic Decreasing Stack
        stack<int> st;

        for (int i = N - 1; i >= 0; i--) {

            // pop smaller elements
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if (!st.empty())
                nextWarmerDaysIn[i] = st.top() - i;

            st.push(i);
        }

        return nextWarmerDaysIn;
    }
};