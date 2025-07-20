class Solution {
public:
    /*
    What makes a valid binary tree?
    
    A valid binary tree must satisfy:
        Only one root – Exactly one node has no parent.
        No multiple parents – A node can have only one parent.
        No cycles – You cannot revisit a node.
        All nodes are connected – Every node must be reachable from the root.
    */

    /*
    Approach
    
    Step 1: Compute indegree of each node from leftChild and rightChild.
    Step 2: Find the root (node with indegree = 0).
            If there’s no root or more than one, return false.
    Step 3: DFS/BFS traversal from root:
            If you visit a node twice → cycle → return false.
    Step 4: Check connectivity by verifying if all nodes were visited.
    */

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        // Step 1: Calculate indegrees
        for (int i = 0; i < n; i++) {
            // when a node has indegree > 1, it has more than 1 parent, which violates Tree Property
            if (leftChild[i] != -1 && ++indegree[leftChild[i]] > 1) 
                return false;

            if (rightChild[i] != -1 && ++indegree[rightChild[i]] > 1) 
                return false;
        }

        // Step 2: Find the root
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) 
                    return false; // More than 1 root

                root = i; // identified first node, potential for a root
            }
        }
        
        if (root == -1) return false; // No root

        // Step 3: DFS
        unordered_set<int> visited;
        
        // dfs traversal + cycle detection
        if (!dfs(root, leftChild, rightChild, visited)) 
            return false;

        // Step 4: Check if all nodes are visited
        return visited.size() == n;
    }

private:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, unordered_set<int>& visited) {
        if (node == -1) return true;
        if (visited.count(node)) return false; // cycle
        visited.insert(node);
        return dfs(leftChild[node], leftChild, rightChild, visited) &&
               dfs(rightChild[node], leftChild, rightChild, visited);
    }
};