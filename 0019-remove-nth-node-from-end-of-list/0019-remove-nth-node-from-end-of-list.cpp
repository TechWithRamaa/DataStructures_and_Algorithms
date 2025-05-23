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
    // Two-pass approach 
    // Counting based
    // ~ O ( 2 * n )

    // *******************************
    // The whole crux of it is that you need to stop one node before the node to be deleted
    // *******************************
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // I keep forgetting the dummy node
        // dummy node will take care of deleting head node
        // using the same logic as old nodes are deleted
        
        ListNode* current = head;
        int length = 0;
        while(current) {
            length += 1;
            current = current->next;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        length -= n;
        current = dummy;
        while(length > 0) {
            length--;
            current = current->next;
        }

        // Key trick to note here is 
        // couting pass starts from actual head
        // positioning the nodeToDelete starts from dummy head

        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;

        // this above piece takes care of 
        // 3 cases of delete

        // 1) delete head
        // 2) delete middle
        // 3) delete end

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }

    // Single-pass approach
    // ~ O ( n )
    // Two pointers (not exactly fast and slow pointers)
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // just initialize two pointers
        // as you note the names, it is not slow & fast 
        // as clearly it s not slow & fast pointer approach
        // as they re normal pointers, start from ****** dummy head ******* 
        // no drama 

        // n + 1 times because we start first from dummy
        for (int i = 0; i <= n; i++) 
            first = first->next;
        
        // second exactly stops before n-th node
        while(first) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node
        ListNode* nodeToRemove = second->next;
        second->next = second->next->next;

        // the best part of this logic
        // is that it works for deleting
        // head, middle, tail nodes

        delete nodeToRemove;

        return dummy.next;
    }
};