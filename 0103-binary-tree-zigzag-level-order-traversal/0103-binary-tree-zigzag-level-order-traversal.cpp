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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> result;
        bool isFromLeftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
            }
            
            if(!isFromLeftToRight)
                reverse(currentLevel.begin(), currentLevel.end());
            
            result.push_back(currentLevel);
            isFromLeftToRight = !isFromLeftToRight;
        }
        
        return result;
    }
};