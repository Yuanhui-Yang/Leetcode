// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/

/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k <= 0) {
			return num;
		}
		int sz = num.size(), i = 0;
		if (sz <= k) {
			return "0";
		}
		while (k > 0 and !num.empty()) {
			i = 0;
			sz = num.size();
			while (i + 1 < sz and num[i] <= num[i + 1]) {
				++i;
			}
			num.erase(next(begin(num), i));
			--k;
		}
		while (!num.empty() and num[0] == '0') {
			num.erase(begin(num));
		}
		return num.empty() ? "0" : num;
	}
};

/*
class Solution {
public:
	string removeKdigits(string num, int k) {
		int sz = num.size(), i = 0;
		if (sz <= k) {
			return "0";
		}
		if (k <= 0) {
			return num;
		}
		while (i + 1 < sz and num[i] <= num[i + 1]) {
			++i;
		}
		num.erase(next(begin(num), i));
		while (!num.empty() and num[0] == '0') {
			num.erase(begin(num));
		}
		return removeKdigits(num, --k);
	}
};
*/

int main(void) {
	Solution solution;
	string num, result;
	int k;
	
	num = "10200";
	k = 1;
	result = solution.removeKdigits(num, k);
	cout << result << '\n';

	num = "10";
	k = 1;
	result = solution.removeKdigits(num, k);
	cout << result << '\n';

	num = "222222222222222222222210";
	k = 12;
	result = solution.removeKdigits(num, k);
	cout << result << '\n';

	return 0;
}