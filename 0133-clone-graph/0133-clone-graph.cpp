/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraphHelper(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        if (!node) return nullptr;

        // If the node is already cloned, return the clone
        if (cloneMap.find(node) != cloneMap.end()) 
            return cloneMap[node];
        

        // Clone the current node
        Node* clone = new Node(node->val);
        cloneMap[node] = clone;

        // Clone all neighbors recursively
        for (Node* neighbor : node->neighbors) 
            clone->neighbors.push_back(cloneGraphHelper(neighbor, cloneMap));
        
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloneMap; // To store original->clone mapping
        return cloneGraphHelper(node, cloneMap);
    }
};