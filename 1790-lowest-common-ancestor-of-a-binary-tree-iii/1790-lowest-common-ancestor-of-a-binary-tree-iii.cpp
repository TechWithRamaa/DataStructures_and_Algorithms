/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    /*
        Identical to 2 Linked lists intersection
        2 pointers 
        TC ~ O ( h )
    */
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;

        while (a != b) {
            a = (a == nullptr) ? q : a->parent;
            b = (b == nullptr) ? p : b->parent;
        }

        return a; // or return b, since both are the same at this point
    }
};