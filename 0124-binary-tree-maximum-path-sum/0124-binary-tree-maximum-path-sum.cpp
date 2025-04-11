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
    /*
        Post-order DFS traversal
    */
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to smallest integer value
        dfs(root, maxSum);
        return maxSum;
    }
private:
       int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0; 
       
        int leftMax = max(0, dfs(node->left, maxSum)); 
        int rightMax = max(0, dfs(node->right, maxSum));

        int currentPathSum = node->val + leftMax + rightMax;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftMax, rightMax);
    }
};