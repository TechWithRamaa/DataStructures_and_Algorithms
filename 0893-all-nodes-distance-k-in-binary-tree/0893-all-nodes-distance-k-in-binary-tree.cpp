/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void getParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();

            if(current->left) {
                parentMap[current->left] = current; 
                queue.push(current->left);
            }

            if(current->right) {
                parentMap[current->right] = current; 
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        getParentMap(root, parentMap);

        queue<TreeNode*> queue;
        queue.push(target);

        unordered_map<TreeNode*, bool> visitedMap;
        visitedMap[target] = true;

        int currentDistance = 0;

        while(!queue.empty()) {
            if(currentDistance == k)
                break;

            int qSize = queue.size();
            for(int i = 0; i < qSize; i++) {
                TreeNode *current = queue.front();
                queue.pop();

                if(current->left && !visitedMap[current->left]) {
                    queue.push(current->left);
                    visitedMap[current->left] = true;
                }

                if(current->right && !visitedMap[current->right]) {
                    queue.push(current->right);
                    visitedMap[current->right] = true;
                }

                if(parentMap[current] && !visitedMap[parentMap[current]]) {
                    queue.push(parentMap[current]);
                    visitedMap[parentMap[current]] = true;
                }
            }
            currentDistance += 1;
        }

        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        
        return result;
      }
};