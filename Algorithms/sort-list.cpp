// 148. Sort List
// https://leetcode.com/problems/sort-list/

/*
Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode* sortList(ListNode* head) {
		if (!head or !head->next) {
			return head;
		}
		ListNode * slow = head, * fast = head, * prevSlow = NULL;
		while (slow and fast and fast->next) {
			prevSlow = slow;
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
		}
		prevSlow->next = NULL;
		ListNode * l1 = sortList(head), * l2 = sortList(slow);
		return f(l1, l2);
	}
private:
	ListNode * f(ListNode * l1, ListNode * l2) {
		ListNode dummy(0), * l = &dummy;
		while (l1 or l2) {
			if (!l1) {
				l->next = l2;
				break;
			}
			if (!l2) {
				l->next = l1;
				break;
			}
			if (l1->val < l2->val) {
				l->next = l1;
				l1 = l1->next;
			}
			else {
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;
		}
		return dummy.next;
	}
};