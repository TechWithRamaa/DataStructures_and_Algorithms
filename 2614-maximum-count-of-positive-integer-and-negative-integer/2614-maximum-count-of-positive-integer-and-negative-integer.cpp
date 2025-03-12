class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Binary search for the first non-negative element
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        // Binary search for the first positive element
        int posCount = nums.end() - upper_bound(nums.begin(), nums.end(), 0);

        return max(negCount, posCount);
    }
};