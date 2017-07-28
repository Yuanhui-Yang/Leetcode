// 360. Sort Transformed Array
// https://leetcode.com/problems/sort-transformed-array/

/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

class Solution {
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int> result;
		int sz = nums.size();
		if (a == 0) {
			if (b < 0) {
				for (int i = 0; i < sz; ++i) {
					result.push_back(f(nums[sz - 1 - i], a, b, c));
				}
			}
			else {
				for (int i = 0; i < sz; ++i) {
					result.push_back(f(nums[i], a, b, c));
				}
			}
		}
		else if (a < 0) {
			result = sortTransformedArray(nums, -a, -b, -c);
			reverse(begin(result), end(result));
			for (auto & i : result) {
				i = -i;
			}
		}
		else {
			double d = -b / (2.0 * a);
			int i = 0;
			while (i + 1 < sz and nums[i + 1] < d) {
				++i;
			}
			int j = i + 1;
			while (i >= 0 or j < sz) {
				if (i < 0) {
					int y = f(nums[j], a, b, c);
					result.push_back(y);
					++j;
				}
				else if (j >= sz) {
					int x = f(nums[i], a, b, c);
					result.push_back(x);
					--i;
				}
				else {
					int x = f(nums[i], a, b, c), y = f(nums[j], a, b, c);
					if (x < y) {
						result.push_back(x);
						--i;
					}
					else {
						result.push_back(y);
						++j;
					}
				}
			}
		}
		return result;
	}
private:
	int f(int x, int a, int b, int c) {
		return a * x * x + b * x + c;
	}
};