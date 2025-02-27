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
    // Approach 1 - Counting Based
    // Two Pass 
    // TC ~ O ( n )
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* current = head;

        while(current) {
            count += 1;
            current = current->next;
        }

        int mid = count / 2;
        current = head;
        while(mid) {
            mid -= 1;
            current = current->next;
        }

        // current points at exact middle in case of odd number of nodes in the linked list
        // current points at exact second middle in case of even number of nodes in the linked list
        
        return current; 
    }


};