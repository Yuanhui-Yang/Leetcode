// 100. Same Tree
// https://leetcode.com/problems/same-tree/

// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
#include <stack> // std::stack::top
#include <queue> // std::queue::front; std::priority_queue::top
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p and !q) {
			return true;
		}
		if (p and !q) {
			return false;
		}
		if (!p and q) {
			return false;
		}
		if (p->val != q->val) {
			return false;
		}
		return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
	}
};

int main(void) {
	Solution solution;
	TreeNode* p = NULL, *q = NULL;
	bool result, answer;

	p = new TreeNode(1);
	p->right = new TreeNode(1);
	q = new TreeNode(1);
	q->right = new TreeNode(1);
	answer = true;
	result = solution.isSameTree(p, q);
	assert(answer == result);

	cout << "\nPassed all\n";
	return 0;
}