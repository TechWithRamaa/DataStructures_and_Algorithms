class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int N = heights.size();

        stack<int> st;
        vector<int> pse(N, -1);
        vector<int> nse(N, N);

        // Technique involves 3 main steps
        // step 1 - find previous smaller elements for all bars
        // step 2 - find next smaller elements for all bars
        // step 3 - find maxArea obtained by each bar considering their expanded limits

        // Previous Smaller elements
        // Maintain Increasing Monotonic Stack
        for(int i = 0; i < N; i++) {
            // step 1 -> pop bigger elements
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
                
            // step 2 -> calculate PSE
            if(!st.empty())
                pse[i] = st.top();

            // step 3 -> push the current element
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller elements
        // Maintain Increasing Monotonic Stack
        for(int i = N - 1; i >= 0; i--) {
            // step 1 -> pop bigger elementsep
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            // step 2 -> calculate NSE
            if(!st.empty()) 
                nse[i] = st.top();

            // step 3 -> push the current element
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Update MaxArea
        for(int i = 0; i < N; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }

    /* Concise style
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
    }*/

};