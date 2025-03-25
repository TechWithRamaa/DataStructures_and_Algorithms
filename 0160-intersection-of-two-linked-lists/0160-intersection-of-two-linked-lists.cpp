/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        Both pointers traverse the same total length

        If lists have different lengths, one pointer will catch up after switching to the other list.

        This equalizes their distances.

        TC ~ O ( m + n )
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        while(l1 != l2) {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;                
        }
        
        return l1;
    }
};