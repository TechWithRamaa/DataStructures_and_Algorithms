class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for(auto& time: times) {
            int u = time[0], v = time[1], t = time[2];
            graph[u].push_back({v, t});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        unordered_map<int, int> dist;
        dist[k] = 0;

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for(auto& [neighbor, weight] : graph[node]) {
                int newTime = time + weight;

                if((!dist.count(neighbor)) || newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        if(dist.size() < n)
            return -1;

        int maxTimeTakes = 0;
        for(int i = 1; i <= n; i++) {
            if(!dist.count(i)) return -1;
                maxTimeTakes = max(maxTimeTakes, dist[i]);
        }

        return maxTimeTakes;
    }
};