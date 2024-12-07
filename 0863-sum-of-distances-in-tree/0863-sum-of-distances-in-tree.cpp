class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Step 1: Build the graph (adjacency list)
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Arrays to store the sum of distances and size of each subtree
        vector<int> dist(n, 0);
        vector<int> size(n, 1);

        // Step 2: Compute the sum of distances for the root (node 0) and
        // subtree sizes
        dfs1(0, -1, tree, dist, size);

        // Step 3: Compute the sum of distances for all nodes using the
        // parent-child relationship
        vector<int> answer(n);
        answer[0] = dist[0];
        dfs2(0, -1, tree, dist, size, answer, n);

        return answer;
    }
private:
    // DFS 1: Calculate the sum of distances and size of each subtree
    void dfs1(int node, int parent, const vector<vector<int>>& tree, vector<int>& dist, vector<int>& size) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs1(child, node, tree, dist, size);
            size[node] += size[child];
            dist[node] += dist[child] + size[child];
        }
    }
    
    // DFS 2: Calculate the sum of distances for each node using the parent-child relationship
    void dfs2(int node, int parent, const vector<vector<int>>& tree, vector<int>& dist, vector<int>& size, vector<int>& answer, int n) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            answer[child] = answer[node] + (n - 2 * size[child]);
            dfs2(child, node, tree, dist, size, answer, n);
        }
    }
};