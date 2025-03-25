/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Approach 1 
    // Recursive - Tap into the property of BST unlike the LCA, LCA III on Binary trees
    // We dont have to traverse all the paths
    // Efficient if we leverage the Binary Search property
    // O ( log n ) for Balanced BST

    // Approach 2
    // Iterative - Tap into the property of BST unlike the LCA, LCA III on Binary trees
    // We dont have to traverse all the paths
    // Efficient if we leverage the Binary Search property
    // O ( log n ) for Balanced BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) 
                root = root->left;
            
            else if (p->val > root->val && q->val > root->val) 
                root = root->right;
            else 
                return root;
        }
        
        return nullptr;  
    }
};