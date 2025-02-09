class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for(auto& entry : flights) {
            graph[entry[0]].push_back({entry[1], entry[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, k + 1});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][k + 1] = 0;

        while(!pq.empty()) {
            auto top = pq.top();
            int cost = top[0], node = top[1], stopsLeft = top[2];
            pq.pop();

            if(node == dst) 
                return cost;

            if(stopsLeft > 0) {
                for(auto [neighbor, price] : graph[node]) {
                    int newCost = cost + price;

                    if(newCost < dist[neighbor][stopsLeft - 1]) {
                        dist[neighbor][stopsLeft - 1] = newCost;
                        pq.push({newCost, neighbor, stopsLeft - 1});
                    }
                }
            }
        }

        return -1;

    }
};