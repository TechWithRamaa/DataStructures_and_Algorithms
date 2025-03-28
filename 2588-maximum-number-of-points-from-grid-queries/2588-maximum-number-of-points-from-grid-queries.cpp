class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Store queries with their original index
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end()); // Sort queries

        // Min-Heap to process grid cells in increasing order
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>  minHeap;
        minHeap.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<int> result(queries.size(), 0);
        int count = 0;

        for (auto& [query, idx] : sortedQueries) {
            // Expand cells in increasing order while grid[i][j] < query
            while (!minHeap.empty() && minHeap.top().first < query) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int r = pos.first, c = pos.second;
                count++; // Increment the count of processed cells

                // Explore neighbors
                for (auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !visited[nr][nc]) {
                        minHeap.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            result[idx] = count; // Store answer for this query
        }
        return result;
    }
};