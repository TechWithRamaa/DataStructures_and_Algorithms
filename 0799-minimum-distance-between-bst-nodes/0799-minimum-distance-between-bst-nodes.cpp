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
    int minDiffInBST(TreeNode* root) {
       int minDiff = INT_MAX;   // Initialize minDiff with the maximum possible value
        TreeNode* prev = nullptr;  // To store the value of the previous node in in-order traversal
        
        // Helper function for in-order traversal
        inorderTraversal(root, prev, minDiff);
        
        return minDiff;
    }
    
    // In-order traversal helper function
    void inorderTraversal(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (!root) return;
        
        // Traverse the left subtree
        inorderTraversal(root->left, prev, minDiff);
        
        // If 'prev' is not null, calculate the difference with the current node
        if (prev) {
            minDiff = min(minDiff, root->val - prev->val);  // Update the minimum difference
        }
        
        // Update 'prev' to the current node
        prev = root;
        
        // Traverse the right subtree
        inorderTraversal(root->right, prev, minDiff);
    }
};