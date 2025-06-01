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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = buildParentMapAndgetStartNode(root, start, parentMap);

        int time = 0;

        unordered_set<TreeNode*> visited;

        queue<TreeNode*> q;
        q.push(startNode);
        visited.insert(startNode);

        while(!q.empty()) {
            int qSize = q.size();
            bool infected = false;

            for(int i = 0; i < qSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                
                if(current->left && visited.count(current->left) == 0) {
                    visited.insert(current->left);
                    q.push(current->left);
                    infected = true;
                }

                if(current->right && visited.count(current->right) == 0) {
                    visited.insert(current->right);
                    q.push(current->right);
                    infected = true;
                }

                if(parentMap[current] && visited.count(parentMap[current]) == 0) {
                    visited.insert(parentMap[current]);
                    q.push(parentMap[current]);
                    infected = true;
                }
            }

            if(infected)
                time++; // 1 level completed; incrementing after complete infection at current level
        }

        return time;
    }
private:
    TreeNode* buildParentMapAndgetStartNode(TreeNode* root, int start,
                                       unordered_map<TreeNode*, TreeNode*> &parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode;

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->val == start) 
                startNode = current;

            if(current->left) {
                parentMap[current->left] = current; 
                q.push(current->left);
            }
            
            if(current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }

        return startNode;
    }
};