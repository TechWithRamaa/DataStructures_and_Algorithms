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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* lca = findLCA(root, p, q);

        int leftDepth = findDepth(lca, p);
        int rightDepth = findDepth(lca, q);

        return leftDepth + rightDepth;
    }
private:
    // post-order DFS
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if(!root || root->val == p || root->val == q) 
            return root;
        
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if(left && right)
            return root;

        return left ? left : right;        
    }

    int findDepth(TreeNode* root, int target, int depth = 0) {
        if(!root)
            return -1;
        
        if(root->val == target) 
            return depth;
        
        int leftDepth = findDepth(root->left, target, depth + 1);
        if(leftDepth != -1)
            return leftDepth;
        
        return findDepth(root->right, target, depth + 1);
    }
};