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

            while (count >= k) {
            //     // For visual clarity, print all subarrays [left...end], where end ranges from right to n-1
            //     for (int end = right; end < n; ++end) {
            //         cout << "[";
            //         for (int i = left; i <= end; ++i) {
            //             cout << nums[i];
            //             if (i < end) cout << ", ";
            //         }
            //         cout << "]" << endl;
            //     }

                result += (n - right);

                if (nums[left] == maxNum) {
                    count--;
                }
                left++;
            }
        }

        return result;
    }
};
