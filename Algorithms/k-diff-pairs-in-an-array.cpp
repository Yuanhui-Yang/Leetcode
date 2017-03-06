// 532. K-diff Pairs in an Array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0 or nums.empty()) {
			return 0;
		}
		int result = 0;
		if (k == 0) {
			unordered_map<int, int> h;
			for (const auto &i : nums) {
				h[i]++;
			}
			for (const auto &i : h) {
				result += i.second > 1;
			}
			return result;
		}
		unordered_set<int> s;
		sort(begin(nums), end(nums));
		for (const auto &i : nums) {
			if (s.empty()) {
				s.insert(i);
				continue;
			}
			if (!s.count(i)) {
				result += s.count(i - k);
				s.insert(i);
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int k, result, answer;

	nums = {1, 1, 1, 2, 2};
	k = 1;
	answer = 1;
	result = solution.findPairs(nums, k);
	assert(answer == result);

	nums = {1, 1, 1, 1, 1};
	k = 0;
	answer = 1;
	result = solution.findPairs(nums, k);
	assert(answer == result);

	nums = {3, 1, 4, 1, 5};
	k = 2;
	answer = 2;
	result = solution.findPairs(nums, k);
	assert(answer == result);

	nums = {1, 2, 3, 4, 5};
	k = 1;
	answer = 4;
	result = solution.findPairs(nums, k);
	assert(answer == result);

	nums = {1, 3, 1, 5, 4};
	k = 0;
	answer = 1;
	result = solution.findPairs(nums, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}