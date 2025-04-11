/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
        Pre-Order DFS Traversal
    */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string currentPath;

        dfs(root, currentPath, result);

        return result;
    }

private:
    void dfs(TreeNode* root, string currentPath, vector<string> &result) {
        if(!root)
            return;

        if(!currentPath.empty()) {
            currentPath += "->";
        }

        currentPath += to_string(root->val);

        if(!root->left && !root->right)
            result.push_back(currentPath);
        
        dfs(root->left, currentPath, result);
        dfs(root->right, currentPath, result);
    }
};