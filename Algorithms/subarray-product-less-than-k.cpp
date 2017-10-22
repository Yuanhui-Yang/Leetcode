// 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/

/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (nums.empty() or k < 1) {
			return 0;
		}
		int sz = nums.size(), i = 0, j = 0, curr = 1, result = 0;
		for (j = 0; j < sz; ++j) {
			curr *= nums[j];
			while (i <= j and curr >= k) {
				curr /= nums[i];
				++i;
			}
			result += j - i + 1;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int k, result;
	
	nums = {10, 5, 2, 6};
	k = 100;
	result = solution.numSubarrayProductLessThanK(nums, k);
	cout << result << '\n';

	nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
	k = 19;
	result = solution.numSubarrayProductLessThanK(nums, k);
	cout << result << '\n';

	return 0;
}