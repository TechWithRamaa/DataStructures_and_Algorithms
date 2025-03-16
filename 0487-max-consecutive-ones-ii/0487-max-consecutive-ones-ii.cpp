class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, zeroCount = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                zeroCount++;
            }

            while(zeroCount > 1) {
                if(nums[left] == 0) {
                    zeroCount--;
                }
                
                left++;
            }

            maxOnes = max(maxOnes, right - left + 1);
        }

        return maxOnes;
    }
};