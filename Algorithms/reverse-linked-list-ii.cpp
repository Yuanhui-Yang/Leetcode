// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *f(vector<int>& v) {
	ListNode dummy(0), *it = &dummy;
	for (const auto &i : v) {
		it->next = new ListNode(i);
		it = it->next;
	}
	return dummy.next;
}

vector<int> g(ListNode* head) {
	vector<int> v;
	while (head) {
		v.push_back(head->val);
		head = head->next;
	}
	return v;
}

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head or m >= n) {
			return head;
		}
		ListNode dummy(0), *a = &dummy;
		dummy.next = head;
		for (int i = 1; i < m; ++i) {
			a = a->next;
		}
		ListNode *b = a->next, *c = b->next;
		for (int i = m; i < n; ++i) {
			ListNode *d = c->next;
			c->next = b;
			b = c;
			c = d;
		}
		a->next->next = c;
		a->next = b;
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	ListNode* head;
	vector<int> u, v;
	int m, n;

	u = {3, 5};
	v = {5, 3};
	m = 1;
	n = 2;
	head = f(u);
	head = solution.reverseBetween(head, m, n);
	u = g(head);
	assert(u == v);

	u = {1, 2, 3, 4, 5};
	v = {1, 4, 3, 2, 5};
	m = 2;
	n = 4;
	head = f(u);
	head = solution.reverseBetween(head, m, n);
	u = g(head);
	assert(u == v);

	cout << "\nPassed All\n";
	return 0;
}