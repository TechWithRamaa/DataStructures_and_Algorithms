class Solution {
public:
    // Approach 1 -> BruteForce
    // 3 Nested Loops -> TC ~ O ( N ^3)
    long long maximumTripletValue2(vector<int>& nums) {
        long long maxValue = 0;

        int N = nums.size();

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    long long current =
                        ((long long)(nums[i] - nums[j]) * nums[k]);
                    maxValue = max(maxValue, current);
                }
            }
        }

        return maxValue;
    }

    // Approach 2 -> Optimized
    // Using Prefix Max & Suffix Max
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