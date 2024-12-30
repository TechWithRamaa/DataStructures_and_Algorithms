class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) 
            dist[i][i] = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) 
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find the city with the smallest number of reachable neighbors
        int minReachable = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;

            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) 
                    ++reachableCount;
            }

            // Update the result city based on the problem statement
            if (reachableCount < minReachable || 
                (reachableCount == minReachable && i > resultCity)) {
                minReachable = reachableCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};