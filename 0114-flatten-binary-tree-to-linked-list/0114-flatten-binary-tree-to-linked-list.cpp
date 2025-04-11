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

/*
    3 Approaches are there 

    1) Reverse Post-Order traversal using Recursion
    2) Reverse Post-Order traversal using Iteration & Stack
    3) Morris traversal

    Implemented Reverse Post-Order (Right -> Left -> Root) here
*/
class Solution {
public:
    TreeNode *prev = nullptr;

    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;

        prev = root;
    }
};