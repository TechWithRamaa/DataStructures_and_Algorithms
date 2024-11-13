class Solution {
public:
    int longestSubarray(const vector<int>& nums) {
        const int ATMOST_ZEROS = 1;

        int windowStart = 0;
        int longestWindow = 0;
        int zerosCount = 0;

        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            if(nums[windowEnd] == 0)
                zerosCount++;

            while(zerosCount > ATMOST_ZEROS) {
                if(nums[windowStart] == 0)
                   zerosCount--;

                windowStart++;  // shrinking the window from left
            }
            
            longestWindow = std :: max(longestWindow, windowEnd - windowStart);
        }

        return longestWindow;
    }
};