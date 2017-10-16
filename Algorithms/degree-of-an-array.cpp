// 697. Degree of an Array
// https://leetcode.com/problems/degree-of-an-array/

/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		int result = 0, sz = nums.size(), i, val;
		unordered_map<int, array<int, 3>> A;
		for (i = 0; i < sz; ++i) {
			val = nums[i];
			if (A.count(val)) {
				++A[val][0];
				A[val][2] = i;
			}
			else {
				A[val] = {1, i, i};
			}
		}
		val = 0;
		for (const auto & p : A) {
			if (val < p.second[0] or result == 0) {
				val = p.second[0];
				result = p.second[2] - p.second[1] + 1;
			}
			else if (val == p.second[0] and p.second[2] - p.second[1] + 1 < result) {
				result = p.second[2] - p.second[1] + 1;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result;

	nums = {1, 2, 2, 3, 1};
	result = solution.findShortestSubArray(nums);
	cout << result << '\n';

	nums = {1, 2, 2, 3, 1, 4, 2};
	result = solution.findShortestSubArray(nums);
	cout << result << '\n';

	return 0;
}