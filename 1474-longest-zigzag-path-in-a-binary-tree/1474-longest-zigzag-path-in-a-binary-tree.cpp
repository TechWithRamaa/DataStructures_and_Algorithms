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
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        int leftPathLength = dfs(root -> left, true, 1);
        int rightPathLength = dfs(root -> right, false, 1);

        return std :: max(leftPathLength, rightPathLength);
    }
private:
    int dfs(const TreeNode* root, bool isLeft, int length) {
        if(!root) 
            return length - 1;

        int leftPathLength = dfs(root -> left, true, isLeft ? 1 : length + 1);
        int rightPathLength = dfs(root -> right, false, isLeft ? length + 1 : 1);

        return std :: max(leftPathLength, rightPathLength);
    }
};