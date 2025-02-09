class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INT_MAX));
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto entry = pq.top();
            pq.pop();
            
            int effort = entry.first, cRow = entry.second.first, cCol = entry.second.second;

            if(cRow == ROWS - 1 && cCol == COLS - 1) return effort;

            vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for(auto [dRow, dCol] : directions) {
                int newRow = dRow + cRow;
                int newCol = dCol + cCol;

                if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                    int newEffort = max(effort, abs(heights[cRow][cCol] - heights[newRow][newCol]));
                    if(newEffort < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }

        }

        return -1;
    }
};