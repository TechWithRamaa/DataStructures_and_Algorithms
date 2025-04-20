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
    /*
    To solve 655. Print Binary Tree, we use a two-pass approach. 
    In the first pass, we compute the height of the binary tree. 
    
    This helps us define the matrix dimensions: the number of rows equals the tree's height,
     and the number of columns is 2^height - 1. 
     
    In the second pass, we perform a preorder DFS to fill the matrix. 
    For each node, we place its value at row = depth and col = (left + right) / 2, 
    applying a tree partitioning logic. 
    
    The left child is recursively placed in the range (left, mid - 1) 
    and the right child in (mid + 1, right). 
    
    This ensures that each node is centered in its subtree's horizontal space, 
    producing the desired visual structure of the tree.
    */
private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root || left > right) return;
        
        int mid = (left + right) / 2;
        res[row][mid] = to_string(root->val);
        
        fill(root->left, res, row + 1, left, mid - 1);
        fill(root->right, res, row + 1, mid + 1, right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);

        const int ROWS = height;
        const int COLS = (1 << height) - 1;  // 2^height - 1
        
        vector<vector<string>> res(ROWS, vector<string>(COLS, ""));
        fill(root, res, 0, 0, COLS - 1);
        
        return res;
    }
};