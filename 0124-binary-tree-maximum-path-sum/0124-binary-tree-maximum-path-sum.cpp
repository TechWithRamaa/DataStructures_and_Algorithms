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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to smallest integer value
        dfs(root, maxSum);
        return maxSum;
    }
private:
       int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0; // Base case: null nodes contribute 0 to the path sum

        // Recursively compute the maximum path sum for the left and right subtrees
        int leftMax = max(0, dfs(node->left, maxSum)); // Ignore negative sums
        int rightMax = max(0, dfs(node->right, maxSum));

        // Compute the maximum path sum that passes through the current node
        int currentPathSum = node->val + leftMax + rightMax;

        // Update the global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum sum of a path ending at this node
        return node->val + max(leftMax, rightMax);
    }
};