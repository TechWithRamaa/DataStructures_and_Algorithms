class Solution {
public:
    /*
    Multi-source BFS:

    Run BFS from every building (1 cell).

    During each BFS:

        Update a distanceSum grid (adds distances from current building).
        Update a reachCount grid (how many buildings can reach this cell).

    Final Scan:

        Look for cells where reachCount == totalBuildings.
        Among those, return the smallest distanceSum.

    Data Structures:
    
        distanceSum[i][j]: Total distance from all buildings to cell (i,j)
        reachCount[i][j]: Number of buildings that can reach (i,j)

    Return:

        Minimum distanceSum[i][j] such that reachCount[i][j] == buildingCount
        If no such cell exists, return -1

     Time & Space:
        
        Time: O(B * m * n) — BFS from each building
        Space: O(m * n) — for distance & reach count grids
    */
    int shortestDistance(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> distanceSum(M, vector<int>(N, 0));
        vector<vector<int>> reachCount(M, vector<int>(N, 0));

        int buildingCount = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    bfs(i, j, grid, distanceSum, reachCount);
                    buildingCount++;
                }
            }
        }

        int shortestDistance = INT_MAX;
         for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0 && reachCount[i][j] == buildingCount) {
                   shortestDistance = min(shortestDistance, distanceSum[i][j]);
                }
            }
        }

        return shortestDistance == INT_MAX ? -1 : shortestDistance;
    }

private:
    void bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& distanceSum,
             vector<vector<int>>& reachCount) {
        
        int M = grid.size(), N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int, int>> q;
        q.emplace(i, j);
        visited[i][j] = true;
        int distance = 0;

        while (!q.empty()) {
            int qSize = q.size();
            distance++;

            for (int i = 0; i < qSize; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [nx, ny] : directions) {
                    int nextR = nx + x;
                    int nextC = ny + y;

                    if ((nextR >= 0 && nextR < M && nextC >= 0 && nextC < N) &&
                        visited[nextR][nextC] == false &&
                        grid[nextR][nextC] == 0) {

                        q.emplace(nextR, nextC);
                        visited[nextR][nextC] = true;
                        distanceSum[nextR][nextC] += distance;
                        reachCount[nextR][nextC]++;
                    }
                }
            }
        }
    }
};