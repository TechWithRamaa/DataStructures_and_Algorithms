class Solution {
public:
    // Top-Down
    int f(vector<int>& nums, int house, vector<int>& dp) {
        // base
        if (house >= nums.size())
            return 0;

        if (dp[house] != -1)
            return dp[house];

        // rec
        return dp[house] = max(nums[house] + f(nums, house + 2, dp),
                               f(nums, house + 3, dp));
    }

    // Bottom Up
    // dp[i]=maximum amount we can rob from houses 0 to i.
    /*
        At house i, you have 2 choices:
            Rob it → you get nums[i] + dp[i-2]
            Skip it → you keep dp[i-1]
        So:
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    */

    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];

        vector<int> dp(N);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < N; i++) {
            int rob = nums[i] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(skip, rob);
        }

        return dp[N - 1];
    }

    int robS(vector<int>& nums) {
        // vector<int> dp(nums.size(), -1);
        // return f(nums, 0, dp);

        if (nums.size() == 1) {
            return nums[0];
        }

        int maxRob = 0, secondLast = 0, last = 0;
        for (int i = 0; i < nums.size(); i++) {
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