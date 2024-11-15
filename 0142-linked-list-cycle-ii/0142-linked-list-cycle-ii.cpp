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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)     
            return nullptr;
        
        ListNode *slow = head, *fast = head, *start = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                while(start != slow) {
                    start = start -> next;
                    slow = slow -> next;
                }
                return start;
            }
        }
        return nullptr;
    }
};