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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) { 
            return head;
        }

        // Get the middle node of the given LL
        ListNode* middle = getMiddleNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr; // Split the list into two halves

        // Recursively sort both halves of the LL
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Sort & Merge the 2 LLs using MergeSort Algorithm
        return mergeSortedListofTwoLL(leftHead, rightHead);
    }

private:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // Slow and fast pointers to find the middle node
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // This should return the middle node
    }

    ListNode* mergeSortedListofTwoLL(ListNode* head1, ListNode* head2) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        // Merges the two locally sorted lists into a global sorted list 
        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        // Attaches the remaining nodes of either list (one of these will be null)
        tail->next = (head1) ? head1 : head2;

        return dummy.next;  // Returns the head of the merged list
    }
};
