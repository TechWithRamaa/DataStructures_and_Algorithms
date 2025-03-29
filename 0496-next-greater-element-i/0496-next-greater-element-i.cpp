class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge2;

        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            nge2[nums2[i]] = !st.empty() ? st.top() : -1;

            st.push(nums2[i]);
        }

        vector<int> nge1;
        for (auto num : nums1) {
            if (nge2.find(num) != nge2.end()) {
                nge1.push_back(nge2[num]);
            }
        }

        return nge1;
    }
};