// 421. Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

#include <iostream>
#include <array>
#include <vector>

using namespace std;

struct Node {
	int val;
	array<Node*, 2> next;
	Node() {
		val = 0;
		next.fill(NULL);
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int> & nums) {
		Node * root = new Node();
		for (const auto & i : nums) {
			f1(root, i);
		}
		int result = 0;
		for (const auto & i : nums) {
			if (result < f2(root, i)) {
				result = f2(root, i);
			}
		}
		return result;
	}
private:
	void f1(Node * node, int val) {
		for (int i = 31; i >= 0; --i) {
			int id = val >> i;
			id &= 1;
			if (!node->next[id]) {
				node->next[id] = new Node();
			}
			node = node->next[id];
		}
		node->val = val;
	}
	int f2(Node * node, int val) {
		for (int i = 31; i >= 0; --i) {
			int id = val >> i;
			id &= 1;
			if (node->next[1 - id]) {
				node = node->next[1 - id];
			}
			else {
				node = node->next[id];
			}
		}
		return val ^ (node->val);
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result;
	
	nums = {3, 10, 5, 25, 2, 8};
	result = solution.findMaximumXOR(nums);
	cout << result << '\n';
	
	return 0;
}