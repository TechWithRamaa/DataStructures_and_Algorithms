class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Construct adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Step 2: Dijkstra's Algorithm to find shortest paths
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if (curDist > dist[node])
                continue;

            for (auto& [neighbor, travelTime] : graph[node]) {
                long long newDist = curDist + travelTime;

                // Found a shorter path to neighbor
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] =
                        ways[node]; // Reset ways to new shortest path
                    pq.push({newDist, neighbor});
                }
                // Found another way to reach with the same shortest distance
                else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};