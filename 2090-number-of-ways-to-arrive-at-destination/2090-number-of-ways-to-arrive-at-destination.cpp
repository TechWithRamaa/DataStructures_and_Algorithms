class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);
        for(auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].emplace_back(v, t);
            graph[v].emplace_back(u, t);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        vector<long long> minTime(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        minTime[0] = 0;
        ways[0] = 1;
        minHeap.emplace(0, 0);

        while(!minHeap.empty()) {
            auto [currTime, node] = minHeap.top();
            minHeap.pop();

            if(currTime > minTime[node])
                continue;
            
             for (auto& [neighbor, travelTime] : graph[node]) {  

                long long newTime = currTime + travelTime;

                if (newTime < minTime[neighbor]) {
                    // Found a shorter path to `neighbor`
                    minTime[neighbor] = newTime;
                    ways[neighbor] = ways[node];  // Reset ways count
                    minHeap.emplace(newTime, neighbor);
                } 
                else if (newTime == minTime[neighbor]) {
                    // Found another shortest path to `neighbor`
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};