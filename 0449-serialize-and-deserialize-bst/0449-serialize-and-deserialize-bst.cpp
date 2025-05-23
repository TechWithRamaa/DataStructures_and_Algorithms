/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        preorder(root, ss);

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        
        vector<int> tokens;
        string token;
        stringstream ss(data);

        while(getline(ss, token, ',')) {
            tokens.push_back(stoi(token));
        }

        int index = 0;
        return buildBST(index, tokens, INT_MIN, INT_MAX);
    }

private:
    void preorder(TreeNode* root, stringstream& ss) {
        if(!root)
            return;
        
        ss << root->val << ",";

        preorder(root->left, ss);
        preorder(root->right, ss);
    }

    TreeNode* buildBST(int& index, vector<int>& preOrderVals, int lowerBound, int upperBound) {
        if(index == preOrderVals.size())
            return nullptr;

        int value = preOrderVals[index];

        if(value < lowerBound || value > upperBound) 
            return nullptr;

        TreeNode* root = new TreeNode(value);
        index++;

        root->left = buildBST(index, preOrderVals, lowerBound, value);
        root->right = buildBST(index, preOrderVals, value, upperBound);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;