/*
Maximize the number of edges that can be removed while ensuring that 
both Alice and Bob can fully traverse the graph 
(i.e., the graph remains fully connected for both).

✅ Key Idea:
Use Disjoint Set Union (DSU) data structure (also called Union-Find).

Prioritize type 3 edges (usable by both Alice and Bob) since they contribute to both graphs simultaneously.

Use greedy strategy to connect as many components as possible and remove redundant edges.

-------------
Dont traverse & create MST, it s not weighted 
we use Network Connectivity concept 

Apply Greedy to Prioritize Type 3 edges
1 based indexing - Make not of it 
*/
class DJU {
private:
    vector<int> parent, rank;
    
public:
    int componentsCount; // specific to this problem requirement

    DJU(int N) {
        rank.resize(N + 1, 0);
        parent.resize(N + 1);

        for (int i = 1; i <= N; i++)
            parent[i] = i;

        componentsCount = N;
    }

    int findRoot(int x) {
        // Path Compression
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }

            componentsCount--; // 2 nodes are connected, decrement the components count
        } else
            return false;

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int N, vector<vector<int>>& edges) {
        DJU alice(N), bob(N);
        int noOfEdgesUsed = 0;

        // Greedy 
        sort(edges.rbegin(), edges.rend()); // Sort descending by type

        for (auto &edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];

            if (type == 3) {
                bool aliceEdge = alice.unite(u, v);
                bool bobEdge = bob.unite(u, v);

                if (aliceEdge || bobEdge)
                    noOfEdgesUsed++;
            } else if (type == 2) {
                bool bobEdge = bob.unite(u, v);

                if (bobEdge)
                    noOfEdgesUsed++;
            } else if (type == 1) {
                bool aliceEdge = alice.unite(u, v);

                if (aliceEdge)
                    noOfEdgesUsed++;
            }
        }

        if(alice.componentsCount != 1 || bob.componentsCount != 1)
            return -1;
        
        return edges.size() - noOfEdgesUsed;
    }
};