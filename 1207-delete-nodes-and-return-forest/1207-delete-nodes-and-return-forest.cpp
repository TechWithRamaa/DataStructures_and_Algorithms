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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forests;
        unordered_set<int> deleteNodes(to_delete.begin(), to_delete.end());
        
        TreeNode* newRoot = dfs(root, forests, deleteNodes);
        if(newRoot)
            forests.push_back(newRoot);
            
        return forests;
    }

private:
    // PostOrder DFS
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& forests, unordered_set<int>& deleteNodes) {
        if(!root)
            return nullptr;
        
        root->left = dfs(root->left, forests, deleteNodes);
        root->right = dfs(root->right, forests, deleteNodes);
        
        if(deleteNodes.count(root->val)) {
            if(root->left) 
                forests.push_back(root->left);
            if(root->right)
                forests.push_back(root->right);
            
            return nullptr; // current node is deleted
        }
        
        return root;
    }
};