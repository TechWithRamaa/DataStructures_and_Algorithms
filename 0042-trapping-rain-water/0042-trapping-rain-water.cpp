class Solution {
public:
    int trap(const vector<int>& height) {
        const int N = height.size();
       

        stack<int> st; 
        int waterTrapped = 0;

        for (int i = 0; i < N; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                
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

            st.push(i);
        }

        return waterTrapped;
    }
};