/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

/*
    Mental Model
    ✅ Inorder traversal is crucial for solving BST-based problems efficiently.
    ✅ Use pointers (prev & head) to transform the BST while traversing.
    ✅ Remember circular linkage at the end to complete the DLL.
*/
class Solution {
private:
    void inorder(Node* root, Node*& head, Node*& prev) {
        if (!root)
            return;

        inorder(root->left, head, prev);

        if (!head)
            head = root;

        if (prev) {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        inorder(root->right, head, prev);
    }

public:
    // Approach 1 - Recursion - System Call Stack
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;

        Node *head = nullptr, *prev = nullptr;

        inorder(root, head, prev);

        prev->right = head;
        head->left = prev;

        return head;
    }
};