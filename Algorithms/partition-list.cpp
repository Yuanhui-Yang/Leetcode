// 86. Partition List
// https://leetcode.com/problems/partition-list/#/description

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
	ListNode* partition(ListNode* head, int x) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode *a = &dummy, *b = a;
		while (b->next) {
			if (b->next->val >= x) {
				b = b->next;
				continue;
			}
			if (a == b) {
				a = a->next;
				b = b->next;
			}
			else {
				ListNode *c = a->next, *d = b->next->next;
				a->next = b->next;
				b->next->next = c;
				b->next = d;
				a = a->next;
			}
		}
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	vector<int> u, v;
	int x;
	ListNode* head;

	u = {1, 4, 3, 2, 5, 2};
	v = {1, 2, 2, 4, 3, 5};
	x = 3;
	head = f(u);
	head = solution.partition(head, x);
	u = g(head);
	assert(v == u);

	cout << "\nPassed All\n";
	return 0;
}