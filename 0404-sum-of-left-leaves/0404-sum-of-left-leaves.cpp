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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        
        if(isLeaf(root))
            return 0;

        int leftSum = 0;

        if(root->left && isLeaf(root->left)) {
            if(root->right && isLeaf(root->right))
                leftSum = root->left->val;
            else 
                leftSum = root->left->val + sumOfLeftLeaves(root->right);
            
            return leftSum;
        }

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

private:
    bool isLeaf(TreeNode* node) {
        cout << node->val << endl;
        return ((node->left == nullptr) && (node->right == nullptr));
    }
};