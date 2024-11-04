
class Solution {
public:
    int calculateMinimumHP(const vector<vector<int>>& dungeon) {
     int NO_OF_ROWS = dungeon.size();
        int NO_OF_COLS = dungeon[0].size();

        // Initialize cache with high values for health requirement.
        vector<vector<int>> cache(NO_OF_ROWS, vector<int>(NO_OF_COLS, INT_MAX));

        // Start from the princess's cell (bottom-right corner)
        cache[NO_OF_ROWS - 1][NO_OF_COLS - 1] = max(1, 1 - dungeon[NO_OF_ROWS - 1][NO_OF_COLS - 1]);

        // Fill the cache table bottom-up, right-to-left.
        for (int i = NO_OF_ROWS - 1; i >= 0; --i) {
            for (int j = NO_OF_COLS - 1; j >= 0; --j) {
                if (i < NO_OF_ROWS - 1) { // Move Down
                    cache[i][j] = min(cache[i][j], cache[i + 1][j] - dungeon[i][j]);
                }
                if (j < NO_OF_COLS - 1) { // Move Right
                    cache[i][j] = min(cache[i][j], cache[i][j + 1] - dungeon[i][j]);
                }
                cache[i][j] = max(cache[i][j], 1); // Ensure health is always at least 1.
            }
        }
        
        // The minimum initial health needed to start at the top-left corner
        return cache[0][0];
    }
};