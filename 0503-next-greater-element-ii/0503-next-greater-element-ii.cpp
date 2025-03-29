class Solution {
public:
    // Approach 1 -> Next Great Element
    // Monotonic Stack -> Decreasing order ( Bottom to Top)
    // Instead of doubling the array & identifying the nge
    // We efficiently identify the nge for circular array using the below Approach
    
    // We start iterating from double the size 
    // While accessing the elements, we use i % N 
    
    // These steps simply simulate the doubling technique, but efficiently 
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