class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int longest = 0, current = 0;

        for (int num : nums) {
            if (num == maxVal) {
                current++;
                longest = max(longest, current);
            } else {
                current = 0;
            }
        }

        return longest;
    }
};

/*
Key Observations:

The bitwise AND of a subarray gets smaller or stays the same as you extend the subarray.
So the maximum AND is just the maximum element in the array.
To get subarrays with that max AND, we just need to find the longest contiguous sequence of the maximum element.
Why? Because only maxElement & maxElement & ... & maxElement = maxElement
If you add anything smaller → the AND becomes smaller.

*/
