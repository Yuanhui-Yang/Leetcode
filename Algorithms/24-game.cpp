// 679. 24 Game
// https://leetcode.com/problems/24-game/

/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double> A(begin(nums), end(nums));
		return f(A);
	}
private:
	bool f(vector<double> & A) {
		int sz = A.size(), i = 0, j = 0, k = 0;
		double val = 0;
		vector<double> B;
		if (sz == 1) {
			return fabs(A[0] - 24) < 1e-6;
		}
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				if (i != j) {
					B.clear();
					for (k = 0; k < sz; ++k) {
						if (k != i and k != j) {
							B.push_back(A[k]);
						}
					}
					if (i < j) {
						val = A[i] + A[j];
						B.push_back(val);
						if (f(B)) {
							return true;
						}
						B.pop_back();
						val = A[i] * A[j];
						B.push_back(val);
						if (f(B)) {
							return true;
						}
						B.pop_back();
					}
					val = A[i] - A[j];
					B.push_back(val);
					if (f(B)) {
						return true;
					}
					B.pop_back();
					if (A[j]) {
						val = A[i] / A[j];
						B.push_back(val);
						if (f(B)) {
							return true;
						}
						B.pop_back();
					}
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

	nums = {3, 3, 8, 8};
	result = solution.judgePoint24(nums);
	cout << boolalpha << result << '\n';
	
	nums = {4, 1, 8, 7};
	result = solution.judgePoint24(nums);
	cout << boolalpha << result << '\n';
 
	nums = {1, 2, 1, 2};
	result = solution.judgePoint24(nums);
	cout << boolalpha << result << '\n';
	
	return 0;
}