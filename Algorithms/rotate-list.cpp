// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void gc(ListNode*& head) {
	if (head) {
		gc(head->next);
		delete head;
		head = NULL;
	}
}

bool isSameList(ListNode* a, ListNode* b) {
	if (!a or !b) {
		return a == b;
	}
	return a->val == b->val and isSameList(a->next, b->next);
}

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head or k <= 0) {
			return head;
		}
		ListNode dummy(0), *tail = NULL;
		dummy.next = head;
		int l = 0;
		while (head) {
			++l;
			tail = head;
			head = head->next;
		}
		k = l - k % l;
		if (k == 0) {
			return dummy.next;
		} 
		head = &dummy;
		while (k-- > 0) {
			head = head->next;
		}
		tail->next = dummy.next;
		dummy.next = head->next;
		head->next = NULL;
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	ListNode *head, *answer, *result;
	int k;

	head = NULL;
	k = 0;
	answer = NULL;
	result = solution.rotateRight(head, k);
	assert(isSameList(answer, result));
	gc(answer);
	gc(result);

	head = new ListNode(1);
	head->next = new ListNode(2);
	k = 1;
	answer = new ListNode(2);
	answer->next = new ListNode(1);
	result = solution.rotateRight(head, k);
	assert(isSameList(answer, result));
	gc(answer);
	gc(result);

	head = new ListNode(1);
	k = 1;
	answer = new ListNode(1);
	result = solution.rotateRight(head, k);
	assert(isSameList(answer, result));
	gc(answer);
	gc(result);

	head = new ListNode(1);
	head->next = new ListNode(2);
	k = 3;
	answer = new ListNode(2);
	answer->next = new ListNode(1);
	result = solution.rotateRight(head, k);
	assert(isSameList(answer, result));
	gc(answer);
	gc(result);

	head = new ListNode(1);
	head->next = new ListNode(2);
	k = 0;
	answer = new ListNode(1);
	answer->next = new ListNode(2);
	result = solution.rotateRight(head, k);
	assert(isSameList(answer, result));
	gc(answer);
	gc(result);

	cout << "\nPassed All\n";
	return 0;
}