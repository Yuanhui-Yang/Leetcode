23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Comp {
    bool operator() (const ListNode * a, const ListNode * b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        ListNode * dummy = new ListNode(-1), * node = dummy;
        for (const auto & i : lists) {
            if (i) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            ListNode * top = pq.top();
            pq.pop();
            node->next = top;
            node = node->next;
            top = top->next;
            if (top) {
                pq.push(top);
            }
        }
        return dummy->next;
    }
};