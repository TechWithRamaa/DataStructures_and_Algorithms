/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;

        inorderTraversal(root, prev, minDiff);

        return minDiff;
    }

    void inorderTraversal(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (!root)
            return;

        inorderTraversal(root->left, prev, minDiff);

        if (prev) {
            minDiff =
                min(minDiff,
                    root->val - prev->val); // Update the minimum difference
        }

        prev = root;

        inorderTraversal(root->right, prev, minDiff);
    }
};