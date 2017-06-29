// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(0), *a = &dummy;
		dummy.next = head;
		while (a->next) {
			ListNode *b = a->next;
			bool flag = false;
			while(b->next and b->next->val == b->val) {
				b = b->next;
				flag = true;
			}
			if (flag) {
				a->next = b->next;
			}
			else {
				a = b;
			}
		}
		return dummy.next;
	}
};