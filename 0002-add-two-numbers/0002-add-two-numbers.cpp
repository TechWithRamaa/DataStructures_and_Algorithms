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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        
        ListNode* list1 = l1, *list2 = l2;
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        
        while(list1 || list2 || carry > 0) {
            sum = carry;
            
            if(list1) {
                sum += list1->val;
                list1 = list1->next;
            }
            
            if(list2) {
                sum += list2->val;
                list2 = list2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current -> next;
        }
        
        return dummyHead->next;
    }
};