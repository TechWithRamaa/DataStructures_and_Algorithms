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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          // Iterate until we find the LCA
        while (root) {
            // If both p and q are smaller, move to the left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both p and q are larger, move to the right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Otherwise, we found the split point, so root is the LCA
            else {
                return root;
            }
        }
        return nullptr;  // In case the tree is empty, but this won't happen for valid inputs
    }
};