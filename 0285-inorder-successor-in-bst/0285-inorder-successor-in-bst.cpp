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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        TreeNode* current = root;
        
        while(current) {
            if(p->val < current->val) {
                successor = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        return successor;
    }
};