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


    /* 
    int atMostK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;
        unordered_map<int, int> freq;

        for (right = 0; right < nums.size(); right++) {
            if (freq[nums[right]] == 0) // Expansion
                k--;                    // budget decreases when a num is bought

            freq[nums[right]]++;

            // Validation
            while (k < 0) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    k++; // budget increases when a num is sold

                left++; // Shrinking
            }

            count += (right - left + 1); // gives no of sub-arrays within valid window
        }

        return count;
    }*/
};