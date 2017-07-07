// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) {
			return NULL;
		}
		if (h.count(head)) {
			return h[head];
		}
		RandomListNode dummy(0);
		for (RandomListNode * it = head, * jt = &dummy; it; it = it->next, jt = jt->next) {
			jt->next = h.count(it) ? h[it] : h[it] = new RandomListNode(it->label);
		}
		for (RandomListNode * it = head, * jt = dummy.next; it and jt; it = it->next, jt = jt->next) {
			jt->random = h.count(it->random) ? h[it->random] : NULL;
		}
		return dummy.next;
	}
private:
	unordered_map<RandomListNode*, RandomListNode*> h;
};