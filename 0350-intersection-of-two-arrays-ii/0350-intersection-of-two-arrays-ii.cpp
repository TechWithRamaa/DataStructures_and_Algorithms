class Solution {
public:
    // Approach 1 : TC ~ O ( n ) ; SC ~ O ( n )
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
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

    // Approach 2 : TC ~ O ( n ) ; SC ~ O ( 1 )
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]); // Found common element
                i++;
                j++;
            }
        }
        return result;
    }
};