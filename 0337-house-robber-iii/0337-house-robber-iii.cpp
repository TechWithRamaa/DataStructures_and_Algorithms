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
    int rob(TreeNode* root) {
        auto finalPair = robHouses(root);
        return max(finalPair.first, finalPair.second);
    }
private:
    pair<int, int> robHouses(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        auto leftSubTreePair = robHouses(root->left);
        auto rightSubTreePair = robHouses(root->right);

        auto withRootPair = root->val + leftSubTreePair.second + rightSubTreePair.second;
        auto withoutRootPair = max(leftSubTreePair.first, leftSubTreePair.second)  + 
                               max(rightSubTreePair.first, rightSubTreePair.second);

        return {withRootPair, withoutRootPair};
    }
};