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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1;  // Base case: empty path sums to 0
        return dfs(root, 0, targetSum, prefixSums);
    }
private:
    int dfs(TreeNode* node, long long currSum, int targetSum, 
                unordered_map<long long, int>& prefixSums) {
        if (!node) return 0;

        currSum += node->val;
        int count = prefixSums[currSum - targetSum];

        // Add current prefix sum to map
        prefixSums[currSum]++;

        // Recurse
        count += dfs(node->left, currSum, targetSum, prefixSums);
        count += dfs(node->right, currSum, targetSum, prefixSums);

        // Backtrack
        prefixSums[currSum]--;

        return count;
    }
};