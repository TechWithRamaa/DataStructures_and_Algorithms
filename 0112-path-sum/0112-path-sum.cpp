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
    /*
    Pre-Order DFS Traversal
    */
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preOrderDFS(root, 0, targetSum); 
    }
private:
    bool preOrderDFS(TreeNode *root, int currentSum, int targetSum) {
        if(!root)
            return false;

        currentSum += root->val;

        if(!root->left && !root->right) {
            if(currentSum == targetSum)
                return true;
            else
                return false;
        }
        
        return preOrderDFS(root->left, currentSum, targetSum) 
                || preOrderDFS(root->right, currentSum, targetSum);
    }
};