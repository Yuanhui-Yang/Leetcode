// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility> // pair; make_pair; swap
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root) {
			return 0;
		}
		if (!root->left and !root->right) {
			return 0;
		}
		if (!root->left) {
			return max(diameterOfBinaryTree(root->right), 1 + depth(root->right));
		}
		if (!root->right) {
			return max(diameterOfBinaryTree(root->left), 1 + depth(root->left));
		}
		int left = depth(root->left);
		int right = depth(root->right);
		int result = left + right + 2;
		result = max(result, diameterOfBinaryTree(root->left));
		result = max(result, diameterOfBinaryTree(root->right));
		return result;
	}
private:
	int depth (TreeNode* root) {
		if (!root) {
			return 0;
		}
		if (!root->left and !root->right) {
			return 0;
		}
		return 1 + max(depth(root->left), depth(root->right));
	}
};

int main(void) {
	Solution solution;
	TreeNode* root = NULL;
	int result = 0, answer = 0;

	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	answer = 2;
	result = solution.diameterOfBinaryTree(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	answer = 3;
	result = solution.diameterOfBinaryTree(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}