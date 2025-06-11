class Solution {
public:
    // Modified Kadane's algorithm
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];

        int runningMax = nums[0], runningMin = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if(num < 0)
                swap(runningMax, runningMin);

            runningMax = max(num, num * runningMax);
            runningMin = min(num, num * runningMin);

            maxProduct = max(maxProduct, runningMax);
        }

        return maxProduct;
    }
};