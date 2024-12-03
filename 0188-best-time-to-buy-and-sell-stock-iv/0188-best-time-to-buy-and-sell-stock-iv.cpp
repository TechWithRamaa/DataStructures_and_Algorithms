class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int N = prices.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return maximumProfit(prices, N, 0, 0, k, dp);
    }

public:
    int maximumProfit(const vector<int>& arr, const int N, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if (ind == N || cap == 0)
            return 0;
       
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit;

        if (buy == 0)
            profit = max(0 + maximumProfit(arr, N, ind + 1, 0, cap, dp),
                         -arr[ind] + maximumProfit(arr, N, ind + 1, 1, cap, dp));

        if (buy == 1)
            profit = max(0 + maximumProfit(arr, N, ind + 1, 1, cap, dp),
                        arr[ind] + maximumProfit(arr, N, ind + 1, 0, cap - 1, dp));
        

        return dp[ind][buy][cap] = profit;
    }
};