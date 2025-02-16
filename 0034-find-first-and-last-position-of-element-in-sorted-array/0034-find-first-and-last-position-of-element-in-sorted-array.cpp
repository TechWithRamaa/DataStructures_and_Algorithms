class Solution {
public:
    // BruteForce ~ O(N)
    vector<int> searchRangeBruteForce(vector<int>& nums, int target) {
        int startingPosition = -1, lastPosition = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(startingPosition == -1) 
                    startingPosition = i; 
                lastPosition = i;
            }
        }
        
        return {startingPosition, lastPosition};
    }

    // BinarySearch ~ O(log N) + O(log N)
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirstPosition(nums, target), findLastPosition(nums, target)};
    }

private:
    int findFirstPosition(vector<int>& nums, int target) {
        int firstPosition = -1;
        
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left ) / 2;

            if(nums[mid] == target) {
                firstPosition = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return firstPosition;
    }

    int findLastPosition(vector<int>& nums, int target) {
        int lastPosition = -1;
        
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left ) / 2;

            if(nums[mid] == target) {
                lastPosition = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return lastPosition;
    }
};