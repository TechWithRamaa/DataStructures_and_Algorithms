class Solution {
public:
    vector<int> sumOfDistancesInTree(const int N, const vector<vector<int>>& edges) {
        // Build the tree
        vector<vector<int>> tree(N);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Arrays to store the sum of distances for the root (node 0) and subtree sizes
        vector<int> dist(N, 0);
        vector<int> size(N, 1);

        // Depth First Traversal for calculating (distance from root to other nodes) + (sub-tree size for each node) 
        dfs1(0, -1, tree, dist, size);

        vector<int> answer(N);
        answer[0] = dist[0]; // already calculated in previous step

        // Depth First Traversal for calcuting total distance for other nodes leveraging parent-child relationship
        dfs2(0, -1, tree, dist, size, answer, N);

        return answer;
    }
private:
    // Calculate the sum of distances and size of each subtree
    // post-order DFS
    void dfs1(int node, int parent, const vector<vector<int>>& tree, vector<int>& dist, vector<int>& size) {
        for (int child : tree[node]) {
            if (child == parent)
                continue;
            
            dfs1(child, node, tree, dist, size);
            
            size[node] += size[child];
            dist[node] += dist[child] + size[child];
        }
    }
    
    // Calculate the sum of distances for each node using the parent-child relationship
    // re-rooting from parent to child
    // pre-order dfs
    void dfs2(int node, int parent, const vector<vector<int>>& tree, vector<int>& dist, 
                vector<int>& size, vector<int>& answer, int n) {

        for (int child : tree[node]) {
            if (child == parent) 
                continue;
            
            answer[child] = answer[node] + (n - 2 * size[child]);
            
            dfs2(child, node, tree, dist, size, answer, n);
        }
    }
};