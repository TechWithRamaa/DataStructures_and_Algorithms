class Solution {
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