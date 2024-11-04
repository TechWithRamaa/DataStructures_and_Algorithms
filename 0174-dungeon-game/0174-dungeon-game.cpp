#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        // Create a memoization table initialized to -1
        std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, -1));

        return minimumHealthNeeded(dungeon, 0, 0, memo);
    }

    int minimumHealthNeeded(const std::vector<std::vector<int>>& dungeon, 
                            int i, int j, 
                            std::vector<std::vector<int>>& memo) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        // If the knight reaches the princess's cell
        if (i == rows - 1 && j == cols - 1) {
            return std::max(1, 1 - dungeon[i][j]); // Health must be at least 1
        }

        // Check if the result is already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int healthOnExitRight = INT_MAX;
        int healthOnExitDown = INT_MAX;

        // Move right if within bounds
        if (j + 1 < cols) {
            healthOnExitRight = minimumHealthNeeded(dungeon, i, j + 1, memo);
        }

        // Move down if within bounds
        if (i + 1 < rows) {
            healthOnExitDown = minimumHealthNeeded(dungeon, i + 1, j, memo);
        }

        // Determine the minimum health needed to enter this cell
        int minHealthNeeded = std::min(healthOnExitRight, healthOnExitDown);
        memo[i][j] = std::max(1, minHealthNeeded - dungeon[i][j]);

        return memo[i][j];
    }
};
