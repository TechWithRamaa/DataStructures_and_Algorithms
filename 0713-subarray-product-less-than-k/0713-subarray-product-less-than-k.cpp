class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // No subarray can satisfy the condition
        
        int product = 1, left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            
            // Shrink the window while the product is not valid
            while (product >= k) {
                product /= nums[left];
                ++left;
            }
            
            // Add the number of subarrays ending at 'right'
            result += (right - left + 1);
        }
        
        return result;
    }
};