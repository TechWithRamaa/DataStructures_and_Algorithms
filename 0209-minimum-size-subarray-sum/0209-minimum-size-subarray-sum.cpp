class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;

        int left = 0, windowSum = 0;
        for(int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];

            while(windowSum >= target) {
                minLength = min(minLength, right - left + 1);

                windowSum -= nums[left];
                left++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};