class Solution {
public:
    // It is a beautiful formula
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
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

            noOfSubArrays += right - left + 1; 
        }

        return noOfSubArrays;
    } 
};