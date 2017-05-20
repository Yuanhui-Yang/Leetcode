// 549. Binary Tree Longest Consecutive Sequence II
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

/*
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
Note: All the values of tree nodes are in the range of [-1e7, 1e7].
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close;
#include <ctime>
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* root) {
	if (!root) {
		return;
	}
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		TreeNode *node = s.top();
		s.pop();
		if (node->left) {
			s.push(node->left);
		}
		if (node->right) {
			s.push(node->right);
		}
		delete node;
	}
}

class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		if (!root) {
			return 0;
		}
		return max(max(longestConsecutive(root->left), longestConsecutive(root->right)), max(f1(root) + f4(root) - 1, f2(root) + f3(root) - 1));
	}
private:
	int f1(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int result = 1;
		if (root->left and root->left->val +1 == root->val) {
			result = 1 + max(f1(root->left), f2(root->left));
		}
		return result;
	}
	int f2(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int result = 1;
		if (root->right and root->right->val + 1 == root->val) {
			result = 1 + max(f2(root->right), f1(root->right));
		}
		return result;
	}
	int f3(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int result = 1;
		if (root->left and root->val + 1 == root->left->val) {
			result = 1 + max(f3(root->left), f4(root->left));
		}
		return result;
	}
	int f4(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int result = 1;
		if (root->right and root->val + 1 == root->right->val) {
			result = 1 + max(f4(root->right), f3(root->right));
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	int result = 0, answer = 0;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	answer = 2;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	answer = 2;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(3);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(4);
	answer = 3;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->left->left = new TreeNode(1);
	answer = 3;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = NULL;
	answer = 0;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	answer = 2;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	answer = 3;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}