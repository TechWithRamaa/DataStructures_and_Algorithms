class Solution {
public:
    // Approach 1
    // Hashset - A BruteForce
    // TC ~ O ( N ) ; SC ~ O ( N )
    int firstMissingPositive1(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); i++) {
            if (!numSet.count(i))
                return i;
        }

        return nums.size() + 1;
    }

    // Approach 2
    // Swap Cyclic Index - Best
    // TC ~ O ( N ) ; SC ~ O ( 1 )
    // Visualization is important for this
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]); // Place nums[i] at correct index
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1; // First missing positive
        }

        return n + 1; // If all numbers are in place, return n + 1
    }
};