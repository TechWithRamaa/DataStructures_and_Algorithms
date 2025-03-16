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
    // Approach - Combination of LCA & Depth of the Binary tree problems
    // Post Order DFS Traversal
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return getLCAoftheDeepestNodes(root).second;
    }
private:
    pair<int, TreeNode*> getLCAoftheDeepestNodes(TreeNode* root) {
        if(!root) {
            return {0, nullptr};
        }

        auto left = getLCAoftheDeepestNodes(root->left);
        auto right = getLCAoftheDeepestNodes(root->right);

        if(left.first > right.first) {
            return {left.first + 1, left.second};
        } else if(left.first < right.first) {
            return {right.first + 1, right.second};
        } else {
            return {left.first + 1, root};
        }
    }
};