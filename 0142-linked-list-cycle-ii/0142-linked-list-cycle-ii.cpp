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
        
        ListNode *slow = head, *fast = head, *cycleStart = head;

        // Floyd Cycle detection algorithm to detect cycle in a LL
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                // Identifying & returning starting node in the cycle 
                while(cycleStart != slow) {
                    cycleStart = cycleStart -> next;
                    slow = slow -> next;
                }
                return cycleStart;
            }
        }
        return nullptr;
    }
};