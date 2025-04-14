class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // shrink the search range until left == right
        while(left < right) {            
            int mid = left + (right - left) / 2 ;
            
            // right half is unsorted
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right--;
        }

        return nums[left];
    }
};