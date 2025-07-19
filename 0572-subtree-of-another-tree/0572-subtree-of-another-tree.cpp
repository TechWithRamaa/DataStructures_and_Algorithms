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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        
        if(isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) 
            return p == q;

        if(p->val != q->val)
            return false;
        
        bool isLeftTreeSame = isSameTree(p->left, q->left);
        bool isRightTreeSame = isSameTree(p->right, q->right);

        return isLeftTreeSame && isRightTreeSame;
    }
};