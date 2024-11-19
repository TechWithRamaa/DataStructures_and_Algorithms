class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>> memo(stones.size(), vector<int>(totalSum + 1, -1));

        return dfs(0, 0, stones, memo, totalSum);
    }
private:
    int dfs(int index, int currentSum, vector<int>& stones, vector<vector<int>>& memo, int totalSum) {
        if (index == stones.size()) 
            return abs(totalSum - 2 * currentSum);

        if (memo[index][currentSum] != -1) 
            return memo[index][currentSum];
        
        int include = dfs(index + 1, currentSum + stones[index], stones, memo, totalSum);
        int exclude = dfs(index + 1, currentSum, stones, memo, totalSum);

        return memo[index][currentSum] = min(include, exclude);
    }
};