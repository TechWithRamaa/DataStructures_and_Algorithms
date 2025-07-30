class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);  // track nodes already in MST
        vector<int> minDist(n, INT_MAX);  // min cost to connect each node
        minDist[0] = 0;

        int result = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Step 1: Find the node u not in MST with min edge weight
            for (int j = 0; j < n; ++j) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            result += minDist[u];
            inMST[u] = true;

            // Step 2: Update min distances from newly added node u
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], weight);
                }
            }
        }

        return result;
    }
};


class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);  // Initialize each node as its own parent
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;

        // Union by rank
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

class Solution1 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges; // {cost, u, v}

        // Step 1: Build all possible edges with Manhattan distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        // Step 2: Sort edges by cost
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int result = 0;
        int count = 0;

        // Step 3: Greedily pick edges that don’t form a cycle
        for (auto& [cost, u, v] : edges) {
            if (dsu.unite(u, v)) {
                result += cost;
                count++;
                if (count == n - 1) break;
            }
        }

        return result;
    }
};
