class Solution {
public:
    int trap(const vector<int>& height) {
        const int N = height.size();
        if (N == 0)
            return 0;

        stack<int> st; // Stack to store indices
        int waterTrapped = 0;

        for (int i = 0; i < N; i++) {
            // While the stack is not empty and the current bar is taller than
            // the bar at the stack's top
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                // If the stack is empty after popping, there's no left boundary
                // for trapping water
                if (st.empty())
                    break;

                // Calculate the width of the trapped water
                int width = i - st.top() - 1;

                // The height of the trapped water is determined by the shorter
                // of the two boundaries
                int h = min(height[i], height[st.top()]) - height[top];

                // Add the trapped water to the result
                waterTrapped += width * h;
            }

            // Push the current index to the stack
            st.push(i);
        }

        return waterTrapped;
    }
};