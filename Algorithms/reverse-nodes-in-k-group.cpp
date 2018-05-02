// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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

vector<int> print(ListNode *head) {
	vector<int> result;
	while (head) {
		result.push_back(head->val);
		head = head->next;
	}
	return result;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head or k <= 1) {
            return head;
        }
        int len = f1(head);
        ListNode * dummy = new ListNode(-1), * prev = dummy;
        dummy->next = head;
        while (len >= k) {
            ListNode * curr = prev->next;
            for (int i = 1; i < k; ++i) {
                ListNode * next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
private:
    int f1(ListNode * head) {
        int result = 0;
        while (head) {
            ++result;
            head = head->next;
        }
        return result;
    }
};

int main(void) {
	Solution solution;
	ListNode *head;
	int k;
	vector<int> answer, result;

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	k = 2;
	answer = {2, 1, 4, 3, 5};
	head = solution.reverseKGroup(head, k);
	result = print(head);
	gc(head);
	assert(answer == result);

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	k = 3;
	answer = {3, 2, 1, 4, 5};
	head = solution.reverseKGroup(head, k);
	result = print(head);
	gc(head);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
