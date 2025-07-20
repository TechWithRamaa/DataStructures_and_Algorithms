class Solution {
public:
    // DFS + Cycle Detection + Connectivity Check
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_set<int> visited;
        
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // cycle detection + traversal
        if(!dfs(0, -1, graph, visited )) { 
            return false;
        }

        return visited.size() == n; // singlurar connected component
    }
private:
    bool dfs(int node, int parent, vector<vector<int>>& graph,  unordered_set<int>& visited) {
        //if(visited.count(node) > 0) return false;

        visited.insert(node);
        for(auto neighbor: graph[node]) {
            if(neighbor == parent) 
                continue;
            if(visited.count(neighbor) > 0 || !dfs(neighbor, node, graph, visited))
                return false;
        }

        return true;
    }
};