// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/
#include <iostream>
#include <cassert>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> result;
		for (const auto &i : findNums) {
			vector<int>::iterator it = find(begin(nums), end(nums), i);
			vector<int>::iterator jt = next(it);
			if (jt == end(nums)) {
				result.push_back(-1);
				continue;
			}
			while (jt != end(nums) && *jt <= i) jt++;
			if (jt == end(nums)) {
				result.push_back(-1);
				continue;
			}
			result.push_back(*jt);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> findNums;
	vector<int> nums;
	vector<int> result;

	findNums = {4, 1, 2};
	nums = {1, 3, 4, 2};
	result = solution.nextGreaterElement(findNums, nums);
	assert(vector<int>({-1, 3, -1}) == result);

	findNums = {2, 4};
	nums = {1, 2, 3, 4};
	result = solution.nextGreaterElement(findNums, nums);
	assert(vector<int>({3, -1}) == result);

	cout << "\nPassed All\n";
	return 0;
}