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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* oddList = head;
        ListNode* evenListHead = head->next;
        ListNode* evenList = head->next;
        
        while(evenList && evenList->next) {
            oddList->next = evenList->next;
            evenList->next = oddList->next->next;
            
            oddList = oddList->next;
            evenList = evenList->next;
        }
        oddList->next = evenListHead;
        
        return head;
    }
};