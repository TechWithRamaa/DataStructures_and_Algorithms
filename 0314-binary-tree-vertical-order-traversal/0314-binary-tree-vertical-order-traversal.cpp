/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
   
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)
            return {};

        map<int, vector<int>> colMap;
        queue<pair<TreeNode*, int>> q; // pair of node and column index
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            colMap[col].push_back(node->val);

            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }

        vector<vector<int>> result;
        for (auto& [col, vals] : colMap)
            result.push_back(vals);

        return result;
    }
};