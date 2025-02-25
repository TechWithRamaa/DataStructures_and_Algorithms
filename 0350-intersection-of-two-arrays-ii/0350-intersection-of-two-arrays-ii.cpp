class Solution {
public:
    // Approach 1 : TC ~ O ( n ) ; SC ~ O ( n )
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1); // Ensure nums1 is the smaller array

        unordered_map<int, int> freq;
        for (int num : nums1)
            freq[num]++; // Count occurrences in the smaller array

        vector<int> result;
        for (int num : nums2) {
            if (freq[num] > 0) { // If present in map
                result.push_back(num);
                freq[num]--; // Decrease count
            }
        }
        return result;
    }
};