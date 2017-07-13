// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
	bool isPalindrome(ListNode* head) {
		if (!head or !head->next) {
			return true;
		}
		ListNode * slow = head, * fast = head, * prev = NULL;
		while (slow and fast and fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		fast = NULL;
		while (slow) {
			ListNode * next = slow->next;
			slow->next = fast;
			fast = slow;
			slow = next;
		}
		while (head and fast) {
			if (head->val != fast->val) {
				return false;
			}
			head = head->next;
			fast = fast->next;
		} 
		return true;
	}
};