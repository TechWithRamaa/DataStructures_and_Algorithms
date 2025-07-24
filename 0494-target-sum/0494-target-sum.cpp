class Solution {
public:
    // classic subset sum with signs - problem reference

    /*
    We are given an array nums and a target S.
    We can assign + or - signs to each number in nums.
    We need to find the total number of ways to assign signs so that the total sum equals S.
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if((target + totalSum) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int sum = (target + totalSum) / 2;
        int N = nums.size();

        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));

        for(int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j]; // dont take

                if(nums[i - 1] <= j) { // pruning
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; // take 
                }
            }
        }

        return dp[N][sum];
    }
};