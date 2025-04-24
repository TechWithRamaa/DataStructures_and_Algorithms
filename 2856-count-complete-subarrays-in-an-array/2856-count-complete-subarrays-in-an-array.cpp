class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (auto num : nums) {
            freqMap[num]++;
        }

        int distinctElements = freqMap.size();
        unordered_map<int, int> windowFreqMap;
        int windowDistinctElements = 0, left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            int current = nums[right];
            windowFreqMap[current]++;

            if (windowFreqMap[current] == 1) {
                windowDistinctElements++;
            }

            while (windowDistinctElements == distinctElements) {
                count += (nums.size() - right);

                // shrink
                windowFreqMap[nums[left]]--;
                if (windowFreqMap[nums[left]] == 0) {
                    windowDistinctElements--;
                }

                left++;
            }
        }

        return count;
    }
};