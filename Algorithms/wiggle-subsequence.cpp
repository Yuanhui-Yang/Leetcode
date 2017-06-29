// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/

/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return n;
		}
		int a = 1, b = 1;
		for (int i = 1; i < n; ++i) {
			if (nums[i - 1] < nums[i]) {
				a = b + 1;
				continue;
			}
			if (nums[i - 1] > nums[i]) {
				b = a + 1;
				continue;
			}
		}
		return max(a, b);
	}
};

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		list<int> l;
		for (const auto &i : nums) {
			if (l.empty()) {
				l.push_back(i);
				continue;
			}
			if (l.back() == i) {
				continue;
			}
			if (l.size() == 1) {
				l.push_back(i);
				continue;
			}
			list<int>::iterator x = prev(end(l), 2), y = prev(end(l));
			if (*x < *y) {
				if (*y < i) {
					*y = i;
				}
				else {
					l.push_back(i);
				}
			}
			else {
				if (*y < i) {
					l.push_back(i);
				}
				else {
					*y = i;
				}
			}
		}
		return l.size();
	}
};

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int n = nums.size(), result = 1;
		vector<int> a(n, 1), b(n, 1);
		for (int i = n - 2; i >= 0; --i) {
			int x = 0, y = 0;
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] < nums[j]) {
					x = max(x, b[j]);
				}
				if (nums[i] > nums[j]) {
					y = max(y, a[j]);
				}
			}
			a[i] += x;
			b[i] += y;
			result = max(result, a[i]);
			result = max(result, b[i]);
		}
		return result;
	}
};