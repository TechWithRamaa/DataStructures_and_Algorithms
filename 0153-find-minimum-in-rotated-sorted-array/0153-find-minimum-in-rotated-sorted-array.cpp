class Solution {
public:
    // the minimum element is the pivot of rotation
    // we need to look for the pivot in the unsorted half
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // plz note down the condition used in while & last statement inside else block
        while (left < right) {
            // when the array is already sorted
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};