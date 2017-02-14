// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
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
	vector<int> largestValues(TreeNode* root) {
		if (!root) {
			return {};
		}
		vector<int> result;
		multiset<TreeNode*, MaxHeapComp> max_heap;
		max_heap.insert(root);
		while (!max_heap.empty()) {
			result.push_back((*begin(max_heap))->val);
			vector<TreeNode*> stack(begin(max_heap), end(max_heap));
			max_heap.clear();
			for (const auto &i : stack) {
				if (i->left) {
					max_heap.insert(i->left);
				}
				if (i->right) {
					max_heap.insert(i->right);
				}
			}
		}
		return result;
	}
private:
	struct MaxHeapComp {
		bool operator() (const TreeNode* i, const TreeNode* j) {
			return i->val > j->val;
		}
	};
};
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	vector<int> result;
	vector<int> answer;

	root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(9);
	answer = {1, 3, 9};
	result = solution.largestValues(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}