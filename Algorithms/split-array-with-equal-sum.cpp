// 548. Split Array with Equal Sum
// https://leetcode.com/problems/split-array-with-equal-sum/

/*
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:
1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool splitArray(vector<int>& nums) {
		int sz = nums.size(), i, j, k, a, b;
		vector<int> A;
		A.push_back(0);
		unordered_set<int> B;
		for (const auto & i : nums) {
			A.push_back(A.back() + i);
		}
		for (j = 3; j <= sz - 4; ++j) {
			B.clear();
			for (i = 1; i <= j - 2; ++i) {
				a = A[i] - A[0];
				b = A[j] - A[i + 1];
				if (a == b) {
					B.insert(a);
				}
			}
			for (k = j + 2; k <= sz - 2; ++k) {
				a = A[k] - A[j + 1];
				b = A[sz] - A[k + 1];
				if (a == b and B.count(a)) {
					return true;
				}
			}
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	bool result;
	
	nums = {1, 2, 1, 2, 1, 2, 1};
	result = solution.splitArray(nums);
	cout << boolalpha << result << '\n';

	return 0;
}