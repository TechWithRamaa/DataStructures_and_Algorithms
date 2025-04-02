class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0;

        int N = nums.size();

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    long long current = ((long long)(nums[i] - nums[j]) * nums[k]);
                    maxValue = max(maxValue, current);
                }
            }
        }

        return maxValue;
    }
};