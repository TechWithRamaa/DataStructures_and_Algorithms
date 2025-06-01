class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        const int NODES = edges.size() + 1;

        vector<vector<int>> graph(NODES);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int diameter = 0;
        dfs(0, -1, graph, diameter);

        return diameter;
    }

private:
    // post-order dfs
    int dfs(int node, int parent, vector<vector<int>>& graph, int& diameter) {
        int max1 = 0, max2 = 0;

        for(auto neighbor : graph[node]) {
            if(neighbor == parent)
                continue;
            
            int height = dfs(neighbor, node, graph, diameter);

            if(height > max1) {
                max2 = max1;
                max1 = height;
            } else if (height > max2) {
                max2 = height;
            }
        }

        // The length of the longest path through the node
        diameter = max(diameter, max1 + max2);

        return 1 + max(max1, max2);
    }
};