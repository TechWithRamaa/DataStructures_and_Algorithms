class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int N = nums.size();

        int count = 0;

        for (int i = 1; i < N - 1; ++i) {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                ++count;
            }
        }
        return count;
    }
};