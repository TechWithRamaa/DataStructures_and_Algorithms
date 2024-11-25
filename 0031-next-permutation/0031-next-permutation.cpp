class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            // Find the next larger element
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;

            // Swap the elements
            swap(nums[i], nums[j]);
        }
        // Reverse the elements from i+1 to the end
        reverse(nums.begin() + i + 1, nums.end());
    }
};