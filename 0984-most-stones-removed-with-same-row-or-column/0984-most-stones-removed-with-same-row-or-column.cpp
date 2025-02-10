class UnionFind {
public:
    unordered_map<int, int> parent, rank;

    int find(int x) {
        if (parent.find(x) == parent.end())
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return; // Already in the same set
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent, rank;

        int find(int x) {
            if (parent.find(x) == parent.end())
                parent[x] = x;
            if (parent[x] != x)
                parent[x] = find(parent[x]); // Path compression
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return;
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;  // // Use negative values to separate row & column spaces
            uf.unite(row, col);
        }

        // Count unique connected components
        unordered_map<int, bool> uniqueComponents;
        for (auto& stone : stones) {
            uniqueComponents[uf.find(stone[0])] = true;
        }

        return stones.size() - uniqueComponents.size();
    }
};