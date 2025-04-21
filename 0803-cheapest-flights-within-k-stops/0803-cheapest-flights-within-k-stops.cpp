class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);

    for (auto& flight : flights) {
        graph[flight[0]].emplace_back(flight[1], flight[2]);
    }

    queue<tuple<int, int, int>> q; // {node, cost so far, stops so far}
    q.emplace(src, 0, 0);

    vector<int> minCost(n, INT_MAX);
    minCost[src] = 0;

    while (!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();

        if (stops > k) continue;

        for (auto& [neighbor, price] : graph[node]) {
            int newCost = cost + price;

            // If the new cost is cheaper, or we still have stops left to explore
            if (newCost < minCost[neighbor]) {
                minCost[neighbor] = newCost;
                q.emplace(neighbor, newCost, stops + 1);
            }
        }
    }

    return minCost[dst] == INT_MAX ? -1 : minCost[dst];
}


    // Djikshtra's algorithm
    int findCheapestPriceOption2(int n, vector<vector<int>>& flights, int src,
                                 int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto& entry : flights) {
            graph[entry[0]].push_back({entry[1], entry[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, src, k + 1});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][k + 1] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            int cost = top[0], node = top[1], stopsLeft = top[2];
            pq.pop();

            if (node == dst)
                return cost;

            if (stopsLeft > 0) {
                for (auto [neighbor, price] : graph[node]) {
                    int newCost = cost + price;

                    if (newCost < dist[neighbor][stopsLeft - 1]) {
                        dist[neighbor][stopsLeft - 1] = newCost;
                        pq.push({newCost, neighbor, stopsLeft - 1});
                    }
                }
            }
        }

        return -1;
    }
};