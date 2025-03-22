class Solution {
public:
    // Typical DFS
    // TC ~ O ( V + E )
    // CRUX
    // how do you count the noOfNodes in a connected component 
    // how do you count the noOfEdges in a connected component
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int noOfCompleteComponents = 0;

        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> nodes;
                int edgeCount = 0;

                dfs(graph, visited, i, nodes, edgeCount);

                int noOfNodes = nodes.size();
                int expectedEdges = (noOfNodes * (noOfNodes - 1)) / 2; 

                if(expectedEdges == edgeCount/2) {
                    noOfCompleteComponents++;
                }
            }
        }

        return noOfCompleteComponents;
    }

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& nodes, int& edgeCount) {
        visited[node] = true;
        nodes.push_back(node); //  Add node to the current component

        for(auto neighbor : graph[node]) {
            edgeCount++; // Count the edge
           
            if(!visited[neighbor]) {
                dfs(graph, visited, neighbor, nodes, edgeCount);
            }
        }
    }
};