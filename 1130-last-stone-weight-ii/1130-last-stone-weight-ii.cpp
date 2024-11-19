class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);

        // Memoization vector, the size is `totalSum + 1` because we're dealing with possible subset sums.
        vector<vector<int>> memo(stones.size(), vector<int>(totalSum + 1, -1));

        // Starting recursive search
        return dfs(0, 0, stones, memo, totalSum);
    }
private:
    int dfs(int index, int currentSum, vector<int>& stones, vector<vector<int>>& memo, int totalSum) {
        // Base case: All stones processed
        if (index == stones.size()) {
            return abs(totalSum - 2 * currentSum); // Minimize the difference
        }

        // Check if this state was already computed
        if (memo[index][currentSum] != -1) {
            return memo[index][currentSum];
        }

        // Explore both choices: include or exclude current stone
        int include = dfs(index + 1, currentSum + stones[index], stones, memo, totalSum);
        int exclude = dfs(index + 1, currentSum, stones, memo, totalSum);

        // Store the minimum of both choices
        return memo[index][currentSum] = min(include, exclude);
    }
};