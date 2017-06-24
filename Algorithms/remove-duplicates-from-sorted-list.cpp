// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
		ListNode dummy(0), *a = &dummy;
		dummy.next = head;
		while (a->next) {
			ListNode *b = a->next;
			while (b->next and a->next->val == b->next->val) {
				b = b->next;
			}
			a->next->next = b->next;
			a = b;
		}
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	vector<int> x, y;
	ListNode* head;

	x = {1, 1, 2};
	y = {1, 2};
	head = f(x);
	head = solution.deleteDuplicates(head);
	x = g(head);
	assert(y == x);

	x = {1, 1, 1, 2, 3};
	y = {1, 2, 3};
	head = f(x);
	head = solution.deleteDuplicates(head);
	x = g(head);
	assert(y == x);

	cout << "\nPassed All\n";
	return 0;
}