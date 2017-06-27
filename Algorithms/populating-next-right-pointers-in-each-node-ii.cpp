// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root or (!root->left and !root->right)) {
			return;
		}
		while(root) {
			TreeLinkNode *next = NULL, *prev = NULL;
			while (root) {
				if (root->left) {
					if (prev) {
						prev->next = root->left;
					}
					prev = root->left;
					if (!next) {
						next = root->left;
					}
				}
				if (root->right) {
					if (prev) {
						prev->next = root->right;
					}
					prev = root->right;
					if (!next) {
						next = root->right;
					}
				}
				root = root->next;
			}
			root = next;
		}
	}
};