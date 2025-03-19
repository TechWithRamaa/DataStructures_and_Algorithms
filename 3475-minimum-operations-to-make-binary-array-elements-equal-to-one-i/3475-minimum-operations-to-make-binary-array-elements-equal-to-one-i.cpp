class Solution {
public:
     int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Flip the triplet starting at index i
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++operations;
            }
        }

        // Check the last two elements
        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }

        return operations;
    }
};