class Solution {
public:
    // the minimum element is the pivot of rotation
    // we need to look for the pivot in the decreasing half
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // plz note down the condition used in while & last statement inside
        // else block
        while (left < right) {
            int mid =  left + (right - left) / 2;

            // Pivot is to the right
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Pivot is at mid or to the left
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};