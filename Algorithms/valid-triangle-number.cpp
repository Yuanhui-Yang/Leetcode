// 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/

/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(begin(nums), end(nums));
		int result = 0;
		for (int n = nums.size(), i = 0; i + 2 < n; ++i) {
			for (int j = i + 1; j + 1 < n; ++j) {
				result += distance(next(begin(nums), j + 1), lower_bound(next(begin(nums), j + 1), end(nums), nums[i] + nums[j]));
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {2, 2, 3, 4};
	answer = 3;
	result = solution.triangleNumber(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}