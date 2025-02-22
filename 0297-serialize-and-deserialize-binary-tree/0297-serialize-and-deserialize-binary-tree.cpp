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
        if (!root)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string serializedString = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                serializedString += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                serializedString += "#,";
            }
        }

        if (!serializedString.empty()) {
            serializedString.pop_back();
        }

        return serializedString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<string> tokens;
        string token;
        istringstream iss(data);

        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (tokens[i] != "#") {
                node->left  = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }

            i++;

            if (i >= tokens.size()) {
                break;
            }

            if (tokens[i] != "#") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
          
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));