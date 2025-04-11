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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode *root, int currentNum) {
        if(!root)
            return 0;
        
        currentNum = (currentNum * 10) + root->val;

        if(!root->left && !root->right)
            return currentNum;
        
        return dfs(root->left, currentNum) + dfs(root->right, currentNum);
    }
};