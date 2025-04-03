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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return head;
        
        // no need for sublist reversal
        if(left == right) 
            return head;
        
        // creating dummy node before actual head
        // in the stack memory
        ListNode dummy(0);
        dummy.next = head;

        // park 1 node before the left
        // keep in mind we are starting from dummy node
        ListNode* temp = &dummy;
        for(int i = 1; i < left; i++) 
            temp = temp->next;
        
        // park 1 temp variable before actual left
        // so that can be connected with the reversed sublist
        ListNode* nodeBeforeReversal = temp;

        // applying standard reveral logic
        // for sublist reversal
        ListNode *leftHead = temp->next; // actual left -> becomes tail of the sublist
        ListNode *actualNext, *prev = nullptr;
        ListNode *current = leftHead;

        // we need to include left, .... and right also
        // inclusive, so we iterate from 0 to (right - left)
        for(int i = 0; i <= (right - left); i++) {
            actualNext = current->next;
            current->next = prev;

            prev = current;
            current = actualNext;
        }
        // sublist is reversed
        // prev is parked at the head of the sublist
        // main list is connected to the reversed sublist
        nodeBeforeReversal->next = prev;

        // connecting the tail of the sublist to the mainlist
        leftHead->next = current;

        // returning the actual head
        return dummy.next;
    }
};