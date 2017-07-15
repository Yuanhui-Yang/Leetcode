// 369. Plus One Linked List
// https://leetcode.com/problems/plus-one-linked-list/

/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
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
	ListNode* plusOne(ListNode* head) {
		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;
		for (ListNode * it = dummy; it; it = it->next) {
			if (it->val != 9) {
				head = it;
			}
		}
		++(head->val);
		head = head->next;
		while (head) {
			head->val = 0;
			head = head->next;
		}
		return dummy->val ? dummy : dummy->next;
	}
};

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
	ListNode* plusOne(ListNode* head) {
		head = f(head);
		int carry = 1, base = 10;
		ListNode dummy(0);
		dummy.next = head;
		head = &dummy;
		while (head->next or carry > 0) {
			if (head->next) {
				head->next->val += carry;
			}
			else {
				head->next = new ListNode(carry);
			}
			carry = head->next->val / base;
			head->next->val %= base;
			head = head->next;
		}
		return f(dummy.next);
	}
private:
	ListNode * f(ListNode * head) {
		ListNode * result = NULL;
		while (head) {
			ListNode * next = head->next;
			head->next = result;
			result = head;
			head = next;
		}
		return result;
	}
};