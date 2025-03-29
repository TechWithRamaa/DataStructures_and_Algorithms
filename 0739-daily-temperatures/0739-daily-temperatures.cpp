class Solution {
public:
    // Approach 1 -> Next Greater Element -> Monotonic Stack (Decreasing order)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> nextWarmerDaysIn(N, 0);

        // Next Greater Element // Monotonic Decreasing Stack
        stack<int> st;

        for (int i = N - 1; i >= 0; i--) {

            // step 1 -> pop smaller elements
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            // step 2 -> calculate warmer days
            if (!st.empty())
                nextWarmerDaysIn[i] = st.top() - i;

            // step 3 -> push the current temperature
            st.push(i);
        }

        return nextWarmerDaysIn;
    }
};