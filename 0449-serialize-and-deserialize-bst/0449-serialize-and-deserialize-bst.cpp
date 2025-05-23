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
        if (data.empty())
            return nullptr;

        stringstream ss(data);
        vector<int> preorderVals;
        string val;

        while (getline(ss, val, ',')) {
            preorderVals.push_back(stoi(val));
        }

        int index = 0;
        return build(preorderVals, index, INT_MIN, INT_MAX);
    }

private:
    void preorder(TreeNode* root, stringstream& ss) {
        if (!root) 
            return;

        ss << root->val << ",";

        preorder(root->left, ss);
        preorder(root->right, ss);
    }

    TreeNode* build(vector<int>& vals, int& index, int lower, int upper) {
        if (index == vals.size()) 
            return nullptr;

        int val = vals[index];
        
        if (val < lower || val > upper) 
            return nullptr;

        TreeNode* root = new TreeNode(val);
        index++;

        root->left = build(vals, index, lower, val);
        root->right = build(vals, index, val, upper);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;