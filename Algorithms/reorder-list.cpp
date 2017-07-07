// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
	void reorderList(ListNode* head) {
		if (!head or !head->next) {
			return;
		}
		ListNode * slow = head, * fast = head, * prevSlow = NULL;
		while (slow and fast and fast->next) {
			prevSlow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prevSlow->next = NULL;
		prevSlow = NULL;
		while (slow) {
			ListNode * nextSlow = slow->next;
			slow->next = prevSlow;
			prevSlow = slow;
			slow = nextSlow;
		}
		ListNode dummy(0);
		int i = 0;
		for (ListNode * it = &dummy; head or prevSlow; it = it->next, ++i) {
			if (!head) {
				it->next = prevSlow;
				break;
			}
			if (!prevSlow) {
				it->next = head;
				break;
			}
			if (i & 1) {
				it->next = prevSlow;
				prevSlow = prevSlow->next;
			}
			else {
				it->next = head;
				head = head->next;
			}
		}
		head = dummy.next;
	}
};