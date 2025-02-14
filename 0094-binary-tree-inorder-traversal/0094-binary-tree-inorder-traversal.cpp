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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderDFS(root, result);
        return result;
    }
    
private:
    /* Recursive approach */
    void inorderDFS(TreeNode* root, vector<int>& result) {
        if(!root)
            return;
        
        inorderDFS(root->left, result);
        result.push_back(root->val);
        inorderDFS(root->right, result);
    }
    
    /* Iterative approach */
    vector<int> inorderIterative(TreeNode* root) {
        if(!root) 
            return {};
        
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        while(current || !st.empty()) {
            while(current) {
                st.push(current);
                current = current->left;
            }
            
            TreeNode* node = st.top();
            st.pop();
            
            result.push_back(node->val);
            
            current = node->right;
        }
        
        return result;
    }

};