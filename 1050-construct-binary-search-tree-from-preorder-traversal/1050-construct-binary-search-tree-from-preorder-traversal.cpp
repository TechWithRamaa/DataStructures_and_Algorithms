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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode* buildBST(vector<int>& preorder, int& index, int lowerBound, int upperBound) {
        if(index >= preorder.size())
            return nullptr;

        int rootVal = preorder[index];

        if(lowerBound >= rootVal || rootVal >= upperBound)
            return nullptr;

        index++;

        TreeNode* root = new TreeNode(rootVal);

        root->left = buildBST(preorder, index, lowerBound, rootVal);
        root->right = buildBST(preorder, index, rootVal, upperBound);

        return root;
    }
};