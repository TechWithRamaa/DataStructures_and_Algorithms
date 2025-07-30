class Solution1 {
public:
    int rows, cols;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    bool canReach(vector<vector<int>>& heights, int maxEffort) {
        rows = heights.size();
        cols = heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x == rows - 1 && y == cols - 1) return true;

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny]) {
                    int diff = abs(heights[nx][ny] - heights[x][y]);
                    if (diff <= maxEffort) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6, answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(heights, mid)) {
                answer = mid;
                right = mid - 1; // Try smaller effort
            } else {
                left = mid + 1;  // Try larger effort
            }
        }

        return answer;
    }
};

/*
We are minimizing the maximum difference in heights along any path from (0,0) to (m-1,n-1). 
This is a classic:
Binary Search on Answer + BFS/DFS/Union-Find check

\U0001f50d Idea: Binary Search on Effort
Let’s binary search over the possible effort (range: 0 to 1e6).
For each effort mid, check if there exists a path from (0,0) to (m-1,n-1) where no edge has a difference > mid.
If a path exists → try a smaller effort (right = mid).
If not → try a bigger effort (left = mid + 1).

\U0001f527 Check Function:
Use DFS or BFS to verify if a path exists under the current allowed max effort.
*/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});  // {effort, x, y}
        effort[0][0] = 0;

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top(); pq.pop();

            if (x == m - 1 && y == n - 1)
                return currEffort;

            for (auto &[dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newEffort = max(currEffort, abs(heights[nx][ny] - heights[x][y]));
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        return 0; // Just a fallback (we’ll never reach here)
    }
};


/*
When to use this approach?
This is usually faster in practice than binary search + BFS for dense grids.

It’s a direct application of Dijkstra with a clever cost definition.

*/