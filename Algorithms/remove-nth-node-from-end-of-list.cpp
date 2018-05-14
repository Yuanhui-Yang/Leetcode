// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void gc(ListNode *node) {
	if (node) {
		gc(node->next);
		delete node;
	}
}

vector<int> print(ListNode* head) {
	vector<int> result;
	while (head) {
		result.push_back(head->val);
		head = head->next;
	}
	return result;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0), * node = dummy;
        dummy->next = head;
        while (n-- > 0) {
            head = head->next;
        }
        while (head) {
            node = node->next;
            head = head->next;
        }
        node->next = node->next->next;
        return dummy->next;
    }
};

int main(void) {
	Solution solution;
	ListNode *head, *answer, *result;
	vector<int> x, y;
	int n;

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	n = 2;
	answer = new ListNode(1);
	answer->next = new ListNode(2);
	answer->next->next = new ListNode(3);
	answer->next->next->next = new ListNode(5);
	result = solution.removeNthFromEnd(head, n);
	x = print(answer);
	y = print(result);
	gc(answer);
	gc(head);
	assert(x == y);

	cout << "\nPassed All\n";
	return 0;
}
