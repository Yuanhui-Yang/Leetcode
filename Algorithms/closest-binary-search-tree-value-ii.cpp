// 272. Closest Binary Search Tree Value II
// https://leetcode.com/problems/closest-binary-search-tree-value-ii/

/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode * node) {
	if (node) {
		gc(node->left);
		gc(node->right);
		delete node;
	}
}

class Solution {
public:
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		if (!root or k <= 0) {
			return {};
		}
		list<int> A;
		TreeNode * pred = NULL;
		while (root) {
			if (!root->left) {
				if (A.size() == k) {
					if (fabs(A.front() - target) <= fabs(root->val - target)) {
						break;
					}
					else {
						A.pop_front();
					}
				}
				A.push_back(root->val);
				root = root->right;
			}
			else {
				pred = root->left;
				while (pred->right and pred->right != root) {
					pred = pred->right;
				}
				if (!pred->right) {
					pred->right = root;
					root = root->left;
				}
				else {
					if (A.size() == k) {
						if (fabs(A.front() - target) <= fabs(root->val - target)) {
							break;
						}
						else {
							A.pop_front();
						}
					}
					A.push_back(root->val);
					pred->right = NULL;
					root = root->right;
				}
			}
		}
		return vector<int>(begin(A), end(A));
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	double target;
	int k;
	vector<int> result;

	root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->left->left->right = new TreeNode(2);
	target = 2.571429;
	k = 1;
	result = solution.closestKValues(root, target, k);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	target = 2147483647.0;
	k = 1;
	result = solution.closestKValues(root, target, k);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	target = 2;
	k = 1;
	result = solution.closestKValues(root, target, k);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <iterator>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode * node) {
	if (node) {
		gc(node->left);
		gc(node->right);
		delete node;
	}
}

class Solution {
public:
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		if (!root or k <= 0) {
			return {};
		}
		stack<TreeNode*> A;
		list<int> B;
		while (root or !A.empty()) {
			if (root) {
				A.push(root);
				root = root->left;
			}
			else {
				root = A.top();
				A.pop();
				if (B.size() == k) {
					if (fabs(B.front() - target) <= fabs(root->val - target)) {
						break;
					}
					else {
						B.pop_front();
					}
				}
				B.push_back(root->val);
				root = root->right;
			}
		}
		return vector<int>(begin(B), end(B));
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	double target;
	int k;
	vector<int> result;
	
	root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	target = 2;
	k = 1;
	result = solution.closestKValues(root, target, k);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

double origin(0);

struct Comp {
	bool operator() (const int a, const int b) {
		return fabs(a - origin) < fabs(b - origin);
	}
};

class Solution {
public:
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		vector<int> result;
		
		if (!root or k <= 0) {
			return result;
		}
		origin = target;
		priority_queue<int, vector<int>, Comp> pq;
		queue<TreeNode*> curr;
		curr.push(root);
		while (pq.size() < k) {
			root = curr.front();
			curr.pop();
			pq.push(root->val);
			if (root->left) {
				curr.push(root->left);
			}
			if (root->right) {
				curr.push(root->right);
			}
		}
		while (!curr.empty()) {
			root = curr.front();
			curr.pop();
			if (root->val <= origin) {
				if (origin - root->val < abs(origin - pq.top())) {
					if (root->left) {
						curr.push(root->left);
					}
					if (root->right) {
						curr.push(root->right);
					}
					pq.pop();
					pq.push(root->val);
				}
				else {
					if (root->right) {
						curr.push(root->right);
					}
				}
			}
			else {
				if (root->val - origin < abs(origin - pq.top())) {
					if (root->left) {
						curr.push(root->left);
					}
					if (root->right) {
						curr.push(root->right);
					}
					pq.pop();
					pq.push(root->val);
				}
				else {
					if (root->left) {
						curr.push(root->left);
					}
				}
			}
		}
		while (!pq.empty()) {
			result.push_back(pq.top());
			pq.pop();
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	double target;
	int k;
	vector<int> result;
	
	root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	target = 2;
	k = 1;
	result = solution.closestKValues(root, target, k);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}