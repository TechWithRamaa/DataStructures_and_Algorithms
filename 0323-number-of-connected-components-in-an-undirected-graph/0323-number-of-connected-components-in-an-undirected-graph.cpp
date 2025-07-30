class Solution {
public:
    // Find with path compression
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    // Union operation
    void unite(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            parent[rootY] = rootX;  // Merge the components
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        
        // Initially, each node is its own parent (n components)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Merge nodes based on edges
        for (const auto& edge : edges) {
            unite(parent, edge[0], edge[1]);
        }

        // Count unique roots (representing connected components)
        unordered_set<int> uniqueRoots;
        for (int i = 0; i < n; ++i) {
            uniqueRoots.insert(find(parent, i));
        }

        return uniqueRoots.size();
    }
};


class Solution1 {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs(neighbor, adj, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;  // new component found
            }
        }

        return components;
    }
};
