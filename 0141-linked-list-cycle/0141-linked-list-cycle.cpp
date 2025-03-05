class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) 
            return false; // If the list is empty or has only one node, no cycle is possible

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps

            if (slow == fast) {         // If they meet, there is a cycle
                return true;
            }
        }

        return false; // If fast reaches NULL, no cycle exists
    }
};
