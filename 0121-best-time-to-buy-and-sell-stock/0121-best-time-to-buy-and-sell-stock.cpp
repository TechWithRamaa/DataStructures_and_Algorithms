class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        // Brute-Force
        /*
        for(int buyIndex = 0; buyIndex < prices.size() - 1; buyIndex++) {
            for(int sellIndex = buyIndex + 1; sellIndex < prices.size(); sellIndex++) {
                if(prices[sellIndex] > prices[buyIndex]) {
                    int profit = prices[sellIndex] - prices[buyIndex];
                    maxProfit = max(profit, maxProfit);
                }
            }
        }
        */

        // single pass 
        int minBuyPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            minBuyPrice = min(minBuyPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minBuyPrice);
        }

        return maxProfit;
    }
};