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

 class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * dummy = new ListNode(-1), * head = dummy;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for (int sz = lists.size(), i = 0; i < sz; ++i) {
            ListNode * node = lists[i];
            if (node) {
                array<int, 2> element = {node->val, i};
                pq.push(element);
            }
        }
        while (!pq.empty()) {
            array<int, 2> top = pq.top();
            pq.pop();
            int index = top[1];
            ListNode * node = lists[index];
            head->next = node;
            head = head->next;
            node = lists[index] = lists[index]->next;
            if (node) {
                array<int, 2> element = {node->val, index};
                pq.push(element);
            }
        }
        return dummy->next;
    }
};
    
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
