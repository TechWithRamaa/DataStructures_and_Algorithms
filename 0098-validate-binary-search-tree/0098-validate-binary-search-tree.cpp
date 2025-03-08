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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN , LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long long leftBound, long long rightBound) {
        if(!root) 
            return true;
        
        if(root->val <= leftBound || root->val >= rightBound) 
            return false;

        return isValidBST(root->left, leftBound, root->val)
                && isValidBST(root->right, root->val, rightBound);
    }
};