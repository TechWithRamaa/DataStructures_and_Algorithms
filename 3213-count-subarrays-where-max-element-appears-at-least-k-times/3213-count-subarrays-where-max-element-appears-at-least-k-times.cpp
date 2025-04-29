class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        
        long long result = 0;
        int left = 0;
        int count = 0; // count of maxNum in current window

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxNum) {
                count++;
            }

            // shrink window from the left until count of maxNum >= k
            while (count >= k) {
                // once count >= k, we can count (n - right) valid subarrays starting at left
                result += (n - right);

                // now shrink from left
                if (nums[left] == maxNum) {
                    count--;
                }
                left++;
            }
        }

        return result;
    }
};
