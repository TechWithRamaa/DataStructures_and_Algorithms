class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateRoot(int x) {
        if(parent[x] != x) {
            parent[x] = findUltimateRoot(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = findUltimateRoot(x);
        int rootY = findUltimateRoot(y);

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if(rank[rootY] > rank[rootX]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
private:
    vector<int> parent, rank;
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        UnionFind unionSet(N+1);

        vector<int> redundantEdge;
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            if(unionSet.findUltimateRoot(u) == unionSet.findUltimateRoot(v)) {
                redundantEdge = edge;
            } else {
                unionSet.unionSets(u, v);
            }
        }

        return redundantEdge;
    }
};
