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

/*
Always remember this Tree template

Base case: if (!root) return 0;

int result = 0;

if (relevant_condition_on_node)
    result += X;

result += recur(root->left);
result += recur(root->right);

return result;


*/ 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSum = 0;

        if(root->left && isLeaf(root->left)) {
                leftSum = root->left->val;
        }

        leftSum += sumOfLeftLeaves(root->left);
        leftSum += sumOfLeftLeaves(root->right);

        return leftSum;
    }

private:
    bool isLeaf(TreeNode* node) {
        cout << node->val << endl;
        return ((node->left == nullptr) && (node->right == nullptr));
    }
};