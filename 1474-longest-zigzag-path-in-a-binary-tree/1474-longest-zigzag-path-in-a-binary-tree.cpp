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
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        std :: unordered_map<const TreeNode*, std :: pair<int, int>> memo;

        int leftPathLength = dfs(root -> left, true, 1, memo);
        int rightPathLength = dfs(root -> right, false, 1, memo);

        return std :: max(leftPathLength, rightPathLength);
    }
private:
    int dfs(const TreeNode* node, bool isLeft, int length,
            std :: unordered_map<const TreeNode*, std :: pair<int, int>>& memo) {
        
        if(!node) 
            return length - 1;

        if(memo.find(node) != memo.end())
            return isLeft ? memo[node].first : memo[node].second;

        int leftPathLength = dfs(node -> left, true, isLeft ? 1 : length + 1, memo);
        int rightPathLength = dfs(node -> right, false, isLeft ? length + 1 : 1, memo);

        memo[node] = {leftPathLength, rightPathLength};

        return std :: max(leftPathLength, rightPathLength);
    }
};