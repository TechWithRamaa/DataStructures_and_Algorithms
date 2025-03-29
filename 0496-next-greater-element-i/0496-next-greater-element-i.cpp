class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge2;

        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge2[nums2[i]] = st.top();
            } else {
                nge2[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }

        vector<int> nge1(nums1.size(), -1);

        for(int i = 0; i < nums1.size(); i++) {
            if(nge2.find(nums1[i]) != nge2.end()) {
                nge1[i] = nge2[nums1[i]];
            }
        }

        return nge1;
    }
};