// 662. Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/

/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

		   1
		 /   \
		3     2
	   / \     \  
	  5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

		  1
		 /  
		3    
	   / \       
	  5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

		  1
		 / \
		3   2 
	   /        
	  5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

		  1
		 / \
		3   2
	   /     \  
	  5       9 
	 /         \
	6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/

#include <iostream>
#include <list>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int widthOfBinaryTree(TreeNode * root) {
		if (!root) {
			return 0;
		}
		int result = 0, diff = 0;
		list<pair<TreeNode*, int>> curr, next;
		curr.push_back({root, 0});
		while (!curr.empty()) {
			diff = curr.back().second - curr.front().second + 1;
			next.clear();
			if (result < diff) {
				result = diff;
			}
			for (const auto & i : curr) {
				if (i.first->left) {
					next.push_back({i.first->left, 2 * i.second + 1});
				}
				if (i.first->right) {
					next.push_back({i.first->right, 2 * i.second + 2});
				}
			}
			curr = next;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	int result;
	
	root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(9);
	result = solution.widthOfBinaryTree(root);
	cout << result << '\n';

	root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	result = solution.widthOfBinaryTree(root);
	cout << result << '\n';

	return 0;
}