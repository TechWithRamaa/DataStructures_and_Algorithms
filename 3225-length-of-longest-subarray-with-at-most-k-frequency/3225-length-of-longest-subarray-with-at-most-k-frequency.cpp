class Solution {
public:
    // Vairable or Dynamic Sliding Window
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxSubArrayLength = INT_MIN;

        int left = 0;
        unordered_map<int, int> freqMap;
        for(int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;

            while(freqMap[nums[right]] > k) {
                freqMap[nums[left]]--;
                left++;
            }

            maxSubArrayLength = max(maxSubArrayLength, right - left + 1);
        }

        return maxSubArrayLength == INT_MIN ? 0 : maxSubArrayLength;
    }
};