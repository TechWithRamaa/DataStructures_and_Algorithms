/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        Node* leftMostNode = root;
         Node* current = leftMostNode;

        while(leftMostNode->left) {  // checking one-level down from current level
            current = leftMostNode;
            while(current) { // checking at current level
                current->left->next = current->right; // connecting within same sub-tree

                if(current->next) { // connecting between 2 different sub-tree component
                    current->right->next = current->next->left;
                }
                current = current->next; // traversing between differnt sub-tree within same level
            }
            leftMostNode = leftMostNode->left; // going to next level down
        }

        return root;
    }
};