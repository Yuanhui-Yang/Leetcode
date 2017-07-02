// 634. Find the Derangement of An Array
// https://leetcode.com/problems/find-the-derangement-of-an-array/

/*
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 106].
*/

class Solution {
public:
	int findDerangement(int n) {
		if (n <= 3) {
			return n - 1;
		}
		size_t f1 = 0, f2 = 1, g = pow(10, 9) + 7;
		for (int i = 3; i <= n; ++i) {
			size_t t = f2;
			f2 = (i - 1) * (f1 + f2);
			f2 %= g;
			f1 = t;
		}
		return f2 % g;
	}
};