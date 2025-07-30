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
