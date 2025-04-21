class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
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

            if (stops > k)
                continue;

            for (auto& [neighbor, price] : graph[node]) {
                int newCost = cost + price;

                // If the new cost is cheaper, or we still have stops left to
                // explore
                if (newCost < minCost[neighbor]) {
                    minCost[neighbor] = newCost;
                    q.emplace(neighbor, newCost, stops + 1);
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }

    // Djikshtra's algorithm
    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights) {
            graph[f[0]].emplace_back(f[1], f[2]);
        }

        // {cost so far, node, stops so far}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(0, src, 0);

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;
            if (stops > k)
                continue;

            for (auto& [nei, price] : graph[node]) {
                pq.emplace(cost + price, nei, stops + 1);
            }
        }

        return -1;
    }
};