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
    int diameterOfBinaryTree(TreeNode* root) { 
        int diameter = 0; 
        diameterOfBinaryTree(root, diameter);
        return diameter;
    }

private:
    // returns depth or height & updates maxDiameter at each node
    // post order DFS traversal
    // longest path btwn any two nodes 
    // no of edges btwn nodes in the longest path 
    // not the actual no of nodes in the longest path
    // path may or may not pass through the root
    int diameterOfBinaryTree(TreeNode* root, int& maxDiameter) {
        if(!root) 
            return 0;

        int leftHeight = diameterOfBinaryTree(root->left, maxDiameter);
        int rightHeight = diameterOfBinaryTree(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};