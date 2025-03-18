class Solution {
public:
    // Dynamic Sliding Window
    // TC ~ O ( n ) ; SC ~ O ( 1 )
    int longestNiceSubarray(vector<int>& nums) {
        int longestSubarray = 0;
        int left = 0, cumulativeSetBits = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((cumulativeSetBits & nums[right]) != 0) {
                cumulativeSetBits ^= nums[left];
                left++;
            }
            cumulativeSetBits |= nums[right];
            longestSubarray = max(longestSubarray, right - left + 1);
        }

        return longestSubarray;
    }
};