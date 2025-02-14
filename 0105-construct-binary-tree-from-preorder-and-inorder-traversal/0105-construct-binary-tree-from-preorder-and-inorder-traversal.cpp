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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderIndexMap;
        const int N = preorder.size();
        
        for(int i = 0; i < N; i++) {
            inOrderIndexMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, inorder, inOrderIndexMap, 0, 0, N-1);
    }
private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder,
                              unordered_map<int, int>& inOrderIndexMap,
                             int preorderStart, int inorderStart, int inorderEnd) {
        
        if(inorderStart > inorderEnd)
            return NULL;
        
        int rootVal = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int inorderIndex = inOrderIndexMap[rootVal];
        int leftSubTreeSize = inorderIndex - inorderStart;
        
        root->left =  buildTreeHelper(preorder, inorder, inOrderIndexMap, 
                                      preorderStart + 1, inorderStart, inorderIndex - 1);
        root->right =  buildTreeHelper(preorder, inorder, inOrderIndexMap, 
                                       preorderStart + 1 + leftSubTreeSize, inorderIndex + 1, inorderEnd);
        
        return root;
    }
};