class Solution {
public:
    // Approach 1
    // BruteForce
    // TC ~ O ( n )
    int maximumCount1(vector<int>& nums) {
        int negCount = 0, posCount = 0;
        for (int num : nums) {
            if (num < 0)
                negCount++;
            else if (num > 0)
                posCount++;
        }
        return max(negCount, posCount);
    }

    // Approach 2
    // BinarySearch STL
    // TC ~ O ( log n )
    int maximumCount2(vector<int>& nums) {
        // Binary search for the first non-negative element or zero
        auto lastIndexOfNegatives = lower_bound(nums.begin(), nums.end(), 0);
        int negCount = lastIndexOfNegatives - nums.begin();

        // Binary search for the first positive element
        auto firstIndexOfPositives = upper_bound(nums.begin(), nums.end(), 0);
        int posCount = nums.end() - firstIndexOfPositives;

        return max(negCount, posCount);
    }

    // Approach 2
    // in few lines
    int maximumCount(vector<int>& nums) {
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(negCount, posCount);
    }
};