// 298. Binary Tree Longest Consecutive Sequence
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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

void gc(TreeNode*& root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
		root = NULL;
	}
}

// BEGIN: Time Complexity O(n) and Space Complexity O(n)
class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		if (!root) {
			return 0;
		}
		list<pair<TreeNode*, int>> current;
		current.push_back(make_pair(root, 1));
		int result = 0;
		while (!current.empty()) {
			list<pair<TreeNode*, int>> next;
			for (const auto &i : current) {
				result = max(result, i.second);
				if (i.first->left) {
					next.push_back(make_pair(i.first->left, i.first->left->val == i.first->val + 1 ? i.second + 1 : 1));
				}
				if (i.first->right) {
					next.push_back(make_pair(i.first->right, i.first->right->val == i.first->val + 1 ? i.second + 1 : 1));
				}
			}
			current = next;
		}
		return result;
	}
};
// END: Time Complexity O(n) and Space Complexity O(n)

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	int result = 0, answer = 0;

	root = NULL;
	answer = 0;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	answer = 1;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(5);
	answer = 3;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(1);
	answer = 2;
	result = solution.longestConsecutive(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}