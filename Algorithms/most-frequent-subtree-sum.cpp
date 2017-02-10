// 508. Most Frequent Subtree Sum
// https://leetcode.com/problems/most-frequent-subtree-sum/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		if (!root) {
			return {};
		}
		unordered_map<int, int> hash_map;
		findFrequentTreeSum(root, hash_map);
		map<int, vector<int>, greater<int>> tree_map;
		for (const auto &i : hash_map) {
			tree_map[i.second].push_back(i.first);
		}
		return begin(tree_map)->second;
	}
private:
	int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& hash_map) {
		if (!root) {
			return 0;
		}
		if (!root->left && !root->right) {
			hash_map[root->val]++;
			return root->val;
		}
		int left = findFrequentTreeSum(root->left, hash_map);
		int right = findFrequentTreeSum(root->right, hash_map);
		int sum = left + root->val + right;
		hash_map[sum]++;
		return sum;
	}
};
int main(void) {
	Solution solution;
	TreeNode* root = NULL;
	vector<int> result;

	result = solution.findFrequentTreeSum(root);
	assert(unordered_multiset<int>({}) == unordered_multiset<int>(begin(result), end(result)));

	root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(-3);
	result = solution.findFrequentTreeSum(root);
	assert(unordered_multiset<int>({2, -3, 4}) == unordered_multiset<int>(begin(result), end(result)));

	root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(-5);
	result = solution.findFrequentTreeSum(root);
	assert(unordered_multiset<int>({2}) == unordered_multiset<int>(begin(result), end(result)));

	cout << "\nPassed All\n";
	return 0;
}