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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Dummy node before head to handle edge cases easily
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Pointer to the node before the current group
        ListNode* prevGroupTail = dummy;

        while (true) {
            // Find the end of the current k-group
            ListNode* kthNode = getKthNode(prevGroupTail, k);
            if (!kthNode) break;  // Not enough nodes left

            ListNode* groupStart = prevGroupTail->next;
            ListNode* nextGroupHead = kthNode->next;

            // Reverse k nodes
            ListNode* prev = nextGroupHead;
            ListNode* curr = groupStart;

            while (curr != nextGroupHead) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group with reversed group
            prevGroupTail->next = kthNode;
            prevGroupTail = groupStart;  // This is now the tail of the group
        }

        return dummy->next;
    }

private:
    // Return k-th node from `start`, or nullptr if not enough nodes
    ListNode* getKthNode(ListNode* start, int k) {
        while (start && k > 0) {
            start = start->next;
            k--;
        }
        return start;
    }
};
