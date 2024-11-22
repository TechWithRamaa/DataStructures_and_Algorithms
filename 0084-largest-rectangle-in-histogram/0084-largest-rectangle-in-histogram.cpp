class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        const int N = heights.size();
        vector<int> PSE(N), NSE(N); 
        stack<int> st;

        // Calculate left limits
        for (int i = 0; i < N; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack to reuse
        while (!st.empty())
            st.pop();

        // Calculate right limits
        for (int i = N - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
           
            NSE[i] = st.empty() ? N : st.top();
            st.push(i);
        }

        // Calculate maximum area
        int maxArea = 0;
        for (int i = 0; i < N; ++i) {
            int width = NSE[i] - PSE[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};