class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // stack of indices
        int waterTrapped = 0;

        for (int i = 0; i < height.size(); ++i) {
            // While stack is not empty and current height is higher than stack top
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top(); // This is the bottom of the trapped water
                st.pop();

                if (st.empty()) {
                    break; // No left wall to trap water
                }

                int left = st.top(); // Now top of stack is the left wall
                int right = i;       // current i is the right wall

                int width = right - left - 1;
                int boundedHeight = min(height[left], height[right]) - height[bottom];

                waterTrapped += width * boundedHeight;
            }

            st.push(i); // Add current bar to stack
        }

        return waterTrapped;
    }
};
