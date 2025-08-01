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

// PreOrder DFS 
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodesSoFar(root, INT_MIN);
    }

private:
    int goodNodesSoFar(TreeNode* root, int maxSoFar) {
        if(!root)
            return 0;

        int isItAGoodNode = 0;

        if(root->val >= maxSoFar) {
            isItAGoodNode = 1; 
            maxSoFar = max(maxSoFar, root->val);
        }

        return isItAGoodNode + goodNodesSoFar(root->left, maxSoFar) + goodNodesSoFar(root->right, maxSoFar);
    }
};