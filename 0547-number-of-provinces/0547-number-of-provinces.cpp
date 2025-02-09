class Solution {
/* Solution - 1    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int N = isConnected.size();
        vector<bool> visited(N, false);
        int provinces = 0;

        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
private: 
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;

        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
*/

// Solution - 2
public:
    int findCircleNum(vector<vector<int>>& isConnected) { 
        int N = isConnected.size();
        vector<int> parent(N), rank(N, 0);

        for(int i = 0; i < N; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(isConnected[i][j] == 1) {
                    unionSets(i, j, parent, rank);
                }
            }
        }

        int provinces = 0;
        for(int i = 0; i < N; i++) {
            if(findUltimateRoot(i, parent) == i) {
                provinces++;
            }
        }

        return provinces;
    }
private:
    int findUltimateRoot(int x, vector<int>& parent) {
        if(parent[x] != x) 
            parent[x] = findUltimateRoot(parent[x], parent);

        return parent[x];
    }

    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = findUltimateRoot(x, parent);
        int rootY = findUltimateRoot(y, parent);

        if(rootX != rootY) {
            if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};