// 659. Split Array into Consecutive Subsequences
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

/*
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		int sz = nums.size();
		if (sz < 3) {
			return false;
		}
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> A;
		for (int i = 0; i < sz; ++i) {
			int key = nums[i] - 1;
			if (A.count(key)) {
				priority_queue<int, vector<int>, greater<int>> & val = A.at(key);
				if (!val.empty()) {
					int cnt = val.top();
					val.pop();
					if (val.empty()) {
						A.erase(key);
					}
					A[nums[i]].push(cnt + 1);
				}
			}
			else {
				A[nums[i]].push(1);
			}
		}
		for (const auto & i : A) {
			if (!i.second.empty() and i.second.top() < 3) {
				return false;
			}
		}
		return true;
	}
};

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		int sz = nums.size();
		if (sz < 3) {
			return false;
		}
		unordered_map<int, multiset<int>> A;
		for (int i = 0; i < sz; ++i) {
			int key = nums[i] - 1;
			if (A.count(key)) {
				multiset<int> & val = A.at(key);
				if (!val.empty()) {
					multiset<int>::iterator it = begin(val);
					int cnt = *it;
					val.erase(it);
					if (val.empty()) {
						A.erase(key);
					}
					A[nums[i]].insert(cnt + 1);
				}
			}
			else {
				A[nums[i]].insert(1);
			}
		}
		for (const auto & i : A) {
			for (const auto & j : i.second) {
				if (j < 3) {
					return false;
				}
			}
		}
		return true;
	}
};