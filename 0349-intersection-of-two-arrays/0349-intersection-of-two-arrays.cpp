class Solution {
public:
    // Approach 1 - BruteForce 
    // Approach 2 - Set + Set
    // Approach 3 - Sorting + Two Pointers 
    // Approach 4 - Sorting + Binary Search + Set
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        // Approach 2 
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for(auto num : nums2) {
            if(set1.count(num)) {
                result.insert(num);
            }
        }

        vector<int> resultList(result.begin(), result.end());
        return resultList;
    }

    // Approach 3
    // Merge 2 sorted lists but only iff elements intersect
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                if(result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};