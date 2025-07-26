class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Make sure mid is even
            if (mid % 2 == 1)
                mid--;

            // Check if the pair is valid
            if (nums[mid] == nums[mid + 1]) {
                // Single is in the right half
                left = mid + 2;
            } else {
                // Single is in the left half (including mid)
                right = mid;
            }
        }

        return nums[left];
    }
};