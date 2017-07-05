// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/

/*
Sort a linked list using insertion sort.
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
	ListNode* insertionSortList(ListNode* head) {
		for (ListNode * it = head; it; it = it->next) {
			ListNode * node = it;
			for (ListNode * jt = it; jt; jt = jt->next) {
				if (jt->val < node->val) {
					node = jt;
				}
			}
			swap(it->val, node->val);
		}
		return head;
	}
};