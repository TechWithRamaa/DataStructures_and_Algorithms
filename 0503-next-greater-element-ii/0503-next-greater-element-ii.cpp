class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(), -1);
        stack<int> st;

        int N = nums.size();
        int start = 2 * N - 1;
        for(int i = start; i >= 0; i--) {
            // step 1 -> pop smaller elements
            while(!st.empty() && st.top() <= nums[i % N])
                st.pop();

            // step 2 -> update nge
            if(!st.empty() && i < N)
                nge[i] = st.top();

            // step 3 -> push the current element
            st.push(nums[i % N]);
        }

        return nge;
    }
};