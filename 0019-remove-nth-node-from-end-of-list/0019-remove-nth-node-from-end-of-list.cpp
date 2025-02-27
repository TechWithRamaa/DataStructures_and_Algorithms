/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Two-pass approach 
    // ~ O ( 2 * n )
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // I keep forgetting the dummy node
        // dummy node will take care of deleting head node
        // using the same logic as old nodes are deleted
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = head;
        int length = 0;
        while(current) {
            length += 1;
            current = current->next;
        }

        length -= n;
        current = dummy;
        while(length > 0) {
            length--;
            current = current->next;
        }

        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; i++) 
            first = first->next;
        
        while(first) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node
        ListNode* nodeToRemove = second->next;
        second->next = second->next->next;

        delete nodeToRemove;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};