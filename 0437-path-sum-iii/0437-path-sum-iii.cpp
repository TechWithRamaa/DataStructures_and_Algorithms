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

class Solution1 {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return countPaths(root, targetSum)
             + pathSum(root->left, targetSum)
             + pathSum(root->right, targetSum);
    }

private:
    int countPaths(TreeNode* node, long long remainingSum) {
        if (!node) return 0;

        int count = 0;
        if (node->val == remainingSum) count++;

        count += countPaths(node->left, remainingSum - node->val);
        count += countPaths(node->right, remainingSum - node->val);

        return count;
    }
};

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

    /*
    
    | Technique            | Role                                                                               |
    | -------------------- | ---------------------------------------------------------------------------------- |
    | **Pre-order DFS**    | Traverse top-down, so prefix sums are built in root-to-current-node order.         |
    | **Prefix Sum**       | Allow **O(1)** lookup of matching paths instead of recomputing all subpaths.       |
    | **Combined Benefit** | From O(N²) → **O(N)**, while covering **all downward paths starting at any node**. |

    */
};