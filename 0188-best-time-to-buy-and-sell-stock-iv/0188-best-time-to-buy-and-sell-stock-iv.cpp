class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        return maxProfitBottomUp(k, prices);
        //return maxProfitTopDown(k, prices);
    }

private:
    int maxProfitBottomUp(int k, vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = N - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) 
                        cur[buy][cap] = max(0 + ahead[0][cap], -prices[ind] + ahead[1][cap]);
                    

                    if (buy == 1) 
                        cur[buy][cap] = max(0 + ahead[1][cap], prices[ind] + ahead[0][cap - 1]);
                
            }
        }
       
        ahead = cur;
    }

    return ahead[0][k];
    }
    int maxProfitTopDown(int k, vector<int>& prices) {
         int N = prices.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return maxProfitTopDown(prices, N, 0, 0, k, dp);
    }
    int maxProfitTopDown(const vector<int>& arr, const int N, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if (ind == N || cap == 0)
            return 0;
       
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit;

        if (buy == 0)
            profit = max(0 + maxProfitTopDown(arr, N, ind + 1, 0, cap, dp),
                         -arr[ind] + maxProfitTopDown(arr, N, ind + 1, 1, cap, dp));

        if (buy == 1)
            profit = max(0 + maxProfitTopDown(arr, N, ind + 1, 1, cap, dp),
                        arr[ind] + maxProfitTopDown(arr, N, ind + 1, 0, cap - 1, dp));
        

        return dp[ind][buy][cap] = profit;
    }
};