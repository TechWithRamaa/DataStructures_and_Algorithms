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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        // when only 1 node is present
        // we need minimum 2 nodes to run this algorithm
        if(!head->next)
            return head;
    
        if(k == 0) 
            return head;
        
        // find length of the linkedlist 
        // find last node

        // so length logic is modified to fit both
        // of these tasks

        ListNode* temp = head;
        int length = 1;
        while(temp->next) {
            length++;
            temp = temp->next;
        }

        k = k % length;
        if(k == 0)
            return head;
        
        // make the list circular by
        // linking last node to head
        temp->next = head;

        // head changes after rotation
        // break the circular link at the new last node
        temp = head;
        for(int i = 1; i < (length - k); i++) 
            temp = temp->next;
        

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};