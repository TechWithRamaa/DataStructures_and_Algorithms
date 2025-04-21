class Solution {
public:
    int findCheapestPrice1(int n, vector<vector<int>>& flights, int src,
                           int dst, int k) {
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> stops(n, INT_MAX);
        
        priority_queue<tuple<int, int, int>,  vector<tuple<int, int, int>>, greater<>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}

        pq.emplace(0, src, 0);

        while (!pq.empty()) {
            auto [dist, node, steps] = pq.top();
            pq.pop();
           
            // We have already encountered a path with a lower cost and fewer
            // stops, or the number of stops exceeds the limit.
            if (steps > stops[node] || steps > k + 1)
                continue;

            stops[node] = steps;

            if (node == dst)
                return dist;

            for (auto& [neighbor, price] : adj[node]) {
                pq.push({dist + price, neighbor, steps + 1});
            }
        }
        return -1;
    }
};