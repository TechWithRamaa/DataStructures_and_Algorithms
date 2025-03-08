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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* leftSubTree, TreeNode*rightSubTree) {
        if(!leftSubTree && !rightSubTree)
            return true;

        if((!leftSubTree || !rightSubTree) || (leftSubTree->val != rightSubTree->val)) 
            return false;

        return isSymmetric(leftSubTree->left, rightSubTree->right)
                 && isSymmetric(leftSubTree->right, rightSubTree->left);
    }
};