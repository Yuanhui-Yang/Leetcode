// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void gc(ListNode* head) {
	if (head) {
		gc(head->next);
		delete head;
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
	ListNode* swapPairs(ListNode* head) {
		ListNode dummy(0);
		dummy.next = head;
		head = &dummy;
		while (head->next and head->next->next) {
			ListNode *a = head->next, *b = head->next->next;
			head->next = b;
			a->next = b->next;
			b->next = a;
			head = a;
		}
		return dummy.next;
	}
};

int main(void) {
	Solution solution;
	ListNode* head;
	vector<int> answer, result;

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head = solution.swapPairs(head);
	answer = {2, 1, 4, 3};
	result = print(head);
	gc(head);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}