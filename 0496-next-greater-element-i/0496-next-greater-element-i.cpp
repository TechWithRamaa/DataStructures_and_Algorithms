class Solution {
public:
    // Approach1 - BruteForce -> TC ~ O ( N * N )
    // Approach2 - Monotonic Stack -> TC ~ O ( N )

    // For NGE - we have to start from right to left
    // Leverage Monotonic Stack
    // For NGE - the order maintained is Decreasing order ( from down to top )
    // bottom -> 4 , 3, 1 .. is at the top .. meaning the the stack is decreasing from bottom to top
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge2;

        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            // step 1 -> pop smaller elements
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            // step 2 -> assign nge 
            nge2[nums2[i]] = !st.empty() ? st.top() : -1;

            // step 3 -> push the current element 
            st.push(nums2[i]);
        }

        vector<int> nge1;
        for (auto num : nums1) {
            if (nge2.find(num) != nge2.end()) {
                nge1.push_back(nge2[num]);
            }
        }

        while(!st.empty()) {
            cout << st.top() << endl;
            st.pop();
        }

        return nge1;
    }
};