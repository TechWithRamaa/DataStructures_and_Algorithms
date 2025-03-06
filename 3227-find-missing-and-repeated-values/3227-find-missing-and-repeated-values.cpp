class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int repeated = -1, missing = -1;

        for (int num = 1; num <= N; num++) { // Check each number from 1 to N
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == num) {
                        count++;
                    }
                }
            }
            if (count == 2)
                repeated = num;
            if (count == 0)
                missing = num;
        }

        return {repeated, missing};
    }
};