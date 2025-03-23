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
    // Approach - BFS 
    // CRUX - Choosing the right data structure to maintain the traversal in the 
    // order asked in the problem statement

    // key is to come up with a custom data structure that helps us to manage the 
    // the data in the order .. which internally takes care of sorting

    // hero - map<int, map<int, multiset<int>>> nodeMap;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodeMap;

        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});

        while(!que.empty()) {
            auto [node, position] = que.front();
            que.pop();

            int colIndex = position.first;
            int rowIndex = position.second;

            nodeMap[colIndex][rowIndex].insert(node->val);

            if(node->left) 
                que.push({node->left, {colIndex - 1, rowIndex + 1}});
            
            if(node->right)
                que.push({node->right, {colIndex + 1, rowIndex + 1}});
        }


        vector<vector<int>> result;
        for(auto [columnIndex, rows] : nodeMap) {
            vector<int> temporary;
            for(auto [rowIndex, mset] : rows) {
                temporary.insert(temporary.end(), mset.begin(), mset.end());
            }
            result.push_back(temporary);
        }

        return result;
    }
};