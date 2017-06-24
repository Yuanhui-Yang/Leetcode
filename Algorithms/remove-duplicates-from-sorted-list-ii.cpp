// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode *a = &dummy;
		while (a->next) {
			ListNode *b = a->next;
			int l = 0;
			while (b->next and b->next->val == a->next->val) {
				b = b->next;
				++l;
			}
			if (l > 0) {
				a->next = b->next;
			}
			else {
				a = a->next;   
			}
		}
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	vector<int> x, y;
	ListNode* head;

	x = {1, 2, 3, 3, 4, 4, 5};
	y = {1, 2, 5};
	head = f(x);
	head = solution.deleteDuplicates(head);
	x = g(head);
	assert(y == x);

	x = {1, 1, 1, 2, 3};
	y = {2, 3};
	head = f(x);
	head = solution.deleteDuplicates(head);
	x = g(head);
	assert(y == x);

	cout << "\nPassed All\n";
	return 0;
}