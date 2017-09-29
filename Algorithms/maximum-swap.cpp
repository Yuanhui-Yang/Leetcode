// 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap/

/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		string s = to_string(num);
		int sz = s.size(), i = 0, a = -1, b = -1, c = -1, d = -1;
		for (i = sz - 1; i >= 0; --i) {
			if (a < s[i]) {
				a = s[i];
				b = i;
			}
			else if (s[i] < a) {
				c = i;
				d = b;
			}
		}
		if (c < 0 and d < 0) {
			return num;
		}
		swap(s[c], s[d]);
		return stoi(s);
	}
};

int main(void) {
	Solution solution;
	int num, result;

	num = 1993;
	result = solution.maximumSwap(num);
	cout << result << '\n';
	
	num = 98368;
	result = solution.maximumSwap(num);
	cout << result << '\n';
	
	num = 2736;
	result = solution.maximumSwap(num);
	cout << result << '\n';

	num = 9973;
	result = solution.maximumSwap(num);
	cout << result << '\n';

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		string s = to_string(num), t, u;
		int sz = s.size(), i = 0, j = 0;
		bool flag = false;
		for (i = 0; i + 1 < sz; ++i) {
			t = s;
			for (j = i + 1; j < sz; ++j) {
				u = s;
				swap(u[i], u[j]);
				if (t < u) {
					flag = true;
					t = u;
				}
			}
			if (flag) {
				return stoi(t);
			}
		}
		return num;
	}
};

int main(void) {
	Solution solution;
	int num, result;

	num = 1993;
	result = solution.maximumSwap(num);
	cout << result << '\n';
	
	num = 98368;
	result = solution.maximumSwap(num);
	cout << result << '\n';
	
	num = 2736;
	result = solution.maximumSwap(num);
	cout << result << '\n';

	num = 9973;
	result = solution.maximumSwap(num);
	cout << result << '\n';

	return 0;
}