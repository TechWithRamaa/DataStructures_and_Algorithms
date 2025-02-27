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
    // Approach 1 -> Two Pointer Approach ( Iterative )
    // TC ~ O ( n + m )
    // Useful for Merge Sort Algorithm 
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        // whenever there is a scenario involving
        // creation of new nodes or deletion of nodes
        // this operation can involve at head or tail
        // so introducing dummy head will generalize the solution
        // edge cases don't ve to be handled

        while(list1 && list2) {
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) {
            temp->next = list1;
        }

        if(list2) {
            temp->next = list2;
        }

        return dummy->next;
    }

    // Approach 2 -> Recursion
    // May this solution type be useful in solving Merge K sorted lists
    // TC ~ O ( n + m ) + Recursice Stack Overhead ~ O ( n + m )
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) 
            return list2;
        
        if(!list2)
            return list1;

        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1; // I forget to return here
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2; // I forget to return here
        }
    }
};