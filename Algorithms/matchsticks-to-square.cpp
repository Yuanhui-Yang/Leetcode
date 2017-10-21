// 473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/

/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/

#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int sz = nums.size(), sum = accumulate(begin(nums), end(nums), 0);
		if (sz < 4 or sum % 4 != 0) {
			return false;
		}
		sort(begin(nums), end(nums), greater<int>());
		array<int, 4> A;
		A.fill(0);
		return f1(nums, 0, A, sum / 4);
	}
private:
	bool f1(const vector<int> & nums, const int start, array<int, 4> & A, const int target) {
		int sz = nums.size(), i;
		if (start == sz) {
			return A[0] == target and A[1] == target and A[2] == target and A[3] == target;
		}
		for (i = 0; i < 4; ++i) {
			if (A[i] + nums[start] <= target) {
				A[i] += nums[start];
				if (f1(nums, start + 1, A, target)) {
					return true;
				}
				A[i] -= nums[start];
			}
		}
		return false;
	}
};

int main (void) {
	Solution solution;
	vector<int> nums;
	bool result;
	
	nums = {1, 1, 2, 2, 2};
	result = solution.makesquare(nums);
	cout << boolalpha << result << '\n';

	nums = {3, 3, 3, 3, 4};
	result = solution.makesquare(nums);
	cout << boolalpha << result << '\n';

	nums = {12, 12, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60};
	result = solution.makesquare(nums);
	cout << boolalpha << result << '\n';

	return 0;
}