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
        if (head == nullptr || head->next == nullptr) { // Base case for empty or single-node list
            return head;
        }

        // Get the middle node to split the list into two halves
        ListNode* middle = getMiddleNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr; // Split the list into two halves

        // Recursively sort both halves
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge the sorted halves and return the sorted list
        return mergeSortedListofTwoLL(leftHead, rightHead);
    }

private:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // Use the slow and fast pointers to find the middle node
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // This should return the middle node
    }

    ListNode* mergeSortedListofTwoLL(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);  // Dummy node to simplify the merge logic
        ListNode* tail = &dummy;

        // Merge the two sorted lists
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

        // Attach the remaining nodes of either list (one of these will be null)
        tail->next = (head1) ? head1 : head2;

        return dummy.next;  // Return the head of the merged list
    }
};
