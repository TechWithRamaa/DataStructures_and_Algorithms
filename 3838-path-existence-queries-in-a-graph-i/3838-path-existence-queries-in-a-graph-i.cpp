class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return; // already connected

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        // Form Graph for 0 to N nodes using the given constraint for adjacency
        // Connect adjacent nodes if their value difference <= maxDiff
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                dsu.unite(i, i+1);
            }
        }

        vector<bool> answer;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            answer.push_back(dsu.find(u) == dsu.find(v));
        }

        return answer;
    }
};
