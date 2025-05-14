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
        stack<int> s1, s2;

        ListNode* head1 = l1;
        while(head1) {
            s1.push(head1->val);
            head1 = head1->next;
        }

        ListNode* head2 = l2;
         while(head2) {
            s2.push(head2->val);
            head2 = head2->next;
        }

        ListNode* head = nullptr;

        int sum = 0, carry = 0;
        while(!s1.empty() || !s2.empty() || carry != 0) {
            sum = carry;

            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            // Building list from Tail
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};