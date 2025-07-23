class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        if (N == 1) {
            return nums[0];
        }

        return max(rob(0, N - 2, nums), rob(1, N - 1, nums));
    }

private:
    int rob(int start, int end, vector<int>& nums) {
        int N = end - start + 1;
        
        if(N == 0)
            return 0;

        if (N == 1)
            return nums[start];

        vector<int> dp(N);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < N; i++) {
            int rob = nums[start + i] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(skip, rob);
        }

        return dp[N - 1];
    }

    int robS(int start, int end, const vector<int>& nums) {
        int maxRob = 0;

        int secondLast = 0, last = 0;
        for (int i = start; i <= end; i++) {
            int rob = nums[i] + secondLast;
            int dontRob = last;

            int currentRob = max(rob, dontRob);
            maxRob = max(maxRob, currentRob);

            secondLast = last;
            last = currentRob;
        }

        return maxRob;
    }
};