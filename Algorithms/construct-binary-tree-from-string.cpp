// 536. Construct Binary Tree from String
// https://leetcode.com/problems/construct-binary-tree-from-string/

// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

// You always start to construct the left child node of the parent first if it exists.

// Example:
// Input: "4(2(3)(1))(6(5))"
// Output: return the tree root node representing the following tree:

//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
// Note:
// There will only be '(', ')', '-' and '0' ~ '9' in the input string.

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
	TreeNode* str2tree(string s) {
		if (s.empty()) {
			return NULL;
		}
		const size_t n = s.size();
		size_t i = 0;
		while (i < n and (isdigit(s.at(i)) or s.at(i) == '-')) {
			i++;
		}
		if (i == n) {
			return new TreeNode(stoi(s));
		}
		stack<size_t> stk;
		TreeNode *root = NULL;
		string left = "", right = "";
		for (size_t i = 0, l1 = string::npos, r1 = string::npos, l2 = string::npos, r2 = string::npos; i < n; i++) {
			if (s.at(i) == '(') {
				if (root == NULL) {
					// cout << stoi(s.substr(0, i)) << '\n';
					root = new TreeNode(stoi(s.substr(0, i)));
					l1 = i;
					stk.push(i);
					continue;
				}
				if (stk.empty()) {
					l2 = i;
				}
				stk.push(i);
				continue;
			}
			if (s.at(i) == ')') {
				stk.pop();
				if (stk.empty()) {
					if (left.empty() and right.empty()) {
						r1 = i;
						left = s.substr(l1 + 1, r1 - l1 - 1);
						// cout << left << '\n';
						continue;
					}
					if (!left.empty() and right.empty()) {
						r2 = i;
						right = s.substr(l2 + 1, r2 - l2 - 1);
						// cout << right << '\n';
						continue;
					}
				}
				continue;
			}
		}
		root->left = str2tree(left);
		root->right = str2tree(right);
		// cout << root->val << '\n';
		return root;
	}
};

int main(void) {
	Solution solution;
	string s;
	TreeNode *result = NULL;

	s = "4(2(3)(1))(6(5))";
	result = solution.str2tree(s);

	cout << "\nPassed All\n";
	return 0;
}