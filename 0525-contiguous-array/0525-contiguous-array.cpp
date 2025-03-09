class Solution {
public:
    // Problem transformed into 
    // maximum length of the subarray sum of 0

    // so we re going with PrefixSum + HashMap
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixIndex;
        // <k, v> -> <prefixSum, index>
        int maxLen = 0, sum = 0;

        // Base case: prefix sum 0 at index -1
        prefixIndex[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            // Convert 0 to -1, keep 1 as is
            sum += (nums[i] == 0 ? -1 : 1);

            // If this sum was seen before, we have a subarray with equal 0's
            // and 1's
            if (prefixIndex.find(sum) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[sum]);
            } else {
                // Store the first occurrence of this sum
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};