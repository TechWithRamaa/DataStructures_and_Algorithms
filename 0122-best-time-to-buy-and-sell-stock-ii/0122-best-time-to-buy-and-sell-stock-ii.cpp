class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                cout << profit << " - ";
                profit += prices[i + 1] - prices[i];
                cout << profit << endl;
            }
        }
        return profit;
    }
};