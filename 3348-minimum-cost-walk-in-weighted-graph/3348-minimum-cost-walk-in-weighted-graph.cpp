class DisjointUnionSet {
private:
    vector<int> parent, rank;
public:
    DisjointUnionSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        /* alternate
        iota(parent.begin(), parent.end(), 0);
        */
    }

    int findRoot(int x) {
        if(parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    void unionOfXAndY(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    // CRUX - BITWISE AND OEPERATOR & DSU
    // KEYWORD - WALK, BITWISE AND OF ALL WEIGHTS IN A WALK (NOT PATH)
    // ✅ Since AND values can only decrease or stay the same, 
    // there's no need to explore paths individually — 
    // your component-wise tracking achieves the same result efficiently.
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointUnionSet dsu(n);

        // Group the ADJACENT edges into the same root
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dsu.unionOfXAndY(u, v);
        }

        // IDENTIFY THE MINIMUM COST IN A COMPONENT
        unordered_map<int, int> rootComponentToCost;
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int root = dsu.findRoot(u);
            if(rootComponentToCost.find(root) == rootComponentToCost.end()) {
                rootComponentToCost[root] = w;
            } else {
                rootComponentToCost[root] &= w;
            }
        }

        vector<int> queryResults;
        for(auto query : query) {
            int s = query[0], d = query[1];
            if(dsu.findRoot(s) != dsu.findRoot(d)) {
                queryResults.push_back(-1);
            } else {
                 queryResults.push_back(rootComponentToCost[dsu.findRoot(s)]);
            }
        }

        return queryResults;
    }
};