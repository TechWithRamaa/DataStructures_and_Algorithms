class Solution {
public:
    /*
    \U0001f527 Approach:
        BFS traversal from all nodes

        Use mask to represent the set of visited nodes

        Use seen to avoid revisiting the same (node, mask) state

        \U0001f522 How Many Total States?
        
        Each state is represented as (node, mask), where:

        node is one of n nodes.

        mask is a bitmask of visited nodes (2^n possible values).

        Thus, total states = n * 2^n. ✅
    */
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();

        if(N == 1)
            return 0;

        int goal = (1 << N) - 1;

        queue<tuple<int, int, int>> q;
        // i th node, mask (log of nodes in the current path), distancer

        vector<vector<bool>> seen(N, vector<bool>(1 << N, false));

        // start from all nodes as per problem requirement
        for(int i = 0; i < N - 1; i++) {
            int mask = 1 << i;
            q.emplace(i, mask, 0);
            seen[i][mask] = true;
        }

        while(!q.empty()) {
            auto [node, mask, distance] = q.front();
            q.pop();

            if(mask == goal)
                return distance;

            for(auto neighbor : graph[node]) {
                int nextMask = mask | (1 << neighbor);
                
                if(seen[neighbor][mask] == false) {
                    seen[neighbor][mask] = true;
                    q.emplace(neighbor, nextMask, distance + 1);
                }
            }
        }

        return -1;
    }
};