/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
In the N-ary tree serialization and deserialization problem, 
preorder DFS is a natural fit because it lets us process each node 
before its children, capturing both the node's value and 
the number of its children in one pass. 

During serialization, we record each node as <value> <number_of_children> 
and recursively serialize its children. Deserialization is just as clean — 

we read the value and child count from the stream 
(using istringstream for space-separated parsing) and recursively rebuild the tree. 

This approach avoids the complexity of BFS, which struggles with 
variable child counts and structural ambiguity, 
making DFS the more elegant and scalable solution.

*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root)
            return "";

        string res;
        dfsSerialize(root, res);

        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty())
            return nullptr;

        istringstream iss(data);
        return dfsDeserialize(iss);
    }

private:
    void dfsSerialize(Node* node, string& res) {
        if (!node)
            return;

        res +=
            to_string(node->val) + " " + to_string(node->children.size()) + " ";

        for (Node* child : node->children) {
            dfsSerialize(child, res);
        }
    }

    Node* dfsDeserialize(istringstream& iss) {
        int val, size;
        iss >> val >> size;

        Node* node = new Node(val);

        for (int i = 0; i < size; ++i) {
            node->children.push_back(dfsDeserialize(iss));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));