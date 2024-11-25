class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

      
        for (int i = 0; i <= right; ++i) {
            while (nums[i] == 2 && i < right) {
                swap(nums[i], nums[right]);
                right--;
            }
            while (nums[i] == 0 && i > left) {
                swap(nums[i], nums[left]);
                left++;
            }
        }
    }
};