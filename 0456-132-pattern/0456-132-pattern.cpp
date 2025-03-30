class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();

        if(N < 3) return false;

        stack<int> st; 
        // monotonic decreasing stack
        int third = INT_MIN;

        for(int i = N - 1; i >= 0; i--) {
            
            if(nums[i] < third)
                return true;

            while(!st.empty() && st.top() < nums[i]) {
                third = st.top();
                st.pop();
            }


            st.push(nums[i]);
        }

        return false;
    }
};