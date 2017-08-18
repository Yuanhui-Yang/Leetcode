// 445. Add Two Numbers II
// https://leetcode.com/problems/add-two-numbers-ii/

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> A, B;
		while (l1) {
			A.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			B.push(l2->val);
			l2 = l2->next;
		}
		ListNode * dummy = new ListNode(0);
		int carry = 0, base = 10;
		while (!A.empty() or !B.empty() or carry > 0) {
			int x = 0, y = 0;
			if (!A.empty()) {
				x = A.top();
				A.pop();
			}
			if (!B.empty()) {
				y = B.top();
				B.pop();
			}
			int z = x + y + carry;
			carry = z / base;
			z %= base;
			ListNode * t = dummy->next;
			dummy->next = new ListNode(z);
			dummy->next->next = t;
		}
		return dummy->next;
	}
};