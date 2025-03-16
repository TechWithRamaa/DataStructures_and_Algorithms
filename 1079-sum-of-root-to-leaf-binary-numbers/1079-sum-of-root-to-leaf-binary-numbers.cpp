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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafDFS(root, 0);
    }
private:
    // Pre-Order DFS Traversal
    int sumRootToLeafDFS(TreeNode* root, int currentVal) {
        // base condition
        if(!root) {
            return 0;
        }

        // Decimal calcuation by converting binary value into decimal value
        // currentVal = currentVal * 2 + root->val;

        // Binary Calculation using Bitwise operators
        currentVal = (currentVal << 1) | root->val;

        // if it is a leaf 
        // terminating condition
        if(!root->left && !root->right) {
            return currentVal;
        }

        return sumRootToLeafDFS(root->left, currentVal) + sumRootToLeafDFS(root->right, currentVal);
    }
};