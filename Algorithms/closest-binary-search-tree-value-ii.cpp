// 272. Closest Binary Search Tree Value II
// https://leetcode.com/problems/closest-binary-search-tree-value-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> closestKValues(TreeNode* root, double target, int k) {
		vector<int> result;
		if (!root) return result;
		vector<double> inorderTraversal;
		while (root) {
			if (!root->left) {
				inorderTraversal.push_back((double)root->val);
				root = root->right;
				continue;
			}
			TreeNode *predecessor = root->left;
			while(predecessor->right && predecessor->right != root)
				predecessor = predecessor->right;
			if (!predecessor->right) {
				predecessor->right = root;
				root = root->left;
				continue;
			}
			inorderTraversal.push_back((double)root->val);
			predecessor->right = NULL;
			root = root->right;
		}
		const int n = inorderTraversal.size();
		int initIdx = lower_bound(begin(inorderTraversal), end(inorderTraversal), target) - begin(inorderTraversal);
		if (initIdx >= n) {
			result.insert(end(result), end(inorderTraversal) - k, end(inorderTraversal));
			return result;
		}
		for (int i = 0; i < k; i++) {
			int lower = initIdx - 1;
			while (lower >= 0 && inorderTraversal[lower] < 0)
				lower--;
			int upper = initIdx;
			while (upper < n && inorderTraversal[upper] < 0)
				upper++;
			if (lower < 0 && upper < n) {
				result.push_back((int)inorderTraversal[upper]);
				inorderTraversal[upper] = -1.0;
				continue;
			}
			if (lower >= 0 && upper >= n) {
				result.push_back((int)inorderTraversal[lower]);
				inorderTraversal[lower] = -1.0;
				continue;
			}
			if (lower < 0 && upper >= n) {
				return result;
			}
			double differenceLower = target - inorderTraversal[lower];
			double differenceUpper = inorderTraversal[upper] - target;
			if (differenceLower < differenceUpper) {
				result.push_back((int)inorderTraversal[lower]);
				inorderTraversal[lower] = -1.0;
			}
			else {
				result.push_back((int)inorderTraversal[upper]);
				inorderTraversal[upper] = -1.0;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	for (const auto &i : solution.closestKValues(root, 1.0, 3)) cout << i << '\t';
	cout << "\tPassed\n";
	root = new TreeNode(1);
	for (const auto &i : solution.closestKValues(root, 4.428571, 1)) cout << i << '\t';
	cout << "\tPassed\n";
	root = new TreeNode(1);
	root->right = new TreeNode(8);
	for (const auto &i : solution.closestKValues(root, 3.0, 1)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}