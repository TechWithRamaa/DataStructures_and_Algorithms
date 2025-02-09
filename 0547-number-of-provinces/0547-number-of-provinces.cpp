class Solution {
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
};