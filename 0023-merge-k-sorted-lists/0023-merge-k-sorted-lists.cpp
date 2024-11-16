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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        int n = lists.size();

        while(n > 1) {
            for(int i = 0; i < n/2; i++) 
                lists[i] = mergeTwoSortedLists(lists[i], lists[n - 1 - i]);
        
            n = (n + 1 ) / 2;
        }

        return lists[0];
    }
private:
    ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2) {
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode dummy(0);
        ListNode* current = &dummy;

        while(head1 && head2) {
            if(head1->val <= head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        current->next = (head1) ? head1 : head2;

        return dummy.next;
    }
};