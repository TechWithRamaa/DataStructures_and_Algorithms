/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        // Deep copy or cloning the list, 
        // deep copy of node is stored in the same list
        // cloned node is stored next to original nodes
        Node* current = head;
        while(current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Including random references cloned nodes from original nodes
        current = head;
        Node* cloned = head->next;
        while(current) {
            if(current->random) 
                current->next->random = current->random->next;

            current = current->next->next;
        }

        // De-linking cloned nodes from original list
        current = head;
        Node* clonedHead = head->next;
        Node* clone = clonedHead;
        while(current) {
            current->next = current->next->next;
            if (clone->next) {
                clone->next = clone->next->next;
            }
            current = current->next;
            clone = clone->next;
        }

        return clonedHead;
    }
};