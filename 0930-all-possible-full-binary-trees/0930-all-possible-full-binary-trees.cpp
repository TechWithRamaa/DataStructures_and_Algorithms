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
        // this vector is used for storing root nodes of all possible full binary trees
        vector<TreeNode*> trees; 

         if(!cache[n].empty()) return cache[n]; 

        // full-binary not possible for when n is even, so returning empty result
        if(n % 2 == 0 ) {
           cache[n] = trees;
           return trees; 
        }
    
        if(n == 1) {
            trees.push_back(new TreeNode(0));
            cache[n] = trees;
            return trees;
        }

        // constructing tree 
        for(int noOfLeftNodes = 1; noOfLeftNodes < n; noOfLeftNodes+=2) {
            int noOfRightNodes = n - 1 - noOfLeftNodes;

            vector<TreeNode*> leftSubTrees = allPossibleFBT(noOfLeftNodes);
            vector<TreeNode*> rightSubTrees = allPossibleFBT(noOfRightNodes);

            for(TreeNode* leftNode: leftSubTrees) {
                for(TreeNode* rightNode: rightSubTrees) {
                    TreeNode* rootNode = new TreeNode(0);
                    rootNode -> left = leftNode;
                    rootNode -> right = rightNode;

                    trees.push_back(rootNode);
                }
            }
        }

        cache[n] = trees;
        return trees;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        /* 
        This problem can be solved using Recursion
        Recursion is a suitable technique to generate all possible Full Binary Trees
        
        Bigger problem can be broken down into smaller sub-problem and results of sub-problems
        can be utilized to arrive at final solution for bigger problem

        Overlapping sub-problems are found and hence results of sub-problems 
        can be stored in a data-structure and can be re-used for efficient comput
        */

        vector<vector<TreeNode*>> cache(n+1);    //  this datastructure is used for memoization of results

        return allPossibleFBT(n, cache);
    }
};