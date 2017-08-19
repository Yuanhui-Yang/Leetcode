// 508. Most Frequent Subtree Sum
// https://leetcode.com/problems/most-frequent-subtree-sum/

/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> A;
		f(A, root);
		vector<int> result;
		int highestFrequency = 0;
		for (const auto & i : A) {
			if (result.empty() or highestFrequency == i.second) {
				highestFrequency = i.second;
				result.push_back(i.first);
			}
			else if (highestFrequency < i.second) {
				highestFrequency = i.second;
				result.clear();
				result.push_back(i.first);
			}
		}
		return result;
	}
private:
	int f(unordered_map<int, int> & A, TreeNode * node) {
		if (!node) {
			return 0;
		}
		if (!node->left and !node->right) {
			++A[node->val];
			return node->val;
		}
		int left = f(A, node->left), right = f(A, node->right), sum = left + right + node->val;
		++A[sum];
		return sum;
	}
};