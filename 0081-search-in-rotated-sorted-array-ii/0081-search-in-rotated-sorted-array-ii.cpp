class Solution {
public:
    /*
    Yes, allowing duplicates affects the runtime complexity.
    Because in the worst case, when nums[left] == nums[mid] == nums[right], 
    we cant determine which half is sorted
    
    you can't reduce the search space logarithmically, and 
    may end up doing a linear scan, leading to O(n) time complexity.
    */
    bool search(const vector<int>& nums, const int TARGET) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == TARGET)    // Target found
                return true;

            // Handle duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            // Determine the sorted half in the given rotated array
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= TARGET && TARGET < nums[mid])
                    right = mid - 1; // Target in left half, narrow the search space to left half
                else
                    left = mid + 1; // Target in right half, narrow the search space to right half
            } else {
                if (nums[mid] < TARGET && TARGET <= nums[right])
                    left = mid + 1; /// Target in left half, narrow the search space to left half
                else
                    right = mid - 1; // Target in left half, narrow the search space to left half
            }
        }

        return false; // Target not found
    }
};