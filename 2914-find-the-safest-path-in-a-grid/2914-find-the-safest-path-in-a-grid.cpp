struct Cell {
    int row, col, safeness;
    bool operator<(const Cell& other) const {
        return safeness < other.safeness;
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // 1 Find the thieves and add position of thieves in the Queue
        // to start calculating BFS for every cell from thieves

        int GRID_SIZE = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> distanceFromThieves(GRID_SIZE, vector<int>(GRID_SIZE, INT_MAX));

        
        for(int r = 0; r < GRID_SIZE; r++) {
            for(int c = 0; c < GRID_SIZE; c++) {
                if(grid[r][c] == 1) {
                    q.push({r, c});
                    distanceFromThieves[r][c] = 0; // distance of thieves to thieves itself is zero
                }
            }    
        }

        vector<int> adjacentRows = {0, 0, -1, 1};
        vector<int> adjacentCols = {-1, 1, 0, 0};

        // 2 Update the BFS from thieves to every cell
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + adjacentRows[i];
                int nc = c + adjacentCols[i];

                if(nr >= 0 && nc >= 0 && nr < GRID_SIZE && nc < GRID_SIZE) {
                    if(distanceFromThieves[nr][nc] > distanceFromThieves[r][c] + 1) {
                        distanceFromThieves[nr][nc] = distanceFromThieves[r][c] + 1; // updating the distance of empty cells from previous level of BFS traversal
                        q.push({nr, nc});
                    }
                }
            }
        }

        // 3 Calculating maximum safeness factor of an entire path from (0,0) to (N-1, N-1)
        priority_queue<Cell> pq;
        pq.push({0,0, distanceFromThieves[0][0]});
        vector<vector<int>> safenessFactor(GRID_SIZE, vector<int>(GRID_SIZE, -1));
        safenessFactor[0][0] = distanceFromThieves[0][0];

        while(!pq.empty()) {
            auto[r, c, safeness] = pq.top();
            pq.pop();

            if(r == GRID_SIZE-1 && c == GRID_SIZE-1) return safeness;

            for(int i = 0; i < 4; i++) {
                int nr = r + adjacentRows[i];
                int nc = c + adjacentCols[i];

                if(nr >= 0 && nc >= 0 && nr < GRID_SIZE && nc < GRID_SIZE) {
                    int newSafeness = min(safeness, distanceFromThieves[nr][nc]);
                    if(newSafeness > safenessFactor[nr][nc]) {
                        safenessFactor[nr][nc] = newSafeness; // updating the maximum safenss factor of each cell in the path
                        pq.push({nr, nc, newSafeness});
                    }
                }
            }
        }

        return 0; // return 0 if final cell is unreachable
    }
};