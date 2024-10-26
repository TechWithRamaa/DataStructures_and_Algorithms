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
private:
    vector<TreeNode*> allPossibleFBT(int n, vector<vector<TreeNode*>>& cache) {
        vector<TreeNode*> result;

        if(n % 2 ==0 ) {
           cache[n] = result;
           return result; 
        }
    
        if(n == 1) {
            result.push_back(new TreeNode(0));
            cache[n] = result;
            return result;
        }

        if(!cache[n].empty()) return cache[n];

        for(int noOfLeftNodes = 1; noOfLeftNodes < n; noOfLeftNodes+=2) {
            int noOfRightNodes = n - 1 - noOfLeftNodes;

            vector<TreeNode*> leftSubTrees = allPossibleFBT(noOfLeftNodes);
            vector<TreeNode*> rightSubTrees = allPossibleFBT(noOfRightNodes);

            for(TreeNode* leftNode: leftSubTrees) {
                for(TreeNode* rightNode: rightSubTrees) {
                    TreeNode* rootNode = new TreeNode(0);
                    rootNode -> left = leftNode;
                    rootNode -> right = rightNode;

                    result.push_back(rootNode);
                }
            }
        }

        cache[n] = result;
        return result;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> cache(n+1);     

        return allPossibleFBT(n, cache);
    }
};