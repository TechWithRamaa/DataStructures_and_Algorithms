class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<long long> maxHeap;

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            // Sort each row in descending order
            sort(grid[i].rbegin(), grid[i].rend());

            // Take the top 'limits[i]' elements and push into maxHeap
            for (int j = 0; j < min((int)grid[i].size(), limits[i]); j++) {
                maxHeap.push(grid[i][j]);
            }
        }

        // Extract top 'k' elements from maxHeap to get the max sum
        long long maxSum = 0;
        while (k-- > 0 && !maxHeap.empty()) {
            maxSum += maxHeap.top();
            maxHeap.pop();
        }

        return maxSum;
    }
};