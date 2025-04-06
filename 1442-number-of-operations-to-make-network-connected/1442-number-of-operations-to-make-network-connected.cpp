class DJU {
private:
    vector<int> parent, rank;
    
public:

    DJU(int N) {
        rank.resize(N , 0);
        parent.resize(N);

        for (int i = 1; i < N; i++)
            parent[i] = i;
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
        } else
            return false;

        return true;
    }
};

class Solution {
public:
    int makeConnected(int N, vector<vector<int>>& connections) {
        int noOfEdges = connections.size();

        if(noOfEdges < (N - 1))
            return -1;
        
        DJU network(N);
        int componentsCount = N;

        for(auto &edge : connections) {
            int u = edge[0], v = edge[1];

            if(network.unite(u, v))
                componentsCount--;
        }

        return componentsCount - 1; // need this no of edges to connect the remaining computers
    }
};