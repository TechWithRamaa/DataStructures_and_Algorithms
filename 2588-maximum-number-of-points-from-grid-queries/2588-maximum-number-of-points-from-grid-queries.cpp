class Solution {
public:
    // Approach Name - Dijkstra-like Expansion or "Flood Fill with Priority Queue
    // or otherwise - Increasing cost traversal
    // very efficient than BruteForce

    /* Final Complexity
    Sorting Queries: \U0001d442(\U0001d444 log \U0001d444)
    Grid Expansion (Dijkstra-like approach): \U0001d442((\U0001d440×\U0001d441) log(\U0001d440×\U0001d441))
    Processing Queries: \U0001d442(\U0001d444)

    Thus, the total time complexity is: \U0001d442(\U0001d444 log \U0001d444 + (\U0001d440×\U0001d441) log (\U0001d440×\U0001d441))
    */
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int M = grid.size();
        int N = grid[0].size();

        vector<pair<int, int>> queriesIndexList;
        for (int i = 0; i < queries.size(); i++) {
            queriesIndexList.push_back({queries[i], i});
        }

        sort(queriesIndexList.begin(), queriesIndexList.end());

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<bool>> isVisited(M, vector<bool>(N, false));
        vector<int> results(queries.size(), 0);
        int count = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        isVisited[0][0] = true;       

        for (auto& [query, index] : queriesIndexList) {
           
            while (!minHeap.empty() && minHeap.top().first < query) {
                auto [val, position] = minHeap.top();
                minHeap.pop();
                
                int r = position.first;
                int c = position.second;

                count++;

                for(auto& [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nr < M && nc >= 0 && nc < N && !isVisited[nr][nc]) {
                        minHeap.push({grid[nr][nc], {nr, nc}});
                        isVisited[nr][nc] = true;
                    }
                }
            }

            results[index] = count;
        }

        return results;
    }
};