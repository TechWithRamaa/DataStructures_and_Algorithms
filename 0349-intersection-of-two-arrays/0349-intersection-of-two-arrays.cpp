class Solution {
public:
    // Approach 1 - BruteForce 
    // Approach 2 - Set + Set
    // Approach 3 - Sorting + Two Pointers 
    // Approach 4 - Binary Search + Set
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
};