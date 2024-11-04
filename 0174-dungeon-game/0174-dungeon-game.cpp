
class Solution {
public:
    int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
        int ROWS = dungeon.size();
        int COLS = dungeon[0].size();
        vector<vector<int>> cache(ROWS, vector<int>(COLS, -1));

        return minimumHealthNeeded(dungeon, 0, 0, cache);
    }

    int minimumHealthNeeded(const vector<vector<int>>& dungeon, 
                            int i, int j, vector<vector<int>>& cache) {
        int ROWS = dungeon.size();
        int COLS = dungeon[0].size();

        // When knight reaches the princess's cell
        if (i == ROWS - 1 && j == COLS - 1) 
            return cache[i][j] = max(1, 1 - dungeon[i][j]);
    
        if (cache[i][j] != -1) return cache[i][j];
    
        int healthOnRightPath = INT_MAX;
        int healthOnDownPath = INT_MAX;

        if (j + 1 < COLS) 
            healthOnRightPath = minimumHealthNeeded(dungeon, i, j + 1, cache);
        
        if (i + 1 < ROWS) 
            healthOnDownPath = minimumHealthNeeded(dungeon, i + 1, j, cache);
        
        int minHealthNeeded = min(healthOnRightPath, healthOnDownPath);
        cache[i][j] = max(1, minHealthNeeded - dungeon[i][j]);

        return cache[i][j];
    }
};
