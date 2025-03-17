/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    
    stack<TreeNode*> tree;

    void pushLeftNodes(TreeNode* root) {
        while (root) {
            tree.push(root);
            root = root->left;
        }
    }

public:
    
    BSTIterator(TreeNode* root) { pushLeftNodes(root); }

    int next() {
        // defensive evaluation
        if (hasNext()) {
            TreeNode* node = tree.top();
            tree.pop();
            
            // Dont forget to process right nodes 
            // lazy evaluation 
            if(node->right)
                pushLeftNodes(node->right);

            return node->val;
        } else {
            throw out_of_range("No more elements in the iterator.");
        }
    }

    bool hasNext() { return !tree.empty(); }   
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */