class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < N; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // You can reach the top from step n-1 or step n-2
        return min(dp[N - 1], dp[N - 2]);
    }
};