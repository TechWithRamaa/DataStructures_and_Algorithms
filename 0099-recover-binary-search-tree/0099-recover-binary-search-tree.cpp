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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // Inorder traversal to find the two swapped nodes
        inorder(root, first, second, prev);

        // Swap the values of the two nodes to recover the BST
        if (first && second) {
            swap(first->val, second->val);
        }
    }
private:
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!root) return;

        // Traverse the left subtree
        inorder(root->left, first, second, prev);

        // Detect the swapped nodes
        if (prev && root->val < prev->val) {
            if (!first) {
                // First violation
                first = prev;
            }
            // Second violation
            second = root;
        }
        // Update prev node
        prev = root;

        // Traverse the right subtree
        inorder(root->right, first, second, prev);
    }
};