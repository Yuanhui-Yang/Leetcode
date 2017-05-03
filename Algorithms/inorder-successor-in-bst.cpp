// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
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
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
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

// BEGIN: https://discuss.leetcode.com/topic/25052/10-and-4-lines-o-h-java-c
// BEGIN: Time Complexity O(h) Space Complexity O(1)
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode *successor = NULL;
		while (root) {
			root = root->val > p->val ? (successor = root)->left : root->right;
		}
		return successor;
	}
};
// END: Time Complexity O(h) Space Complexity O(1)
// END: https://discuss.leetcode.com/topic/25052/10-and-4-lines-o-h-java-c

int main(void) {
	Solution solution;
	TreeNode *root = NULL, *p = NULL, *answer = NULL, *result = NULL;

	root = new TreeNode(2);
	root->right = new TreeNode(3);
	p = root->right;
	answer = NULL;
	result = solution.inorderSuccessor(root, p);
	assert(answer ==  result);
	gc(root);

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	p = root;
	answer = root->right;
	result = solution.inorderSuccessor(root, p);
	assert(answer ==  result);
	gc(root);

	root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(2);
	root->right->left->right = new TreeNode(3);
	p = root;
	answer = root->right->left;
	result = solution.inorderSuccessor(root, p);
	assert(answer ==  result);
	gc(root);

	cout << "\nPassed All\n";
	return 0;
}