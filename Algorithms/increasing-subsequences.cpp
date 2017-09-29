// 491. Increasing Subsequences
// https://leetcode.com/problems/increasing-subsequences/

/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

struct Node {
	bool isEnd = false;
	unordered_map<int, Node*> next;
	Node () {
		isEnd = false;
		next.clear();
	}
};

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		int sz = nums.size(), i = 0, j = 0;
		if (sz <= 1) {
			return {};
		}
		vector<vector<vector<int>>> A(sz);
		vector<vector<int>> B;
		Node * root = new Node();
		for (i = sz - 2; i >= 0; --i) {
			for (j = i + 1; j < sz; ++j) {
				if (nums[i] <= nums[j]) {
					A[i].push_back({nums[i], nums[j]});
					f(root, A[i].back(), B);
					for (auto & k : A[j]) {
						k.insert(begin(k), nums[i]);
						A[i].push_back(k);
						f(root, k, B);
						k.erase(begin(k));
					}
				}
			}
		}
		return B;
	}
	void f(Node * root, const vector<int> & A, vector<vector<int>> & B) {
		for (const auto & i : A) {
			if (!root->next.count(i)) {
				root->next[i] = new Node();
			}
			root = root->next[i];
		}
		if (!root->isEnd) {
			root->isEnd = true;
			B.push_back(A);
		}
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result;
	
	nums = {4, 6, 7, 7};
	result = solution.findSubsequences(nums);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

struct Node {
	bool isEnd = false;
	unordered_map<int, Node*> next;
	Node () {
		isEnd = false;
		next.clear();
	}
};

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		int sz = nums.size(), i = 0, j = 0;
		if (sz <= 1) {
			return {};
		}
		vector<vector<vector<int>>> A(sz);
		vector<vector<int>> B;
		vector<int> C;
		Node * root = new Node();
		for (i = sz - 2; i >= 0; --i) {
			for (j = i + 1; j < sz; ++j) {
				if (nums[i] <= nums[j]) {
					A[i].push_back({nums[i], nums[j]});
					f1(root, A[i].back());
					for (auto & k : A[j]) {
						k.insert(begin(k), nums[i]);
						A[i].push_back(k);
						f1(root, k);
						k.erase(begin(k));
					}
				}
			}
		}
		f2(root, B, C);
		return B;
	}
	void f1(Node * root, const vector<int> & A) {
		for (const auto & i : A) {
			if (!root->next.count(i)) {
				root->next[i] = new Node();
			}
			root = root->next[i];
		}
		root->isEnd = true;
	}
	void f2(Node * root, vector<vector<int>> & B, vector<int> & C) {
		if (!root) {
			return;
		}
		if (root->isEnd) {
			B.push_back(C);
		}
		for (const auto & i : root->next) {
			C.push_back(i.first);
			f2(i.second, B, C);
			C.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result;
	
	nums = {4, 6, 7, 7};
	result = solution.findSubsequences(nums);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		int sz = nums.size(), i = 0, j = 0;
		if (sz <= 1) {
			return {};
		}
		vector<vector<vector<int>>> A(sz);
		vector<vector<int>> B;
		set<vector<int>> C;
		for (i = sz - 2; i >= 0; --i) {
			for (j = i + 1; j < sz; ++j) {
				if (nums[i] <= nums[j]) {
					A[i].push_back({nums[i], nums[j]});
					for (auto & k : A[j]) {
						k.insert(begin(k), nums[i]);
						A[i].push_back(k);
						k.erase(begin(k));
					}
				}
			}
		}
		for (const auto & i : A) {
			for (const auto & j : i) {
				C.insert(j);
			}
		}
		return vector<vector<int>>(begin(C), end(C));
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result;
	
	nums = {4, 6, 7, 7};
	result = solution.findSubsequences(nums);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}