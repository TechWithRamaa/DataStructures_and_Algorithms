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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> solution;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;

            for(int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if(node->left) 
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);   
            }

            solution.push_back(currentLevel);
        }

        return solution;
    }
};