class Solution {
public:
    // Approach 1
    // Hashset - A BruteForce
    // TC ~ O ( N ) ; SC ~ O ( N )
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); i++) {
            if (!numSet.count(i))
                return i;
        }

        return nums.size() + 1;
    }
};