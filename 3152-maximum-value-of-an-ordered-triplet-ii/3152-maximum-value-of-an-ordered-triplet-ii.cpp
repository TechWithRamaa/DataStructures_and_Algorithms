class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0;

        int N = nums.size();
        vector<int> suffixMax(N, 0);
        
        suffixMax[N - 1] = nums[N - 1]; 
        for(int k = N - 2; k >= 0; k--)
            suffixMax[k] = max(suffixMax[k + 1], nums[k]);

        int prefixMax = nums[0];
        for(int j = 1; j < N - 1; j++) {
            if(prefixMax > nums[j] && suffixMax[j + 1] > 0) {
                maxValue = max(maxValue, (long long)(prefixMax - nums[j]) * suffixMax[j + 1]);
            }
            prefixMax = max(prefixMax, nums[j]);
        }

        return maxValue;
    }
};