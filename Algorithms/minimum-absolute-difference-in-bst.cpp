// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
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
	int getMinimumDifference(TreeNode* root) {
		vector<int> nums;
		dfs(root, nums);
		sort(begin(nums), end(nums));
		int result = 0;
		for (size_t i = 1; i < nums.size(); i++) {
			if (i == 1) {
				result = nums.at(1) - nums.at(0);
				continue;
			}
			if (i > 1) {
				result = min(result, nums.at(i) - nums.at(i - 1));
				continue;
			}
		}
		return result;
	}
private:
	void dfs(TreeNode* root, vector<int>& nums) {
		if (root) {
			nums.push_back(root->val);
			dfs(root->left, nums);
			dfs(root->right, nums);
		}
	} 
};
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	int result = 0;
	int answer = 0;

	root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	answer = 1;
	result = solution.getMinimumDifference(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}