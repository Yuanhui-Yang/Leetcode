// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
	ListNode *detectCycle(ListNode *head) {
		ListNode * slow = head, * fast = head;
		while (slow and fast and fast->next) {
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
			if (slow == fast) {
				break;
			}
		}
		if (!(slow and fast and fast->next)) {
			return NULL;
		}
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};