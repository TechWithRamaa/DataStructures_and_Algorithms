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
        
        // park at 1 node before actual left
        ListNode dummy(0);
        dummy.next = head;

        ListNode* temp = &dummy;
        for(int i = 1; i < left; i++) 
            temp = temp->next;
        
        ListNode* nodeBeforeReversal = temp;

        cout << "node before reversal - " << temp->val << endl;
        cout << "left start - " << temp->next->val << endl;

        ListNode *leftHead = temp->next;
        ListNode *actualNext, *prev = nullptr;
        ListNode *current = leftHead;

        for(int i = 0; i <= (right - left); i++) {
            actualNext = current->next;
            current->next = prev;

            prev = current;
            current = actualNext;
        }

        nodeBeforeReversal->next = prev;
        leftHead->next = current;

        return dummy.next;
    }
};