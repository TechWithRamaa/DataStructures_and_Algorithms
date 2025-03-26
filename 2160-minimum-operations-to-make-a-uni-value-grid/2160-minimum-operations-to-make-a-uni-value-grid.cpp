class Solution {
public:
     int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        
        // Convert 2D grid to 1D array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // Check if making them equal is possible
        int remainder = nums[0] % x;
        for (int num : nums) {
            if (num % x != remainder) return -1; // Impossible to make them equal
        }

        // Sort to find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        // Calculate the minimum operations
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};