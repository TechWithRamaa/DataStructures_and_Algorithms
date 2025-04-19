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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> freq;
        vector<TreeNode*> result;
        
        serialize(root, freq, result);
        
        return result;
    }

private:
    // Post Order DFS Traversal
    string serialize(TreeNode* node, unordered_map<string, int>& freq, vector<TreeNode*>& result) {
        if (!node) return "#";

    
        string left = serialize(node->left, freq, result);
        string right = serialize(node->right, freq, result);

        string key = to_string(node->val) + "," + left + "," + right;

        if (++freq[key] == 2) {
            result.push_back(node);  // only add once when it becomes duplicate
        }

        return key;
    }
};
