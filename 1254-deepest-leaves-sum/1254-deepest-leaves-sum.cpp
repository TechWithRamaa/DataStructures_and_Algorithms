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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int deepestLevelSum = 0;
        
        while(!q.empty()) {
            deepestLevelSum = 0; // reset at every level
            
            int qSize = q.size();
            for(int i = 0; i < qSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                deepestLevelSum += current->val;
                
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
        }
        
        return deepestLevelSum;
    }
};