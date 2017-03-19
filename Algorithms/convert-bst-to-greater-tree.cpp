// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
	TreeNode* convertBST(TreeNode* root) {
		if (!root) {
			return root;
		}
		int carry = 0;
		convertBST(root, carry);
		return root;
	}
private:
	void convertBST(TreeNode* root, int& carry) {
		if (!root) {
			return;
		}
		convertBST(root->right, carry);
		root->val += carry;
		carry = root->val;
		convertBST(root->left, carry);
	}
public:
	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (!s and !t) {
			return true;
		}
		if (s and !t) {
			return false;
		}
		if (!s and t) {
			return false;
		}
		if (s->val != t->val) {
			return false;
		}
		return isSameTree(s->left, t->left) and isSameTree(s->right, t->right);
	}
};

int main(void) {
	Solution solution;
	TreeNode *root = NULL, *answer = NULL, *result = NULL;

	root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(13);
	
	answer = new TreeNode(18);
	answer->left = new TreeNode(20);
	answer->right = new TreeNode(13);

	result = solution.convertBST(root);
	assert(solution.isSameTree(answer, result));

	cout << "\nPassed All\n";
	return 0;
}