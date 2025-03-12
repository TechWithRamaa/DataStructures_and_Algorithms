class Solution {
public:
    // It is a beautiful formula
    // whenever you re given exactly K
    // we transform into Inclusion Exclusion principle as details below

    // it is too risky, it involves hell a lot of computations
    // so we transform into known standard problems
    // we have transformed into Dynamic Sliding Window problem
    // Longest SubArray Sum with atmost K distinct numbers

    // Math formula
    // Exactly K  =At most K − At most (K - 1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    // template from Longest SubArray Sum with atmost K distinct numbers
    int atMostK(vector<int>& nums, int k) {
        int noOfSubArrays = 0;
        
        unordered_map<int, int> freqMap;
        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;

            while(freqMap.size() > k) {
                freqMap[nums[left]]--;

                if(freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }

                left++;
            }

            noOfSubArrays += right - left + 1; // magical here 
        }

        return noOfSubArrays;
    } 
};