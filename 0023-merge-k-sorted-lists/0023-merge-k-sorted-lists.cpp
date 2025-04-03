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

struct Compare {
    bool operator()(ListNode* node1, ListNode* node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    // Approach 1 -> BruteForce
    // Merge Sequentially k lists

    // Approach 2 -> Optimized -> most efficient
    // Merge lists in parallel

    // Approach 3 -> Priority Queue / Heap

    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        int k = lists.size();

        if (k == 0)
            return nullptr;

        while (k > 1) {
            for (int i = 0; i < k / 2; i++)
                lists[i] = merge(lists[i], lists[(k - 1 - i)]);

            k = (k + 1) / 2;
        }

        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;

        if (!l2)
            return l1;

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1)
            current->next = l1;
        if (l2)
            current->next = l2;

        return dummy.next;
    }

    // Approach 3
    // Using Priority Queue
    // TC ~ O (N log k)
    // SC ~ O ( k )
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (auto list : lists) {
            if (list)
                minHeap.push(list);
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (!minHeap.empty()) {
            ListNode* currMin = minHeap.top();
            minHeap.pop();

            temp->next = currMin;

            if (currMin->next)
                minHeap.push(currMin->next);

            temp = temp->next;
        }

        return dummy.next;
    }

    // Approach 2 (repeated for practice)
    ListNode* mergeKListsX(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        int n = lists.size();
        while (n > 1) {
            for (int i = 0; i < n / 2; i++)
                lists[i] = mergeTwoSortedLists(lists[i], lists[n - 1 - i]);
            n = (n + 1) / 2;
        }
        return lists[0];
    }

private:
    ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        ListNode dummy(0);
        ListNode* current = &dummy;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
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