class Solution {
public:
    /*
        Very important problem
        Trick is building a undirected graph for fast traversing
        even though the input is a Directed Acyclic Graph ( A Tree )
    */
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        unordered_set<long long> directions;

        for(auto connection : connections) {
            int u = connection[0], v = connection[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            directions.insert((long long) u * n + v);
        }

        return dfs(graph, directions, 0, -1, n);
    }

private:
    int dfs(vector<vector<int>>& graph, unordered_set<long long>& directions, int node, int parent, int n) {
        int changes = 0;

        for(int neighbor : graph[node]) {
            if(neighbor == parent)
                continue;

            // If original edge is from node to neighbor, it needs to be reversed
            if(directions.count((long long) node * n + neighbor)) {
                changes++;
            }

            changes += dfs(graph, directions, neighbor, node, n);
        }

        return changes;
    }
};