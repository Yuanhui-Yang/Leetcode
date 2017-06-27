// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) {
			return NULL;
		}
		if (!head->next) {
			return new TreeNode(head->val);
		}
		ListNode *slow = head, *fast = head, *p = NULL;
		while (fast and fast->next) {
			p = slow;
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
		}
		p->next = NULL;
		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);
		return root;
	}
};