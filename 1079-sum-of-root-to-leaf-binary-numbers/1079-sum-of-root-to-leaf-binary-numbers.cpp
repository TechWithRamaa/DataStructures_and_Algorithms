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
    int sumRootToLeaf(TreeNode* root) {
        //return sumRootToLeafDFS(root, 0);
        return sumRootToLeafBFS(root);
    }
private:
    // Pre-Order DFS Traversal
    // Recursion 
    // TC ~ O ( N ) ; SC ~ O ( N )
    int sumRootToLeafDFS(TreeNode* root, int currentVal) {
        // base condition
        if(!root) {
            return 0;
        }

        // Decimal calcuation by converting binary value into decimal value
        // currentVal = currentVal * 2 + root->val;

        // Binary Calculation using Bitwise operators
        currentVal = (currentVal << 1) | root->val;

        // if it is a leaf 
        // terminating condition
        if(!root->left && !root->right) {
            return currentVal;
        }

        return sumRootToLeafDFS(root->left, currentVal) + sumRootToLeafDFS(root->right, currentVal);
    }

    // BFS Traversal
    // Iterative 
    // TC ~ O ( N ) ; SC ~ O ( N )
    int sumRootToLeafBFS(TreeNode* root) {
        int totalSum = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            TreeNode* node = current.first;
            int currentValue = current.second;

            currentValue = currentValue << 1 | node->val;

            if(!node->left && !node->right) {
                totalSum += currentValue;
            }

            if(node->left) 
                q.push({node->left, currentValue});
            if(node->right) 
                q.push({node->right, currentValue});
        }

        return totalSum;
    }

};