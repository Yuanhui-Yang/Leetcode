// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
	}
}

bool isSameTree(TreeNode* t1, TreeNode* t2) {
	if (!t1 or !t2) {
		return t1 == t2;
	}
	return t1->val == t2->val and isSameTree(t1->left, t2->left) and isSameTree(t1->right, t2->right);
}

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) {
			return t2;
		}
		if (!t2) {
			return t1;
		}
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};

int main(void) {
	Solution solution;
	TreeNode *t1, *t2, *answer, *result;

	t1 = new TreeNode(1);
	t1->left = new TreeNode(3);
	t1->right = new TreeNode(2);
	t1->left->left = new TreeNode(5);
	t2 = new TreeNode(2);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(3);
	t2->left->right = new TreeNode(4);
	t2->right->right = new TreeNode(7);
	answer = new TreeNode(3);
	answer->left = new TreeNode(4);
	answer->right = new TreeNode(5);
	answer->left->left = new TreeNode(5);
	answer->left->right = new TreeNode(4);
	answer->right->right = new TreeNode(7);
	result = solution.mergeTrees(t1, t2);
	assert(isSameTree(answer, result));
	gc(answer);
	gc(result);

	cout << "\nPassed All\n";
	return 0;
}