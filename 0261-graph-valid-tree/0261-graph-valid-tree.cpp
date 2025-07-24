class Solution {
public:
    // DFS + Cycle Detection + Connectivity Check
    /*
    ✅ A graph is a valid tree if and only if:
        It is fully connected → every node is reachable from any node
        It has no cycles
    \U0001f449 In other words:
        A tree with n nodes must have exactly n - 1 edges
        And the graph must be connected (i.e., 1 connected component)
    */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) 
        return false;

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

        return visited.size() == n; // singluar connected component
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

        return true; // success
    }
};