class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> memo(amount + 1, -2);
        return coinChangeHelper(coins, amount, memo);
    }

private:
    int coinChangeHelper(std::vector<int>& coins, int amount, std::vector<int>& memo) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount] != -2)
            return memo[amount];

        int minCoins = INT_MAX;

        for (int coin : coins) {
            int result = coinChangeHelper(coins, amount - coin, memo);
            if (result >= 0 && result < minCoins) {
                minCoins = result + 1;
            }
        }

        memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[amount];
    }
};