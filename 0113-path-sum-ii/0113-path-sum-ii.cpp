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
    // Classic DFS + Backtracking
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;

        preOrderDFS(root, targetSum, 0, path, result);

        return result;
    }

private:
    void preOrderDFS(TreeNode* root, int targetSum, int currentSum, 
                        vector<int>& path, vector<vector<int>>& result) {
        if(!root)
            return;
        
        path.push_back(root->val);
        currentSum += root->val;

        if(currentSum == targetSum && isLeaf(root)) {
            result.push_back(path);
        } else {
            preOrderDFS(root->left, targetSum, currentSum, path, result);
            preOrderDFS(root->right, targetSum, currentSum, path, result);
        }

        // Backtracking
        path.pop_back();
    }

    bool isLeaf(TreeNode* root) {
        return ((!root->left) && !(root->right));
    }
};