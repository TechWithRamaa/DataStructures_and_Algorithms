class Solution {
public:
    // BruteForce ~ O (n)
    int findPeakElementBruteForce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if((i == 0 || nums[i] > nums[i-1]) && ( i == nums.size() - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
        return -1;
    }
    
    // Binary Search ~ O(log n)
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};