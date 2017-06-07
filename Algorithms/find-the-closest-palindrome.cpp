// 564. Find the Closest Palindrome
// https://leetcode.com/problems/find-the-closest-palindrome/

/*
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string nearestPalindromic(string n) {
		const long long len = n.size();
		if (len == 1) {
			return string(1, n.front() - 1);
		}
		string s1(len - 1, '9');

		string s2(len + 1, '0');
		s2.front() = '1';
		s2.back() = '1';
		
		long long leftVal = stoll(n.substr(0, len % 2 + len / 2));
		string s3 = h1(leftVal, len);

		string s4 = h1(leftVal + 1, len);

		string s5 = h1(leftVal - 1, len);

		string result = h2(s1, s2, n);
		result = h2(result, s3, n);
		result = h2(result, s4, n);
		result = h2(result, s5, n);

		return result;
	}
private:
	string h1(long long leftVal, long long len) {
		string leftStr = to_string(leftVal);
		string rightStr(leftStr);
		if (len % 2) {
			rightStr.pop_back();
		}
		reverse(begin(rightStr), end(rightStr));
		return leftStr + rightStr;
	}
	string h2(const string& a, const string& b, const string& n) {
		if (a == n) {
			return b;
		}
		if (b == n) {
			return a;
		}
		long long x = stoll(a), y = stoll(b), z = stoll(n);
		if (abs(x - z) < abs(y - z)) {
			return a;
		}
		if (abs(x - z) > abs(y - z)) {
			return b;
		}
		if (x < y) {
			return a;
		}
		return b;
	}
};

int main(void) {
	Solution soluiton;
	string n, answer, result;

	n = "807045053224792883";
	answer = "807045053350540708";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "88";
	answer = "77";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "1796831971";
	answer = "1796776971";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "1933388391";
	answer = "1933333391";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "1915060191";
	answer = "1915005191";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "11";
	answer = "9";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "10";
	answer = "9";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "2147483647";
	answer = "2147447412";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	n = "123";
	answer = "121";
	result = soluiton.nearestPalindromic(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}