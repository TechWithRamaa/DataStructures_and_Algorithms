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
    // Very interesting problem
    // Approach 1
    // Convert the linked list to vector or array
    // Use Two-Pointer approach to verify if the vector or array is palindrome

    // Approach 2
    // Add every element from the linked list into Stack 
    // As Stack follows LIFO, pop the stack & keep comparing from the head of the LL
    // Naturally traversing LL from the HEAD & LIFO of Stack will help verify if the LL is a palindrome

    // Approach 3
    // Find the middle node of the LL
    // Reverse the second of the LL
    // Compare the Palindrome for first half & reversed half
    // Reverse the second half for restoration
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode* middle = getMiddleNode(head);
        ListNode* secondHalfStart = reverseLL(middle);

        ListNode* firstHalfHead = head;
        ListNode* secondHalfHead = secondHalfStart;

        bool result = true;
        
        while(secondHalfHead) {
            if(firstHalfHead->val != secondHalfHead->val) {
                result = false;
                break;
            }
            
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }

        reverseLL(secondHalfStart);

        return result;   
    }

private:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; 
    }

    ListNode* reverseLL(ListNode* node) {
        ListNode* previous = nullptr;
        ListNode* current = node;

        while(current) {
            ListNode* actualNext = current->next;
            current->next = previous;

            previous = current;
            current = actualNext;
        }

        return previous; // new head
    }
};