class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0, -1, graph, visited )) {
            return false;
        }

        return visited.size() == n;
    }
private:
    bool dfs(int node, int parent, unordered_map<int, vector<int>>& graph,  unordered_set<int>& visited) {
        if(visited.count(node) > 0) return false;

        visited.insert(node);
        for(auto neighbor: graph[node]) {
            if(neighbor == parent) 
                continue;
            if(!dfs(neighbor, node, graph, visited))
                return false;
        }

        return true;
    }
};